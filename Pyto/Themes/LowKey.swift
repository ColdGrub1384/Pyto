//
//  LowKey.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/16/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Low Key code theme.
struct LowKeySourceCodeTheme: SourceCodeTheme {
    
    let defaultTheme = DefaultSourceCodeTheme()
    
    var lineNumbersStyle: LineNumbersStyle? {
        return LineNumbersStyle(font: defaultTheme.font.withSize(font.pointSize), textColor: defaultTheme.lineNumbersStyle?.textColor ?? color(for: .plain))
    }
    
    var gutterStyle: GutterStyle {
        return GutterStyle(backgroundColor: backgroundColor, minimumWidth: defaultTheme.gutterStyle.minimumWidth)
    }
    
    var font: Font {
        return EditorViewController.font.withSize(CGFloat(ThemeFontSize))
    }
    
    let backgroundColor = Color.white
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(red: 67/255, green: 81/255, blue: 56/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(displayP3Red: 71/255, green: 106/255, blue: 151/255, alpha: 1)
        case .keyword:
            return Color(red: 38/255, green: 44/255, blue: 106/255, alpha: 1)
        case .number:
            return Color(red: 38/255, green: 44/255, blue: 106/255, alpha: 1)
        case .plain:
            return .black
        case .string:
            return Color(red: 112/255, green: 44/255, blue: 81/255, alpha: 1)
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

/// The Low Key theme.
struct LowKeyTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .default
    
    let barStyle: UIBarStyle = .default
    
    var userInterfaceStyle: UIUserInterfaceStyle {
        return .light
    }
    
    let sourceCodeTheme: SourceCodeTheme = LowKeySourceCodeTheme()
    
    let name: String? = "LowKey"
}
