//
//  PyFilePicker.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/10/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class for representing an `UIDocumentPickerViewController` settings to be used by the Python API.
@objc public class PyFilePicker: NSObject, UIDocumentPickerDelegate {
    
    /// The code to execute when files where picked.
    @objc public var completion: (([NSURL]) -> Void)?
    
    /// Document types that can be opened.
    @objc public var fileTypes = [NSString]()
    
    /// Allow multiple selection or not.
    @objc public var allowsMultipleSelection = false
    
    // MARK: - Document picker delegate
    
    public func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        self.completion?(urls as [NSURL])
    }
}
