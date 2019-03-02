'''
Python mapping for the Photos framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from Photos import _metadata
import Photos._Photos

sys.modules['Photos'] = mod = objc.ObjCLazyModule(
    "Photos",
    "com.apple.photos",
    objc.pathForFramework("/System/Library/Frameworks/Photos.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['Photos._metadata']
