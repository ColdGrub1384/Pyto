'''
Python mapping for the CalendarStore framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import sys
import objc
import Foundation

from CalendarStore import _metadata

sys.modules['CalendarStore'] = objc.ObjCLazyModule(
    "CalendarStore", "com.apple.CalendarStore",
    objc.pathForFramework("/System/Library/Frameworks/CalendarStore.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        '__path__': __path__,
        'objc': objc,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['CalendarStore._metadata']
