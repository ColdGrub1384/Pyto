'''
Python mapping for the UserNotifications framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from UserNotifications import _metadata
import UserNotifications._UserNotifications

sys.modules['UserNotifications'] = mod = objc.ObjCLazyModule(
    "UserNotifications",
    "com.apple.UserNotifications",
    objc.pathForFramework("/System/Library/Frameworks/UserNotifications.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['UserNotifications._metadata']
