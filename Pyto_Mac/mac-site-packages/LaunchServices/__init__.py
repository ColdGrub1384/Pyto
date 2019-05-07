'''
Python mapping for the LaunchServices framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import objc, sys
import os
import CoreServices

import warnings
warnings.warn("pyobjc-framework-LaunchServices is deprecated, use 'import CoreServices' instead", DeprecationWarning)

sys.modules['LaunchServices'] = mod = objc.ObjCLazyModule(
    "LaunchServices",
    "com.apple.CoreServices",
    objc.pathForFramework('/System/Library/Frameworks/CoreServices.framework/CoreServices'),
    {}, None, {
    '__doc__': __doc__,
    'objc': objc,
    '__path__': __path__,
    '__loader__': globals().get('__loader__', None),
    }, (CoreServices,))
