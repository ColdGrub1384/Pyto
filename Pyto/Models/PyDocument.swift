//
//  PyDocument.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

#if os(iOS)
import UIKit

typealias Document = UIDocument
#else
import Cocoa

typealias Document = NSDocument
#endif

/// Errors opening the document.
enum PyDocumentError: Error {
    case unableToParseText
    case unableToEncodeText
}

/// A document representing a Python script.
class PyDocument: Document {
    
    /// The text of the Python script to save.
    var text = ""
    
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
    
    #if os(iOS)
    
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
    
    #else
    
    override func makeWindowControllers() {
        // Returns the Storyboard that contains your Document window.
        let storyboard = NSStoryboard(name: NSStoryboard.Name("Main"), bundle: nil)
        let windowController = storyboard.instantiateController(withIdentifier: NSStoryboard.SceneIdentifier("Document Window Controller")) as! NSWindowController
        if !windowController.isWindowLoaded {
            windowController.loadWindow()
        }
        (windowController.contentViewController as? EditorViewController)?.document = self
        self.addWindowController(windowController)
    }
    
    override func data(ofType typeName: String) throws -> Data {
        
        do {
            return try makeData()
        } catch {
            throw error
        }
    }
    
    override func read(from data: Data, ofType typeName: String) throws {
        
        do {
            try load(contents: data)
        } catch {
            throw error
        }
    }
    
    #endif
}
