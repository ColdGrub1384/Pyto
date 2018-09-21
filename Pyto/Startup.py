import sys as __sys__
import os as __os__

__sys__.path.insert(0, __os__.path.expanduser("~/Library/pylib/site-packages"))
__sys__.path.insert(0, __os__.path.expanduser("~/Documents"))

import console as __Pyto__
import code as __code__
import PytoClasses as __PytoClassesApp__
from importlib.machinery import SourceFileLoader

__PytoClassesApp__.Python.shared.version = __sys__.version

__builtins__.input = __Pyto__.input

oldStdout = __sys__.stdout

class Reader:
    def write(self, txt):
        oldStdout.write(txt)
        __Pyto__.print(txt, end="")

reader = Reader()
__sys__.stderr = reader
__sys__.stdout = reader

interact = __code__.interact
def newInteract():
    __PytoClassesApp__.Python.shared.isREPLRunning = True
    interact()
__code__.interact = newInteract

try:
    SourceFileLoader("main", "%@").load_module()
except Exception as e:
    print(e)
