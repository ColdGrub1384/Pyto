'''
Classes from the 'CTCarrierSpace' framework.
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

    
CTCarrierSpaceError = _Class('CTCarrierSpaceError')
CTCarrierSpacePlanGroupInfo = _Class('CTCarrierSpacePlanGroupInfo')
CTCarrierSpaceUsagePlanItemMessages = _Class('CTCarrierSpaceUsagePlanItemMessages')
CTCarrierSpaceUsagePlanItemVoice = _Class('CTCarrierSpaceUsagePlanItemVoice')
CTCarrierSpaceAuthenticationContext = _Class('CTCarrierSpaceAuthenticationContext')
CTCarrierSpaceUserConsentFlowInfo = _Class('CTCarrierSpaceUserConsentFlowInfo')
CTCarrierSpaceAppsInfo = _Class('CTCarrierSpaceAppsInfo')
CTCarrierSpaceCapabilities = _Class('CTCarrierSpaceCapabilities')
CTCarrierSpaceUsageAccountMetrics = _Class('CTCarrierSpaceUsageAccountMetrics')
CTCarrierSpaceClient = _Class('CTCarrierSpaceClient')
CTCarrierSpaceAuthInfo = _Class('CTCarrierSpaceAuthInfo')
CTCarrierSpaceUsagePlanItemData = _Class('CTCarrierSpaceUsagePlanItemData')
CTCarrierSpaceClientDelegateProxy = _Class('CTCarrierSpaceClientDelegateProxy')
CTCarrierSpaceUsageInfo = _Class('CTCarrierSpaceUsageInfo')
CTCarrierSpaceDataPlanMetricsError = _Class('CTCarrierSpaceDataPlanMetricsError')
CTCarrierSpaceInfo = _Class('CTCarrierSpaceInfo')
CTCarrierSpacePlansInfo = _Class('CTCarrierSpacePlansInfo')
CTCarrierSpaceUsagePlanMetrics = _Class('CTCarrierSpaceUsagePlanMetrics')
CTCarrierSpaceDataPlanMetrics = _Class('CTCarrierSpaceDataPlanMetrics')
CTCarrierSpacePlanGroupOptionInfo = _Class('CTCarrierSpacePlanGroupOptionInfo')
CTCarrierSpaceDataPlanMetricsItem = _Class('CTCarrierSpaceDataPlanMetricsItem')
