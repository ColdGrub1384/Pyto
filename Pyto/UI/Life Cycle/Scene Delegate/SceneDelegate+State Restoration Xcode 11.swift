//
//  SceneDelegate+State Restoration Xcode 11.swift
//  Pyto
//
//  Created by Adrian Labbé on 05-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//
//
// Backward compatibility with Xcode 11
//

import UIKit

extension SceneDelegate {
    
    /// Continues the given user activity.
    func continueActivity(_ userActivity: NSUserActivity) {
       
        let root = window?.rootViewController
        
        func runScript() {
            if let data = userActivity.userInfo?["bookmarkData"] as? Data {
                do {
                    var isStale = false
                    let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                    
                    _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
                        
                        guard let self = self else {
                            return
                        }
                        
                        if let doc = self.documentBrowserViewController {
                            doc.revealDocument(at: url, importIfNeeded: false) { (url_, _) in
                                doc.openDocument(url_ ?? url, run: false)
                            }
                            timer.invalidate()
                        }
                    })
                } catch {
                    print(error.localizedDescription)
                }
            } else if let path = userActivity.userInfo?["filePath"] as? String {
                
                let url = URL(fileURLWithPath: path.replacingFirstOccurrence(of: "iCloud/", with: (DocumentBrowserViewController.iCloudContainerURL?.path ?? DocumentBrowserViewController.localContainerURL.path)+"/"), relativeTo: DocumentBrowserViewController.localContainerURL)
                
                if FileManager.default.fileExists(atPath: url.path) {
                    
                    _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
                        if let doc = self?.documentBrowserViewController {
                            doc.revealDocument(at: url, importIfNeeded: true) { (url_, _) in
                                doc.openDocument(url_ ?? url, run: true)
                            }
                            timer.invalidate()
                        }
                    })
                } else {
                    let alert = UIAlertController(title: Localizable.Errors.errorReadingFile, message: nil, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                    root?.present(alert, animated: true, completion: nil)
                }
            } else if let data = (userActivity.userInfo?["filePath"] as? Data) ?? (userActivity.interaction?.intent as? RunScriptIntent)?.script?.data {
                do {
                    var isStale = false
                    let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                    
                    if let arguments = userActivity.userInfo?["arguments"] as? [String] ?? (userActivity.interaction?.intent as? RunScriptIntent)?.arguments {
                        Python.shared.args = NSMutableArray(array: arguments)
                        UserDefaults.standard.set(arguments, forKey: "arguments\(url.path.replacingOccurrences(of: "//", with: "/"))")
                    }
                    
                    _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
                        if let doc = self?.documentBrowserViewController {
                            doc.revealDocument(at: url, importIfNeeded: true) { (url_, _) in
                                doc.openDocument(url_ ?? url, run: true, isShortcut: true)
                            }
                            timer.invalidate()
                        }
                    })
                } catch {
                    let alert = UIAlertController(title: Localizable.Errors.errorReadingFile, message: error.localizedDescription, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                    root?.present(alert, animated: true, completion: nil)
                }
            } else if let code = userActivity.userInfo?["code"] as? String {
                let fileURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent("Shortcuts.py")
                if FileManager.default.fileExists(atPath: fileURL.path) {
                    try? FileManager.default.removeItem(at: fileURL)
                }
                
                if let arguments = userActivity.userInfo?["arguments"] as? [String] {
                    Python.shared.args = NSMutableArray(array: arguments)
                    UserDefaults.standard.set(arguments, forKey: "arguments\(fileURL.path.replacingOccurrences(of: "//", with: "/"))")
                }
                
                FileManager.default.createFile(atPath: fileURL.path, contents: code.data(using: .utf8), attributes: nil)
                _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
                    if let doc = self?.documentBrowserViewController {
                        doc.openDocument(fileURL, run: true, isShortcut: true)
                        timer.invalidate()
                    }
                })
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
    
    /// Restores the given user activity.
    func restoreActivity(_ restorationActivity: NSUserActivity, session: UISceneSession) {
       
        if let console = restorationActivity.userInfo?["replConsole"] as? String {
            guard let navVC = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "repl") as? UINavigationController else {
                return
            }
            
            guard let repl = navVC.viewControllers.first as? REPLViewController else {
                return
            }
            
            repl.loadViewIfNeeded()
            repl.console.print_(Notification(name: .init("Output"), object: console, userInfo: nil))
            
            repl.noBanner = true
            
            _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
                if let doc = self?.documentBrowserViewController, Python.shared.isSetup {
                    doc.present(navVC, animated: true, completion: nil)
                    timer.invalidate()
                }
            })
        } else if let data = restorationActivity.userInfo?["bookmarkData"] as? Data {
            do {
                var isStale = false
                let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                
                (window?.rootViewController as? DocumentBrowserViewController)?.documentURL = url
                
                if let folder = restorationActivity.userInfo?["folderBookmarkData"] as? Data {
                    let folderURL = try URL(resolvingBookmarkData: folder, bookmarkDataIsStale: &isStale)
                    let doc = FolderDocument(fileURL: folderURL)
                    doc.open(completionHandler: nil)
                    (self.window?.rootViewController as? DocumentBrowserViewController)?.folder = doc
                }
            } catch {
                print(error.localizedDescription)
            }
        } else if let className = restorationActivity.userInfo?["viewControllerClass"] as? String, let ViewController = NSClassFromString(className) as? UIViewController.Type {
            
            let navClassName = restorationActivity.userInfo?["navigationControllerClass"] as? String
            var NavigationController: UINavigationController.Type?
            if let className = navClassName {
                NavigationController = NSClassFromString(className) as? UINavigationController.Type
            }
            
            let blankVC = SceneDelegate.ViewController()
            blankVC.sceneSession = session
            if let navVC = NavigationController?.init() {
                navVC.viewControllers = [ViewController.init()]
                blankVC.viewControllerToPresent = navVC
            } else {
                blankVC.viewControllerToPresent = ViewController.init()
            }
            window?.rootViewController = blankVC
            
        } else if restorationActivity.userInfo?["filePath"] != nil {
            continueActivity(restorationActivity)
        }
    }
    
    // MARK: - Scene Delegate
    
    func stateRestorationActivity(for scene: UIScene) -> NSUserActivity? {
        
        if let presented = (scene.delegate as? UIWindowSceneDelegate)?.window??.topViewController as? EditorSplitViewController, let url = presented.editor?.document?.fileURL, !(presented is PipInstallerViewController), !(presented is RunModuleViewController) {
            
            if presented is REPLViewController {
                let activity = NSUserActivity(activityType: "stateRestoration")
                activity.userInfo?["replConsole"] = presented.console.textView.text
                return activity
            } else {
                do {
                    
                    let bookmarkData = try url.bookmarkData()

                    let activity = NSUserActivity(activityType: "stateRestoration")
                    activity.userInfo?["bookmarkData"] = bookmarkData
                    return activity
                } catch {
                    return nil
                }
            }
        } else if let splitVC = ((scene.delegate as? UIWindowSceneDelegate)?.window??.rootViewController?.presentedViewController as? EditorSplitViewController.ProjectSplitViewController), let editor = splitVC.editor, let folder = editor.folder, let url = editor.editor?.document?.fileURL {
            
            do {
                
                let bookmarkData = try url.bookmarkData()
                let folderBookmarkData = try folder.fileURL.bookmarkData()
                
                let activity = NSUserActivity(activityType: "stateRestoration")
                activity.userInfo?["bookmarkData"] = bookmarkData
                activity.userInfo?["folderBookmarkData"] = folderBookmarkData
                return activity
            } catch {
                return nil
            }
        } else if let vc = ((scene.delegate as? UIWindowSceneDelegate)?.window??.rootViewController as? ViewController)?.viewControllerToPresent {
            
            let ViewController = type(of: vc) as UIViewController.Type
            
            let activity = NSUserActivity(activityType: "stateRestoration")
            if ViewController is UINavigationController.Type, let visible = (vc as? UINavigationController)?.visibleViewController {
                activity.userInfo?["navigationControllerClass"] = NSStringFromClass(ViewController)
                activity.userInfo?["viewControllerClass"] = NSStringFromClass(type(of: visible))
            } else {
                activity.userInfo?["viewControllerClass"] = NSStringFromClass(ViewController)
            }
            return activity
        }
        
        return nil
    }
}
