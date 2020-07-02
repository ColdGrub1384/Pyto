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
    
    /// Opens a document after the scene is shown.
    ///
    /// - Parameters:
    ///     - url: The URL to open.
    ///     - run: A boolean indicating whether the script should be executed.
    ///     - isShortcut: A boolean indicating whether the script is executed from Shortcuts.
    func openDocument(at url: URL, run: Bool, isShortcut: Bool) {
        _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { (timer) in
            if let doc = self.documentBrowserViewController {
                doc.revealDocument(at: url, importIfNeeded: false) { (url_, _) in
                    doc.openDocument(url_ ?? url, run: run)
                }
                timer.invalidate()
            }
        })
    }
    
    /// Continues the given user activity.
    func continueActivity(_ userActivity: NSUserActivity) {
        let root = window?.rootViewController
        
        if root?.presentedViewController != nil {
            root?.dismiss(animated: true, completion: {
                self.continueActivity(userActivity)
            })
            return
        }
        
        if let data = userActivity.userInfo?["bookmarkData"] as? Data {
            
            //
            // Continue editing a script
            //
            
            do {
                var isStale = false
                let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
                openDocument(at: url, run: false, isShortcut: false)
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
                
                if let arguments = userActivity.userInfo?["arguments"] as? [String] {
                    Python.shared.args = NSMutableArray(array: arguments)
                    UserDefaults.standard.set(arguments, forKey: "arguments\(url.path.replacingOccurrences(of: "//", with: "/"))")
                }
                
                openDocument(at: url, run: true, isShortcut: true)
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
            openDocument(at: fileURL, run: true, isShortcut: true)
        } else {
            print("Invalid shortcut!")
        }
    }
    
    /// Restores the given user activity.
    @available(iOS 14.0, *)
    func restoreActivity(_ restorationActivity: NSUserActivity, session: UISceneSession) {
       
        guard let sceneStateData = restorationActivity.userInfo?["sceneState"] as? Data else {
            return
        }
        
        do {
            let sceneState = try JSONDecoder().decode(SceneState.self, from: sceneStateData)
            
            var url: URL?
            switch sceneState.selection {
            case .recent(let _url):
                url = _url
            default:
                break
            }
            
            sceneStateStore.sceneState = sceneState
            
            _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { (timer) in
                if let doc = self.documentBrowserViewController, doc.view.window != nil {
                    let sidebar = doc.makeSidebarNavigation(url: url)
                    let vc = UIHostingController(rootView: sidebar)
                    vc.modalPresentationStyle = .fullScreen
                    vc.modalTransitionStyle = .crossDissolve
                    sidebar.viewControllerStore.vc = vc
                    
                    doc.present(vc, animated: true, completion: nil)
                    timer.invalidate()
                }
            })
        } catch {
            print(error.localizedDescription)
        }
    }
    
    // MARK: - Scene delegate
    
    func stateRestorationActivity(for scene: UIScene) -> NSUserActivity? {
        
        do {
            let data = try JSONEncoder().encode(sceneStateStore.sceneState)
            
            let activity = NSUserActivity(activityType: "pyto.stateRestoration")
            activity.addUserInfoEntries(from: ["sceneState":data])
            return activity
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
}
