'''
Python mapping for the Network framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from Network import _metadata

sys.modules['Network'] = mod = objc.ObjCLazyModule(
    "Network",
    "com.apple.Network",
    objc.pathForFramework("/System/Library/Frameworks/Network.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['Network._metadata']

import Network._Network as _manual
for nm in dir(_manual):
    if nm.startswith('__'): continue
    setattr(mod, nm, getattr(_manual, nm))

