//
//  PySharingHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/10/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class accessible by Rubicon to share items and pick documents..
@objc public class PySharingHelper: NSObject {
    
    /// Presents the share sheet for sharing given items in the main thread. The Python code is stopped until the sheet is closed.
    ///
    /// - Parameters:
    ///     - items: Items to share with the picker.
    @objc public static func share(_ items: [Any]) {
        DispatchQueue.main.async {
            let activityVC = UIActivityViewController(activityItems: items, applicationActivities: nil)
            activityVC.popoverPresentationController?.sourceView = PyContentViewController.shared?.tabBarController?.tabBar
            activityVC.popoverPresentationController?.sourceRect = activityVC.popoverPresentationController?.sourceView?.bounds ?? .zero
            UIApplication.shared.keyWindow?.topViewController?.present(activityVC, animated: true, completion: nil)
        }        
    }
    
    @objc public static func presentFilePicker(_ filePicker: PyFilePicker) {
        DispatchQueue.main.async {
            let picker = UIDocumentPickerViewController(documentTypes: filePicker.fileTypes as [String], in: .open)
            picker.allowsMultipleSelection = filePicker.allowsMultipleSelection
            picker.delegate = filePicker
            UIApplication.shared.keyWindow?.topViewController?.present(picker, animated: true, completion: nil)
        }
    }
}
