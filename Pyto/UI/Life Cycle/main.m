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
<<<<<<< HEAD
#import "../../../Extensions/_extensionsimporter.h"
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
#elif WIDGET
#if Xcode11
#import "TodayExtension-Swift.h"
#else
#import "WidgetExtension-Swift.h"
#endif
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

<<<<<<< HEAD
=======
// MARK: - BandHandle

void BandHandle(NSString *fkTitle, NSArray *nameArray, NSArray *keyArray) {
    
    NSError *error;
    for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:mainBundle().privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
        NSURL *file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-37m-darwin.so"].lastPathComponent];
        if (![NSFileManager.defaultManager fileExistsAtPath:file.path]) {
            file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"abi3.so"].lastPathComponent];
        }
        if (![NSFileManager.defaultManager fileExistsAtPath:file.path]) {
            file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-38-darwin.so"].lastPathComponent];
        }
        if (![NSFileManager.defaultManager fileExistsAtPath:file.path]) {
            file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"abi3.so"].lastPathComponent];
        }
        NSString *name = file.URLByDeletingPathExtension.URLByDeletingPathExtension.lastPathComponent;
        
        void *handle = NULL;
        for( int i=0; i<nameArray.count; i++){
            NSString *fkey  = [keyArray  objectAtIndex:i];
            
            #if MAIN || WIDGET
            NSArray *imported = [[NSArray alloc] initWithArray: Python.shared.importedModules];
            if ([imported containsObject: fkey]) {
                continue;
            }
            #endif
            
            if ([name isEqualToString:[nameArray objectAtIndex:i]]){
                void *dllHandle = NULL; load(dllHandle);
                
                if (!dllHandle) {
                    fprintf(stderr, "%s\n", dlerror());
                }
                
                NSString *funcName = [nameArray objectAtIndex:i];
                
                PyObject* (*func)(void);
                func = dlsym(dllHandle, [NSString stringWithFormat:@"PyInit_%@", funcName].UTF8String);
                
                if (!func) {
                    NSMutableArray *comp = [NSMutableArray arrayWithArray:[funcName componentsSeparatedByString:@"_"]];
                    [comp removeObjectAtIndex:0];
                    func = dlsym(dllHandle, [NSString stringWithFormat:@"PyInit__%@", [comp componentsJoinedByString:@"_"]].UTF8String);
                    if (!func) {
                        func = dlsym(dllHandle, [NSString stringWithFormat:@"PyInit_%@", [comp componentsJoinedByString:@"_"]].UTF8String);
                    }
                }
                
                if (!handle) {
                    fprintf(stderr, "%s\n", dlerror());
                } else {
                    if (!func) {
                        NSLog(@"%@", funcName);
                    } else {
                        //PyObject* pyModule = func();
                        //PyObject* importer = Pymodule;
                        //[Python.shared.modules setObject: (__bridge id _Nonnull)(pyModule) forKey: fkey];
                        PyImport_AppendInittab(fkey.UTF8String, func);
                        #if MAIN
                        [Python.shared.modules addObject: fkey];
                        #endif
                    }
                }
                break;
            }
        }
    }
}

#if !(TARGET_IPHONE_SIMULATOR)

#if MAIN

// MARK: - Matplotlib

void init_matplotlib() {
    NSURL *mpl_data = [[NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask].firstObject URLByAppendingPathComponent:@"mpl-data"];
    
    if (![NSFileManager.defaultManager fileExistsAtPath:mpl_data.path]) {
        [NSFileManager.defaultManager createDirectoryAtPath:mpl_data.path withIntermediateDirectories:NO attributes:NULL error:NULL];
    }
    
    putenv((char *)[[NSString stringWithFormat:@"MATPLOTLIBDATA=%@", mpl_data.path] UTF8String]);
    
    for (NSURL *fileURL in [NSFileManager.defaultManager contentsOfDirectoryAtURL:[mainBundle() URLForResource:@"site-packages/mpl-data" withExtension:NULL] includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:NULL]) {
        NSURL *newURL = [mpl_data URLByAppendingPathComponent:fileURL.lastPathComponent];
        if (![NSFileManager.defaultManager fileExistsAtPath:newURL.path]) {
            [NSFileManager.defaultManager copyItemAtURL:fileURL toURL:newURL error:NULL];
        }
    }
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"ttconv"];             [key addObject:@"__matplotlib_ttconv"];
    [name addObject:@"_backend_agg"];       [key addObject:@"__matplotlib_backends__backend_agg"];
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
    [name addObject:@"_sas"];         [key addObject:@"__pandas_io_sas__sas"];
    [name addObject:@"aggregations"]; [key addObject:@"__pandas__libs_window_aggregations"];
    [name addObject:@"algos"];        [key addObject:@"__pandas__libs_algos"];
    [name addObject:@"c_timestamp"];  [key addObject:@"__pandas__libs_tslibs_c_timestamp"];
    [name addObject:@"ccalendar"];    [key addObject:@"__pandas__libs_tslibs_ccalendar"];
    [name addObject:@"conversion"];   [key addObject:@"__pandas__libs_tslibs_conversion"];
    [name addObject:@"fields"];       [key addObject:@"__pandas__libs_tslibs_fields"];
    [name addObject:@"frequencies"];  [key addObject:@"__pandas__libs_tslibs_frequencies"];
    [name addObject:@"groupby"];      [key addObject:@"__pandas__libs_groupby"];
    [name addObject:@"hashing"];      [key addObject:@"__pandas__libs_hashing"];
    [name addObject:@"hashtable"];    [key addObject:@"__pandas__libs_hashtable"];
    [name addObject:@"index"];        [key addObject:@"__pandas__libs_index"];
    [name addObject:@"indexers"];     [key addObject:@"__pandas__libs_window_indexers"];
    [name addObject:@"indexing"];     [key addObject:@"__pandas__libs_indexing"];
    [name addObject:@"internals"];    [key addObject:@"__pandas__libs_internals"];
    [name addObject:@"interval"];     [key addObject:@"__pandas__libs_interval"];
    [name addObject:@"join"];         [key addObject:@"__pandas__libs_join"];
    [name addObject:@"json"];         [key addObject:@"__pandas__libs_json"];
    [name addObject:@"lib"];          [key addObject:@"__pandas__libs_lib"];
    [name addObject:@"missing"];      [key addObject:@"__pandas__libs_missing"];
    [name addObject:@"nattype"];      [key addObject:@"__pandas__libs_tslibs_nattype"];
    [name addObject:@"np_datetime"];  [key addObject:@"__pandas__libs_tslibs_np_datetime"];
    [name addObject:@"offsets"];      [key addObject:@"__pandas__libs_tslibs_offsets"];
    [name addObject:@"ops_dispatch"]; [key addObject:@"__pandas__libs_ops_dispatch"];
    [name addObject:@"ops"];          [key addObject:@"__pandas__libs_ops"];
    [name addObject:@"parsers"];      [key addObject:@"__pandas__libs_parsers"];
    [name addObject:@"parsing"];      [key addObject:@"__pandas__libs_tslibs_parsing"];
    [name addObject:@"period"];       [key addObject:@"__pandas__libs_tslibs_period"];
    [name addObject:@"properties"];   [key addObject:@"__pandas__libs_properties"];
    [name addObject:@"reduction"];    [key addObject:@"__pandas__libs_reduction"];
    [name addObject:@"reshape"];      [key addObject:@"__pandas__libs_reshape"];
    [name addObject:@"resolution"];   [key addObject:@"__pandas__libs_tslibs_resolution"];
    [name addObject:@"sparse"];       [key addObject:@"__pandas__libs_sparse"];
    [name addObject:@"strptime"];     [key addObject:@"__pandas__libs_tslibs_strptime"];
    [name addObject:@"testing"];      [key addObject:@"__pandas__libs_testing"];
    [name addObject:@"timedeltas"];   [key addObject:@"__pandas__libs_tslibs_timedeltas"];
    [name addObject:@"timestamps"];   [key addObject:@"__pandas__libs_tslibs_timestamps"];
    [name addObject:@"timezones"];    [key addObject:@"__pandas__libs_tslibs_timezones"];
    [name addObject:@"tslib"];        [key addObject:@"__pandas__libs_tslib"];
    [name addObject:@"tzconversion"]; [key addObject:@"__pandas__libs_tslibs_tzconversion"];
    [name addObject:@"writers"];      [key addObject:@"__pandas__libs_writers"];
    BandHandle(@"pandas", name, key);
}

