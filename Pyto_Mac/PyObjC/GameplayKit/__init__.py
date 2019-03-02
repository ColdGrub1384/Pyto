'''
Python mapping for the GameplayKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Cocoa
import SpriteKit

from GameplayKit import _metadata
from GameplayKit._GameplayKit import *


sys.modules['GameplayKit'] = mod = objc.ObjCLazyModule(
    "GameplayKit",
    "com.apple.GameplayKit",
    objc.pathForFramework("/System/Library/Frameworks/GameplayKit.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Cocoa, SpriteKit))

import sys
del sys.modules['GameplayKit._metadata']
