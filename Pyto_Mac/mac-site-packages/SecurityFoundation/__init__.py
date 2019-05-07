'''
Python mapping for the SecurityFoundation framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation
import Security

from SecurityFoundation import _metadata

sys.modules['SecurityFoundation'] = mod = objc.ObjCLazyModule(
    "SecurityFoundation",
    "com.apple.securityfoundatio",
    objc.pathForFramework("/System/Library/Frameworks/SecurityFoundation.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation, Security))

import sys
del sys.modules['SecurityFoundation._metadata']
