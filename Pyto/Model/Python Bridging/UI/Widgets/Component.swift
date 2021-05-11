//
//  Component.swift
//  Pyto
//
//  Created by Emma Labbé on 25-07-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SwiftUI

@objc class WidgetComponent: NSObject, Identifiable, Codable {
    
    struct PaddingView: View {
        
        var view: AnyView
        
        var customPadding: WidgetPadding
        
        var body: some View {
            view
                .padding(.top, CGFloat(customPadding.top))
                .padding(.bottom, CGFloat(customPadding.bottom))
                .padding(.leading, CGFloat(customPadding.left))
                .padding(.trailing, CGFloat(customPadding.right))
        }
    }
    
    override init() {}
    
    let id = UUID()
    
    @objc var backgroundColor: UIColor?
    
    @objc var cornerRadius: Float = 0
    
    @objc var identifier: String?
    
    @objc var padding = 0
    
    @objc var customPadding = WidgetPadding()
    
    var paddingEdges: Edge.Set {
        switch padding {
        case 0:
            return []
        case 1:
            return .all
        case 2:
            return .vertical
        case 3:
            return .horizontal
        default:
            return []
        }
    }
    
    var makeView: AnyView {
        return AnyView(Spacer())
    }
    
    enum Keys: CodingKey {
        
        case backgroundColor
        
        case cornerRadius
        
        case text
        
        case color
        
        case font
        
        case date
        
        case dateStyle
        
        case fill
        
        case image
        
        case symbolName
        
        case id
        
        case padding
        
        case customPadding
        
        case fontSize
        
        case circular
        
        case progress
        
        case label
    }
    
    required init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Keys.self)
        cornerRadius = try container.decode(Float.self, forKey: .cornerRadius)
        do {
            let colorData = try container.decode(Data.self, forKey: .backgroundColor)
            backgroundColor = UIColor.color(withData: colorData)
        } catch {
            backgroundColor = nil
        }
        
        do {
            identifier = try container.decode(String.self, forKey: .id)
        } catch {
            identifier = nil
        }
        
        do {
            padding = try container.decode(Int.self, forKey: .padding)
        } catch {
            padding = 0
        }
        
        do {
            customPadding = try container.decode(WidgetPadding.self, forKey: .customPadding)
        } catch {
            customPadding = WidgetPadding()
        }
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(cornerRadius, forKey: .cornerRadius)
        try container.encode(backgroundColor?.encode(), forKey: .backgroundColor)
        try container.encode(identifier, forKey: .id)
        try container.encode(padding, forKey: .padding)
        try container.encode(customPadding, forKey: .customPadding)
    }
}
