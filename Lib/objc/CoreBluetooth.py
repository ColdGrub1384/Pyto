'''
Classes from the 'CoreBluetooth' framework.
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

    
CBSpatialInteractionSession = _Class('CBSpatialInteractionSession')
CBSpatialInteractionPeerInfoClient = _Class('CBSpatialInteractionPeerInfoClient')
CBServer = _Class('CBServer')
CBPairingAgent = _Class('CBPairingAgent')
CBDevice = _Class('CBDevice')
CBATTRequest = _Class('CBATTRequest')
CBDiscovery = _Class('CBDiscovery')
CBXpcConnection = _Class('CBXpcConnection')
CBConnection = _Class('CBConnection')
CBL2CAPChannel = _Class('CBL2CAPChannel')
CBUUID = _Class('CBUUID')
CBWriteRequest = _Class('CBWriteRequest')
CBReadRequest = _Class('CBReadRequest')
CBController = _Class('CBController')
CBScalablePipe = _Class('CBScalablePipe')
CBIdentity = _Class('CBIdentity')
CBAttribute = _Class('CBAttribute')
CBService = _Class('CBService')
CBMutableService = _Class('CBMutableService')
CBDescriptor = _Class('CBDescriptor')
CBMutableDescriptor = _Class('CBMutableDescriptor')
CBCharacteristic = _Class('CBCharacteristic')
CBMutableCharacteristic = _Class('CBMutableCharacteristic')
CBRFCOMMChannel = _Class('CBRFCOMMChannel')
CBManager = _Class('CBManager')
CBPeripheralManager = _Class('CBPeripheralManager')
CBClassicManager = _Class('CBClassicManager')
CBScalablePipeManager = _Class('CBScalablePipeManager')
CBCentralManager = _Class('CBCentralManager')
CBPeer = _Class('CBPeer')
CBCentral = _Class('CBCentral')
CBPeripheral = _Class('CBPeripheral')
CBClassicPeer = _Class('CBClassicPeer')
BTDevicePicker = _Class('BTDevicePicker')
PSSpecifierStub = _Class('PSSpecifierStub')
