//
//  InterfaceDocument.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 05-07-22.
//

import UIKit
import UniformTypeIdentifiers

extension UTType {
    
    /// An interface builder view.
    static var interfaceBuilderView: Self {
        UTType(exportedAs: "interfacebuilder.view")
    }
}

/// A PytoUI document.
public class InterfaceDocument: UIDocument {
    
    static var currentlyDecodingURL: URL?
    
    /// The data of the document.
    public var interfaceModel: InterfaceModel!
    
    /// Creates an empty document at the given file URL.
    ///
    /// - Parameters:
    ///     - fileURL: The URL of the file. Can exist or not.
    public static func createEmptyDocument(at fileURL: URL) throws {
        let data = try JSONEncoder().encode(InterfaceModel())
        try data.write(to: fileURL)
    }
    
    // MARK: - Document
    
    private func load(contents: Any) throws {
                
        guard let data = contents as? Data else {
            // This would be a developer error.
            fatalError("*** \(contents) is not an instance of NSData.***")
        }
        
        Self.currentlyDecodingURL = fileURL
        do {
            interfaceModel = try JSONDecoder().decode(InterfaceModel.self, from: data)
            Self.currentlyDecodingURL = nil
        } catch {
            Self.currentlyDecodingURL = nil
            throw error
        }
    }
    
    public override func save(to url: URL, for saveOperation: UIDocument.SaveOperation, completionHandler: ((Bool) -> Void)? = nil) {
        
        do {
            try JSONEncoder().encode(interfaceModel).write(to: url)
            completionHandler?(true)
        } catch {
            completionHandler?(false)
        }
    }
        
    private func makeData() throws -> Data {
        try JSONEncoder().encode(interfaceModel)
    }
    
    public override func contents(forType typeName: String) throws -> Any {
        try makeData()
    }
    
    public override func load(fromContents contents: Any, ofType typeName: String?) throws {
        try load(contents: contents)
    }
}
