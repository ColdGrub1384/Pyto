//
//  Dusk.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/16/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Dusk source code theme.
struct DuskSourceCodeTheme: SourceCodeTheme {
    
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
    
    let backgroundColor = Color(displayP3Red: 31/255, green: 32/255, blue: 41/255, alpha: 1)
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(red: 69/255, green: 187/255, blue: 62/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(displayP3Red: 37/255, green: 144/255, blue: 151/255, alpha: 1)
        case .keyword:
            return Color(red: 215/255, green: 0/255, blue: 143/255, alpha: 1)
        case .number:
            return Color(red: 20/255, green: 156/255, blue: 146/255, alpha: 1)
        case .plain:
            return .white
        case .string:
            return Color(red: 211/255, green: 35/255, blue: 46/255, alpha: 1)
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

/// The Dusk theme.
struct DuskTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .dark
    
    let barStyle: UIBarStyle = .black
    
    let sourceCodeTheme: SourceCodeTheme = DuskSourceCodeTheme()
}