// MARK: - Biopython

void init_biopython() {

    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_aligners"];              [key addObject:@"__Bio_Align__aligners"];
    [name addObject:@"_CKDTree"];               [key addObject:@"__Bio_KDTree__CKDTree"];
    [name addObject:@"_cluster"];               [key addObject:@"__Bio_Cluster__cluster"];
    [name addObject:@"_pwm"];                   [key addObject:@"__Bio_motifs__pwm"];
    [name addObject:@"cnexus"];                 [key addObject:@"__Bio_Nexus_cnexus"];
    [name addObject:@"cpairwise2"];             [key addObject:@"__Bio_cpairwise2"];
    [name addObject:@"kdtrees"];                [key addObject:@"__Bio_PDB_kdtrees"];
    [name addObject:@"qcprotmodule"];           [key addObject:@"__Bio_PDB_QCPSuperimposer_qcprotmodule"];
    [name addObject:@"trie"];                   [key addObject:@"__Bio_trie"];
    BandHandle(@"Bio", name, key);
}

// MARK: - LXML

extern PyMODINIT_FUNC PyInit__elementpath(void);
extern PyMODINIT_FUNC PyInit_builder(void);
extern PyMODINIT_FUNC PyInit_etree(void);
extern PyMODINIT_FUNC PyInit_clean(void);
extern PyMODINIT_FUNC PyInit_diff(void);
extern PyMODINIT_FUNC PyInit_objectify(void);

void init_lxml() {
    PyImport_AppendInittab("__lxml__elementpath", &PyInit__elementpath);
    PyImport_AppendInittab("__lxml_builder", &PyInit_builder);
    PyImport_AppendInittab("__lxml_etree", &PyInit_etree);
    PyImport_AppendInittab("__lxml_html_clean", &PyInit_clean);
    PyImport_AppendInittab("__lxml_html_diff", &PyInit_diff);
    PyImport_AppendInittab("__lxml_objectifiy", &PyInit_objectify);
}

// MARK: - SciPy

// Thanks @goodclass !!!!!!

#if !(TARGET_IPHONE_SIMULATOR)

//_lib
extern PyMODINIT_FUNC PyInit__ccallback_c(void);
extern PyMODINIT_FUNC PyInit__fpumode(void);
extern PyMODINIT_FUNC PyInit_messagestream(void);

//cluster
extern PyMODINIT_FUNC PyInit__vq(void);
extern PyMODINIT_FUNC PyInit__hierarchy(void);
extern PyMODINIT_FUNC PyInit__optimal_leaf_ordering(void);

//fftpack
extern PyMODINIT_FUNC PyInit__fftpack(void);
extern PyMODINIT_FUNC PyInit_convolve(void);

//integrate
extern PyMODINIT_FUNC PyInit__dop(void);
extern PyMODINIT_FUNC PyInit__odepack(void);
extern PyMODINIT_FUNC PyInit__quadpack(void);
extern PyMODINIT_FUNC PyInit_lsoda(void);
extern PyMODINIT_FUNC PyInit_vode(void);

//interpolate
extern PyMODINIT_FUNC PyInit__bspl(void);
extern PyMODINIT_FUNC PyInit__fitpack(void);
extern PyMODINIT_FUNC PyInit__interpolate(void);
extern PyMODINIT_FUNC PyInit__ppoly(void);
extern PyMODINIT_FUNC PyInit_dfitpack(void);
extern PyMODINIT_FUNC PyInit_interpnd(void);

//io_matlab
extern PyMODINIT_FUNC PyInit_mio5_utils(void);
extern PyMODINIT_FUNC PyInit_mio_utils(void);
extern PyMODINIT_FUNC PyInit_streams(void);

