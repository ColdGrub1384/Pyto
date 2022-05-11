"""
Module used internally by Pyto for importing C extension.
"""

import sys
import importlib
import traceback
import os
import warnings
from rubicon.objc import ObjCClass
import _extensionsimporter
import ctypes
import threading
import weakref
import gc
from pyto import PyOutputHelper
from importlib import util
from importlib.machinery import ExtensionFileLoader, ModuleSpec, PathFinder
from types import BuiltinFunctionType
from inspect import isclass
from time import sleep

NSBundle = ObjCClass("NSBundle")


class __UpgradeException__(Exception):
    pass


if "widget" not in os.environ:
    from _sharing import open_url
    import urllib.parse
    from pyto import Python, __Class__

    def have_internet():
        return __Class__("InternetConnection").isReachable

    def update_mods():
        # Builtins
        def add(mod):
            if str(mod) in sys.builtin_module_names:
                return

            sys.builtin_module_names += (str(mod),)
            Python.shared.importedModules.addObject(mod)

        try:
            for mod in Python.shared.modules:
                add(mod)
        except TypeError:
            for mod in Python.shared.modules():
                add(mod)


_added_modules = []

class Extension:

    def __init__(self, module):
        self.__original_module__ = module
    
    def __repr__(self):
        return self.__original_module__.__repr__() # __repr__() isn't called for modules

    def __getattribute__(self, attr):
        if attr == "__original_module__" or attr == "__repr__":
            return super().__getattribute__(attr)
        else:
            return getattr(self.__original_module__, attr)

    def __setattr__(self, attr, value):
        if attr == "__original_module__":
            super().__setattr__(attr, value)
        else:
            setattr(self.__original_module__, attr, value)


class FrameworkLoader(ExtensionFileLoader):
    def __init__(self, fullname, path):
        self.fullname = fullname
        super().__init__(fullname.split(".")[-1], path)

    def create_module(self, spec):
        fullname = self.fullname
        mod = sys.modules.get(fullname)
        if mod is None:
            with warnings.catch_warnings(record=True) as w:
                try:
                    mod = _extensionsimporter.module_from_binary(fullname, spec)
                except ImportError:
                    try:
                        price = str(Python.shared.environment["UPGRADE_PRICE"])
                    except KeyError:
                        price = "5.99$"

                    try:
                        script_path = threading.current_thread().script_path
                    except AttributeError:
                        script_path = None

                    PyOutputHelper.printLink(
                        f"Upgrade to import C extensions {price}\n",
                        url="pyto://upgrade",
                        script=script_path,
                    )

                    raise __UpgradeException__()

                mod.__repr__ = self.mod_repr
                mod = Extension(mod)
                sys.modules[fullname] = mod
            return mod

        mod.__repr__ = self.mod_repr
        return mod

    def exec_module(self, module):
        pass

    def mod_repr(self):
        return f"<module '{self.fullname}' from '{self.path}'>"


class BuiltinLoader(ExtensionFileLoader):
    def __init__(self, fullname, path):
        self.fullname = fullname
        super().__init__(fullname.split(".")[-1], path)

    def create_module(self, spec):
        fullname = self.fullname
        f = "__" + fullname.replace(".", "_")
        mod = sys.modules.get(f)
        if mod is None:
            with warnings.catch_warnings(record=True) as w:
                mod = __import__(f)
                sys.modules[fullname] = mod
            return mod

        return mod

    def exec_module(self, module):
        pass

    def module_repr(self, module):
        return f"<module '{module.__name__}' (built-in)>"

def check_name(name, suffix, compare_with):
    if not name.endswith(suffix):
        return False
    
    return (name.split(suffix)[0] == compare_with)


def find_extension(path, name):
    try:
        content = os.listdir(path)
    except Exception as e:
        return None

    for file in content:
        if check_name(file, ".cpython-310-darwin.so", name) or check_name(file, ".abi3.so", name):
            return os.path.join(path, file)


