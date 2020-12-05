"""
Classes from the 'SignpostSupport' framework.
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


SignpostContextInfo = _Class("SignpostContextInfo")
SignpostAnimationSubInterval = _Class("SignpostAnimationSubInterval")
SignpostFrameLifetimeInterval = _Class("SignpostFrameLifetimeInterval")
SignpostRenderServerRenderInterval = _Class("SignpostRenderServerRenderInterval")
SignpostHIDLatencyInterval = _Class("SignpostHIDLatencyInterval")
SignpostFrameLatencyInterval = _Class("SignpostFrameLatencyInterval")
SignpostAnimationTransactionLifetime = _Class("SignpostAnimationTransactionLifetime")
SignpostCommitInterval = _Class("SignpostCommitInterval")
SignpostSupportCompositorInterval = _Class("SignpostSupportCompositorInterval")
SignpostMetrics = _Class("SignpostMetrics")
SignpostStackFrame = _Class("SignpostStackFrame")
SignpostSupportMetadataSegment = _Class("SignpostSupportMetadataSegment")
SignpostSupportMessageArgument = _Class("SignpostSupportMessageArgument")
SignpostSupportObject = _Class("SignpostSupportObject")
SignpostSupportLogMessage = _Class("SignpostSupportLogMessage")
SignpostObject = _Class("SignpostObject")
SignpostInterval = _Class("SignpostInterval")
SignpostAnimationInterval = _Class("SignpostAnimationInterval")
SignpostEvent = _Class("SignpostEvent")
SignpostStreamEvent = _Class("SignpostStreamEvent")
SignpostCAStallAggregationBuilder = _Class("SignpostCAStallAggregationBuilder")
SignpostCAStallAggregation = _Class("SignpostCAStallAggregation")
SignpostCAProcessStallAggregation = _Class("SignpostCAProcessStallAggregation")
SignpostCAIntervalAggregationStats = _Class("SignpostCAIntervalAggregationStats")
SignpostSupportMachTimeTranslator = _Class("SignpostSupportMachTimeTranslator")
SignpostSupportMachTimeTranslationRange = _Class(
    "SignpostSupportMachTimeTranslationRange"
)
SignpostSupportSerializabledObjectCollection = _Class(
    "SignpostSupportSerializabledObjectCollection"
)
SignpostIntervalBuilder = _Class("SignpostIntervalBuilder")
SignpostAnimationAccumulatedState = _Class("SignpostAnimationAccumulatedState")
SignpostCAInstrumentationProcessor = _Class("SignpostCAInstrumentationProcessor")
SignpostFrameAccumulatedState = _Class("SignpostFrameAccumulatedState")
SignpostSupportExactProcessNameFilter = _Class("SignpostSupportExactProcessNameFilter")
SignpostSupportExactProcessNameWhitelist = _Class(
    "SignpostSupportExactProcessNameWhitelist"
)
SignpostSupportExactProcessNameBlacklist = _Class(
    "SignpostSupportExactProcessNameBlacklist"
)
SignpostSupportUniquePIDFilter = _Class("SignpostSupportUniquePIDFilter")
SignpostSupportUniquePIDWhitelist = _Class("SignpostSupportUniquePIDWhitelist")
SignpostSupportUniquePIDBlacklist = _Class("SignpostSupportUniquePIDBlacklist")
SignpostSupportPIDFilter = _Class("SignpostSupportPIDFilter")
SignpostSupportPIDWhitelist = _Class("SignpostSupportPIDWhitelist")
SignpostSupportPIDBlacklist = _Class("SignpostSupportPIDBlacklist")
SignpostSupportObjectFilter = _Class("SignpostSupportObjectFilter")
SignpostSupportSubsystemCategoryFilter = _Class(
    "SignpostSupportSubsystemCategoryFilter"
)
SignpostSupportSubsystemCategoryBlacklist = _Class(
    "SignpostSupportSubsystemCategoryBlacklist"
)
SignpostSupportSubsystemCategoryWhitelist = _Class(
    "SignpostSupportSubsystemCategoryWhitelist"
)
SignpostSupportSubsystemCategoryFilterEntry = _Class(
    "SignpostSupportSubsystemCategoryFilterEntry"
)
SignpostSupportObjectExtractor = _Class("SignpostSupportObjectExtractor")