//linalg
extern PyMODINIT_FUNC PyInit__decomp_update(void);
extern PyMODINIT_FUNC PyInit__fblas(void);
extern PyMODINIT_FUNC PyInit__flapack(void);
extern PyMODINIT_FUNC PyInit__flinalg(void);
extern PyMODINIT_FUNC PyInit__interpolative(void);
extern PyMODINIT_FUNC PyInit__solve_toeplitz(void);
extern PyMODINIT_FUNC PyInit_cython_blas(void);
extern PyMODINIT_FUNC PyInit_cython_lapack(void);

//ndimage
extern PyMODINIT_FUNC PyInit__nd_image(void);
extern PyMODINIT_FUNC PyInit__ni_label(void);
extern PyMODINIT_FUNC PyInit___odrpack(void);

//optimize
extern PyMODINIT_FUNC PyInit__cobyla(void);
extern PyMODINIT_FUNC PyInit__group_columns(void);
extern PyMODINIT_FUNC PyInit__lbfgsb(void);
extern PyMODINIT_FUNC PyInit__minpack(void);
extern PyMODINIT_FUNC PyInit__nnls(void);
extern PyMODINIT_FUNC PyInit__slsqp(void);
extern PyMODINIT_FUNC PyInit__zeros(void);
extern PyMODINIT_FUNC PyInit_minpack2(void);
extern PyMODINIT_FUNC PyInit_moduleTNC(void);

extern PyMODINIT_FUNC PyInit_givens_elimination(void);
extern PyMODINIT_FUNC PyInit__trlib(void);

//signal
extern PyMODINIT_FUNC PyInit__max_len_seq_inner(void);
extern PyMODINIT_FUNC PyInit__peak_finding_utils(void);
extern PyMODINIT_FUNC PyInit__spectral(void);
extern PyMODINIT_FUNC PyInit__upfirdn_apply(void);
extern PyMODINIT_FUNC PyInit_sigtools(void);
extern PyMODINIT_FUNC PyInit_spline(void);

//sparse_csgraph
extern PyMODINIT_FUNC PyInit__min_spanning_tree(void);
extern PyMODINIT_FUNC PyInit__reordering(void);
extern PyMODINIT_FUNC PyInit__shortest_path(void);
extern PyMODINIT_FUNC PyInit__tools(void);
extern PyMODINIT_FUNC PyInit__traversal(void);
//sparse_linalg
extern PyMODINIT_FUNC PyInit__superlu(void);
extern PyMODINIT_FUNC PyInit__arpack(void);
extern PyMODINIT_FUNC PyInit__iterative(void);
//sparse
extern PyMODINIT_FUNC PyInit__csparsetools(void);
extern PyMODINIT_FUNC PyInit__sparsetools(void);

//spatial
extern PyMODINIT_FUNC PyInit__distance_wrap(void);
extern PyMODINIT_FUNC PyInit__hausdorff(void);
extern PyMODINIT_FUNC PyInit__voronoi(void);
extern PyMODINIT_FUNC PyInit_ckdtree(void);
extern PyMODINIT_FUNC PyInit_qhull(void);

//special
extern PyMODINIT_FUNC PyInit__comb(void);
extern PyMODINIT_FUNC PyInit__ellip_harm_2(void);
extern PyMODINIT_FUNC PyInit__ufuncs(void);
extern PyMODINIT_FUNC PyInit__ufuncs_cxx(void);
extern PyMODINIT_FUNC PyInit_cython_special(void);
extern PyMODINIT_FUNC PyInit_specfun(void);

//stats
extern PyMODINIT_FUNC PyInit__stats(void);
extern PyMODINIT_FUNC PyInit_mvn(void);
extern PyMODINIT_FUNC PyInit_statlib(void);

