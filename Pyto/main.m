//
//  main.m
//  Pyto
//
//  Created by Adrian Labbe on 9/16/18.
//  Modified by goodclass on 2019/4/30.
//
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "../Python/Headers/Python.h"
#if MAIN
#import "Pyto-Swift.h"
#elif WIDGET
#import "Pyto_Widget-Swift.h"
#endif
#include <dlfcn.h>

#define load(HANDLE) handle = dlopen(file.path.UTF8String, RTLD_GLOBAL);  HANDLE = handle;

/// Returns the main bundle.
NSBundle* mainBundle() {
    #if MAIN
    return [NSBundle mainBundle];
    #elif WIDGET
    // Taken from https://stackoverflow.com/a/27849695/7515957
    NSBundle *bundle = [NSBundle mainBundle];
    if ([[bundle.bundleURL pathExtension] isEqualToString:@"appex"]) {
        // Peel off two directory levels - MY_APP.app/PlugIns/MY_APP_EXTENSION.appex
        bundle = [NSBundle bundleWithURL:[[bundle.bundleURL URLByDeletingLastPathComponent] URLByDeletingLastPathComponent]];
    }
    return bundle;
    #else
    return NULL;
    #endif
}

// MARK: - BandHandle

void BandHandle(NSString *fkTitle, NSArray *nameArray, NSArray *keyArray){
    NSError *error;
    for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:mainBundle().privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
        NSURL *file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-37m-darwin.so"].lastPathComponent];
        NSString *name = file.URLByDeletingPathExtension.URLByDeletingPathExtension.lastPathComponent;
        
        void *handle = NULL;
        for( int i=0; i<nameArray.count; i++){
            NSString *fname = [NSString stringWithFormat:@"%@_%@",fkTitle,[nameArray objectAtIndex:i]];
            NSString *fkey  = [keyArray  objectAtIndex:i];
            
            if ([name isEqualToString:[nameArray objectAtIndex:i]]){
                void *dllHandle = NULL; load(dllHandle);
                if (!handle) {
                    fprintf(stderr, "%s\n", dlerror());
                } else {
                    PyImport_AppendInittab(fkey.UTF8String, dlsym(dllHandle, [NSString stringWithFormat:@"PyInit_%@",[nameArray objectAtIndex:i]].UTF8String));
                }
                break;
            }
        }
    }
}

// MARK: - Numpy

void init_numpy() {
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_multiarray_umath"];  [key addObject:@"__numpy_core__multiarray_umath"];
    [name addObject:@"lapack_lite"];        [key addObject:@"__numpy_linalg_lapack_lite"];
    [name addObject:@"_umath_linalg"];      [key addObject:@"__numpy_linalg__umath_linalg"];
    [name addObject:@"fftpack_lite"];       [key addObject:@"__numpy_fft_fftpack_lite"];
    [name addObject:@"mtrand"];             [key addObject:@"__numpy_random_mtrand"];
    BandHandle(@"numpy", name, key);
}

// MARK: - Matplotlib

void init_matplotlib(){
    NSURL *mpl_data = [[NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask].firstObject URLByAppendingPathComponent:@"mpl-data"];
    
    [NSFileManager.defaultManager removeItemAtPath:mpl_data.path error:NULL];
    
    if (![NSFileManager.defaultManager fileExistsAtPath:mpl_data.path]) {
        [NSFileManager.defaultManager createDirectoryAtPath:mpl_data.path withIntermediateDirectories:NO attributes:NULL error:NULL];
    }
    
    putenv((char *)[[NSString stringWithFormat:@"MATPLOTLIBDATA=%@", mpl_data.path] UTF8String]);
    
    for (NSURL *fileURL in [NSFileManager.defaultManager contentsOfDirectoryAtURL:[mainBundle() URLForResource:@"site-packages/matplotlib/mpl-data" withExtension:NULL] includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:NULL]) {
        NSURL *newURL = [mpl_data URLByAppendingPathComponent:fileURL.lastPathComponent];
        if (![NSFileManager.defaultManager fileExistsAtPath:newURL.path]) {
            [NSFileManager.defaultManager copyItemAtURL:fileURL toURL:newURL error:NULL];
        }
    }
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_backend_agg"];       [key addObject:@"__matplotlib_backends__backend_agg"];
    [name addObject:@"ttconv"];             [key addObject:@"__matplotlib_ttconv"];
    [name addObject:@"_tkagg"];             [key addObject:@"__matplotlib_backends__tkagg"];
    [name addObject:@"_png"];               [key addObject:@"__matplotlib__png"];
    [name addObject:@"_image"];             [key addObject:@"__matplotlib__image"];
    [name addObject:@"_contour"];           [key addObject:@"__matplotlib__contour"];
    [name addObject:@"_qhull"];             [key addObject:@"__matplotlib__qhull"];
    [name addObject:@"_tri"];               [key addObject:@"__matplotlib__tri"];
    [name addObject:@"ft2font"];            [key addObject:@"__matplotlib_ft2font"];
    [name addObject:@"_path"];              [key addObject:@"__matplotlib__path"];
    [name addObject:@"kiwisolver"];         [key addObject:@"kiwisolver"];
    BandHandle(@"matplotlib", name, key);
}

// MARK: - Pandas

