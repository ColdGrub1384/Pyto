'''
Python mapping for the Social framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from Social import _metadata

sys.modules['Social'] = mod = objc.ObjCLazyModule(
    "Social",
    "com.apple.Social.framework",
    objc.pathForFramework("/System/Library/Frameworks/Social.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['Social._metadata']
