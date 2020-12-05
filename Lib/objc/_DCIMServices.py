"""
Classes from the 'DCIMServices' framework.
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


DCIMImageWellUtilities = _Class("DCIMImageWellUtilities")
DCIMImageWriter = _Class("DCIMImageWriter")
DCIMLocationUtilities = _Class("DCIMLocationUtilities")
DCIMAVMetadataUtilities = _Class("DCIMAVMetadataUtilities")
DCIMSlalomUtilities = _Class("DCIMSlalomUtilities")
DCIMDirectoryUtilities = _Class("DCIMDirectoryUtilities")
DCIMImageUtilities = _Class("DCIMImageUtilities")
DCIMAssetFormats = _Class("DCIMAssetFormats")
PLIOSurfaceData = _Class("PLIOSurfaceData")
