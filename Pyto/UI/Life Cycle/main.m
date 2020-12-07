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
#import "../Python/Python.h"
#if MAIN
#import "Pyto-Swift.h"
#elif WIDGET
#if Xcode11
#import "TodayExtension-Swift.h"
#else
#import "WidgetExtension-Swift.h"
#endif
#endif

#if MAIN || WIDGET && !Xcode11
#import "../../../Extensions/_extensionsimporter.h"
#endif

#include <dlfcn.h>

#define load(HANDLE) handle = dlopen(file.path.UTF8String, RTLD_GLOBAL);  HANDLE = handle;

void logToNSLog(const char* text) {
    NSLog(@"Log from Python: %s", text);
}

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
    return [NSBundle mainBundle];
    #endif
}

// MARK: - Main

#if MAIN || WIDGET
int initialize_python(int argc, char *argv[]) {
    
    NSBundle *pythonBundle = Python.shared.bundle;
    // MARK: - Python env variables
    putenv("PYTHONOPTIMIZE=");
    putenv("PYTHONIOENCODING=utf-8");
    #if !WIDGET
    putenv("PYTHONDONTWRITEBYTECODE=1");
    #endif
    NSString *zippedLib = [pythonBundle pathForResource:@"python38.zip" ofType:NULL];
    
    putenv((char *)[[NSString stringWithFormat:@"ZIPPEDLIB=%@", zippedLib] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"TMP=%@", NSTemporaryDirectory()] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONHOME=%@", pythonBundle.bundlePath] UTF8String]);
    NSString* path = [NSString stringWithFormat:@"PYTHONPATH=%@:%@:%@:%@:%@", [[NSFileManager.defaultManager URLsForDirectory:NSLibraryDirectory inDomains:NSAllDomainsMask].firstObject URLByAppendingPathComponent:@"python38"].path, [mainBundle() pathForResource: @"Lib" ofType:NULL], [mainBundle() pathForResource: @"Lib/objc" ofType:NULL], [mainBundle() pathForResource:@"site-packages" ofType:NULL], zippedLib];
    #if WIDGET
    path = [path stringByAppendingString: [NSString stringWithFormat:@":%@:%@", [NSFileManager.defaultManager sharedDirectory], [NSFileManager.defaultManager.sharedDirectory URLByAppendingPathComponent:@"modules"]]];
    #endif
    putenv((char *)path.UTF8String);
    
    #if WIDGET
    NSString *certPath = [mainBundle() pathForResource:@"cacert.pem" ofType:NULL];
    putenv((char *)[[NSString stringWithFormat:@"SSL_CERT_FILE=%@", certPath] UTF8String]);
    putenv("PYTHONMALLOC=malloc");
    #endif
    
    // Astropy
    NSString *caches = [NSFileManager.defaultManager URLsForDirectory:NSCachesDirectory inDomains:NSAllDomainsMask].firstObject.path;
    NSString *astropyCaches = [caches stringByAppendingPathComponent:@"astropy"];
    if ([NSFileManager.defaultManager fileExistsAtPath:astropyCaches]) {
        [NSFileManager.defaultManager removeItemAtPath:astropyCaches error:NULL];
    }
    [NSFileManager.defaultManager createDirectoryAtPath:astropyCaches withIntermediateDirectories:YES attributes:NULL error:NULL];
    putenv((char *)[NSString stringWithFormat:@"XDG_CACHE_HOME=%@", caches].UTF8String);
    [NSFileManager.defaultManager createDirectoryAtPath:astropyCaches withIntermediateDirectories:YES attributes:NULL error:NULL];
    putenv((char *)[NSString stringWithFormat:@"XDG_CONFIG_HOME=%@", caches].UTF8String);
    
    // SKLearn data
    putenv((char *)[NSString stringWithFormat:@"SCIKIT_LEARN_DATA=%@", [NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask].firstObject.path].UTF8String);
    
    // MARK: - Init Python
    
    #if MAIN || WIDGET && !Xcode11
    PyImport_AppendInittab("_extensionsimporter", &PyInit__extensionsimporter);
    #endif
    
    #if MAIN
    dispatch_async(dispatch_queue_create(NULL, NULL), ^{
    #endif
        #if MAIN
        // Matplotlib
        NSURL *mpl_data = [[NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask].firstObject URLByAppendingPathComponent:@"mpl-data"];
        NSURL *mpl_config = [[NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask].firstObject URLByAppendingPathComponent:@"matplotlib"];
        
        if (![NSFileManager.defaultManager fileExistsAtPath:mpl_data.path]) {
            [NSFileManager.defaultManager createDirectoryAtPath:mpl_data.path withIntermediateDirectories:NO attributes:NULL error:NULL];
        }
        
        if (![NSFileManager.defaultManager fileExistsAtPath:mpl_config.path]) {
            [NSFileManager.defaultManager createDirectoryAtPath:mpl_config.path withIntermediateDirectories:NO attributes:NULL error:NULL];
        }
        
        putenv((char *)[[NSString stringWithFormat:@"MATPLOTLIBDATA=%@", mpl_data.path] UTF8String]);
        putenv((char *)[[NSString stringWithFormat:@"MPLCONFIGDIR=%@", mpl_config.path] UTF8String]);
        
        for (NSURL *fileURL in [NSFileManager.defaultManager contentsOfDirectoryAtURL:[mainBundle() URLForResource:@"site-packages/mpl-data" withExtension:NULL] includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:NULL]) {
            NSURL *newURL = [mpl_data URLByAppendingPathComponent:fileURL.lastPathComponent];
            if (![NSFileManager.defaultManager fileExistsAtPath:newURL.path]) {
                [NSFileManager.defaultManager copyItemAtURL:fileURL toURL:newURL error:NULL];
            }
        }
        #endif
        
        Py_SetPythonHome(Py_DecodeLocale([pythonBundle.bundlePath UTF8String], NULL));
        Py_Initialize();
        PyEval_InitThreads();
        
        #if MAIN
        wchar_t** python_argv = PyMem_RawMalloc(sizeof(wchar_t*) * argc);
        int i;
        for (i = 0; i < argc; i++) {
            python_argv[i] = Py_DecodeLocale(argv[i], NULL);
        }
        PySys_SetArgv(argc, python_argv);
        #endif
        
        // MARK: - Start the REPL that will contain all child modules
        #if !WIDGET
        [Python.shared runScriptAt:[[NSBundle mainBundle] URLForResource:@"scripts_runner" withExtension:@"py"]];
        #endif
    #if MAIN
    });
    #endif
    
    #if MAIN
    @autoreleasepool {
        return UIApplicationMain(argc, argv, NULL, NSStringFromClass(AppDelegate.class));
    }
    #endif
    
    return 0;
}

#if MAIN
int main(int argc, char *argv[]) {
#elif WIDGET
int init_python() {
#endif
    
    #if !MAIN
    int argc = 0;
    char *argv[] = {};
    #endif
    
    return initialize_python(argc, argv);
    
}
#endif

