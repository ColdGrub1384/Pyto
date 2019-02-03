'''
Python mapping for the LaunchServices framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import objc, sys
import os
import Foundation

from CoreServices.LaunchServices import _metadata


sys.modules['CoreServices.LaunchServices'] = mod = objc.ObjCLazyModule(
    "LaunchServices",
    "com.apple.CoreServices",
    objc.pathForFramework('/System/Library/Frameworks/CoreServices.framework/CoreServices'),
    _metadata.__dict__, None, {
    '__doc__': __doc__,
    'objc': objc,
    '__path__': __path__,
    '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['CoreServices.LaunchServices._metadata']
