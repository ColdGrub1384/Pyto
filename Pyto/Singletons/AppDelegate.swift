//
//  AppDelegate.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices
#if MAIN
import ios_system
#endif

/// The application's delegate.
@objc public class AppDelegate: UIResponder, UIApplicationDelegate {
    
    #if !MAIN
    /// Script to run at startup passed by `PythonApplicationMain`.
    @objc public static var scriptToRun: String?
    #else
    /// Copies modules to shared container.
    func copyModules() {
        
        if Thread.current.isMainThread {
            return DispatchQueue.global().async {
                self.copyModules()
            }
        }
        
        do {
            guard let sharedDir = FileManager.default.sharedDirectory else {
                return
            }
            
            if let widgetPath = UserDefaults.standard.string(forKey: "todayWidgetScriptPath") {
                
                let widgetURL = URL(fileURLWithPath: widgetPath.replacingFirstOccurrence(of: "iCloud/", with: (DocumentBrowserViewController.iCloudContainerURL?.path ?? DocumentBrowserViewController.localContainerURL.path)+"/"), relativeTo: DocumentBrowserViewController.localContainerURL)
                
                let newWidgetURL = sharedDir.appendingPathComponent("main.py")
                
                if FileManager.default.fileExists(atPath: newWidgetURL.path) {
                    try FileManager.default.removeItem(at: newWidgetURL)
                }
                
                try FileManager.default.copyItem(at: widgetURL, to: newWidgetURL)
            }
            
            let sharedModulesDir = sharedDir.appendingPathComponent("modules")
            
            if FileManager.default.fileExists(atPath: sharedModulesDir.path) {
                try FileManager.default.removeItem(at: sharedModulesDir)
            }
            
            try FileManager.default.copyItem(at: DocumentBrowserViewController.localContainerURL.appendingPathComponent("modules"), to: sharedModulesDir)
        } catch {
            print(error.localizedDescription)
        }
    }
    #endif
    
    /// If set to `true`, app will show a Welcome message at startup.
    var shouldShowWelcomeMessage: Bool {
        get {
            return !UserDefaults.standard.bool(forKey: "welcomeMessageShown")
        }
        
        set {
            UserDefaults.standard.set(!newValue, forKey: "welcomeMessageShown")
            UserDefaults.standard.synchronize()
        }
    }
    
    // MARK: - Application delegate
    
    @objc public var window: UIWindow?
    
    @objc public func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
                
        #if MAIN
        initializeEnvironment()
        unsetenv("TERM")
        unsetenv("LSCOLORS")
        unsetenv("CLICOLOR")
        setenv("PWD", FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].path, 1)
        setenv("SSL_CERT_FILE", Bundle.main.path(forResource: "cacert", ofType: "pem"), 1)
        
        window?.tintColor = ConsoleViewController.choosenTheme.tintColor
        
        for file in ((try? FileManager.default.contentsOfDirectory(at: URL(fileURLWithPath: NSTemporaryDirectory()), includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []) {
            try? FileManager.default.removeItem(at: file)
        }
        
        UIMenuController.shared.menuItems = [
            UIMenuItem(title: Localizable.MenuItems.breakpoint, action: #selector(EditorViewController.setBreakpoint(_:))),
            UIMenuItem(title: Localizable.MenuItems.toggleComment, action: #selector(EditorViewController.toggleComment))
        ]
        
        let docs = DocumentBrowserViewController.localContainerURL
        let iCloudDriveContainer = DocumentBrowserViewController.iCloudContainerURL
        
        do {
            let modulesURL = docs.appendingPathComponent("modules")
            if !FileManager.default.fileExists(atPath: modulesURL.path) {
                try FileManager.default.createDirectory(at: modulesURL, withIntermediateDirectories: false, attributes: nil)
            }
            if let iCloudURL = iCloudDriveContainer {
                if !FileManager.default.fileExists(atPath: iCloudURL.path) {
                    try? FileManager.default.createDirectory(at: iCloudURL, withIntermediateDirectories: true, attributes: nil)
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
        #else
        window = UIWindow()
        window?.backgroundColor = .white
        window?.rootViewController = UIStoryboard(name: "Splash Screen", bundle: Bundle(for: Python.self)).instantiateInitialViewController()
        window?.makeKeyAndVisible()
        DispatchQueue.main.asyncAfter(deadline: .now()+1) {
            
            ConsoleViewController.visible.modalTransitionStyle = .crossDissolve
            self.window?.rootViewController?.present(ConsoleViewController.visible, animated: true, completion: {
                ConsoleViewController.visible.textView.text = ""
                Python.shared.isScriptRunning = true
                PyInputHelper.userInput = "import console as __console__; script = __console__.run_script('\(AppDelegate.scriptToRun!)'); from suspend import suspend; suspend(); from time import sleep; sleep(0.5); exit(0)"
            })
        }
        #endif
        
        return true
    }
    
    #if MAIN
    
    @objc public func application(_ app: UIApplication, open inputURL: URL, options: [UIApplication.OpenURLOptionsKey: Any] = [:]) -> Bool {
        
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
                return true
            }
            
            return false
        }
      
        // Open script
        
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
        
        _ = inputURL.startAccessingSecurityScopedResource()
        
        // Reveal / import the document at the URL
        
        documentBrowserViewController.openDocument(inputURL, run: false)
        
        return true
    }
    
    @objc public func applicationWillResignActive(_ application: UIApplication) {
        #if MAIN
        copyModules()
        #endif
    }
    
    @objc public func application(_ application: UIApplication, continue userActivity: NSUserActivity, restorationHandler: @escaping ([UIUserActivityRestoring]?) -> Void) -> Bool {
        
        let root = window?.rootViewController
        
        func runScript() {
            if let path = userActivity.userInfo?["filePath"] as? String {
                
                let url = URL(fileURLWithPath: path.replacingFirstOccurrence(of: "iCloud/", with: (DocumentBrowserViewController.iCloudContainerURL?.path ?? DocumentBrowserViewController.localContainerURL.path)+"/"), relativeTo: DocumentBrowserViewController.localContainerURL)
                
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
    
    #endif
}

