'''
Classes from the 'BluetoothManager' framework.
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

    
RemoteDeviceManager = _Class('RemoteDeviceManager')
BluetoothManager = _Class('BluetoothManager')
BluetoothDevice = _Class('BluetoothDevice')
