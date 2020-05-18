#include <stdio.h>
#include <string.h>

#include "ast/ast.h"
#include "filegen/driver.h"
#include "filegen/genmacros.h"
#include "filegen/util.h"
#include "gen-functions.h"

static int indent = 0;

void gen_free_func(Config *config, FILE *fp, Node *node) {
    char *nodelwr = strlwr(node->id);
    char *nodeupr = strupr(node->id);
    out_comment("%s", node->id);
    out_start_func("Node *free_%s(Node *arg_node)", nodelwr);
    if (node->children) {
        out_field("arg_node = trav_children(arg_node)");
    }
    for (int i = 0; i < array_size(node->attrs); i++) {
        Attr *attr = array_get(node->attrs, i);
        char *attrupr = strupr(attr->id);
        char *freefunc;
        if (attr->type == AT_link) {
            if (!attr->construct) {
                out_begin_if("%s_%s(arg_node)", nodeupr, attrupr);
            }
            char *attrtypelwr = strlwr(attr->type_id);
            out_field("free_%s(%s_%s(arg_node))", attrtypelwr, nodeupr,
                      attrupr);
            mem_free(attrtypelwr);
            if (!attr->construct) {
                out_end_if();
            }
        }
        mem_free(attrupr);
    }
    out_field("mem_free(arg_node->data.N_%s)", nodelwr);
    out_field("mem_free(arg_node)");
    out_field("return arg_node");
    out_end_func();
    mem_free(nodelwr);
    mem_free(nodeupr);
}

void gen_free_src(Config *config, FILE *fp) {
    out("#include <stdlib.h>\n");
    out("\n");
    out("#include \"include/core/actions_core.h\"\n");
    out("#include \"lib/memory.h\"\n");
    out("\n");
    for (int i = 0; i < array_size(config->nodes); ++i) {
        Node *node = array_get(config->nodes, i);
        gen_free_func(config, fp, node);
    }
}