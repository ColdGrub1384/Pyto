"""
Classes from the 'UserNotifications' framework.
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


UNNotificationTopicRequest = _Class("UNNotificationTopicRequest")
UNNotificationTopic = _Class("UNNotificationTopic")
UNUserNotificationServiceConnection = _Class("UNUserNotificationServiceConnection")
UNNotificationCategory = _Class("UNNotificationCategory")
UNMutableNotificationCategory = _Class("UNMutableNotificationCategory")
UNUserNotificationCenterDelegateService = _Class(
    "UNUserNotificationCenterDelegateService"
)
UNNotificationContent = _Class("UNNotificationContent")
UNMutableNotificationContent = _Class("UNMutableNotificationContent")
UNNotificationResponse = _Class("UNNotificationResponse")
UNTextInputNotificationResponse = _Class("UNTextInputNotificationResponse")
UNUserNotificationService = _Class("UNUserNotificationService")
UNNotificationAttachment = _Class("UNNotificationAttachment")
UNPushNotificationRequestBuilder = _Class("UNPushNotificationRequestBuilder")
UNNotificationSound = _Class("UNNotificationSound")
UNMutableNotificationSound = _Class("UNMutableNotificationSound")
UNNotification = _Class("UNNotification")
UNNotificationAttachmentOptions = _Class("UNNotificationAttachmentOptions")
UNMutableNotificationAttachmentOptions = _Class(
    "UNMutableNotificationAttachmentOptions"
)
UNNotificationRequest = _Class("UNNotificationRequest")
UNNotificationServiceExtension = _Class("UNNotificationServiceExtension")
UNUserNotificationCenterDelegateConnectionListener = _Class(
    "UNUserNotificationCenterDelegateConnectionListener"
)
UNNotificationIcon = _Class("UNNotificationIcon")
UNNotificationSettings = _Class("UNNotificationSettings")
UNMutableNotificationSettings = _Class("UNMutableNotificationSettings")
UNNotificationAction = _Class("UNNotificationAction")
UNTextInputNotificationAction = _Class("UNTextInputNotificationAction")
UNNotificationTrigger = _Class("UNNotificationTrigger")
UNTimeIntervalNotificationTrigger = _Class("UNTimeIntervalNotificationTrigger")
UNPushNotificationTrigger = _Class("UNPushNotificationTrigger")
UNLocationNotificationTrigger = _Class("UNLocationNotificationTrigger")
UNLegacyNotificationTrigger = _Class("UNLegacyNotificationTrigger")
UNCalendarNotificationTrigger = _Class("UNCalendarNotificationTrigger")
UNLocalizedStringFactory = _Class("UNLocalizedStringFactory")
_UNNotificationServiceExtensionContext = _Class(
    "_UNNotificationServiceExtensionContext"
)
_UNNotificationServiceExtensionHostContext = _Class(
    "_UNNotificationServiceExtensionHostContext"
)
_UNNotificationServiceExtensionRemoteContext = _Class(
    "_UNNotificationServiceExtensionRemoteContext"
)
UNUserNotificationCenter = _Class("UNUserNotificationCenter")
UNLocalizedString = _Class("UNLocalizedString")
UNSecurityScopedURL = _Class("UNSecurityScopedURL")
