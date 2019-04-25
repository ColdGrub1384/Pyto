'''
Python mapping for the InstallerPlugins framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import AppKit

from InstallerPlugins import _metadata

sys.modules['InstallerPlugins'] = mod = objc.ObjCLazyModule('InstallerPlugins',
    "com.apple.InstallerPlugins",
    objc.pathForFramework("/System/Library/Frameworks/InstallerPlugins.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( AppKit,))

import sys
del sys.modules['InstallerPlugins._metadata']
