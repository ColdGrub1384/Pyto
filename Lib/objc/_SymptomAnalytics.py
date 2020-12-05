"""
Classes from the 'SymptomAnalytics' framework.
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


ObjectAnalytics = _Class("ObjectAnalytics")
UsageAnalytics = _Class("UsageAnalytics")
NetworkAttachmentAnalytics = _Class("NetworkAttachmentAnalytics")
ProcessAnalytics = _Class("ProcessAnalytics")
AppAnalytics = _Class("AppAnalytics")
DiagnosticCaseUsageAnalytics = _Class("DiagnosticCaseUsageAnalytics")
AnalyticsWorkspace = _Class("AnalyticsWorkspace")
AnalyticsWorkspaceRetrievalCallback = _Class("AnalyticsWorkspaceRetrievalCallback")
SFLiveRoutePerf = _Class("SFLiveRoutePerf")
SFNetworkAttachment = _Class("SFNetworkAttachment")
SFFlow = _Class("SFFlow")
SFProvisioningData = _Class("SFProvisioningData")
SFTrackerDomain = _Class("SFTrackerDomain")
LiveUsage = _Class("LiveUsage")
SFAppTypicalUsage = _Class("SFAppTypicalUsage")
SFAppRun = _Class("SFAppRun")
DiagnosticCaseUsage = _Class("DiagnosticCaseUsage")
SFAppExperience = _Class("SFAppExperience")
NWActivityFragment = _Class("NWActivityFragment")
SFAppCalendarUsage = _Class("SFAppCalendarUsage")
SFAppDomainUsage = _Class("SFAppDomainUsage")
Process = _Class("Process")
SFApp = _Class("SFApp")
SFLiveFlowPerf = _Class("SFLiveFlowPerf")
NWActivityMetricData = _Class("NWActivityMetricData")
