//
//  Padding.swift
//  Pyto
//
//  Created by Emma Labbé on 18-09-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import Foundation

@objc class WidgetPadding: NSObject, Codable {
    
    @objc var top: Float = 0
    
    @objc var bottom: Float = 0
    
    @objc var left: Float = 0
    
    @objc var right: Float = 0
    
    override init() {}
    
    enum Keys: CodingKey {
        
        case top
        case bottom
        case left
        case right
    }
    
    required init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Keys.self)
        top = try container.decode(Float.self, forKey: .top)
        bottom = try container.decode(Float.self, forKey: .bottom)
        left = try container.decode(Float.self, forKey: .left)
        right = try container.decode(Float.self, forKey: .right)
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(top, forKey: .top)
        try container.encode(bottom, forKey: .bottom)
        try container.encode(left, forKey: .left)
        try container.encode(right, forKey: .right)
    }
}
