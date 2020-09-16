'''
Classes from the 'MobileAsset' framework.
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

    
MAProgressNotification = _Class('MAProgressNotification')
MADownloadConfig = _Class('MADownloadConfig')
MADownloadOptions = _Class('MADownloadOptions')
MAMsuDownloadOptions = _Class('MAMsuDownloadOptions')
MAAssetDiff = _Class('MAAssetDiff')
ASAssetQuery = _Class('ASAssetQuery')
ASAsset = _Class('ASAsset')
MAAbsoluteAssetId = _Class('MAAbsoluteAssetId')
MAProgressHandler = _Class('MAProgressHandler')
MAAsset = _Class('MAAsset')
MAXpcConnection = _Class('MAXpcConnection')
MAXpcManager = _Class('MAXpcManager')
MAAssetQuery = _Class('MAAssetQuery')
