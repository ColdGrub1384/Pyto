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
    
    private let copyModulesQueue = DispatchQueue.global(qos: .background)
    
    /// Copies modules to shared container.
    func copyModules() {
        
        if Thread.current.isMainThread {
            return copyModulesQueue.async {
                self.copyModules()
            }
        }
        
        do {
            guard let sharedDir = FileManager.default.sharedDirectory else {
                return
            }
            
            let path = UserDefaults.standard.string(forKey: "todayWidgetScriptPath")
            let data = UserDefaults.standard.data(forKey: "todayWidgetScriptPath")
            let url: URL?
            if let data = data {
                var isStale = false
                url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                _ = url?.startAccessingSecurityScopedResource()
            } else if let path = path {
                url = URL(fileURLWithPath: path)
            } else {
                url = nil
            }
            
            if let widgetPath = url?.path {
                
                for file in try FileManager.default.contentsOfDirectory(at: sharedDir, includingPropertiesForKeys: nil, options: .init(rawValue: 0)) {
                    try FileManager.default.removeItem(at: file)
                }
                
                let widgetURL: URL
                if data != nil {
                    widgetURL = URL(fileURLWithPath: widgetPath)
                } else {
                    widgetURL = URL(fileURLWithPath: widgetPath.replacingFirstOccurrence(of: "iCloud/", with: (DocumentBrowserViewController.iCloudContainerURL?.path ?? DocumentBrowserViewController.localContainerURL.path)+"/"), relativeTo: DocumentBrowserViewController.localContainerURL)
                }
                
                let newWidgetURL = sharedDir.appendingPathComponent("main.py")
                
                if FileManager.default.fileExists(atPath: newWidgetURL.path) {
                    try FileManager.default.removeItem(at: newWidgetURL)
                }
                
                try FileManager.default.copyItem(at: widgetURL, to: newWidgetURL)
                
                for file in ((try? FileManager.default.contentsOfDirectory(at: EditorViewController.directory(for: url!), includingPropertiesForKeys: nil, options: .init(rawValue: 0))) ?? []) {
                    let newURL = sharedDir.appendingPathComponent(file.lastPathComponent)
                    if FileManager.default.fileExists(atPath: newURL.path) {
                        try? FileManager.default.removeItem(at: newURL)
                    }
                    
                    try? FileManager.default.copyItem(at: file, to: newURL)
                }
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
        
        window?.tintColor = ConsoleViewController.choosenTheme.tintColor
        
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
        
        DispatchQueue.global().async {
            for folder in FoldersBrowserViewController.accessibleFolders {
                _ = folder.startAccessingSecurityScopedResource()
                sleep(UInt32(0.2))
            }
        }
        
        #else
        window = UIWindow()
        window?.backgroundColor = .white
        window?.rootViewController = UIStoryboard(name: "Splash Screen", bundle: Bundle(for: Python.self)).instantiateInitialViewController()
        window?.makeKeyAndVisible()
        DispatchQueue.main.asyncAfter(deadline: .now()+1) {
            let console = ConsoleViewController()
            console.modalTransitionStyle = .crossDissolve
            self.window?.rootViewController?.present(console, animated: true, completion: {
                console.textView.text = ""
                Python.shared.runningScripts = [AppDelegate.scriptToRun!]
                PyInputHelper.userInput = "import console as __console__; script = __console__.run_script('\(AppDelegate.scriptToRun!)'); import code; code.interact(banner='', local=vars(script))"
            })
        }
        #endif
        
        return true
    }
    
    #if MAIN
    
    public func applicationWillResignActive(_ application: UIApplication) {
        guard #available(iOS 13.0, *) else {
            ((window?.rootViewController?.presentedViewController as? UINavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor.save()
            return
        }
    }
    
    public func applicationDidEnterBackground(_ application: UIApplication) {
        ((window?.rootViewController?.presentedViewController as? UINavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor.save()
    }
    
    @available(iOS 13.0, *)
    public func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        
        for session in sceneSessions {
            (((session.scene?.delegate as? UIWindowSceneDelegate)?.window??.rootViewController?.presentedViewController as? UINavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor.save()
        }
    }
            
    public func applicationWillTerminate(_ application: UIApplication) {
        exit(0)
    }
    
    #endif
}

