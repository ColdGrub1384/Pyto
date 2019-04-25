'''
Python mapping for the PreferencePanes framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import AppKit

from PreferencePanes import _metadata

sys.modules['PreferencePanes'] = mod = objc.ObjCLazyModule('PreferencePanes',
    "com.apple.frameworks.preferencepanes",
    objc.pathForFramework("/System/Library/Frameworks/PreferencePanes.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( AppKit,))

import sys
del sys.modules['PreferencePanes._metadata']
