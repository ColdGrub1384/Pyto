import sys
import os

sys.path.insert(0, os.path.expanduser("~/Library/pylib"))
sys.path.insert(0, os.path.expanduser("~/Documents"))
sys.path.insert(0, os.path.expanduser("~/Documents/modules"))

import console as Pyto
import code
import PytoClasses
from importlib.machinery import SourceFileLoader
import importlib

PytoClasses.Python.shared.version = sys.version

__builtins__.input = Pyto.input

oldStdout = sys.stdout

class Reader:
    
    def isatty(self):
        return False
    
    def write(self, txt):
        oldStdout.write(txt)
        Pyto.print(txt, end="")

reader = Reader()
sys.stderr = reader
sys.stdout = reader

interact = code.interact
def newInteract():
    PytoClasses.Python.shared.isREPLRunning = True
    interact()
code.interact = newInteract

# NumPy

class NumpyImporter(object):
    def find_module(self, fullname, mpath=None):
        if fullname in ('numpy.core.multiarray', 'numpy.core.umath', 'numpy.fft.fftpack_lite', 'numpy.linalg._umath_linalg', 'numpy.linalg.lapack_lite', 'numpy.random.mtrand'):
            return self
                    
        return

    def load_module(self, fullname):
        f = '__' + fullname.replace('.', '_')
        mod = sys.modules.get(f)
        if mod is None:
            mod = importlib.__import__(f)
            sys.modules[fullname] = mod
            return mod

        return mod

sys.meta_path.append(NumpyImporter())

try:
    SourceFileLoader("main", "%@").load_module()
except Exception as e:
    print(e)
