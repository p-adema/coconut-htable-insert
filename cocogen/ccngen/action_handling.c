#include <stddef.h>
#include "ccn/action_types.h"
#include "ccngen/action_handling.h"
#include "ccngen/enum.h"
#include "ccngen/ast.h"
#include "ccngen/gate.h"
#include "ccn/phase_driver.h"
enum ccn_action_id cleanup_ids_table[2] = { CCNAC_ID_free, CCNAC_ID_NULL };
enum ccn_action_id dynamicgenuserfiles_ids_table[] = {    CCNAC_ID_DYNAMICUSERGENPASSES,     CCNAC_ID_DYNAMICUSERGENTRAVERSALS,     CCNAC_ID_DYNAMICUSERGENEQUATIONS,     CCNAC_ID_NULL, };

enum ccn_action_id dynamicgenvisits_ids_table[] = {    CCNAC_ID_DYNAMIC_START_EQUATION_HEADER,     CCNAC_ID_DYNAMICGENEQUATIONINCLUDES,     CCNAC_ID_DYNAMICGENEQUATIONFUNCTIONS,     CCNAC_ID_DYNAMIC_START_VISIT_HEADER,     CCNAC_ID_DYNAMICGENVISITFUNCTIONS,     CCNAC_ID_DYNAMICSWITCHTOVISITSOURCE,     CCNAC_ID_DYNAMICGENVISITSOURCE,     CCNAC_ID_NULL, };

enum ccn_action_id dynamicgenast_ids_table[] = {    CCNAC_ID_DYNAMIC_START_AST_HEADER,     CCNAC_ID_DYNAMICGENNODESTRUCTS,     CCNAC_ID_DYNAMICGENNODEMACROS,     CCNAC_ID_DYNAMICGENNODEINITFUNCTIONS,     CCNAC_ID_DYNAMICGENNODEUNION,     CCNAC_ID_DYNAMICGENBASENODE,     CCNAC_ID_DYNAMICGENNODESETACCESSFUNCTIONS,     CCNAC_ID_DYNAMICSWITCHTOASTSOURCE,     CCNAC_ID_DYNAMICGENBASENODEINIT,     CCNAC_ID_DYNAMICGENNODECONSTRUCTOR,     CCNAC_ID_NULL, };

enum ccn_action_id dynamicgentravdata_ids_table[] = {    CCNAC_ID_DYNAMICSTARTTRAVDATA,     CCNAC_ID_DYNAMICGENTRAVDATASTRUCTS,     CCNAC_ID_DYNAMICGENTRAVDATAUNION,     CCNAC_ID_DYNAMICGENTRAVDATAGETTERS,     CCNAC_ID_DYNAMICGENTRAVDATACTORSHEADER,     CCNAC_ID_DYNAMICSWITCHTRAVDATA,     CCNAC_ID_DYNAMICGENTRAVDATACTORS,     CCNAC_ID_NULL, };

enum ccn_action_id staticgenast_ids_table[] = {    CCNAC_ID_STATICGENNODESTRUCTS,     CCNAC_ID_NULL, };

enum ccn_action_id staticbackend_ids_table[] = {    CCNAC_ID_STATICGENAST,     CCNAC_ID_NULL, };

enum ccn_action_id dynamicbackend_ids_table[] = {    CCNAC_ID_DYNAMICGENAST,     CCNAC_ID_DYNAMICSTARTENUMHEADER,     CCNAC_ID_DYNAMICGENENUM,     CCNAC_ID_DYNAMICGENENUMVALUES,     CCNAC_ID_DYNAMICGENTRAVDATA,     CCNAC_ID_DYNAMICSTARTTABLEGEN,     CCNAC_ID_DYNAMICGENTRAVVTABLE,     CCNAC_ID_DYNAMICGENPASSTABLE,     CCNAC_ID_DYNAMICGENSYSTEMTRAVERSALS,     CCNAC_ID_DYNAMICGENTRAVTABLE,     CCNAC_ID_DYNAMICGENTRAVDATATABLES,     CCNAC_ID_DYNAMICGENACTIONSHEADER,     CCNAC_ID_DYNAMICGENCOPYTRAVERSAL,     CCNAC_ID_DYNAMICGENFREETRAVERSAL,     CCNAC_ID_DYNAMICGENCHECKTRAVERSAL,     CCNAC_ID_DYNAMICGENVISITS,     CCNAC_ID_DYNAMICGENUSERFILES,     CCNAC_ID_DYNAMICGENTRAVFUNCTIONS,     CCNAC_ID_NULL, };

