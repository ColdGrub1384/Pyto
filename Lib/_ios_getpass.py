import sys
import time

from pyto import PyInputHelper
from console import ignoredThreads
import threading
import os
try:
    from rubicon.objc import *
except ValueError:
    def ObjCClass(class_name):
        return None


if "widget" in os.environ:
    raise ImportError("Cannot ask for input from a widget")

def getpass(prompt="Password: ", stream=sys.stdout):
    NSBundle = ObjCClass("NSBundle")
    if NSBundle.mainBundle.bundlePath.pathExtension == "appex":
        return None
    
    if prompt is None:
        prompt = ""

    print(prompt, end="")

    try:
        path = threading.current_thread().script_path
    except AttributeError:
        path = ""

    try:
        PyInputHelper.getPassWithPrompt(prompt, script=threading.current_thread().script_path)
    except AttributeError:
        PyInputHelper.getPassWithPrompt(prompt, script=None)

    userInput = PyInputHelper.waitForInput(path)

    if userInput == "<WILL INTERRUPT>": # Will raise KeyboardInterrupt, don't return
        while True:
            time.sleep(0.2)

    return str(userInput)
