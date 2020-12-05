"""
Classes from the 'QuickLookSupport' framework.
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


QLExtensionPreview = _Class("QLExtensionPreview")
QLURLExtensionPreview = _Class("QLURLExtensionPreview")
QLCoreSpotlightExtensionPreview = _Class("QLCoreSpotlightExtensionPreview")
QLZipArchive = _Class("QLZipArchive")
QLZipArchiveEntry = _Class("QLZipArchiveEntry")
QLExtension = _Class("QLExtension")
QLGracePeriodTimer = _Class("QLGracePeriodTimer")
QLPlatformImage = _Class("QLPlatformImage")
QLExtensionManager = _Class("QLExtensionManager")
QLUTIManager = _Class("QLUTIManager")
QLThumbnailUTICache = _Class("QLThumbnailUTICache")
QLExtensionThumbnailGenerator = _Class("QLExtensionThumbnailGenerator")
QLExtensionManagerCache = _Class("QLExtensionManagerCache")
