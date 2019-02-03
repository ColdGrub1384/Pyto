'''
Python mapping for the PubSub framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation

from PubSub import _metadata

sys.modules['PubSub'] = mod = objc.ObjCLazyModule('PubSub',
    "com.apple.PubSub",
    objc.pathForFramework("/System/Library/Frameworks/PubSub.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Foundation,))

import sys
del sys.modules['PubSub._metadata']
