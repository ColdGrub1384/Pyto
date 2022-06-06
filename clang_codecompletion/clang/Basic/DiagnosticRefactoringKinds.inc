#ifdef REFACTORINGSTART
__REFACTORINGSTART = DIAG_START_REFACTORING,
#undef REFACTORINGSTART
#endif

DIAG(err_refactor_code_outside_of_function, CLASS_ERROR, (unsigned)diag::Severity::Error, "the selected code is not a part of a function's / method's body", 0, SFINAE_SubstitutionFailure, false, true, false, 25)
DIAG(err_refactor_extract_prohibited_expression, CLASS_ERROR, (unsigned)diag::Severity::Error, "the selected expression can't be extracted", 0, SFINAE_SubstitutionFailure, false, true, false, 25)
DIAG(err_refactor_extract_simple_expression, CLASS_ERROR, (unsigned)diag::Severity::Error, "the selected expression is too simple to extract", 0, SFINAE_SubstitutionFailure, false, true, false, 25)
DIAG(err_refactor_no_selection, CLASS_ERROR, (unsigned)diag::Severity::Error, "refactoring action can't be initiated without a selection", 0, SFINAE_SubstitutionFailure, false, true, false, 25)
DIAG(err_refactor_selection_invalid_ast, CLASS_ERROR, (unsigned)diag::Severity::Error, "the provided selection does not overlap with the AST nodes of interest", 0, SFINAE_SubstitutionFailure, false, true, false, 25)
DIAG(err_refactor_selection_no_symbol, CLASS_ERROR, (unsigned)diag::Severity::Error, "there is no symbol at the given location", 0, SFINAE_SubstitutionFailure, false, true, false, 25)
