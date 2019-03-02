"""
Helper module that makes it easier to import all of Quartz
"""
import sys
import objc
import Foundation
import AppKit

def _load():
    submods = []
    sys.modules['Quartz'] = mod = objc.ObjCLazyModule('Quartz',
            None, None, {}, None, {
                '__doc__': __doc__,
                'objc': objc,
                '__path__': __path__,
                '__loader__': globals().get('__loader__', None),
            }, submods)


    try:
        from Quartz import CoreGraphics as m
        submods.append(m)
        mod.CoreGraphics = m
    except ImportError:
        pass

    try:
        from Quartz import ImageIO as m
        submods.append(m)
        mod.ImageIO = m
    except ImportError:
        pass

    try:
        from Quartz import ImageKit as m
        submods.append(m)
        mod.ImageIO = m
    except ImportError:
        pass

    try:
        from Quartz import CoreVideo as m
        submods.append(m)
        mod.CoreVideo = m
    except ImportError:
        pass

    try:
        from Quartz import QuartzCore as m
        submods.append(m)
        mod.QuartCore = m
    except ImportError:
        pass

    try:
        from Quartz import ImageIO as m
        submods.append(m)
        mod.ImageIO = m
    except ImportError:
        pass

    try:
        from Quartz import PDFKit as m
        submods.append(m)
        mod.PDFKit = m
    except ImportError:
        pass

    try:
        from Quartz import QuartzFilters as m
        submods.append(m)
        mod.QuartzFilters = m
    except ImportError:
        pass

    try:
        from Quartz import QuickLookUI as m
        submods.append(m)
        mod.QuickLookUI = m
    except ImportError:
        pass

_load()
