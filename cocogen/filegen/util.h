#pragma once

#include "ast/ast.h"
#include <stdio.h>

void print_indent_level(int indent_level, FILE *);
void generate_node_header_includes(Config *, FILE *, Node *);

bool is_traversal_node(Traversal *trav, Node *node);
char *attr_default_value(Config *config, FILE *fp, enum AttrType type);

#include "genmacros.h"