'''
Classes from the 'PushKit' framework.
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

    
PKPushPayload = _Class('PKPushPayload')
PKPushCredentials = _Class('PKPushCredentials')
PKPushRegistry = _Class('PKPushRegistry')
PKUserNotificationsRemoteNotificationServiceConnection = _Class('PKUserNotificationsRemoteNotificationServiceConnection')
