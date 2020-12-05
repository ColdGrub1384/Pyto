"""
Classes from the 'LoggingSupport' framework.
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


OSLogEventStore = _Class("OSLogEventStore")
OSLogEventLocalStore = _Class("OSLogEventLocalStore")
_OSLogEventStoreMetadata = _Class("_OSLogEventStoreMetadata")
_OSLogEventStoreTimeRef = _Class("_OSLogEventStoreTimeRef")
OSLogDecomposedMessageSegment = _Class("OSLogDecomposedMessageSegment")
OSLogEventSerializer = _Class("OSLogEventSerializer")
_OSLogEventSerializationMetadata = _Class("_OSLogEventSerializationMetadata")
OSLogPreferencesCategory = _Class("OSLogPreferencesCategory")
OSLogPreferencesSubsystem = _Class("OSLogPreferencesSubsystem")
OSLogPreferencesProcess = _Class("OSLogPreferencesProcess")
OSLogPreferencesManager = _Class("OSLogPreferencesManager")
OSLogEventSource = _Class("OSLogEventSource")
_OSLogStreamFilter = _Class("_OSLogStreamFilter")
_OSLogSimplePredicate = _Class("_OSLogSimplePredicate")
LoggingSupport_OSLogCoder = _Class("LoggingSupport_OSLogCoder")
_OSLogVersioning = _Class("_OSLogVersioning")
OSLogEventStreamPosition = _Class("OSLogEventStreamPosition")
OSLogEventLiveStore = _Class("OSLogEventLiveStore")
_OSLogCollectionReference = _Class("_OSLogCollectionReference")
_OSLogDirectoryReference = _Class("_OSLogDirectoryReference")
_OSLogCatalogFilter = _Class("_OSLogCatalogFilter")
OSLogTermDumper = _Class("OSLogTermDumper")
OSLogEventStreamBase = _Class("OSLogEventStreamBase")
OSLogDeserializedEventStream = _Class("OSLogDeserializedEventStream")
OSLogEventStream = _Class("OSLogEventStream")
OSLogEventLiveStream = _Class("OSLogEventLiveStream")
OSLogPersistence = _Class("OSLogPersistence")
_OSLogPredicateMapper = _Class("_OSLogPredicateMapper")
_OSLogLegacyPredicateMapper = _Class("_OSLogLegacyPredicateMapper")
_OSLogIndex = _Class("_OSLogIndex")
_OSLogIndexEnumerator = _Class("_OSLogIndexEnumerator")
_OSLogTracepointBuffer = _Class("_OSLogTracepointBuffer")
_OSLogEnumeratorCatalog = _Class("_OSLogEnumeratorCatalog")
_OSLogEnumeratorCatalogSubchunk = _Class("_OSLogEnumeratorCatalogSubchunk")
_OSLogChunkBuffer = _Class("_OSLogChunkBuffer")
_OSLogEnumeratorOversizeChunk = _Class("_OSLogEnumeratorOversizeChunk")
_OSLogIndexFile = _Class("_OSLogIndexFile")
_OSLogChunkFileReference = _Class("_OSLogChunkFileReference")
_OSLogChunkStore = _Class("_OSLogChunkStore")
_OSLogChunkFile = _Class("_OSLogChunkFile")
_OSLogChunkMemory = _Class("_OSLogChunkMemory")
OSLogEventLiveSource = _Class("OSLogEventLiveSource")
OSActivityEvent = _Class("OSActivityEvent")
OSActivityLossEvent = _Class("OSActivityLossEvent")
OSActivityTimesyncEvent = _Class("OSActivityTimesyncEvent")
OSActivityStatedumpEvent = _Class("OSActivityStatedumpEvent")
OSActivityTransitionEvent = _Class("OSActivityTransitionEvent")
OSActivityUserActionEvent = _Class("OSActivityUserActionEvent")
OSActivityEventMessage = _Class("OSActivityEventMessage")
OSActivityLogMessageEvent = _Class("OSActivityLogMessageEvent")
OSActivitySignpostEvent = _Class("OSActivitySignpostEvent")
OSActivityTraceMessageEvent = _Class("OSActivityTraceMessageEvent")
OSActivityCreateEvent = _Class("OSActivityCreateEvent")
OSActivityStream = _Class("OSActivityStream")
OSLogDevice = _Class("OSLogDevice")
OSLogEventBacktrace = _Class("OSLogEventBacktrace")
OSLogEventBacktraceFrame = _Class("OSLogEventBacktraceFrame")
OSLogEventMessageArgument = _Class("OSLogEventMessageArgument")
OSLogDeserializedEventMessageArgument = _Class("OSLogDeserializedEventMessageArgument")
OSLogMessagePlaceholder = _Class("OSLogMessagePlaceholder")
OSLogDeserializedMessagePlaceholder = _Class("OSLogDeserializedMessagePlaceholder")
OSLogEventDecomposedMessage = _Class("OSLogEventDecomposedMessage")
OSLogDeserializedEventDecomposedMessage = _Class(
    "OSLogDeserializedEventDecomposedMessage"
)
OSLogEventProxy = _Class("OSLogEventProxy")
_OSLogDeserializedEventProxy = _Class("_OSLogDeserializedEventProxy")
