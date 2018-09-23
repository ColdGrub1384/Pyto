import sys as sys
import os as os

sys.path.insert(0, os.path.expanduser("~/Library/pylib"))
sys.path.insert(0, os.path.expanduser("~/Documents"))

import console as Pyto
import code as code
import PytoClasses as PytoClassesApp
from importlib.machinery import SourceFileLoader

PytoClassesApp.Python.shared.version = sys.version

__builtins__.input = Pyto.input

oldStdout = sys.stdout

class Reader:
    def write(self, txt):
        oldStdout.write(txt)
        Pyto.print(txt, end="")

reader = Reader()
sys.stderr = reader
sys.stdout = reader

interact = code.interact
def newInteract():
    PytoClassesApp.Python.shared.isREPLRunning = True
    interact()
code.interact = newInteract

try:
    SourceFileLoader("main", "%@").load_module()
except Exception as e:
    print(e)