try:

    # llvm_call_function
    llvm_call_function = ctypes.CDLL(None).llvm_call_function
    llvm_call_function.argtypes = [
        ctypes.c_char_p, ctypes.py_object, ctypes.c_bool, ctypes.py_object, ctypes.py_object, ctypes.py_object,
        ctypes.py_object, ctypes.py_object, ctypes.py_object,
    ]
    llvm_call_function.restype = ctypes.py_object

    # llvm_create_instance
    llvm_create_instance = ctypes.CDLL(None).llvm_create_instance
    llvm_create_instance.argtypes = [
        ctypes.py_object, ctypes.py_object, ctypes.py_object, ctypes.py_object,
        ctypes.py_object, ctypes.py_object, ctypes.py_object
    ]
    llvm_create_instance.restype = ctypes.py_object

    # llvm_call_getter
    llvm_call_getter = ctypes.CDLL(None).llvm_call_getter
    llvm_call_getter.argtypes = [
        ctypes.py_object, ctypes.py_object, ctypes.py_object, ctypes.c_char_p
    ]
    llvm_call_getter.restype = ctypes.py_object

    # llvm_call_setter
    llvm_call_setter = ctypes.CDLL(None).llvm_call_setter
    llvm_call_setter.argtypes = [
        ctypes.py_object, ctypes.py_object, ctypes.py_object, ctypes.c_char_p, ctypes.py_object
    ]
    llvm_call_setter.restype = ctypes.py_object

    # llvm_has_getter
    llvm_has_getter = ctypes.CDLL(None).llvm_has_getter
    llvm_has_getter.argtypes = [
        ctypes.py_object, ctypes.c_char_p
    ]
    llvm_has_getter.restype = ctypes.c_bool

    # llvm_has_setter
    llvm_has_setter = ctypes.CDLL(None).llvm_has_setter
    llvm_has_setter.argtypes = [
        ctypes.py_object, ctypes.c_char_p
    ]
    llvm_has_setter.restype = ctypes.c_bool

    # llvm_has_getattr
    llvm_has_getattr = ctypes.CDLL(None).llvm_has_getattr
    llvm_has_getattr.argtypes = [
        ctypes.py_object
    ]
    llvm_has_getattr.restype = ctypes.c_bool

    # llvm_has_setattr
    llvm_has_setattr = ctypes.CDLL(None).llvm_has_setattr
    llvm_has_setattr.argtypes = [
        ctypes.py_object
    ]
    llvm_has_setattr.restype = ctypes.c_bool

    # llvm_call_getattro
    llvm_call_getattro = ctypes.CDLL(None).llvm_call_getattro
    llvm_call_getattro.argtypes = [
        ctypes.py_object, ctypes.py_object, ctypes.py_object, ctypes.py_object
    ]
    llvm_call_getattro.restype = ctypes.py_object

    # void llvm_call_setattro(PyObject *cls, PyObject *__self, PyObject *module, PyObject *name, PyObject *value)
    llvm_call_setattro = ctypes.CDLL(None).llvm_call_setattro
    llvm_call_setattro.argtypes = [
        ctypes.py_object, ctypes.py_object, ctypes.py_object, ctypes.py_object, ctypes.py_object
    ]
    llvm_call_setattro.restype = None

    # llvm_is_cfunction
    llvm_is_cfunction = ctypes.CDLL(None).llvm_is_cfunction
    llvm_is_cfunction.argtypes = [ctypes.py_object]
    llvm_is_cfunction.restype = ctypes.c_bool

    # llvm_delete_module
    llvm_delete_module = ctypes.CDLL(None).llvm_delete_module
    llvm_delete_module.argtypes = [ctypes.py_object]
    llvm_delete_module.restype = ctypes.c_void_p

    # llvm_free_objects
    llvm_free_objects = ctypes.CDLL(None).llvm_free_objects
    llvm_free_objects.restype = ctypes.c_void_p

