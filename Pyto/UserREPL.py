"""
The REPL. Goes to the file browser when exited.
"""

from pyto import REPLViewController, PyOutputHelper
from colorama import Fore, Back, Style
import console
import sys
import threading
from json import dumps
from collections.abc import Mapping
from types import ModuleType as Module

def displayhook(_value):
    if _value is None:
        return
        
    def represent(value):
        if hasattr(value, "__dict__"):
            val = {}

            _dict = dict(value.__class__.__dict__)
            _dict.update(dict(value.__dict__))
            for key in _dict:
                item = _dict[key]
                if item is value or (not isinstance(item, dict) and not isinstance(item, list)):
                    item = repr(item)
                else:
                    item = represent(item)
                val[key] = item
        elif isinstance(value, Mapping):
            val = {}
            _dict = value
            for key in _dict:
                item = _dict[key]
                if item is value or (not isinstance(item, dict) and not isinstance(item, list)):
                    item = repr(item)
                else:
                    item = represent(item)
                val[repr(key)] = item
        elif isinstance(value, list):
            val = {}
            i = 0
            for item in value:
                _item = item
                if item is value or (not isinstance(item, dict) and not isinstance(item, list)):
                    _item = repr(item)
                
                val[str(i)] = represent(_item)
                i += 1
        else:
            val = repr(value)
            
        return val

    if isinstance(_value, Mapping) or isinstance(_value, list) or hasattr(_value, "__dict__"):
        val = represent(_value)
    else:
        print(_value)
        val = represent([_value])
    
    def default(o):
        return repr(o)
    
    json = dumps(val, default=default)
    try:
        PyOutputHelper.printValue(repr(_value)+"\n", value=json, script=threading.current_thread().script_path)
    except AttributeError:
        PyOutputHelper.printValue(repr(_value)+"\n", value=json, script=None)

sys.excepthook = console.excepthook
sys.displayhook = displayhook

try:
    console.__runREPL__(__file__.split("/")[-1])
finally:
    del console.__repl_namespace__[__file__.split("/")[-1]]
    REPLViewController.goToFileBrowser()

