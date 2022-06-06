//
//  clang_codecompletion.c
//  clang_codecompletion
//
//  Created by Emma on 13-05-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

#include <clang_codecompletion.h>

/*void crash_handler(int signal) {
    printf("CRASHED\n");
}*/

NSArray* complete(const char *path, const char *code, int line, int column, NSArray *argv) {

    /*signal(SIGSEGV, crash_handler);
    signal(SIGABRT, crash_handler);*/
    
    CXIndex idx = clang_createIndex(0, 1);
    if (!idx) {
        std::cerr << "createIndex failed" << std::endl;
        return NULL;
    }
    
    int argc = (int)argv.count;

    char **_argv = (char **) malloc(sizeof(char *) * (argc + 1));

    int i;
    for(i = 0; i < argc; i++) {
        NSString *s = [argv objectAtIndex:i]; //get a NSString
        const char *cstr = [s cStringUsingEncoding:NSUTF8StringEncoding];
        size_t len = strlen(cstr); //get its length
        char *cstr_copy = (char *) malloc(sizeof(char) * (len + 1));//allocate memory, + 1 for ending '\0'
        strcpy(cstr_copy, cstr);//make a copy
        _argv[i] = cstr_copy; //put the point in cargs
    }
    _argv[i] = NULL;
    
    CXUnsavedFile unsaved_files[1];
    unsaved_files[0].Filename = path;
    unsaved_files[0].Contents = code;
    unsaved_files[0].Length   = strlen(code);
    
    CXTranslationUnit u;
    CXErrorCode error = clang_parseTranslationUnit2(idx, path, (const char**)_argv,
                        argc, unsaved_files, 1,
                        CXTranslationUnit_PrecompiledPreamble | CXTranslationUnit_CacheCompletionResults,
                        &u);

    if (!u) {
        std::cerr << "parseTranslationUnit failed: " << error << std::endl;
        return NULL;
    }

    clang_reparseTranslationUnit(u, 0, 0, clang_defaultReparseOptions(u));

    CXCodeCompleteResults* res = clang_codeCompleteAt(u, path, line, column, unsaved_files, 1, clang_defaultCodeCompleteOptions() | CXCodeComplete_IncludeCompletionsWithFixIts);
    if (!res) {
        std::cerr << "Could not complete" << std::endl;
        return NULL;
    }

    NSMutableArray *diagnostics = [[NSMutableArray alloc] init];
    
    for (unsigned i = 0; i < clang_codeCompleteGetNumDiagnostics(res); i++) {
        const CXDiagnostic& diag = clang_codeCompleteGetDiagnostic(res, i);
        const CXString& s = clang_getDiagnosticSpelling(diag);
        const CXSourceLocation location = clang_getDiagnosticLocation(diag);
        
        CXFile file;
        unsigned int line;
        unsigned int column;
        
        clang_getSpellingLocation(location, &file, &line, &column, NULL);
        
        NSString *severity = @"";
        
        bool ignored = false;
        switch (clang_getDiagnosticSeverity(diag)) {
            case CXDiagnostic_Note:
                severity = @"note";
                break;
            case CXDiagnostic_Error:
                severity = @"error";
                break;
            case CXDiagnostic_Fatal:
                severity = @"fatal error";
                break;
            case CXDiagnostic_Ignored:
                ignored = true;
                break;
            case CXDiagnostic_Warning:
                severity = @"warning";
                break;
            default:
                break;
        }
        
        if (ignored) {
            continue;
        }
        
        CXString path = clang_File_tryGetRealPathName(file);
        
        NSString *message = [NSString stringWithUTF8String:clang_getCString(s)];
        NSString *filePath = [NSString stringWithUTF8String:clang_getCString(path)];
        
        [diagnostics addObject: [NSString stringWithFormat:@"%@:%i:%i:%@:%@", filePath, line, column, severity, message]];
        
        clang_disposeString(s);
        clang_disposeString(path);
        clang_disposeDiagnostic(diag);
    }
    
    NSMutableArray *completions = [[NSMutableArray alloc] init];

    clang_sortCodeCompletionResults(res->Results, res->NumResults);
    
    for (unsigned i = 0; i < res->NumResults; i++) {
        const CXCompletionString& str = res->Results[i].CompletionString;
        
        clang::CodeCompletionString *CCStr = (clang::CodeCompletionString *)str;
        
        NSString *signature = [NSString stringWithUTF8String:CCStr->getAsString().c_str()];
                
        for (unsigned j = 0; j < clang_getNumCompletionChunks(str); j++) {
            if (clang_getCompletionChunkKind(str, j) == CXCompletionChunk_TypedText) {
                
                const CXString& out = clang_getCompletionChunkText(str, j);
                
                NSArray *arr = @[[NSString stringWithUTF8String:clang_getCString(out)], signature];
                                
                [completions addObject:arr];
                clang_disposeString(out);
            }
        }
    }
    clang_disposeCodeCompleteResults(res);
    clang_disposeIndex(idx);
    clang_disposeTranslationUnit(u);

    for(i = 0; i < argc; i++) {
        free(_argv[i]);
    }
    free(_argv);
    
    return @[completions, diagnostics];
}