void init_scipy() {
    
    PyImport_AppendInittab("__scipy__lib__ccallback_c", &PyInit__ccallback_c);
    PyImport_AppendInittab("__scipy__lib__fpumode", &PyInit__fpumode);
    PyImport_AppendInittab("__scipy__lib_messagestream", &PyInit_messagestream);
    
    PyImport_AppendInittab("__scipy_cluster__vq", &PyInit__vq);
    PyImport_AppendInittab("__scipy_cluster__hierarchy", &PyInit__hierarchy);
    PyImport_AppendInittab("__scipy_cluster__optimal_leaf_ordering", &PyInit__optimal_leaf_ordering);
    
    PyImport_AppendInittab("__scipy_fftpack__fftpack", &PyInit__fftpack);
    PyImport_AppendInittab("__scipy_fftpack_convolve", &PyInit_convolve);
    
    PyImport_AppendInittab("__scipy_integrate__dop", &PyInit__dop);
    PyImport_AppendInittab("__scipy_integrate__odepack", &PyInit__odepack);
    PyImport_AppendInittab("__scipy_integrate__quadpack", &PyInit__quadpack);
    PyImport_AppendInittab("__scipy_integrate_lsoda", &PyInit_lsoda);
    PyImport_AppendInittab("__scipy_integrate_vode", &PyInit_vode);
    
    PyImport_AppendInittab("__scipy_interpolate__bspl", &PyInit__bspl);
    PyImport_AppendInittab("__scipy_interpolate__fitpack", &PyInit__fitpack);
    PyImport_AppendInittab("__scipy_interpolate__interpolate", &PyInit__interpolate);
    PyImport_AppendInittab("__scipy_interpolate__ppoly", &PyInit__ppoly);
    PyImport_AppendInittab("__scipy_interpolate_dfitpack", &PyInit_dfitpack);
    PyImport_AppendInittab("__scipy_interpolate_interpnd", &PyInit_interpnd);
    
    PyImport_AppendInittab("__scipy_io_matlab_mio5_utils", &PyInit_mio5_utils);
    PyImport_AppendInittab("__scipy_io_matlab_mio_utils", &PyInit_mio_utils);
    PyImport_AppendInittab("__scipy_io_matlab_streams", &PyInit_streams);
    
    PyImport_AppendInittab("__scipy_linalg__decomp_update", &PyInit__decomp_update);
    PyImport_AppendInittab("__scipy_linalg__fblas", &PyInit__fblas);
    PyImport_AppendInittab("__scipy_linalg__flapack", &PyInit__flapack);
    PyImport_AppendInittab("__scipy_linalg__flinalg", &PyInit__flinalg);
    PyImport_AppendInittab("__scipy_linalg__interpolative", &PyInit__interpolative);
    PyImport_AppendInittab("__scipy_linalg__solve_toeplitz", &PyInit__solve_toeplitz);
    PyImport_AppendInittab("__scipy_linalg_cython_blas", &PyInit_cython_blas);
    PyImport_AppendInittab("__scipy_linalg_cython_lapack", &PyInit_cython_lapack);
    
    PyImport_AppendInittab("__scipy_ndimage__nd_image", &PyInit__nd_image);
    PyImport_AppendInittab("__scipy_ndimage__ni_label", &PyInit__ni_label);
    PyImport_AppendInittab("__scipy_odr___odrpack", &PyInit___odrpack);
    
    PyImport_AppendInittab("__scipy_optimize__cobyla", &PyInit__cobyla);
    PyImport_AppendInittab("__scipy_optimize__group_columns", &PyInit__group_columns);
    PyImport_AppendInittab("__scipy_optimize__lbfgsb", &PyInit__lbfgsb);
    PyImport_AppendInittab("__scipy_optimize__minpack", &PyInit__minpack);
    PyImport_AppendInittab("__scipy_optimize__nnls", &PyInit__nnls);
    PyImport_AppendInittab("__scipy_optimize__slsqp", &PyInit__slsqp);
    PyImport_AppendInittab("__scipy_optimize__zeros", &PyInit__zeros);
    PyImport_AppendInittab("__scipy_optimize_minpack2", &PyInit_minpack2);
    PyImport_AppendInittab("__scipy_optimize_moduleTNC", &PyInit_moduleTNC);
    PyImport_AppendInittab("__scipy_optimize__lsq_givens_elimination", &PyInit_givens_elimination);
    PyImport_AppendInittab("__scipy_optimize__trlib__trlib", &PyInit__trlib);
    
    PyImport_AppendInittab("__scipy_signal__max_len_seq_inner", &PyInit__max_len_seq_inner);
    PyImport_AppendInittab("__scipy_signal__peak_finding_utils", &PyInit__peak_finding_utils);
    PyImport_AppendInittab("__scipy_signal__spectral", &PyInit__spectral);
    PyImport_AppendInittab("__scipy_signal__upfirdn_apply",  &PyInit__upfirdn_apply);
    PyImport_AppendInittab("__scipy_signal_sigtools", &PyInit_sigtools);
    PyImport_AppendInittab("__scipy_signal_spline", &PyInit_spline);
    
    PyImport_AppendInittab("__scipy_sparse_csgraph__min_spanning_tree", &PyInit__min_spanning_tree);
    PyImport_AppendInittab("__scipy_sparse_csgraph__reordering", &PyInit__reordering);
    PyImport_AppendInittab("__scipy_sparse_csgraph__shortest_path", &PyInit__shortest_path);
    PyImport_AppendInittab("__scipy_sparse_csgraph__tools", &PyInit__tools);
    PyImport_AppendInittab("__scipy_sparse_csgraph__traversal", &PyInit__traversal);
    PyImport_AppendInittab("__scipy_sparse_linalg_dsolve__superlu", &PyInit__superlu);
    PyImport_AppendInittab("__scipy_sparse_linalg_eigen_arpack__arpack", &PyInit__arpack);
    PyImport_AppendInittab("__scipy_sparse_linalg_isolve__iterative", &PyInit__iterative);
    PyImport_AppendInittab("__scipy_sparse__csparsetools", &PyInit__csparsetools);
    PyImport_AppendInittab("__scipy_sparse__sparsetools", &PyInit__sparsetools);
    
    PyImport_AppendInittab("__scipy_spatial__distance_wrap", &PyInit__distance_wrap);
    PyImport_AppendInittab("__scipy_spatial__hausdorff", &PyInit__hausdorff);
    PyImport_AppendInittab("__scipy_spatial__voronoi", &PyInit__voronoi);
    PyImport_AppendInittab("__scipy_spatial_ckdtree", &PyInit_ckdtree);
    PyImport_AppendInittab("__scipy_spatial_qhull", &PyInit_qhull);
    
    PyImport_AppendInittab("__scipy_special__comb", &PyInit__comb);
    PyImport_AppendInittab("__scipy_special__ellip_harm_2", &PyInit__ellip_harm_2);
    PyImport_AppendInittab("__scipy_special__ufuncs_cxx", &PyInit__ufuncs_cxx);
    PyImport_AppendInittab("__scipy_special__ufuncs", &PyInit__ufuncs);
    PyImport_AppendInittab("__scipy_special_cython_special", &PyInit_cython_special);
    PyImport_AppendInittab("__scipy_special_specfun", &PyInit_specfun);
    
    PyImport_AppendInittab("__scipy_stats__stats", &PyInit__stats);
    PyImport_AppendInittab("__scipy_stats_mvn", &PyInit_mvn);
    PyImport_AppendInittab("__scipy_stats_statlib", &PyInit_statlib);
}

#endif

// MARK: - SKLearn

