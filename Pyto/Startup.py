try:
    import sys
    import os
    import zipfile

    zippedLib = os.environ["ZIPPEDLIB"]
    destDir = os.path.expanduser("~/Library/python38")

    if not os.path.isdir(destDir):
        with zipfile.ZipFile(zippedLib, "r") as zip_ref:
            zip_ref.extractall(destDir)

    sys.path.insert(-1, os.path.expanduser("~/Documents"))
    sys.path.insert(-1, os.path.expanduser("~/Documents/site-packages"))

    try:
        os.remove(destDir+"/turtle.py")
    except:
        pass
        
    try:
        os.remove(destDir+"/pydoc.py")
    except:
        pass

    try:
        os.remove(destDir+"/pdb.py")
    except:
        pass

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
        try:
            pyto.PyOutputHelper.printWarning(_message, script=threading.current_thread().script_path)
        except AttributeError:
            pyto.PyOutputHelper.printWarning(_message, script=None)
        return

    warnings.showwarning = __send_warnings_to_log__

    # MARK: - Allow / Disallow subprocesses

    os.allows_subprocesses = (not sys.platform == "ios")

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

    for importer in (NumpyImporter, MatplotlibImporter, PandasImporter, PillowImporter, BiopythonImporter, LXMLImporter, ScipyImporter, SkLearnImporter, SkImageImporter, PywtImporter, NaclImporter, CryptographyImporter, BcryptImporter, StatsmodelsImporter, ZmqImporter, RegexImporter, GensimImporter, AstropyImporter):
        sys.meta_path.insert(0, importer())

    sys.meta_path.insert(0, DownloadableImporter()) # Needs to be first

    # MARK: - Pre-import modules

    def importModules():

        try:
            import PIL.ImageShow

            def show_image(image, title=None, **options):
                import os
                import tempfile
                import sharing
        
                imgPath = tempfile.gettempdir()+"/image.png"

                i = 1
                while os.path.isfile(imgPath):
                    i += 1
                    imgPath = os.path.join(tempfile.gettempdir(), 'image '+str(i)+'.png')
        
                image.save(imgPath, "PNG")
                
                if title == "OpenCV":
                    sharing.quick_look(imgPath, remove_previous=True)
                else:
                    sharing.quick_look(imgPath)

            PIL.ImageShow.show = show_image
        
        except:
            pass

    threading.Thread(target=importModules).start()

    def addOnDemandPaths():
        paths = pyto.Python.shared.accessibleOnDemandPaths
        for path in paths:
            sys.path.append(str(path))

    threading.Thread(target=addOnDemandPaths).start()

    # MARK: - Create a Selector without class.

    __builtins__.Selector = pyto.PySelector.makeSelector
    __builtins__.Target = pyto.SelectorTarget.shared

    # MARK: - Deprecations

    __builtins__.deprecated = []

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

    try:
        def run():

            pyto.Python.shared.isSetup = True
            
            SourceFileLoader("main", "%@").load_module()

        threading.Thread(target=run).start()
    except Exception as e:
        print(e)

    while True:
        sleep(5)

except Exception as e:
    import traceback
    s = traceback.format_exc()
    
    from ctypes import CDLL
    CDLL(None).logToNSLog(s.encode())
    CDLL(None).logToNSLog(str(e).encode())
