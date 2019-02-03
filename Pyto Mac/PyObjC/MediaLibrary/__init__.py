'''
Python mapping for the MediaLibrary framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Cocoa
import Quartz

from MediaLibrary import _metadata

sys.modules['MediaLibrary'] = mod = objc.ObjCLazyModule(
    "MediaLibrary",
    "com.apple.MediaLibrary",
    objc.pathForFramework("/System/Library/Frameworks/MediaLibrary.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Cocoa, Quartz))

import sys
del sys.modules['MediaLibrary._metadata']
