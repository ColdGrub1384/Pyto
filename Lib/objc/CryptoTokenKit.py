'''
Classes from the 'CryptoTokenKit' framework.
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

    
TKTokenWatcher = _Class('TKTokenWatcher')
TKTokenWatcherTokenInfo = _Class('TKTokenWatcherTokenInfo')
TKTokenWatcherProxy = _Class('TKTokenWatcherProxy')
TKTokenKeyAlgorithm = _Class('TKTokenKeyAlgorithm')
TKTokenKeyExchangeParameters = _Class('TKTokenKeyExchangeParameters')
TKApplicationProxy = _Class('TKApplicationProxy')
TKTokenConnection = _Class('TKTokenConnection')
TKTokenSessionConnection = _Class('TKTokenSessionConnection')
TKTokenAccessUserPromptInfo = _Class('TKTokenAccessUserPromptInfo')
TKSharedResource = _Class('TKSharedResource')
TKSharedResourceSlot = _Class('TKSharedResourceSlot')
TKTokenAccessRegistry = _Class('TKTokenAccessRegistry')
TKSmartCardATR = _Class('TKSmartCardATR')
TKSmartCardATRInterfaceGroup = _Class('TKSmartCardATRInterfaceGroup')
TKTokenAccessUserPromptNoop = _Class('TKTokenAccessUserPromptNoop')
TKTokenAccessUserPromptRemoteAlert = _Class('TKTokenAccessUserPromptRemoteAlert')
TKTokenKeychainContents = _Class('TKTokenKeychainContents')
TKTokenKeychainItem = _Class('TKTokenKeychainItem')
TKTokenKeychainKey = _Class('TKTokenKeychainKey')
TKTokenKeychainCertificate = _Class('TKTokenKeychainCertificate')
TKTokenAccessRequest = _Class('TKTokenAccessRequest')
TKClientTokenAdvertisedItem = _Class('TKClientTokenAdvertisedItem')
TKClientTokenSession = _Class('TKClientTokenSession')
TKClientTokenObject = _Class('TKClientTokenObject')
TKClientToken = _Class('TKClientToken')
TKTokenSession = _Class('TKTokenSession')
TKSmartCardTokenSession = _Class('TKSmartCardTokenSession')
TKTokenAuthOperation = _Class('TKTokenAuthOperation')
TKTokenPasswordAuthOperation = _Class('TKTokenPasswordAuthOperation')
TKTokenSmartCardPINAuthOperation = _Class('TKTokenSmartCardPINAuthOperation')
TKSmartCardSessionEngine = _Class('TKSmartCardSessionEngine')
TKSmartCardSlotEngine = _Class('TKSmartCardSlotEngine')
_TKSmartCardSlotReservation = _Class('_TKSmartCardSlotReservation')
TKPowerMonitor = _Class('TKPowerMonitor')
TKSmartCardSessionRequest = _Class('TKSmartCardSessionRequest')
TKTokenDriverConfiguration = _Class('TKTokenDriverConfiguration')
TKTokenConfiguration = _Class('TKTokenConfiguration')
TKTokenConfigurationTransaction = _Class('TKTokenConfigurationTransaction')
TKTokenConfigurationConnection = _Class('TKTokenConfigurationConnection')
TKTokenID = _Class('TKTokenID')
TKSmartCardUserInteraction = _Class('TKSmartCardUserInteraction')
TKSmartCardUserInteractionForStringEntry = _Class('TKSmartCardUserInteractionForStringEntry')
TKSmartCardUserInteractionForConfirmation = _Class('TKSmartCardUserInteractionForConfirmation')
TKSmartCardUserInteractionForPINOperation = _Class('TKSmartCardUserInteractionForPINOperation')
TKSmartCardUserInteractionForSecurePINChange = _Class('TKSmartCardUserInteractionForSecurePINChange')
TKSmartCardUserInteractionForSecurePINVerification = _Class('TKSmartCardUserInteractionForSecurePINVerification')
TKSmartCardSlotScreen = _Class('TKSmartCardSlotScreen')
TKSmartCardPINFormat = _Class('TKSmartCardPINFormat')
TKSmartCard = _Class('TKSmartCard')
TKSmartCardWithError = _Class('TKSmartCardWithError')
TKSmartCardSlot = _Class('TKSmartCardSlot')
TKSmartCardSlotProxy = _Class('TKSmartCardSlotProxy')
TKSmartCardSlotManager = _Class('TKSmartCardSlotManager')
TKTokenAccessDBBackedByUserDefaults = _Class('TKTokenAccessDBBackedByUserDefaults')
TKTLVRecord = _Class('TKTLVRecord')
TKCompactTLVRecord = _Class('TKCompactTLVRecord')
TKSimpleTLVRecord = _Class('TKSimpleTLVRecord')
TKBERTLVRecord = _Class('TKBERTLVRecord')
TKDataSource = _Class('TKDataSource')
TKTokenDriverRequest = _Class('TKTokenDriverRequest')
TKTokenService_Subsystem = _Class('TKTokenService_Subsystem')
TKTokenDriver = _Class('TKTokenDriver')
TKSmartCardTokenDriver = _Class('TKSmartCardTokenDriver')
TKToken = _Class('TKToken')
TKSmartCardToken = _Class('TKSmartCardToken')
TKTokenBaseContext = _Class('TKTokenBaseContext')
TKTokenDriverContext = _Class('TKTokenDriverContext')
