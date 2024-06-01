//
//  _extensionsimporter.c
//  Pyto
//
//  Created by Emma Labbé on 17-11-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

#include "_extensionsimporter.h"
#import "Pyto-Swift.h"

static char _extensionsimporter_module_docstring[] =
    "Import frameworks and LLVM bitcode.";

void *lli_msgSend(id self, SEL msg, int argc, va_list parameters) {
    
    NSLog(@"Will invoke %@", NSStringFromSelector(msg));
    SEL sel = NSSelectorFromString(NSStringFromSelector(msg));
    
    NSMethodSignature *signature = [self methodSignatureForSelector:sel];
        
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
    [invocation setTarget:self]; // 0
    [invocation setSelector:sel]; // 1
    
    int i;
    for (i = 2; i < argc+2; i += 1) { // 2
        void *arg = va_arg(parameters, void *);
        [invocation setArgument:&arg atIndex:i];
    }
    
    [invocation invoke];
        
    const char *returnType = [invocation.methodSignature methodReturnType];
    
    if (strcmp(returnType, "v") == 0) {
        return NULL;
    } else if (strcmp(returnType, "@") && strcmp(returnType, "#")) {
        // Not an object
        
        void *value;
        [invocation getReturnValue:&value];
        return value;
    } else {
        // An object
        
        id object;
        [invocation getReturnValue:&object];
        return (void *)CFBridgingRetain(object);
    }
}

FILE *makeInputFile(NSString *string) {
    NSURL *url = [[NSURL fileURLWithPath:NSTemporaryDirectory()] URLByAppendingPathComponent:[NSUUID UUID].UUIDString];
    [string writeToURL:url atomically:NO encoding:NSUTF8StringEncoding error:NULL];
    return fopen(url.path.UTF8String, "r");
}

NSMutableArray<NSPipe *> *inputCache;

// MARK: - module_from_bitcode

static char _extensionsimporter_module_from_bitcode_docstring[] =
    "Returns a module from the path of an LLVM bitcode file.";

static PyObject *last_llvm_module;

static PyObject *llvm_importing_module_spec;

static PyCFunction llvm_calling_function;
static const char *llvm_calling_function_name;
static const char *llvm_calling_getter_setter_name;
static PyObject *llvm_calling_setter_value;
static PyObject *llvm_calling_function_self;
static PyObject *llvm_calling_function_cls;
static PyObject *llvm_calling_function_args;
static PyObject *llvm_calling_function_kwargs;
static PyObject *llvm_calling_function_all_args;
static PyObject *llvm_calling_function_first_arg;
static PyObject *llvm_calling_function_kwnames;
static PyObject *llvm_calling_function_exc_type;
static PyObject *llvm_calling_function_exc_value;
static int llvm_calling_function_flags;
static PyObject* llvm_calling_cython_function;
static PyObject *llvm_calling_function_retvalue;
static PyObject *llvm_deleting_module;

static size_t llvm_free_size = 0;
static PyObject **llvm_free_objects_list;

PyObject **llvm_get_free_objects_list(void) {
    return llvm_free_objects_list;
}

size_t llvm_get_free_size(void) {
    return llvm_free_size;
}

static dispatch_semaphore_t lli_semaphore;

PyObject *llvm_importing_module_get_spec(void) {
    return llvm_importing_module_spec;
}

const char *llvm_calling_function_get_name(void) {
    return llvm_calling_function_name;
}

const char *llvm_calling_getter_setter_get_name(void) {
    return llvm_calling_getter_setter_name;
}

PyObject *llvm_calling_setter_get_value(void) {
    return llvm_calling_setter_value;
}

PyObject *llvm_calling_function_get_cls(void) {
    return llvm_calling_function_cls;
}

PyObject *llvm_calling_function_get_self(void) {
    return llvm_calling_function_self;
}

PyObject *llvm_calling_function_get_args(void) {
    return llvm_calling_function_args;
}

PyObject *llvm_calling_function_get_kwargs(void) {
    return llvm_calling_function_kwargs;
}

PyObject *llvm_calling_function_get_all_args(void) {
    return llvm_calling_function_all_args;
}

