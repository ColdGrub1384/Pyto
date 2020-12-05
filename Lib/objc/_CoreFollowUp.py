"""
Classes from the 'CoreFollowUp' framework.
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


FLApprovedItemsFilter = _Class("FLApprovedItemsFilter")
FLHSA2PasswordResetNotification = _Class("FLHSA2PasswordResetNotification")
FLItemChangeObserver = _Class("FLItemChangeObserver")
FLApprovedItemsDecorator = _Class("FLApprovedItemsDecorator")
FLHSA2LoginNotification = _Class("FLHSA2LoginNotification")
FLDaemon = _Class("FLDaemon")
FLGroupViewModelImpl = _Class("FLGroupViewModelImpl")
FLTopLevelViewModel = _Class("FLTopLevelViewModel")
FLHeadlessExtensionLoader = _Class("FLHeadlessExtensionLoader")
FLItemDetailViewModel = _Class("FLItemDetailViewModel")
FLFollowUpAction = _Class("FLFollowUpAction")
FLFollowUpNotification = _Class("FLFollowUpNotification")
FLEnvironment = _Class("FLEnvironment")
FLHeadlessActionHandler = _Class("FLHeadlessActionHandler")
FLTelemetryAggregateController = _Class("FLTelemetryAggregateController")
FLFollowUpController = _Class("FLFollowUpController")
FLUtilities = _Class("FLUtilities")
FLTelemetryFactory = _Class("FLTelemetryFactory")
FLFollowUpItem = _Class("FLFollowUpItem")
FLConstants = _Class("FLConstants")
FLTelemetryProcessor = _Class("FLTelemetryProcessor")
FLExtensionHostContext = _Class("FLExtensionHostContext")
