'''
Classes from the 'StreamingZip' framework.
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

    
StreamingUnzipper = _Class('StreamingUnzipper')
StreamingUnzipState = _Class('StreamingUnzipState')
SZExtractor = _Class('SZExtractor')
SZExtractorInternalDelegate = _Class('SZExtractorInternalDelegate')
StreamingUnzipDelegateProtocolInterface = _Class('StreamingUnzipDelegateProtocolInterface')
StreamingUnzipProtocolInterface = _Class('StreamingUnzipProtocolInterface')
