// --------------------------------
// Interpreter comptatibilty stuff
// --------------------------------

#include <Python.h>
#include "pycore_gc.h"
#include "structmember.h"
#include "pthread.h"

#define FETCH_ERROR PyThreadState *tstate = PyThreadState_Get(); \
PyObject* exc_type; \
PyObject* exc_value; \
PyObject* exc_tb; \
PyErr_Fetch(&exc_type, &exc_value, &exc_tb);

typedef struct {
    PyObject_HEAD
    PyObject *md_dict;
    struct PyModuleDef *md_def;
    void *md_state;
} PyModuleObject;

PyObject *llvm_importing_module_get_spec(void);

PyObject *llvm_calling_function_get_self(void);
PyObject *llvm_calling_function_get_args(void);
PyObject *llvm_calling_function_get_kwargs(void);
PyObject *llvm_calling_function_get_all_args(void);
PyObject *llvm_calling_function_get_first_arg(void);
PyObject *llvm_calling_function_get_kwnames(void);
PyObject *llvm_calling_function_get_cls(void);
const char *llvm_calling_function_get_name(void);
const char *llvm_calling_getter_setter_get_name(void);
PyObject *llvm_calling_setter_get_value(void);

PyObject **llvm_get_free_objects_list(void);
size_t llvm_get_free_size(void);

int llvm_calling_function_get_flags(void);
PyObject *llvm_get_cython_function(void);
void *llvm_get_calling_function(void);
void llvm_stop_waiting(PyObject *module, PyObject *return_value, PyObject *exc_type, PyObject *exc_value);
PyObject* llvm_wait_for_calling_function(PyObject *module);

PyGILState_STATE llvm_ensure_gil(void);

PyObject *llvm_type_alloc(PyTypeObject *cls, Py_ssize_t nitems) {
    return PyType_GenericAlloc(cls, nitems);
}

void llvm_set_thread_id_for_module(pthread_t thread, PyObject *module);

#define likely(x)   (x)
#define unlikely(x) (x)

#define CYTHON_FORMAT_SSIZE_T "z"

// Crashes with 2+ parameters
PyObject *cython_print_result(PyObject *self, PyObject *args, PyObject *kw);

static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    Py_ssize_t size;
    printf("__Pyx_CyFunction_CallMethod: 1\n");
    PyCFunction meth = llvm_get_calling_function();
    printf("__Pyx_CyFunction_CallMethod: 2\n");
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        printf("__Pyx_CyFunction_CallMethod: METH_VARARGS\n");
        return Py_None;
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        printf("__Pyx_CyFunction_CallMethod: METH_VARARGS | METH_KEYWORDS\n");
        return cython_print_result(self, arg, kw);
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        printf("__Pyx_CyFunction_CallMethod: METH_NOARGS\n");
        return Py_None;
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        printf("__Pyx_CyFunction_CallMethod: METH_O\n");
        return Py_None;
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags for CyFunction");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}

void Cext_Py_DECREF(PyObject *op) {
        
#if defined(Py_REF_DEBUG) && defined(Py_LIMITED_API) && Py_LIMITED_API+0 >= 0x030A0000
    // Stable ABI for Python 3.10 built in debug mode.
    _Py_DecRef(op);
#else
    // Non-limited C API and limited C API for Python 3.9 and older access
    // directly PyObject.ob_refcnt.
#ifdef Py_REF_DEBUG
    _Py_RefTotal--;
#endif
    if (--op->ob_refcnt != 0) {
#ifdef Py_REF_DEBUG
        if (op->ob_refcnt < 0) {
            _Py_NegativeRefcount(filename, lineno, op);
        }
#endif
    }
    else {
        destructor dealloc = Py_TYPE(op)->tp_dealloc;
#ifdef Py_TRACE_REFS
        _Py_ForgetReference(op);
#endif
        (*dealloc)(op);
    }
    
#endif
}

