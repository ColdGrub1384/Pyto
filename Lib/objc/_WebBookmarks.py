'''
Classes from the 'WebBookmarks' framework.
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

    
WBSettingsTaskHandler = _Class('WBSettingsTaskHandler')
WebBookmarksXPCListener = _Class('WebBookmarksXPCListener')
WebBookmarksXPCConnection = _Class('WebBookmarksXPCConnection')
WBDatabaseLockAcquisitor = _Class('WBDatabaseLockAcquisitor')
WebBookmarksSettingsGateway = _Class('WebBookmarksSettingsGateway')
SafariFetcherServerProxy = _Class('SafariFetcherServerProxy')
WBFeatureManager = _Class('WBFeatureManager')
WBSettingsTask = _Class('WBSettingsTask')
WBBookmarksDatabaseHealthInformation = _Class('WBBookmarksDatabaseHealthInformation')
WBWebsiteDataRecord = _Class('WBWebsiteDataRecord')
WebBookmarkReadonlyCollection = _Class('WebBookmarkReadonlyCollection')
WebBookmarkListQuery = _Class('WebBookmarkListQuery')
WebBookmarkTitleWordTokenizer = _Class('WebBookmarkTitleWordTokenizer')
WebBookmarkWebFilterSettings = _Class('WebBookmarkWebFilterSettings')
WebBookmarkList = _Class('WebBookmarkList')
WebBookmarkCollectionSyncFlags = _Class('WebBookmarkCollectionSyncFlags')
WebBookmark = _Class('WebBookmark')
WBReadingList = _Class('WBReadingList')
WBReadingListPrivate = _Class('WBReadingListPrivate')
CloudTabServices = _Class('CloudTabServices')
WebBookmarkChangeSet = _Class('WebBookmarkChangeSet')
WebBookmarkChange = _Class('WebBookmarkChange')
WBDuplicateBookmarkGroup = _Class('WBDuplicateBookmarkGroup')
WebBookmarkInMemoryChangeFilterUnreadOnly = _Class('WebBookmarkInMemoryChangeFilterUnreadOnly')
BABookmarkItem = _Class('BABookmarkItem')
WebBookmarkCollection = _Class('WebBookmarkCollection')
WebBookmarkSecondaryCollection = _Class('WebBookmarkSecondaryCollection')
WebBookmarkCloudKitSyncCollection = _Class('WebBookmarkCloudKitSyncCollection')
BAChangeRecord = _Class('BAChangeRecord')
WebBookmarkDeviceIdentifier = _Class('WebBookmarkDeviceIdentifier')