PyObject *llvm_calling_function_get_first_arg(void) {
    return llvm_calling_function_first_arg;
}

PyObject *llvm_calling_function_get_kwnames(void) {
    return llvm_calling_function_kwnames;
}

int llvm_calling_function_get_flags(void) {
    return llvm_calling_function_flags;
}

PyGILState_STATE llvm_ensure_gil(void) {
    return PyGILState_Ensure();
}

PyObject *llvm_get_cython_function(void) {
    return llvm_calling_cython_function;
}

PyCFunction llvm_get_calling_function(void) {
    return llvm_calling_function;
}

PyObject* llvm_wait_for_calling_function(PyObject *module) {
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    [semaphores setWaiter:dispatch_semaphore_create(0)];
    
    if (lli_semaphore) {
        dispatch_semaphore_signal(lli_semaphore);
        lli_semaphore = NULL;
    }
    
    dispatch_semaphore_wait(semaphores.waiter, DISPATCH_TIME_FOREVER);
    PyObject *mod = llvm_deleting_module;
    return mod;
}

PyObject *llvm_start_waiting(PyObject *module) {
    
    if (llvm_calling_function_retvalue) {
        PyObject *value = llvm_calling_function_retvalue;
        llvm_calling_function_retvalue = NULL;
        return value;
    }
    
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    [semaphores setFunction:dispatch_semaphore_create(0)];
    dispatch_semaphore_wait(semaphores.function, DISPATCH_TIME_FOREVER);
    
    return llvm_calling_function_retvalue;
}

void llvm_stop_waiting(PyObject *module, PyObject *return_value, PyObject *exc_type, PyObject *exc_value) {
    
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    
    llvm_calling_function_retvalue = return_value;
    llvm_calling_function = NULL;
    llvm_calling_function_self = NULL;
    llvm_calling_function_args = NULL;
    llvm_calling_function_exc_type = exc_type;
    llvm_calling_function_exc_value = exc_value;
    dispatch_semaphore_signal(semaphores.function);
}

void llvm_set_bitcode_module(PyObject *module) {
    last_llvm_module = module;
}

void llvm_delete_module(PyObject *module) {
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    pthread_kill((pthread_t)semaphores.moduleThread, SIGSEGV);
}

bool llvm_is_cfunction(PyObject *function) {
    return PyCFunction_Check(function);
}

bool llvm_has_getter(PyObject *cls, const char *name) {
    
    struct PyGetSetDef *getset = ((PyTypeObject *)cls)->tp_getset;
        
    int i = 0;
    for (i = 0; true; i += 1) {
        PyGetSetDef def = getset[i];
        
        if (!def.name) {
            break;
        }
        
        if (strcmp(def.name, name) == 0 && def.get) {
            return true;
        }
    }
    
    return false;
}

bool llvm_has_setter(PyObject *cls, const char *name) {
    
    PyGetSetDef *getset = ((PyTypeObject *)cls)->tp_getset;
    
    if (!getset) {
        return false;
    }
    
    int i = 0;
    for (i = 0; true; i += 1) {
        PyGetSetDef def = getset[i];
        
        if (!def.name) {
            break;
        }
        
        if (strcmp(def.name, name) == 0 && def.set) {
            return true;
        }
    }
    
    return false;
}

bool llvm_has_getattr(PyObject *cls) {
    
    getattrofunc getattr = ((PyTypeObject *)cls)->tp_getattro;
    if (getattr) {
        return true;
    } else {
        return false;
    }
}

bool llvm_has_setattr(PyObject *cls) {
    
    setattrofunc setattr = ((PyTypeObject *)cls)->tp_setattro;
    if (setattr) {
        return true;
    } else {
        return false;
    }
}

PyObject *llvm_dummy_function(PyObject *_self, PyObject *args) {
    return Py_None;
}

