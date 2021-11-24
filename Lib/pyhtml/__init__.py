from . import _jsobject
from . import _webview
from ._window import window
from pyto import __Class__

PyHTMLServer = __Class__("PyHTMLServer")

class _FunctionHolder:
    
    def __init__(self):
        self._dict = {}
        self._web_views = {}
    
    def call(self, id, arguments):
        
        args = []
        
        function = self[id]
        web_view = self._web_views[id]
        
        for i in range(function.__code__.co_argcount):
            try:
                args.append(_jsobject.JSObject(arguments[i], web_view))
            except IndexError:
                break
        
        exec("function(*tuple(args))", web_view._globals, locals())
    
    def __getitem__(self, key):
        return self._dict[key]
    
    def __setitem__(self, key, value):
        self._dict[key] = value
    
    def __getattribute__(self, name):
        try:
            return super().__getattribute__(name)
        except AttributeError:
            return self[name]

_function_holder = _FunctionHolder()
_jsobject._function_holder = _function_holder
_webview._function_holder = _function_holder

WebView = _webview.WebView
JSObject = _jsobject.JSObject
