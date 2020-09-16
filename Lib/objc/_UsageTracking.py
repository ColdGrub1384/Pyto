'''
Classes from the 'UsageTracking' framework.
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

    
USXPCRemoteObjectProxy = _Class('USXPCRemoteObjectProxy')
USWebpageUsage = _Class('USWebpageUsage')
USWebHistory = _Class('USWebHistory')
USVideoUsage = _Class('USVideoUsage')
USUsageTrust = _Class('USUsageTrust')
USUsageTrackingBundle = _Class('USUsageTrackingBundle')
USTrackingAgentPrivateConnection = _Class('USTrackingAgentPrivateConnection')
USTrackingAgentConnection = _Class('USTrackingAgentConnection')
USUsageReporter = _Class('USUsageReporter')
USWebUsageReport = _Class('USWebUsageReport')
USApplicationUsageReport = _Class('USApplicationUsageReport')
USCategoryUsageReport = _Class('USCategoryUsageReport')
USUsageReport = _Class('USUsageReport')
USUsageQuerying = _Class('USUsageQuerying')
USUsageMonitor = _Class('USUsageMonitor')
USBudget = _Class('USBudget')
USTrustIdentifier = _Class('USTrustIdentifier')
USDomainNormalization = _Class('USDomainNormalization')
