"""
Classes from the 'ChronoServices' framework.
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


CHSWidgetKeysBox = _Class("CHSWidgetKeysBox")
CHSPlaceholderRequest = _Class("CHSPlaceholderRequest")
CHSWidgetMetrics = _Class("CHSWidgetMetrics")
CHSToolSupportService = _Class("CHSToolSupportService")
CHSTimelineController = _Class("CHSTimelineController")
CHSProactiveService = _Class("CHSProactiveService")
CHSNSURLSessiondService = _Class("CHSNSURLSessiondService")
CHSURLSessionToken = _Class("CHSURLSessionToken")
CHSWidgetMetricsSpecification = _Class("CHSWidgetMetricsSpecification")
CHSMutableWidgetMetricsSpecification = _Class("CHSMutableWidgetMetricsSpecification")
CHSScreenshotManager = _Class("CHSScreenshotManager")
CHSConfiguredWidgetContainerConsumer = _Class("CHSConfiguredWidgetContainerConsumer")
CHSConfiguredWidgetContainerDescriptorsBox = _Class(
    "CHSConfiguredWidgetContainerDescriptorsBox"
)
CHSConfiguredWidgetContainerDescriptor = _Class(
    "CHSConfiguredWidgetContainerDescriptor"
)
CHSConfiguredWidgetDescriptor = _Class("CHSConfiguredWidgetDescriptor")
CHSSizeConfiguration = _Class("CHSSizeConfiguration")
CHSChronoToolServiceSpecification = _Class("CHSChronoToolServiceSpecification")
CHSWidgetKey = _Class("CHSWidgetKey")
CHSChronoServicesConnection = _Class("CHSChronoServicesConnection")
CHSAvocadoDescriptorsBox = _Class("CHSAvocadoDescriptorsBox")
CHSAvocadoDescriptorProvider = _Class("CHSAvocadoDescriptorProvider")
CHSAvocadoDescriptor = _Class("CHSAvocadoDescriptor")
CHSLocalizableString = _Class("CHSLocalizableString")
CHSApplicationProcessStateChangeConsumer = _Class(
    "CHSApplicationProcessStateChangeConsumer"
)
CHSChronoServicesToolConnection = _Class("CHSChronoServicesToolConnection")
CHSChronoWidgetServiceSpecification = _Class("CHSChronoWidgetServiceSpecification")
CHSWidget = _Class("CHSWidget")
