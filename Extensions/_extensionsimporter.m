//
//  _extensionsimporter.c
//  Pyto
//
//  Created by Emma Labbé on 17-11-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

#include <Python.h>
#include <dlfcn.h>
#import <Foundation/Foundation.h>

#define SET_FILE() PyObject_SetAttrString(module, "__file__", PyUnicode_FromString(binaryURL.path.UTF8String));

static char _extensionsimporter_module_docstring[] =
    "Import frameworks.";
static char _extensionsimporter_module_from_binary_docstring[] =
    "Returns a module from the name of a framework. E.g: PIL._imaging";

static PyObject *_extensionsimporter_module_from_binary(PyObject *self, PyObject *args) {
    const char *name;
    PyObject *spec;
    if(!PyArg_ParseTuple(args, "sO", &name, &spec)) {
        return NULL;
    }
    
    NSURL *frameworksURL = NSBundle.mainBundle.privateFrameworksURL;
    #if WIDGET
    frameworksURL = [frameworksURL.URLByDeletingLastPathComponent.URLByDeletingLastPathComponent.URLByDeletingLastPathComponent URLByAppendingPathComponent:@"Frameworks"];
    #endif
    
    NSString *dependenciesName = [[[NSString stringWithUTF8String:name] componentsSeparatedByString:@"."].firstObject stringByAppendingString:@"-deps.framework"];
    NSMutableString *dependenciesFrameworkPath = [NSMutableString stringWithString:[NSBundle.mainBundle privateFrameworksURL].path];
    [dependenciesFrameworkPath appendString:@"/"];
    [dependenciesFrameworkPath appendString:dependenciesName];
    
    if ([NSFileManager.defaultManager fileExistsAtPath:dependenciesFrameworkPath]) {
        [[NSBundle bundleWithPath:dependenciesFrameworkPath] load];
    }
    
    NSMutableString *frameworkName = [NSMutableString stringWithString:[[NSString stringWithUTF8String:name] stringByReplacingOccurrencesOfString:@"." withString:@"-"]];
    [frameworkName appendString:@".framework"];
    
    NSMutableString *frameworkPath = [NSMutableString stringWithString:frameworksURL.path];
    [frameworkPath appendString:@"/"];
    [frameworkPath appendString:frameworkName];
    
    if (![NSFileManager.defaultManager fileExistsAtPath:frameworkPath]) {
        NSString *libraryName = [[[NSString stringWithUTF8String:name] componentsSeparatedByString:@"."].firstObject stringByAppendingString:@"-.framework"];
        
        frameworkPath = [NSMutableString stringWithString:frameworksURL.path];
        [frameworkPath appendString:libraryName];
    }
    
    NSArray *content = [NSFileManager.defaultManager contentsOfDirectoryAtURL:[NSURL fileURLWithPath:frameworkPath] includingPropertiesForKeys:NULL options:0 error:NULL];
    
    NSURL *binaryURL;
    
    if (content) {
        for (NSURL *url in content) {
            printf("URL: %s\n", url.path.UTF8String);
            if ([url.pathExtension isEqual:@"so"] || [url.lastPathComponent isEqual:frameworkPath.stringByDeletingPathExtension.lastPathComponent]) {
                binaryURL = url;
                break;
            }
        }
    }
    
    if (!binaryURL) {
        printf("%s\n", binaryURL.path.UTF8String);
        PyErr_SetString(PyExc_FileNotFoundError, [@"Binary not found inside " stringByAppendingString:frameworkPath].UTF8String);
        return NULL;
    }
        
    NSMutableString *init_function = [NSMutableString stringWithString:@"PyInit_"];
    NSString *last_name = [[NSString stringWithUTF8String:name] componentsSeparatedByString:@"."].lastObject;
    [init_function appendString:[last_name stringByReplacingOccurrencesOfString:@"." withString:@"_"]];
        
    void *handle = dlopen(binaryURL.path.UTF8String, RTLD_GLOBAL);
    
    const char *error;
    error = dlerror();
    if (error) {
        PyErr_SetString(PyExc_SystemError, error);
        return NULL;
    }
    
    PyObject* (*func)(void) = dlsym(handle, init_function.UTF8String);
    
    error = dlerror();
    if (error) {
        PyErr_SetString(PyExc_SystemError, error);
        return NULL;
    }
    
    PyObject* module = func();
    
    if (PyObject_TypeCheck(module, &PyModuleDef_Type)) {
        PyModuleDef *def = (PyModuleDef*)module;
        module = PyModule_FromDefAndSpec(def, spec);
        SET_FILE();
        PyModule_ExecDef(module, def);
    } else {
        SET_FILE();
    }
    
    printf("%s\n", name);
    return module;
}

static PyMethodDef _extensionsimporter_methods[] = {
    {"module_from_binary", _extensionsimporter_module_from_binary, METH_VARARGS, _extensionsimporter_module_from_binary_docstring},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _extensionsimporter = {
    PyModuleDef_HEAD_INIT,
    "_extensionsimporter",   /* name of module */
    _extensionsimporter_module_docstring, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    _extensionsimporter_methods,
};

PyMODINIT_FUNC PyInit__extensionsimporter(void)
{
    return PyModule_Create(&_extensionsimporter);
}
