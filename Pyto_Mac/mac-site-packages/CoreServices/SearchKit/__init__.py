'''
Python mapping for the SearchKit framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import objc, sys

import CoreFoundation
from CoreServices.SearchKit import _metadata

mod = objc.ObjCLazyModule(
    "SearchKit", "com.apple.SearchKit",
    objc.pathForFramework(
        "/System/Library/Frameworks/CoreServices.framework/Frameworks/SearchKit.framework"),
    _metadata.__dict__, None, {
        '__doc__': __doc__,
        'objc': objc,
        '__path__': __path__,
        '__loader__': globals().get('__loader__', None),
    }, (CoreFoundation,))

import sys
del sys.modules['CoreServices.SearchKit._metadata']



# SKIndexGetTypeID is documented, but not actually exported by Leopard. Try to
# emulate the missing functionality.
#
# See also radar:6525606.
#
# UPDATE 20151123: The workaround is still necessary on OSX 10.11
def workaround():
    from Foundation import NSMutableData, NSAutoreleasePool

    pool = NSAutoreleasePool.alloc().init()
    try:
        rI = mod.SKIndexCreateWithMutableData(NSMutableData.data(),
                None, mod.kSKIndexInverted, None)

        indexID = mod.CFGetTypeID(rI)

        r = mod.SKIndexDocumentIteratorCreate(rI, None)
        iterID = mod.CFGetTypeID(r)
        del r

        r = mod.SKSearchGroupCreate([rI])
        groupID = mod.CFGetTypeID(r)

        r = mod.SKSearchResultsCreateWithQuery(r, ".*", mod.kSKSearchRanked, 1, None, None)
        resultID = mod.CFGetTypeID(r)

        if mod.SKSearchGetTypeID() == 0:
            # Type doesn't get registered unless you try to use it.
            # That's no good for PyObjC, therefore forcefully create
            # a SKSearch object
            mod.SKSearchCreate(rI, "q", 0)
            searchref = objc.registerCFSignature(
                    "SKSearchRef", b"^{__SKSearch=}", mod.SKSearchGetTypeID())
        else:
            searchref = mod.SKSearchRef

        del r
        del rI

        r = mod.SKSummaryCreateWithString("foo")
        summaryID = mod.CFGetTypeID(r)
        del r

    finally:
        del pool

    def SKIndexGetTypeID():
        return indexID

    def SKIndexDocumentIteratorGetTypeID():
        return iterID

    def SKSearchGroupGetTypeID():
        return groupID

    def SKSearchResultsGetTypeID():
        return resultID

    def SKSummaryGetTypeID():
        return summaryID

    indexType = objc.registerCFSignature(
            "SKIndexRef", b"^{__SKIndex=}", indexID)
    iterType = objc.registerCFSignature(
            "SKIndexDocumentIteratorRef", b"^{__SKIndexDocumentIterator=}", iterID)
    groupType = objc.registerCFSignature(
            "SKSearchGroupRef", b"^{__SKSearchGroup=}", groupID)
    resultType = objc.registerCFSignature(
            "SKSearchResultsRef", b"^{__SKSearchResults=}", resultID)
    summaryType = objc.registerCFSignature(
            "SKSummaryRef", b"^{__SKSummary=}", summaryID)


    # For some reason SKDocumentGetTypeID doesn't return the right value
    # when the framework loader calls it the first time around,
    # by this time the framework is fully initialized and we get
    # the correct result.
    SKDocumentRef = objc.registerCFSignature(
            "SKDocumentRef", b"@", mod.SKDocumentGetTypeID())


    return (SKIndexGetTypeID, indexType, SKIndexDocumentIteratorGetTypeID, iterType,
            SKSearchGroupGetTypeID, groupType, SKSearchResultsGetTypeID, resultType,
            SKSummaryGetTypeID, summaryType, iterType,
            SKDocumentRef, searchref)

(mod.SKIndexGetTypeID, mod.SKIndexRef,
    mod.SKIndexDocumentIteratorGetTypeID, mod.SKIndexDocumentRef,
    mod.SKSearchGroupGetTypeID, mod.SKSearchGroupRef,
    mod.SKSearchResultsGetTypeID, mod.SKSearchResultsRef,
    mod.SKSummaryGetTypeID, mod.SKSummaryRef,
    mod.SKIndexDocumentIteratorRef,
    mod.SKDocumentRef, mod.SKSearchRef,
) = workaround()

del workaround

sys.modules['CoreServices.SearchKit']  = mod
