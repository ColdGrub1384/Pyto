'''
Classes from the 'IntentsUI' framework.
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

    
INUIExtensionViewControllerConfiguration = _Class('INUIExtensionViewControllerConfiguration')
INUIInterfaceSection = _Class('INUIInterfaceSection')
INUIExtensionRequestInfo = _Class('INUIExtensionRequestInfo')
INUIImageLoader = _Class('INUIImageLoader')
INUIPortableImageLoaderHelper = _Class('INUIPortableImageLoaderHelper')
INUIImageSizeProvider = _Class('INUIImageSizeProvider')
_INUIXPCInterfaceUtilities = _Class('_INUIXPCInterfaceUtilities')
INUIImageServiceConnection = _Class('INUIImageServiceConnection')
INUIVoiceShortcutXPCInterface = _Class('INUIVoiceShortcutXPCInterface')
_INUIExtensionContextState = _Class('_INUIExtensionContextState')
INUIAppIntentForwardingActionExecutor = _Class('INUIAppIntentForwardingActionExecutor')
INUIAppIntentDeliverer = _Class('INUIAppIntentDeliverer')
INUISearchFoundationImageAdapter = _Class('INUISearchFoundationImageAdapter')
_INUIExtensionContext = _Class('_INUIExtensionContext')
_INUIExtensionHostContext = _Class('_INUIExtensionHostContext')
INUIAddVoiceShortcutButton = _Class('INUIAddVoiceShortcutButton')
INUIEditVoiceShortcutViewController = _Class('INUIEditVoiceShortcutViewController')
_INUIServiceViewController = _Class('_INUIServiceViewController')
INUILoadingVoiceShortcutViewController = _Class('INUILoadingVoiceShortcutViewController')
INUIAddVoiceShortcutViewController = _Class('INUIAddVoiceShortcutViewController')
INUIRemoteViewController = _Class('INUIRemoteViewController')
INUIVoiceShortcutHostViewController = _Class('INUIVoiceShortcutHostViewController')
