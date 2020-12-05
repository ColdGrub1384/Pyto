"""
Classes from the 'HealthKit' framework.
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


HKInspectableValueInRange = _Class("HKInspectableValueInRange")
HKGymKitMetricsDataSource = _Class("HKGymKitMetricsDataSource")
HKMedicalCoding = _Class("HKMedicalCoding")
HKOAuth2TokenSession = _Class("HKOAuth2TokenSession")
HKECGOnboardingVersion = _Class("HKECGOnboardingVersion")
HKSourceRevision = _Class("HKSourceRevision")
HKMobileCountryCode = _Class("HKMobileCountryCode")
HKMobileCountryCodeManager = _Class("HKMobileCountryCodeManager")
HKHealthServicesManager = _Class("HKHealthServicesManager")
HKConceptRelationship = _Class("HKConceptRelationship")
HKBackgroundObservationExtension = _Class("HKBackgroundObservationExtension")
HKHeartRateVariabilityUtilities = _Class("HKHeartRateVariabilityUtilities")
HKBeatToBeatInstantaneousBPM = _Class("HKBeatToBeatInstantaneousBPM")
_HKWorkoutRouteStore = _Class("_HKWorkoutRouteStore")
_HKDaemonPreferences = _Class("_HKDaemonPreferences")
HKCalendarCache = _Class("HKCalendarCache")
HKHeartRateSummaryStatistics = _Class("HKHeartRateSummaryStatistics")
HKHeartRateSummaryBreatheStatistics = _Class("HKHeartRateSummaryBreatheStatistics")
HKHeartRateSummaryWorkoutRecoveryStatistics = _Class(
    "HKHeartRateSummaryWorkoutRecoveryStatistics"
)
HKHeartRateSummaryWorkoutStatistics = _Class("HKHeartRateSummaryWorkoutStatistics")
HKMedicalDateInterval = _Class("HKMedicalDateInterval")
HKSleepQuery = _Class("HKSleepQuery")
HKHeartRateSummary = _Class("HKHeartRateSummary")
HKNanoSyncPairedDeviceInfo = _Class("HKNanoSyncPairedDeviceInfo")
HKNanoSyncPairedDevicesSnapshot = _Class("HKNanoSyncPairedDevicesSnapshot")
_HKEmergencyContactWrapper = _Class("_HKEmergencyContactWrapper")
HKJSONVisitor = _Class("HKJSONVisitor")
_HKSampleQueryUtility = _Class("_HKSampleQueryUtility")
_HKBehavior = _Class("_HKBehavior")
_HKAuthorizationRecord = _Class("_HKAuthorizationRecord")
HKRemoteFeatureAvailabilityRuleSet = _Class("HKRemoteFeatureAvailabilityRuleSet")
HKSleepDay = _Class("HKSleepDay")
HKSleepPeriod = _Class("HKSleepPeriod")
HKSleepPeriodSegment = _Class("HKSleepPeriodSegment")
HKNotificationStore = _Class("HKNotificationStore")
HKDiagnosticStore = _Class("HKDiagnosticStore")
_HKMobileAssetDownloadOperation = _Class("_HKMobileAssetDownloadOperation")
_HKMobileAssetDownloadManager = _Class("_HKMobileAssetDownloadManager")
_HKFirstPartyWorkoutSnapshot = _Class("_HKFirstPartyWorkoutSnapshot")
HKSampleTypeChange = _Class("HKSampleTypeChange")
_HKWorkoutEvent = _Class("_HKWorkoutEvent")
HKOAuth2Credential = _Class("HKOAuth2Credential")
HKWorkoutEvent = _Class("HKWorkoutEvent")
_HKXPCExportedObjectProxy = _Class("_HKXPCExportedObjectProxy")
_HKXPCConnection = _Class("_HKXPCConnection")
HKCoverageClassification = _Class("HKCoverageClassification")
HKTableFormatter = _Class("HKTableFormatter")
HKFHIRVersion = _Class("HKFHIRVersion")
_HKXMLTranslator = _Class("_HKXMLTranslator")
_HKWeakObserversMap = _Class("_HKWeakObserversMap")
HKClinicalProvider = _Class("HKClinicalProvider")
HKProfileStore = _Class("HKProfileStore")
HKClinicalAccountLoginCompletionState = _Class("HKClinicalAccountLoginCompletionState")
HKClinicalAccount = _Class("HKClinicalAccount")
HKConceptSynthesizer = _Class("HKConceptSynthesizer")
_HKLocationShifter = _Class("_HKLocationShifter")
_HKWheelchairUseCharacteristicCache = _Class("_HKWheelchairUseCharacteristicCache")
HKAudioExposureUtilities = _Class("HKAudioExposureUtilities")
HKAudioExposureValue = _Class("HKAudioExposureValue")
_HKXMLExtractorSpecification = _Class("_HKXMLExtractorSpecification")
_HKXMLExtractorElement = _Class("_HKXMLExtractorElement")
_HKXMLExtractor = _Class("_HKXMLExtractor")
HKStatisticsCollection = _Class("HKStatisticsCollection")
HKGPXExporter = _Class("HKGPXExporter")
HKHealthWrapEncryptor = _Class("HKHealthWrapEncryptor")
HKSortedQueryAnchor = _Class("HKSortedQueryAnchor")
_HKExpiringCompletionTimer = _Class("_HKExpiringCompletionTimer")
HKInspectableValueCollection = _Class("HKInspectableValueCollection")
HKAllergyReaction = _Class("HKAllergyReaction")
_HKActivityStatisticsWorkoutInfo = _Class("_HKActivityStatisticsWorkoutInfo")
_HKActivityStatisticsQuantityInfo = _Class("_HKActivityStatisticsQuantityInfo")
_HKActivityStatisticsStandHourInfo = _Class("_HKActivityStatisticsStandHourInfo")
HKProfileIdentifier = _Class("HKProfileIdentifier")
HKPPT = _Class("HKPPT")
HKPPTPluginManager = _Class("HKPPTPluginManager")
HKHeartRhythmAvailability = _Class("HKHeartRhythmAvailability")
HKUnit = _Class("HKUnit")
HKBaseUnit = _Class("HKBaseUnit")
HKDecibelHearingLevelUnit = _Class("HKDecibelHearingLevelUnit")
HKTiterUnit = _Class("HKTiterUnit")
HKPotentiallyNonConvertibleMassUnit = _Class("HKPotentiallyNonConvertibleMassUnit")
HKMoleUnit = _Class("HKMoleUnit")
HKEquivalentsUnit = _Class("HKEquivalentsUnit")
HKNonConvertibleIUUnit = _Class("HKNonConvertibleIUUnit")
HKScalarUnit = _Class("HKScalarUnit")
HKFrequencyUnit = _Class("HKFrequencyUnit")
HKElectricPotentialDifferenceUnit = _Class("HKElectricPotentialDifferenceUnit")
HKConductanceUnit = _Class("HKConductanceUnit")
HKTemperatureUnit = _Class("HKTemperatureUnit")
HKEnergyUnit = _Class("HKEnergyUnit")
HKTimeUnit = _Class("HKTimeUnit")
HKDecibelAWeightedSoundPressureLevelUnit = _Class(
    "HKDecibelAWeightedSoundPressureLevelUnit"
)
HKPressureUnit = _Class("HKPressureUnit")
HKVolumeUnit = _Class("HKVolumeUnit")
HKLengthUnit = _Class("HKLengthUnit")
HKMassUnit = _Class("HKMassUnit")
_HKCompoundUnit = _Class("_HKCompoundUnit")
HKXPCEventObserver = _Class("HKXPCEventObserver")
HKWorkoutRouteDataSource = _Class("HKWorkoutRouteDataSource")
_HKCurrentWorkoutSnapshot = _Class("_HKCurrentWorkoutSnapshot")
HKActivitySummary = _Class("HKActivitySummary")
HKFeatureAvailabilityStore = _Class("HKFeatureAvailabilityStore")
HKCurrentActivityCacheQueryResult = _Class("HKCurrentActivityCacheQueryResult")
_HKFitnessMachine = _Class("_HKFitnessMachine")
_HKActivityStatisticsQueryResult = _Class("_HKActivityStatisticsQueryResult")
HKWatchAppAvailability = _Class("HKWatchAppAvailability")
HKHealthRecordsIngestionOutcome = _Class("HKHealthRecordsIngestionOutcome")
HKRegionAvailabilityMask = _Class("HKRegionAvailabilityMask")
_HKClinicalContact = _Class("_HKClinicalContact")
_HKEmergencyContact = _Class("_HKEmergencyContact")
_HKMedicalIDData = _Class("_HKMedicalIDData")
_HKDateIntervalCollection = _Class("_HKDateIntervalCollection")
HKEADFFileParser = _Class("HKEADFFileParser")
HKFHIRResource = _Class("HKFHIRResource")
HKEntitlementStore = _Class("HKEntitlementStore")
_HKQuantityDistributionData = _Class("_HKQuantityDistributionData")
HKHeartRateSummaryStatisticsBucket = _Class("HKHeartRateSummaryStatisticsBucket")
HKQuantitySeriesSampleEditor = _Class("HKQuantitySeriesSampleEditor")
HKSampleListDataProviderFilter = _Class("HKSampleListDataProviderFilter")
_HKCompressionEngine = _Class("_HKCompressionEngine")
_HKDataCollectorFlushRequest = _Class("_HKDataCollectorFlushRequest")
_HKDataCollectorPendingBatch = _Class("_HKDataCollectorPendingBatch")
HKDataCollectorCollectionConfiguration = _Class(
    "HKDataCollectorCollectionConfiguration"
)
HKDataCollector = _Class("HKDataCollector")
HKAudiogramSensitivityPoint = _Class("HKAudiogramSensitivityPoint")
_HKAudiogramDiagnosticSensitivityPoint = _Class(
    "_HKAudiogramDiagnosticSensitivityPoint"
)
_HKDateCalendarUnitKey = _Class("_HKDateCalendarUnitKey")
HKChartableCodedQuantitySet = _Class("HKChartableCodedQuantitySet")
HKMedicalDate = _Class("HKMedicalDate")
HKQuantityDatum = _Class("HKQuantityDatum")
HKKeyValueDomain = _Class("HKKeyValueDomain")
HKClinicalProviderSearchResultsPage = _Class("HKClinicalProviderSearchResultsPage")
HKDataFlowLink = _Class("HKDataFlowLink")
HKCloudSyncControl = _Class("HKCloudSyncControl")
_HKSampleQueryResult = _Class("_HKSampleQueryResult")
HKStatistics = _Class("HKStatistics")
HKWorkoutSession = _Class("HKWorkoutSession")
HKMultiTypeSampleIterator = _Class("HKMultiTypeSampleIterator")
HKContributor = _Class("HKContributor")
HKLiveWorkoutDataSource = _Class("HKLiveWorkoutDataSource")
_HKDeepBreathingSession = _Class("_HKDeepBreathingSession")
_HKFitnessMachineSessionConfiguration = _Class("_HKFitnessMachineSessionConfiguration")
HKMedicationDosage = _Class("HKMedicationDosage")
HKSampleQueryDescription = _Class("HKSampleQueryDescription")
HKCSVParser = _Class("HKCSVParser")
HKJSONValidator = _Class("HKJSONValidator")
HKRegionAvailabilityMasks = _Class("HKRegionAvailabilityMasks")
HKAvailableRegions = _Class("HKAvailableRegions")
HKHealthRecordsAccountInfoStore = _Class("HKHealthRecordsAccountInfoStore")
_HKFactorization = _Class("_HKFactorization")
_HKMutableFactorization = _Class("_HKMutableFactorization")
HKHealthStoreProvider = _Class("HKHealthStoreProvider")
_HKFitnessMachineConnection = _Class("_HKFitnessMachineConnection")
HKHealthServiceSession = _Class("HKHealthServiceSession")
HKHealthServiceDiscovery = _Class("HKHealthServiceDiscovery")
HKElectrocardiogramSessionConfiguration = _Class(
    "HKElectrocardiogramSessionConfiguration"
)
HKElectrocardiogramSession = _Class("HKElectrocardiogramSession")
HKIndexableObject = _Class("HKIndexableObject")
HKConceptIndexUtilities = _Class("HKConceptIndexUtilities")
HKConceptIndexKeyPath = _Class("HKConceptIndexKeyPath")
HKActiveWatchRemoteFeatureAvailabilityDataSource = _Class(
    "HKActiveWatchRemoteFeatureAvailabilityDataSource"
)
HKSemanticDate = _Class("HKSemanticDate")
_HKQueryUtilities = _Class("_HKQueryUtilities")
HKMedicalIDStore = _Class("HKMedicalIDStore")
HKElectrocardiogramVoltageMeasurement = _Class("HKElectrocardiogramVoltageMeasurement")
HKChartableCodedQuantity = _Class("HKChartableCodedQuantity")
HKRemoteFeatureAvailabilityAlwaysFalseRule = _Class(
    "HKRemoteFeatureAvailabilityAlwaysFalseRule"
)
HKRemoteFeatureAvailabilityAlwaysTrueRule = _Class(
    "HKRemoteFeatureAvailabilityAlwaysTrueRule"
)
HKClinicalBrand = _Class("HKClinicalBrand")
HKDeviceStore = _Class("HKDeviceStore")
HKDateInterval = _Class("HKDateInterval")
HKHealthRecordsIngestionPerAccountOutcome = _Class(
    "HKHealthRecordsIngestionPerAccountOutcome"
)
HKWorkoutConfiguration = _Class("HKWorkoutConfiguration")
HKStateMachine = _Class("HKStateMachine")
HKStateMachineTransition = _Class("HKStateMachineTransition")
HKStateMachineState = _Class("HKStateMachineState")
HKStateMachinePendingEvent = _Class("HKStateMachinePendingEvent")
HKUCUMUnitDisplayConverter = _Class("HKUCUMUnitDisplayConverter")
HKSourceStore = _Class("HKSourceStore")
_HKDimension = _Class("_HKDimension")
_HKCompoundDimension = _Class("_HKCompoundDimension")
_HKBaseDimension = _Class("_HKBaseDimension")
_HKHeartRateRecoveryQueryUtility = _Class("_HKHeartRateRecoveryQueryUtility")
HKNonMPNDeviceRegionFeatureSupportedStateProvider = _Class(
    "HKNonMPNDeviceRegionFeatureSupportedStateProvider"
)
HKStaticSyncControl = _Class("HKStaticSyncControl")
HKQueryAnchor = _Class("HKQueryAnchor")
HKElectrocardiogramBuilder = _Class("HKElectrocardiogramBuilder")
HKMultiTypeQueryCursor = _Class("HKMultiTypeQueryCursor")
HKDatabaseControl = _Class("HKDatabaseControl")
HKWorkoutCondenserControl = _Class("HKWorkoutCondenserControl")
HKHealthRecordsStore = _Class("HKHealthRecordsStore")
HKInspectableValue = _Class("HKInspectableValue")
HKRatioValue = _Class("HKRatioValue")
HKMetadataValidationUtilities = _Class("HKMetadataValidationUtilities")
HKSleepAnalysisUtilities = _Class("HKSleepAnalysisUtilities")
HKClinicalProviderSearchResult = _Class("HKClinicalProviderSearchResult")
HKDateIntervalTree = _Class("HKDateIntervalTree")
HKAuthorizationRequestRecord = _Class("HKAuthorizationRequestRecord")
_HKDelayedOperation = _Class("_HKDelayedOperation")
HKAuthorizationPresentationRequest = _Class("HKAuthorizationPresentationRequest")
HKProductVersions = _Class("HKProductVersions")
HKElectrocardiogramActiveAlgorithmVersion = _Class(
    "HKElectrocardiogramActiveAlgorithmVersion"
)
HKNanoRegistryDeviceUtility = _Class("HKNanoRegistryDeviceUtility")
HKMPNDeviceRegionFeatureSupportedStateProvider = _Class(
    "HKMPNDeviceRegionFeatureSupportedStateProvider"
)
HKReferenceRange = _Class("HKReferenceRange")
HKSource = _Class("HKSource")
HKMedicalRecordsStore = _Class("HKMedicalRecordsStore")
HKHealthWrapMessage = _Class("HKHealthWrapMessage")
HKHealthWrapMessageConfiguration = _Class("HKHealthWrapMessageConfiguration")
HKWorkoutControl = _Class("HKWorkoutControl")
HKQuerySortConstraint = _Class("HKQuerySortConstraint")
_HKCDADocumentExtractedFields = _Class("_HKCDADocumentExtractedFields")
HKCDADocument = _Class("HKCDADocument")
HKCloudSyncObserver = _Class("HKCloudSyncObserver")
HKCloudSyncObserverStatus = _Class("HKCloudSyncObserverStatus")
HKWorkoutDataSource = _Class("HKWorkoutDataSource")
HKDaemonTransaction = _Class("HKDaemonTransaction")
_HKContextFreeGrammar = _Class("_HKContextFreeGrammar")
_HKCFGReplacementRule = _Class("_HKCFGReplacementRule")
_HKCFGExpression = _Class("_HKCFGExpression")
_HKCFGTerminal = _Class("_HKCFGTerminal")
_HKCFGCharacterSequenceTerminal = _Class("_HKCFGCharacterSequenceTerminal")
_HKCFGDoubleTerminal = _Class("_HKCFGDoubleTerminal")
_HKCFGIntegerTerminal = _Class("_HKCFGIntegerTerminal")
_HKCFGCharacterTerminal = _Class("_HKCFGCharacterTerminal")
_HKCFGStringTerminal = _Class("_HKCFGStringTerminal")
_HKCFGNonTerminal = _Class("_HKCFGNonTerminal")
_HKCFGParseContext = _Class("_HKCFGParseContext")
_HKCFGNodeCache = _Class("_HKCFGNodeCache")
_HKCFGNode = _Class("_HKCFGNode")
_HKCFGEmptyStringNode = _Class("_HKCFGEmptyStringNode")
_HKCFGTerminalNode = _Class("_HKCFGTerminalNode")
_HKCFGNonTerminalNode = _Class("_HKCFGNonTerminalNode")
HKCardioFitnessMedicationsUseObject = _Class("HKCardioFitnessMedicationsUseObject")
HKWheelchairUseObject = _Class("HKWheelchairUseObject")
HKFitzpatrickSkinTypeObject = _Class("HKFitzpatrickSkinTypeObject")
HKBiologicalSexObject = _Class("HKBiologicalSexObject")
HKBloodTypeObject = _Class("HKBloodTypeObject")
HKHealthService = _Class("HKHealthService")
HKFHIRIdentifier = _Class("HKFHIRIdentifier")
HKQuantitySeriesSampleBuilder = _Class("HKQuantitySeriesSampleBuilder")
HKPersistentTimer = _Class("HKPersistentTimer")
_HKTimePeriod = _Class("_HKTimePeriod")
HKObjectAuthorizationPromptSession = _Class("HKObjectAuthorizationPromptSession")
HKAuthorizationStore = _Class("HKAuthorizationStore")
HKConceptAttribute = _Class("HKConceptAttribute")
HKTokenKeychainItem = _Class("HKTokenKeychainItem")
HKSleepAnalysis = _Class("HKSleepAnalysis")
HKMedicalCodingCollection = _Class("HKMedicalCodingCollection")
HKDevice = _Class("HKDevice")
HKBadge = _Class("HKBadge")
HKSeriesBuilder = _Class("HKSeriesBuilder")
HKWorkoutRouteBuilder = _Class("HKWorkoutRouteBuilder")
HKHeartbeatSeriesBuilder = _Class("HKHeartbeatSeriesBuilder")
HKCodedValueCollection = _Class("HKCodedValueCollection")
_HKArchiveCreator = _Class("_HKArchiveCreator")
HKHeartRateSummaryReading = _Class("HKHeartRateSummaryReading")
HKOnboardingCompletion = _Class("HKOnboardingCompletion")
HKConceptStore = _Class("HKConceptStore")
_HKEntitlements = _Class("_HKEntitlements")
HKRetryableOperation = _Class("HKRetryableOperation")
HKPendingOperationRecord = _Class("HKPendingOperationRecord")
_HKZipArchiveExtractor = _Class("_HKZipArchiveExtractor")
_HKTaskCompletionCounter = _Class("_HKTaskCompletionCounter")
_HKValidationErrorTracker = _Class("_HKValidationErrorTracker")
_HKXMLValidator = _Class("_HKXMLValidator")
_HKAppURLSpecification = _Class("_HKAppURLSpecification")
HKQuantity = _Class("HKQuantity")
HKGymKitDataSource = _Class("HKGymKitDataSource")
_HKSleepQueryResultBuilder = _Class("_HKSleepQueryResultBuilder")
HKHealthStoreIdentifier = _Class("HKHealthStoreIdentifier")
HKSynchronousObserverSet = _Class("HKSynchronousObserverSet")
HKProxyProvider = _Class("HKProxyProvider")
HKPluginProxyProvider = _Class("HKPluginProxyProvider")
HKTaskServerProxyProvider = _Class("HKTaskServerProxyProvider")
HKQueryServerProxyProvider = _Class("HKQueryServerProxyProvider")
HKConcept = _Class("HKConcept")
HKSortedSampleArray = _Class("HKSortedSampleArray")
_HKSleepQueryResult = _Class("_HKSleepQueryResult")
_HKXPCAuditToken = _Class("_HKXPCAuditToken")
HKObjectType = _Class("HKObjectType")
HKActivitySummaryType = _Class("HKActivitySummaryType")
HKCharacteristicType = _Class("HKCharacteristicType")
HKSampleType = _Class("HKSampleType")
HKClinicalType = _Class("HKClinicalType")
HKHeartbeatSequenceSampleType = _Class("HKHeartbeatSequenceSampleType")
HKElectrocardiogramType = _Class("HKElectrocardiogramType")
HKAudiogramSampleType = _Class("HKAudiogramSampleType")
HKSeriesType = _Class("HKSeriesType")
HKWorkoutType = _Class("HKWorkoutType")
HKDocumentType = _Class("HKDocumentType")
HKCorrelationType = _Class("HKCorrelationType")
HKCategoryType = _Class("HKCategoryType")
HKQuantityType = _Class("HKQuantityType")
HKMedicalType = _Class("HKMedicalType")
HKMedicationRecordType = _Class("HKMedicationRecordType")
HKVaccinationRecordType = _Class("HKVaccinationRecordType")
HKCoverageRecordType = _Class("HKCoverageRecordType")
HKDiagnosticTestReportType = _Class("HKDiagnosticTestReportType")
HKMedicationDispenseRecordType = _Class("HKMedicationDispenseRecordType")
HKConditionRecordType = _Class("HKConditionRecordType")
HKDiagnosticTestResultType = _Class("HKDiagnosticTestResultType")
HKProcedureRecordType = _Class("HKProcedureRecordType")
HKAccountOwnerType = _Class("HKAccountOwnerType")
HKAllergyRecordType = _Class("HKAllergyRecordType")
HKMedicationOrderType = _Class("HKMedicationOrderType")
HKUnknownRecordType = _Class("HKUnknownRecordType")
_HKFitnessMachineConnectionInitiator = _Class("_HKFitnessMachineConnectionInitiator")
HKHealthStore = _Class("HKHealthStore")
_HKWorkoutObserver = _Class("_HKWorkoutObserver")
HKNanoSyncControl = _Class("HKNanoSyncControl")
HKQuery = _Class("HKQuery")
HKDocumentQuery = _Class("HKDocumentQuery")
HKDeviceQuery = _Class("HKDeviceQuery")
HKSampleCountQuery = _Class("HKSampleCountQuery")
_HKDatabaseChangesQuery = _Class("_HKDatabaseChangesQuery")
HKCorrelationQuery = _Class("HKCorrelationQuery")
HKMultiTypeSampleQuery = _Class("HKMultiTypeSampleQuery")
HKStatisticsCollectionQuery = _Class("HKStatisticsCollectionQuery")
HKSourceQuery = _Class("HKSourceQuery")
_HKQuantityDistributionQuery = _Class("_HKQuantityDistributionQuery")
_HKCurrentActivitySummaryQuery = _Class("_HKCurrentActivitySummaryQuery")
_HKActivityStatisticsQuery = _Class("_HKActivityStatisticsQuery")
HKElectrocardiogramQuery = _Class("HKElectrocardiogramQuery")
HKWorkoutBuilderSampleQuery = _Class("HKWorkoutBuilderSampleQuery")
HKActivitySummaryQuery = _Class("HKActivitySummaryQuery")
HKAnchoredObjectQuery = _Class("HKAnchoredObjectQuery")
HKQuantitySeriesSampleQuery = _Class("HKQuantitySeriesSampleQuery")
_HKSampleTypeQuery = _Class("_HKSampleTypeQuery")
HKWorkoutRouteQuery = _Class("HKWorkoutRouteQuery")
HKStatisticsQuery = _Class("HKStatisticsQuery")
HKObserverQuery = _Class("HKObserverQuery")
_HKDateRangeQuery = _Class("_HKDateRangeQuery")
HKSampleQuery = _Class("HKSampleQuery")
HKHeartbeatSeriesQuery = _Class("HKHeartbeatSeriesQuery")
HKCurrentActivityCacheQuery = _Class("HKCurrentActivityCacheQuery")
HKHeartRateSummaryQuery = _Class("HKHeartRateSummaryQuery")
HKCodedQuantity = _Class("HKCodedQuantity")
HKMedicalCodingSystem = _Class("HKMedicalCodingSystem")
HKHealthStoreConfiguration = _Class("HKHealthStoreConfiguration")
HKPluginLoader = _Class("HKPluginLoader")
_HKObserverRecord = _Class("_HKObserverRecord")
HKObserverSet = _Class("HKObserverSet")
_HKFilter = _Class("_HKFilter")
_HKCompoundFilter = _Class("_HKCompoundFilter")
_HKBooleanFilter = _Class("_HKBooleanFilter")
_HKComparisonFilter = _Class("_HKComparisonFilter")
_HKObjectComparisonFilter = _Class("_HKObjectComparisonFilter")
_HKWorkoutComparisonFilter = _Class("_HKWorkoutComparisonFilter")
_HKDiagnosticTestResultComparisonFilter = _Class(
    "_HKDiagnosticTestResultComparisonFilter"
)
_HKConceptIndexableComparisonFilter = _Class("_HKConceptIndexableComparisonFilter")
_HKQuantitySampleComparisonFilter = _Class("_HKQuantitySampleComparisonFilter")
_HKActivitySummaryComparisonFilter = _Class("_HKActivitySummaryComparisonFilter")
_HKCDADocumentSampleComparisonFilter = _Class("_HKCDADocumentSampleComparisonFilter")
_HKSampleComparisonFilter = _Class("_HKSampleComparisonFilter")
_HKCategorySampleComparisonFilter = _Class("_HKCategorySampleComparisonFilter")
_HKActivityCacheComparisonFilter = _Class("_HKActivityCacheComparisonFilter")
_HKElectrocardiogramComparisonFilter = _Class("_HKElectrocardiogramComparisonFilter")
_HKDiscreteQuantitySampleComparisonFilter = _Class(
    "_HKDiscreteQuantitySampleComparisonFilter"
)
_HKMedicalRecordComparisonFilter = _Class("_HKMedicalRecordComparisonFilter")
_HKClinicalRecordComparisonFilter = _Class("_HKClinicalRecordComparisonFilter")
HKDeletedObject = _Class("HKDeletedObject")
HKRemoteFeatureAvailabilityBaseRule = _Class("HKRemoteFeatureAvailabilityBaseRule")
HKRemoteFeatureAvailabilityActiveWatchAtrialFibrillationDetectionVersionEqualsRule = _Class(
    "HKRemoteFeatureAvailabilityActiveWatchAtrialFibrillationDetectionVersionEqualsRule"
)
HKRemoteFeatureAvailabilityActiveWatchElectrocardiogramVersionLessThanRule = _Class(
    "HKRemoteFeatureAvailabilityActiveWatchElectrocardiogramVersionLessThanRule"
)
HKRemoteFeatureAvailabilityWatchOSVersionLessThanRule = _Class(
    "HKRemoteFeatureAvailabilityWatchOSVersionLessThanRule"
)
HKRemoteFeatureAvailabilityActiveWatchElectrocardiogramVersionEqualsRule = _Class(
    "HKRemoteFeatureAvailabilityActiveWatchElectrocardiogramVersionEqualsRule"
)
HKRemoteFeatureAvailabilityWatchBuildTypeEqualsRule = _Class(
    "HKRemoteFeatureAvailabilityWatchBuildTypeEqualsRule"
)
HKRemoteFeatureAvailabilityWatchCompanionDevicePlatformEqualsRule = _Class(
    "HKRemoteFeatureAvailabilityWatchCompanionDevicePlatformEqualsRule"
)
HKRemoteFeatureAvailabilityWatchOSBuildVersionLessThanRule = _Class(
    "HKRemoteFeatureAvailabilityWatchOSBuildVersionLessThanRule"
)
HKRemoteFeatureAvailabilityWatchModelNumberHasPrefixRule = _Class(
    "HKRemoteFeatureAvailabilityWatchModelNumberHasPrefixRule"
)
HKRemoteFeatureAvailabilityWatchOSBuildVersionGreaterThanRule = _Class(
    "HKRemoteFeatureAvailabilityWatchOSBuildVersionGreaterThanRule"
)
HKRemoteFeatureAvailabilityActiveWatchAtrialFibrillationDetectionVersionLessThanRule = _Class(
    "HKRemoteFeatureAvailabilityActiveWatchAtrialFibrillationDetectionVersionLessThanRule"
)
HKRemoteFeatureAvailabilityAtrialFibrillationOnboardingCountryCodeRule = _Class(
    "HKRemoteFeatureAvailabilityAtrialFibrillationOnboardingCountryCodeRule"
)
HKRemoteFeatureAvailabilityWatchOSVersionEqualsRule = _Class(
    "HKRemoteFeatureAvailabilityWatchOSVersionEqualsRule"
)
HKRemoteFeatureAvailabilityWatchRegionEqualsRule = _Class(
    "HKRemoteFeatureAvailabilityWatchRegionEqualsRule"
)
HKRemoteFeatureAvailabilityActiveWatchAtrialFibrillationDetectionVersionGreaterThanRule = _Class(
    "HKRemoteFeatureAvailabilityActiveWatchAtrialFibrillationDetectionVersionGreaterThanRule"
)
HKRemoteFeatureAvailabilityCompoundRule = _Class(
    "HKRemoteFeatureAvailabilityCompoundRule"
)
HKRemoteFeatureAvailabilityWatchOSVersionGreaterThanRule = _Class(
    "HKRemoteFeatureAvailabilityWatchOSVersionGreaterThanRule"
)
HKRemoteFeatureAvailabilityElectrocardiogramOnboardingCountryCodeRule = _Class(
    "HKRemoteFeatureAvailabilityElectrocardiogramOnboardingCountryCodeRule"
)
HKRemoteFeatureAvailabilityWatchOSBuildVersionEqualsRule = _Class(
    "HKRemoteFeatureAvailabilityWatchOSBuildVersionEqualsRule"
)
HKRemoteFeatureAvailabilityActiveWatchElectrocardiogramVersionGreaterThanRule = _Class(
    "HKRemoteFeatureAvailabilityActiveWatchElectrocardiogramVersionGreaterThanRule"
)
HKRemoteFeatureAvailabilityWatchProductTypeHasPrefixRule = _Class(
    "HKRemoteFeatureAvailabilityWatchProductTypeHasPrefixRule"
)
HKObject = _Class("HKObject")
HKSample = _Class("HKSample")
HKElectrocardiogram = _Class("HKElectrocardiogram")
HKCategorySample = _Class("HKCategorySample")
HKWorkout = _Class("HKWorkout")
_HKFitnessFriendWorkout = _Class("_HKFitnessFriendWorkout")
HKCorrelation = _Class("HKCorrelation")
_HKCorrelationPlaceholder = _Class("_HKCorrelationPlaceholder")
_HKFitnessFriendAchievement = _Class("_HKFitnessFriendAchievement")
HKActivityCache = _Class("HKActivityCache")
HKAudiogramSample = _Class("HKAudiogramSample")
_HKFitnessFriendActivitySnapshot = _Class("_HKFitnessFriendActivitySnapshot")
HKDocumentSample = _Class("HKDocumentSample")
HKCDADocumentSample = _Class("HKCDADocumentSample")
HKClinicalRecord = _Class("HKClinicalRecord")
HKSleepSchedule = _Class("HKSleepSchedule")
HKQuantitySample = _Class("HKQuantitySample")
HKDiscreteQuantitySample = _Class("HKDiscreteQuantitySample")
HKCumulativeQuantitySample = _Class("HKCumulativeQuantitySample")
HKCumulativeQuantitySeriesSample = _Class("HKCumulativeQuantitySeriesSample")
HKSeriesSample = _Class("HKSeriesSample")
HKHeartbeatSeriesSample = _Class("HKHeartbeatSeriesSample")
HKHeartbeatSequenceSample = _Class("HKHeartbeatSequenceSample")
HKWorkoutRoute = _Class("HKWorkoutRoute")
HKMedicalRecord = _Class("HKMedicalRecord")
HKVaccinationRecord = _Class("HKVaccinationRecord")
HKAllergyRecord = _Class("HKAllergyRecord")
HKUnknownRecord = _Class("HKUnknownRecord")
HKProcedureRecord = _Class("HKProcedureRecord")
HKConditionRecord = _Class("HKConditionRecord")
HKMedicationRecord = _Class("HKMedicationRecord")
HKCoverageRecord = _Class("HKCoverageRecord")
HKDiagnosticTestReport = _Class("HKDiagnosticTestReport")
HKDiagnosticTestResult = _Class("HKDiagnosticTestResult")
HKAccountOwner = _Class("HKAccountOwner")
HKMedicationOrder = _Class("HKMedicationOrder")
HKMedicationDispenseRecord = _Class("HKMedicationDispenseRecord")
HKClinicalGateway = _Class("HKClinicalGateway")
HKCodedValue = _Class("HKCodedValue")
HKFeatureAvailabilityDatabaseInaccessibilityCache = _Class(
    "HKFeatureAvailabilityDatabaseInaccessibilityCache"
)
HKWorkoutBuilder = _Class("HKWorkoutBuilder")
HKLiveWorkoutBuilder = _Class("HKLiveWorkoutBuilder")
HKTaskConfiguration = _Class("HKTaskConfiguration")
HKQuantitySeriesSampleEditorTaskServerConfiguration = _Class(
    "HKQuantitySeriesSampleEditorTaskServerConfiguration"
)
HKDataCollectorTaskServerConfiguration = _Class(
    "HKDataCollectorTaskServerConfiguration"
)
HKSeriesBuilderConfiguration = _Class("HKSeriesBuilderConfiguration")
HKKeyValueDomainServerConfiguration = _Class("HKKeyValueDomainServerConfiguration")
HKWorkoutSessionTaskConfiguration = _Class("HKWorkoutSessionTaskConfiguration")
HKFeatureAvailabilityStoreServerConfiguration = _Class(
    "HKFeatureAvailabilityStoreServerConfiguration"
)
HKElectrocardiogramSessionTaskConfiguration = _Class(
    "HKElectrocardiogramSessionTaskConfiguration"
)
HKWorkoutDataSourceConfiguration = _Class("HKWorkoutDataSourceConfiguration")
HKQuantitySeriesSampleBuilderTaskServerConfiguration = _Class(
    "HKQuantitySeriesSampleBuilderTaskServerConfiguration"
)
HKConceptStoreServerConfiguration = _Class("HKConceptStoreServerConfiguration")
HKQueryServerConfiguration = _Class("HKQueryServerConfiguration")
_HKDocumentQueryServerConfiguration = _Class("_HKDocumentQueryServerConfiguration")
_HKSampleCountQueryServerConfiguration = _Class(
    "_HKSampleCountQueryServerConfiguration"
)
_HKDatabaseChangesQueryServerConfiguration = _Class(
    "_HKDatabaseChangesQueryServerConfiguration"
)
_HKCorrelationQueryServerConfiguration = _Class(
    "_HKCorrelationQueryServerConfiguration"
)
_HKMultiTypeSampleQueryServerConfiguration = _Class(
    "_HKMultiTypeSampleQueryServerConfiguration"
)
_HKStatisticsCollectionQueryServerConfiguration = _Class(
    "_HKStatisticsCollectionQueryServerConfiguration"
)
_HKQuantityDistributionQueryServerConfiguration = _Class(
    "_HKQuantityDistributionQueryServerConfiguration"
)
_HKCurrentActivitySummaryQueryServerConfiguration = _Class(
    "_HKCurrentActivitySummaryQueryServerConfiguration"
)
_HKActivityStatisticsQueryServerConfiguration = _Class(
    "_HKActivityStatisticsQueryServerConfiguration"
)
_HKWorkoutBuilderSampleQueryConfiguration = _Class(
    "_HKWorkoutBuilderSampleQueryConfiguration"
)
HKActivitySummaryQueryServerConfiguration = _Class(
    "HKActivitySummaryQueryServerConfiguration"
)
_HKAnchoredObjectQueryServerConfiguration = _Class(
    "_HKAnchoredObjectQueryServerConfiguration"
)
_HKQuantitySeriesSampleQueryServerConfiguration = _Class(
    "_HKQuantitySeriesSampleQueryServerConfiguration"
)
_HKWorkoutRouteQueryServerConfiguration = _Class(
    "_HKWorkoutRouteQueryServerConfiguration"
)
_HKStatisticsQueryServerConfiguration = _Class("_HKStatisticsQueryServerConfiguration")
_HKObserverQueryServerConfiguration = _Class("_HKObserverQueryServerConfiguration")
_HKSampleQueryConfiguration = _Class("_HKSampleQueryConfiguration")
HKCurrentActivityCacheQueryServerConfiguration = _Class(
    "HKCurrentActivityCacheQueryServerConfiguration"
)
HKWorkoutBuilderConfiguration = _Class("HKWorkoutBuilderConfiguration")
_HKDeepBreathingSessionConfiguration = _Class("_HKDeepBreathingSessionConfiguration")
HKConceptIdentifier = _Class("HKConceptIdentifier")
HKHealthWrapCodableValue = _Class("HKHealthWrapCodableValue")
HKHealthWrapCodableKeyValue = _Class("HKHealthWrapCodableKeyValue")
HKCodableCondensedWorkout = _Class("HKCodableCondensedWorkout")
HKHealthWrapCodablePayloadHeader = _Class("HKHealthWrapCodablePayloadHeader")
HKCodableQuantitySeriesEnumerationResult = _Class(
    "HKCodableQuantitySeriesEnumerationResult"
)
HKCodableQuantitySeriesDatum = _Class("HKCodableQuantitySeriesDatum")
HKHealthWrapCodableMessageHeader = _Class("HKHealthWrapCodableMessageHeader")
HKHealthWrapCodableMessageKey = _Class("HKHealthWrapCodableMessageKey")
HKCodableQuantitySeriesEnumerationResultCollection = _Class(
    "HKCodableQuantitySeriesEnumerationResultCollection"
)
HKCodableQuantitySeries = _Class("HKCodableQuantitySeries")
HKCodableCondensedWorkoutCollection = _Class("HKCodableCondensedWorkoutCollection")
_HKBackgroundObservationExtensionContext = _Class(
    "_HKBackgroundObservationExtensionContext"
)
_HKBackgroundObservationExtensionHostContext = _Class(
    "_HKBackgroundObservationExtensionHostContext"
)
_HKBackgroundObservationExtensionRemoteContext = _Class(
    "_HKBackgroundObservationExtensionRemoteContext"
)
