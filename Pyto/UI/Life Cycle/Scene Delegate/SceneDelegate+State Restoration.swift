//
//  SceneDelegate+State Restoration.swift
//  Pyto
//
//  Created by Emma Labbé on 02-07-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
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
            
            if sidebarSplitViewController == nil {
                DispatchQueue.main.asyncAfter(deadline: .now()+0.1) { [weak self] in
                    self?.continueActivity(userActivity)
                }
            } else {
                do {
                    sidebarSplitViewController?.restore(sceneState: try JSONDecoder().decode(SceneState.self, from: sceneStateData))
                } catch {
                    print(error.localizedDescription)
                }
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
                    UserDefaults.standard.set(arguments, forKey: "arguments\(url.path.replacingOccurrences(of: "//", with: "/"))")
                }
                
                openDocument(at: url, run: true, folder: nil, isShortcut: true)
            } catch {
                let alert = UIAlertController(title: NSLocalizedString("errors.errorReadingFile", comment: "The title of the alert shown when a script cannot be read"), message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: NSLocalizedString("ok", comment: "'Ok' button"), style: .cancel, handler: nil))
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
        do {
            let activity = NSUserActivity(activityType: "pyto.stateRestoration")
            
            guard let directoryBookmarkData = try sidebarSplitViewController?.fileBrowser.directory.bookmarkData() else {
                return nil
            }
            
            let section: SceneState.Section?
            
            let vc = (sidebarSplitViewController?.viewController(for: sidebarSplitViewController?.isCollapsed == true ? .compact : .secondary) as? UINavigationController)?.viewControllers.first
            switch vc {
                
            case is REPLViewController:
                section = .repl
            
            case is RunModuleViewController:
                section = .runModule
            
            case is UIHostingController<PyPiView>:
                section = .pypi
            
            case is ModulesTableViewController:
                section = .loadedModules
            
            case is UIHostingController<SamplesNavigationView>:
                section = .examples
            
            case is DocumentationViewController:
                section = .documentation
            
            case is EditorSplitViewController:
                section = .editor(try (vc as! EditorSplitViewController).editor!.document!.fileURL.bookmarkData())
                
            default:
                section = nil
            }
            
            activity.addUserInfoEntries(from: ["sceneState": try JSONEncoder().encode(SceneState(directoryBookmarkData: directoryBookmarkData, section: section))])
            
            return activity
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
}
