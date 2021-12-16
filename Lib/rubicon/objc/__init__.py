# Examples of valid version strings
# __version__ = '1.2.3.dev1'  # Development release 1
# __version__ = '1.2.3a1'     # Alpha Release 1
# __version__ = '1.2.3b1'     # Beta Release 1
# __version__ = '1.2.3rc1'    # RC Release 1
# __version__ = '1.2.3'       # Final Release
# __version__ = '1.2.3.post1' # Post Release 1

__version__ = '0.4.2'

# Import commonly used submodules right away.
# The first few imports are only included for clarity. They are not strictly necessary, because the from-imports below
# also import the types and runtime modules and implicitly add them to the rubicon.objc namespace.
from . import types  # noqa: F401
from . import runtime  # noqa: F401
from . import api  # noqa: F401
# The import of collections is important, however. The classes from collections are not meant to be used directly,
# instead they are registered with the runtime module (using the for_objcclass decorator) so they are used in place of
# ObjCInstance when representing Foundation collections in Python. If this module is not imported, the registration
# will not take place, and Foundation collections will not support the expected methods/operators in Python!
from . import collections  # noqa: F401

# Note to developers: when modifying any of the import lists below, please:
# * Keep each list in alphabetical order
# * Update the corresponding list in the documentation at docs/reference/rubicon-objc.rst
# Thank you!
from .types import (  # noqa: F401
    CFIndex, CFRange, CGFloat, CGGlyph, CGPoint, CGPointMake, CGRect, CGRectMake, CGSize, CGSizeMake, NSEdgeInsets,
    NSEdgeInsetsMake, NSInteger, NSMakePoint, NSMakeRect, NSMakeSize, NSPoint, NSRange, NSRect, NSSize, NSTimeInterval,
    NSUInteger, NSZeroPoint, UIEdgeInsets, UIEdgeInsetsMake, UIEdgeInsetsZero, UniChar, unichar,
)
from .runtime import SEL, send_message, send_super  # noqa: F401
from .api import (  # noqa: F401
    Block, NSArray, NSDictionary, NSMutableArray, NSMutableDictionary, NSObject, NSObjectProtocol, ObjCBlock,
    ObjCClass, ObjCInstance, ObjCMetaClass, ObjCProtocol, at, ns_from_py, objc_classmethod, objc_const, objc_ivar,
    objc_method, objc_property, objc_rawmethod, py_from_ns,
)
