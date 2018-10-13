//
//  AppDelegate.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import StoreKit
import SafariServices

/// The application's delegate.
@objc class AppDelegate: UIResponder, UIApplicationDelegate, SKStoreProductViewControllerDelegate {
    
    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        UIMenuController.shared.menuItems = [
            UIMenuItem(title: "Open", action: #selector(FileCollectionViewCell.open(_:))),
            UIMenuItem(title: "Run", action: #selector(FileCollectionViewCell.run(_:))),
            UIMenuItem(title: "Rename", action: #selector(FileCollectionViewCell.rename(_:))),
            UIMenuItem(title: "Remove", action: #selector(FileCollectionViewCell.remove(_:))),
            UIMenuItem(title: "Copy", action: #selector(FileCollectionViewCell.copyFile(_:))),
            UIMenuItem(title: "Move", action: #selector(FileCollectionViewCell.move(_:)))
        ]
        
        window?.accessibilityIgnoresInvertColors = true
        
        ReviewHelper.shared.launches += 1
        ReviewHelper.shared.requestReview()
        if ReviewHelper.shared.launches == 5 && !UserDefaults.standard.bool(forKey: "pisth") {
            UserDefaults.standard.set(true, forKey: "pisth")
            UserDefaults.standard.synchronize()
            if !UIApplication.shared.canOpenURL(URL(string: "pisth://")!) {
                let alert = UIAlertController(title: "Pisth - SSH Client", message: "Do you want to run your scripts remotely via SSH? You can download Pisth, an SSH client.", preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "View on the App Store", style: .default, handler: { _ in
                    let store = SKStoreProductViewController()
                    store.delegate = self
                    store.loadProduct(withParameters: [SKStoreProductParameterITunesItemIdentifier: "1331070425"], completionBlock: nil)
                    self.window?.rootViewController?.present(store, animated: true, completion: nil)
                }))
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
                window?.rootViewController?.present(alert, animated: true, completion: nil)
            }
        }
        
        NSSetUncaughtExceptionHandler { (exception) in
            PyOutputHelper.print("An Objective-C exception occurred. \(exception.name.rawValue), reason: \(exception.reason ?? "")\n\nThis error is not caught by Python but by the app.\nYou can continue editing scripts but you cannot run scripts anymore until the app is restarted.\n")
            PyInputHelper.showAlert(prompt: "Press enter to quit the app. ")
            while PyInputHelper.userInput == nil {
                sleep(UInt32(0.5))
            }
        }
        
        return true
    }
    
    func application(_ app: UIApplication, open inputURL: URL, options: [UIApplication.OpenURLOptionsKey: Any] = [:]) -> Bool {
        
        guard let documentBrowserViewController = window?.rootViewController as? DocumentBrowserViewController else { return false }
        
        // Ensure the URL is a file URL
        guard inputURL.isFileURL else {
            
            guard let query = inputURL.query?.removingPercentEncoding else {
                return false
            }
            
            // Run code passed to the URL
            documentBrowserViewController.run(code: query)
            
            return true
        }
        
        // Reveal / import the document at the URL
        
        documentBrowserViewController.openDocument(inputURL, run: false)
        
        return true
    }
    
    func applicationWillResignActive(_ application: UIApplication) {
        (window?.topViewController as? SFSafariViewController)?.dismiss(animated: true, completion: nil)
    }
    
    func application(_ application: UIApplication, shouldSaveApplicationState coder: NSCoder) -> Bool {
        return true
    }
    
    func application(_ application: UIApplication, shouldRestoreApplicationState coder: NSCoder) -> Bool {
        return true
    }
    
    // MARK: - Store product view controller delegate
    
    func productViewControllerDidFinish(_ viewController: SKStoreProductViewController) {
        viewController.dismiss(animated: true, completion: nil)
    }
}

