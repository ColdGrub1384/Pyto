//
//  AppDelegate.swift
//  Pyto
//
//  Created by Emma Labbé on 9/8/18.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import SafariServices
import NotificationCenter
import CoreLocation
import CoreMotion
import BackgroundTasks
#if MAIN
import WatchConnectivity
import Intents
import SwiftyStoreKit
import TrueTime
import AVFoundation
#endif

/// The application's delegate.
@objc public class AppDelegate: UIResponder, UIApplicationDelegate, CLLocationManagerDelegate, UNUserNotificationCenterDelegate {
    
    /// The shared instance.
    @objc static var shared: AppDelegate {
        if Thread.current.isMainThread {
            return UIApplication.shared.delegate as! AppDelegate
        } else {
            var object: AppDelegate!
            
            let semaphore = DispatchSemaphore(value: 0)
            DispatchQueue.main.async {
                object = UIApplication.shared.delegate as? AppDelegate
                semaphore.signal()
            }
            semaphore.wait()
            
            return object
        }
    }
    
    /// The shared location manager.
    let locationManager = CLLocationManager()
    
    #if !MAIN
    /// Script to run at startup passed by `PythonApplicationMain`.
    @objc public static var scriptToRun: String?
    #else
    
    /// The script currently running from an Apple Watch.
    @objc var watchScript: String?
    
    /// The script currently running from Shortcuts.
    @objc var shortcutScript: String?
    
    private let copyModulesQueue = DispatchQueue.global(qos: .background)
    
    private var downloadingPyPICache = false
    