void init_sklearn() {
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    
    [name addObject:@"_ball_tree"];                 [key addObject:@"__sklearn_neighbors__ball_tree"];
    [name addObject:@"_barnes_hut_tsne"];           [key addObject:@"__sklearn_manifold__barnes_hut_tsne"];
    [name addObject:@"_binning"];                   [key addObject:@"__sklearn_ensemble__hist_gradient_boosting__binning"];
    [name addObject:@"_cd_fast"];                   [key addObject:@"__sklearn_linear_model__cd_fast"];
    [name addObject:@"_cdnmf_fast"];                [key addObject:@"__sklearn_decomposition__cdnmf_fast"];
    [name addObject:@"_check_build"];               [key addObject:@"__sklearn___check_build__check_build"];
    [name addObject:@"_criterion"];                 [key addObject:@"__sklearn_tree__criterion"];
    [name addObject:@"_csr_polynomial_expansion"];  [key addObject:@"__sklearn_preprocessing__csr_polynomial_expansion"];
    [name addObject:@"_cython_blas"];               [key addObject:@"__sklearn_utils__cython_blas"];
    [name addObject:@"_dbscan_inner"];              [key addObject:@"__sklearn_cluster__dbscan_inner"];
    [name addObject:@"_dist_metrics"];              [key addObject:@"__sklearn_neighbors__dist_metrics"];
    [name addObject:@"_expected_mutual_info_fast"]; [key addObject:@"__sklearn_metrics_cluster__expected_mutual_info_fast"];
    [name addObject:@"_fast_dict"];                 [key addObject:@"__sklearn_utils__fast_dict"];
    [name addObject:@"_hist_gradient_boosting"];    [key addObject:@"__sklearn_ensemble__hist_gradient_boosting__gradient_boosting"];
    [name addObject:@"_gradient_boosting"];         [key addObject:@"__sklearn_ensemble__gradient_boosting"];
    [name addObject:@"_hashing_fast"];              [key addObject:@"__sklearn_feature_extraction__hashing_fast"];
    [name addObject:@"_hierarchical_fast"];         [key addObject:@"__sklearn_cluster__hierarchical_fast"];
    [name addObject:@"_isotonic"];                  [key addObject:@"__sklearn__isotonic"];
    [name addObject:@"_k_means_elkan"];             [key addObject:@"__sklearn_cluster__k_means_elkan"];
    [name addObject:@"_k_means_fast"];              [key addObject:@"__sklearn_cluster__k_means_fast"];
    [name addObject:@"_kd_tree"];                   [key addObject:@"__sklearn_neighbors__kd_tree"];
    [name addObject:@"_liblinear"];                 [key addObject:@"__sklearn_svm__liblinear"];
    [name addObject:@"_libsvm_sparse"];             [key addObject:@"__sklearn_svm__libsvm_sparse"];
    [name addObject:@"_libsvm"];                    [key addObject:@"__sklearn_svm__libsvm"];
    [name addObject:@"_logistic_sigmoid"];          [key addObject:@"__sklearn_utils__logistic_sigmoid"];
    [name addObject:@"_loss"];                      [key addObject:@"__sklearn_ensemble__hist_gradient_boosting__loss"];
    [name addObject:@"_online_lda_fast"];           [key addObject:@"__sklearn_decomposition__online_lda_fast"];
    [name addObject:@"_openmp_helpers"];            [key addObject:@"__sklearn_utils__openmp_helpers"];
    [name addObject:@"_pairwise_fast"];             [key addObject:@"__sklearn_metrics__pairwise_fast"];
    [name addObject:@"_predictor"];                 [key addObject:@"__sklearn_ensemble__hist_gradient_boosting__predictor"];
    [name addObject:@"_quad_tree"];                 [key addObject:@"__sklearn_neighbors__quad_tree"];
    [name addObject:@"_random"];                    [key addObject:@"__sklearn_utils__random"];
    [name addObject:@"_sag_fast"];                  [key addObject:@"__sklearn_linear_model__sag_fast"];
    [name addObject:@"_seq_dataset"];               [key addObject:@"__sklearn_utils__seq_dataset"];
    [name addObject:@"_sgd_fast"];                  [key addObject:@"__sklearn_linear_model__sgd_fast"];
    [name addObject:@"_splitter"];                  [key addObject:@"__sklearn_tree__splitter"];
    [name addObject:@"_svmlight_format_fast"];      [key addObject:@"__sklearn_datasets__svmlight_format_fast"];
    [name addObject:@"_tree"];                      [key addObject:@"__sklearn_tree__tree"];
    [name addObject:@"_typedefs"];                  [key addObject:@"__sklearn_neighbors__typedefs"];
    [name addObject:@"tree_utils"];                 [key addObject:@"__sklearn_tree__utils"];
    [name addObject:@"manifold_utils"];             [key addObject:@"__sklearn_manifold__utils"];
    [name addObject:@"_weight_vector"];             [key addObject:@"__sklearn_utils__weight_vector"];
    [name addObject:@"arrayfuncs"];                 [key addObject:@"__sklearn_utils_arrayfuncs"];
    [name addObject:@"common"];                     [key addObject:@"__sklearn_ensemble__hist_gradient_boosting_common"];
    [name addObject:@"graph_shortest_path"];        [key addObject:@"__sklearn_utils_graph_shortest_path"];
    [name addObject:@"histogram"];                  [key addObject:@"__sklearn_ensemble__hist_gradient_boosting_histogram"];
    [name addObject:@"murmurhash"];                 [key addObject:@"__sklearn_utils_murmurhash"];
    [name addObject:@"sparsefuncs_fast"];           [key addObject:@"__sklearn_utils_sparsefuncs_fast"];
    [name addObject:@"splitting"];                  [key addObject:@"__sklearn_ensemble__hist_gradient_boosting_splitting"];
    [name addObject:@"utils"];                      [key addObject:@"__sklearn_ensemble__hist_gradient_boosting_utils"];
    
    BandHandle(@"sklearn", name, key);
}

// MARK: - SKImage

