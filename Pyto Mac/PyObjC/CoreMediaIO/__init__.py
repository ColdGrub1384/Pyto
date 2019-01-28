'''
Python mapping for the CoreMediaIO framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from CoreMediaIO import _metadata

sys.modules['CoreMediaIO'] = mod = objc.ObjCLazyModule(
    "CoreMediaIO",
    "com.apple.CoreMediaIO",
    objc.pathForFramework("/System/Library/Frameworks/CoreMediaIO.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['CoreMediaIO._metadata']

from CoreMediaIO import _CoreMediaIO

for nm in dir(_CoreMediaIO):
    setattr(mod, nm, getattr(_CoreMediaIO, nm))

def CMIOGetNextSequenceNumber(value):
    if value == 0xffffffffffffffff:
        return 0
    return value + 1
mod.CMIOGetNextSequenceNumber = CMIOGetNextSequenceNumber

def CMIODiscontinuityFlagsHaveHardDiscontinuities(value):
    return (value & mod.kCMIOSampleBufferDiscontinuityFlag_DurationWasExtended) != 0

mod.CMIODiscontinuityFlagsHaveHardDiscontinuities = CMIODiscontinuityFlagsHaveHardDiscontinuities