static inline void _PyObject_GC_UNTRACK(PyObject *op) {
    PyGC_Head *gc = _Py_AS_GC(op);
    PyGC_Head *prev = _PyGCHead_PREV(gc);
    PyGC_Head *next = _PyGCHead_NEXT(gc);
    /*_PyGCHead_SET_NEXT(prev, next);
    _PyGCHead_SET_PREV(next, prev);
    gc->_gc_next = 0;
    gc->_gc_prev &= _PyGC_PREV_MASK_FINALIZED;*/
}

void Cext_PyObject_GC_UnTrack(void *op_raw) {
    PyObject *op = _PyObject_CAST(op_raw);
    /* Obscure:  the Py_TRASHCAN mechanism requires that we be able to
     * call PyObject_GC_UnTrack twice on an object.
     */
    if (_PyObject_GC_IS_TRACKED(op)) {
        _PyObject_GC_UNTRACK(op);
    }
}

void Cext_PyObjectFree(void *self) {
    PyObject_Free(self);
}

int llvm_wait_for_functions(PyObject *module) {
    PyObject* deleting = llvm_wait_for_calling_function(module);
        
    if (deleting == module) {
        llvm_stop_waiting(module, Py_None, NULL, NULL);
        return 0;
    }
    
    if (llvm_get_calling_function()) {
    
        PyGILState_STATE gstate = PyGILState_Ensure();
    
        // Call the function
        PyObject *self = llvm_calling_function_get_self();
        PyObject *args = llvm_calling_function_get_args();
        PyObject *kwargs = llvm_calling_function_get_kwargs();
        PyObject *all_args = llvm_calling_function_get_all_args();
        PyObject *first_arg = llvm_calling_function_get_first_arg();
        PyObject *kwnames = llvm_calling_function_get_kwnames();
        int flags = llvm_calling_function_get_flags() & (METH_VARARGS | METH_FASTCALL | METH_NOARGS | METH_O | METH_KEYWORDS | METH_METHOD);
        PyCFunction function = llvm_get_calling_function();
        
        const char *name = llvm_calling_function_get_name();
        
        if (llvm_get_free_objects_list()) { // Free objects
                        
            size_t i;
            for (i = 0; i <= llvm_get_free_size(); i+=1) {
                PyObject *obj = llvm_get_free_objects_list()[i];
                Cext_Py_DECREF(obj);
            }
            
            PyGILState_Release(gstate);
            llvm_stop_waiting(module, Py_None, NULL, NULL);
            return llvm_wait_for_functions(module);
        } else if (llvm_get_cython_function()) { // Call Cython function
            PyObject *ret_value = __Pyx_CyFunction_CallMethod(llvm_get_cython_function(), self, args, kwargs);
            
            FETCH_ERROR;
            
            PyGILState_Release(gstate);
            llvm_stop_waiting(module, ret_value, exc_type, exc_value);
            return llvm_wait_for_functions(module);
        } else if (strcmp(name, "llvm_new_instance") == 0) { // Create an instance
            PyTypeObject *cls = (PyTypeObject *)llvm_calling_function_get_cls();
            cls->tp_alloc = llvm_type_alloc;
            
            PyCFunctionWithKeywords new = (PyCFunctionWithKeywords)cls->tp_new;
            PyCFunctionWithKeywords init = (PyCFunctionWithKeywords)cls->tp_init;
            
            PyObject *instance = new((PyObject *)cls, args, kwargs);
            init(instance, args, kwargs);
            
            FETCH_ERROR;
            
            PyGILState_Release(gstate);
            llvm_stop_waiting(module, instance, exc_type, exc_value);
            return llvm_wait_for_functions(module);
        } else if (strcmp(name, "llvm_call_getter") == 0 || strcmp(name, "llvm_call_setter") == 0) { // Call getter or setter
            const char *attr = llvm_calling_getter_setter_get_name();
            
            PyTypeObject *cls = (PyTypeObject *)llvm_calling_function_get_cls();
            PyGetSetDef *getset = ((PyTypeObject *)cls)->tp_getset;
                        
            PyObject *value = NULL;
            
            int i = 0;
            for (i = 0; 1; i += 1) {
                PyGetSetDef def = getset[i];
                
                if (!def.name) {
                    break;
                }
                
                if (strcmp(name, "llvm_call_setter") == 0) {
                    if (def.name && strcmp(def.name, attr) == 0 && def.set) {
                        value = Py_None;
                        setter set = def.set;
                        set(llvm_calling_function_get_self(), llvm_calling_setter_get_value(), NULL);
                    }
                } else {
                    if (def.name && strcmp(def.name, attr) == 0 && def.get) {
                        getter get = def.get;
                        value = get(llvm_calling_function_get_self(), NULL);
                    }
                }
            }
            
            if (!value) {
                PyErr_SetString(PyExc_SystemError, "No getter was found.");
            }
            
            FETCH_ERROR;
            
            PyGILState_Release(gstate);
            llvm_stop_waiting(module, value, exc_type, exc_value);
            return llvm_wait_for_functions(module);
        }
        
        PyObject *ret;
        
        if (flags == METH_VARARGS) {
            PyCFunction func = function;
            ret = func(self, args);
        } else if (flags == (METH_VARARGS | METH_KEYWORDS)) {
            PyCFunctionWithKeywords func = (PyCFunctionWithKeywords)function;
            ret = func(self, args, kwargs);
        } else if (flags == (METH_FASTCALL | METH_KEYWORDS)) {
            _PyCFunctionFastWithKeywords func = (_PyCFunctionFastWithKeywords)function;
            Py_ssize_t size = PyList_Size(all_args);
            PyObject **args_array = malloc(size*sizeof(PyObject));
            
            int i;
            for(i=0; i < (int)size; i++) {
                args_array[i] = PyList_GetItem(args, i);
            }
            
            ret = func(self, (PyObject *const *)args_array, size, kwnames);
        } else if (flags == (METH_METHOD | METH_FASTCALL | METH_KEYWORDS)) {
            PyCMethod func = (PyCMethod)function;
            Py_ssize_t size = PyList_Size(all_args);
            PyObject **args_array = malloc(size*sizeof(PyObject));
            
            int i;
            for(i=0; i < (int)size; i++) {
                args_array[i] = PyList_GetItem(args, i);
            }
            // TODO: pass defining class
            ret = func(self, NULL, args_array, size, kwnames);
        } else if ((flags == METH_FASTCALL) || flags == (METH_FASTCALL | METH_METHOD)) {
            _PyCFunctionFast func = (_PyCFunctionFast)function;
            Py_ssize_t size = PyList_Size(args);
            PyObject **args_array = malloc(size*sizeof(PyObject));
               
            int i;
            for(i=0; i < (int)size; i++) {
                args_array[i] = PyList_GetItem(args, i);
            }
               
            ret = func(self, (PyObject *const *)args_array, size);
        } else if (flags == METH_NOARGS) {
            PyCFunction func = function;
            ret = func(self, NULL);
        } else if (flags == METH_O) {
            PyCFunction func = function;
            ret = func(self, first_arg) ;
        }
        
        if (!ret) { // Exception
            ret = Py_None;
        }

        FETCH_ERROR;
        
        PyGILState_Release(gstate);
        
        // Send the return value
        llvm_stop_waiting(module, ret, exc_type, exc_value);
    }
    return llvm_wait_for_functions(module);
}

