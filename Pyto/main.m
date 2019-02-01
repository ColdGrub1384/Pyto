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
//#import "../Matplotlib/matplotlib.h"
#include <dlfcn.h>

/// The path of the Python home directory.
NSString *pythonHome;

// MARK: - Modules

#define load(HANDLE) \
handle = dlopen(file.path.UTF8String, RTLD_NOW); \
HANDLE = handle;

// MARK: - Numpy

PyMODINIT_FUNC (*PyInit_multiarray)(void);
PyMODINIT_FUNC (*PyInit_umath)(void);
PyMODINIT_FUNC (*PyInit_fftpack_lite)(void);
PyMODINIT_FUNC (*PyInit__umath_linalg)(void);
PyMODINIT_FUNC (*PyInit_lapack_lite)(void);
PyMODINIT_FUNC (*PyInit_mtrand)(void);

void *multiarray = NULL;
void *umath = NULL;
void *fftpack_lite = NULL;
void *umath_linalg = NULL;
void *lapack_lite = NULL;
void *mtrand = NULL;

/// Initializes Numpy.
void init_numpy() {
    
    NSError *error;
    for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:NSBundle.mainBundle.privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
        NSURL *file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-37m-darwin.so"].lastPathComponent];
        
        NSString *name = file.URLByDeletingPathExtension.URLByDeletingPathExtension.lastPathComponent;
        
        void *handle;
        
        if ([name isEqualToString:@"multiarray"]) {
            load(multiarray);
        } else if ([name isEqualToString:@"umath"]) {
            load(umath);
        } else if ([name isEqualToString:@"fftpack_lite"]) {
            load(fftpack_lite);
        } else if ([name isEqualToString:@"_umath_linalg"]) {
            load(umath_linalg);
        } else if ([name isEqualToString:@"lapack_lite"]) {
            load(lapack_lite);
        } else if ([name isEqualToString:@"mtrand"]) {
            load(mtrand);
        } else {
            continue;
        }
        
        if (!handle) {
            fprintf(stderr, "%s", dlerror());
        }
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
}

// MARK: - Matplotlib

PyMODINIT_FUNC (*__PyInit__backend_agg)(void);
PyMODINIT_FUNC (*__PyInit__image)(void);
PyMODINIT_FUNC (*__PyInit__path)(void);
PyMODINIT_FUNC (*__PyInit__png)(void);
PyMODINIT_FUNC (*__PyInit_ft2font)(void);
PyMODINIT_FUNC (*__PyInit__contour)(void);
PyMODINIT_FUNC (*__PyInit__qhull)(void);
PyMODINIT_FUNC (*__PyInit__tri)(void);
PyMODINIT_FUNC (*__PyInit_ttconv)(void);
PyMODINIT_FUNC (*__PyInit_kiwisolver)(void);

void *_backend_agg = NULL;
void *_image = NULL;
void *_path = NULL;
void *_png = NULL;
void *ft2font = NULL;
void *_contour = NULL;
void *_qhull = NULL;
void *_tri = NULL;
void *ttconv = NULL;
void *kiwisolver = NULL;

