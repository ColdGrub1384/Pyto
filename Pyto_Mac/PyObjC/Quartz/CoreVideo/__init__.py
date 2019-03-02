'''
Python mapping for the CoreVideo framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import CoreFoundation

from Quartz.CoreVideo import _metadata

sys.modules['Quartz.CoreVideo'] = mod = objc.ObjCLazyModule('Quartz.CoreVideo',
    "com.apple.CoreVideo",
    objc.pathForFramework("/System/Library/Frameworks/CoreVideo.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( CoreFoundation, ))

import sys
del sys.modules['Quartz.CoreVideo._metadata']

def _load(mod):
    import Quartz
    Quartz.CoreVideo = mod
    import Quartz.CoreVideo._CVPixelBuffer as m
    for nm in dir(m):
        if nm.startswith('_'): continue
        setattr(mod, nm, getattr(m, nm))
_load(mod)
