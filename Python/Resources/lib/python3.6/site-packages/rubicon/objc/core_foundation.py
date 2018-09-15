from ctypes import c_double, c_ulong, cdll
from ctypes.util import find_library

from .runtime import objc_id

__all__ = [
    'CFAbsoluteTime',
    'CFAllocatorRef',
    'CFDataRef',
    'CFOptionFlags',
    'CFRunLoopRef',
    'CFStringRef',
    'CFTimeInterval',
    'CFTypeID',
    'CFTypeRef',
    'kCFAllocatorDefault',
    'kCFRunLoopDefaultMode',
    'libcf',
]


######################################################################

# CORE FOUNDATION

libcf = cdll.LoadLibrary(find_library('CoreFoundation'))

CFTypeID = c_ulong

# Core Foundation type refs. These are all treated as equivalent to objc_id.

CFTypeRef = objc_id

CFAllocatorRef = objc_id
kCFAllocatorDefault = None

CFDataRef = objc_id
CFOptionFlags = c_ulong
CFRunLoopRef = objc_id
CFStringRef = objc_id

CFTimeInterval = c_double
CFAbsoluteTime = CFTimeInterval

kCFRunLoopDefaultMode = CFStringRef.in_dll(libcf, 'kCFRunLoopDefaultMode')

libcf.CFRunLoopGetCurrent.restype = CFRunLoopRef
libcf.CFRunLoopGetCurrent.argtypes = []

libcf.CFRunLoopGetMain.restype = CFRunLoopRef
libcf.CFRunLoopGetMain.argtypes = []