void llvm_set_bitcode_module(PyObject *module);

PyObject* PYINIT_FUNCTION(void);

#ifndef PYINIT_FUNCTION
#error PYINIT_FUNCTION must be set
#endif

int add_methods_to_object(PyObject *module, PyObject *name, PyMethodDef *functions) {
    PyObject *func;
    PyMethodDef *fdef;

    for (fdef = functions; fdef->ml_name != NULL; fdef++) {
        if ((fdef->ml_flags & METH_CLASS) ||
            (fdef->ml_flags & METH_STATIC)) {

            return -1;
        }
        func = PyCFunction_NewEx(fdef, (PyObject*)module, name);
        if (func == NULL) {
            return -1;
        }
        if (PyObject_SetAttrString(module, fdef->ml_name, func) != 0) {
            Py_DECREF(func);
            return -1;
        }
        Py_DECREF(func);
    }

    return 0;
}

PyObject * LLVMModule_FromDefAndSpec(struct PyModuleDef* def, PyObject *spec) {
    PyModuleDef_Slot* cur_slot;
    PyObject *(*create)(PyObject *, PyModuleDef*) = NULL;
    PyObject *nameobj;
    PyObject *m = NULL;
    int has_execution_slots = 0;
    const char *name;
    int ret;

    PyModuleDef_Init(def);

    nameobj = PyObject_GetAttrString(spec, "name");
    if (nameobj == NULL) {
        return NULL;
    }
    name = PyUnicode_AsUTF8(nameobj);
    if (name == NULL) {
        goto error;
    }

    if (def->m_size < 0) {
        goto error;
    }

    for (cur_slot = def->m_slots; cur_slot && cur_slot->slot; cur_slot++) {
        if (cur_slot->slot == Py_mod_create) {
        } else if (cur_slot->slot < 0 || cur_slot->slot > _Py_mod_LAST_SLOT) {
        } else {
            has_execution_slots = 1;
        }
    }

    m = PyModule_NewObject(nameobj);
    if (m == NULL) {
        goto error;
    }

    if (PyModule_Check(m)) {
        ((PyModuleObject*)m)->md_state = NULL;
        ((PyModuleObject*)m)->md_def = def;
    } else {
        if (def->m_size > 0 || def->m_traverse || def->m_clear || def->m_free) {
            goto error;
        }
        if (has_execution_slots) {
            goto error;
        }
    }

    if (def->m_methods != NULL) {
        ret = add_methods_to_object(m, nameobj, def->m_methods);
        if (ret != 0) {
            goto error;
        }
    }

    if (def->m_doc != NULL) {
        ret = PyModule_SetDocString(m, def->m_doc);
        if (ret != 0) {
            goto error;
        }
    }

    Py_DECREF(nameobj);
    return m;

error:
    Py_DECREF(nameobj);
    Py_XDECREF(m);
    return NULL;
}

