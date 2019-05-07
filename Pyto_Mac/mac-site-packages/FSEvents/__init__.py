'''
Python mapping for the FSEvents framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation
import FSEvents._callbacks

from FSEvents import _metadata

sys.modules['FSEvents'] = mod = objc.ObjCLazyModule('FSEvents',
    "com.apple.CoreServices",
    objc.pathForFramework("/System/Library/Frameworks/CoreServices.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( FSEvents._callbacks, Foundation))

import sys
del sys.modules['FSEvents._metadata']
