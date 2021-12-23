# -*- coding: utf-8 -*-
"""
Some Pyto core functions
"""

# (!) Warning (!)
# The following code is horrible
# Protect your eyes
#  Good luck

import os
from pyto import *
from pyto import __isMainApp__, __Class__
import os
import sys
import traceback
import threading
import time
from extensionsimporter import __UpgradeException__
import ctypes
import weakref
import json
from types import ModuleType as Module

if "widget" not in os.environ:
    from code import interact, InteractiveConsole
    import importlib.util
    from importlib import reload
    import builtins
    import pdb
    from colorama import Fore, Back, Style
    from json import dumps
    from collections.abc import Mapping
    import stopit
    import asyncio
    import gc
    from time import sleep
    from rubicon.objc import ObjCInstance
    from Foundation import NSObject
    import warnings
    from _exc_handling import get_json, offer_suggestion

    try:
        from rubicon.objc import *
    except ValueError:

        def ObjCClass(class_name):
            return None

    try:
        import pyto_core as pc
    except ImportError:
        pass


namespaces = {}


def displayhook(_value):
    if _value is None:
        return

    def represent(value):
        if hasattr(value, "__dict__"):
            val = {}

            _dict = dict(value.__class__.__dict__)
            _dict.update(dict(value.__dict__))
            for key in list(_dict):
                item = _dict[key]
                if item is value or (
                    not isinstance(item, dict) and not isinstance(item, list)
                ):
                    item = repr(item)
                else:
                    item = represent(item)
                val[key] = item
        elif isinstance(value, Mapping):
            val = {}
            _dict = value
            for key in list(_dict):
                item = _dict[key]
                if item is value or (
                    not isinstance(item, dict) and not isinstance(item, list)
                ):
                    item = repr(item)
                else:
                    item = represent(item)
                val[repr(key)] = item
        elif isinstance(value, list):
            val = {}
            i = 0
            for item in value:
                _item = item
                if item is value or (
                    not isinstance(item, dict) and not isinstance(item, list)
                ):
                    val[str(i)] = repr(item)
                else:
                    val[str(i)] = represent(item)
                i += 1
        else:
            val = repr(value)

        return val

    _repr = repr(_value)

    if isinstance(_value, tuple):
        _value = list(_value)

    if isinstance(
        _value, ObjCInstance
    ):  # We assume it's an instance or subclass of NSObject
        _repr = str(_value.debugDescription)
        val = {
            "Description": _repr,
            "Superclass": str(_value.superclass.name),
            "Methods": str(_value._methodDescription()),
        }
    elif (
        isinstance(_value, Mapping)
        or isinstance(_value, list)
        or hasattr(_value, "__dict__")
    ):
        val = represent(_value)
    else:
        val = represent([_value])

    def default(o):
        return repr(o)

    json = dumps(val, default=default)
    try:
        PyOutputHelper.printValue(
            _repr + "\n", value=json, script=threading.current_thread().script_path
        )
    except AttributeError:
        PyOutputHelper.printValue(_repr + "\n", value=json, script=None)


def return_excepthook(exc, value, tb, limit=None):

    text = ""

    if isinstance(value, __UpgradeException__):
        builtins.print(value)
        return

    message = traceback.format_exception(exc, value, tb, limit=limit)

    if limit is None and not exc is SyntaxError:
        del message[1]  # Remove the first element of the traceback in the REPL

    for part in message:
        if part == message[0]:  # Traceback (most recent blah blah blah)
            msg = Fore.RED + part + Style.RESET_ALL
        elif part == message[-1]:  #  Exception: message
            parts = part.split(":")
            parts[0] = Fore.RED + parts[0] + Style.RESET_ALL

            msg = ":".join(parts)

            suggestion = offer_suggestion(value)
            if suggestion is not None:
                msg =  msg[:-1]
                msg += ". Did you mean '"+suggestion.decode()+"'?\n"
        elif part.startswith("  File"):  # File "file", line 1, in function
            parts = part.split('"')
            parts[1] = Fore.YELLOW + parts[1] + Style.RESET_ALL

            parts = '"'.join(parts).split("\n")
            first_line = parts[0].split(" ")
            first_line[-1] = Fore.YELLOW + first_line[-1] + Style.RESET_ALL
            parts[0] = " ".join(first_line)
            msg = "\n".join(parts)
        else:
            msg = part

        text += msg
    
    return text


