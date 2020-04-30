#include <stdio.h>

#include "core/ast_core.h"
#include "core/copy_core.h"
#include "core/free_core.h"
#include "core/trav_core.h"
#include "user/trav_print.h"

int main(int argc, char *argv[]) {
    Node *left = node_init_intconst(4);
    Node *right = node_init_intconst(5);
    Node *binop = node_init_binop(left, right, BO_add);
    Node *expr = node_init_exprlist(binop, NULL);
    trav_start(expr, TRAV_print, &trav_init_print, &trav_free_print);
    trav_start(expr, TRAV_context, &trav_init, &trav_free);
    free_node(expr);
}