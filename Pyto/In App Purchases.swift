//
//  In App Purchases.swift
//  Pyto
//
//  Created by Adrian Labbé on 04-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import SwiftyStoreKit
import SwiftUI
import SwiftUI_Views
import ObjectUserDefaults
import StoreKit
import TrueTime

fileprivate let fullVersionProductID = "ch.ada.Pyto.fullversion"

fileprivate let liteVersionProductID = "ch.ada.Pyto.liteversion"

fileprivate let freeTrialProductID = "ch.ada.Pyto.freetrial"

let isPurchased = ObjectUserDefaults.standard.item(forKey: "isPurchased")

let isLiteVersion = ObjectUserDefaults.standard.item(forKey: "isLiteVersion")

var isUnlocked = false

func completePurchase(id: String) {
    
    func unlock() {
        isUnlocked = true
        
        if #available(iOS 13.0, *) {
            for scene in UIApplication.shared.connectedScenes {
                guard let window = (scene as? UIWindowScene)?.windows.first else {
                    continue
                }
                
                let vc = window.topViewController
                
                if vc is UIHostingController<OnboardingView> {
                    vc?.dismiss(animated: true, completion: nil)
                }
            }
        }
    }
    
    switch id {
    case fullVersionProductID:
        isPurchased.boolValue = true
        isLiteVersion.boolValue = false
        unlock()
    case liteVersionProductID:
        isPurchased.boolValue = true
        isLiteVersion.boolValue = true
        unlock()
    case freeTrialProductID:
        guard let validator = ReceiptValidator() else {
            return
        }
        
        guard let date = validator.trialExpirationDate else {
            return
        }
        
        TrueTimeClient.sharedInstance.fetchIfNeeded(success: { (time) in
            let calendar = Calendar.current

            let date1 = calendar.startOfDay(for: date)
            let date2 = calendar.startOfDay(for: time.now())

            let components = calendar.dateComponents([.day], from: date1, to: date2)
            
            guard let days = components.day else {
                return
            }
            
            if days <= 3 { // Free trial
                unlock()
            }
        }) { (error) in
            print(error.localizedDescription)
        }
    default:
        break
    }
}

@available(iOS 13.0.0, *)
func showOnboarding(window: UIWindow?, isTrialExpired: Bool = false) {
    SwiftyStoreKit.retrieveProductsInfo(Set([fullVersionProductID, liteVersionProductID])) { (results) in
        var fullPrice = "9.99$"
        var litePrice = "3.99$"
        
        for result in results.retrievedProducts {
            if result.productIdentifier == fullVersionProductID {
                fullPrice = result.localizedPrice ?? fullPrice
            } else if result.productIdentifier == liteVersionProductID {
                litePrice = result.localizedPrice ?? litePrice
            }
        }
        
        func purchase(id: String) {
            if id != "" {
                UIApplication.shared.isNetworkActivityIndicatorVisible = true
                SwiftyStoreKit.purchaseProduct(id) { (result) in
                    UIApplication.shared.isNetworkActivityIndicatorVisible = false
                    switch result {
                    case .error(error: let error):
                        if error.code != .paymentCancelled {
                            let alert = UIAlertController(title: Localizable.error, message: error.localizedDescription, preferredStyle: .alert)
                            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
                            window?.topViewController?.present(alert, animated: true, completion: nil)
                        }
                    case .success(purchase: let details):
                        if details.needsFinishTransaction {
                            SwiftyStoreKit.finishTransaction(details.transaction)
                        }
                                                
                        completePurchase(id: details.productId)
                    }
                }
            } else {
                UIApplication.shared.isNetworkActivityIndicatorVisible = true
                SwiftyStoreKit.restorePurchases { (result) in
                    UIApplication.shared.isNetworkActivityIndicatorVisible = false
                    
                    for purchase in result.restoredPurchases {
                        if purchase.needsFinishTransaction {
                            SwiftyStoreKit.finishTransaction(purchase.transaction)
                        }

                        completePurchase(id: purchase.productId)
                    }
                }
            }
        }
        
        let onboardingView = OnboardingView(isTrialEnded: true, fullFeaturedPrice: fullPrice, noExtensionsPrice: litePrice, startFreeTrial: {
            purchase(id: freeTrialProductID)
        }, purchaseFull: {
            purchase(id: fullVersionProductID)
        }, purchaseLite: {
            purchase(id: liteVersionProductID)
        }, restore: {
            purchase(id: "")
        })
        let controller = UIHostingController(rootView: onboardingView)
        controller.modalPresentationStyle = .fullScreen
        controller.modalTransitionStyle = .crossDissolve
        window?.topViewController?.present(controller, animated: true, completion: nil)
    }
}