except AttributeError:
    pass

def object_to_bitcode_value(obj, module=None, attribute_name=None):
    if obj is None:
        return None
    elif llvm_is_cfunction(obj):
        return BitcodeFunction(obj, module, name=attribute_name)
    elif type(obj).__name__ == "cython_function_or_method":
        return BitcodeCythonFunction(obj, module, name=attribute_name)
    elif isclass(obj) and module is not None and obj.__module__ == module.__name__:
        cls = BitcodeClass(obj.__name__, (BitcodeClass,), {})
        cls.__bitcode_pointer__ = obj
        cls.__llvm_module__ = module
        return cls
    elif isinstance(obj, int) or isinstance(obj, float) or isinstance(obj, str) or isinstance(obj, bool) or isinstance(obj, list) or isinstance(obj, dict) or callable(obj):
        return obj
    else:
        return BitcodeValue(obj, module)


cext_references = []

running_modules = []

def store_reference(obj, bitcode_obj):
    if not isinstance(bitcode_obj, (
        type(None),
        str,
        int,
        list,
        dict,
        bool
    )) and not isclass(bitcode_obj):
        try:
            cext_references.append(obj)
        except TypeError:
            pass

def free_cext_objects():
    global cext_references

    free = []
    for obj in list(cext_references):
        if sys.getrefcount(obj()) <= 3:
            free.append(weakref.ref(obj))
            cext_references.remove(obj)
    
    cext_references = []

    module = None
    for mod in list(running_modules):
        if mod() is not None:
            module = mod()
            break
        else:
            running_modules.remove(mod)

    arr = (ctypes.py_object * len(free))(*free)
    llvm_free_objects.argtypes = [type(arr), ctypes.c_size_t, ctypes.py_object]
    llvm_free_objects(arr, len(free)-1, module)


class BitcodeValue:

    def __init__(self, pointer=None, module=None, _dict=None):
        # _dict is there so the initializer of 'BitcodeClass' works

        self.__bitcode_pointer__ = pointer
        if module is None:
            self.__llvm_module__ = pointer
        else:
            self.__llvm_module__ = module

    def __supports_custom_gettattro_setattro__(self):
        return True

    def __returns_pointer_attributes__(self=None):
        return True

    def __repr__(self):
        func = BitcodeFunction(self.__bitcode_pointer_repr__, self.__llvm_module__)
        _repr = f"<bitcode-value {func()}>"
        return _repr

    def __call__(self, *args, **kwargs):
        return BitcodeFunction(self.__bitcode_pointer__, self.__llvm_module__)(*args, **kwargs)

    def __instancecheck__(cls, obj):
        if isinstance(obj, BitcodeValue):
            return isinstance(obj.__bitcode_pointer__, cls.__bitcode_pointer__)
        else:
            return isinstance(obj, cls.__bitcode_pointer__)

    def __getattribute__(self, name):

        if name != "__doc__" and name != "__returns_pointer_attributes__" and not self.__returns_pointer_attributes__():
            return super().__getattribute__(name)

        if name == "__dict__":
            return {}

        if name in ["__bitcode_pointer__", "__repr__", "__del__", "__setattr__", "__llvm_module__", "__call__", "__instancecheck__", "__class__", "__annotations__", "__supports_custom_gettattro_setattro__", "__returns_pointer_attributes__", "__doc__", "__attribute_name__"]:
            try:
                return super().__getattribute__(name)
            except TypeError:
                return super().__getattribute__(self, name)

        if name == "__bitcode_pointer_repr__":
            name = "__repr__"

        ret = None
        if llvm_has_getter(type(self.__bitcode_pointer__), name.encode("utf-8")):
            ret = llvm_call_getter(type(self.__bitcode_pointer__), self, self.__llvm_module__, name.encode("utf-8"))
            _extensionsimporter.raise_exception_if_needed()
            sleep(0.25)
        elif llvm_has_getattr(type(self.__bitcode_pointer__)) and self.__supports_custom_gettattro_setattro__():
            ret = llvm_call_getattro(type(self.__bitcode_pointer__), self, self.__llvm_module__, name)
            _extensionsimporter.raise_exception_if_needed()
            sleep(0.25)
        else:
            ret = getattr(self.__bitcode_pointer__, name)
            _extensionsimporter.raise_exception_if_needed()

        obj = object_to_bitcode_value(ret, self.__llvm_module__, name)
        store_reference(ret, obj)
        return obj
    
    def __setattr__(self, name, value):
        if name in ["__bitcode_pointer__", "__llvm_module__", "__attribute_name__"]:
            try:
                return super().__setattr__(name, value)
            except TypeError:
                return super().__setattr__(self, name, value)

        if llvm_has_setter(type(self.__bitcode_pointer__), name.encode("utf-8")):
            llvm_call_setter(type(self.__bitcode_pointer__), self, self.__llvm_module__, name.encode("utf-8"), value)
            _extensionsimporter.raise_exception_if_needed()
            sleep(0.25)
            return
        
        if llvm_has_setattr(type(self.__bitcode_pointer__)) and self.__supports_custom_gettattro_setattro__():
            llvm_call_setattro(type(self.__bitcode_pointer__), self, self.__llvm_module__, name, value)
            _extensionsimporter.raise_exception_if_needed()
            sleep(0.25)
            return

        if llvm_has_setattr(type(self.__bitcode_pointer__)) and self.__supports_custom_gettattro_setattro__():
            pass

        if isinstance(value, BitcodeValue):
            setattr(self.__bitcode_pointer__, name, value.__bitcode_pointer__)
        else:
            setattr(self.__bitcode_pointer__, name, value)
    
    def __del__(self):
        pass


