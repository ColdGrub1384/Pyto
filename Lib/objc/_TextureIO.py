'''
Classes from the 'TextureIO' framework.
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

    
TXRDataConverter = _Class('TXRDataConverter')
TXRParserKTX = _Class('TXRParserKTX')
TXRPixelFormatInfo = _Class('TXRPixelFormatInfo')
TXRAssetCatalogSet = _Class('TXRAssetCatalogSet')
TXRAssetCatalogConfig = _Class('TXRAssetCatalogConfig')
TXRAssetCatalogFileAttributes = _Class('TXRAssetCatalogFileAttributes')
TXRAssetCatalogMipFileAttributes = _Class('TXRAssetCatalogMipFileAttributes')
TXRTextureInfo = _Class('TXRTextureInfo')
TXRImageInfo = _Class('TXRImageInfo')
TXRParserImageIO = _Class('TXRParserImageIO')
TXRAssetCatalogParser = _Class('TXRAssetCatalogParser')
TXRFileDataSourceProvider = _Class('TXRFileDataSourceProvider')
TXRDeferredTextureInfo = _Class('TXRDeferredTextureInfo')
TXRDeferredMipmapInfo = _Class('TXRDeferredMipmapInfo')
TXRDeferredElementInfo = _Class('TXRDeferredElementInfo')
TXRDeferredImageInfo = _Class('TXRDeferredImageInfo')
TXRTexture = _Class('TXRTexture')
TXRMipmapLevel = _Class('TXRMipmapLevel')
TXRArrayElement = _Class('TXRArrayElement')
TXRImage = _Class('TXRImage')
TXRImageIndependent = _Class('TXRImageIndependent')
TXRDataScaler = _Class('TXRDataScaler')
TXRDefaultBufferAllocator = _Class('TXRDefaultBufferAllocator')
TXRDefaultBuffer = _Class('TXRDefaultBuffer')
TXRDefaultBufferMap = _Class('TXRDefaultBufferMap')
TXROptions = _Class('TXROptions')
