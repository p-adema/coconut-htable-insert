#include <stdio.h>

#include "ccngen/ast.h"
#include "ccn/dynamic_core.h"

void *PRTallocTravData()
{
    return 0;
}

void PRTfreeTravData(void *data)
{

}

node_st *PRTast(node_st *ast)
{
    printf("AST:\n");
    printf("Child: %d\n", NODE_TYPE(AST_IPHASES(ast)));
    TRAVchildren(ast);
    return ast;
}

node_st *PRTiphase(node_st *node)
{
    printf("Phase: %s\n", ID_ORIG(IPHASE_NAME(node)));
    TRAVchildren(node);
    return node;
}

node_st *PRTitraversal(node_st *node)
{
    printf("Trav: %s\n", ID_ORIG(ITRAVERSAL_NAME(node)));
    TRAVchildren(node);
    return node;
}

node_st *PRTipass(node_st *node)
{
    printf("Pass: %s\n", ID_ORIG(IPASS_NAME(node)));
    TRAVchildren(node);
    return node;
}


node_st *PRTiactions(node_st *node)
{
    TRAVchildren(node);
    return node;
}


node_st *PRTinode(node_st *node)
{
    printf("NODE: %s\n", ID_ORIG(INODE_NAME(node)));
    TRAVchildren(node);
    return node;
}

node_st *PRTchild(node_st *node)
{
    TRAVchildren(node);
    return node;
}

node_st *PRTattribute(node_st *node)
{
    printf("Attr: %s\n", ID_ORIG(ATTRIBUTE_NAME(node)));
    TRAVchildren(node);
    return node;
}

node_st *PRTsetreference(node_st *node)
{
    printf("Set refence: %s\n", ID_ORIG(SETREFERENCE_REFERENCE(node)));
    TRAVchildren(node);
    return node;
}

node_st *PRTsetliteral(node_st *node)
{
    if (SETLITERAL_REFERENCE(node)) {
        printf("%s\n", ID_ORIG(SETLITERAL_REFERENCE(node)));
    }
    TRAVchildren(node);
    return node;
}

node_st *PRTinodeset(node_st *node)
{
    printf("NODESET {\n");
    TRAVdo(INODESET_EXPR(node));
    printf("} END\n");
    TRAVopt(INODESET_NEXT(node));
    return node;
}

node_st *PRTid(node_st *node)
{
    printf("Ref: %s\n", ID_ORIG(node));
    return node;
}

node_st *PRTsetoperation(node_st *node)
{
    TRAVchildren(node);
    return node;
}

node_st *PRTienum(node_st *node)
{
    TRAVchildren(node);
    return node;
}

node_st *PRTste(node_st *node)
{
    printf("STE: %s, %d\n", ID_ORIG(STE_KEY(node)), NODE_TYPE(STE_VALUE(node)));
    TRAVchildren(node);
    return node;
}
