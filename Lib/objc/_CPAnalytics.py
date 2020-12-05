"""
Classes from the 'CPAnalytics' framework.
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


CPAnalyticsSystemProperties = _Class("CPAnalyticsSystemProperties")
CPAnalyticsConditional = _Class("CPAnalyticsConditional")
PhotosAnalyticsSystemPropertyProvider = _Class("PhotosAnalyticsSystemPropertyProvider")
CPAnalyticsMetricsDestination = _Class("CPAnalyticsMetricsDestination")
CPAnalyticsMetricEventRoute = _Class("CPAnalyticsMetricEventRoute")
CPAnalyticsCoreAnalyticsHelper = _Class("CPAnalyticsCoreAnalyticsHelper")
CPAnalyticsPropertyProviderClassLoader = _Class(
    "CPAnalyticsPropertyProviderClassLoader"
)
CPAnalyticsScreenManager = _Class("CPAnalyticsScreenManager")
CPAnalytics = _Class("CPAnalytics")
CPAnalyticsDestinationsRegistry = _Class("CPAnalyticsDestinationsRegistry")
CPAnalyticsEvent = _Class("CPAnalyticsEvent")
CPAnalyticsLogDestination = _Class("CPAnalyticsLogDestination")
PhotosAnalyticsDemographicPropertyProvider = _Class(
    "PhotosAnalyticsDemographicPropertyProvider"
)
CPAnalyticsDashboardDestination = _Class("CPAnalyticsDashboardDestination")
CPAnalyticsAppStateDestination = _Class("CPAnalyticsAppStateDestination")
CPAnalyticsIntervalDestination = _Class("CPAnalyticsIntervalDestination")
CPAnalyticsEventCounter = _Class("CPAnalyticsEventCounter")
CPAnalyticsDevLogger = _Class("CPAnalyticsDevLogger")
CPAnalyticsEventMatcher = _Class("CPAnalyticsEventMatcher")
CPAnalyticsCompoundEventMatcher = _Class("CPAnalyticsCompoundEventMatcher")
CPAnalyticsLogEventMatcher = _Class("CPAnalyticsLogEventMatcher")
CPAnalyticsCoreDuetEventMatcher = _Class("CPAnalyticsCoreDuetEventMatcher")
CPAnalyticsKnowledgeStoreDestination = _Class("CPAnalyticsKnowledgeStoreDestination")
CPAnalyticsKnowledgeStoreDatasetSample = _Class(
    "CPAnalyticsKnowledgeStoreDatasetSample"
)
CPAnalyticsSignpostDestination = _Class("CPAnalyticsSignpostDestination")
CPAnalyticsErrorPropertyProvider = _Class("CPAnalyticsErrorPropertyProvider")
