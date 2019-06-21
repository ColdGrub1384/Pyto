//
//  Sunset.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/16/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Sunset source code theme.
struct SunsetSourceCodeTheme: SourceCodeTheme {
    
    let defaultTheme = DefaultSourceCodeTheme()
    
    var lineNumbersStyle: LineNumbersStyle? {
        return defaultTheme.lineNumbersStyle
    }
    
    var gutterStyle: GutterStyle {
        return GutterStyle(backgroundColor: backgroundColor, minimumWidth: defaultTheme.gutterStyle.minimumWidth)
    }
    
    var font: Font {
        return defaultTheme.font.withSize(CGFloat(ThemeFontSize))
    }
    
    let backgroundColor = Color(displayP3Red: 255/255, green: 252/255, blue: 229/255, alpha: 1)
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(displayP3Red: 195/255, green: 116/255, blue: 28/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(red: 71/255, green: 106/255, blue: 151/255, alpha: 1)
        case .keyword:
            return Color(red: 41/255, green: 66/255, blue: 119/255, alpha: 1)
        case .number:
            return Color(red: 41/255, green: 66/255, blue: 119/255, alpha: 1)
        case .plain:
            return .black
        case .string:
            return Color(red: 223/255, green: 7/255, blue: 0/255, alpha: 1)
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

/// The Sunset theme.
struct SunsetTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .default
    
    let barStyle: UIBarStyle = .default
    
    let sourceCodeTheme: SourceCodeTheme = SunsetSourceCodeTheme()
}
