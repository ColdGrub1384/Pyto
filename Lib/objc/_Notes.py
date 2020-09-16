'''
Classes from the 'Notes' framework.
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

    
ICRadarUtilities = _Class('ICRadarUtilities')
ICExclusiveLock = _Class('ICExclusiveLock')
ICSearchRankingStrategySwitch = _Class('ICSearchRankingStrategySwitch')
ICWeakObject = _Class('ICWeakObject')
ICCDCSIReindexer = _Class('ICCDCSIReindexer')
ICSettingsUtilities = _Class('ICSettingsUtilities')
ICSearchIndexConfiguration = _Class('ICSearchIndexConfiguration')
ICSpotlightUtilities = _Class('ICSpotlightUtilities')
ICBackoffTimer = _Class('ICBackoffTimer')
ICFolderCustomNoteSortType = _Class('ICFolderCustomNoteSortType')
ICUtilities = _Class('ICUtilities')
AccountUtilities = _Class('AccountUtilities')
NotesMigrationMapping = _Class('NotesMigrationMapping')
NotesMigrationManager = _Class('NotesMigrationManager')
ICSearchQueryParser = _Class('ICSearchQueryParser')
ICReachability = _Class('ICReachability')
ICRankingQueriesDefinition = _Class('ICRankingQueriesDefinition')
ICSelectorDelayer = _Class('ICSelectorDelayer')
ICNoteListSortUtilities = _Class('ICNoteListSortUtilities')
ICPaths = _Class('ICPaths')
ICBaseSearchIndexerDataSource = _Class('ICBaseSearchIndexerDataSource')
ICHTMLSearchIndexerDataSource = _Class('ICHTMLSearchIndexerDataSource')
ICNoteSnippetUtilities = _Class('ICNoteSnippetUtilities')
ICAssert = _Class('ICAssert')
ICSearchIndexer = _Class('ICSearchIndexer')
ICRankingQueryDescriptor = _Class('ICRankingQueryDescriptor')
ICManagedObjectContextUpdater = _Class('ICManagedObjectContextUpdater')
NotesLocalization = _Class('NotesLocalization')
ICReindexer = _Class('ICReindexer')
NoteContext = _Class('NoteContext')
NoteResurrectionMergePolicy = _Class('NoteResurrectionMergePolicy')
ExternalSequenceNumberToAttachmentNoteBodyToAttachmentMigrationPolicy = _Class('ExternalSequenceNumberToAttachmentNoteBodyToAttachmentMigrationPolicy')
ICCoreDataCoreSpotlightDelegate = _Class('ICCoreDataCoreSpotlightDelegate')
ICMutableSetOfNumbersSecureUnarchiveFromDataTransformer = _Class('ICMutableSetOfNumbersSecureUnarchiveFromDataTransformer')
ICNSStringOrNumberSecureUnarchiveFromDataTransformer = _Class('ICNSStringOrNumberSecureUnarchiveFromDataTransformer')
NoteAttachmentObject = _Class('NoteAttachmentObject')
NoteObject = _Class('NoteObject')
MNFNoteProperty = _Class('MNFNoteProperty')
NoteCollectionObject = _Class('NoteCollectionObject')
NoteAccountObject = _Class('NoteAccountObject')
NoteStoreObject = _Class('NoteStoreObject')
NoteChangeObject = _Class('NoteChangeObject')
NoteBodyObject = _Class('NoteBodyObject')
ICIndexItemsOperation = _Class('ICIndexItemsOperation')
ICIndexItemsByIdentifiersOperation = _Class('ICIndexItemsByIdentifiersOperation')
ICReindexAllItemsOperation = _Class('ICReindexAllItemsOperation')
