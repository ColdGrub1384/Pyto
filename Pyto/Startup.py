# MARK: - Platform checking

__builtins__.iOS = "iOS"
__builtins__.macOS = "macOS"
__builtins__.__platform__ = __builtins__.iOS

import sys
import os

sys.path.insert(0, os.path.expanduser("~/Library/pylib"))
sys.path.insert(0, os.path.expanduser("~/Documents"))
sys.path.insert(0, os.path.expanduser("~/Documents/modules"))

import io
import console as Pyto
import code
import pyto
from importlib.machinery import SourceFileLoader
import importlib
import threading
from time import sleep
from _thread import interrupt_main

pyto.Python.shared.version = sys.version

# MARK: - Input

def askForInput(prompt=None):
    if (threading.currentThread() in Pyto.ignoredThreads):
        return ""
    else:
        return Pyto.input(prompt)

__builtins__.input = askForInput

# MARK: - Output

oldStdout = sys.__stdout__

class Reader:
    
    @property
    def buffer(self):
        return self._buffer
    
    @property
    def encoding(self):
        return "utf-8"
    
    @property
    def closed(self):
        return False
    
    def __init__(self):
        pass
    
    def isatty(self):
        return False
    
    def writable(self):
        return True
    
    def flush(self):
        pass
    
    def write(self, txt):
        
        if (threading.currentThread() in Pyto.ignoredThreads):
            return
        
        if txt.__class__.__name__ == 'str':
            oldStdout.write(txt)
            Pyto.print(txt, end="")
        elif txt.__class__.__name__ == 'bytes':
            text = txt.decode()
            oldStdout.write(text)
            Pyto.print(text, end="")

standardOutput = Reader()
standardOutput._buffer = io.BufferedWriter(standardOutput)

standardError = Reader()
standardError._buffer = io.BufferedWriter(standardError)

sys.stdout = standardOutput
sys.stderr = standardError

# MARK: - NumPy

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

# MARK: - Pandas

# TODO: Add Pandas
'''class PandasImporter(object):
    def find_module(self, fullname, mpath=None):
        if fullname in ('pandas.hashtable', 'pandas.lib'):
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

sys.meta_path.append(PandasImporter())'''

# MARK: - Selector

"""
Create a Selector without class.
"""

__builtins__.Selector = pyto.PySelector.makeSelector
__builtins__.Target = pyto.SelectorTarget.shared
__builtins__.deprecated = ["runAsync", "runSync", "generalPasteboard", "setString", "setStrings", "setImage", "setImages", "setURL", "setURLs", "showViewController", "closeViewController", "mainLoop", "openURL", "shareItems", "pickDocumentsWithFilePicker"]

# MARK: - Run script

while True:
    try:
        SourceFileLoader("main", "%@").load_module()
    except Exception as e:
        print(e)
