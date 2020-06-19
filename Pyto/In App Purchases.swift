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
import UserNotifications

/// Purchasable products.
enum Product: String {
    
    /// Full version
    case fullVersion = "ch.ada.Pyto.fullversion"
    
    /// Lite version
    case liteVersion = "ch.ada.Pyto.liteversion"
    
    /// Free trial
    case freeTrial = "ch.ada.Pyto.freetrial"
    
    /// Upgrade from lite to full
    case upgrade = "ch.ada.Pyto.upgradeToFull"
    
    /// Restore
    case restore = ""
}

/// Purchases a product with the given ID.
///
/// - Parameters:
///     - id: The product id.
///     - window: The window where errors will be presented.
func purchase(id: Product, window: UIWindow?) {
    
    let vc = ActivityViewController(message: "")
    
    window?.topViewController?.present(vc, animated: true, completion: {
        if id.rawValue != Product.restore.rawValue {
            SwiftyStoreKit.purchaseProduct(id.rawValue) { (result) in
                vc.dismiss(animated: true) {
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
            }
        } else {
            SwiftyStoreKit.restorePurchases { (result) in
                vc.dismiss(animated: true) {
                    var products = [Product]()
                    
                    for purchase in result.restoredPurchases {
                        if purchase.needsFinishTransaction {
                            SwiftyStoreKit.finishTransaction(purchase.transaction)
                        }
                        
                        if let product = Product(rawValue: purchase.productId) {
                            products.append(product)
                        }
                    }
                    
                    // Only activate the "most upgraded" purchase
                    
                    if products.contains(.freeTrial) && products.count > 1 {
                        // Don't activate the free trial if something else was purchased
                        
                        if products.contains(.fullVersion) || products.contains(.upgrade) {
                            // Don't activate the lite version if the full version is purchased
                            completePurchase(id: Product.fullVersion.rawValue)
                        } else if products.contains(.liteVersion) {
                            completePurchase(id: Product.liteVersion.rawValue)
                        }
                    } else {
                        completePurchase(id: Product.freeTrial.rawValue)
                    }
                }
            }
        }
    })
}

/// The version of Pyto introducing free trials.
var initialVersionRequiringUserToPay: String {
    if isSandbox {
        return "1.0" // Sandbox
    }
    
    return "275"
}

/// The free trial duration in days.
var freeTrialDuration: Int {
    return 3
}

/// Returns a boolean indicating whether the app is in sandbox environment.
var isSandbox: Bool {
    return Bundle.main.appStoreReceiptURL?.lastPathComponent.contains("sandbox") == true
}

/// A boolean indicating whether Pyto was either purchased from the App Store or if an IAP was purchased.
public let isPurchased = ObjectUserDefaults.standard.item(forKey: "isPurchased")

/// A boolean indicating whether Pyto should not allow importing C extensions.
public let isLiteVersion = ObjectUserDefaults.standard.item(forKey: "isLiteVersion")

/// A boolean indicating wheter the app is usable.
public var isUnlocked = false

/// A boolean indicating whether the app finished verifying the receipt at startup.
var isReceiptChecked = false

fileprivate var _isPurchased = isPurchased.boolValue

fileprivate var _isLiteVersion = isLiteVersion.boolValue

/// A boolean indicating whether changes to UserDefaults for unlocking extra content are allowed.
public var changingUserDefaultsInAppPurchasesValues = false

/// Adds a notification observer that checks if a change in UserDefaults for unlocking extra content is made without allowing it with a Swift variable.
func observeUserDefaults() {
    NotificationCenter.default.addObserver(forName: UserDefaults.didChangeNotification, object: nil, queue: nil) { (_) in
        
        guard !changingUserDefaultsInAppPurchasesValues else {
            changingUserDefaultsInAppPurchasesValues = false
            
            _isPurchased = isPurchased.boolValue
            _isLiteVersion = isLiteVersion.boolValue
            
            return
        }
        
        // Compile the source code if you want to use Pyto for free 😊
        if (isPurchased.boolValue != _isPurchased) || (isLiteVersion.boolValue != _isLiteVersion) {
            isPurchased.boolValue = false
            isLiteVersion.boolValue = _isLiteVersion
            fatalError("Detected unallowed change on UserDefaults related to In App Purchases.")
        }
    }
}

/// Completes purchase for the given product id.
///
/// - Parameters:
///     - id: The purchased product identifier.
func completePurchase(id: String) {
    
    func unlock() {
        
        if id != Product.freeTrial.rawValue {
            UNUserNotificationCenter.current().removeAllPendingNotificationRequests()
        }
        
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
    case Product.fullVersion.rawValue, Product.upgrade.rawValue:
        changingUserDefaultsInAppPurchasesValues = true
        isPurchased.boolValue = true
        changingUserDefaultsInAppPurchasesValues = true
        isLiteVersion.boolValue = false
        unlock()
    case Product.liteVersion.rawValue:
        changingUserDefaultsInAppPurchasesValues = true
        isPurchased.boolValue = true
        changingUserDefaultsInAppPurchasesValues = true
        isLiteVersion.boolValue = true
        unlock()
    case Product.freeTrial.rawValue:
        guard let validator = ReceiptValidator() else {
            return
        }
        
        guard let date = validator.trialStartDate else {
            return
        }
        
        TrueTimeClient.sharedInstance.fetchIfNeeded(success: { (time) in
            let calendar = Calendar.current

            let date1 = calendar.startOfDay(for: date)
            let date2 = calendar.startOfDay(for: isSandbox ? Date() : time.now()) // Make the date fakable in sandbox

            let components = calendar.dateComponents([.day], from: date1, to: date2)
            
            guard let days = components.day else {
                return
            }
            
            if days <= freeTrialDuration { // Free trial
                PyNotificationCenter.scheduleNotification(title: Localizable.trialExpiredTitle, message: Localizable.trialExpiredMessage, delay: Double(((freeTrialDuration*24)*60)*60))
                unlock()
            } else {
                
                if #available(iOS 13.0, *) {
                    for scene in UIApplication.shared.connectedScenes {
                        guard let window = (scene as? UIWindowScene)?.windows.first else {
                            continue
                        }
                        
                        let vc = window.topViewController
                        
                        if vc is UIHostingController<OnboardingView> {
                            vc?.dismiss(animated: true, completion: {
                                Pyto.showOnboarding(window: window, isTrialExpired: true)
                            })
                        }
                    }
                }
            }
        }) { (error) in
            print(error.localizedDescription)
        }
    default:
        break
    }
}

