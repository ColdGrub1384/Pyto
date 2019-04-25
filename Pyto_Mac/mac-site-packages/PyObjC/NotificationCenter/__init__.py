'''
Python mapping for the NotificationCenter framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Cocoa

from NotificationCenter import _metadata, _NotificationCenter

sys.modules['NotificationCenter'] = mod = objc.ObjCLazyModule(
    "NotificationCenter",
    "com.apple.notificationcenter",
    objc.pathForFramework("/System/Library/Frameworks/NotificationCenter.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Cocoa, ))

import sys
del sys.modules['NotificationCenter._metadata']
del sys.modules['NotificationCenter._NotificationCenter']
