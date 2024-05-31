//
//  InspectorImage.swift
//  InterfaceBuilder
//
//  Created by Emma on 21-08-22.
//

import Foundation

/// An image selected from the inspector-
enum InspectorImage: Codable, Equatable {
    
    /// An SF Symbol.
    case symbol(String)
    
    /// The file path of an image relative to the pytoui file path.
    case path(String)
    
    /// The data of an image.
    case data(Data)
}
