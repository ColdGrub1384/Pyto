//
//  WWDC16.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The WWDC16 source code theme.
struct WWDC16SourceCodeTheme: SourceCodeTheme {
    
    let defaultTheme = DefaultSourceCodeTheme()
    
    var lineNumbersStyle: LineNumbersStyle? {
        #if os(iOS)
        return nil
        #else
        return defaultTheme.lineNumbersStyle
        #endif
    }
    
    var gutterStyle: GutterStyle {
        #if os(iOS)
        return GutterStyle(backgroundColor: .clear, minimumWidth: 0)
        #else
        return GutterStyle(backgroundColor: backgroundColor, minimumWidth: defaultTheme.gutterStyle.minimumWidth)
        #endif
    }
    
    var font: Font {
        return defaultTheme.font
    }
    
    let backgroundColor = Color(displayP3Red: 31/255, green: 32/255, blue: 41/255, alpha: 1)
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(displayP3Red: 81/255, green: 114/255, blue: 124/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(red: 19/255, green: 157/255, blue: 146/255, alpha: 1)
        case .keyword:
            return Color(red: 131/255, green: 189/255, blue: 91/255, alpha: 1)
        case .number:
            return Color(red: 116/255, green: 109/255, blue: 176/255, alpha: 1)
        case .plain:
            return .white
        case .string:
            return Color(red: 209/255, green: 36/255, blue: 46/255, alpha: 1)
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

/// The WWDC16 theme.
struct WWDC16Theme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .dark
    
    let barStyle: UIBarStyle = .black
    
    let sourceCodeTheme: SourceCodeTheme = WWDC16SourceCodeTheme()
    
    var tintColor: UIColor? {
        return sourceCodeTheme.color(for: .identifier)
    }
}

#endif
