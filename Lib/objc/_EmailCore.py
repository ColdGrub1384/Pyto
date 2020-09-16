'''
Classes from the 'EmailCore' framework.
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

    
ECTransferMessageActionItem = _Class('ECTransferMessageActionItem')
ECSubjectParser = _Class('ECSubjectParser')
_ECSubjectFormatterContext = _Class('_ECSubjectFormatterContext')
ECSubject = _Class('ECSubject')
ECServerMessage = _Class('ECServerMessage')
ECSecureMIMETrustEvaluation = _Class('ECSecureMIMETrustEvaluation')
ECSASLClient = _Class('ECSASLClient')
ECRawMessageHeaders = _Class('ECRawMessageHeaders')
ECRawMessageHeader = _Class('ECRawMessageHeader')
ECNWConnectionWrapper = _Class('ECNWConnectionWrapper')
ECNWActivity = _Class('ECNWActivity')
ECMessageFlags = _Class('ECMessageFlags')
ECMessageFlagChange = _Class('ECMessageFlagChange')
ECLocalMessageActionResults = _Class('ECLocalMessageActionResults')
ECTransferMessageActionResults = _Class('ECTransferMessageActionResults')
ECIMAPAppendInfo = _Class('ECIMAPAppendInfo')
ECIMAPCopyInfo = _Class('ECIMAPCopyInfo')
ECIDNADecoder = _Class('ECIDNADecoder')
ECIDNAEncoder = _Class('ECIDNAEncoder')
ECHTMLStringAndMIMECharset = _Class('ECHTMLStringAndMIMECharset')
ECLocalMessageAction = _Class('ECLocalMessageAction')
ECTransferUndownloadedMessageAction = _Class('ECTransferUndownloadedMessageAction')
ECTransferMessageAction = _Class('ECTransferMessageAction')
ECLabelChangeMessageAction = _Class('ECLabelChangeMessageAction')
ECFlagChangeUndownloadedMessageAction = _Class('ECFlagChangeUndownloadedMessageAction')
ECFlagChangeMessageAction = _Class('ECFlagChangeMessageAction')
ECEncodedWordEncoder = _Class('ECEncodedWordEncoder')
ECEncodedWordDecoder = _Class('ECEncodedWordDecoder')
ECEmailCoreFramework = _Class('ECEmailCoreFramework')
ECEmailAddressParser = _Class('ECEmailAddressParser')
ECEmailAddressLists = _Class('ECEmailAddressLists')
ECEmailAddressComponents = _Class('ECEmailAddressComponents')
ECEmailAddress = _Class('ECEmailAddress')
ECDKIMVerifier = _Class('ECDKIMVerifier')
ECDKIMVerificationContext = _Class('ECDKIMVerificationContext')
ECDKIMPublicKey = _Class('ECDKIMPublicKey')
ECDKIMMessageHeader = _Class('ECDKIMMessageHeader')
ECDKIMDNSClient = _Class('ECDKIMDNSClient')
ECDKIMCryptoUtil = _Class('ECDKIMCryptoUtil')
ECAuthScheme = _Class('ECAuthScheme')
ECPlainAuthScheme = _Class('ECPlainAuthScheme')
ECOAuth2AuthScheme = _Class('ECOAuth2AuthScheme')
ECNTLMAuthScheme = _Class('ECNTLMAuthScheme')
ECGSSAPIAuthScheme = _Class('ECGSSAPIAuthScheme')
ECExternalAuthScheme = _Class('ECExternalAuthScheme')
ECDigestMD5AuthScheme = _Class('ECDigestMD5AuthScheme')
ECCramMD5AuthScheme = _Class('ECCramMD5AuthScheme')
ECAppleTokenAuthScheme = _Class('ECAppleTokenAuthScheme')
ECAPOPAuthScheme = _Class('ECAPOPAuthScheme')
ECAccountsObserver = _Class('ECAccountsObserver')
ECAccountFactory = _Class('ECAccountFactory')
ECAccount = _Class('ECAccount')
ECSMTPAccount = _Class('ECSMTPAccount')
ECPOPAccount = _Class('ECPOPAccount')
ECIMAPAccount = _Class('ECIMAPAccount')
ECExchangeAccount = _Class('ECExchangeAccount')
ECLocalActionReplayer = _Class('ECLocalActionReplayer')
ECTransferUndownloadedActionIMAPReplayer = _Class('ECTransferUndownloadedActionIMAPReplayer')
ECIMAPFlagChangeUndownloadedActionReplayer = _Class('ECIMAPFlagChangeUndownloadedActionReplayer')
ECIMAPFlagChangeActionReplayer = _Class('ECIMAPFlagChangeActionReplayer')
ECGmailLabelChangeReplayer = _Class('ECGmailLabelChangeReplayer')
ECTransferActionReplayer = _Class('ECTransferActionReplayer')
ECTransferActionIMAPReplayer = _Class('ECTransferActionIMAPReplayer')
ECSASLAuthenticator = _Class('ECSASLAuthenticator')
ECAuthenticationScheme = _Class('ECAuthenticationScheme')
ECAngleBracketIDHash = _Class('ECAngleBracketIDHash')
ECSubjectFormatter = _Class('ECSubjectFormatter')
ECEmailAddressFormatter = _Class('ECEmailAddressFormatter')
