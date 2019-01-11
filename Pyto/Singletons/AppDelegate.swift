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
    
    /// Suspends app. Set from Python.
    @objc var suspendApp_: (() -> Void)?
    
    /// Suspends the app.
    @objc func suspendApp() {
        DispatchQueue.main.async {
            self.suspendApp_?()
        }
    }
    
    // MARK: - Application delegate
    
    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        window?.rootViewController?.addKeyCommand(UIKeyCommand(input: "h", modifierFlags: .command, action: #selector(suspendApp)))
        
        UIMenuController.shared.menuItems = [
            UIMenuItem(title: Localizable.MenuItems.open, action: #selector(FileCollectionViewCell.open(_:))),
            UIMenuItem(title: Localizable.MenuItems.run, action: #selector(FileCollectionViewCell.run(_:))),
            UIMenuItem(title: Localizable.MenuItems.rename, action: #selector(FileCollectionViewCell.rename(_:))),
            UIMenuItem(title: Localizable.MenuItems.remove, action: #selector(FileCollectionViewCell.remove(_:))),
            UIMenuItem(title: Localizable.MenuItems.copy, action: #selector(FileCollectionViewCell.copyFile(_:))),
            UIMenuItem(title: Localizable.MenuItems.move, action: #selector(FileCollectionViewCell.move(_:))),
        ]
        
        window?.accessibilityIgnoresInvertColors = true
        
        let docs = DocumentBrowserViewController.localContainerURL
        let iCloudDriveContainer = DocumentBrowserViewController.iCloudContainerURL
        
        do {
            let modulesURL = docs.appendingPathComponent("modules")
            if !FileManager.default.fileExists(atPath: modulesURL.path) {
                try FileManager.default.createDirectory(at: modulesURL, withIntermediateDirectories: false, attributes: nil)
            }
            
            let newSamplesURL = docs.appendingPathComponent("Examples") // Removed since 4.0
            if FileManager.default.fileExists(atPath: newSamplesURL.path), let samplesURL = Bundle.main.url(forResource: "Samples", withExtension: nil), let contents = (try? FileManager.default.contentsOfDirectory(atPath: newSamplesURL.path)), let defaultContents = (try? FileManager.default.contentsOfDirectory(atPath: samplesURL.path)), contents == defaultContents {
               try FileManager.default.removeItem(at: newSamplesURL)
            }
            
            let newREADMEURL = docs.appendingPathComponent("README.py") // Removed since 4.0
            if let readmeURL = Bundle.main.url(forResource: "Help", withExtension: "py"), FileManager.default.fileExists(atPath: newREADMEURL.path), let defaultData = try? Data(contentsOf: readmeURL), let data = try? Data(contentsOf: newREADMEURL), data == defaultData {
                try FileManager.default.removeItem(at: newREADMEURL)
            }
            
            if let iCloudURL = iCloudDriveContainer {
                if !FileManager.default.fileExists(atPath: iCloudURL.path) {
                    try? FileManager.default.createDirectory(at: iCloudURL, withIntermediateDirectories: true, attributes: nil)
                }
                
                for file in ((try? FileManager.default.contentsOfDirectory(at: docs, includingPropertiesForKeys: nil, options: .init(rawValue: 0))) ?? []) {
                    
                    if file.lastPathComponent != modulesURL.lastPathComponent {
                        try? FileManager.default.moveItem(at: file, to: iCloudURL.appendingPathComponent(file.lastPathComponent))
                    }
                }
            }
        } catch {
            print(error.localizedDescription)
        }
        
        NSSetUncaughtExceptionHandler { (exception) in
            PyOutputHelper.print(NSString(format: Localizable.ObjectiveC.exception as NSString, exception.name.rawValue, exception.reason ?? "") as String)
            PyInputHelper.showAlert(prompt: Localizable.ObjectiveC.quit)
            while PyInputHelper.userInput == nil {
                sleep(UInt32(0.5))
            }
        }
        
        PyInputHelper.userInput = [
            "from UIKit import *",
            "from rubicon.objc import *",
            "delegate = UIApplication.sharedApplication.delegate",
            "def suspend() -> None:",
            "   UIApplication.sharedApplication.suspend()",
            "delegate.suspendApp_ = Block(suspend)",
        ].joined(separator: ";")
        
        return true
    }
    
    func application(_ app: UIApplication, open inputURL: URL, options: [UIApplication.OpenURLOptionsKey: Any] = [:]) -> Bool {
        
        guard let documentBrowserViewController = DocumentBrowserViewController.visible else {
            window?.rootViewController?.dismiss(animated: true, completion: {
                _ = self.application(app, open: inputURL, options: options)
            })
            return true
        }
        
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
    
    func application(_ application: UIApplication, continue userActivity: NSUserActivity, restorationHandler: @escaping ([UIUserActivityRestoring]?) -> Void) -> Bool {

        let root = window?.rootViewController
        
        func runScript() {
            if let path = userActivity.userInfo?["filePath"] as? String {
                
                let url = URL(fileURLWithPath: RelativePathForScript(URL(fileURLWithPath: path)).replacingFirstOccurrence(of: "iCloud/", with: (DocumentBrowserViewController.iCloudContainerURL?.path ?? DocumentBrowserViewController.localContainerURL.path)+"/"), relativeTo: FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask).first)
                
                if FileManager.default.fileExists(atPath: url.path) {
                    
                    if FileManager.default.isUbiquitousItem(at: url) {
                        try? FileManager.default.startDownloadingUbiquitousItem(at: url)
                    }
                    
                    DocumentBrowserViewController.visible?.openDocument(url, run: true)
                } else {
                    let alert = UIAlertController(title: Localizable.Errors.errorReadingFile, message: nil, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                    root?.present(alert, animated: true, completion: nil)
                }
            } else {
                print("Invalid shortcut!")
            }
        }
        
        if root?.presentedViewController != nil {
            root?.dismiss(animated: true, completion: {
                runScript()
            })
        } else {
            runScript()
        }
        
        return true
    }
    
    func applicationWillEnterForeground(_ application: UIApplication) {
        DocumentBrowserViewController.visible?.reloadData()
    }
    
    // MARK: - Store product view controller delegate
    
    func productViewControllerDidFinish(_ viewController: SKStoreProductViewController) {
        viewController.dismiss(animated: true, completion: nil)
    }
}

