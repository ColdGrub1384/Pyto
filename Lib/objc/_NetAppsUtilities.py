"""
Classes from the 'NetAppsUtilities' framework.
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


NAIdentityBuilder = _Class("NAIdentityBuilder")
NAIdentity = _Class("NAIdentity")
NAIdentityCharacteristic = _Class("NAIdentityCharacteristic")
NADescriptionBuilder = _Class("NADescriptionBuilder")
NAItemDiffOperation = _Class("NAItemDiffOperation")
NAGroupDiffOperation = _Class("NAGroupDiffOperation")
NAGroupedItemDiff = _Class("NAGroupedItemDiff")
NASimpleDiffableItemGroup = _Class("NASimpleDiffableItemGroup")
_NAObserverProxy = _Class("_NAObserverProxy")
_NAKeyValueObserverProxy = _Class("_NAKeyValueObserverProxy")
_NANotificationObserverProxy = _Class("_NANotificationObserverProxy")
_NAOperationQueueScheduler = _Class("_NAOperationQueueScheduler")
_NAImmediateScheduler = _Class("_NAImmediateScheduler")
_NABoundedQueueingStrategy = _Class("_NABoundedQueueingStrategy")
_NAPriorityQueueingStrategy = _Class("_NAPriorityQueueingStrategy")
_NADefaultQueueingStrategy = _Class("_NADefaultQueueingStrategy")
NAQueue = _Class("NAQueue")
NADelegateMethodLogSettings = _Class("NADelegateMethodLogSettings")
NADelegateDispatcher = _Class("NADelegateDispatcher")
_NADelegateMethodMetadata = _Class("_NADelegateMethodMetadata")
_NAQueueScheduler = _Class("_NAQueueScheduler")
NAPromise = _Class("NAPromise")
NACancelationToken = _Class("NACancelationToken")
NADecayingTimer = _Class("NADecayingTimer")
_NAMainThreadScheduler = _Class("_NAMainThreadScheduler")
NAScheduler = _Class("NAScheduler")
NAValueThrottler = _Class("NAValueThrottler")
NAUniqueArrayDiff = _Class("NAUniqueArrayDiff")
_NASetContainer = _Class("_NASetContainer")
NAUniqueArrayDiffOptions = _Class("NAUniqueArrayDiffOptions")
NADeallocationSentinel = _Class("NADeallocationSentinel")
NADeallocationTracer = _Class("NADeallocationTracer")
NAFuture = _Class("NAFuture")
_NALazyFuture = _Class("_NALazyFuture")
NATreeNode = _Class("NATreeNode")
NAMutableTreeNode = _Class("NAMutableTreeNode")
NAPair = _Class("NAPair")
NAFlatMapEnumerator = _Class("NAFlatMapEnumerator")
NAFilterEnumerator = _Class("NAFilterEnumerator")
NATreeNodeDeepNodeEnumerator = _Class("NATreeNodeDeepNodeEnumerator")
