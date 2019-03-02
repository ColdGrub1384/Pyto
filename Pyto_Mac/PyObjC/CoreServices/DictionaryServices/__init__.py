'''
Python mapping for the DictionaryServices framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation

from CoreServices.DictionaryServices import _metadata

sys.modules['CoreServices.DictionaryServices'] = mod = objc.ObjCLazyModule('DictionaryServices',
    "com.apple.CoreServices",
    objc.pathForFramework("/System/Library/Frameworks/CoreServices.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Foundation,))

import sys
del sys.modules['CoreServices.DictionaryServices._metadata']