void init_skimage() {
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    
    [name addObject:@"_ctmf"];                      [key addObject:@"__skimage_filters__ctmf"];
    [name addObject:@"bilateral_cy"];               [key addObject:@"__skimage_filters_rank_bilateral_cy"];
    [name addObject:@"generic_cy"];                 [key addObject:@"__skimage_filters_rank_generic_cy"];
    [name addObject:@"percentile_cy"];              [key addObject:@"__skimage_filters_rank_percentile_cy"];
    [name addObject:@"core_cy"];                    [key addObject:@"__skimage_filters_rank_core_cy"];
    [name addObject:@"_denoise_cy"];                [key addObject:@"__skimage_restoration__denoise_cy"];
    [name addObject:@"_unwrap_1d"];                 [key addObject:@"__skimage_restoration__unwrap_1d"];
    [name addObject:@"_unwrap_2d"];                 [key addObject:@"__skimage_restoration__unwrap_2d"];
    [name addObject:@"_nl_means_denoising"];        [key addObject:@"__skimage_restoration__nl_means_denoising"];
    [name addObject:@"_unwrap_3d"];                 [key addObject:@"__skimage_restoration__unwrap_3d"];
    [name addObject:@"_felzenszwalb_cy"];           [key addObject:@"__skimage_segmentation__felzenszwalb_cy"];
    [name addObject:@"_slic"];                      [key addObject:@"__skimage_segmentation__slic"];
    [name addObject:@"_quickshift_cy"];             [key addObject:@"__skimage_segmentation__quickshift_cy"];
    [name addObject:@"_colormixer"];                [key addObject:@"__skimage_io__plugins__colormixer"];
    [name addObject:@"_histograms"];                [key addObject:@"__skimage_io__plugins__histograms"];
    [name addObject:@"_mcp"];                       [key addObject:@"__skimage_graph__mcp"];
    [name addObject:@"_spath"];                     [key addObject:@"__skimage_graph__spath"];
    [name addObject:@"heap"];                       [key addObject:@"__skimage_graph_heap"];
    [name addObject:@"_ccomp"];                     [key addObject:@"__skimage_measure__ccomp"];
    [name addObject:@"_pnpoly"];                    [key addObject:@"__skimage_measure__pnpoly"];
    [name addObject:@"_marching_cubes_classic_cy"]; [key addObject:@"__skimage_measure__marching_cubes_classic_cy"];
    [name addObject:@"_marching_cubes_lewiner_cy"]; [key addObject:@"__skimage_measure__marching_cubes_lewiner_cy"];
    [name addObject:@"_find_contours_cy"];          [key addObject:@"__skimage_measure__find_contours_cy"];
    [name addObject:@"_moments_cy"];                [key addObject:@"__skimage_measure__moments_cy"];
    [name addObject:@"transform"];                  [key addObject:@"__skimage__shared_transform"];
    [name addObject:@"interpolation"];              [key addObject:@"__skimage__shared_interpolation"];
    [name addObject:@"geometry"];                   [key addObject:@"__skimage__shared_geometry"];
    [name addObject:@"_extrema_cy"];                [key addObject:@"__skimage_morphology__extrema_cy"];
    [name addObject:@"_skeletonize_3d_cy"];         [key addObject:@"__skimage_morphology__skeletonize_3d_cy"];
    [name addObject:@"_convex_hull"];               [key addObject:@"__skimage_morphology__convex_hull"];
    [name addObject:@"_greyreconstruct"];           [key addObject:@"__skimage_morphology__greyreconstruct"];
    [name addObject:@"_skeletonize_cy"];            [key addObject:@"__skimage_morphology__skeletonize_cy"];
    [name addObject:@"_watershed"];                 [key addObject:@"__skimage_morphology__watershed"];
    [name addObject:@"_texture"];                   [key addObject:@"__skimage_feature__texture"];
    [name addObject:@"orb_cy"];                     [key addObject:@"__skimage_feature_orb_cy"];
    [name addObject:@"_hoghistogram"];              [key addObject:@"__skimage_feature__hoghistogram"];
    [name addObject:@"brief_cy"];                   [key addObject:@"__skimage_feature_brief_cy"];
    [name addObject:@"censure_cy"];                 [key addObject:@"__skimage_feature_censure_cy"];
    [name addObject:@"_haar"];                      [key addObject:@"__skimage_feature__haar"];
    [name addObject:@"_hessian_det_appx"];          [key addObject:@"__skimage_feature__hessian_det_appx"];
    [name addObject:@"corner_cy"];                  [key addObject:@"__skimage_feature_corner_cy"];
    [name addObject:@"tifffile._tifffile"];         [key addObject:@"__skimage_external_tifffile__tifffile"];
    [name addObject:@"_warps_cy"];                  [key addObject:@"__skimage_transform__warps_cy"];
    [name addObject:@"_hough_transform"];           [key addObject:@"__skimage_transform__hough_transform"];
    [name addObject:@"_radon_transform"];           [key addObject:@"__skimage_transform__radon_transform"];
    [name addObject:@"_seam_carving"];              [key addObject:@"__skimage_transform__seam_carving"];
    [name addObject:@"_draw"];                      [key addObject:@"__skimage_draw__draw"];
    [name addObject:@"_ncut_cy"];                   [key addObject:@"__skimage_future_graph__ncut_cy"];
    [name addObject:@"_multiotsu"];                 [key addObject:@"__skimage_filters__multiotsu"];
    [name addObject:@"_flood_fill_cy"];             [key addObject:@"__skimage_morphology__flood_fill_cy"];
    [name addObject:@"_max_tree"];                  [key addObject:@"__skimage_morphology__max_tree"];
    [name addObject:@"_cascade"];                   [key addObject:@"__skimage_feature__cascade"];
    
    BandHandle(@"skimage", name, key);
}

#endif

// MARK: - PIL

void init_pil() {

    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_imaging"];           [key addObject:@"__PIL__imaging"];
    #if !WIDGET
    [name addObject:@"_imagingft"];         [key addObject:@"__PIL__imagingft"];
    [name addObject:@"_imagingmath"];       [key addObject:@"__PIL__imagingmath"];
    [name addObject:@"_imagingmorph"];      [key addObject:@"__PIL__imagingmorph"];
    #endif
    BandHandle(@"PIL", name, key);
}

// MARK: - Numpy

void init_numpy() {
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_bit_generator"];      [key addObject:@"__numpy_random__bit_generator"];
    [name addObject:@"_bounded_integers"];   [key addObject:@"__numpy_random__bounded_integers"];
    [name addObject:@"_common"];             [key addObject:@"__numpy_random__common"];
    [name addObject:@"_generator"];          [key addObject:@"__numpy_random__generator"];
    [name addObject:@"_mt19937"];            [key addObject:@"__numpy_random__mt19937"];
    [name addObject:@"_multiarray_tests"];   [key addObject:@"__numpy_core__multiarray_tests"];
    [name addObject:@"_operand_flag_tests"]; [key addObject:@"__numpy_core__operand_flag_tests"];
    [name addObject:@"_pcg64"];              [key addObject:@"__numpy_random__pcg64"];
    [name addObject:@"_philox"];             [key addObject:@"__numpy_random__philox"];
    [name addObject:@"_pocketfft_internal"]; [key addObject:@"__numpy_fft__pocketfft_internal"];
    [name addObject:@"_rational_tests"];     [key addObject:@"__numpy_core__rational_tests"];
    [name addObject:@"_sfc64"];              [key addObject:@"__numpy_random__sfc64"];
    [name addObject:@"_struct_ufunc_tests"]; [key addObject:@"__numpy_core__struct_ufunc_tests"];
    [name addObject:@"_umath_linalg"];       [key addObject:@"__numpy_linalg__umath_linalg"];
    [name addObject:@"_umath_tests"];        [key addObject:@"__numpy_core__umath_tests"];
    [name addObject:@"lapack_lite"];         [key addObject:@"__numpy_linalg_lapack_lite"];
    [name addObject:@"mtrand"];              [key addObject:@"__numpy_random_mtrand"];
    [name addObject:@"_multiarray_umath"];   [key addObject:@"__numpy_core__multiarray_umath"];
    BandHandle(@"numpy", name, key);
}

