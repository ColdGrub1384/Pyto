'''
Python mapping for the StoreKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from StoreKit import _metadata
import StoreKit._StoreKit

sys.modules['StoreKit'] = mod = objc.ObjCLazyModule(
    "StoreKit",
    "com.apple.StoreKit",
    objc.pathForFramework("/System/Library/Frameworks/StoreKit.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['StoreKit._metadata']
