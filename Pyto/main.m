//
//  main.m
//  Pyto
//
//  Created by Adrian Labbe on 9/16/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../Python/Headers/Python.h"
#if MAIN
#import "Pyto-Swift.h"
#elif WIDGET
#import "Pyto_Widget-Swift.h"
#endif
#include <dlfcn.h>

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

/// The path of the Python home directory.
NSString *pythonHome;

// MARK: - Modules

#define load(HANDLE) \
handle = dlopen(file.path.UTF8String, RTLD_GLOBAL); \
HANDLE = handle;

// MARK: - Numpy

PyMODINIT_FUNC (*PyInit__multiarray_umath)(void);
PyMODINIT_FUNC (*PyInit_fftpack_lite)(void);
PyMODINIT_FUNC (*PyInit__umath_linalg)(void);
PyMODINIT_FUNC (*PyInit_lapack_lite)(void);
PyMODINIT_FUNC (*PyInit_mtrand)(void);

void *_multiarray_umath = NULL;
void *fftpack_lite = NULL;
void *umath_linalg = NULL;
void *lapack_lite = NULL;
void *mtrand = NULL;

/// Initializes Numpy.
void init_numpy() {
    
    NSError *error;
    for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:mainBundle().privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
        NSURL *file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-37m-darwin.so"].lastPathComponent];
        
        NSString *name = file.URLByDeletingPathExtension.URLByDeletingPathExtension.lastPathComponent;
        
        void *handle;
        
        if ([name isEqualToString:@"_multiarray_umath"]) {
            load(_multiarray_umath);
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
            fprintf(stderr, "%s\n", dlerror());
        }
    }
    
    *(void **) (&PyInit__multiarray_umath) = dlsym(_multiarray_umath, "PyInit__multiarray_umath");
    *(void **) (&PyInit_fftpack_lite) = dlsym(fftpack_lite, "PyInit_fftpack_lite");
    *(void **) (&PyInit__umath_linalg) = dlsym(umath_linalg, "PyInit__umath_linalg");
    *(void **) (&PyInit_lapack_lite) = dlsym(lapack_lite, "PyInit_lapack_lite");
    *(void **) (&PyInit_mtrand) = dlsym(mtrand, "PyInit_mtrand");
    
    PyImport_AppendInittab("__numpy_core__multiarray_umath", PyInit__multiarray_umath);
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
    
    for (NSURL *fileURL in [NSFileManager.defaultManager contentsOfDirectoryAtURL:[mainBundle() URLForResource:@"site-packages/matplotlib/mpl-data" withExtension:NULL] includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:NULL]) {
        NSURL *newURL = [mpl_data URLByAppendingPathComponent:fileURL.lastPathComponent];
        if (![NSFileManager.defaultManager fileExistsAtPath:newURL.path]) {
            [NSFileManager.defaultManager copyItemAtURL:fileURL toURL:newURL error:NULL];
        }
    }
    
    NSError *error;
    for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:mainBundle().privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
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
            fprintf(stderr, "%s\n", dlerror());
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

// MARK: - Pandas

void *writers = NULL;
void *_packer = NULL;
void *_sas = NULL;
void *hashtable = NULL;
void *reshape = NULL;
void *tslib = NULL;
void *interval = NULL;
void *missing = NULL;
void *ops = NULL;
void *_unpacker = NULL;
void *hashing = NULL;
void *join = NULL;
void *sparse = NULL;
void *indexing = NULL;
void *parsers = NULL;
void *algos = NULL;
void *reduction = NULL;
void *testing = NULL;
void *properties = NULL;
void *internals = NULL;
void *window = NULL;
void *json = NULL;
void *pandas_index = NULL;
void *groupby = NULL;
void *skiplist = NULL;
void *lib = NULL;
void *_move = NULL;
void *ccalendar = NULL;
void *conversion = NULL;
void *fields = NULL;
void *nattype = NULL;
void *timedeltas = NULL;
void *frequencies = NULL;
void *resolution = NULL;
void *offsets = NULL;
void *np_datetime = NULL;
void *period = NULL;
void *timezones = NULL;
void *pandas_strptime = NULL;
void *parsing = NULL;
void *timestamps = NULL;

