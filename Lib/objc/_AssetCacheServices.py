"""
Classes from the 'AssetCacheServices' framework.
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


ACSURLSessionTask = _Class("ACSURLSessionTask")
ACSURLSessionDownloadTask = _Class("ACSURLSessionDownloadTask")
ACSURLSessionDataTask = _Class("ACSURLSessionDataTask")
ACSURLSessionUploadTask = _Class("ACSURLSessionUploadTask")
ACSURLSession = _Class("ACSURLSession")
