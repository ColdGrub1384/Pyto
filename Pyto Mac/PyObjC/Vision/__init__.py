'''
Python mapping for the Vision framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation
import Quartz
import CoreML

from Vision import _metadata
from Vision._Vision import *


sys.modules['Vision'] = mod = objc.ObjCLazyModule(
    "Vision",
    "com.apple.Vision",
    objc.pathForFramework("/System/Library/Frameworks/Vision.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation, Quartz, CoreML))

import sys
del sys.modules['Vision._metadata']
