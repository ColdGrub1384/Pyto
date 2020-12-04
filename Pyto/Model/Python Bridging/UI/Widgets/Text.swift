//
//  Text.swift
//  Pyto
//
//  Created by Adrian Labbé on 25-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI
import WatchConnectivity

@objc class WidgetText: WidgetComponent {
        
    override init() { super.init() }
    
    private var _text: String?
    
    @objc var text: String? {
        get {
            return _text
        }
        
        set {
            guard let text = newValue?.replacingOccurrences(of: "\n", with: "<br/>") else {
                _text = nil
                return
            }
            
            // Convert HTML to plain text
            
            _text = (text as NSString).replacingOccurrences(of: "<[^>]+>", with: "", options: .regularExpression, range: NSRange(location: 0, length: (text as NSString).length))
        }
    }
    
    @objc var color: UIColor?
    
    @objc var font: UIFont?
    
    override var makeView: AnyView {
        #if os(iOS)
        let label = UIColor.label
        let fontSize = UIFont.systemFontSize
        #elseif os(watchOS)
        let label = UIColor.white
        let fontSize = CGFloat(17)
        #endif
                
        return AnyView(Text(text ?? "")
                        .foregroundColor(Color(color ?? label))
                        .font(Font(font ?? UIFont.systemFont(ofSize: fontSize)))
                        .padding((backgroundColor != nil && backgroundColor != UIColor.clear) ? .all : [])
                        .background(Color(backgroundColor ?? UIColor.clear))
                        .cornerRadius(CGFloat(cornerRadius)))
    }
    
    required init(from decoder: Decoder) throws {
        try super.init(from: decoder)
        
        let container = try decoder.container(keyedBy: Keys.self)
        
        font = try container.decode(CodableFont.self, forKey: .font).uiFont
        
        do {
            text = try container.decode(String.self, forKey: .text)
        } catch {
            text = nil
        }
        
        do {
            let colorData = try container.decode(Data.self, forKey: .color)
            color = UIColor.color(withData: colorData)
        } catch {
            color = nil
        }
    }
    
    override func encode(to encoder: Encoder) throws {
        try super.encode(to: encoder)
        
        #if os(iOS)
        let fontSize = UIFont.systemFontSize
        #elseif os(watchOS)
        let fontSize = CGFloat(17)
        #endif
        
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(text, forKey: .text)
        try container.encode(color?.encode(), forKey: .color)
        try container.encode(CodableFont(font: font ?? UIFont.systemFont(ofSize: fontSize)), forKey: .font)
    }
}