PyObject* llvm_create_instance(PyObject *cls, PyObject *module, PyObject *args, PyObject *kwargs, PyObject *first_arg, PyObject *all_args, PyObject *kwnames) {
    
    llvm_calling_function_cls = cls;
    llvm_calling_function_retvalue = NULL;
    llvm_calling_function_exc_value = NULL;
    llvm_calling_function_exc_type = NULL;
    llvm_calling_function_args = args;
    llvm_calling_function_kwargs = kwargs;
    llvm_calling_function_all_args = all_args;
    llvm_calling_function_first_arg = first_arg;
    llvm_calling_function_kwnames = kwnames;
    llvm_calling_function_flags = METH_VARARGS | METH_KEYWORDS;
    llvm_calling_function = llvm_dummy_function;
    llvm_calling_function_name = "llvm_new_instance";
    
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    dispatch_semaphore_signal(semaphores.waiter);
    
    return llvm_start_waiting(module);
}

PyObject* llvm_call_getter(PyObject *cls, PyObject *__self, PyObject *module, const char *name) {
    
    PyGILState_STATE gstate = PyGILState_Ensure();
    PyObject *_self = PyObject_GetAttr(__self, PyUnicode_FromString("__bitcode_pointer__"));
    PyGILState_Release(gstate);
    
    llvm_calling_function_cls = cls;
    llvm_calling_function_retvalue = NULL;
    llvm_calling_function_exc_value = NULL;
    llvm_calling_function_exc_type = NULL;
    llvm_calling_function_self = _self;
    llvm_calling_function_args = NULL;
    llvm_calling_function_kwargs = NULL;
    llvm_calling_function_all_args = NULL;
    llvm_calling_function_first_arg = NULL;
    llvm_calling_function_kwnames = NULL;
    llvm_calling_function_flags = 0;
    llvm_calling_function = llvm_dummy_function;
    llvm_calling_function_name = "llvm_call_getter";
    llvm_calling_getter_setter_name = name;
        
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    dispatch_semaphore_signal(semaphores.waiter);
    
    return llvm_start_waiting(module);
}

PyObject* llvm_call_setter(PyObject *cls, PyObject *__self, PyObject *module, const char *name, PyObject *value) {
    
    PyGILState_STATE gstate = PyGILState_Ensure();
    PyObject *_self = PyObject_GetAttr(__self, PyUnicode_FromString("__bitcode_pointer__"));
    PyGILState_Release(gstate);
    
    llvm_calling_function_cls = cls;
    llvm_calling_function_retvalue = NULL;
    llvm_calling_function_exc_value = NULL;
    llvm_calling_function_exc_type = NULL;
    llvm_calling_function_self = _self;
    llvm_calling_function_args = NULL;
    llvm_calling_function_kwargs = NULL;
    llvm_calling_function_all_args = NULL;
    llvm_calling_function_first_arg = NULL;
    llvm_calling_function_kwnames = NULL;
    llvm_calling_function_flags = 0;
    llvm_calling_function = llvm_dummy_function;
    llvm_calling_function_name = "llvm_call_setter";
    llvm_calling_getter_setter_name = name;
    llvm_calling_setter_value = value;
    
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    dispatch_semaphore_signal(semaphores.waiter);
    
    return llvm_start_waiting(module);
}

PyObject* llvm_call_getattro(PyObject *cls, PyObject *__self, PyObject *module, PyObject *name) {
    PyGILState_STATE gstate = PyGILState_Ensure();
    PyObject *_self = PyObject_GetAttr(__self, PyUnicode_FromString("__bitcode_pointer__"));
    getattrofunc getattro = ((PyTypeObject *)cls)->tp_getattro;
    
    if (getattro == PyObject_GenericGetAttr) {
        PyObject *value = getattro(_self, name);
        PyGILState_Release(gstate);
        return value;
    }
    
    PyGILState_Release(gstate);
    
    llvm_calling_function_retvalue = NULL;
    llvm_calling_function_exc_value = NULL;
    llvm_calling_function_exc_type = NULL;
    llvm_calling_function_self = _self;
    llvm_calling_function_args = name;
    llvm_calling_function_kwargs = NULL;
    llvm_calling_function_all_args = NULL;
    llvm_calling_function_first_arg = NULL;
    llvm_calling_function_kwnames = NULL;
    llvm_calling_function_flags = METH_VARARGS;
    llvm_calling_function = (PyCFunction)getattro;
    llvm_calling_function_name = "getattro";
    
    if (llvm_calling_function_self && _PyType_Check(llvm_calling_function_self)) {
        ((PyTypeObject *)llvm_calling_function_self)->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE;
    }
    
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    dispatch_semaphore_signal(semaphores.waiter);
    
    return llvm_start_waiting(module);
}

