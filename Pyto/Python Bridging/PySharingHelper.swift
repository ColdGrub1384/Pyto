//
//  PySharingHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/10/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import GCDWebServer
import SafariServices

/// A class accessible by Rubicon to share items and pick documents..
@objc class PySharingHelper: NSObject {
    
    /// Presents the share sheet for sharing given items in the main thread.
    ///
    /// - Parameters:
    ///     - items: Items to share with the picker.
    @objc static func share(_ items: [Any]) {
        DispatchQueue.main.async {
            let activityVC = UIActivityViewController(activityItems: items, applicationActivities: nil)
            activityVC.popoverPresentationController?.sourceView = PyContentViewController.shared?.tabBarController?.tabBar
            activityVC.popoverPresentationController?.sourceRect = activityVC.popoverPresentationController?.sourceView?.bounds ?? .zero
            PyContentViewController.shared?.present(activityVC, animated: true, completion: nil)
        }        
    }
    
    /// Presents a file picker with given settings in the main thread.
    ///
    /// - Parameters:
    ///     - filePicker: Python representation of the file picker.
    @objc static func presentFilePicker(_ filePicker: PyFilePicker) {
        DispatchQueue.main.async {
            let picker = UIDocumentPickerViewController(documentTypes: filePicker.fileTypes as [String], in: .open)
            picker.allowsMultipleSelection = filePicker.allowsMultipleSelection
            picker.delegate = filePicker
            PyContentViewController.shared?.present(picker, animated: true, completion: nil)
        }
    }
    
    /// - Returns: `true` if `url` is an `NSURL`.
    @objc static func isURL(_ url: Any) -> Bool {
        return (url is NSURL)
    }
    
    /// Installs a Home Screen shortcut for current editing script.
    ///
    /// - Parameters:
    ///     - name: Name of the icon.
    ///     - id: ID of the profile.
    @objc static func installShortcut(name: String, id: String) {
        DispatchQueue.main.async {
            guard let mobileconfig = Bundle.main.url(forResource: "Shortcut", withExtension: "mobileconfig"), var xml = try? String(contentsOf: mobileconfig) else {
                return
            }
            guard let editor = ((UIApplication.shared.keyWindow?.rootViewController?.presentedViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.viewControllers.first as? EditorViewController else {
                return
            }
            xml = xml.replacingOccurrences(of: "<Name>", with: name)
            xml = xml.replacingOccurrences(of: "<ID>", with: id)
            guard let page = Bundle.main.url(forResource: "Shortcut", withExtension: "html"), var pageSource = try? String(contentsOf: page) else {
                return
            }
            pageSource = pageSource.replacingOccurrences(of: "<Name>", with: name)
            pageSource = pageSource.replacingOccurrences(of: "<Code>", with: editor.textView.text.addingPercentEncoding(withAllowedCharacters: .urlQueryAllowed) ?? "")
            xml = xml.replacingOccurrences(of: "<URL>", with: "data:text/html,\(pageSource.addingPercentEncoding(withAllowedCharacters: .urlPathAllowed) ?? "")")
            
            let path = NSTemporaryDirectory()+"/Shortcut.mobileconfig"
            if FileManager.default.fileExists(atPath: path) {
                try? FileManager.default.removeItem(atPath: path)
            }
            
            if FileManager.default.createFile(atPath: path, contents: xml.data(using: .utf8), attributes: nil) {
                let server = GCDWebServer()
                server.addDefaultHandler(forMethod: "GET", request: GCDWebServerRequest.self, processBlock: { (_) -> GCDWebServerResponse? in
                    
                    defer {
                        server.stop()
                    }
                    
                    return GCDWebServerFileResponse(file: path)
                })
                server.start(withPort: 8080, bonjourName: nil)
                if let url = URL(string: "http://localhost:8080") {
                    UIApplication.shared.keyWindow?.rootViewController?.dismiss(animated: true, completion: {
                        UIApplication.shared.keyWindow?.topViewController?.present(SFSafariViewController(url: url), animated: true, completion: nil)
                    })
                }
            }
        }
    }
}
