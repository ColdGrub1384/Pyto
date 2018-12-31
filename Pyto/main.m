//
//  main.m
//  Pyto
//
//  Created by Adrian Labbe on 9/16/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Pyto-Bridging-Header.h"
#import "../Python/Headers/Python.h"
#import "Pyto-Swift.h"
#include <dlfcn.h>

/// The path of the Python home directory.
NSString *pythonHome;

int main(int argc, char *argv[]) {
        
    pythonHome = Python.shared.bundle.bundlePath;
    
    if (!pythonHome) {
        Py_FatalError("Python home doesn't exist");
    }
    
    // MARK: - Python env variables
    putenv("PYTHONOPTIMIZE=");
    putenv("PYTHONDONTWRITEBYTECODE=1");
    putenv((char *)[[NSString stringWithFormat:@"TMP=%@", NSTemporaryDirectory()] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONHOME=%@", pythonHome] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONPATH=%@:%@", [pythonHome stringByAppendingPathComponent:@"python37.zip"], Python.shared.bundle.bundlePath] UTF8String]);
    
    // MARK: - NumPy
    
    void *multiarray = NULL;
    void *umath = NULL;
    void *fftpack_lite = NULL;
    void *umath_linalg = NULL;
    void *lapack_lite = NULL;
    void *mtrand = NULL;
    
    PyMODINIT_FUNC (*PyInit_multiarray)(void);
    PyMODINIT_FUNC (*PyInit_umath)(void);
    PyMODINIT_FUNC (*PyInit_fftpack_lite)(void);
    PyMODINIT_FUNC (*PyInit__umath_linalg)(void);
    PyMODINIT_FUNC (*PyInit_lapack_lite)(void);
    PyMODINIT_FUNC (*PyInit_mtrand)(void);
    
    NSError *error;
    for (NSURL *file in [NSFileManager.defaultManager contentsOfDirectoryAtURL:[[NSBundle.mainBundle privateFrameworksURL] URLByAppendingPathComponent:@"NumPy.framework"] includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
        if ([file.pathExtension isEqualToString:@"so"]) {
            void *handle = dlopen(file.path.UTF8String, RTLD_LAZY);
            
            if (!handle) {
                fprintf(stderr, "%s", dlerror());
            }
            
            NSString *name = file.URLByDeletingPathExtension.lastPathComponent;
            
            if ([name isEqualToString:@"multiarray.cpython-37m-darwin"]) {
                multiarray = handle;
            } else if ([name isEqualToString:@"umath.cpython-37m-darwin"]) {
                umath = handle;
            } else if ([name isEqualToString:@"fftpack_lite.cpython-37m-darwin"]) {
                fftpack_lite = handle;
            } else if ([name isEqualToString:@"_umath_linalg.cpython-37m-darwin"]) {
                umath_linalg = handle;
            } else if ([name isEqualToString:@"lapack_lite.cpython-37m-darwin"]) {
                lapack_lite = handle;
            } else if ([name isEqualToString:@"mtrand.cpython-37m-darwin"]) {
                mtrand = handle;
            }
        }
    }
    if (error) {
        NSLog(@"%@", error.localizedDescription);
    }
    
    *(void **) (&PyInit_multiarray) = dlsym(multiarray, "PyInit_multiarray");
    *(void **) (&PyInit_umath) = dlsym(umath, "PyInit_umath");
    *(void **) (&PyInit_fftpack_lite) = dlsym(fftpack_lite, "PyInit_fftpack_lite");
    *(void **) (&PyInit__umath_linalg) = dlsym(umath_linalg, "PyInit__umath_linalg");
    *(void **) (&PyInit_lapack_lite) = dlsym(lapack_lite, "PyInit_lapack_lite");
    *(void **) (&PyInit_mtrand) = dlsym(mtrand, "PyInit_mtrand");
    
    PyImport_AppendInittab("__numpy_core_multiarray", PyInit_multiarray);
    PyImport_AppendInittab("__numpy_core_umath", PyInit_umath);
    PyImport_AppendInittab("__numpy_fft_fftpack_lite", PyInit_fftpack_lite);
    PyImport_AppendInittab("__numpy_linalg__umath_linalg", PyInit__umath_linalg);
    PyImport_AppendInittab("__numpy_linalg_lapack_lite", PyInit_lapack_lite);
    PyImport_AppendInittab("__numpy_random_mtrand", PyInit_mtrand);
    
    // MARK: - Init Python
    Py_SetPythonHome(Py_DecodeLocale([pythonHome UTF8String], NULL));
    Py_Initialize();
    PyEval_InitThreads();
    
    [Python.shared importPytoLib];
    
    // MARK: - Set Python arguments
    wchar_t** python_argv = PyMem_RawMalloc(sizeof(wchar_t*) * argc);
    int i;
    for (i = 0; i < argc; i++) {
        python_argv[i] = Py_DecodeLocale(argv[i], NULL);
    }
    PySys_SetArgv(argc, python_argv);
    
    // MARK: - Start the REPL that will contain all child modules
    [Python.shared runScriptAt:[[NSBundle mainBundle] URLForResource:@"REPL" withExtension:@"py"]];
    
    @autoreleasepool {
        return UIApplicationMain(argc, argv, NULL, NSStringFromClass(AppDelegate.class));
    }
}