void llvm_call_setattro(PyObject *cls, PyObject *__self, PyObject *module, PyObject *name, PyObject *value) {
    PyGILState_STATE gstate = PyGILState_Ensure();
    PyObject *_self = PyObject_GetAttr(__self, PyUnicode_FromString("__bitcode_pointer__"));
    setattrofunc setattro = ((PyTypeObject *)cls)->tp_setattro;
    
    if (setattro == PyObject_GenericSetAttr) {
        setattro(_self, name, value);
        PyGILState_Release(gstate);
        return;
    }
    
    PyGILState_Release(gstate);
    
    llvm_calling_function_retvalue = NULL;
    llvm_calling_function_exc_value = NULL;
    llvm_calling_function_exc_type = NULL;
    llvm_calling_function_self = _self;
    llvm_calling_function_args = name;
    llvm_calling_function_kwargs = value;
    llvm_calling_function_all_args = NULL;
    llvm_calling_function_first_arg = NULL;
    llvm_calling_function_kwnames = NULL;
    llvm_calling_function_flags = METH_VARARGS | METH_KEYWORDS;
    llvm_calling_function = (PyCFunction)setattro;
    llvm_calling_function_name = "setattro";
    
    if (llvm_calling_function_self && _PyType_Check(llvm_calling_function_self)) {
        ((PyTypeObject *)llvm_calling_function_self)->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE;
    }
    
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    dispatch_semaphore_signal(semaphores.waiter);
    
    llvm_start_waiting(module);
}

typedef struct {
    PyObject_HEAD
    PyMethodDef m_ml;
} CythonFunction;

#if !MAIN
PyObject* llvm_call_function(const char *name, PyObject *function, bool is_cython, PyObject *module, PyObject *args, PyObject *kwargs, PyObject *first_arg, PyObject *all_args, PyObject *kwnames) {
    return NULL;
}
#else
PyObject* llvm_call_function(const char *name, PyObject *function, bool is_cython, PyObject *module, PyObject *args, PyObject *kwargs, PyObject *first_arg, PyObject *all_args, PyObject *kwnames) {
    
    if (!is_cython && function != Py_None) {
        llvm_calling_function_self = PyCFunction_GetSelf(function);
        llvm_calling_function = PyCFunction_GetFunction(function);
        llvm_calling_function_flags = PyCFunction_GetFlags(function);
        llvm_calling_cython_function = NULL;
    } else {
        PyMethodDef def = ((CythonFunction *)function)->m_ml;
        llvm_calling_function_self = module;
        llvm_calling_function = def.ml_meth;
        llvm_calling_function_flags = def.ml_flags;
        llvm_calling_cython_function = function;
    }
        
    llvm_calling_function_retvalue = NULL;
    llvm_calling_function_exc_value = NULL;
    llvm_calling_function_exc_type = NULL;
    llvm_calling_function_args = args;
    llvm_calling_function_kwargs = kwargs;
    llvm_calling_function_all_args = all_args;
    llvm_calling_function_first_arg = first_arg;
    llvm_calling_function_kwnames = kwnames;
    
    llvm_calling_function_name = name;
    
    if (llvm_calling_function_self && _PyType_Check(llvm_calling_function_self)) {
        ((PyTypeObject *)llvm_calling_function_self)->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE;
    }
    
    LLVMSemaphores *semaphores = [LLVMSemaphores semaphoresFor:module];
    dispatch_semaphore_signal(semaphores.waiter);
    
    return llvm_start_waiting(module);
}
#endif


