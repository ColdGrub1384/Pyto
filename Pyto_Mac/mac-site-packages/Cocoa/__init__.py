'''
Python mapping for the Cocoa framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation
import AppKit

mod = objc.ObjCLazyModule('Cocoa', None, None, {}, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (AppKit, Foundation))
sys.modules['Cocoa'] = mod
