//
//  WidgetRow.swift
//  Pyto
//
//  Created by Emma Labbé on 25-07-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import UIKit

struct WidgetRow: Identifiable, Codable {

    struct RowContent: Codable {
        
        var content: [CodableWidgetComponent]
        
        var decodedContent: [WidgetComponent] {
            var decoded = [WidgetComponent]()
            
            for component in content {
                if let obj = component.makeObject() {
                    decoded.append(obj)
                }
            }
            
            return decoded
        }
        
        init(content: [WidgetComponent]) {
            var codable = [CodableWidgetComponent]()
            
            for component in content {
                do {
                    let data = try JSONEncoder().encode(component)
                    codable.append(CodableWidgetComponent(className: "\(type(of: component))", data: data))
                } catch {
                    print(error.localizedDescription)
                }
            }
            
            self.content = codable
        }
    }
    
    var content: [WidgetComponent]
    
    var isSpacer: Bool
    
    var isDivider: Bool
    
    var backgroundColor: UIColor?
    
    var cornerRadius: Float = 0
    
    var identifier: String?
    
    init(content: [WidgetComponent], isSpacer: Bool = false, isDivider: Bool = false, identifier: String?) {
        self.content = content
        self.isSpacer = isSpacer
        self.isDivider = isDivider
        self.identifier = identifier
    }
    
    let id = UUID()
    
    enum Keys: CodingKey {
        
        case content
        
        case isSpacer
        
        case isDivider
        
        case backgroundColor
        
        case cornerRadius
        
        case id
    }
    
    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Keys.self)
        content = try container.decode(RowContent.self, forKey: .content).decodedContent
        isSpacer = try container.decode(Bool.self, forKey: .isSpacer)
        isDivider = try container.decode(Bool.self, forKey: .isDivider)
        cornerRadius = try container.decode(Float.self, forKey: .cornerRadius)
        
        do {
            backgroundColor = UIColor.color(withData: try container.decode(Data.self, forKey: .backgroundColor))
        } catch {
            backgroundColor = nil
        }
        
        do {
            identifier = try container.decode(String.self, forKey: .id)
        } catch {
            identifier = nil
        }
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(RowContent(content: content), forKey: .content)
        try container.encode(isSpacer, forKey: .isSpacer)
        try container.encode(isDivider, forKey: .isDivider)
        try container.encode(backgroundColor?.encode(), forKey: .backgroundColor)
        try container.encode(cornerRadius, forKey: .cornerRadius)
        try container.encode(identifier, forKey: .id)
    }
}
