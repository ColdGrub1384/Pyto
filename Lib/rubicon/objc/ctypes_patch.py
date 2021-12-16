"""This module provides a workaround to allow callback functions to return composite types (most importantly structs).

Currently, ctypes callback functions (created by passing a Python callable to a CFUNCTYPE object) are only able to
return what ctypes considers a "simple" type. This includes void (None), scalars (c_int, c_float, etc.), c_void_p,
c_char_p, c_wchar_p, and py_object. Returning "composite" types (structs, unions, and non-"simple" pointers) is
not possible. This issue has been reported on the Python bug tracker as bpo-5710 (https://bugs.python.org/issue5710).

For pointers, the easiest workaround is to return a c_void_p instead of the correctly typed pointer, and to cast
the value on both sides. For structs and unions there is no easy workaround, which is why this somewhat hacky
workaround is necessary.
"""

import ctypes
import sys
import types
import warnings

# This module relies on the layout of a few internal Python and ctypes structures.
# Because of this, it's possible (but not all that likely) that things will break on newer/older Python versions.
if sys.version_info < (3, 4) or sys.version_info >= (3, 11):
    warnings.warn(
        "rubicon.objc.ctypes_patch has only been tested with Python 3.4 through 3.10. "
        "You are using Python {v.major}.{v.minor}.{v.micro}. Most likely things will "
        "work properly, but you may experience crashes if Python's internals have "
        "changed significantly."
        .format(v=sys.version_info)
    )


# The PyTypeObject struct from "Include/object.h".
# This is a forward declaration, fields are set later once PyVarObject has been declared.
class PyTypeObject(ctypes.Structure):
    pass


# The PyObject struct from "Include/object.h".
class PyObject(ctypes.Structure):
    _fields_ = [
        ("ob_refcnt", ctypes.c_ssize_t),
        ("ob_type", ctypes.POINTER(PyTypeObject)),
    ]


# The PyVarObject struct from "Include/object.h".
class PyVarObject(ctypes.Structure):
    _fields_ = [
        ("ob_base", PyObject),
        ("ob_size", ctypes.c_ssize_t),
    ]


# This structure is not stable across Python versions, but the few fields that we use probably won't change.
PyTypeObject._fields_ = [
    ("ob_base", PyVarObject),
    ("tp_name", ctypes.c_char_p),
    ("tp_basicsize", ctypes.c_ssize_t),
    ("tp_itemsize", ctypes.c_ssize_t),
    # There are many more fields, but we're only interested in the size fields, so we can leave out everything else.
]


# The PyTypeObject structure for the dict class.
# This is used to determine the size of the PyDictObject structure.
PyDict_Type = PyTypeObject.from_address(id(dict))


# The PyDictObject structure from "Include/dictobject.h".
# This structure is not stable across Python versions, and did indeed change in recent Python releases.
# Because we only care about the size of the structure and not its actual contents,
# we can declare it as an opaque byte array, with the length taken from PyDict_Type.
class PyDictObject(ctypes.Structure):
    _fields_ = [
        ("PyDictObject_opaque", (ctypes.c_ubyte*PyDict_Type.tp_basicsize)),
    ]


# The mappingproxyobject struct from "Objects/descrobject.c".
# This structure is not officially stable across Python versions, but its layout hasn't changed since 2001.
class mappingproxyobject(ctypes.Structure):
    _fields_ = [
        ("ob_base", PyObject),
        ("mapping", ctypes.py_object),
    ]


# The ffi_type structure from libffi's "include/ffi.h".
# This is a forward declaration, because the structure contains pointers to itself.
class ffi_type(ctypes.Structure):
    pass


ffi_type._fields_ = [
    ("size", ctypes.c_size_t),
    ("alignment", ctypes.c_ushort),
    ("type", ctypes.c_ushort),
    ("elements", ctypes.POINTER(ctypes.POINTER(ffi_type))),
]


# The GETFUNC and SETFUNC typedefs from "Modules/_ctypes/ctypes.h".
GETFUNC = ctypes.PYFUNCTYPE(ctypes.py_object, ctypes.c_void_p, ctypes.c_ssize_t)
# The return type of SETFUNC is declared here as a c_void_p instead of py_object to work around ctypes bug
# bpo-36880 (https://bugs.python.org/issue36880). See the comment in make_callback_returnable's setfunc for details.
SETFUNC = ctypes.PYFUNCTYPE(ctypes.c_void_p, ctypes.c_void_p, ctypes.py_object, ctypes.c_ssize_t)


# The StgDictObject structure from "Modules/_ctypes/ctypes.h".
# This structure is not officially stable across Python versions,
# but it basically hasn't changed since ctypes was originally added to Python in 2009.
class StgDictObject(ctypes.Structure):
    _fields_ = [
        ("dict", PyDictObject),
        ("size", ctypes.c_ssize_t),
        ("align", ctypes.c_ssize_t),
        ("length", ctypes.c_ssize_t),
        ("ffi_type_pointer", ffi_type),
        ("proto", ctypes.py_object),
        ("setfunc", SETFUNC),
        ("getfunc", GETFUNC),
        # There are a few more fields, but we leave them out again because we don't need them.
    ]


