print("Startup script called")

import sys
import console as Pyto
import code
import PytoClasses
from importlib.machinery import SourceFileLoader
import importlib
import threading

PytoClasses.Python.shared.version = sys.version

# MARK: - Input

def askForInput(prompt=None):
    if (threading.currentThread() in Pyto.ignoredThreads):
        return ""
    else:
        return Pyto.input(prompt)


__builtins__.input = askForInput

# MARK: - Output

oldStdout = sys.stdout

class Reader:
    
    def isatty(self):
        return False
    
    def write(self, txt):
        
        if (threading.currentThread() in Pyto.ignoredThreads):
            return
        
        oldStdout.write(txt)
        Pyto.print(txt, end="")

reader = Reader()
sys.stderr = reader
sys.stdout = reader

# MARK: - REPL

interact = code.interact
def newInteract():
    PytoClasses.Python.shared.isREPLRunning = True
    interact()
code.interact = newInteract

# MARK: - Run script

try:
    SourceFileLoader("main", "%@").load_module()
except Exception as e:
    print(e)

