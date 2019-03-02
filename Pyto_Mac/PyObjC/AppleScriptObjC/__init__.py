'''
Python mapping for the AppleScriptObjC framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import sys
import objc
import Foundation

from AppleScriptObjC import _metadata

sys.modules['AppleScriptObjC'] = mod = objc.ObjCLazyModule(
    "AppleScriptObjC", "com.apple.AppleScriptObjC",
    objc.pathForFramework("/System/Library/Frameworks/AppleScriptObjC.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['AppleScriptObjC._metadata']
