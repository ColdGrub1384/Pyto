'''
Python mapping for the CloudKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from LocalAuthentication import _metadata

sys.modules['LocalAuthentication'] = mod = objc.ObjCLazyModule(
    "LocalAuthentication",
    "com.apple.LocalAuthentication",
    objc.pathForFramework("/System/Library/Frameworks/LocalAuthentication.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['LocalAuthentication._metadata']
