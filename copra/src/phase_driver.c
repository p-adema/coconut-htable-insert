#include <ctype.h>
#include <err.h>
#include <palm/str.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "ccn/action_types.h"
#include "ccn/dynamic_core.h"
#include "ccngen/action_handling.h"
#include "palm/ctinfo.h"
#include "ccn/phase_driver.h"


struct phase_driver {
    size_t level;
    size_t action_id;
    size_t cycle_iter;
    size_t max_cycles;
    enum pd_verbosity verbosity;
    bool fixed_point;
    bool action_error;
    bool phase_error;
    bool tree_check;
    struct ccn_phase *current_phase;
    char *breakpoint;
};

static struct phase_driver phase_driver = {
    .level = 0,
    .action_id = 0,
    .cycle_iter = 0,
    .max_cycles = 100,
    .current_phase = NULL,
    .fixed_point = false,
    .action_error = false,
    .phase_error = false,
    .tree_check = true,
    .verbosity = PD_V_QUIET,
    .breakpoint = NULL,
};

static void resetPhaseDriver()
{
    phase_driver.level = 0;
    phase_driver.action_id = 0;
    phase_driver.cycle_iter = 0;
    phase_driver.current_phase = NULL;
    phase_driver.fixed_point = false;
    phase_driver.action_error = false;
    phase_driver.phase_error = false;
}

static struct ccn_node *StartPhase(struct ccn_phase *phase, char *phase_name, struct ccn_node *node);

extern void BreakpointHandler(node_st *node);

struct ccn_node *CCNdispatchAction(struct ccn_action *action, enum ccn_nodetype root_type, struct ccn_node *node,
                          bool is_root) {
    phase_driver.action_id++;


    if (action->type == CCN_ACTION_PHASE && phase_driver.verbosity > PD_V_QUIET) {
        fprintf(stderr, ">> %s\n", action->name);
    } else {
        if (phase_driver.verbosity > PD_V_SMALL) {
            fprintf(stderr, "  *** %s\n", action->name);
        }
    }

    if (phase_driver.tree_check) {
        node = TRAVstart(node, TRAV_check);
        CTIabortOnError();
    }

    bool phase_error = false;
    switch (action->type) {
    case CCN_ACTION_PASS:
        node = PASSstart(node, action->pass.pass_type);
        break;
    case CCN_ACTION_TRAVERSAL:
        node = TRAVstart(node, action->traversal.trav_type);
        break;
    case CCN_ACTION_PHASE:
        phase_error = phase_driver.phase_error;
        phase_driver.phase_error = false;
        node = StartPhase(&(action->phase), action->name, node);
        phase_driver.phase_error = phase_error || phase_driver.phase_error;
        break;
    case CCN_ACTION_NULL:
        err(EXIT_FAILURE, "[coconut] error in phase driver.");
    }
    if (phase_driver.action_error) {
        fprintf(stderr, "[coconut] Action error received. Stopping...\n");
        CTIabortCompilation();
    }

    if (phase_driver.breakpoint) {
        if (STReqci(phase_driver.breakpoint, action->name)) {
            BreakpointHandler(node);
            exit(0);
        }
    }
    if (action->type == CCN_ACTION_PHASE && phase_driver.verbosity > PD_V_QUIET) {
        fprintf(stderr, "<< %s\n", action->name);
    }

    root_type = root_type;
    is_root = is_root;
    return node;
}

/* Moves action counter used by lifetimes forward when we skip. */
static void SkipPhase(struct ccn_phase *phase) {
    size_t action_counter = 0;
    enum ccn_action_id action_id = phase->action_table[action_counter];
    while (action_id != CCNAC_ID_NULL) {
        phase_driver.action_id++;
        action_counter++;
        action_id = phase->action_table[action_counter];
    }
}

char *Checkbreakpoint(char *name)
{
    int len = STRlen(name);
    for (int i = 0; i < len; i++) {
        if (phase_driver.breakpoint[i] == '\0') {
            return NULL;
        }
        if (tolower(name[i]) != tolower(phase_driver.breakpoint[i])) {
            return NULL;
        }
    }
    // Handled by the action start.
    if (STRlen(phase_driver.breakpoint) == len) {
        return NULL;
    }
    if (phase_driver.breakpoint[len] == '.') {
        if (phase_driver.breakpoint[len + 1] == '\0') {
            fprintf(stderr, "[coconut] breakpoint string is invalid.\n");
            return NULL;
        }
        return phase_driver.breakpoint + len + 1;
    }

    return NULL;
}

