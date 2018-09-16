//
//  AppDelegate.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// The application's delegate.
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
                
        window = UIWindow(frame: UIScreen.main.bounds)
        window?.rootViewController = UIDocumentBrowserViewController()
        window?.accessibilityIgnoresInvertColors = true
        window?.tintColor = #colorLiteral(red: 0.394202292, green: 0.8019036651, blue: 0.3871951401, alpha: 1)
        window?.makeKeyAndVisible()
        
        return true
    }
}

