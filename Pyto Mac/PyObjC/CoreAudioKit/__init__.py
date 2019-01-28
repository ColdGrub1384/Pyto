'''
Python mapping for the CoreAudioKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from CoreAudioKit import _metadata
import CoreAudio

sys.modules['CoreAudioKit'] = mod = objc.ObjCLazyModule(
    "CoreAudio",
    "com.apple.CoreAudioKit",
    objc.pathForFramework("/System/Library/Frameworks/CoreAudioKit.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (CoreAudio, Foundation,))

import sys
del sys.modules['CoreAudioKit._metadata']
