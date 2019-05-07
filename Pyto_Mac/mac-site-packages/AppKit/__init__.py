'''
Python mapping for the AppKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation

from AppKit import _metadata
from AppKit._inlines import _inline_list_

def _setup_conveniences():
    def fontdescriptor_get(self, key, default=None):
        value = self.objectForKey_(key)
        if value is None:
            return default
        return value

    def fontdescriptor_getitem(self, key, default=None):
        value = self.objectForKey_(key)
        if value is None:
            raise KeyError(key)
        return value

    objc.addConvenienceForClass('NSFontDescriptor', (
        ('__getitem__',  fontdescriptor_getitem),
        ('get',          fontdescriptor_get),
    ))

_setup_conveniences()

def NSDictionaryOfVariableBindings(*names):
    """
    Return a dictionary with the given names and there values.
    """
    import sys
    variables = sys._getframe(1).f_locals

    return {
        nm: variables[nm]
        for nm in names
    }


sys.modules['AppKit'] = mod = objc.ObjCLazyModule('AppKit',
        "com.apple.AppKit", objc.pathForFramework("/System/Library/Frameworks/AppKit.framework"),
        _metadata.__dict__, _inline_list_, {
            '__doc__': __doc__,
            'objc': objc,
            'NSDictionaryOfVariableBindings': NSDictionaryOfVariableBindings,
            '__path__': __path__,
            '__loader__': globals().get('__loader__', None),
        }, (Foundation,))

# NSApp is a global variable that can be changed in ObjC,
# somewhat emulate that (it is *not* possible to assign to
# NSApp in Python)
from AppKit._nsapp import NSApp
mod.NSApp = NSApp

# Manually written wrappers:
import AppKit._AppKit
for nm in dir(AppKit._AppKit):
    setattr(mod, nm, getattr(AppKit._AppKit, nm))

# Fix types for a number of character constants
try:
    unichr
except NameError:
    unichr = chr
mod.NSEnterCharacter = unichr(mod.NSEnterCharacter)
mod.NSBackspaceCharacter = unichr(mod.NSBackspaceCharacter)
mod.NSTabCharacter = unichr(mod.NSTabCharacter)
mod.NSNewlineCharacter = unichr(mod.NSNewlineCharacter)
mod.NSFormFeedCharacter = unichr(mod.NSFormFeedCharacter)
mod.NSCarriageReturnCharacter = unichr(mod.NSCarriageReturnCharacter)
mod.NSBackTabCharacter = unichr(mod.NSBackTabCharacter)
mod.NSDeleteCharacter = unichr(mod.NSDeleteCharacter)
mod.NSLineSeparatorCharacter = unichr(mod.NSLineSeparatorCharacter)
mod.NSParagraphSeparatorCharacter = unichr(mod.NSParagraphSeparatorCharacter)


for nm in [
   "NSUpArrowFunctionKey",
   "NSDownArrowFunctionKey",
   "NSLeftArrowFunctionKey",
   "NSRightArrowFunctionKey",
   "NSF1FunctionKey",
   "NSF2FunctionKey",
   "NSF3FunctionKey",
   "NSF4FunctionKey",
   "NSF5FunctionKey",
   "NSF6FunctionKey",
   "NSF7FunctionKey",
   "NSF8FunctionKey",
   "NSF9FunctionKey",
   "NSF10FunctionKey",
   "NSF11FunctionKey",
   "NSF12FunctionKey",
   "NSF13FunctionKey",
   "NSF14FunctionKey",
   "NSF15FunctionKey",
   "NSF16FunctionKey",
   "NSF17FunctionKey",
   "NSF18FunctionKey",
   "NSF19FunctionKey",
   "NSF20FunctionKey",
   "NSF21FunctionKey",
   "NSF22FunctionKey",
   "NSF23FunctionKey",
   "NSF24FunctionKey",
   "NSF25FunctionKey",
   "NSF26FunctionKey",
   "NSF27FunctionKey",
   "NSF28FunctionKey",
   "NSF29FunctionKey",
   "NSF30FunctionKey",
   "NSF31FunctionKey",
   "NSF32FunctionKey",
   "NSF33FunctionKey",
   "NSF34FunctionKey",
   "NSF35FunctionKey",
   "NSInsertFunctionKey",
   "NSDeleteFunctionKey",
   "NSHomeFunctionKey",
   "NSBeginFunctionKey",
   "NSEndFunctionKey",
   "NSPageUpFunctionKey",
   "NSPageDownFunctionKey",
   "NSPrintScreenFunctionKey",
   "NSScrollLockFunctionKey",
   "NSPauseFunctionKey",
   "NSSysReqFunctionKey",
   "NSBreakFunctionKey",
   "NSResetFunctionKey",
   "NSStopFunctionKey",
   "NSMenuFunctionKey",
   "NSUserFunctionKey",
   "NSSystemFunctionKey",
   "NSPrintFunctionKey",
   "NSClearLineFunctionKey",
   "NSClearDisplayFunctionKey",
   "NSInsertLineFunctionKey",
   "NSDeleteLineFunctionKey",
   "NSInsertCharFunctionKey",
   "NSDeleteCharFunctionKey",
   "NSPrevFunctionKey",
   "NSNextFunctionKey",
   "NSSelectFunctionKey",
   "NSExecuteFunctionKey",
   "NSUndoFunctionKey",
   "NSRedoFunctionKey",
   "NSFindFunctionKey",
   "NSHelpFunctionKey",
   "NSModeSwitchFunctionKey",
   ]:
    try:
        setattr(mod, nm, unichr(getattr(mod, nm)))
    except AttributeError:
        pass

try:
    mod.NSImageNameApplicationIcon
except AttributeError:
    mod.NSImageNameApplicationIcon = "NSApplicationIcon"

import sys
del sys.modules['AppKit._metadata']
