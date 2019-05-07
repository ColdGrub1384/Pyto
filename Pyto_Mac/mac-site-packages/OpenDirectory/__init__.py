"""
Wrappers for the OpenDirectory framework
"""
import sys
import objc
import CFOpenDirectory

from OpenDirectory import _metadata

sys.modules['OpenDirectory'] = mod = objc.ObjCLazyModule('OpenDirectory',
    "com.apple.OpenDirectory",
    objc.pathForFramework("/System/Library/Frameworks/OpenDirectory.framework/Frameworks/OpenDirectory.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, (CFOpenDirectory,))

import sys
del sys.modules['OpenDirectory._metadata']
