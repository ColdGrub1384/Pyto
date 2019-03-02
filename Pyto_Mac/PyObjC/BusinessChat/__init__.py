'''
Python mapping for the BusinessChat framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import AppKit

from BusinessChat import _metadata

sys.modules['BusinessChat'] = mod = objc.ObjCLazyModule(
    "BusinessChat",
    "com.apple.icloud.messages.apps.businessframework",
    objc.pathForFramework("/System/Library/Frameworks/BusinessChat.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (AppKit,))

import sys
del sys.modules['BusinessChat._metadata']
