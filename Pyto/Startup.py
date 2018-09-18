import pyto as __Pyto__
import sys as __sys__
import code as __code__
import PytoClasses as __PytoClassesApp__
from importlib.machinery import SourceFileLoader
    
__builtins__.input = __Pyto__.input
__builtins__.print = __Pyto__.print
                
class Reader:
    def write(self, txt):
        print(txt)

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
