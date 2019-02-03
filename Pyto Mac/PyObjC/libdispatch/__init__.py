'''
Python mapping for the dispatch library on macOS

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions.
'''

import objc
import sys

from libdispatch import _metadata
from libdispatch._inlines import _inline_list_


sys.modules['libdispatch'] = mod = objc.ObjCLazyModule(
    "libdispatch",
    None,
    None,
    _metadata.__dict__, _inline_list_, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    })

import libdispatch._libdispatch as _manual
for nm in dir(_manual):
    if nm.startswith('__'): continue
    setattr(mod, nm, getattr(_manual, nm))

import sys
del sys.modules['libdispatch._metadata']
