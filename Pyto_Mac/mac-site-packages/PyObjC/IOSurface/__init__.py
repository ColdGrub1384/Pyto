'''
Python mapping for the IOSurface framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from IOSurface import _metadata

sys.modules['IOSurface'] = mod = objc.ObjCLazyModule(
    "IOSurface",
    "com.apple.IOSurface",
    objc.pathForFramework("/System/Library/Frameworks/IOSurface.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['IOSurface._metadata']
