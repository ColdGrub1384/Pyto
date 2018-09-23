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
                
        window = UIWindow(frame: UIScreen.main.bounds)
        window?.rootViewController = DocumentBrowserViewController(forOpeningFilesWithContentTypes: ["public.python-script"])
        window?.accessibilityIgnoresInvertColors = true
        window?.makeKeyAndVisible()
        
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
        
        documentBrowserViewController.revealDocument(at: inputURL, importIfNeeded: true) { (revealedDocumentURL, error) in
            if let error = error {
                // Handle the error appropriately
                print("Failed to reveal the document at URL \(inputURL) with error: '\(error)'")
                return
            }
            
            if revealedDocumentURL != nil {
                // Present the Document View Controller for the revealed URL
                documentBrowserViewController.openDocument(revealedDocumentURL!, run: false)
            } else {
                documentBrowserViewController.openDocument(inputURL, run: false)
            }
        }
        
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

