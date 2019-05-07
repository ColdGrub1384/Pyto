'''
Python mapping for the CloudKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Accounts
import Foundation
import CoreData
import CoreLocation

from CloudKit import _metadata

sys.modules['CloudKit'] = mod = objc.ObjCLazyModule(
    "CloudKit",
    "com.apple.CloudKit",
    objc.pathForFramework("/System/Library/Frameworks/CloudKit.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (CoreData, CoreLocation, Accounts, Foundation))

import sys
del sys.modules['CloudKit._metadata']
