from pyto import Python, PyOutputHelper, ConsoleViewController, EditorViewController, __Class__
from time import sleep
from console import run_script
from rubicon.objc import ObjCClass, objc_method, NSObject
import threading
import traceback
import stopit
import sys
import os
import ctypes
import gc
import __pyto_ui_garbage_collector__ as _gc

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
<<<<<<< HEAD
        
        try:
            Python.shared.registerThread(self.script_path)
        except AttributeError:
            pass
        
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
        super().run()
        pool.release()
        del pool

threading.Thread = Thread

class PythonImplementation(NSObject):

    @objc_method
    def runScript_(self, script):
        gc.collect()

        for view in _gc.collected:
            view.releaseReference()
            view.release()
            
        _gc.collected = []

<<<<<<< HEAD
        thread = Thread(target=run_script, args=(str(script.path), False, script.debug, script.breakpoints, script.runREPL))
=======
        thread = Thread(target=run_script, args=(str(script.path), False, script.debug, script.breakpoints))
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
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
            Python.shared.tooMuchUsedMemory = False
            exc = MemoryError
        raise_exception(str(script), exc)
        
    
    @objc_method
    def interruptScript_(self, script):
        raise_exception(str(script), KeyboardInterrupt)

Python.pythonShared = PythonImplementation.alloc().init()

Python.shared.handleCrashesForCurrentThread()
