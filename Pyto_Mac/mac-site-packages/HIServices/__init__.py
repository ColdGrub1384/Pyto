'''
Python mapping for the HIServices framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Cocoa

from HIServices import _metadata

sys.modules['HIServices'] = mod = objc.ObjCLazyModule('HIServices',
    "com.apple.HIServices",
    objc.pathForFramework("/System/Library/Frameworks/ApplicationServices.framework/Frameworks/HIServices.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Cocoa, ))

import sys
del sys.modules['HIServices._metadata']