def excepthook(exc, value, tb, limit=None):
    builtins.print(return_excepthook(exc, value, tb, limit), end="")


__repl_namespace__ = {}

__repl_threads__ = {}

class MainModule(Module):

    def __getattribute__(self, name):
        if name == "__dict__":
            return self._dict
        elif name != "_dict" and name in self._dict:
            return self._dict[name]
        else:
            return super().__getattribute__(name)

    def __setattr__(self, name, value):
        if name == "_dict":
            super().__setattr__(name, value)
        else:
            self._dict[name] = value

    def __init__(self, name, _dict):
        self._dict = _dict
        super().__init__(name)

def __runREPL__(repl_name="", namespace={}, banner=None):

    if "widget" in os.environ:
        return

    sys.excepthook = excepthook
    sys.displayhook = displayhook

    __repl_namespace__[repl_name] = {
        "clear": ClearREPL(),
        "__name__": repl_name.split(".")[0],
        "__file__": threading.current_thread().script_path,
    }
    __repl_namespace__[repl_name].update(namespace)

    sys.__class__.main[threading.current_thread().script_path] = MainModule(repl_name, __repl_namespace__[repl_name])

    __namespace__ = __repl_namespace__[repl_name]

    def read(prompt):
        import console

        __namespace__.update(console.__repl_namespace__[repl_name])

        return input(prompt, highlight=True)

    if banner is None:
        banner = f"Python {sys.version}\n{str(__Class__('SidebarViewController').pytoVersion)}\nType \"help\", \"copyright\", \"credits\" or \"license\" for more information.\nType \"clear()\" to clear the console."
    try:
        interact(readfunc=read, local=__namespace__, banner=banner)
    except SystemExit:
        del sys.__class__.main[threading.current_thread().script_path]


# MARK: - Running


def __clear_mods__():
    try:
        del sys.modules["pip"]
    except KeyError:
        pass

    try:
        del sys.modules["pdb"]
    except KeyError:
        pass

    try:
        del sys.modules["logging"]
        del sys.modules["logging.config"]
        del sys.modules["logging.handlers"]
    except KeyError:
        pass

    try:
        del sys.modules["pyto_ui"]
    except KeyError:
        pass

    try:
        del sys.modules["pyto_core"]
    except KeyError:
        pass

    try:
        del sys.modules["ui_constants"]
    except KeyError:
        pass

    try:
        del sys.modules["watch"]
    except KeyError:
        pass

    try:
        del sys.modules["widgets"]
    except KeyError:
        pass

    try:
        del sys.modules["turtle"]
    except KeyError:
        pass

    try:
        _values = sys.modules["_values"]

        for attr in dir(_values):
            if attr not in _values._dir:
                delattr(_values, attr)

    except:
        pass

    try:
        if "matplotlib" in sys.modules:
            import matplotlib.pyplot as plt

            plt.close()
            plt.clf()
    except:
        pass

    keys = list(sys.modules.keys())
    for key in keys:
        try:
            mod = sys.modules[key]
            if (
                os.access(mod.__file__, os.W_OK)
                and not "/Library/python38" in mod.__file__
                and key != "<run_path>"
            ):
                del sys.modules[key]
        except AttributeError:
            pass
        except TypeError:
            pass
        except KeyError:
            pass


__widget_id__ = None

