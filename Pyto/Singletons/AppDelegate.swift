//
//  AppDelegate.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices

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
    
    // MARK: - Application delegate
    
    @objc public var window: UIWindow?
    
    @objc public func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
                
        #if MAIN
        unsetenv("TERM")
        unsetenv("LSCOLORS")
        unsetenv("CLICOLOR")
        setenv("PWD", FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].path, 1)
        setenv("SSL_CERT_FILE", Bundle.main.path(forResource: "cacert", ofType: "pem"), 1)
        
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
        
    public func applicationWillTerminate(_ application: UIApplication) {
        exit(0)
    }
    
    #endif
}

