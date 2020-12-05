"""
Classes from the 'ProactiveEventTracker' framework.
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


PETStringPairs = _Class("PETStringPairs")
PETEventTracker2 = _Class("PETEventTracker2")
PETReservoirSamplingLog = _Class("PETReservoirSamplingLog")
PETReservoirSamplingLogStoreFile = _Class("PETReservoirSamplingLogStoreFile")
PETReservoirSamplingLogStoreInMemory = _Class("PETReservoirSamplingLogStoreInMemory")
PETLoggingUtils = _Class("PETLoggingUtils")
PETAggregateState = _Class("PETAggregateState")
PETConfig = _Class("PETConfig")
PETAggregateStateStorage = _Class("PETAggregateStateStorage")
PETAggregateStateStorageOnDisk = _Class("PETAggregateStateStorageOnDisk")
PETAggregateStateStorageInMemory = _Class("PETAggregateStateStorageInMemory")
PETEventStringValidator = _Class("PETEventStringValidator")
PETTestLoggingOutlet = _Class("PETTestLoggingOutlet")
PETEventProperty = _Class("PETEventProperty")
PETEventFreeValuedProperty = _Class("PETEventFreeValuedProperty")
PETEventStringValuedProperty = _Class("PETEventStringValuedProperty")
PETEventEnumMappedProperty = _Class("PETEventEnumMappedProperty")
PETEventNumericalProperty = _Class("PETEventNumericalProperty")
PETProtobufRawDecoder = _Class("PETProtobufRawDecoder")
PETConfigValidator = _Class("PETConfigValidator")
PETEventTracker = _Class("PETEventTracker")
PETScalarEventTracker = _Class("PETScalarEventTracker")
PETDistributionEventTracker = _Class("PETDistributionEventTracker")
PETGoalConversionEventTracker = _Class("PETGoalConversionEventTracker")
PET2LoggingOutlet = _Class("PET2LoggingOutlet")
PETAggdLoggingOutlet = _Class("PETAggdLoggingOutlet")
PETRawMessage = _Class("PETRawMessage")
PETAggregatedMessage = _Class("PETAggregatedMessage")
PETMetadata = _Class("PETMetadata")
PETUpload = _Class("PETUpload")
PET1Key = _Class("PET1Key")
PETAggregationKey = _Class("PETAggregationKey")
PETProtobufRawDecodedMessage = _Class("PETProtobufRawDecodedMessage")
PETDistribution = _Class("PETDistribution")