if "widget" not in os.environ:

    __script__ = None

    __is_loop_running__ = False

    __i__ = 0

    _breakpoints = []

    _are_breakpoints_set = True

    def run_script(path, replMode=False, debug=False, breakpoints="[]", runREPL=True, args=[], cwd="/"):
        """
        Run the script at given path catching exceptions.
    
        This function should only be used internally by Pyto.
    
        Args:
            path: The path of the script.
            replMode: If set to `True`, errors will not be handled.
            debug: Set to `True` for debugging.
            breakpoints: A list of breakpoints as a JSON array.
            runREPL: Set it to `True` for running the REPL.
            args: The arguments passed to sys.argv.
            cwd: The thread working directory.
        """
        
        sys = __import__("sys")

        __repl_namespace__[path.split("/")[-1]] = {}
        __clear_mods__()
        
        python = Python.shared
        python.addScriptToList(path)
        
        if PyCallbackHelper is not None:
            PyCallbackHelper.exception = None

        is_watch_script = False
        if path == str(Python.watchScriptURL.path):
            is_watch_script = True

        currentDir = cwd

        try:
            del os.environ["ps1"]
        except KeyError:
            pass

        try:
            del os.environ["ps2"]
        except KeyError:
            pass
            
        sys.argv = [path]+args

        d = os.path.expanduser("~/tmp")
        filesToRemove = []
        try:
            filesToRemove = [os.path.join(d, f) for f in os.listdir(d)]
        except:
            pass

        try:
            filesToRemove.remove(d + "/Script.py")
        except:
            pass

        try:
            filesToRemove.remove(d + "/Watch.py")
        except:
            pass

        for f in filesToRemove:

            if f.endswith(".repl.py"):
                continue

            if f.endswith(".tmp"):
                continue

            try:
                os.remove(f)
            except PermissionError:
                pass

        # Kill the REPL running for this script
        global __repl_threads__
        if path in __repl_threads__:
        
            Python.shared.interruptInputWithScript(path)
        
            thread = __repl_threads__[path]
            for tid, tobj in threading._active.items():
                if tobj is thread:
                    try:
                        stopit.async_raise(tid, SystemExit)
                        break
                    except:
                        pass
            del __repl_threads__[path]

        def run():
            def add_signal_handler(s, f):
                return

            loop = asyncio.new_event_loop()
            loop.add_signal_handler = add_signal_handler
            asyncio.set_event_loop(loop)
                        
            pip_directory = os.path.expanduser("~/Documents/site-packages")
            os.chdir(currentDir)
                        
            try:
                sys.path.remove(pip_directory)
            except:
                pass
            sys.path.insert(-1, currentDir)
            sys.path.insert(-1, pip_directory)

            try:
                global __script__
                spec = importlib.util.spec_from_file_location("__main__", path)
                __script__ = importlib.util.module_from_spec(spec)
                sys.__class__.main[path] = weakref.ref(__script__)
                sys.modules["__main__"] = __import__("__main__")
                if debug and "widget" not in os.environ:

                    try:
                        console
                    except:
                        import console

                    console._has_started_debugging = False
                    console._are_breakpoints_set = False
                    console._breakpoints = json.loads(breakpoints)

                    console.__i__ = -1

                    old_input = input

                    def debugger_input(prompt):

                        try:
                            console
                        except:
                            import console

                        if not console._are_breakpoints_set:

                            breakpoints = console._breakpoints
                            console.__i__ += 1

                            if len(breakpoints) < console.__i__:
                                console._are_breakpoints_set = True
                                return ""

                            try:
                                breakpoints[console.__i__ + 1]
                            except:
                                console._are_breakpoints_set = True

                            return "b " + str(breakpoints[console.__i__]["file_path"]) + ":" + str(breakpoints[console.__i__]["lineno"])
                        elif not console._has_started_debugging:
                            console._has_started_debugging = True
                            return "c"
                        else:
                            console.__should_inspect__ = True
                            _input = old_input(prompt)
                            if _input == "<WILL INTERRUPT>":
                                return "exit"
                            else:
                                return _input

                    if len(breakpoints) > 0:
                        builtins.input = debugger_input

                    pdb.main(["pdb", path])
                    builtins.input = old_input

                    loop.close()
                else:
                    spec.loader.exec_module(__script__)
                    loop.close()
                    return (path, vars(__script__), None)
            except SystemExit:
                if PyCallbackHelper is not None:
                    PyCallbackHelper.cancelled = True

                loop.close()
                return (path, vars(__script__), SystemExit)
            except KeyboardInterrupt:
                if PyCallbackHelper is not None:
                    PyCallbackHelper.cancelled = True

                loop.close()
                return (path, vars(__script__), KeyboardInterrupt)
            except Exception as e:

                if PyCallbackHelper is not None:
                    PyCallbackHelper.exception = str(e)

                loop.close()

                if not __isMainApp__() or replMode:
                    print(traceback.format_exc())
                    if not replMode:
                        Python.shared.fatalError(traceback.format_exc())
                else:
                    exc_type, exc_obj, exc_tb = sys.exc_info()

                    extracts = traceback.extract_tb(exc_tb)
                    count = len(extracts)

                    lineNumber = -1

                    fileName = path
                    for i, extract in enumerate(extracts):
                        if extract[0] == fileName:
                            lineNumber = extract[1]
                            break
                        count -= 1

                    if (
                        type(e) == SyntaxError
                    ):  # The last word in a `SyntaxError` exception is the line number
                        lineNumber = [
                            int(s) for s in (str(e)[:-1]).split() if s.isdigit()
                        ][-1]

                    as_text = return_excepthook(exc_type, exc_obj, exc_tb, -count)

                    offset = 0
                    end_offset = 0
                    if isinstance(e, SyntaxError):
                        offset = e.offset
                        end_offset = e.end_offset
                        count = 0

                    _json = get_json(exc_tb, exc_obj, as_text, count, offset, end_offset)

                    traceback_shown = False
                    for console in ConsoleViewController.objcVisibles:
                        if (
                            console.editorSplitViewController.editor.document.fileURL.path
                            != path
                        ):
                            continue
                        console.editorSplitViewController.editor.showTraceback(
                            _json
                        )
                        traceback_shown = True

                    if not traceback_shown:
                        builtins.print(as_text)

                    try:
                        PyOutputHelper.printError(
                            "", script=threading.current_thread().script_path
                        )
                    except AttributeError:
                        PyOutputHelper.printError("", script=None)

                    error = traceback.format_exc(limit=-count)
                    if "cv2.error" in error and "!_src.empty()" in error:
                        string = "\nOn Pyto, 'cv2.VideoCapture.read' may return an invalid value the first time. If you are running a loop for capturing a video from the camera, check if the return value is valid before using it. See the 'OpenCV/face_detection.py' example.\n"
                        try:
                            PyOutputHelper.printError(
                                string, script=threading.current_thread().script_path
                            )
                        except AttributeError:
                            PyOutputHelper.printError(string, script=None)

                    if debug:
                        pdb.post_mortem(exc_tb)

                    return (path, vars(__script__), e)

            if __isMainApp__():

                EditorViewController.runningLine = 0

                ConsoleViewController.enableDoneButton()

                ReviewHelper.shared.launches = ReviewHelper.shared.launches + 1
                ReviewHelper.shared.requestReview()

        def run_repl(t):

            global __repl_threads__

            Python.shared.removeScriptFromList(path)

            if path.endswith(".repl.py") or not runREPL:
                return

            if type(t) is tuple and len(t) == 3 and not is_watch_script:
                __repl_threads__[t[0]] = threading.current_thread()
                __runREPL__(t[0], t[1], "")

        _script = None

        if (
            "__editor_delegate__" in dir(builtins)
            and builtins.__editor_delegate__ is not None
        ):
            delegate = builtins.__editor_delegate__

            def _run():
                import builtins

                delegate = builtins.__editor_delegate__

                t = run()
                if type(t) is tuple and len(t) == 3:
                    try:
                        delegate.did_run_script(t[0], t[1], t[2])
                    except NotImplementedError:
                        run_repl(t)
                    except SystemExit:
                        run_repl(t)
                    except KeyboardInterrupt:
                        run_repl(t)
                    except Exception:
                        traceback.print_tb()

            try:
                delegate.run_script(path, _run)
            except NotImplementedError:
                run_repl(_run())
        else:
            # Return the script's __dict__ for the Xcode template
            t = run()
            
            if Python.shared.tooMuchUsedMemory:
                del t
            elif __isMainApp__():
                run_repl(t)
            else:
                _script = t[1]

        Python.shared.removeScriptFromList(path)

        sys.path = list(dict.fromkeys(sys.path))  # I don't remember why 😭

        if "widget" not in os.environ:
            import watch

            watch.__show_ui_if_needed__()

        __clear_mods__()

        # time.sleep(0.2)

        if Python.shared.tooMuchUsedMemory:
            Python.shared.runBlankScript()

        return _script


