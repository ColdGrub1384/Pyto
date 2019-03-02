'''
Python mapping for the QuickLookUI framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Cocoa

from Quartz.QuickLookUI import _metadata
import Quartz.QuickLookUI._QuickLookUI

sys.modules['Quartz.QuickLookUI'] = mod = objc.ObjCLazyModule('Quartz.QuickLookUI',
    "com.apple.QuickLookUIFramework",
    objc.pathForFramework("/System/Library/Frameworks/Quartz.framework/Frameworks/QuickLookUI.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Cocoa,))

import sys
del sys.modules['Quartz.QuickLookUI._metadata']
