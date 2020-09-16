'''
Classes from the 'MediaStream' framework.
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

    
XPCNSServiceListener = _Class('XPCNSServiceListener')
XPCNSServiceConnection = _Class('XPCNSServiceConnection')
XPCNSClientConnection = _Class('XPCNSClientConnection')
XPCNSRequest = _Class('XPCNSRequest')
XPCServiceListener = _Class('XPCServiceListener')
XPCServiceConnection = _Class('XPCServiceConnection')
XPCClientConnection = _Class('XPCClientConnection')
XPCRequest = _Class('XPCRequest')
MSASPlatformImplementation = _Class('MSASPlatformImplementation')
MSPowerBudget = _Class('MSPowerBudget')
MSPBTimerContext = _Class('MSPBTimerContext')
MSASConnection = _Class('MSASConnection')
MSBatteryPowerMonitor = _Class('MSBatteryPowerMonitor')
MSPauseManager = _Class('MSPauseManager')
MSClientSidePauseContext = _Class('MSClientSidePauseContext')
MSMSPlatform = _Class('MSMSPlatform')
MSConnection = _Class('MSConnection')
MSAuthenticationManager = _Class('MSAuthenticationManager')
MSAlertManager = _Class('MSAlertManager')
MSAMNotificationInfo = _Class('MSAMNotificationInfo')
MSPowerAssertionManager = _Class('MSPowerAssertionManager')
