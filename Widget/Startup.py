import os
import sys
import builtins
import traceback
from pyto import __Class__, Python
from time import sleep

os.environ["widget"] = "1"

PyWidget = __Class__("PyWidget")

while True:

    for code in PyWidget.codeToRun:
        try:
            exec(str(code[0]))
            PyWidget.removeWidgetID(code[1])
        except Exception as e:
            PyWidget.breakpoint(traceback.format_exc())
            print(e)
    
    PyWidget.codeToRun = []
 
    try: # Run code
        code = str(Python.shared.codeToRun)
        exec(code)
        if code == Python.shared.codeToRun:
            Python.shared.codeToRun = None
    except:
        pass

    try:
        del sys.modules["pyto_ui"]
    except KeyError:
        pass
    
    try:
        _values = sys.modules["_values"]
         
        for attr in dir(_values):
            if attr not in _values._dir:
                delattr(_values, attr)
    except:
        pass

    sleep(0.2)
