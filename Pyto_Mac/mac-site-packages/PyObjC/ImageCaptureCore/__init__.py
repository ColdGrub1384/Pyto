'''
Python mapping for the ImageCaptureCore framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation

from ImageCaptureCore import _metadata, _ImageCaptureCore

sys.modules['ImageCaptureCore'] = mod = objc.ObjCLazyModule('ImageCaptureCore',
    "com.apple.ImageCaptureCoreFramework",
    objc.pathForFramework("/System/Library/Frameworks/ImageCaptureCore.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Foundation,))

import sys
del sys.modules['ImageCaptureCore._metadata']
