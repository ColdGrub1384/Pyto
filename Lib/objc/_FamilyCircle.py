"""
Classes from the 'FamilyCircle' framework.
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


FASharedServiceGroup = _Class("FASharedServiceGroup")
FABroadcaster = _Class("FABroadcaster")
FAPropertyEligibilityRequirements = _Class("FAPropertyEligibilityRequirements")
FAEligibilityRequirements = _Class("FAEligibilityRequirements")
FAFamilyPresenterHostInterface = _Class("FAFamilyPresenterHostInterface")
FAInviteCompletionInfo = _Class("FAInviteCompletionInfo")
FACircleStateResponse = _Class("FACircleStateResponse")
FARecommendedFamilyMember = _Class("FARecommendedFamilyMember")
FASharedService = _Class("FASharedService")
FAMonogram = _Class("FAMonogram")
FAInviteContext = _Class("FAInviteContext")
FAFamilyCloudKitProperties = _Class("FAFamilyCloudKitProperties")
FARequestConfigurator = _Class("FARequestConfigurator")
FAFamilyCircle = _Class("FAFamilyCircle")
FAFollowupManager = _Class("FAFollowupManager")
FAFamilyMember = _Class("FAFamilyMember")
FAPushNotificationHandler = _Class("FAPushNotificationHandler")
FAFamilyCircleRequest = _Class("FAFamilyCircleRequest")
FAFetchFamilyCircleRequest = _Class("FAFetchFamilyCircleRequest")
FARegisterPushTokenRequest = _Class("FARegisterPushTokenRequest")
FAFetchFollowupRequest = _Class("FAFetchFollowupRequest")
FAClearFamilyCircleCacheRequest = _Class("FAClearFamilyCircleCacheRequest")
FALaunchOutOfProcessRequest = _Class("FALaunchOutOfProcessRequest")
FAEligiblityEvaluationRequest = _Class("FAEligiblityEvaluationRequest")
FAFetchFamilyPhotoRequest = _Class("FAFetchFamilyPhotoRequest")
FAHandleFamilyEventPushNotificationRequest = _Class(
    "FAHandleFamilyEventPushNotificationRequest"
)
FAFamilySettings = _Class("FAFamilySettings")
FAUpdateFamilyMemberFlagRequest = _Class("FAUpdateFamilyMemberFlagRequest")
FARemoveFamilyMemberRequest = _Class("FARemoveFamilyMemberRequest")
FAURLConfiguration = _Class("FAURLConfiguration")
_FAFamilyCircleRequestConnectionFactory = _Class(
    "_FAFamilyCircleRequestConnectionFactory"
)
_FAFamilyCircleRequestConnectionProvider = _Class(
    "_FAFamilyCircleRequestConnectionProvider"
)
FAFamilyMemberPhotoRequest = _Class("FAFamilyMemberPhotoRequest")
