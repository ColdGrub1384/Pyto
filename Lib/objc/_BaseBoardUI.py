'''
Classes from the 'BaseBoardUI' framework.
'''

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

    
BSUIResolutionClass = _Class('BSUIResolutionClass')
BSUIMappedImageCacheFuture = _Class('BSUIMappedImageCacheFuture')
BSUIAnimationFactory = _Class('BSUIAnimationFactory')
_BSUIAnimationAttributesFactory = _Class('_BSUIAnimationAttributesFactory')
BSUIDateLabelFactory = _Class('BSUIDateLabelFactory')
BSUIMappedImageCacheOptions = _Class('BSUIMappedImageCacheOptions')
BSUIMappedImageCache = _Class('BSUIMappedImageCache')
BSUIFontProvider = _Class('BSUIFontProvider')
BSUIAnimationFactorySettings = _Class('BSUIAnimationFactorySettings')
BSUIAnimationFactoryDomain = _Class('BSUIAnimationFactoryDomain')
BSUIMappedSurfaceImage = _Class('BSUIMappedSurfaceImage')
BSUIEmojiLabelView = _Class('BSUIEmojiLabelView')
BSUICAPackageView = _Class('BSUICAPackageView')
BSUIBackdropView = _Class('BSUIBackdropView')
BSUIScrollView = _Class('BSUIScrollView')
BSUIDefaultDateLabel = _Class('BSUIDefaultDateLabel')
BSUIRelativeDateLabel = _Class('BSUIRelativeDateLabel')
