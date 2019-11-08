// This source file is part of the https://github.com/ColdGrub1384/Pisth open source project
//
// Copyright (c) 2017 - 2018 Adrian Labbé
// Licensed under Apache License v2.0
//
// See https://raw.githubusercontent.com/ColdGrub1384/Pisth/master/LICENSE for license information

import Foundation
import StoreKit

/// Helper used to request app review based on app launches.
@objc class ReviewHelper: NSObject {
    
    /// Request review and reset points.
    @objc func requestReview() {
        
        if minLaunches == nil {
            minLaunches = 0
        } else if (minLaunches as! Int) == 0 {
            minLaunches = 6
        } else if launches == 6 {
            minLaunches = 10
        } else if launches >= 10 {
            minLaunches = 0
        }
        
        if launches >= (minLaunches as? Int ?? 0) {
            launches = 0
            if #available(iOS 10.3, *) {
                SKStoreReviewController.requestReview()
                
                DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + Double(1 * Double(NSEC_PER_SEC)) / Double(NSEC_PER_SEC), execute: {
                    if UIApplication.shared.windows.count > 1 {
                        for console in ConsoleViewController.visibles {
                            console.textView.resignFirstResponder()
                        }
                    }
                })
            }
        }
    }
    
    // MARK: - Singleton
    
    /// Shared and unique instance.
    @objc static let shared = ReviewHelper()
    private override init() {}
    
    // MARK: - Launches tracking
    
    /// App launches incremented in `AppDelegate.application(_:, didFinishLaunchingWithOptions:)`.
    ///
    /// Launches are saved to `UserDefaults`.
    @objc var launches: Int {
        
        get {
            return UserDefaults.standard.integer(forKey: "launches")
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "launches")
        }
    }
    
    /// Minimum launches for asking for review.
    var minLaunches: Any? {
        
        get {
            return UserDefaults.standard.value(forKey: "minLaunches")
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "minLaunches")
            UserDefaults.standard.synchronize()
        }
    }
}
