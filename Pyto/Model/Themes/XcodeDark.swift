//
//  XcodeDark.swift
//  Pyto
//
//  Created by Emma Labbé on 1/15/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Xcode source code theme.
struct XcodeDarkSourceCodeTheme: SourceCodeTheme {
    
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
    
    let backgroundColor = Color(displayP3Red: 31/255, green: 31/255, blue: 36/255, alpha: 1)
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        switch syntaxColorType {
        case .comment:
            return Color(red: 83/255, green: 101/255, blue: 121/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(displayP3Red: 122/255, green: 200/255, blue: 182/255, alpha: 1)
        case .keyword:
            return Color(red: 252/255, green: 95/255, blue: 163/255, alpha: 1)
        case .number:
            return Color(red: 150/255, green: 134/255, blue: 245/255, alpha: 1)
        case .plain:
            return .white
        case .string:
            return Color(red: 252/255, green: 106/255, blue: 93/255, alpha: 1)
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

/// The Xcode dark theme.
struct XcodeDarkTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .dark
    
    let barStyle: UIBarStyle = .black
    
    var userInterfaceStyle: UIUserInterfaceStyle {
        return .dark
    }
    
    let sourceCodeTheme: SourceCodeTheme = XcodeDarkSourceCodeTheme()
    
    let name: String? = "Xcode Dark"
}