void llvm_free_objects(PyObject **weak_references, size_t size, PyObject *module) {
    
    PyObject *objects[size];
        
    for (int i = 0; i <= size; i += 1) {
        objects[i] = PyWeakref_GET_OBJECT(weak_references[i]);
    }
    
    llvm_free_objects_list = objects;
    llvm_free_size = size;
    
    llvm_call_function("None", Py_None, false, module, Py_None, Py_None, Py_None, Py_None, Py_None);
    
    llvm_free_objects_list = NULL;
}

int llvm_traverse(PyObject *self, visitproc visit, void *arg) {
    return 0;
}

void llvm_remove_traverse_from_cython_type(PyObject *_type) {
    if (PyType_Check(_type)) {
        PyTypeObject *type = ((PyTypeObject *)_type);
        if ([[NSString stringWithUTF8String:((PyTypeObject *)type)->tp_name] hasPrefix:@"_cython"]) {
            type->tp_flags &= ~(Py_TPFLAGS_HAVE_GC);
            type->tp_traverse = llvm_traverse;
        }
    }
}

static char _extensionsimporter_raise_exception_if_needed_docstring[] =
"Re-raises an exception raised by the LLVM interpreter if needed.";

static PyObject *_extensionsimporter_raise_exception_if_needed(PyObject *self, PyObject *args) {
    if (llvm_calling_function_exc_type && llvm_calling_function_exc_value) {
        PyErr_SetObject(llvm_calling_function_exc_type, llvm_calling_function_exc_value);
        llvm_calling_function_exc_type = NULL;
        llvm_calling_function_exc_value = NULL;
        return NULL;
    } else {
        return Py_None;
    }
}

void llvm_set_thread_id_for_module(pthread_t thread, PyObject *module) {
    [[LLVMSemaphores semaphoresFor:module] setModuleThread: thread];
}

bool is_bitcode_thread(void) {
    pthread_t current = pthread_self();
    for (LLVMSemaphores *semaphore in LLVMSemaphores.objcSemaphores) {
        if (pthread_equal(current, (pthread_t)semaphore.moduleThread)) {
            return true;
        }
    }
    return false;
}

