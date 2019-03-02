'''
Python mapping for the ApplicationServices framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Quartz.ImageIO
import Quartz.CoreGraphics
import CoreText
import HIServices
#import ATS
#import ColorSync
#import LangAnalysis
#import PrintCore
#import QD
#import SpeechSynthesis

sys.modules['ApplicationServices'] = mod = objc.ObjCLazyModule('ApplicationServices',
    "com.apple.ApplicationServices",
    objc.pathForFramework("/System/Library/Frameworks/ApplicationServices.framework"),
    {}, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, ( Quartz.ImageIO, Quartz.CoreGraphics, HIServices, CoreText ))
