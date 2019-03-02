'''
Python mapping for the Intents framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from Intents import _metadata
from Intents._Intents import *


sys.modules['Intents'] = mod = objc.ObjCLazyModule(
    "Intents",
    "com.apple.Intents",
    objc.pathForFramework("/System/Library/Frameworks/Intents.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['Intents._metadata']
