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
        window?.rootViewController = DocumentBrowserViewController()
        window?.accessibilityIgnoresInvertColors = true
        window?.tintColor = #colorLiteral(red: 0.394202292, green: 0.8019036651, blue: 0.3871951401, alpha: 1)
        window?.makeKeyAndVisible()
        
        return true
    }
    
    func application(_ app: UIApplication, open inputURL: URL, options: [UIApplication.OpenURLOptionsKey: Any] = [:]) -> Bool {
        // Ensure the URL is a file URL
        guard inputURL.isFileURL else { return false }
        
        // Reveal / import the document at the URL
        guard let documentBrowserViewController = window?.rootViewController as? DocumentBrowserViewController else { return false }
        
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
}

