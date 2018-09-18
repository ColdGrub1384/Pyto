//
//  main.m
//  Pyto
//
//  Created by Adrian Labbe on 9/16/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../Python/Headers/Python.h"
#import "Pyto-Swift.h"

/// The path of the Python home directory.
NSString *pythonHome;

/// The path of the file where errors are printed.
NSString *pythonStderrPath;

int main(int argc, char *argv[]) {
    
    pythonHome = [[NSBundle mainBundle] pathForResource:@"Library/Python.framework/Resources" ofType:NULL];
    pythonStderrPath = [[[[NSFileManager defaultManager] URLsForDirectory:NSLibraryDirectory inDomains:NSAllDomainsMask] firstObject] URLByAppendingPathComponent:@"errors"].path;
    
    if (!pythonHome) {
        Py_FatalError("Python home doesn't exist");
    }
    
    // Python env variables
    putenv("PYTHONOPTIMIZE=");
    putenv((char *)[[NSString stringWithFormat:@"HOME=%@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask] firstObject].path] UTF8String]);
    putenv("PYTHONDONTWRITEBYTECODE=1");
    putenv((char *)[[NSString stringWithFormat:@"TMP=%@", NSTemporaryDirectory()] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONHOME=%@", pythonHome] UTF8String]);
    
    // Init Python
    Py_SetPythonHome(Py_DecodeLocale([pythonHome UTF8String], NULL));
    Py_Initialize();
    PyEval_InitThreads();
    
    // Set Python arguments
    wchar_t** python_argv = PyMem_RawMalloc(sizeof(wchar_t*) * argc);
    int i;
    for (i = 0; i < argc; i++) {
        python_argv[i] = Py_DecodeLocale(argv[i], NULL);
    }
    PySys_SetArgv(argc, python_argv);
    
    // Get Python version
    PyRun_SimpleStringFlags("import sys\nfrom rubicon.objc import *\nObjCClass('Pyto.Python').shared.version = sys.version", NULL);
    
    // Start the REPL that will contain all child modules
    [Python.shared runScriptAt:[[NSBundle mainBundle] URLForResource:@"REPL" withExtension:@"py"]];
    
    @autoreleasepool {
        return UIApplicationMain(argc, argv, NULL, NSStringFromClass(AppDelegate.class));
    }
}