ctypes.pythonapi.Py_IncRef.restype = None
ctypes.pythonapi.Py_IncRef.argtypes = [ctypes.POINTER(PyObject)]


def unwrap_mappingproxy(proxy):
    """Return the mapping contained in a mapping proxy object."""

    if not isinstance(proxy, types.MappingProxyType):
        raise TypeError(
            'Expected a mapping proxy object, not {tp.__module__}.{tp.__qualname__}'
            .format(tp=type(proxy))
        )

    return mappingproxyobject.from_address(id(proxy)).mapping


def get_stgdict_of_type(tp):
    """Return the given ctypes type's StgDict object. If the object's dict is not a StgDict, an error is raised.

    This function is roughly equivalent to the PyType_stgdict function in the ctypes source code. We cannot use that
    function directly, because it is not part of CPython's public C API, and thus not accessible on some systems
    (see #113).
    """

    if not isinstance(tp, type):
        raise TypeError(
            'Expected a type object, not {tptp.__module__}.{tptp.__qualname__}'
            .format(tptp=type(tp))
        )

    stgdict = tp.__dict__
    if isinstance(stgdict, types.MappingProxyType):
        # If the type's __dict__ is wrapped in a mapping proxy, we need to unwrap it.
        # (This appears to always be the case, so the isinstance check above could perhaps be left out, but it
        # doesn't hurt to check.)
        stgdict = unwrap_mappingproxy(stgdict)

    # The StgDict type is not publicly exposed anywhere, so we can't use isinstance. Checking the name is the best
    # we can do here.
    if type(stgdict).__name__ != 'StgDict':
        raise TypeError(
            "The given type's dict must be a StgDict, not {tp.__module__}.{tp.__qualname__}"
            .format(tp=type(stgdict))
        )

    return stgdict


def make_callback_returnable(ctype):
    """Modify the given ctypes type so it can be returned from a callback function.

    This function may be used as a decorator on a struct/union declaration.

    The method is idempotent; it only modifies the type the first time it
    is invoked on a type.
    """
    # The presence of the _rubicon_objc_ctypes_patch_getfunc attribute is a
    # sentinel for whether the type has been modified previously.
    if hasattr(ctype, '_rubicon_objc_ctypes_patch_getfunc'):
        return ctype

    # Extract the StgDict from the ctype.
    stgdict = get_stgdict_of_type(ctype)
    stgdict_c = StgDictObject.from_address(id(stgdict))

    # Ensure that there is no existing getfunc or setfunc on the stgdict.
    if ctypes.cast(stgdict_c.getfunc, ctypes.c_void_p).value is not None:
        raise ValueError("The ctype {}.{} already has a getfunc".format(ctype.__module__, ctype.__name__))
    elif ctypes.cast(stgdict_c.setfunc, ctypes.c_void_p).value is not None:
        raise ValueError("The ctype {}.{} already has a setfunc".format(ctype.__module__, ctype.__name__))

    # Define the getfunc and setfunc.
    @GETFUNC
    def getfunc(ptr, size):
        actual_size = ctypes.sizeof(ctype)
        if size != 0 and size != actual_size:
            raise ValueError(
                "getfunc for ctype {}: Requested size {} does not match actual size {}"
                .format(ctype, size, actual_size)
            )

        return ctype.from_buffer_copy(ctypes.string_at(ptr, actual_size))

    @SETFUNC
    def setfunc(ptr, value, size):
        actual_size = ctypes.sizeof(ctype)
        if size != 0 and size != actual_size:
            raise ValueError(
                "setfunc for ctype {}: Requested size {} does not match actual size {}"
                .format(ctype, size, actual_size)
            )

        ctypes.memmove(ptr, ctypes.addressof(value), actual_size)
        # Because of ctypes bug bpo-36880 (https://bugs.python.org/issue36880), returning None from a callback with
        # restype py_object causes a reference counting error that can crash Python.
        # To work around this bug, the restype of SETFUNC is declared as c_void_p instead.
        # This way ctypes performs no automatic reference counting for the returned object, which avoids the bug.
        # However, this way we have to manually convert the Python object to a pointer and adjust its reference count.
        none_ptr = ctypes.cast(id(None), ctypes.POINTER(PyObject))
        # The return value of a SETFUNC is expected to have an extra reference
        # (which will be owned by the caller of the SETFUNC).
        ctypes.pythonapi.Py_IncRef(none_ptr)
        # The returned pointer must be returned as a plain int, not as a c_void_p,
        # otherwise ctypes won't recognize it and will raise a TypeError.
        return ctypes.cast(none_ptr, ctypes.c_void_p).value

    # Store the getfunc and setfunc as attributes on the ctype, so they don't get garbage-collected.
    ctype._rubicon_objc_ctypes_patch_getfunc = getfunc
    ctype._rubicon_objc_ctypes_patch_setfunc = setfunc
    # Put the getfunc and setfunc into the stgdict fields.
    stgdict_c.getfunc = getfunc
    stgdict_c.setfunc = setfunc

    # Return the passed in ctype, so this function can be used as a decorator.
    return ctype
