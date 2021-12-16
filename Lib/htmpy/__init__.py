"""
HTML + Python

HtmPy is let's you run Python code in a ``<script>`` tag on an HTML page when it's shown on a :class:`~htmpy.WebView`.

This module is also a bridge between Python and JavaScript so the code has access to the ``window`` object. However, the code can be very slow if too many JavaScript functions are called. 
This can be easily solved by doing the logic in Python and then calling a JavaScript function previously declared on a ``script`` tag to modify the DOM.

To take advantage of HtmPy, just create an HTML file and the editor will let you show it.
Place your Python code in a ``script`` tag like that:

.. highlight:: html
.. code-block:: html

    <script type="text/python">
        ...
    </script>

To access the window object:

.. highlight:: python
.. code-block:: python

    from htmpy import window

Then you can just call any function or get any attribute of the window object to modify the DOM.
If you put JavaScript code on a tag before, you can get anything declared on the global scope through the ``window`` object.
You can do the opposite, store a Python function or variable in the ``window`` object and it will be accessible from JavaScript.
HtmPy will bridge Python functions so they can be called from JavaScript, so you could use ``addEventListener`` for example. However, the functions will run asynchronously and will not return any value.

You can use :class:`~htmpy.WebView` to show HTML + Python pages on your custom UI.
"""

from . import jsobject as _jsobject
from . import webview as _webview
from ._window import window
from pyto import __Class__

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
