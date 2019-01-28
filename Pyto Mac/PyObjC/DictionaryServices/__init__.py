'''
Python mapping for the DictionaryServices framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import CoreServices

import warnings
warnings.warn("pyobjc-framework-DictionaryServices is deprecated, use 'import CoreServices' instead", DeprecationWarning)

sys.modules['DictionaryServices'] = mod = objc.ObjCLazyModule('DictionaryServices',
    "com.apple.CoreServices",
    objc.pathForFramework("/System/Library/Frameworks/CoreServices.framework"),
    None, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( CoreServices,))
