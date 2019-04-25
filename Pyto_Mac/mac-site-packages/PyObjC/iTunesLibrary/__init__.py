'''
Python mapping for the iTunesLibrary framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from iTunesLibrary import _metadata

sys.modules['iTunesLibrary'] = mod = objc.ObjCLazyModule(
    "iTunesLibrary",
    "com.apple.iTunesLibrary",
    objc.pathForFramework("/Library/Frameworks/iTunesLibrary.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['iTunesLibrary._metadata']
