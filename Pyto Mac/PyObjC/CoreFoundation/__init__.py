'''
Python mapping for the CoreFoundation framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc

from CoreFoundation import _metadata
from CoreFoundation._inlines import _inline_list_

sys.modules['CoreFoundation'] = mod = objc.ObjCLazyModule('CoreFoundation',
    "com.apple.CoreFoundation", objc.pathForFramework("/System/Library/Frameworks/CoreFoundation.framework"),
    _metadata.__dict__, _inline_list_,
    {
        '__doc__': __doc__,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, ())

import CoreFoundation._CoreFoundation
import CoreFoundation._static
for nm in dir(CoreFoundation._CoreFoundation):
    setattr(mod, nm, getattr(CoreFoundation._CoreFoundation, nm))
for nm in dir(CoreFoundation._static):
    setattr(mod, nm, getattr(CoreFoundation._static, nm))

import sys
del sys.modules['CoreFoundation._metadata']
