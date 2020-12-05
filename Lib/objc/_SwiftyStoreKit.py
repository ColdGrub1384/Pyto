"""
Classes from the 'SwiftyStoreKit' framework.
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


InAppReceipt = _Class("SwiftyStoreKit.InAppReceipt")
CompleteTransactionsController = _Class("SwiftyStoreKit.CompleteTransactionsController")
RestorePurchasesController = _Class("SwiftyStoreKit.RestorePurchasesController")
PaymentsController = _Class("SwiftyStoreKit.PaymentsController")
InAppProductQueryRequestBuilder = _Class(
    "SwiftyStoreKit.InAppProductQueryRequestBuilder"
)
SwiftyStoreKit = _Class("SwiftyStoreKit.SwiftyStoreKit")
InAppReceiptRefreshRequest = _Class("SwiftyStoreKit.InAppReceiptRefreshRequest")
PodsDummy_SwiftyStoreKit = _Class("PodsDummy_SwiftyStoreKit")
InAppProductQueryRequest = _Class("SwiftyStoreKit.InAppProductQueryRequest")
InAppReceiptVerificator = _Class("SwiftyStoreKit.InAppReceiptVerificator")
PaymentQueueController = _Class("SwiftyStoreKit.PaymentQueueController")
ProductsInfoController = _Class("SwiftyStoreKit.ProductsInfoController")
