'''
Python mapping for the CoreML framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from CoreML import _metadata
from CoreML._CoreML import *


sys.modules['CoreML'] = mod = objc.ObjCLazyModule(
    "CoreML",
    "com.apple.CoreML",
    objc.pathForFramework("/System/Library/Frameworks/CoreML.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['CoreML._metadata']
