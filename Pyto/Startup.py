import sys

__builtins__.iOS = "iOS"
__builtins__.macOS = "macOS"
if sys.platform == "ios":
    __builtins__.__platform__ = __builtins__.iOS
else:
    __builtins__.__platform__ = __builtins__.macOS

__builtins__.widget = "widget"
__builtins__.app = "app"
__builtins__.__host__ = __builtins__.app

import os

sys.path.insert(-1, os.path.expanduser("~/Documents"))
sys.path.insert(-1, os.path.expanduser("~/Documents/modules"))

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
import _signal
from pip import BUNDLED_MODULES

# MARK: - Warnings

logging.basicConfig(level=logging.INFO)

def __send_warnings_to_log__(message, category, filename, lineno, file=None, line=None):
    _message = warnings.formatwarning(message, category, filename, lineno, line)
    try:
        pyto.PyOutputHelper.printWarning(_message, script=threading.current_thread().script_path)
    except:
        pyto.PyOutputHelper.printWarning(_message, script=None)
    return

warnings.showwarning = __send_warnings_to_log__

pyto.Python.shared.version = sys.version

# MARK: - Allow / Disallow subprocesses

if __platform__ is iOS:
    os.allows_subprocesses = False
elif __platform__ is macOS:
    os.allows_subprocesses = True

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

for importer in (NumpyImporter, MatplotlibImporter, PandasImporter, PillowImporter):
    sys.meta_path.insert(0, importer())

# MARK: - Pre-import modules

def importModules():
    try:
        import matplotlib, numpy, pandas, PIL
        import PIL.ImageShow

        def show_image(image, title=None, **options):
            import os
            import tempfile
            import sharing
    
            imgPath = tempfile.gettempdir()+"/image.png"
    
            i = 1
            while os.path.isfile(imgPath):
                i += 1
                imgPath = os.path.join(tempfile.gettempdir(), 'image '+str(i)+'.png')
    
            image.save(imgPath,"PNG")
            sharing.quick_look(imgPath)

        PIL.ImageShow.show = show_image
    except:
        pass

threading.Thread(target=importModules).start()

# MARK: - Create a Selector without class.

__builtins__.Selector = pyto.PySelector.makeSelector
__builtins__.Target = pyto.SelectorTarget.shared

# MARK: - Deprecations

__builtins__.deprecated = []

# MARK: - Pip bundled modules

if pyto.PipViewController != None:
    pyto.PipViewController.bundled = BUNDLED_MODULES

# MARK: - OS

def fork():
    pass

def waitpid(pid, options):
    return (-1, 0)

os.fork = fork
os.waitpid = waitpid

# MARK: - Handle signal called outside main thread

old_signal = _signal.signal
def signal(signal, handler):
    try:
        threading
    except NameError:
        import threading
    
    if threading.main_thread() == threading.current_thread():
        return old_signal(signal, handler)
    else:
        return None
_signal.signal = signal

# MARK: - Run script

pyto.Python.shared.isSetup = True

while True:
    try:
        SourceFileLoader("main", "%@").load_module()
    except Exception as e:
        print(e)
