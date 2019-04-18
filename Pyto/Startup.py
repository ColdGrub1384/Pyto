__builtins__.iOS = "iOS"
__builtins__.macOS = "macOS"
__builtins__.__platform__ = __builtins__.iOS

__builtins__.widget = "widget"
__builtins__.app = "app"
__builtins__.__host__ = __builtins__.app

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
import warnings
import logging
from _ios_getpass import getpass as _ios_getpass
import getpass
import webbrowser
import sharing

# MARK: - Warnings

logging.basicConfig(level=logging.INFO)

def __send_warnings_to_log__(message, category, filename, lineno, file=None, line=None):
    pyto.PyOutputHelper.printWarning(warnings.formatwarning(message, category, filename, lineno, line))
    return

warnings.showwarning = __send_warnings_to_log__

os.system = pyto.Python.shared.version = sys.version

# MARK: - Disallow subprocesses

os.allows_subprocesses = False

# MARK: - Input

def askForInput(prompt=None):
    try:
        threading
    except NameError:
        import threading

    try:
        console
    except NameError:
        import console

    if (threading.currentThread() in console.ignoredThreads):
        return ""
    else:
        return console.input(prompt)

__builtins__.input = askForInput

getpass.getpass = _ios_getpass

# MARK: - Output

def read(text):
    try:
        console
    except NameError:
        import console

    console.print(text, end="")

standardOutput = Reader(read)
standardOutput._buffer = io.BufferedWriter(standardOutput)

standardError = Reader(read)
standardError._buffer = io.BufferedWriter(standardError)

sys.stdout = standardOutput
sys.stderr = standardError

# MARK: - Web browser

class MobileSafari(webbrowser.BaseBrowser):
    '''
    Mobile Safari web browser.
    '''
    
    def open(self, url, new=0, autoraise=True):
        sharing.open_url(url)
        return True

webbrowser.register("mobile-safari", None, MobileSafari("MobileSafari.app"))

# MARK: - Modules

for importer in (NumpyImporter, MatplotlibImporter, PandasImporter):
    sys.meta_path.insert(0, importer())

# Pre-import modules

import matplotlib, numpy, pandas


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
