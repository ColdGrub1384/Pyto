'''
Python mapping for the ServiceManagement framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import CoreFoundation

from ServiceManagement import _metadata

sys.modules['ServiceManagement'] = mod = objc.ObjCLazyModule('ServiceManagement',
    "com.apple.bsd.ServiceManagement",
    objc.pathForFramework("/System/Library/Frameworks/ServiceManagement.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( CoreFoundation, ))

import sys
del sys.modules['ServiceManagement._metadata']