// MARK: - CFFI

#if MAIN

void init_cffi() {

    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_cffi_backend"]; [key addObject:@"_cffi_backend"];
    BandHandle(@"_cffi_backend", name, key);
    
    [Python.shared.modules addObject: @"_cffi_backend"];
}

// MARK: - Bcrypt

void init_bcrypt() {

    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_bcrypt"]; [key addObject:@"__bcrypt__bcrypt"];
    BandHandle(@"bcrypt", name, key);
}

// MARK: - Pywt

void init_pywt() {
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_cwt"]; [key addObject:@"__pywt__extensions__cwt"];
    [name addObject:@"_pywt"]; [key addObject:@"__pywt__extensions__pywt"];
    [name addObject:@"_swt"]; [key addObject:@"__pywt__extensions__swt"];
    [name addObject:@"_dwt"]; [key addObject:@"__pywt__extensions__dwt"];
    BandHandle(@"pywt", name, key);
}

// MARK: - Statsmodels

void init_statsmodels() {
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_alternative"];                   [key addObject:@"__statsmodels_tsa_statespace__smoothers__alternative"];
    [name addObject:@"_arma_innovations"];              [key addObject:@"__statsmodels_tsa_innovations__arma_innovations"];
    [name addObject:@"_classical"];                     [key addObject:@"__statsmodels_tsa_statespace__smoothers__classical"];
    [name addObject:@"_exponential_smoothers"];         [key addObject:@"__statsmodels_tsa__exponential_smoothers"];
    [name addObject:@"filters__conventional"];          [key addObject:@"__statsmodels_tsa_statespace__filters__conventional"];
    [name addObject:@"filters__univariate_diffuse"];    [key addObject:@"__statsmodels_tsa_statespace__filters__univariate_diffuse"];
    [name addObject:@"filters__univariate"];            [key addObject:@"__statsmodels_tsa_statespace__filters__univariate"];
    [name addObject:@"_hamilton_filter"];               [key addObject:@"__statsmodels_tsa_regime_switching__hamilton_filter"];
    [name addObject:@"_initialization"];                [key addObject:@"__statsmodels_tsa_statespace__initialization"];
    [name addObject:@"_innovations"];                   [key addObject:@"__statsmodels_tsa__innovations"];
    [name addObject:@"_inversions"];                    [key addObject:@"__statsmodels_tsa_statespace__filters__inversions"];
    [name addObject:@"_kalman_filter"];                 [key addObject:@"__statsmodels_tsa_statespace__kalman_filter"];
    [name addObject:@"_kalman_smoother"];               [key addObject:@"__statsmodels_tsa_statespace__kalman_smoother"];
    [name addObject:@"_kim_smoother"];                  [key addObject:@"__statsmodels_tsa_regime_switching__kim_smoother"];
    [name addObject:@"_representation"];                [key addObject:@"__statsmodels_tsa_statespace__representation"];
    [name addObject:@"_simulation_smoother"];           [key addObject:@"__statsmodels_tsa_statespace__simulation_smoother"];
    [name addObject:@"smoothers__conventional"];        [key addObject:@"__statsmodels_tsa_statespace__smoothers__conventional"];
    [name addObject:@"smoothers__univariate_diffuse"];  [key addObject:@"__statsmodels_tsa_statespace__smoothers__univariate_diffuse"];
    [name addObject:@"smoothers__univariate"];          [key addObject:@"__statsmodels_tsa_statespace__smoothers__univariate"];
    [name addObject:@"_smoothers_lowess"];              [key addObject:@"__statsmodels_nonparametric__smoothers_lowess"];
    [name addObject:@"_stl"];                           [key addObject:@"__statsmodels_tsa__stl"];
    [name addObject:@"_tools"];                         [key addObject:@"__statsmodels_tsa_statespace__tools"];
    [name addObject:@"kalman_loglike"];                 [key addObject:@"__statsmodels_tsa_kalmanf_kalman_loglike"];
    [name addObject:@"linbin"];                         [key addObject:@"__statsmodels_nonparametric_linbin"];
    BandHandle(@"statsmodels", name, key);
}

// MARK: - Zmq

BOOL initialized_zmq = NO;

void init_zmq() {
    
    if (!initialized_zmq) {
        initialized_zmq = YES;
        dlopen([NSBundle.mainBundle.privateFrameworksURL URLByAppendingPathComponent:@"Zmq.framework/Zmq"].path.UTF8String, RTLD_GLOBAL);        
    }
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_device"];          [key addObject:@"__zmq_backend_cython__device"];
    [name addObject:@"_poll"];            [key addObject:@"__zmq_backend_cython__poll"];
    [name addObject:@"_proxy_steerable"]; [key addObject:@"__zmq_backend_cython__proxy_steerable"];
    [name addObject:@"_version"];         [key addObject:@"__zmq_backend_cython__version"];
    [name addObject:@"constants"];        [key addObject:@"__zmq_backend_cython_constants"];
    [name addObject:@"context"];          [key addObject:@"__zmq_backend_cython_context"];
    [name addObject:@"error"];            [key addObject:@"__zmq_backend_cython_error"];
    [name addObject:@"message"];          [key addObject:@"__zmq_backend_cython_message"];
    [name addObject:@"monitoredqueue"];   [key addObject:@"__zmq_devices_monitoredqueue"];
    [name addObject:@"socket"];           [key addObject:@"__zmq_backend_cython_socket"];
    [name addObject:@"zmq_utils"];        [key addObject:@"__zmq_backend_cython_utils"];
    BandHandle(@"zmq", name, key);
}

// MARK: - Gensim