void init_pandas(){
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_move"];              [key addObject:@"__pandas_util__move"];
    [name addObject:@"_packer"];            [key addObject:@"__pandas_io_msgpack__packer"];
    [name addObject:@"_unpacker"];          [key addObject:@"__pandas_io_msgpack__unpacker"];
    [name addObject:@"_sas"];               [key addObject:@"__pandas_io_sas__sas"];
    [name addObject:@"writers"];            [key addObject:@"__pandas__libs_writers"];
    [name addObject:@"properties"];         [key addObject:@"__pandas__libs_properties"];
    [name addObject:@"interval"];           [key addObject:@"__pandas__libs_interval"];
    [name addObject:@"reduction"];          [key addObject:@"__pandas__libs_reduction"];
    [name addObject:@"lib"];                [key addObject:@"__pandas__libs_lib"];
    [name addObject:@"join"];               [key addObject:@"__pandas__libs_join"];
    [name addObject:@"testing"];            [key addObject:@"__pandas__libs_testing"];
    [name addObject:@"reshape"];            [key addObject:@"__pandas__libs_reshape"];
    [name addObject:@"internals"];          [key addObject:@"__pandas__libs_internals"];
    [name addObject:@"hashing"];            [key addObject:@"__pandas__libs_hashing"];
    [name addObject:@"missing"];            [key addObject:@"__pandas__libs_missing"];
    [name addObject:@"groupby"];            [key addObject:@"__pandas__libs_groupby"];
    [name addObject:@"parsers"];            [key addObject:@"__pandas__libs_parsers"];
    [name addObject:@"ops"];                [key addObject:@"__pandas__libs_ops"];
    [name addObject:@"indexing"];           [key addObject:@"__pandas__libs_indexing"];
    [name addObject:@"sparse"];             [key addObject:@"__pandas__libs_sparse"];
    [name addObject:@"window"];             [key addObject:@"__pandas__libs_window"];
    [name addObject:@"ccalendar"];          [key addObject:@"__pandas__libs_tslibs_ccalendar"];
    [name addObject:@"conversion"];         [key addObject:@"__pandas__libs_tslibs_conversion"];
    [name addObject:@"fields"];             [key addObject:@"__pandas__libs_tslibs_fields"];
    [name addObject:@"nattype"];            [key addObject:@"__pandas__libs_tslibs_nattype"];
    [name addObject:@"timedeltas"];         [key addObject:@"__pandas__libs_tslibs_timedeltas"];
    [name addObject:@"frequencies"];        [key addObject:@"__pandas__libs_tslibs_frequencies"];
    [name addObject:@"resolution"];         [key addObject:@"__pandas__libs_tslibs_resolution"];
    [name addObject:@"offsets"];            [key addObject:@"__pandas__libs_tslibs_offsets"];
    [name addObject:@"np_datetime"];        [key addObject:@"__pandas__libs_tslibs_np_datetime"];
    [name addObject:@"period"];             [key addObject:@"__pandas__libs_tslibs_period"];
    [name addObject:@"timezones"];          [key addObject:@"__pandas__libs_tslibs_timezones"];
    [name addObject:@"strptime"];           [key addObject:@"__pandas__libs_tslibs_strptime"];
    [name addObject:@"parsing"];            [key addObject:@"__pandas__libs_tslibs_parsing"];
    [name addObject:@"timestamps"];         [key addObject:@"__pandas__libs_tslibs_timestamps"];
    [name addObject:@"tslib"];              [key addObject:@"__pandas__libs_tslib"];
    [name addObject:@"index"];              [key addObject:@"__pandas__libs_index"];
    [name addObject:@"algos"];              [key addObject:@"__pandas__libs_algos"];
    [name addObject:@"skiplist"];           [key addObject:@"__pandas__libs_skiplist"];
    [name addObject:@"hashtable"];          [key addObject:@"__pandas__libs_hashtable"];
    [name addObject:@"json"];               [key addObject:@"__pandas__libs_json"];
    BandHandle(@"pandas", name, key);
}

// MARK: - Main

#if MAIN
int main(int argc, char *argv[]) {
#else
void init_python() {
#endif
    
    // MARK: - Init builtins
    #if MAIN
    init_numpy();
    init_matplotlib();
    init_pandas();
    #endif
    
    NSString *pythonHome = Python.shared.bundle.bundlePath;
    // MARK: - Python env variables
    putenv("PYTHONOPTIMIZE=");
    putenv("PYTHONDONTWRITEBYTECODE=1");
    putenv((char *)[[NSString stringWithFormat:@"TMP=%@", NSTemporaryDirectory()] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONHOME=%@", pythonHome] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONPATH=%@:%@", [mainBundle() pathForResource:@"site-packages" ofType:NULL],
                     [pythonHome stringByAppendingPathComponent:@"python37.zip"]] UTF8String]);
    
    // MARK: - Init Python
    Py_SetPythonHome(Py_DecodeLocale([pythonHome UTF8String], NULL));
    Py_Initialize();
    PyEval_InitThreads();
    
    #if !MAIN
    int argc = 0;
    const char *argv[0] = {};
    #endif
    
    wchar_t** python_argv = PyMem_RawMalloc(sizeof(wchar_t*) * argc);
    int i;
    for (i = 0; i < argc; i++) {
        python_argv[i] = Py_DecodeLocale(argv[i], NULL);
    }
    PySys_SetArgv(argc, python_argv);
    
    #if MAIN
    [Python.shared importPytoLib];
    
    // MARK: - Start the REPL that will contain all child modules
    [Python.shared runScriptAt:[[NSBundle mainBundle] URLForResource:@"scripts_runner" withExtension:@"py"]];
    
    @autoreleasepool {
        return UIApplicationMain(argc, argv, NULL, NSStringFromClass(AppDelegate.class));
    }
    #else
    NSString *certPath = [mainBundle() pathForResource:@"cacert.pem" ofType:NULL];
    putenv((char *)[[NSString stringWithFormat:@"SSL_CERT_FILE=%@", certPath] UTF8String]);
    #endif
}
