print("Startup script called")

__builtins__.iOS = 'iOS'
__builtins__.macOS = 'macOS'
__builtins__.__platform__ = iOS

import sys
import console as Pyto
import code
import pyto
from importlib.machinery import SourceFileLoader
import importlib
import threading

pyto.Python.shared.version = sys.version

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
    pyto.Python.shared.isREPLRunning = True
    interact()
code.interact = newInteract

# MARK: - Create a Selector without class.

__builtins__.Selector = pyto.PySelector.makeSelector
__builtins__.Target = pyto.SelectorTarget.shared
__builtins__.deprecated = ["runAsync", "runSync", "generalPasteboard", "setString", "setStrings", "setImage", "setImages", "setURL", "setURLs", "showViewController", "closeViewController", "mainLoop", "openURL", "shareItems", "pickDocumentsWithFilePicker"]

# MARK: - Run script

try:
    SourceFileLoader("main", "%@").load_module()
except Exception as e:
    print(e)

