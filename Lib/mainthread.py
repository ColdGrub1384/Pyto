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

__PyMainThread__ = pyto.PyMainThread


def runAsync(code):
    raise NameError("`runAsync` was renamed to `run_async`")


def runSync(code):
    raise NameError("`runSync` was renamed to `run_sync`")


def mainthread(func):
    """
    A decorator for a function running in the main thread.

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
            func(*args, **kwargs)

        mainthread.run_async(_run)

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


def run_sync(code):

    check(code, "code", [_func])

    def code_() -> None:
        code()

    __PyMainThread__.runSync(code_)
    sleep(0.1)
