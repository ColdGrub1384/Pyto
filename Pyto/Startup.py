__builtins__.iOS = "iOS"
__builtins__.macOS = "macOS"
__builtins__.__platform__ = __builtins__.iOS

__builtins__.widget = "widget"
__builtins__.app = "app"
__builtins__.__host__ = app

import sys
import os

sys.path.insert(0, os.path.expanduser("~/Library/pylib"))
sys.path.insert(0, os.path.expanduser("~/Documents"))
sys.path.insert(0, os.path.expanduser("~/Documents/modules"))

import io
import console
import code
import pyto
from importlib.machinery import SourceFileLoader
import importlib
import threading
from time import sleep
from outputredirector import Reader
from extensionsimporter import *

pyto.Python.shared.version = sys.version

# MARK: - Input

def askForInput(prompt=None):
    if (threading.currentThread() in console.ignoredThreads):
        return ""
    else:
        return console.input(prompt)

__builtins__.input = askForInput

# MARK: - Output

def read(text):
    console.print(text, end="")

standardOutput = Reader(read)
standardOutput._buffer = io.BufferedWriter(standardOutput)

standardError = Reader(read)
standardError._buffer = io.BufferedWriter(standardError)

sys.stdout = standardOutput
sys.stderr = standardError

# MARK: - Modules

sys.meta_path.append(NumpyImporter())
sys.meta_path.append(MatplotlibImporter())

# MARK: - Create a Selector without class.

__builtins__.Selector = pyto.PySelector.makeSelector
__builtins__.Target = pyto.SelectorTarget.shared

# MARK: - Deprecations

__builtins__.deprecated = ["runAsync", "runSync", "generalPasteboard", "setString", "setStrings", "setImage", "setImages", "setURL", "setURLs", "showViewController", "closeViewController", "mainLoop", "openURL", "shareItems", "pickDocumentsWithFilePicker"]

# MARK: - Run script

while True:
    try:
        SourceFileLoader("main", "%@").load_module()
    except Exception as e:
        print(e)
