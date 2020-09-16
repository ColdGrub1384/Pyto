'''
Classes from the 'FTServices' framework.
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

    
FTPasswordManager = _Class('FTPasswordManager')
_FTPasswordManagerCachedAuthTokenInfo = _Class('_FTPasswordManagerCachedAuthTokenInfo')
FTRegionSupport = _Class('FTRegionSupport')
FTRegion = _Class('FTRegion')
FTUserConfiguration = _Class('FTUserConfiguration')
FTEntitlementSupport = _Class('FTEntitlementSupport')
FTMessageDeliveryRemoteURLConnectionFactory = _Class('FTMessageDeliveryRemoteURLConnectionFactory')
FTAuthKitManager = _Class('FTAuthKitManager')
FTEmbeddedReachability = _Class('FTEmbeddedReachability')
FTiMessageStatus = _Class('FTiMessageStatus')
FTServiceStatus = _Class('FTServiceStatus')
FTNetworkSupport = _Class('FTNetworkSupport')
FTSelectedPNRSubscription = _Class('FTSelectedPNRSubscription')
FTSelectedPNRSubscriptionCache = _Class('FTSelectedPNRSubscriptionCache')
FTDeviceSupport = _Class('FTDeviceSupport')
FTMessageDelivery_DualMode = _Class('FTMessageDelivery_DualMode')
FTMessageQueue = _Class('FTMessageQueue')
FTMessageDelivery = _Class('FTMessageDelivery')
FTMessageDelivery_APS = _Class('FTMessageDelivery_APS')
FTMessageDelivery_HTTP = _Class('FTMessageDelivery_HTTP')
FTServerBag = _Class('FTServerBag')
FTGetRegionMetadataMessage = _Class('FTGetRegionMetadataMessage')
FTIDSMessage = _Class('FTIDSMessage')
FTURLRequestMessage = _Class('FTURLRequestMessage')
IDSWebTunnelRequestMessage = _Class('IDSWebTunnelRequestMessage')
