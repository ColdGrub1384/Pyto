//
//  ActionViewController.swift
//  Pyto Share
//
//  Created by Adrian Labbe on 9/16/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

class ActionViewController: UIViewController, UIDocumentPickerDelegate {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        allowsMultipleSelection = false
        delegate = self
    }
    
    // MARK: - Document picker delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        
    }
    
    func documentPickerWasCancelled(_ controller: UIDocumentPickerViewController) {
        extensionContext?.completeRequest(returningItems: nil, completionHandler: nil)
    }
}
