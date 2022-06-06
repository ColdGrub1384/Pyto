/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Option Parsing Definitions                                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/////////
// Prefixes

#ifdef PREFIX
#define COMMA ,
PREFIX(prefix_0, {nullptr})
PREFIX(prefix_1, {"-" COMMA nullptr})
PREFIX(prefix_4, {"-" COMMA "--" COMMA nullptr})
PREFIX(prefix_3, {"--" COMMA nullptr})
PREFIX(prefix_2, {"/" COMMA "-" COMMA nullptr})
#undef COMMA
#endif // PREFIX

/////////
// Groups

#ifdef OPTION
OPTION(nullptr, "<action group>", Action_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<CompileOnly group>", CompileOnly_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<g group>", DebugInfo_Group, Group, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<W/R group>", Diag_Group, Group, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<I group>", I_Group, Group, IncludePath_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<I/i group>", IncludePath_Group, Group, Preprocessor_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<T/e/s/t/u group>", Link_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<LongDouble group>", LongDouble_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<M group>", M_Group, Group, Preprocessor_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<O group>", O_Group, Group, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<Preprocessor group>", Preprocessor_Group, Group, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<R group>", R_Group, Group, Diag_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<R (with value) group>", R_value_Group, Group, R_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<Static analyzer group>", StaticAnalyzer_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<T group>", T_Group, Group, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<W group>", W_Group, Group, Diag_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<W (with value) group>", W_value_Group, Group, W_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "</M group>", _SLASH_M_Group, Group, cl_compile_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "</volatile group>", _SLASH_volatile_Group, Group, cl_compile_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang-cl options>", cl_Group, Group, INVALID, INVALID, nullptr, 0, 0,
       "CL.EXE COMPATIBILITY OPTIONS", nullptr, nullptr)
OPTION(nullptr, "<clang-cl compile-only options>", cl_compile_Group, Group, cl_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang-cl ignored options>", cl_ignored_Group, Group, cl_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang i group>", clang_i_Group, Group, i_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang ignored f group>", clang_ignored_f_Group, Group, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang_ignored_gcc_optimization_f_Group>", clang_ignored_gcc_optimization_f_Group, Group, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang legacy flags>", clang_ignored_legacy_options_Group, Group, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang ignored m group>", clang_ignored_m_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<d group>", d_Group, Group, Preprocessor_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<f group>", f_Group, Group, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<f (clang-only) group>", f_clang_Group, Group, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<gN group>", gN_Group, Group, g_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<gTune group>", gTune_Group, Group, g_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<g group>", g_Group, Group, DebugInfo_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<g flags group>", g_flags_Group, Group, DebugInfo_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<gfortran group>", gfortran_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<ggdbN group>", ggdbN_Group, Group, gN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<i group>", i_Group, Group, IncludePath_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang internal options>", internal_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<clang debug/development internal options>", internal_debug_Group, Group, internal_Group, INVALID, nullptr, 0, 0,
       "DEBUG/DEVELOPMENT OPTIONS", nullptr, nullptr)
OPTION(nullptr, "<clang driver internal options>", internal_driver_Group, Group, internal_Group, INVALID, nullptr, 0, 0,
       "DRIVER OPTIONS", nullptr, nullptr)
OPTION(nullptr, "<m group>", m_Group, Group, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<aarch64 features group>", m_aarch64_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<amdgpu features group>", m_amdgpu_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<arm features group>", m_arm_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<hexagon features group>", m_hexagon_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<hexagon features group>", m_hexagon_Features_HVX_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<m libc group>", m_libc_Group, Group, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<m68k features group>", m_m68k_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<mips features group>", m_mips_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<ppc features group>", m_ppc_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<riscv features group>", m_riscv_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<wasm driver features group>", m_wasm_Features_Driver_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<wasm features group>", m_wasm_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<x86 features group>", m_x86_Features_Group, Group, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<opencl group>", opencl_Group, Group, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<pedantic group>", pedantic_Group, Group, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<reserved libs group>", reserved_lib_Group, Group, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<SYCL group>", sycl_Group, Group, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(nullptr, "<u group>", u_Group, Group, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)

//////////
// Options

OPTION(prefix_0, &"<input>"[0], INPUT, Input, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_0, &"<unknown>"[0], UNKNOWN, Unknown, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-###"[1], _HASH_HASH_HASH, Flag, INVALID, INVALID, nullptr, NoXarchOption | CoreOption | FlangOption, 0,
       "Print (but do not run) the commands to run for this compilation", nullptr, nullptr)
OPTION(prefix_2, &"/?"[1], _SLASH_QUESTION, Flag, cl_Group, help, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Display available options", nullptr, nullptr)
OPTION(prefix_1, &"-A-"[1], A_DASH, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-add-plugin"[1], add_plugin, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the named plugin action in addition to the default action", "<name>", nullptr)
OPTION(prefix_2, &"/AI"[1], _SLASH_AI, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--all-warnings"[2], _all_warnings, Flag, INVALID, Wall, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-all_load"[1], all__load, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-allowable_client"[1], allowable__client, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--amdgpu-arch-tool="[2], amdgpu_arch_tool_EQ, Joined, i_Group, INVALID, nullptr, 0, 0,
       "Tool used for detecting AMD GPU arch in the system.", nullptr, nullptr)
OPTION(prefix_1, &"-analyze-function="[1], analyze_function_EQ, Joined, INVALID, analyze_function, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyze-function"[1], analyze_function, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run analysis on specific function (for C++ include parameters in name)", nullptr, nullptr)
OPTION(prefix_2, &"/analyze-"[1], _SLASH_analyze_, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker-help-alpha"[1], analyzer_checker_help_alpha, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of in development analyzer checkers. These are NOT considered safe, they are unstable and will emit incorrect reports. Enable ONLY FOR DEVELOPMENT purposes", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker-help-developer"[1], analyzer_checker_help_developer, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of developer-only checkers such as modeling and debug checkers", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker-help"[1], analyzer_checker_help, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of analyzer checkers that are available", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker-option-help-alpha"[1], analyzer_checker_option_help_alpha, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of in development checker and package options. These are NOT considered safe, they are unstable and will emit incorrect reports. Enable ONLY FOR DEVELOPMENT purposes", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker-option-help-developer"[1], analyzer_checker_option_help_developer, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of checker and package options meant for development purposes only", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker-option-help"[1], analyzer_checker_option_help, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of checker and package options", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker="[1], analyzer_checker_EQ, Joined, INVALID, analyzer_checker, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-checker"[1], analyzer_checker, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Choose analyzer checkers to enable", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-config-compatibility-mode="[1], analyzer_config_compatibility_mode_EQ, Joined, INVALID, analyzer_config_compatibility_mode, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-config-compatibility-mode"[1], analyzer_config_compatibility_mode, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't emit errors on invalid analyzer-config inputs", nullptr, "true,false")
OPTION(prefix_1, &"-analyzer-config-help"[1], analyzer_config_help, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of -analyzer-config options. These are meant for development purposes only!", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-config"[1], analyzer_config, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Choose analyzer options to enable", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-constraints="[1], analyzer_constraints_EQ, Joined, INVALID, analyzer_constraints, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-constraints"[1], analyzer_constraints, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Source Code Analysis - Symbolic Constraint Engines", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-disable-all-checks"[1], analyzer_disable_all_checks, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable all static analyzer checks", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-disable-checker="[1], analyzer_disable_checker_EQ, Joined, INVALID, analyzer_disable_checker, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-disable-checker"[1], analyzer_disable_checker, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Choose analyzer checkers to disable", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-disable-retry-exhausted"[1], analyzer_disable_retry_exhausted, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not re-analyze paths leading to exhausted nodes with a different strategy (may decrease code coverage)", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-display-progress"[1], analyzer_display_progress, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit verbose output about the analyzer's progress", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-dump-egraph="[1], analyzer_dump_egraph_EQ, Joined, INVALID, analyzer_dump_egraph, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-dump-egraph"[1], analyzer_dump_egraph, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump exploded graph to the specified file", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-inline-max-stack-depth="[1], analyzer_inline_max_stack_depth_EQ, Joined, INVALID, analyzer_inline_max_stack_depth, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-inline-max-stack-depth"[1], analyzer_inline_max_stack_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Bound on stack depth while inlining (4 by default)", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-inlining-mode="[1], analyzer_inlining_mode_EQ, Joined, INVALID, analyzer_inlining_mode, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-inlining-mode"[1], analyzer_inlining_mode, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Specify the function selection heuristic used during inlining", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-list-enabled-checkers"[1], analyzer_list_enabled_checkers, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of enabled analyzer checkers", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-max-loop"[1], analyzer_max_loop, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The maximum number of times the analyzer will go through a loop", nullptr, nullptr)
OPTION(prefix_3, &"--analyzer-no-default-checks"[2], _analyzer_no_default_checks, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-opt-analyze-headers"[1], analyzer_opt_analyze_headers, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Force the static analyzer to analyze functions defined in header files", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-opt-analyze-nested-blocks"[1], analyzer_opt_analyze_nested_blocks, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Analyze the definitions of blocks in addition to functions", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-output="[1], analyzer_output_EQ, Joined, INVALID, analyzer_output, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--analyzer-output"[2], _analyzer_output, JoinedOrSeparate, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Static analyzer report output format (html|plist|plist-multi-file|plist-html|sarif|sarif-html|text).", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-output"[1], analyzer_output, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Source Code Analysis - Output Options", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-purge="[1], analyzer_purge_EQ, Joined, INVALID, analyzer_purge, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-purge"[1], analyzer_purge, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Source Code Analysis - Dead Symbol Removal Frequency", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-stats"[1], analyzer_stats, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print internal analyzer statistics.", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-store="[1], analyzer_store_EQ, Joined, INVALID, analyzer_store, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-store"[1], analyzer_store, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Source Code Analysis - Abstract Memory Store Models", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-viz-egraph-graphviz"[1], analyzer_viz_egraph_graphviz, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display exploded graph using GraphViz", nullptr, nullptr)
OPTION(prefix_1, &"-analyzer-werror"[1], analyzer_werror, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit analyzer results as errors rather than warnings", nullptr, nullptr)
OPTION(prefix_3, &"--analyze"[2], _analyze, Flag, INVALID, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Run the static analyzer", nullptr, nullptr)
OPTION(prefix_1, &"-analyze"[1], analyze, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run static analysis engine", nullptr, nullptr)
OPTION(prefix_4, &"-ansi"[1], ansi, Flag, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/arch:"[1], _SLASH_arch, Joined, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Set architecture for code generation", nullptr, nullptr)
OPTION(prefix_1, &"-arch_errors_fatal"[1], arch__errors__fatal, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-arch_only"[1], arch__only, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-arch"[1], arch, Separate, INVALID, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-arcmt-action="[1], arcmt_action_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The ARC migration action to take", nullptr, "check,modify,migrate")
OPTION(prefix_1, &"-arcmt-migrate-emit-errors"[1], arcmt_migrate_emit_arc_errors, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Emit ARC errors even if the migrator can fix them", nullptr, nullptr)
OPTION(prefix_1, &"-arcmt-migrate-report-output"[1], arcmt_migrate_report_output, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Output path for the plist report", nullptr, nullptr)
OPTION(prefix_3, &"--assemble"[2], _assemble, Flag, INVALID, S, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--assert="[2], _assert_EQ, Joined, INVALID, A, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--assert"[2], _assert, Separate, INVALID, A, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ast-dump-all="[1], ast_dump_all_EQ, Joined, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and then debug dump them in the specified format, forcing deserialization. Supported formats include: default, json", nullptr, nullptr)
OPTION(prefix_1, &"-ast-dump-all"[1], ast_dump_all, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and then debug dump them, forcing deserialization", nullptr, nullptr)
OPTION(prefix_1, &"-ast-dump-decl-types"[1], ast_dump_decl_types, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include declaration types in AST dumps", nullptr, nullptr)
OPTION(prefix_1, &"-ast-dump-filter="[1], ast_dump_filter_EQ, Joined, INVALID, ast_dump_filter, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ast-dump-filter"[1], ast_dump_filter, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use with -ast-dump or -ast-print to dump/print only AST declaration nodes having a certain substring in a qualified name. Use -ast-list to list all filterable declaration node names.", "<dump_filter>", nullptr)
OPTION(prefix_1, &"-ast-dump-lookups"[1], ast_dump_lookups, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and then debug dump their name lookup tables", nullptr, nullptr)
OPTION(prefix_1, &"-ast-dump="[1], ast_dump_EQ, Joined, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and then debug dump them in the specified format. Supported formats include: default, json", nullptr, nullptr)
OPTION(prefix_1, &"-ast-dump"[1], ast_dump, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and then debug dump them", nullptr, nullptr)
OPTION(prefix_1, &"-ast-list"[1], ast_list, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and print the list of declaration node qualified names", nullptr, nullptr)
OPTION(prefix_1, &"-ast-merge"[1], ast_merge, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Merge the given AST file into the translation unit being compiled.", "<ast file>", nullptr)
OPTION(prefix_1, &"-ast-print"[1], ast_print, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and then pretty-print them", nullptr, nullptr)
OPTION(prefix_1, &"-ast-view"[1], ast_view, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and view them with GraphViz", nullptr, nullptr)
OPTION(prefix_3, &"--autocomplete="[2], autocomplete, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-aux-target-cpu"[1], aux_target_cpu, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Target a specific auxiliary cpu type", nullptr, nullptr)
OPTION(prefix_1, &"-aux-target-feature"[1], aux_target_feature, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Target specific auxiliary attributes", nullptr, nullptr)
OPTION(prefix_1, &"-aux-triple"[1], aux_triple, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Auxiliary target triple.", nullptr, nullptr)
OPTION(prefix_2, &"/await:"[1], _SLASH_await_COLON, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/await"[1], _SLASH_await, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-A"[1], A, JoinedOrSeparate, gfortran_Group, INVALID, nullptr, RenderJoined, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-a"[1], a, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/bigobj"[1], _SLASH_bigobj, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-bind_at_load"[1], bind__at__load, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--bootclasspath="[2], _bootclasspath_EQ, Joined, INVALID, fbootclasspath_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--bootclasspath"[2], _bootclasspath, Separate, INVALID, fbootclasspath_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Brepro-"[1], _SLASH_Brepro_, Flag, cl_Group, mincremental_linker_compatible, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Write current time into COFF output (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Brepro"[1], _SLASH_Brepro, Flag, cl_Group, mno_incremental_linker_compatible, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not write current time into COFF output (breaks link.exe /incremental)", nullptr, nullptr)
OPTION(prefix_2, &"/Bt+"[1], _SLASH_Bt_plus, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Bt"[1], _SLASH_Bt, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-building-pch-with-obj"[1], building_pch_with_obj, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "This compilation is part of building a PCH with corresponding object file.", nullptr, nullptr)
OPTION(prefix_1, &"-bundle_loader"[1], bundle__loader, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-bundle"[1], bundle, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-B"[1], B, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0,
       "Search $prefix/$triple-$file and $prefix$file for executables, libraries, includes, and data files used by the compiler. $prefix may or may not be a directory", "<prefix>", nullptr)
OPTION(prefix_1, &"-b"[1], b, JoinedOrSeparate, Link_Group, INVALID, nullptr, LinkerInput | RenderAsInput, 0,
       "Pass -b <arg> to the linker on AIX (only).", "<arg>", nullptr)
OPTION(prefix_1, &"-c-isystem"[1], c_isystem, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add directory to the C SYSTEM include search path", "<directory>", nullptr)
OPTION(prefix_1, &"-canonical-prefixes"[1], canonical_prefixes, Flag, INVALID, INVALID, nullptr, HelpHidden | CoreOption, 0,
       "Use absolute paths for invoking subcommands (default)", nullptr, nullptr)
OPTION(prefix_1, &"-cc1as"[1], cc1as, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-cc1"[1], cc1, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ccc-arcmt-check"[1], ccc_arcmt_check, Flag, internal_driver_Group, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "Check for ARC migration issues that need manual handling", nullptr, nullptr)
OPTION(prefix_1, &"-ccc-arcmt-migrate"[1], ccc_arcmt_migrate, Separate, internal_driver_Group, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "Apply modifications and produces temporary files that conform to ARC", nullptr, nullptr)
OPTION(prefix_1, &"-ccc-arcmt-modify"[1], ccc_arcmt_modify, Flag, internal_driver_Group, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "Apply modifications to files to conform to ARC", nullptr, nullptr)
OPTION(prefix_1, &"-ccc-gcc-name"[1], ccc_gcc_name, Separate, internal_driver_Group, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "Name for native GCC compiler", "<gcc-path>", nullptr)
OPTION(prefix_1, &"-ccc-install-dir"[1], ccc_install_dir, Separate, internal_debug_Group, INVALID, nullptr, NoXarchOption | HelpHidden | CoreOption, 0,
       "Simulate installation in the given directory", nullptr, nullptr)
OPTION(prefix_1, &"-ccc-objcmt-migrate"[1], ccc_objcmt_migrate, Separate, internal_driver_Group, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "Apply modifications and produces temporary files to migrate to modern ObjC syntax", nullptr, nullptr)
OPTION(prefix_1, &"-ccc-print-bindings"[1], ccc_print_bindings, Flag, internal_debug_Group, INVALID, nullptr, NoXarchOption | HelpHidden | CoreOption, 0,
       "Show bindings of tools to actions", nullptr, nullptr)
OPTION(prefix_1, &"-ccc-print-phases"[1], ccc_print_phases, Flag, internal_debug_Group, INVALID, nullptr, NoXarchOption | HelpHidden | CoreOption, 0,
       "Dump list of actions to perform", nullptr, nullptr)
OPTION(prefix_1, &"-ccc-"[1], ccc_, Joined, internal_Group, INVALID, nullptr, Unsupported | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-CC"[1], CC, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option, 0,
       "Include comments from within macros in preprocessed output", nullptr, nullptr)
OPTION(prefix_1, &"-cfg-add-implicit-dtors"[1], analysis_CFGAddImplicitDtors, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add C++ implicit destructors to CFGs for all analyses", nullptr, nullptr)
OPTION(prefix_1, &"-cfguard-no-checks"[1], cfguard_no_checks, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit Windows Control Flow Guard tables only (no checks)", nullptr, nullptr)
OPTION(prefix_1, &"-cfguard"[1], cfguard, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit Windows Control Flow Guard tables and checks", nullptr, nullptr)
OPTION(prefix_2, &"/cgthreads"[1], _SLASH_cgthreads, Joined, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-chain-include"[1], chain_include, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include and chain a header file after turning it into PCH", "<file>", nullptr)
OPTION(prefix_1, &"-cl-denorms-are-zero"[1], cl_denorms_are_zero, Flag, opencl_Group, INVALID, nullptr, 0, 0,
       "OpenCL only. Allow denormals to be flushed to zero.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-ext="[1], cl_ext_EQ, CommaJoined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "OpenCL only. Enable or disable OpenCL extensions. The argument is a comma-separated sequence of one or more extension names, each prefixed by '+' or '-'.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-fast-relaxed-math"[1], cl_fast_relaxed_math, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Sets -cl-finite-math-only and -cl-unsafe-math-optimizations, and defines __FAST_RELAXED_MATH__.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-finite-math-only"[1], cl_finite_math_only, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow floating-point optimizations that assume arguments and results are not NaNs or +-Inf.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-fp32-correctly-rounded-divide-sqrt"[1], cl_fp32_correctly_rounded_divide_sqrt, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Specify that single precision floating-point divide and sqrt used in the program source are correctly rounded.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-kernel-arg-info"[1], cl_kernel_arg_info, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Generate kernel argument metadata.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-mad-enable"[1], cl_mad_enable, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow use of less precise MAD computations in the generated binary.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-no-signed-zeros"[1], cl_no_signed_zeros, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow use of less precise no signed zeros computations in the generated binary.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-no-stdinc"[1], cl_no_stdinc, Flag, opencl_Group, INVALID, nullptr, 0, 0,
       "OpenCL only. Disables all standard includes containing non-native compiler types and functions.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-opt-disable"[1], cl_opt_disable, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. This option disables all optimizations. By default optimizations are enabled.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-single-precision-constant"[1], cl_single_precision_constant, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Treat double precision floating-point constant as single precision constant.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-std="[1], cl_std_EQ, Joined, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL language standard to compile for.", nullptr, "cl,CL,cl1.0,CL1.0,cl1.1,CL1.1,cl1.2,CL1.2,cl2.0,CL2.0,cl3.0,CL3.0,clc++,CLC++,clc++1.0,CLC++1.0,clc++2021,CLC++2021")
OPTION(prefix_1, &"-cl-strict-aliasing"[1], cl_strict_aliasing, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. This option is added for compatibility with OpenCL 1.0.", nullptr, nullptr)
OPTION(prefix_1, &"-cl-uniform-work-group-size"[1], cl_uniform_work_group_size, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Defines that the global work-size be a multiple of the work-group size specified to clEnqueueNDRangeKernel", nullptr, nullptr)
OPTION(prefix_1, &"-cl-unsafe-math-optimizations"[1], cl_unsafe_math_optimizations, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow unsafe floating-point optimizations.  Also implies -cl-no-signed-zeros and -cl-mad-enable.", nullptr, nullptr)
OPTION(prefix_2, &"/clang:"[1], _SLASH_clang, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Pass <arg> to the clang driver", "<arg>", nullptr)
OPTION(prefix_3, &"--CLASSPATH="[2], _CLASSPATH_EQ, Joined, INVALID, fclasspath_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--classpath="[2], _classpath_EQ, Joined, INVALID, fclasspath_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--CLASSPATH"[2], _CLASSPATH, Separate, INVALID, fclasspath_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--classpath"[2], _classpath, Separate, INVALID, fclasspath_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-clear-ast-before-backend"[1], clear_ast_before_backend, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Clear the Clang AST before running backend code generation", nullptr, nullptr)
OPTION(prefix_1, &"-client_name"[1], client__name, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/clr"[1], _SLASH_clr, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-code-completion-at="[1], code_completion_at_EQ, Joined, INVALID, code_completion_at, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-code-completion-at"[1], code_completion_at, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump code-completion information at a location", "<file>:<line>:<column>", nullptr)
OPTION(prefix_1, &"-code-completion-brief-comments"[1], code_completion_brief_comments, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include brief documentation comments in code-completion results.", nullptr, nullptr)
OPTION(prefix_1, &"-code-completion-macros"[1], code_completion_macros, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include macros in code-completion results", nullptr, nullptr)
OPTION(prefix_1, &"-code-completion-patterns"[1], code_completion_patterns, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include code patterns in code-completion results", nullptr, nullptr)
OPTION(prefix_1, &"-code-completion-with-fixits"[1], code_completion_with_fixits, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include code completion results which require small fix-its.", nullptr, nullptr)
OPTION(prefix_4, &"-combine"[1], combine, Flag, INVALID, INVALID, nullptr, NoXarchOption | Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--comments-in-macros"[2], _comments_in_macros, Flag, INVALID, CC, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--comments"[2], _comments, Flag, INVALID, C, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-compatibility_version"[1], compatibility__version, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-compiler-options-dump"[1], compiler_options_dump, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump the compiler configuration options", nullptr, nullptr)
OPTION(prefix_3, &"--compile"[2], _compile, Flag, INVALID, c, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-compress-debug-sections="[1], compress_debug_sections_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "DWARF debug sections compression type", nullptr, "none,zlib,zlib-gnu")
OPTION(prefix_4, &"-compress-debug-sections"[1], compress_debug_sections, Flag, INVALID, compress_debug_sections_EQ, "zlib\0", CC1Option | CC1AsOption | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--config-system-dir="[2], config_system_dir_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "System directory for configuration files", nullptr, nullptr)
OPTION(prefix_3, &"--config-user-dir="[2], config_user_dir_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "User directory for configuration files", nullptr, nullptr)
OPTION(prefix_3, &"--config"[2], config, Separate, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Specifies configuration file", nullptr, nullptr)
OPTION(prefix_3, &"--constant-cfstrings"[2], _constant_cfstrings, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/constexpr:"[1], _SLASH_constexpr, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-coverage-data-file="[1], coverage_data_file_EQ, Joined, INVALID, coverage_data_file, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-coverage-data-file"[1], coverage_data_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit coverage data to this filename.", nullptr, nullptr)
OPTION(prefix_1, &"-coverage-notes-file="[1], coverage_notes_file_EQ, Joined, INVALID, coverage_notes_file, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-coverage-notes-file"[1], coverage_notes_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit coverage notes to this filename.", nullptr, nullptr)
OPTION(prefix_1, &"-coverage-version="[1], coverage_version_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Four-byte version string for gcov files.", nullptr, nullptr)
OPTION(prefix_4, &"-coverage"[1], coverage, Flag, Link_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-cpp-precomp"[1], cpp_precomp, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-cpp"[1], cpp, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Enable predefined and command line preprocessor macros", nullptr, nullptr)
OPTION(prefix_3, &"--cuda-compile-host-device"[2], cuda_compile_host_device, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Compile CUDA code for both host and device (default).  Has no effect on non-CUDA compilations.", nullptr, nullptr)
OPTION(prefix_3, &"--cuda-device-only"[2], cuda_device_only, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Compile CUDA code for device only", nullptr, nullptr)
OPTION(prefix_3, &"--cuda-gpu-arch="[2], cuda_gpu_arch_EQ, Joined, INVALID, offload_arch_EQ, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--cuda-host-only"[2], cuda_host_only, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Compile CUDA code for host only.  Has no effect on non-CUDA compilations.", nullptr, nullptr)
OPTION(prefix_3, &"--cuda-include-ptx="[2], cuda_include_ptx_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Include PTX for the following GPU architecture (e.g. sm_35) or 'all'. May be specified more than once.", nullptr, nullptr)
OPTION(prefix_3, &"--cuda-noopt-device-debug"[2], cuda_noopt_device_debug, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Enable device-side debug info generation. Disables ptxas optimizations.", nullptr, nullptr)
OPTION(prefix_3, &"--cuda-path-ignore-env"[2], cuda_path_ignore_env, Flag, i_Group, INVALID, nullptr, 0, 0,
       "Ignore environment variables to detect CUDA installation", nullptr, nullptr)
OPTION(prefix_3, &"--cuda-path="[2], cuda_path_EQ, Joined, i_Group, INVALID, nullptr, 0, 0,
       "CUDA installation path", nullptr, nullptr)
OPTION(prefix_1, &"-cuid="[1], cuid_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "An ID for compilation unit, which should be the same for the same compilation unit but different for different compilation units. It is used to externalize device-side static variables for single source offloading languages CUDA and HIP so that they can be accessed by the host code of the same compilation unit.", nullptr, nullptr)
OPTION(prefix_1, &"-current_version"[1], current__version, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-cxx-isystem"[1], cxx_isystem, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Add directory to the C++ SYSTEM include search path", "<directory>", nullptr)
OPTION(prefix_1, &"-C"[1], C, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option, 0,
       "Include comments in preprocessed output", nullptr, nullptr)
OPTION(prefix_2, &"/C"[1], _SLASH_C, Flag, cl_Group, C, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not discard comments when preprocessing", nullptr, nullptr)
OPTION(prefix_1, &"-c"[1], c, Flag, Action_Group, INVALID, nullptr, NoXarchOption | FlangOption, 0,
       "Only run preprocess, compile, and assemble steps", nullptr, nullptr)
OPTION(prefix_2, &"/c"[1], _SLASH_c, Flag, cl_Group, c, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Compile only", nullptr, nullptr)
OPTION(prefix_2, &"/d1PP"[1], _SLASH_d1PP, Flag, cl_Group, dD, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Retain macro definitions in /E mode", nullptr, nullptr)
OPTION(prefix_2, &"/d1reportAllClassLayout"[1], _SLASH_d1reportAllClassLayout, Flag, cl_Group, Xclang, "-fdump-record-layouts\0", CLOption | NoXarchOption | CLOption, 0,
       "Dump record layout information", nullptr, nullptr)
OPTION(prefix_2, &"/d2FastFail"[1], _SLASH_d2FastFail, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/d2Zi+"[1], _SLASH_d2Zi_PLUS, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/d2"[1], _SLASH_d2, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dA"[1], dA, Flag, INVALID, fverbose_asm, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dD"[1], dD, Flag, d_Group, INVALID, nullptr, CC1Option, 0,
       "Print macro definitions in -E mode in addition to normal output", nullptr, nullptr)
OPTION(prefix_1, &"-dead_strip"[1], dead__strip, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-debug-forward-template-params"[1], debug_forward_template_params, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit complete descriptions of template parameters in forward declarations", nullptr, nullptr)
OPTION(prefix_1, &"-debug-info-kind="[1], debug_info_kind_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-debug-info-macro"[1], debug_info_macro, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Emit macro debug information", nullptr, nullptr)
OPTION(prefix_3, &"--debug="[2], _debug_EQ, Joined, INVALID, g_Flag, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-debugger-tuning="[1], debugger_tuning_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0, nullptr, nullptr, "gdb,lldb,sce,dbx")
OPTION(prefix_3, &"--debug"[2], _debug, Flag, INVALID, g_Flag, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-default-function-attr"[1], default_function_attr, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Apply given attribute to all functions", nullptr, nullptr)
OPTION(prefix_3, &"--define-macro="[2], _define_macro_EQ, Joined, INVALID, D, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--define-macro"[2], _define_macro, Separate, INVALID, D, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-defsym"[1], defsym, Separate, INVALID, INVALID, nullptr, CC1AsOption | NoDriverOption, 0,
       "Define a value for a symbol", nullptr, nullptr)
OPTION(prefix_3, &"--dependencies"[2], _dependencies, Flag, INVALID, M, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dependency-dot"[1], dependency_dot, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Filename to write DOT-formatted header dependencies to", nullptr, nullptr)
OPTION(prefix_1, &"-dependency-file"[1], dependency_file, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Filename (or -) to write dependency output to", nullptr, nullptr)
OPTION(prefix_3, &"--dependent-lib="[2], dependent_lib, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add dependent library", nullptr, nullptr)
OPTION(prefix_1, &"-detailed-preprocessing-record"[1], detailed_preprocessing_record, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "include a detailed record of preprocessing actions", nullptr, nullptr)
OPTION(prefix_1, &"-diagnostic-log-file"[1], diagnostic_log_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename (or -) to log diagnostics to", nullptr, nullptr)
OPTION(prefix_2, &"/diagnostics:caret"[1], _SLASH_diagnostics_caret, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable caret and column diagnostics (default)", nullptr, nullptr)
OPTION(prefix_2, &"/diagnostics:classic"[1], _SLASH_diagnostics_classic, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable column and caret diagnostics", nullptr, nullptr)
OPTION(prefix_2, &"/diagnostics:column"[1], _SLASH_diagnostics_column, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable caret diagnostics but keep column info", nullptr, nullptr)
OPTION(prefix_2, &"/diasdkdir"[1], _SLASH_diasdkdir, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Path to the DIA SDK", "<dir>", nullptr)
OPTION(prefix_1, &"-disable-free"[1], disable_free, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable freeing of memory on exit", nullptr, nullptr)
OPTION(prefix_1, &"-disable-lifetime-markers"[1], disable_lifetimemarkers, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable lifetime-markers emission even when optimizations are enabled", nullptr, nullptr)
OPTION(prefix_1, &"-disable-llvm-optzns"[1], disable_llvm_optzns, Flag, INVALID, disable_llvm_passes, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-disable-llvm-passes"[1], disable_llvm_passes, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use together with -emit-llvm to get pristine LLVM IR from the frontend by not running any LLVM passes at all", nullptr, nullptr)
OPTION(prefix_1, &"-disable-llvm-verifier"[1], disable_llvm_verifier, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't run the LLVM IR verifier pass", nullptr, nullptr)
OPTION(prefix_1, &"-disable-O0-optnone"[1], disable_O0_optnone, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable adding the optnone attribute to functions at O0", nullptr, nullptr)
OPTION(prefix_1, &"-disable-objc-default-synthesize-properties"[1], disable_objc_default_synthesize_properties, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "disable the default synthesis of Objective-C properties", nullptr, nullptr)
OPTION(prefix_1, &"-disable-pragma-debug-crash"[1], disable_pragma_debug_crash, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable any #pragma clang __debug that can lead to crashing behavior. This is meant for testing.", nullptr, nullptr)
OPTION(prefix_1, &"-disable-red-zone"[1], disable_red_zone, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not emit code that uses the red zone.", nullptr, nullptr)
OPTION(prefix_1, &"-discard-value-names"[1], discard_value_names, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Discard value names in LLVM IR", nullptr, nullptr)
OPTION(prefix_1, &"-dI"[1], dI, Flag, d_Group, INVALID, nullptr, CC1Option, 0,
       "Print include directives in -E mode in addition to normal output", nullptr, nullptr)
OPTION(prefix_1, &"-dM"[1], dM, Flag, d_Group, INVALID, nullptr, CC1Option, 0,
       "Print macro definitions in -E mode instead of normal output", nullptr, nullptr)
OPTION(prefix_2, &"/doc"[1], _SLASH_doc, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--driver-mode="[2], driver_mode, Joined, internal_driver_Group, INVALID, nullptr, CoreOption | NoXarchOption | HelpHidden, 0,
       "Set the driver mode to either 'gcc', 'g++', 'cpp', or 'cl'", nullptr, nullptr)
OPTION(prefix_1, &"-dsym-dir"[1], dsym_dir, JoinedOrSeparate, INVALID, INVALID, nullptr, NoXarchOption | RenderAsInput, 0,
       "Directory to output dSYM's (if any) to", "<dir>", nullptr)
OPTION(prefix_1, &"-dump-coverage-mapping"[1], dump_coverage_mapping, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump the coverage mapping records, for testing", nullptr, nullptr)
OPTION(prefix_1, &"-dump-deserialized-decls"[1], dump_deserialized_pch_decls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump declarations that are deserialized from PCH, for testing", nullptr, nullptr)
OPTION(prefix_1, &"-dump-raw-tokens"[1], dump_raw_tokens, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Lex file in raw mode and dump raw tokens", nullptr, nullptr)
OPTION(prefix_1, &"-dump-tokens"[1], dump_tokens, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run preprocessor, dump internal rep of tokens", nullptr, nullptr)
OPTION(prefix_1, &"-dumpmachine"[1], dumpmachine, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dumpspecs"[1], dumpspecs, Flag, INVALID, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dumpversion"[1], dumpversion, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dwarf-debug-flags"[1], dwarf_debug_flags, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "The string to embed in the Dwarf debug flags record.", nullptr, nullptr)
OPTION(prefix_1, &"-dwarf-debug-producer"[1], dwarf_debug_producer, Separate, INVALID, INVALID, nullptr, CC1AsOption | NoDriverOption, 0,
       "The string to embed in the Dwarf debug AT_producer record.", nullptr, nullptr)
OPTION(prefix_1, &"-dwarf-explicit-import"[1], dwarf_explicit_import, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate explicit import from anonymous namespace to containing scope", nullptr, nullptr)
OPTION(prefix_1, &"-dwarf-ext-refs"[1], dwarf_ext_refs, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate debug info with external references to clang modules or precompiled headers", nullptr, nullptr)
OPTION(prefix_1, &"-dwarf-version="[1], dwarf_version_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--dyld-prefix="[2], _dyld_prefix_EQ, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--dyld-prefix"[2], _dyld_prefix, Separate, INVALID, _dyld_prefix_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dylib_file"[1], dylib__file, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dylinker_install_name"[1], dylinker__install__name, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dylinker"[1], dylinker, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dynamiclib"[1], dynamiclib, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-dynamic"[1], dynamic, Flag, INVALID, INVALID, nullptr, NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-D"[1], D, JoinedOrSeparate, Preprocessor_Group, INVALID, nullptr, CC1Option | FlangOption | FC1Option, 0,
       "Define <macro> to <value> (or 1 if <value> omitted)", "<macro>=<value>", nullptr)
OPTION(prefix_2, &"/D"[1], _SLASH_D, JoinedOrSeparate, cl_Group, D, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Define macro", "<macro[=value]>", nullptr)
OPTION(prefix_1, &"-d"[1], d_Flag, Flag, d_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-d"[1], d_Joined, Joined, d_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-EB"[1], EB, Flag, INVALID, mbig_endian, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ehcontguard"[1], ehcontguard, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit Windows EH Continuation Guard tables", nullptr, nullptr)
OPTION(prefix_2, &"/EH"[1], _SLASH_EH, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set exception handling model", nullptr, nullptr)
OPTION(prefix_1, &"-EL"[1], EL, Flag, INVALID, mlittle_endian, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-emit-ast"[1], emit_ast, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Emit Clang AST files for source inputs", nullptr, nullptr)
OPTION(prefix_1, &"-emit-codegen-only"[1], emit_codegen_only, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate machine code, but discard output", nullptr, nullptr)
OPTION(prefix_1, &"-emit-header-module"[1], emit_header_module, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate pre-compiled module file from a set of header files", nullptr, nullptr)
OPTION(prefix_1, &"-emit-html"[1], emit_html, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Output input source as HTML", nullptr, nullptr)
OPTION(prefix_1, &"-emit-interface-stubs"[1], emit_interface_stubs, Flag, Action_Group, INVALID, nullptr, CC1Option, 0,
       "Generate Interface Stub Files.", nullptr, nullptr)
OPTION(prefix_1, &"-emit-llvm-bc"[1], emit_llvm_bc, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs then convert to LLVM, emit .bc file", nullptr, nullptr)
OPTION(prefix_1, &"-emit-llvm-only"[1], emit_llvm_only, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and convert to LLVM, discarding output", nullptr, nullptr)
OPTION(prefix_1, &"-emit-llvm-uselists"[1], emit_llvm_uselists, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve order of LLVM use-lists when serializing", nullptr, nullptr)
OPTION(prefix_1, &"-emit-llvm"[1], emit_llvm, Flag, Action_Group, INVALID, nullptr, CC1Option, 0,
       "Use the LLVM representation for assembler and object files", nullptr, nullptr)
OPTION(prefix_1, &"-emit-merged-ifs"[1], emit_merged_ifs, Flag, Action_Group, INVALID, nullptr, CC1Option, 0,
       "Generate Interface Stub Files, emit merged text not binary.", nullptr, nullptr)
OPTION(prefix_1, &"-emit-module-interface"[1], emit_module_interface, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate pre-compiled module file from a C++ module interface", nullptr, nullptr)
OPTION(prefix_1, &"-emit-module"[1], emit_module, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate pre-compiled module file from a module map", nullptr, nullptr)
OPTION(prefix_1, &"-emit-obj"[1], emit_obj, Flag, Action_Group, INVALID, nullptr, CC1Option | FC1Option | NoDriverOption, 0,
       "Emit native object files", nullptr, nullptr)
OPTION(prefix_1, &"-emit-pch"[1], emit_pch, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate pre-compiled header file", nullptr, nullptr)
OPTION(prefix_3, &"--emit-static-lib"[2], emit_static_lib, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Enable linker job to emit a static library.", nullptr, nullptr)
OPTION(prefix_1, &"-enable-noundef-analysis"[1], enable_noundef_analysis, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable analyzing function argument and return types for mandatory definedness", nullptr, nullptr)
OPTION(prefix_1, &"-enable-trivial-auto-var-init-zero-knowing-it-will-be-removed-from-clang"[1], enable_trivial_var_init_zero, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption | NoArgumentUnused, 0,
       "Trivial automatic variable initialization to zero is only here for benchmarks, it'll eventually be removed, and I'm OK with that because I'm only using it to benchmark", nullptr, nullptr)
OPTION(prefix_3, &"--encoding="[2], _encoding_EQ, Joined, INVALID, fencoding_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--encoding"[2], _encoding, Separate, INVALID, fencoding_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--entry"[2], _entry, Flag, INVALID, e, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Eonly"[1], Eonly, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Just run preprocessor, no output (for timings)", nullptr, nullptr)
OPTION(prefix_2, &"/EP"[1], _SLASH_EP, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable linemarker output and preprocess to stdout", nullptr, nullptr)
OPTION(prefix_1, &"-error-on-deserialized-decl="[1], error_on_deserialized_pch_decl_EQ, Joined, INVALID, error_on_deserialized_pch_decl, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-error-on-deserialized-decl"[1], error_on_deserialized_pch_decl, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit error if a specific declaration is deserialized from PCH, for testing", nullptr, nullptr)
OPTION(prefix_2, &"/errorReport"[1], _SLASH_errorReport, Joined, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-exception-model="[1], exception_model_EQ, Joined, INVALID, exception_model, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-exception-model"[1], exception_model, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The exception model: dwarf|sjlj|seh|wasm", nullptr, "dwarf,sjlj,seh,wasm")
OPTION(prefix_2, &"/execution-charset:"[1], _SLASH_execution_charset, Joined, cl_compile_Group, fexec_charset_EQ, nullptr, CLOption | NoXarchOption, 0,
       "Set runtime encoding, supports only UTF-8", nullptr, nullptr)
OPTION(prefix_2, &"/experimental:"[1], _SLASH_experimental, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-exported_symbols_list"[1], exported__symbols__list, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/exportHeader"[1], _SLASH_exportHeader, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--extdirs="[2], _extdirs_EQ, Joined, INVALID, fextdirs_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--extdirs"[2], _extdirs, Separate, INVALID, fextdirs_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/external:env:"[1], _SLASH_external_env, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Add dirs in env var <var> to include search path with warnings suppressed", "<var>", nullptr)
OPTION(prefix_2, &"/external:I"[1], _SLASH_external_COLON_I, JoinedOrSeparate, cl_Group, isystem, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Add directory to include search path with warnings suppressed", "<dir>", nullptr)
OPTION(prefix_2, &"/external:"[1], _SLASH_external, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--extra-warnings"[2], _extra_warnings, Flag, INVALID, W_Joined, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-E"[1], E, Flag, Action_Group, INVALID, nullptr, NoXarchOption | CC1Option | FlangOption | FC1Option, 0,
       "Only run the preprocessor", nullptr, nullptr)
OPTION(prefix_2, &"/E"[1], _SLASH_E, Flag, cl_Group, E, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Preprocess to stdout", nullptr, nullptr)
OPTION(prefix_1, &"-e"[1], e, JoinedOrSeparate, Link_Group, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-faapcs-bitfield-load"[1], ForceAAPCSBitfieldLoad, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Follows the AAPCS standard that all volatile bit-field write generates at least one load. (ARM only).", nullptr, nullptr)
OPTION(prefix_1, &"-faapcs-bitfield-width"[1], faapcs_bitfield_width, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Follow the AAPCS standard requirement stating that volatile bit-field width is dictated by the field container type. (ARM only).", nullptr, nullptr)
OPTION(prefix_1, &"-faccess-control"[1], faccess_control, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-faddress-space-map-mangling="[1], faddress_space_map_mangling_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the mode for address space map based mangling; OpenCL testing purposes only", "<yes|no|target>", "target,no,yes")
OPTION(prefix_1, &"-faddrsig"[1], faddrsig, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Emit an address-significance table", nullptr, nullptr)
OPTION(prefix_1, &"-faggressive-function-elimination"[1], faggressive_function_elimination, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-commons"[1], falign_commons, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-functions="[1], falign_functions_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-functions"[1], falign_functions, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-jumps="[1], falign_jumps_EQ, Joined, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-jumps"[1], falign_jumps, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-labels="[1], falign_labels_EQ, Joined, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-labels"[1], falign_labels, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falign-loops="[1], falign_loops_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "N must be a power of two. Align loops to the boundary", "<N>", nullptr)
OPTION(prefix_1, &"-falign-loops"[1], falign_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-faligned-alloc-unavailable"[1], aligned_alloc_unavailable, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Aligned allocation/deallocation functions are unavailable", nullptr, nullptr)
OPTION(prefix_1, &"-faligned-allocation"[1], faligned_allocation, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++17 aligned allocation functions", nullptr, nullptr)
OPTION(prefix_1, &"-faligned-new="[1], faligned_new_EQ, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-faligned-new"[1], anonymous_838, Flag, INVALID, faligned_allocation, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fall-intrinsics"[1], fall_intrinsics, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fallow-editor-placeholders"[1], fallow_editor_placeholders, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Treat editor placeholders as valid source code", nullptr, nullptr)
OPTION(prefix_1, &"-fallow-half-arguments-and-returns"[1], fallow_half_arguments_and_returns, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow function arguments and returns of type half", nullptr, nullptr)
OPTION(prefix_1, &"-fallow-pch-with-compiler-errors"[1], fallow_pch_with_errors, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Accept a PCH file that was created with compiler errors", nullptr, nullptr)
OPTION(prefix_1, &"-fallow-pch-with-different-modules-cache-path"[1], fallow_pch_with_different_modules_cache_path, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Accept a PCH file that was created with a different modules cache path", nullptr, nullptr)
OPTION(prefix_1, &"-fallow-pcm-with-compiler-errors"[1], fallow_pcm_with_errors, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Accept a PCM file that was created with compiler errors", nullptr, nullptr)
OPTION(prefix_1, &"-fallow-unsupported"[1], fallow_unsupported, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-falternative-parameter-statement"[1], falternative_parameter_statement, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Enable the old style PARAMETER statement", nullptr, nullptr)
OPTION(prefix_1, &"-faltivec-src-compat="[1], altivec_src_compat, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Source-level compatibility for Altivec vectors (for PowerPC targets). This includes results of vector comparison (scalar for 'xl', vector for 'gcc') as well as behavior when initializing with a scalar (splatting for 'xl', element zero only for 'gcc'). For 'mixed', the compatibility is as 'gcc' for 'vector bool/vector pixel' and as 'xl' for other types. Current default is 'mixed'.", nullptr, "mixed,gcc,xl")
OPTION(prefix_1, &"-faltivec"[1], faltivec, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fanalyzed-objects-for-unparse"[1], fanalyzed_objects_for_unparse, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fansi-escape-codes"[1], fansi_escape_codes, Flag, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Use ANSI escape codes for diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fapple-kext"[1], fapple_kext, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use Apple's kernel extensions ABI", nullptr, nullptr)
OPTION(prefix_1, &"-fapple-link-rtlib"[1], fapple_link_rtlib, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Force linking the clang builtins runtime library", nullptr, nullptr)
OPTION(prefix_1, &"-fapple-pragma-pack"[1], fapple_pragma_pack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable Apple gcc-compatible #pragma pack handling", nullptr, nullptr)
OPTION(prefix_1, &"-fapplication-extension"[1], fapplication_extension, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Restrict code to those available for App Extensions", nullptr, nullptr)
OPTION(prefix_1, &"-fapply-global-visibility-to-externs"[1], fapply_global_visibility_to_externs, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply global symbol visibility to external declarations without an explicit visibility", nullptr, nullptr)
OPTION(prefix_1, &"-fapprox-func"[1], fapprox_func, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow certain math function calls to be replaced with an approximately equivalent calculation", nullptr, nullptr)
OPTION(prefix_1, &"-fasm-blocks"[1], fasm_blocks, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fasm"[1], fasm, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fassociative-math"[1], fassociative_math, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fassume-sane-operator-new"[1], fassume_sane_operator_new, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fastcp"[1], fastcp, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fastf"[1], fastf, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fast"[1], fast, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fasync-exceptions"[1], fasync_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable EH Asynchronous exceptions", nullptr, nullptr)
OPTION(prefix_1, &"-fasynchronous-unwind-tables"[1], fasynchronous_unwind_tables, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fauto-profile-accurate"[1], fauto_profile_accurate, Flag, f_Group, fprofile_sample_accurate, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fauto-profile="[1], fauto_profile_EQ, Joined, INVALID, fprofile_sample_use_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fauto-profile"[1], fauto_profile, Flag, f_Group, fprofile_sample_use, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fautolink"[1], fautolink, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fautomatic"[1], fautomatic, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/favor"[1], _SLASH_favor, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/FA"[1], _SLASH_FA, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Output assembly code file during compilation", nullptr, nullptr)
OPTION(prefix_2, &"/FA"[1], _SLASH_FA_joined, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Fa"[1], _SLASH_Fa, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set assembly output file name (with /FA)", "<file or dir/>", nullptr)
OPTION(prefix_1, &"-fbackslash"[1], fbackslash, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Specify that backslash in string introduces an escape character", nullptr, nullptr)
OPTION(prefix_1, &"-fbacktrace"[1], fbacktrace, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fbasic-block-sections="[1], fbasic_block_sections_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "Place each function's basic blocks in unique sections (ELF Only) : all | labels | none | list=<file>", nullptr, "all,labels,none,list=")
OPTION(prefix_1, &"-fbinutils-version="[1], fbinutils_version_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Produced object files can use all ELF features supported by this binutils version and newer. If -fno-integrated-as is specified, the generated assembly will consider GNU as support. 'none' means that all ELF features can be used, regardless of binutils support. Defaults to 2.26.", "<major.minor>", nullptr)
OPTION(prefix_1, &"-fblas-matmul-limit="[1], fblas_matmul_limit_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fblocks-runtime-optional"[1], fblocks_runtime_optional, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Weakly link in the blocks runtime", nullptr, nullptr)
OPTION(prefix_1, &"-fblocks"[1], fblocks, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable the 'blocks' language feature", nullptr, nullptr)
OPTION(prefix_1, &"-fbootclasspath="[1], fbootclasspath_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fborland-extensions"[1], fborland_extensions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Accept non-standard constructs supported by the Borland compiler", nullptr, nullptr)
OPTION(prefix_1, &"-fbounds-check"[1], fbounds_check, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fbracket-depth="[1], fbracket_depth_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fbracket-depth"[1], fbracket_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum nesting level for parentheses, brackets, and braces", nullptr, nullptr)
OPTION(prefix_1, &"-fbranch-count-reg"[1], fbranch_count_reg, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fbuild-session-file="[1], fbuild_session_file, Joined, i_Group, INVALID, nullptr, 0, 0,
       "Use the last modification time of <file> as the build session timestamp", "<file>", nullptr)
OPTION(prefix_1, &"-fbuild-session-timestamp="[1], fbuild_session_timestamp, Joined, i_Group, INVALID, nullptr, CC1Option, 0,
       "Time when the current build session started", "<time since Epoch in seconds>", nullptr)
OPTION(prefix_1, &"-fbuiltin-module-map"[1], fbuiltin_module_map, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Load the clang builtins module map file.", nullptr, nullptr)
OPTION(prefix_1, &"-fbuiltin"[1], fbuiltin, Flag, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fc++-abi="[1], fcxx_abi_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "C++ ABI to use. This will override the target C++ ABI.", nullptr, nullptr)
OPTION(prefix_1, &"-fc++-static-destructors"[1], fcxx_static_destructors, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x10"[1], fcall_saved_x10, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x10 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x11"[1], fcall_saved_x11, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x11 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x12"[1], fcall_saved_x12, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x12 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x13"[1], fcall_saved_x13, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x13 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x14"[1], fcall_saved_x14, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x14 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x15"[1], fcall_saved_x15, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x15 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x18"[1], fcall_saved_x18, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x18 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x8"[1], fcall_saved_x8, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x8 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcall-saved-x9"[1], fcall_saved_x9, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Make the x9 register call-saved (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fcaller-saves"[1], fcaller_saves, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcaret-diagnostics-max-lines"[1], fcaret_diagnostics_max_lines, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of source lines to show in a caret diagnostic", "<N>", nullptr)
OPTION(prefix_1, &"-fcaret-diagnostics"[1], fcaret_diagnostics, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fcf-protection="[1], fcf_protection_EQ, Joined, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Instrument control-flow architecture protection. Options: return, branch, full, none.", nullptr, "return,branch,full,none")
OPTION(prefix_1, &"-fcf-protection"[1], fcf_protection, Flag, f_Group, fcf_protection_EQ, "full\0", CoreOption | CC1Option, 0,
       "Enable cf-protection in 'full' mode", nullptr, nullptr)
OPTION(prefix_1, &"-fcf-runtime-abi="[1], fcf_runtime_abi_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "unspecified,standalone,objc,swift,swift-5.0,swift-4.2,swift-4.1")
OPTION(prefix_1, &"-fchar8_t"[1], fchar8__t, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++ builtin type char8_t", nullptr, nullptr)
OPTION(prefix_1, &"-fcheck-array-temporaries"[1], fcheck_array_temporaries, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcheck-new"[1], ffcheck_new, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcheck="[1], fcheck_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fclang-abi-compat="[1], fclang_abi_compat_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Attempt to match the ABI of Clang <version>", "<version>", "<major>.<minor>,latest")
OPTION(prefix_1, &"-fclasspath="[1], fclasspath_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcoarray="[1], fcoarray_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcolor-diagnostics"[1], fcolor_diagnostics, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption | FlangOption, 0,
       "Enable colors in diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fcomment-block-commands="[1], fcomment_block_commands, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Treat each comma separated argument in <arg> as a documentation comment block command", "<arg>", nullptr)
OPTION(prefix_1, &"-fcommon"[1], fcommon, Flag, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Place uninitialized global variables in a common block", nullptr, nullptr)
OPTION(prefix_1, &"-fcompatibility-qualified-id-block-type-checking"[1], fcompatibility_qualified_id_block_param_type_checking, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow using blocks with parameters of more specific type than the type system guarantees when a parameter is qualified id", nullptr, nullptr)
OPTION(prefix_1, &"-fcompile-resource="[1], fcompile_resource_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcomplete-member-pointers"[1], fcomplete_member_pointers, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Require member pointer base types to be complete if they would be significant under the Microsoft ABI", nullptr, nullptr)
OPTION(prefix_1, &"-fconcepts-ts"[1], fconcepts_ts, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable C++ Extensions for Concepts. (deprecated - use -std=c++2a)", nullptr, nullptr)
OPTION(prefix_1, &"-fconst-strings"[1], fconst_strings, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use a const qualified type for string literals in C and ObjC", nullptr, nullptr)
OPTION(prefix_1, &"-fconstant-cfstrings"[1], fconstant_cfstrings, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fconstant-string-class="[1], fconstant_string_class_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fconstant-string-class"[1], fconstant_string_class, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Specify the class to use for constant Objective-C string objects.", "<class name>", nullptr)
OPTION(prefix_1, &"-fconstexpr-backtrace-limit="[1], fconstexpr_backtrace_limit_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fconstexpr-backtrace-limit"[1], fconstexpr_backtrace_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of entries to print in a constexpr evaluation backtrace (0 = no limit).", "<N>", nullptr)
OPTION(prefix_1, &"-fconstexpr-depth="[1], fconstexpr_depth_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fconstexpr-depth"[1], fconstexpr_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum depth of recursive constexpr function calls", nullptr, nullptr)
OPTION(prefix_1, &"-fconstexpr-steps="[1], fconstexpr_steps_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fconstexpr-steps"[1], fconstexpr_steps, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum number of steps in constexpr function evaluation", nullptr, nullptr)
OPTION(prefix_1, &"-fconvergent-functions"[1], fconvergent_functions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Assume functions may be convergent", nullptr, nullptr)
OPTION(prefix_1, &"-fconvert="[1], fconvert_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcoroutines-ts"[1], fcoroutines_ts, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for the C++ Coroutines TS", nullptr, nullptr)
OPTION(prefix_1, &"-fcoverage-compilation-dir="[1], fcoverage_compilation_dir_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "The compilation directory to embed in the coverage mapping.", nullptr, nullptr)
OPTION(prefix_1, &"-fcoverage-mapping"[1], fcoverage_mapping, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Generate coverage mapping to enable code coverage analysis", nullptr, nullptr)
OPTION(prefix_1, &"-fcoverage-prefix-map="[1], fcoverage_prefix_map_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "remap file source paths in coverage mapping", nullptr, nullptr)
OPTION(prefix_1, &"-fcrash-diagnostics-dir="[1], fcrash_diagnostics_dir, Joined, f_clang_Group, INVALID, nullptr, NoArgumentUnused | CoreOption, 0,
       "Put crash-report files in <dir>", "<dir>", nullptr)
OPTION(prefix_1, &"-fcray-pointer"[1], fcray_pointer, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcreate-profile"[1], fcreate_profile, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcs-profile-generate="[1], fcs_profile_generate_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0,
       "Generate instrumented code to collect context sensitive execution counts into <directory>/default.profraw (overridden by LLVM_PROFILE_FILE env var)", "<directory>", nullptr)
OPTION(prefix_1, &"-fcs-profile-generate"[1], fcs_profile_generate, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Generate instrumented code to collect context sensitive execution counts into default.profraw (overridden by LLVM_PROFILE_FILE env var)", nullptr, nullptr)
OPTION(prefix_1, &"-fcuda-allow-variadic-functions"[1], fcuda_allow_variadic_functions, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow variadic functions in CUDA device code.", nullptr, nullptr)
OPTION(prefix_1, &"-fcuda-approx-transcendentals"[1], fcuda_approx_transcendentals, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use approximate transcendental functions", nullptr, nullptr)
OPTION(prefix_1, &"-fcuda-flush-denormals-to-zero"[1], fcuda_flush_denormals_to_zero, Flag, INVALID, fgpu_flush_denormals_to_zero, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcuda-include-gpubinary"[1], fcuda_include_gpubinary, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Incorporate CUDA device-side binary into host object file.", nullptr, nullptr)
OPTION(prefix_1, &"-fcuda-is-device"[1], fcuda_is_device, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate code for CUDA device", nullptr, nullptr)
OPTION(prefix_1, &"-fcuda-rdc"[1], anonymous_52, Flag, INVALID, fgpu_rdc, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fcuda-short-ptr"[1], fcuda_short_ptr, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use 32-bit pointers for accessing const/local/shared address spaces", nullptr, nullptr)
OPTION(prefix_1, &"-fcxx-exceptions"[1], fcxx_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++ exceptions", nullptr, nullptr)
OPTION(prefix_1, &"-fcxx-modules"[1], fcxx_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Enable modules for C++", nullptr, nullptr)
OPTION(prefix_2, &"/FC"[1], _SLASH_FC, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fd-lines-as-code"[1], fd_lines_as_code, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fd-lines-as-comments"[1], fd_lines_as_comments, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdata-sections"[1], fdata_sections, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Place each data in its own section", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-compilation-dir="[1], fdebug_compilation_dir_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "The compilation directory to embed in the debug info", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-compilation-dir"[1], fdebug_compilation_dir, Separate, f_Group, fdebug_compilation_dir_EQ, nullptr, CC1Option | CC1AsOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-default-version="[1], fdebug_default_version, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Default DWARF version to use, if a -g option caused DWARF debug info to be produced", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-dump-all"[1], fdebug_dump_all, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump symbols and the parse tree after the semantic checks", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-dump-parse-tree-no-sema"[1], fdebug_dump_parse_tree_no_sema, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump the parse tree (skips the semantic checks)", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-dump-parse-tree"[1], fdebug_dump_parse_tree, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump the parse tree", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-dump-parsing-log"[1], fdebug_dump_parsing_log, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Run instrumented parse and dump the parsing log", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-dump-provenance"[1], fdebug_dump_provenance, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump provenance", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-dump-symbols"[1], fdebug_dump_symbols, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump symbols after the semantic analysis", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-info-for-profiling"[1], fdebug_info_for_profiling, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Emit extra debug info to make sample profile more accurate", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-macro"[1], fdebug_macro, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Emit macro debug information", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-measure-parse-tree"[1], fdebug_measure_parse_tree, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Measure the parse tree", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-module-writer"[1], fdebug_module_writer, Flag, INVALID, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Enable debug messages while writing module files", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-pass-arguments"[1], fdebug_pass_arguments, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-pass-manager"[1], fdebug_pass_manager, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Prints debug information for the new pass manager", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-pass-structure"[1], fdebug_pass_structure, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-pre-fir-tree"[1], fdebug_pre_fir_tree, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump the pre-FIR tree", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-prefix-map="[1], fdebug_prefix_map_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "remap file source paths in debug info", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-ranges-base-address"[1], fdebug_ranges_base_address, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use DWARF base address selection entries in .debug_ranges", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-types-section"[1], fdebug_types_section, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Place debug types in their own section (ELF Only)", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-unparse-no-sema"[1], fdebug_unparse_no_sema, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Unparse and stop (skips the semantic checks)", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-unparse-with-symbols"[1], fdebug_unparse_with_symbols, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Unparse and stop.", nullptr, nullptr)
OPTION(prefix_1, &"-fdebug-unparse"[1], fdebug_unparse, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Unparse and stop.", nullptr, nullptr)
OPTION(prefix_1, &"-fdebugger-cast-result-to-id"[1], fdebugger_cast_result_to_id, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable casting unknown expression results to id", nullptr, nullptr)
OPTION(prefix_1, &"-fdebugger-objc-literal"[1], fdebugger_objc_literal, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable special debugger support for Objective-C subscripting and literals", nullptr, nullptr)
OPTION(prefix_1, &"-fdebugger-support"[1], fdebugger_support, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable special debugger support behavior", nullptr, nullptr)
OPTION(prefix_1, &"-fdeclare-opencl-builtins"[1], fdeclare_opencl_builtins, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add OpenCL builtin function declarations (experimental)", nullptr, nullptr)
OPTION(prefix_1, &"-fdeclspec"[1], fdeclspec, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Allow __declspec as a keyword", nullptr, nullptr)
OPTION(prefix_1, &"-fdefault-calling-conv="[1], fdefault_calling_conv_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set default calling convention", nullptr, "cdecl,fastcall,stdcall,vectorcall,regcall")
OPTION(prefix_1, &"-fdefault-double-8"[1], fdefault_double_8, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Set the default double precision kind to an 8 byte wide type", nullptr, nullptr)
OPTION(prefix_1, &"-fdefault-inline"[1], fdefault_inline, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdefault-integer-8"[1], fdefault_integer_8, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Set the default integer kind to an 8 byte wide type", nullptr, nullptr)
OPTION(prefix_1, &"-fdefault-real-8"[1], fdefault_real_8, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Set the default real kind to an 8 byte wide type", nullptr, nullptr)
OPTION(prefix_1, &"-fdefer-pop"[1], anonymous_365, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdelayed-template-parsing"[1], fdelayed_template_parsing, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Parse templated function definitions at the end of the translation unit", nullptr, nullptr)
OPTION(prefix_1, &"-fdelete-null-pointer-checks"[1], fdelete_null_pointer_checks, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Treat usage of null pointers as undefined behavior (default)", nullptr, nullptr)
OPTION(prefix_1, &"-fdenormal-fp-math-f32="[1], fdenormal_fp_math_f32_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdenormal-fp-math="[1], fdenormal_fp_math_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdepfile-entry="[1], fdepfile_entry, Joined, f_clang_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdeprecated-macro"[1], fdeprecated_macro, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Defines the __DEPRECATED macro", nullptr, nullptr)
OPTION(prefix_1, &"-fdevirtualize-speculatively"[1], fdevirtualize_speculatively, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdevirtualize"[1], fdevirtualize, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-absolute-paths"[1], fdiagnostics_absolute_paths, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Print absolute paths in diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-color="[1], fdiagnostics_color_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-color"[1], fdiagnostics_color, Flag, f_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-fixit-info"[1], fdiagnostics_fixit_info, Flag, f_clang_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-format="[1], fdiagnostics_format_EQ, Joined, f_clang_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-format"[1], fdiagnostics_format, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Change diagnostic formatting to match IDE and command line tools", nullptr, "clang,msvc,vi")
OPTION(prefix_1, &"-fdiagnostics-hotness-threshold="[1], fdiagnostics_hotness_threshold_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Prevent optimization remarks from being output if they do not have at least this profile count. Use 'auto' to apply the threshold from profile summary", "<value>", nullptr)
OPTION(prefix_1, &"-fdiagnostics-parseable-fixits"[1], fdiagnostics_parseable_fixits, Flag, f_clang_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Print fix-its in machine parseable form", nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-print-source-range-info"[1], fdiagnostics_print_source_range_info, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Print source range spans in numeric form", nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-show-category="[1], fdiagnostics_show_category_EQ, Joined, f_clang_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-show-category"[1], fdiagnostics_show_category, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print diagnostic category", nullptr, "none,id,name")
OPTION(prefix_1, &"-fdiagnostics-show-hotness"[1], fdiagnostics_show_hotness, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable profile hotness information in diagnostic line", nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-show-location="[1], fdiagnostics_show_location_EQ, Joined, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-show-note-include-stack"[1], fdiagnostics_show_note_include_stack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Display include stacks for diagnostic notes", nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-show-option"[1], fdiagnostics_show_option, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Print option name with mappable diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fdiagnostics-show-template-tree"[1], fdiagnostics_show_template_tree, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Print a template comparison tree for differing templates", nullptr, nullptr)
OPTION(prefix_1, &"-fdigraphs"[1], fdigraphs, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable alternative token representations '<:', ':>', '<%', '%>', '%:', '%:%:' (default)", nullptr, nullptr)
OPTION(prefix_1, &"-fdirect-access-external-data"[1], fdirect_access_external_data, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't use GOT indirection to reference external data symbols", nullptr, nullptr)
OPTION(prefix_1, &"-fdisable-module-hash"[1], fdisable_module_hash, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable the module hash", nullptr, nullptr)
OPTION(prefix_1, &"-fdiscard-value-names"[1], fdiscard_value_names, Flag, f_clang_Group, INVALID, nullptr, NoXarchOption, 0,
       "Discard value names in LLVM IR", nullptr, nullptr)
OPTION(prefix_1, &"-fdollar-ok"[1], fdollar_ok, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdollars-in-identifiers"[1], fdollars_in_identifiers, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow '$' in identifiers", nullptr, nullptr)
OPTION(prefix_1, &"-fdouble-square-bracket-attributes"[1], fdouble_square_bracket_attributes, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Enable '[[]]' attributes in all C and C++ language modes", nullptr, nullptr)
OPTION(prefix_1, &"-fdump-fortran-optimized"[1], fdump_fortran_optimized, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdump-fortran-original"[1], fdump_fortran_original, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdump-parse-tree"[1], fdump_parse_tree, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fdump-record-layouts-canonical"[1], fdump_record_layouts_canonical, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information with canonical field types", nullptr, nullptr)
OPTION(prefix_1, &"-fdump-record-layouts-complete"[1], fdump_record_layouts_complete, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information for all complete types", nullptr, nullptr)
OPTION(prefix_1, &"-fdump-record-layouts-simple"[1], fdump_record_layouts_simple, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information in a simple form used for testing", nullptr, nullptr)
OPTION(prefix_1, &"-fdump-record-layouts"[1], fdump_record_layouts, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information", nullptr, nullptr)
OPTION(prefix_1, &"-fdump-vtable-layouts"[1], fdump_vtable_layouts, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump the layouts of all vtables that will be emitted in a translation unit", nullptr, nullptr)
OPTION(prefix_1, &"-fdwarf-directory-asm"[1], fdwarf_directory_asm, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fdwarf-exceptions"[1], fdwarf_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Use DWARF style exceptions", nullptr, nullptr)
OPTION(prefix_1, &"-fdwarf2-cfi-asm"[1], fdwarf2_cfi_asm, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Fd"[1], _SLASH_Fd, Joined, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Fe:"[1], _SLASH_Fe_COLON, Joined, cl_Group, _SLASH_Fe, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-felide-constructors"[1], felide_constructors, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-feliminate-unused-debug-symbols"[1], feliminate_unused_debug_symbols, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-feliminate-unused-debug-types"[1], feliminate_unused_debug_types, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Do not emit  debug info for defined but unused types", nullptr, nullptr)
OPTION(prefix_1, &"-fembed-bitcode-marker"[1], fembed_bitcode_marker, Flag, INVALID, fembed_bitcode_EQ, "marker\0", 0, 0,
       "Embed placeholder LLVM IR data as a marker", nullptr, nullptr)
OPTION(prefix_1, &"-fembed-bitcode="[1], fembed_bitcode_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CC1AsOption, 0,
       "Embed LLVM bitcode (option: off, all, bitcode, marker)", "<option>", "off,all,bitcode,marker")
OPTION(prefix_1, &"-fembed-bitcode"[1], fembed_bitcode, Flag, f_Group, fembed_bitcode_EQ, "all\0", 0, 0,
       "Embed LLVM IR bitcode as data", nullptr, nullptr)
OPTION(prefix_1, &"-femit-all-decls"[1], femit_all_decls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Emit all declarations, even if unused", nullptr, nullptr)
OPTION(prefix_1, &"-femulated-tls"[1], femulated_tls, Flag, f_Group, INVALID, nullptr, CC1Option | CC1Option, 0,
       "Use emutls functions to access thread_local variables", nullptr, nullptr)
OPTION(prefix_1, &"-fenable-matrix"[1], fenable_matrix, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable matrix data type and related builtin functions", nullptr, nullptr)
OPTION(prefix_1, &"-fencode-extended-block-signature"[1], fencode_extended_block_signature, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "enable extended encoding of block type signature", nullptr, nullptr)
OPTION(prefix_1, &"-fencoding="[1], fencoding_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ferror-limit="[1], ferror_limit_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ferror-limit"[1], ferror_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of errors to emit before stopping (0 = no limit).", "<N>", nullptr)
OPTION(prefix_1, &"-fescaping-block-tail-calls"[1], fescaping_block_tail_calls, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fexceptions"[1], fexceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for exception handling", nullptr, nullptr)
OPTION(prefix_1, &"-fexcess-precision="[1], fexcess_precision_EQ, Joined, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fexec-charset="[1], fexec_charset_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fexpensive-optimizations"[1], anonymous_363, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fexperimental-isel"[1], fexperimental_isel, Flag, f_clang_Group, fglobal_isel, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fexperimental-new-constant-interpreter"[1], fexperimental_new_constant_interpreter, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable the experimental new constant interpreter", nullptr, nullptr)
OPTION(prefix_1, &"-fexperimental-new-pass-manager"[1], fexperimental_new_pass_manager, Flag, f_clang_Group, fno_legacy_pass_manager, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fexperimental-relative-c++-abi-vtables"[1], fexperimental_relative_cxx_abi_vtables, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use the experimental C++ class ABI for classes with virtual tables", nullptr, nullptr)
OPTION(prefix_1, &"-fexperimental-strict-floating-point"[1], fexperimental_strict_floating_point, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Enables experimental strict floating point in LLVM.", nullptr, nullptr)
OPTION(prefix_1, &"-fextdirs="[1], fextdirs_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fextend-arguments="[1], fextend_args_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Controls how scalar integer arguments are extended in calls to unprototyped and varargs functions", nullptr, "32,64")
OPTION(prefix_1, &"-fextended-identifiers"[1], anonymous_367, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fexternal-blas"[1], fexternal_blas, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fexternc-nounwind"[1], fexternc_nounwind, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Assume all functions with C linkage do not unwind", nullptr, nullptr)
OPTION(prefix_2, &"/Fe"[1], _SLASH_Fe, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set output executable file name", "<file or dir/>", nullptr)
OPTION(prefix_1, &"-ff2c"[1], ff2c, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffake-address-space-map"[1], ffake_address_space_map, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use a fake address space map; OpenCL testing purposes only", nullptr, nullptr)
OPTION(prefix_1, &"-ffast-math"[1], ffast_math, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow aggressive, lossy floating-point optimizations", nullptr, nullptr)
OPTION(prefix_1, &"-ffat-lto-objects"[1], ffat_lto_objects, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffile-compilation-dir="[1], ffile_compilation_dir_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0,
       "The compilation directory to embed in the debug info and coverage mapping.", nullptr, nullptr)
OPTION(prefix_1, &"-ffile-prefix-map="[1], ffile_prefix_map_EQ, Joined, f_Group, INVALID, nullptr, 0, 0,
       "remap file source paths in debug info, predefined preprocessor macros and __builtin_FILE()", nullptr, nullptr)
OPTION(prefix_1, &"-ffine-grained-bitfield-accesses"[1], ffine_grained_bitfield_accesses, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use separate accesses for consecutive bitfield runs with legal widths and alignments.", nullptr, nullptr)
OPTION(prefix_1, &"-ffinite-loops"[1], ffinite_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Assume all loops are finite.", nullptr, nullptr)
OPTION(prefix_1, &"-ffinite-math-only"[1], ffinite_math_only, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-a0"[1], ffixed_a0, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the a0 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-a1"[1], ffixed_a1, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the a1 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-a2"[1], ffixed_a2, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the a2 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-a3"[1], ffixed_a3, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the a3 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-a4"[1], ffixed_a4, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the a4 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-a5"[1], ffixed_a5, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the a5 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-a6"[1], ffixed_a6, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the a6 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d0"[1], ffixed_d0, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d0 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d1"[1], ffixed_d1, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d1 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d2"[1], ffixed_d2, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d2 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d3"[1], ffixed_d3, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d3 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d4"[1], ffixed_d4, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d4 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d5"[1], ffixed_d5, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d5 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d6"[1], ffixed_d6, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d6 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-d7"[1], ffixed_d7, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the d7 register (M68k only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-form"[1], ffixed_form, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Process source files in fixed form", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-line-length-"[1], ffixed_line_length_VALUE, Joined, f_Group, ffixed_line_length_EQ, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-line-length="[1], ffixed_line_length_EQ, Joined, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Use <value> as character line width in fixed mode", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-point"[1], ffixed_point, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable fixed point types", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-r19"[1], ffixed_r19, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Reserve register r19 (Hexagon only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-r9"[1], ffixed_r9, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Reserve the r9 register (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x10"[1], ffixed_x10, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x10 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x11"[1], ffixed_x11, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x11 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x12"[1], ffixed_x12, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x12 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x13"[1], ffixed_x13, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x13 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x14"[1], ffixed_x14, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x14 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x15"[1], ffixed_x15, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x15 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x16"[1], ffixed_x16, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x16 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x17"[1], ffixed_x17, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x17 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x18"[1], ffixed_x18, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x18 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x19"[1], ffixed_x19, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x19 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x1"[1], ffixed_x1, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x1 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x20"[1], ffixed_x20, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x20 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x21"[1], ffixed_x21, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x21 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x22"[1], ffixed_x22, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x22 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x23"[1], ffixed_x23, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x23 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x24"[1], ffixed_x24, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x24 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x25"[1], ffixed_x25, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x25 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x26"[1], ffixed_x26, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x26 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x27"[1], ffixed_x27, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x27 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x28"[1], ffixed_x28, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x28 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x29"[1], ffixed_x29, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x29 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x2"[1], ffixed_x2, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x2 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x30"[1], ffixed_x30, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x30 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x31"[1], ffixed_x31, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x31 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x3"[1], ffixed_x3, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x3 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x4"[1], ffixed_x4, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x4 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x5"[1], ffixed_x5, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x5 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x6"[1], ffixed_x6, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x6 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x7"[1], ffixed_x7, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x7 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x8"[1], ffixed_x8, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x8 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffixed-x9"[1], ffixed_x9, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Reserve the x9 register (AArch64/RISC-V only)", nullptr, nullptr)
OPTION(prefix_1, &"-ffloat-store"[1], ffloat_store, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffor-scope"[1], ffor_scope, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fforbid-guard-variables"[1], fforbid_guard_variables, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit an error if a C++ static local initializer would need a guard variable", nullptr, nullptr)
OPTION(prefix_1, &"-fforce-addr"[1], force_addr, Joined, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fforce-dwarf-frame"[1], fforce_dwarf_frame, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Always emit a debug frame section", nullptr, nullptr)
OPTION(prefix_1, &"-fforce-emit-vtables"[1], fforce_emit_vtables, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Emits more virtual tables to improve devirtualization", nullptr, nullptr)
OPTION(prefix_1, &"-fforce-enable-int128"[1], fforce_enable_int128, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for int128_t type", nullptr, nullptr)
OPTION(prefix_1, &"-ffp-contract="[1], ffp_contract, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Form fused FP ops (e.g. FMAs): fast (fuses across statements disregarding pragmas) | on (only fuses in the same statement unless dictated by pragmas) | off (never fuses) | fast-honor-pragmas (fuses across statements unless diectated by pragmas). Default is 'fast' for CUDA, 'fast-honor-pragmas' for HIP, and 'on' otherwise.", nullptr, "fast,on,off,fast-honor-pragmas")
OPTION(prefix_1, &"-ffp-exception-behavior="[1], ffp_exception_behavior_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specifies the exception behavior of floating-point operations.", nullptr, "ignore,maytrap,strict")
OPTION(prefix_1, &"-ffp-model="[1], ffp_model_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Controls the semantics of floating-point calculations.", nullptr, nullptr)
OPTION(prefix_1, &"-ffpe-trap="[1], ffpe_trap_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffree-form"[1], ffree_form, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Process source files in free form", nullptr, nullptr)
OPTION(prefix_1, &"-ffree-line-length-"[1], ffree_line_length_VALUE, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffreestanding"[1], ffreestanding, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Assert that the compilation takes place in a freestanding environment", nullptr, nullptr)
OPTION(prefix_1, &"-ffriend-injection"[1], ffriend_injection, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffrontend-optimize"[1], ffrontend_optimize, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffuchsia-api-level="[1], ffuchsia_api_level_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set Fuchsia API level", nullptr, nullptr)
OPTION(prefix_1, &"-ffunction-attribute-list"[1], ffunction_attribute_list, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ffunction-sections"[1], ffunction_sections, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Place each function in its own section", nullptr, nullptr)
OPTION(prefix_1, &"-fgcse-after-reload"[1], fgcse_after_reload, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fgcse-las"[1], fgcse_las, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fgcse-sm"[1], fgcse_sm, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fgcse"[1], fgcse, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fget-definition"[1], fget_definition, MultiArg, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 3,
       "Get the symbol definition from <line> <start-column> <end-column>", nullptr, nullptr)
OPTION(prefix_1, &"-fget-symbols-sources"[1], fget_symbols_sources, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump symbols and their source code locations", nullptr, nullptr)
OPTION(prefix_1, &"-fglobal-isel"[1], fglobal_isel, Flag, f_clang_Group, INVALID, nullptr, 0, 0,
       "Enables the global instruction selector", nullptr, nullptr)
OPTION(prefix_1, &"-fgnu-inline-asm"[1], fgnu_inline_asm, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fgnu-keywords"[1], fgnu_keywords, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow GNU-extension keywords regardless of language standard", nullptr, nullptr)
OPTION(prefix_1, &"-fgnu-runtime"[1], fgnu_runtime, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Generate output compatible with the standard GNU Objective-C runtime", nullptr, nullptr)
OPTION(prefix_1, &"-fgnu89-inline"[1], fgnu89_inline, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use the gnu89 inline semantics", nullptr, nullptr)
OPTION(prefix_1, &"-fgnuc-version="[1], fgnuc_version_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Sets various macros to claim compatibility with the given GCC version (default is 4.2.1)", nullptr, nullptr)
OPTION(prefix_1, &"-fgnu"[1], fgnu, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fgpu-allow-device-init"[1], fgpu_allow_device_init, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow device side init function in HIP (experimental)", nullptr, nullptr)
OPTION(prefix_1, &"-fgpu-defer-diag"[1], fgpu_defer_diag, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Defer host/device related diagnostic messages for CUDA/HIP", nullptr, nullptr)
OPTION(prefix_1, &"-fgpu-exclude-wrong-side-overloads"[1], fgpu_exclude_wrong_side_overloads, Flag, f_Group, INVALID, nullptr, CC1Option | HelpHidden, 0,
       "Always exclude wrong side overloads in overloading resolution for CUDA/HIP", nullptr, nullptr)
OPTION(prefix_1, &"-fgpu-flush-denormals-to-zero"[1], fgpu_flush_denormals_to_zero, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Flush denormal floating point values to zero in CUDA/HIP device mode.", nullptr, nullptr)
OPTION(prefix_1, &"-fgpu-inline-threshold="[1], fgpu_inline_threshold_EQ, Joined, INVALID, INVALID, nullptr, HelpHidden, 0,
       "Inline threshold for device compilation for CUDA/HIP", nullptr, nullptr)
OPTION(prefix_1, &"-fgpu-rdc"[1], fgpu_rdc, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate relocatable device code, also known as separate compilation mode", nullptr, nullptr)
OPTION(prefix_1, &"-fgpu-sanitize"[1], fgpu_sanitize, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable sanitizer for AMDGPU target", nullptr, nullptr)
OPTION(prefix_1, &"-fhalf-no-semantic-interposition"[1], fhalf_no_semantic_interposition, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Like -fno-semantic-interposition but don't use local aliases", nullptr, nullptr)
OPTION(prefix_1, &"-fheinous-gnu-extensions"[1], fheinous_gnu_extensions, Flag, INVALID, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fhip-dump-offload-linker-script"[1], fhip_dump_offload_linker_script, Flag, f_Group, INVALID, nullptr, NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fhip-fp32-correctly-rounded-divide-sqrt"[1], fhip_fp32_correctly_rounded_divide_sqrt, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Specify that single precision floating-point divide and sqrt used in the program source are correctly rounded (HIP device compilation only)", nullptr, nullptr)
OPTION(prefix_1, &"-fhip-new-launch-api"[1], fhip_new_launch_api, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use new kernel launching API for HIP", nullptr, nullptr)
OPTION(prefix_1, &"-fhonor-infinites"[1], anonymous_528, Flag, INVALID, fhonor_infinities, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fhonor-infinities"[1], fhonor_infinities, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fhonor-nans"[1], fhonor_nans, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fhosted"[1], fhosted, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fident"[1], anonymous_31, Flag, f_Group, Qy, nullptr, CoreOption | CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fignore-exceptions"[1], fignore_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for ignoring exception handling constructs", nullptr, nullptr)
OPTION(prefix_1, &"-filelist"[1], filelist, Separate, Link_Group, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-filetype"[1], filetype, Separate, INVALID, INVALID, nullptr, CC1AsOption | NoDriverOption, 0,
       "Specify the output file type ('asm', 'null', or 'obj')", nullptr, nullptr)
OPTION(prefix_1, &"-fimplement-inlines"[1], fimplement_inlines, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fimplicit-module-maps"[1], fimplicit_module_maps, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Implicitly search the file system for module map files.", nullptr, nullptr)
OPTION(prefix_1, &"-fimplicit-modules-use-lock"[1], ffimplicit_modules_use_lock, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use filesystem locks for implicit modules builds to avoid duplicating work in competing clang invocations.", nullptr, nullptr)
OPTION(prefix_1, &"-fimplicit-modules"[1], fimplicit_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fimplicit-none"[1], fimplicit_none, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "No implicit typing allowed unless overridden by IMPLICIT statements", nullptr, nullptr)
OPTION(prefix_1, &"-fimplicit-templates"[1], fimplicit_templates, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finclude-default-header"[1], finclude_default_header, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include default header file for OpenCL", nullptr, nullptr)
OPTION(prefix_1, &"-findirect-virtual-calls"[1], anonymous_590, Flag, INVALID, fapple_kext, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finit-character="[1], finit_character_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finit-integer="[1], finit_integer_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finit-local-zero"[1], finit_local_zero, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finit-logical="[1], finit_logical_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finit-real="[1], finit_real_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finline-functions-called-once"[1], finline_functions_called_once, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finline-functions"[1], finline_functions, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Inline suitable functions", nullptr, nullptr)
OPTION(prefix_1, &"-finline-hint-functions"[1], finline_hint_functions, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Inline functions which are (explicitly or implicitly) marked inline", nullptr, nullptr)
OPTION(prefix_1, &"-finline-limit="[1], finline_limit_EQ, Joined, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finline-limit"[1], ffinline_limit, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finline-small-functions"[1], finline_small_functions, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finline"[1], finline, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-finput-charset="[1], finput_charset_EQ, Joined, f_Group, INVALID, nullptr, FlangOption | FC1Option, 0,
       "Specify the default character set for source files", nullptr, nullptr)
OPTION(prefix_1, &"-finstrument-function-entry-bare"[1], finstrument_function_entry_bare, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Instrument function entry only, after inlining, without arguments to the instrumentation call", nullptr, nullptr)
OPTION(prefix_1, &"-finstrument-functions-after-inlining"[1], finstrument_functions_after_inlining, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Like -finstrument-functions, but insert the calls after inlining", nullptr, nullptr)
OPTION(prefix_1, &"-finstrument-functions"[1], finstrument_functions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate calls to instrument function entry and exit", nullptr, nullptr)
OPTION(prefix_1, &"-finteger-4-integer-8"[1], finteger_4_integer_8, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fintegrated-as"[1], fintegrated_as, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable the integrated assembler", nullptr, nullptr)
OPTION(prefix_1, &"-fintegrated-cc1"[1], fintegrated_cc1, Flag, f_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Run cc1 in-process", nullptr, nullptr)
OPTION(prefix_1, &"-fintrinsic-modules-path"[1], fintrinsic_modules_path, Separate, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Specify where to find the compiled intrinsic modules", "<dir>", nullptr)
OPTION(prefix_1, &"-fipa-cp"[1], fipa_cp, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fivopts"[1], fivopts, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fix-only-warnings"[1], fix_only_warnings, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it advice only for warnings, not errors", nullptr, nullptr)
OPTION(prefix_1, &"-fix-what-you-can"[1], fix_what_you_can, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it advice even in the presence of unfixable errors", nullptr, nullptr)
OPTION(prefix_1, &"-fixit-recompile"[1], fixit_recompile, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it changes and recompile", nullptr, nullptr)
OPTION(prefix_1, &"-fixit-to-temporary"[1], fixit_to_temp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it changes to temporary files", nullptr, nullptr)
OPTION(prefix_1, &"-fixit="[1], fixit_EQ, Joined, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it advice creating a file with the given suffix", nullptr, nullptr)
OPTION(prefix_1, &"-fixit"[1], fixit, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it advice to the input source", nullptr, nullptr)
OPTION(prefix_2, &"/FI"[1], _SLASH_FI, JoinedOrSeparate, cl_Group, include, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Include file before parsing", nullptr, nullptr)
OPTION(prefix_2, &"/Fi"[1], _SLASH_Fi, Joined, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Set preprocess output file name (with /P)", "<file>", nullptr)
OPTION(prefix_1, &"-fjump-tables"[1], fjump_tables, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Use jump tables for lowering switches", nullptr, nullptr)
OPTION(prefix_1, &"-fkeep-inline-functions"[1], fanonymous_1321, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fkeep-static-consts"[1], fkeep_static_consts, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption, 0,
       "Keep static const variables if unused", nullptr, nullptr)
OPTION(prefix_1, &"-flarge-sizes"[1], flarge_sizes, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Use INTEGER(KIND=8) for the result type in size-related intrinsics", nullptr, nullptr)
OPTION(prefix_1, &"-flat_namespace"[1], flat__namespace, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-flax-vector-conversions="[1], flax_vector_conversions_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable implicit vector bit-casts", nullptr, "none,integer,all")
OPTION(prefix_1, &"-flax-vector-conversions"[1], flax_vector_conversions, Flag, f_Group, flax_vector_conversions_EQ, "integer\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-flegacy-pass-manager"[1], flegacy_pass_manager, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use the legacy pass manager in LLVM (deprecated, to be removed in a future release)", nullptr, nullptr)
OPTION(prefix_1, &"-flimit-debug-info"[1], flimit_debug_info, Flag, INVALID, fno_standalone_debug, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-flimited-precision="[1], flimited_precision_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-flogical-abbreviations"[1], flogical_abbreviations, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Enable logical abbreviations", nullptr, nullptr)
OPTION(prefix_1, &"-flto-jobs="[1], flto_jobs_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Controls the backend parallelism of -flto=thin (default of 0 means the number of threads will be derived from the number of CPUs detected)", nullptr, nullptr)
OPTION(prefix_1, &"-flto-unit"[1], flto_unit, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit IR to support LTO unit features (CFI, whole program vtable opt)", nullptr, nullptr)
OPTION(prefix_1, &"-flto-visibility-public-std"[1], flto_visibility_public_std, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use public LTO visibility for classes in std and stdext namespaces", nullptr, nullptr)
OPTION(prefix_1, &"-flto=auto"[1], flto_EQ_auto, Flag, f_Group, flto_EQ, "full\0", 0, 0,
       "Enable LTO in 'full' mode", nullptr, nullptr)
OPTION(prefix_1, &"-flto=jobserver"[1], flto_EQ_jobserver, Flag, f_Group, flto_EQ, "full\0", 0, 0,
       "Enable LTO in 'full' mode", nullptr, nullptr)
OPTION(prefix_1, &"-flto="[1], flto_EQ, Joined, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Set LTO mode to either 'full' or 'thin'", nullptr, "thin,full")
OPTION(prefix_1, &"-flto"[1], flto, Flag, f_Group, flto_EQ, "full\0", CoreOption | CC1Option, 0,
       "Enable LTO in 'full' mode", nullptr, nullptr)
OPTION(prefix_1, &"-fmacro-backtrace-limit="[1], fmacro_backtrace_limit_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmacro-backtrace-limit"[1], fmacro_backtrace_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of entries to print in a macro expansion backtrace (0 = no limit).", "<N>", nullptr)
OPTION(prefix_1, &"-fmacro-prefix-map="[1], fmacro_prefix_map_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "remap file source paths in predefined preprocessor macros and __builtin_FILE()", nullptr, nullptr)
OPTION(prefix_1, &"-fmath-errno"[1], fmath_errno, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Require math functions to indicate errors by setting errno", nullptr, nullptr)
OPTION(prefix_1, &"-fmax-array-constructor="[1], fmax_array_constructor_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmax-errors="[1], fmax_errors_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmax-identifier-length"[1], fmax_identifier_length, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmax-stack-var-size="[1], fmax_stack_var_size_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmax-subrecord-length="[1], fmax_subrecord_length_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmax-tokens="[1], fmax_tokens_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Max total number of preprocessed tokens for -Wmax-tokens.", nullptr, nullptr)
OPTION(prefix_1, &"-fmax-type-align="[1], fmax_type_align_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the maximum alignment to enforce on pointers lacking an explicit alignment", nullptr, nullptr)
OPTION(prefix_1, &"-fmemory-profile="[1], fmemory_profile_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable heap memory profiling and dump results into <directory>", "<directory>", nullptr)
OPTION(prefix_1, &"-fmemory-profile"[1], fmemory_profile, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable heap memory profiling", nullptr, nullptr)
OPTION(prefix_1, &"-fmerge-all-constants"[1], fmerge_all_constants, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Allow merging of constants", nullptr, nullptr)
OPTION(prefix_1, &"-fmerge-constants"[1], fmerge_constants, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmerge-functions"[1], fmerge_functions, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Permit merging of identical functions when optimizing.", nullptr, nullptr)
OPTION(prefix_1, &"-fmessage-length="[1], fmessage_length_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Format message diagnostics so that they fit within N columns", nullptr, nullptr)
OPTION(prefix_1, &"-fminimize-whitespace"[1], fminimize_whitespace, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Minimize whitespace when emitting preprocessor output", nullptr, nullptr)
OPTION(prefix_1, &"-fmodule-feature"[1], fmodule_feature, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable <feature> in module map requires declarations", "<feature>", nullptr)
OPTION(prefix_1, &"-fmodule-file-deps"[1], fmodule_file_deps, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmodule-file="[1], fmodule_file, Joined, i_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Specify the mapping of module name to precompiled module file, or load a module file if name is omitted.", "[<name>=]<file>", nullptr)
OPTION(prefix_1, &"-fmodule-format="[1], fmodule_format_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Select the container format for clang modules and PCH. Supported options are 'raw' and 'obj'.", nullptr, nullptr)
OPTION(prefix_1, &"-fmodule-implementation-of"[1], fmodule_implementation_of, Separate, INVALID, fmodule_name_EQ, nullptr, CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmodule-map-file-home-is-cwd"[1], fmodule_map_file_home_is_cwd, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the current working directory as the home directory of module maps specified by -fmodule-map-file=<FILE>", nullptr, nullptr)
OPTION(prefix_1, &"-fmodule-map-file="[1], fmodule_map_file, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Load this module map file", "<file>", nullptr)
OPTION(prefix_1, &"-fmodule-maps"[1], fmodule_maps, Flag, INVALID, fimplicit_module_maps, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmodule-name="[1], fmodule_name_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Specify the name of the module to build", "<name>", nullptr)
OPTION(prefix_1, &"-fmodule-private"[1], fmodule_private, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-cache-path="[1], fmodules_cache_path, Joined, i_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the module cache path", "<directory>", nullptr)
OPTION(prefix_1, &"-fmodules-codegen"[1], fmodules_codegen, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate code for uses of this module that assumes an explicit object file will be built for the module", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-debuginfo"[1], fmodules_debuginfo, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate debug info for types in an object file built from this module and do not generate them elsewhere", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-decluse"[1], fmodules_decluse, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption | CoreOption, 0,
       "Require declaration of modules used within a module", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-disable-diagnostic-validation"[1], fmodules_disable_diagnostic_validation, Flag, i_Group, INVALID, nullptr, CC1Option, 0,
       "Disable validation of the diagnostic options when loading the module", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-embed-all-files"[1], fmodules_embed_all_files, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Embed the contents of all files read by this compilation into the produced module file.", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-embed-file="[1], fmodules_embed_file_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Embed the contents of the specified file into the module file being compiled.", "<file>", nullptr)
OPTION(prefix_1, &"-fmodules-hash-content"[1], fmodules_hash_content, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable hashing the content of a module file", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-ignore-macro="[1], fmodules_ignore_macro, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Ignore the definition of the given macro when building and loading modules", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-local-submodule-visibility"[1], fmodules_local_submodule_visibility, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enforce name visibility rules across submodules of the same top-level module.", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-prune-after="[1], fmodules_prune_after, Joined, i_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the interval (in seconds) after which a module file will be considered unused", "<seconds>", nullptr)
OPTION(prefix_1, &"-fmodules-prune-interval="[1], fmodules_prune_interval, Joined, i_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the interval (in seconds) between attempts to prune the module cache", "<seconds>", nullptr)
OPTION(prefix_1, &"-fmodules-search-all"[1], fmodules_search_all, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Search even non-imported modules to resolve references", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-strict-context-hash"[1], fmodules_strict_context_hash, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable hashing of all compiler options that could impact the semantics of a module in an implicit build", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-strict-decluse"[1], fmodules_strict_decluse, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Like -fmodules-decluse but requires all headers to be in modules", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-ts"[1], fmodules_ts, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for the C++ Modules TS", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-user-build-path"[1], fmodules_user_build_path, Separate, i_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the module user build path", "<directory>", nullptr)
OPTION(prefix_1, &"-fmodules-validate-input-files-content"[1], fmodules_validate_input_files_content, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Validate PCM input files based on content if mtime differs", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-validate-once-per-build-session"[1], fmodules_validate_once_per_build_session, Flag, i_Group, INVALID, nullptr, CC1Option, 0,
       "Don't verify input files for the modules if the module has been successfully validated or loaded during this build session", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules-validate-system-headers"[1], fmodules_validate_system_headers, Flag, i_Group, INVALID, nullptr, CC1Option, 0,
       "Validate the system headers that a module depends on when loading the module", nullptr, nullptr)
OPTION(prefix_1, &"-fmodules"[1], fmodules, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption | CoreOption, 0,
       "Enable the 'modules' language feature", nullptr, nullptr)
OPTION(prefix_1, &"-fmodulo-sched-allow-regmoves"[1], fmodulo_sched_allow_regmoves, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmodulo-sched"[1], fmodulo_sched, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fms-compatibility-version="[1], fms_compatibility_version, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Dot-separated value representing the Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))", nullptr, nullptr)
OPTION(prefix_1, &"-fms-compatibility"[1], fms_compatibility, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable full Microsoft Visual C++ compatibility", nullptr, nullptr)
OPTION(prefix_1, &"-fms-extensions"[1], fms_extensions, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Accept some non-standard constructs supported by the Microsoft compiler", nullptr, nullptr)
OPTION(prefix_1, &"-fms-memptr-rep="[1], fms_memptr_rep_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "single,multiple,virtual")
OPTION(prefix_1, &"-fms-volatile"[1], fms_volatile, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmsc-version="[1], fmsc_version, Joined, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))", nullptr, nullptr)
OPTION(prefix_1, &"-fmudflapth"[1], fmudflapth, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fmudflap"[1], fmudflap, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Fm"[1], _SLASH_Fm, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fnative-half-arguments-and-returns"[1], fnative_half_arguments_and_returns, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the native __fp16 type for arguments and returns (and skip ABI-specific lowering)", nullptr, nullptr)
OPTION(prefix_1, &"-fnative-half-type"[1], fnative_half_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the native half type for __fp16 instead of promoting to float", nullptr, nullptr)
OPTION(prefix_1, &"-fnested-functions"[1], fnested_functions, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fnew-alignment="[1], fnew_alignment_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specifies the largest alignment guaranteed by '::operator new(size_t)'", "<align>", nullptr)
OPTION(prefix_1, &"-fnew-alignment"[1], anonymous_837, Separate, INVALID, fnew_alignment_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fnew-infallible"[1], fnew_infallible, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable treating throwing global C++ operator new as always returning valid memory (annotates with __attribute__((returns_nonnull)) and throw()). This is detectable in source.", nullptr, nullptr)
OPTION(prefix_1, &"-fnext-runtime"[1], fnext_runtime, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-aapcs-bitfield-width"[1], fno_aapcs_bitfield_width, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Do not follow the AAPCS standard requirement stating that volatile bit-field width is dictated by the field container type. (ARM only).", nullptr, nullptr)
OPTION(prefix_1, &"-fno-access-control"[1], fno_access_control, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ access control", nullptr, nullptr)
OPTION(prefix_1, &"-fno-addrsig"[1], fno_addrsig, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Don't emit an address-significance table", nullptr, nullptr)
OPTION(prefix_1, &"-fno-aggressive-function-elimination"[1], fno_aggressive_function_elimination, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-align-commons"[1], fno_align_commons, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-align-functions"[1], fno_align_functions, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-align-jumps"[1], fno_align_jumps, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-align-labels"[1], fno_align_labels, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-align-loops"[1], fno_align_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-aligned-allocation"[1], fno_aligned_allocation, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-aligned-new"[1], anonymous_839, Flag, INVALID, fno_aligned_allocation, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-all-intrinsics"[1], fno_all_intrinsics, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-allow-editor-placeholders"[1], fno_allow_editor_placeholders, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-altivec"[1], fno_altivec, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-analyzed-objects-for-unparse"[1], fno_analyzed_objects_for_unparse, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Do not use the analyzed objects when unparsing", nullptr, nullptr)
OPTION(prefix_1, &"-fno-apple-pragma-pack"[1], fno_apple_pragma_pack, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-application-extension"[1], fno_application_extension, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-approx-func"[1], fno_approx_func, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-asm-blocks"[1], fno_asm_blocks, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-asm"[1], fno_asm, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-associative-math"[1], fno_associative_math, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-assume-sane-operator-new"[1], fno_assume_sane_operator_new, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't assume that C++'s global operator new can't alias any pointer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-async-exceptions"[1], fno_async_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-asynchronous-unwind-tables"[1], fno_asynchronous_unwind_tables, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-auto-profile-accurate"[1], fno_auto_profile_accurate, Flag, f_Group, fno_profile_sample_accurate, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-auto-profile"[1], fno_auto_profile, Flag, f_Group, fno_profile_sample_use, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-autolink"[1], fno_autolink, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of linker directives for automatic library linking", nullptr, nullptr)
OPTION(prefix_1, &"-fno-automatic"[1], fno_automatic, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Implies the SAVE attribute for non-automatic local objects in subprograms unless RECURSIVE", nullptr, nullptr)
OPTION(prefix_1, &"-fno-backslash"[1], fno_backslash, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-backtrace"[1], fno_backtrace, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-bitfield-type-align"[1], fno_bitfield_type_align, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Ignore bit-field types when aligning structures", nullptr, nullptr)
OPTION(prefix_1, &"-fno-blocks"[1], fno_blocks, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-borland-extensions"[1], fno_borland_extensions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-bounds-check"[1], fno_bounds_check, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-branch-count-reg"[1], fno_branch_count_reg, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-builtin-"[1], fno_builtin_, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable implicit builtin knowledge of a specific function", nullptr, nullptr)
OPTION(prefix_1, &"-fno-builtin"[1], fno_builtin, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable implicit builtin knowledge of functions", nullptr, nullptr)
OPTION(prefix_1, &"-fno-c++-static-destructors"[1], fno_cxx_static_destructors, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ static destructor registration", nullptr, nullptr)
OPTION(prefix_1, &"-fno-caller-saves"[1], fno_caller_saves, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-caret-diagnostics"[1], fno_caret_diagnostics, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-char8_t"[1], fno_char8__t, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ builtin type char8_t", nullptr, nullptr)
OPTION(prefix_1, &"-fno-check-array-temporaries"[1], fno_check_array_temporaries, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-check-new"[1], fno_fcheck_new, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-color-diagnostics"[1], fno_color_diagnostics, Flag, f_Group, INVALID, nullptr, CoreOption | FlangOption, 0,
       "Disable colors in diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fno-common"[1], fno_common, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Compile common globals like normal definitions", nullptr, nullptr)
OPTION(prefix_1, &"-fno-complete-member-pointers"[1], fno_complete_member_pointers, Flag, f_clang_Group, INVALID, nullptr, CoreOption, 0,
       "Do not require member pointer base types to be complete if they would be significant under the Microsoft ABI", nullptr, nullptr)
OPTION(prefix_1, &"-fno-concept-satisfaction-caching"[1], fno_concept_satisfaction_caching, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable satisfaction caching for C++2a Concepts.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-const-strings"[1], fno_const_strings, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't use a const qualified type for string literals in C and ObjC", nullptr, nullptr)
OPTION(prefix_1, &"-fno-constant-cfstrings"[1], fno_constant_cfstrings, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable creation of CodeFoundation-type constant strings", nullptr, nullptr)
OPTION(prefix_1, &"-fno-coroutines-ts"[1], fno_coroutines_ts, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-coverage-mapping"[1], fno_coverage_mapping, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Disable code coverage analysis", nullptr, nullptr)
OPTION(prefix_1, &"-fno-crash-diagnostics"[1], fno_crash_diagnostics, Flag, f_clang_Group, INVALID, nullptr, NoArgumentUnused | CoreOption, 0,
       "Disable auto-generation of preprocessed source files and a script for reproduction during a clang crash", nullptr, nullptr)
OPTION(prefix_1, &"-fno-cray-pointer"[1], fno_cray_pointer, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-cuda-approx-transcendentals"[1], fno_cuda_approx_transcendentals, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't use approximate transcendental functions", nullptr, nullptr)
OPTION(prefix_1, &"-fno-cuda-flush-denormals-to-zero"[1], fno_cuda_flush_denormals_to_zero, Flag, INVALID, fno_gpu_flush_denormals_to_zero, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-cuda-host-device-constexpr"[1], fno_cuda_host_device_constexpr, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't treat unattributed constexpr functions as __host__ __device__.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-cuda-rdc"[1], anonymous_53, Flag, INVALID, fno_gpu_rdc, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-cuda-short-ptr"[1], fno_cuda_short_ptr, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-cxx-exceptions"[1], fno_cxx_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-cxx-modules"[1], fno_cxx_modules, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption, 0,
       "Disable modules for C++", nullptr, nullptr)
OPTION(prefix_1, &"-fno-d-lines-as-code"[1], fno_d_lines_as_code, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-d-lines-as-comments"[1], fno_d_lines_as_comments, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-data-sections"[1], fno_data_sections, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-debug-info-for-profiling"[1], fno_debug_info_for_profiling, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-debug-macro"[1], fno_debug_macro, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Do not emit macro debug information", nullptr, nullptr)
OPTION(prefix_1, &"-fno-debug-pass-manager"[1], fno_debug_pass_manager, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disables debug printing for the new pass manager", nullptr, nullptr)
OPTION(prefix_1, &"-fno-debug-ranges-base-address"[1], fno_debug_ranges_base_address, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-debug-types-section"[1], fno_debug_types_section, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-declspec"[1], fno_declspec, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Disallow __declspec as a keyword", nullptr, nullptr)
OPTION(prefix_1, &"-fno-default-inline"[1], fno_default_inline, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-defer-pop"[1], anonymous_366, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-delayed-template-parsing"[1], fno_delayed_template_parsing, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Disable delayed template parsing", nullptr, nullptr)
OPTION(prefix_1, &"-fno-delete-null-pointer-checks"[1], fno_delete_null_pointer_checks, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Do not treat usage of null pointers as undefined behavior", nullptr, nullptr)
OPTION(prefix_1, &"-fno-deprecated-macro"[1], fno_deprecated_macro, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Undefines the __DEPRECATED macro", nullptr, nullptr)
OPTION(prefix_1, &"-fno-devirtualize-speculatively"[1], fno_devirtualize_speculatively, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-devirtualize"[1], fno_devirtualize, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-diagnostics-color"[1], fno_diagnostics_color, Flag, f_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-diagnostics-fixit-info"[1], fno_diagnostics_fixit_info, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not include fixit information in diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fno-diagnostics-show-hotness"[1], fno_diagnostics_show_hotness, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-diagnostics-show-note-include-stack"[1], fno_diagnostics_show_note_include_stack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-diagnostics-show-option"[1], fno_diagnostics_show_option, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-diagnostics-use-presumed-location"[1], fno_diagnostics_use_presumed_location, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Ignore #line directives when displaying diagnostic locations", nullptr, nullptr)
OPTION(prefix_1, &"-fno-digraphs"[1], fno_digraphs, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disallow alternative token representations '<:', ':>', '<%', '%>', '%:', '%:%:'", nullptr, nullptr)
OPTION(prefix_1, &"-fno-direct-access-external-data"[1], fno_direct_access_external_data, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use GOT indirection to reference external data symbols", nullptr, nullptr)
OPTION(prefix_1, &"-fno-discard-value-names"[1], fno_discard_value_names, Flag, f_clang_Group, INVALID, nullptr, NoXarchOption, 0,
       "Do not discard value names in LLVM IR", nullptr, nullptr)
OPTION(prefix_1, &"-fno-dllexport-inlines"[1], fno_dllexport_inlines, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-dollar-ok"[1], fno_dollar_ok, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-dollars-in-identifiers"[1], fno_dollars_in_identifiers, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disallow '$' in identifiers", nullptr, nullptr)
OPTION(prefix_1, &"-fno-double-square-bracket-attributes"[1], fno_double_square_bracket_attributes, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Disable '[[]]' attributes in all C and C++ language modes", nullptr, nullptr)
OPTION(prefix_1, &"-fno-dump-fortran-optimized"[1], fno_dump_fortran_optimized, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-dump-fortran-original"[1], fno_dump_fortran_original, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-dump-parse-tree"[1], fno_dump_parse_tree, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-dwarf-directory-asm"[1], fno_dwarf_directory_asm, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-dwarf2-cfi-asm"[1], fno_dwarf2_cfi_asm, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-elide-constructors"[1], fno_elide_constructors, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ copy constructor elision", nullptr, nullptr)
OPTION(prefix_1, &"-fno-elide-type"[1], fno_elide_type, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not elide types when printing diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fno-eliminate-unused-debug-symbols"[1], fno_eliminate_unused_debug_symbols, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-eliminate-unused-debug-types"[1], fno_eliminate_unused_debug_types, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Emit  debug info for defined but unused types", nullptr, nullptr)
OPTION(prefix_1, &"-fno-emulated-tls"[1], fno_emulated_tls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-escaping-block-tail-calls"[1], fno_escaping_block_tail_calls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-exceptions"[1], fno_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable support for exception handling", nullptr, nullptr)
OPTION(prefix_1, &"-fno-expensive-optimizations"[1], anonymous_364, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-experimental-isel"[1], fno_experimental_isel, Flag, f_clang_Group, fno_global_isel, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-experimental-new-pass-manager"[1], fno_experimental_new_pass_manager, Flag, f_clang_Group, flegacy_pass_manager, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-experimental-relative-c++-abi-vtables"[1], fno_experimental_relative_cxx_abi_vtables, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Do not use the experimental C++ class ABI for classes with virtual tables", nullptr, nullptr)
OPTION(prefix_1, &"-fno-extended-identifiers"[1], anonymous_368, Flag, f_Group, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-external-blas"[1], fno_external_blas, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-f2c"[1], fno_f2c, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-fast-math"[1], fno_fast_math, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-fat-lto-objects"[1], fno_fat_lto_objects, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-fine-grained-bitfield-accesses"[1], fno_fine_grained_bitfield_accesses, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use large-integer access for consecutive bitfield runs.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-finite-loops"[1], fno_finite_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not assume that any loop is finite.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-finite-math-only"[1], fno_finite_math_only, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-fixed-point"[1], fno_fixed_point, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable fixed point types", nullptr, nullptr)
OPTION(prefix_1, &"-fno-float-store"[1], fno_float_store, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-for-scope"[1], fno_for_scope, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-force-dwarf-frame"[1], fno_force_dwarf_frame, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-force-emit-vtables"[1], fno_force_emit_vtables, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-force-enable-int128"[1], fno_force_enable_int128, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable support for int128_t type", nullptr, nullptr)
OPTION(prefix_1, &"-fno-friend-injection"[1], fno_friend_injection, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-frontend-optimize"[1], fno_frontend_optimize, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-function-attribute-list"[1], fno_function_attribute_list, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-function-sections"[1], fno_function_sections, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gcse-after-reload"[1], fno_gcse_after_reload, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-gcse-las"[1], fno_gcse_las, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-gcse-sm"[1], fno_gcse_sm, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-gcse"[1], fno_gcse, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-global-isel"[1], fno_global_isel, Flag, f_clang_Group, INVALID, nullptr, 0, 0,
       "Disables the global instruction selector", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gnu-inline-asm"[1], fno_gnu_inline_asm, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable GNU style inline asm", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gnu-keywords"[1], fno_gnu_keywords, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gnu89-inline"[1], fno_gnu89_inline, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gnu"[1], fno_gnu, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-gpu-allow-device-init"[1], fno_gpu_allow_device_init, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't allow device side init function in HIP (experimental)", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gpu-defer-diag"[1], fno_gpu_defer_diag, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't defer host/device related diagnostic messages for CUDA/HIP", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gpu-exclude-wrong-side-overloads"[1], fno_gpu_exclude_wrong_side_overloads, Flag, f_Group, INVALID, nullptr, HelpHidden, 0,
       "Exclude wrong side overloads only if there are same side overloads in overloading resolution for CUDA/HIP", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gpu-flush-denormals-to-zero"[1], fno_gpu_flush_denormals_to_zero, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-gpu-rdc"[1], fno_gpu_rdc, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-gpu-sanitize"[1], fno_gpu_sanitize, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-hip-fp32-correctly-rounded-divide-sqrt"[1], fno_hip_fp32_correctly_rounded_divide_sqrt, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't specify that single precision floating-point divide and sqrt used in the program source are correctly rounded (HIP device compilation only)", nullptr, nullptr)
OPTION(prefix_1, &"-fno-hip-new-launch-api"[1], fno_hip_new_launch_api, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't use new kernel launching API for HIP", nullptr, nullptr)
OPTION(prefix_1, &"-fno-honor-infinites"[1], anonymous_529, Flag, INVALID, fno_honor_infinities, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-honor-infinities"[1], fno_honor_infinities, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-honor-nans"[1], fno_honor_nans, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-ident"[1], anonymous_32, Flag, f_Group, Qn, nullptr, CoreOption | CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-implement-inlines"[1], fno_implement_inlines, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-implicit-module-maps"[1], fno_implicit_module_maps, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-implicit-modules-use-lock"[1], fno_fimplicit_modules_use_lock, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-implicit-modules"[1], fno_implicit_modules, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-implicit-none"[1], fno_implicit_none, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-implicit-templates"[1], fno_implicit_templates, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-init-local-zero"[1], fno_init_local_zero, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-inline-functions-called-once"[1], fno_inline_functions_called_once, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-inline-functions"[1], fno_inline_functions, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-inline-limit"[1], fno_finline_limit, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-inline-small-functions"[1], fno_inline_small_functions, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-inline"[1], fno_inline, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-integer-4-integer-8"[1], fno_integer_4_integer_8, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-integrated-as"[1], fno_integrated_as, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable the integrated assembler", nullptr, nullptr)
OPTION(prefix_1, &"-fno-integrated-cc1"[1], fno_integrated_cc1, Flag, f_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Spawn a separate process for each cc1", nullptr, nullptr)
OPTION(prefix_1, &"-fno-ipa-cp"[1], fno_ipa_cp, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-ivopts"[1], fno_ivopts, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-jump-tables"[1], fno_jump_tables, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not use jump tables for lowering switches", nullptr, nullptr)
OPTION(prefix_1, &"-fno-keep-inline-functions"[1], fno_anonymous_1321, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-keep-static-consts"[1], fno_keep_static_consts, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Don't keep static const variables if unused", nullptr, nullptr)
OPTION(prefix_1, &"-fno-lax-vector-conversions"[1], fno_lax_vector_conversions, Flag, f_Group, flax_vector_conversions_EQ, "none\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-legacy-pass-manager"[1], fno_legacy_pass_manager, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use the new pass manager in LLVM", nullptr, nullptr)
OPTION(prefix_1, &"-fno-limit-debug-info"[1], fno_limit_debug_info, Flag, INVALID, fstandalone_debug, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-logical-abbreviations"[1], fno_logical_abbreviations, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-lto-unit"[1], fno_lto_unit, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-lto"[1], fno_lto, Flag, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Disable LTO mode (default)", nullptr, nullptr)
OPTION(prefix_1, &"-fno-math-builtin"[1], fno_math_builtin, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Disable implicit builtin knowledge of math functions", nullptr, nullptr)
OPTION(prefix_1, &"-fno-math-errno"[1], fno_math_errno, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-max-identifier-length"[1], fno_max_identifier_length, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-max-type-align"[1], fno_max_type_align, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-memory-profile"[1], fno_memory_profile, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable heap memory profiling", nullptr, nullptr)
OPTION(prefix_1, &"-fno-merge-all-constants"[1], fno_merge_all_constants, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disallow merging of constants", nullptr, nullptr)
OPTION(prefix_1, &"-fno-merge-constants"[1], fno_merge_constants, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-minimize-whitespace"[1], fno_minimize_whitespace, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-module-file-deps"[1], fno_module_file_deps, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-module-maps"[1], fno_module_maps, Flag, INVALID, fno_implicit_module_maps, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-module-private"[1], fno_module_private, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-modules-decluse"[1], fno_modules_decluse, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-modules-error-recovery"[1], fno_modules_error_recovery, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not automatically import modules for error recovery", nullptr, nullptr)
OPTION(prefix_1, &"-fno-modules-global-index"[1], fno_modules_global_index, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not automatically generate or update the global module index", nullptr, nullptr)
OPTION(prefix_1, &"-fno-modules-search-all"[1], fno_modules_search_all, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-modules-validate-system-headers"[1], fno_modules_validate_system_headers, Flag, i_Group, INVALID, nullptr, NoXarchOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-modules"[1], fno_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-modulo-sched-allow-regmoves"[1], fno_modulo_sched_allow_regmoves, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-modulo-sched"[1], fno_modulo_sched, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-ms-compatibility"[1], fno_ms_compatibility, Flag, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-ms-extensions"[1], fno_ms_extensions, Flag, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-new-infallible"[1], fno_new_infallible, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable treating throwing global C++ operator new as always returning valid memory (annotates with __attribute__((returns_nonnull)) and throw()). This is detectable in source.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-non-call-exceptions"[1], fno_non_call_exceptions, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-arc-exceptions"[1], fno_objc_arc_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-arc"[1], fno_objc_arc, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-avoid-heapify-local-blocks"[1], fno_objc_avoid_heapify_local_blocks, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't try to avoid heapifying local blocks", nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-convert-messages-to-runtime-calls"[1], fno_objc_convert_messages_to_runtime_calls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-encode-cxx-class-template-spec"[1], fno_objc_encode_cxx_class_template_spec, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-exceptions"[1], fno_objc_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-infer-related-result-type"[1], fno_objc_infer_related_result_type, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "do not infer Objective-C related result type based on method family", nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-legacy-dispatch"[1], fno_objc_legacy_dispatch, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-nonfragile-abi"[1], fno_objc_nonfragile_abi, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-objc-weak"[1], fno_objc_weak, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-offload-lto"[1], fno_offload_lto, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Disable LTO mode (default) for offload compilation", nullptr, nullptr)
OPTION(prefix_1, &"-fno-omit-frame-pointer"[1], fno_omit_frame_pointer, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-assume-teams-oversubscription"[1], fno_openmp_assume_teams_oversubscription, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-assume-threads-oversubscription"[1], fno_openmp_assume_threads_oversubscription, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-cuda-force-full-runtime"[1], fno_openmp_cuda_force_full_runtime, Flag, f_Group, INVALID, nullptr, NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-cuda-mode"[1], fno_openmp_cuda_mode, Flag, f_Group, INVALID, nullptr, NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-extensions"[1], fno_openmp_extensions, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Disable all Clang extensions for OpenMP directives and clauses", nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-optimistic-collapse"[1], fno_openmp_optimistic_collapse, Flag, f_Group, INVALID, nullptr, NoArgumentUnused | HelpHidden, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-simd"[1], fno_openmp_simd, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-target-debug"[1], fno_openmp_target_debug, Flag, f_Group, INVALID, nullptr, NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp-target-new-runtime"[1], fno_openmp_target_new_runtime, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-openmp"[1], fno_openmp, Flag, f_Group, INVALID, nullptr, NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-operator-names"[1], fno_operator_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not treat C++ operator name keywords as synonyms for operators", nullptr, nullptr)
OPTION(prefix_1, &"-fno-optimize-sibling-calls"[1], fno_optimize_sibling_calls, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-pack-derived"[1], fno_pack_derived, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-pack-struct"[1], fno_pack_struct, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-padding-on-unsigned-fixed-point"[1], fno_padding_on_unsigned_fixed_point, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-pascal-strings"[1], fno_pascal_strings, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-pch-codegen"[1], fno_pch_codegen, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Do not generate code for uses of this PCH that assumes an explicit object file will be built for the PCH", nullptr, nullptr)
OPTION(prefix_1, &"-fno-pch-debuginfo"[1], fno_pch_debuginfo, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Do not generate debug info for types in an object file built from this PCH and do not generate them elsewhere", nullptr, nullptr)
OPTION(prefix_1, &"-fno-pch-instantiate-templates"[1], fno_pch_instantiate_templates, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-pch-timestamp"[1], fno_pch_timestamp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable inclusion of timestamp in precompiled headers", nullptr, nullptr)
OPTION(prefix_1, &"-fno-peel-loops"[1], fno_peel_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-permissive"[1], fno_permissive, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-PIC"[1], fno_PIC, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-pic"[1], fno_pic, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-PIE"[1], fno_PIE, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-pie"[1], fno_pie, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-plt"[1], fno_plt, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use GOT indirection instead of PLT to make external function calls (x86 only)", nullptr, nullptr)
OPTION(prefix_1, &"-fno-prebuilt-implicit-modules"[1], fno_prebuilt_implicit_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-prefetch-loop-arrays"[1], fno_prefetch_loop_arrays, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-preserve-as-comments"[1], fno_preserve_as_comments, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not preserve comments in inline assembly", nullptr, nullptr)
OPTION(prefix_1, &"-fno-printf"[1], fno_printf, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-arcs"[1], fno_profile_arcs, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-correction"[1], fno_profile_correction, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-generate-sampling"[1], fno_profile_generate_sampling, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-generate"[1], fno_profile_generate, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Disable generation of profile instrumentation.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-instr-generate"[1], fno_profile_instr_generate, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Disable generation of profile instrumentation.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-instr-use"[1], fno_profile_instr_use, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Disable using instrumentation data for profile-guided optimization", nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-reusedist"[1], fno_profile_reusedist, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-sample-accurate"[1], fno_profile_sample_accurate, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-sample-use"[1], fno_profile_sample_use, Flag, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-use"[1], fno_profile_use, Flag, INVALID, fno_profile_instr_use, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile-values"[1], fno_profile_values, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-profile"[1], fno_profile, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-protect-parens"[1], fno_protect_parens, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-pseudo-probe-for-profiling"[1], fno_pseudo_probe_for_profiling, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Do not emit pseudo probes for sample profiling", nullptr, nullptr)
OPTION(prefix_1, &"-fno-range-check"[1], fno_range_check, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-real-4-real-10"[1], fno_real_4_real_10, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-real-4-real-16"[1], fno_real_4_real_16, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-real-4-real-8"[1], fno_real_4_real_8, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-real-8-real-10"[1], fno_real_8_real_10, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-real-8-real-16"[1], fno_real_8_real_16, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-real-8-real-4"[1], fno_real_8_real_4, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-realloc-lhs"[1], fno_realloc_lhs, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-reciprocal-math"[1], fno_reciprocal_math, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-record-command-line"[1], fno_record_command_line, Flag, f_clang_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-record-gcc-switches"[1], anonymous_253, Flag, INVALID, fno_record_command_line, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-recovery-ast-type"[1], fno_recovery_ast_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-recovery-ast"[1], fno_recovery_ast, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-recursive"[1], fno_recursive, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-reformat"[1], fno_reformat, Flag, Preprocessor_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Dump the cooked character stream in -E mode", nullptr, nullptr)
OPTION(prefix_1, &"-fno-register-global-dtors-with-atexit"[1], fno_register_global_dtors_with_atexit, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't use atexit or __cxa_atexit to register global destructors", nullptr, nullptr)
OPTION(prefix_1, &"-fno-regs-graph"[1], fno_regs_graph, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-relaxed-template-template-args"[1], fno_relaxed_template_template_args, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-rename-registers"[1], fno_rename_registers, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-reorder-blocks"[1], fno_reorder_blocks, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-repack-arrays"[1], fno_repack_arrays, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-reroll-loops"[1], fno_reroll_loops, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-rewrite-imports"[1], fno_rewrite_imports, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-rewrite-includes"[1], fno_rewrite_includes, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-ripa"[1], fno_ripa, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-ropi"[1], fno_ropi, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-rounding-math"[1], fno_rounding_math, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-rtlib-add-rpath"[1], fno_rtlib_add_rpath, Flag, INVALID, INVALID, nullptr, NoArgumentUnused, 0,
       "Do not add -rpath with architecture-specific resource directory to the linker flags", nullptr, nullptr)
OPTION(prefix_1, &"-fno-rtti-data"[1], fno_rtti_data, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of RTTI data", nullptr, nullptr)
OPTION(prefix_1, &"-fno-rtti"[1], fno_rtti, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of rtti information", nullptr, nullptr)
OPTION(prefix_1, &"-fno-rwpi"[1], fno_rwpi, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-address-outline-instrumentation"[1], fno_sanitize_address_outline_instrumentation, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Use default code inlining logic for the address sanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-address-poison-custom-array-cookie"[1], fno_sanitize_address_poison_custom_array_cookie, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable poisoning array cookies when using custom operator new[] in AddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-address-use-after-scope"[1], fno_sanitize_address_use_after_scope, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable use-after-scope detection in AddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-address-use-odr-indicator"[1], fno_sanitize_address_use_odr_indicator, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable ODR indicator globals", nullptr, nullptr)
OPTION(prefix_2, &"/fno-sanitize-address-vcasan-lib"[1], _SLASH_fno_sanitize_address_vcasan_lib, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-blacklist"[1], anonymous_429, Flag, f_clang_Group, fno_sanitize_ignorelist, nullptr, CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-cfi-canonical-jump-tables"[1], fno_sanitize_cfi_canonical_jump_tables, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Do not make the jump table addresses canonical in the symbol table", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-cfi-cross-dso"[1], fno_sanitize_cfi_cross_dso, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable control flow integrity (CFI) checks for cross-DSO calls.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-coverage="[1], fno_sanitize_coverage, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable features of coverage instrumentation for Sanitizers", nullptr, "func,bb,edge,indirect-calls,trace-bb,trace-cmp,trace-div,trace-gep,8bit-counters,trace-pc,trace-pc-guard,no-prune,inline-8bit-counters,inline-bool-flag")
OPTION(prefix_1, &"-fno-sanitize-hwaddress-experimental-aliasing"[1], fno_sanitize_hwaddress_experimental_aliasing, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable aliasing mode in HWAddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-ignorelist"[1], fno_sanitize_ignorelist, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Don't use ignorelist file for sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-link-c++-runtime"[1], fno_sanitize_link_cxx_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-link-runtime"[1], fno_sanitize_link_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-memory-track-origins"[1], fno_sanitize_memory_track_origins, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable origins tracking in MemorySanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-memory-use-after-dtor"[1], fno_sanitize_memory_use_after_dtor, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable use-after-destroy detection in MemorySanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-minimal-runtime"[1], fno_sanitize_minimal_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-recover="[1], fno_sanitize_recover_EQ, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable recovery for specified sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-recover"[1], fno_sanitize_recover, Flag, f_clang_Group, fno_sanitize_recover_EQ, "all\0", CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-stats"[1], fno_sanitize_stats, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable sanitizer statistics gathering.", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-thread-atomics"[1], fno_sanitize_thread_atomics, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable atomic operations instrumentation in ThreadSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-thread-func-entry-exit"[1], fno_sanitize_thread_func_entry_exit, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable function entry/exit instrumentation in ThreadSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-thread-memory-access"[1], fno_sanitize_thread_memory_access, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable memory access instrumentation in ThreadSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-trap="[1], fno_sanitize_trap_EQ, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable trapping for specified sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-trap"[1], fno_sanitize_trap, Flag, f_clang_Group, fno_sanitize_trap_EQ, "all\0", CC1Option | CoreOption, 0,
       "Disable trapping for all sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize-undefined-trap-on-error"[1], fno_sanitize_undefined_trap_on_error, Flag, f_clang_Group, fno_sanitize_trap_EQ, "undefined\0", CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sanitize="[1], fno_sanitize_EQ, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-save-optimization-record"[1], fno_save_optimization_record, Flag, f_Group, INVALID, nullptr, NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-schedule-insns2"[1], fno_schedule_insns2, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-schedule-insns"[1], fno_schedule_insns, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-second-underscore"[1], fno_second_underscore, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-see"[1], fno_see, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-semantic-interposition"[1], fno_semantic_interposition, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-short-enums"[1], fno_short_enums, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-short-wchar"[1], fno_short_wchar, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Force wchar_t to be an unsigned int", nullptr, nullptr)
OPTION(prefix_1, &"-fno-show-column"[1], fno_show_column, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not include column number on diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fno-show-source-location"[1], fno_show_source_location, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not include source location information with diagnostics", nullptr, nullptr)
OPTION(prefix_1, &"-fno-sign-zero"[1], fno_sign_zero, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-signaling-math"[1], fno_signaling_math, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-signaling-nans"[1], fno_signaling_nans, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-signed-char"[1], fno_signed_char, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "char is unsigned", nullptr, nullptr)
OPTION(prefix_1, &"-fno-signed-wchar"[1], fno_signed_wchar, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use an unsigned type for wchar_t", nullptr, nullptr)
OPTION(prefix_1, &"-fno-signed-zeros"[1], fno_signed_zeros, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow optimizations that ignore the sign of floating point zeros", nullptr, nullptr)
OPTION(prefix_1, &"-fno-single-precision-constant"[1], fno_single_precision_constant, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sized-deallocation"[1], fno_sized_deallocation, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-slp-vectorize-aggressive"[1], anonymous_1, Flag, clang_ignored_legacy_options_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-slp-vectorize"[1], fno_slp_vectorize, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-spec-constr-count"[1], fno_spec_constr_count, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-spell-checking"[1], fno_spell_checking, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable spell-checking", nullptr, nullptr)
OPTION(prefix_1, &"-fno-split-dwarf-inlining"[1], fno_split_dwarf_inlining, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-split-lto-unit"[1], fno_split_lto_unit, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-split-machine-functions"[1], fno_split_machine_functions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable late function splitting using profile information (x86 ELF)", nullptr, nullptr)
OPTION(prefix_1, &"-fno-split-stack"[1], fno_split_stack, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Wouldn't use segmented stack", nullptr, nullptr)
OPTION(prefix_1, &"-fno-stack-arrays"[1], fno_stack_arrays, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-stack-check"[1], fno_stack_check, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-stack-clash-protection"[1], fno_stack_clash_protection, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable stack clash protection", nullptr, nullptr)
OPTION(prefix_1, &"-fno-stack-protector"[1], fno_stack_protector, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable the use of stack protectors", nullptr, nullptr)
OPTION(prefix_1, &"-fno-stack-size-section"[1], fno_stack_size_section, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-standalone-debug"[1], fno_standalone_debug, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Limit debug information produced to reduce size of debug binary", nullptr, nullptr)
OPTION(prefix_1, &"-fno-strength-reduce"[1], fno_strength_reduce, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-strict-aliasing"[1], fno_strict_aliasing, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-strict-enums"[1], fno_strict_enums, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-strict-float-cast-overflow"[1], fno_strict_float_cast_overflow, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Relax language rules and try to match the behavior of the target's native float-to-int conversion instructions", nullptr, nullptr)
OPTION(prefix_1, &"-fno-strict-modules-decluse"[1], fno_modules_strict_decluse, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-strict-overflow"[1], fno_strict_overflow, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-strict-return"[1], fno_strict_return, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't treat control flow paths that fall off the end of a non-void function as unreachable", nullptr, nullptr)
OPTION(prefix_1, &"-fno-strict-vtable-pointers"[1], fno_strict_vtable_pointers, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-struct-path-tbaa"[1], fno_struct_path_tbaa, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-sycl"[1], fno_sycl, Flag, sycl_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Disables SYCL kernels compilation for device", nullptr, nullptr)
OPTION(prefix_1, &"-fno-temp-file"[1], fno_temp_file, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Directly create compilation output files. This may lead to incorrect incremental builds if the compiler crashes", nullptr, nullptr)
OPTION(prefix_1, &"-fno-test-coverage"[1], fno_test_coverage, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-threadsafe-statics"[1], fno_threadsafe_statics, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not emit code to make initialization of local statics thread safe", nullptr, nullptr)
OPTION(prefix_1, &"-fno-tls-model"[1], fno_tls_model, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tracer"[1], fno_tracer, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-trapping-math"[1], fno_trapping_math, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tree-dce"[1], fno_tree_dce, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tree-salias"[1], fno_tree_salias, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tree-slp-vectorize"[1], anonymous_1002, Flag, INVALID, fno_slp_vectorize, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tree-ter"[1], fno_tree_ter, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tree-vectorizer-verbose"[1], fno_tree_vectorizer_verbose, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tree-vectorize"[1], anonymous_1000, Flag, INVALID, fno_vectorize, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-tree-vrp"[1], fno_tree_vrp, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-trigraphs"[1], fno_trigraphs, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not process trigraph sequences", nullptr, nullptr)
OPTION(prefix_1, &"-fno-underscoring"[1], fno_underscoring, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-unique-basic-block-section-names"[1], fno_unique_basic_block_section_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-unique-internal-linkage-names"[1], fno_unique_internal_linkage_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-unique-section-names"[1], fno_unique_section_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't use unique names for text and data sections", nullptr, nullptr)
OPTION(prefix_1, &"-fno-unit-at-a-time"[1], fno_unit_at_a_time, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-unroll-all-loops"[1], fno_unroll_all_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-unroll-loops"[1], fno_unroll_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Turn off loop unroller", nullptr, nullptr)
OPTION(prefix_1, &"-fno-unsafe-loop-optimizations"[1], fno_unsafe_loop_optimizations, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-unsafe-math-optimizations"[1], fno_unsafe_math_optimizations, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-unsigned-char"[1], fno_unsigned_char, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-unswitch-loops"[1], fno_unswitch_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-unwind-tables"[1], fno_unwind_tables, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-use-ctor-homing"[1], fno_use_ctor_homing, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Don't use constructor homing for debug info", nullptr, nullptr)
OPTION(prefix_1, &"-fno-use-cxa-atexit"[1], fno_use_cxa_atexit, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't use __cxa_atexit for calling destructors", nullptr, nullptr)
OPTION(prefix_1, &"-fno-use-init-array"[1], fno_use_init_array, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use .ctors/.dtors instead of .init_array/.fini_array", nullptr, nullptr)
OPTION(prefix_1, &"-fno-use-line-directives"[1], fno_use_line_directives, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-use-linker-plugin"[1], fno_use_linker_plugin, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-validate-pch"[1], fno_validate_pch, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable validation of precompiled headers", nullptr, nullptr)
OPTION(prefix_1, &"-fno-var-tracking"[1], fno_var_tracking, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-variable-expansion-in-unroller"[1], fno_variable_expansion_in_unroller, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-vect-cost-model"[1], fno_vect_cost_model, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-vectorize"[1], fno_vectorize, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-verbose-asm"[1], fno_verbose_asm, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-virtual-function-elimination"[1], fno_virtual_function_elimination, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-visibility-from-dllstorageclass"[1], fno_visibility_from_dllstorageclass, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-visibility-inlines-hidden-static-local-var"[1], fno_visibility_inlines_hidden_static_local_var, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disables -fvisibility-inlines-hidden-static-local-var (this is the default on non-darwin targets)", nullptr, nullptr)
OPTION(prefix_1, &"-fno-visibility-inlines-hidden"[1], fno_visibility_inlines_hidden, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-wchar"[1], fno_wchar, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable C++ builtin type wchar_t", nullptr, nullptr)
OPTION(prefix_1, &"-fno-web"[1], fno_web, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-whole-file"[1], fno_whole_file, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-whole-program-vtables"[1], fno_whole_program_vtables, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-whole-program"[1], fno_whole_program, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-working-directory"[1], fno_working_directory, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-wrapv"[1], fno_wrapv, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno-xl-pragma-pack"[1], fno_xl_pragma_pack, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-xor-operator"[1], fno_xor_operator, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-xray-always-emit-customevents"[1], fno_xray_always_emit_customevents, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-xray-always-emit-typedevents"[1], fno_xray_always_emit_typedevents, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-xray-function-index"[1], fno_xray_function_index, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Omit function index section at the expense of single-function patching performance", nullptr, nullptr)
OPTION(prefix_1, &"-fno-xray-ignore-loops"[1], fno_xray_ignore_loops, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-xray-instrument"[1], fno_xray_instrument, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno-zero-initialized-in-bss"[1], fno_zero_initialized_in_bss, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't place zero initialized data in BSS", nullptr, nullptr)
OPTION(prefix_1, &"-fno-zvector"[1], fno_zvector, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fno_modules-validate-input-files-content"[1], fno_modules_validate_input_files_content, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fno_pch-validate-input-files-content"[1], fno_pch_validate_input_files_content, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fnon-call-exceptions"[1], fnon_call_exceptions, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fnoopenmp-relocatable-target"[1], fnoopenmp_relocatable_target, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fnoopenmp-use-tls"[1], fnoopenmp_use_tls, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fnoxray-link-deps"[1], fnoxray_link_deps, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-abi-version="[1], fobjc_abi_version_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-arc-cxxlib="[1], fobjc_arc_cxxlib_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Objective-C++ Automatic Reference Counting standard library kind", nullptr, "libc++,libstdc++,none")
OPTION(prefix_1, &"-fobjc-arc-exceptions"[1], fobjc_arc_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use EH-safe code when synthesizing retains and releases in -fobjc-arc", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-arc"[1], fobjc_arc, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Synthesize retain and release calls for Objective-C pointers", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-atdefs"[1], fobjc_atdefs, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-avoid-heapify-local-blocks"[1], fobjc_avoid_heapify_local_blocks, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Try to avoid heapifying local blocks", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-call-cxx-cdtors"[1], fobjc_call_cxx_cdtors, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-convert-messages-to-runtime-calls"[1], fobjc_convert_messages_to_runtime_calls, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-disable-direct-methods-for-testing"[1], fobjc_disable_direct_methods_for_testing, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Ignore attribute objc_direct so that direct methods can be tested", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-dispatch-method="[1], fobjc_dispatch_method_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Objective-C dispatch method to use", nullptr, "legacy,non-legacy,mixed")
OPTION(prefix_1, &"-fobjc-encode-cxx-class-template-spec"[1], fobjc_encode_cxx_class_template_spec, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Fully encode c++ class template specialization", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-exceptions"[1], fobjc_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable Objective-C exceptions", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-gc-only"[1], fobjc_gc_only, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use GC exclusively for Objective-C related memory management", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-gc"[1], fobjc_gc, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable Objective-C garbage collection", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-infer-related-result-type"[1], fobjc_infer_related_result_type, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-legacy-dispatch"[1], fobjc_legacy_dispatch, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-link-runtime"[1], fobjc_link_runtime, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-new-property"[1], fobjc_new_property, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-nonfragile-abi-version="[1], fobjc_nonfragile_abi_version_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-nonfragile-abi"[1], fobjc_nonfragile_abi, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-runtime-has-weak"[1], fobjc_runtime_has_weak, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The target Objective-C runtime supports ARC weak operations", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-runtime="[1], fobjc_runtime_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Specify the target Objective-C runtime kind and version", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-sender-dependent-dispatch"[1], fobjc_sender_dependent_dispatch, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-subscripting-legacy-runtime"[1], fobjc_subscripting_legacy_runtime, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow Objective-C array and dictionary subscripting in legacy runtime", nullptr, nullptr)
OPTION(prefix_1, &"-fobjc-weak"[1], fobjc_weak, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable ARC-style weak references in Objective-C", nullptr, nullptr)
OPTION(prefix_1, &"-foffload-lto="[1], foffload_lto_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0,
       "Set LTO mode to either 'full' or 'thin' for offload compilation", nullptr, "thin,full")
OPTION(prefix_1, &"-foffload-lto"[1], foffload_lto, Flag, f_Group, foffload_lto_EQ, "full\0", CoreOption, 0,
       "Enable LTO in 'full' mode for offload compilation", nullptr, nullptr)
OPTION(prefix_1, &"-fomit-frame-pointer"[1], fomit_frame_pointer, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenacc"[1], fopenacc, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Enable OpenACC", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-assume-teams-oversubscription"[1], fopenmp_assume_teams_oversubscription, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-assume-threads-oversubscription"[1], fopenmp_assume_threads_oversubscription, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-cuda-blocks-per-sm="[1], fopenmp_cuda_blocks_per_sm_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-cuda-force-full-runtime"[1], fopenmp_cuda_force_full_runtime, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-cuda-mode"[1], fopenmp_cuda_mode, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-cuda-number-of-sm="[1], fopenmp_cuda_number_of_sm_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-cuda-teams-reduction-recs-num="[1], fopenmp_cuda_teams_reduction_recs_num_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-enable-irbuilder"[1], fopenmp_enable_irbuilder, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0,
       "Use the experimental OpenMP-IR-Builder codegen path.", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-extensions"[1], fopenmp_extensions, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Enable all Clang extensions for OpenMP directives and clauses", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-host-ir-file-path"[1], fopenmp_host_ir_file_path, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Path to the IR file produced by the frontend for the host.", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-is-device"[1], fopenmp_is_device, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate code only for an OpenMP target device.", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-optimistic-collapse"[1], fopenmp_optimistic_collapse, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-relocatable-target"[1], fopenmp_relocatable_target, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-simd"[1], fopenmp_simd, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Emit OpenMP code only for SIMD-based constructs.", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-target-debug="[1], fopenmp_target_debug_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-target-debug"[1], fopenmp_target_debug, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Enable debugging in the OpenMP offloading device RTL", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-target-new-runtime"[1], fopenmp_target_new_runtime, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use the new bitcode library for OpenMP offloading", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-targets="[1], fopenmp_targets_EQ, CommaJoined, INVALID, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify comma-separated list of triples OpenMP offloading targets to be supported", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-use-tls"[1], fopenmp_use_tls, Flag, f_Group, INVALID, nullptr, NoArgumentUnused | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp-version="[1], fopenmp_version_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Set OpenMP version (e.g. 45 for OpenMP 4.5, 50 for OpenMP 5.0). Default value is 50.", nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp="[1], fopenmp_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fopenmp"[1], fopenmp, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | FlangOption | FC1Option, 0,
       "Parse OpenMP pragmas and generate parallel code.", nullptr, nullptr)
OPTION(prefix_1, &"-foperator-arrow-depth="[1], foperator_arrow_depth_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-foperator-arrow-depth"[1], foperator_arrow_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum number of 'operator->'s to call for a member access", nullptr, nullptr)
OPTION(prefix_1, &"-foperator-names"[1], foperator_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-foptimization-record-file="[1], foptimization_record_file_EQ, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Specify the output name of the file containing the optimization remarks. Implies -fsave-optimization-record. On Darwin platforms, this cannot be used with multiple -arch <arch> options.", "<file>", nullptr)
OPTION(prefix_1, &"-foptimization-record-passes="[1], foptimization_record_passes_EQ, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Only include passes which match a specified regular expression in the generated optimization record (by default, include all passes)", "<regex>", nullptr)
OPTION(prefix_1, &"-foptimize-sibling-calls"[1], foptimize_sibling_calls, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--for-linker="[2], _for_linker_EQ, Joined, INVALID, Xlinker, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--for-linker"[2], _for_linker, Separate, INVALID, Xlinker, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--force-link="[2], _force_link_EQ, Joined, INVALID, u, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--force-link"[2], _force_link, Separate, INVALID, u, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-force_cpusubtype_ALL"[1], force__cpusubtype__ALL, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-force_flat_namespace"[1], force__flat__namespace, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-force_load"[1], force__load, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-forder-file-instrumentation"[1], forder_file_instrumentation, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Generate instrumented code to collect order file into default.profraw file (overridden by '=' form of option or LLVM_PROFILE_FILE env var)", nullptr, nullptr)
OPTION(prefix_1, &"-foutput-class-dir="[1], foutput_class_dir_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-foverride-record-layout="[1], foverride_record_layout_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Override record layouts with those in the given file", nullptr, nullptr)
OPTION(prefix_2, &"/Fo"[1], _SLASH_Fo, Joined, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Set output object file (with /c)", "<file or dir/>", nullptr)
OPTION(prefix_2, &"/fp:except-"[1], _SLASH_fp_except_, Flag, cl_Group, fno_trapping_math, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_2, &"/fp:except"[1], _SLASH_fp_except, Flag, cl_Group, ftrapping_math, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_2, &"/fp:fast"[1], _SLASH_fp_fast, Flag, cl_Group, ffast_math, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_2, &"/fp:precise"[1], _SLASH_fp_precise, Flag, cl_Group, fno_fast_math, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_2, &"/fp:strict"[1], _SLASH_fp_strict, Flag, cl_Group, fno_fast_math, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fpack-derived"[1], fpack_derived, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpack-struct="[1], fpack_struct_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the default maximum struct packing alignment", nullptr, nullptr)
OPTION(prefix_1, &"-fpack-struct"[1], fpack_struct, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpadding-on-unsigned-fixed-point"[1], fpadding_on_unsigned_fixed_point, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Force each unsigned fixed point type to have an extra bit of padding to align their scales with those of signed fixed point types", nullptr, nullptr)
OPTION(prefix_1, &"-fparse-all-comments"[1], fparse_all_comments, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpascal-strings"[1], fpascal_strings, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Recognize and construct Pascal-style string literals", nullptr, nullptr)
OPTION(prefix_1, &"-fpass-by-value-is-noalias"[1], fpass_by_value_is_noalias, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allows assuming by-value parameters do not alias any other value. Has no effect on non-trivially-copyable classes in C++.", nullptr, nullptr)
OPTION(prefix_1, &"-fpass-plugin="[1], fpass_plugin_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Load pass plugin from a dynamic shared object file (only with new pass manager).", "<dsopath>", nullptr)
OPTION(prefix_1, &"-fpatchable-function-entry-offset="[1], fpatchable_function_entry_offset_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate M NOPs before function entry", "<M>", nullptr)
OPTION(prefix_1, &"-fpatchable-function-entry="[1], fpatchable_function_entry_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate M NOPs before function entry and N-M NOPs after function entry", "<N,M>", nullptr)
OPTION(prefix_1, &"-fpcc-struct-return"[1], fpcc_struct_return, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Override the default ABI to return all structs on the stack", nullptr, nullptr)
OPTION(prefix_1, &"-fpch-codegen"[1], fpch_codegen, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate code for uses of this PCH that assumes an explicit object file will be built for the PCH", nullptr, nullptr)
OPTION(prefix_1, &"-fpch-debuginfo"[1], fpch_debuginfo, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate debug info for types in an object file built from this PCH and do not generate them elsewhere", nullptr, nullptr)
OPTION(prefix_1, &"-fpch-instantiate-templates"[1], fpch_instantiate_templates, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Instantiate templates already while building a PCH", nullptr, nullptr)
OPTION(prefix_1, &"-fpch-preprocess"[1], fpch_preprocess, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpch-validate-input-files-content"[1], fpch_validate_input_files_content, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Validate PCH input files based on content if mtime differs", nullptr, nullptr)
OPTION(prefix_1, &"-fpeel-loops"[1], fpeel_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpermissive"[1], fpermissive, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fPIC"[1], fPIC, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpic"[1], fpic, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fPIE"[1], fPIE, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpie"[1], fpie, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fplt"[1], fplt, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fplugin-arg-"[1], fplugin_arg, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Pass <arg> to plugin <name>", "<name>-<arg>", nullptr)
OPTION(prefix_1, &"-fplugin="[1], fplugin_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Load the named plugin (dynamic shared object)", "<dsopath>", nullptr)
OPTION(prefix_1, &"-fprebuilt-implicit-modules"[1], fprebuilt_implicit_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Look up implicit modules in the prebuilt module path", nullptr, nullptr)
OPTION(prefix_1, &"-fprebuilt-module-path="[1], fprebuilt_module_path, Joined, i_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the prebuilt module path", "<directory>", nullptr)
OPTION(prefix_1, &"-fprefetch-loop-arrays"[1], fprefetch_loop_arrays, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fpreserve-as-comments"[1], fpreserve_as_comments, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fpreserve-vec3-type"[1], fpreserve_vec3_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve 3-component vector type", nullptr, nullptr)
OPTION(prefix_1, &"-fprintf"[1], fprintf, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fproc-stat-report="[1], fproc_stat_report_EQ, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Save subprocess statistics to the given file", nullptr, nullptr)
OPTION(prefix_1, &"-fproc-stat-report"[1], fproc_stat_report, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Print subprocess statistics", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-arcs"[1], fprofile_arcs, Flag, f_Group, INVALID, nullptr, CC1Option | LinkOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-correction"[1], fprofile_correction, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-dir="[1], fprofile_dir, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-exclude-files="[1], fprofile_exclude_files_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Instrument only functions from files where names don't match all the regexes separated by a semi-colon", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-filter-files="[1], fprofile_filter_files_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Instrument only functions from files where names match any regex separated by a semi-colon", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-generate-sampling"[1], fprofile_generate_sampling, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-generate="[1], fprofile_generate_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0,
       "Generate instrumented code to collect execution counts into <directory>/default.profraw (overridden by LLVM_PROFILE_FILE env var)", "<directory>", nullptr)
OPTION(prefix_1, &"-fprofile-generate"[1], fprofile_generate, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Generate instrumented code to collect execution counts into default.profraw (overridden by LLVM_PROFILE_FILE env var)", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-instr-generate="[1], fprofile_instr_generate_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0,
       "Generate instrumented code to collect execution counts into <file> (overridden by LLVM_PROFILE_FILE env var)", "<file>", nullptr)
OPTION(prefix_1, &"-fprofile-instr-generate"[1], fprofile_instr_generate, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Generate instrumented code to collect execution counts into default.profraw file (overridden by '=' form of option or LLVM_PROFILE_FILE env var)", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-instr-use="[1], fprofile_instr_use_EQ, Joined, f_Group, INVALID, nullptr, CoreOption, 0,
       "Use instrumentation data for profile-guided optimization", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-instr-use"[1], fprofile_instr_use, Flag, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-instrument-path="[1], fprofile_instrument_path_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate instrumented code to collect execution counts into <file> (overridden by LLVM_PROFILE_FILE env var)", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-instrument-use-path="[1], fprofile_instrument_use_path_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Specify the profile path in PGO use compilation", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-instrument="[1], fprofile_instrument_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable PGO instrumentation. The accepted value is clang, llvm, or none", nullptr, "none,clang,llvm,csllvm")
OPTION(prefix_1, &"-fprofile-list="[1], fprofile_list_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Filename defining the list of functions/files to instrument", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-remapping-file="[1], fprofile_remapping_file_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Use the remappings described in <file> to match the profile data against names in the program", "<file>", nullptr)
OPTION(prefix_1, &"-fprofile-reusedist"[1], fprofile_reusedist, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-sample-accurate"[1], fprofile_sample_accurate, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specifies that the sample profile is accurate", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-sample-use="[1], fprofile_sample_use_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Enable sample-based profile guided optimizations", nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-sample-use"[1], fprofile_sample_use, Flag, f_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-update="[1], fprofile_update_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Set update method of profile counters (atomic,prefer-atomic,single)", "<method>", "atomic,prefer-atomic,single")
OPTION(prefix_1, &"-fprofile-use="[1], fprofile_use_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Use instrumentation data for profile-guided optimization. If pathname is a directory, it reads from <pathname>/default.profdata. Otherwise, it reads from file <pathname>.", "<pathname>", nullptr)
OPTION(prefix_1, &"-fprofile-use"[1], fprofile_use, Flag, f_Group, fprofile_instr_use, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile-values"[1], fprofile_values, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprofile"[1], fprofile, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fprotect-parens"[1], fprotect_parens, Flag, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Determines whether the optimizer honors parentheses when floating-point expressions are evaluated", nullptr, nullptr)
OPTION(prefix_1, &"-fpseudo-probe-for-profiling"[1], fpseudo_probe_for_profiling, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Emit pseudo probes for sample profiling", nullptr, nullptr)
OPTION(prefix_2, &"/Fp"[1], _SLASH_Fp, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set pch file name (with /Yc and /Yu)", "<file>", nullptr)
OPTION(prefix_1, &"-framework"[1], framework, Separate, INVALID, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frandom-seed="[1], frandom_seed_EQ, Joined, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frange-check"[1], frange_check, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freal-4-real-10"[1], freal_4_real_10, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freal-4-real-16"[1], freal_4_real_16, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freal-4-real-8"[1], freal_4_real_8, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freal-8-real-10"[1], freal_8_real_10, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freal-8-real-16"[1], freal_8_real_16, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freal-8-real-4"[1], freal_8_real_4, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frealloc-lhs"[1], frealloc_lhs, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freciprocal-math"[1], freciprocal_math, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow division operations to be reassociated", nullptr, nullptr)
OPTION(prefix_1, &"-frecord-command-line"[1], frecord_command_line, Flag, f_clang_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frecord-gcc-switches"[1], anonymous_252, Flag, INVALID, frecord_command_line, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frecord-marker="[1], frecord_marker_EQ, Joined, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frecovery-ast-type"[1], frecovery_ast_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve the type for recovery expressions when possible", nullptr, nullptr)
OPTION(prefix_1, &"-frecovery-ast"[1], frecovery_ast, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve expressions in AST rather than dropping them when encountering semantic errors", nullptr, nullptr)
OPTION(prefix_1, &"-frecursive"[1], frecursive, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freg-struct-return"[1], freg_struct_return, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Override the default ABI to return small structs in registers", nullptr, nullptr)
OPTION(prefix_1, &"-fregister-global-dtors-with-atexit"[1], fregister_global_dtors_with_atexit, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use atexit or __cxa_atexit to register global destructors", nullptr, nullptr)
OPTION(prefix_1, &"-fregs-graph"[1], fregs_graph, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frelaxed-template-template-args"[1], frelaxed_template_template_args, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++17 relaxed template template argument matching", nullptr, nullptr)
OPTION(prefix_1, &"-frename-registers"[1], frename_registers, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freorder-blocks"[1], freorder_blocks, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frepack-arrays"[1], frepack_arrays, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-freroll-loops"[1], freroll_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Turn on loop reroller", nullptr, nullptr)
OPTION(prefix_1, &"-fretain-comments-from-system-headers"[1], fretain_comments_from_system_headers, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frewrite-imports"[1], frewrite_imports, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-frewrite-includes"[1], frewrite_includes, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-frewrite-map-file="[1], frewrite_map_file_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fripa"[1], fripa, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fropi"[1], fropi, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate read-only position independent code (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-frounding-math"[1], frounding_math, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-frtlib-add-rpath"[1], frtlib_add_rpath, Flag, INVALID, INVALID, nullptr, NoArgumentUnused, 0,
       "Add -rpath with architecture-specific resource directory to the linker flags", nullptr, nullptr)
OPTION(prefix_1, &"-frtti-data"[1], frtti_data, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-frtti"[1], frtti, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-frwpi"[1], frwpi, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate read-write position independent code (ARM only)", nullptr, nullptr)
OPTION(prefix_2, &"/FR"[1], _SLASH_FR, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Fr"[1], _SLASH_Fr, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-address-destructor="[1], sanitize_address_destructor_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Set destructor type used in ASan instrumentation", nullptr, "none,global")
OPTION(prefix_1, &"-fsanitize-address-field-padding="[1], fsanitize_address_field_padding, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Level of field padding for AddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-address-globals-dead-stripping"[1], fsanitize_address_globals_dead_stripping, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable linker dead stripping of globals in AddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-address-outline-instrumentation"[1], fsanitize_address_outline_instrumentation, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Always generate function calls for address sanitizer instrumentation", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-address-poison-custom-array-cookie"[1], fsanitize_address_poison_custom_array_cookie, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable poisoning array cookies when using custom operator new[] in AddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-address-use-after-return="[1], sanitize_address_use_after_return_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Select the mode of detecting stack use-after-return in AddressSanitizer: never | runtime (default) | always", "<mode>", "never,runtime,always")
OPTION(prefix_2, &"/fsanitize-address-use-after-return"[1], _SLASH_fsanitize_address_use_after_return, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-address-use-after-scope"[1], fsanitize_address_use_after_scope, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable use-after-scope detection in AddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-address-use-odr-indicator"[1], fsanitize_address_use_odr_indicator, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable ODR indicator globals to avoid false ODR violation reports in partially sanitized programs at the cost of an increase in binary size", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-blacklist="[1], anonymous_427, Joined, f_clang_Group, fsanitize_ignorelist_EQ, nullptr, CC1Option | CoreOption, 0,
       "Alias for -fsanitize-ignorelist=", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-cfi-canonical-jump-tables"[1], fsanitize_cfi_canonical_jump_tables, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Make the jump table addresses canonical in the symbol table", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-cfi-cross-dso"[1], fsanitize_cfi_cross_dso, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable control flow integrity (CFI) checks for cross-DSO calls.", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-cfi-icall-generalize-pointers"[1], fsanitize_cfi_icall_generalize_pointers, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Generalize pointers in CFI indirect call type signature checks", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-8bit-counters"[1], fsanitize_coverage_8bit_counters, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable frequency counters in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-allowlist="[1], fsanitize_coverage_allowlist, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Restrict sanitizer coverage instrumentation exclusively to modules and functions that match the provided special case list, except the blocked ones", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-blacklist="[1], anonymous_433, Joined, f_clang_Group, fsanitize_coverage_ignorelist, nullptr, CC1Option | CoreOption, 0,
       "Deprecated, use -fsanitize-coverage-ignorelist= instead", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-ignorelist="[1], fsanitize_coverage_ignorelist, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable sanitizer coverage instrumentation for modules and functions that match the provided special case list, even the allowed ones", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-indirect-calls"[1], fsanitize_coverage_indirect_calls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable sanitizer coverage for indirect calls", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-inline-8bit-counters"[1], fsanitize_coverage_inline_8bit_counters, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable inline 8-bit counters in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-inline-bool-flag"[1], fsanitize_coverage_inline_bool_flag, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable inline bool flag in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-no-prune"[1], fsanitize_coverage_no_prune, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable coverage pruning (i.e. instrument all blocks/edges)", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-pc-table"[1], fsanitize_coverage_pc_table, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Create a table of coverage-instrumented PCs", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-stack-depth"[1], fsanitize_coverage_stack_depth, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable max stack depth tracing", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-bb"[1], fsanitize_coverage_trace_bb, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable basic block tracing in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-cmp"[1], fsanitize_coverage_trace_cmp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable cmp instruction tracing in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-div"[1], fsanitize_coverage_trace_div, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable div instruction tracing in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-gep"[1], fsanitize_coverage_trace_gep, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable gep instruction tracing in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-loads"[1], fsanitize_coverage_trace_loads, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable tracing of loads", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-pc-guard"[1], fsanitize_coverage_trace_pc_guard, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable PC tracing with guard in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-pc"[1], fsanitize_coverage_trace_pc, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable PC tracing in sanitizer coverage", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-trace-stores"[1], fsanitize_coverage_trace_stores, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable tracing of stores", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-type="[1], fsanitize_coverage_type, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Sanitizer coverage type", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage-whitelist="[1], anonymous_431, Joined, f_clang_Group, fsanitize_coverage_allowlist, nullptr, CC1Option | CoreOption, 0,
       "Deprecated, use -fsanitize-coverage-allowlist= instead", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-coverage="[1], fsanitize_coverage, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Specify the type of coverage instrumentation for Sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-hwaddress-abi="[1], fsanitize_hwaddress_abi_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Select the HWAddressSanitizer ABI to target (interceptor or platform, default interceptor). This option is currently unused.", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-hwaddress-experimental-aliasing"[1], fsanitize_hwaddress_experimental_aliasing, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable aliasing mode in HWAddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-ignorelist="[1], fsanitize_ignorelist_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Path to ignorelist file for sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-link-c++-runtime"[1], fsanitize_link_cxx_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-link-runtime"[1], fsanitize_link_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-memory-track-origins="[1], fsanitize_memory_track_origins_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable origins tracking in MemorySanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-memory-track-origins"[1], fsanitize_memory_track_origins, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable origins tracking in MemorySanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-memory-use-after-dtor"[1], fsanitize_memory_use_after_dtor, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable use-after-destroy detection in MemorySanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-minimal-runtime"[1], fsanitize_minimal_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-recover="[1], fsanitize_recover_EQ, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable recovery for specified sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-recover"[1], fsanitize_recover, Flag, f_clang_Group, fsanitize_recover_EQ, "all\0", CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-stats"[1], fsanitize_stats, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable sanitizer statistics gathering.", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-system-blacklist="[1], anonymous_428, Joined, INVALID, fsanitize_system_ignorelist_EQ, nullptr, CC1Option | CoreOption, 0,
       "Alias for -fsanitize-system-ignorelist=", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-system-ignorelist="[1], fsanitize_system_ignorelist_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Path to system ignorelist file for sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-thread-atomics"[1], fsanitize_thread_atomics, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable atomic operations instrumentation in ThreadSanitizer (default)", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-thread-func-entry-exit"[1], fsanitize_thread_func_entry_exit, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable function entry/exit instrumentation in ThreadSanitizer (default)", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-thread-memory-access"[1], fsanitize_thread_memory_access, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable memory access instrumentation in ThreadSanitizer (default)", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-trap="[1], fsanitize_trap_EQ, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable trapping for specified sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-trap"[1], fsanitize_trap, Flag, f_clang_Group, fsanitize_trap_EQ, "all\0", CC1Option | CoreOption, 0,
       "Enable trapping for all sanitizers", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize-undefined-strip-path-components="[1], fsanitize_undefined_strip_path_components_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Strip (or keep only, if negative) a given number of path components when emitting check metadata.", "<number>", nullptr)
OPTION(prefix_1, &"-fsanitize-undefined-trap-on-error"[1], fsanitize_undefined_trap_on_error, Flag, f_clang_Group, fsanitize_trap_EQ, "undefined\0", CC1Option | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/fsanitize=address"[1], _SLASH_fsanitize_EQ_address, Flag, cl_Group, fsanitize_EQ, "address\0", CLOption | NoXarchOption | CLOption, 0,
       "Enable AddressSanitizer", nullptr, nullptr)
OPTION(prefix_1, &"-fsanitize="[1], fsanitize_EQ, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Turn on runtime checks for various forms of undefined or suspicious behavior. See user manual for available checks", "<check>", nullptr)
OPTION(prefix_1, &"-fsave-optimization-record="[1], fsave_optimization_record_EQ, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Generate an optimization record file in a specific format", "<format>", nullptr)
OPTION(prefix_1, &"-fsave-optimization-record"[1], fsave_optimization_record, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Generate a YAML optimization record file", nullptr, nullptr)
OPTION(prefix_1, &"-fsched-interblock"[1], anonymous_930, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fschedule-insns2"[1], fschedule_insns2, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fschedule-insns"[1], fschedule_insns, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsecond-underscore"[1], fsecond_underscore, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsee"[1], fsee, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fseh-exceptions"[1], fseh_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Use SEH style exceptions", nullptr, nullptr)
OPTION(prefix_1, &"-fsemantic-interposition"[1], fsemantic_interposition, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fshort-enums"[1], fshort_enums, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allocate to an enum type only as many bytes as it needs for the declared range of possible values", nullptr, nullptr)
OPTION(prefix_1, &"-fshort-wchar"[1], fshort_wchar, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Force wchar_t to be a short unsigned int", nullptr, nullptr)
OPTION(prefix_1, &"-fshow-column"[1], fshow_column, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fshow-overloads="[1], fshow_overloads_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Which overload candidates to show when overload resolution fails: best|all; defaults to all", nullptr, "best,all")
OPTION(prefix_1, &"-fshow-skipped-includes"[1], fshow_skipped_includes, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Show skipped includes in -H output.", nullptr, nullptr)
OPTION(prefix_1, &"-fshow-source-location"[1], fshow_source_location, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fsign-zero"[1], fsign_zero, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsignaling-math"[1], fsignaling_math, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsignaling-nans"[1], fsignaling_nans, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsigned-bitfields"[1], fsigned_bitfields, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsigned-char"[1], fsigned_char, Flag, f_Group, INVALID, nullptr, 0, 0,
       "char is signed", nullptr, nullptr)
OPTION(prefix_1, &"-fsigned-wchar"[1], fsigned_wchar, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use a signed type for wchar_t", nullptr, nullptr)
OPTION(prefix_1, &"-fsigned-zeros"[1], fsigned_zeros, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fsingle-precision-constant"[1], fsingle_precision_constant, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsized-deallocation"[1], fsized_deallocation, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++14 sized global deallocation functions", nullptr, nullptr)
OPTION(prefix_1, &"-fsjlj-exceptions"[1], fsjlj_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Use SjLj style exceptions", nullptr, nullptr)
OPTION(prefix_1, &"-fslp-vectorize-aggressive"[1], anonymous_0, Flag, clang_ignored_legacy_options_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fslp-vectorize"[1], fslp_vectorize, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable the superword-level parallelism vectorization passes", nullptr, nullptr)
OPTION(prefix_1, &"-fspec-constr-count"[1], fspec_constr_count, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fspell-checking-limit="[1], fspell_checking_limit_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fspell-checking-limit"[1], fspell_checking_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of times to perform spell checking on unrecognized identifiers (0 = no limit).", "<N>", nullptr)
OPTION(prefix_1, &"-fspell-checking"[1], fspell_checking, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fsplit-dwarf-inlining"[1], fsplit_dwarf_inlining, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Provide minimal debug info in the object/executable to facilitate online symbolication/stack traces in the absence of .dwo/.dwp files when using Split DWARF", nullptr, nullptr)
OPTION(prefix_1, &"-fsplit-lto-unit"[1], fsplit_lto_unit, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enables splitting of the LTO unit", nullptr, nullptr)
OPTION(prefix_1, &"-fsplit-machine-functions"[1], fsplit_machine_functions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable late function splitting using profile information (x86 ELF)", nullptr, nullptr)
OPTION(prefix_1, &"-fsplit-stack"[1], fsplit_stack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use segmented stack", nullptr, nullptr)
OPTION(prefix_1, &"-fstack-arrays"[1], fstack_arrays, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fstack-check"[1], fstack_check, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fstack-clash-protection"[1], fstack_clash_protection, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable stack clash protection", nullptr, nullptr)
OPTION(prefix_1, &"-fstack-protector-all"[1], fstack_protector_all, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable stack protectors for all functions", nullptr, nullptr)
OPTION(prefix_1, &"-fstack-protector-strong"[1], fstack_protector_strong, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable stack protectors for some functions vulnerable to stack smashing. Compared to -fstack-protector, this uses a stronger heuristic that includes functions containing arrays of any size (and any type), as well as any calls to alloca or the taking of an address from a local variable", nullptr, nullptr)
OPTION(prefix_1, &"-fstack-protector"[1], fstack_protector, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable stack protectors for some functions vulnerable to stack smashing. This uses a loose heuristic which considers functions vulnerable if they contain a char (or 8bit integer) array or constant sized calls to alloca , which are of greater size than ssp-buffer-size (default: 8 bytes). All variable sized calls to alloca are considered vulnerable. A function with a stack protector has a guard value added to the stack frame that is checked on function exit. The guard value must be positioned in the stack frame such that a buffer overflow from a vulnerable variable will overwrite the guard value before overwriting the function's return address. The reference stack guard value is stored in a global variable.", nullptr, nullptr)
OPTION(prefix_1, &"-fstack-size-section"[1], fstack_size_section, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Emit section containing metadata on function stack sizes", nullptr, nullptr)
OPTION(prefix_1, &"-fstack-usage"[1], fstack_usage, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Emit .su file containing information on function stack sizes", nullptr, nullptr)
OPTION(prefix_1, &"-fstandalone-debug"[1], fstandalone_debug, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Emit full debug info for all types used by the program", nullptr, nullptr)
OPTION(prefix_1, &"-fstrength-reduce"[1], fstrength_reduce, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fstrict-aliasing"[1], fstrict_aliasing, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fstrict-enums"[1], fstrict_enums, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable optimizations based on the strict definition of an enum's value range", nullptr, nullptr)
OPTION(prefix_1, &"-fstrict-float-cast-overflow"[1], fstrict_float_cast_overflow, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Assume that overflowing float-to-int casts are undefined (default)", nullptr, nullptr)
OPTION(prefix_1, &"-fstrict-overflow"[1], fstrict_overflow, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fstrict-return"[1], fstrict_return, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fstrict-vtable-pointers"[1], fstrict_vtable_pointers, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable optimizations based on the strict rules for overwriting polymorphic C++ objects", nullptr, nullptr)
OPTION(prefix_1, &"-fstruct-path-tbaa"[1], fstruct_path_tbaa, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fswift-async-fp="[1], fswift_async_fp_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Control emission of Swift async extended frame info (option: auto, always, never)", "<option>", "auto,always,never")
OPTION(prefix_1, &"-fsycl-is-device"[1], fsycl_is_device, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate code for SYCL device.", nullptr, nullptr)
OPTION(prefix_1, &"-fsycl-is-host"[1], fsycl_is_host, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "SYCL host compilation", nullptr, nullptr)
OPTION(prefix_1, &"-fsycl"[1], fsycl, Flag, sycl_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Enables SYCL kernels compilation for device", nullptr, nullptr)
OPTION(prefix_1, &"-fsymbol-partition="[1], fsymbol_partition_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsyntax-only"[1], fsyntax_only, Flag, Action_Group, INVALID, nullptr, NoXarchOption | CoreOption | CC1Option | FC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fsystem-module"[1], fsystem_module, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Build this module as a system module. Only used with -emit-module", nullptr, nullptr)
OPTION(prefix_2, &"/FS"[1], _SLASH_FS, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftabstop="[1], ftabstop_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftabstop"[1], ftabstop, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the tab stop distance.", "<N>", nullptr)
OPTION(prefix_1, &"-ftemplate-backtrace-limit="[1], ftemplate_backtrace_limit_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftemplate-backtrace-limit"[1], ftemplate_backtrace_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of entries to print in a template instantiation backtrace (0 = no limit).", "<N>", nullptr)
OPTION(prefix_1, &"-ftemplate-depth-"[1], ftemplate_depth_, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftemplate-depth="[1], ftemplate_depth_EQ, Joined, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftemplate-depth"[1], ftemplate_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum depth of recursive template instantiation", nullptr, nullptr)
OPTION(prefix_1, &"-fterminated-vtables"[1], anonymous_1004, Flag, INVALID, fapple_kext, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftest-coverage"[1], ftest_coverage, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-ftest-module-file-extension="[1], ftest_module_file_extension_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "introduce a module file extension for testing purposes. The argument is parsed as blockname:major:minor:hashed:user info", nullptr, nullptr)
OPTION(prefix_1, &"-fthin-link-bitcode="[1], fthin_link_bitcode_EQ, Joined, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Write minimized bitcode to <file> for the ThinLTO thin link only", nullptr, nullptr)
OPTION(prefix_1, &"-fthinlto-index="[1], fthinlto_index_EQ, Joined, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Perform ThinLTO importing using provided function summary index", nullptr, nullptr)
OPTION(prefix_1, &"-fthreadsafe-statics"[1], fthreadsafe_statics, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-ftime-report="[1], ftime_report_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "(For new pass manager) \"per-pass\": one report for each pass; \"per-pass-run\": one report for each pass invocation", nullptr, "per-pass,per-pass-run")
OPTION(prefix_1, &"-ftime-report"[1], ftime_report, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftime-trace-granularity="[1], ftime_trace_granularity_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Minimum time granularity (in microseconds) traced by time profiler", nullptr, nullptr)
OPTION(prefix_1, &"-ftime-trace"[1], ftime_trace, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Turn on time profiler. Generates JSON file based on output filename.", nullptr, nullptr)
OPTION(prefix_1, &"-ftls-model="[1], ftlsmodel_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "global-dynamic,local-dynamic,initial-exec,local-exec")
OPTION(prefix_1, &"-ftls-model"[1], ftls_model, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftracer"[1], ftracer, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftrap-function="[1], ftrap_function_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Issue call to specified function rather than a trap instruction", nullptr, nullptr)
OPTION(prefix_1, &"-ftrapping-math"[1], ftrapping_math, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftrapv-handler="[1], ftrapv_handler_EQ, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Specify the function to be called on overflow", "<function name>", nullptr)
OPTION(prefix_1, &"-ftrapv-handler"[1], ftrapv_handler, Separate, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftrapv"[1], ftrapv, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Trap on integer overflow", nullptr, nullptr)
OPTION(prefix_1, &"-ftree-dce"[1], ftree_dce, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftree-salias"[1], ftree_salias, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftree-slp-vectorize"[1], anonymous_1001, Flag, INVALID, fslp_vectorize, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftree-ter"[1], ftree_ter, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftree-vectorizer-verbose"[1], ftree_vectorizer_verbose, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftree-vectorize"[1], anonymous_999, Flag, INVALID, fvectorize, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftree-vrp"[1], ftree_vrp, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ftrigraphs"[1], ftrigraphs, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Process trigraph sequences", nullptr, nullptr)
OPTION(prefix_1, &"-ftrivial-auto-var-init-stop-after="[1], ftrivial_auto_var_init_stop_after, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Stop initializing trivial automatic stack variables after the specified number of instances", nullptr, nullptr)
OPTION(prefix_1, &"-ftrivial-auto-var-init="[1], ftrivial_auto_var_init, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Initialize trivial automatic stack variables: uninitialized (default) | pattern", nullptr, "uninitialized,zero,pattern")
OPTION(prefix_1, &"-ftype-visibility"[1], ftype_visibility, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Default type visibility", nullptr, "default,hidden,internal,protected")
OPTION(prefix_1, &"-function-alignment"[1], function_alignment, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "default alignment for functions", nullptr, nullptr)
OPTION(prefix_1, &"-funderscoring"[1], funderscoring, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funique-basic-block-section-names"[1], funique_basic_block_section_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use unique names for basic block sections (ELF Only)", nullptr, nullptr)
OPTION(prefix_1, &"-funique-internal-linkage-names"[1], funique_internal_linkage_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Uniqueify Internal Linkage Symbol Names by appending the MD5 hash of the module path", nullptr, nullptr)
OPTION(prefix_1, &"-funique-section-names"[1], funique_section_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-funit-at-a-time"[1], funit_at_a_time, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funknown-anytype"[1], funknown_anytype, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable parser support for the __unknown_anytype type; for testing purposes only", nullptr, nullptr)
OPTION(prefix_1, &"-funroll-all-loops"[1], funroll_all_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funroll-loops"[1], funroll_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Turn on loop unroller", nullptr, nullptr)
OPTION(prefix_1, &"-funsafe-loop-optimizations"[1], funsafe_loop_optimizations, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funsafe-math-optimizations"[1], funsafe_math_optimizations, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funsigned-bitfields"[1], funsigned_bitfields, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funsigned-char"[1], funsigned_char, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funswitch-loops"[1], funswitch_loops, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-funwind-tables="[1], funwind_tables_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate unwinding tables for all functions", nullptr, nullptr)
OPTION(prefix_1, &"-funwind-tables"[1], funwind_tables, Flag, f_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fuse-ctor-homing"[1], fuse_ctor_homing, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Use constructor homing if we are using limited debug info already", nullptr, nullptr)
OPTION(prefix_1, &"-fuse-cuid="[1], fuse_cuid_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Method to generate ID's for compilation units for single source offloading languages CUDA and HIP: 'hash' (ID's generated by hashing file path and command line options) | 'random' (ID's generated as random numbers) | 'none' (disabled). Default is 'hash'. This option will be overridden by option '-cuid=[ID]' if it is specified.", nullptr, nullptr)
OPTION(prefix_1, &"-fuse-cxa-atexit"[1], fuse_cxa_atexit, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fuse-init-array"[1], fuse_init_array, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fuse-ld="[1], fuse_ld_EQ, Joined, f_Group, INVALID, nullptr, CoreOption | LinkOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fuse-line-directives"[1], fuse_line_directives, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use #line in preprocessed output", nullptr, nullptr)
OPTION(prefix_1, &"-fuse-linker-plugin"[1], fuse_linker_plugin, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fuse-register-sized-bitfield-access"[1], fuse_register_sized_bitfield_access, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use register sized accesses to bit-fields, when possible.", nullptr, nullptr)
OPTION(prefix_2, &"/FU"[1], _SLASH_FU, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fvalidate-ast-input-files-content"[1], fvalidate_ast_input_files_content, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Compute and store the hash of input files used to build an AST. Files with mismatching mtime's are considered valid if both contents is identical", nullptr, nullptr)
OPTION(prefix_1, &"-fvariable-expansion-in-unroller"[1], fvariable_expansion_in_unroller, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fveclib="[1], fveclib, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given vector functions library", nullptr, "Accelerate,libmvec,MASSV,SVML,Darwin_libsystem_m,none")
OPTION(prefix_1, &"-fvect-cost-model"[1], fvect_cost_model, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fvectorize"[1], fvectorize, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable the loop vectorization passes", nullptr, nullptr)
OPTION(prefix_1, &"-fverbose-asm"[1], fverbose_asm, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Generate verbose assembly output", nullptr, nullptr)
OPTION(prefix_1, &"-fverify-debuginfo-preserve-export="[1], fverify_debuginfo_preserve_export, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Export debug info (by testing original Debug Info) failures into specified (JSON) file (should be abs path as we use append mode to insert new JSON objects).", "<file>", nullptr)
OPTION(prefix_1, &"-fverify-debuginfo-preserve"[1], fverify_debuginfo_preserve, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable Debug Info Metadata preservation testing in optimizations.", nullptr, nullptr)
OPTION(prefix_1, &"-fvirtual-function-elimination"[1], fvirtual_function_elimination, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enables dead virtual function elimination optimization. Requires -flto=full", nullptr, nullptr)
OPTION(prefix_1, &"-fvisibility-dllexport="[1], fvisibility_dllexport_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for dllexport definitions [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected")
OPTION(prefix_1, &"-fvisibility-externs-dllimport="[1], fvisibility_externs_dllimport_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for dllimport external declarations [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected")
OPTION(prefix_1, &"-fvisibility-externs-nodllstorageclass="[1], fvisibility_externs_nodllstorageclass_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for external declarations without an explicit DLL dllstorageclass [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected")
OPTION(prefix_1, &"-fvisibility-from-dllstorageclass"[1], fvisibility_from_dllstorageclass, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Set the visibility of symbols in the generated code from their DLL storage class", nullptr, nullptr)
OPTION(prefix_1, &"-fvisibility-global-new-delete-hidden"[1], fvisibility_global_new_delete_hidden, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Give global C++ operator new and delete declarations hidden visibility", nullptr, nullptr)
OPTION(prefix_1, &"-fvisibility-inlines-hidden-static-local-var"[1], fvisibility_inlines_hidden_static_local_var, Flag, f_Group, INVALID, nullptr, CC1Option | CC1Option, 0,
       "When -fvisibility-inlines-hidden is enabled, static variables in inline C++ member functions will also be given hidden visibility by default", nullptr, nullptr)
OPTION(prefix_1, &"-fvisibility-inlines-hidden"[1], fvisibility_inlines_hidden, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Give inline C++ member functions hidden visibility by default", nullptr, nullptr)
OPTION(prefix_1, &"-fvisibility-ms-compat"[1], fvisibility_ms_compat, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Give global types 'default' visibility and global functions and variables 'hidden' visibility by default", nullptr, nullptr)
OPTION(prefix_1, &"-fvisibility-nodllstorageclass="[1], fvisibility_nodllstorageclass_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for defintiions without an explicit DLL export class [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected")
OPTION(prefix_1, &"-fvisibility="[1], fvisibility_EQ, Joined, f_Group, INVALID, nullptr, 0, 0,
       "Set the default symbol visibility for all global declarations", nullptr, "hidden,default")
OPTION(prefix_1, &"-fvisibility"[1], fvisibility, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Default type and symbol visibility", nullptr, "default,hidden,internal,protected")
OPTION(prefix_1, &"-fwarn-stack-size="[1], fwarn_stack_size_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fwasm-exceptions"[1], fwasm_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Use WebAssembly style exceptions", nullptr, nullptr)
OPTION(prefix_1, &"-fwchar-type="[1], fwchar_type_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Select underlying type for wchar_t", nullptr, "char,short,int")
OPTION(prefix_1, &"-fweb"[1], fweb, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fwhole-file"[1], fwhole_file, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fwhole-program-vtables"[1], fwhole_program_vtables, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enables whole-program vtable optimization. Requires -flto", nullptr, nullptr)
OPTION(prefix_1, &"-fwhole-program"[1], fwhole_program, Flag, clang_ignored_gcc_optimization_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fwrapv"[1], fwrapv, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Treat signed integer overflow as two's complement", nullptr, nullptr)
OPTION(prefix_1, &"-fwritable-strings"[1], fwritable_strings, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Store string literals as writable data", nullptr, nullptr)
OPTION(prefix_1, &"-fxl-pragma-pack"[1], fxl_pragma_pack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable IBM XL #pragma pack handling", nullptr, nullptr)
OPTION(prefix_1, &"-fxor-operator"[1], fxor_operator, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Enable .XOR. as a synonym of .NEQV.", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-always-emit-customevents"[1], fxray_always_emit_customevents, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Always emit __xray_customevent(...) calls even if the containing function is not always instrumented", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-always-emit-typedevents"[1], fxray_always_emit_typedevents, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Always emit __xray_typedevent(...) calls even if the containing function is not always instrumented", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-always-instrument="[1], fxray_always_instrument, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "DEPRECATED: Filename defining the whitelist for imbuing the 'always instrument' XRay attribute.", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-attr-list="[1], fxray_attr_list, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "Filename defining the list of functions/types for imbuing XRay attributes.", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-function-groups="[1], fxray_function_groups, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Only instrument 1 of N groups", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-function-index"[1], fxray_function_index, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-ignore-loops"[1], fxray_ignore_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't instrument functions with loops unless they also meet the minimum function size", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-instruction-threshold="[1], fxray_instruction_threshold_EQ, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "Sets the minimum function size to instrument with XRay", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-instruction-threshold"[1], fxray_instruction_threshold_, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fxray-instrumentation-bundle="[1], fxray_instrumentation_bundle, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "Select which XRay instrumentation points to emit. Options: all, none, function-entry, function-exit, function, custom. Default is 'all'.  'function' includes both 'function-entry' and 'function-exit'.", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-instrument"[1], fxray_instrument, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate XRay instrumentation sleds on function entry and exit", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-link-deps"[1], fxray_link_deps, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Tells clang to add the link dependencies for XRay.", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-modes="[1], fxray_modes, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "List of modes to link in by default into XRay instrumented binaries.", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-never-instrument="[1], fxray_never_instrument, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "DEPRECATED: Filename defining the whitelist for imbuing the 'never instrument' XRay attribute.", nullptr, nullptr)
OPTION(prefix_1, &"-fxray-selected-function-group="[1], fxray_selected_function_group, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "When using -fxray-function-groups, select which group of functions to instrument. Valid range is 0 to fxray-function-groups - 1", nullptr, nullptr)
OPTION(prefix_2, &"/Fx"[1], _SLASH_Fx, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-fzero-initialized-in-bss"[1], fzero_initialized_in_bss, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-fzvector"[1], fzvector, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable System z vector language extension", nullptr, nullptr)
OPTION(prefix_1, &"-F"[1], F, JoinedOrSeparate, INVALID, INVALID, nullptr, RenderJoined | CC1Option, 0,
       "Add directory to framework include search path", nullptr, nullptr)
OPTION(prefix_2, &"/F"[1], _SLASH_F, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-g0"[1], g0, Flag, gN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/G1"[1], _SLASH_G1, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-g1"[1], g1, Flag, gN_Group, gline_tables_only, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/G2"[1], _SLASH_G2, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-g2"[1], g2, Flag, gN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-g3"[1], g3, Flag, gN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-G="[1], G_EQ, Joined, m_Group, G, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GA"[1], _SLASH_GA, Flag, cl_Group, ftlsmodel_EQ, "local-exec\0", CLOption | NoXarchOption | CLOption, 0,
       "Assume thread-local variables are defined in the executable", nullptr, nullptr)
OPTION(prefix_3, &"--gcc-toolchain="[2], gcc_toolchain, Joined, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Search for GCC installation in the specified directory on targets which commonly use GCC. The directory usually contains 'lib{,32,64}/gcc{,-cross}/$triple' and 'include'. If specified, sysroot is skipped for GCC detection. Note: executables (e.g. ld) used by the compiler are not overridden by the selected GCC installation", nullptr, nullptr)
OPTION(prefix_1, &"-gcodeview-ghash"[1], gcodeview_ghash, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Emit type record hashes in a .debug$H section", nullptr, nullptr)
OPTION(prefix_1, &"-gcodeview"[1], gcodeview, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Generate CodeView debug information", nullptr, nullptr)
OPTION(prefix_1, &"-gcoff"[1], gcoff, Joined, g_Group, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gcolumn-info"[1], gcolumn_info, Flag, g_flags_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-gdbx"[1], gdbx, Flag, gTune_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf-2"[1], gdwarf_2, Flag, g_Group, INVALID, nullptr, 0, 0,
       "Generate source-level debug information with dwarf version 2", nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf-3"[1], gdwarf_3, Flag, g_Group, INVALID, nullptr, 0, 0,
       "Generate source-level debug information with dwarf version 3", nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf-4"[1], gdwarf_4, Flag, g_Group, INVALID, nullptr, 0, 0,
       "Generate source-level debug information with dwarf version 4", nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf-5"[1], gdwarf_5, Flag, g_Group, INVALID, nullptr, 0, 0,
       "Generate source-level debug information with dwarf version 5", nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf-aranges"[1], gdwarf_aranges, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf32"[1], gdwarf32, Flag, g_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "Enables DWARF32 format for ELF binaries, if debug information emission is enabled.", nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf64"[1], gdwarf64, Flag, g_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "Enables DWARF64 format for ELF binaries, if debug information emission is enabled.", nullptr, nullptr)
OPTION(prefix_1, &"-gdwarf"[1], gdwarf, Flag, g_Group, INVALID, nullptr, CoreOption, 0,
       "Generate source-level debug information with the default dwarf version", nullptr, nullptr)
OPTION(prefix_2, &"/Gd"[1], _SLASH_Gd, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set __cdecl as a default calling convention", nullptr, nullptr)
OPTION(prefix_1, &"-gembed-source"[1], gembed_source, Flag, g_flags_Group, INVALID, nullptr, CC1Option, 0,
       "Embed source text in DWARF debug sections", nullptr, nullptr)
OPTION(prefix_1, &"-gen-cdb-fragment-path"[1], gen_cdb_fragment_path, Separate, internal_debug_Group, INVALID, nullptr, NoXarchOption | HelpHidden | CoreOption, 0,
       "Emit a compilation database fragment to the specified directory", nullptr, nullptr)
OPTION(prefix_1, &"-gen-reproducer"[1], gen_reproducer, Flag, internal_debug_Group, INVALID, nullptr, NoXarchOption | HelpHidden | CoreOption, 0,
       "Auto-generates preprocessed source files and a reproduction script", nullptr, nullptr)
OPTION(prefix_2, &"/Ge"[1], _SLASH_Ge, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GF-"[1], _SLASH_GF_, Flag, cl_Group, fwritable_strings, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable string pooling", nullptr, nullptr)
OPTION(prefix_1, &"-gfull"[1], gfull, Flag, g_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GF"[1], _SLASH_GF, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Enable string pooling (default)", nullptr, nullptr)
OPTION(prefix_1, &"-ggdb0"[1], ggdb0, Flag, ggdbN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ggdb1"[1], ggdb1, Flag, ggdbN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ggdb2"[1], ggdb2, Flag, ggdbN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ggdb3"[1], ggdb3, Flag, ggdbN_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ggdb"[1], ggdb, Flag, gTune_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ggnu-pubnames"[1], ggnu_pubnames, Flag, g_flags_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GH"[1], _SLASH_GH, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Gh"[1], _SLASH_Gh, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-ginline-line-tables"[1], ginline_line_tables, Flag, g_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_2, &"/GL-"[1], _SLASH_GL_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gline-directives-only"[1], gline_directives_only, Flag, gN_Group, INVALID, nullptr, CoreOption, 0,
       "Emit debug line info directives only", nullptr, nullptr)
OPTION(prefix_1, &"-gline-tables-only"[1], gline_tables_only, Flag, gN_Group, INVALID, nullptr, CoreOption, 0,
       "Emit debug line number tables only", nullptr, nullptr)
OPTION(prefix_1, &"-glldb"[1], glldb, Flag, gTune_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GL"[1], _SLASH_GL, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Gm-"[1], _SLASH_Gm_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gmlt"[1], gmlt, Flag, INVALID, gline_tables_only, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gmodules"[1], gmodules, Flag, gN_Group, INVALID, nullptr, 0, 0,
       "Generate debug info with external references to clang modules or precompiled headers", nullptr, nullptr)
OPTION(prefix_2, &"/Gm"[1], _SLASH_Gm, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gno-codeview-ghash"[1], gno_codeview_ghash, Flag, INVALID, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-gno-column-info"[1], gno_column_info, Flag, g_flags_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-gno-embed-source"[1], gno_embed_source, Flag, g_flags_Group, INVALID, nullptr, NoXarchOption, 0,
       "Restore the default behavior of not embedding source text in DWARF debug sections", nullptr, nullptr)
OPTION(prefix_1, &"-gno-gnu-pubnames"[1], gno_gnu_pubnames, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gno-inline-line-tables"[1], gno_inline_line_tables, Flag, g_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Don't emit inline line tables.", nullptr, nullptr)
OPTION(prefix_1, &"-gno-pubnames"[1], gno_pubnames, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gno-record-command-line"[1], gno_record_command_line, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gno-record-gcc-switches"[1], anonymous_1194, Flag, INVALID, gno_record_command_line, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gno-simple-template-names"[1], gno_simple_template_names, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gno-split-dwarf"[1], gno_split_dwarf, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gno-strict-dwarf"[1], gno_strict_dwarf, Flag, g_flags_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_3, &"--gpu-bundle-output"[2], gpu_bundle_output, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Bundle output files of HIP device compilation", nullptr, nullptr)
OPTION(prefix_3, &"--gpu-instrument-lib="[2], gpu_instrument_lib_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Instrument device library for HIP, which is a LLVM bitcode containing __cyg_profile_func_enter and __cyg_profile_func_exit", nullptr, nullptr)
OPTION(prefix_3, &"--gpu-max-threads-per-block="[2], gpu_max_threads_per_block_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "Default max threads per block for kernel launch bounds for HIP", nullptr, nullptr)
OPTION(prefix_3, &"--gpu-use-aux-triple-only"[2], gpu_use_aux_triple_only, Flag, internal_driver_Group, INVALID, nullptr, NoXarchOption | HelpHidden, 0,
       "Prepare '-aux-triple' only without populating '-aux-target-cpu' and '-aux-target-feature'.", nullptr, nullptr)
OPTION(prefix_1, &"-gpubnames"[1], gpubnames, Flag, g_flags_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GR-"[1], _SLASH_GR_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not emit RTTI data", nullptr, nullptr)
OPTION(prefix_1, &"-grecord-command-line"[1], grecord_command_line, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-grecord-gcc-switches"[1], anonymous_1193, Flag, INVALID, grecord_command_line, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Gregcall"[1], _SLASH_Gregcall, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set __regcall as a default calling convention", nullptr, nullptr)
OPTION(prefix_2, &"/GR"[1], _SLASH_GR, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Emit RTTI data (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Gr"[1], _SLASH_Gr, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set __fastcall as a default calling convention", nullptr, nullptr)
OPTION(prefix_2, &"/GS-"[1], _SLASH_GS_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable buffer security check", nullptr, nullptr)
OPTION(prefix_1, &"-gsce"[1], gsce, Flag, gTune_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gsimple-template-names="[1], gsimple_template_names_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use simple template names in DWARF, or include the full template name with a modified prefix for validation", nullptr, "simple,mangled")
OPTION(prefix_1, &"-gsimple-template-names"[1], gsimple_template_names, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gsplit-dwarf="[1], gsplit_dwarf_EQ, Joined, g_flags_Group, INVALID, nullptr, 0, 0,
       "Set DWARF fission mode to either 'split' or 'single'", nullptr, "split,single")
OPTION(prefix_1, &"-gsplit-dwarf"[1], gsplit_dwarf, Flag, g_flags_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gstabs"[1], gstabs, Joined, g_Group, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gstrict-dwarf"[1], gstrict_dwarf, Flag, g_flags_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_2, &"/GS"[1], _SLASH_GS, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable buffer security check (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Gs"[1], anonymous_1660, Flag, cl_Group, mstack_probe_size, "4096\0", CLOption | NoXarchOption | CLOption, 0,
       "Use stack probes (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Gs"[1], _SLASH_Gs, Joined, cl_Group, mstack_probe_size, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set stack probe size (default 4096)", nullptr, nullptr)
OPTION(prefix_1, &"-gtoggle"[1], gtoggle, Flag, g_flags_Group, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GT"[1], _SLASH_GT, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/guard:"[1], _SLASH_guard, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable Control Flow Guard with /guard:cf, or only the table with /guard:cf,nochecks. Enable EH Continuation Guard with /guard:ehcont", nullptr, nullptr)
OPTION(prefix_1, &"-gused"[1], gused, Flag, g_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-gvms"[1], gvms, Joined, g_Group, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Gv"[1], _SLASH_Gv, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set __vectorcall as a default calling convention", nullptr, nullptr)
OPTION(prefix_2, &"/Gw-"[1], _SLASH_Gw_, Flag, cl_Group, fno_data_sections, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not put each data item in its own section (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Gw"[1], _SLASH_Gw, Flag, cl_Group, fdata_sections, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Put each data item in its own section", nullptr, nullptr)
OPTION(prefix_2, &"/GX-"[1], _SLASH_GX_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Deprecated (like not passing /EH)", nullptr, nullptr)
OPTION(prefix_1, &"-gxcoff"[1], gxcoff, Joined, g_Group, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/GX"[1], _SLASH_GX, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Deprecated; use /EHsc", nullptr, nullptr)
OPTION(prefix_2, &"/Gy-"[1], _SLASH_Gy_, Flag, cl_Group, fno_function_sections, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not put each function in its own section (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Gy"[1], _SLASH_Gy, Flag, cl_Group, ffunction_sections, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Put each function in its own section", nullptr, nullptr)
OPTION(prefix_1, &"-gz="[1], gz_EQ, Joined, g_flags_Group, INVALID, nullptr, 0, 0,
       "DWARF debug sections compression type", nullptr, nullptr)
OPTION(prefix_2, &"/GZ"[1], _SLASH_GZ, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Gz"[1], _SLASH_Gz, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set __stdcall as a default calling convention", nullptr, nullptr)
OPTION(prefix_1, &"-gz"[1], gz, Flag, g_flags_Group, gz_EQ, "zlib\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-G"[1], G, JoinedOrSeparate, m_Group, INVALID, nullptr, NoXarchOption, 0,
       "Put objects of at most <size> bytes into small data section (MIPS / Hexagon)", "<size>", nullptr)
OPTION(prefix_1, &"-g"[1], g_Flag, Flag, g_Group, INVALID, nullptr, 0, 0,
       "Generate source-level debug information", nullptr, nullptr)
OPTION(prefix_1, &"-header-include-file"[1], header_include_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename (or -) to write header include output to", nullptr, nullptr)
OPTION(prefix_2, &"/headerName:"[1], _SLASH_headername, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-headerpad_max_install_names"[1], headerpad__max__install__names, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/headerUnit:angle"[1], _SLASH_headerUnitAngle, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/headerUnit:quote"[1], _SLASH_headerUnitQuote, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/headerUnit"[1], _SLASH_headerUnit, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--help-hidden"[2], _help_hidden, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Display help for hidden options", nullptr, nullptr)
OPTION(prefix_2, &"/HELP"[1], _SLASH_HELP, Flag, cl_Group, help, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-help"[1], help, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | FC1Option | FlangOption, 0,
       "Display available options", nullptr, nullptr)
OPTION(prefix_2, &"/help"[1], _SLASH_help, Flag, cl_Group, help, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Display available options", nullptr, nullptr)
OPTION(prefix_3, &"--hip-device-lib-path="[2], anonymous_60, Joined, INVALID, rocm_device_lib_path_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--hip-device-lib="[2], hip_device_lib_EQ, Joined, Link_Group, INVALID, nullptr, 0, 0,
       "HIP device library", nullptr, nullptr)
OPTION(prefix_3, &"--hip-link"[2], hip_link, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Link clang-offload-bundler bundles for HIP", nullptr, nullptr)
OPTION(prefix_3, &"--hip-path="[2], hip_path_EQ, Joined, i_Group, INVALID, nullptr, 0, 0,
       "HIP runtime installation path, used for finding HIP version and adding HIP include path.", nullptr, nullptr)
OPTION(prefix_3, &"--hip-version="[2], hip_version_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "HIP version in the format of major.minor.patch", nullptr, nullptr)
OPTION(prefix_3, &"--hipspv-pass-plugin="[2], hipspv_pass_plugin_EQ, Joined, Link_Group, INVALID, nullptr, 0, 0,
       "path to a pass plugin for HIP to SPIR-V passes.", "<dsopath>", nullptr)
OPTION(prefix_2, &"/homeparams"[1], _SLASH_homeparams, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/hotpatch"[1], _SLASH_hotpatch, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-H"[1], H, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option, 0,
       "Show header includes and nesting depth", nullptr, nullptr)
OPTION(prefix_2, &"/H"[1], _SLASH_H, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-I-"[1], I_, Flag, I_Group, INVALID, nullptr, 0, 0,
       "Restrict all prior -I flags to double-quoted inclusion and remove current directory from include path", nullptr, nullptr)
OPTION(prefix_1, &"-ibuiltininc"[1], ibuiltininc, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Enable builtin #include directories even when -nostdinc is used before or after -ibuiltininc. Using -nobuiltininc after the option disables it", nullptr, nullptr)
OPTION(prefix_1, &"-idirafter"[1], idirafter, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Add directory to AFTER include search path", nullptr, nullptr)
OPTION(prefix_1, &"-iframeworkwithsysroot"[1], iframeworkwithsysroot, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Add directory to SYSTEM framework search path, absolute paths are relative to -isysroot", "<directory>", nullptr)
OPTION(prefix_1, &"-iframework"[1], iframework, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Add directory to SYSTEM framework search path", nullptr, nullptr)
OPTION(prefix_3, &"--imacros="[2], _imacros_EQ, Joined, INVALID, imacros, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-imacros"[1], imacros, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Include macros from file before parsing", "<file>", nullptr)
OPTION(prefix_1, &"-image_base"[1], image__base, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/imsvc"[1], _SLASH_imsvc, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Add <dir> to system include search path, as if in %INCLUDE%", "<dir>", nullptr)
OPTION(prefix_1, &"-imultilib"[1], imultilib, Separate, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-barrier"[2], _include_barrier, Flag, INVALID, I_, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-directory-after="[2], _include_directory_after_EQ, Joined, INVALID, idirafter, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-directory-after"[2], _include_directory_after, Separate, INVALID, idirafter, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-directory="[2], _include_directory_EQ, Joined, INVALID, I, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-directory"[2], _include_directory, Separate, INVALID, I, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-include-pch"[1], include_pch, Separate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Include precompiled header file", "<file>", nullptr)
OPTION(prefix_3, &"--include-prefix="[2], _include_prefix_EQ, Joined, INVALID, iprefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-prefix"[2], _include_prefix, Separate, INVALID, iprefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-with-prefix-after="[2], _include_with_prefix_after_EQ, Joined, INVALID, iwithprefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-with-prefix-after"[2], _include_with_prefix_after, Separate, INVALID, iwithprefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-with-prefix-before="[2], _include_with_prefix_before_EQ, Joined, INVALID, iwithprefixbefore, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-with-prefix-before"[2], _include_with_prefix_before, Separate, INVALID, iwithprefixbefore, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-with-prefix="[2], _include_with_prefix_EQ, Joined, INVALID, iwithprefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include-with-prefix"[2], _include_with_prefix, Separate, INVALID, iwithprefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--include="[2], _include_EQ, Joined, INVALID, include, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-include"[1], include, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Include file before parsing", "<file>", nullptr)
OPTION(prefix_1, &"-index-header-map"[1], index_header_map, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Make the next included directory (-I or -F) an indexer header map", nullptr, nullptr)
OPTION(prefix_1, &"-init-only"[1], init_only, Flag, Action_Group, INVALID, nullptr, CC1Option | FC1Option | NoDriverOption, 0,
       "Only execute frontend initialization", nullptr, nullptr)
OPTION(prefix_1, &"-init"[1], init, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-inline-asm="[1], inline_asm_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "att,intel")
OPTION(prefix_1, &"-install_name"[1], install__name, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-integrated-as"[1], anonymous_1318, Flag, INVALID, fintegrated_as, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-interface-stub-version="[1], interface_stub_version_EQ, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-internal-externc-isystem"[1], internal_externc_isystem, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add directory to the internal system include search path with implicit extern \"C\" semantics; these are assumed to not be user-provided and are used to model system and standard headers' paths.", "<directory>", nullptr)
OPTION(prefix_1, &"-internal-isystem"[1], internal_isystem, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add directory to the internal system include search path; these are assumed to not be user-provided and are used to model system and standard headers' paths.", "<directory>", nullptr)
OPTION(prefix_1, &"-iprefix"[1], iprefix, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Set the -iwithprefix/-iwithprefixbefore prefix", "<dir>", nullptr)
OPTION(prefix_1, &"-iquote"[1], iquote, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Add directory to QUOTE include search path", "<directory>", nullptr)
OPTION(prefix_1, &"-isysroot"[1], isysroot, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Set the system root directory (usually /)", "<dir>", nullptr)
OPTION(prefix_1, &"-isystem-after"[1], isystem_after, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, NoXarchOption, 0,
       "Add directory to end of the SYSTEM include search path", "<directory>", nullptr)
OPTION(prefix_1, &"-isystem"[1], isystem, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Add directory to SYSTEM include search path", "<directory>", nullptr)
OPTION(prefix_1, &"-ivfsoverlay"[1], ivfsoverlay, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Overlay the virtual filesystem described by file over the real file system", nullptr, nullptr)
OPTION(prefix_1, &"-iwithprefixbefore"[1], iwithprefixbefore, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Set directory to include search path with prefix", "<dir>", nullptr)
OPTION(prefix_1, &"-iwithprefix"[1], iwithprefix, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Set directory to SYSTEM include search path with prefix", "<dir>", nullptr)
OPTION(prefix_1, &"-iwithsysroot"[1], iwithsysroot, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Add directory to SYSTEM include search path, absolute paths are relative to -isysroot", "<directory>", nullptr)
OPTION(prefix_1, &"-I"[1], I, JoinedOrSeparate, I_Group, INVALID, nullptr, CC1Option | CC1AsOption | FlangOption | FC1Option, 0,
       "Add directory to the end of the list of include search paths", "<dir>", nullptr)
OPTION(prefix_2, &"/I"[1], _SLASH_I, JoinedOrSeparate, cl_Group, I, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Add directory to include search path", "<dir>", nullptr)
OPTION(prefix_2, &"/JMC"[1], _SLASH_JMC, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-J"[1], J, JoinedOrSeparate, gfortran_Group, module_dir, nullptr, RenderJoined | FlangOption | FC1Option | FlangOnlyOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/J"[1], _SLASH_J, Flag, cl_Group, funsigned_char, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Make char type unsigned", nullptr, nullptr)
OPTION(prefix_1, &"-keep_private_externs"[1], keep__private__externs, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/kernel-"[1], _SLASH_kernel_, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/kernel"[1], _SLASH_kernel, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--language="[2], _language_EQ, Joined, INVALID, x, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--language"[2], _language, Separate, INVALID, x, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-lazy_framework"[1], lazy__framework, Separate, INVALID, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-lazy_library"[1], lazy__library, Separate, INVALID, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--ld-path="[2], ld_path_EQ, Joined, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/LDd"[1], _SLASH_LDd, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Create debug DLL", nullptr, nullptr)
OPTION(prefix_2, &"/LD"[1], _SLASH_LD, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Create DLL", nullptr, nullptr)
OPTION(prefix_3, &"--libomptarget-amdgcn-bc-path="[2], libomptarget_amdgcn_bc_path_EQ, Joined, i_Group, INVALID, nullptr, 0, 0,
       "Path to libomptarget-amdgcn bitcode library", nullptr, nullptr)
OPTION(prefix_3, &"--libomptarget-nvptx-bc-path="[2], libomptarget_nvptx_bc_path_EQ, Joined, i_Group, INVALID, nullptr, 0, 0,
       "Path to libomptarget-nvptx bitcode library", nullptr, nullptr)
OPTION(prefix_3, &"--library-directory="[2], _library_directory_EQ, Joined, INVALID, L, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--library-directory"[2], _library_directory, Separate, INVALID, L, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--linker-option="[2], linker_option, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add linker option", nullptr, nullptr)
OPTION(prefix_2, &"/link"[1], _SLASH_link, RemainingArgsJoined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Forward options to the linker", "<options>", nullptr)
OPTION(prefix_2, &"/LN"[1], _SLASH_LN, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-load"[1], load, Separate, INVALID, INVALID, nullptr, CC1Option | FC1Option | NoDriverOption, 0,
       "Load the named plugin (dynamic shared object)", "<dsopath>", nullptr)
OPTION(prefix_1, &"-L"[1], L, JoinedOrSeparate, Link_Group, INVALID, nullptr, RenderJoined, 0,
       "Add directory to library search path", "<dir>", nullptr)
OPTION(prefix_1, &"-l"[1], l, JoinedOrSeparate, Link_Group, INVALID, nullptr, LinkerInput | RenderJoined, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m16"[1], m16, Flag, m_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m32"[1], m32, Flag, m_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m3dnowa"[1], m3dnowa, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m3dnow"[1], m3dnow, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m64"[1], m64, Flag, m_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m68000"[1], m68000, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m68010"[1], m68010, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m68020"[1], m68020, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m68030"[1], m68030, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m68040"[1], m68040, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m68060"[1], m68060, Flag, m_m68k_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-m80387"[1], m80387, Flag, INVALID, mx87, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mabi=ieeelongdouble"[1], mabi_EQ_ieeelongdouble, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use IEEE 754 quadruple-precision for long double", nullptr, nullptr)
OPTION(prefix_1, &"-mabi=vec-default"[1], mabi_EQ_vec_default, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Enable the default Altivec ABI on AIX (AIX only). Uses only volatile vector registers.", nullptr, nullptr)
OPTION(prefix_1, &"-mabi=vec-extabi"[1], mabi_EQ_vec_extabi, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Enable the extended Altivec ABI on AIX (AIX only). Uses volatile and nonvolatile vector registers", nullptr, nullptr)
OPTION(prefix_1, &"-mabi="[1], mabi_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mabicalls"[1], mabicalls, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Enable SVR4-style position-independent code (Mips only)", nullptr, nullptr)
OPTION(prefix_1, &"-mabs="[1], mabs_EQ, Joined, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Mach"[1], Mach, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-madx"[1], madx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-maes"[1], maes, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-main-file-name"[1], main_file_name, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Main file name to use for debug info and source if missing", nullptr, nullptr)
OPTION(prefix_1, &"-maix-struct-return"[1], maix_struct_return, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Return all structs in memory (PPC32 only)", nullptr, nullptr)
OPTION(prefix_1, &"-malign-branch-boundary="[1], malign_branch_boundary_EQ, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0,
       "Specify the boundary's size to align branches", nullptr, nullptr)
OPTION(prefix_1, &"-malign-branch="[1], malign_branch_EQ, CommaJoined, m_Group, INVALID, nullptr, NoXarchOption, 0,
       "Specify types of branches to align", nullptr, nullptr)
OPTION(prefix_1, &"-malign-double"[1], malign_double, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Align doubles to two words in structs (x86 only)", nullptr, nullptr)
OPTION(prefix_1, &"-malign-functions="[1], malign_functions_EQ, Joined, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-malign-jumps="[1], malign_jumps_EQ, Joined, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-malign-loops="[1], malign_loops_EQ, Joined, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-maltivec"[1], maltivec, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mamdgpu-ieee"[1], mamdgpu_ieee, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Sets the IEEE bit in the expected default floating point  mode register. Floating point opcodes that support exception flag gathering quiet and propagate signaling NaN inputs per IEEE 754-2008. This option changes the ABI. (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mamx-bf16"[1], mamx_bf16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mamx-int8"[1], mtamx_int8, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mamx-tile"[1], mamx_tile, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mappletvos-version-min="[1], mappletvos_version_min_EQ, Joined, INVALID, mtvos_version_min_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mappletvsimulator-version-min="[1], mappletvsimulator_version_min_EQ, Joined, INVALID, mtvos_simulator_version_min_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-march="[1], march_EQ, Joined, m_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-marm"[1], marm, Flag, INVALID, mno_thumb, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-masm="[1], masm_EQ, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-massembler-fatal-warnings"[1], massembler_fatal_warnings, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Make assembler warnings fatal", nullptr, nullptr)
OPTION(prefix_1, &"-massembler-no-warn"[1], massembler_no_warn, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Make assembler not emit warnings", nullptr, nullptr)
OPTION(prefix_1, &"-matomics"[1], matomics, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx2"[1], mavx2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512bf16"[1], mavx512bf16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512bitalg"[1], mavx512bitalg, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512bw"[1], mavx512bw, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512cd"[1], mavx512cd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512dq"[1], mavx512dq, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512er"[1], mavx512er, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512fp16"[1], mavx512fp16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512f"[1], mavx512f, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512ifma"[1], mavx512ifma, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512pf"[1], mavx512pf, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512vbmi2"[1], mavx512vbmi2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512vbmi"[1], mavx512vbmi, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512vl"[1], mavx512vl, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512vnni"[1], mavx512vnni, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512vp2intersect"[1], mavx512vp2intersect, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx512vpopcntdq"[1], mavx512vpopcntdq, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavxvnni"[1], mavxvnni, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mavx"[1], mavx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mbackchain"[1], mbackchain, Flag, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Link stack frames through backchain on System Z", nullptr, nullptr)
OPTION(prefix_1, &"-mbig-endian"[1], mbig_endian, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mbmi2"[1], mbmi2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mbmi"[1], mbmi, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mbranch-likely"[1], mbranch_likely, Flag, m_Group, INVALID, nullptr, HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mbranch-protection="[1], mbranch_protection_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Enforce targets of indirect branches and function returns", nullptr, nullptr)
OPTION(prefix_1, &"-mbranch-target-enforce"[1], mbranch_target_enforce, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mbranches-within-32B-boundaries"[1], mbranches_within_32B_boundaries, Flag, m_Group, INVALID, nullptr, NoXarchOption, 0,
       "Align selected branches (fused, jcc, jmp) within 32-byte boundary", nullptr, nullptr)
OPTION(prefix_1, &"-mbulk-memory"[1], mbulk_memory, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcheck-zero-division"[1], mcheck_zero_division, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcldemote"[1], mcldemote, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mclflushopt"[1], mclflushopt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mclwb"[1], mclwb, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mclzero"[1], mclzero, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcmodel=medany"[1], mcmodel_EQ_medany, Flag, m_riscv_Features_Group, mcmodel_EQ, "medium\0", CC1Option, 0,
       "Equivalent to -mcmodel=medium, compatible with RISC-V gcc.", nullptr, nullptr)
OPTION(prefix_1, &"-mcmodel=medlow"[1], mcmodel_EQ_medlow, Flag, m_riscv_Features_Group, mcmodel_EQ, "small\0", CC1Option, 0,
       "Equivalent to -mcmodel=small, compatible with RISC-V gcc.", nullptr, nullptr)
OPTION(prefix_1, &"-mcmodel="[1], mcmodel_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcmpb"[1], mcmpb, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcmse"[1], mcmse, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Allow use of CMSE (Armv8-M Security Extensions)", nullptr, nullptr)
OPTION(prefix_1, &"-mcode-object-v3"[1], mcode_object_v3_legacy, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Legacy option to specify code object ABI V3 (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mcode-object-version="[1], mcode_object_version_EQ, Joined, m_Group, INVALID, nullptr, 0, 0,
       "Specify code object ABI version. Defaults to 3. (AMDGPU only)", "<version>", "2,3,4")
OPTION(prefix_1, &"-mcompact-branches="[1], mcompact_branches_EQ, Joined, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mconsole"[1], mconsole, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mconstant-cfstrings"[1], mconstant_cfstrings, Flag, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mconstructor-aliases"[1], mconstructor_aliases, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable emitting complete constructors and destructors as aliases when possible", nullptr, nullptr)
OPTION(prefix_1, &"-mcpu=?"[1], mcpu_EQ_QUESTION, Flag, INVALID, print_supported_cpus, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcpu="[1], mcpu_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcrbits"[1], mcrbits, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcrc32"[1], mcrc32, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcrc"[1], mcrc, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Allow use of CRC instructions (ARM/Mips only)", nullptr, nullptr)
OPTION(prefix_1, &"-mcrypto"[1], mpower8_crypto, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mcumode"[1], mcumode, Flag, m_amdgpu_Features_Group, INVALID, nullptr, 0, 0,
       "Specify CU wavefront execution mode (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mcx16"[1], mcx16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/MDd"[1], _SLASH_MDd, Flag, _SLASH_M_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Use DLL debug run-time", nullptr, nullptr)
OPTION(prefix_1, &"-mdebug-pass"[1], mdebug_pass, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable additional debug output", nullptr, nullptr)
OPTION(prefix_1, &"-mdefault-build-attributes"[1], mdefault_build_attributes, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mdirect-move"[1], mdirect_move, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mdisable-tail-calls"[1], mdisable_tail_calls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable tail call optimization, keeping the call stack accurate", nullptr, nullptr)
OPTION(prefix_1, &"-mdll"[1], mdll, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mdouble-float"[1], mdouble_float, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mdouble="[1], mdouble_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Force double to be 32 bits or 64 bits", nullptr, "32,64")
OPTION(prefix_1, &"-mdspr2"[1], mdspr2, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mdsp"[1], mdsp, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mdynamic-no-pic"[1], mdynamic_no_pic, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MD"[1], MD, Flag, M_Group, INVALID, nullptr, 0, 0,
       "Write a depfile containing user and system headers", nullptr, nullptr)
OPTION(prefix_2, &"/MD"[1], _SLASH_MD, Flag, _SLASH_M_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Use DLL run-time", nullptr, nullptr)
OPTION(prefix_1, &"-meabi"[1], meabi, Separate, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set EABI type, e.g. 4, 5 or gnu (default depends on triple)", nullptr, "default,4,5,gnu")
OPTION(prefix_1, &"-mefpu2"[1], mefpu2, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-membedded-data"[1], membedded_data, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Place constants in the .rodata section instead of the .sdata section even if they meet the -G <size> threshold (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-menable-experimental-extensions"[1], menable_experimental_extensions, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Enable use of experimental RISC-V extensions.", nullptr, nullptr)
OPTION(prefix_1, &"-menable-no-infs"[1], menable_no_infinities, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow optimization to assume there are no infinities.", nullptr, nullptr)
OPTION(prefix_1, &"-menable-no-nans"[1], menable_no_nans, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow optimization to assume there are no NaNs.", nullptr, nullptr)
OPTION(prefix_1, &"-menable-unsafe-fp-math"[1], menable_unsafe_fp_math, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Allow unsafe floating-point math optimizations which may decrease precision", nullptr, nullptr)
OPTION(prefix_1, &"-menqcmd"[1], menqcmd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mexception-handling"[1], mexception_handing, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mexec-model="[1], mexec_model_EQ, Joined, m_wasm_Features_Driver_Group, INVALID, nullptr, 0, 0,
       "Execution model (WebAssembly only)", nullptr, "command,reactor")
OPTION(prefix_1, &"-mexecute-only"[1], mexecute_only, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Disallow generation of data access to code sections (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-mextern-sdata"[1], mextern_sdata, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Assume that externally defined data is in the small data if it meets the -G <size> threshold (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-mf16c"[1], mf16c, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfancy-math-387"[1], mfancy_math_387, Flag, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfentry"[1], mfentry, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Insert calls to fentry at function entry (x86/SystemZ only)", nullptr, nullptr)
OPTION(prefix_1, &"-mfix-and-continue"[1], mfix_and_continue, Flag, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfix-cmse-cve-2021-35465"[1], mfix_cmse_cve_2021_35465, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Work around VLLDM erratum CVE-2021-35465 (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-mfix-cortex-a53-835769"[1], mfix_cortex_a53_835769, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Workaround Cortex-A53 erratum 835769 (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mfix4300"[1], mfix4300, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfloat-abi="[1], mfloat_abi_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, "soft,softfp,hard")
OPTION(prefix_1, &"-mfloat-abi"[1], mfloat_abi, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The float ABI to use", nullptr, nullptr)
OPTION(prefix_1, &"-mfloat128"[1], mfloat128, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfma4"[1], mfma4, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfma"[1], mfma, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfp32"[1], mfp32, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Use 32-bit floating point registers (MIPS only)", nullptr, nullptr)
OPTION(prefix_1, &"-mfp64"[1], mfp64, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Use 64-bit floating point registers (MIPS only)", nullptr, nullptr)
OPTION(prefix_1, &"-mfpmath="[1], mfpmath_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfpmath"[1], mfpmath, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Which unit to use for fp math", nullptr, nullptr)
OPTION(prefix_1, &"-mfprnd"[1], mfprnd, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfpu="[1], mfpu_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfpxx"[1], mfpxx, Flag, m_mips_Features_Group, INVALID, nullptr, HelpHidden, 0,
       "Avoid FPU mode dependent operations when used with the O32 ABI", nullptr, nullptr)
OPTION(prefix_1, &"-mframe-pointer="[1], mframe_pointer_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Specify which frame pointers to retain (all, non-leaf, none).", nullptr, "all,non-leaf,none")
OPTION(prefix_1, &"-mfsgsbase"[1], mfsgsbase, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mfxsr"[1], mfxsr, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MF"[1], MF, JoinedOrSeparate, M_Group, INVALID, nullptr, 0, 0,
       "Write depfile output from -MMD, -MD, -MM, or -M to <file>", "<file>", nullptr)
OPTION(prefix_1, &"-mgeneral-regs-only"[1], mgeneral_regs_only, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Generate code which only uses the general purpose registers (AArch64/x86 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mgfni"[1], mgfni, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mginv"[1], mginv, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mglibc"[1], mglibc, Flag, m_libc_Group, INVALID, nullptr, HelpHidden | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mglobal-merge"[1], mglobal_merge, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Enable merging of globals", nullptr, nullptr)
OPTION(prefix_1, &"-mgpopt"[1], mgpopt, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Use GP relative accesses for symbols known to be in a small data section (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-MG"[1], MG, Flag, M_Group, INVALID, nullptr, CC1Option, 0,
       "Add missing headers to depfile", nullptr, nullptr)
OPTION(prefix_1, &"-mhard-float"[1], mhard_float, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mharden-sls="[1], mharden_sls_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Select straight-line speculation hardening scope", nullptr, nullptr)
OPTION(prefix_1, &"-mhreset"[1], mhreset, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mhtm"[1], mhtm, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mhvx-ieee-fp"[1], mhexagon_hvx_ieee_fp, Flag, m_hexagon_Features_Group, INVALID, nullptr, 0, 0,
       "Enable Hexagon HVX IEEE floating-point", nullptr, nullptr)
OPTION(prefix_1, &"-mhvx-length="[1], mhexagon_hvx_length_EQ, Joined, m_hexagon_Features_HVX_Group, INVALID, nullptr, 0, 0,
       "Set Hexagon Vector Length", nullptr, "64B,128B")
OPTION(prefix_1, &"-mhvx-qfloat"[1], mhexagon_hvx_qfloat, Flag, m_hexagon_Features_HVX_Group, INVALID, nullptr, 0, 0,
       "Enable Hexagon HVX QFloat instructions", nullptr, nullptr)
OPTION(prefix_1, &"-mhvx="[1], mhexagon_hvx_EQ, Joined, m_hexagon_Features_HVX_Group, INVALID, nullptr, 0, 0,
       "Enable Hexagon Vector eXtensions", nullptr, nullptr)
OPTION(prefix_1, &"-mhvx"[1], mhexagon_hvx, Flag, m_hexagon_Features_HVX_Group, INVALID, nullptr, 0, 0,
       "Enable Hexagon Vector eXtensions", nullptr, nullptr)
OPTION(prefix_3, &"--mhwdiv="[2], _mhwdiv_EQ, Joined, INVALID, mhwdiv_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mhwdiv="[1], mhwdiv_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--mhwdiv"[2], _mhwdiv, Separate, INVALID, mhwdiv_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mhwmult="[1], mhwmult_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-miamcu"[1], miamcu, Flag, m_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Use Intel MCU ABI", nullptr, nullptr)
OPTION(prefix_1, &"-mieee-fp"[1], mieee_fp, Flag, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mieee-rnd-near"[1], mieee_rnd_near, Flag, m_hexagon_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mignore-xcoff-visibility"[1], mignore_xcoff_visibility, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Not emit the visibility attribute for asm in AIX OS or give all symbols 'unspecified' visibility in XCOFF object file", nullptr, nullptr)
OPTION(prefix_3, &"--migrate"[2], _migrate, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Run the migrator", nullptr, nullptr)
OPTION(prefix_1, &"-migrate"[1], migrate, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Migrate source code", nullptr, nullptr)
OPTION(prefix_1, &"-mimplicit-float"[1], mimplicit_float, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mimplicit-it="[1], mimplicit_it_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mincremental-linker-compatible"[1], mincremental_linker_compatible, Flag, m_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "(integrated-as) Emit an object file which can be used with an incremental linker", nullptr, nullptr)
OPTION(prefix_1, &"-mindirect-jump="[1], mindirect_jump_EQ, Joined, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Change indirect jump instructions to inhibit speculation", nullptr, nullptr)
OPTION(prefix_1, &"-minline-all-stringops"[1], minline_all_stringops, Flag, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-minvariant-function-descriptors"[1], minvariant_function_descriptors, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-minvpcid"[1], minvpcid, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mios-simulator-version-min="[1], mios_simulator_version_min_EQ, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mios-version-min="[1], mios_version_min_EQ, Joined, INVALID, miphoneos_version_min_EQ, nullptr, 0, 0,
       "Set iOS deployment target", nullptr, nullptr)
OPTION(prefix_1, &"-miphoneos-version-min="[1], miphoneos_version_min_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-miphonesimulator-version-min="[1], miphonesimulator_version_min_EQ, Joined, INVALID, mios_simulator_version_min_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mips16"[1], mips16, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mips1"[1], mips1, Flag, m_mips_Features_Group, march_EQ, "mips1\0", HelpHidden, 0,
       "Equivalent to -march=mips1", nullptr, nullptr)
OPTION(prefix_1, &"-mips2"[1], mips2, Flag, m_mips_Features_Group, march_EQ, "mips2\0", HelpHidden, 0,
       "Equivalent to -march=mips2", nullptr, nullptr)
OPTION(prefix_1, &"-mips32r2"[1], mips32r2, Flag, m_mips_Features_Group, march_EQ, "mips32r2\0", HelpHidden, 0,
       "Equivalent to -march=mips32r2", nullptr, nullptr)
OPTION(prefix_1, &"-mips32r3"[1], mips32r3, Flag, m_mips_Features_Group, march_EQ, "mips32r3\0", HelpHidden, 0,
       "Equivalent to -march=mips32r3", nullptr, nullptr)
OPTION(prefix_1, &"-mips32r5"[1], mips32r5, Flag, m_mips_Features_Group, march_EQ, "mips32r5\0", HelpHidden, 0,
       "Equivalent to -march=mips32r5", nullptr, nullptr)
OPTION(prefix_1, &"-mips32r6"[1], mips32r6, Flag, m_mips_Features_Group, march_EQ, "mips32r6\0", HelpHidden, 0,
       "Equivalent to -march=mips32r6", nullptr, nullptr)
OPTION(prefix_1, &"-mips32"[1], mips32, Flag, m_mips_Features_Group, march_EQ, "mips32\0", HelpHidden, 0,
       "Equivalent to -march=mips32", nullptr, nullptr)
OPTION(prefix_1, &"-mips3"[1], mips3, Flag, m_mips_Features_Group, march_EQ, "mips3\0", HelpHidden, 0,
       "Equivalent to -march=mips3", nullptr, nullptr)
OPTION(prefix_1, &"-mips4"[1], mips4, Flag, m_mips_Features_Group, march_EQ, "mips4\0", HelpHidden, 0,
       "Equivalent to -march=mips4", nullptr, nullptr)
OPTION(prefix_1, &"-mips5"[1], mips5, Flag, m_mips_Features_Group, march_EQ, "mips5\0", HelpHidden, 0,
       "Equivalent to -march=mips5", nullptr, nullptr)
OPTION(prefix_1, &"-mips64r2"[1], mips64r2, Flag, m_mips_Features_Group, march_EQ, "mips64r2\0", HelpHidden, 0,
       "Equivalent to -march=mips64r2", nullptr, nullptr)
OPTION(prefix_1, &"-mips64r3"[1], mips64r3, Flag, m_mips_Features_Group, march_EQ, "mips64r3\0", HelpHidden, 0,
       "Equivalent to -march=mips64r3", nullptr, nullptr)
OPTION(prefix_1, &"-mips64r5"[1], mips64r5, Flag, m_mips_Features_Group, march_EQ, "mips64r5\0", HelpHidden, 0,
       "Equivalent to -march=mips64r5", nullptr, nullptr)
OPTION(prefix_1, &"-mips64r6"[1], mips64r6, Flag, m_mips_Features_Group, march_EQ, "mips64r6\0", HelpHidden, 0,
       "Equivalent to -march=mips64r6", nullptr, nullptr)
OPTION(prefix_1, &"-mips64"[1], mips64, Flag, m_mips_Features_Group, march_EQ, "mips64\0", HelpHidden, 0,
       "Equivalent to -march=mips64", nullptr, nullptr)
OPTION(prefix_1, &"-misel"[1], misel, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MJ"[1], MJ, JoinedOrSeparate, M_Group, INVALID, nullptr, 0, 0,
       "Write a compilation database entry per input", nullptr, nullptr)
OPTION(prefix_1, &"-mkernel"[1], mkernel, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mkl"[1], mkl, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mldc1-sdc1"[1], mldc1_sdc1, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mlimit-float-precision"[1], mlimit_float_precision, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Limit float precision to the given value", nullptr, nullptr)
OPTION(prefix_1, &"-mlink-bitcode-file"[1], mlink_bitcode_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Link the given bitcode file before performing optimizations.", nullptr, nullptr)
OPTION(prefix_1, &"-mlink-builtin-bitcode"[1], mlink_builtin_bitcode, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Link and internalize needed symbols from the given bitcode file before performing optimizations.", nullptr, nullptr)
OPTION(prefix_1, &"-mlink-cuda-bitcode"[1], mlink_cuda_bitcode, Separate, INVALID, mlink_builtin_bitcode, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mlinker-version="[1], mlinker_version_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mlittle-endian"[1], mlittle_endian, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mllvm"[1], mllvm, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Additional arguments to forward to LLVM's option processing", nullptr, nullptr)
OPTION(prefix_1, &"-mlocal-sdata"[1], mlocal_sdata, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Extend the -G behaviour to object local data (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-mlong-calls"[1], mlong_calls, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Generate branches with extended addressability, usually via indirect jumps.", nullptr, nullptr)
OPTION(prefix_1, &"-mlong-double-128"[1], mlong_double_128, Flag, LongDouble_Group, INVALID, nullptr, CC1Option, 0,
       "Force long double to be 128 bits", nullptr, nullptr)
OPTION(prefix_1, &"-mlong-double-64"[1], mlong_double_64, Flag, LongDouble_Group, INVALID, nullptr, CC1Option, 0,
       "Force long double to be 64 bits", nullptr, nullptr)
OPTION(prefix_1, &"-mlong-double-80"[1], mlong_double_80, Flag, LongDouble_Group, INVALID, nullptr, CC1Option, 0,
       "Force long double to be 80 bits, padded to 128 bits for storage", nullptr, nullptr)
OPTION(prefix_1, &"-mlongcall"[1], mlongcall, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mlvi-cfi"[1], mlvi_cfi, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Enable only control-flow mitigations for Load Value Injection (LVI)", nullptr, nullptr)
OPTION(prefix_1, &"-mlvi-hardening"[1], mlvi_hardening, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Enable all mitigations for Load Value Injection (LVI)", nullptr, nullptr)
OPTION(prefix_1, &"-mlwp"[1], mlwp, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mlzcnt"[1], mlzcnt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmacos-version-min="[1], mmacos_version_min_EQ, Joined, m_Group, mmacosx_version_min_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmacosx-version-min="[1], mmacosx_version_min_EQ, Joined, m_Group, INVALID, nullptr, 0, 0,
       "Set Mac OS X deployment target", nullptr, nullptr)
OPTION(prefix_1, &"-mmadd4"[1], mmadd4, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Enable the generation of 4-operand madd.s, madd.d and related instructions.", nullptr, nullptr)
OPTION(prefix_1, &"-mmark-bti-property"[1], mmark_bti_property, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Add .note.gnu.property with BTI to assembly files (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mmcu="[1], mmcu_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MMD"[1], MMD, Flag, M_Group, INVALID, nullptr, 0, 0,
       "Write a depfile containing user headers", nullptr, nullptr)
OPTION(prefix_1, &"-mmemops"[1], mmemops, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Enable generation of memop instructions", nullptr, nullptr)
OPTION(prefix_1, &"-mmfcrf"[1], mmfcrf, Flag, INVALID, mmfocrf, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmfocrf"[1], mmfocrf, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmicromips"[1], mmicromips, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmma"[1], mmma, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmmx"[1], mmmx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmovbe"[1], mmovbe, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmovdir64b"[1], mmovdir64b, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmovdiri"[1], mmovdiri, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmpx"[1], mmpx, Flag, clang_ignored_legacy_options_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mms-bitfields"[1], mms_bitfields, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set the default structure layout to be compatible with the Microsoft compiler standard", nullptr, nullptr)
OPTION(prefix_1, &"-mmsa"[1], mmsa, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Enable MSA ASE (MIPS only)", nullptr, nullptr)
OPTION(prefix_1, &"-mmt"[1], mmt, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Enable MT ASE (MIPS only)", nullptr, nullptr)
OPTION(prefix_1, &"-mmultivalue"[1], mmultivalue, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmutable-globals"[1], mmutable_globals, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mmwaitx"[1], mmwaitx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MM"[1], MM, Flag, M_Group, INVALID, nullptr, 0, 0,
       "Like -MMD, but also implies -E and writes to stdout by default", nullptr, nullptr)
OPTION(prefix_1, &"-mnan="[1], mnan_EQ, Joined, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-3dnowa"[1], mno_3dnowa, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-3dnow"[1], mno_3dnow, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-80387"[1], mno_80387, Flag, INVALID, mno_x87, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-abicalls"[1], mno_abicalls, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Disable SVR4-style position-independent code (Mips only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-adx"[1], mno_adx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-aes"[1], mno_aes, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-altivec"[1], mno_altivec, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-amdgpu-ieee"[1], mno_amdgpu_ieee, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-mno-amx-bf16"[1], mno_amx_bf16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-amx-int8"[1], mno_amx_int8, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-amx-tile"[1], mno_amx_tile, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-atomics"[1], mno_atomics, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx2"[1], mno_avx2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512bf16"[1], mno_avx512bf16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512bitalg"[1], mno_avx512bitalg, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512bw"[1], mno_avx512bw, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512cd"[1], mno_avx512cd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512dq"[1], mno_avx512dq, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512er"[1], mno_avx512er, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512fp16"[1], mno_avx512fp16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512f"[1], mno_avx512f, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512ifma"[1], mno_avx512ifma, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512pf"[1], mno_avx512pf, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512vbmi2"[1], mno_avx512vbmi2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512vbmi"[1], mno_avx512vbmi, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512vl"[1], mno_avx512vl, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512vnni"[1], mno_avx512vnni, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512vp2intersect"[1], mno_avx512vp2intersect, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx512vpopcntdq"[1], mno_avx512vpopcntdq, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avxvnni"[1], mno_avxvnni, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-avx"[1], mno_avx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-backchain"[1], mno_backchain, Flag, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-mno-bmi2"[1], mno_bmi2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-bmi"[1], mno_bmi, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-branch-likely"[1], mno_branch_likely, Flag, m_Group, INVALID, nullptr, HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-bti-at-return-twice"[1], mno_bti_at_return_twice, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Do not add a BTI instruction after a setjmp or other return-twice construct (Arm only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-bulk-memory"[1], mno_bulk_memory, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-check-zero-division"[1], mno_check_zero_division, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-cldemote"[1], mno_cldemote, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-clflushopt"[1], mno_clflushopt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-clwb"[1], mno_clwb, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-clzero"[1], mno_clzero, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-cmpb"[1], mno_cmpb, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-code-object-v3"[1], mno_code_object_v3_legacy, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Legacy option to specify code object ABI V2 (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-constant-cfstrings"[1], mno_constant_cfstrings, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-constructor-aliases"[1], mno_constructor_aliases, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable emitting complete constructors and destructors as aliases when possible", nullptr, nullptr)
OPTION(prefix_1, &"-mno-crbits"[1], mno_crbits, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-crc32"[1], mno_crc32, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-crc"[1], mno_crc, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Disallow use of CRC instructions (Mips only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-crypto"[1], mnopower8_crypto, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-cumode"[1], mno_cumode, Flag, m_amdgpu_Features_Group, INVALID, nullptr, 0, 0,
       "Specify WGP wavefront execution mode (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-cx16"[1], mno_cx16, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-default-build-attributes"[1], mno_default_build_attributes, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-direct-move"[1], mnodirect_move, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-dspr2"[1], mno_dspr2, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-dsp"[1], mno_dsp, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-embedded-data"[1], mno_embedded_data, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Do not place constants in the .rodata section instead of the .sdata if they meet the -G <size> threshold (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-enqcmd"[1], mno_enqcmd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-exception-handling"[1], mno_exception_handing, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-execute-only"[1], mno_execute_only, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Allow generation of data access to code sections (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-extern-sdata"[1], mno_extern_sdata, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Do not assume that externally defined data is in the small data if it meets the -G <size> threshold (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-f16c"[1], mno_f16c, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-fix-cmse-cve-2021-35465"[1], mno_fix_cmse_cve_2021_35465, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Don't work around VLLDM erratum CVE-2021-35465 (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-fix-cortex-a53-835769"[1], mno_fix_cortex_a53_835769, Flag, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Don't workaround Cortex-A53 erratum 835769 (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-float128"[1], mno_float128, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-fma4"[1], mno_fma4, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-fma"[1], mno_fma, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-fp-ret-in-387"[1], mno_fp_ret_in_387, Flag, INVALID, mno_x87, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-fprnd"[1], mno_fprnd, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-fsgsbase"[1], mno_fsgsbase, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-fxsr"[1], mno_fxsr, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-gfni"[1], mno_gfni, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-ginv"[1], mno_ginv, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-global-merge"[1], mno_global_merge, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Disable merging of globals", nullptr, nullptr)
OPTION(prefix_1, &"-mno-gpopt"[1], mno_gpopt, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Do not use GP relative accesses for symbols known to be in a small data section (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-hreset"[1], mno_hreset, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-htm"[1], mno_htm, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-hvx-ieee-fp"[1], mno_hexagon_hvx_ieee_fp, Flag, m_hexagon_Features_Group, INVALID, nullptr, 0, 0,
       "Disable Hexagon HVX IEEE floating-point", nullptr, nullptr)
OPTION(prefix_1, &"-mno-hvx-qfloat"[1], mno_hexagon_hvx_qfloat, Flag, m_hexagon_Features_HVX_Group, INVALID, nullptr, 0, 0,
       "Disable Hexagon HVX QFloat instructions", nullptr, nullptr)
OPTION(prefix_1, &"-mno-hvx"[1], mno_hexagon_hvx, Flag, m_hexagon_Features_HVX_Group, INVALID, nullptr, 0, 0,
       "Disable Hexagon Vector eXtensions", nullptr, nullptr)
OPTION(prefix_1, &"-mno-iamcu"[1], mno_iamcu, Flag, m_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-implicit-float"[1], mno_implicit_float, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Don't generate implicit floating point instructions", nullptr, nullptr)
OPTION(prefix_1, &"-mno-incremental-linker-compatible"[1], mno_incremental_linker_compatible, Flag, m_Group, INVALID, nullptr, 0, 0,
       "(integrated-as) Emit an object file which cannot be used with an incremental linker", nullptr, nullptr)
OPTION(prefix_1, &"-mno-inline-all-stringops"[1], mno_inline_all_stringops, Flag, clang_ignored_m_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-invariant-function-descriptors"[1], mno_invariant_function_descriptors, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-invpcid"[1], mno_invpcid, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-isel"[1], mno_isel, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-kl"[1], mno_kl, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-ldc1-sdc1"[1], mno_ldc1_sdc1, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-local-sdata"[1], mno_local_sdata, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Do not extend the -G behaviour to object local data (MIPS)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-long-calls"[1], mno_long_calls, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Restore the default behaviour of not generating long calls", nullptr, nullptr)
OPTION(prefix_1, &"-mno-longcall"[1], mno_longcall, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-lvi-cfi"[1], mno_lvi_cfi, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Disable control-flow mitigations for Load Value Injection (LVI)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-lvi-hardening"[1], mno_lvi_hardening, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Disable mitigations for Load Value Injection (LVI)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-lwp"[1], mno_lwp, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-lzcnt"[1], mno_lzcnt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-madd4"[1], mno_madd4, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Disable the generation of 4-operand madd.s, madd.d and related instructions.", nullptr, nullptr)
OPTION(prefix_1, &"-mno-memops"[1], mno_memops, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of memop instructions", nullptr, nullptr)
OPTION(prefix_1, &"-mno-mfcrf"[1], mno_mfcrf, Flag, INVALID, mno_mfocrf, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-mfocrf"[1], mno_mfocrf, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-micromips"[1], mno_micromips, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-mips16"[1], mno_mips16, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-mma"[1], mno_mma, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-mmx"[1], mno_mmx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-movbe"[1], mno_movbe, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-movdir64b"[1], mno_movdir64b, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-movdiri"[1], mno_movdiri, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-movt"[1], mno_movt, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Disallow use of movt/movw pairs (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-mpx"[1], mno_mpx, Flag, clang_ignored_legacy_options_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-ms-bitfields"[1], mno_ms_bitfields, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Do not set the default structure layout to be compatible with the Microsoft compiler standard", nullptr, nullptr)
OPTION(prefix_1, &"-mno-msa"[1], mno_msa, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Disable MSA ASE (MIPS only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-mt"[1], mno_mt, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0,
       "Disable MT ASE (MIPS only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-multivalue"[1], mno_multivalue, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-mutable-globals"[1], mno_mutable_globals, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-mwaitx"[1], mno_mwaitx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-neg-immediates"[1], mno_neg_immediates, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Disallow converting instructions with negative immediates to their negation or inversion.", nullptr, nullptr)
OPTION(prefix_1, &"-mno-nontrapping-fptoint"[1], mno_nontrapping_fptoint, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-nvj"[1], mno_nvj, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of new-value jumps", nullptr, nullptr)
OPTION(prefix_1, &"-mno-nvs"[1], mno_nvs, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of new-value stores", nullptr, nullptr)
OPTION(prefix_1, &"-mno-odd-spreg"[1], mno_odd_spreg, Flag, m_mips_Features_Group, INVALID, nullptr, HelpHidden, 0,
       "Disable odd single-precision floating point registers", nullptr, nullptr)
OPTION(prefix_1, &"-mno-omit-leaf-frame-pointer"[1], mno_omit_leaf_frame_pointer, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-outline-atomics"[1], mno_outline_atomics, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Don't generate local calls to out-of-line atomic operations", nullptr, nullptr)
OPTION(prefix_1, &"-mno-outline"[1], mno_outline, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Disable function outlining (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-packed-stack"[1], mno_packed_stack, Flag, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-packets"[1], mno_packets, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of instruction packets", nullptr, nullptr)
OPTION(prefix_1, &"-mno-paired-vector-memops"[1], mnopaired_vector_memops, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-pascal-strings"[1], mno_pascal_strings, Flag, INVALID, fno_pascal_strings, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-pclmul"[1], mno_pclmul, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-pconfig"[1], mno_pconfig, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-pcrel"[1], mno_pcrel, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-pku"[1], mno_pku, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-popcntd"[1], mno_popcntd, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-popcnt"[1], mno_popcnt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-power10-vector"[1], mno_power10_vector, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-power8-vector"[1], mno_power8_vector, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-power9-vector"[1], mno_power9_vector, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-prefetchwt1"[1], mno_prefetchwt1, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-prefixed"[1], mno_prefixed, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-prfchw"[1], mno_prfchw, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-ptwrite"[1], mno_ptwrite, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-pure-code"[1], mno_pure_code, Flag, INVALID, mno_execute_only, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-rdpid"[1], mno_rdpid, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-rdrnd"[1], mno_rdrnd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-rdseed"[1], mno_rdseed, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-red-zone"[1], mno_red_zone, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-reference-types"[1], mno_reference_types, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-relax-all"[1], mno_relax_all, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-relax-pic-calls"[1], mno_relax_pic_calls, Flag, m_mips_Features_Group, INVALID, nullptr, HelpHidden, 0,
       "Do not produce relaxation hints for linkers to try optimizing PIC call sequences into direct calls (MIPS only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-relaxed-simd"[1], mno_relaxed_simd, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-relax"[1], mno_relax, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Disable linker relaxation", nullptr, nullptr)
OPTION(prefix_1, &"-mno-restrict-it"[1], mno_restrict_it, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Allow generation of deprecated IT blocks for ARMv8. It is off by default for ARMv8 Thumb mode", nullptr, nullptr)
OPTION(prefix_1, &"-mno-retpoline-external-thunk"[1], mno_retpoline_external_thunk, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-retpoline"[1], mno_retpoline, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-rtd"[1], mno_rtd, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-rtm"[1], mno_rtm, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sahf"[1], mno_sahf, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-save-restore"[1], mno_save_restore, Flag, m_riscv_Features_Group, INVALID, nullptr, 0, 0,
       "Disable using library calls for save and restore", nullptr, nullptr)
OPTION(prefix_1, &"-mno-serialize"[1], mno_serialize, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-seses"[1], mno_seses, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Disable speculative execution side effect suppression (SESES)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-sgx"[1], mno_sgx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sha"[1], mno_sha, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-shstk"[1], mno_shstk, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sign-ext"[1], mno_sign_ext, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-simd128"[1], mno_simd128, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-skip-rax-setup"[1], mno_skip_rax_setup, Flag, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-soft-float"[1], mno_soft_float, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-speculative-load-hardening"[1], mno_speculative_load_hardening, Flag, m_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-mno-spe"[1], mno_spe, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sse2"[1], mno_sse2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sse3"[1], mno_sse3, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sse4.1"[1], mno_sse4_1, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sse4.2"[1], mno_sse4_2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sse4a"[1], mno_sse4a, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sse4"[1], mno_sse4, Flag, INVALID, mno_sse4_1, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-sse"[1], mno_sse, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-ssse3"[1], mno_ssse3, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-stack-arg-probe"[1], mno_stack_arg_probe, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Disable stack probes which are enabled by default", nullptr, nullptr)
OPTION(prefix_1, &"-mno-stackrealign"[1], mno_stackrealign, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-tail-call"[1], mno_tail_call, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-tbm"[1], mno_tbm, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-tgsplit"[1], mno_tgsplit, Flag, m_amdgpu_Features_Group, INVALID, nullptr, 0, 0,
       "Disable threadgroup split execution mode (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-thumb"[1], mno_thumb, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-tls-direct-seg-refs"[1], mno_tls_direct_seg_refs, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Disable direct TLS access through segment registers", nullptr, nullptr)
OPTION(prefix_1, &"-mno-tsxldtrk"[1], mno_tsxldtrk, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-uintr"[1], mno_uintr, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-unaligned-access"[1], mno_unaligned_access, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Force all memory accesses to be aligned (AArch32/AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-unsafe-fp-atomics"[1], mno_unsafe_fp_atomics, Flag, m_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-mno-vaes"[1], mno_vaes, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-virt"[1], mno_virt, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-vpclmulqdq"[1], mno_vpclmulqdq, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-vsx"[1], mno_vsx, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-vx"[1], mno_vx, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-vzeroupper"[1], mno_vzeroupper, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-waitpkg"[1], mno_waitpkg, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-warn-nonportable-cfstrings"[1], mno_warn_nonportable_cfstrings, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-wavefrontsize64"[1], mno_wavefrontsize64, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Specify wavefront size 32 mode (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mno-wbnoinvd"[1], mno_wbnoinvd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-widekl"[1], mno_widekl, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-x87"[1], mno_x87, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-xgot"[1], mno_xgot, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-xop"[1], mno_xop, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-xsavec"[1], mno_xsavec, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-xsaveopt"[1], mno_xsaveopt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-xsaves"[1], mno_xsaves, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-xsave"[1], mno_xsave, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mno-zvector"[1], mno_zvector, Flag, INVALID, fno_zvector, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mnocrc"[1], mnocrc, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Disallow use of CRC instructions (ARM only)", nullptr, nullptr)
OPTION(prefix_1, &"-mnoexecstack"[1], mno_exec_stack, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Mark the file as not needing an executable stack", nullptr, nullptr)
OPTION(prefix_1, &"-mnontrapping-fptoint"[1], mnontrapping_fptoint, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mnop-mcount"[1], mnop_mcount, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Generate mcount/__fentry__ calls as nops. To activate they need to be patched in.", nullptr, nullptr)
OPTION(prefix_1, &"-mnvj"[1], mnvj, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Enable generation of new-value jumps", nullptr, nullptr)
OPTION(prefix_1, &"-mnvs"[1], mnvs, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Enable generation of new-value stores", nullptr, nullptr)
OPTION(prefix_1, &"-modd-spreg"[1], modd_spreg, Flag, m_mips_Features_Group, INVALID, nullptr, HelpHidden, 0,
       "Enable odd single-precision floating point registers", nullptr, nullptr)
OPTION(prefix_1, &"-module-dependency-dir"[1], module_dependency_dir, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Directory to dump module dependencies to", nullptr, nullptr)
OPTION(prefix_1, &"-module-dir"[1], module_dir, Separate, INVALID, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Put MODULE files in <dir>", "<dir>", nullptr)
OPTION(prefix_1, &"-module-file-deps"[1], module_file_deps, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include module files in dependency output", nullptr, nullptr)
OPTION(prefix_1, &"-module-file-info"[1], module_file_info, Flag, Action_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Provide information about a particular module file", nullptr, nullptr)
OPTION(prefix_1, &"-module-suffix"[1], module_suffix, Separate, f_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Use <suffix> as the suffix for module files (the default value is `.mod`)", "<suffix>", nullptr)
OPTION(prefix_1, &"-momit-leaf-frame-pointer"[1], momit_leaf_frame_pointer, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Omit frame pointer setup for leaf functions", nullptr, nullptr)
OPTION(prefix_1, &"-moslib="[1], moslib_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-moutline-atomics"[1], moutline_atomics, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Generate local calls to out-of-line atomic operations", nullptr, nullptr)
OPTION(prefix_1, &"-moutline"[1], moutline, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Enable function outlining (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mpacked-stack"[1], mpacked_stack, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use packed stack layout (SystemZ only).", nullptr, nullptr)
OPTION(prefix_1, &"-mpackets"[1], mpackets, Flag, m_hexagon_Features_Group, INVALID, nullptr, CC1Option, 0,
       "Enable generation of instruction packets", nullptr, nullptr)
OPTION(prefix_1, &"-mpad-max-prefix-size="[1], mpad_max_prefix_size_EQ, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0,
       "Specify maximum number of prefixes to use for padding", nullptr, nullptr)
OPTION(prefix_1, &"-mpaired-vector-memops"[1], mpaired_vector_memops, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpascal-strings"[1], mpascal_strings, Flag, INVALID, fpascal_strings, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpclmul"[1], mpclmul, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpconfig"[1], mpconfig, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpcrel"[1], mpcrel, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpku"[1], mpku, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpopcntd"[1], mpopcntd, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpopcnt"[1], mpopcnt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpower10-vector"[1], mpower10_vector, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpower8-vector"[1], mpower8_vector, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpower9-vector"[1], mpower9_vector, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mprefer-vector-width="[1], mprefer_vector_width_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Specifies preferred vector width for auto-vectorization. Defaults to 'none' which allows target specific decisions.", nullptr, nullptr)
OPTION(prefix_1, &"-mprefetchwt1"[1], mprefetchwt1, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mprefixed"[1], mprefixed, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mprfchw"[1], mprfchw, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mprivileged"[1], mprivileged, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mptwrite"[1], mptwrite, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mpure-code"[1], mpure_code, Flag, INVALID, mexecute_only, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MP"[1], MP, Flag, M_Group, INVALID, nullptr, CC1Option, 0,
       "Create phony target for each dependency (other than main file)", nullptr, nullptr)
OPTION(prefix_2, &"/MP"[1], _SLASH_MP, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mqdsp6-compat"[1], mqdsp6_compat, Flag, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Enable hexagon-qdsp6 backward compatibility", nullptr, nullptr)
OPTION(prefix_1, &"-MQ"[1], MQ, JoinedOrSeparate, M_Group, INVALID, nullptr, CC1Option, 0,
       "Specify name of main file output to quote in depfile", nullptr, nullptr)
OPTION(prefix_1, &"-mrdpid"[1], mrdpid, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mrdrnd"[1], mrdrnd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mrdseed"[1], mrdseed, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mreassociate"[1], mreassociate, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow reassociation transformations for floating-point instructions", nullptr, nullptr)
OPTION(prefix_1, &"-mrecip="[1], mrecip_EQ, CommaJoined, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mrecip"[1], mrecip, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mrecord-mcount"[1], mrecord_mcount, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Generate a __mcount_loc section entry for each __fentry__ call.", nullptr, nullptr)
OPTION(prefix_1, &"-mred-zone"[1], mred_zone, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mreference-types"[1], mreference_types, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mregparm="[1], mregparm_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mregparm"[1], mregparm, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Limit the number of registers available for integer arguments", nullptr, nullptr)
OPTION(prefix_1, &"-mrelax-all"[1], mrelax_all, Flag, m_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "(integrated-as) Relax all machine instructions", nullptr, nullptr)
OPTION(prefix_1, &"-mrelax-pic-calls"[1], mrelax_pic_calls, Flag, m_mips_Features_Group, INVALID, nullptr, HelpHidden, 0,
       "Produce relaxation hints for linkers to try optimizing PIC call sequences into direct calls (MIPS only)", nullptr, nullptr)
OPTION(prefix_3, &"--mrelax-relocations"[2], mrelax_relocations, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Use relaxable elf relocations", nullptr, nullptr)
OPTION(prefix_1, &"-mrelaxed-simd"[1], mrelaxed_simd, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mrelax"[1], mrelax, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Enable linker relaxation", nullptr, nullptr)
OPTION(prefix_1, &"-mrelocation-model"[1], mrelocation_model, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "The relocation model to use", nullptr, "static,pic,ropi,rwpi,ropi-rwpi,dynamic-no-pic")
OPTION(prefix_1, &"-mrestrict-it"[1], mrestrict_it, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Disallow generation of deprecated IT blocks for ARMv8. It is on by default for ARMv8 Thumb mode.", nullptr, nullptr)
OPTION(prefix_1, &"-mretpoline-external-thunk"[1], mretpoline_external_thunk, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mretpoline"[1], mretpoline, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mrop-protect"[1], mrop_protect, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mrtd"[1], mrtd, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Make StdCall calling convention the default", nullptr, nullptr)
OPTION(prefix_1, &"-mrtm"[1], mrtm, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msahf"[1], msahf, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msave-restore"[1], msave_restore, Flag, m_riscv_Features_Group, INVALID, nullptr, 0, 0,
       "Enable using library calls for save and restore", nullptr, nullptr)
OPTION(prefix_1, &"-msave-temp-labels"[1], msave_temp_labels, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Save temporary labels in the symbol table. Note this may change .s semantics and shouldn't generally be used on compiler-generated code.", nullptr, nullptr)
OPTION(prefix_1, &"-msecure-plt"[1], msecure_plt, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mserialize"[1], mserialize, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mseses"[1], m_seses, Flag, m_Group, INVALID, nullptr, CoreOption | NoXarchOption, 0,
       "Enable speculative execution side effect suppression (SESES). Includes LVI control flow integrity mitigations", nullptr, nullptr)
OPTION(prefix_1, &"-msgx"[1], msgx, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msha"[1], msha, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mshstk"[1], mshstk, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msign-ext"[1], msign_ext, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msign-return-address-key="[1], msign_return_address_key_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, "a_key,b_key")
OPTION(prefix_1, &"-msign-return-address="[1], msign_return_address_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Select return address signing scope", nullptr, "none,all,non-leaf")
OPTION(prefix_1, &"-msimd128"[1], msimd128, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msim"[1], msim, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msingle-float"[1], msingle_float, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mskip-rax-setup"[1], mskip_rax_setup, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Skip setting up RAX register when passing variable arguments (x86 only)", nullptr, nullptr)
OPTION(prefix_1, &"-msmall-data-limit="[1], msmall_data_limit_EQ, Joined, m_Group, G, nullptr, 0, 0,
       "Put global and static data smaller than the limit into a special section", nullptr, nullptr)
OPTION(prefix_1, &"-msmall-data-limit"[1], msmall_data_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Put global and static data smaller than the limit into a special section", nullptr, nullptr)
OPTION(prefix_1, &"-msmall-data-threshold="[1], msmall_data_threshold_EQ, Joined, m_Group, G, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msoft-float"[1], msoft_float, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use software floating point", nullptr, nullptr)
OPTION(prefix_1, &"-mspeculative-load-hardening"[1], mspeculative_load_hardening, Flag, m_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-mspe"[1], mspe, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msse2"[1], msse2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msse3"[1], msse3, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msse4.1"[1], msse4_1, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msse4.2"[1], msse4_2, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msse4a"[1], msse4a, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msse4"[1], msse4, Flag, INVALID, msse4_2, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-msse"[1], msse, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mssse3"[1], mssse3, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mstack-alignment="[1], mstack_alignment, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set the stack alignment", nullptr, nullptr)
OPTION(prefix_1, &"-mstack-arg-probe"[1], mstack_arg_probe, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Enable stack probes", nullptr, nullptr)
OPTION(prefix_1, &"-mstack-probe-size="[1], mstack_probe_size, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set the stack probe size", nullptr, nullptr)
OPTION(prefix_1, &"-mstack-protector-guard-offset="[1], mstack_protector_guard_offset_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given offset for addressing the stack-protector guard", nullptr, nullptr)
OPTION(prefix_1, &"-mstack-protector-guard-reg="[1], mstack_protector_guard_reg_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given reg for addressing the stack-protector guard", nullptr, nullptr)
OPTION(prefix_1, &"-mstack-protector-guard="[1], mstack_protector_guard_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given guard (global, tls) for addressing the stack-protector guard", nullptr, nullptr)
OPTION(prefix_1, &"-mstackrealign"[1], mstackrealign, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Force realign the stack at entry to every function", nullptr, nullptr)
OPTION(prefix_1, &"-mstrict-align"[1], mstrict_align, Flag, INVALID, mno_unaligned_access, nullptr, CC1Option | HelpHidden, 0,
       "Force all memory accesses to be aligned (same as mno-unaligned-access)", nullptr, nullptr)
OPTION(prefix_1, &"-msve-vector-bits="[1], msve_vector_bits_EQ, Joined, m_aarch64_Features_Group, INVALID, nullptr, 0, 0,
       "Specify the size in bits of an SVE vector register. Defaults to the vector length agnostic value of \"scalable\". (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-msvr4-struct-return"[1], msvr4_struct_return, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Return small structs in registers (PPC32 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mt-migrate-directory"[1], mt_migrate_directory, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Directory for temporary files produced during ARC or ObjC migration", nullptr, nullptr)
OPTION(prefix_1, &"-mtail-call"[1], mtail_call, Flag, m_wasm_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mtargetos="[1], mtargetos_EQ, Joined, m_Group, INVALID, nullptr, 0, 0,
       "Set the deployment target to be the specified OS and OS version", nullptr, nullptr)
OPTION(prefix_1, &"-mtbm"[1], mtbm, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/MTd"[1], _SLASH_MTd, Flag, _SLASH_M_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Use static debug run-time", nullptr, nullptr)
OPTION(prefix_1, &"-mtgsplit"[1], mtgsplit, Flag, m_amdgpu_Features_Group, INVALID, nullptr, 0, 0,
       "Enable threadgroup split execution mode (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mthread-model"[1], mthread_model, Separate, m_Group, INVALID, nullptr, CC1Option, 0,
       "The thread model to use, e.g. posix, single (posix by default)", nullptr, "posix,single")
OPTION(prefix_1, &"-mthreads"[1], mthreads, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mthumb"[1], mthumb, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mtls-direct-seg-refs"[1], mtls_direct_seg_refs, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Enable direct TLS access through segment registers (default)", nullptr, nullptr)
OPTION(prefix_1, &"-mtls-size="[1], mtls_size_EQ, Joined, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify bit size of immediate TLS offsets (AArch64 ELF only): 12 (for 4KB) | 24 (for 16MB, default) | 32 (for 4GB) | 48 (for 256TB, needs -mcmodel=large)", nullptr, nullptr)
OPTION(prefix_1, &"-mtp="[1], mtp_mode_EQ, Joined, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Thread pointer access method (AArch32/AArch64 only)", nullptr, "soft,cp15,el0,el1,el2,el3")
OPTION(prefix_1, &"-mtp"[1], mtp, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Mode for reading thread pointer", nullptr, nullptr)
OPTION(prefix_1, &"-mtsxldtrk"[1], mtsxldtrk, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mtune=?"[1], mtune_EQ_QUESTION, Flag, INVALID, print_supported_cpus, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mtune="[1], mtune_EQ, Joined, m_Group, INVALID, nullptr, 0, 0,
       "Only supported on X86 and RISC-V. Otherwise accepted for compatibility with GCC.", nullptr, nullptr)
OPTION(prefix_1, &"-mtvos-simulator-version-min="[1], mtvos_simulator_version_min_EQ, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mtvos-version-min="[1], mtvos_version_min_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MT"[1], MT, JoinedOrSeparate, M_Group, INVALID, nullptr, CC1Option, 0,
       "Specify name of main file output in depfile", nullptr, nullptr)
OPTION(prefix_2, &"/MT"[1], _SLASH_MT, Flag, _SLASH_M_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Use static run-time", nullptr, nullptr)
OPTION(prefix_1, &"-muclibc"[1], muclibc, Flag, m_libc_Group, INVALID, nullptr, HelpHidden | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-muintr"[1], muintr, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-multi_module"[1], multi__module, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-multiply_defined_unused"[1], multiply__defined__unused, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-multiply_defined"[1], multiply__defined, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-munaligned-access"[1], munaligned_access, Flag, m_arm_Features_Group, INVALID, nullptr, 0, 0,
       "Allow memory accesses to be unaligned (AArch32/AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-municode"[1], municode, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-munsafe-fp-atomics"[1], munsafe_fp_atomics, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Enable unsafe floating point atomic instructions (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mv55"[1], mv55, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv55\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv5"[1], mv5, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv5\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv60"[1], mv60, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv60\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv62"[1], mv62, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv62\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv65"[1], mv65, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv65\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv66"[1], mv66, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv66\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv67t"[1], mv67t, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv67t\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv67"[1], mv67, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv67\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv68"[1], mv68, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv68\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mv69"[1], mv69, Flag, m_hexagon_Features_Group, mcpu_EQ, "hexagonv69\0", 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mvaes"[1], mvaes, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mvirt"[1], mvirt, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mvpclmulqdq"[1], mvpclmulqdq, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mvscale-max="[1], mvscale_max_EQ, Joined, m_aarch64_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the vscale maximum. Defaults to the vector length agnostic value of \"0\". (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mvscale-min="[1], mvscale_min_EQ, Joined, m_aarch64_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the vscale minimum. Defaults to \"1\". (AArch64 only)", nullptr, nullptr)
OPTION(prefix_1, &"-mvsx"[1], mvsx, Flag, m_ppc_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mvx"[1], mvx, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mvzeroupper"[1], mvzeroupper, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-MV"[1], MV, Flag, M_Group, INVALID, nullptr, CC1Option, 0,
       "Use NMake/Jom format for the depfile", nullptr, nullptr)
OPTION(prefix_1, &"-mwaitpkg"[1], mwaitpkg, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mwarn-nonportable-cfstrings"[1], mwarn_nonportable_cfstrings, Flag, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mwatchos-simulator-version-min="[1], mwatchos_simulator_version_min_EQ, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mwatchos-version-min="[1], mwatchos_version_min_EQ, Joined, m_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mwatchsimulator-version-min="[1], mwatchsimulator_version_min_EQ, Joined, INVALID, mwatchos_simulator_version_min_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mwavefrontsize64"[1], mwavefrontsize64, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Specify wavefront size 64 mode (AMDGPU only)", nullptr, nullptr)
OPTION(prefix_1, &"-mwbnoinvd"[1], mwbnoinvd, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mwidekl"[1], mwidekl, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mwindows"[1], mwindows, Joined, m_Group, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mx32"[1], mx32, Flag, m_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mx87"[1], mx87, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mxgot"[1], mxgot, Flag, m_mips_Features_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mxop"[1], mxop, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mxsavec"[1], mxsavec, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mxsaveopt"[1], mxsaveopt, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mxsaves"[1], mxsaves, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mxsave"[1], mxsave, Flag, m_x86_Features_Group, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-mzvector"[1], mzvector, Flag, INVALID, fzvector, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-M"[1], M, Flag, M_Group, INVALID, nullptr, 0, 0,
       "Like -MD, but also implies -E and writes to stdout by default", nullptr, nullptr)
OPTION(prefix_1, &"-new-struct-path-tbaa"[1], new_struct_path_tbaa, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable enhanced struct-path aware Type Based Alias Analysis", nullptr, nullptr)
OPTION(prefix_1, &"-no-canonical-prefixes"[1], no_canonical_prefixes, Flag, INVALID, INVALID, nullptr, HelpHidden | CoreOption, 0,
       "Use relative paths for invoking subcommands", nullptr, nullptr)
OPTION(prefix_1, &"-no-clear-ast-before-backend"[1], no_clear_ast_before_backend, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't clear the Clang AST before running backend code generation", nullptr, nullptr)
OPTION(prefix_1, &"-no-code-completion-globals"[1], no_code_completion_globals, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not include global declarations in code-completion results.", nullptr, nullptr)
OPTION(prefix_1, &"-no-code-completion-ns-level-decls"[1], no_code_completion_ns_level_decls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not include declarations inside namespaces (incl. global namespace) in the code-completion results.", nullptr, nullptr)
OPTION(prefix_1, &"-no-cpp-precomp"[1], no_cpp_precomp, Flag, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--no-cuda-gpu-arch="[2], no_cuda_gpu_arch_EQ, Joined, INVALID, no_offload_arch_EQ, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--no-cuda-include-ptx="[2], no_cuda_include_ptx_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Do not include PTX for the following GPU architecture (e.g. sm_35) or 'all'. May be specified more than once.", nullptr, nullptr)
OPTION(prefix_3, &"--no-cuda-noopt-device-debug"[2], no_cuda_noopt_device_debug, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--no-cuda-version-check"[2], no_cuda_version_check, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Don't error out if the detected version of the CUDA install is too low for the requested CUDA gpu architecture.", nullptr, nullptr)
OPTION(prefix_1, &"-no-emit-llvm-uselists"[1], no_emit_llvm_uselists, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't preserve order of LLVM use-lists when serializing", nullptr, nullptr)
OPTION(prefix_1, &"-no-finalize-removal"[1], migrator_no_finalize_removal, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not remove finalize method in gc mode", nullptr, nullptr)
OPTION(prefix_3, &"--no-gpu-bundle-output"[2], no_gpu_bundle_output, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Do not bundle output files of HIP device compilation", nullptr, nullptr)
OPTION(prefix_1, &"-no-implicit-float"[1], no_implicit_float, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't generate implicit floating point instructions", nullptr, nullptr)
OPTION(prefix_1, &"-no-integrated-as"[1], anonymous_1319, Flag, INVALID, fno_integrated_as, nullptr, CC1Option | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-no-integrated-cpp"[1], no_integrated_cpp, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--no-line-commands"[2], _no_line_commands, Flag, INVALID, P, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-no-ns-alloc-error"[1], migrator_no_nsalloc_error, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not error on use of NSAllocateCollectable/NSReallocateCollectable", nullptr, nullptr)
OPTION(prefix_3, &"--no-offload-arch="[2], no_offload_arch_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Remove CUDA/HIP offloading device architecture (e.g. sm_35, gfx906) from the list of devices to compile for. 'all' resets the list to its default value.", nullptr, nullptr)
OPTION(prefix_4, &"-no-pedantic"[1], no_pedantic, Flag, pedantic_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-no-pie"[1], no_pie, Flag, INVALID, nopie, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-no-pthread"[1], no_pthread, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr)
OPTION(prefix_1, &"-no-round-trip-args"[1], no_round_trip_args, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable command line arguments round-trip.", nullptr, nullptr)
OPTION(prefix_3, &"--no-standard-includes"[2], _no_standard_includes, Flag, INVALID, nostdinc, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--no-standard-libraries"[2], _no_standard_libraries, Flag, INVALID, nostdlib, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-no-struct-path-tbaa"[1], no_struct_path_tbaa, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Turn off struct-path aware Type Based Alias Analysis", nullptr, nullptr)
OPTION(prefix_3, &"--no-system-header-prefix="[2], no_system_header_prefix, Joined, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Treat all #include paths starting with <prefix> as not including a system header.", "<prefix>", nullptr)
OPTION(prefix_3, &"--no-system-header-prefix"[2], anonymous_1301, Separate, INVALID, no_system_header_prefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--no-undefined"[2], _no_undefined, Flag, INVALID, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--no-warnings"[2], _no_warnings, Flag, INVALID, w, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-no_dead_strip_inits_and_terms"[1], no__dead__strip__inits__and__terms, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nobuiltininc"[1], nobuiltininc, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable builtin #include directories", nullptr, nullptr)
OPTION(prefix_1, &"-nocpp"[1], nocpp, Flag, f_Group, INVALID, nullptr, FC1Option | FlangOption | FlangOnlyOption, 0,
       "Disable predefined and command line preprocessor macros", nullptr, nullptr)
OPTION(prefix_1, &"-nocudainc"[1], anonymous_1284, Flag, INVALID, nogpuinc, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nocudalib"[1], anonymous_1285, Flag, INVALID, nogpulib, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nodefaultlibs"[1], nodefaultlibs, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nofixprebinding"[1], nofixprebinding, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nogpuinc"[1], nogpuinc, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Do not add include paths for CUDA/HIP and do not include the default CUDA/HIP wrapper headers", nullptr, nullptr)
OPTION(prefix_1, &"-nogpulib"[1], nogpulib, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Do not link device library for CUDA/HIP device compilation", nullptr, nullptr)
OPTION(prefix_1, &"-nohipwrapperinc"[1], nohipwrapperinc, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Do not include the default HIP wrapper headers and include paths", nullptr, nullptr)
OPTION(prefix_1, &"-nolibc"[1], nolibc, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/nologo"[1], _SLASH_nologo, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nomultidefs"[1], nomultidefs, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nopie"[1], nopie, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-noprebind"[1], noprebind, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-noprofilelib"[1], noprofilelib, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-noseglinkedit"[1], noseglinkedit, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nostartfiles"[1], nostartfiles, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nostdinc++"[1], nostdincxx, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Disable standard #include directories for the C++ standard library", nullptr, nullptr)
OPTION(prefix_1, &"-nostdinc"[1], nostdinc, Flag, INVALID, INVALID, nullptr, CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nostdlib++"[1], nostdlibxx, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nostdlibinc"[1], nostdlibinc, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nostdlib"[1], nostdlib, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-nostdsysteminc"[1], nostdsysteminc, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable standard system #include directories", nullptr, nullptr)
OPTION(prefix_1, &"-n"[1], n, Flag, INVALID, INVALID, nullptr, CC1AsOption | NoDriverOption, 0,
       "Don't automatically start assembly file with a text section", nullptr, nullptr)
OPTION(prefix_1, &"-O0"[1], O0, Flag, O_Group, INVALID, nullptr, CC1Option | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/O1"[1], anonymous_1661, Flag, cl_Group, _SLASH_O, "1\0", CLOption | NoXarchOption | CLOption, 0,
       "Optimize for size  (like /Og     /Os /Oy /Ob2 /GF /Gy)", nullptr, nullptr)
OPTION(prefix_2, &"/O2"[1], anonymous_1662, Flag, cl_Group, _SLASH_O, "2\0", CLOption | NoXarchOption | CLOption, 0,
       "Optimize for speed (like /Og /Oi /Ot /Oy /Ob2 /GF /Gy)", nullptr, nullptr)
OPTION(prefix_1, &"-O4"[1], O4, Flag, O_Group, INVALID, nullptr, CC1Option | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Ob0"[1], anonymous_1663, Flag, cl_Group, _SLASH_O, "b0\0", CLOption | NoXarchOption | CLOption, 0,
       "Disable function inlining", nullptr, nullptr)
OPTION(prefix_2, &"/Ob1"[1], anonymous_1664, Flag, cl_Group, _SLASH_O, "b1\0", CLOption | NoXarchOption | CLOption, 0,
       "Only inline functions explicitly or implicitly marked inline", nullptr, nullptr)
OPTION(prefix_2, &"/Ob2"[1], anonymous_1665, Flag, cl_Group, _SLASH_O, "b2\0", CLOption | NoXarchOption | CLOption, 0,
       "Inline functions as deemed beneficial by the compiler", nullptr, nullptr)
OPTION(prefix_1, &"-ObjC++"[1], ObjCXX, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Treat source input files as Objective-C++ inputs", nullptr, nullptr)
OPTION(prefix_1, &"-objc-isystem"[1], objc_isystem, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add directory to the ObjC SYSTEM include search path", "<directory>", nullptr)
OPTION(prefix_1, &"-objcmt-allowlist-dir-path="[1], objcmt_allowlist_dir_path, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "Only modify files with a filename contained in the provided directory path", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-atomic-property"[1], objcmt_atomic_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Make migration to 'atomic' properties", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-all"[1], objcmt_migrate_all, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-annotation"[1], objcmt_migrate_annotation, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to property and method annotations", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-designated-init"[1], objcmt_migrate_designated_init, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to infer NS_DESIGNATED_INITIALIZER for initializer methods", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-instancetype"[1], objcmt_migrate_instancetype, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to infer instancetype for method result type", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-literals"[1], objcmt_migrate_literals, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC literals", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-ns-macros"[1], objcmt_migrate_nsmacros, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to NS_ENUM/NS_OPTIONS macros", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-property-dot-syntax"[1], objcmt_migrate_property_dot_syntax, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration of setter/getter messages to property-dot syntax", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-property"[1], objcmt_migrate_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC property", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-protocol-conformance"[1], objcmt_migrate_protocol_conformance, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to add protocol conformance on classes", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-readonly-property"[1], objcmt_migrate_readonly_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC readonly property", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-readwrite-property"[1], objcmt_migrate_readwrite_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC readwrite property", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-migrate-subscripting"[1], objcmt_migrate_subscripting, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC subscripting", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-ns-nonatomic-iosonly"[1], objcmt_ns_nonatomic_iosonly, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to use NS_NONATOMIC_IOSONLY macro for setting property's 'atomic' attribute", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-returns-innerpointer-property"[1], objcmt_returns_innerpointer_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to annotate property with NS_RETURNS_INNER_POINTER", nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-white-list-dir-path="[1], anonymous_21, Joined, INVALID, objcmt_allowlist_dir_path, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-objcmt-whitelist-dir-path="[1], anonymous_20, Joined, INVALID, objcmt_allowlist_dir_path, nullptr, CC1Option, 0,
       "Alias for -objcmt-allowlist-dir-path", nullptr, nullptr)
OPTION(prefix_1, &"-objcxx-isystem"[1], objcxx_isystem, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add directory to the ObjC++ SYSTEM include search path", "<directory>", nullptr)
OPTION(prefix_1, &"-ObjC"[1], ObjC, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Treat source input files as Objective-C inputs", nullptr, nullptr)
OPTION(prefix_1, &"-object-file-name="[1], object_file_name_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Set the output <file> for debug infos", "<file>", nullptr)
OPTION(prefix_1, &"-object-file-name"[1], object_file_name, Separate, INVALID, object_file_name_EQ, nullptr, CC1Option | CC1AsOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-object"[1], object, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Od"[1], anonymous_1666, Flag, cl_Group, _SLASH_O, "d\0", CLOption | NoXarchOption | CLOption, 0,
       "Disable optimization", nullptr, nullptr)
OPTION(prefix_1, &"-Ofast"[1], Ofast, Joined, O_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--offload-arch="[2], offload_arch_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "CUDA offloading device architecture (e.g. sm_35), or HIP offloading target ID in the form of a device architecture followed by target ID features delimited by a colon. Each target ID feature is a pre-defined string followed by a plus or minus sign (e.g. gfx908:xnack+:sramecc-).  May be specified more than once.", nullptr, nullptr)
OPTION(prefix_3, &"--offload="[2], offload_EQ, CommaJoined, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Specify comma-separated list of offloading target triples (HIP only)", nullptr, nullptr)
OPTION(prefix_2, &"/Og"[1], anonymous_1667, Flag, cl_Group, _SLASH_O, "g\0", CLOption | NoXarchOption | CLOption, 0,
       "No effect", nullptr, nullptr)
OPTION(prefix_2, &"/Oi-"[1], anonymous_1669, Flag, cl_Group, _SLASH_O, "i-\0", CLOption | NoXarchOption | CLOption, 0,
       "Disable use of builtin functions", nullptr, nullptr)
OPTION(prefix_2, &"/Oi"[1], anonymous_1668, Flag, cl_Group, _SLASH_O, "i\0", CLOption | NoXarchOption | CLOption, 0,
       "Enable use of builtin functions", nullptr, nullptr)
OPTION(prefix_2, &"/openmp-"[1], _SLASH_openmp_, Flag, cl_Group, fno_openmp, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable OpenMP support", nullptr, nullptr)
OPTION(prefix_2, &"/openmp:experimental"[1], _SLASH_openmp_experimental, Flag, cl_Group, fopenmp, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable OpenMP support with experimental SIMD support", nullptr, nullptr)
OPTION(prefix_2, &"/openmp"[1], _SLASH_openmp, Flag, cl_Group, fopenmp, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable OpenMP support", nullptr, nullptr)
OPTION(prefix_1, &"-opt-record-file"[1], opt_record_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "File name to use for YAML optimization record output", nullptr, nullptr)
OPTION(prefix_1, &"-opt-record-format"[1], opt_record_format, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The format used for serializing remarks (default: YAML)", nullptr, nullptr)
OPTION(prefix_1, &"-opt-record-passes"[1], opt_record_passes, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Only record remark information for passes whose names match the given regular expression", nullptr, nullptr)
OPTION(prefix_3, &"--optimize="[2], _optimize_EQ, Joined, INVALID, O, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--optimize"[2], _optimize, Flag, INVALID, O, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Os"[1], anonymous_1670, Flag, cl_Group, _SLASH_O, "s\0", CLOption | NoXarchOption | CLOption, 0,
       "Optimize for size", nullptr, nullptr)
OPTION(prefix_2, &"/Ot"[1], anonymous_1671, Flag, cl_Group, _SLASH_O, "t\0", CLOption | NoXarchOption | CLOption, 0,
       "Optimize for speed", nullptr, nullptr)
OPTION(prefix_1, &"-output-asm-variant"[1], output_asm_variant, Separate, INVALID, INVALID, nullptr, CC1AsOption | NoDriverOption, 0,
       "Select the asm variant index to use for output", nullptr, nullptr)
OPTION(prefix_3, &"--output-class-directory="[2], _output_class_directory_EQ, Joined, INVALID, foutput_class_dir_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--output-class-directory"[2], _output_class_directory, Separate, INVALID, foutput_class_dir_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--output="[2], _output_EQ, Joined, INVALID, o, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--output"[2], _output, Separate, INVALID, o, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Ox"[1], anonymous_1672, Flag, cl_Group, _SLASH_O, "x\0", CLOption | NoXarchOption | CLOption, 0,
       "Deprecated (like /Og /Oi /Ot /Oy /Ob2); use /O2", nullptr, nullptr)
OPTION(prefix_2, &"/Oy-"[1], anonymous_1674, Flag, cl_Group, _SLASH_O, "y-\0", CLOption | NoXarchOption | CLOption, 0,
       "Disable frame pointer omission (x86 only, default)", nullptr, nullptr)
OPTION(prefix_2, &"/Oy"[1], anonymous_1673, Flag, cl_Group, _SLASH_O, "y\0", CLOption | NoXarchOption | CLOption, 0,
       "Enable frame pointer omission (x86 only)", nullptr, nullptr)
OPTION(prefix_1, &"-O"[1], O_flag, Flag, INVALID, O, "1\0", CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-O"[1], O, Joined, O_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/O"[1], _SLASH_O, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set multiple /O flags at once; e.g. '/O2y-' for '/O2 /Oy-'", "<flags>", nullptr)
OPTION(prefix_1, &"-o"[1], o, JoinedOrSeparate, INVALID, INVALID, nullptr, NoXarchOption | RenderAsInput | CC1Option | CC1AsOption | FC1Option | FlangOption, 0,
       "Write output to <file>", "<file>", nullptr)
OPTION(prefix_2, &"/o"[1], _SLASH_o, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Deprecated (set output file name); use /Fe or /Fe", "<file or dir/>", nullptr)
OPTION(prefix_1, &"-pagezero_size"[1], pagezero__size, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--param="[2], _param_EQ, Joined, INVALID, _param, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--param"[2], _param, Separate, CompileOnly_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-pass-exit-codes"[1], pass_exit_codes, Flag, INVALID, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-pch-through-hdrstop-create"[1], pch_through_hdrstop_create, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "When creating a PCH, stop PCH generation after #pragma hdrstop.", nullptr, nullptr)
OPTION(prefix_1, &"-pch-through-hdrstop-use"[1], pch_through_hdrstop_use, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "When using a PCH, skip tokens until after a #pragma hdrstop.", nullptr, nullptr)
OPTION(prefix_1, &"-pch-through-header="[1], pch_through_header_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Stop PCH generation after including this file.  When using a PCH, skip tokens until after this file is included.", nullptr, nullptr)
OPTION(prefix_4, &"-pedantic-errors"[1], pedantic_errors, Flag, pedantic_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-pedantic"[1], pedantic, Flag, pedantic_Group, INVALID, nullptr, CC1Option | FlangOption | FC1Option, 0,
       "Warn on language extensions", nullptr, nullptr)
OPTION(prefix_2, &"/permissive-"[1], _SLASH_permissive_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable non conforming code from compiling (default)", nullptr, nullptr)
OPTION(prefix_2, &"/permissive"[1], _SLASH_permissive, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable some non conforming code to compile", nullptr, nullptr)
OPTION(prefix_1, &"-pg"[1], pg, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable mcount instrumentation", nullptr, nullptr)
OPTION(prefix_1, &"-pic-is-pie"[1], pic_is_pie, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "File is for a position independent executable", nullptr, nullptr)
OPTION(prefix_1, &"-pic-level"[1], pic_level, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Value for __PIC__", nullptr, nullptr)
OPTION(prefix_1, &"-pie"[1], pie, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-pipe"[1], pipe, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Use pipes between commands, when possible", nullptr, nullptr)
OPTION(prefix_1, &"-plugin-arg-"[1], plugin_arg, JoinedAndSeparate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Pass <arg> to plugin <name>", "<name> <arg>", nullptr)
OPTION(prefix_1, &"-plugin"[1], plugin, Separate, INVALID, INVALID, nullptr, CC1Option | FC1Option | NoDriverOption, 0,
       "Use the named plugin action instead of the default action (use \"help\" to list available options)", "<name>", nullptr)
OPTION(prefix_1, &"-preamble-bytes="[1], preamble_bytes_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Assume that the precompiled header is a precompiled preamble covering the first N bytes of the main file", nullptr, nullptr)
OPTION(prefix_1, &"-prebind_all_twolevel_modules"[1], prebind__all__twolevel__modules, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-prebind"[1], prebind, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--precompile"[2], _precompile, Flag, Action_Group, INVALID, nullptr, NoXarchOption, 0,
       "Only precompile the input", nullptr, nullptr)
OPTION(prefix_3, &"--prefix="[2], _prefix_EQ, Joined, INVALID, B, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--prefix"[2], _prefix, Separate, INVALID, B, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-preload"[1], preload, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--preprocess"[2], _preprocess, Flag, INVALID, E, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-print-dependency-directives-minimized-source"[1], print_dependency_directives_minimized_source, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print the output of the dependency directives source minimizer", nullptr, nullptr)
OPTION(prefix_3, &"--print-diagnostic-categories"[2], _print_diagnostic_categories, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-print-effective-triple"[1], print_effective_triple, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the effective target triple", nullptr, nullptr)
OPTION(prefix_4, &"-print-file-name="[1], print_file_name_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Print the full library path of <file>", "<file>", nullptr)
OPTION(prefix_3, &"--print-file-name"[2], _print_file_name, Separate, INVALID, print_file_name_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-print-ivar-layout"[1], print_ivar_layout, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable Objective-C Ivar layout bitmap print trace", nullptr, nullptr)
OPTION(prefix_4, &"-print-libgcc-file-name"[1], print_libgcc_file_name, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the library path for the currently used compiler runtime library (\"libgcc.a\" or \"libclang_rt.builtins.*.a\")", nullptr, nullptr)
OPTION(prefix_3, &"--print-missing-file-dependencies"[2], _print_missing_file_dependencies, Flag, INVALID, MG, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-print-multi-directory"[1], print_multi_directory, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-print-multi-lib"[1], print_multi_lib, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-print-multi-os-directory"[1], print_multi_os_directory, Flag, INVALID, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-print-multiarch"[1], print_multiarch, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the multiarch target triple", nullptr, nullptr)
OPTION(prefix_1, &"-print-preamble"[1], print_preamble, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print the \"preamble\" of a file, which is a candidate for implicit precompiled headers.", nullptr, nullptr)
OPTION(prefix_4, &"-print-prog-name="[1], print_prog_name_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Print the full program path of <name>", "<name>", nullptr)
OPTION(prefix_3, &"--print-prog-name"[2], _print_prog_name, Separate, INVALID, print_prog_name_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-print-resource-dir"[1], print_resource_dir, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the resource directory pathname", nullptr, nullptr)
OPTION(prefix_4, &"-print-rocm-search-dirs"[1], print_rocm_search_dirs, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the paths used for finding ROCm installation", nullptr, nullptr)
OPTION(prefix_4, &"-print-runtime-dir"[1], print_runtime_dir, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the directory pathname containing clangs runtime libraries", nullptr, nullptr)
OPTION(prefix_4, &"-print-search-dirs"[1], print_search_dirs, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the paths used for finding libraries and programs", nullptr, nullptr)
OPTION(prefix_1, &"-print-stats"[1], print_stats, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print performance metrics and statistics", nullptr, nullptr)
OPTION(prefix_4, &"-print-supported-cpus"[1], print_supported_cpus, Flag, CompileOnly_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Print supported cpu models for the given target (if target is not specified, it will print the supported cpus for the default target)", nullptr, nullptr)
OPTION(prefix_4, &"-print-target-triple"[1], print_target_triple, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the normalized target triple", nullptr, nullptr)
OPTION(prefix_4, &"-print-targets"[1], print_targets, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Print the registered targets", nullptr, nullptr)
OPTION(prefix_1, &"-private_bundle"[1], private__bundle, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--profile-blocks"[2], _profile_blocks, Flag, INVALID, a, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--profile"[2], _profile, Flag, INVALID, p, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-pthreads"[1], pthreads, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-pthread"[1], pthread, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Support POSIX threads in generated code", nullptr, nullptr)
OPTION(prefix_3, &"--ptxas-path="[2], ptxas_path_EQ, Joined, i_Group, INVALID, nullptr, 0, 0,
       "Path to ptxas (used for compiling CUDA code)", nullptr, nullptr)
OPTION(prefix_1, &"-P"[1], P, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option | FlangOption | FC1Option, 0,
       "Disable linemarker output in -E mode", nullptr, nullptr)
OPTION(prefix_2, &"/P"[1], _SLASH_P, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Preprocess to file", nullptr, nullptr)
OPTION(prefix_1, &"-p"[1], p, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qfast_transcendentals"[1], _SLASH_Qfast_transcendentals, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/QIfist"[1], _SLASH_QIfist, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qimprecise_fwaits"[1], _SLASH_Qimprecise_fwaits, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/QIntel-jcc-erratum"[1], _SLASH_QIntel_jcc_erratum, Flag, cl_Group, mbranches_within_32B_boundaries, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Align branches within 32-byte boundaries to mitigate the performance impact of the Intel JCC erratum.", nullptr, nullptr)
OPTION(prefix_1, &"-Qn"[1], Qn, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Do not emit metadata containing compiler name and version", nullptr, nullptr)
OPTION(prefix_2, &"/Qpar-report"[1], _SLASH_Qpar_report, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qpar"[1], _SLASH_Qpar, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qsafe_fp_loads"[1], _SLASH_Qsafe_fp_loads, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qspectre-load-cf"[1], _SLASH_Qspectre_load_cf, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qspectre-load"[1], _SLASH_Qspectre_load, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qspectre"[1], _SLASH_Qspectre, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Qunused-arguments"[1], Qunused_arguments, Flag, INVALID, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Don't emit warning for unused driver arguments", nullptr, nullptr)
OPTION(prefix_2, &"/Qvec-report"[1], _SLASH_Qvec_report, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Qvec-"[1], _SLASH_Qvec_, Flag, cl_Group, fno_vectorize, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable the loop vectorization passes", nullptr, nullptr)
OPTION(prefix_2, &"/Qvec"[1], _SLASH_Qvec, Flag, cl_Group, fvectorize, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable the loop vectorization passes", nullptr, nullptr)
OPTION(prefix_1, &"-Qy"[1], Qy, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Emit metadata containing compiler name and version", nullptr, nullptr)
OPTION(prefix_1, &"-Q"[1], Q, Flag, INVALID, INVALID, nullptr, HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-rdynamic"[1], rdynamic, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-read_only_relocs"[1], read__only__relocs, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-record-command-line"[1], record_command_line, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "The string to embed in the .LLVM.command.line section.", nullptr, nullptr)
OPTION(prefix_2, &"/reference"[1], _SLASH_reference, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-relaxed-aliasing"[1], relaxed_aliasing, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Turn off Type Based Alias Analysis", nullptr, nullptr)
OPTION(prefix_4, &"-relocatable-pch"[1], relocatable_pch, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Whether to build a relocatable precompiled header", nullptr, nullptr)
OPTION(prefix_1, &"-remap-file"[1], remap_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Replace the contents of the <from> file with the contents of the <to> file", "<from>;<to>", nullptr)
OPTION(prefix_1, &"-remap"[1], remap, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-resource-dir="[1], resource_dir_EQ, Joined, INVALID, resource_dir, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-resource-dir"[1], resource_dir, Separate, INVALID, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption | HelpHidden, 0,
       "The directory which holds the compiler resource files", nullptr, nullptr)
OPTION(prefix_3, &"--resource="[2], _resource_EQ, Joined, INVALID, fcompile_resource_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--resource"[2], _resource, Separate, INVALID, fcompile_resource_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-rewrite-legacy-objc"[1], rewrite_legacy_objc, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Rewrite Legacy Objective-C source to C++", nullptr, nullptr)
OPTION(prefix_1, &"-rewrite-macros"[1], rewrite_macros, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Expand macros without full preprocessing", nullptr, nullptr)
OPTION(prefix_1, &"-rewrite-objc"[1], rewrite_objc, Flag, Action_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Rewrite Objective-C source to C++", nullptr, nullptr)
OPTION(prefix_1, &"-rewrite-test"[1], rewrite_test, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Rewriter playground", nullptr, nullptr)
OPTION(prefix_3, &"--rocm-device-lib-path="[2], rocm_device_lib_path_EQ, Joined, Link_Group, INVALID, nullptr, 0, 0,
       "ROCm device library path. Alternative to rocm-path.", nullptr, nullptr)
OPTION(prefix_3, &"--rocm-path="[2], rocm_path_EQ, Joined, i_Group, INVALID, nullptr, 0, 0,
       "ROCm installation path, used for finding and automatically linking required bitcode libraries.", nullptr, nullptr)
OPTION(prefix_1, &"-round-trip-args"[1], round_trip_args, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable command line arguments round-trip.", nullptr, nullptr)
OPTION(prefix_1, &"-Rpass-analysis="[1], Rpass_analysis_EQ, Joined, R_value_Group, INVALID, nullptr, CC1Option, 0,
       "Report transformation analysis from optimization passes whose name matches the given POSIX regular expression", nullptr, nullptr)
OPTION(prefix_1, &"-Rpass-missed="[1], Rpass_missed_EQ, Joined, R_value_Group, INVALID, nullptr, CC1Option, 0,
       "Report missed transformations by optimization passes whose name matches the given POSIX regular expression", nullptr, nullptr)
OPTION(prefix_1, &"-Rpass="[1], Rpass_EQ, Joined, R_value_Group, INVALID, nullptr, CC1Option, 0,
       "Report transformations performed by optimization passes whose name matches the given POSIX regular expression", nullptr, nullptr)
OPTION(prefix_1, &"-rpath"[1], rpath, Separate, Link_Group, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--rsp-quoting="[2], rsp_quoting, Joined, internal_driver_Group, INVALID, nullptr, CoreOption | NoXarchOption | HelpHidden, 0,
       "Set the rsp quoting to either 'posix', or 'windows'", nullptr, nullptr)
OPTION(prefix_2, &"/RTC"[1], _SLASH_RTC, Joined, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-rtlib="[1], rtlib_EQ, Joined, INVALID, INVALID, nullptr, 0, 0,
       "Compiler runtime library to use", nullptr, nullptr)
OPTION(prefix_3, &"--rtlib"[2], _rtlib, Separate, INVALID, rtlib_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-R"[1], R_Joined, Joined, R_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable the specified remark", "<remark>", nullptr)
OPTION(prefix_1, &"-r"[1], r, Flag, Link_Group, INVALID, nullptr, LinkerInput | NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-save-stats="[1], save_stats_EQ, Joined, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Save llvm statistics.", nullptr, nullptr)
OPTION(prefix_4, &"-save-stats"[1], save_stats, Flag, INVALID, save_stats_EQ, "cwd\0", NoXarchOption, 0,
       "Save llvm statistics.", nullptr, nullptr)
OPTION(prefix_4, &"-save-temps="[1], save_temps_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoXarchOption, 0,
       "Save intermediate compilation results.", nullptr, nullptr)
OPTION(prefix_4, &"-save-temps"[1], save_temps, Flag, INVALID, save_temps_EQ, "cwd\0", NoXarchOption, 0,
       "Save intermediate compilation results", nullptr, nullptr)
OPTION(prefix_2, &"/sdl-"[1], _SLASH_sdl_, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/sdl"[1], _SLASH_sdl, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-sectalign"[1], sectalign, MultiArg, INVALID, INVALID, nullptr, 0, 3, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-sectcreate"[1], sectcreate, MultiArg, INVALID, INVALID, nullptr, 0, 3, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-sectobjectsymbols"[1], sectobjectsymbols, MultiArg, INVALID, INVALID, nullptr, 0, 2, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-sectorder"[1], sectorder, MultiArg, INVALID, INVALID, nullptr, 0, 3, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-seg1addr"[1], seg1addr, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-seg_addr_table_filename"[1], seg__addr__table__filename, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-seg_addr_table"[1], seg__addr__table, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-segaddr"[1], segaddr, MultiArg, INVALID, INVALID, nullptr, 0, 2, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-segcreate"[1], segcreate, MultiArg, INVALID, INVALID, nullptr, 0, 3, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-seglinkedit"[1], seglinkedit, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-segprot"[1], segprot, MultiArg, INVALID, INVALID, nullptr, 0, 3, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-segs_read_only_addr"[1], segs__read__only__addr, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-segs_read_write_addr"[1], segs__read__write__addr, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-segs_read_"[1], segs__read__, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-serialize-diagnostic-file"[1], diagnostic_serialized_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "File for serializing diagnostics in a binary format", "<filename>", nullptr)
OPTION(prefix_4, &"-serialize-diagnostics"[1], _serialize_diags, Separate, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Serialize compiler diagnostics to a file", nullptr, nullptr)
OPTION(prefix_1, &"-setup-static-analyzer"[1], setup_static_analyzer, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set up preprocessor for static analyzer (done automatically when static analyzer is run).", nullptr, nullptr)
OPTION(prefix_1, &"-shared-libasan"[1], anonymous_147, Flag, INVALID, shared_libsan, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-shared-libgcc"[1], shared_libgcc, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-shared-libsan"[1], shared_libsan, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Dynamically link the sanitizer runtime", nullptr, nullptr)
OPTION(prefix_4, &"-shared"[1], shared, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-show-encoding"[1], show_encoding, Flag, INVALID, INVALID, nullptr, CC1AsOption | NoDriverOption, 0,
       "Show instruction encoding information in transliterate mode", nullptr, nullptr)
OPTION(prefix_3, &"--show-includes"[2], show_includes, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print cl.exe style /showIncludes to stdout", nullptr, nullptr)
OPTION(prefix_1, &"-show-inst"[1], show_inst, Flag, INVALID, INVALID, nullptr, CC1AsOption | NoDriverOption, 0,
       "Show internal instruction representation in transliterate mode", nullptr, nullptr)
OPTION(prefix_2, &"/showFilenames-"[1], _SLASH_showFilenames_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not print the name of each compiled file (default)", nullptr, nullptr)
OPTION(prefix_2, &"/showFilenames"[1], _SLASH_showFilenames, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Print the name of each compiled file", nullptr, nullptr)
OPTION(prefix_2, &"/showIncludes:user"[1], _SLASH_showIncludes_user, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Like /showIncludes but omit system headers", nullptr, nullptr)
OPTION(prefix_2, &"/showIncludes"[1], _SLASH_showIncludes, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Print info about included files to stderr", nullptr, nullptr)
OPTION(prefix_3, &"--signed-char"[2], _signed_char, Flag, INVALID, fsigned_char, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-single_module"[1], single__module, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/source-charset:"[1], _SLASH_source_charset, Joined, cl_compile_Group, finput_charset_EQ, nullptr, CLOption | NoXarchOption, 0,
       "Set source encoding, supports only UTF-8", nullptr, nullptr)
OPTION(prefix_2, &"/sourceDependencies:directives"[1], _SLASH_sourceDependenciesDirectives, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/sourceDependencies"[1], _SLASH_sourceDependencies, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-specs="[1], specs_EQ, Joined, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-specs"[1], specs, Separate, INVALID, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-split-dwarf-file"[1], split_dwarf_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Name of the split dwarf debug info file to encode in the object file", nullptr, nullptr)
OPTION(prefix_1, &"-split-dwarf-output"[1], split_dwarf_output, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "File name to use for split dwarf debug info output", nullptr, nullptr)
OPTION(prefix_1, &"-stack-protector-buffer-size"[1], stack_protector_buffer_size, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Lower bound for a buffer to be considered for stack protection", nullptr, nullptr)
OPTION(prefix_1, &"-stack-protector"[1], stack_protector, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable stack protectors", nullptr, "0,1,2,3")
OPTION(prefix_1, &"-stack-usage-file"[1], stack_usage_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename (or -) to write stack usage output to", nullptr, nullptr)
OPTION(prefix_1, &"-static-define"[1], static_define, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Should __STATIC__ be defined", nullptr, nullptr)
OPTION(prefix_1, &"-static-libgcc"[1], static_libgcc, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-static-libgfortran"[1], static_libgfortran, Flag, gfortran_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-static-libsan"[1], static_libsan, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Statically link the sanitizer runtime", nullptr, nullptr)
OPTION(prefix_1, &"-static-libstdc++"[1], static_libstdcxx, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-static-openmp"[1], static_openmp, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Use the static host OpenMP runtime while linking.", nullptr, nullptr)
OPTION(prefix_1, &"-static-pie"[1], static_pie, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-static"[1], static, Flag, Link_Group, INVALID, nullptr, NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-stats-file="[1], stats_file, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename to write statistics to", nullptr, nullptr)
OPTION(prefix_1, &"-std-default="[1], std_default_EQ, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/std:"[1], _SLASH_std, Joined, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Set language version (c++14,c++17,c++20,c++latest,c11,c17)", nullptr, nullptr)
OPTION(prefix_4, &"-std="[1], std_EQ, Joined, CompileOnly_Group, INVALID, nullptr, CC1Option | FlangOption | FC1Option, 0,
       "Language standard to compile for", nullptr, nullptr)
OPTION(prefix_1, &"-stdlib++-isystem"[1], stdlibxx_isystem, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, NoXarchOption, 0,
       "Use directory as the C++ standard library include path", "<directory>", nullptr)
OPTION(prefix_4, &"-stdlib="[1], stdlib_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "C++ standard library to use", nullptr, "libc++,libstdc++,platform")
OPTION(prefix_3, &"--stdlib"[2], _stdlib, Separate, INVALID, stdlib_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--std"[2], _std, Separate, INVALID, std_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-sub_library"[1], sub__library, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-sub_umbrella"[1], sub__umbrella, JoinedOrSeparate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-sycl-std="[1], sycl_std_EQ, Joined, sycl_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | CoreOption, 0,
       "SYCL language standard to compile for.", nullptr, "2020,2017,121,1.2.1,sycl-1.2.1")
OPTION(prefix_1, &"-sys-header-deps"[1], sys_header_deps, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include system headers in dependency output", nullptr, nullptr)
OPTION(prefix_3, &"--sysroot="[2], _sysroot_EQ, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--sysroot"[2], _sysroot, Separate, INVALID, _sysroot_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--system-header-prefix="[2], system_header_prefix, Joined, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Treat all #include paths starting with <prefix> as including a system header.", "<prefix>", nullptr)
OPTION(prefix_3, &"--system-header-prefix"[2], anonymous_1300, Separate, INVALID, system_header_prefix, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-S"[1], S, Flag, Action_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Only run preprocess and compilation steps", nullptr, nullptr)
OPTION(prefix_1, &"-s"[1], s, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-target-abi"[1], target_abi, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Target a particular ABI type", nullptr, nullptr)
OPTION(prefix_1, &"-target-cpu"[1], target_cpu, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Target a specific cpu type", nullptr, nullptr)
OPTION(prefix_1, &"-target-feature"[1], target_feature, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Target specific attributes", nullptr, nullptr)
OPTION(prefix_3, &"--target-help"[2], _target_help, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-target-linker-version"[1], target_linker_version, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Target linker version", nullptr, nullptr)
OPTION(prefix_1, &"-target-sdk-version="[1], target_sdk_version_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "The version of target SDK used for compilation", nullptr, nullptr)
OPTION(prefix_3, &"--target="[2], target, Joined, INVALID, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Generate code for the given target", nullptr, nullptr)
OPTION(prefix_1, &"-target"[1], target_legacy_spelling, Separate, INVALID, target, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Tbss"[1], Tbss, JoinedOrSeparate, T_Group, INVALID, nullptr, 0, 0,
       "Set starting address of BSS to <addr>", "<addr>", nullptr)
OPTION(prefix_2, &"/TC"[1], _SLASH_TC, Flag, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Treat all source files as C", nullptr, nullptr)
OPTION(prefix_2, &"/Tc"[1], _SLASH_Tc, JoinedOrSeparate, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Treat <file> as C source file", "<file>", nullptr)
OPTION(prefix_1, &"-Tdata"[1], Tdata, JoinedOrSeparate, T_Group, INVALID, nullptr, 0, 0,
       "Set starting address of DATA to <addr>", "<addr>", nullptr)
OPTION(prefix_1, &"-templight-dump"[1], templight_dump, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump templight information to stdout", nullptr, nullptr)
OPTION(prefix_1, &"-test-io"[1], test_io, Flag, Action_Group, INVALID, nullptr, FC1Option | FlangOnlyOption, 0,
       "Run the InputOuputTest action. Use for development and testing only.", nullptr, nullptr)
OPTION(prefix_1, &"-time"[1], time, Flag, INVALID, INVALID, nullptr, 0, 0,
       "Time individual commands", nullptr, nullptr)
OPTION(prefix_2, &"/TP"[1], _SLASH_TP, Flag, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Treat all source files as C++", nullptr, nullptr)
OPTION(prefix_2, &"/Tp"[1], _SLASH_Tp, JoinedOrSeparate, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Treat <file> as C++ source file", "<file>", nullptr)
OPTION(prefix_3, &"--trace-includes"[2], _trace_includes, Flag, INVALID, H, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-traditional-cpp"[1], traditional_cpp, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable some traditional CPP emulation", nullptr, nullptr)
OPTION(prefix_4, &"-traditional"[1], traditional, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/translateInclude"[1], _SLASH_translateInclude, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-trigraphs"[1], trigraphs, Flag, INVALID, ftrigraphs, nullptr, 0, 0,
       "Process trigraph sequences", nullptr, nullptr)
OPTION(prefix_1, &"-trim-egraph"[1], trim_egraph, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Only show error-related paths in the analysis graph", nullptr, nullptr)
OPTION(prefix_1, &"-triple="[1], triple_EQ, Joined, INVALID, triple, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-triple"[1], triple, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Specify target triple (e.g. i686-apple-darwin9)", nullptr, nullptr)
OPTION(prefix_1, &"-Ttext"[1], Ttext, JoinedOrSeparate, T_Group, INVALID, nullptr, 0, 0,
       "Set starting address of TEXT to <addr>", "<addr>", nullptr)
OPTION(prefix_1, &"-tune-cpu"[1], tune_cpu, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Tune for a specific cpu type", nullptr, nullptr)
OPTION(prefix_2, &"/tune:"[1], _SLASH_tune, Joined, cl_compile_Group, mtune_EQ, nullptr, CLOption | NoXarchOption, 0,
       "Set CPU for optimization without affecting instruction set", nullptr, nullptr)
OPTION(prefix_1, &"-twolevel_namespace_hints"[1], twolevel__namespace__hints, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-twolevel_namespace"[1], twolevel__namespace, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-T"[1], T, JoinedOrSeparate, T_Group, INVALID, nullptr, 0, 0,
       "Specify <script> as linker script", "<script>", nullptr)
OPTION(prefix_1, &"-t"[1], t, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-umbrella"[1], umbrella, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--undefine-macro="[2], _undefine_macro_EQ, Joined, INVALID, U, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--undefine-macro"[2], _undefine_macro, Separate, INVALID, U, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-undefined"[1], undefined, JoinedOrSeparate, u_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-undef"[1], undef, Flag, u_Group, INVALID, nullptr, CC1Option, 0,
       "undef all system defines", nullptr, nullptr)
OPTION(prefix_1, &"-unexported_symbols_list"[1], unexported__symbols__list, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-unoptimized-cfg"[1], analysis_UnoptimizedCFG, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate unoptimized CFGs for all analyses", nullptr, nullptr)
OPTION(prefix_3, &"--unsigned-char"[2], _unsigned_char, Flag, INVALID, funsigned_char, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_4, &"-unwindlib="[1], unwindlib_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "Unwind library to use", nullptr, "libgcc,unwindlib,platform")
OPTION(prefix_3, &"--user-dependencies"[2], _user_dependencies, Flag, INVALID, MM, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/utf-8"[1], _SLASH_utf8, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Set source and runtime encoding to UTF-8 (default)", nullptr, nullptr)
OPTION(prefix_1, &"-U"[1], U, JoinedOrSeparate, Preprocessor_Group, INVALID, nullptr, CC1Option | FlangOption | FC1Option, 0,
       "Undefine macro <macro>", "<macro>", nullptr)
OPTION(prefix_2, &"/U"[1], _SLASH_U, JoinedOrSeparate, cl_Group, U, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Undefine macro", "<macro>", nullptr)
OPTION(prefix_1, &"-u"[1], u, JoinedOrSeparate, u_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/u"[1], _SLASH_u, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/validate-charset-"[1], _SLASH_validate_charset_, Flag, cl_Group, W_Joined, "no-invalid-source-encoding\0", CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/validate-charset"[1], _SLASH_validate_charset, Flag, cl_Group, W_Joined, "invalid-source-encoding\0", CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/vctoolsdir"[1], _SLASH_vctoolsdir, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Path to the VCToolChain", "<dir>", nullptr)
OPTION(prefix_2, &"/vctoolsversion"[1], _SLASH_vctoolsversion, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "For use with /winsysroot, defaults to newest found", nullptr, nullptr)
OPTION(prefix_2, &"/vd"[1], _SLASH_vd, Joined, cl_Group, vtordisp_mode_EQ, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Control vtordisp placement", nullptr, nullptr)
OPTION(prefix_1, &"-vectorize-loops"[1], vectorize_loops, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run the Loop vectorization passes", nullptr, nullptr)
OPTION(prefix_1, &"-vectorize-slp"[1], vectorize_slp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run the SLP vectorization passes", nullptr, nullptr)
OPTION(prefix_3, &"--verbose"[2], _verbose, Flag, INVALID, v, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--verify-debug-info"[2], verify_debug_info, Flag, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Verify the binary representation of debug output", nullptr, nullptr)
OPTION(prefix_1, &"-verify-ignore-unexpected="[1], verify_ignore_unexpected_EQ, CommaJoined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Ignore unexpected diagnostic messages", nullptr, nullptr)
OPTION(prefix_1, &"-verify-ignore-unexpected"[1], verify_ignore_unexpected, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Ignore unexpected diagnostic messages", nullptr, nullptr)
OPTION(prefix_1, &"-verify-pch"[1], verify_pch, Flag, Action_Group, INVALID, nullptr, CC1Option, 0,
       "Load and verify that a pre-compiled header file is not stale", nullptr, nullptr)
OPTION(prefix_1, &"-verify="[1], verify_EQ, CommaJoined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Verify diagnostic output using comment directives that start with prefixes in the comma-separated sequence <prefixes>", "<prefixes>", nullptr)
OPTION(prefix_1, &"-verify"[1], verify, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Equivalent to -verify=expected", nullptr, nullptr)
OPTION(prefix_3, &"--version"[2], _version, Flag, INVALID, INVALID, nullptr, CoreOption | CC1Option | FC1Option | FlangOption, 0,
       "Print version information", nullptr, nullptr)
OPTION(prefix_1, &"-version"[1], version, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Print the compiler version", nullptr, nullptr)
OPTION(prefix_4, &"-via-file-asm"[1], via_file_asm, Flag, internal_debug_Group, INVALID, nullptr, NoXarchOption | HelpHidden | CoreOption, 0,
       "Write assembly to file for input to assemble jobs", nullptr, nullptr)
OPTION(prefix_2, &"/vmb"[1], _SLASH_vmb, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Use a best-case representation method for member pointers", nullptr, nullptr)
OPTION(prefix_2, &"/vmg"[1], _SLASH_vmg, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Use a most-general representation for member pointers", nullptr, nullptr)
OPTION(prefix_2, &"/vmm"[1], _SLASH_vmm, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set the default most-general representation to multiple inheritance", nullptr, nullptr)
OPTION(prefix_2, &"/vms"[1], _SLASH_vms, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set the default most-general representation to single inheritance", nullptr, nullptr)
OPTION(prefix_2, &"/vmv"[1], _SLASH_vmv, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set the default most-general representation to virtual inheritance", nullptr, nullptr)
OPTION(prefix_2, &"/volatile:iso"[1], _SLASH_volatile_iso, Flag, _SLASH_volatile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Volatile loads and stores have standard semantics", nullptr, nullptr)
OPTION(prefix_2, &"/volatile:ms"[1], _SLASH_volatile_ms, Flag, _SLASH_volatile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0,
       "Volatile loads and stores have acquire and release semantics", nullptr, nullptr)
OPTION(prefix_1, &"-vtordisp-mode="[1], vtordisp_mode_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Control vtordisp placement on win32 targets", nullptr, nullptr)
OPTION(prefix_1, &"-V"[1], V, JoinedOrSeparate, INVALID, INVALID, nullptr, NoXarchOption | Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/V"[1], _SLASH_V, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-v"[1], v, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Show commands to run and use verbose output", nullptr, nullptr)
OPTION(prefix_2, &"/W0"[1], _SLASH_W0, Flag, cl_Group, w, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable all warnings", nullptr, nullptr)
OPTION(prefix_2, &"/W1"[1], _SLASH_W1, Flag, cl_Group, Wall, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable -Wall", nullptr, nullptr)
OPTION(prefix_2, &"/W2"[1], _SLASH_W2, Flag, cl_Group, Wall, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable -Wall", nullptr, nullptr)
OPTION(prefix_2, &"/W3"[1], _SLASH_W3, Flag, cl_Group, Wall, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable -Wall", nullptr, nullptr)
OPTION(prefix_2, &"/W4"[1], _SLASH_W4, Flag, cl_Group, WCL4, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable -Wall and -Wextra", nullptr, nullptr)
OPTION(prefix_1, &"-Wa,"[1], Wa_COMMA, CommaJoined, INVALID, INVALID, nullptr, 0, 0,
       "Pass the comma separated arguments in <arg> to the assembler", "<arg>", nullptr)
OPTION(prefix_1, &"-Wall"[1], Wall, Flag, W_Group, INVALID, nullptr, CC1Option | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Wall"[1], _SLASH_Wall, Flag, cl_Group, W_Joined, "everything\0", CLOption | NoXarchOption | CLOption, 0,
       "Enable -Weverything", nullptr, nullptr)
OPTION(prefix_3, &"--warn-="[2], _warn__EQ, Joined, INVALID, W_Joined, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--warn-"[2], _warn_, Joined, INVALID, W_Joined, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-WCL4"[1], WCL4, Flag, W_Group, INVALID, nullptr, CC1Option | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wdeprecated"[1], Wdeprecated, Flag, W_Group, INVALID, nullptr, CC1Option, 0,
       "Enable warnings for deprecated constructs and define __DEPRECATED", nullptr, nullptr)
OPTION(prefix_2, &"/wd"[1], _SLASH_wd, Joined, cl_compile_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-weak-l"[1], weak_l, Joined, INVALID, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-weak_framework"[1], weak__framework, Separate, INVALID, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-weak_library"[1], weak__library, Separate, INVALID, INVALID, nullptr, LinkerInput, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-weak_reference_mismatches"[1], weak__reference__mismatches, Separate, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wframe-larger-than="[1], Wframe_larger_than_EQ, Joined, W_value_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wframe-larger-than"[1], Wframe_larger_than, Flag, INVALID, Wframe_larger_than_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-whatsloaded"[1], whatsloaded, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-why_load"[1], why_load, Flag, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-whyload"[1], whyload, Flag, INVALID, why_load, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/winsdkdir"[1], _SLASH_winsdkdir, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Path to the Windows SDK", "<dir>", nullptr)
OPTION(prefix_2, &"/winsdkversion"[1], _SLASH_winsdkversion, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Full version of the Windows SDK, defaults to newest found", nullptr, nullptr)
OPTION(prefix_2, &"/winsysroot"[1], _SLASH_winsysroot, JoinedOrSeparate, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Same as \"/diasdkdir <dir>/DIA SDK\" /vctoolsdir <dir>/VC/Tools/MSVC/<vctoolsversion> \"/winsdkdir <dir>/Windows Kits/10\"", "<dir>", nullptr)
OPTION(prefix_1, &"-Wl,"[1], Wl_COMMA, CommaJoined, Link_Group, INVALID, nullptr, LinkerInput | RenderAsInput, 0,
       "Pass the comma separated arguments in <arg> to the linker", "<arg>", nullptr)
OPTION(prefix_1, &"-Wlarge-by-value-copy="[1], Wlarge_by_value_copy_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wlarge-by-value-copy"[1], Wlarge_by_value_copy_def, Flag, INVALID, INVALID, nullptr, HelpHidden, 0,
       "Warn if a function definition returns or accepts an object larger in bytes than a given value", nullptr, nullptr)
OPTION(prefix_1, &"-Wlarger-than-"[1], Wlarger_than_, Joined, INVALID, Wlarger_than_EQ, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wlarger-than="[1], Wlarger_than_EQ, Joined, clang_ignored_f_Group, INVALID, nullptr, Ignored, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/WL"[1], _SLASH_WL, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wno-deprecated"[1], Wno_deprecated, Flag, W_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wno-nonportable-cfstrings"[1], Wno_nonportable_cfstrings, Joined, W_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wno-rewrite-macros"[1], Wno_rewrite_macros, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Silence ObjC rewriting warnings", nullptr, nullptr)
OPTION(prefix_1, &"-Wno-write-strings"[1], Wno_write_strings, Flag, W_Group, INVALID, nullptr, CC1Option | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wnonportable-cfstrings"[1], Wnonportable_cfstrings, Joined, W_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-working-directory="[1], working_directory_EQ, Joined, INVALID, working_directory, nullptr, CC1Option, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-working-directory"[1], working_directory, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Resolve file paths relative to the specified directory", nullptr, nullptr)
OPTION(prefix_1, &"-Wp,"[1], Wp_COMMA, CommaJoined, Preprocessor_Group, INVALID, nullptr, 0, 0,
       "Pass the comma separated arguments in <arg> to the preprocessor", "<arg>", nullptr)
OPTION(prefix_2, &"/Wp64"[1], _SLASH_Wp64, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--write-dependencies"[2], _write_dependencies, Flag, INVALID, MD, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--write-user-dependencies"[2], _write_user_dependencies, Flag, INVALID, MMD, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Wundef-prefix="[1], Wundef_prefix_EQ, CommaJoined, W_value_Group, INVALID, nullptr, CC1Option | CoreOption | HelpHidden, 0,
       "Enable warnings for undefined macros with a prefix in the comma separated list <arg>", "<arg>", nullptr)
OPTION(prefix_1, &"-Wwrite-strings"[1], Wwrite_strings, Flag, W_Group, INVALID, nullptr, CC1Option | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/WX-"[1], _SLASH_WX_, Flag, cl_Group, W_Joined, "no-error\0", CLOption | NoXarchOption | CLOption, 0,
       "Do not treat warnings as errors (default)", nullptr, nullptr)
OPTION(prefix_2, &"/WX"[1], _SLASH_WX, Flag, cl_Group, W_Joined, "error\0", CLOption | NoXarchOption | CLOption, 0,
       "Treat warnings as errors", nullptr, nullptr)
OPTION(prefix_1, &"-W"[1], W_Joined, Joined, W_Group, INVALID, nullptr, CC1Option | CoreOption | FC1Option | FlangOption, 0,
       "Enable the specified warning", "<warning>", nullptr)
OPTION(prefix_1, &"-w"[1], w, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Suppress all warnings", nullptr, nullptr)
OPTION(prefix_2, &"/w"[1], _SLASH_w_flag, Flag, cl_Group, w, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable all warnings", nullptr, nullptr)
OPTION(prefix_2, &"/w"[1], _SLASH_w, Joined, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Xanalyzer"[1], Xanalyzer, Separate, StaticAnalyzer_Group, INVALID, nullptr, 0, 0,
       "Pass <arg> to the static analyzer", "<arg>", nullptr)
OPTION(prefix_1, &"-Xarch_device"[1], Xarch_device, Separate, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Pass <arg> to the CUDA/HIP device compilation", "<arg>", nullptr)
OPTION(prefix_1, &"-Xarch_host"[1], Xarch_host, Separate, INVALID, INVALID, nullptr, NoXarchOption, 0,
       "Pass <arg> to the CUDA/HIP host compilation", "<arg>", nullptr)
OPTION(prefix_1, &"-Xarch_"[1], Xarch__, JoinedAndSeparate, INVALID, INVALID, nullptr, NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Xassembler"[1], Xassembler, Separate, CompileOnly_Group, INVALID, nullptr, 0, 0,
       "Pass <arg> to the assembler", "<arg>", nullptr)
OPTION(prefix_1, &"-Xclang"[1], Xclang, Separate, CompileOnly_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Pass <arg> to the clang compiler", "<arg>", nullptr)
OPTION(prefix_1, &"-Xcuda-fatbinary"[1], Xcuda_fatbinary, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Pass <arg> to fatbinary invocation", "<arg>", nullptr)
OPTION(prefix_1, &"-Xcuda-ptxas"[1], Xcuda_ptxas, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Pass <arg> to the ptxas assembler", "<arg>", nullptr)
OPTION(prefix_1, &"-Xflang"[1], Xflang, Separate, CompileOnly_Group, INVALID, nullptr, FlangOption | FlangOnlyOption | NoXarchOption | CoreOption, 0,
       "Pass <arg> to the flang compiler", "<arg>", nullptr)
OPTION(prefix_1, &"-Xlinker"[1], Xlinker, Separate, Link_Group, INVALID, nullptr, LinkerInput | RenderAsInput, 0,
       "Pass <arg> to the linker", "<arg>", nullptr)
OPTION(prefix_1, &"-Xopenmp-target="[1], Xopenmp_target_EQ, JoinedAndSeparate, INVALID, INVALID, nullptr, 0, 0,
       "Pass <arg> to the target offloading toolchain identified by <triple>.", "<triple> <arg>", nullptr)
OPTION(prefix_1, &"-Xopenmp-target"[1], Xopenmp_target, Separate, INVALID, INVALID, nullptr, 0, 0,
       "Pass <arg> to the target offloading toolchain.", "<arg>", nullptr)
OPTION(prefix_1, &"-Xpreprocessor"[1], Xpreprocessor, Separate, Preprocessor_Group, INVALID, nullptr, 0, 0,
       "Pass <arg> to the preprocessor", "<arg>", nullptr)
OPTION(prefix_1, &"-X"[1], X_Flag, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-X"[1], X_Joined, Joined, INVALID, INVALID, nullptr, HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/X"[1], _SLASH_X, Flag, cl_Group, nostdlibinc, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not add %INCLUDE% to include search path", nullptr, nullptr)
OPTION(prefix_1, &"-x"[1], x, JoinedOrSeparate, INVALID, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Treat subsequent input files as having type <language>", "<language>", nullptr)
OPTION(prefix_2, &"/Y-"[1], _SLASH_Y_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable precompiled headers, overrides /Yc and /Yu", nullptr, nullptr)
OPTION(prefix_2, &"/Yc"[1], _SLASH_Yc, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Generate a pch file for all code up to and including <filename>", "<filename>", nullptr)
OPTION(prefix_2, &"/Yd"[1], _SLASH_Yd, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Yl"[1], _SLASH_Yl, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Yu"[1], _SLASH_Yu, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Load a pch file and use it instead of all code up to and including <filename>", "<filename>", nullptr)
OPTION(prefix_1, &"-y"[1], y, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Z-reserved-lib-cckext"[1], Z_reserved_lib_cckext, Flag, reserved_lib_Group, INVALID, nullptr, LinkerInput | NoArgumentUnused | Unsupported | Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Z-reserved-lib-stdc++"[1], Z_reserved_lib_stdcxx, Flag, reserved_lib_Group, INVALID, nullptr, LinkerInput | NoArgumentUnused | Unsupported | Unsupported, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Z-Xlinker-no-demangle"[1], Z_Xlinker__no_demangle, Flag, INVALID, INVALID, nullptr, Unsupported | NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Z7"[1], _SLASH_Z7, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable CodeView debug information in object files", nullptr, nullptr)
OPTION(prefix_2, &"/Za"[1], _SLASH_Za, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:__cplusplus"[1], _SLASH_Zc___cplusplus, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:alignedNew-"[1], _SLASH_Zc_alignedNew_, Flag, cl_Group, fno_aligned_allocation, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable C++17 aligned allocation functions", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:alignedNew"[1], _SLASH_Zc_alignedNew, Flag, cl_Group, faligned_allocation, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable C++17 aligned allocation functions", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:auto"[1], _SLASH_Zc_auto, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:char8_t-"[1], _SLASH_Zc_char8_t_, Flag, cl_Group, fno_char8__t, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable char8_t from c++2a", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:char8_t"[1], _SLASH_Zc_char8_t, Flag, cl_Group, fchar8__t, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable char8_t from C++2a", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:dllexportInlines-"[1], _SLASH_Zc_dllexportInlines_, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not dllexport/dllimport inline member functions of dllexport/import classes", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:dllexportInlines"[1], _SLASH_Zc_dllexportInlines, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "dllexport/dllimport inline member functions of dllexport/import classes (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:forScope"[1], _SLASH_Zc_forScope, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:inline"[1], _SLASH_Zc_inline, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:rvalueCast"[1], _SLASH_Zc_rvalueCast, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:sizedDealloc-"[1], _SLASH_Zc_sizedDealloc_, Flag, cl_Group, fno_sized_deallocation, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable C++14 sized global deallocation functions", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:sizedDealloc"[1], _SLASH_Zc_sizedDealloc, Flag, cl_Group, fsized_deallocation, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable C++14 sized global deallocation functions", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:strictStrings"[1], _SLASH_Zc_strictStrings, Flag, cl_Group, W_Joined, "error=c++11-compat-deprecated-writable-strings\0", CLOption | NoXarchOption | CLOption, 0,
       "Treat string literals as const", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:ternary"[1], _SLASH_Zc_ternary, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:threadSafeInit-"[1], _SLASH_Zc_threadSafeInit_, Flag, cl_Group, fno_threadsafe_statics, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable thread-safe initialization of static variables", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:threadSafeInit"[1], _SLASH_Zc_threadSafeInit, Flag, cl_Group, fthreadsafe_statics, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable thread-safe initialization of static variables", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:trigraphs-"[1], _SLASH_Zc_trigraphs_off, Flag, cl_Group, fno_trigraphs, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable trigraphs (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:trigraphs"[1], _SLASH_Zc_trigraphs, Flag, cl_Group, ftrigraphs, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable trigraphs", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:twoPhase-"[1], _SLASH_Zc_twoPhase_, Flag, cl_Group, fdelayed_template_parsing, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Disable two-phase name lookup in templates (default)", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:twoPhase"[1], _SLASH_Zc_twoPhase, Flag, cl_Group, fno_delayed_template_parsing, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Enable two-phase name lookup in templates", nullptr, nullptr)
OPTION(prefix_2, &"/Zc:wchar_t"[1], _SLASH_Zc_wchar_t, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zc:"[1], _SLASH_Zc, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Ze"[1], _SLASH_Ze, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zg"[1], _SLASH_Zg, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/ZH:MD5"[1], _SLASH_ZH_MD5, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/ZH:SHA1"[1], _SLASH_ZH_SHA1, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/ZH:SHA_256"[1], _SLASH_ZH_SHA_256, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/ZI"[1], _SLASH_ZI, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zi"[1], _SLASH_Zi, Flag, cl_Group, _SLASH_Z7, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Like /Z7", nullptr, nullptr)
OPTION(prefix_1, &"-Zlinker-input"[1], Zlinker_input, Separate, INVALID, INVALID, nullptr, Unsupported | NoArgumentUnused, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zl"[1], _SLASH_Zl, Flag, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Do not let object file auto-link default libraries", nullptr, nullptr)
OPTION(prefix_2, &"/Zm"[1], _SLASH_Zm, Joined, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption | HelpHidden, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zo-"[1], _SLASH_Zo_, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zo"[1], _SLASH_Zo, Flag, cl_ignored_Group, INVALID, nullptr, CLOption | NoXarchOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_2, &"/Zp"[1], _SLASH_Zp_flag, Flag, cl_Group, fpack_struct_EQ, "1\0", CLOption | NoXarchOption | CLOption, 0,
       "Set default maximum struct packing alignment to 1", nullptr, nullptr)
OPTION(prefix_2, &"/Zp"[1], _SLASH_Zp, Joined, cl_Group, fpack_struct_EQ, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Set default maximum struct packing alignment", nullptr, nullptr)
OPTION(prefix_2, &"/Zs"[1], _SLASH_Zs, Flag, cl_Group, fsyntax_only, nullptr, CLOption | NoXarchOption | CLOption, 0,
       "Syntax-check only", nullptr, nullptr)
OPTION(prefix_2, &"/ZW"[1], _SLASH_ZW, Joined, cl_Group, INVALID, nullptr, CLOption | NoXarchOption | CLOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Z"[1], Z_Flag, Flag, Link_Group, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-Z"[1], Z_Joined, Joined, INVALID, INVALID, nullptr, 0, 0, nullptr, nullptr, nullptr)
OPTION(prefix_1, &"-z"[1], z, Separate, Link_Group, INVALID, nullptr, LinkerInput | RenderAsInput, 0,
       "Pass -z <arg> to the linker", "<arg>", nullptr)
OPTION(prefix_3, &"--"[2], _DASH_DASH, RemainingArgs, INVALID, INVALID, nullptr, NoXarchOption | CoreOption, 0, nullptr, nullptr, nullptr)
OPTION(prefix_3, &"--"[2], _, Joined, INVALID, INVALID, nullptr, Unsupported, 0, nullptr, nullptr, nullptr)
#endif // OPTION
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-arcmt-migrate-report-output"[1], arcmt_migrate_report_output, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Output path for the plist report", nullptr, nullptr, "-arcmt-migrate-report-output", true, 0, FrontendOpts.ARCMTMigrateReportOut, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-arcmt-migrate-emit-errors"[1], arcmt_migrate_emit_arc_errors, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Emit ARC errors even if the migrator can fix them", nullptr, nullptr, "-arcmt-migrate-emit-errors", true, 0, FrontendOpts.ARCMTMigrateEmitARCErrors, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-literals"[1], objcmt_migrate_literals, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC literals", nullptr, nullptr, "-objcmt-migrate-literals", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_Literals), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_Literals), FrontendOptions::ObjCMT_Literals>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-subscripting"[1], objcmt_migrate_subscripting, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC subscripting", nullptr, nullptr, "-objcmt-migrate-subscripting", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_Subscripting), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_Subscripting), FrontendOptions::ObjCMT_Subscripting>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-property"[1], objcmt_migrate_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC property", nullptr, nullptr, "-objcmt-migrate-property", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_Property), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_Property), FrontendOptions::ObjCMT_Property>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-all"[1], objcmt_migrate_all, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC", nullptr, nullptr, "-objcmt-migrate-all", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_MigrateDecls), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_MigrateDecls), FrontendOptions::ObjCMT_MigrateDecls>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-readonly-property"[1], objcmt_migrate_readonly_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC readonly property", nullptr, nullptr, "-objcmt-migrate-readonly-property", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_ReadonlyProperty), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_ReadonlyProperty), FrontendOptions::ObjCMT_ReadonlyProperty>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-readwrite-property"[1], objcmt_migrate_readwrite_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to modern ObjC readwrite property", nullptr, nullptr, "-objcmt-migrate-readwrite-property", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_ReadwriteProperty), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_ReadwriteProperty), FrontendOptions::ObjCMT_ReadwriteProperty>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-property-dot-syntax"[1], objcmt_migrate_property_dot_syntax, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration of setter/getter messages to property-dot syntax", nullptr, nullptr, "-objcmt-migrate-property-dot-syntax", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_PropertyDotSyntax), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_PropertyDotSyntax), FrontendOptions::ObjCMT_PropertyDotSyntax>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-annotation"[1], objcmt_migrate_annotation, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to property and method annotations", nullptr, nullptr, "-objcmt-migrate-annotation", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_Annotation), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_Annotation), FrontendOptions::ObjCMT_Annotation>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-instancetype"[1], objcmt_migrate_instancetype, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to infer instancetype for method result type", nullptr, nullptr, "-objcmt-migrate-instancetype", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_Instancetype), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_Instancetype), FrontendOptions::ObjCMT_Instancetype>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-ns-macros"[1], objcmt_migrate_nsmacros, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to NS_ENUM/NS_OPTIONS macros", nullptr, nullptr, "-objcmt-migrate-ns-macros", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_NsMacros), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_NsMacros), FrontendOptions::ObjCMT_NsMacros>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-protocol-conformance"[1], objcmt_migrate_protocol_conformance, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to add protocol conformance on classes", nullptr, nullptr, "-objcmt-migrate-protocol-conformance", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_ProtocolConformance), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_ProtocolConformance), FrontendOptions::ObjCMT_ProtocolConformance>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-atomic-property"[1], objcmt_atomic_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Make migration to 'atomic' properties", nullptr, nullptr, "-objcmt-atomic-property", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_AtomicProperty), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_AtomicProperty), FrontendOptions::ObjCMT_AtomicProperty>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-returns-innerpointer-property"[1], objcmt_returns_innerpointer_property, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to annotate property with NS_RETURNS_INNER_POINTER", nullptr, nullptr, "-objcmt-returns-innerpointer-property", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_ReturnsInnerPointerProperty), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_ReturnsInnerPointerProperty), FrontendOptions::ObjCMT_ReturnsInnerPointerProperty>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-ns-nonatomic-iosonly"[1], objcmt_ns_nonatomic_iosonly, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to use NS_NONATOMIC_IOSONLY macro for setting property's 'atomic' attribute", nullptr, nullptr, "-objcmt-ns-nonatomic-iosonly", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_NsAtomicIOSOnlyProperty), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_NsAtomicIOSOnlyProperty), FrontendOptions::ObjCMT_NsAtomicIOSOnlyProperty>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-migrate-designated-init"[1], objcmt_migrate_designated_init, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable migration to infer NS_DESIGNATED_INITIALIZER for initializer methods", nullptr, nullptr, "-objcmt-migrate-designated-init", true, 0, FrontendOpts.ObjCMTAction, 0u, false, 0u, makeFlagToValueNormalizer(FrontendOptions::ObjCMT_DesignatedInitializer), denormalizeSimpleFlag, mergeMaskValue, (extractMaskValue<unsigned, decltype(FrontendOptions::ObjCMT_DesignatedInitializer), FrontendOptions::ObjCMT_DesignatedInitializer>), -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-objcmt-allowlist-dir-path="[1], objcmt_allowlist_dir_path, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "Only modify files with a filename contained in the provided directory path", nullptr, nullptr, "-objcmt-allowlist-dir-path=", true, 0, FrontendOpts.ObjCMTAllowListPath, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-CC"[1], CC, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option, 0,
       "Include comments from within macros in preprocessed output", nullptr, nullptr, "-CC", true, 0, PreprocessorOutputOpts.ShowMacroComments, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-C"[1], C, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option, 0,
       "Include comments in preprocessed output", nullptr, nullptr, "-C", true, 0, PreprocessorOutputOpts.ShowComments, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-H"[1], H, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option, 0,
       "Show header includes and nesting depth", nullptr, nullptr, "-H", true, 0, DependencyOutputOpts.ShowHeaderIncludes, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-fshow-skipped-includes"[1], fshow_skipped_includes, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Show skipped includes in -H output.", nullptr, nullptr, "-fshow-skipped-includes", true, 0, DependencyOutputOpts.ShowSkippedHeaderIncludes, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-MG"[1], MG, Flag, M_Group, INVALID, nullptr, CC1Option, 0,
       "Add missing headers to depfile", nullptr, nullptr, "-MG", true, 0, DependencyOutputOpts.AddMissingHeaderDeps, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-MP"[1], MP, Flag, M_Group, INVALID, nullptr, CC1Option, 0,
       "Create phony target for each dependency (other than main file)", nullptr, nullptr, "-MP", true, 0, DependencyOutputOpts.UsePhonyTargets, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-MT"[1], MT, JoinedOrSeparate, M_Group, INVALID, nullptr, CC1Option, 0,
       "Specify name of main file output in depfile", nullptr, nullptr, "-MT", true, 0, DependencyOutputOpts.Targets, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-MV"[1], MV, Flag, M_Group, INVALID, nullptr, CC1Option, 0,
       "Use NMake/Jom format for the depfile", nullptr, nullptr, "-MV", true, 0, DependencyOutputOpts.OutputFormat, DependencyOutputFormat::Make, false, DependencyOutputFormat::Make, makeFlagToValueNormalizer(DependencyOutputFormat::NMake), denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-P"[1], P, Flag, Preprocessor_Group, INVALID, nullptr, CC1Option | FlangOption | FC1Option, 0,
       "Disable linemarker output in -E mode", nullptr, nullptr, "-P", true, 0, PreprocessorOutputOpts.ShowLineMarkers, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-Wundef-prefix="[1], Wundef_prefix_EQ, CommaJoined, W_value_Group, INVALID, nullptr, CC1Option | CoreOption | HelpHidden, 0,
       "Enable warnings for undefined macros with a prefix in the comma separated list <arg>", "<arg>", nullptr, "-Wundef-prefix=", true, 0, DiagnosticOpts->UndefPrefixes, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-single-precision-constant"[1], cl_single_precision_constant, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Treat double precision floating-point constant as single precision constant.", nullptr, nullptr, "-cl-single-precision-constant", true, 0, LangOpts->SinglePrecisionConstants, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-finite-math-only"[1], cl_finite_math_only, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow floating-point optimizations that assume arguments and results are not NaNs or +-Inf.", nullptr, nullptr, "-cl-finite-math-only", true, 0, LangOpts->CLFiniteMathOnly, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-kernel-arg-info"[1], cl_kernel_arg_info, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Generate kernel argument metadata.", nullptr, nullptr, "-cl-kernel-arg-info", true, 0, CodeGenOpts.EmitOpenCLArgMetadata, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-unsafe-math-optimizations"[1], cl_unsafe_math_optimizations, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow unsafe floating-point optimizations.  Also implies -cl-no-signed-zeros and -cl-mad-enable.", nullptr, nullptr, "-cl-unsafe-math-optimizations", true, 0, LangOpts->CLUnsafeMath, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-fast-relaxed-math"[1], cl_fast_relaxed_math, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Sets -cl-finite-math-only and -cl-unsafe-math-optimizations, and defines __FAST_RELAXED_MATH__.", nullptr, nullptr, "-cl-fast-relaxed-math", true, 0, LangOpts->FastRelaxedMath, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-mad-enable"[1], cl_mad_enable, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow use of less precise MAD computations in the generated binary.", nullptr, nullptr, "-cl-mad-enable", true, 0, CodeGenOpts.LessPreciseFPMAD, false, false || LangOpts->CLUnsafeMath || LangOpts->FastRelaxedMath, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-no-signed-zeros"[1], cl_no_signed_zeros, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Allow use of less precise no signed zeros computations in the generated binary.", nullptr, nullptr, "-cl-no-signed-zeros", true, 0, LangOpts->CLNoSignedZero, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-fp32-correctly-rounded-divide-sqrt"[1], cl_fp32_correctly_rounded_divide_sqrt, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Specify that single precision floating-point divide and sqrt used in the program source are correctly rounded.", nullptr, nullptr, "-cl-fp32-correctly-rounded-divide-sqrt", true, 0, CodeGenOpts.OpenCLCorrectlyRoundedDivSqrt, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-uniform-work-group-size"[1], cl_uniform_work_group_size, Flag, opencl_Group, INVALID, nullptr, CC1Option, 0,
       "OpenCL only. Defines that the global work-size be a multiple of the work-group size specified to clEnqueueNDRangeKernel", nullptr, nullptr, "-cl-uniform-work-group-size", true, 0, CodeGenOpts.UniformWGSize, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fgpu-rdc"[1], fgpu_rdc, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate relocatable device code, also known as separate compilation mode", nullptr, nullptr, "-fgpu-rdc", true, 0, LangOpts->GPURelocatableDeviceCode, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_gpu_rdc), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-gpu-rdc"[1], fno_gpu_rdc, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-gpu-rdc", true, 0, LangOpts->GPURelocatableDeviceCode, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fgpu_rdc), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-fcuda-short-ptr"[1], fcuda_short_ptr, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use 32-bit pointers for accessing const/local/shared address spaces", nullptr, nullptr, "-fcuda-short-ptr", true, 0, TargetOpts->NVPTXUseShortPointers, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_cuda_short_ptr), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-cuda-short-ptr"[1], fno_cuda_short_ptr, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-cuda-short-ptr", true, 0, TargetOpts->NVPTXUseShortPointers, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fcuda_short_ptr), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fhip-new-launch-api"[1], fhip_new_launch_api, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use new kernel launching API for HIP", nullptr, nullptr, "-fhip-new-launch-api", true, 0, LangOpts->HIPUseNewLaunchAPI, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_hip_new_launch_api), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-hip-new-launch-api"[1], fno_hip_new_launch_api, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't use new kernel launching API for HIP", nullptr, nullptr, "-fno-hip-new-launch-api", true, 0, LangOpts->HIPUseNewLaunchAPI, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fhip_new_launch_api), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fhip-fp32-correctly-rounded-divide-sqrt"[1], fhip_fp32_correctly_rounded_divide_sqrt, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Specify that single precision floating-point divide and sqrt used in the program source are correctly rounded (HIP device compilation only)", nullptr, nullptr, "-fhip-fp32-correctly-rounded-divide-sqrt", LangOpts->HIP, 0, CodeGenOpts.HIPCorrectlyRoundedDivSqrt, true, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_hip_fp32_correctly_rounded_divide_sqrt), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-hip-fp32-correctly-rounded-divide-sqrt"[1], fno_hip_fp32_correctly_rounded_divide_sqrt, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't specify that single precision floating-point divide and sqrt used in the program source are correctly rounded (HIP device compilation only)", nullptr, nullptr, "-fno-hip-fp32-correctly-rounded-divide-sqrt", LangOpts->HIP, 0, CodeGenOpts.HIPCorrectlyRoundedDivSqrt, true, false, false, makeBooleanOptionNormalizer(false, true, OPT_fhip_fp32_correctly_rounded_divide_sqrt), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fgpu-allow-device-init"[1], fgpu_allow_device_init, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow device side init function in HIP (experimental)", nullptr, nullptr, "-fgpu-allow-device-init", LangOpts->HIP, 0, LangOpts->GPUAllowDeviceInit, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_gpu_allow_device_init), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-gpu-allow-device-init"[1], fno_gpu_allow_device_init, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't allow device side init function in HIP (experimental)", nullptr, nullptr, "-fno-gpu-allow-device-init", LangOpts->HIP, 0, LangOpts->GPUAllowDeviceInit, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fgpu_allow_device_init), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fgpu-defer-diag"[1], fgpu_defer_diag, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Defer host/device related diagnostic messages for CUDA/HIP", nullptr, nullptr, "-fgpu-defer-diag", true, 0, LangOpts->GPUDeferDiag, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_gpu_defer_diag), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-gpu-defer-diag"[1], fno_gpu_defer_diag, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't defer host/device related diagnostic messages for CUDA/HIP", nullptr, nullptr, "-fno-gpu-defer-diag", true, 0, LangOpts->GPUDeferDiag, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fgpu_defer_diag), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fgpu-exclude-wrong-side-overloads"[1], fgpu_exclude_wrong_side_overloads, Flag, f_Group, INVALID, nullptr, CC1Option | HelpHidden, 0,
       "Always exclude wrong side overloads in overloading resolution for CUDA/HIP", nullptr, nullptr, "-fgpu-exclude-wrong-side-overloads", true, 0, LangOpts->GPUExcludeWrongSideOverloads, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_gpu_exclude_wrong_side_overloads), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-gpu-exclude-wrong-side-overloads"[1], fno_gpu_exclude_wrong_side_overloads, Flag, f_Group, INVALID, nullptr, HelpHidden, 0,
       "Exclude wrong side overloads only if there are same side overloads in overloading resolution for CUDA/HIP", nullptr, nullptr, "-fno-gpu-exclude-wrong-side-overloads", true, 0, LangOpts->GPUExcludeWrongSideOverloads, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fgpu_exclude_wrong_side_overloads), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_3, &"--gpu-max-threads-per-block="[2], gpu_max_threads_per_block_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "Default max threads per block for kernel launch bounds for HIP", nullptr, nullptr, "--gpu-max-threads-per-block=", LangOpts->HIP, 0, LangOpts->GPUMaxThreadsPerBlock, 1024, false, 1024, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-cuid="[1], cuid_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0,
       "An ID for compilation unit, which should be the same for the same compilation unit but different for different compilation units. It is used to externalize device-side static variables for single source offloading languages CUDA and HIP so that they can be accessed by the host code of the same compilation unit.", nullptr, nullptr, "-cuid=", true, 0, LangOpts->CUID, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-dI"[1], dI, Flag, d_Group, INVALID, nullptr, CC1Option, 0,
       "Print include directives in -E mode in addition to normal output", nullptr, nullptr, "-dI", true, 0, PreprocessorOutputOpts.ShowIncludeDirectives, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-dependency-file"[1], dependency_file, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Filename (or -) to write dependency output to", nullptr, nullptr, "-dependency-file", true, 0, DependencyOutputOpts.OutputFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-dependency-dot"[1], dependency_dot, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Filename to write DOT-formatted header dependencies to", nullptr, nullptr, "-dependency-dot", true, 0, DependencyOutputOpts.DOTOutputFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-module-dependency-dir"[1], module_dependency_dir, Separate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Directory to dump module dependencies to", nullptr, nullptr, "-module-dependency-dir", true, 0, DependencyOutputOpts.ModuleDependencyOutputDir, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmax-tokens="[1], fmax_tokens_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Max total number of preprocessed tokens for -Wmax-tokens.", nullptr, nullptr, "-fmax-tokens=", true, 0, LangOpts->MaxTokens, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-access-control"[1], fno_access_control, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ access control", nullptr, nullptr, "-fno-access-control", true, 0, LangOpts->AccessControl, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_faccess_control), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-faccess-control"[1], faccess_control, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-faccess-control", true, 0, LangOpts->AccessControl, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_access_control), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-falign-loops="[1], falign_loops_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "N must be a power of two. Align loops to the boundary", "<N>", nullptr, "-falign-loops=", true, 0, CodeGenOpts.LoopAlignment, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fallow-editor-placeholders"[1], fallow_editor_placeholders, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Treat editor placeholders as valid source code", nullptr, nullptr, "-fallow-editor-placeholders", true, 0, LangOpts->AllowEditorPlaceholders, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_allow_editor_placeholders), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-allow-editor-placeholders"[1], fno_allow_editor_placeholders, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-allow-editor-placeholders", true, 0, LangOpts->AllowEditorPlaceholders, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fallow_editor_placeholders), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fapple-kext"[1], fapple_kext, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use Apple's kernel extensions ABI", nullptr, nullptr, "-fapple-kext", true, 0, LangOpts->AppleKext, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fapple-pragma-pack"[1], fapple_pragma_pack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable Apple gcc-compatible #pragma pack handling", nullptr, nullptr, "-fapple-pragma-pack", true, 0, LangOpts->ApplePragmaPack, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_apple_pragma_pack), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-apple-pragma-pack"[1], fno_apple_pragma_pack, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-apple-pragma-pack", true, 0, LangOpts->ApplePragmaPack, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fapple_pragma_pack), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fxl-pragma-pack"[1], fxl_pragma_pack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable IBM XL #pragma pack handling", nullptr, nullptr, "-fxl-pragma-pack", true, 0, LangOpts->XLPragmaPack, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_xl_pragma_pack), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-xl-pragma-pack"[1], fno_xl_pragma_pack, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-xl-pragma-pack", true, 0, LangOpts->XLPragmaPack, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fxl_pragma_pack), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdouble-square-bracket-attributes"[1], fdouble_square_bracket_attributes, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Enable '[[]]' attributes in all C and C++ language modes", nullptr, nullptr, "-fdouble-square-bracket-attributes", true, 0, LangOpts->DoubleSquareBracketAttributes, LangOpts->CPlusPlus11||LangOpts->C2x, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_double_square_bracket_attributes), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-double-square-bracket-attributes"[1], fno_double_square_bracket_attributes, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Disable '[[]]' attributes in all C and C++ language modes", nullptr, nullptr, "-fno-double-square-bracket-attributes", true, 0, LangOpts->DoubleSquareBracketAttributes, LangOpts->CPlusPlus11||LangOpts->C2x, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdouble_square_bracket_attributes), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-autolink"[1], fno_autolink, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of linker directives for automatic library linking", nullptr, nullptr, "-fno-autolink", true, 0, CodeGenOpts.Autolink, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fautolink), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fautolink"[1], fautolink, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fautolink", true, 0, CodeGenOpts.Autolink, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_autolink), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcoroutines-ts"[1], fcoroutines_ts, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for the C++ Coroutines TS", nullptr, nullptr, "-fcoroutines-ts", true, 0, LangOpts->Coroutines, LangOpts->CPlusPlus20, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_coroutines_ts), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-coroutines-ts"[1], fno_coroutines_ts, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-coroutines-ts", true, 0, LangOpts->Coroutines, LangOpts->CPlusPlus20, false, false, makeBooleanOptionNormalizer(false, true, OPT_fcoroutines_ts), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fembed-bitcode="[1], fembed_bitcode_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CC1AsOption, 0,
       "Embed LLVM bitcode (option: off, all, bitcode, marker)", "<option>", "off,all,bitcode,marker", "-fembed-bitcode=", true, 0, CodeGenOpts.EmbedBitcode, CodeGenOptions::Embed_Off, false, CodeGenOptions::Embed_Off, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 0)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-gnu-inline-asm"[1], fno_gnu_inline_asm, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable GNU style inline asm", nullptr, nullptr, "-fno-gnu-inline-asm", true, 0, LangOpts->GNUAsm, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fgnu_inline_asm), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fgnu-inline-asm"[1], fgnu_inline_asm, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fgnu-inline-asm", true, 0, LangOpts->GNUAsm, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_gnu_inline_asm), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-sample-use="[1], fprofile_sample_use_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Enable sample-based profile guided optimizations", nullptr, nullptr, "-fprofile-sample-use=", true, 0, CodeGenOpts.SampleProfileFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-sample-accurate"[1], fprofile_sample_accurate, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specifies that the sample profile is accurate", nullptr, nullptr, "-fprofile-sample-accurate", true, 0, CodeGenOpts.ProfileSampleAccurate, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdebug-compilation-dir="[1], fdebug_compilation_dir_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "The compilation directory to embed in the debug info", nullptr, nullptr, "-fdebug-compilation-dir=", true, 0, CodeGenOpts.DebugCompilationDir, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fcoverage-compilation-dir="[1], fcoverage_compilation_dir_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "The compilation directory to embed in the coverage mapping.", nullptr, nullptr, "-fcoverage-compilation-dir=", true, 0, CodeGenOpts.CoverageCompilationDir, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdebug-info-for-profiling"[1], fdebug_info_for_profiling, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Emit extra debug info to make sample profile more accurate", nullptr, nullptr, "-fdebug-info-for-profiling", true, 0, CodeGenOpts.DebugInfoForProfiling, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_debug_info_for_profiling), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-debug-info-for-profiling"[1], fno_debug_info_for_profiling, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-debug-info-for-profiling", true, 0, CodeGenOpts.DebugInfoForProfiling, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdebug_info_for_profiling), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-remapping-file="[1], fprofile_remapping_file_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Use the remappings described in <file> to match the profile data against names in the program", "<file>", nullptr, "-fprofile-remapping-file=", true, 0, CodeGenOpts.ProfileRemappingFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fcoverage-mapping"[1], fcoverage_mapping, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Generate coverage mapping to enable code coverage analysis", nullptr, nullptr, "-fcoverage-mapping", true, 0, CodeGenOpts.CoverageMapping, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_coverage_mapping), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-coverage-mapping"[1], fno_coverage_mapping, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Disable code coverage analysis", nullptr, nullptr, "-fno-coverage-mapping", true, 0, CodeGenOpts.CoverageMapping, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fcoverage_mapping), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-arcs"[1], fprofile_arcs, Flag, f_Group, INVALID, nullptr, CC1Option | LinkOption, 0,
       "", nullptr, nullptr, "-fprofile-arcs", true, 0, CodeGenOpts.EmitGcovArcs, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_profile_arcs), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-profile-arcs"[1], fno_profile_arcs, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-profile-arcs", true, 0, CodeGenOpts.EmitGcovArcs, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fprofile_arcs), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ftest-coverage"[1], ftest_coverage, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-ftest-coverage", true, 0, CodeGenOpts.EmitGcovNotes, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_test_coverage), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-test-coverage"[1], fno_test_coverage, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-test-coverage", true, 0, CodeGenOpts.EmitGcovNotes, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_ftest_coverage), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-filter-files="[1], fprofile_filter_files_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Instrument only functions from files where names match any regex separated by a semi-colon", nullptr, nullptr, "-fprofile-filter-files=", CodeGenOpts.EmitGcovArcs||CodeGenOpts.EmitGcovNotes, 0, CodeGenOpts.ProfileFilterFiles, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-exclude-files="[1], fprofile_exclude_files_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Instrument only functions from files where names don't match all the regexes separated by a semi-colon", nullptr, nullptr, "-fprofile-exclude-files=", CodeGenOpts.EmitGcovArcs||CodeGenOpts.EmitGcovNotes, 0, CodeGenOpts.ProfileExcludeFiles, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-update="[1], fprofile_update_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Set update method of profile counters (atomic,prefer-atomic,single)", "<method>", "atomic,prefer-atomic,single", "-fprofile-update=", true, 0, CodeGenOpts.AtomicProfileUpdate, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fpseudo-probe-for-profiling"[1], fpseudo_probe_for_profiling, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Emit pseudo probes for sample profiling", nullptr, nullptr, "-fpseudo-probe-for-profiling", true, 0, CodeGenOpts.PseudoProbeForProfiling, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_pseudo_probe_for_profiling), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-pseudo-probe-for-profiling"[1], fno_pseudo_probe_for_profiling, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Do not emit pseudo probes for sample profiling", nullptr, nullptr, "-fno-pseudo-probe-for-profiling", true, 0, CodeGenOpts.PseudoProbeForProfiling, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fpseudo_probe_for_profiling), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-list="[1], fprofile_list_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Filename defining the list of functions/files to instrument", nullptr, nullptr, "-fprofile-list=", true, 0, LangOpts->ProfileListFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fswift-async-fp="[1], fswift_async_fp_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Control emission of Swift async extended frame info (option: auto, always, never)", "<option>", "auto,always,never", "-fswift-async-fp=", true, 0, CodeGenOpts.SwiftAsyncFramePointer, CodeGenOptions::SwiftAsyncFramePointerKind::Always, false, CodeGenOptions::SwiftAsyncFramePointerKind::Always, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-faddrsig"[1], faddrsig, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Emit an address-significance table", nullptr, nullptr, "-faddrsig", true, 0, CodeGenOpts.Addrsig, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_addrsig), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-addrsig"[1], fno_addrsig, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Don't emit an address-significance table", nullptr, nullptr, "-fno-addrsig", true, 0, CodeGenOpts.Addrsig, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_faddrsig), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fborland-extensions"[1], fborland_extensions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Accept non-standard constructs supported by the Borland compiler", nullptr, nullptr, "-fborland-extensions", true, 0, LangOpts->Borland, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_borland_extensions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-borland-extensions"[1], fno_borland_extensions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-borland-extensions", true, 0, LangOpts->Borland, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fborland_extensions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-caret-diagnostics"[1], fno_caret_diagnostics, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-caret-diagnostics", true, 0, DiagnosticOpts->ShowCarets, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fcaret_diagnostics), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcaret-diagnostics"[1], fcaret_diagnostics, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fcaret-diagnostics", true, 0, DiagnosticOpts->ShowCarets, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_caret_diagnostics), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fansi-escape-codes"[1], fansi_escape_codes, Flag, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Use ANSI escape codes for diagnostics", nullptr, nullptr, "-fansi-escape-codes", true, 0, DiagnosticOpts->UseANSIEscapeCodes, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcomment-block-commands="[1], fcomment_block_commands, CommaJoined, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Treat each comma separated argument in <arg> as a documentation comment block command", "<arg>", nullptr, "-fcomment-block-commands=", true, 0, LangOpts->CommentOpts.BlockCommandNames, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fparse-all-comments"[1], fparse_all_comments, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-fparse-all-comments", true, 0, LangOpts->CommentOpts.ParseAllComments, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fcommon"[1], fcommon, Flag, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Place uninitialized global variables in a common block", nullptr, nullptr, "-fcommon", true, 0, CodeGenOpts.NoCommon, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcomplete-member-pointers"[1], fcomplete_member_pointers, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Require member pointer base types to be complete if they would be significant under the Microsoft ABI", nullptr, nullptr, "-fcomplete-member-pointers", true, 0, LangOpts->CompleteMemberPointers, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_complete_member_pointers), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-complete-member-pointers"[1], fno_complete_member_pointers, Flag, f_clang_Group, INVALID, nullptr, CoreOption, 0,
       "Do not require member pointer base types to be complete if they would be significant under the Microsoft ABI", nullptr, nullptr, "-fno-complete-member-pointers", true, 0, LangOpts->CompleteMemberPointers, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fcomplete_member_pointers), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcf-runtime-abi="[1], fcf_runtime_abi_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "unspecified,standalone,objc,swift,swift-5.0,swift-4.2,swift-4.1", "-fcf-runtime-abi=", true, 0, LangOpts->CFRuntime, LangOptions::CoreFoundationABI::ObjectiveC, false, LangOptions::CoreFoundationABI::ObjectiveC, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 2)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-constant-cfstrings"[1], fno_constant_cfstrings, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable creation of CodeFoundation-type constant strings", nullptr, nullptr, "-fno-constant-cfstrings", true, 0, LangOpts->NoConstantCFStrings, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fconstant_cfstrings), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fconstant-cfstrings"[1], fconstant_cfstrings, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fconstant-cfstrings", true, 0, LangOpts->NoConstantCFStrings, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_constant_cfstrings), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fexperimental-new-constant-interpreter"[1], fexperimental_new_constant_interpreter, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable the experimental new constant interpreter", nullptr, nullptr, "-fexperimental-new-constant-interpreter", true, 0, LangOpts->EnableNewConstInterp, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcxx-exceptions"[1], fcxx_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++ exceptions", nullptr, nullptr, "-fcxx-exceptions", true, 0, LangOpts->CXXExceptions, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_cxx_exceptions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-cxx-exceptions"[1], fno_cxx_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-cxx-exceptions", true, 0, LangOpts->CXXExceptions, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fcxx_exceptions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fasync-exceptions"[1], fasync_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable EH Asynchronous exceptions", nullptr, nullptr, "-fasync-exceptions", true, 0, LangOpts->EHAsynch, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_async_exceptions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-async-exceptions"[1], fno_async_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-async-exceptions", true, 0, LangOpts->EHAsynch, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fasync_exceptions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-cxx-modules"[1], fno_cxx_modules, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption, 0,
       "Disable modules for C++", nullptr, nullptr, "-fno-cxx-modules", LangOpts->CPlusPlus, 0, LangOpts->CPlusPlusModules, LangOpts->CPlusPlus20, false, true, makeBooleanOptionNormalizer(false, true, OPT_fcxx_modules), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcxx-modules"[1], fcxx_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Enable modules for C++", nullptr, nullptr, "-fcxx-modules", LangOpts->CPlusPlus, 0, LangOpts->CPlusPlusModules, LangOpts->CPlusPlus20, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_cxx_modules), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-diagnostics-fixit-info"[1], fno_diagnostics_fixit_info, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not include fixit information in diagnostics", nullptr, nullptr, "-fno-diagnostics-fixit-info", true, 0, DiagnosticOpts->ShowFixits, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-parseable-fixits"[1], fdiagnostics_parseable_fixits, Flag, f_clang_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Print fix-its in machine parseable form", nullptr, nullptr, "-fdiagnostics-parseable-fixits", true, 0, DiagnosticOpts->ShowParseableFixits, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-print-source-range-info"[1], fdiagnostics_print_source_range_info, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Print source range spans in numeric form", nullptr, nullptr, "-fdiagnostics-print-source-range-info", true, 0, DiagnosticOpts->ShowSourceRanges, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-show-hotness"[1], fdiagnostics_show_hotness, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable profile hotness information in diagnostic line", nullptr, nullptr, "-fdiagnostics-show-hotness", true, 0, CodeGenOpts.DiagnosticsWithHotness, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_diagnostics_show_hotness), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-diagnostics-show-hotness"[1], fno_diagnostics_show_hotness, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-diagnostics-show-hotness", true, 0, CodeGenOpts.DiagnosticsWithHotness, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdiagnostics_show_hotness), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-diagnostics-show-option"[1], fno_diagnostics_show_option, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-diagnostics-show-option", true, 0, DiagnosticOpts->ShowOptionNames, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fdiagnostics_show_option), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-show-option"[1], fdiagnostics_show_option, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Print option name with mappable diagnostics", nullptr, nullptr, "-fdiagnostics-show-option", true, 0, DiagnosticOpts->ShowOptionNames, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_diagnostics_show_option), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-show-note-include-stack"[1], fdiagnostics_show_note_include_stack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Display include stacks for diagnostic notes", nullptr, nullptr, "-fdiagnostics-show-note-include-stack", true, 0, DiagnosticOpts->ShowNoteIncludeStack, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_diagnostics_show_note_include_stack), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-diagnostics-show-note-include-stack"[1], fno_diagnostics_show_note_include_stack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-diagnostics-show-note-include-stack", true, 0, DiagnosticOpts->ShowNoteIncludeStack, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdiagnostics_show_note_include_stack), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-show-template-tree"[1], fdiagnostics_show_template_tree, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Print a template comparison tree for differing templates", nullptr, nullptr, "-fdiagnostics-show-template-tree", true, 0, DiagnosticOpts->ShowTemplateTree, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdollars-in-identifiers"[1], fdollars_in_identifiers, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow '$' in identifiers", nullptr, nullptr, "-fdollars-in-identifiers", true, 0, LangOpts->DollarIdents, !LangOpts->AsmPreprocessor, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_dollars_in_identifiers), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-dollars-in-identifiers"[1], fno_dollars_in_identifiers, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disallow '$' in identifiers", nullptr, nullptr, "-fno-dollars-in-identifiers", true, 0, LangOpts->DollarIdents, !LangOpts->AsmPreprocessor, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdollars_in_identifiers), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-dwarf-directory-asm"[1], fno_dwarf_directory_asm, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-dwarf-directory-asm", true, 0, CodeGenOpts.NoDwarfDirectoryAsm, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fdwarf_directory_asm), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdwarf-directory-asm"[1], fdwarf_directory_asm, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fdwarf-directory-asm", true, 0, CodeGenOpts.NoDwarfDirectoryAsm, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_dwarf_directory_asm), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-elide-constructors"[1], fno_elide_constructors, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ copy constructor elision", nullptr, nullptr, "-fno-elide-constructors", true, 0, LangOpts->ElideConstructors, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_felide_constructors), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-felide-constructors"[1], felide_constructors, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-felide-constructors", true, 0, LangOpts->ElideConstructors, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_elide_constructors), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-elide-type"[1], fno_elide_type, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not elide types when printing diagnostics", nullptr, nullptr, "-fno-elide-type", true, 0, DiagnosticOpts->ElideType, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-femit-all-decls"[1], femit_all_decls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Emit all declarations, even if unused", nullptr, nullptr, "-femit-all-decls", true, 0, LangOpts->EmitAllDecls, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-femulated-tls"[1], femulated_tls, Flag, f_Group, INVALID, nullptr, CC1Option | CC1Option, 0,
       "Use emutls functions to access thread_local variables", nullptr, nullptr, "-femulated-tls", true, 0, CodeGenOpts.EmulatedTLS, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_emulated_tls), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-emulated-tls"[1], fno_emulated_tls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-emulated-tls", true, 0, CodeGenOpts.EmulatedTLS, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_femulated_tls), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fexceptions"[1], fexceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for exception handling", nullptr, nullptr, "-fexceptions", true, 0, LangOpts->Exceptions, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_exceptions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-exceptions"[1], fno_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable support for exception handling", nullptr, nullptr, "-fno-exceptions", true, 0, LangOpts->Exceptions, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fexceptions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-exception-model"[1], exception_model, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The exception model: dwarf|sjlj|seh|wasm", nullptr, "dwarf,sjlj,seh,wasm", "-exception-model", true, 0, LangOpts->ExceptionHandling, LangOptions::ExceptionHandlingKind::None, false, LangOptions::ExceptionHandlingKind::None, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 3)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fignore-exceptions"[1], fignore_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for ignoring exception handling constructs", nullptr, nullptr, "-fignore-exceptions", true, 0, LangOpts->IgnoreExceptions, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ffp-exception-behavior="[1], ffp_exception_behavior_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specifies the exception behavior of floating-point operations.", nullptr, "ignore,maytrap,strict", "-ffp-exception-behavior=", true, 0, LangOpts->FPExceptionMode, LangOptions::FPE_Ignore, false, LangOptions::FPE_Ignore, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 4)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ffast-math"[1], ffast_math, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow aggressive, lossy floating-point optimizations", nullptr, nullptr, "-ffast-math", true, 0, LangOpts->FastMath, false, false || LangOpts->FastRelaxedMath, true, makeBooleanOptionNormalizer(true, false, OPT_fno_fast_math), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-fast-math"[1], fno_fast_math, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-fast-math", true, 0, LangOpts->FastMath, false, false || LangOpts->FastRelaxedMath, true, makeBooleanOptionNormalizer(false, true, OPT_ffast_math), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-menable-unsafe-fp-math"[1], menable_unsafe_fp_math, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Allow unsafe floating-point math optimizations which may decrease precision", nullptr, nullptr, "-menable-unsafe-fp-math", true, 0, LangOpts->UnsafeFPMath, false, false || LangOpts->CLUnsafeMath || LangOpts->FastMath, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmath-errno"[1], fmath_errno, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Require math functions to indicate errors by setting errno", nullptr, nullptr, "-fmath-errno", !LangOpts->OpenCL, 0, LangOpts->MathErrno, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_math_errno), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-math-errno"[1], fno_math_errno, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-math-errno", !LangOpts->OpenCL, 0, LangOpts->MathErrno, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fmath_errno), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fextend-arguments="[1], fextend_args_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Controls how scalar integer arguments are extended in calls to unprototyped and varargs functions", nullptr, "32,64", "-fextend-arguments=", true, 0, LangOpts->ExtendIntArgs, LangOptions::ExtendArgsKind::ExtendTo32, false, LangOptions::ExtendArgsKind::ExtendTo32, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 5)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-jump-tables"[1], fno_jump_tables, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not use jump tables for lowering switches", nullptr, nullptr, "-fno-jump-tables", true, 0, CodeGenOpts.NoUseJumpTables, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fjump_tables), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fjump-tables"[1], fjump_tables, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Use jump tables for lowering switches", nullptr, nullptr, "-fjump-tables", true, 0, CodeGenOpts.NoUseJumpTables, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_jump_tables), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-fforce-enable-int128"[1], fforce_enable_int128, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for int128_t type", nullptr, nullptr, "-fforce-enable-int128", true, 0, TargetOpts->ForceEnableInt128, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_force_enable_int128), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-force-enable-int128"[1], fno_force_enable_int128, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable support for int128_t type", nullptr, nullptr, "-fno-force-enable-int128", true, 0, TargetOpts->ForceEnableInt128, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fforce_enable_int128), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fkeep-static-consts"[1], fkeep_static_consts, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption, 0,
       "Keep static const variables if unused", nullptr, nullptr, "-fkeep-static-consts", true, 0, CodeGenOpts.KeepStaticConsts, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_keep_static_consts), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-keep-static-consts"[1], fno_keep_static_consts, Flag, f_Group, INVALID, nullptr, NoXarchOption, 0,
       "Don't keep static const variables if unused", nullptr, nullptr, "-fno-keep-static-consts", true, 0, CodeGenOpts.KeepStaticConsts, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fkeep_static_consts), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ffixed-point"[1], ffixed_point, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable fixed point types", nullptr, nullptr, "-ffixed-point", !LangOpts->CPlusPlus, 0, LangOpts->FixedPoint, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_fixed_point), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-fixed-point"[1], fno_fixed_point, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable fixed point types", nullptr, nullptr, "-fno-fixed-point", !LangOpts->CPlusPlus, 0, LangOpts->FixedPoint, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_ffixed_point), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-c++-static-destructors"[1], fno_cxx_static_destructors, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ static destructor registration", nullptr, nullptr, "-fno-c++-static-destructors", true, 0, LangOpts->RegisterStaticDestructors, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fcxx_static_destructors), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fc++-static-destructors"[1], fcxx_static_destructors, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fc++-static-destructors", true, 0, LangOpts->RegisterStaticDestructors, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_cxx_static_destructors), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsymbol-partition="[1], fsymbol_partition_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-fsymbol-partition=", true, 0, CodeGenOpts.SymbolPartition, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-allowlist="[1], fsanitize_coverage_allowlist, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Restrict sanitizer coverage instrumentation exclusively to modules and functions that match the provided special case list, except the blocked ones", nullptr, nullptr, "-fsanitize-coverage-allowlist=", true, 0, CodeGenOpts.SanitizeCoverageAllowlistFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-ignorelist="[1], fsanitize_coverage_ignorelist, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable sanitizer coverage instrumentation for modules and functions that match the provided special case list, even the allowed ones", nullptr, nullptr, "-fsanitize-coverage-ignorelist=", true, 0, CodeGenOpts.SanitizeCoverageIgnorelistFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-memory-track-origins="[1], fsanitize_memory_track_origins_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable origins tracking in MemorySanitizer", nullptr, nullptr, "-fsanitize-memory-track-origins=", true, 0, CodeGenOpts.SanitizeMemoryTrackOrigins, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-memory-use-after-dtor"[1], fsanitize_memory_use_after_dtor, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable use-after-destroy detection in MemorySanitizer", nullptr, nullptr, "-fsanitize-memory-use-after-dtor", true, 0, CodeGenOpts.SanitizeMemoryUseAfterDtor, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_memory_use_after_dtor), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-memory-use-after-dtor"[1], fno_sanitize_memory_use_after_dtor, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable use-after-destroy detection in MemorySanitizer", nullptr, nullptr, "-fno-sanitize-memory-use-after-dtor", true, 0, CodeGenOpts.SanitizeMemoryUseAfterDtor, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_memory_use_after_dtor), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-address-field-padding="[1], fsanitize_address_field_padding, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Level of field padding for AddressSanitizer", nullptr, nullptr, "-fsanitize-address-field-padding=", true, 0, LangOpts->SanitizeAddressFieldPadding, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-address-use-after-scope"[1], fsanitize_address_use_after_scope, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable use-after-scope detection in AddressSanitizer", nullptr, nullptr, "-fsanitize-address-use-after-scope", true, 0, CodeGenOpts.SanitizeAddressUseAfterScope, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_address_use_after_scope), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-address-use-after-scope"[1], fno_sanitize_address_use_after_scope, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable use-after-scope detection in AddressSanitizer", nullptr, nullptr, "-fno-sanitize-address-use-after-scope", true, 0, CodeGenOpts.SanitizeAddressUseAfterScope, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_address_use_after_scope), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-address-use-after-return="[1], sanitize_address_use_after_return_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Select the mode of detecting stack use-after-return in AddressSanitizer: never | runtime (default) | always", "<mode>", "never,runtime,always", "-fsanitize-address-use-after-return=", true, 0, CodeGenOpts.SanitizeAddressUseAfterReturn, llvm::AsanDetectStackUseAfterReturnMode::Runtime, false, llvm::AsanDetectStackUseAfterReturnMode::Runtime, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 6)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-address-poison-custom-array-cookie"[1], fsanitize_address_poison_custom_array_cookie, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable poisoning array cookies when using custom operator new[] in AddressSanitizer", nullptr, nullptr, "-fsanitize-address-poison-custom-array-cookie", true, 0, CodeGenOpts.SanitizeAddressPoisonCustomArrayCookie, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_address_poison_custom_array_cookie), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-address-poison-custom-array-cookie"[1], fno_sanitize_address_poison_custom_array_cookie, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable poisoning array cookies when using custom operator new[] in AddressSanitizer", nullptr, nullptr, "-fno-sanitize-address-poison-custom-array-cookie", true, 0, CodeGenOpts.SanitizeAddressPoisonCustomArrayCookie, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_address_poison_custom_array_cookie), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-address-globals-dead-stripping"[1], fsanitize_address_globals_dead_stripping, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable linker dead stripping of globals in AddressSanitizer", nullptr, nullptr, "-fsanitize-address-globals-dead-stripping", true, 0, CodeGenOpts.SanitizeAddressGlobalsDeadStripping, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-address-use-odr-indicator"[1], fsanitize_address_use_odr_indicator, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable ODR indicator globals to avoid false ODR violation reports in partially sanitized programs at the cost of an increase in binary size", nullptr, nullptr, "-fsanitize-address-use-odr-indicator", true, 0, CodeGenOpts.SanitizeAddressUseOdrIndicator, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_address_use_odr_indicator), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-address-use-odr-indicator"[1], fno_sanitize_address_use_odr_indicator, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable ODR indicator globals", nullptr, nullptr, "-fno-sanitize-address-use-odr-indicator", true, 0, CodeGenOpts.SanitizeAddressUseOdrIndicator, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_address_use_odr_indicator), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-address-destructor="[1], sanitize_address_destructor_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Set destructor type used in ASan instrumentation", nullptr, "none,global", "-fsanitize-address-destructor=", true, 0, CodeGenOpts.SanitizeAddressDtor, llvm::AsanDtorKind::Global, false, llvm::AsanDtorKind::Global, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 7)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-minimal-runtime"[1], fsanitize_minimal_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr, "-fsanitize-minimal-runtime", true, 0, CodeGenOpts.SanitizeMinimalRuntime, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_minimal_runtime), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-minimal-runtime"[1], fno_sanitize_minimal_runtime, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr, "-fno-sanitize-minimal-runtime", true, 0, CodeGenOpts.SanitizeMinimalRuntime, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_minimal_runtime), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-cfi-cross-dso"[1], fsanitize_cfi_cross_dso, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable control flow integrity (CFI) checks for cross-DSO calls.", nullptr, nullptr, "-fsanitize-cfi-cross-dso", true, 0, CodeGenOpts.SanitizeCfiCrossDso, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_cfi_cross_dso), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-cfi-cross-dso"[1], fno_sanitize_cfi_cross_dso, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable control flow integrity (CFI) checks for cross-DSO calls.", nullptr, nullptr, "-fno-sanitize-cfi-cross-dso", true, 0, CodeGenOpts.SanitizeCfiCrossDso, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_cfi_cross_dso), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-cfi-icall-generalize-pointers"[1], fsanitize_cfi_icall_generalize_pointers, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Generalize pointers in CFI indirect call type signature checks", nullptr, nullptr, "-fsanitize-cfi-icall-generalize-pointers", true, 0, CodeGenOpts.SanitizeCfiICallGeneralizePointers, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-cfi-canonical-jump-tables"[1], fsanitize_cfi_canonical_jump_tables, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Make the jump table addresses canonical in the symbol table", nullptr, nullptr, "-fsanitize-cfi-canonical-jump-tables", true, 0, CodeGenOpts.SanitizeCfiCanonicalJumpTables, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_cfi_canonical_jump_tables), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-cfi-canonical-jump-tables"[1], fno_sanitize_cfi_canonical_jump_tables, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Do not make the jump table addresses canonical in the symbol table", nullptr, nullptr, "-fno-sanitize-cfi-canonical-jump-tables", true, 0, CodeGenOpts.SanitizeCfiCanonicalJumpTables, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_cfi_canonical_jump_tables), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-stats"[1], fsanitize_stats, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable sanitizer statistics gathering.", nullptr, nullptr, "-fsanitize-stats", true, 0, CodeGenOpts.SanitizeStats, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sanitize_stats), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sanitize-stats"[1], fno_sanitize_stats, Flag, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable sanitizer statistics gathering.", nullptr, nullptr, "-fno-sanitize-stats", true, 0, CodeGenOpts.SanitizeStats, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsanitize_stats), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-undefined-strip-path-components="[1], fsanitize_undefined_strip_path_components_EQ, Joined, f_clang_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Strip (or keep only, if negative) a given number of path components when emitting check metadata.", "<number>", nullptr, "-fsanitize-undefined-strip-path-components=", true, 0, CodeGenOpts.EmitCheckPathComponentsToStrip, 0, false, 0, normalizeStringIntegral<int>, denormalizeString<int>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-freciprocal-math"[1], freciprocal_math, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow division operations to be reassociated", nullptr, nullptr, "-freciprocal-math", true, 0, LangOpts->AllowRecip, false, false || LangOpts->UnsafeFPMath, true, makeBooleanOptionNormalizer(true, false, OPT_fno_reciprocal_math), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-reciprocal-math"[1], fno_reciprocal_math, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-reciprocal-math", true, 0, LangOpts->AllowRecip, false, false || LangOpts->UnsafeFPMath, true, makeBooleanOptionNormalizer(false, true, OPT_freciprocal_math), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fapprox-func"[1], fapprox_func, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow certain math function calls to be replaced with an approximately equivalent calculation", nullptr, nullptr, "-fapprox-func", true, 0, LangOpts->ApproxFunc, false, false || LangOpts->UnsafeFPMath, true, makeBooleanOptionNormalizer(true, false, OPT_fno_approx_func), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-approx-func"[1], fno_approx_func, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-approx-func", true, 0, LangOpts->ApproxFunc, false, false || LangOpts->UnsafeFPMath, true, makeBooleanOptionNormalizer(false, true, OPT_fapprox_func), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ffinite-math-only"[1], ffinite_math_only, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-ffinite-math-only", true, 0, LangOpts->FiniteMathOnly, false, false || LangOpts->CLFiniteMathOnly || LangOpts->FastMath, true, makeBooleanOptionNormalizer(true, false, OPT_fno_finite_math_only), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-finite-math-only"[1], fno_finite_math_only, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-finite-math-only", true, 0, LangOpts->FiniteMathOnly, false, false || LangOpts->CLFiniteMathOnly || LangOpts->FastMath, true, makeBooleanOptionNormalizer(false, true, OPT_ffinite_math_only), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-signed-zeros"[1], fno_signed_zeros, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow optimizations that ignore the sign of floating point zeros", nullptr, nullptr, "-fno-signed-zeros", true, 0, LangOpts->NoSignedZero, false, false || LangOpts->CLNoSignedZero || LangOpts->UnsafeFPMath, true, makeBooleanOptionNormalizer(true, false, OPT_fsigned_zeros), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsigned-zeros"[1], fsigned_zeros, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fsigned-zeros", true, 0, LangOpts->NoSignedZero, false, false || LangOpts->CLNoSignedZero || LangOpts->UnsafeFPMath, true, makeBooleanOptionNormalizer(false, true, OPT_fno_signed_zeros), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-frounding-math"[1], frounding_math, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-frounding-math", true, 0, LangOpts->FPRoundingMode, llvm::RoundingMode::NearestTiesToEven, false, llvm::RoundingMode::NearestTiesToEven, makeFlagToValueNormalizer(llvm::RoundingMode::Dynamic), denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-strict-float-cast-overflow"[1], fno_strict_float_cast_overflow, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Relax language rules and try to match the behavior of the target's native float-to-int conversion instructions", nullptr, nullptr, "-fno-strict-float-cast-overflow", true, 0, CodeGenOpts.StrictFloatCastOverflow, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fstrict_float_cast_overflow), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fstrict-float-cast-overflow"[1], fstrict_float_cast_overflow, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Assume that overflowing float-to-int casts are undefined (default)", nullptr, nullptr, "-fstrict-float-cast-overflow", true, 0, CodeGenOpts.StrictFloatCastOverflow, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_strict_float_cast_overflow), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fprotect-parens"[1], fprotect_parens, Flag, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Determines whether the optimizer honors parentheses when floating-point expressions are evaluated", nullptr, nullptr, "-fprotect-parens", true, 0, LangOpts->ProtectParens, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_protect_parens), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-protect-parens"[1], fno_protect_parens, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-protect-parens", true, 0, LangOpts->ProtectParens, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fprotect_parens), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-frewrite-imports"[1], frewrite_imports, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-frewrite-imports", true, 0, PreprocessorOutputOpts.RewriteImports, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_rewrite_imports), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-rewrite-imports"[1], fno_rewrite_imports, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-rewrite-imports", true, 0, PreprocessorOutputOpts.RewriteImports, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_frewrite_imports), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-frewrite-includes"[1], frewrite_includes, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-frewrite-includes", true, 0, PreprocessorOutputOpts.RewriteIncludes, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_rewrite_includes), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-rewrite-includes"[1], fno_rewrite_includes, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-rewrite-includes", true, 0, PreprocessorOutputOpts.RewriteIncludes, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_frewrite_includes), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-delete-null-pointer-checks"[1], fno_delete_null_pointer_checks, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Do not treat usage of null pointers as undefined behavior", nullptr, nullptr, "-fno-delete-null-pointer-checks", true, 0, CodeGenOpts.NullPointerIsValid, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fdelete_null_pointer_checks), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdelete-null-pointer-checks"[1], fdelete_null_pointer_checks, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "Treat usage of null pointers as undefined behavior (default)", nullptr, nullptr, "-fdelete-null-pointer-checks", true, 0, CodeGenOpts.NullPointerIsValid, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_delete_null_pointer_checks), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-frewrite-map-file="[1], frewrite_map_file_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0, nullptr, nullptr, nullptr, "-frewrite-map-file=", true, 0, CodeGenOpts.RewriteMapFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-fuse-line-directives"[1], fuse_line_directives, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use #line in preprocessed output", nullptr, nullptr, "-fuse-line-directives", true, 0, PreprocessorOutputOpts.UseLineDirectives, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_use_line_directives), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-use-line-directives"[1], fno_use_line_directives, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-use-line-directives", true, 0, PreprocessorOutputOpts.UseLineDirectives, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fuse_line_directives), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-fminimize-whitespace"[1], fminimize_whitespace, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Minimize whitespace when emitting preprocessor output", nullptr, nullptr, "-fminimize-whitespace", true, 0, PreprocessorOutputOpts.MinimizeWhitespace, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_minimize_whitespace), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-minimize-whitespace"[1], fno_minimize_whitespace, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-minimize-whitespace", true, 0, PreprocessorOutputOpts.MinimizeWhitespace, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fminimize_whitespace), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ffreestanding"[1], ffreestanding, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Assert that the compilation takes place in a freestanding environment", nullptr, nullptr, "-ffreestanding", true, 0, LangOpts->Freestanding, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fgnu-keywords"[1], fgnu_keywords, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allow GNU-extension keywords regardless of language standard", nullptr, nullptr, "-fgnu-keywords", true, 0, LangOpts->GNUKeywords, LangOpts->GNUMode, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_gnu_keywords), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-gnu-keywords"[1], fno_gnu_keywords, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-gnu-keywords", true, 0, LangOpts->GNUKeywords, LangOpts->GNUMode, false, false, makeBooleanOptionNormalizer(false, true, OPT_fgnu_keywords), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fgnu89-inline"[1], fgnu89_inline, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use the gnu89 inline semantics", nullptr, nullptr, "-fgnu89-inline", !LangOpts->CPlusPlus, 0, LangOpts->GNUInline, !LangOpts->C99 && !LangOpts->CPlusPlus, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_gnu89_inline), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-gnu89-inline"[1], fno_gnu89_inline, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-gnu89-inline", !LangOpts->CPlusPlus, 0, LangOpts->GNUInline, !LangOpts->C99 && !LangOpts->CPlusPlus, false, false, makeBooleanOptionNormalizer(false, true, OPT_fgnu89_inline), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fheinous-gnu-extensions"[1], fheinous_gnu_extensions, Flag, INVALID, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-fheinous-gnu-extensions", true, 0, LangOpts->HeinousExtensions, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-flegacy-pass-manager"[1], flegacy_pass_manager, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use the legacy pass manager in LLVM (deprecated, to be removed in a future release)", nullptr, nullptr, "-flegacy-pass-manager", true, 0, CodeGenOpts.LegacyPassManager, !static_cast<unsigned>(LLVM_ENABLE_NEW_PASS_MANAGER), false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_legacy_pass_manager), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-legacy-pass-manager"[1], fno_legacy_pass_manager, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use the new pass manager in LLVM", nullptr, nullptr, "-fno-legacy-pass-manager", true, 0, CodeGenOpts.LegacyPassManager, !static_cast<unsigned>(LLVM_ENABLE_NEW_PASS_MANAGER), false, false, makeBooleanOptionNormalizer(false, true, OPT_flegacy_pass_manager), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fexperimental-strict-floating-point"[1], fexperimental_strict_floating_point, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Enables experimental strict floating point in LLVM.", nullptr, nullptr, "-fexperimental-strict-floating-point", true, 0, LangOpts->ExpStrictFP, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-finstrument-functions"[1], finstrument_functions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate calls to instrument function entry and exit", nullptr, nullptr, "-finstrument-functions", true, 0, CodeGenOpts.InstrumentFunctions, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-finstrument-functions-after-inlining"[1], finstrument_functions_after_inlining, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Like -finstrument-functions, but insert the calls after inlining", nullptr, nullptr, "-finstrument-functions-after-inlining", true, 0, CodeGenOpts.InstrumentFunctionsAfterInlining, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-finstrument-function-entry-bare"[1], finstrument_function_entry_bare, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Instrument function entry only, after inlining, without arguments to the instrumentation call", nullptr, nullptr, "-finstrument-function-entry-bare", true, 0, CodeGenOpts.InstrumentFunctionEntryBare, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-instrument"[1], fxray_instrument, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate XRay instrumentation sleds on function entry and exit", nullptr, nullptr, "-fxray-instrument", true, 0, LangOpts->XRayInstrument, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_xray_instrument), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-xray-instrument"[1], fno_xray_instrument, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-xray-instrument", true, 0, LangOpts->XRayInstrument, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fxray_instrument), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-instruction-threshold="[1], fxray_instruction_threshold_EQ, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "Sets the minimum function size to instrument with XRay", nullptr, nullptr, "-fxray-instruction-threshold=", true, 0, CodeGenOpts.XRayInstructionThreshold, 200, false, 200, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-always-instrument="[1], fxray_always_instrument, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "DEPRECATED: Filename defining the whitelist for imbuing the 'always instrument' XRay attribute.", nullptr, nullptr, "-fxray-always-instrument=", true, 0, LangOpts->XRayAlwaysInstrumentFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-never-instrument="[1], fxray_never_instrument, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "DEPRECATED: Filename defining the whitelist for imbuing the 'never instrument' XRay attribute.", nullptr, nullptr, "-fxray-never-instrument=", true, 0, LangOpts->XRayNeverInstrumentFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-attr-list="[1], fxray_attr_list, JoinedOrSeparate, f_Group, INVALID, nullptr, CC1Option, 0,
       "Filename defining the list of functions/types for imbuing XRay attributes.", nullptr, nullptr, "-fxray-attr-list=", true, 0, LangOpts->XRayAttrListFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-always-emit-customevents"[1], fxray_always_emit_customevents, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Always emit __xray_customevent(...) calls even if the containing function is not always instrumented", nullptr, nullptr, "-fxray-always-emit-customevents", true, 0, LangOpts->XRayAlwaysEmitCustomEvents, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_xray_always_emit_customevents), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-xray-always-emit-customevents"[1], fno_xray_always_emit_customevents, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-xray-always-emit-customevents", true, 0, LangOpts->XRayAlwaysEmitCustomEvents, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fxray_always_emit_customevents), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-always-emit-typedevents"[1], fxray_always_emit_typedevents, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Always emit __xray_typedevent(...) calls even if the containing function is not always instrumented", nullptr, nullptr, "-fxray-always-emit-typedevents", true, 0, LangOpts->XRayAlwaysEmitTypedEvents, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_xray_always_emit_typedevents), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-xray-always-emit-typedevents"[1], fno_xray_always_emit_typedevents, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-xray-always-emit-typedevents", true, 0, LangOpts->XRayAlwaysEmitTypedEvents, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fxray_always_emit_typedevents), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-ignore-loops"[1], fxray_ignore_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't instrument functions with loops unless they also meet the minimum function size", nullptr, nullptr, "-fxray-ignore-loops", true, 0, CodeGenOpts.XRayIgnoreLoops, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_xray_ignore_loops), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-xray-ignore-loops"[1], fno_xray_ignore_loops, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-xray-ignore-loops", true, 0, CodeGenOpts.XRayIgnoreLoops, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fxray_ignore_loops), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-xray-function-index"[1], fno_xray_function_index, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Omit function index section at the expense of single-function patching performance", nullptr, nullptr, "-fno-xray-function-index", true, 0, CodeGenOpts.XRayOmitFunctionIndex, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fxray_function_index), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-function-index"[1], fxray_function_index, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fxray-function-index", true, 0, CodeGenOpts.XRayOmitFunctionIndex, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_xray_function_index), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-function-groups="[1], fxray_function_groups, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Only instrument 1 of N groups", nullptr, nullptr, "-fxray-function-groups=", true, 0, CodeGenOpts.XRayTotalFunctionGroups, 1, false, 1, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fxray-selected-function-group="[1], fxray_selected_function_group, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "When using -fxray-function-groups, select which group of functions to instrument. Valid range is 0 to fxray-function-groups - 1", nullptr, nullptr, "-fxray-selected-function-group=", true, 0, CodeGenOpts.XRaySelectedFunctionGroup, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ffine-grained-bitfield-accesses"[1], ffine_grained_bitfield_accesses, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use separate accesses for consecutive bitfield runs with legal widths and alignments.", nullptr, nullptr, "-ffine-grained-bitfield-accesses", true, 0, CodeGenOpts.FineGrainedBitfieldAccesses, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_fine_grained_bitfield_accesses), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-fine-grained-bitfield-accesses"[1], fno_fine_grained_bitfield_accesses, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Use large-integer access for consecutive bitfield runs.", nullptr, nullptr, "-fno-fine-grained-bitfield-accesses", true, 0, CodeGenOpts.FineGrainedBitfieldAccesses, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_ffine_grained_bitfield_accesses), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-flax-vector-conversions="[1], flax_vector_conversions_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable implicit vector bit-casts", nullptr, "none,integer,all", "-flax-vector-conversions=", true, 0, LangOpts->LaxVectorConversions, LangOpts->OpenCL ? LangOptions::LaxVectorConversionKind::None : LangOptions::LaxVectorConversionKind::All, false, LangOpts->OpenCL ? LangOptions::LaxVectorConversionKind::None : LangOptions::LaxVectorConversionKind::All, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 8)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fthin-link-bitcode="[1], fthin_link_bitcode_EQ, Joined, f_Group, INVALID, nullptr, CoreOption | CC1Option, 0,
       "Write minimized bitcode to <file> for the ThinLTO thin link only", nullptr, nullptr, "-fthin-link-bitcode=", true, 0, CodeGenOpts.ThinLinkBitcodeFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fmerge-all-constants"[1], fmerge_all_constants, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Allow merging of constants", nullptr, nullptr, "-fmerge-all-constants", true, 0, CodeGenOpts.MergeAllConstants, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_merge_all_constants), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-merge-all-constants"[1], fno_merge_all_constants, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disallow merging of constants", nullptr, nullptr, "-fno-merge-all-constants", true, 0, CodeGenOpts.MergeAllConstants, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fmerge_all_constants), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmessage-length="[1], fmessage_length_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Format message diagnostics so that they fit within N columns", nullptr, nullptr, "-fmessage-length=", true, 0, DiagnosticOpts->MessageLength, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fms-compatibility"[1], fms_compatibility, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enable full Microsoft Visual C++ compatibility", nullptr, nullptr, "-fms-compatibility", true, 0, LangOpts->MSVCCompat, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fms-extensions"[1], fms_extensions, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Accept some non-standard constructs supported by the Microsoft compiler", nullptr, nullptr, "-fms-extensions", true, 0, LangOpts->MicrosoftExt, false, false || LangOpts->MSVCCompat, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fasm-blocks"[1], fasm_blocks, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fasm-blocks", true, 0, LangOpts->AsmBlocks, LangOpts->MicrosoftExt, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_asm_blocks), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-asm-blocks"[1], fno_asm_blocks, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-asm-blocks", true, 0, LangOpts->AsmBlocks, LangOpts->MicrosoftExt, false, false, makeBooleanOptionNormalizer(false, true, OPT_fasm_blocks), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fms-volatile"[1], fms_volatile, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-fms-volatile", true, 0, CodeGenOpts.MSVolatile, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdelayed-template-parsing"[1], fdelayed_template_parsing, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Parse templated function definitions at the end of the translation unit", nullptr, nullptr, "-fdelayed-template-parsing", true, 0, LangOpts->DelayedTemplateParsing, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_delayed_template_parsing), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-delayed-template-parsing"[1], fno_delayed_template_parsing, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "Disable delayed template parsing", nullptr, nullptr, "-fno-delayed-template-parsing", true, 0, LangOpts->DelayedTemplateParsing, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdelayed_template_parsing), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fms-memptr-rep="[1], fms_memptr_rep_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "single,multiple,virtual", "-fms-memptr-rep=", true, 0, LangOpts->MSPointerToMemberRepresentationMethod, LangOptions::PPTMK_BestCase, false, LangOptions::PPTMK_BestCase, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 9)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdeclspec"[1], fdeclspec, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Allow __declspec as a keyword", nullptr, nullptr, "-fdeclspec", true, 0, LangOpts->DeclSpecKeyword, false, false || LangOpts->MicrosoftExt || LangOpts->Borland || LangOpts->CUDA, true, makeBooleanOptionNormalizer(true, false, OPT_fno_declspec), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-declspec"[1], fno_declspec, Flag, f_clang_Group, INVALID, nullptr, CC1Option, 0,
       "Disallow __declspec as a keyword", nullptr, nullptr, "-fno-declspec", true, 0, LangOpts->DeclSpecKeyword, false, false || LangOpts->MicrosoftExt || LangOpts->Borland || LangOpts->CUDA, true, makeBooleanOptionNormalizer(false, true, OPT_fdeclspec), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-user-build-path"[1], fmodules_user_build_path, Separate, i_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the module user build path", "<directory>", nullptr, "-fmodules-user-build-path", true, 0, HeaderSearchOpts->ModuleUserBuildPath, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fprebuilt-implicit-modules"[1], fprebuilt_implicit_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Look up implicit modules in the prebuilt module path", nullptr, nullptr, "-fprebuilt-implicit-modules", true, 0, HeaderSearchOpts->EnablePrebuiltImplicitModules, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_prebuilt_implicit_modules), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-prebuilt-implicit-modules"[1], fno_prebuilt_implicit_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "", nullptr, nullptr, "-fno-prebuilt-implicit-modules", true, 0, HeaderSearchOpts->EnablePrebuiltImplicitModules, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fprebuilt_implicit_modules), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-prune-interval="[1], fmodules_prune_interval, Joined, i_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the interval (in seconds) between attempts to prune the module cache", "<seconds>", nullptr, "-fmodules-prune-interval=", true, 0, HeaderSearchOpts->ModuleCachePruneInterval, 7 * 24 * 60 * 60, false, 7 * 24 * 60 * 60, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-prune-after="[1], fmodules_prune_after, Joined, i_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the interval (in seconds) after which a module file will be considered unused", "<seconds>", nullptr, "-fmodules-prune-after=", true, 0, HeaderSearchOpts->ModuleCachePruneAfter, 31 * 24 * 60 * 60, false, 31 * 24 * 60 * 60, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fbuild-session-timestamp="[1], fbuild_session_timestamp, Joined, i_Group, INVALID, nullptr, CC1Option, 0,
       "Time when the current build session started", "<time since Epoch in seconds>", nullptr, "-fbuild-session-timestamp=", true, 0, HeaderSearchOpts->BuildSessionTimestamp, 0, false, 0, normalizeStringIntegral<uint64_t>, denormalizeString<uint64_t>, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-validate-once-per-build-session"[1], fmodules_validate_once_per_build_session, Flag, i_Group, INVALID, nullptr, CC1Option, 0,
       "Don't verify input files for the modules if the module has been successfully validated or loaded during this build session", nullptr, nullptr, "-fmodules-validate-once-per-build-session", true, 0, HeaderSearchOpts->ModulesValidateOncePerBuildSession, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-disable-diagnostic-validation"[1], fmodules_disable_diagnostic_validation, Flag, i_Group, INVALID, nullptr, CC1Option, 0,
       "Disable validation of the diagnostic options when loading the module", nullptr, nullptr, "-fmodules-disable-diagnostic-validation", true, 0, HeaderSearchOpts->ModulesValidateDiagnosticOptions, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-validate-system-headers"[1], fmodules_validate_system_headers, Flag, i_Group, INVALID, nullptr, CC1Option, 0,
       "Validate the system headers that a module depends on when loading the module", nullptr, nullptr, "-fmodules-validate-system-headers", true, 0, HeaderSearchOpts->ModulesValidateSystemHeaders, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_modules_validate_system_headers), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-modules-validate-system-headers"[1], fno_modules_validate_system_headers, Flag, i_Group, INVALID, nullptr, NoXarchOption, 0,
       "", nullptr, nullptr, "-fno-modules-validate-system-headers", true, 0, HeaderSearchOpts->ModulesValidateSystemHeaders, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fmodules_validate_system_headers), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fvalidate-ast-input-files-content"[1], fvalidate_ast_input_files_content, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Compute and store the hash of input files used to build an AST. Files with mismatching mtime's are considered valid if both contents is identical", nullptr, nullptr, "-fvalidate-ast-input-files-content", true, 0, HeaderSearchOpts->ValidateASTInputFilesContent, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fpch-instantiate-templates"[1], fpch_instantiate_templates, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Instantiate templates already while building a PCH", nullptr, nullptr, "-fpch-instantiate-templates", true, 0, LangOpts->PCHInstantiateTemplates, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_pch_instantiate_templates), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-pch-instantiate-templates"[1], fno_pch_instantiate_templates, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr, "-fno-pch-instantiate-templates", true, 0, LangOpts->PCHInstantiateTemplates, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fpch_instantiate_templates), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fimplicit-module-maps"[1], fimplicit_module_maps, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Implicitly search the file system for module map files.", nullptr, nullptr, "-fimplicit-module-maps", true, 0, HeaderSearchOpts->ImplicitModuleMaps, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-ts"[1], fmodules_ts, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable support for the C++ Modules TS", nullptr, nullptr, "-fmodules-ts", true, 0, LangOpts->ModulesTS, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules"[1], fmodules, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption | CoreOption, 0,
       "Enable the 'modules' language feature", nullptr, nullptr, "-fmodules", true, 0, LangOpts->Modules, LangOpts->ModulesTS||LangOpts->CPlusPlusModules, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_modules), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-modules"[1], fno_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr, "-fno-modules", true, 0, LangOpts->Modules, LangOpts->ModulesTS||LangOpts->CPlusPlusModules, false, false, makeBooleanOptionNormalizer(false, true, OPT_fmodules), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodule-name="[1], fmodule_name_EQ, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Specify the name of the module to build", "<name>", nullptr, "-fmodule-name=", true, 0, LangOpts->ModuleName, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fsystem-module"[1], fsystem_module, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Build this module as a system module. Only used with -emit-module", nullptr, nullptr, "-fsystem-module", true, 0, FrontendOpts.IsSystemModule, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodule-map-file="[1], fmodule_map_file, Joined, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Load this module map file", "<file>", nullptr, "-fmodule-map-file=", true, 0, FrontendOpts.ModuleMapFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-strict-decluse"[1], fmodules_strict_decluse, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Like -fmodules-decluse but requires all headers to be in modules", nullptr, nullptr, "-fmodules-strict-decluse", true, 0, LangOpts->ModulesStrictDeclUse, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-decluse"[1], fmodules_decluse, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption | CoreOption, 0,
       "Require declaration of modules used within a module", nullptr, nullptr, "-fmodules-decluse", true, 0, LangOpts->ModulesDeclUse, LangOpts->ModulesStrictDeclUse, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_modules_decluse), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-modules-decluse"[1], fno_modules_decluse, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr, "-fno-modules-decluse", true, 0, LangOpts->ModulesDeclUse, LangOpts->ModulesStrictDeclUse, false, false, makeBooleanOptionNormalizer(false, true, OPT_fmodules_decluse), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-search-all"[1], fmodules_search_all, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "Search even non-imported modules to resolve references", nullptr, nullptr, "-fmodules-search-all", LangOpts->Modules, 0, LangOpts->ModulesSearchAll, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_modules_search_all), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-modules-search-all"[1], fno_modules_search_all, Flag, f_Group, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption, 0,
       "", nullptr, nullptr, "-fno-modules-search-all", LangOpts->Modules, 0, LangOpts->ModulesSearchAll, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fmodules_search_all), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-implicit-modules"[1], fno_implicit_modules, Flag, f_Group, INVALID, nullptr, CC1Option | NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr, "-fno-implicit-modules", true, 0, LangOpts->ImplicitModules, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fimplicit_modules), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fimplicit-modules"[1], fimplicit_modules, Flag, f_Group, INVALID, nullptr, NoXarchOption | CoreOption, 0,
       "", nullptr, nullptr, "-fimplicit-modules", true, 0, LangOpts->ImplicitModules, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_implicit_modules), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fretain-comments-from-system-headers"[1], fretain_comments_from_system_headers, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-fretain-comments-from-system-headers", true, 0, LangOpts->RetainCommentsFromSystemHeaders, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-assume-sane-operator-new"[1], fno_assume_sane_operator_new, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't assume that C++'s global operator new can't alias any pointer", nullptr, nullptr, "-fno-assume-sane-operator-new", true, 0, CodeGenOpts.AssumeSaneOperatorNew, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdigraphs"[1], fdigraphs, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable alternative token representations '<:', ':>', '<%', '%>', '%:', '%:%:' (default)", nullptr, nullptr, "-fdigraphs", true, 0, LangOpts->Digraphs, LangStandard::getLangStandardForKind(LangOpts->LangStd).hasDigraphs(), false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_digraphs), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-digraphs"[1], fno_digraphs, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disallow alternative token representations '<:', ':>', '<%', '%>', '%:', '%:%:'", nullptr, nullptr, "-fno-digraphs", true, 0, LangOpts->Digraphs, LangStandard::getLangStandardForKind(LangOpts->LangStd).hasDigraphs(), false, false, makeBooleanOptionNormalizer(false, true, OPT_fdigraphs), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fveclib="[1], fveclib, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given vector functions library", nullptr, "Accelerate,libmvec,MASSV,SVML,Darwin_libsystem_m,none", "-fveclib=", true, 0, CodeGenOpts.VecLib, CodeGenOptions::NoLibrary, false, CodeGenOptions::NoLibrary, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 10)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-operator-names"[1], fno_operator_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not treat C++ operator name keywords as synonyms for operators", nullptr, nullptr, "-fno-operator-names", true, 0, LangOpts->CXXOperatorNames, LangOpts->CPlusPlus, false, true, makeBooleanOptionNormalizer(false, true, OPT_foperator_names), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-foperator-names"[1], foperator_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-foperator-names", true, 0, LangOpts->CXXOperatorNames, LangOpts->CPlusPlus, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_operator_names), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-absolute-paths"[1], fdiagnostics_absolute_paths, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Print absolute paths in diagnostics", nullptr, nullptr, "-fdiagnostics-absolute-paths", true, 0, DiagnosticOpts->AbsolutePath, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-temp-file"[1], fno_temp_file, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Directly create compilation output files. This may lead to incorrect incremental builds if the compiler crashes", nullptr, nullptr, "-fno-temp-file", true, 0, FrontendOpts.UseTemporary, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-use-cxa-atexit"[1], fno_use_cxa_atexit, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't use __cxa_atexit for calling destructors", nullptr, nullptr, "-fno-use-cxa-atexit", true, 0, CodeGenOpts.CXAAtExit, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fuse_cxa_atexit), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fuse-cxa-atexit"[1], fuse_cxa_atexit, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fuse-cxa-atexit", true, 0, CodeGenOpts.CXAAtExit, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_use_cxa_atexit), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-verbose-asm"[1], fno_verbose_asm, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-fno-verbose-asm", true, 0, CodeGenOpts.AsmVerbose, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-encode-cxx-class-template-spec"[1], fobjc_encode_cxx_class_template_spec, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Fully encode c++ class template specialization", nullptr, nullptr, "-fobjc-encode-cxx-class-template-spec", true, 0, LangOpts->EncodeCXXClassTemplateSpec, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_objc_encode_cxx_class_template_spec), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-objc-encode-cxx-class-template-spec"[1], fno_objc_encode_cxx_class_template_spec, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-objc-encode-cxx-class-template-spec", true, 0, LangOpts->EncodeCXXClassTemplateSpec, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fobjc_encode_cxx_class_template_spec), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-objc-convert-messages-to-runtime-calls"[1], fno_objc_convert_messages_to_runtime_calls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-objc-convert-messages-to-runtime-calls", true, 0, CodeGenOpts.ObjCConvertMessagesToRuntimeCalls, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fobjc_convert_messages_to_runtime_calls), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-convert-messages-to-runtime-calls"[1], fobjc_convert_messages_to_runtime_calls, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fobjc-convert-messages-to-runtime-calls", true, 0, CodeGenOpts.ObjCConvertMessagesToRuntimeCalls, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_objc_convert_messages_to_runtime_calls), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-arc-exceptions"[1], fobjc_arc_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use EH-safe code when synthesizing retains and releases in -fobjc-arc", nullptr, nullptr, "-fobjc-arc-exceptions", true, 0, CodeGenOpts.ObjCAutoRefCountExceptions, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_objc_arc_exceptions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-objc-arc-exceptions"[1], fno_objc_arc_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-objc-arc-exceptions", true, 0, CodeGenOpts.ObjCAutoRefCountExceptions, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fobjc_arc_exceptions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-exceptions"[1], fobjc_exceptions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable Objective-C exceptions", nullptr, nullptr, "-fobjc-exceptions", true, 0, LangOpts->ObjCExceptions, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_objc_exceptions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-objc-exceptions"[1], fno_objc_exceptions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-objc-exceptions", true, 0, LangOpts->ObjCExceptions, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fobjc_exceptions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fapplication-extension"[1], fapplication_extension, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Restrict code to those available for App Extensions", nullptr, nullptr, "-fapplication-extension", true, 0, LangOpts->AppExt, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_application_extension), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-application-extension"[1], fno_application_extension, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-application-extension", true, 0, LangOpts->AppExt, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fapplication_extension), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-frelaxed-template-template-args"[1], frelaxed_template_template_args, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++17 relaxed template template argument matching", nullptr, nullptr, "-frelaxed-template-template-args", true, 0, LangOpts->RelaxedTemplateTemplateArgs, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_relaxed_template_template_args), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-relaxed-template-template-args"[1], fno_relaxed_template_template_args, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-relaxed-template-template-args", true, 0, LangOpts->RelaxedTemplateTemplateArgs, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_frelaxed_template_template_args), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsized-deallocation"[1], fsized_deallocation, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++14 sized global deallocation functions", nullptr, nullptr, "-fsized-deallocation", true, 0, LangOpts->SizedDeallocation, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_sized_deallocation), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-sized-deallocation"[1], fno_sized_deallocation, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-sized-deallocation", true, 0, LangOpts->SizedDeallocation, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsized_deallocation), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-faligned-allocation"[1], faligned_allocation, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++17 aligned allocation functions", nullptr, nullptr, "-faligned-allocation", true, 0, LangOpts->AlignedAllocation, LangOpts->CPlusPlus17, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_aligned_allocation), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-aligned-allocation"[1], fno_aligned_allocation, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-aligned-allocation", true, 0, LangOpts->AlignedAllocation, LangOpts->CPlusPlus17, false, false, makeBooleanOptionNormalizer(false, true, OPT_faligned_allocation), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fnew-alignment="[1], fnew_alignment_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specifies the largest alignment guaranteed by '::operator new(size_t)'", "<align>", nullptr, "-fnew-alignment=", true, 0, LangOpts->NewAlignOverride, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-objc-infer-related-result-type"[1], fno_objc_infer_related_result_type, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "do not infer Objective-C related result type based on method family", nullptr, nullptr, "-fno-objc-infer-related-result-type", true, 0, LangOpts->ObjCInferRelatedResultType, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fobjc_infer_related_result_type), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-infer-related-result-type"[1], fobjc_infer_related_result_type, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fobjc-infer-related-result-type", true, 0, LangOpts->ObjCInferRelatedResultType, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_objc_infer_related_result_type), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-disable-direct-methods-for-testing"[1], fobjc_disable_direct_methods_for_testing, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Ignore attribute objc_direct so that direct methods can be tested", nullptr, nullptr, "-fobjc-disable-direct-methods-for-testing", true, 0, LangOpts->ObjCDisableDirectMethodsForTesting, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-avoid-heapify-local-blocks"[1], fobjc_avoid_heapify_local_blocks, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Try to avoid heapifying local blocks", nullptr, nullptr, "-fobjc-avoid-heapify-local-blocks", true, 0, CodeGenOpts.ObjCAvoidHeapifyLocalBlocks, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_objc_avoid_heapify_local_blocks), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-objc-avoid-heapify-local-blocks"[1], fno_objc_avoid_heapify_local_blocks, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't try to avoid heapifying local blocks", nullptr, nullptr, "-fno-objc-avoid-heapify-local-blocks", true, 0, CodeGenOpts.ObjCAvoidHeapifyLocalBlocks, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fobjc_avoid_heapify_local_blocks), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fopenmp-extensions"[1], fopenmp_extensions, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Enable all Clang extensions for OpenMP directives and clauses", nullptr, nullptr, "-fopenmp-extensions", true, 0, LangOpts->OpenMPExtensions, true, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_openmp_extensions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-openmp-extensions"[1], fno_openmp_extensions, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused, 0,
       "Disable all Clang extensions for OpenMP directives and clauses", nullptr, nullptr, "-fno-openmp-extensions", true, 0, LangOpts->OpenMPExtensions, true, false, false, makeBooleanOptionNormalizer(false, true, OPT_fopenmp_extensions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fopenmp-target-new-runtime"[1], fopenmp_target_new_runtime, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use the new bitcode library for OpenMP offloading", nullptr, nullptr, "-fopenmp-target-new-runtime", true, 0, LangOpts->OpenMPTargetNewRuntime, true, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_openmp_target_new_runtime), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-openmp-target-new-runtime"[1], fno_openmp_target_new_runtime, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-openmp-target-new-runtime", true, 0, LangOpts->OpenMPTargetNewRuntime, true, false, false, makeBooleanOptionNormalizer(false, true, OPT_fopenmp_target_new_runtime), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fopenmp-optimistic-collapse"[1], fopenmp_optimistic_collapse, Flag, f_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | HelpHidden, 0,
       "", nullptr, nullptr, "-fopenmp-optimistic-collapse", true, 0, LangOpts->OpenMPOptimisticCollapse, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_openmp_optimistic_collapse), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-openmp-optimistic-collapse"[1], fno_openmp_optimistic_collapse, Flag, f_Group, INVALID, nullptr, NoArgumentUnused | HelpHidden, 0,
       "", nullptr, nullptr, "-fno-openmp-optimistic-collapse", true, 0, LangOpts->OpenMPOptimisticCollapse, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fopenmp_optimistic_collapse), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-escaping-block-tail-calls"[1], fno_escaping_block_tail_calls, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fno-escaping-block-tail-calls", true, 0, CodeGenOpts.NoEscapingBlockTailCalls, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fescaping_block_tail_calls), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fescaping-block-tail-calls"[1], fescaping_block_tail_calls, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fescaping-block-tail-calls", true, 0, CodeGenOpts.NoEscapingBlockTailCalls, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_escaping_block_tail_calls), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fpack-struct="[1], fpack_struct_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the default maximum struct packing alignment", nullptr, nullptr, "-fpack-struct=", true, 0, LangOpts->PackStruct, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmax-type-align="[1], fmax_type_align_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Specify the maximum alignment to enforce on pointers lacking an explicit alignment", nullptr, nullptr, "-fmax-type-align=", true, 0, LangOpts->MaxTypeAlign, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fpascal-strings"[1], fpascal_strings, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Recognize and construct Pascal-style string literals", nullptr, nullptr, "-fpascal-strings", true, 0, LangOpts->PascalStrings, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_pascal_strings), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-pascal-strings"[1], fno_pascal_strings, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-pascal-strings", true, 0, LangOpts->PascalStrings, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fpascal_strings), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fpatchable-function-entry="[1], fpatchable_function_entry_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate M NOPs before function entry and N-M NOPs after function entry", "<N,M>", nullptr, "-fpatchable-function-entry=", true, 0, CodeGenOpts.PatchableFunctionEntryCount, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-plt"[1], fno_plt, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use GOT indirection instead of PLT to make external function calls (x86 only)", nullptr, nullptr, "-fno-plt", true, 0, CodeGenOpts.NoPLT, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fplt), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fplt"[1], fplt, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fplt", true, 0, CodeGenOpts.NoPLT, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_plt), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fropi"[1], fropi, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate read-only position independent code (ARM only)", nullptr, nullptr, "-fropi", true, 0, LangOpts->ROPI, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_ropi), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-ropi"[1], fno_ropi, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-ropi", true, 0, LangOpts->ROPI, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fropi), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-frwpi"[1], frwpi, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Generate read-write position independent code (ARM only)", nullptr, nullptr, "-frwpi", true, 0, LangOpts->RWPI, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_rwpi), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-rwpi"[1], fno_rwpi, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-rwpi", true, 0, LangOpts->RWPI, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_frwpi), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fpass-plugin="[1], fpass_plugin_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Load pass plugin from a dynamic shared object file (only with new pass manager).", "<dsopath>", nullptr, "-fpass-plugin=", true, 0, CodeGenOpts.PassPlugins, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-preserve-as-comments"[1], fno_preserve_as_comments, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not preserve comments in inline assembly", nullptr, nullptr, "-fno-preserve-as-comments", true, 0, CodeGenOpts.PreserveAsmComments, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fpreserve_as_comments), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fpreserve-as-comments"[1], fpreserve_as_comments, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fpreserve-as-comments", true, 0, CodeGenOpts.PreserveAsmComments, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_preserve_as_comments), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-rtti"[1], fno_rtti, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of rtti information", nullptr, nullptr, "-fno-rtti", LangOpts->CPlusPlus, 0, LangOpts->RTTI, LangOpts->CPlusPlus, false, true, makeBooleanOptionNormalizer(false, true, OPT_frtti), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-frtti"[1], frtti, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-frtti", LangOpts->CPlusPlus, 0, LangOpts->RTTI, LangOpts->CPlusPlus, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_rtti), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-rtti-data"[1], fno_rtti_data, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable generation of RTTI data", nullptr, nullptr, "-fno-rtti-data", LangOpts->RTTI, 0, LangOpts->RTTIData, LangOpts->RTTI, false, true, makeBooleanOptionNormalizer(false, true, OPT_frtti_data), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-frtti-data"[1], frtti_data, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-frtti-data", LangOpts->RTTI, 0, LangOpts->RTTIData, LangOpts->RTTI, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_rtti_data), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fshort-enums"[1], fshort_enums, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Allocate to an enum type only as many bytes as it needs for the declared range of possible values", nullptr, nullptr, "-fshort-enums", true, 0, LangOpts->ShortEnums, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_short_enums), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-short-enums"[1], fno_short_enums, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-short-enums", true, 0, LangOpts->ShortEnums, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fshort_enums), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fchar8_t"[1], fchar8__t, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable C++ builtin type char8_t", nullptr, nullptr, "-fchar8_t", true, 0, LangOpts->Char8, LangOpts->CPlusPlus20, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_char8__t), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-char8_t"[1], fno_char8__t, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable C++ builtin type char8_t", nullptr, nullptr, "-fno-char8_t", true, 0, LangOpts->Char8, LangOpts->CPlusPlus20, false, false, makeBooleanOptionNormalizer(false, true, OPT_fchar8__t), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fshow-overloads="[1], fshow_overloads_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Which overload candidates to show when overload resolution fails: best|all; defaults to all", nullptr, "best,all", "-fshow-overloads=", true, 0, DiagnosticOpts->ShowOverloads, Ovl_All, false, Ovl_All, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 11)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-show-column"[1], fno_show_column, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not include column number on diagnostics", nullptr, nullptr, "-fno-show-column", true, 0, DiagnosticOpts->ShowColumn, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fshow_column), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fshow-column"[1], fshow_column, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fshow-column", true, 0, DiagnosticOpts->ShowColumn, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_show_column), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-show-source-location"[1], fno_show_source_location, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not include source location information with diagnostics", nullptr, nullptr, "-fno-show-source-location", true, 0, DiagnosticOpts->ShowLocation, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fshow_source_location), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fshow-source-location"[1], fshow_source_location, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fshow-source-location", true, 0, DiagnosticOpts->ShowLocation, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_show_source_location), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-spell-checking"[1], fno_spell_checking, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable spell-checking", nullptr, nullptr, "-fno-spell-checking", true, 0, LangOpts->SpellChecking, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fspell_checking), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fspell-checking"[1], fspell_checking, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fspell-checking", true, 0, LangOpts->SpellChecking, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_spell_checking), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-signed-char"[1], fno_signed_char, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "char is unsigned", nullptr, nullptr, "-fno-signed-char", !LangOpts->OpenCL, 0, LangOpts->CharIsSigned, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fsigned_char), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsigned-char"[1], fsigned_char, Flag, f_Group, INVALID, nullptr, 0, 0,
       "char is signed", nullptr, nullptr, "-fsigned-char", !LangOpts->OpenCL, 0, LangOpts->CharIsSigned, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_signed_char), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-split-stack"[1], fno_split_stack, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Wouldn't use segmented stack", nullptr, nullptr, "-fno-split-stack", true, 0, CodeGenOpts.EnableSegmentedStacks, false, false, true, makeBooleanOptionNormalizer(false, true, OPT_fsplit_stack), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsplit-stack"[1], fsplit_stack, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use segmented stack", nullptr, nullptr, "-fsplit-stack", true, 0, CodeGenOpts.EnableSegmentedStacks, false, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_split_stack), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fstack-clash-protection"[1], fstack_clash_protection, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable stack clash protection", nullptr, nullptr, "-fstack-clash-protection", true, 0, CodeGenOpts.StackClashProtector, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_stack_clash_protection), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-stack-clash-protection"[1], fno_stack_clash_protection, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable stack clash protection", nullptr, nullptr, "-fno-stack-clash-protection", true, 0, CodeGenOpts.StackClashProtector, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fstack_clash_protection), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ftrivial-auto-var-init="[1], ftrivial_auto_var_init, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Initialize trivial automatic stack variables: uninitialized (default) | pattern", nullptr, "uninitialized,zero,pattern", "-ftrivial-auto-var-init=", true, 0, LangOpts->TrivialAutoVarInit, LangOptions::TrivialAutoVarInitKind::Uninitialized, false, LangOptions::TrivialAutoVarInitKind::Uninitialized, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 12)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ftrivial-auto-var-init-stop-after="[1], ftrivial_auto_var_init_stop_after, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Stop initializing trivial automatic stack variables after the specified number of instances", nullptr, nullptr, "-ftrivial-auto-var-init-stop-after=", true, 0, LangOpts->TrivialAutoVarInitStopAfter, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fstrict-enums"[1], fstrict_enums, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable optimizations based on the strict definition of an enum's value range", nullptr, nullptr, "-fstrict-enums", true, 0, CodeGenOpts.StrictEnums, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fstrict-vtable-pointers"[1], fstrict_vtable_pointers, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable optimizations based on the strict rules for overwriting polymorphic C++ objects", nullptr, nullptr, "-fstrict-vtable-pointers", true, 0, CodeGenOpts.StrictVTablePointers, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_strict_vtable_pointers), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-strict-vtable-pointers"[1], fno_strict_vtable_pointers, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-strict-vtable-pointers", true, 0, CodeGenOpts.StrictVTablePointers, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fstrict_vtable_pointers), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-Wlarge-by-value-copy="[1], Wlarge_by_value_copy_EQ, Joined, INVALID, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-Wlarge-by-value-copy=", true, 0, LangOpts->NumLargeByValueCopy, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-threadsafe-statics"[1], fno_threadsafe_statics, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Do not emit code to make initialization of local statics thread safe", nullptr, nullptr, "-fno-threadsafe-statics", true, 0, LangOpts->ThreadsafeStatics, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fthreadsafe_statics), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fthreadsafe-statics"[1], fthreadsafe_statics, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fthreadsafe-statics", true, 0, LangOpts->ThreadsafeStatics, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_threadsafe_statics), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ftime-report"[1], ftime_report, Flag, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-ftime-report", true, 0, CodeGenOpts.TimePasses, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ftime-report="[1], ftime_report_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "(For new pass manager) \"per-pass\": one report for each pass; \"per-pass-run\": one report for each pass invocation", nullptr, "per-pass,per-pass-run", "-ftime-report=", true, 0, CodeGenOpts.TimePassesPerRun, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-ftime-trace"[1], ftime_trace, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Turn on time profiler. Generates JSON file based on output filename.", nullptr, nullptr, "-ftime-trace", true, 0, FrontendOpts.TimeTrace, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-ftime-trace-granularity="[1], ftime_trace_granularity_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Minimum time granularity (in microseconds) traced by time profiler", nullptr, nullptr, "-ftime-trace-granularity=", true, 0, FrontendOpts.TimeTraceGranularity, 500u, false, 500u, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ftls-model="[1], ftlsmodel_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "global-dynamic,local-dynamic,initial-exec,local-exec", "-ftls-model=", true, 0, CodeGenOpts.DefaultTLSModel, CodeGenOptions::GeneralDynamicTLSModel, false, CodeGenOptions::GeneralDynamicTLSModel, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 13)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ftrap-function="[1], ftrap_function_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Issue call to specified function rather than a trap instruction", nullptr, nullptr, "-ftrap-function=", true, 0, CodeGenOpts.TrapFuncName, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-freroll-loops"[1], freroll_loops, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Turn on loop reroller", nullptr, nullptr, "-freroll-loops", true, 0, CodeGenOpts.RerollLoops, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_reroll_loops), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-reroll-loops"[1], fno_reroll_loops, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-reroll-loops", true, 0, CodeGenOpts.RerollLoops, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_freroll_loops), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fregister-global-dtors-with-atexit"[1], fregister_global_dtors_with_atexit, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use atexit or __cxa_atexit to register global destructors", nullptr, nullptr, "-fregister-global-dtors-with-atexit", true, 0, CodeGenOpts.RegisterGlobalDtorsWithAtExit, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_register_global_dtors_with_atexit), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-register-global-dtors-with-atexit"[1], fno_register_global_dtors_with_atexit, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't use atexit or __cxa_atexit to register global destructors", nullptr, nullptr, "-fno-register-global-dtors-with-atexit", true, 0, CodeGenOpts.RegisterGlobalDtorsWithAtExit, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fregister_global_dtors_with_atexit), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-use-init-array"[1], fno_use_init_array, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use .ctors/.dtors instead of .init_array/.fini_array", nullptr, nullptr, "-fno-use-init-array", true, 0, CodeGenOpts.UseInitArray, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fuse_init_array), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fuse-init-array"[1], fuse_init_array, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fuse-init-array", true, 0, CodeGenOpts.UseInitArray, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_use_init_array), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-from-dllstorageclass"[1], fvisibility_from_dllstorageclass, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Set the visibility of symbols in the generated code from their DLL storage class", nullptr, nullptr, "-fvisibility-from-dllstorageclass", true, 0, LangOpts->VisibilityFromDLLStorageClass, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_visibility_from_dllstorageclass), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-visibility-from-dllstorageclass"[1], fno_visibility_from_dllstorageclass, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-visibility-from-dllstorageclass", true, 0, LangOpts->VisibilityFromDLLStorageClass, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fvisibility_from_dllstorageclass), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-dllexport="[1], fvisibility_dllexport_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for dllexport definitions [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected", "-fvisibility-dllexport=", LangOpts->VisibilityFromDLLStorageClass, 0, LangOpts->DLLExportVisibility, DefaultVisibility, false, DefaultVisibility, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 14)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-nodllstorageclass="[1], fvisibility_nodllstorageclass_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for defintiions without an explicit DLL export class [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected", "-fvisibility-nodllstorageclass=", LangOpts->VisibilityFromDLLStorageClass, 0, LangOpts->NoDLLStorageClassVisibility, HiddenVisibility, false, HiddenVisibility, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 15)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-externs-dllimport="[1], fvisibility_externs_dllimport_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for dllimport external declarations [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected", "-fvisibility-externs-dllimport=", LangOpts->VisibilityFromDLLStorageClass, 0, LangOpts->ExternDeclDLLImportVisibility, DefaultVisibility, false, DefaultVisibility, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 16)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-externs-nodllstorageclass="[1], fvisibility_externs_nodllstorageclass_EQ, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "The visibility for external declarations without an explicit DLL dllstorageclass [-fvisibility-from-dllstorageclass]", nullptr, "default,hidden,internal,protected", "-fvisibility-externs-nodllstorageclass=", LangOpts->VisibilityFromDLLStorageClass, 0, LangOpts->ExternDeclNoDLLStorageClassVisibility, HiddenVisibility, false, HiddenVisibility, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 17)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-inlines-hidden"[1], fvisibility_inlines_hidden, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Give inline C++ member functions hidden visibility by default", nullptr, nullptr, "-fvisibility-inlines-hidden", true, 0, LangOpts->InlineVisibilityHidden, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_visibility_inlines_hidden), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-visibility-inlines-hidden"[1], fno_visibility_inlines_hidden, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-visibility-inlines-hidden", true, 0, LangOpts->InlineVisibilityHidden, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fvisibility_inlines_hidden), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-inlines-hidden-static-local-var"[1], fvisibility_inlines_hidden_static_local_var, Flag, f_Group, INVALID, nullptr, CC1Option | CC1Option, 0,
       "When -fvisibility-inlines-hidden is enabled, static variables in inline C++ member functions will also be given hidden visibility by default", nullptr, nullptr, "-fvisibility-inlines-hidden-static-local-var", true, 0, LangOpts->VisibilityInlinesHiddenStaticLocalVar, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_visibility_inlines_hidden_static_local_var), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-visibility-inlines-hidden-static-local-var"[1], fno_visibility_inlines_hidden_static_local_var, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disables -fvisibility-inlines-hidden-static-local-var (this is the default on non-darwin targets)", nullptr, nullptr, "-fno-visibility-inlines-hidden-static-local-var", true, 0, LangOpts->VisibilityInlinesHiddenStaticLocalVar, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fvisibility_inlines_hidden_static_local_var), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility-global-new-delete-hidden"[1], fvisibility_global_new_delete_hidden, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Give global C++ operator new and delete declarations hidden visibility", nullptr, nullptr, "-fvisibility-global-new-delete-hidden", true, 0, LangOpts->GlobalAllocationFunctionVisibilityHidden, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fnew-infallible"[1], fnew_infallible, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable treating throwing global C++ operator new as always returning valid memory (annotates with __attribute__((returns_nonnull)) and throw()). This is detectable in source.", nullptr, nullptr, "-fnew-infallible", true, 0, LangOpts->NewInfallible, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_new_infallible), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-new-infallible"[1], fno_new_infallible, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable treating throwing global C++ operator new as always returning valid memory (annotates with __attribute__((returns_nonnull)) and throw()). This is detectable in source.", nullptr, nullptr, "-fno-new-infallible", true, 0, LangOpts->NewInfallible, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fnew_infallible), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fwhole-program-vtables"[1], fwhole_program_vtables, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enables whole-program vtable optimization. Requires -flto", nullptr, nullptr, "-fwhole-program-vtables", true, 0, CodeGenOpts.WholeProgramVTables, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_whole_program_vtables), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-whole-program-vtables"[1], fno_whole_program_vtables, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-fno-whole-program-vtables", true, 0, CodeGenOpts.WholeProgramVTables, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fwhole_program_vtables), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsplit-lto-unit"[1], fsplit_lto_unit, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enables splitting of the LTO unit", nullptr, nullptr, "-fsplit-lto-unit", true, 0, CodeGenOpts.EnableSplitLTOUnit, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_split_lto_unit), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-split-lto-unit"[1], fno_split_lto_unit, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-fno-split-lto-unit", true, 0, CodeGenOpts.EnableSplitLTOUnit, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsplit_lto_unit), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fforce-emit-vtables"[1], fforce_emit_vtables, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Emits more virtual tables to improve devirtualization", nullptr, nullptr, "-fforce-emit-vtables", true, 0, CodeGenOpts.ForceEmitVTables, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_force_emit_vtables), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-force-emit-vtables"[1], fno_force_emit_vtables, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-fno-force-emit-vtables", true, 0, CodeGenOpts.ForceEmitVTables, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fforce_emit_vtables), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fvirtual-function-elimination"[1], fvirtual_function_elimination, Flag, f_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Enables dead virtual function elimination optimization. Requires -flto=full", nullptr, nullptr, "-fvirtual-function-elimination", true, 0, CodeGenOpts.VirtualFunctionElimination, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_virtual_function_elimination), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-virtual-function-elimination"[1], fno_virtual_function_elimination, Flag, f_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-fno-virtual-function-elimination", true, 0, CodeGenOpts.VirtualFunctionElimination, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fvirtual_function_elimination), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fwritable-strings"[1], fwritable_strings, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Store string literals as writable data", nullptr, nullptr, "-fwritable-strings", true, 0, LangOpts->WritableStrings, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-zero-initialized-in-bss"[1], fno_zero_initialized_in_bss, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't place zero initialized data in BSS", nullptr, nullptr, "-fno-zero-initialized-in-bss", true, 0, CodeGenOpts.NoZeroInitializedInBSS, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fzero_initialized_in_bss), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fzero-initialized-in-bss"[1], fzero_initialized_in_bss, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fzero-initialized-in-bss", true, 0, CodeGenOpts.NoZeroInitializedInBSS, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_zero_initialized_in_bss), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ffunction-sections"[1], ffunction_sections, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Place each function in its own section", nullptr, nullptr, "-ffunction-sections", true, 0, CodeGenOpts.FunctionSections, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_function_sections), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-function-sections"[1], fno_function_sections, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-function-sections", true, 0, CodeGenOpts.FunctionSections, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_ffunction_sections), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fbasic-block-sections="[1], fbasic_block_sections_EQ, Joined, f_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "Place each function's basic blocks in unique sections (ELF Only) : all | labels | none | list=<file>", nullptr, "all,labels,none,list=", "-fbasic-block-sections=", true, 0, CodeGenOpts.BBSections, "none", false, "none", normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdata-sections"[1], fdata_sections, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Place each data in its own section", nullptr, nullptr, "-fdata-sections", true, 0, CodeGenOpts.DataSections, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_data_sections), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-data-sections"[1], fno_data_sections, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-data-sections", true, 0, CodeGenOpts.DataSections, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdata_sections), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fstack-size-section"[1], fstack_size_section, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Emit section containing metadata on function stack sizes", nullptr, nullptr, "-fstack-size-section", true, 0, CodeGenOpts.StackSizeSection, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_stack_size_section), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-stack-size-section"[1], fno_stack_size_section, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-stack-size-section", true, 0, CodeGenOpts.StackSizeSection, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fstack_size_section), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-stack-usage-file"[1], stack_usage_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename (or -) to write stack usage output to", nullptr, nullptr, "-stack-usage-file", true, 0, CodeGenOpts.StackUsageOutput, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-funique-basic-block-section-names"[1], funique_basic_block_section_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use unique names for basic block sections (ELF Only)", nullptr, nullptr, "-funique-basic-block-section-names", true, 0, CodeGenOpts.UniqueBasicBlockSectionNames, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_unique_basic_block_section_names), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-unique-basic-block-section-names"[1], fno_unique_basic_block_section_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-unique-basic-block-section-names", true, 0, CodeGenOpts.UniqueBasicBlockSectionNames, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_funique_basic_block_section_names), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-funique-internal-linkage-names"[1], funique_internal_linkage_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Uniqueify Internal Linkage Symbol Names by appending the MD5 hash of the module path", nullptr, nullptr, "-funique-internal-linkage-names", true, 0, CodeGenOpts.UniqueInternalLinkageNames, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_unique_internal_linkage_names), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-unique-internal-linkage-names"[1], fno_unique_internal_linkage_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-unique-internal-linkage-names", true, 0, CodeGenOpts.UniqueInternalLinkageNames, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_funique_internal_linkage_names), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-unique-section-names"[1], fno_unique_section_names, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't use unique names for text and data sections", nullptr, nullptr, "-fno-unique-section-names", true, 0, CodeGenOpts.UniqueSectionNames, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_funique_section_names), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-funique-section-names"[1], funique_section_names, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-funique-section-names", true, 0, CodeGenOpts.UniqueSectionNames, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_unique_section_names), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsplit-machine-functions"[1], fsplit_machine_functions, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable late function splitting using profile information (x86 ELF)", nullptr, nullptr, "-fsplit-machine-functions", true, 0, CodeGenOpts.SplitMachineFunctions, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_split_machine_functions), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-split-machine-functions"[1], fno_split_machine_functions, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Disable late function splitting using profile information (x86 ELF)", nullptr, nullptr, "-fno-split-machine-functions", true, 0, CodeGenOpts.SplitMachineFunctions, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsplit_machine_functions), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-strict-return"[1], fno_strict_return, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Don't treat control flow paths that fall off the end of a non-void function as unreachable", nullptr, nullptr, "-fno-strict-return", true, 0, CodeGenOpts.StrictReturn, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fstrict_return), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fstrict-return"[1], fstrict_return, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fstrict-return", true, 0, CodeGenOpts.StrictReturn, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_strict_return), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fenable-matrix"[1], fenable_matrix, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable matrix data type and related builtin functions", nullptr, nullptr, "-fenable-matrix", true, 0, LangOpts->MatrixTypes, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdebug-ranges-base-address"[1], fdebug_ranges_base_address, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use DWARF base address selection entries in .debug_ranges", nullptr, nullptr, "-fdebug-ranges-base-address", true, 0, CodeGenOpts.DebugRangesBaseAddress, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_debug_ranges_base_address), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-debug-ranges-base-address"[1], fno_debug_ranges_base_address, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-debug-ranges-base-address", true, 0, CodeGenOpts.DebugRangesBaseAddress, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdebug_ranges_base_address), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-split-dwarf-inlining"[1], fno_split_dwarf_inlining, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-split-dwarf-inlining", true, 0, CodeGenOpts.SplitDwarfInlining, false, false, true, makeBooleanOptionNormalizer(false, true, OPT_fsplit_dwarf_inlining), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsplit-dwarf-inlining"[1], fsplit_dwarf_inlining, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Provide minimal debug info in the object/executable to facilitate online symbolication/stack traces in the absence of .dwo/.dwp files when using Split DWARF", nullptr, nullptr, "-fsplit-dwarf-inlining", true, 0, CodeGenOpts.SplitDwarfInlining, false, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_split_dwarf_inlining), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fforce-dwarf-frame"[1], fforce_dwarf_frame, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Always emit a debug frame section", nullptr, nullptr, "-fforce-dwarf-frame", true, 0, CodeGenOpts.ForceDwarfFrameSection, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_force_dwarf_frame), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-force-dwarf-frame"[1], fno_force_dwarf_frame, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-force-dwarf-frame", true, 0, CodeGenOpts.ForceDwarfFrameSection, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fforce_dwarf_frame), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gdwarf64"[1], gdwarf64, Flag, g_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "Enables DWARF64 format for ELF binaries, if debug information emission is enabled.", nullptr, nullptr, "-gdwarf64", true, 0, CodeGenOpts.Dwarf64, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gcodeview"[1], gcodeview, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Generate CodeView debug information", nullptr, nullptr, "-gcodeview", true, 0, CodeGenOpts.EmitCodeView, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gcodeview-ghash"[1], gcodeview_ghash, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Emit type record hashes in a .debug$H section", nullptr, nullptr, "-gcodeview-ghash", true, 0, CodeGenOpts.CodeViewGHash, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_gno_codeview_ghash), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gno-codeview-ghash"[1], gno_codeview_ghash, Flag, INVALID, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-gno-codeview-ghash", true, 0, CodeGenOpts.CodeViewGHash, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_gcodeview_ghash), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gno-inline-line-tables"[1], gno_inline_line_tables, Flag, g_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Don't emit inline line tables.", nullptr, nullptr, "-gno-inline-line-tables", true, 0, CodeGenOpts.NoInlineLineTables, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_ginline_line_tables), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ginline-line-tables"[1], ginline_line_tables, Flag, g_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-ginline-line-tables", true, 0, CodeGenOpts.NoInlineLineTables, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_gno_inline_line_tables), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gstrict-dwarf"[1], gstrict_dwarf, Flag, g_flags_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr, "-gstrict-dwarf", true, 0, CodeGenOpts.DebugStrictDwarf, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_gno_strict_dwarf), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gno-strict-dwarf"[1], gno_strict_dwarf, Flag, g_flags_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-gno-strict-dwarf", true, 0, CodeGenOpts.DebugStrictDwarf, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_gstrict_dwarf), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gno-column-info"[1], gno_column_info, Flag, g_flags_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr, "-gno-column-info", true, 0, CodeGenOpts.DebugColumnInfo, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_gcolumn_info), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gcolumn-info"[1], gcolumn_info, Flag, g_flags_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-gcolumn-info", true, 0, CodeGenOpts.DebugColumnInfo, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_gno_column_info), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-gembed-source"[1], gembed_source, Flag, g_flags_Group, INVALID, nullptr, CC1Option, 0,
       "Embed source text in DWARF debug sections", nullptr, nullptr, "-gembed-source", true, 0, CodeGenOpts.EmbedSource, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_4, &"-help"[1], help, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | FC1Option | FlangOption, 0,
       "Display available options", nullptr, nullptr, "-help", true, 0, FrontendOpts.ShowHelp, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_4, &"-imacros"[1], imacros, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Include macros from file before parsing", "<file>", nullptr, "-imacros", true, 0, PreprocessorOpts->MacroIncludes, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-include-pch"[1], include_pch, Separate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Include precompiled header file", "<file>", nullptr, "-include-pch", true, 0, PreprocessorOpts->ImplicitPCHInclude, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_4, &"-relocatable-pch"[1], relocatable_pch, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Whether to build a relocatable precompiled header", nullptr, nullptr, "-relocatable-pch", true, 0, FrontendOpts.RelocatablePCH, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-isysroot"[1], isysroot, JoinedOrSeparate, clang_i_Group, INVALID, nullptr, CC1Option, 0,
       "Set the system root directory (usually /)", "<dir>", nullptr, "-isysroot", true, 0, HeaderSearchOpts->Sysroot, "/", false, "/", normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mqdsp6-compat"[1], mqdsp6_compat, Flag, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Enable hexagon-qdsp6 backward compatibility", nullptr, nullptr, "-mqdsp6-compat", true, 0, LangOpts->HexagonQdsp6Compat, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mdouble="[1], mdouble_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Force double to be 32 bits or 64 bits", nullptr, "32,64", "-mdouble=", true, 0, LangOpts->DoubleSize, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-inline-asm="[1], inline_asm_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, "att,intel", "-inline-asm=", true, 0, CodeGenOpts.InlineAsmDialect, CodeGenOptions::IAD_ATT, false, CodeGenOptions::IAD_ATT, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 18)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-mcmodel="[1], mcmodel_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-mcmodel=", true, 0, TargetOpts->CodeModel, "default", false, "default", normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mtls-size="[1], mtls_size_EQ, Joined, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify bit size of immediate TLS offsets (AArch64 ELF only): 12 (for 4KB) | 24 (for 16MB, default) | 32 (for 4GB) | 48 (for 256TB, needs -mcmodel=large)", nullptr, nullptr, "-mtls-size=", true, 0, CodeGenOpts.TLSSize, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-malign-double"[1], malign_double, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Align doubles to two words in structs (x86 only)", nullptr, nullptr, "-malign-double", true, 0, LangOpts->AlignDouble, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-mllvm"[1], mllvm, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Additional arguments to forward to LLVM's option processing", nullptr, nullptr, "-mllvm", true, 0, FrontendOpts.LLVMArgs, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ffuchsia-api-level="[1], ffuchsia_api_level_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set Fuchsia API level", nullptr, nullptr, "-ffuchsia-api-level=", true, 0, LangOpts->FuchsiaAPILevel, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mms-bitfields"[1], mms_bitfields, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set the default structure layout to be compatible with the Microsoft compiler standard", nullptr, nullptr, "-mms-bitfields", true, 0, LangOpts->MSBitfields, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mskip-rax-setup"[1], mskip_rax_setup, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Skip setting up RAX register when passing variable arguments (x86 only)", nullptr, nullptr, "-mskip-rax-setup", true, 0, CodeGenOpts.SkipRaxSetup, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mstackrealign"[1], mstackrealign, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Force realign the stack at entry to every function", nullptr, nullptr, "-mstackrealign", true, 0, CodeGenOpts.StackRealignment, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mstack-alignment="[1], mstack_alignment, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set the stack alignment", nullptr, nullptr, "-mstack-alignment=", true, 0, CodeGenOpts.StackAlignment, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mstack-probe-size="[1], mstack_probe_size, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set the stack probe size", nullptr, nullptr, "-mstack-probe-size=", true, 0, CodeGenOpts.StackProbeSize, 4096, false, 4096, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mno-stack-arg-probe"[1], mno_stack_arg_probe, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Disable stack probes which are enabled by default", nullptr, nullptr, "-mno-stack-arg-probe", true, 0, CodeGenOpts.NoStackArgProbe, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mthread-model"[1], mthread_model, Separate, m_Group, INVALID, nullptr, CC1Option, 0,
       "The thread model to use, e.g. posix, single (posix by default)", nullptr, "posix,single", "-mthread-model", true, 0, LangOpts->ThreadModel, LangOptions::ThreadModelKind::POSIX, false, LangOptions::ThreadModelKind::POSIX, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 19)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-meabi"[1], meabi, Separate, m_Group, INVALID, nullptr, CC1Option, 0,
       "Set EABI type, e.g. 4, 5 or gnu (default depends on triple)", nullptr, "default,4,5,gnu", "-meabi", true, 0, TargetOpts->EABIVersion, llvm::EABI::Default, false, llvm::EABI::Default, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 20)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mno-tls-direct-seg-refs"[1], mno_tls_direct_seg_refs, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Disable direct TLS access through segment registers", nullptr, nullptr, "-mno-tls-direct-seg-refs", true, 0, CodeGenOpts.IndirectTlsSegRefs, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mspeculative-load-hardening"[1], mspeculative_load_hardening, Flag, m_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "", nullptr, nullptr, "-mspeculative-load-hardening", true, 0, CodeGenOpts.SpeculativeLoadHardening, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_mno_speculative_load_hardening), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mno-speculative-load-hardening"[1], mno_speculative_load_hardening, Flag, m_Group, INVALID, nullptr, CoreOption, 0,
       "", nullptr, nullptr, "-mno-speculative-load-hardening", true, 0, CodeGenOpts.SpeculativeLoadHardening, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_mspeculative_load_hardening), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mcmse"[1], mcmse, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Allow use of CMSE (Armv8-M Security Extensions)", nullptr, nullptr, "-mcmse", true, 0, LangOpts->Cmse, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-faapcs-bitfield-load"[1], ForceAAPCSBitfieldLoad, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Follows the AAPCS standard that all volatile bit-field write generates at least one load. (ARM only).", nullptr, nullptr, "-faapcs-bitfield-load", true, 0, CodeGenOpts.ForceAAPCSBitfieldLoad, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-aapcs-bitfield-width"[1], fno_aapcs_bitfield_width, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Do not follow the AAPCS standard requirement stating that volatile bit-field width is dictated by the field container type. (ARM only).", nullptr, nullptr, "-fno-aapcs-bitfield-width", true, 0, CodeGenOpts.AAPCSBitfieldWidth, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_faapcs_bitfield_width), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-faapcs-bitfield-width"[1], faapcs_bitfield_width, Flag, m_arm_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Follow the AAPCS standard requirement stating that volatile bit-field width is dictated by the field container type. (ARM only).", nullptr, nullptr, "-faapcs-bitfield-width", true, 0, CodeGenOpts.AAPCSBitfieldWidth, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_aapcs_bitfield_width), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mvscale-min="[1], mvscale_min_EQ, Joined, m_aarch64_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the vscale minimum. Defaults to \"1\". (AArch64 only)", nullptr, nullptr, "-mvscale-min=", true, 0, LangOpts->VScaleMin, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mvscale-max="[1], mvscale_max_EQ, Joined, m_aarch64_Features_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Specify the vscale maximum. Defaults to the vector length agnostic value of \"0\". (AArch64 only)", nullptr, nullptr, "-mvscale-max=", true, 0, LangOpts->VScaleMax, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mamdgpu-ieee"[1], mamdgpu_ieee, Flag, m_Group, INVALID, nullptr, 0, 0,
       "Sets the IEEE bit in the expected default floating point  mode register. Floating point opcodes that support exception flag gathering quiet and propagate signaling NaN inputs per IEEE 754-2008. This option changes the ABI. (AMDGPU only)", nullptr, nullptr, "-mamdgpu-ieee", true, 0, CodeGenOpts.EmitIEEENaNCompliantInsts, true, false, false, makeBooleanOptionNormalizer(true, false, OPT_mno_amdgpu_ieee), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mno-amdgpu-ieee"[1], mno_amdgpu_ieee, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-mno-amdgpu-ieee", true, 0, CodeGenOpts.EmitIEEENaNCompliantInsts, true, false, false, makeBooleanOptionNormalizer(false, true, OPT_mamdgpu_ieee), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-munsafe-fp-atomics"[1], munsafe_fp_atomics, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Enable unsafe floating point atomic instructions (AMDGPU only)", nullptr, nullptr, "-munsafe-fp-atomics", true, 0, TargetOpts->AllowAMDGPUUnsafeFPAtomics, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_mno_unsafe_fp_atomics), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-mno-unsafe-fp-atomics"[1], mno_unsafe_fp_atomics, Flag, m_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-mno-unsafe-fp-atomics", true, 0, TargetOpts->AllowAMDGPUUnsafeFPAtomics, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_munsafe_fp_atomics), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mabi=vec-extabi"[1], mabi_EQ_vec_extabi, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Enable the extended Altivec ABI on AIX (AIX only). Uses volatile and nonvolatile vector registers", nullptr, nullptr, "-mabi=vec-extabi", true, 0, LangOpts->EnableAIXExtendedAltivecABI, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fzvector"[1], fzvector, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Enable System z vector language extension", nullptr, nullptr, "-fzvector", true, 0, LangOpts->ZVector, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_zvector), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-zvector"[1], fno_zvector, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-zvector", true, 0, LangOpts->ZVector, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fzvector), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mbackchain"[1], mbackchain, Flag, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "Link stack frames through backchain on System Z", nullptr, nullptr, "-mbackchain", true, 0, CodeGenOpts.Backchain, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_mno_backchain), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mno-backchain"[1], mno_backchain, Flag, m_Group, INVALID, nullptr, NoXarchOption | CC1Option, 0,
       "", nullptr, nullptr, "-mno-backchain", true, 0, CodeGenOpts.Backchain, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_mbackchain), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mrelax-all"[1], mrelax_all, Flag, m_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "(integrated-as) Relax all machine instructions", nullptr, nullptr, "-mrelax-all", true, 0, CodeGenOpts.RelaxAll, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mincremental-linker-compatible"[1], mincremental_linker_compatible, Flag, m_Group, INVALID, nullptr, CC1Option | CC1AsOption, 0,
       "(integrated-as) Emit an object file which can be used with an incremental linker", nullptr, nullptr, "-mincremental-linker-compatible", true, 0, CodeGenOpts.IncrementalLinkerCompatible, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-msoft-float"[1], msoft_float, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use software floating point", nullptr, nullptr, "-msoft-float", true, 0, CodeGenOpts.SoftFloat, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mrecip="[1], mrecip_EQ, CommaJoined, m_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-mrecip=", true, 0, CodeGenOpts.Reciprocals, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mprefer-vector-width="[1], mprefer_vector_width_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Specifies preferred vector width for auto-vectorization. Defaults to 'none' which allows target specific decisions.", nullptr, nullptr, "-mprefer-vector-width=", true, 0, CodeGenOpts.PreferVectorWidth, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mstack-protector-guard="[1], mstack_protector_guard_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given guard (global, tls) for addressing the stack-protector guard", nullptr, nullptr, "-mstack-protector-guard=", true, 0, CodeGenOpts.StackProtectorGuard, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mstack-protector-guard-offset="[1], mstack_protector_guard_offset_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given offset for addressing the stack-protector guard", nullptr, nullptr, "-mstack-protector-guard-offset=", true, 0, CodeGenOpts.StackProtectorGuardOffset, INT_MAX, false, INT_MAX, normalizeStringIntegral<int>, denormalizeString<int>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mstack-protector-guard-reg="[1], mstack_protector_guard_reg_EQ, Joined, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use the given reg for addressing the stack-protector guard", nullptr, nullptr, "-mstack-protector-guard-reg=", true, 0, CodeGenOpts.StackProtectorGuardReg, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mfentry"[1], mfentry, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Insert calls to fentry at function entry (x86/SystemZ only)", nullptr, nullptr, "-mfentry", true, 0, CodeGenOpts.CallFEntry, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mnop-mcount"[1], mnop_mcount, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Generate mcount/__fentry__ calls as nops. To activate they need to be patched in.", nullptr, nullptr, "-mnop-mcount", true, 0, CodeGenOpts.MNopMCount, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mrecord-mcount"[1], mrecord_mcount, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Generate a __mcount_loc section entry for each __fentry__ call.", nullptr, nullptr, "-mrecord-mcount", true, 0, CodeGenOpts.RecordMCount, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mpacked-stack"[1], mpacked_stack, Flag, m_Group, INVALID, nullptr, CC1Option, 0,
       "Use packed stack layout (SystemZ only).", nullptr, nullptr, "-mpacked-stack", true, 0, CodeGenOpts.PackedStack, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-nobuiltininc"[1], nobuiltininc, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Disable builtin #include directories", nullptr, nullptr, "-nobuiltininc", true, 0, HeaderSearchOpts->UseBuiltinIncludes, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-nostdinc++"[1], nostdincxx, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Disable standard #include directories for the C++ standard library", nullptr, nullptr, "-nostdinc++", true, 0, HeaderSearchOpts->UseStandardCXXIncludes, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-o"[1], o, JoinedOrSeparate, INVALID, INVALID, nullptr, NoXarchOption | RenderAsInput | CC1Option | CC1AsOption | FC1Option | FlangOption, 0,
       "Write output to <file>", "<file>", nullptr, "-o", true, 0, FrontendOpts.OutputFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-object-file-name="[1], object_file_name_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | CoreOption, 0,
       "Set the output <file> for debug infos", "<file>", nullptr, "-object-file-name=", true, 0, CodeGenOpts.ObjectFilenameForDebug, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_4, &"-pedantic-errors"[1], pedantic_errors, Flag, pedantic_Group, INVALID, nullptr, CC1Option, 0, nullptr, nullptr, nullptr, "-pedantic-errors", true, 0, DiagnosticOpts->PedanticErrors, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_4, &"-pedantic"[1], pedantic, Flag, pedantic_Group, INVALID, nullptr, CC1Option | FlangOption | FC1Option, 0,
       "Warn on language extensions", nullptr, nullptr, "-pedantic", true, 0, DiagnosticOpts->Pedantic, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-pg"[1], pg, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable mcount instrumentation", nullptr, nullptr, "-pg", true, 0, CodeGenOpts.InstrumentForProfiling, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-print-ivar-layout"[1], print_ivar_layout, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable Objective-C Ivar layout bitmap print trace", nullptr, nullptr, "-print-ivar-layout", true, 0, LangOpts->ObjCGCBitmapPrint, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-pthread"[1], pthread, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Support POSIX threads in generated code", nullptr, nullptr, "-pthread", true, 0, LangOpts->POSIXThreads, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_no_pthread), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-no-pthread"[1], no_pthread, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-no-pthread", true, 0, LangOpts->POSIXThreads, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_pthread), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-resource-dir"[1], resource_dir, Separate, INVALID, INVALID, nullptr, NoXarchOption | CC1Option | CoreOption | HelpHidden, 0,
       "The directory which holds the compiler resource files", nullptr, nullptr, "-resource-dir", true, 0, HeaderSearchOpts->ResourceDir, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_4, &"-print-supported-cpus"[1], print_supported_cpus, Flag, CompileOnly_Group, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Print supported cpu models for the given target (if target is not specified, it will print the supported cpus for the default target)", nullptr, nullptr, "-print-supported-cpus", true, 0, FrontendOpts.PrintSupportedCPUs, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_4, &"-traditional-cpp"[1], traditional_cpp, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Enable some traditional CPP emulation", nullptr, nullptr, "-traditional-cpp", true, 0, LangOpts->TraditionalCPP, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-undef"[1], undef, Flag, u_Group, INVALID, nullptr, CC1Option, 0,
       "undef all system defines", nullptr, nullptr, "-undef", true, 0, PreprocessorOpts->UsePredefines, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-v"[1], v, Flag, INVALID, INVALID, nullptr, CC1Option | CoreOption, 0,
       "Show commands to run and use verbose output", nullptr, nullptr, "-v", true, 0, HeaderSearchOpts->Verbose, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-faltivec-src-compat="[1], altivec_src_compat, Joined, f_Group, INVALID, nullptr, CC1Option, 0,
       "Source-level compatibility for Altivec vectors (for PowerPC targets). This includes results of vector comparison (scalar for 'xl', vector for 'gcc') as well as behavior when initializing with a scalar (splatting for 'xl', element zero only for 'gcc'). For 'mixed', the compatibility is as 'gcc' for 'vector bool/vector pixel' and as 'xl' for other types. Current default is 'mixed'.", nullptr, "mixed,gcc,xl", "-faltivec-src-compat=", true, 0, LangOpts->AltivecSrcCompat, LangOptions::AltivecSrcCompatKind::Mixed, false, LangOptions::AltivecSrcCompatKind::Mixed, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 21)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-w"[1], w, Flag, INVALID, INVALID, nullptr, CC1Option, 0,
       "Suppress all warnings", nullptr, nullptr, "-w", true, 0, DiagnosticOpts->IgnoreWarnings, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-integrated-as"[1], fno_integrated_as, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Disable the integrated assembler", nullptr, nullptr, "-fno-integrated-as", true, 0, CodeGenOpts.DisableIntegratedAS, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fintegrated_as), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fintegrated-as"[1], fintegrated_as, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Enable the integrated assembler", nullptr, nullptr, "-fintegrated-as", true, 0, CodeGenOpts.DisableIntegratedAS, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fno_integrated_as), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef FILE_SYSTEM_OPTION_WITH_MARSHALLING
FILE_SYSTEM_OPTION_WITH_MARSHALLING(prefix_1, &"-working-directory"[1], working_directory, JoinedOrSeparate, INVALID, INVALID, nullptr, CC1Option, 0,
       "Resolve file paths relative to the specified directory", nullptr, nullptr, "-working-directory", true, 0, FileSystemOpts.WorkingDir, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FILE_SYSTEM_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsemantic-interposition"[1], fsemantic_interposition, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "", nullptr, nullptr, "-fsemantic-interposition", true, 0, LangOpts->SemanticInterposition, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_semantic_interposition), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-semantic-interposition"[1], fno_semantic_interposition, Flag, f_Group, INVALID, nullptr, 0, 0,
       "", nullptr, nullptr, "-fno-semantic-interposition", true, 0, LangOpts->SemanticInterposition, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fsemantic_interposition), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-target-cpu"[1], target_cpu, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Target a specific cpu type", nullptr, nullptr, "-target-cpu", true, 0, TargetOpts->CPU, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-tune-cpu"[1], tune_cpu, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Tune for a specific cpu type", nullptr, nullptr, "-tune-cpu", true, 0, TargetOpts->TuneCPU, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-target-feature"[1], target_feature, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Target specific attributes", nullptr, nullptr, "-target-feature", true, 0, TargetOpts->FeaturesAsWritten, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-triple"[1], triple, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Specify target triple (e.g. i686-apple-darwin9)", nullptr, nullptr, "-triple", true, 1, TargetOpts->Triple, llvm::Triple::normalize(llvm::sys::getDefaultTargetTriple()), false, llvm::Triple::normalize(llvm::sys::getDefaultTargetTriple()), normalizeTriple, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-target-abi"[1], target_abi, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Target a particular ABI type", nullptr, nullptr, "-target-abi", true, 0, TargetOpts->ABI, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-target-linker-version"[1], target_linker_version, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Target linker version", nullptr, nullptr, "-target-linker-version", true, 0, TargetOpts->LinkerVersion, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-mfpmath"[1], mfpmath, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Which unit to use for fp math", nullptr, nullptr, "-mfpmath", true, 0, TargetOpts->FPMath, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fpadding-on-unsigned-fixed-point"[1], fpadding_on_unsigned_fixed_point, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Force each unsigned fixed point type to have an extra bit of padding to align their scales with those of signed fixed point types", nullptr, nullptr, "-fpadding-on-unsigned-fixed-point", LangOpts->FixedPoint, 0, LangOpts->PaddingOnUnsignedFixedPoint, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_padding_on_unsigned_fixed_point), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-padding-on-unsigned-fixed-point"[1], fno_padding_on_unsigned_fixed_point, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr, "-fno-padding-on-unsigned-fixed-point", LangOpts->FixedPoint, 0, LangOpts->PaddingOnUnsignedFixedPoint, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fpadding_on_unsigned_fixed_point), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-unoptimized-cfg"[1], analysis_UnoptimizedCFG, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate unoptimized CFGs for all analyses", nullptr, nullptr, "-unoptimized-cfg", true, 0, AnalyzerOpts->UnoptimizedCFG, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-opt-analyze-headers"[1], analyzer_opt_analyze_headers, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Force the static analyzer to analyze functions defined in header files", nullptr, nullptr, "-analyzer-opt-analyze-headers", true, 0, AnalyzerOpts->AnalyzeAll, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-opt-analyze-nested-blocks"[1], analyzer_opt_analyze_nested_blocks, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Analyze the definitions of blocks in addition to functions", nullptr, nullptr, "-analyzer-opt-analyze-nested-blocks", true, 0, AnalyzerOpts->AnalyzeNestedBlocks, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-display-progress"[1], analyzer_display_progress, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit verbose output about the analyzer's progress", nullptr, nullptr, "-analyzer-display-progress", true, 0, AnalyzerOpts->AnalyzerDisplayProgress, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyze-function"[1], analyze_function, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run analysis on specific function (for C++ include parameters in name)", nullptr, nullptr, "-analyze-function", true, 0, AnalyzerOpts->AnalyzeSpecificFunction, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-trim-egraph"[1], trim_egraph, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Only show error-related paths in the analysis graph", nullptr, nullptr, "-trim-egraph", true, 0, AnalyzerOpts->TrimGraph, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-viz-egraph-graphviz"[1], analyzer_viz_egraph_graphviz, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display exploded graph using GraphViz", nullptr, nullptr, "-analyzer-viz-egraph-graphviz", true, 0, AnalyzerOpts->visualizeExplodedGraphWithGraphViz, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-dump-egraph"[1], analyzer_dump_egraph, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump exploded graph to the specified file", nullptr, nullptr, "-analyzer-dump-egraph", true, 0, AnalyzerOpts->DumpExplodedGraphTo, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-inline-max-stack-depth"[1], analyzer_inline_max_stack_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Bound on stack depth while inlining (4 by default)", nullptr, nullptr, "-analyzer-inline-max-stack-depth", true, 0, AnalyzerOpts->InlineMaxStackDepth, 5, false, 5, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-disable-retry-exhausted"[1], analyzer_disable_retry_exhausted, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not re-analyze paths leading to exhausted nodes with a different strategy (may decrease code coverage)", nullptr, nullptr, "-analyzer-disable-retry-exhausted", true, 0, AnalyzerOpts->NoRetryExhausted, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-max-loop"[1], analyzer_max_loop, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The maximum number of times the analyzer will go through a loop", nullptr, nullptr, "-analyzer-max-loop", true, 0, AnalyzerOpts->maxBlockVisitOnPath, 4, false, 4, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-stats"[1], analyzer_stats, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print internal analyzer statistics.", nullptr, nullptr, "-analyzer-stats", true, 0, AnalyzerOpts->PrintStats, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-disable-all-checks"[1], analyzer_disable_all_checks, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable all static analyzer checks", nullptr, nullptr, "-analyzer-disable-all-checks", true, 0, AnalyzerOpts->DisableAllCheckers, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-checker-help"[1], analyzer_checker_help, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of analyzer checkers that are available", nullptr, nullptr, "-analyzer-checker-help", true, 0, AnalyzerOpts->ShowCheckerHelp, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-checker-help-alpha"[1], analyzer_checker_help_alpha, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of in development analyzer checkers. These are NOT considered safe, they are unstable and will emit incorrect reports. Enable ONLY FOR DEVELOPMENT purposes", nullptr, nullptr, "-analyzer-checker-help-alpha", true, 0, AnalyzerOpts->ShowCheckerHelpAlpha, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-checker-help-developer"[1], analyzer_checker_help_developer, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of developer-only checkers such as modeling and debug checkers", nullptr, nullptr, "-analyzer-checker-help-developer", true, 0, AnalyzerOpts->ShowCheckerHelpDeveloper, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-config-help"[1], analyzer_config_help, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of -analyzer-config options. These are meant for development purposes only!", nullptr, nullptr, "-analyzer-config-help", true, 0, AnalyzerOpts->ShowConfigOptionsList, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-list-enabled-checkers"[1], analyzer_list_enabled_checkers, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of enabled analyzer checkers", nullptr, nullptr, "-analyzer-list-enabled-checkers", true, 0, AnalyzerOpts->ShowEnabledCheckerList, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-checker-option-help"[1], analyzer_checker_option_help, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of checker and package options", nullptr, nullptr, "-analyzer-checker-option-help", true, 0, AnalyzerOpts->ShowCheckerOptionList, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-checker-option-help-alpha"[1], analyzer_checker_option_help_alpha, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of in development checker and package options. These are NOT considered safe, they are unstable and will emit incorrect reports. Enable ONLY FOR DEVELOPMENT purposes", nullptr, nullptr, "-analyzer-checker-option-help-alpha", true, 0, AnalyzerOpts->ShowCheckerOptionAlphaList, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-checker-option-help-developer"[1], analyzer_checker_option_help_developer, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Display the list of checker and package options meant for development purposes only", nullptr, nullptr, "-analyzer-checker-option-help-developer", true, 0, AnalyzerOpts->ShowCheckerOptionDeveloperList, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-config-compatibility-mode"[1], analyzer_config_compatibility_mode, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't emit errors on invalid analyzer-config inputs", nullptr, "true,false", "-analyzer-config-compatibility-mode", true, 0, AnalyzerOpts->ShouldEmitErrorsOnInvalidConfigValue, true, false, true, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 22)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef ANALYZER_OPTION_WITH_MARSHALLING
ANALYZER_OPTION_WITH_MARSHALLING(prefix_1, &"-analyzer-werror"[1], analyzer_werror, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit analyzer results as errors rather than warnings", nullptr, nullptr, "-analyzer-werror", true, 0, AnalyzerOpts->AnalyzerWerror, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // ANALYZER_OPTION_WITH_MARSHALLING
#ifdef MIGRATOR_OPTION_WITH_MARSHALLING
MIGRATOR_OPTION_WITH_MARSHALLING(prefix_1, &"-no-ns-alloc-error"[1], migrator_no_nsalloc_error, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not error on use of NSAllocateCollectable/NSReallocateCollectable", nullptr, nullptr, "-no-ns-alloc-error", true, 0, MigratorOpts.NoNSAllocReallocError, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // MIGRATOR_OPTION_WITH_MARSHALLING
#ifdef MIGRATOR_OPTION_WITH_MARSHALLING
MIGRATOR_OPTION_WITH_MARSHALLING(prefix_1, &"-no-finalize-removal"[1], migrator_no_finalize_removal, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not remove finalize method in gc mode", nullptr, nullptr, "-no-finalize-removal", true, 0, MigratorOpts.NoFinalizeRemoval, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // MIGRATOR_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-debug-info-macro"[1], debug_info_macro, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Emit macro debug information", nullptr, nullptr, "-debug-info-macro", true, 0, CodeGenOpts.MacroDebugInfo, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-default-function-attr"[1], default_function_attr, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Apply given attribute to all functions", nullptr, nullptr, "-default-function-attr", true, 0, CodeGenOpts.DefaultFunctionAttrs, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-dwarf-version="[1], dwarf_version_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0, nullptr, nullptr, nullptr, "-dwarf-version=", true, 0, CodeGenOpts.DwarfVersion, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-debugger-tuning="[1], debugger_tuning_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0, nullptr, nullptr, "gdb,lldb,sce,dbx", "-debugger-tuning=", true, 0, CodeGenOpts.DebuggerTuning, llvm::DebuggerKind::Default, false, llvm::DebuggerKind::Default, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 23)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-dwarf-debug-flags"[1], dwarf_debug_flags, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "The string to embed in the Dwarf debug flags record.", nullptr, nullptr, "-dwarf-debug-flags", true, 0, CodeGenOpts.DwarfDebugFlags, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-record-command-line"[1], record_command_line, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "The string to embed in the .LLVM.command.line section.", nullptr, nullptr, "-record-command-line", true, 0, CodeGenOpts.RecordCommandLine, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_4, &"-compress-debug-sections="[1], compress_debug_sections_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "DWARF debug sections compression type", nullptr, "none,zlib,zlib-gnu", "-compress-debug-sections=", true, 0, CodeGenOpts.CompressDebugSections, llvm::DebugCompressionType::None, false, llvm::DebugCompressionType::None, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 24)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mnoexecstack"[1], mno_exec_stack, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Mark the file as not needing an executable stack", nullptr, nullptr, "-mnoexecstack", true, 0, CodeGenOpts.NoExecStack, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-massembler-no-warn"[1], massembler_no_warn, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Make assembler not emit warnings", nullptr, nullptr, "-massembler-no-warn", true, 0, CodeGenOpts.NoWarn, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-massembler-fatal-warnings"[1], massembler_fatal_warnings, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Make assembler warnings fatal", nullptr, nullptr, "-massembler-fatal-warnings", true, 0, CodeGenOpts.FatalWarnings, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_3, &"--mrelax-relocations"[2], mrelax_relocations, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Use relaxable elf relocations", nullptr, nullptr, "--mrelax-relocations", true, 0, CodeGenOpts.RelaxELFRelocations, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-msave-temp-labels"[1], msave_temp_labels, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Save temporary labels in the symbol table. Note this may change .s semantics and shouldn't generally be used on compiler-generated code.", nullptr, nullptr, "-msave-temp-labels", true, 0, CodeGenOpts.SaveTempLabels, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mrelocation-model"[1], mrelocation_model, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "The relocation model to use", nullptr, "static,pic,ropi,rwpi,ropi-rwpi,dynamic-no-pic", "-mrelocation-model", true, 0, CodeGenOpts.RelocationModel, llvm::Reloc::PIC_, false, llvm::Reloc::PIC_, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 25)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-math-builtin"[1], fno_math_builtin, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Disable implicit builtin knowledge of math functions", nullptr, nullptr, "-fno-math-builtin", true, 0, LangOpts->NoMathBuiltin, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-llvm-verifier"[1], disable_llvm_verifier, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't run the LLVM IR verifier pass", nullptr, nullptr, "-disable-llvm-verifier", true, 0, CodeGenOpts.VerifyModule, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-llvm-passes"[1], disable_llvm_passes, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use together with -emit-llvm to get pristine LLVM IR from the frontend by not running any LLVM passes at all", nullptr, nullptr, "-disable-llvm-passes", true, 0, CodeGenOpts.DisableLLVMPasses, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-lifetime-markers"[1], disable_lifetimemarkers, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable lifetime-markers emission even when optimizations are enabled", nullptr, nullptr, "-disable-lifetime-markers", true, 0, CodeGenOpts.DisableLifetimeMarkers, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-O0-optnone"[1], disable_O0_optnone, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable adding the optnone attribute to functions at O0", nullptr, nullptr, "-disable-O0-optnone", true, 0, CodeGenOpts.DisableO0ImplyOptNone, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-red-zone"[1], disable_red_zone, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not emit code that uses the red zone.", nullptr, nullptr, "-disable-red-zone", true, 0, CodeGenOpts.DisableRedZone, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-dwarf-ext-refs"[1], dwarf_ext_refs, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate debug info with external references to clang modules or precompiled headers", nullptr, nullptr, "-dwarf-ext-refs", true, 0, CodeGenOpts.DebugTypeExtRefs, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-dwarf-explicit-import"[1], dwarf_explicit_import, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate explicit import from anonymous namespace to containing scope", nullptr, nullptr, "-dwarf-explicit-import", true, 0, CodeGenOpts.DebugExplicitImport, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-debug-forward-template-params"[1], debug_forward_template_params, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit complete descriptions of template parameters in forward declarations", nullptr, nullptr, "-debug-forward-template-params", true, 0, CodeGenOpts.DebugFwdTemplateParams, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fforbid-guard-variables"[1], fforbid_guard_variables, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit an error if a C++ static local initializer would need a guard variable", nullptr, nullptr, "-fforbid-guard-variables", true, 0, CodeGenOpts.ForbidGuardVariables, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-no-implicit-float"[1], no_implicit_float, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't generate implicit floating point instructions", nullptr, nullptr, "-no-implicit-float", true, 0, CodeGenOpts.NoImplicitFloat, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdump-vtable-layouts"[1], fdump_vtable_layouts, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump the layouts of all vtables that will be emitted in a translation unit", nullptr, nullptr, "-fdump-vtable-layouts", true, 0, LangOpts->DumpVTableLayouts, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fmerge-functions"[1], fmerge_functions, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Permit merging of identical functions when optimizing.", nullptr, nullptr, "-fmerge-functions", true, 0, CodeGenOpts.MergeFunctions, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-coverage-data-file"[1], coverage_data_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit coverage data to this filename.", nullptr, nullptr, "-coverage-data-file", CodeGenOpts.EmitGcovArcs||CodeGenOpts.EmitGcovNotes, 0, CodeGenOpts.CoverageDataFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-coverage-notes-file"[1], coverage_notes_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit coverage notes to this filename.", nullptr, nullptr, "-coverage-notes-file", CodeGenOpts.EmitGcovArcs||CodeGenOpts.EmitGcovNotes, 0, CodeGenOpts.CoverageNotesFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-dump-coverage-mapping"[1], dump_coverage_mapping, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump the coverage mapping records, for testing", nullptr, nullptr, "-dump-coverage-mapping", true, 0, CodeGenOpts.DumpCoverageMapping, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fuse-register-sized-bitfield-access"[1], fuse_register_sized_bitfield_access, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use register sized accesses to bit-fields, when possible.", nullptr, nullptr, "-fuse-register-sized-bitfield-access", true, 0, CodeGenOpts.UseRegisterSizedBitfieldAccess, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-relaxed-aliasing"[1], relaxed_aliasing, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Turn off Type Based Alias Analysis", nullptr, nullptr, "-relaxed-aliasing", true, 0, CodeGenOpts.RelaxedAliasing, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-no-struct-path-tbaa"[1], no_struct_path_tbaa, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Turn off struct-path aware Type Based Alias Analysis", nullptr, nullptr, "-no-struct-path-tbaa", true, 0, CodeGenOpts.StructPathTBAA, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mdebug-pass"[1], mdebug_pass, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable additional debug output", nullptr, nullptr, "-mdebug-pass", true, 0, CodeGenOpts.DebugPass, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mframe-pointer="[1], mframe_pointer_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Specify which frame pointers to retain (all, non-leaf, none).", nullptr, "all,non-leaf,none", "-mframe-pointer=", true, 0, CodeGenOpts.FramePointer, CodeGenOptions::FramePointerKind::None, false, CodeGenOptions::FramePointerKind::None, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 26)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mdisable-tail-calls"[1], mdisable_tail_calls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable tail call optimization, keeping the call stack accurate", nullptr, nullptr, "-mdisable-tail-calls", true, 0, CodeGenOpts.DisableTailCalls, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-menable-no-infs"[1], menable_no_infinities, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow optimization to assume there are no infinities.", nullptr, nullptr, "-menable-no-infs", true, 0, LangOpts->NoHonorInfs, false, false || LangOpts->FiniteMathOnly, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-menable-no-nans"[1], menable_no_nans, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow optimization to assume there are no NaNs.", nullptr, nullptr, "-menable-no-nans", true, 0, LangOpts->NoHonorNaNs, false, false || LangOpts->FiniteMathOnly, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mreassociate"[1], mreassociate, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow reassociation transformations for floating-point instructions", nullptr, nullptr, "-mreassociate", true, 0, LangOpts->AllowFPReassoc, false, false || LangOpts->UnsafeFPMath, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mabi=ieeelongdouble"[1], mabi_EQ_ieeelongdouble, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use IEEE 754 quadruple-precision for long double", nullptr, nullptr, "-mabi=ieeelongdouble", true, 0, LangOpts->PPCIEEELongDouble, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mfloat-abi"[1], mfloat_abi, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The float ABI to use", nullptr, nullptr, "-mfloat-abi", true, 0, CodeGenOpts.FloatABI, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mlimit-float-precision"[1], mlimit_float_precision, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Limit float precision to the given value", nullptr, nullptr, "-mlimit-float-precision", true, 0, CodeGenOpts.LimitFloatPrecision, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mregparm"[1], mregparm, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Limit the number of registers available for integer arguments", nullptr, nullptr, "-mregparm", true, 0, CodeGenOpts.NumRegisterParameters, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-msmall-data-limit"[1], msmall_data_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Put global and static data smaller than the limit into a special section", nullptr, nullptr, "-msmall-data-limit", true, 0, CodeGenOpts.SmallDataLimit, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-funwind-tables="[1], funwind_tables_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate unwinding tables for all functions", nullptr, nullptr, "-funwind-tables=", true, 0, CodeGenOpts.UnwindTables, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mconstructor-aliases"[1], mconstructor_aliases, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable emitting complete constructors and destructors as aliases when possible", nullptr, nullptr, "-mconstructor-aliases", true, 0, CodeGenOpts.CXXCtorDtorAliases, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_mno_constructor_aliases), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-mno-constructor-aliases"[1], mno_constructor_aliases, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable emitting complete constructors and destructors as aliases when possible", nullptr, nullptr, "-mno-constructor-aliases", true, 0, CodeGenOpts.CXXCtorDtorAliases, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_mconstructor_aliases), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-vectorize-loops"[1], vectorize_loops, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run the Loop vectorization passes", nullptr, nullptr, "-vectorize-loops", true, 0, CodeGenOpts.VectorizeLoop, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-vectorize-slp"[1], vectorize_slp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Run the SLP vectorization passes", nullptr, nullptr, "-vectorize-slp", true, 0, CodeGenOpts.VectorizeSLP, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_3, &"--dependent-lib="[2], dependent_lib, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add dependent library", nullptr, nullptr, "--dependent-lib=", true, 0, CodeGenOpts.DependentLibraries, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_3, &"--linker-option="[2], linker_option, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Add linker option", nullptr, nullptr, "--linker-option=", true, 0, CodeGenOpts.LinkerOptions, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-type="[1], fsanitize_coverage_type, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Sanitizer coverage type", nullptr, nullptr, "-fsanitize-coverage-type=", true, 0, CodeGenOpts.SanitizeCoverageType, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-indirect-calls"[1], fsanitize_coverage_indirect_calls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable sanitizer coverage for indirect calls", nullptr, nullptr, "-fsanitize-coverage-indirect-calls", true, 0, CodeGenOpts.SanitizeCoverageIndirectCalls, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-bb"[1], fsanitize_coverage_trace_bb, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable basic block tracing in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-trace-bb", true, 0, CodeGenOpts.SanitizeCoverageTraceBB, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-cmp"[1], fsanitize_coverage_trace_cmp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable cmp instruction tracing in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-trace-cmp", true, 0, CodeGenOpts.SanitizeCoverageTraceCmp, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-div"[1], fsanitize_coverage_trace_div, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable div instruction tracing in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-trace-div", true, 0, CodeGenOpts.SanitizeCoverageTraceDiv, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-gep"[1], fsanitize_coverage_trace_gep, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable gep instruction tracing in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-trace-gep", true, 0, CodeGenOpts.SanitizeCoverageTraceGep, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-8bit-counters"[1], fsanitize_coverage_8bit_counters, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable frequency counters in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-8bit-counters", true, 0, CodeGenOpts.SanitizeCoverage8bitCounters, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-inline-8bit-counters"[1], fsanitize_coverage_inline_8bit_counters, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable inline 8-bit counters in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-inline-8bit-counters", true, 0, CodeGenOpts.SanitizeCoverageInline8bitCounters, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-inline-bool-flag"[1], fsanitize_coverage_inline_bool_flag, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable inline bool flag in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-inline-bool-flag", true, 0, CodeGenOpts.SanitizeCoverageInlineBoolFlag, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-pc-table"[1], fsanitize_coverage_pc_table, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Create a table of coverage-instrumented PCs", nullptr, nullptr, "-fsanitize-coverage-pc-table", true, 0, CodeGenOpts.SanitizeCoveragePCTable, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-pc"[1], fsanitize_coverage_trace_pc, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable PC tracing in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-trace-pc", true, 0, CodeGenOpts.SanitizeCoverageTracePC, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-pc-guard"[1], fsanitize_coverage_trace_pc_guard, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable PC tracing with guard in sanitizer coverage", nullptr, nullptr, "-fsanitize-coverage-trace-pc-guard", true, 0, CodeGenOpts.SanitizeCoverageTracePCGuard, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-no-prune"[1], fsanitize_coverage_no_prune, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable coverage pruning (i.e. instrument all blocks/edges)", nullptr, nullptr, "-fsanitize-coverage-no-prune", true, 0, CodeGenOpts.SanitizeCoverageNoPrune, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-stack-depth"[1], fsanitize_coverage_stack_depth, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable max stack depth tracing", nullptr, nullptr, "-fsanitize-coverage-stack-depth", true, 0, CodeGenOpts.SanitizeCoverageStackDepth, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-loads"[1], fsanitize_coverage_trace_loads, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable tracing of loads", nullptr, nullptr, "-fsanitize-coverage-trace-loads", true, 0, CodeGenOpts.SanitizeCoverageTraceLoads, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fsanitize-coverage-trace-stores"[1], fsanitize_coverage_trace_stores, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable tracing of stores", nullptr, nullptr, "-fsanitize-coverage-trace-stores", true, 0, CodeGenOpts.SanitizeCoverageTraceStores, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fpatchable-function-entry-offset="[1], fpatchable_function_entry_offset_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate M NOPs before function entry", "<M>", nullptr, "-fpatchable-function-entry-offset=", true, 0, CodeGenOpts.PatchableFunctionEntryOffset, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-instrument="[1], fprofile_instrument_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable PGO instrumentation. The accepted value is clang, llvm, or none", nullptr, "none,clang,llvm,csllvm", "-fprofile-instrument=", true, 0, CodeGenOpts.ProfileInstr, CodeGenOptions::ProfileNone, false, CodeGenOptions::ProfileNone, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 27)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-instrument-path="[1], fprofile_instrument_path_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate instrumented code to collect execution counts into <file> (overridden by LLVM_PROFILE_FILE env var)", nullptr, nullptr, "-fprofile-instrument-path=", true, 0, CodeGenOpts.InstrProfileOutput, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fprofile-instrument-use-path="[1], fprofile_instrument_use_path_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Specify the profile path in PGO use compilation", nullptr, nullptr, "-fprofile-instrument-use-path=", true, 0, CodeGenOpts.ProfileInstrumentUsePath, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-flto-visibility-public-std"[1], flto_visibility_public_std, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use public LTO visibility for classes in std and stdext namespaces", nullptr, nullptr, "-flto-visibility-public-std", true, 0, CodeGenOpts.LTOVisibilityPublicStd, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-flto-unit"[1], flto_unit, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit IR to support LTO unit features (CFI, whole program vtable opt)", nullptr, nullptr, "-flto-unit", true, 0, CodeGenOpts.LTOUnit, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_lto_unit), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-lto-unit"[1], fno_lto_unit, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr, "-fno-lto-unit", true, 0, CodeGenOpts.LTOUnit, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_flto_unit), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fdebug-pass-manager"[1], fdebug_pass_manager, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Prints debug information for the new pass manager", nullptr, nullptr, "-fdebug-pass-manager", true, 0, CodeGenOpts.DebugPassManager, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_debug_pass_manager), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-debug-pass-manager"[1], fno_debug_pass_manager, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disables debug printing for the new pass manager", nullptr, nullptr, "-fno-debug-pass-manager", true, 0, CodeGenOpts.DebugPassManager, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdebug_pass_manager), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fverify-debuginfo-preserve"[1], fverify_debuginfo_preserve, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable Debug Info Metadata preservation testing in optimizations.", nullptr, nullptr, "-fverify-debuginfo-preserve", true, 0, CodeGenOpts.EnableDIPreservationVerify, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fverify-debuginfo-preserve-export="[1], fverify_debuginfo_preserve_export, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Export debug info (by testing original Debug Info) failures into specified (JSON) file (should be abs path as we use append mode to insert new JSON objects).", "<file>", nullptr, "-fverify-debuginfo-preserve-export=", true, 0, CodeGenOpts.DIBugsReportFilePath, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fwarn-stack-size="[1], fwarn_stack_size_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr, "-fwarn-stack-size=", true, 0, CodeGenOpts.WarnStackSize, UINT_MAX, false, UINT_MAX, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-mbranch-target-enforce"[1], mbranch_target_enforce, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr, "-mbranch-target-enforce", true, 0, LangOpts->BranchTargetEnforcement, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-dllexport-inlines"[1], fno_dllexport_inlines, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0, nullptr, nullptr, nullptr, "-fno-dllexport-inlines", true, 0, LangOpts->DllExportInlines, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-cfguard-no-checks"[1], cfguard_no_checks, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit Windows Control Flow Guard tables only (no checks)", nullptr, nullptr, "-cfguard-no-checks", true, 0, CodeGenOpts.ControlFlowGuardNoChecks, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-cfguard"[1], cfguard, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit Windows Control Flow Guard tables and checks", nullptr, nullptr, "-cfguard", true, 0, CodeGenOpts.ControlFlowGuard, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-ehcontguard"[1], ehcontguard, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Emit Windows EH Continuation Guard tables", nullptr, nullptr, "-ehcontguard", true, 0, CodeGenOpts.EHContGuard, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-sys-header-deps"[1], sys_header_deps, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include system headers in dependency output", nullptr, nullptr, "-sys-header-deps", true, 0, DependencyOutputOpts.IncludeSystemHeaders, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-module-file-deps"[1], module_file_deps, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include module files in dependency output", nullptr, nullptr, "-module-file-deps", true, 0, DependencyOutputOpts.IncludeModuleFiles, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING(prefix_1, &"-header-include-file"[1], header_include_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename (or -) to write header include output to", nullptr, nullptr, "-header-include-file", true, 0, DependencyOutputOpts.HeaderIncludeOutputFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // DEPENDENCY_OUTPUT_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-diagnostic-log-file"[1], diagnostic_log_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename (or -) to log diagnostics to", nullptr, nullptr, "-diagnostic-log-file", true, 0, DiagnosticOpts->DiagnosticLogFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-format"[1], fdiagnostics_format, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Change diagnostic formatting to match IDE and command line tools", nullptr, "clang,msvc,vi", "-fdiagnostics-format", true, 0, DiagnosticOpts->Format, DiagnosticOptions::Clang, false, DiagnosticOptions::Clang, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 28)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdiagnostics-show-category"[1], fdiagnostics_show_category, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print diagnostic category", nullptr, "none,id,name", "-fdiagnostics-show-category", true, 0, DiagnosticOpts->ShowCategories, 0, false, 0, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 29)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-diagnostics-use-presumed-location"[1], fno_diagnostics_use_presumed_location, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Ignore #line directives when displaying diagnostic locations", nullptr, nullptr, "-fno-diagnostics-use-presumed-location", true, 0, DiagnosticOpts->ShowPresumedLoc, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-ftabstop"[1], ftabstop, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the tab stop distance.", "<N>", nullptr, "-ftabstop", true, 0, DiagnosticOpts->TabStop, DiagnosticOptions::DefaultTabStop, false, DiagnosticOptions::DefaultTabStop, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-ferror-limit"[1], ferror_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of errors to emit before stopping (0 = no limit).", "<N>", nullptr, "-ferror-limit", true, 0, DiagnosticOpts->ErrorLimit, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmacro-backtrace-limit"[1], fmacro_backtrace_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of entries to print in a macro expansion backtrace (0 = no limit).", "<N>", nullptr, "-fmacro-backtrace-limit", true, 0, DiagnosticOpts->MacroBacktraceLimit, DiagnosticOptions::DefaultMacroBacktraceLimit, false, DiagnosticOptions::DefaultMacroBacktraceLimit, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-ftemplate-backtrace-limit"[1], ftemplate_backtrace_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of entries to print in a template instantiation backtrace (0 = no limit).", "<N>", nullptr, "-ftemplate-backtrace-limit", true, 0, DiagnosticOpts->TemplateBacktraceLimit, DiagnosticOptions::DefaultTemplateBacktraceLimit, false, DiagnosticOptions::DefaultTemplateBacktraceLimit, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fconstexpr-backtrace-limit"[1], fconstexpr_backtrace_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of entries to print in a constexpr evaluation backtrace (0 = no limit).", "<N>", nullptr, "-fconstexpr-backtrace-limit", true, 0, DiagnosticOpts->ConstexprBacktraceLimit, DiagnosticOptions::DefaultConstexprBacktraceLimit, false, DiagnosticOptions::DefaultConstexprBacktraceLimit, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fspell-checking-limit"[1], fspell_checking_limit, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of times to perform spell checking on unrecognized identifiers (0 = no limit).", "<N>", nullptr, "-fspell-checking-limit", true, 0, DiagnosticOpts->SpellCheckingLimit, DiagnosticOptions::DefaultSpellCheckingLimit, false, DiagnosticOptions::DefaultSpellCheckingLimit, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcaret-diagnostics-max-lines"[1], fcaret_diagnostics_max_lines, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the maximum number of source lines to show in a caret diagnostic", "<N>", nullptr, "-fcaret-diagnostics-max-lines", true, 0, DiagnosticOpts->SnippetLineLimit, DiagnosticOptions::DefaultSnippetLineLimit, false, DiagnosticOptions::DefaultSnippetLineLimit, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef DIAG_OPTION_WITH_MARSHALLING
DIAG_OPTION_WITH_MARSHALLING(prefix_1, &"-Wno-rewrite-macros"[1], Wno_rewrite_macros, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Silence ObjC rewriting warnings", nullptr, nullptr, "-Wno-rewrite-macros", true, 0, DiagnosticOpts->NoRewriteMacros, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // DIAG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-ast-merge"[1], ast_merge, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Merge the given AST file into the translation unit being compiled.", "<ast file>", nullptr, "-ast-merge", true, 0, FrontendOpts.ASTMergeFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-aux-triple"[1], aux_triple, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Auxiliary target triple.", nullptr, nullptr, "-aux-triple", true, 0, FrontendOpts.AuxTriple, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-code-completion-macros"[1], code_completion_macros, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include macros in code-completion results", nullptr, nullptr, "-code-completion-macros", true, 0, FrontendOpts.CodeCompleteOpts.IncludeMacros, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-code-completion-patterns"[1], code_completion_patterns, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include code patterns in code-completion results", nullptr, nullptr, "-code-completion-patterns", true, 0, FrontendOpts.CodeCompleteOpts.IncludeCodePatterns, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-no-code-completion-globals"[1], no_code_completion_globals, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not include global declarations in code-completion results.", nullptr, nullptr, "-no-code-completion-globals", true, 0, FrontendOpts.CodeCompleteOpts.IncludeGlobals, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-no-code-completion-ns-level-decls"[1], no_code_completion_ns_level_decls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not include declarations inside namespaces (incl. global namespace) in the code-completion results.", nullptr, nullptr, "-no-code-completion-ns-level-decls", true, 0, FrontendOpts.CodeCompleteOpts.IncludeNamespaceLevelDecls, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-code-completion-brief-comments"[1], code_completion_brief_comments, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include brief documentation comments in code-completion results.", nullptr, nullptr, "-code-completion-brief-comments", true, 0, FrontendOpts.CodeCompleteOpts.IncludeBriefComments, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-code-completion-with-fixits"[1], code_completion_with_fixits, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include code completion results which require small fix-its.", nullptr, nullptr, "-code-completion-with-fixits", true, 0, FrontendOpts.CodeCompleteOpts.IncludeFixIts, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-free"[1], disable_free, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable freeing of memory on exit", nullptr, nullptr, "-disable-free", true, 0, FrontendOpts.DisableFree, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-clear-ast-before-backend"[1], clear_ast_before_backend, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Clear the Clang AST before running backend code generation", nullptr, nullptr, "-clear-ast-before-backend", true, 0, CodeGenOpts.ClearASTBeforeBackend, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_no_clear_ast_before_backend), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-no-clear-ast-before-backend"[1], no_clear_ast_before_backend, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't clear the Clang AST before running backend code generation", nullptr, nullptr, "-no-clear-ast-before-backend", true, 0, CodeGenOpts.ClearASTBeforeBackend, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_clear_ast_before_backend), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-enable-noundef-analysis"[1], enable_noundef_analysis, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable analyzing function argument and return types for mandatory definedness", nullptr, nullptr, "-enable-noundef-analysis", true, 0, CodeGenOpts.EnableNoundefAttrs, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-discard-value-names"[1], discard_value_names, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Discard value names in LLVM IR", nullptr, nullptr, "-discard-value-names", true, 0, CodeGenOpts.DiscardValueNames, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-add-plugin"[1], add_plugin, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the named plugin action in addition to the default action", "<name>", nullptr, "-add-plugin", true, 0, FrontendOpts.AddPluginActions, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-ast-dump-filter"[1], ast_dump_filter, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use with -ast-dump or -ast-print to dump/print only AST declaration nodes having a certain substring in a qualified name. Use -ast-list to list all filterable declaration node names.", "<dump_filter>", nullptr, "-ast-dump-filter", true, 0, FrontendOpts.ASTDumpFilter, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-modules-global-index"[1], fno_modules_global_index, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not automatically generate or update the global module index", nullptr, nullptr, "-fno-modules-global-index", true, 0, FrontendOpts.UseGlobalModuleIndex, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-modules-error-recovery"[1], fno_modules_error_recovery, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Do not automatically import modules for error recovery", nullptr, nullptr, "-fno-modules-error-recovery", true, 0, LangOpts->ModulesErrorRecovery, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodule-map-file-home-is-cwd"[1], fmodule_map_file_home_is_cwd, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the current working directory as the home directory of module maps specified by -fmodule-map-file=<FILE>", nullptr, nullptr, "-fmodule-map-file-home-is-cwd", true, 0, HeaderSearchOpts->ModuleMapFileHomeIsCwd, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodule-feature"[1], fmodule_feature, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable <feature> in module map requires declarations", "<feature>", nullptr, "-fmodule-feature", true, 0, LangOpts->ModuleFeatures, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-embed-file="[1], fmodules_embed_file_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Embed the contents of the specified file into the module file being compiled.", "<file>", nullptr, "-fmodules-embed-file=", true, 0, FrontendOpts.ModulesEmbedFiles, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-embed-all-files"[1], fmodules_embed_all_files, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Embed the contents of all files read by this compilation into the produced module file.", nullptr, nullptr, "-fmodules-embed-all-files", true, 0, FrontendOpts.ModulesEmbedAllFiles, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-implicit-modules-use-lock"[1], fno_fimplicit_modules_use_lock, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr, "-fno-implicit-modules-use-lock", true, 0, FrontendOpts.BuildingImplicitModuleUsesLock, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_ffimplicit_modules_use_lock), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fimplicit-modules-use-lock"[1], ffimplicit_modules_use_lock, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use filesystem locks for implicit modules builds to avoid duplicating work in competing clang invocations.", nullptr, nullptr, "-fimplicit-modules-use-lock", true, 0, FrontendOpts.BuildingImplicitModuleUsesLock, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_fimplicit_modules_use_lock), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-local-submodule-visibility"[1], fmodules_local_submodule_visibility, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enforce name visibility rules across submodules of the same top-level module.", nullptr, nullptr, "-fmodules-local-submodule-visibility", true, 0, LangOpts->ModulesLocalVisibility, false, false || LangOpts->ModulesTS || LangOpts->CPlusPlusModules, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-codegen"[1], fmodules_codegen, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate code for uses of this module that assumes an explicit object file will be built for the module", nullptr, nullptr, "-fmodules-codegen", true, 0, LangOpts->ModulesCodegen, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-debuginfo"[1], fmodules_debuginfo, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate debug info for types in an object file built from this module and do not generate them elsewhere", nullptr, nullptr, "-fmodules-debuginfo", true, 0, LangOpts->ModulesDebugInfo, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodule-format="[1], fmodule_format_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Select the container format for clang modules and PCH. Supported options are 'raw' and 'obj'.", nullptr, nullptr, "-fmodule-format=", true, 0, HeaderSearchOpts->ModuleFormat, "raw", false, "raw", normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-concept-satisfaction-caching"[1], fno_concept_satisfaction_caching, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable satisfaction caching for C++2a Concepts.", nullptr, nullptr, "-fno-concept-satisfaction-caching", true, 0, LangOpts->ConceptSatisfactionCaching, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-recovery-ast"[1], fno_recovery_ast, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr, "-fno-recovery-ast", true, 0, LangOpts->RecoveryAST, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_frecovery_ast), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-frecovery-ast"[1], frecovery_ast, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve expressions in AST rather than dropping them when encountering semantic errors", nullptr, nullptr, "-frecovery-ast", true, 0, LangOpts->RecoveryAST, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_recovery_ast), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-recovery-ast-type"[1], fno_recovery_ast_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "", nullptr, nullptr, "-fno-recovery-ast-type", true, 0, LangOpts->RecoveryASTType, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_frecovery_ast_type), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-frecovery-ast-type"[1], frecovery_ast_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve the type for recovery expressions when possible", nullptr, nullptr, "-frecovery-ast-type", true, 0, LangOpts->RecoveryASTType, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_recovery_ast_type), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-ast-dump-decl-types"[1], ast_dump_decl_types, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Include declaration types in AST dumps", nullptr, nullptr, "-ast-dump-decl-types", true, 0, FrontendOpts.ASTDumpDeclTypes, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-ast-dump-lookups"[1], ast_dump_lookups, Flag, Action_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Build ASTs and then debug dump their name lookup tables", nullptr, nullptr, "-ast-dump-lookups", true, 0, FrontendOpts.ASTDumpLookups, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-emit-llvm-uselists"[1], emit_llvm_uselists, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve order of LLVM use-lists when serializing", nullptr, nullptr, "-emit-llvm-uselists", true, 0, CodeGenOpts.EmitLLVMUseLists, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_no_emit_llvm_uselists), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-no-emit-llvm-uselists"[1], no_emit_llvm_uselists, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't preserve order of LLVM use-lists when serializing", nullptr, nullptr, "-no-emit-llvm-uselists", true, 0, CodeGenOpts.EmitLLVMUseLists, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_emit_llvm_uselists), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-mt-migrate-directory"[1], mt_migrate_directory, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Directory for temporary files produced during ARC or ObjC migration", nullptr, nullptr, "-mt-migrate-directory", true, 0, FrontendOpts.MTMigrateDir, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-arcmt-action="[1], arcmt_action_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "The ARC migration action to take", nullptr, "check,modify,migrate", "-arcmt-action=", true, 0, FrontendOpts.ARCMTAction, FrontendOptions::ARCMT_None, false, FrontendOptions::ARCMT_None, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 30)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-opt-record-file"[1], opt_record_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "File name to use for YAML optimization record output", nullptr, nullptr, "-opt-record-file", true, 0, CodeGenOpts.OptRecordFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-print-stats"[1], print_stats, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Print performance metrics and statistics", nullptr, nullptr, "-print-stats", true, 0, FrontendOpts.ShowStats, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-stats-file="[1], stats_file, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Filename to write statistics to", nullptr, nullptr, "-stats-file=", true, 0, FrontendOpts.StatsFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdump-record-layouts-simple"[1], fdump_record_layouts_simple, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information in a simple form used for testing", nullptr, nullptr, "-fdump-record-layouts-simple", true, 0, LangOpts->DumpRecordLayoutsSimple, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdump-record-layouts-canonical"[1], fdump_record_layouts_canonical, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information with canonical field types", nullptr, nullptr, "-fdump-record-layouts-canonical", true, 0, LangOpts->DumpRecordLayoutsCanonical, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdump-record-layouts-complete"[1], fdump_record_layouts_complete, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information for all complete types", nullptr, nullptr, "-fdump-record-layouts-complete", true, 0, LangOpts->DumpRecordLayoutsComplete, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdump-record-layouts"[1], fdump_record_layouts, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump record layout information", nullptr, nullptr, "-fdump-record-layouts", true, 0, LangOpts->DumpRecordLayouts, false, false || LangOpts->DumpRecordLayoutsSimple || LangOpts->DumpRecordLayoutsComplete || LangOpts->DumpRecordLayoutsCanonical, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fix-what-you-can"[1], fix_what_you_can, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it advice even in the presence of unfixable errors", nullptr, nullptr, "-fix-what-you-can", true, 0, FrontendOpts.FixWhatYouCan, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fix-only-warnings"[1], fix_only_warnings, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it advice only for warnings, not errors", nullptr, nullptr, "-fix-only-warnings", true, 0, FrontendOpts.FixOnlyWarnings, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fixit-recompile"[1], fixit_recompile, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it changes and recompile", nullptr, nullptr, "-fixit-recompile", true, 0, FrontendOpts.FixAndRecompile, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fixit-to-temporary"[1], fixit_to_temp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply fix-it changes to temporary files", nullptr, nullptr, "-fixit-to-temporary", true, 0, FrontendOpts.FixToTemporaries, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-foverride-record-layout="[1], foverride_record_layout_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Override record layouts with those in the given file", nullptr, nullptr, "-foverride-record-layout=", true, 0, FrontendOpts.OverrideRecordLayoutsFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-pch-through-header="[1], pch_through_header_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Stop PCH generation after including this file.  When using a PCH, skip tokens until after this file is included.", nullptr, nullptr, "-pch-through-header=", true, 0, PreprocessorOpts->PCHThroughHeader, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-pch-through-hdrstop-create"[1], pch_through_hdrstop_create, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "When creating a PCH, stop PCH generation after #pragma hdrstop.", nullptr, nullptr, "-pch-through-hdrstop-create", true, 0, PreprocessorOpts->PCHWithHdrStopCreate, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-pch-timestamp"[1], fno_pch_timestamp, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable inclusion of timestamp in precompiled headers", nullptr, nullptr, "-fno-pch-timestamp", true, 0, FrontendOpts.IncludeTimestamps, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-building-pch-with-obj"[1], building_pch_with_obj, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "This compilation is part of building a PCH with corresponding object file.", nullptr, nullptr, "-building-pch-with-obj", true, 0, LangOpts->BuildingPCHWithObjectFile, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-faligned-alloc-unavailable"[1], aligned_alloc_unavailable, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Aligned allocation/deallocation functions are unavailable", nullptr, nullptr, "-faligned-alloc-unavailable", LangOpts->AlignedAllocation, 0, LangOpts->AlignedAllocationUnavailable, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-version"[1], version, Flag, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Print the compiler version", nullptr, nullptr, "-version", true, 0, FrontendOpts.ShowVersion, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-main-file-name"[1], main_file_name, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "Main file name to use for debug info and source if missing", nullptr, nullptr, "-main-file-name", true, 0, CodeGenOpts.MainFileName, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-split-dwarf-output"[1], split_dwarf_output, Separate, INVALID, INVALID, nullptr, CC1Option | CC1AsOption | NoDriverOption, 0,
       "File name to use for split dwarf debug info output", nullptr, nullptr, "-split-dwarf-output", true, 0, CodeGenOpts.SplitDwarfOutput, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fblocks-runtime-optional"[1], fblocks_runtime_optional, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Weakly link in the blocks runtime", nullptr, nullptr, "-fblocks-runtime-optional", true, 0, LangOpts->BlocksRuntimeOptional, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fexternc-nounwind"[1], fexternc_nounwind, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Assume all functions with C linkage do not unwind", nullptr, nullptr, "-fexternc-nounwind", true, 0, LangOpts->ExternCNoUnwind, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-split-dwarf-file"[1], split_dwarf_file, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Name of the split dwarf debug info file to encode in the object file", nullptr, nullptr, "-split-dwarf-file", true, 0, CodeGenOpts.SplitDwarfFile, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-wchar"[1], fno_wchar, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable C++ builtin type wchar_t", nullptr, nullptr, "-fno-wchar", LangOpts->CPlusPlus, 0, LangOpts->WChar, LangOpts->CPlusPlus, false, LangOpts->CPlusPlus, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fconstant-string-class"[1], fconstant_string_class, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Specify the class to use for constant Objective-C string objects.", "<class name>", nullptr, "-fconstant-string-class", true, 0, LangOpts->ObjCConstantStringClass, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-arc-cxxlib="[1], fobjc_arc_cxxlib_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Objective-C++ Automatic Reference Counting standard library kind", nullptr, "libc++,libstdc++,none", "-fobjc-arc-cxxlib=", true, 0, PreprocessorOpts->ObjCXXARCStandardLibrary, ARCXX_nolib, false, ARCXX_nolib, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 31)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fobjc-dispatch-method="[1], fobjc_dispatch_method_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Objective-C dispatch method to use", nullptr, "legacy,non-legacy,mixed", "-fobjc-dispatch-method=", true, 0, CodeGenOpts.ObjCDispatchMethod, CodeGenOptions::Legacy, false, CodeGenOptions::Legacy, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 32)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-objc-default-synthesize-properties"[1], disable_objc_default_synthesize_properties, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "disable the default synthesis of Objective-C properties", nullptr, nullptr, "-disable-objc-default-synthesize-properties", true, 0, LangOpts->ObjCDefaultSynthProperties, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fencode-extended-block-signature"[1], fencode_extended_block_signature, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "enable extended encoding of block type signature", nullptr, nullptr, "-fencode-extended-block-signature", true, 0, LangOpts->EncodeExtendedBlockSig, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-function-alignment"[1], function_alignment, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "default alignment for functions", nullptr, nullptr, "-function-alignment", true, 0, LangOpts->FunctionAlignment, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-pic-level"[1], pic_level, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Value for __PIC__", nullptr, nullptr, "-pic-level", true, 0, LangOpts->PICLevel, 0, false, 0, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-pic-is-pie"[1], pic_is_pie, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "File is for a position independent executable", nullptr, nullptr, "-pic-is-pie", true, 0, LangOpts->PIE, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fhalf-no-semantic-interposition"[1], fhalf_no_semantic_interposition, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Like -fno-semantic-interposition but don't use local aliases", nullptr, nullptr, "-fhalf-no-semantic-interposition", true, 0, LangOpts->HalfNoSemanticInterposition, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-validate-pch"[1], fno_validate_pch, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable validation of precompiled headers", nullptr, nullptr, "-fno-validate-pch", true, 0, PreprocessorOpts->DisablePCHOrModuleValidation, DisableValidationForModuleKind::None, false, DisableValidationForModuleKind::None, makeFlagToValueNormalizer(DisableValidationForModuleKind::All), denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef FRONTEND_OPTION_WITH_MARSHALLING
FRONTEND_OPTION_WITH_MARSHALLING(prefix_1, &"-fallow-pcm-with-compiler-errors"[1], fallow_pcm_with_errors, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Accept a PCM file that was created with compiler errors", nullptr, nullptr, "-fallow-pcm-with-compiler-errors", true, 0, FrontendOpts.AllowPCMWithCompilerErrors, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // FRONTEND_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-fallow-pch-with-compiler-errors"[1], fallow_pch_with_errors, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Accept a PCH file that was created with compiler errors", nullptr, nullptr, "-fallow-pch-with-compiler-errors", true, 0, PreprocessorOpts->AllowPCHWithCompilerErrors, false, false || FrontendOpts.AllowPCMWithCompilerErrors, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-fallow-pch-with-different-modules-cache-path"[1], fallow_pch_with_different_modules_cache_path, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Accept a PCH file that was created with a different modules cache path", nullptr, nullptr, "-fallow-pch-with-different-modules-cache-path", true, 0, PreprocessorOpts->AllowPCHWithDifferentModulesCachePath, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-dump-deserialized-decls"[1], dump_deserialized_pch_decls, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Dump declarations that are deserialized from PCH, for testing", nullptr, nullptr, "-dump-deserialized-decls", true, 0, PreprocessorOpts->DumpDeserializedPCHDecls, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-static-define"[1], static_define, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Should __STATIC__ be defined", nullptr, nullptr, "-static-define", true, 0, LangOpts->Static, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-stack-protector"[1], stack_protector, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable stack protectors", nullptr, "0,1,2,3", "-stack-protector", true, 0, LangOpts->StackProtector, LangOptions::SSPOff, false, LangOptions::SSPOff, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 33)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-stack-protector-buffer-size"[1], stack_protector_buffer_size, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Lower bound for a buffer to be considered for stack protection", nullptr, nullptr, "-stack-protector-buffer-size", true, 0, CodeGenOpts.SSPBufferSize, 8, false, 8, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fvisibility"[1], fvisibility, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Default type and symbol visibility", nullptr, "default,hidden,internal,protected", "-fvisibility", true, 1, LangOpts->ValueVisibilityMode, DefaultVisibility, false, DefaultVisibility, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 34)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ftype-visibility"[1], ftype_visibility, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Default type visibility", nullptr, "default,hidden,internal,protected", "-ftype-visibility", true, 0, LangOpts->TypeVisibilityMode, LangOpts->ValueVisibilityMode, false, LangOpts->ValueVisibilityMode, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 35)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fapply-global-visibility-to-externs"[1], fapply_global_visibility_to_externs, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Apply global symbol visibility to external declarations without an explicit visibility", nullptr, nullptr, "-fapply-global-visibility-to-externs", true, 0, LangOpts->SetVisibilityForExternDecls, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ftemplate-depth"[1], ftemplate_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum depth of recursive template instantiation", nullptr, nullptr, "-ftemplate-depth", true, 0, LangOpts->InstantiationDepth, 1024, false, 1024, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-foperator-arrow-depth"[1], foperator_arrow_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum number of 'operator->'s to call for a member access", nullptr, nullptr, "-foperator-arrow-depth", true, 0, LangOpts->ArrowDepth, 256, false, 256, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fconstexpr-depth"[1], fconstexpr_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum depth of recursive constexpr function calls", nullptr, nullptr, "-fconstexpr-depth", true, 0, LangOpts->ConstexprCallDepth, 512, false, 512, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fconstexpr-steps"[1], fconstexpr_steps, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum number of steps in constexpr function evaluation", nullptr, nullptr, "-fconstexpr-steps", true, 0, LangOpts->ConstexprStepLimit, 1048576, false, 1048576, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fbracket-depth"[1], fbracket_depth, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Maximum nesting level for parentheses, brackets, and braces", nullptr, nullptr, "-fbracket-depth", true, 0, LangOpts->BracketDepth, 256, false, 256, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fconst-strings"[1], fconst_strings, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use a const qualified type for string literals in C and ObjC", nullptr, nullptr, "-fconst-strings", true, 0, LangOpts->ConstStrings, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_const_strings), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-const-strings"[1], fno_const_strings, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't use a const qualified type for string literals in C and ObjC", nullptr, nullptr, "-fno-const-strings", true, 0, LangOpts->ConstStrings, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fconst_strings), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-bitfield-type-align"[1], fno_bitfield_type_align, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Ignore bit-field types when aligning structures", nullptr, nullptr, "-fno-bitfield-type-align", true, 0, LangOpts->NoBitFieldTypeAlign, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-ffake-address-space-map"[1], ffake_address_space_map, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use a fake address space map; OpenCL testing purposes only", nullptr, nullptr, "-ffake-address-space-map", true, 0, LangOpts->FakeAddressSpaceMap, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-faddress-space-map-mangling="[1], faddress_space_map_mangling_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set the mode for address space map based mangling; OpenCL testing purposes only", "<yes|no|target>", "target,no,yes", "-faddress-space-map-mangling=", true, 0, LangOpts->AddressSpaceMapMangling, LangOptions::ASMM_Target, false, LangOptions::ASMM_Target, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 36)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-funknown-anytype"[1], funknown_anytype, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable parser support for the __unknown_anytype type; for testing purposes only", nullptr, nullptr, "-funknown-anytype", true, 0, LangOpts->ParseUnknownAnytype, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdebugger-support"[1], fdebugger_support, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable special debugger support behavior", nullptr, nullptr, "-fdebugger-support", true, 0, LangOpts->DebuggerSupport, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdebugger-cast-result-to-id"[1], fdebugger_cast_result_to_id, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable casting unknown expression results to id", nullptr, nullptr, "-fdebugger-cast-result-to-id", true, 0, LangOpts->DebuggerCastResultToId, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdebugger-objc-literal"[1], fdebugger_objc_literal, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable special debugger support for Objective-C subscripting and literals", nullptr, nullptr, "-fdebugger-objc-literal", true, 0, LangOpts->DebuggerObjCLiteral, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdeprecated-macro"[1], fdeprecated_macro, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Defines the __DEPRECATED macro", nullptr, nullptr, "-fdeprecated-macro", true, 0, LangOpts->Deprecated, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_deprecated_macro), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-deprecated-macro"[1], fno_deprecated_macro, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Undefines the __DEPRECATED macro", nullptr, nullptr, "-fno-deprecated-macro", true, 0, LangOpts->Deprecated, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fdeprecated_macro), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-vtordisp-mode="[1], vtordisp_mode_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Control vtordisp placement on win32 targets", nullptr, nullptr, "-vtordisp-mode=", true, 0, LangOpts->VtorDispMode, 1, false, 1, normalizeStringIntegral<unsigned>, denormalizeString<unsigned>, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fnative-half-type"[1], fnative_half_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the native half type for __fp16 instead of promoting to float", nullptr, nullptr, "-fnative-half-type", true, 0, LangOpts->NativeHalfType, false, false || LangOpts->OpenCL || LangOpts->RenderScript, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fnative-half-arguments-and-returns"[1], fnative_half_arguments_and_returns, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use the native __fp16 type for arguments and returns (and skip ABI-specific lowering)", nullptr, nullptr, "-fnative-half-arguments-and-returns", true, 0, LangOpts->NativeHalfArgsAndReturns, false, false || LangOpts->OpenCL || LangOpts->RenderScript, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fallow-half-arguments-and-returns"[1], fallow_half_arguments_and_returns, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow function arguments and returns of type half", nullptr, nullptr, "-fallow-half-arguments-and-returns", true, 0, LangOpts->HalfArgsAndReturns, false, false || LangOpts->NativeHalfArgsAndReturns, true, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fdefault-calling-conv="[1], fdefault_calling_conv_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set default calling convention", nullptr, "cdecl,fastcall,stdcall,vectorcall,regcall", "-fdefault-calling-conv=", true, 0, LangOpts->DefaultCallingConv, LangOptions::DCC_None, false, LangOptions::DCC_None, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 37)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fpreserve-vec3-type"[1], fpreserve_vec3_type, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Preserve 3-component vector type", nullptr, nullptr, "-fpreserve-vec3-type", true, 0, CodeGenOpts.PreserveVec3Type, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fwchar-type="[1], fwchar_type_EQ, Joined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Select underlying type for wchar_t", nullptr, "char,short,int", "-fwchar-type=", true, 0, LangOpts->WCharSize, 0, false, 0, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 38)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-signed-wchar"[1], fno_signed_wchar, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use an unsigned type for wchar_t", nullptr, nullptr, "-fno-signed-wchar", true, 0, LangOpts->WCharIsSigned, true, false, true, makeBooleanOptionNormalizer(false, true, OPT_fsigned_wchar), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsigned-wchar"[1], fsigned_wchar, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Use a signed type for wchar_t", nullptr, nullptr, "-fsigned-wchar", true, 0, LangOpts->WCharIsSigned, true, false, true, makeBooleanOptionNormalizer(true, false, OPT_fno_signed_wchar), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcompatibility-qualified-id-block-type-checking"[1], fcompatibility_qualified_id_block_param_type_checking, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow using blocks with parameters of more specific type than the type system guarantees when a parameter is qualified id", nullptr, nullptr, "-fcompatibility-qualified-id-block-type-checking", true, 0, LangOpts->CompatibilityQualifiedIdBlockParamTypeChecking, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fpass-by-value-is-noalias"[1], fpass_by_value_is_noalias, Flag, f_Group, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allows assuming by-value parameters do not alias any other value. Has no effect on non-trivially-copyable classes in C++.", nullptr, nullptr, "-fpass-by-value-is-noalias", true, 0, CodeGenOpts.PassByValueIsNoAlias, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-nostdsysteminc"[1], nostdsysteminc, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable standard system #include directories", nullptr, nullptr, "-nostdsysteminc", true, 0, HeaderSearchOpts->UseStandardSystemIncludes, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fdisable-module-hash"[1], fdisable_module_hash, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable the module hash", nullptr, nullptr, "-fdisable-module-hash", true, 0, HeaderSearchOpts->DisableModuleHash, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-hash-content"[1], fmodules_hash_content, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable hashing the content of a module file", nullptr, nullptr, "-fmodules-hash-content", true, 0, HeaderSearchOpts->ModulesHashContent, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef HEADER_SEARCH_OPTION_WITH_MARSHALLING
HEADER_SEARCH_OPTION_WITH_MARSHALLING(prefix_1, &"-fmodules-strict-context-hash"[1], fmodules_strict_context_hash, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Enable hashing of all compiler options that could impact the semantics of a module in an implicit build", nullptr, nullptr, "-fmodules-strict-context-hash", true, 0, HeaderSearchOpts->ModulesStrictContextHash, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // HEADER_SEARCH_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-detailed-preprocessing-record"[1], detailed_preprocessing_record, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "include a detailed record of preprocessing actions", nullptr, nullptr, "-detailed-preprocessing-record", true, 0, PreprocessorOpts->DetailedRecord, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-setup-static-analyzer"[1], setup_static_analyzer, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Set up preprocessor for static analyzer (done automatically when static analyzer is run).", nullptr, nullptr, "-setup-static-analyzer", true, 0, PreprocessorOpts->SetUpStaticAnalyzer, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef PREPROCESSOR_OPTION_WITH_MARSHALLING
PREPROCESSOR_OPTION_WITH_MARSHALLING(prefix_1, &"-disable-pragma-debug-crash"[1], disable_pragma_debug_crash, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Disable any #pragma clang __debug that can lead to crashing behavior. This is meant for testing.", nullptr, nullptr, "-disable-pragma-debug-crash", true, 0, PreprocessorOpts->DisablePragmaDebugCrash, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // PREPROCESSOR_OPTION_WITH_MARSHALLING
#ifdef TARGET_OPTION_WITH_MARSHALLING
TARGET_OPTION_WITH_MARSHALLING(prefix_1, &"-cl-ext="[1], cl_ext_EQ, CommaJoined, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "OpenCL only. Enable or disable OpenCL extensions. The argument is a comma-separated sequence of one or more extension names, each prefixed by '+' or '-'.", nullptr, nullptr, "-cl-ext=", true, 0, TargetOpts->OpenCLExtensionsAsWritten, std::vector<std::string>({}), false, std::vector<std::string>({}), normalizeStringVector, denormalizeStringVector, mergeForwardValue, extractForwardValue, -1)
#endif // TARGET_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcuda-is-device"[1], fcuda_is_device, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate code for CUDA device", nullptr, nullptr, "-fcuda-is-device", true, 0, LangOpts->CUDAIsDevice, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef CODEGEN_OPTION_WITH_MARSHALLING
CODEGEN_OPTION_WITH_MARSHALLING(prefix_1, &"-fcuda-include-gpubinary"[1], fcuda_include_gpubinary, Separate, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Incorporate CUDA device-side binary into host object file.", nullptr, nullptr, "-fcuda-include-gpubinary", true, 0, CodeGenOpts.CudaGpuBinaryFileName, std::string(), false, std::string(), normalizeString, denormalizeString, mergeForwardValue, extractForwardValue, -1)
#endif // CODEGEN_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcuda-allow-variadic-functions"[1], fcuda_allow_variadic_functions, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Allow variadic functions in CUDA device code.", nullptr, nullptr, "-fcuda-allow-variadic-functions", true, 0, LangOpts->CUDAAllowVariadicFunctions, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-cuda-host-device-constexpr"[1], fno_cuda_host_device_constexpr, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Don't treat unattributed constexpr functions as __host__ __device__.", nullptr, nullptr, "-fno-cuda-host-device-constexpr", true, 0, LangOpts->CUDAHostDeviceConstexpr, true, false, true, normalizeSimpleNegativeFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsycl-is-device"[1], fsycl_is_device, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "Generate code for SYCL device.", nullptr, nullptr, "-fsycl-is-device", true, 0, LangOpts->SYCLIsDevice, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fsycl-is-host"[1], fsycl_is_host, Flag, INVALID, INVALID, nullptr, CC1Option | NoDriverOption, 0,
       "SYCL host compilation", nullptr, nullptr, "-fsycl-is-host", true, 0, LangOpts->SYCLIsHost, false, false, false, normalizeSimpleFlag, denormalizeSimpleFlag, mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-sycl-std="[1], sycl_std_EQ, Joined, sycl_Group, INVALID, nullptr, CC1Option | NoArgumentUnused | CoreOption, 0,
       "SYCL language standard to compile for.", nullptr, "2020,2017,121,1.2.1,sycl-1.2.1", "-sycl-std=", LangOpts->SYCLIsDevice||LangOpts->SYCLIsHost, 0, LangOpts->SYCLVersion, LangOptions::SYCL_None, false, LangOptions::SYCL_None, normalizeSimpleEnum, denormalizeSimpleEnum, mergeForwardValue, extractForwardValue, 39)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fcuda-approx-transcendentals"[1], fcuda_approx_transcendentals, Flag, f_Group, INVALID, nullptr, CC1Option, 0,
       "Use approximate transcendental functions", nullptr, nullptr, "-fcuda-approx-transcendentals", LangOpts->CUDAIsDevice, 0, LangOpts->CUDADeviceApproxTranscendentals, false, false, false, makeBooleanOptionNormalizer(true, false, OPT_fno_cuda_approx_transcendentals), makeBooleanOptionDenormalizer(true), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING
#ifdef LANG_OPTION_WITH_MARSHALLING
LANG_OPTION_WITH_MARSHALLING(prefix_1, &"-fno-cuda-approx-transcendentals"[1], fno_cuda_approx_transcendentals, Flag, f_Group, INVALID, nullptr, 0, 0,
       "Don't use approximate transcendental functions", nullptr, nullptr, "-fno-cuda-approx-transcendentals", LangOpts->CUDAIsDevice, 0, LangOpts->CUDADeviceApproxTranscendentals, false, false, false, makeBooleanOptionNormalizer(false, true, OPT_fcuda_approx_transcendentals), makeBooleanOptionDenormalizer(false), mergeForwardValue, extractForwardValue, -1)
#endif // LANG_OPTION_WITH_MARSHALLING

#ifdef SIMPLE_ENUM_VALUE_TABLE

struct SimpleEnumValue {
  const char *Name;
  unsigned Value;
};

struct SimpleEnumValueTable {
  const SimpleEnumValue *Table;
  unsigned Size;
};
static const SimpleEnumValue fembed_bitcode_EQValueTable[] = {
{"off",static_cast<unsigned>(CodeGenOptions::Embed_Off)},{"all",static_cast<unsigned>(CodeGenOptions::Embed_All)},{"bitcode",static_cast<unsigned>(CodeGenOptions::Embed_Bitcode)},{"marker",static_cast<unsigned>(CodeGenOptions::Embed_Marker)},};
static const SimpleEnumValue fswift_async_fp_EQValueTable[] = {
{"auto",static_cast<unsigned>(CodeGenOptions::SwiftAsyncFramePointerKind::Auto)},{"always",static_cast<unsigned>(CodeGenOptions::SwiftAsyncFramePointerKind::Always)},{"never",static_cast<unsigned>(CodeGenOptions::SwiftAsyncFramePointerKind::Never)},};
static const SimpleEnumValue fcf_runtime_abi_EQValueTable[] = {
{"unspecified",static_cast<unsigned>(LangOptions::CoreFoundationABI::ObjectiveC)},{"standalone",static_cast<unsigned>(LangOptions::CoreFoundationABI::ObjectiveC)},{"objc",static_cast<unsigned>(LangOptions::CoreFoundationABI::ObjectiveC)},{"swift",static_cast<unsigned>(LangOptions::CoreFoundationABI::Swift5_0)},{"swift-5.0",static_cast<unsigned>(LangOptions::CoreFoundationABI::Swift5_0)},{"swift-4.2",static_cast<unsigned>(LangOptions::CoreFoundationABI::Swift4_2)},{"swift-4.1",static_cast<unsigned>(LangOptions::CoreFoundationABI::Swift4_1)},};
static const SimpleEnumValue exception_modelValueTable[] = {
{"dwarf",static_cast<unsigned>(LangOptions::ExceptionHandlingKind::DwarfCFI)},{"sjlj",static_cast<unsigned>(LangOptions::ExceptionHandlingKind::SjLj)},{"seh",static_cast<unsigned>(LangOptions::ExceptionHandlingKind::WinEH)},{"wasm",static_cast<unsigned>(LangOptions::ExceptionHandlingKind::Wasm)},};
static const SimpleEnumValue ffp_exception_behavior_EQValueTable[] = {
{"ignore",static_cast<unsigned>(LangOptions::FPE_Ignore)},{"maytrap",static_cast<unsigned>(LangOptions::FPE_MayTrap)},{"strict",static_cast<unsigned>(LangOptions::FPE_Strict)},};
static const SimpleEnumValue fextend_args_EQValueTable[] = {
{"32",static_cast<unsigned>(LangOptions::ExtendArgsKind::ExtendTo32)},{"64",static_cast<unsigned>(LangOptions::ExtendArgsKind::ExtendTo64)},};
static const SimpleEnumValue sanitize_address_use_after_return_EQValueTable[] = {
{"never",static_cast<unsigned>(llvm::AsanDetectStackUseAfterReturnMode::Never)},{"runtime",static_cast<unsigned>(llvm::AsanDetectStackUseAfterReturnMode::Runtime)},{"always",static_cast<unsigned>(llvm::AsanDetectStackUseAfterReturnMode::Always)},};
static const SimpleEnumValue sanitize_address_destructor_EQValueTable[] = {
{"none",static_cast<unsigned>(llvm::AsanDtorKind::None)},{"global",static_cast<unsigned>(llvm::AsanDtorKind::Global)},};
static const SimpleEnumValue flax_vector_conversions_EQValueTable[] = {
{"none",static_cast<unsigned>(LangOptions::LaxVectorConversionKind::None)},{"integer",static_cast<unsigned>(LangOptions::LaxVectorConversionKind::Integer)},{"all",static_cast<unsigned>(LangOptions::LaxVectorConversionKind::All)},};
static const SimpleEnumValue fms_memptr_rep_EQValueTable[] = {
{"single",static_cast<unsigned>(LangOptions::PPTMK_FullGeneralitySingleInheritance)},{"multiple",static_cast<unsigned>(LangOptions::PPTMK_FullGeneralityMultipleInheritance)},{"virtual",static_cast<unsigned>(LangOptions::PPTMK_FullGeneralityVirtualInheritance)},};
static const SimpleEnumValue fveclibValueTable[] = {
{"Accelerate",static_cast<unsigned>(CodeGenOptions::Accelerate)},{"libmvec",static_cast<unsigned>(CodeGenOptions::LIBMVEC)},{"MASSV",static_cast<unsigned>(CodeGenOptions::MASSV)},{"SVML",static_cast<unsigned>(CodeGenOptions::SVML)},{"Darwin_libsystem_m",static_cast<unsigned>(CodeGenOptions::Darwin_libsystem_m)},{"none",static_cast<unsigned>(CodeGenOptions::NoLibrary)},};
static const SimpleEnumValue fshow_overloads_EQValueTable[] = {
{"best",static_cast<unsigned>(Ovl_Best)},{"all",static_cast<unsigned>(Ovl_All)},};
static const SimpleEnumValue ftrivial_auto_var_initValueTable[] = {
{"uninitialized",static_cast<unsigned>(LangOptions::TrivialAutoVarInitKind::Uninitialized)},{"zero",static_cast<unsigned>(LangOptions::TrivialAutoVarInitKind::Zero)},{"pattern",static_cast<unsigned>(LangOptions::TrivialAutoVarInitKind::Pattern)},};
static const SimpleEnumValue ftlsmodel_EQValueTable[] = {
{"global-dynamic",static_cast<unsigned>(CodeGenOptions::GeneralDynamicTLSModel)},{"local-dynamic",static_cast<unsigned>(CodeGenOptions::LocalDynamicTLSModel)},{"initial-exec",static_cast<unsigned>(CodeGenOptions::InitialExecTLSModel)},{"local-exec",static_cast<unsigned>(CodeGenOptions::LocalExecTLSModel)},};
static const SimpleEnumValue fvisibility_dllexport_EQValueTable[] = {
{"default",static_cast<unsigned>(DefaultVisibility)},{"hidden",static_cast<unsigned>(HiddenVisibility)},{"internal",static_cast<unsigned>(HiddenVisibility)},{"protected",static_cast<unsigned>(ProtectedVisibility)},};
static const SimpleEnumValue fvisibility_nodllstorageclass_EQValueTable[] = {
{"default",static_cast<unsigned>(DefaultVisibility)},{"hidden",static_cast<unsigned>(HiddenVisibility)},{"internal",static_cast<unsigned>(HiddenVisibility)},{"protected",static_cast<unsigned>(ProtectedVisibility)},};
static const SimpleEnumValue fvisibility_externs_dllimport_EQValueTable[] = {
{"default",static_cast<unsigned>(DefaultVisibility)},{"hidden",static_cast<unsigned>(HiddenVisibility)},{"internal",static_cast<unsigned>(HiddenVisibility)},{"protected",static_cast<unsigned>(ProtectedVisibility)},};
static const SimpleEnumValue fvisibility_externs_nodllstorageclass_EQValueTable[] = {
{"default",static_cast<unsigned>(DefaultVisibility)},{"hidden",static_cast<unsigned>(HiddenVisibility)},{"internal",static_cast<unsigned>(HiddenVisibility)},{"protected",static_cast<unsigned>(ProtectedVisibility)},};
static const SimpleEnumValue inline_asm_EQValueTable[] = {
{"att",static_cast<unsigned>(CodeGenOptions::IAD_ATT)},{"intel",static_cast<unsigned>(CodeGenOptions::IAD_Intel)},};
static const SimpleEnumValue mthread_modelValueTable[] = {
{"posix",static_cast<unsigned>(LangOptions::ThreadModelKind::POSIX)},{"single",static_cast<unsigned>(LangOptions::ThreadModelKind::Single)},};
static const SimpleEnumValue meabiValueTable[] = {
{"default",static_cast<unsigned>(llvm::EABI::Default)},{"4",static_cast<unsigned>(llvm::EABI::EABI4)},{"5",static_cast<unsigned>(llvm::EABI::EABI5)},{"gnu",static_cast<unsigned>(llvm::EABI::GNU)},};
static const SimpleEnumValue altivec_src_compatValueTable[] = {
{"mixed",static_cast<unsigned>(LangOptions::AltivecSrcCompatKind::Mixed)},{"gcc",static_cast<unsigned>(LangOptions::AltivecSrcCompatKind::GCC)},{"xl",static_cast<unsigned>(LangOptions::AltivecSrcCompatKind::XL)},};
static const SimpleEnumValue analyzer_config_compatibility_modeValueTable[] = {
{"true",static_cast<unsigned>(false)},{"false",static_cast<unsigned>(true)},};
static const SimpleEnumValue debugger_tuning_EQValueTable[] = {
{"gdb",static_cast<unsigned>(llvm::DebuggerKind::GDB)},{"lldb",static_cast<unsigned>(llvm::DebuggerKind::LLDB)},{"sce",static_cast<unsigned>(llvm::DebuggerKind::SCE)},{"dbx",static_cast<unsigned>(llvm::DebuggerKind::DBX)},};
static const SimpleEnumValue compress_debug_sections_EQValueTable[] = {
{"none",static_cast<unsigned>(llvm::DebugCompressionType::None)},{"zlib",static_cast<unsigned>(llvm::DebugCompressionType::Z)},{"zlib-gnu",static_cast<unsigned>(llvm::DebugCompressionType::GNU)},};
static const SimpleEnumValue mrelocation_modelValueTable[] = {
{"static",static_cast<unsigned>(llvm::Reloc::Static)},{"pic",static_cast<unsigned>(llvm::Reloc::PIC_)},{"ropi",static_cast<unsigned>(llvm::Reloc::ROPI)},{"rwpi",static_cast<unsigned>(llvm::Reloc::RWPI)},{"ropi-rwpi",static_cast<unsigned>(llvm::Reloc::ROPI_RWPI)},{"dynamic-no-pic",static_cast<unsigned>(llvm::Reloc::DynamicNoPIC)},};
static const SimpleEnumValue mframe_pointer_EQValueTable[] = {
{"all",static_cast<unsigned>(CodeGenOptions::FramePointerKind::All)},{"non-leaf",static_cast<unsigned>(CodeGenOptions::FramePointerKind::NonLeaf)},{"none",static_cast<unsigned>(CodeGenOptions::FramePointerKind::None)},};
static const SimpleEnumValue fprofile_instrument_EQValueTable[] = {
{"none",static_cast<unsigned>(CodeGenOptions::ProfileNone)},{"clang",static_cast<unsigned>(CodeGenOptions::ProfileClangInstr)},{"llvm",static_cast<unsigned>(CodeGenOptions::ProfileIRInstr)},{"csllvm",static_cast<unsigned>(CodeGenOptions::ProfileCSIRInstr)},};
static const SimpleEnumValue fdiagnostics_formatValueTable[] = {
{"clang",static_cast<unsigned>(DiagnosticOptions::Clang)},{"msvc",static_cast<unsigned>(DiagnosticOptions::MSVC)},{"vi",static_cast<unsigned>(DiagnosticOptions::Vi)},};
static const SimpleEnumValue fdiagnostics_show_categoryValueTable[] = {
{"none",static_cast<unsigned>(0)},{"id",static_cast<unsigned>(1)},{"name",static_cast<unsigned>(2)},};
static const SimpleEnumValue arcmt_action_EQValueTable[] = {
{"check",static_cast<unsigned>(FrontendOptions::ARCMT_Check)},{"modify",static_cast<unsigned>(FrontendOptions::ARCMT_Modify)},{"migrate",static_cast<unsigned>(FrontendOptions::ARCMT_Migrate)},};
static const SimpleEnumValue fobjc_arc_cxxlib_EQValueTable[] = {
{"libc++",static_cast<unsigned>(ARCXX_libcxx)},{"libstdc++",static_cast<unsigned>(ARCXX_libstdcxx)},{"none",static_cast<unsigned>(ARCXX_nolib)},};
static const SimpleEnumValue fobjc_dispatch_method_EQValueTable[] = {
{"legacy",static_cast<unsigned>(CodeGenOptions::Legacy)},{"non-legacy",static_cast<unsigned>(CodeGenOptions::NonLegacy)},{"mixed",static_cast<unsigned>(CodeGenOptions::Mixed)},};
static const SimpleEnumValue stack_protectorValueTable[] = {
{"0",static_cast<unsigned>(LangOptions::SSPOff)},{"1",static_cast<unsigned>(LangOptions::SSPOn)},{"2",static_cast<unsigned>(LangOptions::SSPStrong)},{"3",static_cast<unsigned>(LangOptions::SSPReq)},};
static const SimpleEnumValue fvisibilityValueTable[] = {
{"default",static_cast<unsigned>(DefaultVisibility)},{"hidden",static_cast<unsigned>(HiddenVisibility)},{"internal",static_cast<unsigned>(HiddenVisibility)},{"protected",static_cast<unsigned>(ProtectedVisibility)},};
static const SimpleEnumValue ftype_visibilityValueTable[] = {
{"default",static_cast<unsigned>(DefaultVisibility)},{"hidden",static_cast<unsigned>(HiddenVisibility)},{"internal",static_cast<unsigned>(HiddenVisibility)},{"protected",static_cast<unsigned>(ProtectedVisibility)},};
static const SimpleEnumValue faddress_space_map_mangling_EQValueTable[] = {
{"target",static_cast<unsigned>(LangOptions::ASMM_Target)},{"no",static_cast<unsigned>(LangOptions::ASMM_Off)},{"yes",static_cast<unsigned>(LangOptions::ASMM_On)},};
static const SimpleEnumValue fdefault_calling_conv_EQValueTable[] = {
{"cdecl",static_cast<unsigned>(LangOptions::DCC_CDecl)},{"fastcall",static_cast<unsigned>(LangOptions::DCC_FastCall)},{"stdcall",static_cast<unsigned>(LangOptions::DCC_StdCall)},{"vectorcall",static_cast<unsigned>(LangOptions::DCC_VectorCall)},{"regcall",static_cast<unsigned>(LangOptions::DCC_RegCall)},};
static const SimpleEnumValue fwchar_type_EQValueTable[] = {
{"char",static_cast<unsigned>(1)},{"short",static_cast<unsigned>(2)},{"int",static_cast<unsigned>(4)},};
static const SimpleEnumValue sycl_std_EQValueTable[] = {
{"2020",static_cast<unsigned>(LangOptions::SYCL_2020)},{"2017",static_cast<unsigned>(LangOptions::SYCL_2017)},{"121",static_cast<unsigned>(LangOptions::SYCL_2017)},{"1.2.1",static_cast<unsigned>(LangOptions::SYCL_2017)},{"sycl-1.2.1",static_cast<unsigned>(LangOptions::SYCL_2017)},};
static const SimpleEnumValueTable SimpleEnumValueTables[] = {{fembed_bitcode_EQValueTable, sizeof(fembed_bitcode_EQValueTable) / sizeof(SimpleEnumValue)},
{fswift_async_fp_EQValueTable, sizeof(fswift_async_fp_EQValueTable) / sizeof(SimpleEnumValue)},
{fcf_runtime_abi_EQValueTable, sizeof(fcf_runtime_abi_EQValueTable) / sizeof(SimpleEnumValue)},
{exception_modelValueTable, sizeof(exception_modelValueTable) / sizeof(SimpleEnumValue)},
{ffp_exception_behavior_EQValueTable, sizeof(ffp_exception_behavior_EQValueTable) / sizeof(SimpleEnumValue)},
{fextend_args_EQValueTable, sizeof(fextend_args_EQValueTable) / sizeof(SimpleEnumValue)},
{sanitize_address_use_after_return_EQValueTable, sizeof(sanitize_address_use_after_return_EQValueTable) / sizeof(SimpleEnumValue)},
{sanitize_address_destructor_EQValueTable, sizeof(sanitize_address_destructor_EQValueTable) / sizeof(SimpleEnumValue)},
{flax_vector_conversions_EQValueTable, sizeof(flax_vector_conversions_EQValueTable) / sizeof(SimpleEnumValue)},
{fms_memptr_rep_EQValueTable, sizeof(fms_memptr_rep_EQValueTable) / sizeof(SimpleEnumValue)},
{fveclibValueTable, sizeof(fveclibValueTable) / sizeof(SimpleEnumValue)},
{fshow_overloads_EQValueTable, sizeof(fshow_overloads_EQValueTable) / sizeof(SimpleEnumValue)},
{ftrivial_auto_var_initValueTable, sizeof(ftrivial_auto_var_initValueTable) / sizeof(SimpleEnumValue)},
{ftlsmodel_EQValueTable, sizeof(ftlsmodel_EQValueTable) / sizeof(SimpleEnumValue)},
{fvisibility_dllexport_EQValueTable, sizeof(fvisibility_dllexport_EQValueTable) / sizeof(SimpleEnumValue)},
{fvisibility_nodllstorageclass_EQValueTable, sizeof(fvisibility_nodllstorageclass_EQValueTable) / sizeof(SimpleEnumValue)},
{fvisibility_externs_dllimport_EQValueTable, sizeof(fvisibility_externs_dllimport_EQValueTable) / sizeof(SimpleEnumValue)},
{fvisibility_externs_nodllstorageclass_EQValueTable, sizeof(fvisibility_externs_nodllstorageclass_EQValueTable) / sizeof(SimpleEnumValue)},
{inline_asm_EQValueTable, sizeof(inline_asm_EQValueTable) / sizeof(SimpleEnumValue)},
{mthread_modelValueTable, sizeof(mthread_modelValueTable) / sizeof(SimpleEnumValue)},
{meabiValueTable, sizeof(meabiValueTable) / sizeof(SimpleEnumValue)},
{altivec_src_compatValueTable, sizeof(altivec_src_compatValueTable) / sizeof(SimpleEnumValue)},
{analyzer_config_compatibility_modeValueTable, sizeof(analyzer_config_compatibility_modeValueTable) / sizeof(SimpleEnumValue)},
{debugger_tuning_EQValueTable, sizeof(debugger_tuning_EQValueTable) / sizeof(SimpleEnumValue)},
{compress_debug_sections_EQValueTable, sizeof(compress_debug_sections_EQValueTable) / sizeof(SimpleEnumValue)},
{mrelocation_modelValueTable, sizeof(mrelocation_modelValueTable) / sizeof(SimpleEnumValue)},
{mframe_pointer_EQValueTable, sizeof(mframe_pointer_EQValueTable) / sizeof(SimpleEnumValue)},
{fprofile_instrument_EQValueTable, sizeof(fprofile_instrument_EQValueTable) / sizeof(SimpleEnumValue)},
{fdiagnostics_formatValueTable, sizeof(fdiagnostics_formatValueTable) / sizeof(SimpleEnumValue)},
{fdiagnostics_show_categoryValueTable, sizeof(fdiagnostics_show_categoryValueTable) / sizeof(SimpleEnumValue)},
{arcmt_action_EQValueTable, sizeof(arcmt_action_EQValueTable) / sizeof(SimpleEnumValue)},
{fobjc_arc_cxxlib_EQValueTable, sizeof(fobjc_arc_cxxlib_EQValueTable) / sizeof(SimpleEnumValue)},
{fobjc_dispatch_method_EQValueTable, sizeof(fobjc_dispatch_method_EQValueTable) / sizeof(SimpleEnumValue)},
{stack_protectorValueTable, sizeof(stack_protectorValueTable) / sizeof(SimpleEnumValue)},
{fvisibilityValueTable, sizeof(fvisibilityValueTable) / sizeof(SimpleEnumValue)},
{ftype_visibilityValueTable, sizeof(ftype_visibilityValueTable) / sizeof(SimpleEnumValue)},
{faddress_space_map_mangling_EQValueTable, sizeof(faddress_space_map_mangling_EQValueTable) / sizeof(SimpleEnumValue)},
{fdefault_calling_conv_EQValueTable, sizeof(fdefault_calling_conv_EQValueTable) / sizeof(SimpleEnumValue)},
{fwchar_type_EQValueTable, sizeof(fwchar_type_EQValueTable) / sizeof(SimpleEnumValue)},
{sycl_std_EQValueTable, sizeof(sycl_std_EQValueTable) / sizeof(SimpleEnumValue)},
};
static const unsigned SimpleEnumValueTablesSize = sizeof(SimpleEnumValueTables) / sizeof(SimpleEnumValueTable);
#endif // SIMPLE_ENUM_VALUE_TABLE


#ifdef OPTTABLE_ARG_INIT
//////////
// Option Values

{
bool ValuesWereAdded;

    const char *Values =
    #define GET_CHECKERS
    #define CHECKER(FULLNAME, CLASS, HT, DOC_URI, IS_HIDDEN)  FULLNAME ","
    #include "clang/StaticAnalyzer/Checkers/Checkers.inc"
    #undef GET_CHECKERS
    #define GET_PACKAGES
    #define PACKAGE(FULLNAME)  FULLNAME ","
    #include "clang/StaticAnalyzer/Checkers/Checkers.inc"
    #undef GET_PACKAGES
    ;
  
ValuesWereAdded = Opt.addValues("-analyzer-checker", Values);
(void)ValuesWereAdded;
assert(ValuesWereAdded && "Couldn't add values to OptTable!");
}
{
bool ValuesWereAdded;

    const char *Values =
    #define LANGSTANDARD(id, name, lang, desc, features) name ","
    #define LANGSTANDARD_ALIAS(id, alias) alias ","
    #include "clang/Basic/LangStandards.def"
    ;
  
ValuesWereAdded = Opt.addValues("-std=", Values);
(void)ValuesWereAdded;
assert(ValuesWereAdded && "Couldn't add values to OptTable!");
ValuesWereAdded = Opt.addValues("--std=", Values);
(void)ValuesWereAdded;
assert(ValuesWereAdded && "Couldn't add values to OptTable!");
}

#endif // OPTTABLE_ARG_INIT
