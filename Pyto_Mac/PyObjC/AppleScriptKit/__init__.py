'''
Python mapping for the AppleScriptKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import sys
import objc
import AppKit

from AppleScriptKit import _metadata

sys.modules['AppleScriptKit'] = mod = objc.ObjCLazyModule("AppleScriptKit",
    "com.apple.AppleScriptKit",
    objc.pathForFramework("/System/Library/Frameworks/AppleScriptKit.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (AppKit,))

import sys
del sys.modules['AppleScriptKit._metadata']