enum ccn_action_id phasedriver_ids_table[] = {    CCNAC_ID_GENACTIONARRAYHEADER,     CCNAC_ID_GENIDSTABLES,     CCNAC_ID_GENACTIONARRAY,     CCNAC_ID_GENGATEHEADER,     CCNAC_ID_NULL, };

enum ccn_action_id unpacklifetimes_ids_table[] = {    CCNAC_ID_CHECKLIFETIMES,     CCNAC_ID_ASSIGNIDTOACTION,     CCNAC_ID_MAPIDTOLIFETIME,     CCNAC_ID_CHILDRENSETMANDATORY,     CCNAC_ID_NULL, };

enum ccn_action_id semantic_ids_table[] = {    CCNAC_ID_BUILDSYMBOLTABLE,     CCNAC_ID_CHECKEXISTANCE,     CCNAC_ID_NODESETCHILDTABLE,     CCNAC_ID_UNWRAPSETEXPR,     CCNAC_ID_PROPAGATEATTRIBUTES,     CCNAC_ID_CHECKATTRIBUTES,     CCNAC_ID_CHECKPRODUCTRULES,     CCNAC_ID_REACHABILITY,     CCNAC_ID_SCHEDULEATTRIBUTEVISITS,     CCNAC_ID_NULL, };

enum ccn_action_id opts_ids_table[] = {    CCNAC_ID_DOOPTS,     CCNAC_ID_NULL, };

enum ccn_action_id startphase_ids_table[] = {    CCNAC_ID_SCANANDPARSE,     CCNAC_ID_SEMANTIC,     CCNAC_ID_UNPACKLIFETIMES,     CCNAC_ID_DYNAMICBACKEND,     CCNAC_ID_STATICBACKEND,     CCNAC_ID_PHASEDRIVER,     CCNAC_ID_GENDOT,     CCNAC_ID_GENDEFINES,     CCNAC_ID_PRINT,     CCNAC_ID_NULL, };

