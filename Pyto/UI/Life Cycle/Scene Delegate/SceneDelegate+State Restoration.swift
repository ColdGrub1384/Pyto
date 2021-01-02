//
//  SceneDelegate+State Restoration.swift
//  Pyto
//
//  Created by Adrian Labbé on 02-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import SwiftUI

extension SceneDelegate {
    
    /// Continues the given user activity.
    func continueActivity(_ userActivity: NSUserActivity) {
        let root = window?.rootViewController
        
        if root?.presentedViewController != nil {
            root?.dismiss(animated: true, completion: { [weak self] in
                self?.continueActivity(userActivity)
            })
            return
        }
        
        if let sceneStateData = userActivity.userInfo?["sceneState"] as? Data, #available(iOS 14.0, *) {
            
            do {
                let sceneState = try JSONDecoder().decode(SceneState.self, from: sceneStateData)
                
                if sceneState.selection == nil || sceneState.selection == .none {
                    return
                }
                
                var url: URL?
                switch sceneState.selection {
                case .recent(let _url):
                    url = _url
                default:
                    break
                }
                
                sceneStateStore.sceneState = sceneState
                
                _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { [weak self] (timer) in
                    
                    guard let self = self else {
                        return
                    }
                    
                    if let doc = self.documentBrowserViewController, doc.view.window != nil {
                        let sidebar = doc.makeSidebarNavigation(url: url, run: false, isShortcut: false, restoreSelection: true)
                        let vc = SidebarController(rootView: AnyView(sidebar))
                        vc.modalPresentationStyle = .fullScreen
                        vc.modalTransitionStyle = .crossDissolve
                        sidebar.viewControllerStore.vc = vc
                         
                        doc.present(vc, animated: true, completion: nil)
                    }
                    
                    timer.invalidate()
                })
            } catch {
                print(error.localizedDescription)
            }
            
        } else if let data = userActivity.userInfo?["bookmarkData"] as? Data {
            
            //
            // Continue editing a script
            //
            
            do {
                var isStale = false
                let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                
                var folder: URL?
                if let folderData = userActivity.userInfo?["directory"] as? Data {
                    folder = try URL(resolvingBookmarkData: folderData, bookmarkDataIsStale: &isStale)
                    _ = folder?.startAccessingSecurityScopedResource()
                }
                
                openDocument(at: url, run: false, folder: folder, isShortcut: false)
            } catch {
                print(error.localizedDescription)
            }
        } else if let data = (userActivity.userInfo?["filePath"] as? Data) ?? (userActivity.interaction?.intent as? RunScriptIntent)?.script?.data {
            
            //
            // Run script from Shortcuts
            //
            
            do {
                var isStale = false
                let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                
                if let arguments = (userActivity.userInfo?["arguments"] as? [String]) ?? (userActivity.interaction?.intent as? RunScriptIntent)?.arguments {
                    Python.shared.args = NSMutableArray(array: arguments)
                    UserDefaults.standard.set(arguments, forKey: "arguments\(url.path.replacingOccurrences(of: "//", with: "/"))")
                }
                
                openDocument(at: url, run: true, folder: nil, isShortcut: true)
            } catch {
                let alert = UIAlertController(title: Localizable.Errors.errorReadingFile, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                root?.present(alert, animated: true, completion: nil)
            }
        } else if let code = userActivity.userInfo?["code"] as? String {
            
            //
            // Run code from Shortcuts
            //
            
            let fileURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent("Shortcuts.py")
            if FileManager.default.fileExists(atPath: fileURL.path) {
                try? FileManager.default.removeItem(at: fileURL)
            }
            
            if let arguments = userActivity.userInfo?["arguments"] as? [String] {
                Python.shared.args = NSMutableArray(array: arguments)
                UserDefaults.standard.set(arguments, forKey: "arguments\(fileURL.path.replacingOccurrences(of: "//", with: "/"))")
            }
            
            FileManager.default.createFile(atPath: fileURL.path, contents: code.data(using: .utf8), attributes: nil)
            openDocument(at: fileURL, run: true, folder: nil, isShortcut: true)
        } else {
            print("Invalid shortcut!")
        }
    }
    
    /// Restores the given user activity.
    @available(iOS 14.0, *)
    func restoreActivity(_ restorationActivity: NSUserActivity, session: UISceneSession) {
       
        continueActivity(restorationActivity)
    }
    
    // MARK: - Scene delegate
    
    func stateRestorationActivity(for scene: UIScene) -> NSUserActivity? {
        
        guard !isiOSAppOnMac else {
            return nil
        }
        
        do {
            let activity = NSUserActivity(activityType: "pyto.stateRestoration")
            
            if isiOSAppOnMac, let splitVC = ((window?.rootViewController as? EditorSplitViewController.NavigationController) ?? (window?.rootViewController?.presentedViewController as? EditorSplitViewController.NavigationController))?.viewControllers.first as? EditorSplitViewController, let editor = splitVC.editor {
                activity.addUserInfoEntries(from: ["bookmarkData": try editor.document!.fileURL.bookmarkData()])
            }
            
            if let splitVC = documentBrowserViewController?.presentedViewController as? EditorSplitViewController.ProjectSplitViewController, let dir = ((splitVC.viewControllers.first as? UINavigationController)?.viewControllers.first as? FileBrowserViewController)?.directory {
                
                activity.addUserInfoEntries(from: ["directory": try dir.bookmarkData()])
                
                if let editor = ((splitVC.viewControllers.last as? UINavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor {
                    activity.addUserInfoEntries(from: ["bookmarkData": try editor.document!.fileURL.bookmarkData()])
                }
            } else {
                let data = try JSONEncoder().encode(sceneStateStore.sceneState)
                activity.addUserInfoEntries(from: ["sceneState":data])
            }
            
            return activity
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
}