PyObject *_extensionsimporter_module_from_bitcode(PyObject *self, PyObject *args) {
    
    const char *path;
    PyObject *spec;
    const char *scriptPath;
    if(!PyArg_ParseTuple(args, "sOs", &path, &spec, &scriptPath)) {
        return NULL;
    }
    
    NSString *_scriptPath;
    if (scriptPath) {
        _scriptPath = [NSString stringWithCString:scriptPath encoding:NSUTF8StringEncoding];
    }
    
    llvm_importing_module_spec = spec;
    
    __block PyObject *module;
    
    Py_BEGIN_ALLOW_THREADS;
    
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    
    __block void *session;
    
    [[[NSThread alloc] initWithBlock:^{
        lli_semaphore = dispatch_semaphore_create(0);
        [[[NSThread alloc] initWithBlock:^{
            #if !WIDGET
            NSPipe *outputPipe = [[NSPipe alloc] init];
            outputPipe.fileHandleForReading.readabilityHandler = ^void((NSFileHandle *handle)) {
                NSString *str = [[NSString alloc] initWithData:handle.availableData encoding:NSUTF8StringEncoding];
                if (str) {
                    dispatch_async(dispatch_queue_create(NULL, NULL), ^{
                        [PyOutputHelper print:str script:_scriptPath];
                    });
                }
            };
            
            NSPipe *errorPipe = [[NSPipe alloc] init];
            errorPipe.fileHandleForReading.readabilityHandler = ^void((NSFileHandle *handle)) {
                NSString *str = [[NSString alloc] initWithData:handle.availableData encoding:NSUTF8StringEncoding];
                if (str) {
                    dispatch_async(dispatch_queue_create(NULL, NULL), ^{
                        [PyOutputHelper print:str script:[NSString stringWithCString:scriptPath encoding:NSUTF8StringEncoding]];
                    });
                }
            };
            
            FILE *output = fdopen(outputPipe.fileHandleForWriting.fileDescriptor, "w");
            FILE *error = fdopen(errorPipe.fileHandleForWriting.fileDescriptor, "w");
            
            NSPipe *inputPipe;
            FILE *inputFile;
            
            if (!inputCache) {
                inputCache = [NSMutableArray array];
            }
            
            if (_scriptPath && PyInputHelper.inputPipes[_scriptPath]) {
                inputPipe = PyInputHelper.inputPipes[_scriptPath];
                inputFile = fdopen(inputPipe.fileHandleForReading.fileDescriptor, "r");
            } else if (scriptPath) {
                inputPipe = [[NSPipe alloc] init];
                inputFile = fdopen(inputPipe.fileHandleForReading.fileDescriptor, "r");
                [inputCache addObject:inputPipe];
                
                NSMutableDictionary *pipes = [NSMutableDictionary dictionaryWithDictionary:PyInputHelper.inputPipes];
                [pipes setObject:inputPipe forKey:_scriptPath];
                PyInputHelper.inputPipes = pipes;
            } else {
                inputFile = makeInputFile(@"");
            }
            
            session = output;
            ios_switchSession(output);
            ios_setStreams(inputFile, output, error);
            #else
            session = NULL;
            #endif
            
            #if MAIN
            ios_system([NSString stringWithFormat:@"lli '%@'", [[NSString stringWithUTF8String:path] stringByReplacingOccurrencesOfString:@"'" withString:@"\\'"]].UTF8String);
            
            fclose(inputFile);
            
            NSMutableDictionary *pipes = [NSMutableDictionary dictionaryWithDictionary:PyInputHelper.inputPipes];
            if ([pipes.allKeys containsObject:_scriptPath]) {
                [pipes removeObjectForKey:_scriptPath];
            }
            PyInputHelper.inputPipes = pipes;
            
            if ([inputCache containsObject:inputPipe]) {
                [inputCache removeObject:inputPipe];
            }
            #endif
            if (lli_semaphore) {
                dispatch_semaphore_signal(lli_semaphore);
            }
        }] start];
        dispatch_semaphore_wait(lli_semaphore, DISPATCH_TIME_FOREVER);
        lli_semaphore = NULL;
        
        // Convert PyModuleDef from the interpeter
        if (!last_llvm_module || PyObject_TypeCheck(last_llvm_module, &PyModuleDef_Type)) {
            module = Py_None;
            dispatch_semaphore_signal(semaphore);
            return;
        }
        
        module = last_llvm_module;
        
        PyGILState_STATE state = PyGILState_Ensure();
        
        NSURL *binaryURL = [NSURL fileURLWithPath:[NSString stringWithUTF8String:path]];
        SET_FILE();
        
        PyGILState_Release(state);
        
        last_llvm_module = NULL;
        
        dispatch_semaphore_signal(semaphore);
    }] start];
    
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    
    Py_END_ALLOW_THREADS;
    
    return module;
}

// MARK: - module_from_binary

