#include <stddef.h>
#include "ccn/action_types.h"
#include "ccngen/action_handling.h"
#include "ccngen/enum.h"
#include "ccngen/ast.h"
#include "ccn/phase_driver.h"
enum ccn_action_id cleanup_ids_table[2] = { CCNAC_ID_free, CCNAC_ID_NULL };
enum ccn_action_id dynamic_gen_ast_ids_table[] = {
CCNAC_ID_DYNAMIC_START_AST_HEADER, CCNAC_ID_DYNAMIC_GENNODESTRUCTS, CCNAC_ID_DYNAMIC_GENNODEMACROS, CCNAC_ID_DYNAMIC_GENNODEINITFUNCTIONS, CCNAC_ID_DYNAMIC_GENNODEUNION, CCNAC_ID_DYNAMIC_GENBASENODE, CCNAC_ID_DYNAMIC_SWITCH_TO_AST_SOURCE, CCNAC_ID_DYNAMIC_GENBASENODEINIT, CCNAC_ID_DYNAMIC_GENNODECONSTRUCTOR, CCNAC_ID_NULL, };

enum ccn_action_id dynamic_gen_trav_data_ids_table[] = {
CCNAC_ID_DYNAMIC_START_TRAV_DATA, CCNAC_ID_DYNAMIC_GENTRAVDATASTRUCTS, CCNAC_ID_DYNAMIC_GENTRAVDATAUNION, CCNAC_ID_DYNAMIC_GENTRAVDATAGETTERS, CCNAC_ID_DYNAMIC_GENTRAVDATACTORSHEADER, CCNAC_ID_DYNAMIC_SWITCH_TRAV_DATA, CCNAC_ID_DYNAMIC_GENTRAVDATACTORS, CCNAC_ID_NULL, };

enum ccn_action_id dynamic_backend_ids_table[] = {
CCNAC_ID_DYNAMIC_GEN_AST, CCNAC_ID_DYNAMIC_START_ENUM_HEADER, CCNAC_ID_DYNAMIC_GENENUM, CCNAC_ID_DYNAMIC_GENENUMVALUES, CCNAC_ID_DYNAMIC_GEN_TRAV_DATA, CCNAC_ID_DYNAMIC_START_TABLE_GEN, CCNAC_ID_DYNAMIC_GENTRAVVTABLE, CCNAC_ID_DYNAMIC_GENPASSTABLE, CCNAC_ID_DYNAMIC_GENSYSTEMTRAVERSALS, CCNAC_ID_DYNAMIC_GENTRAVTABLE, CCNAC_ID_DYNAMIC_GENTRAVDATATABLES, CCNAC_ID_DYNAMIC_GENACTIONSHEADER, CCNAC_ID_DYNAMIC_GENCOPYTRAVERSAL, CCNAC_ID_DYNAMIC_GENFREETRAVERSAL, CCNAC_ID_DYNAMIC_GENCHECKTRAVERSAL, CCNAC_ID_NULL, };

enum ccn_action_id phase_driver_ids_table[] = {
CCNAC_ID_GEN_ACTION_ARRAY_HEADER, CCNAC_ID_GEN_IDS_TABLES, CCNAC_ID_GEN_ACTION_ARRAY, CCNAC_ID_NULL, };

enum ccn_action_id unpack_lifetimes_ids_table[] = {
CCNAC_ID_ASSIGN_ID_TO_ACTION, CCNAC_ID_MAP_ID_TO_LIFETIME, CCNAC_ID_NULL, };

enum ccn_action_id semantic_ids_table[] = {
CCNAC_ID_BUILDSYMBOLTABLE, CCNAC_ID_CHECKEXISTANCE, CCNAC_ID_UNWRAPSETEXPR, CCNAC_ID_REACHABILITY, CCNAC_ID_NULL, };

enum ccn_action_id startphase_ids_table[] = {
CCNAC_ID_SCANANDPARSE, CCNAC_ID_SEMANTIC, CCNAC_ID_UNPACK_LIFETIMES, CCNAC_ID_DYNAMIC_BACKEND, CCNAC_ID_PHASE_DRIVER, CCNAC_ID_GEN_DOT, CCNAC_ID_PRINT, CCNAC_ID_NULL, };

