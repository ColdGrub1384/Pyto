'''
Classes from the 'MultipeerConnectivity' framework.
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

    
MCPeerID = _Class('MCPeerID')
MCPeerIDInternal = _Class('MCPeerIDInternal')
MCNearbyDiscoveryPeer = _Class('MCNearbyDiscoveryPeer')
MCAdvertiserAssistant = _Class('MCAdvertiserAssistant')
MCNearbyServiceBrowser = _Class('MCNearbyServiceBrowser')
MCNearbyServiceAdvertiser = _Class('MCNearbyServiceAdvertiser')
MCNearbyDiscoveryPeerConnection = _Class('MCNearbyDiscoveryPeerConnection')
MCNearbyServiceUtils = _Class('MCNearbyServiceUtils')
MCSession = _Class('MCSession')
MCResourceProgressObserver = _Class('MCResourceProgressObserver')
MCSessionPeerConnectionData = _Class('MCSessionPeerConnectionData')
MCResourceDownloader = _Class('MCResourceDownloader')
MCSessionStream = _Class('MCSessionStream')
MCSessionPeerState = _Class('MCSessionPeerState')
MCNearbyPeerTableViewHeader = _Class('MCNearbyPeerTableViewHeader')
MCNearbyPeerTableViewCell = _Class('MCNearbyPeerTableViewCell')
MCBrowserViewController = _Class('MCBrowserViewController')
MCAlertController = _Class('MCAlertController')
