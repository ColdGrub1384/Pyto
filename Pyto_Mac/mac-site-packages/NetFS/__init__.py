'''
Python mapping for the NetFS framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from NetFS import _metadata

try:
    long
except NameError:
    long = int

sys.modules['NetFS'] = mod = objc.ObjCLazyModule(
    "NetFS",
    "com.apple.NetFS",
    objc.pathForFramework("/System/Library/Frameworks/NetFS.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['NetFS._metadata']
