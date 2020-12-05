"""
Classes from the 'EmojiFoundation' framework.
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


EMFQueryResultOverride = _Class("EMFQueryResultOverride")
EMFEmojiLocaleData = _Class("EMFEmojiLocaleData")
EMFEmojiSearchEngine = _Class("EMFEmojiSearchEngine")
EMFIndexManager = _Class("EMFIndexManager")
EMFQueryEvaluator = _Class("EMFQueryEvaluator")
EMFDefaultAutocompleteCandidateProvider = _Class(
    "EMFDefaultAutocompleteCandidateProvider"
)
EMFStringUtilities = _Class("EMFStringUtilities")
EMFIndexLoader = _Class("EMFIndexLoader")
EMFQueryResultOverrideListLoader = _Class("EMFQueryResultOverrideListLoader")
EMFEmojiToken = _Class("EMFEmojiToken")
EMFSearchEngineBundleLoader = _Class("EMFSearchEngineBundleLoader")
EMFInvertedIndex = _Class("EMFInvertedIndex")
EMFStringStemmer = _Class("EMFStringStemmer")
EMFQueryResultOverrideList = _Class("EMFQueryResultOverrideList")
EMFQueryResult = _Class("EMFQueryResult")
EMFEmojiCategory = _Class("EMFEmojiCategory")
EMFQueryLogger = _Class("EMFQueryLogger")
EMFIndexStrategyFactory = _Class("EMFIndexStrategyFactory")
EMFEmojiPreferencesService = _Class("EMFEmojiPreferencesService")
EMFEmojiPreferences = _Class("EMFEmojiPreferences")
EMFEmojiPreferencesClient = _Class("EMFEmojiPreferencesClient")
EMFQuery = _Class("EMFQuery")
EMFQueryUntokenized = _Class("EMFQueryUntokenized")
EMFAbstractIndexStrategy = _Class("EMFAbstractIndexStrategy")
EMFIndexStrategySingleStemmedIndexOnly = _Class(
    "EMFIndexStrategySingleStemmedIndexOnly"
)
EMFIndexStrategyDefault = _Class("EMFIndexStrategyDefault")
