'''
Classes from the 'SetupAssistantSupport' framework.
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

    
SASProximityAnisetteDataProvider = _Class('SASProximityAnisetteDataProvider')
SASProximityInformation = _Class('SASProximityInformation')
SASProximitySessionTransport = _Class('SASProximitySessionTransport')
SASProximitySessionSharingTransport = _Class('SASProximitySessionSharingTransport')
SASProximityHandshake = _Class('SASProximityHandshake')
SASProximitySession = _Class('SASProximitySession')
SASLogging = _Class('SASLogging')
SASSystemInformation = _Class('SASSystemInformation')
SASProximityAction = _Class('SASProximityAction')
SASProximityAnisetteRequestAction = _Class('SASProximityAnisetteRequestAction')
SASProximityBackupAction = _Class('SASProximityBackupAction')
SASProximityFinishedAction = _Class('SASProximityFinishedAction')
SASProximityMigrationStartAction = _Class('SASProximityMigrationStartAction')
SASProximityPasscodeValidationAction = _Class('SASProximityPasscodeValidationAction')
SASProximityReadyAction = _Class('SASProximityReadyAction')
SASProximityHandshakeAction = _Class('SASProximityHandshakeAction')
SASProximityCompanionAuthRequestAction = _Class('SASProximityCompanionAuthRequestAction')
SASProximityInformationAction = _Class('SASProximityInformationAction')
SASProximityMigrationTransferPreparationAction = _Class('SASProximityMigrationTransferPreparationAction')
