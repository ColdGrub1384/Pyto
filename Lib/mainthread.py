"""
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

__PyMainThread__ = pyto.PyMainThread


def runAsync(code):
    raise NameError("`runAsync` was renamed to `run_async`")


def runSync(code):
    raise NameError("`runSync` was renamed to `run_sync`")


def run_async(code):
    """
    Runs the given code asynchronously on the main thread.

    :param code: Code to execute in the main thread.
    """

    def code_() -> None:
        code()

    __PyMainThread__.runAsync(code_)


def run_sync(code):

    def code_() -> None:
        code()

    __PyMainThread__.runSync(code_)
    sleep(0.1)
