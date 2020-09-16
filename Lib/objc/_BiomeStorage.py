'''
Classes from the 'BiomeStorage' framework.
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

    
BMFileLock = _Class('BMFileLock')
BMFrame = _Class('BMFrame')
BMStreamDatastorePruner = _Class('BMStreamDatastorePruner')
BMStreamDatastoreReader = _Class('BMStreamDatastoreReader')
BMStreamDatastoreWriter = _Class('BMStreamDatastoreWriter')
BMStreamMetadata = _Class('BMStreamMetadata')
BMStoreDirectory = _Class('BMStoreDirectory')
BMStreamDatastore = _Class('BMStreamDatastore')
BMStoreConfig = _Class('BMStoreConfig')
BMPublicStreamUtilities = _Class('BMPublicStreamUtilities')
BMStoreBookmark = _Class('BMStoreBookmark')
BMMemoryMapping = _Class('BMMemoryMapping')
BMFrameStore = _Class('BMFrameStore')
BMStoreEnumerator = _Class('BMStoreEnumerator')
BMStoreEvent = _Class('BMStoreEvent')
BMPBStoreBookmark = _Class('BMPBStoreBookmark')
