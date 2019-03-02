'''
Python mapping for the Automator framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import sys
import objc
import AppKit
from Automator import _metadata

sys.modules['Automator'] = objc.ObjCLazyModule('Automator',
        "com.apple.AutomatorFramework", objc.pathForFramework("/System/Library/Frameworks/Automator.framework"),
        _metadata.__dict__, None, {
            '__doc__': __doc__,
            '__path__': __path__,
            'objc': objc,
            '__loader__': globals().get('__loader__', None),
        }, (AppKit,))

import sys
del sys.modules['Automator._metadata']
