'''
Python mapping for the NaturalLanguage framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from NaturalLanguage import _metadata

sys.modules['NaturalLanguage'] = mod = objc.ObjCLazyModule(
    "NaturalLanguage",
    "com.apple.NaturalLanguage",
    objc.pathForFramework("/System/Library/Frameworks/NaturalLanguage.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['NaturalLanguage._metadata']
