//
//  PyFilePicker.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/10/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class for representing an `UIDocumentPickerViewController` settings to be used by the Python API.
@objc class PyFilePicker: NSObject, UIDocumentPickerDelegate {
    
    /// The code to execute when files where picked.
    @objc var completion: (() -> Void)?
    
    /// Document types that can be opened.
    @objc var fileTypes = NSArray()
    
    /// Allow multiple selection or not.
    @objc var allowsMultipleSelection = false
    
    @objc static private(set) var urls: NSArray?
    
    // MARK: - Document picker delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        
        for url in urls {
            _ = url.startAccessingSecurityScopedResource()
        }
        
        PyFilePicker.urls = NSArray(array: urls)
        Python.shared.queue.async {
            PySharingHelper.semaphore?.signal()
            self.completion?()
        }
    }
    
    func documentPickerWasCancelled(_ controller: UIDocumentPickerViewController) {
        PyFilePicker.urls = NSArray(array: [])
        Python.shared.queue.async {
            PySharingHelper.semaphore?.signal()
        }
    }
}
