'''
Python mapping for the Accounts framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from Accounts import _metadata

sys.modules['Accounts'] = mod = objc.ObjCLazyModule(
    "Accounts",
    "com.apple.Accounts",
    objc.pathForFramework("/System/Library/Frameworks/Accounts.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['Accounts._metadata']
