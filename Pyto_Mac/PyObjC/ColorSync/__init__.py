'''
Python mapping for the ColorSync framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import CoreFoundation

from ColorSync import _metadata

sys.modules['ColorSync'] = mod = objc.ObjCLazyModule('ColorSync',
    "com.apple.ColorSync",
    objc.pathForFramework("/System/Library/Frameworks/ColorSync.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( CoreFoundation,))

import sys
del sys.modules['ColorSync._metadata']