/// Initializes Matplotlib.
void init_matplotlib() {
    
    NSURL *mpl_data = [[NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask].firstObject URLByAppendingPathComponent:@"mpl-data"];
    
    [NSFileManager.defaultManager removeItemAtPath:mpl_data.path error:NULL];
    
    if (![NSFileManager.defaultManager fileExistsAtPath:mpl_data.path]) {
        [NSFileManager.defaultManager createDirectoryAtPath:mpl_data.path withIntermediateDirectories:NO attributes:NULL error:NULL];
    }
    
    putenv((char *)[[NSString stringWithFormat:@"MATPLOTLIBDATA=%@", mpl_data.path] UTF8String]);
    
    for (NSURL *fileURL in [NSFileManager.defaultManager contentsOfDirectoryAtURL:[NSBundle.mainBundle URLForResource:@"site-packages/matplotlib/mpl-data" withExtension:NULL] includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:NULL]) {
        NSURL *newURL = [mpl_data URLByAppendingPathComponent:fileURL.lastPathComponent];
        if (![NSFileManager.defaultManager fileExistsAtPath:newURL.path]) {
            [NSFileManager.defaultManager copyItemAtURL:fileURL toURL:newURL error:NULL];
        }
    }
    
    NSError *error;
    for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:NSBundle.mainBundle.privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
        NSURL *file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-37m-darwin.so"].lastPathComponent];
        
        NSString *name = file.URLByDeletingPathExtension.URLByDeletingPathExtension.lastPathComponent;
        
        void *handle;
        
        if ([name isEqualToString:@"_backend_agg"]) {
            load(_backend_agg);
        } else if ([name isEqualToString:@"_image"]) {
            load(_image);
        } else if ([name isEqualToString:@"_path"]) {
            load(_path);
        } else if ([name isEqualToString:@"_png"]) {
            load(_png);
        } else if ([name isEqualToString:@"ft2font"]) {
            load(ft2font);
        } else if ([name isEqualToString:@"_contour"]) {
            load(_contour);
        } else if ([name isEqualToString:@"_qhull"]) {
            load(_qhull);
        } else if ([name isEqualToString:@"_tri"]) {
            load(_tri);
        } else if ([name isEqualToString:@"ttconv"]) {
            load(ttconv);
        } else if ([name isEqualToString:@"kiwisolver"]) {
            load(kiwisolver);
        } else {
            continue;
        }
        
        if (!handle) {
            fprintf(stderr, "%s", dlerror());
        }
    }
    
    *(void **) (&__PyInit__backend_agg) = dlsym(_backend_agg, "PyInit__backend_agg");
    *(void **) (&__PyInit__image) = dlsym(_image, "PyInit__image");
    *(void **) (&__PyInit__path) = dlsym(_path, "PyInit__path");
    *(void **) (&__PyInit__png) = dlsym(_png, "PyInit__png");
    *(void **) (&__PyInit_ft2font) = dlsym(ft2font, "PyInit_ft2font");
    *(void **) (&__PyInit__contour) = dlsym(_contour, "PyInit__contour");
    *(void **) (&__PyInit__qhull) = dlsym(_qhull, "PyInit__qhull");
    *(void **) (&__PyInit_ttconv) = dlsym(ttconv, "PyInit_ttconv");
    *(void **) (&__PyInit_kiwisolver) = dlsym(kiwisolver, "PyInit_kiwisolver");
    
    PyImport_AppendInittab("__matplotlib_backends__backend_agg", __PyInit__backend_agg);
    PyImport_AppendInittab("__matplotlib__image", __PyInit__image);
    PyImport_AppendInittab("__matplotlib__path", __PyInit__path);
    PyImport_AppendInittab("__matplotlib__png", __PyInit__png);
    PyImport_AppendInittab("__matplotlib_ft2font", __PyInit_ft2font);
    PyImport_AppendInittab("__matplotlib__contour", __PyInit__contour);
    PyImport_AppendInittab("__matplotlib__qhull", __PyInit__qhull);
    PyImport_AppendInittab("__matplotlib__tri", __PyInit__tri);
    PyImport_AppendInittab("__matplotlib_ttconv", __PyInit_ttconv);
    PyImport_AppendInittab("kiwisolver", __PyInit_kiwisolver);
}

// MARK: - Main

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
    putenv((char *)[[NSString stringWithFormat:@"PYTHONPATH=%@:%@", [NSBundle.mainBundle pathForResource:@"site-packages" ofType:NULL], [pythonHome stringByAppendingPathComponent:@"python37.zip"]] UTF8String]);
    
    // MARK: - Init builtins
    init_numpy();
    init_matplotlib();
    
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

