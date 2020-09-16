'''
Classes from the 'SymptomPresentationFeed' framework.
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

    
UsageFeed = _Class('UsageFeed')
ProcessNetStatsIndividualEntity = _Class('ProcessNetStatsIndividualEntity')
NWNetworkPredictions = _Class('NWNetworkPredictions')
NWNetworkOfInterestManager = _Class('NWNetworkOfInterestManager')
NWNetworkAdviceUpdate = _Class('NWNetworkAdviceUpdate')
NWAppAdvice = _Class('NWAppAdvice')
NWNetworkOfInterest = _Class('NWNetworkOfInterest')
NetworkPerformanceFeed = _Class('NetworkPerformanceFeed')
NetworkInterfaceUtils = _Class('NetworkInterfaceUtils')