# MARK: - I/O

ignoredThreads = []
"""
All output and input request from these threads will be ignored.
"""


class ClearREPL:
    def __repr__(self):
        return self.__str__()

    def __str__(self):
        return "Type 'clear()' to clear the console."

    def __call__(self):
        print(u"{}[2J{}[;H".format(chr(27), chr(27)), end="")
        print(chr(27) + "[3J", end="")


def clear():
    """
    Clears the console.
    """

    if threading.current_thread() in ignoredThreads:
        return

    print(u"{}[2J{}[;H".format(chr(27), chr(27)), end="")
    print(chr(27) + "[3J", end="")
    
    msg = "'clear()' was deprecated in Pyto 16.1 since the terminal supports more escape sequences. You should just print the adequate escape sequences to clear the terminal."
    warnings.warn(msg, DeprecationWarning)


__PyInputHelper__ = PyInputHelper


def input(prompt: str = None, highlight=False):
    """
    Requests input with given prompt.

    :param prompt: Text printed before the user's input without a newline.
    :param highlight: A boolean indicating whether the line should be syntax colored.
    """

    if "widget" in os.environ:
        return None

    if prompt is None:
        prompt = ""

    print(prompt, end="")

    try:
        path = threading.current_thread().script_path
    except AttributeError:
        path = ""

    try:
        __PyInputHelper__.showAlertWithPrompt(
            prompt, script=threading.current_thread().script_path, highlight=highlight
        )
    except AttributeError:
        __PyInputHelper__.showAlertWithPrompt(prompt, script=None, highlight=highlight)

    userInput = __PyInputHelper__.waitForInput(path)

    if userInput == "<WILL INTERRUPT>":  #  Will raise KeyboardInterrupt, don't return
        while True:
            time.sleep(0.2)

    return str(userInput)


