//
//  Text.swift
//  Pyto
//
//  Created by Adrian Labbé on 25-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

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
            
            do {
                let attrString = try NSAttributedString(data: text.data(using: .utf16) ?? Data(), options: [.documentType:NSAttributedString.DocumentType.html], documentAttributes: nil)
                _text = attrString.string
            } catch {
                print(error.localizedDescription)
            }
        }
    }
    
    @objc var color: UIColor?
    
    @objc var font: UIFont?
    
    override var makeView: AnyView {
        return AnyView(Text(text ?? "")
                        .foregroundColor(Color(color ?? UIColor.label))
                        .font(Font(font ?? UIFont.systemFont(ofSize: UIFont.systemFontSize)))
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
        
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(text, forKey: .text)
        try container.encode(color?.encode(), forKey: .color)
        try container.encode(CodableFont(font: font ?? UIFont.systemFont(ofSize: UIFont.systemFontSize)), forKey: .font)
    }
}
