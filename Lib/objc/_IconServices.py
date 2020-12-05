"""
Classes from the 'IconServices' framework.
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


ISImageSpecification = _Class("ISImageSpecification")
ISHintedValue = _Class("ISHintedValue")
ISHintedFloat = _Class("ISHintedFloat")
ISHintedSize = _Class("ISHintedSize")
ISHintedRect = _Class("ISHintedRect")
ISIconObserver = _Class("ISIconObserver")
ISIconDecoration = _Class("ISIconDecoration")
ISiosDocumentRecipe = _Class("ISiosDocumentRecipe")
ISmacosDocumentRecipe = _Class("ISmacosDocumentRecipe")
ISiosmacDocumentRecipe = _Class("ISiosmacDocumentRecipe")
ISSymbolImageDescriptor = _Class("ISSymbolImageDescriptor")
ISImageDescriptor = _Class("ISImageDescriptor")
ISImage = _Class("ISImage")
ISSymbolImage = _Class("ISSymbolImage")
ISPlaceholderImage = _Class("ISPlaceholderImage")
ISConcreteImage = _Class("ISConcreteImage")
ISCacheImage = _Class("ISCacheImage")
ISDeviceInfo = _Class("ISDeviceInfo")
ISBlurEffect = _Class("ISBlurEffect")
ISBorderEffect = _Class("ISBorderEffect")
ISDimmedDarkEffect = _Class("ISDimmedDarkEffect")
ISDimmedEffect = _Class("ISDimmedEffect")
ISEmbossedEffect = _Class("ISEmbossedEffect")
ISDropShaddowEffect = _Class("ISDropShaddowEffect")
ISIconManager = _Class("ISIconManager")
ISImageBag = _Class("ISImageBag")
ISIconResourceLocator = _Class("ISIconResourceLocator")
ISIconTypeResourceLocator = _Class("ISIconTypeResourceLocator")
ISBundle = _Class("ISBundle")
ISCenterEmbossRecipe = _Class("ISCenterEmbossRecipe")
ISLeadingStatusBadgeRecipe = _Class("ISLeadingStatusBadgeRecipe")
ISTrailingStatusBadgeRecipe = _Class("ISTrailingStatusBadgeRecipe")
ISShapeCompositorResource = _Class("ISShapeCompositorResource")
ISCircle = _Class("ISCircle")
ISContinuousRoundedRect = _Class("ISContinuousRoundedRect")
ISDefaults = _Class("ISDefaults")
ISIconDecorationResource = _Class("ISIconDecorationResource")
ISGraphicsContext = _Class("ISGraphicsContext")
ISColor = _Class("ISColor")
ISLayer = _Class("ISLayer")
ISCompositor = _Class("ISCompositor")
_ISCompositorElement = _Class("_ISCompositorElement")
ISIconSpecification = _Class("ISIconSpecification")
ISImageCache = _Class("ISImageCache")
ISIconCacheIOS = _Class("ISIconCacheIOS")
ISIconCacheClient = _Class("ISIconCacheClient")
ISIcon = _Class("ISIcon")
ISGenericIconIOS = _Class("ISGenericIconIOS")
ISIconIOS = _Class("ISIconIOS")
ISBundleIcon = _Class("ISBundleIcon")
ISImageBagIcon = _Class("ISImageBagIcon")
ISIconFactory = _Class("ISIconFactory")
ISGenericRecipe = _Class("ISGenericRecipe")
ISMessagesAppRecipe = _Class("ISMessagesAppRecipe")
ISwatchOSAppRecipe = _Class("ISwatchOSAppRecipe")
ISiOSAppClipRecipe = _Class("ISiOSAppClipRecipe")
ISiOSAppRecipe = _Class("ISiOSAppRecipe")
ISiOSMacAppRecipe = _Class("ISiOSMacAppRecipe")
ISAssetCatalogResource = _Class("ISAssetCatalogResource")
ISResourceMetadata = _Class("ISResourceMetadata")
ISIconLayer = _Class("ISIconLayer")
