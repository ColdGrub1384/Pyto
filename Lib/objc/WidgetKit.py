'''
Classes from the 'WidgetKit' framework.
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

    
_TtC9WidgetKitP33_4EED76D0401824B32C7CAD5F3379DA3F26TightLeadingFontDefinition = _Class('_TtC9WidgetKitP33_4EED76D0401824B32C7CAD5F3379DA3F26TightLeadingFontDefinition')
_TtC9WidgetKitP33_4EED76D0401824B32C7CAD5F3379DA3F45ContentSizeCategoryIncrementingFontDefinition = _Class('_TtC9WidgetKitP33_4EED76D0401824B32C7CAD5F3379DA3F45ContentSizeCategoryIncrementingFontDefinition')
_TtC9WidgetKitP33_4EED76D0401824B32C7CAD5F3379DA3F45ContentSizeCategoryDecrementingFontDefinition = _Class('_TtC9WidgetKitP33_4EED76D0401824B32C7CAD5F3379DA3F45ContentSizeCategoryDecrementingFontDefinition')
WidgetURLHandler = _Class('WidgetKit.WidgetURLHandler')
UnfairLock = _Class('WidgetKit.UnfairLock')
BaseEntryProviderBox = _Class('WidgetKit.BaseEntryProviderBox')
WidgetPreviewAgent = _Class('WidgetKit.WidgetPreviewAgent')
_WidgetExtensionSession = _Class('WidgetKit._WidgetExtensionSession')
_RunningBoardInterface = _Class('WidgetKit._RunningBoardInterface')
WidgetExtensionSessionFactory = _Class('WidgetKit.WidgetExtensionSessionFactory')
_TtC9WidgetKitP33_A678AB8EBD96EB0F22F9B66B950B3AAD19ClockHandController = _Class('_TtC9WidgetKitP33_A678AB8EBD96EB0F22F9B66B950B3AAD19ClockHandController')
OptionalLocalizationsWrapper = _Class('WidgetKit.OptionalLocalizationsWrapper')
WidgetHost = _Class('WidgetKit.WidgetHost')
ResolvedWidgetBundleHost = _Class('WidgetKit.ResolvedWidgetBundleHost')
WidgetArchiver = _Class('WidgetKit.WidgetArchiver')
WidgetLocalizations = _Class('WidgetKit.WidgetLocalizations')
WGAutoreleasePool = _Class('WidgetKit.WGAutoreleasePool')
_TimelineArchivedViewCollection = _Class('WidgetKit._TimelineArchivedViewCollection')
Dates = _Class('WidgetKit.Dates')
_TtCCV9WidgetKit17WidgetEnvironment16AnyKeyValueTupleP33_78669324E9282AD527DC22F3259D9FF411StorageBase = _Class('_TtCCV9WidgetKit17WidgetEnvironment16AnyKeyValueTupleP33_78669324E9282AD527DC22F3259D9FF411StorageBase')
_TtCV9WidgetKit17WidgetEnvironment16AnyKeyValueTuple = _Class('_TtCV9WidgetKit17WidgetEnvironment16AnyKeyValueTuple')
_TtCCV9WidgetKit17WidgetEnvironment8AnyValueP33_78669324E9282AD527DC22F3259D9FF411StorageBase = _Class('_TtCCV9WidgetKit17WidgetEnvironment8AnyValueP33_78669324E9282AD527DC22F3259D9FF411StorageBase')
_TtCV9WidgetKit17WidgetEnvironment8AnyValue = _Class('_TtCV9WidgetKit17WidgetEnvironment8AnyValue')
_TtCCV9WidgetKit17WidgetEnvironment6AnyKeyP33_78669324E9282AD527DC22F3259D9FF411StorageBase = _Class('_TtCCV9WidgetKit17WidgetEnvironment6AnyKeyP33_78669324E9282AD527DC22F3259D9FF411StorageBase')
_TtCV9WidgetKit17WidgetEnvironment6AnyKey = _Class('_TtCV9WidgetKit17WidgetEnvironment6AnyKey')
WidgetViewCollection = _Class('WidgetKit.WidgetViewCollection')
WidgetCenter = _Class('WidgetKit.WidgetCenter')
CHKWidgetPersonality = _Class('CHKWidgetPersonality')
CHKWidgetEnvironment = _Class('CHKWidgetEnvironment')
WidgetExtensionChecker = _Class('WidgetExtensionChecker')
_CHSWidgetMetricsCodable = _Class('_CHSWidgetMetricsCodable')
_AvocadoExtensionBaseContext = _Class('WidgetKit._AvocadoExtensionBaseContext')
WidgetExtensionContext = _Class('WidgetKit.WidgetExtensionContext')
WidgetHostContext = _Class('WidgetKit.WidgetHostContext')
