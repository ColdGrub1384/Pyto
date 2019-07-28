__builtins__.iOS = 'iOS'
__builtins__.macOS = 'macOS'
__builtins__.__platform__ = __builtins__.iOS

__builtins__.widget = 'widget'
__builtins__.app = 'app'
__builtins__.__host__ = None

import sys
import console as Pyto
import pyto
from importlib.machinery import SourceFileLoader
import importlib
import threading
from outputredirector import *
from extensionsimporter import PillowImporter
import io
import traceback
from time import sleep

plt = sys.platform
sys.platform = "pyto"
import webbrowser
sys.platform = plt

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
    Pyto.print(text, end="")

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
        import sharing
        sharing.open_url(url)
        return True

webbrowser.register("mobile-safari", None, MobileSafari("MobileSafari.app"))

# MARK: - Pillow

sys.meta_path.insert(0, PillowImporter())

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

# MARK: - Run script

def run_code_loop():

    while True:
    
        try:
            code = str(pyto.Python.shared.codeToRun)
            exec(code)
            if code == pyto.Python.shared.codeToRun:
                pyto.Python.shared.codeToRun = None
        except:
            print(traceback.format_exc())

        if pyto.ConsoleViewController.isPresentingView:
            sleep(0.02)
        else:
            sleep(0.2)

threading.Thread(target=run_code_loop, args=()).start()

script = "%@"

try:
    SourceFileLoader("main", script).load_module()
except Exception as e:
    ex_type, ex, tb = sys.exc_info()
    traceback.print_tb(tb)
