'''
Classes from the 'C2' framework.
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

    
C2SessionPool = _Class('C2SessionPool')
C2RequestManager = _Class('C2RequestManager')
C2Session = _Class('C2Session')
C2RequestOptions = _Class('C2RequestOptions')
C2SessionTask = _Class('C2SessionTask')
C2SessionCallbackMetrics = _Class('C2SessionCallbackMetrics')
C2DeviceInfo = _Class('C2DeviceInfo')
C2SessionTLSCache = _Class('C2SessionTLSCache')
C2NetworkingDelegateURLSessionDataTask = _Class('C2NetworkingDelegateURLSessionDataTask')
C2NetworkingDelegateURLSession = _Class('C2NetworkingDelegateURLSession')
C2Logging = _Class('C2Logging')
C2Metric = _Class('C2Metric')
C2SessionGroup = _Class('C2SessionGroup')
C2ReportMetrics = _Class('C2ReportMetrics')
C2MetricRequestOptions = _Class('C2MetricRequestOptions')
C2MetricOperationOptions = _Class('C2MetricOperationOptions')
C2MetricOperationGroupOptions = _Class('C2MetricOperationGroupOptions')
C2MetricOptions = _Class('C2MetricOptions')
C2Time = _Class('C2Time')
C2RoutingTable = _Class('C2RoutingTable')
C2Route = _Class('C2Route')
C2MPDeviceInfo = _Class('C2MPDeviceInfo')
C2MPCloudKitOperationGroupInfo = _Class('C2MPCloudKitOperationGroupInfo')
C2MPMetric = _Class('C2MPMetric')
C2MPServerInfo = _Class('C2MPServerInfo')
C2MPGenericEventMetric = _Class('C2MPGenericEventMetric')
C2MPError = _Class('C2MPError')
C2MPGenericEvent = _Class('C2MPGenericEvent')
C2MPCloudKitInfo = _Class('C2MPCloudKitInfo')
C2MPNetworkEvent = _Class('C2MPNetworkEvent')
C2MPCloudKitOperationInfo = _Class('C2MPCloudKitOperationInfo')
C2MPGenericEventMetricValue = _Class('C2MPGenericEventMetricValue')
C2MPInternalTestConfig = _Class('C2MPInternalTestConfig')
