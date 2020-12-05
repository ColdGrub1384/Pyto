"""
Classes from the 'BiomePubSub' framework.
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


BPSFutureResult = _Class("BPSFutureResult")
_BPSScanInner = _Class("_BPSScanInner")
BPSSubscriberList = _Class("BPSSubscriberList")
BPSSubscriptionStatus = _Class("BPSSubscriptionStatus")
BPSAggregations = _Class("BPSAggregations")
BPSAggregator = _Class("BPSAggregator")
_BPSAbstractZipSide = _Class("_BPSAbstractZipSide")
_BPSMapInner = _Class("_BPSMapInner")
BPSDrivableSink = _Class("BPSDrivableSink")
BPSSink = _Class("BPSSink")
_CMLastInnser = _Class("_CMLastInnser")
_BPSAbstractCombineLatestSide = _Class("_BPSAbstractCombineLatestSide")
BPSPartialCompletion = _Class("BPSPartialCompletion")
_BPSFlatMapSide = _Class("_BPSFlatMapSide")
BPSCompletion = _Class("BPSCompletion")
_BPSAbstractOrderedMergeSide = _Class("_BPSAbstractOrderedMergeSide")
_BPSMergedSide = _Class("_BPSMergedSide")
BPSTuple = _Class("BPSTuple")
BPSPublisher = _Class("BPSPublisher")
BPSFuture = _Class("BPSFuture")
BPSCollect = _Class("BPSCollect")
BPSScan = _Class("BPSScan")
BPSPassThroughSubject = _Class("BPSPassThroughSubject")
BPSZipMany = _Class("BPSZipMany")
BPSZip = _Class("BPSZip")
BPSMap = _Class("BPSMap")
BPSReduce = _Class("BPSReduce")
BPSLast = _Class("BPSLast")
BPSCombineLatest = _Class("BPSCombineLatest")
BPSFlatMap = _Class("BPSFlatMap")
BPSOrderedMerge = _Class("BPSOrderedMerge")
BPSFilter = _Class("BPSFilter")
BPSMergeMany = _Class("BPSMergeMany")
BPSMerge = _Class("BPSMerge")
BPSSequence = _Class("BPSSequence")
BPSRemoveDuplicates = _Class("BPSRemoveDuplicates")
BPSSubscription = _Class("BPSSubscription")
BPSEmpty = _Class("BPSEmpty")
_BPSInnerFutureConduit = _Class("_BPSInnerFutureConduit")
_BPSInnerConduit = _Class("_BPSInnerConduit")
_BPSAbstractZip = _Class("_BPSAbstractZip")
_BPSZipManyInner = _Class("_BPSZipManyInner")
_BPSZip2Inner = _Class("_BPSZip2Inner")
BPSReduceProducer = _Class("BPSReduceProducer")
_BPSCollectInner = _Class("_BPSCollectInner")
_BPSReduceInner = _Class("_BPSReduceInner")
_BPSAbstractCombineLatest = _Class("_BPSAbstractCombineLatest")
_BPSCombineLatest2Inner = _Class("_BPSCombineLatest2Inner")
_BPSFlatMapOuter = _Class("_BPSFlatMapOuter")
_BPSAbstractOrderedMerge = _Class("_BPSAbstractOrderedMerge")
_BPSOrderedMergeManyInner = _Class("_BPSOrderedMergeManyInner")
_BPSMerged = _Class("_BPSMerged")
_BPSSequenceInner = _Class("_BPSSequenceInner")
BPSFilterProducer = _Class("BPSFilterProducer")
_BPSFilterInner = _Class("_BPSFilterInner")
_BPSRemoveDuplicatesInner = _Class("_BPSRemoveDuplicatesInner")
