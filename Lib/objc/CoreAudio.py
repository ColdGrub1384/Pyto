'''
Classes from the 'CoreAudio' framework.
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

    
Core_Audio_Gateway = _Class('Core_Audio_Gateway')
Core_Audio_Property_Listener_Gateway = _Class('Core_Audio_Property_Listener_Gateway')
Core_Audio_IO_Gateway = _Class('Core_Audio_IO_Gateway')
Core_Audio_Daemon = _Class('Core_Audio_Daemon')
Core_Audio_XPC_Connection_To_Server = _Class('Core_Audio_XPC_Connection_To_Server')
Core_Audio_XPC_Raw_Transporter = _Class('Core_Audio_XPC_Raw_Transporter')
HALB_TailspinImpl = _Class('HALB_TailspinImpl')
