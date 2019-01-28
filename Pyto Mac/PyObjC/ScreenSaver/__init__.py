'''
Python mapping for the ScreenSaver framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import AppKit

from ScreenSaver import _metadata
from ScreenSaver._inlines import _inline_list_

sys.modules['ScreenSaver'] = mod = objc.ObjCLazyModule('ScreenSaver',
    "com.apple.ScreenSaver",
    objc.pathForFramework("/System/Library/Frameworks/ScreenSaver.framework"),
    _metadata.__dict__, _inline_list_, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( AppKit,))

import sys
del sys.modules['ScreenSaver._metadata']
