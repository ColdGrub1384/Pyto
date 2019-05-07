'''
Python mapping for the ScriptingBridge framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation

from ScriptingBridge import _metadata
from ScriptingBridge._ScriptingBridge import *

sys.modules['ScriptingBridge'] = mod = objc.ObjCLazyModule('ScriptingBridge',
    "com.apple.ScriptingBridge",
    objc.pathForFramework("/System/Library/Frameworks/ScriptingBridge.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Foundation,))

import sys
del sys.modules['ScriptingBridge._metadata']

# Override the default behaviour of the bridge to ensure that we
# make the minimal amount of AppleScript calls.
import objc
objc.addConvenienceForClass('SBElementArray', [
    ('__iter__', lambda self: iter(self.objectEnumerator())),
])