static struct ccn_action ccn_action_array[] = {
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMICGENUSERFILES, "dynamicGenUserFiles", .phase = {NULL, NT_AST, dynamicgenuserfiles_ids_table, false, CCNAC_ID_DYNAMICGENUSERFILES,},},
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMICGENVISITS, "dynamicGenVisits", .phase = {NULL, NT_AST, dynamicgenvisits_ids_table, false, CCNAC_ID_DYNAMICGENVISITS,},},
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMICGENAST, "dynamicGenAst", .phase = {NULL, NT_AST, dynamicgenast_ids_table, false, CCNAC_ID_DYNAMICGENAST,},},
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMICGENTRAVDATA, "dynamicGenTravData", .phase = {NULL, NT_AST, dynamicgentravdata_ids_table, false, CCNAC_ID_DYNAMICGENTRAVDATA,},},
{CCN_ACTION_PHASE, CCNAC_ID_STATICGENAST, "staticGenAst", .phase = {NULL, NT_AST, staticgenast_ids_table, false, CCNAC_ID_STATICGENAST,},},
{CCN_ACTION_PHASE, CCNAC_ID_STATICBACKEND, "staticBackend", .phase = {backendIsStatic, NT_AST, staticbackend_ids_table, false, CCNAC_ID_STATICBACKEND,},},
{CCN_ACTION_PHASE, CCNAC_ID_DYNAMICBACKEND, "dynamicBackend", .phase = {backendIsDynamic, NT_AST, dynamicbackend_ids_table, false, CCNAC_ID_DYNAMICBACKEND,},},
{CCN_ACTION_PHASE, CCNAC_ID_PHASEDRIVER, "phaseDriver", .phase = {NULL, NT_AST, phasedriver_ids_table, false, CCNAC_ID_PHASEDRIVER,},},
{CCN_ACTION_PHASE, CCNAC_ID_UNPACKLIFETIMES, "unpackLifetimes", .phase = {NULL, NT_AST, unpacklifetimes_ids_table, false, CCNAC_ID_UNPACKLIFETIMES,},},
{CCN_ACTION_PHASE, CCNAC_ID_SEMANTIC, "semantic", .phase = {NULL, NT_AST, semantic_ids_table, false, CCNAC_ID_SEMANTIC,},},
{CCN_ACTION_PHASE, CCNAC_ID_OPTS, "opts", .phase = {NULL, NT_AST, opts_ids_table, true, CCNAC_ID_OPTS,},},
{CCN_ACTION_PHASE, CCNAC_ID_STARTPHASE, "startPhase", .phase = {NULL, NT_AST, startphase_ids_table, false, CCNAC_ID_STARTPHASE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_PRINT, "print", .traversal = {TRAV_PRT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALCONTAINS, "setliteralContains", .traversal = {TRAV_SLC,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALDIFFERENCE, "setliteralDifference", .traversal = {TRAV_SLD,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALINTERSECT, "setliteralIntersect", .traversal = {TRAV_SLIS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALUNION, "setliteralUnion", .traversal = {TRAV_SLU,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SETLITERALINSERT, "setliteralInsert", .traversal = {TRAV_SLI,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_SCHEDULEATTRIBUTEVISITS, "scheduleAttributeVisits", .traversal = {TRAV_SAV,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_REACHABILITY, "reachability", .traversal = {TRAV_RCB,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_CHECKPRODUCTRULES, "checkProductRules", .traversal = {TRAV_CPR,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_CHECKATTRIBUTES, "checkAttributes", .traversal = {TRAV_CHA,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_PROPAGATEATTRIBUTES, "propagateAttributes", .traversal = {TRAV_PRA,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_UNWRAPSETEXPR, "unwrapSetExpr", .traversal = {TRAV_USE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_NODESETCHILDTABLE, "nodesetChildTable", .traversal = {TRAV_NCT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_BUILDSYMBOLTABLE, "buildSymbolTable", .traversal = {TRAV_BST,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_CHECKEXISTANCE, "checkExistance", .traversal = {TRAV_CEX,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENVISITSOURCE, "dynamicGenVisitSource", .traversal = {TRAV_DGVS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENVISITFUNCTIONS, "dynamicGenVisitFunctions", .traversal = {TRAV_DGVF,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENEQUATIONFUNCTIONS, "dynamicGenEquationFunctions", .traversal = {TRAV_DGEF,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENEQUATIONINCLUDES, "dynamicGenEquationIncludes", .traversal = {TRAV_DGEI,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENNODEMACROS, "dynamicGenNodeMacros", .traversal = {TRAV_DGNM,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENNODESETACCESSFUNCTIONS, "dynamicGenNodesetAccessFunctions", .traversal = {TRAV_DGNAF,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENNODESTRUCTS, "dynamicGenNodeStructs", .traversal = {TRAV_DGNS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENNODEINITFUNCTIONS, "dynamicGenNodeInitFunctions", .traversal = {TRAV_DGIF,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENNODEUNION, "dynamicGenNodeUnion", .traversal = {TRAV_DGBU,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENNODECONSTRUCTOR, "dynamicGenNodeConstructor", .traversal = {TRAV_DGNC,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENENUM, "dynamicGenEnum", .traversal = {TRAV_DGE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENENUMVALUES, "dynamicGenEnumValues", .traversal = {TRAV_DGEV,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVVTABLE, "dynamicGenTravVtable", .traversal = {TRAV_DGTV,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENNODESFORTRAVTABLE, "dynamicGenNodesForTravTable", .traversal = {TRAV_DGNFTT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENPASSTABLE, "dynamicGenPassTable", .traversal = {TRAV_DGPT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVTABLE, "dynamicGenTravTable", .traversal = {TRAV_DGTT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENSYSTEMTRAVERSALS, "dynamicGenSystemTraversals", .traversal = {TRAV_DGST,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENACTIONSHEADER, "dynamicGenActionsHeader", .traversal = {TRAV_DGAH,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVACTIONS, "dynamicGenTravActions", .traversal = {TRAV_DGTA,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENCOPYTRAVERSAL, "dynamicGenCopyTraversal", .traversal = {TRAV_DGCT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENCONSTRUCTORCALL, "dynamicGenConstructorCall", .traversal = {TRAV_DGCC,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENFREETRAVERSAL, "dynamicGenFreeTraversal", .traversal = {TRAV_DGFT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENCHECKTRAVERSAL, "dynamicGenCheckTraversal", .traversal = {TRAV_DGCHT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVDATASTRUCTS, "dynamicGenTravDataStructs", .traversal = {TRAV_DGTDS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVDATACTORS, "dynamicGenTravDataCtors", .traversal = {TRAV_DGTDC,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVDATACTORSHEADER, "dynamicGenTravDataCtorsHeader", .traversal = {TRAV_DGTDCH,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVDATAGETTERS, "dynamicGenTravDataGetters", .traversal = {TRAV_DGTDG,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVDATAUNION, "dynamicGenTravDataUnion", .traversal = {TRAV_DGTDU,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVFUNCTIONS, "dynamicGenTravFunctions", .traversal = {TRAV_DGT_F,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GENACTIONARRAY, "genActionArray", .traversal = {TRAV_GAA,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GENACTIONARRAYHEADER, "genActionArrayHeader", .traversal = {TRAV_GAAH,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GENIDSTABLES, "genIdsTables", .traversal = {TRAV_GIT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GENGATEHEADER, "genGateHeader", .traversal = {TRAV_GGH,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICGENTRAVDATATABLES, "dynamicGenTravDataTables", .traversal = {TRAV_DGTDT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_GENDOT, "genDot", .traversal = {TRAV_GD,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICUSERGENEQUATIONS, "dynamicUserGenEquations", .traversal = {TRAV_DUGE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICUSERGENTRAVERSALS, "dynamicUserGenTraversals", .traversal = {TRAV_DUGT,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_DYNAMICUSERGENPASSES, "dynamicUserGenPasses", .traversal = {TRAV_DUGP,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_STATICGENNODESTRUCTS, "staticGenNodeStructs", .traversal = {TRAV_SGNS,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_CHILDRENSETMANDATORY, "childrenSetMandatory", .traversal = {TRAV_CSM,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_MAPIDTOLIFETIME, "mapIdToLifetime", .traversal = {TRAV_MITL,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_ASSIGNIDTOACTION, "assignIdToAction", .traversal = {TRAV_AITA,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_CHECKLIFETIMES, "checkLifetimes", .traversal = {TRAV_CLT,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICSWITCHTOVISITSOURCE, "dynamicSwitchToVisitSource", .pass = {PASS_DYNAMICSWITCHTOVISITSOURCE,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_START_VISIT_HEADER, "dynamic_start_visit_header", .pass = {PASS_DYNAMIC_START_VISIT_HEADER,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_START_EQUATION_HEADER, "dynamic_start_equation_header", .pass = {PASS_DYNAMIC_START_EQUATION_HEADER,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICGENBASENODEINIT, "dynamicGenBaseNodeInit", .pass = {PASS_DYNAMICGENBASENODEINIT,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICSWITCHTOASTSOURCE, "dynamicSwitchToAstSource", .pass = {PASS_DYNAMICSWITCHTOASTSOURCE,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICGENBASENODE, "dynamicGenBaseNode", .pass = {PASS_DYNAMICGENBASENODE,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMIC_START_AST_HEADER, "dynamic_start_ast_header", .pass = {PASS_DYNAMIC_START_AST_HEADER,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICSWITCHTRAVDATA, "dynamicSwitchTravData", .pass = {PASS_DYNAMICSWITCHTRAVDATA,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICSTARTTRAVDATA, "dynamicStartTravData", .pass = {PASS_DYNAMICSTARTTRAVDATA,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICSTARTTABLEGEN, "dynamicStartTableGen", .pass = {PASS_DYNAMICSTARTTABLEGEN,},},
{CCN_ACTION_PASS, CCNAC_ID_DYNAMICSTARTENUMHEADER, "dynamicStartEnumHeader", .pass = {PASS_DYNAMICSTARTENUMHEADER,},},
{CCN_ACTION_PASS, CCNAC_ID_DOOPTS, "doOpts", .pass = {PASS_DOOPTS,},},
{CCN_ACTION_PASS, CCNAC_ID_GENDEFINES, "genDefines", .pass = {PASS_GENDEFINES,},},
{CCN_ACTION_PASS, CCNAC_ID_SCANANDPARSE, "scanAndParse", .pass = {PASS_SCANANDPARSE,},},
{CCN_ACTION_TRAVERSAL, CCNAC_ID_free, "Free", .traversal = {TRAV_free,},},
{CCN_ACTION_PHASE, CCNAC_ID_cleanup, "Cleanup", .phase = {NULL, NT_AST, cleanup_ids_table, false, CCNAC_ID_cleanup,},},
};

struct ccn_action *CCNgetActionFromID(enum ccn_action_id action_id) {
    return &ccn_action_array[action_id];
}