PyMODINIT_FUNC (*PyInit_writers)(void);
PyMODINIT_FUNC (*PyInit__packer)(void);
PyMODINIT_FUNC (*PyInit__sas)(void);
PyMODINIT_FUNC (*PyInit_hashtable)(void);
PyMODINIT_FUNC (*PyInit_reshape)(void);
PyMODINIT_FUNC (*PyInit_tslib)(void);
PyMODINIT_FUNC (*PyInit_interval)(void);
PyMODINIT_FUNC (*PyInit_missing)(void);
PyMODINIT_FUNC (*PyInit_ops)(void);
PyMODINIT_FUNC (*PyInit__unpacker)(void);
PyMODINIT_FUNC (*PyInit_hashing)(void);
PyMODINIT_FUNC (*PyInit_join)(void);
PyMODINIT_FUNC (*PyInit_sparse)(void);
PyMODINIT_FUNC (*PyInit_indexing)(void);
PyMODINIT_FUNC (*PyInit_parsers)(void);
PyMODINIT_FUNC (*PyInit_algos)(void);
PyMODINIT_FUNC (*PyInit_reduction)(void);
PyMODINIT_FUNC (*PyInit_testing)(void);
PyMODINIT_FUNC (*PyInit_properties)(void);
PyMODINIT_FUNC (*PyInit_internals)(void);
PyMODINIT_FUNC (*PyInit_window)(void);
PyMODINIT_FUNC (*PyInit_json)(void);
PyMODINIT_FUNC (*PyInit_index)(void);
PyMODINIT_FUNC (*PyInit_groupby)(void);
PyMODINIT_FUNC (*PyInit_skiplist)(void);
PyMODINIT_FUNC (*PyInit_lib)(void);
PyMODINIT_FUNC (*PyInit__move)(void);
PyMODINIT_FUNC (*PyInit_ccalendar)(void);
PyMODINIT_FUNC (*PyInit_conversion)(void);
PyMODINIT_FUNC (*PyInit_fields)(void);
PyMODINIT_FUNC (*PyInit_nattype)(void);
PyMODINIT_FUNC (*PyInit_timedeltas)(void);
PyMODINIT_FUNC (*PyInit_frequencies)(void);
PyMODINIT_FUNC (*PyInit_resolution)(void);
PyMODINIT_FUNC (*PyInit_offsets)(void);
PyMODINIT_FUNC (*PyInit_np_datetime)(void);
PyMODINIT_FUNC (*PyInit_period)(void);
PyMODINIT_FUNC (*PyInit_timezones)(void);
PyMODINIT_FUNC (*PyInit_strptime)(void);
PyMODINIT_FUNC (*PyInit_parsing)(void);
PyMODINIT_FUNC (*PyInit_timestamps)(void);

