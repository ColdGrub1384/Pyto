'''
Python mapping for the AddressBook framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from AddressBook import _metadata
from AddressBook._AddressBook import *

try:
    long
except NameError:
    long = int

sys.modules['AddressBook'] = mod = objc.ObjCLazyModule(
    "AddressBook",
    "com.apple.AddressBook.framework",
    objc.pathForFramework("/System/Library/Frameworks/AddressBook.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (Foundation,))

import sys
del sys.modules['AddressBook._metadata']
