'''
Classes from the 'AddressBookLegacy' framework.
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

    
ABVCardActivityAlertSerialization = _Class('ABVCardActivityAlertSerialization')
ABVCardActivityAlertEscapingSerializationStrategy = _Class('ABVCardActivityAlertEscapingSerializationStrategy')
ABVCardActivityAlertQuotingSerializationStrategy = _Class('ABVCardActivityAlertQuotingSerializationStrategy')
ABVCardActivityAlertSerializer = _Class('ABVCardActivityAlertSerializer')
ABBufferQueryCursor = _Class('ABBufferQueryCursor')
ABBufferQuery = _Class('ABBufferQuery')
ABBinders = _Class('ABBinders')
ABPhoneFormatting = _Class('ABPhoneFormatting')
ABDynamicLoader = _Class('ABDynamicLoader')
NamePredicateSortKeyWrapper = _Class('NamePredicateSortKeyWrapper')
ABSQLPredicate = _Class('ABSQLPredicate')
ABFavoritesListManager = _Class('ABFavoritesListManager')
ABFavoritesLookupChangeRecord = _Class('ABFavoritesLookupChangeRecord')
ABFavoritesEntry = _Class('ABFavoritesEntry')
ABDataCollection = _Class('ABDataCollection')
_ABVCardTimeProvider = _Class('_ABVCardTimeProvider')
ABVCardWatchdogTimer = _Class('ABVCardWatchdogTimer')
ABChangeStoreRowInfo = _Class('ABChangeStoreRowInfo')
ABChangeStoreInfo = _Class('ABChangeStoreInfo')
ABVCardValueSetter = _Class('ABVCardValueSetter')
ABVCardPersonValueSetter = _Class('ABVCardPersonValueSetter')
ABVCardCardDAVValueSetter = _Class('ABVCardCardDAVValueSetter')
ABVCardParameter = _Class('ABVCardParameter')
ABVCardParser = _Class('ABVCardParser')
ABVCardCardDAVParser = _Class('ABVCardCardDAVParser')
ABUtils = _Class('ABUtils')
ABVCardLexer = _Class('ABVCardLexer')
ABVCardRecord = _Class('ABVCardRecord')
ABVCardCardDAVRecord = _Class('ABVCardCardDAVRecord')
ABVCardExporter = _Class('ABVCardExporter')
ABVCardCardDAVExporter = _Class('ABVCardCardDAVExporter')
ABVCardActivityAlertScanner = _Class('ABVCardActivityAlertScanner')
ABPersonLinker = _Class('ABPersonLinker')
ABPhoneNumber = _Class('ABPhoneNumber')
ABCCallbackInvoker = _Class('ABCCallbackInvoker')
ABDowntimeWhitelistMigrator = _Class('ABDowntimeWhitelistMigrator')
ABAccountScorer = _Class('ABAccountScorer')
ABFacebookMigrator = _Class('ABFacebookMigrator')
ABVCardDateScanner = _Class('ABVCardDateScanner')
ABPredicate = _Class('ABPredicate')
ABServerSearchPredicate = _Class('ABServerSearchPredicate')
ABAnyValuePredicate = _Class('ABAnyValuePredicate')
ABPhonePredicate = _Class('ABPhonePredicate')
ABValuePredicate = _Class('ABValuePredicate')
ABNamePredicate = _Class('ABNamePredicate')
ABGroupMembershipPredicate = _Class('ABGroupMembershipPredicate')
ABSearchOperation = _Class('ABSearchOperation')