struct ccn_node *StartPhase(struct ccn_phase *phase, char *phase_name, struct ccn_node *node) {
    if (phase->gate_func && !phase->gate_func()) {
        if (phase_driver.verbosity >= PD_V_HIGH) {
            fprintf(stderr, "[coconut] Skipping phase %s because gate function returned false.", phase_name);
        }
        SkipPhase(phase);
        return node;
    }

    char *old_break = NULL;
    if (phase_driver.breakpoint) {
        char *new_break = Checkbreakpoint(phase_name);
        if (new_break != NULL) {
            old_break = phase_driver.breakpoint;
            phase_driver.breakpoint = new_break;
        }
    }

    struct ccn_phase *prev = phase_driver.current_phase;
    phase_driver.current_phase = phase;
    phase_driver.level++;
    bool cycle = phase->is_cycle;
    uint64_t curr_action_id = phase_driver.action_id;

    do {
        // If we cycle around, reset the action id.
        phase_driver.fixed_point = true;
        phase_driver.action_id = curr_action_id;
        size_t action_counter = 0;
        enum ccn_action_id action_id = phase->action_table[action_counter];
        while (action_id != CCNAC_ID_NULL) {
            struct ccn_action *action = CCNgetActionFromID(action_id);
            node = CCNdispatchAction(action, phase->root_type, node, false);
            action_counter++;
            action_id = phase->action_table[action_counter];
        }
        phase_driver.cycle_iter++;
    } while(cycle && phase_driver.cycle_iter < phase_driver.max_cycles && !(phase_driver.fixed_point));

    if (phase_driver.phase_error) {
        fprintf(stderr, "[coconut] Phase error received. Stopping...\n");
        CTIabortCompilation();
    }

    phase_driver.cycle_iter = 0;
    phase_driver.level--;

    phase_driver.current_phase = prev;
    if (old_break != NULL) {
        phase_driver.breakpoint = old_break;
    }
    return node;
}

/**
 * Notify CoCoNut that a fixed point is not reached in current cycle.
 */
void CCNcycleNotify()
{
    phase_driver.fixed_point = false;
}

/**
 * Signal an action error. CoCoNut will call CTIabortCompilation
 * after the action this error was signalled in.
 */
void CCNerrorAction()
{
    phase_driver.action_error = true;
}

/**
 * Signal an phase error. As a result, CoCoNut will call CTIabortCompilation
 * at the end of the phase this error was signalled in.
 */
void CCNerrorPhase()
{
    phase_driver.phase_error = true;
}

/**
 * Set the maximum number of cycles for a cycle. Can be changed at runtime.
 * @param cycle_count the maximum number of cycles.
 */
void CCNsetCycles(size_t cycle_count)
{
    phase_driver.max_cycles = cycle_count;
}

/**
 * Set a breakpoint at which CoCoNut will stop and call the handler:
 * *BreakpointHandler*.
 * @param breakpoint The breakpoint in format: <phase>.<phase>.<action>
 */
void CCNsetBreakpoint(char *breakpoint)
{
    phase_driver.breakpoint = breakpoint;
}

/**
 * Set the verbosity level of CoCoNut.
 * @param type the type of verbosity.
 */
void CCNsetVerbosity(enum pd_verbosity type)
{
    phase_driver.verbosity = type;
}

/**
 * Enable or disable consistency checking your tree.
 * @param enable
 */
void CCNsetTreeCheck(bool enable)
{
    phase_driver.tree_check = enable;
}

/**
 * Perform a invocation of your compiler.
 * @param node the root of the tree.
 */
void CCNrun(struct ccn_node *node)
{
    resetPhaseDriver();
    node = CCNdispatchAction(CCNgetActionFromID(CCN_ROOT_ACTION), CCN_ROOT_TYPE, node, false);
    TRAVstart(node, TRAV_free);
}

size_t CCNgetCurrentActionId()
{
    return phase_driver.action_id;
}
