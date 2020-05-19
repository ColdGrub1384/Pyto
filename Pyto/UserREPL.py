"""
The REPL. Goes to the file browser when exited.
"""

from pyto import REPLViewController, PyOutputHelper
from colorama import Fore, Back, Style
import console
import sys
import threading
from types import ModuleType as Module
import rubicon.objc
from json import dumps
import pydoc

__inspected_times__ = {}

def get_variables_hierarchy(object):
    
    global __inspected_times__
    
    vars = {}
    
    def represent(value_):
        
        value = value_
        
        if isinstance(value, Module):
            value = value.__dict__
        
        try:
            repr_value = repr(value)
            __inspected_times__[repr_value] = __inspected_times__.get(repr_value, 0) + 1
            if __inspected_times__[repr_value] > 5:
                    return repr_value
        except Exception as e:
            pass
        
        if isinstance(value, list):
            dictionnary = {}
            for i, value_ in enumerate(value):
                if isinstance(value_, (rubicon.objc.api.ObjCClass, rubicon.objc.api.ObjCInstance)):
                    dictionnary[str(i)] = value
                elif isinstance(value_, (dict, list)):
                    dictionnary[str(i)] = represent(value_.copy())
                elif callable(value_):
                    dictionnary[str(i)] = pydoc.render_doc(value_).splitlines()[2]
                else:
                    dictionnary[str(i)] = repr(value_)
            return dictionnary
                
        elif type(value) is dict:
            
            dictionnary = {}
            for key_, value_ in value.items():
                if isinstance(value_, (rubicon.objc.api.ObjCClass, rubicon.objc.api.ObjCInstance)):
                    dictionnary[repr(key_)] = value_
                elif isinstance(value_, (dict, list)):
                    dictionnary[repr(key_)] = represent(value_.copy())
                elif callable(value_):
                    dictionnary[repr(key)] = pydoc.render_doc(value_).splitlines()[2]
                else:
                    dictionnary[repr(key_)] = repr(value_)
            return dictionnary
        elif isinstance(value, (rubicon.objc.api.ObjCClass, rubicon.objc.api.ObjCInstance)):
            return value
        elif isinstance(value, str) and not value.startswith("'") and not value.endswith("'"):
            return "'"+value+"'"
        else:
            try:
                if callable(value) or isinstance(value, int) or isinstance(value, float):
                    raise AttributeError
                return get_variables_hierarchy(value)
            except AttributeError:
                return repr(value)
    
    isdict = False
    if isinstance(object, dict):
        isdict = True
        module = Module("__inspected__")
        for (key, value) in object.items():
            module.__dict__[repr(key)] = value
        object = module

    for key in dir(object):
    
        if isdict and key in ["__loader__", "__name__", "__spec__", "__package__", "__doc__"]:
            continue
    
        _key = key
        if isdict:
            _key = repr(_key)
        vars[_key] = represent(getattr(object, key))

    __inspected_times__ = {}
    
    return vars


class MyClass:
    
    def __init__(self, a, b):
        self.a = a
        self.b = b

def displayhook(value):
    if value is None:
        return

    json = dumps(get_variables_hierarchy(value))
    try:
        PyOutputHelper.printValue(repr(value)+"\n", value=json, script=threading.current_thread().script_path)
    except AttributeError:
        PyOutputHelper.printValue(repr(value)+"\n", value=json, script=None)

sys.excepthook = console.excepthook
sys.displayhook = displayhook

try:
    console.__runREPL__(__file__.split("/")[-1])
finally:
    del console.__repl_namespace__[__file__.split("/")[-1]]
    REPLViewController.goToFileBrowser()
