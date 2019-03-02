'''
Python mapping for the ExternalAccessory framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from ExternalAccessory import _metadata
from ExternalAccessory._ExternalAccessory import *

sys.modules['ExternalAccessory'] = mod = objc.ObjCLazyModule(
    "ExternalAccessory",
    "com.apple.externalaccessory",
    objc.pathForFramework("/System/Library/Frameworks/ExternalAccessory.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['ExternalAccessory._metadata']
