'''
Python mapping for the Photos framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from PhotosUI import _metadata
import PhotosUI._PhotosUI

sys.modules['PhotosUI'] = mod = objc.ObjCLazyModule(
    "PhotosUI",
    "com.apple.photosui",
    objc.pathForFramework("/System/Library/Frameworks/PhotosUI.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['PhotosUI._metadata']
