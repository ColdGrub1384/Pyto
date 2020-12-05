"""
Classes from the 'CellularPlanManager' framework.
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


CTUserLabel = _Class("CTUserLabel")
CTCellularPlanRequest = _Class("CTCellularPlanRequest")
CTCellularPlanManager = _Class("CTCellularPlanManager")
CTCellularPlanManagerDelegate = _Class("CTCellularPlanManagerDelegate")
CTCellularPlanProfile = _Class("CTCellularPlanProfile")
CTCellularPlanSubscription = _Class("CTCellularPlanSubscription")
CTCellularPlanSubscriptionDataUsage = _Class("CTCellularPlanSubscriptionDataUsage")
CTCellularPlanDateParser = _Class("CTCellularPlanDateParser")
CTCellularPlanBoolValidator = _Class("CTCellularPlanBoolValidator")
CTCellularPlanNumberValidator = _Class("CTCellularPlanNumberValidator")
CTCellularPlanDataValidator = _Class("CTCellularPlanDataValidator")
CTCellularPlanStringValidator = _Class("CTCellularPlanStringValidator")
CTCellularPlanArrayValidator = _Class("CTCellularPlanArrayValidator")
CTCellularPlanDictionaryValidator = _Class("CTCellularPlanDictionaryValidator")
CTCellularPlan = _Class("CTCellularPlan")
CTCellularPlanCarrierItem = _Class("CTCellularPlanCarrierItem")
CTCellularPlanJsonResponseParser = _Class("CTCellularPlanJsonResponseParser")
CTCellularPlanSubscriptionParser = _Class("CTCellularPlanSubscriptionParser")
CTCellularPlanSubscriptionDataUsageParser = _Class(
    "CTCellularPlanSubscriptionDataUsageParser"
)
CTCellularPlanSubscriptionAccountStatusParser = _Class(
    "CTCellularPlanSubscriptionAccountStatusParser"
)
CTCellularPlanSubscriptionStatusParser = _Class(
    "CTCellularPlanSubscriptionStatusParser"
)
CTCellularPlanSubscriptionTypeParser = _Class("CTCellularPlanSubscriptionTypeParser")
CTCellularPlanResponseCodeParser = _Class("CTCellularPlanResponseCodeParser")
CTCellularPlanPendingTransfer = _Class("CTCellularPlanPendingTransfer")
CTDanglingPlanItem = _Class("CTDanglingPlanItem")
CTCellularPlanItem = _Class("CTCellularPlanItem")
CTCellularPlanError = _Class("CTCellularPlanError")
