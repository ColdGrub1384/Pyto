'''
Python mapping for the CoreServices/Metadata framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.

Note that PyObjC only wrappers the non-deprecated parts of the CoreServices
framework.
'''
import sys
import objc

from CoreServices.Metadata import _metadata

sys.modules['CoreServices.Metadata'] = mod = objc.ObjCLazyModule('CoreServices.Metadata',
    "com.apple.Metadata",
    objc.pathForFramework("/System/Library/Frameworks/CoreServices.framework"),
    _metadata.__dict__,
    None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ())

import sys
del sys.modules['CoreServices.Metadata._metadata']
