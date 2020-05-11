from pyto import Python, PyOutputHelper, ConsoleViewController
from time import sleep
from console import run_script
import threading
import traceback
import stopit
import sys
import os

def raise_exception(script, exception):
    for tid, tobj in threading._active.items():
        try:
            if tobj.script_path == script:
                stopit.async_raise(tid, exception)
                break
        except:
            continue

class ScriptThread(threading.Thread):
    """
    A thread running a script.
    """
    
    script_path = None
    """
    The script that the thread is running.
    """

while True:
    
    try: # Run code
        code = str(Python.shared.codeToRun)
        exec(code)
        if code == Python.shared.codeToRun:
            Python.shared.codeToRun = None
    except:
        error = traceback.format_exc()
        PyOutputHelper.printError(error, script=None)
        Python.shared.codeToRun = None
    
    if Python.shared.scriptToRun is not None: # Run Script
        
        script = Python.shared.scriptToRun
        
        thread = ScriptThread(target=run_script, args=(str(script.path), False, script.debug, script.breakpoints))
        thread.script_path = str(script.path)
        thread.start()
        
        Python.shared.scriptToRun = None
    
    sys.stdout.write("")
    
    exc = SystemExit
    if Python.shared.tooMuchUsedMemory:
        Python.shared.tooMuchUsedMemory = False
        exc = MemoryError

    for script in Python.shared.scriptsToExit: # Send SystemExit or MemoryError
        raise_exception(str(script), exc)
    
    if Python.shared.scriptsToExit.count != 0:
        Python.shared.scriptsToExit = []
        
    for script in Python.shared.scriptsToInterrupt: # Send KeyboardInterrupt
        raise_exception(str(script), KeyboardInterrupt)
    if Python.shared.scriptsToInterrupt.count != 0:
        Python.shared.scriptsToInterrupt = []

    # Builtins
    for mod in Python.shared.modules:
        if str(mod) in sys.builtin_module_names:
            continue
        
        sys.builtin_module_names += (str(mod),)
        Python.shared.importedModules.addObject(mod)
        
    if ConsoleViewController.isPresentingView:
        sleep(0.002)
    else:
        sleep(0.2)
