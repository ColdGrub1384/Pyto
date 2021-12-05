try:
    import sys
    import os
    import zipfile

    sys.path.insert(-1, os.path.expanduser("~/Documents/site-packages"))

    import io
    import console
    import code
    import pyto
    from importlib.machinery import SourceFileLoader
    import importlib
    import threading
    from time import sleep
    from outputredirector import Reader
    from extensionsimporter import *
    import warnings
    import logging
    from _ios_getpass import getpass as _ios_getpass
    import getpass
    import webbrowser
    import sharing
    import _signal
    import traceback
    import unittest
    from pip import BUNDLED_MODULES
    from ctypes import CDLL
    from time import sleep

    # MARK: - Warnings

    logging.basicConfig(level=logging.INFO)

    def __send_warnings_to_log__(message, category, filename, lineno, file=None, line=None):

        import platform
        if platform.uname()[4] == "x86_64":
            return

        try:
            warnings
        except:
            import warnings
        
        try:
            pyto
        except:
            import pyto
        
        _message = warnings.formatwarning(message, category, filename, lineno, line)
        
        if "ImportWarning: DownloadableImporter.find_spec()" in _message or "DeprecationWarning: the load_module() method is deprecated" in _message or "DeprecationWarning: PathFinder.find_module() is deprecated":
            # TODO: Fix those warnings instead of hiding them
            return
        
        try:
            pyto.PyOutputHelper.printWarning(_message, script=threading.current_thread().script_path)
        except AttributeError:
            pyto.PyOutputHelper.printWarning(_message, script=None)
        return

    warnings.showwarning = __send_warnings_to_log__
    warnings.filterwarnings("default")

    # MARK: - Allow / Disallow subprocesses

    os.allows_subprocesses = (not sys.platform == "ios")
    
    # MARK: - Per thread chdir
    
    def chdir(dir):
        CDLL(None).pthread_chdir_np(os.path.realpath(dir).encode())
    
    os.chdir = chdir

    # MARK: - Input

    def askForInput(prompt=None):
        try:
            threading
        except NameError:
            import threading

        try:
            console
        except NameError:
            import console

        if (threading.currentThread() in console.ignoredThreads):
            return ""
        else:
            return console.input(prompt)

    __builtins__.input = askForInput

    getpass.getpass = _ios_getpass

    # MARK: - Output

    def read(text):
        try:
            console
        except NameError:
            import console

        console.print(text, end="")

    def write(txt):

        try:
            os
        except NameError:
            import os
        
        try:
            threading
        except NameError:
            import threading

        if ("widget" not in os.environ) and (threading.currentThread() in console.ignoredThreads):
            return
        
        if txt.__class__ is str:
            read(txt)
        elif txt.__class__ is bytes:
            text = txt.decode()
            write(text)

    standardOutput = Reader(read)
    standardOutput._buffer = io.BufferedWriter(standardOutput)
    standardOutput.buffer.write = write

    standardError = Reader(read)
    standardError._buffer = io.BufferedWriter(standardError)
    standardError.buffer.write = write

    sys.stdout = standardOutput
    sys.stderr = standardError

    # MARK: - Web browser

    class MobileSafari(webbrowser.BaseBrowser):
        '''
        Mobile Safari web browser.
        '''
        
        def open(self, url, new=0, autoraise=True):
            sharing.open_url(url)
            return True

    webbrowser.register("mobile-safari", None, MobileSafari("MobileSafari.app"))

    # MARK: - Modules

    sys.meta_path.insert(0, DownloadableImporter())
    sys.meta_path.insert(1, FrameworksImporter())

    # MARK: - Pre-import modules

    def importModules():

        try:
            import PIL.ImageShow

            def show_image(image, title=None, **options):
                import os
                import tempfile
                import sharing
                import _opencv_view as ocv
                
                if title == "OpenCV":
                    ocv.show(image)
                else:

                    imgPath = tempfile.gettempdir()+"/image.png"

                    i = 1
                    while os.path.isfile(imgPath):
                        i += 1
                        imgPath = os.path.join(tempfile.gettempdir(), 'image '+str(i)+'.png')
            
                    image.save(imgPath, "PNG")
                    
                    sharing.quick_look(imgPath)

            PIL.ImageShow.show = show_image
        
        except:
            pass

    importModules()

    def addOnDemandPaths():
        paths = pyto.Python.shared.accessibleOnDemandPaths
        for path in paths:
            sys.path.append(str(path))

    threading.Thread(target=addOnDemandPaths).start()

    # MARK: - Sys
    
    class Sys(sys.__class__):
    
        instances = {}
    
        def __init__(self, sys):
            self.sys = sys
        
        def __dir__(self):
            return dir(self.sys)
        
        def setup_properties_if_needed(self, script_path):
            if not script_path in self.__class__.instances:
                path = []
                for location in self.sys.path:
                    path.append(location)
                self.__class__.instances[script_path] = { "path": path, "argv": [] }
        
        def __setattr__(self, attr, value):
            if attr == "sys":
                super().__setattr__(attr, value)
            else:
                thread = threading.current_thread()
        
                if "script_path" in dir(thread):
        
                    self.setup_properties_if_needed(thread.script_path)
        
                    if attr in self.__class__.instances[thread.script_path]:
                        self.__class__.instances[thread.script_path][attr] = value
                        return
            
                setattr(self.sys, attr, value)
        
        def __getattr__(self, attr):
            thread = threading.current_thread()
    
            if "script_path" in dir(thread):
    
                self.setup_properties_if_needed(thread.script_path)
    
                if attr in self.__class__.instances[thread.script_path]:
                    return self.__class__.instances[thread.script_path][attr]
                        
        
            return getattr(self.sys, attr)

    sys.modules["sys"] = Sys(sys)

    # MARK: - Pip bundled modules
    
    # Add modules to `bundled`. I add it one by one because for some reason setting directly an array fails **sometimes**. Seems like something new in iOS 13.5 but I'm not sure.
    for module in BUNDLED_MODULES:
        pyto.PipViewController.addBundledModule(module)


    # MARK: - OS

    def fork():
        pass

    def waitpid(pid, options):
        return (-1, 0)

    os.fork = fork
    os.waitpid = waitpid
    os._exit = sys.exit        

    # MARK: - Handle signal called outside main thread

    old_signal = _signal.signal
    def signal(signal, handler):
        try:
            threading
        except NameError:
            import threading
        
        if threading.main_thread() == threading.current_thread():
            return old_signal(signal, handler)
        else:
            return None
    _signal.signal = signal

    # MARK: - Plugin

    __builtins__.__editor_delegate__ = None

    # MARK: - Unittest

    _original_unittest_main = unittest.main
    def _unittest_main(module='__main__', defaultTest=None, argv=None, testRunner=None, testLoader=unittest.defaultTestLoader, exit=True, verbosity=1, failfast=None, catchbreak=None, buffer=None, warnings=None):

        _module = module
        
        if module == "__main__":
            thread = threading.current_thread()

            try:
                path = thread.script_path
                _module = path.split("/")[-1]
                _module = os.path.splitext(_module)[0]
            except AttributeError:
                pass

        _original_unittest_main(_module, defaultTest, argv, testRunner, testLoader, exit, verbosity, failfast, catchbreak, buffer, warnings)

    unittest.main = _unittest_main

    # MARK: - Run script
        
    def run():
        SourceFileLoader("main", "%@").load_module()
        sleep(0.5)
        CDLL(None).putenv(b"IS_PYTHON_RUNNING=1")

    threading.Thread(target=run).start()

    threading.Event().wait()

except Exception as e:
    import traceback
    from ctypes import CDLL
    
    s = traceback.format_exc()
    
    CDLL(None).logToNSLog(s.encode())
    CDLL(None).logToNSLog(str(e).encode())