/// Shows onboarding on the given window.
///
/// - Parameters:
///     - window: The window where the onboarding screen should be presented.
///     - isTrialExpired: A boolean indicating whether the trial expired.
@available(iOS 13.0.0, *)
func showOnboarding(window: UIWindow?, isTrialExpired: Bool = false) {
    SwiftyStoreKit.retrieveProductsInfo(Set([Product.fullVersion.rawValue, Product.liteVersion.rawValue])) { (results) in
        var fullPrice = "9.99$"
        var litePrice = "2.99$"
        
        for result in results.retrievedProducts {
            if result.productIdentifier == Product.fullVersion.rawValue {
                fullPrice = result.localizedPrice ?? fullPrice
            } else if result.productIdentifier == Product.liteVersion.rawValue {
                litePrice = result.localizedPrice ?? litePrice
            }
        }
        
        let onboardingView = OnboardingView(isTrialEnded: isTrialExpired, fullFeaturedPrice: fullPrice, noExtensionsPrice: litePrice, startFreeTrial: {
            purchase(id: .freeTrial, window: window)
        }, purchaseFull: {
            purchase(id: .fullVersion, window: window)
        }, purchaseLite: {
            purchase(id: .liteVersion, window: window)
        }, restore: {
            purchase(id: .restore, window: window)
        })
        let controller = UIHostingController(rootView: onboardingView)
        controller.modalPresentationStyle = .fullScreen
        controller.modalTransitionStyle = .crossDissolve
        window?.topViewController?.present(controller, animated: true, completion: nil)
    }
}