void init_gensim() {
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_matutils"];           [key addObject:@"__gensim__matutils"];
    [name addObject:@"_mmreader"];           [key addObject:@"__gensim_corpora__mmreader"];
    [name addObject:@"_utils_any2vec"];      [key addObject:@"__gensim_models__utils_any2vec"];
    [name addObject:@"doc2vec_corpusfile"];  [key addObject:@"__gensim_models_doc2vec_corpusfile"];
    [name addObject:@"doc2vec_inner"];       [key addObject:@"__gensim_models_doc2vec_inner"];
    [name addObject:@"fasttext_corpusfile"]; [key addObject:@"__gensim_models_fasttext_corpusfile"];
    [name addObject:@"fasttext_inner"];      [key addObject:@"__gensim_models_fasttext_inner"];
    [name addObject:@"nmf_pgd"];             [key addObject:@"__gensim_models_nmf_pgd"];
    [name addObject:@"word2vec_corpusfile"]; [key addObject:@"__gensim_models_word2vec_corpusfile"];
    [name addObject:@"word2vec_inner"];      [key addObject:@"__gensim_models_word2vec_inner"];
    BandHandle(@"gensim", name, key);
}


// MARK: - Regex

void init_regex() {
    
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_regex"]; [key addObject:@"__regex__regex"];
    BandHandle(@"regex", name, key);
}

// MARK: - Astropy

void init_astropy() {
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"_column_mixins"]; [key addObject:@"__astropy_table__column_mixins"];
    [name addObject:@"_compiler"]; [key addObject:@"__astropy_utils__compiler"];
    [name addObject:@"_convolve"]; [key addObject:@"__astropy_convolution__convolve"];
    [name addObject:@"_impl"]; [key addObject:@"__astropy_timeseries_periodograms_bls__impl"];
    [name addObject:@"_iterparser"]; [key addObject:@"__astropy_utils_xml__iterparser"];
    [name addObject:@"_np_utils"]; [key addObject:@"__astropy_table__np_utils"];
    [name addObject:@"_projections"]; [key addObject:@"__astropy_modeling__projections"];
    [name addObject:@"_stats"]; [key addObject:@"__astropy_stats__stats"];
    [name addObject:@"_wcs"]; [key addObject:@"__astropy_wcs__wcs"];
    [name addObject:@"compiler_version"]; [key addObject:@"__astropy_compiler_version"];
    [name addObject:@"cparser"]; [key addObject:@"__astropy_io_ascii_cparser"];
    [name addObject:@"cython_impl"]; [key addObject:@"__astropy_timeseries_periodograms_lombscargle_implementations_cython_impl"];
    [name addObject:@"fits__utils"]; [key addObject:@"__astropy_io_fits__utils"];
    [name addObject:@"scalar_inv_efuncs"]; [key addObject:@"__astropy_cosmology_scalar_inv_efuncs"];
    [name addObject:@"tablewriter"]; [key addObject:@"__astropy_io_votable_tablewriter"];
    [name addObject:@"ufunc"]; [key addObject:@"__astropy__erfa_ufunc"];
    [name addObject:@"compression"]; [key addObject:@"__astropy_io_fits_compression"];
    BandHandle(@"astropy", name, key);
}

// MARK: - Emd

void init_emd() {
    NSMutableArray *name = [NSMutableArray array]; NSMutableArray *key = [NSMutableArray array];
    [name addObject:@"emd"]; [key addObject:@"__pyemd_emd"];
    BandHandle(@"emd", name, key);
}

#endif

#endif

// MARK: - OpenCV

#if !(TARGET_IPHONE_SIMULATOR) && MAIN

extern PyMODINIT_FUNC PyInit_cv2(void);

void init_cv2() {
    PyImport_AppendInittab("__cv2_cv2", &PyInit_cv2);
}

// MARK: - Nacl

extern PyMODINIT_FUNC PyInit__sodium(void);

void init_nacl() {
    PyImport_AppendInittab("__nacl__sodium", &PyInit__sodium);
    [Python.shared.modules addObject: @"__nacl__sodium"];
}

#endif

>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
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
    
    // Astropy caches
    NSString *caches = [NSFileManager.defaultManager URLsForDirectory:NSCachesDirectory inDomains:NSAllDomainsMask].firstObject.path;
    NSString *astropyCaches = [caches stringByAppendingPathComponent:@"astropy"];
    if ([NSFileManager.defaultManager fileExistsAtPath:astropyCaches]) {
        [NSFileManager.defaultManager removeItemAtPath:astropyCaches error:NULL];
    }
    [NSFileManager.defaultManager createDirectoryAtPath:astropyCaches withIntermediateDirectories:YES attributes:NULL error:NULL];
    putenv((char *)[NSString stringWithFormat:@"XDG_CACHE_HOME=%@", caches].UTF8String);
    
    // SKLearn data
    putenv((char *)[NSString stringWithFormat:@"SCIKIT_LEARN_DATA=%@", [NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSAllDomainsMask].firstObject.path].UTF8String);
    
    #if MAIN
    dispatch_async(dispatch_queue_create(NULL, NULL), ^{
    #endif
        // MARK: - Init Python
<<<<<<< HEAD
        
        #if MAIN
        PyImport_AppendInittab("_extensionsimporter", &PyInit__extensionsimporter);
        
        dlopen([NSBundle.mainBundle.privateFrameworksURL URLByAppendingPathComponent:@"Zmq.framework/Zmq"].path.UTF8String, RTLD_GLOBAL);
        
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
        
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
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
        
<<<<<<< HEAD
=======
        // Now the app initializes modules when they are imported
        // That makes the app startup a lot faster
        // It's not recommended by the Python docs to add builtin modules after PyInitialize
        // But it works after adding mod names to builtin mod names manually
        #if !SCREENSHOTS
        init_pil();
        #if MAIN
        init_numpy();
        init_cffi();
        #endif
        #endif
        
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
        // MARK: - Start the REPL that will contain all child modules
        #if !WIDGET
        [Python.shared runScriptAt:[[NSBundle mainBundle] URLForResource:@"scripts_runner" withExtension:@"py"]];
        #endif
    #if MAIN
    });
    #endif
    
    #if MAIN
<<<<<<< HEAD
=======
    
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
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

