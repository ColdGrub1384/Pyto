//
//  Basic.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/16/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Basic code theme.
struct BasicSourceCodeTheme: SourceCodeTheme {
    
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
    
    let backgroundColor = Color.white
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(red: 0/255, green: 128/255, blue: 0/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(red: 43/255, green: 131/255, blue: 159/255, alpha: 1)
        case .keyword:
            return Color(red: 0/255, green: 0/255, blue: 255/255, alpha: 1)
        case .number:
            return .black
        case .plain:
            return .black
        case .string:
            return Color(red: 163/255, green: 21/255, blue: 21/255, alpha: 1)
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

/// The Basic theme.
struct BasicTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .default
    
    let barStyle: UIBarStyle = .default
    
    let sourceCodeTheme: SourceCodeTheme = BasicSourceCodeTheme()
}

#endif
