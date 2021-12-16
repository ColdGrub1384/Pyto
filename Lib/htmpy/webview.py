import pyto_ui as ui
from .jsobject import JSObject
from os.path import dirname, realpath
from Foundation import NSURL
import runpy
import sys

class WebView(ui.WebView):
    """
    A Web View that runs Python code in ``<script type="text/python">`` tags.
    """

    _locals = {}
    
    _globals = {}

    def __init__(self):
        super().__init__()

        self.register_message_handler("webView")

        with open(dirname(__file__)+"/pyhtml.js", "r") as f:
            self.__py_view__.addUserScript(f.read())
    
    def run(self, code: str):
        sys.modules["htmpy"].window = JSObject("window", self)
        self._locals["window"] = sys.modules["htmpy"].window
        self._locals["_function_holder"] = globals()["_function_holder"]
        exec(code, self._globals, self._locals)
        try:
            sys.modules["htmpy"].window = sys.modules["htmpy._window"].window
        except KeyError:
            pass
    
    def did_receive_message(self, web_view, name, message):
        if isinstance(message, dict) and message["run"] is not None:
            if isinstance(message["run"], str):
        
                lines = message["run"].split("\n")
                
                try:
                    first_line = 0
                except IndexError:
                    return
                
                while lines[first_line] == "":
                    first_line += 1
                
                text = ""
                spaces = 0
                try:
                    if lines[first_line].startswith(" "):
                        new_line = lines[first_line]
                        while new_line.startswith(" "):
                            new_line = new_line[1:]
                            spaces += 1
                except IndexError:
                    pass
                
                for line in lines:
                    try:
                        if line.startswith(" "):
                            text += line[spaces:]+"\n"
                        else:
                            raise IndexError
                    except IndexError as e:
                        text += line+"\n"
                
                self.run(text)
            elif isinstance(message["run"], list):
                for code in message["run"]:
                    self.did_receive_message(web_view, name, { "run": code })
