//
//  PySharingHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/10/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices

/// A class accessible by Rubicon to share items and pick documents..
@objc class PySharingHelper: NSObject {
    
    static var semaphore: DispatchSemaphore?
    
    private static var itemsToShare = [Any]()
    
    /// Presents the share sheet for sharing given items in the main thread.
    ///
    /// - Parameters:
    ///     - items: Items to share with the picker.
    @objc static func share(_ items: [Any]) {
        
        itemsToShare = items
        
        let semaphore = DispatchSemaphore(value: 0)
        
        #if WIDGET
        let visibles = [ConsoleViewController.visible ?? ConsoleViewController()]
        #else
        let visibles = ConsoleViewController.visibles
        #endif
        
        for console in visibles {
            DispatchQueue.main.async {
                let activityVC = UIActivityViewController(activityItems: itemsToShare, applicationActivities: nil)
                activityVC.popoverPresentationController?.sourceView = console.view
                activityVC.popoverPresentationController?.sourceRect = activityVC.popoverPresentationController?.sourceView?.bounds ?? .zero
                console.present(activityVC, animated: true, completion: {
                    semaphore.signal()
                })
            }
        }
        
        if !Thread.current.isMainThread {
            semaphore.wait()
        }
    }
    
    /// Presents a file picker with given settings in the main thread.
    ///
    /// - Parameters:
    ///     - filePicker: Python representation of the file picker.
    ///     - scriptPath: The script that called this function.
    @objc static func presentFilePicker(_ filePicker: PyFilePicker, scriptPath: String?) {
        semaphore = DispatchSemaphore(value: 0)
        DispatchQueue.main.async {
            let picker = UIDocumentPickerViewController(documentTypes: (filePicker.fileTypes as? [String]) ?? [], in: .open)
            picker.allowsMultipleSelection = filePicker.allowsMultipleSelection
            picker.delegate = filePicker
            #if WIDGET
            ConsoleViewController.visible.present(picker, animated: true, completion: nil)
            #elseif !MAIN
            ConsoleViewController.visibles.first?.present(picker, animated: true, completion: nil)
            #else
            for console in ConsoleViewController.visibles {
                
                if scriptPath == nil {
                    (console.presentedViewController ?? console).present(picker, animated: true, completion: nil)
                    break
                }
                
                if console.editorSplitViewController?.editor.document?.fileURL.path == scriptPath {
                    (console.presentedViewController ?? console).present(picker, animated: true, completion: nil)
                    break
                }
            }
            #endif
        }
        semaphore?.wait()
    }
    
    /// - Returns: `true` if `url` is an `NSURL`.
    @objc static func isURL(_ url: Any) -> Bool {
        return (url is NSURL)
    }
    
    #if !WIDGET
    /// Opens the given URL.
    ///
    /// - Parameters:
    ///     - url: The URL to open.
    @objc static func openURL(_ url: URL) {
        DispatchQueue.main.async {
            UIApplication.shared.open(url, options: [:], completionHandler: nil)
        }
    }
    #endif
}
