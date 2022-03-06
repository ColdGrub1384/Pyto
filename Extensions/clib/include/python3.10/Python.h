#ifndef Py_PYTHON_H
#define Py_PYTHON_H

/* Since this is a "meta-include" file, no #ifdef __cplusplus / extern "C" { */

/* Include nearly all Python header files */

#include "patchlevel.h"
#include "pyconfig.h"
#include "pymacconfig.h"

#include <limits.h>

#ifndef UCHAR_MAX
#error "Something's broken.  UCHAR_MAX should be defined in limits.h."
#endif

#if UCHAR_MAX != 255
#error "Python's source code assumes C's unsigned char is an 8-bit type."
#endif

#if defined(__sgi) && !defined(_SGI_MP_SOURCE)
#define _SGI_MP_SOURCE
#endif

#include <stdio.h>
#ifndef NULL
#   error "Python.h requires that stdio.h define NULL."
#endif

#include <string.h>
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#include <stdlib.h>
#ifndef MS_WINDOWS
#include <unistd.h>
#endif

/* For size_t? */
#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif

/* CAUTION:  Build setups should ensure that NDEBUG is defined on the
 * compiler command line when building Python in release mode; else
 * assert() calls won't be removed.
 */
#include <assert.h>

#include "pyport.h"
#include "pymacro.h"

/* A convenient way for code to know if sanitizers are enabled. */
#if defined(__has_feature)
#  if __has_feature(memory_sanitizer)
#    if !defined(_Py_MEMORY_SANITIZER)
#      define _Py_MEMORY_SANITIZER
#    endif
#  endif
#  if __has_feature(address_sanitizer)
#    if !defined(_Py_ADDRESS_SANITIZER)
#      define _Py_ADDRESS_SANITIZER
#    endif
#  endif
#elif defined(__GNUC__)
#  if defined(__SANITIZE_ADDRESS__)
#    define _Py_ADDRESS_SANITIZER
#  endif
#endif

#include "pymath.h"
#include "pymem.h"

#include "object.h"
#include "objimpl.h"
#include "typeslots.h"
#include "pyhash.h"

#include "cpython/pydebug.h"

#include "bytearrayobject.h"
#include "bytesobject.h"
#include "unicodeobject.h"
#include "longobject.h"
#include "longintrepr.h"
#include "boolobject.h"
#include "floatobject.h"
#include "complexobject.h"
#include "rangeobject.h"
#include "memoryobject.h"
#include "tupleobject.h"
#include "listobject.h"
#include "dictobject.h"
#include "cpython/odictobject.h"
#include "enumobject.h"
#include "setobject.h"
#include "methodobject.h"
#include "moduleobject.h"
#include "funcobject.h"
#include "classobject.h"
#include "fileobject.h"
#include "pycapsule.h"
#include "code.h"
#include "pyframe.h"
#include "traceback.h"
#include "sliceobject.h"
#include "cellobject.h"
#include "iterobject.h"
#include "genobject.h"
#include "descrobject.h"
#include "genericaliasobject.h"
#include "warnings.h"
#include "weakrefobject.h"
#include "structseq.h"
#include "namespaceobject.h"
#include "cpython/picklebufobject.h"
#include "cpython/pytime.h"

#include "codecs.h"
#include "pyerrors.h"

#include "cpython/initconfig.h"
#include "pythread.h"
#include "pystate.h"
#include "context.h"

#include "modsupport.h"
#include "compile.h"
#include "pythonrun.h"
#include "pylifecycle.h"
#include "ceval.h"
#include "sysmodule.h"
#include "osmodule.h"
#include "intrcheck.h"
#include "import.h"

#include "abstract.h"
#include "bltinmodule.h"

#include "eval.h"

#include "cpython/pyctype.h"
#include "pystrtod.h"
#include "pystrcmp.h"
#include "fileutils.h"
#include "cpython/pyfpe.h"
#include "tracemalloc.h"

void Cext_Py_DECREF(PyObject *op);

#undef Py_DECREF
#define Py_DECREF(op) Cext_Py_DECREF(_PyObject_CAST(op))


#undef PyObject_HEAD
#define PyObject_HEAD PyObject ob_base; \
PyObject *weakreflist;

void Cext_PyObjectFree(void *self);


typedef struct {
    PyObject_HEAD
} __WeakrefObjectDummy__;

#undef PyVarObject_HEAD_INIT
#define PyVarObject_HEAD_INIT(type, size) _PyObject_EXTRA_INIT 1, type, size, \
.tp_weaklistoffset = offsetof(__WeakrefObjectDummy__, weakreflist), \
.tp_free = Cext_PyObjectFree,

void Cext_PyObject_GC_UnTrack(void *);
#define PyObject_GC_UnTrack(op) Cext_PyObject_GC_UnTrack(op)

#endif /* !Py_PYTHON_H */
