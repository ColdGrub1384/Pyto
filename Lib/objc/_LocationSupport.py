'''
Classes from the 'LocationSupport' framework.
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

    
CLIntersiloProxy = _Class('CLIntersiloProxy')
CLIntersiloProxyToInitiator = _Class('CLIntersiloProxyToInitiator')
CLIntersiloProxyToRecipient = _Class('CLIntersiloProxyToRecipient')
CLCppContainer = _Class('CLCppContainer')
CLCppEncodableDataContainer = _Class('CLCppEncodableDataContainer')
CLServiceVendor = _Class('CLServiceVendor')
_CLUnSupportedService = _Class('_CLUnSupportedService')
_CLMainService = _Class('_CLMainService')
_Locationd = _Class('_Locationd')
CLServiceVendorHeartbeatRecord = _Class('CLServiceVendorHeartbeatRecord')
CLTimerWeakHolder = _Class('CLTimerWeakHolder')
CLDispatchTimerScheduler = _Class('CLDispatchTimerScheduler')
CLIntersiloUniverse = _Class('CLIntersiloUniverse')
CLIntersiloServiceMockPayload = _Class('CLIntersiloServiceMockPayload')
CLTimer = _Class('CLTimer')
CLPermissiveTimer = _Class('CLPermissiveTimer')
CLRunLoopTimerScheduler = _Class('CLRunLoopTimerScheduler')
CLIntersiloInterface = _Class('CLIntersiloInterface')
CLIntersiloInterfaceSelectorInfo = _Class('CLIntersiloInterfaceSelectorInfo')
CLIntersiloService = _Class('CLIntersiloService')
CLIntersiloServiceMock = _Class('CLIntersiloServiceMock')
CLSettingsManagerInternal = _Class('CLSettingsManagerInternal')
CLSettingsManager = _Class('CLSettingsManager')
CLSettingsManagerMock = _Class('CLSettingsManagerMock')
CLSettingsDictionary = _Class('CLSettingsDictionary')
CLSettingsMirror = _Class('CLSettingsMirror')
CLRunLoopSiloThread = _Class('CLRunLoopSiloThread')
CLSilo = _Class('CLSilo')
CLDispatchSilo = _Class('CLDispatchSilo')
CLTimeCoercibleDispatchSilo = _Class('CLTimeCoercibleDispatchSilo')
CLRunLoopSilo = _Class('CLRunLoopSilo')
