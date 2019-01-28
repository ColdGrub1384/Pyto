'''
Python mapping for the DiskArbitration framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import CoreFoundation

from DiskArbitration import _metadata

sys.modules['DiskArbitration'] = mod = objc.ObjCLazyModule(
    "DiskArbitration",
    "com.apple.DiskArbitration",
    objc.pathForFramework("/System/Library/Frameworks/DiskArbitration.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (CoreFoundation,))

import sys
del sys.modules['DiskArbitration._metadata']
