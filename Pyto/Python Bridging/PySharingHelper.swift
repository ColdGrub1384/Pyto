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
    
    /// Presents the share sheet for sharing given items in the main thread.
    ///
    /// - Parameters:
    ///     - items: Items to share with the picker.
    @objc static func share(_ items: [Any]) {
        DispatchQueue.main.async {
            let activityVC = UIActivityViewController(activityItems: items, applicationActivities: nil)
            activityVC.popoverPresentationController?.sourceView = ConsoleViewController.visible?.view
            activityVC.popoverPresentationController?.sourceRect = activityVC.popoverPresentationController?.sourceView?.bounds ?? .zero
            UIApplication.shared.keyWindow?.topViewController?.present(activityVC, animated: true, completion: nil)
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
            UIApplication.shared.keyWindow?.topViewController?.present(picker, animated: true, completion: nil)
        }
    }
    
    /// - Returns: `true` if `url` is an `NSURL`.
    @objc static func isURL(_ url: Any) -> Bool {
        return (url is NSURL)
    }
}
