//
//  SelectedSection.swift
//  Pyto
//
//  Created by Emma Labbé on 02-07-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

// MARK: Selected section

/// An enum representing selected sections in the sidebar.
public enum SelectedSection: Hashable {
            
    /// A recent file with its URL.
    case recent(URL)
    
    /// The REPL
    case repl
    
    /// Run module
    case runModule
    
    /// PyPI
    case pypi
    
    /// Examples
    case examples
    
    /// Documentation
    case documentation
    
    /// LoadedModules
    case loadedModules
    
    /// Settings
    case settings
    
    /// Projects
    case projects
}

extension SelectedSection: Codable {
    
    enum Key: CodingKey {
        case rawValue
    }
        
    enum CodingError: Error {
        case unknownValue
    }
        
    public init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Key.self)
        
        do {
            let rawValue = try container.decode(Int.self, forKey: .rawValue)
            switch rawValue {
            case 0:
                self = .repl
            case 1:
                self = .runModule
            case 2:
                self = .pypi
            case 3:
                self = .examples
            case 4:
                self = .documentation
            case 5:
                self = .loadedModules
            case 6:
                self = .settings
            case 7:
                self = .projects
            default:
                throw CodingError.unknownValue
            }
        } catch {
            let data = try container.decode(Data.self, forKey: .rawValue)
            var isStale = false
            
            let url = try URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale)
            _ = url.startAccessingSecurityScopedResource()
            self = .recent(url)
        }
    }
        
    public func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Key.self)
        switch self {
        case .repl:
            try container.encode(0, forKey: .rawValue)
        case .runModule:
            try container.encode(1, forKey: .rawValue)
        case .pypi:
            try container.encode(2, forKey: .rawValue)
        case .examples:
            try container.encode(3, forKey: .rawValue)
        case .documentation:
            try container.encode(4, forKey: .rawValue)
        case .loadedModules:
            try container.encode(5, forKey: .rawValue)
        case .settings:
            try container.encode(6, forKey: .rawValue)
        case .projects:
            try container.encode(7, forKey: .rawValue)
        case .recent(let url):
            try container.encode(url.bookmarkData(), forKey: .rawValue)
        }
    }
}
