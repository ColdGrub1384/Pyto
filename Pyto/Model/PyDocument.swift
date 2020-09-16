//
//  PyDocument.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// Errors opening the document.
enum PyDocumentError: Error {
    case unableToParseText
    case unableToEncodeText
}

/// A document representing a Python script.
@objc class PyDocument: UIDocument {
    
    /// The text of the Python script to save.
    @objc var text = ""
    
    #if MAIN
    /// The editor that is editing this document.
    weak var editor: EditorViewController?
    #endif
    
    /// A boolean indicating whether `open(completionHandler:)` has been called for this instance.
    var hasBeenOpened = false
    
    private var storedModificationDate: Date? {
        didSet {
            print("Set modification date", self.storedModificationDate ?? "nil")
        }
    }
    
    /// Checks for conflicts and presents an alert if needed.
    ///
    /// - Parameters:
    ///     - viewController: The View controller where the conflicts resolver should be presented.
    ///     - completion: Code to call after the file is checked.
    func checkForConflicts(onViewController viewController: UIViewController, completion: (() -> Void)?) {
        #if MAIN
        if documentState == UIDocument.State.inConflict, let versions = NSFileVersion.unresolvedConflictVersionsOfItem(at: fileURL), versions.count > 1 {
            
            guard let resolver = UIStoryboard(name: "ConflictsResolver", bundle: Bundle.main).instantiateInitialViewController() as? ResolveConflictsTableViewController else {
                completion?()
                return
            }
            
            resolver.document = self
            resolver.versions = versions
            resolver.completion = completion
            
            let navVC = UINavigationController(rootViewController: resolver)
            navVC.modalPresentationStyle = .formSheet
            
            viewController.present(navVC, animated: true, completion: nil)
        } else {
            completion?()
        }
        #else
        completion?()
        #endif
    }
    
    private func load(contents: Any) throws {
        guard let data = contents as? Data else {
            // This would be a developer error.
            fatalError("*** \(contents) is not an instance of NSData.***")
        }
        
        guard let newText = String(data: data, encoding: .utf8) else {
            throw PyDocumentError.unableToParseText
        }
        
        text = newText
    }
    
    private func makeData() throws -> Data {
        guard let data = text.data(using: .utf8) else {
            throw PyDocumentError.unableToEncodeText
        }
        return data
    }
    
    override func contents(forType typeName: String) throws -> Any {
        
        do {
            return try makeData()
        } catch {
            throw error
        }
    }
    
    override func load(fromContents contents: Any, ofType typeName: String?) throws {
        do {
            try load(contents: contents)
        } catch {
            throw error
        }
    }
    
    override func open(completionHandler: ((Bool) -> Void)? = nil) {
        
        hasBeenOpened = true
        
        super.open { (success) in
            if self.storedModificationDate == nil {
                self.storedModificationDate = self.fileModificationDate
            }
            completionHandler?(success)
        }
    }
    
    // MARK: - File presenter
    
    #if MAIN
    override func presentedItemDidChange() {
        super.presentedItemDidChange()
        
        print(fileModificationDate ?? "nil")
        print(storedModificationDate ?? "nil")
        guard fileModificationDate != storedModificationDate else {
            return
        }
        
        storedModificationDate = fileModificationDate
        
        if let data = try? Data(contentsOf: fileURL) {
            try? load(fromContents: data, ofType: "public.python-script")
            DispatchQueue.main.async {
                if self.editor?.textView.text != self.text {
                    self.editor?.textView.text = self.text
                }
            }
        }
    }
    #endif
}
