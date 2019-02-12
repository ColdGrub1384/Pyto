//
//  CoolGlow.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Cool Glow source code theme.
struct CoolGlowSourceCodeTheme: SourceCodeTheme {
    
    let defaultTheme = DefaultSourceCodeTheme()
    
    var lineNumbersStyle: LineNumbersStyle? {
        return nil
    }
    
    var gutterStyle: GutterStyle {
        return GutterStyle(backgroundColor: .clear, minimumWidth: 0)
    }
    
    var font: Font {
        return defaultTheme.font
    }
    
    let backgroundColor = Color(displayP3Red: 6/255, green: 7/255, blue: 29/255, alpha: 1)
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(displayP3Red: 174/255, green: 174/255, blue: 174/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(red: 96/255, green: 164/255, blue: 241/255, alpha: 1)
        case .keyword:
            return Color(red: 43/255, green: 241/255, blue: 220/255, alpha: 1)
        case .number:
            return Color(red: 248/255, green: 251/255, blue: 177/255, alpha: 1)
        case .plain:
            return .white
        case .string:
            return Color(red: 146/255, green: 255/255, blue: 163/255, alpha: 1)
        }
    }
    
    func globalAttributes() -> [NSAttributedString.Key : Any] {
        
        var attributes = [NSAttributedString.Key: Any]()
        
        attributes[.font] = font
        attributes[.foregroundColor] = color(for: .plain)
        
        return attributes
    }
}

// MARK: - Theme

#if os(iOS)

/// The Cool Glow theme.
struct CoolGlowTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .dark
    
    let barStyle: UIBarStyle = .black
    
    let sourceCodeTheme: SourceCodeTheme = CoolGlowSourceCodeTheme()
    
    var tintColor: UIColor? {
        return Color(displayP3Red: 175/255, green: 127/255, blue: 196/255, alpha: 1)
    }
}

#endif
