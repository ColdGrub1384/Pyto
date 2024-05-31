//
//  InterfaceModel.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 02-07-22.
//

import UIKit

/// The model of an interface.
public struct InterfaceModel: Codable {
    
    /// A conncection to Python code.
    public struct Connection: Codable {
        
        /// The attribute to set. E.g: `did_appear`.
        public var attributeName: String
        
        /// The name of the function to be used.
        public var functionName: String
    }
    
    /// Custom size properties.
    public struct ViewCustomSizeHolder: Codable {
        
        /// Custom width.
        public var width = [Int: CGFloat]()
        
        /// Custom height.
        public var height = [Int: CGFloat]()
        
        /// Flexible width.
        public var flexibleWidth = [Int: Bool]()
        
        /// Flexible height.
        public var flexibleHeight = [Int: Bool]()
    }
    
    /// Connections to Python code, per view tag. The first item is the name of the Python property to be set, e.g: `did_appear` and the function name.
    public typealias Connections = [Int: [Connection]]
    
    /// A structure holding the names of each view per tag.
    public struct NamesHolder: Codable {
        
        /// All the names per tag.
        public var names = [Int: String]()
        
        /// All the custom class names per tag.
        public var customClassNames = [Int: String]()
        
        /// Sets the name of a view with the given tag.
        ///
        /// - Parameters:
        ///     - name: The new name of the view.
        ///     - tag: The tag corresponding to the view.
        public mutating func set(name: String, for tag: Int) {
            names[tag] = name
        }

        /// Returns the name of a view with the given tag.
        ///
        /// - Parameters:
        ///     - tag: The tag corresponding to the view.
        public func name(for tag: Int) -> String? {
            names[tag]
        }
        
        /// Sets the custom class name of a view with the given tag.
        ///
        /// - Parameters:
        ///     - customClassName: The new custom class name of the view.
        ///     - tag: The tag corresponding to the view.
        public mutating func set(customClassName: String, for tag: Int) {
            guard !customClassName.isEmpty else {
                customClassNames[tag] = nil
                return
            }
            
            customClassNames[tag] = customClassName
        }

        /// Returns the custom class name of a view with the given tag.
        ///
        /// - Parameters:
        ///     - tag: The tag corresponding to the view.
        public func customClassName(for tag: Int) -> String? {
            customClassNames[tag]
        }
        
        public init(from decoder: Decoder) throws {
            let container = try decoder.container(keyedBy: CodingKeys.self)
            names = try container.decode([Int: String].self, forKey: .names)
            do {
                customClassNames = try container.decode([Int: String].self, forKey: .customClassNames)
            } catch {
                customClassNames = [:]
            }
        }
        
        init() {
            
        }
    }
    
    ///Orientations for preview.
    public enum Orientation: Codable {
        
        /// Portrait.
        case portrait
        
        /// Landscape.
        case landscape
    }
    
    /// The selected device for preview.
    public var selectedDevice = DeviceLayout.iPhone13Mini
    
    /// Whether dark mode is enabled or not.
    public var darkMode = false
    
    /// The current orientation for preview.
    public var orientation = Orientation.portrait
    
    /// The content navigation controller.
    public var navigationController: UINavigationController!
    
    /// A structure holding the names of each view per tag.
    public var names = NamesHolder()
    
    /// Connections to Python code.
    public var connections = Connections()
    
    /// Custom size properties.
    public var customSize = ViewCustomSizeHolder()
    
    /// Corner radius.
    public var cornerRadius = [Int:Float]()
    
    public init() {}
    
    // MARK: - Codable
    
    public enum CodingKeys: CodingKey {
        case selectedDevice
        case darkMode
        case orientation
        case view
        case names
        case connections
        case customSize
        case cornerRadius
    }
    
    public init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        selectedDevice = try container.decode(DeviceLayout.self, forKey: .selectedDevice)
        darkMode = try container.decode(Bool.self, forKey: .darkMode)
        orientation = try container.decode(Orientation.self, forKey: .orientation)
        names = (try? container.decode(NamesHolder.self, forKey: .names)) ?? NamesHolder()
        connections = (try? container.decode(Connections.self, forKey: .connections)) ?? Connections()
        customSize = (try? container.decode(ViewCustomSizeHolder.self, forKey: .customSize)) ?? ViewCustomSizeHolder()
        cornerRadius = (try? container.decode([Int:Float].self, forKey: .cornerRadius)) ?? [:]
        
        let viewData = try container.decode(Data.self, forKey: .view)
        navigationController = NSKeyedUnarchiver.unarchiveObject(with: viewData) as? UINavigationController // TODO: Use non deprecated API
    }
    
    public func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        try container.encode(selectedDevice, forKey: .selectedDevice)
        try container.encode(darkMode, forKey: .darkMode)
        try container.encode(orientation, forKey: .orientation)
        try container.encode(names, forKey: .names)
        try container.encode(connections, forKey: .connections)
        try container.encode(customSize, forKey: .customSize)
        try container.encode(cornerRadius, forKey: .cornerRadius)
        
        let viewData: Data?
        if let navigationController = navigationController {
            viewData = try NSKeyedArchiver.archivedData(withRootObject: navigationController, requiringSecureCoding: false)
        } else {
            viewData = nil
        }
        try container.encode(viewData, forKey: .view)
    }
}
