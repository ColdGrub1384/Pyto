//
//  Document.swift
//  SeeLess
//
//  Created by Adrian Labbé on 15-09-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A document representing a Python project.
public class FolderDocument: UIDocument {
    
    /// The file browser using this folder.
    public var browser: FileBrowserViewController?
    
    /// Updates directories content on file browsers and check for warnings and errors.
    public func updateDirectory() {
        DispatchQueue.main.async {
            let navVC = self.browser?.navigationController
            for vc in (navVC?.viewControllers) ?? [] {
                (vc as? FileBrowserViewController)?.load()
            }
        }
    }
    
    // MARK: - Document
    
    public override func contents(forType typeName: String) throws -> Any {
        // Encode your document with an instance of NSData or NSFileWrapper
        return Data()
    }
    
    public override func load(fromContents contents: Any, ofType typeName: String?) throws {
        // Load your document from contents
    }
    
    public override func presentedItemDidChange() {
        super.presentedItemDidChange()
        
        updateDirectory()
    }
    
    public override func accommodatePresentedSubitemDeletion(at url: URL, completionHandler: @escaping (Error?) -> Void) {
        completionHandler(nil)
        
        updateDirectory()
    }
    
    public override func presentedSubitemDidAppear(at url: URL) {
        updateDirectory()
    }
    
    public override func presentedSubitemDidChange(at url: URL) {
        DispatchQueue.main.async {
            self.updateDirectory()
        }
    }
    
    public override func presentedSubitem(at oldURL: URL, didMoveTo newURL: URL) {
        updateDirectory()
    }
}

