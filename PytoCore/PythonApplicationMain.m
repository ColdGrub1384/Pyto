//
//  PythonApplicationMain.m
//  PytoCore
//
//  Created by Emma Labbé on 1/13/19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PytoCore/PytoCore-Swift.h>
#import "../Python/Python.h"
#import "PytoCore.h"

int PythonApplicationMain(NSString * scriptPath, int argc, char * _Nullable * _Nonnull argv) {
    
    NSBundle *bundle = [NSBundle bundleForClass:[Python self]];
    
    // MARK: - Python env variables
    putenv("PYTHONOPTIMIZE=");
    putenv("PYTHONDONTWRITEBYTECODE=1");
    putenv((char *)[[NSString stringWithFormat:@"TMP=%@", NSTemporaryDirectory()] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONHOME=%@", bundle.bundlePath] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONPATH=%@:%@:%@:%@:%@:%@:%@:%@", [bundle.bundlePath stringByAppendingPathComponent:@"python38.zip"], [bundle.bundlePath stringByAppendingPathComponent:@"site-packages"], [bundle.bundlePath stringByAppendingPathComponent:@"Lib"], bundle.bundlePath, [NSBundle.mainBundle.bundlePath stringByAppendingString:@"site-packages"], [NSBundle.mainBundle.bundlePath stringByAppendingString:@"modules"], [NSBundle.mainBundle.bundlePath stringByAppendingString:@"iCloudDrive"], [NSBundle.mainBundle.bundlePath stringByAppendingString:@"Documents"]] UTF8String]);
    
    // MARK: - Init PIL
    init_pil();
    
    // MARK: - Init Python
    Py_SetPythonHome(Py_DecodeLocale([bundle.bundlePath UTF8String], NULL));
    Py_Initialize();
    PyEval_InitThreads();
    
    // MARK: - Set Python arguments
    wchar_t** python_argv = PyMem_RawMalloc(sizeof(wchar_t*) * argc);
    int i;
    for (i = 0; i < argc; i++) {
        python_argv[i] = Py_DecodeLocale(argv[i], NULL);
    }
    PySys_SetArgv(argc, python_argv);
    
    // MARK: - Start the REPL that will contain all child modules
    [Python.shared runScriptAt:[bundle URLForResource:@"REPL" withExtension:@"py"]];
    
    // MARK: - Start UI app
    AppDelegate.scriptToRun = scriptPath;
    return UIApplicationMain(argc, argv, NULL, NSStringFromClass(AppDelegate.self));
}
