'''
Classes from the 'QuickLookThumbnailing' framework.
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

    
QLTThumbnailRequest = _Class('QLTThumbnailRequest')
QLTFileThumbnailRequest = _Class('QLTFileThumbnailRequest')
QLTUbiquitousFileThumbnailRequest = _Class('QLTUbiquitousFileThumbnailRequest')
QLThumbnailGenerationQueue = _Class('QLThumbnailGenerationQueue')
QLThumbnailProvider = _Class('QLThumbnailProvider')
QLFileThumbnailRequest = _Class('QLFileThumbnailRequest')
QLThumbnailReply = _Class('QLThumbnailReply')
QLThumbnailItem = _Class('QLThumbnailItem')
QLExternalThumbnailCache = _Class('QLExternalThumbnailCache')
QLTBitmapFormat = _Class('QLTBitmapFormat')
QLThumbnailAdditionEntry = _Class('QLThumbnailAdditionEntry')
QLThumbnailRepresentation = _Class('QLThumbnailRepresentation')
QLServiceThumbnailRenderer = _Class('QLServiceThumbnailRenderer')
QLThumbnailAddition = _Class('QLThumbnailAddition')
QLThumbnailAdditionCache = _Class('QLThumbnailAdditionCache')
QLThumbnailCachedAddition = _Class('QLThumbnailCachedAddition')
QLThumbnailServiceProxy = _Class('QLThumbnailServiceProxy')
QLThumbnailMetadata = _Class('QLThumbnailMetadata')
QLURLHandler = _Class('QLURLHandler')
QLExternalThumbnailCacheDatabase = _Class('QLExternalThumbnailCacheDatabase')
QLExternallyCachedThumbnailData = _Class('QLExternallyCachedThumbnailData')
QLThumbnailVersion = _Class('QLThumbnailVersion')
QLThumbnailGenerator = _Class('QLThumbnailGenerator')
QLThumbnailGenerationRequest = _Class('QLThumbnailGenerationRequest')
QLCacheVersionedFileIdentifier = _Class('QLCacheVersionedFileIdentifier')
QLCacheFileProviderVersionedFileIdentifier = _Class('QLCacheFileProviderVersionedFileIdentifier')
QLCacheBasicVersionedFileIdentifier = _Class('QLCacheBasicVersionedFileIdentifier')
QLCacheFileIdentifier = _Class('QLCacheFileIdentifier')
QLCacheFileProviderFileIdentifier = _Class('QLCacheFileProviderFileIdentifier')
QLCacheBasicFileIdentifier = _Class('QLCacheBasicFileIdentifier')
QLUTIAnalyzer = _Class('QLUTIAnalyzer')
QLThumbnailHostContext = _Class('QLThumbnailHostContext')
QLThumbnailServiceContext = _Class('QLThumbnailServiceContext')
QLAsynchronousOperation = _Class('QLAsynchronousOperation')
QLExtensionHostContextThumbnailOperation = _Class('QLExtensionHostContextThumbnailOperation')
QLThumbnailStoreRetrievalOperation = _Class('QLThumbnailStoreRetrievalOperation')
QLThumbnailRequestOperation = _Class('QLThumbnailRequestOperation')
QLTThumbnailOperation = _Class('QLTThumbnailOperation')
