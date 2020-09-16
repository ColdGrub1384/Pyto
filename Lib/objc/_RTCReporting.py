'''
Classes from the 'RTCReporting' framework.
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

    
RTCReportingDeallocNotifier = _Class('RTCReportingDeallocNotifier')
RTCReporting = _Class('RTCReporting')
RTCReportingAggregationObject = _Class('RTCReportingAggregationObject')
UpdateAndReportServices = _Class('UpdateAndReportServices')
RTCSecureHierarchyToken = _Class('RTCSecureHierarchyToken')
