'''
Python mapping for the InputMethodKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation

from InputMethodKit import _metadata
from InputMethodKit._InputMethodKit import *

sys.modules['InputMethodKit'] = mod = objc.ObjCLazyModule('InputMethodKit',
    "com.apple.InputMethodKit",
    objc.pathForFramework("/System/Library/Frameworks/InputMethodKit.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Foundation,))

import sys
del sys.modules['InputMethodKit._metadata']
