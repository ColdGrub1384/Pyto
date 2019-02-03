'''
Python mapping for the SafariServices framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from SafariServices import _metadata
from SafariServices._SafariServices import *


sys.modules['SafariServices'] = mod = objc.ObjCLazyModule(
    "SafariServices",
    "com.apple.SafariServices",
    objc.pathForFramework("/System/Library/Frameworks/SafariServices.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['SafariServices._metadata']
