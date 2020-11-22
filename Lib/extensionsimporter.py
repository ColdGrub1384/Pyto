"""
Module used internally by Pyto for importing C extension.
"""

import sys
import importlib
import traceback
import os
import warnings

class __UpgradeException__(Exception):
    pass

if "widget" not in os.environ:
    from sharing import open_url
    import urllib.parse
    from pyto import Python, __Class__
    from rubicon.objc import ObjCClass
    from Foundation import NSBundle
    import _extensionsimporter
    import ctypes
    from importlib import util, __import__
    from importlib.machinery import ExtensionFileLoader, ModuleSpec, PathFinder

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

class FrameworkLoader(ExtensionFileLoader):
    
    def __init__(self, fullname, path):
        self.fullname = fullname
        super().__init__(fullname.split(".")[-1], path)

    def create_module(self, spec):
        fullname = self.fullname
        mod = sys.modules.get(fullname)
        if mod is None:
            with warnings.catch_warnings(record=True) as w:
                mod = _extensionsimporter.module_from_binary(fullname, spec)
                sys.modules[fullname] = mod
            return mod

        return mod
    
    def exec_module(self, module):
        pass
        
    def module_repr(self, module):
        return f"<module '{module.__name__}' from '{self.path}'>"

class BuiltinLoader(ExtensionFileLoader):
    
    def __init__(self, fullname, path):
        self.fullname = fullname
        super().__init__(fullname.split(".")[-1], path)

    def create_module(self, spec):
        fullname = self.fullname
        f = "__"+fullname.replace(".", "_")
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
    
        if "__"+fullname.replace(".", "_") in sys.builtin_module_names:
            loader = BuiltinLoader(fullname, None)
            spec = ModuleSpec(fullname, loader)
            return spec
    
        framework_name = fullname.replace(".", "-")+".framework"
        framework_path = str(NSBundle.mainBundle.bundlePath)+"/Frameworks/"+framework_name
        binary_path = None
        
        if not os.path.isdir(framework_path):
            framework_name = (fullname.split(".")[0]+"-")+".framework"
            framework_path = str(NSBundle.mainBundle.bundlePath)+"/Frameworks/"+framework_name
            
        if os.path.isdir(framework_path):
        
            for path in os.listdir(framework_path):
                if path.endswith(".so") or path == framework_name.split(".framework")[0]:
                    path = framework_path+"/"+path
                    binary_path = path

            lib = ctypes.cdll.LoadLibrary(binary_path)
            try:
                getattr(lib, "PyInit_"+fullname.split(".")[-1])
            except AttributeError:
                return None

            loader = FrameworkLoader(fullname, binary_path)
            spec = ModuleSpec(fullname, loader)
            return spec

if "widget" not in os.environ:

    # MARK: - Downloadable Content

    class DownloadableImporter(object):
        """
        Meta path for importing downloadable libraries to be added to `sys.meta_path`.
        """
        
        __is_importing__ = False
        
        def find_module(self, fullname, mpath=None):
            
            if self.__is_importing__:
                return
            
            libname = fullname.split(".")[0]
            if libname in ('imageio', 'networkx', 'dask', 'jmespath', 'joblib', 'smart_open', 'boto', 'boto3', 'botocore', 'pywt', 'bcrypt', 'Bio', 'cryptography',  'cv2', 'gensim', 'lxml', 'matplotlib', 'nacl', 'numpy', 'pandas', 'regex', 'scipy', 'skimage', 'sklearn', 'statsmodels', 'zmq', 'astropy'):
                return self
            
            return
        
        def is_package(self, i_dont_know_what_goes_here):
            return False
        
        def load_module(self, fullname):
            self.__is_importing__ = True
            
            try:
                mod = importlib.__import__(fullname)
                self.__is_importing__ = False
                return mod
            except ModuleNotFoundError:
            
                if not have_internet():
                    msg = f"The internet connection seems to be offline and the imported library {fullname.split('.')[0].lower()} is not downloaded. Make sure you are connected to internet. Once downloaded, the library will be available offline."
                    raise ImportError(msg)
            
                paths = Python.shared.access(fullname.split(".")[0].lower())
                for path in paths:
                    if str(path) == "error":
                        self.__is_importing__ = False
                        
                        if len(paths) == 3 and str(paths[2]) == "upgrade":
                            import threading
                            from pyto import PyOutputHelper
                            
                            try:
                                price = str(Python.shared.environment["UPGRADE_PRICE"])
                            except KeyError:
                                price = "5.99$"
                            
                            try:
                                script_path = threading.current_thread().script_path
                            except AttributeError:
                                script_path = None
                                
                            PyOutputHelper.printLink(f"Upgrade {price}\n", url="pyto://upgrade", script=script_path)
                            
                            raise __UpgradeException__(str(paths[1]))
                        
                        raise ImportError(str(paths[1]))
                    if not str(path) in sys.path:
                        sys.path.insert(0, str(path))
                
                try:
                    return importlib.__import__(fullname)
                finally:
                    self.__is_importing__ = False
            
            self.__is_importing__ = False

    # MARK: - All

    __all__ = ['FrameworksImporter', 'DownloadableImporter']

else:
    
    __all__ = ['FrameworksImporter']