class BitcodeClass(BitcodeValue, type):

    def __instancecheck__(cls, obj):
        if isinstance(obj, BitcodeValue):
            return isinstance(obj.__bitcode_pointer__, cls.__bitcode_pointer__)
        else:
            return isinstance(obj, cls.__bitcode_pointer__)

    def __repr__(self):
        return f"<bitcode-class {repr(self.__bitcode_pointer__.__name__)}>"

    def __call__(self, *args, **kwargs):

        kwnames = tuple(kwargs.keys())
        all_args = tuple(kwargs.values())
        if len(args) > 0:
            first = args[0]
        else:
            first = None

        obj = llvm_create_instance(self.__bitcode_pointer__, self.__llvm_module__, args, kwargs, first, all_args, kwnames)
        _extensionsimporter.raise_exception_if_needed()
        
        bitcode = BitcodeValue(obj, self.__llvm_module__)
        store_reference(obj, bitcode)
        sleep(0.25)
        return bitcode
    
    def __del__(self):
        pass


class BitcodeFunction(BitcodeValue):

    def __init__(self, function, module, name=None):
        self.__bitcode_pointer__ = function
        self.__llvm_module__ = module
        if name is None:
            self.__attribute_name__ = self.__bitcode_pointer__.__name__
        else:
            self.__attribute_name__ = name
    
    def __returns_pointer_attributes__(self=None):
        return False

    def __repr__(self):
        return f"<bitcode-function {repr(self.__attribute_name__)}>"
    
    def __call__(self, *args, **kwargs):
        name = self.__bitcode_pointer__.__name__
        if llvm_is_cfunction(self.__bitcode_pointer__) or self.__class__ is BitcodeCythonFunction:
            kwnames = tuple(kwargs.keys())
            all_args = tuple(kwargs.values())
            if len(args) > 0:
                first = args[0]
            else:
                first = None

            encoded_name = name.encode("utf-8")
            ret = llvm_call_function(encoded_name, self.__bitcode_pointer__, (self.__class__ is BitcodeCythonFunction), self.__llvm_module__, args, kwargs, first, all_args, kwnames)
            _extensionsimporter.raise_exception_if_needed()
            sleep(0.5)
        else:
            ret = self.__bitcode_pointer__(*args, **kwargs)
        return object_to_bitcode_value(ret, self.__llvm_module__)


