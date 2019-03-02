'''
Python mapping for the AddressBook framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Cocoa

from MediaAccessibility import _metadata

sys.modules['MediaAccessibility'] = mod = objc.ObjCLazyModule(
    "MediaAccessibility",
    "com.apple.MediaAccessibility",
    objc.pathForFramework("/System/Library/Frameworks/MediaAccessibility.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Cocoa,))

import sys
del sys.modules['MediaAccessibility._metadata']
