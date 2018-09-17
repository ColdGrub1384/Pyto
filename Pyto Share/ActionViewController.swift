//
//  ActionViewController.swift
//  Pyto Share
//
//  Created by Adrian Labbe on 9/16/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

class ActionViewController: PyContentViewController, UIDocumentPickerDelegate {
    
    /// Load extension's items and pass them to the Python API.
    func loadItems() {
        
        PyExtensionContext.items = []
        
        // Load items
        guard let context = extensionContext else {
            return
        }
        
        guard let items = context.inputItems as? [NSExtensionItem] else {
            return
        }
        
        for item in items {
            for attachment in item.attachments ?? [] {
                if attachment.hasItemConformingToTypeIdentifier("public.item") {
                    attachment.loadItem(forTypeIdentifier: "public.item", options: nil) { (item, nil) in
                        if let item = item {
                            PyExtensionContext.items?.append(item)
                        }
                    }
                }
            }
        }
    }
    
    // MARK: - Content view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        loadItems()
        
        /// The path of the Python home directory.
        guard let pythonHome = Bundle.main.path(forResource: "Library/Python.framework/Resources", ofType: "") else {
            fatalError("python: python home directory doesn't exist")
        }
        
        putenv("PYTHONOPTIMIZE=".cValue)
        putenv("PYTHONDONTWRITEBYTECODE=1".cValue)
        putenv("TMP=\(NSTemporaryDirectory())".cValue)
        putenv("PYTHONHOME=\(pythonHome)".cValue)
        
        Py_SetPythonHome(pythonHome.cWchar_t)
        Py_Initialize()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let picker = UIDocumentPickerViewController(documentTypes: ["public.python-script"], in: .import)
        picker.delegate = self
        picker.allowsMultipleSelection = false
        present(picker, animated: false, completion: nil)
    }
    
    // MARK: - Document picker delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        Py_SetProgramName(urls[0].lastPathComponent.cWchar_t)
        Python.shared.runScript(at: urls[0])
    }
    
    func documentPickerWasCancelled(_ controller: UIDocumentPickerViewController) {
        extensionContext?.completeRequest(returningItems: nil, completionHandler: nil)
    }
}
