'''
Classes from the 'Osprey' framework.
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

    
OspreyMutableRequest = _Class('OspreyMutableRequest')
OspreyChannelRequestOptions = _Class('OspreyChannelRequestOptions')
OspreyDeviceAuthentication = _Class('OspreyDeviceAuthentication')
OspreyGRPCChannel = _Class('OspreyGRPCChannel')
OspreyMescalAuthentication = _Class('OspreyMescalAuthentication')
OspreyChannel = _Class('OspreyChannel')
OspreyConnectionMetrics = _Class('OspreyConnectionMetrics')
OspreyMethodCall = _Class('OspreyMethodCall')
OspreyUnaryMethodCall = _Class('OspreyUnaryMethodCall')
OspreyMescalSession = _Class('OspreyMescalSession')
OspreyAuthService = _Class('OspreyAuthService')
OspreyKeychain = _Class('OspreyKeychain')
OspreyAnalytics = _Class('OspreyAnalytics')
AbsintheAuthenticationDurations = _Class('AbsintheAuthenticationDurations')
OspreyZlibDataDecompressor = _Class('OspreyZlibDataDecompressor')
OspreyZlibDataCompressor = _Class('OspreyZlibDataCompressor')
OspreyRequest = _Class('OspreyRequest')
OspreyConnectionPreferences = _Class('OspreyConnectionPreferences')
OspreyMessageProducer = _Class('OspreyMessageProducer')
OspreyService = _Class('OspreyService')
OspreyPreferences = _Class('OspreyPreferences')
OspreyAbsintheAuthenticator = _Class('OspreyAbsintheAuthenticator')
OspreyMessageReader = _Class('OspreyMessageReader')
OspreyMessageWriter = _Class('OspreyMessageWriter')
OspreyGRPCStreamingContext = _Class('OspreyGRPCStreamingContext')
OspreyBufferedOutputStream = _Class('OspreyBufferedOutputStream')
