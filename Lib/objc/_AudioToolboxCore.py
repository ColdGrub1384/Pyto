"""
Classes from the 'AudioToolboxCore' framework.
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


AudioComponentPrefRegConnection = _Class("AudioComponentPrefRegConnection")
AudioComponentMainRegConnection = _Class("AudioComponentMainRegConnection")
AudioComponentRegistrar = _Class("AudioComponentRegistrar")
_ACPluginDB = _Class("_ACPluginDB")
_ACPluginDBDirectory = _Class("_ACPluginDBDirectory")
_ACPluginDBBundle = _Class("_ACPluginDBBundle")
AUAudioUnitServiceUI_Subsystem = _Class("AUAudioUnitServiceUI_Subsystem")
AUAudioUnitService_Subsystem = _Class("AUAudioUnitService_Subsystem")
AUPBClientManager = _Class("AUPBClientManager")
RemoteAUPBServer = _Class("RemoteAUPBServer")
_AUStaticParameterInfo = _Class("_AUStaticParameterInfo")
AUParameterNode = _Class("AUParameterNode")
AUParameter = _Class("AUParameter")
AUParameterGroup = _Class("AUParameterGroup")
AUParameterTree = _Class("AUParameterTree")
AUAudioUnitPreset = _Class("AUAudioUnitPreset")
_ACComponentVector = _Class("_ACComponentVector")
_ACComponentWrapper = _Class("_ACComponentWrapper")
AUHostDelegate = _Class("AUHostDelegate")
AUAudioUnit = _Class("AUAudioUnit")
AUAudioUnitV2Bridge = _Class("AUAudioUnitV2Bridge")
AUHALOutputUnit = _Class("AUHALOutputUnit")
AUAudioUnit_XPC = _Class("AUAudioUnit_XPC")
AUAudioUnit_XH = _Class("AUAudioUnit_XH")
AUAudioUnitBusArray = _Class("AUAudioUnitBusArray")
AUV2BridgeBusArray = _Class("AUV2BridgeBusArray")
AUAudioUnitBusArray_XPC = _Class("AUAudioUnitBusArray_XPC")
AUAudioUnitBus = _Class("AUAudioUnitBus")
AUV2BridgeBus = _Class("AUV2BridgeBus")
AUAudioUnitBus_XPC = _Class("AUAudioUnitBus_XPC")
_AUParameterTreeObserver = _Class("_AUParameterTreeObserver")
AUExtensionInstanceProxy = _Class("AUExtensionInstanceProxy")
AUAudioUnitProperty = _Class("AUAudioUnitProperty")
AUPBServer = _Class("AUPBServer")
AUPBClientConnection = _Class("AUPBClientConnection")
AURemoteHost = _Class("AURemoteHost")
AudioComponentRegistrarClient = _Class("AudioComponentRegistrarClient")
InterAppAudioGroup = _Class("InterAppAudioGroup")
InterAppAudioApp = _Class("InterAppAudioApp")
CarbonComponentScannerXPCClient = _Class("CarbonComponentScannerXPCClient")
AUHostExtensionContext = _Class("AUHostExtensionContext")
AURemoteExtensionContext = _Class("AURemoteExtensionContext")
