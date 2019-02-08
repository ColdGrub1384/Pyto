__builtins__.iOS = 'iOS'
__builtins__.macOS = 'macOS'
__builtins__.__platform__ = iOS

__builtins__.widget = 'widget'
__builtins__.app = 'app'
__builtins__.__host__ = None

import sys
import console as Pyto
import code
import pyto
from importlib.machinery import SourceFileLoader
import importlib
import threading
from outputredirector import *
import io

pyto.Python.shared.version = sys.version

# MARK: - Input

def askForInput(prompt=None):
    if (threading.currentThread() in Pyto.ignoredThreads):
        return ""
    else:
        return Pyto.input(prompt)


__builtins__.input = askForInput

# MARK: - Output

def read(text):
    pyto.ConsoleViewController.visible.print(text)

standardOutput = Reader(read)
standardOutput._buffer = io.BufferedWriter(standardOutput)

standardError = Reader(read)
standardError._buffer = io.BufferedWriter(standardError)

sys.stdout = standardOutput
sys.stderr = standardError

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

