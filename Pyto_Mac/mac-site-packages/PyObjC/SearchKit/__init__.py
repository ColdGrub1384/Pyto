'''
Python mapping for the SearchKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import objc, sys

import CoreServices

import warnings
warnings.warn("pyobjc-framework-SearchKit is deprecated, use 'import CoreServices' instead", DeprecationWarning)


sys.modules['SearchKit'] = objc.ObjCLazyModule(
    "SearchKit", "com.apple.SearchKit",
    objc.pathForFramework(
        "/System/Library/Frameworks/CoreServices.framework/Frameworks/SearchKit.framework"),
    {}, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (CoreServices,))
