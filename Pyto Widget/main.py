__builtins__.iOS = "iOS"
__builtins__.macOS = "macOS"
__builtins__.__platform__ = __builtins__.iOS

__builtins__.widget = "widget"
__builtins__.app = "app"
__builtins__.__host__ = widget

import traceback

try:
    import importlib.util
    from time import sleep
    import sys
    from outputredirector import *
    from extensionsimporter import *
    import pyto
    import io
except Exception as e:
    ex_type, ex, tb = sys.exc_info()
    traceback.print_tb(tb)
    
# MARK: - Create selector without class
    
__builtins__.Selector = pyto.PySelector.makeSelector
__builtins__.Target = pyto.SelectorTarget.shared

# MARK: - Output
    
def read(text):
    pyto.ConsoleViewController.visible.print(text)
    
standardOutput = Reader(read)
standardOutput._buffer = io.BufferedWriter(standardOutput)
    
standardError = Reader(read)
standardError._buffer = io.BufferedWriter(standardError)
    
sys.stdout = standardOutput
sys.stderr = standardError
    
# MARK: - Modules

sys.meta_path.append(NumpyImporter())
sys.meta_path.append(MatplotlibImporter())
    
# MARK: - Run script

directory = pyto.ConsoleViewController.sharedDirectoryPath
    
if not directory+"/modules" in sys.path:
    sys.path.append(directory+"/modules")

def run():
    pyto.ConsoleViewController.startScript = False
    
    try:
        spec = importlib.util.spec_from_file_location("__main__", directory+"/main.py")
        script = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(script)
    except Exception as e:
        print(e.__class__.__name__, e)
    
    while not pyto.ConsoleViewController.startScript:
        sleep(0.5)
    
    run()

run()
