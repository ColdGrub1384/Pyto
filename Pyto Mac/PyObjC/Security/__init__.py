'''
Python mapping for the Security framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from Security import _metadata
from Security import _Security

sys.modules['Security'] = mod = objc.ObjCLazyModule(
    "Security",
    "com.apple.security",
    objc.pathForFramework("/System/Library/Frameworks/Security.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (_Security, Foundation,))

import sys
del sys.modules['Security._metadata']
