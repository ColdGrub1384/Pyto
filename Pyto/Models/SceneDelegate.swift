//
//  SceneDelagate.swift
//  Pyto
//
//  Created by Adrian Labbé on 08-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// The scene delegate.
@objc class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    @available(iOS 13.0, *)
    private class ViewController: UIViewController {
        
        var justShown = true
        
        var viewControllerToPresent: UIViewController?
        
        var sceneSession: UISceneSession?
        
        override func viewDidAppear(_ animated: Bool) {
            super.viewDidAppear(animated)
            
            if justShown, let vc = viewControllerToPresent {
                vc.modalPresentationStyle = .fullScreen
                present(vc, animated: true, completion: nil)
            } else if let session = sceneSession {
                UIApplication.shared.requestSceneSessionDestruction(session, options: nil, errorHandler: nil)
            }
            justShown = false
        }
    }
    
    /// The document browser associated with this scene.
    var documentBrowserViewController: DocumentBrowserViewController? {
        return window?.rootViewController as? DocumentBrowserViewController
    }
    
    // MARK: - Scene delegate
    
    var window: UIWindow?
    
    @available(iOS 13.0, *)
    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        
        window?.tintColor = ConsoleViewController.choosenTheme.tintColor
        
        if connectionOptions.urlContexts.count > 0 {
            self.scene(scene, openURLContexts: connectionOptions.urlContexts)
        }
    }
    
    @available(iOS 13.0, *)
    func sceneWillResignActive(_ scene: UIScene) {
        #if MAIN
        (UIApplication.shared.delegate as? AppDelegate)?.copyModules()
        #endif
    }
    
    @available(iOS 13.0, *)
    func scene(_ scene: UIScene, continue userActivity: NSUserActivity) {
        
        guard userActivity.activityType != "vc" else {
            if let vc = userActivity.userInfo?["vc"] as? UIViewController {
                let blankVC = ViewController()
                blankVC.sceneSession = scene.session
                blankVC.viewControllerToPresent = vc
                window?.rootViewController = blankVC
            }
            return
        }
        
        let root = window?.rootViewController
        
        func runScript() {
            if let path = userActivity.userInfo?["filePath"] as? String {
                
                let url = URL(fileURLWithPath: path.replacingFirstOccurrence(of: "iCloud/", with: (DocumentBrowserViewController.iCloudContainerURL?.path ?? DocumentBrowserViewController.localContainerURL.path)+"/"), relativeTo: DocumentBrowserViewController.localContainerURL)
                
                if FileManager.default.fileExists(atPath: url.path) {
                    
                    if FileManager.default.isUbiquitousItem(at: url) {
                        try? FileManager.default.startDownloadingUbiquitousItem(at: url)
                    }
                    
                    documentBrowserViewController?.openDocument(url, run: true)
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
    }
    
    @available(iOS 13.0, *)
    func scene(_ scene: UIScene, openURLContexts URLContexts: Set<UIOpenURLContext>) {
        
        guard let inputURL = URLContexts.first?.url else {
            return
        }
        
        if inputURL.scheme == "pyto" { // Select script for Today widget
            
            if inputURL.host == "select-script", let vc = UIStoryboard(name: "Settings", bundle: Bundle.main).instantiateInitialViewController() {
                window?.topViewController?.present(vc, animated: true, completion: {
                    let settingsVC = (vc as? UINavigationController)?.visibleViewController as? AboutTableViewController
                    
                    let indexPath = IndexPath(row: 0, section: 1)
                    settingsVC?.tableView?.selectRow(at: indexPath, animated: true, scrollPosition: .middle)
                    _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in
                        settingsVC?.tableView(settingsVC!.tableView, didSelectRowAt: indexPath)
                    })
                })
                return
            }
            
            return
        }
        
        // Open script
        
        guard let documentBrowserViewController = documentBrowserViewController else {
            window?.rootViewController?.dismiss(animated: true, completion: {
                self.scene(scene, openURLContexts: URLContexts)
            })
            return
        }
        
        // Ensure the URL is a file URL
        guard inputURL.isFileURL else {
            
            guard let query = inputURL.query?.removingPercentEncoding else {
                return
            }
            
            // Run code passed to the URL
            documentBrowserViewController.run(code: query)
            
            return
        }
        
        _ = inputURL.startAccessingSecurityScopedResource()
        
        // Reveal / import the document at the URL
        
        documentBrowserViewController.revealDocument(at: inputURL, importIfNeeded: true, completion: { (url, _) in
            
            documentBrowserViewController.openDocument(url ?? inputURL, run: false)
        })
    }
}
