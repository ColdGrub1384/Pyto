'''
Python mapping for the MediaPlayer framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import AVFoundation

from MediaPlayer import _metadata

sys.modules['MediaPlayer'] = mod = objc.ObjCLazyModule(
    "MediaPlayer",
    "com.apple.MediaPlayer",
    objc.pathForFramework("/System/Library/Frameworks/MediaPlayer.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (AVFoundation,))

import sys
del sys.modules['MediaPlayer._metadata']
