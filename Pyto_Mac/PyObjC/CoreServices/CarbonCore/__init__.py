'''
Python mapping for the CoreServices/CarbonCore framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.

Note that PyObjC only wrappers the non-deprecated parts of the CoreServices
framework.
'''
import sys
import objc

from CoreServices.CarbonCore import _metadata
from CoreServices._inlines import _inline_list_

sys.modules['CoreServices.CarbonCore'] = mod = objc.ObjCLazyModule('CoreServices.CarbonCore',
    "com.apple.CarbonCore",
    objc.pathForFramework("/System/Library/Frameworks/CoreServices.framework"),
    _metadata.__dict__, _inline_list_, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ())

import sys
del sys.modules['CoreServices.CarbonCore._metadata']
