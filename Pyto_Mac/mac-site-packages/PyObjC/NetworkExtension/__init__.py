'''
Python mapping for the NetworkExtension framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from NetworkExtension import _metadata, _NetworkExtension

sys.modules['NetworkExtension'] = mod = objc.ObjCLazyModule(
    "NetworkExtension",
    "com.apple.NetworkExtension",
    objc.pathForFramework("/System/Library/Frameworks/NetworkExtension.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['NetworkExtension._metadata']
