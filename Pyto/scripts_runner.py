from pyto import Python, PyOutputHelper, ConsoleViewController
from time import sleep
from console import run_script
import threading
import traceback
import stopit

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
    
    try:
        code = str(Python.shared.codeToRun)
        exec(code)
        if code == Python.shared.codeToRun:
            Python.shared.codeToRun = None
    except:
        error = traceback.format_exc()
        PyOutputHelper.printError(error, script=None)
        Python.shared.codeToRun = None
    
    if Python.shared.scriptToRun != None:
        
        script = Python.shared.scriptToRun
        
        thread = ScriptThread(target=run_script, args=(str(script.path), False, script.debug, script.breakpoints))
        thread.script_path = str(script.path)
        thread.start()
        
        Python.shared.scriptToRun = None
    
    for script in Python.shared.scriptsToExit:
        raise_exception(str(script), SystemExit)
    if Python.shared.scriptsToExit.count != 0:
        Python.shared.scriptsToExit = []
        
    for script in Python.shared.scriptsToInterrupt:
        raise_exception(str(script), KeyboardInterrupt)
    if Python.shared.scriptsToInterrupt.count != 0:
        Python.shared.scriptsToInterrupt = []

    if ConsoleViewController.isPresentingView:
        sleep(0.02)
    else:
        sleep(0.2)
