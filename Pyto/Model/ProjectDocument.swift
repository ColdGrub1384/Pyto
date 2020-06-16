//
//  Document.swift
//  SeeLess
//
//  Created by Adrian Labbé on 15-09-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A document representing a Python project.
class FolderDocument: UIDocument {
    
    /// The file browser using this folder.
    var browser: FileBrowserViewController?
    
    /// Updates directories content on file browsers and check for warnings and errors.
    func updateDirectory() {
        DispatchQueue.main.async {
            let navVC = self.browser?.navigationController
            for vc in (navVC?.viewControllers) ?? [] {
                (vc as? FileBrowserViewController)?.load()
            }
        }
    }
    
    // MARK: - Document
    
    override func contents(forType typeName: String) throws -> Any {
        // Encode your document with an instance of NSData or NSFileWrapper
        return Data()
    }
    
    override func load(fromContents contents: Any, ofType typeName: String?) throws {
        // Load your document from contents
    }
    
    override func presentedItemDidChange() {
        super.presentedItemDidChange()
        
        updateDirectory()
    }
    
    override func accommodatePresentedSubitemDeletion(at url: URL, completionHandler: @escaping (Error?) -> Void) {
        completionHandler(nil)
        
        updateDirectory()
    }
    
    override func presentedSubitemDidAppear(at url: URL) {
        updateDirectory()
    }
    
    override func presentedSubitemDidChange(at url: URL) {
        DispatchQueue.main.async {
            self.updateDirectory()
        }
    }
    
    override func presentedSubitem(at oldURL: URL, didMoveTo newURL: URL) {
        updateDirectory()
    }
}