class BitcodeCythonFunction(BitcodeFunction):

     def __repr__(self):
        return f"<bitcode-cython-function {repr(self.__attribute_name__)}>"


class BitcodeModule(BitcodeValue):
    
    def __repr__(self):
        return f"<bitcode-module {repr(self.__name__)} from {repr(self.__file__)}>"
    
    def __del__(self):        
        for mod in list(running_modules):
            if mod() is self.__bitcode_pointer__:
                running_modules.remove(mod)

        llvm_delete_module(self.__bitcode_pointer__)

    def __supports_custom_gettattro_setattro__(self):
        return False


class BitcodeLoader(ExtensionFileLoader):

    def __init__(self, fullname, path):
        self.fullname = fullname
        self.path = path
        super().__init__(fullname.split(".")[-1], path)

    def create_module(self, spec):
        if self.fullname in sys.modules:
            return sys.modules[self.fullname]

        __import__("Cython.Compiler.FlowControl")

        with warnings.catch_warnings():
            warnings.filterwarnings(
                action='ignore',
                category=RuntimeWarning,
            )
            mod = _extensionsimporter.module_from_bitcode(self.path, spec)
        
        if mod is None:
            raise RuntimeError("'{}' is not a valid module.".format(self.fullname))
        running_modules.append(weakref.ref(mod))
        mod = BitcodeModule(mod)
        sys.modules[self.fullname] = mod
        return mod

    def exec_module(self, module):
        pass


class BitcodeImporter(PathFinder):
    """
    Meta path for importing LLVM bitcode to be added to `sys.meta_path`.
    """

    __is_importing__ = False

    def find_spec(self, fullname, path=None, target=None):

        if path is not None and len(path) > 0:
            name = fullname.split(".")[-1]
            file = find_extension(path[0], name)
            if file is not None:
                loader = BitcodeLoader(fullname, file)
                spec = ModuleSpec(fullname, loader)
                return spec

        _sys = __import__("sys")
        for path in _sys.path:
            file = find_extension(path, fullname)
            if file is not None:
                loader = BitcodeLoader(fullname, file)
                spec = ModuleSpec(fullname, loader)
                return spec


class FrameworksImporter(PathFinder):
    """
    Meta path for importing frameworks to be added to `sys.meta_path`.
    """

    __is_importing__ = False

    def find_spec(self, fullname, path=None, target=None):
        if "__" + fullname.replace(".", "_") in sys.builtin_module_names:
            loader = BuiltinLoader(fullname, None)
            spec = ModuleSpec(fullname, loader)
            return spec

        frameworks_path = str(NSBundle.mainBundle.privateFrameworksPath)
        if "widget" in os.environ:
            frameworks_path += "/../../../Frameworks"

        framework_name = fullname.replace(".", "-") + ".framework"
        framework_path = (
            frameworks_path + "/" + framework_name
        )
        binary_path = None

        found = True

        if not os.path.isdir(framework_path):
            not_found = False
            framework_name = (fullname.split(".")[0] + "-") + ".framework"
            framework_path = (
                            frameworks_path + "/" + framework_name
            )
        if os.path.isdir(framework_path):

            for path in os.listdir(framework_path):
                if (
                    path.endswith(".so")
                    or path == framework_name.split(".framework")[0]
                ):
                    path = framework_path + "/" + path
                    binary_path = path

            if not found:
                lib = ctypes.cdll.LoadLibrary(binary_path)
                try:
                    getattr(lib, "PyInit_" + fullname.split(".")[-1])
                except AttributeError:
                    return None

            loader = FrameworkLoader(fullname, binary_path)
            spec = ModuleSpec(fullname, loader)
            return spec



__all__ = ["FrameworksImporter", "BitcodeImporter"]