/// Initializes Pandas.
void init_pandas() {
    NSError *error;
    for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:mainBundle().privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
        NSURL *file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-37m-darwin.so"].lastPathComponent];
        
        NSString *name = file.URLByDeletingPathExtension.URLByDeletingPathExtension.lastPathComponent;
        
        if ([file.pathExtension isEqualToString:@"so"]) {
            
            void *handle;
            
            if ([name isEqualToString:@"writers"]) {
                load(writers);
            } else if ([name isEqualToString:@"_packer"]) {
                load(_packer);
            } else if ([name isEqualToString:@"_sas"]) {
                load(_sas);
            } else if ([name isEqualToString:@"hashtable"]) {
                load(hashtable);
            } else if ([name isEqualToString:@"reshape"]) {
                load(reshape);
            } else if ([name isEqualToString:@"tslib"]) {
                load(tslib);
            } else if ([name isEqualToString:@"interval"]) {
                load(interval);
            } else if ([name isEqualToString:@"missing"]) {
                load(missing);
            } else if ([name isEqualToString:@"ops"]) {
                load(ops);
            } else if ([name isEqualToString:@"_unpacker"]) {
                load(_unpacker);
            } else if ([name isEqualToString:@"hashing"]) {
                load(hashing);
            } else if ([name isEqualToString:@"join"]) {
                load(join);
            } else if ([name isEqualToString:@"sparse"]) {
                load(sparse);
            } else if ([name isEqualToString:@"indexing"]) {
                load(indexing);
            } else if ([name isEqualToString:@"parsers"]) {
                load(parsers);
            } else if ([name isEqualToString:@"algos"]) {
                load(algos);
            } else if ([name isEqualToString:@"reduction"]) {
                load(reduction);
            } else if ([name isEqualToString:@"testing"]) {
                load(testing);
            } else if ([name isEqualToString:@"properties"]) {
                load(properties);
            } else if ([name isEqualToString:@"internals"]) {
                load(internals);
            } else if ([name isEqualToString:@"window"]) {
                load(window);
            } else if ([name isEqualToString:@"json"]) {
                load(json);
            } else if ([name isEqualToString:@"index"]) {
                load(pandas_index);
            } else if ([name isEqualToString:@"groupby"]) {
                load(groupby);
            } else if ([name isEqualToString:@"skiplist"]) {
                load(skiplist);
            } else if ([name isEqualToString:@"lib"]) {
                load(lib);
            } else if ([name isEqualToString:@"_move"]) {
                load(_move);
            } else if ([name isEqualToString:@"ccalendar"]) {
                load(ccalendar);
            } else if ([name isEqualToString:@"conversion"]) {
                load(conversion);
            } else if ([name isEqualToString:@"fields"]) {
                load(fields);
            } else if ([name isEqualToString:@"nattype"]) {
                load(nattype);
            } else if ([name isEqualToString:@"timedeltas"]) {
                load(timedeltas);
            } else if ([name isEqualToString:@"frequencies"]) {
                load(frequencies);
            } else if ([name isEqualToString:@"resolution"]) {
                load(resolution);
            } else if ([name isEqualToString:@"offsets"]) {
                load(offsets);
            } else if ([name isEqualToString:@"np_datetime"]) {
                load(np_datetime);
            } else if ([name isEqualToString:@"period"]) {
                load(period);
            } else if ([name isEqualToString:@"timezones"]) {
                load(timezones);
            } else if ([name isEqualToString:@"strptime"]) {
                load(pandas_strptime);
            } else if ([name isEqualToString:@"parsing"]) {
                load(parsing);
            } else if ([name isEqualToString:@"timestamps"]) {
                load(timestamps);
            } else {
                continue;
            }
            
            if (!handle) {
                fprintf(stderr, "%s\n", dlerror());
            }
        }
    }
    
    *(void **) (&PyInit_writers) = dlsym(writers, "PyInit_writers");
    *(void **) (&PyInit__packer) = dlsym(_packer, "PyInit__packer");
    *(void **) (&PyInit__sas) = dlsym(_sas, "PyInit__sas");
    *(void **) (&PyInit_hashtable) = dlsym(hashtable, "PyInit_hashtable");
    *(void **) (&PyInit_reshape) = dlsym(reshape, "PyInit_reshape");
    *(void **) (&PyInit_tslib) = dlsym(tslib, "PyInit_tslib");
    *(void **) (&PyInit_interval) = dlsym(interval, "PyInit_interval");
    *(void **) (&PyInit_missing) = dlsym(missing, "PyInit_missing");
    *(void **) (&PyInit_ops) = dlsym(ops, "PyInit_ops");
    *(void **) (&PyInit__unpacker) = dlsym(_unpacker, "PyInit__unpacker");
    *(void **) (&PyInit_hashing) = dlsym(hashing, "PyInit_hashing");
    *(void **) (&PyInit_join) = dlsym(join, "PyInit_join");
    *(void **) (&PyInit_sparse) = dlsym(sparse, "PyInit_sparse");
    *(void **) (&PyInit_indexing) = dlsym(indexing, "PyInit_indexing");
    *(void **) (&PyInit_parsers) = dlsym(parsers, "PyInit_parsers");
    *(void **) (&PyInit_algos) = dlsym(algos, "PyInit_algos");
    *(void **) (&PyInit_reduction) = dlsym(reduction, "PyInit_reduction");
    *(void **) (&PyInit_testing) = dlsym(testing, "PyInit_testing");
    *(void **) (&PyInit_properties) = dlsym(properties, "PyInit_properties");
    *(void **) (&PyInit_internals) = dlsym(internals, "PyInit_internals");
    *(void **) (&PyInit_window) = dlsym(window, "PyInit_window");
    *(void **) (&PyInit_json) = dlsym(json, "PyInit_json");
    *(void **) (&PyInit_index) = dlsym(pandas_index, "PyInit_index");
    *(void **) (&PyInit_groupby) = dlsym(groupby, "PyInit_groupby");
    *(void **) (&PyInit_skiplist) = dlsym(skiplist, "PyInit_skiplist");
    *(void **) (&PyInit_lib) = dlsym(lib, "PyInit_lib");
    *(void **) (&PyInit__move) = dlsym(_move, "PyInit__move");
    *(void **) (&PyInit_ccalendar) = dlsym(ccalendar, "PyInit_ccalendar");
    *(void **) (&PyInit_conversion) = dlsym(conversion, "PyInit_conversion");
    *(void **) (&PyInit_fields) = dlsym(fields, "PyInit_fields");
    *(void **) (&PyInit_nattype) = dlsym(nattype, "PyInit_nattype");
    *(void **) (&PyInit_timedeltas) = dlsym(timedeltas, "PyInit_timedeltas");
    *(void **) (&PyInit_frequencies) = dlsym(frequencies, "PyInit_frequencies");
    *(void **) (&PyInit_resolution) = dlsym(resolution, "PyInit_resolution");
    *(void **) (&PyInit_offsets) = dlsym(offsets, "PyInit_offsets");
    *(void **) (&PyInit_np_datetime) = dlsym(np_datetime, "PyInit_np_datetime");
    *(void **) (&PyInit_period) = dlsym(period, "PyInit_period");
    *(void **) (&PyInit_timezones) = dlsym(timezones, "PyInit_timezones");
    *(void **) (&PyInit_strptime) = dlsym(pandas_strptime, "PyInit_strptime");
    *(void **) (&PyInit_parsing) = dlsym(parsing, "PyInit_parsing");
    *(void **) (&PyInit_timestamps) = dlsym(timestamps, "PyInit_timestamps");
    
    PyImport_AppendInittab("__pandas__libs_writers", PyInit_writers);
    PyImport_AppendInittab("__pandas_io_msgpack__packer", PyInit__packer);
    PyImport_AppendInittab("__pandas_io_sas__sas", PyInit__sas);
    PyImport_AppendInittab("__pandas__libs_hashtable", PyInit_hashtable);
    PyImport_AppendInittab("__pandas__libs_reshape", PyInit_reshape);
    PyImport_AppendInittab("__pandas__libs_tslib", PyInit_tslib);
    PyImport_AppendInittab("__pandas__libs_interval", PyInit_interval);
    PyImport_AppendInittab("__pandas__libs_missing", PyInit_missing);
    PyImport_AppendInittab("__pandas__libs_ops", PyInit_ops);
    PyImport_AppendInittab("__pandas_io_msgpack__unpacker", PyInit__unpacker);
    PyImport_AppendInittab("__pandas__libs_hashing", PyInit_hashing);
    PyImport_AppendInittab("__pandas__libs_join", PyInit_join);
    PyImport_AppendInittab("__pandas__libs_sparse", PyInit_sparse);
    PyImport_AppendInittab("__pandas__libs_indexing", PyInit_indexing);
    PyImport_AppendInittab("__pandas__libs_parsers", PyInit_parsers);
    PyImport_AppendInittab("__pandas__libs_algos", PyInit_algos);
    PyImport_AppendInittab("__pandas__libs_reduction", PyInit_reduction);
    PyImport_AppendInittab("__pandas__libs_testing", PyInit_testing);
    PyImport_AppendInittab("__pandas__libs_properties", PyInit_properties);
    PyImport_AppendInittab("__pandas__libs_internals", PyInit_internals);
    PyImport_AppendInittab("__pandas__libs_window", PyInit_window);
    PyImport_AppendInittab("__pandas__libs_json", PyInit_json);
    PyImport_AppendInittab("__pandas__libs_index", PyInit_index);
    PyImport_AppendInittab("__pandas__libs_groupby", PyInit_groupby);
    PyImport_AppendInittab("__pandas__libs_skiplist", PyInit_skiplist);
    PyImport_AppendInittab("__pandas__libs_lib", PyInit_lib);
    PyImport_AppendInittab("__pandas_util__move", PyInit__move);
    PyImport_AppendInittab("__pandas__libs_tslibs_ccalendar", PyInit_ccalendar);
    PyImport_AppendInittab("__pandas__libs_tslibs_conversion", PyInit_conversion);
    PyImport_AppendInittab("__pandas__libs_tslibs_fields", PyInit_fields);
    PyImport_AppendInittab("__pandas__libs_tslibs_nattype", PyInit_nattype);
    PyImport_AppendInittab("__pandas__libs_tslibs_timedeltas", PyInit_timedeltas);
    PyImport_AppendInittab("__pandas__libs_tslibs_frequencies", PyInit_frequencies);
    PyImport_AppendInittab("__pandas__libs_tslibs_resolution", PyInit_resolution);
    PyImport_AppendInittab("__pandas__libs_tslibs_offsets", PyInit_offsets);
    PyImport_AppendInittab("__pandas__libs_tslibs_np_datetime", PyInit_np_datetime);
    PyImport_AppendInittab("__pandas__libs_tslibs_period", PyInit_period);
    PyImport_AppendInittab("__pandas__libs_tslibs_timezones", PyInit_timezones);
    PyImport_AppendInittab("__pandas__libs_tslibs_strptime", PyInit_strptime);
    PyImport_AppendInittab("__pandas__libs_tslibs_parsing", PyInit_parsing);
    PyImport_AppendInittab("__pandas__libs_tslibs_timestamps", PyInit_timestamps);
}

