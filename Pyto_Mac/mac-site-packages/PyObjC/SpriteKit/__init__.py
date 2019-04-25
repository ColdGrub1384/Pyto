'''
Python mapping for the SpriteKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Quartz
import Cocoa

from SpriteKit import _metadata
from SpriteKit import _SpriteKit

sys.modules['SpriteKit'] = mod = objc.ObjCLazyModule(
    "SpriteKit",
    "com.apple.SpriteKit",
    objc.pathForFramework("/System/Library/Frameworks/SpriteKit.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Cocoa, Quartz))


import sys, objc

mod = sys.modules['SpriteKit']
del sys.modules['SpriteKit._metadata']