int main() {
   
    PyGILState_STATE gstate = llvm_ensure_gil();
    
    PyObject *module = PYINIT_FUNCTION();
    
    PyModuleDef *def;
    if (PyObject_TypeCheck(module, &PyModuleDef_Type)) {
        def = (PyModuleDef *)module;
        
        PyModuleDef_Slot* cur_slot;
        PyObject *(*create)(PyObject *, PyModuleDef*) = NULL;
        int (*exec)(PyObject *) = NULL;
            
        for (cur_slot = def->m_slots; cur_slot && cur_slot->slot; cur_slot++) {
            if (cur_slot->slot == Py_mod_create) {
                if (create) {
                    PyGILState_Release(gstate);
                    llvm_set_bitcode_module(module);
                    return 1;
                }
                create = cur_slot->value;
            } else if (cur_slot->slot == Py_mod_exec) {
            } else if (cur_slot->slot < 0 || cur_slot->slot > _Py_mod_LAST_SLOT) {
                PyGILState_Release(gstate);
                llvm_set_bitcode_module(module);
                return 1;
            }
        }
        
        if (create) {
            module = create(llvm_importing_module_get_spec(), def);
        } else {
            module = LLVMModule_FromDefAndSpec(def, llvm_importing_module_get_spec());
        }
                
        if (!module) {
            PyGILState_Release(gstate);
            llvm_set_bitcode_module(Py_None);
            return 1;
        }
        
        cur_slot = NULL;
        for (cur_slot = def->m_slots; cur_slot && cur_slot->slot; cur_slot++) {
            if (cur_slot->slot == Py_mod_exec) {
                exec = cur_slot->value;
                gstate = PyGILState_Ensure();
                exec(module);
            }
        }
    } else {
        def = ((PyModuleObject *)module)->md_def;
    }
    
    PyGILState_Release(gstate);
    
    llvm_set_bitcode_module(module);
    
    llvm_set_thread_id_for_module(pthread_self(), module);
    
    return llvm_wait_for_functions(module);
}