def print(*objects, sep: str = None, end: str = None):
    """
    Prints to the Pyto console, not to the stdout. Works as the builtin `print` function but does not support printing to a custom file. Pyto catches by default the stdout and the stderr, so use the builtin function instead. This function is mainly for internal use.
    """

    if sep is None:
        sep = " "
    if end is None:
        end = "\n"
    array = map(str, objects)

    printed = sep.join(array) + end
    try:
        if objects[0].__class__ is str:
            printed = objects[0]
    except:
        pass

    try:
        PyOutputHelper.print(printed, script=threading.current_thread().script_path)
    except AttributeError:
        PyOutputHelper.print(printed, script=None)


# MARK: - Alerts

if "widget" not in os.environ:

    PyAlert = PyAlert
    """
    A class representing an alert.

    Example:

    code-block::
        python

        alert = console.Alert.alertWithTitle("Hello", message="Hello World!")
        alert.addAction("Ok")
        alert.addCancelAction("Cancel")
        if (alert.show() == "Ok"):
            print("Good Bye!")
    """

    class Alert:
        """
        A wrapper of ``UIAlert``.
        """

        pyAlert = None

        def __init__(self):
            self.pyAlert = PyAlert.alloc().init()

        @staticmethod
        def alertWithTitle(title: str, message: str) -> "Alert":
            """
            Creates an alert.
            
            :param title: The title of the alert.
            :param message: The message of the alert.
            """

            alert = Alert()
            alert.pyAlert.title = title
            alert.pyAlert.message = message
            return alert

        __actions__ = []

        def addAction(self, title: str):
            """
            Add an action with given title.

            :param title: The title of the action.
            """

            self.pyAlert.addAction(title)

        def addDestructiveAction(self, title: str):
            """
            Add a destructive action with given title.
            
            :param title: The title of the action.
            """

            self.pyAlert.addDestructiveAction(title)

        def addCancelAction(self, title: str):
            """
            Add a cancel action with given title. Can only added once.

            :param title: The title of the action.
            """

            if not self.pyAlert.addCancelAction(title):
                raise ValueError("There is already a cancel action.")

        def show(self) -> str:
            """
            Shows alert.

            Returns the title of the selected action.

            :rtype: str
            """

            path = None
            try:
                path = threading.current_thread().script_path
            except AttributeError:
                pass

            return self.pyAlert._show(path)


else:
    PyAlert = None
    Alert = None

__all__ = ["Alert", "clear", "print", "input"]
