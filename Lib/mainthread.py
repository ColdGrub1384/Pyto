"""
Access the main thread

This module allows you to run code on the main thread easely. This can be used for modifiying the UI.

Example:

.. highlight:: python
.. code-block:: python

    from UIKit import UIScreen
    import mainthread

    def set_brightness():
        inverted = int(not int(UIScreen.mainScreen.brightness))
        UIScreen.mainScreen.setBrightness(inverted)

    mainthread.run_async(set_brightness)
"""

import pyto
from time import sleep
from __check_type__ import check
from __check_type__ import func as _func
import threading

__PyMainThread__ = pyto.PyMainThread

def mainthread(func):
    """
    A decorator that makes a function run in synchronously on the main thread.

    Example:

    .. code-block:: python

       import mainthread
       from UIKit import UIApplication

       @mainthread.mainthread
       def run_in_background():
           app = UIApplication.sharedApplication
           app.beginBackgroundTaskWithExpirationHandler(None)

       run_in_background()
    """

    check(func, "func", [_func])

    def run(*args, **kwargs):
        import mainthread

        def _run():
            return func(*args, **kwargs)

        return mainthread.run_sync(_run)

    return run


def run_async(code):
    """
    Runs the given code asynchronously on the main thread.

    :param code: Code to execute in the main thread.
    """

    check(code, "code", [_func])

    def code_() -> None:
        code()

    __PyMainThread__.runAsync(code_)


_ret_value = None
_exc = None

def run_sync(code):
    """
    Runs the given code asynchronously on the main thread.
    Supports return values as opposed to :func:`~mainthread.run_async`

    :param code: Code to execute in the main thread.
    """
    
    global _exc

    check(code, "code", [_func])

    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        script_path = None

    def code_() -> None:
        global _ret_value
        global _exc
        threading.current_thread().script_path = script_path
        try:
            _ret_value = code()
        except Exception as e:
            _exc = e
        threading.current_thread().script_path = None

    __PyMainThread__.runSync(code_)
    sleep(0.1)
    
    if _exc is not None:
        __exc = _exc
        _exc = None
        raise __exc
    
    return _ret_value
