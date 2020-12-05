"""
Classes from the 'DataAccess' framework.
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


DAActivity = _Class("DAActivity")
DABabysitter = _Class("DABabysitter")
DAContactsContainer = _Class("DAContactsContainer")
DAPriorityManager = _Class("DAPriorityManager")
DAPriorityRequest = _Class("DAPriorityRequest")
DATrafficLogger = _Class("DATrafficLogger")
DAABLegacyAccount = _Class("DAABLegacyAccount")
DATrustHandler = _Class("DATrustHandler")
DAiCalendarLogger = _Class("DAiCalendarLogger")
DAUserNotificationInfo = _Class("DAUserNotificationInfo")
DAUserNotificationUtilities = _Class("DAUserNotificationUtilities")
DAAggDReporter = _Class("DAAggDReporter")
DATransaction = _Class("DATransaction")
DAContactsAccountProvider = _Class("DAContactsAccountProvider")
_DAContactsAccountABLegacyProvider = _Class("_DAContactsAccountABLegacyProvider")
_DAContactsAccountContactsProvider = _Class("_DAContactsAccountContactsProvider")
DALocalDBGateKeeper = _Class("DALocalDBGateKeeper")
DAWaiterWrapper = _Class("DAWaiterWrapper")
DARunLoopRegistry = _Class("DARunLoopRegistry")
DALocalDBWatcher = _Class("DALocalDBWatcher")
DAStoreSyncStatusUpdater = _Class("DAStoreSyncStatusUpdater")
DADataHandler = _Class("DADataHandler")
DAAccountUpgrader = _Class("DAAccountUpgrader")
DAContainerProvider = _Class("DAContainerProvider")
_DAContactsContainerProvider = _Class("_DAContactsContainerProvider")
_DAABLegacyContainerProvider = _Class("_DAABLegacyContainerProvider")
DAPowerAssertionManager = _Class("DAPowerAssertionManager")
DALocalDBHelper = _Class("DALocalDBHelper")
DATaskManager = _Class("DATaskManager")
DAContactsBasedAccount = _Class("DAContactsBasedAccount")
DAMailMessage = _Class("DAMailMessage")
DAResolvedRecipient = _Class("DAResolvedRecipient")
DAResolveRecipientsRequest = _Class("DAResolveRecipientsRequest")
DAMoveResponse = _Class("DAMoveResponse")
DAMessageFetchAttachmentRequest = _Class("DAMessageFetchAttachmentRequest")
DAMessageMoveRequest = _Class("DAMessageMoveRequest")
DAMailboxFetchSearchResultRequest = _Class("DAMailboxFetchSearchResultRequest")
DAMailboxRequest = _Class("DAMailboxRequest")
DADraftMessageRequest = _Class("DADraftMessageRequest")
DAMailboxFetchMessageRequest = _Class("DAMailboxFetchMessageRequest")
DAMailboxDeleteMessageRequest = _Class("DAMailboxDeleteMessageRequest")
DAMailboxGetUpdatesRequest = _Class("DAMailboxGetUpdatesRequest")
DAMailboxSetFlagsRequest = _Class("DAMailboxSetFlagsRequest")
DAAccountChangeHandler = _Class("DAAccountChangeHandler")
DAAccountChangeUpdaterAccountStoreWrapper = _Class(
    "DAAccountChangeUpdaterAccountStoreWrapper"
)
DAKeychain = _Class("DAKeychain")
DAAccountMonitor = _Class("DAAccountMonitor")
DAFolder = _Class("DAFolder")
DAABLegacyContainer = _Class("DAABLegacyContainer")
DAAnalyticsReporter = _Class("DAAnalyticsReporter")
DAAction = _Class("DAAction")
DAResponse = _Class("DAResponse")
DAEditPropertyAction = _Class("DAEditPropertyAction")
DAMoveAction = _Class("DAMoveAction")
DAAccountClassNames = _Class("DAAccountClassNames")
DAAccountLoader = _Class("DAAccountLoader")
ContactFolderItemsSyncContext = _Class("ContactFolderItemsSyncContext")
DATransactionMonitor = _Class("DATransactionMonitor")
EventsFolderItemsSyncContext = _Class("EventsFolderItemsSyncContext")
DAAccount = _Class("DAAccount")
ASAccountActor = _Class("ASAccountActor")
