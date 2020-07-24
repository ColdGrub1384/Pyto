//
//  CodablePythonObject.swift
//  Pyto
//
//  Created by Adrian Labbé on 22-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

/// A representation of a Python object.
struct CodablePythonObject: Codable {
    
    /// The value of the object casted as string.
    var description: String
        
    /// The address where the object is stored in the `__shortcuts_store__` module
    var address: String
    
    /// Returns an Intent object.
    var shortcutsObject: PythonObject {
        do {
            let encoder = JSONEncoder()
            encoder.outputFormatting = .prettyPrinted
            let data = try encoder.encode(self)
            let str = String(data: data, encoding: .utf8) ?? ""
            return PythonObject(identifier: address, display: str)
        } catch {
            return PythonObject(identifier: nil, display: "None")
        }
    }
}