static char _extensionsimporter_module_from_binary_docstring[] =
    "Returns a module from the name of a framework.";

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
            if ([url.pathExtension isEqual:@"so"] || [url.lastPathComponent isEqual:frameworkPath.stringByDeletingPathExtension.lastPathComponent]) {
                binaryURL = url;
                break;
            }
        }
    }
    
    if (!binaryURL) {
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
    
    NSString *libName = [NSString stringWithUTF8String:name];
    libName = [libName componentsSeparatedByString:@"."].firstObject;
    if (!libName) {
        libName = [NSString stringWithUTF8String:name];
    }
    if (!Python.shared.canImportExtensions && [Python.shared.fullVersionExclusives containsObject:libName]) {
        PyErr_SetString(PyExc_ImportError, "");
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

// MARK: - system

static char _extensionsimporter_system_docstring[] =
"Executes the given command with ios_system";

bool startsWith(const char *pre, const char *str) {
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : memcmp(pre, str, lenpre) == 0;
}

static PyObject *_extensionsimporter_system(PyObject *self, PyObject *args) {
    
    const char *cmd;
    if(!PyArg_ParseTuple(args, "s", &cmd)) {
        return NULL;
    }
    
    PyObject *threading = PyImport_Import(PyUnicode_FromString("threading"));
    PyObject *currentThread = PyObject_CallNoArgs(PyObject_GetAttrString(threading, "current_thread"));
    PyObject *scriptPathObject = PyObject_GetAttrString(currentThread, "script_path");
    
    PyObject *shutil = PyImport_Import(PyUnicode_FromString("shutil"));
    PyObject *terminalSize = PyObject_CallNoArgs(PyObject_GetAttrString(shutil, "get_terminal_size"));
    PyObject *columnsObject = PyObject_GetAttrString(terminalSize, "columns");
    PyObject *linesObject = PyObject_GetAttrString(terminalSize, "lines");
        
    PyObject* scriptPathAndSize = Py_BuildValue("(OOO)", scriptPathObject, columnsObject, linesObject);
    if (!scriptPathAndSize) return Py_None;
    const char* scriptPath;
    int columns, lines;
    if (!PyArg_ParseTuple(scriptPathAndSize, "sii", &scriptPath, &columns, &lines)) {
      Py_DECREF(args);
      return Py_None;
    }

    Py_DECREF(args);
    
    #if !WIDGET
    NSString *cwd = [NSFileManager.defaultManager currentDirectoryPath];
    #endif
    
    #if !WIDGET
    
    PyObject *sys = PyImport_Import(PyUnicode_FromString("sys"));
    PyObject *defaultSys = PyObject_GetAttr(sys, PyUnicode_FromString("sys"));
    
    PyObject *_stdout = PyObject_GetAttrString(sys, "stdout");
    PyObject *_stderr = PyObject_GetAttrString(sys, "stderr");
    PyObject *_stdin = PyObject_GetAttrString(sys, "stdin");
    PyObject *stdoutWrite = PyObject_GetAttrString(_stdout, "write");
    PyObject *stdinRead = PyObject_GetAttrString(_stdin, "read");
    
    PyObject *defaultStdout = PyObject_GetAttrString(defaultSys, "stdout");
    PyObject *defaultStderr = PyObject_GetAttrString(defaultSys, "stderr");
    
    if (PyObject_IsTrue(PyObject_CallMethodNoArgs(_stdout, PyUnicode_FromString("isatty")))) {
        putenv("CLICOLOR=1");
    } else {
        columns = 0;
        lines = 0;
        unsetenv("CLICOLOR");
    }
    
    PyObject *stderrWrite = PyObject_GetAttrString(_stderr, "write");
    
    NSString *_scriptPath;
    if (scriptPath) {
        _scriptPath = [NSString stringWithCString:scriptPath encoding:NSUTF8StringEncoding];
    } else {
        _scriptPath = @"";
    }
    
    NSPipe *outputPipe = [[NSPipe alloc] init];
    NSMutableString *outputString = [[NSMutableString alloc] init];
    outputPipe.fileHandleForReading.readabilityHandler = ^void((NSFileHandle *handle)) {
        NSString *str = [[NSString alloc] initWithData:handle.availableData encoding:NSUTF8StringEncoding];
        if (str) {
            [outputString appendString: str];
            
            if (_stdout == defaultStdout) {
                [PyOutputHelper print:str script:_scriptPath];
            } else {
                PyGILState_STATE tstate = PyGILState_Ensure();
                
                PyObject *thread = PyObject_CallMethodNoArgs(threading, PyUnicode_FromString("current_thread"));
                PyObject_SetAttrString(thread, "script_path", scriptPathObject);
                PyObject_CallOneArg(stdoutWrite, PyUnicode_FromString([str UTF8String]));
                PyGILState_Release(tstate);
            }
        }
    };
    
    FILE *output = fdopen(outputPipe.fileHandleForWriting.fileDescriptor, "w");
    
    NSPipe *errorPipe = [[NSPipe alloc] init];
    NSMutableString *errorString = [[NSMutableString alloc] init];
    errorPipe.fileHandleForReading.readabilityHandler = ^void((NSFileHandle *handle)) {
        NSString *str = [[NSString alloc] initWithData:handle.availableData encoding:NSUTF8StringEncoding];
        if (str) {
            [errorString appendString: str];
            
            if (_stderr == defaultStderr) {
                [PyOutputHelper print:str script:_scriptPath];
            } else {
                PyGILState_STATE tstate = PyGILState_Ensure();
                
                PyObject *thread = PyObject_CallMethodNoArgs(threading, PyUnicode_FromString("current_thread"));
                PyObject_SetAttrString(thread, "script_path", scriptPathObject);
                PyObject_CallOneArg(stderrWrite, PyUnicode_FromString([str UTF8String]));
                PyGILState_Release(tstate);
            }
        }
    };
    
    FILE *error = fdopen(errorPipe.fileHandleForWriting.fileDescriptor, "w");
    
    const char *input;
    NSPipe *inputPipe;
    FILE *inputFile;
    
    if (!inputCache) {
        inputCache = [NSMutableArray array];
    }
    
    if (PyObject_IsTrue(PyObject_CallMethodNoArgs(_stdin, PyUnicode_FromString("isatty")))) {
        if (scriptPath) {
            inputPipe = [[NSPipe alloc] init];
            inputFile = fdopen(inputPipe.fileHandleForReading.fileDescriptor, "r");
            [inputCache addObject:inputPipe];
            
            NSMutableDictionary *pipes = [NSMutableDictionary dictionaryWithDictionary:PyInputHelper.inputPipes];
            [pipes setObject:inputPipe forKey:_scriptPath];
            PyInputHelper.inputPipes = pipes;
        } else {
            inputFile = makeInputFile(@"");
        }
    } else {
        PyObject *passedInputObject = Py_BuildValue("(O)", PyObject_CallNoArgs(stdinRead));
        if (!passedInputObject) return Py_None;
        if (!PyArg_ParseTuple(passedInputObject, "s", &input)) {
          return Py_None;
        }
        
        NSString *inputString = [NSString stringWithUTF8String: input];
        inputFile = makeInputFile(inputString);
    }
    
    if (_scriptPath && [PyInputHelper.ignoreInputPipes containsObject:_scriptPath]) {
        
        NSMutableArray *arr = [NSMutableArray arrayWithArray: PyInputHelper.ignoreInputPipes];
        [arr removeObject: _scriptPath];
        PyInputHelper.ignoreInputPipes = arr;
    }
    
    ios_switchSession(output);
    ios_setWindowSize(columns, lines, output);
    ios_setStreams(inputFile, output, error);
    ios_setDirectoryURL([NSURL fileURLWithPath: cwd]);
    #endif
    
    #if MAIN
    PyObject *ret = PyLong_FromDouble(ios_system(cmd));
    fclose(inputFile);
    
    NSMutableDictionary *pipes = [NSMutableDictionary dictionaryWithDictionary:PyInputHelper.inputPipes];
    if ([pipes.allKeys containsObject:_scriptPath]) {
        [pipes removeObjectForKey:_scriptPath];
    }
    PyInputHelper.inputPipes = pipes;
    
    if ([inputCache containsObject:inputPipe]) {
        [inputCache removeObject:inputPipe];
    }
    #else
    PyObject *ret = Py_None;
    #endif
    
    #if !WIDGET
    fflush(output);
    fflush(error);
    
    fclose(output);
    fclose(error);
    #endif
    
    return ret;
}

// MARK: - extensionsimporter

static PyMethodDef _extensionsimporter_methods[] = {
    {"module_from_binary", _extensionsimporter_module_from_binary, METH_VARARGS, _extensionsimporter_module_from_binary_docstring},
    {"module_from_bitcode", _extensionsimporter_module_from_bitcode, METH_VARARGS, _extensionsimporter_module_from_bitcode_docstring},
    {"raise_exception_if_needed", _extensionsimporter_raise_exception_if_needed, METH_NOARGS, _extensionsimporter_raise_exception_if_needed_docstring},
    {"system", _extensionsimporter_system, METH_VARARGS, _extensionsimporter_system_docstring},
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

PyMODINIT_FUNC PyInit__extensionsimporter(void) {
    return PyModule_Create(&_extensionsimporter);
}
