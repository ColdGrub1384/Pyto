"""
Classes from the 'BackBoardServices' framework.
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


BKSTouchStream = _Class("BKSTouchStream")
BKSHIDEventAuthenticationKeyRing = _Class("BKSHIDEventAuthenticationKeyRing")
BKSHIDEventAuthenticationKeyRetentionPolicy = _Class(
    "BKSHIDEventAuthenticationKeyRetentionPolicy"
)
BKSDisplayRenderOverlay = _Class("BKSDisplayRenderOverlay")
BKSHIDAuthenticatedKeyCommandSpecification = _Class(
    "BKSHIDAuthenticatedKeyCommandSpecification"
)
BKSTouchEventService = _Class("BKSTouchEventService")
BKSHIDUISensorCharacteristics = _Class("BKSHIDUISensorCharacteristics")
BKSMutableHIDUISensorCharacteristics = _Class("BKSMutableHIDUISensorCharacteristics")
BKSWatchdogServerWrapper = _Class("BKSWatchdogServerWrapper")
BKSEventFocusDeferral = _Class("BKSEventFocusDeferral")
BKSEventFocusManager = _Class("BKSEventFocusManager")
_BKSEventFocusChangeObserverInfo = _Class("_BKSEventFocusChangeObserverInfo")
BKSHIDEventSenderDescriptor = _Class("BKSHIDEventSenderDescriptor")
BKSMutableHIDEventSenderDescriptor = _Class("BKSMutableHIDEventSenderDescriptor")
BKSDefaults = _Class("BKSDefaults")
BKSAbstractDefaults = _Class("BKSAbstractDefaults")
BKSExternalDefaults = _Class("BKSExternalDefaults")
BKSMousePointerServiceSessionSpecification = _Class(
    "BKSMousePointerServiceSessionSpecification"
)
BKSHIDUISensorMode = _Class("BKSHIDUISensorMode")
BKSMutableHIDUISensorMode = _Class("BKSMutableHIDUISensorMode")
BKSTouchDeliveryUpdate = _Class("BKSTouchDeliveryUpdate")
BKSButtonHapticsDefinition = _Class("BKSButtonHapticsDefinition")
BKSHIDEventDiscreteDispatchingPredicate = _Class(
    "BKSHIDEventDiscreteDispatchingPredicate"
)
BKSMutableHIDEventDiscreteDispatchingPredicate = _Class(
    "BKSMutableHIDEventDiscreteDispatchingPredicate"
)
BKSTouchDeliveryObservationService = _Class("BKSTouchDeliveryObservationService")
BKSBacklightFeatures = _Class("BKSBacklightFeatures")
BKSHIDEventKeyCommandsDispatchingPredicate = _Class(
    "BKSHIDEventKeyCommandsDispatchingPredicate"
)
BKSMutableHIDEventKeyCommandsDispatchingPredicate = _Class(
    "BKSMutableHIDEventKeyCommandsDispatchingPredicate"
)
BKSDisplayRenderOverlayDescriptor = _Class("BKSDisplayRenderOverlayDescriptor")
BKSTouchDeliveryPolicyAssertion = _Class("BKSTouchDeliveryPolicyAssertion")
BKSMousePointerDevicePreferences = _Class("BKSMousePointerDevicePreferences")
BKSAnimationFenceAssertion = _Class("BKSAnimationFenceAssertion")
BKSAnimationFenceObserver = _Class("BKSAnimationFenceObserver")
BKSHIDEventAuthenticationKey = _Class("BKSHIDEventAuthenticationKey")
BKSApplicationDataStore = _Class("BKSApplicationDataStore")
BKSAlternateSystemApp = _Class("BKSAlternateSystemApp")
BKSHitTestRegion = _Class("BKSHitTestRegion")
BKSSystemService = _Class("BKSSystemService")
BKSButtonHapticsController = _Class("BKSButtonHapticsController")
BKSTouchAnnotationController = _Class("BKSTouchAnnotationController")
BKSHIDEventDeferringResolution = _Class("BKSHIDEventDeferringResolution")
BKSMutableHIDEventDeferringResolution = _Class("BKSMutableHIDEventDeferringResolution")
BKSSecureModeViolation = _Class("BKSSecureModeViolation")
BKSTouchAuthenticationSpecification = _Class("BKSTouchAuthenticationSpecification")
BKSMutableTouchAuthenticationSpecification = _Class(
    "BKSMutableTouchAuthenticationSpecification"
)
BKSMousePointerService = _Class("BKSMousePointerService")
BKSMousePointerPreferencesObserverInfo = _Class(
    "BKSMousePointerPreferencesObserverInfo"
)
BKSMousePointerDeviceObserverInfo = _Class("BKSMousePointerDeviceObserverInfo")
BKSMousePointerPerDisplayInfo = _Class("BKSMousePointerPerDisplayInfo")
BKSMousePointerEventRoute = _Class("BKSMousePointerEventRoute")
BKSMousePointerSuppressionAssertionDescriptor = _Class(
    "BKSMousePointerSuppressionAssertionDescriptor"
)
BKSHIDEventRouterManager = _Class("BKSHIDEventRouterManager")
BKSHIDEventKeyCommandsDispatchingRule = _Class("BKSHIDEventKeyCommandsDispatchingRule")
BKSTouchDeliveryPolicy = _Class("BKSTouchDeliveryPolicy")
_BKSCombinedTouchDeliveryPolicy = _Class("_BKSCombinedTouchDeliveryPolicy")
_BKSCancelTouchesTouchDeliveryPolicy = _Class("_BKSCancelTouchesTouchDeliveryPolicy")
_BKSShareTouchesTouchDeliveryPolicy = _Class("_BKSShareTouchesTouchDeliveryPolicy")
BKSHIDEventObserver = _Class("BKSHIDEventObserver")
BKSDisplayProgressIndicatorProperties = _Class("BKSDisplayProgressIndicatorProperties")
BKSMousePointerDevice = _Class("BKSMousePointerDevice")
BKSHIDEventHitTestClientContext = _Class("BKSHIDEventHitTestClientContext")
BKSHIDEventDeliveryPolicyObserver = _Class("BKSHIDEventDeliveryPolicyObserver")
BKSHIDEventDispatchingTarget = _Class("BKSHIDEventDispatchingTarget")
BKSContextRelativePoint = _Class("BKSContextRelativePoint")
BKSSystemApplication = _Class("BKSSystemApplication")
BKSDisplayInterstitialRenderOverlayDismissAction = _Class(
    "BKSDisplayInterstitialRenderOverlayDismissAction"
)
BKSHIDEventRouter = _Class("BKSHIDEventRouter")
BKSEventFocusDeferralProperties = _Class("BKSEventFocusDeferralProperties")
BKSTouchAnnotation = _Class("BKSTouchAnnotation")
BKSHIDEventDiscreteDispatchingRule = _Class("BKSHIDEventDiscreteDispatchingRule")
BKSHIDServiceConnection = _Class("BKSHIDServiceConnection")
BKSHIDEventDescriptor = _Class("BKSHIDEventDescriptor")
BKSHIDEventUsagePairDescriptor = _Class("BKSHIDEventUsagePairDescriptor")
BKSHIDEventKeyboardDescriptor = _Class("BKSHIDEventKeyboardDescriptor")
BKSHIDEventVendorDefinedDescriptor = _Class("BKSHIDEventVendorDefinedDescriptor")
BKSHIDEventBiometricDescriptor = _Class("BKSHIDEventBiometricDescriptor")
BKSHIDEventSenderSpecificDescriptor = _Class("BKSHIDEventSenderSpecificDescriptor")
BKSHIDUISensorService = _Class("BKSHIDUISensorService")
BKSTouchStreamPolicy = _Class("BKSTouchStreamPolicy")
BKSSystemGesturesTouchStreamPolicy = _Class("BKSSystemGesturesTouchStreamPolicy")
BKSHIDTouchRoutingPolicy = _Class("BKSHIDTouchRoutingPolicy")
_BKSAnimationFenceXPCClient = _Class("_BKSAnimationFenceXPCClient")
BKSSystemApplicationClient = _Class("BKSSystemApplicationClient")
BKSHIDEventDigitizerPathAttributes = _Class("BKSHIDEventDigitizerPathAttributes")
BKSHIDEventAuthenticationMessage = _Class("BKSHIDEventAuthenticationMessage")
BKSMutableHIDEventAuthenticationMessage = _Class(
    "BKSMutableHIDEventAuthenticationMessage"
)
BKSHIDEventBaseAttributes = _Class("BKSHIDEventBaseAttributes")
BKSHIDEventRedirectAttributes = _Class("BKSHIDEventRedirectAttributes")
BKSHIDEventDigitizerAttributes = _Class("BKSHIDEventDigitizerAttributes")
BKSHIDEventPointerAttributes = _Class("BKSHIDEventPointerAttributes")
BKSAnimationFenceHandle = _Class("BKSAnimationFenceHandle")
BKSSystemAnimationFenceHandle = _Class("BKSSystemAnimationFenceHandle")
BKSCAAnimationFenceHandle = _Class("BKSCAAnimationFenceHandle")
BKSHIDEventDeferringRule = _Class("BKSHIDEventDeferringRule")
BKSHIDEventDeferringTarget = _Class("BKSHIDEventDeferringTarget")
BKSMutableHIDEventDeferringTarget = _Class("BKSMutableHIDEventDeferringTarget")
BKSHIDEventDisplay = _Class("BKSHIDEventDisplay")
BKSHIDEventDeferringPredicate = _Class("BKSHIDEventDeferringPredicate")
BKSMutableHIDEventDeferringPredicate = _Class("BKSMutableHIDEventDeferringPredicate")
BKSSpringBoardDefaults = _Class("BKSSpringBoardDefaults")
BKSPersistentConnectionDefaults = _Class("BKSPersistentConnectionDefaults")
BKSLockdownDefaults = _Class("BKSLockdownDefaults")
BKSIAPDefaults = _Class("BKSIAPDefaults")
BKSKeyboardDefaults = _Class("BKSKeyboardDefaults")
BKSLocalDefaults = _Class("BKSLocalDefaults")
BKSHIDEventKeyCommand = _Class("BKSHIDEventKeyCommand")
BKSHIDEventKeyCommandDescriptor = _Class("BKSHIDEventKeyCommandDescriptor")
BKSHIDEventDeferringToken = _Class("BKSHIDEventDeferringToken")
BKSHIDEventDeferringEnvironment = _Class("BKSHIDEventDeferringEnvironment")
BKSHIDEventKeyCommandsRegistration = _Class("BKSHIDEventKeyCommandsRegistration")
BKSMutableHIDEventKeyCommandsRegistration = _Class(
    "BKSMutableHIDEventKeyCommandsRegistration"
)
BKSHIDEventDeliveryMIGService = _Class("BKSHIDEventDeliveryMIGService")
BKSHIDEventDeliveryManager = _Class("BKSHIDEventDeliveryManager")
BKSInsecureDrawingAction = _Class("BKSInsecureDrawingAction")
BKSRestartAction = _Class("BKSRestartAction")
BKSAccelerometer = _Class("BKSAccelerometer")
