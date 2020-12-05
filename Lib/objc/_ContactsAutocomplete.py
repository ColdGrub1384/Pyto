"""
Classes from the 'ContactsAutocomplete' framework.
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


CNAutocompleteRecentsSearch = _Class("CNAutocompleteRecentsSearch")
CNAutocompleteResultTracing = _Class("CNAutocompleteResultTracing")
CNAutocompleteResultFactory = _Class("CNAutocompleteResultFactory")
CNAutocompleteSuggestionsSearch = _Class("CNAutocompleteSuggestionsSearch")
CNAutocompleteResult = _Class("CNAutocompleteResult")
CNAutocompleteGroupResult = _Class("CNAutocompleteGroupResult")
CNAutocompleteDuetContactResult = _Class("CNAutocompleteDuetContactResult")
CNAutocompleteCalendarServerResult = _Class("CNAutocompleteCalendarServerResult")
CNAutocompleteDirectoryServerResult = _Class("CNAutocompleteDirectoryServerResult")
CNAutocompleteExtensionResult = _Class("CNAutocompleteExtensionResult")
CNAutocompleteSuggestedContactResult = _Class("CNAutocompleteSuggestedContactResult")
CNAutocompleteRecentResult = _Class("CNAutocompleteRecentResult")
CNAutocompleteInfrequentRecentResult = _Class("CNAutocompleteInfrequentRecentResult")
CNAutocompleteFrequentRecentResult = _Class("CNAutocompleteFrequentRecentResult")
CNAutocompleteStoreQueryHelper = _Class("CNAutocompleteStoreQueryHelper")
CNAutocompleteCalendarServerSearch = _Class("CNAutocompleteCalendarServerSearch")
_CNAutocompleteAggregateSourceInclusionPolicy = _Class(
    "_CNAutocompleteAggregateSourceInclusionPolicy"
)
_CNAutocompleteEntitlementSourceInclusionPolicy = _Class(
    "_CNAutocompleteEntitlementSourceInclusionPolicy"
)
_CNAutocompleteUserDefaultsSourceInclusionPolicy = _Class(
    "_CNAutocompleteUserDefaultsSourceInclusionPolicy"
)
_CNAutocompleteMutableSourceInclusionPolicy = _Class(
    "_CNAutocompleteMutableSourceInclusionPolicy"
)
CNAutocompleteSourceInclusionPolicy = _Class("CNAutocompleteSourceInclusionPolicy")
CNAutocompleteResultValue = _Class("CNAutocompleteResultValue")
CNAutocompleteStoreQueryContext = _Class("CNAutocompleteStoreQueryContext")
CNAutocompleteCoreAnalyticsUsageMonitorProbe = _Class(
    "CNAutocompleteCoreAnalyticsUsageMonitorProbe"
)
CNAutocompleteQueryResponseUniqueResultFinder = _Class(
    "CNAutocompleteQueryResponseUniqueResultFinder"
)
CNAutocompleteQueryResponsePreparer = _Class("CNAutocompleteQueryResponsePreparer")
_CNAutocompleteResponsePreparerDecorator = _Class(
    "_CNAutocompleteResponsePreparerDecorator"
)
_CNFilteringResponsePreparer = _Class("_CNFilteringResponsePreparer")
_CNDelegateAdjustingResponsePreparer = _Class("_CNDelegateAdjustingResponsePreparer")
_CNSortingResponsePreparer = _Class("_CNSortingResponsePreparer")
_CNDiagnosticResponsePreparer = _Class("_CNDiagnosticResponsePreparer")
CNAutocompleteResultTokenMatcher = _Class("CNAutocompleteResultTokenMatcher")
CNAutocompleteFetchContext = _Class("CNAutocompleteFetchContext")
CNAutocompleteQueryCacheMissAuditor = _Class("CNAutocompleteQueryCacheMissAuditor")
_CNAutocompleteNonCachingSearchProvider = _Class(
    "_CNAutocompleteNonCachingSearchProvider"
)
CNAutocompleteAggdPerformanceProbe = _Class("CNAutocompleteAggdPerformanceProbe")
CNAutocompleteQuery = _Class("CNAutocompleteQuery")
CNAutocompleteQueryCacheHelper = _Class("CNAutocompleteQueryCacheHelper")
CNAutocompleteObservableBuilder = _Class("CNAutocompleteObservableBuilder")
CNAutocompleteNetworkActivityThrottlingPolicy = _Class(
    "CNAutocompleteNetworkActivityThrottlingPolicy"
)
CNAutocompleteNetworkActivityPolicy = _Class("CNAutocompleteNetworkActivityPolicy")
CNAutocompleteNameComponents = _Class("CNAutocompleteNameComponents")
_CNAutocompleteCachingSearchProvider = _Class("_CNAutocompleteCachingSearchProvider")
CNAutocompleteProbeKeyBuilder = _Class("CNAutocompleteProbeKeyBuilder")
CNAutocompleteRecentContactsTransform = _Class("CNAutocompleteRecentContactsTransform")
CNAutocompleteEntitlementVerifier = _Class("CNAutocompleteEntitlementVerifier")
CNAClassKitResultTransformVisitor = _Class("CNAClassKitResultTransformVisitor")
CNAutocompleteLocalSearch = _Class("CNAutocompleteLocalSearch")
CNAutocompleteDirectoryServerSearch = _Class("CNAutocompleteDirectoryServerSearch")
CNAutocompleteLocalExtensionSearch = _Class("CNAutocompleteLocalExtensionSearch")
CNAutocompleteLocalGroupsFetcher = _Class("CNAutocompleteLocalGroupsFetcher")
CNAutocompleteInputStringTokenizer = _Class("CNAutocompleteInputStringTokenizer")
CNAutocompleteSearchObservableProvider = _Class(
    "CNAutocompleteSearchObservableProvider"
)
CNAutocompleteLocalContactsFetcher = _Class("CNAutocompleteLocalContactsFetcher")
_CNAutocompleteObservableBuilderBatchingHelper = _Class(
    "_CNAutocompleteObservableBuilderBatchingHelper"
)
_CNAutocompleteCalendarObservableBuilderBatchingHelper = _Class(
    "_CNAutocompleteCalendarObservableBuilderBatchingHelper"
)
_CNAutocompleteStandardObservableBuilderBatchingHelper = _Class(
    "_CNAutocompleteStandardObservableBuilderBatchingHelper"
)
CNAutocompleteObservableBuilderBatchingHelperFactory = _Class(
    "CNAutocompleteObservableBuilderBatchingHelperFactory"
)
CNAutocompleteLocalQuery = _Class("CNAutocompleteLocalQuery")
CNAutocompleteLocalContactResultTransformBuilder = _Class(
    "CNAutocompleteLocalContactResultTransformBuilder"
)
CNAutocompleteDuetSearch = _Class("CNAutocompleteDuetSearch")
CNAutocompleteFetchBlockDelegate = _Class("CNAutocompleteFetchBlockDelegate")
CNAutocompleteSearchProviderFactory = _Class("CNAutocompleteSearchProviderFactory")
CNAutocompleteTokenMatcher = _Class("CNAutocompleteTokenMatcher")
CNAutocompleteCalendarQueryAssembler = _Class("CNAutocompleteCalendarQueryAssembler")
CNAutocompleteStore = _Class("CNAutocompleteStore")
CNAutocompleteFetchRequestTracing = _Class("CNAutocompleteFetchRequestTracing")
CNAutocompleteFetchRequest = _Class("CNAutocompleteFetchRequest")
_CNAutocompleteFetchDelegateSafeWrapper = _Class(
    "_CNAutocompleteFetchDelegateSafeWrapper"
)
CNAutocompleteDelegateWrapper = _Class("CNAutocompleteDelegateWrapper")
CNAutocompleteCalendarServerOperationFactory = _Class(
    "CNAutocompleteCalendarServerOperationFactory"
)
_CNAutocompleteQueryCacheMissAggdLogging = _Class(
    "_CNAutocompleteQueryCacheMissAggdLogging"
)
_CNAutocompleteQueryCacheMissOSLogging = _Class(
    "_CNAutocompleteQueryCacheMissOSLogging"
)
CNAutocompleteQueryCacheMissLogger = _Class("CNAutocompleteQueryCacheMissLogger")
CNAutocompleteStoreReproStringRecorder = _Class(
    "CNAutocompleteStoreReproStringRecorder"
)
CNAutocompleteProbeProviderFactory = _Class("CNAutocompleteProbeProviderFactory")
_CNAutocompleteAggdProbeProvider = _Class("_CNAutocompleteAggdProbeProvider")
CNAutocompleteSuggestionsProbe = _Class("CNAutocompleteSuggestionsProbe")
CNAutocompleteUsageMonitor = _Class("CNAutocompleteUsageMonitor")
CNAutocompleteAggdProbeAggdWrapper = _Class("CNAutocompleteAggdProbeAggdWrapper")
CNAutocompleteAggdProbe = _Class("CNAutocompleteAggdProbe")
_CNAutocompleteUserSessionDisplayedResults = _Class(
    "_CNAutocompleteUserSessionDisplayedResults"
)
CNAutocompleteUserSession = _Class("CNAutocompleteUserSession")
CNAutocompleteRecentContactsLibrary = _Class("CNAutocompleteRecentContactsLibrary")
CNAutocompleteObservable = _Class("CNAutocompleteObservable")
