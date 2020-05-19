"""
The REPL. Goes to the file browser when exited.
"""

from pyto import REPLViewController, PyOutputHelper
from colorama import Fore, Back, Style
import console
import sys
import threading
from types import ModuleType as Module
from json import dumps

def displayhook(value):
    if value is None:
        return

    if isinstance(value, Module):
        val = value.__dict__
    else:
        val = value

    def default(o):
        return repr(o)

    json = dumps(val, default=default)
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
