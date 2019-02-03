'''
Python mapping for the MapKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Cocoa
import CoreLocation
import Quartz

from MapKit import _metadata, _MapKit
from MapKit._inlines import _inline_list_

sys.modules['MapKit'] = mod = objc.ObjCLazyModule(
    "MapKit",
    "com.apple.MapKit",
    objc.pathForFramework("/System/Library/Frameworks/MapKit.framework"),
    _metadata.__dict__, _inline_list_, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Cocoa, CoreLocation, Quartz))

import sys
del sys.modules['MapKit._metadata']
del sys.modules['MapKit._MapKit']