// MARK: - Main

#if MAIN
int main(int argc, char *argv[]) {
#else
void init_python() {
#endif
    
    pythonHome = Python.shared.bundle.bundlePath;
    
    if (!pythonHome) {
        Py_FatalError("Python home doesn't exist");
    }
    
    // MARK: - Python env variables
    putenv("PYTHONOPTIMIZE=");
    putenv("PYTHONDONTWRITEBYTECODE=1");
    putenv((char *)[[NSString stringWithFormat:@"TMP=%@", NSTemporaryDirectory()] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONHOME=%@", pythonHome] UTF8String]);
    putenv((char *)[[NSString stringWithFormat:@"PYTHONPATH=%@:%@", [mainBundle() pathForResource:@"site-packages" ofType:NULL], [pythonHome stringByAppendingPathComponent:@"python37.zip"]] UTF8String]);
    
    // MARK: - Init builtins
    #if MAIN
    init_numpy();
    init_matplotlib();
    init_pandas();
    #endif    
    
    // MARK: - Init Python
    Py_SetPythonHome(Py_DecodeLocale([pythonHome UTF8String], NULL));
    Py_Initialize();
    PyEval_InitThreads();
    
    // MARK: - Set Python arguments
    
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
    [Python.shared runScriptAt:[[NSBundle mainBundle] URLForResource:@"REPL" withExtension:@"py"]];
    
    @autoreleasepool {
        return UIApplicationMain(argc, argv, NULL, NSStringFromClass(AppDelegate.class));
    }
    #else
    NSString *certPath = [mainBundle() pathForResource:@"cacert.pem" ofType:NULL];
    putenv((char *)[[NSString stringWithFormat:@"SSL_CERT_FILE=%@", certPath] UTF8String]);
    #endif
}
