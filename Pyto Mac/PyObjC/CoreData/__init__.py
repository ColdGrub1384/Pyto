'''
Python mapping for the CoreData framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import sys
import objc
import Foundation

from CoreData import _metadata
from CoreData._CoreData import *
import CoreData._convenience

sys.modules['CoreData'] = objc.ObjCLazyModule(
    "CoreData", "com.apple.CoreData",
    objc.pathForFramework("/System/Library/Frameworks/CoreData.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
        'objc': objc
    }, (Foundation,))

import sys
del sys.modules['CoreData._metadata']
