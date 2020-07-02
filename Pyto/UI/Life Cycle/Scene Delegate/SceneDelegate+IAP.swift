//
//  SceneDelegate+IAP.swift
//  Pyto
//
//  Created by Adrian Labbé on 02-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import StoreKit
import SwiftyStoreKit

// In App Purchases

extension SceneDelegate: SKRequestDelegate {
    
    /// Verifies the receipt and shows the onboarding screen if needed.
    func verifyReceipt() {
        if let receiptUrl = Bundle.main.appStoreReceiptURL, let _ = try? Data(contentsOf: receiptUrl) {
             showOnboarding()
        } else {
            let request = SKReceiptRefreshRequest()
            request.delegate = self
            request.start()
        }
        
        if !ProcessInfo.processInfo.environment.keys.contains("UPGRADE_PRICE") {
            SwiftyStoreKit.retrieveProductsInfo(Set([Product.upgrade.rawValue])) { (results) in
                for result in results.retrievedProducts {
                    if let price = result.localizedPrice {
                        setenv("UPGRADE_PRICE", "\(price)", 1)
                    }
                }
            }
        }
    }
    
    // MARK: - Request delegate
    
    func requestDidFinish(_ request: SKRequest) {
        showOnboarding()
    }
    
    func request(_ request: SKRequest, didFailWithError error: Error) {
        isReceiptChecked = true
    }
}
