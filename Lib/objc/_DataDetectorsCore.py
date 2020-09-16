'''
Classes from the 'DataDetectorsCore' framework.
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

    
DDScannerResult = _Class('DDScannerResult')
DDMessageCache = _Class('DDMessageCache')
DDMessageCacheElement = _Class('DDMessageCacheElement')
DataDetectorsSourceAccess = _Class('DataDetectorsSourceAccess')
DDURLMatch = _Class('DDURLMatch')
DDURLifier = _Class('DDURLifier')
DDScannerService = _Class('DDScannerService')
DDScanServer = _Class('DDScanServer')
DDScanServerDispatcher = _Class('DDScanServerDispatcher')
DDScannerList = _Class('DDScannerList')
DDScanStepBlockContainer = _Class('DDScanStepBlockContainer')
DDScannerObject = _Class('DDScannerObject')
DDScannerServiceConfiguration = _Class('DDScannerServiceConfiguration')
