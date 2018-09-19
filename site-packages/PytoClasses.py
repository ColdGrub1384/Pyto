# -*- coding: utf-8 -*-
"""
This module contains classes from the main app used by Pyto.

This module is only for private use. Use the `pyto` API instead.
"""

from rubicon.objc import *

NSBundle = ObjCClass("NSBundle")

def __Class__(name):
    if (NSBundle.mainBundle.bundleIdentifier == "ch.marcela.ada.Pyto"):
        return ObjCClass("Pyto."+name)
    else:
        return ObjCClass("Pyto_Share."+name)

PyMainThread = __Class__("PyMainThread")

PyInputHelper = __Class__("PyInputHelper")
PyOutputHelper = __Class__("PyOutputHelper")
PySharingHelper = __Class__("PySharingHelper")
FilePicker = __Class__("PyFilePicker")
Alert = __Class__("PyAlert")
PyContentViewController = __Class__("PyContentViewController")
PyExtensionContext = __Class__("PyExtensionContext")
Python = __Class__("Python")
