'''
Classes from the 'OSAnalytics' framework.
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

    
OSALogCounterObject = _Class('OSALogCounterObject')
MTClientHelpers = _Class('MTClientHelpers')
OSALegacyXform = _Class('OSALegacyXform')
AWDClientHelpers = _Class('AWDClientHelpers')
OSABinaryImageCatalog = _Class('OSABinaryImageCatalog')
OSABinaryImageSegment = _Class('OSABinaryImageSegment')
OSASymbolInfo = _Class('OSASymbolInfo')
OSALog = _Class('OSALog')
OSAProxyConfiguration = _Class('OSAProxyConfiguration')
OSASystemConfiguration = _Class('OSASystemConfiguration')
OSATasking = _Class('OSATasking')
OSAReport = _Class('OSAReport')
OSAJetsamReport = _Class('OSAJetsamReport')
OSACrashReport = _Class('OSACrashReport')
OSAStackShotReport = _Class('OSAStackShotReport')
KCContainer = _Class('KCContainer')
