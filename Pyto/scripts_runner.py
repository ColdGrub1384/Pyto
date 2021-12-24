from pyto import Python, PyOutputHelper, ConsoleViewController, EditorViewController, __Class__, ignored_threads_on_crash
from time import sleep
from console import run_script
from rubicon.objc import ObjCClass, objc_method, NSObject, SEL
import threading
import traceback
import stopit
import sys
import os
import ctypes
import gc
import random
import string
import __pyto_ui_garbage_collector__ as _gc
import extensionsimporter

c = ctypes.CDLL(None)

def raise_exception(script, exception):
    for tid, tobj in threading._active.items():
        try:
            if tobj.script_path == script:
                stopit.async_raise(tid, exception)
                break
        except:
            continue

NSAutoreleasePool = ObjCClass("NSAutoreleasePool")
NSThread = ObjCClass("NSThread")

class Thread(threading.Thread):

    # Pass the 'script_path' attribute
    def start(self):
        if "script_path" not in dir(self):
            try:
                self.script_path = threading.current_thread().script_path
            except AttributeError:
                pass
        
        super().start()

    def run(self):
        pool = NSAutoreleasePool.alloc().init()
        Python.shared.handleCrashesForCurrentThread()
        
        try:
            Python.shared.registerThread(self.script_path)
        except AttributeError:
            pass
        
        super().run()
        pool.release()
        del pool

def release_views(views):
    for view in views:
        if view.respondsToSelector(SEL("releaseReference")):
            try:
                view.releaseReference()
                view.release()
            except ValueError:
                pass

class PythonImplementation(NSObject):

    @objc_method
    def runScript_(self, script):

        gc.collect()

        release_thread = Thread(target=release_views, args=(_gc.collected,))
        ignored_threads_on_crash.append(release_thread)
        release_thread.start()
            
        _gc.collected = []

        args = []
        try:
            py_args = list(script.args)
        except TypeError as e:
            py_args = []

        for arg in py_args:
            args.append(str(arg))
        
        if args == [""]:
            args = []
        
        cwd = str(script.workingDirectory)

        if str(script.path) in sys.__class__.instances:
            del sys.__class__.instances[str(script.path)]

        thread = Thread(target=run_script, args=(str(script.path), False, script.debug, str(script.breakpoints), script.runREPL, args, cwd))
        try:
            thread.script_path = str(script.pagePath)
        except AttributeError:
            thread.script_path = str(script.path)
        thread.start()
    
    @objc_method
    def runCode_(self, code):
        Python.shared.handleCrashesForCurrentThread()
        try:
            exec(str(code))
        except:
            error = traceback.format_exc()
            PyOutputHelper.printError(error, script=None)
            Python.shared.codeToRun = None
    
    @objc_method
    def exitScript_(self, script):
        exc = SystemExit
        if Python.shared.tooMuchUsedMemory:
            exc = MemoryError
        raise_exception(str(script), exc)
        
    
    @objc_method
    def interruptScript_(self, script):
        raise_exception(str(script), KeyboardInterrupt)
        
    
    @objc_method
    def getScriptPath(self):
        try:
            return threading.current_thread().script_path
        except AttributeError:
            return
            
    
    @objc_method
    def getString_(self, code):
        try:
            loc = {}
            exec(str(code), globals(), loc)
            return loc["s"]
        except Exception as e:
            print(e)
            return


threading.Thread = Thread

Python.pythonShared = PythonImplementation.alloc().init()

Python.shared.handleCrashesForCurrentThread()
