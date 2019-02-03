'''
Python mapping for the DiscRecordingUI framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation
import DiscRecording

from DiscRecordingUI import _metadata


sys.modules['DiscRecordingUI'] = mod = objc.ObjCLazyModule(
    "DiscRecordingUI",
    "com.apple.DiscRecordingUI",
    objc.pathForFramework("/System/Library/Frameworks/DiscRecordingUI.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (DiscRecording, Foundation,))

import sys
del sys.modules['DiscRecordingUI._metadata']
