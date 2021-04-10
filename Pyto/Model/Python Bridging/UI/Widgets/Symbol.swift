//
//  Symbol.swift
//  Pyto
//
//  Created by Emma Labbé on 25-07-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import SwiftUI

@objc class WidgetSymbol: WidgetComponent {
    
    override init() { super.init() }
    
    @objc var symbolName: String?
    
    @objc var color: UIColor?
    
    @objc var fontSize: Double = 0
    
    private var _font: Font? {
        if fontSize == 0 {
            return Font.system(.body)
        } else {
            return Font.system(size: CGFloat(fontSize))
        }
    }
    
    override var makeView: AnyView {
        
        #if os(iOS)
        let label = UIColor.label
        #elseif os(watchOS)
        let label = UIColor.white
        #endif
        
        return AnyView(Image(systemName: symbolName ?? "")
                        .font(_font)
                        .foregroundColor(Color(color ?? label))
                        .padding((backgroundColor != nil && backgroundColor != UIColor.clear) ? .all : [])
                        .background(Color(backgroundColor ?? UIColor.clear))
                        .cornerRadius(CGFloat(cornerRadius)))
    }
    
    required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
        
        let container = try decoder.container(keyedBy: Keys.self)
        symbolName = try container.decode(String.self, forKey: .symbolName)
        fontSize = try container.decode(Double.self, forKey: .fontSize)
        
        do {
            let colorData = try container.decode(Data.self, forKey: .color)
            color = UIColor.color(withData: colorData)
        } catch {
            color = nil
        }
    }
    
    override func encode(to encoder: Encoder) throws {
        try super.encode(to: encoder)
        
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(symbolName, forKey: .symbolName)
        try container.encode(color?.encode(), forKey: .color)
        try container.encode(fontSize, forKey: .fontSize)
    }
}