    /// Updates the PyPi index cache.
    func updatePyPiCache() {
        
        guard !downloadingPyPICache else {
            return
        }
        
        downloadingPyPICache = true
        
        let task = UIApplication.shared.beginBackgroundTask(expirationHandler: nil)
        
        URLSession.shared.downloadTask(with: URL(string: "https://pypi.org/simple")!) { (fileURL, _, error) in
            
            self.downloadingPyPICache = false
            
            if let error = error {
                print(error.localizedDescription)
            } else if let url = fileURL {
                
                let cacheURL = FileManager.default.urls(for: .libraryDirectory, in: .userDomainMask)[0].appendingPathComponent("pypi_index.html")
                if FileManager.default.fileExists(atPath: cacheURL.path) {
                    try? FileManager.default.removeItem(at: cacheURL)
                }
                
                do {
                    try FileManager.default.copyItem(at: url, to: cacheURL)
                } catch {
                    print(error.localizedDescription)
                }
            }
            
            UIApplication.shared.endBackgroundTask(task)
        }.resume()
    }
    
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
            }
        } catch {
            print(error.localizedDescription)
        }
        
        if let bundleID = Bundle.main.bundleIdentifier?.appending(".Today-Widget"), let dir = FileManager.default.sharedDirectory?.path {
            let scriptExists = FileManager.default.fileExists(atPath: (dir as NSString).appendingPathComponent("main.py"))
            NCWidgetController().setHasContent(scriptExists, forWidgetWithBundleIdentifier: bundleID)
        }
        
        do {
            guard let modsDir = FileManager.default.sharedDirectory?.appendingPathComponent("modules") else {
                return
            }
            
            if FileManager.default.fileExists(atPath: modsDir.path) {
                try FileManager.default.removeItem(at: modsDir)
            }
        } catch {
            print(error.localizedDescription)
        }
    }
    
    /// Adds an URL bookmark to Siri Shortcuts.
    func addURLToShortcuts(_ url: URL) {
        
        guard !url.resolvingSymlinksInPath().path.hasPrefix(URL(fileURLWithPath: NSTemporaryDirectory()).resolvingSymlinksInPath().path) else {
            return
        }
        
        guard let group = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto") else {
            return
        }
        
        let docs = group.appendingPathComponent("Shortcuts")
        
        if !FileManager.default.fileExists(atPath: docs.path) {
            try? FileManager.default.createDirectory(at: docs, withIntermediateDirectories: true, attributes: nil)
        }
        
        do {
            let bookmarkData = try url.bookmarkData()
            let script = IntentScript(bookmarkData: bookmarkData, code: (try String(contentsOf: url)))
            let data = try JSONEncoder().encode(script)
            try data.write(to: docs.appendingPathComponent(url.lastPathComponent))
        } catch {
            print(error.localizedDescription)
        }
        
        // Remove missing files
        DispatchQueue.global().async {
            var urls = [URL]()
            do {
                for file in try FileManager.default.contentsOfDirectory(at: docs, includingPropertiesForKeys: nil, options: []) {
                    do {
                        var isStale = false
                        let data = try Data(contentsOf: file)
                        let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                        if !FileManager.default.fileExists(atPath: url.path) || (urls.contains(url) && url.lastPathComponent != file.lastPathComponent) {
                            try FileManager.default.removeItem(at: file)
                        }
                        urls.append(url)
                    } catch {
                        print(error.localizedDescription)
                    }
                }
            } catch {
                print(error.localizedDescription)
            }
        }
    }
    
    private let exceptionHandler: Void = NSSetUncaughtExceptionHandler { (exception) in
        PyOutputHelper.printError("\(exception.name.rawValue): \(exception.reason ?? "")\n\n\(exception.callStackSymbols.joined(separator: "\n"))\n", script: nil)
    }
    #endif
    
    // MARK: - Application delegate
        
    @objc public func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        
        UNUserNotificationCenter.current().delegate = self
        
        #if MAIN
        
        FocusSystemObserver.startObserving()
        
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
            let modulesURL = docs.appendingPathComponent("site-packages")
            let oldModulesURL = docs.appendingPathComponent("modules")
            
            if !UserDefaults.standard.bool(forKey: "movedSitePackages") && FileManager.default.fileExists(atPath: oldModulesURL.path) {
                try? FileManager.default.moveItem(at: oldModulesURL, to: modulesURL)
            }
            
            UserDefaults.standard.set(true, forKey: "movedSitePackages")
            
            if !FileManager.default.fileExists(atPath: modulesURL.path) {
                try FileManager.default.createDirectory(at: modulesURL, withIntermediateDirectories: false, attributes: nil)
            }
            
            FoldersBrowserViewController.sitePackages = modulesURL
            
            if let iCloudURL = iCloudDriveContainer {
                if !FileManager.default.fileExists(atPath: iCloudURL.path) {
                    try? FileManager.default.createDirectory(at: iCloudURL, withIntermediateDirectories: true, attributes: nil)
                }
            }
        } catch {
            print(error.localizedDescription)
        }
        
        print(FoldersBrowserViewController.accessibleFolders)
        DispatchQueue.global().async {
            for folder in FoldersBrowserViewController.accessibleFolders {
                print(folder.startAccessingSecurityScopedResource())
                sleep(UInt32(0.2))
            }
        }
        
        WCSession.default.delegate = self
        WCSession.default.activate()
        
        if #available(iOS 13.0, *) { // Listen to memory
            let mem = MemoryManager()
            mem.memoryLimitAlmostReached = {
                Python.shared.tooMuchUsedMemory = true
                
                for script in Python.shared.runningScripts {
                    guard let path = script as? String else {
                        continue
                    }
                    
                    Python.shared.stop(script: path)
                }
            }
            mem.startListening()
        }
        
        // Listen to the pasteboard
        // Converts a value URL from the REPL to its representation
        NotificationCenter.default.addObserver(forName: UIPasteboard.changedNotification, object: nil, queue: nil) { (_) in
                        
            guard let pasteboard = UIPasteboard.general.string else {
                return
            }
            
            guard let url = URL(string: pasteboard) else {
                return
            }
            
            guard url.scheme == "pyto" && url.host == "inspector" else {
                return
            }
            
            guard var description = url.path.removingPercentEncoding else {
                return
            }
            
            if url.path.hasPrefix("/") {
                description.removeFirst()
            }
            if url.path.hasSuffix("\n") {
                description.removeLast()
            }
            
            UIPasteboard.general.string = description
        }
        
        SwiftyStoreKit.completeTransactions { (purchases) in
            for purchase in purchases {
                switch purchase.transaction.transactionState {
                case .purchased, .restored:
                    if purchase.needsFinishTransaction {
                        SwiftyStoreKit.finishTransaction(purchase.transaction)
                    }
                    
                    completePurchase(id: purchase.productId)
                case .failed, .purchasing, .deferred:
                    break
                }
            }
        }
        
        SwiftyStoreKit.shouldAddStorePaymentHandler = { payment, product in
            
            func continuePurchasing(id: Product, window: UIWindow?) {
                
                let name = id.rawValue.components(separatedBy: ".").last ?? ""
                
                let message: String
                if id == .fullVersion || id == .upgrade {
                    message = NSLocalizedString("fullversion.promotion", comment: "")
                } else {
                    message = NSLocalizedString("\(name).promotion", comment: "")
                }
                
                let alert = UIAlertController(title: NSLocalizedString(name, comment: ""), message: message, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .default, handler: { (_) in
                    purchase(id: id, window: window)
                }))
                alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
                DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                    window?.topViewController?.present(alert, animated: true, completion: nil)
                }
            }
            
            if let validator = ReceiptValidator(), let version = validator.receipt[.originalAppVersion] as? String {
                guard version.versionCompare(initialVersionRequiringUserToPay) != .orderedAscending else {
                    return false
                }
            }
            
            switch Product(rawValue: product.productIdentifier) {
            case .freeTrial:
                return true
            case .upgrade:
                return false // Not purchasable from the App Store
            case .liteVersion:
                // Only purchasable if the full version isn't purchased
                
                SwiftyStoreKit.restorePurchases { (results) in
                    
                    var product = Product.liteVersion
                    
                    for purchase in results.restoredPurchases {
                        if purchase.productId == Product.fullVersion.rawValue {
                            product = .fullVersion
                            break
                        } else if purchase.productId == Product.upgrade.rawValue {
                            product = .upgrade
                            break
                        }
                    }
                    
                    if #available(iOS 13.0, *) {
                        let keyWindow = UIApplication.shared.connectedScenes
                        .filter({$0.activationState == .foregroundActive})
                        .map({$0 as? UIWindowScene})
                        .compactMap({$0})
                        .first?.windows
                        .filter({$0.isKeyWindow}).first
                        
                        continuePurchasing(id: product, window: keyWindow)
                    }
                }
                
                return false
            case .fullVersion:
                // Give a discount if the lite version was purchased
                
                SwiftyStoreKit.restorePurchases { (results) in
                    
                    var product = Product.fullVersion
                    
                    for purchase in results.restoredPurchases {
                        if purchase.productId == Product.liteVersion.rawValue || purchase.productId == Product.upgrade.rawValue {
                            product = .upgrade
                            break
                        }
                    }
                    
                    if #available(iOS 13.0, *) {
                        let keyWindow = UIApplication.shared.connectedScenes
                        .filter({$0.activationState == .foregroundActive})
                        .map({$0 as? UIWindowScene})
                        .compactMap({$0})
                        .first?.windows
                        .filter({$0.isKeyWindow}).first
                        
                        continuePurchasing(id: product, window: keyWindow)
                    }
                }
                
                return false
            default:
                return false
            }
        }
        
        TrueTimeClient.sharedInstance.start()
        
        observeUserDefaults()
        
        updatePyPiCache()
        
        #if !Xcode11
        if #available(iOS 14.0, *) {
            SidebarNavigation.footer = """
            \n\(MenuTableViewController.pytoVersion)
                
            Python \(Python.shared.version)
            """
        }
        #endif
        
        #if MAIN
        NotificationCenter.default.addObserver(forName: .init("NSWindowDidBecomeKeyNotification"), object: nil, queue: nil) { (notification) in
            self.appKitWindowDidBecomeKey(notification)
        }
        
        NotificationCenter.default.addObserver(forName: .init("NSWindowWillCloseNotification"), object: nil, queue: nil) { (notification) in
            self.appKitWindowWillClose(notification)
        }
        
        NotificationCenter.default.addObserver(forName: .init("AVCaptureSessionDidStartRunningNotification"), object: nil, queue: nil) { (notification) in
            
            Python.shared.captureSessionsPerThreads[Thread.current] = notification.object as? AVCaptureSession
        }
        
        shareBundleBookmarkData()
        #endif
        
        #else
        window = UIWindow()
        window?.backgroundColor = .white
        window?.rootViewController = UIStoryboard(name: "Splash Screen", bundle: Bundle(for: Python.self)).instantiateInitialViewController()
        window?.makeKeyAndVisible()
        DispatchQueue.main.asyncAfter(deadline: .now()+1) {
            let console = ConsoleViewController()
            console.modalPresentationStyle = .fullScreen
            console.modalTransitionStyle = .crossDissolve
            self.window?.rootViewController?.present(console, animated: true, completion: {
                console.textView.text = ""
                Python.shared.runningScripts = [AppDelegate.scriptToRun!]
                PyInputHelper.userInput[""] = "import console as __console__; script = __console__.run_script('\(AppDelegate.scriptToRun!)'); import code; code.interact(banner='', local=script)"
            })
        }
        #endif
        
        return true
    }
    
    #if MAIN
    
    #if !Xcode11
    @available(iOS 14.0, *)
    public func application(_ application: UIApplication, handlerFor intent: INIntent) -> Any? {
        if intent is RunScriptIntent {
            return RunScriptIntentHandler()
        } else if intent is RunCodeIntent {
            return RunCodeIntentHandler()
        } else if intent is StartHandlingWidgetsInAppIntent {
            return StartHandlingWidgetsInAppIntentHandler()
        } else {
            return nil
        }
    }
    #endif
    
    public func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: Error) {
        RemoteNotifications.deviceToken = nil
        RemoteNotifications.error = error.localizedDescription
    }
    
    public func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        RemoteNotifications.error = nil
        RemoteNotifications.deviceToken = deviceToken.map { String(format: "%02hhx", $0) }.joined()
    }
    
    @available(iOS 13.0, *)
    public func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        
        for session in sceneSessions {
            (((session.scene?.delegate as? UIWindowSceneDelegate)?.window??.rootViewController?.presentedViewController as? UINavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor?.save()
        }
    }
    
    public override func buildMenu(with builder: UIMenuBuilder) {
        setupMenu(builder: builder)
    }
    
    #endif
    
    // MARK: - Location manager delegate
    
    public func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let last = locations.last else {
            return
        }
        
        PyLocationHelper.latitude = Float(last.coordinate.latitude)
        PyLocationHelper.longitude = Float(last.coordinate.longitude)
        PyLocationHelper.altitude = Float(last.altitude)
    }
    
    // MARK: - User notification center delegate
    
    public func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        
        #if Xcode11
        completionHandler([.alert, .sound])
        #else
        if #available(iOS 14.0, *) {
            completionHandler([.banner, .sound])
        } else {
            completionHandler([.alert, .sound])
        }
        #endif
    }
    
    public func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        
        if response.actionIdentifier != UNNotificationDefaultActionIdentifier && response.actionIdentifier != UNNotificationDismissActionIdentifier {
            
            var link = response.actionIdentifier
            
            if let data = (response.notification.request.content.userInfo["data"] as? String)?.addingPercentEncoding(withAllowedCharacters: .urlQueryAllowed) {
                link = link.replacingOccurrences(of: "{}", with: data)
            }
            
            if let url = URL(string: link) {
                UIApplication.shared.open(url, options: [:]) { (_) in
                    completionHandler()
                }
            } else {
                completionHandler()
            }
        } else {
            if let _url = response.notification.request.content.userInfo["url"] as? String, let url = URL(string: _url) {
                UIApplication.shared.open(url, options: [:]) { (_) in
                    completionHandler()
                }
            } else {
                completionHandler()
            }
        }
    }
    
    // MARK: - Apple Watch
    
    #if MAIN
    var watchComplicationsHandlers = [String: ((Any?) -> Void)]()
    
    @available(iOS 14.0, *)
    @objc func callComplicationHandler(id: String, complication: PyComplication) {
        watchComplicationsHandlers[id]?(complication)
    }
    
    @objc var name = "AppDelegate"
    
    public override var description: String {
        return "AppDelegate"
    }
    
    @objc func getWatchScript() -> String? {
        return watchScript
    }
    
    @objc var descriptor: String?
    #endif
}
