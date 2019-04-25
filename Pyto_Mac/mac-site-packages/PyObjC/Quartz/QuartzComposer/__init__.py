'''
Python mapping for the QuartzComposer framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Quartz.CoreGraphics
import Foundation

from Quartz.QuartzComposer import _metadata

sys.modules['Quartz.QuartzComposer'] = mod = objc.ObjCLazyModule('Quartz.QuartzComposer',
    "com.apple.QuartzComposer",
    objc.pathForFramework("/System/Library/Frameworks/Quartz.framework/Frameworks/QuartzComposer.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Quartz.CoreGraphics, Foundation,))

import sys
del sys.modules['Quartz.QuartzComposer._metadata']
