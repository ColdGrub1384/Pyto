'''
Python mapping for the CoreText framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import CoreFoundation
import Quartz
import CoreText._manual

from CoreText import _metadata

sys.modules['CoreText'] = mod = objc.ObjCLazyModule('CoreText',
    "com.apple.CoreText",
    objc.pathForFramework("/System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreText.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( CoreFoundation, Quartz, CoreText._manual,))

import CoreText._manual as m
for nm in dir(m):
    setattr(mod, nm, getattr(m, nm))

import sys
del sys.modules['CoreText._metadata']
