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
from pyto import PyOutputHelper
from importlib import util
from importlib.machinery import ExtensionFileLoader, ModuleSpec, PathFinder

NSBundle = ObjCClass("NSBundle")


class __UpgradeException__(Exception):
    pass


if "widget" not in os.environ:
    from sharing import open_url
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



__all__ = ["FrameworksImporter"]
