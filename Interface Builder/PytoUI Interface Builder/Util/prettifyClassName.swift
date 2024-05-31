//
//  prettifyClassName.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 22-06-22.
//

import Foundation

/// Removes the `UI` prefix from a class name and splits it into multiple words.
func prettifyClassName(_ className: String) -> String {
    var name = className.components(separatedBy: ".").last ?? className
    if name.hasPrefix("UI") {
        name.removeFirst()
        name.removeFirst()
    }
    
    var newName = ""
    for char in name {
        if newName.lowercased() != newName && (String(char).uppercased() == String(char)) {
            newName.append(" ")
        }
        newName.append(char)
    }
    
    if newName != "Text View" && !newName.hasSuffix("Table View") {
        newName = newName.replacingOccurrences(of: " View", with: "")
    }
    
    return newName.replacingOccurrences(of: "Interface Builder ", with: "")
}
