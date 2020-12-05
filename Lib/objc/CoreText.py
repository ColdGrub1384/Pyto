"""
Classes from the 'CoreText' framework.
"""

try:
    from rubicon.objc import ObjCClass
except ValueError:

    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None


FontAssetDownloadManager = _Class("FontAssetDownloadManager")
NSRubyAnnotation = _Class("NSRubyAnnotation")
NSCTRubyAnnotation = _Class("NSCTRubyAnnotation")
_CTGCommonCache = _Class("_CTGCommonCache")
_CTSplicedFontKey = _Class("_CTSplicedFontKey")
CTGlyphStorageInterface = _Class("CTGlyphStorageInterface")
_CTGlyphStorage = _Class("_CTGlyphStorage")
_CTMutableGlyphStorage = _Class("_CTMutableGlyphStorage")
_CTNativeGlyphStorage = _Class("_CTNativeGlyphStorage")
CTFeatureSetting = _Class("CTFeatureSetting")
_CTFontFallbacksArray = _Class("_CTFontFallbacksArray")
