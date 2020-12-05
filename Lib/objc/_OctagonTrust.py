"""
Classes from the 'OctagonTrust' framework.
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


OTEscrowTranslation = _Class("OTEscrowTranslation")
OTICDPRecordContext = _Class("OTICDPRecordContext")
OTEscrowRecord = _Class("OTEscrowRecord")
OTCDPRecoveryInformation = _Class("OTCDPRecoveryInformation")
OTEscrowRecordMetadataClientMetadata = _Class("OTEscrowRecordMetadataClientMetadata")
OTEscrowRecordMetadata = _Class("OTEscrowRecordMetadata")
OTEscrowAuthenticationInformation = _Class("OTEscrowAuthenticationInformation")
OTICDPRecordSilentContext = _Class("OTICDPRecordSilentContext")