static struct ccn_action ccn_action_array[] = {
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMIC_GEN_AST, "dynamic_gen_ast", .phase = {NULL, NT_AST, dynamic_gen_ast_ids_table, false, CCNAC_ID_DYNAMIC_GEN_AST,},},
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMIC_GEN_TRAV_DATA, "dynamic_gen_trav_data", .phase = {NULL, NT_AST, dynamic_gen_trav_data_ids_table, false, CCNAC_ID_DYNAMIC_GEN_TRAV_DATA,},},
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMIC_BACKEND, "dynamic_backend", .phase = {NULL, NT_AST, dynamic_backend_ids_table, false, CCNAC_ID_DYNAMIC_BACKEND,},},
{CCN_ACTION_PHASE, CCNAC_ID_PHASE_DRIVER, "phase_driver", .phase = {NULL, NT_AST, phase_driver_ids_table, false, CCNAC_ID_PHASE_DRIVER,},},
{CCN_ACTION_PHASE, CCNAC_ID_UNPACK_LIFETIMES, "unpack_lifetimes", .phase = {NULL, NT_AST, unpack_lifetimes_ids_table, false, CCNAC_ID_UNPACK_LIFETIMES,},},
{CCN_ACTION_PHASE, CCNAC_ID_SEMANTIC, "semantic", .phase = {NULL, NT_AST, semantic_ids_table, false, CCNAC_ID_SEMANTIC,},},
{CCN_ACTION_PHASE, CCNAC_ID_STARTPHASE, "startPhase", .phase = {NULL, NT_AST, startphase_ids_table, false, CCNAC_ID_STARTPHASE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_PRINT, "print", .traversal = {TRAV_PRINT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALCONTAINS, "setliteralContains", .traversal = {TRAV_SETLITERALCONTAINS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALINTERSECT, "setliteralIntersect", .traversal = {TRAV_SETLITERALINTERSECT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALUNION, "setliteralUnion", .traversal = {TRAV_SETLITERALUNION,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALINSERT, "setliteralInsert", .traversal = {TRAV_SETLITERALINSERT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_REACHABILITY, "reachability", .traversal = {TRAV_REACHABILITY,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_UNWRAPSETEXPR, "unwrapSetExpr", .traversal = {TRAV_UNWRAPSETEXPR,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_BUILDSYMBOLTABLE, "buildSymbolTable", .traversal = {TRAV_BUILDSYMBOLTABLE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_CHECKEXISTANCE, "checkExistance", .traversal = {TRAV_CHECKEXISTANCE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENNODEMACROS, "dynamic_genNodeMacros", .traversal = {TRAV_DYNAMIC_GENNODEMACROS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENNODESTRUCTS, "dynamic_genNodeStructs", .traversal = {TRAV_DYNAMIC_GENNODESTRUCTS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENNODEINITFUNCTIONS, "dynamic_genNodeInitFunctions", .traversal = {TRAV_DYNAMIC_GENNODEINITFUNCTIONS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENNODEUNION, "dynamic_genNodeUnion", .traversal = {TRAV_DYNAMIC_GENNODEUNION,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENNODECONSTRUCTOR, "dynamic_genNodeConstructor", .traversal = {TRAV_DYNAMIC_GENNODECONSTRUCTOR,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENENUM, "dynamic_genEnum", .traversal = {TRAV_DYNAMIC_GENENUM,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENENUMVALUES, "dynamic_genEnumValues", .traversal = {TRAV_DYNAMIC_GENENUMVALUES,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVVTABLE, "dynamic_genTravVtable", .traversal = {TRAV_DYNAMIC_GENTRAVVTABLE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENNODESFORTRAVTABLE, "dynamic_genNodesForTravTable", .traversal = {TRAV_DYNAMIC_GENNODESFORTRAVTABLE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENPASSTABLE, "dynamic_genPassTable", .traversal = {TRAV_DYNAMIC_GENPASSTABLE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVTABLE, "dynamic_genTravTable", .traversal = {TRAV_DYNAMIC_GENTRAVTABLE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENSYSTEMTRAVERSALS, "dynamic_genSystemTraversals", .traversal = {TRAV_DYNAMIC_GENSYSTEMTRAVERSALS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENACTIONSHEADER, "dynamic_genActionsHeader", .traversal = {TRAV_DYNAMIC_GENACTIONSHEADER,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVACTIONS, "dynamic_genTravActions", .traversal = {TRAV_DYNAMIC_GENTRAVACTIONS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENCOPYTRAVERSAL, "dynamic_genCopyTraversal", .traversal = {TRAV_DYNAMIC_GENCOPYTRAVERSAL,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENCONSTRUCTORCALL, "dynamic_genConstructorCall", .traversal = {TRAV_DYNAMIC_GENCONSTRUCTORCALL,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENFREETRAVERSAL, "dynamic_genFreeTraversal", .traversal = {TRAV_DYNAMIC_GENFREETRAVERSAL,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENCHECKTRAVERSAL, "dynamic_genCheckTraversal", .traversal = {TRAV_DYNAMIC_GENCHECKTRAVERSAL,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVDATASTRUCTS, "dynamic_genTravDataStructs", .traversal = {TRAV_DYNAMIC_GENTRAVDATASTRUCTS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVDATACTORS, "dynamic_genTravDataCtors", .traversal = {TRAV_DYNAMIC_GENTRAVDATACTORS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVDATACTORSHEADER, "dynamic_genTravDataCtorsHeader", .traversal = {TRAV_DYNAMIC_GENTRAVDATACTORSHEADER,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVDATAGETTERS, "dynamic_genTravDataGetters", .traversal = {TRAV_DYNAMIC_GENTRAVDATAGETTERS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVDATAUNION, "dynamic_genTravDataUnion", .traversal = {TRAV_DYNAMIC_GENTRAVDATAUNION,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GEN_ACTION_ARRAY, "gen_action_array", .traversal = {TRAV_GEN_ACTION_ARRAY,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GEN_ACTION_ARRAY_HEADER, "gen_action_array_header", .traversal = {TRAV_GEN_ACTION_ARRAY_HEADER,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GEN_IDS_TABLES, "gen_ids_tables", .traversal = {TRAV_GEN_IDS_TABLES,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMIC_GENTRAVDATATABLES, "dynamic_genTravDataTables", .traversal = {TRAV_DYNAMIC_GENTRAVDATATABLES,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GEN_DOT, "gen_dot", .traversal = {TRAV_GEN_DOT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_MAP_ID_TO_LIFETIME, "map_id_to_lifetime", .traversal = {TRAV_MAP_ID_TO_LIFETIME,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_ASSIGN_ID_TO_ACTION, "assign_id_to_action", .traversal = {TRAV_ASSIGN_ID_TO_ACTION,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_GENBASENODEINIT, "dynamic_genBaseNodeInit", .pass = {PASS_DYNAMIC_GENBASENODEINIT,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_SWITCH_TO_AST_SOURCE, "dynamic_switch_to_ast_source", .pass = {PASS_DYNAMIC_SWITCH_TO_AST_SOURCE,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_GENBASENODE, "dynamic_genBaseNode", .pass = {PASS_DYNAMIC_GENBASENODE,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_START_AST_HEADER, "dynamic_start_ast_header", .pass = {PASS_DYNAMIC_START_AST_HEADER,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_SWITCH_TRAV_DATA, "dynamic_switch_trav_data", .pass = {PASS_DYNAMIC_SWITCH_TRAV_DATA,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_START_TRAV_DATA, "dynamic_start_trav_data", .pass = {PASS_DYNAMIC_START_TRAV_DATA,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_START_TABLE_GEN, "dynamic_start_table_gen", .pass = {PASS_DYNAMIC_START_TABLE_GEN,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_START_ENUM_HEADER, "dynamic_start_enum_header", .pass = {PASS_DYNAMIC_START_ENUM_HEADER,},},
{CCN_ACTION_PASS, CCNAC_ID_SCANANDPARSE, "scanAndParse", .pass = {PASS_SCANANDPARSE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_free, "Free", .traversal = {TRAV_free,},},
{CCN_ACTION_PHASE, CCNAC_ID_cleanup, "Cleanup", .phase = {NULL, NT_AST, cleanup_ids_table, false, CCNAC_ID_cleanup,},},
};

struct ccn_action *CCNgetActionFromID(enum ccn_action_id action_id) {
    return &ccn_action_array[action_id];
}

