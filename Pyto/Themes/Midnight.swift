//
//  Midnight.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/16/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Midnight source code theme.
struct MidnightSourceCodeTheme: SourceCodeTheme {
    
    let defaultTheme = DefaultSourceCodeTheme()
    
    var lineNumbersStyle: LineNumbersStyle? {
        return nil
    }
    
    var gutterStyle: GutterStyle {
        return GutterStyle(backgroundColor: .clear, minimumWidth: 0)
    }
    
    var font: Font {
        return defaultTheme.font.withSize(CGFloat(ThemeFontSize))
    }
    
    let backgroundColor = Color.black
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(red: 65/255, green: 204/255, blue: 69/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(displayP3Red: 0/255, green: 160/255, blue: 255/255, alpha: 1)
        case .keyword:
            return Color(red: 211/255, green: 24/255, blue: 149/255, alpha: 1)
        case .number:
            return Color(red: 120/255, green: 109/255, blue: 255/255, alpha: 1)
        case .plain:
            return .white
        case .string:
            return Color(red: 255/255, green: 44/255, blue: 56/255, alpha: 1)
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

/// The Midnight theme.
struct MidnightTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .dark
    
    let barStyle: UIBarStyle = .black
    
    let sourceCodeTheme: SourceCodeTheme = MidnightSourceCodeTheme()
}

#endif
