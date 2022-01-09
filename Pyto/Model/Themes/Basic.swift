//
//  Basic.swift
//  Pyto
//
//  Created by Emma Labbé on 1/16/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

// MARK: - Source code theme

/// The Basic code theme.
struct BasicSourceCodeTheme: SourceCodeTheme {
    
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
            return Color(red: 0/255, green: 128/255, blue: 0/255, alpha: 1)
        case .editorPlaceholder:
            return defaultTheme.color(for: syntaxColorType)
        case .identifier:
            return Color(red: 43/255, green: 131/255, blue: 159/255, alpha: 1)
        case .builtin:
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

/// The Basic theme.
struct BasicTheme: Theme {
    
    let keyboardAppearance: UIKeyboardAppearance = .default
    
    let barStyle: UIBarStyle = .default
    
    var userInterfaceStyle: UIUserInterfaceStyle {
        return .light
    }
    
    let sourceCodeTheme: SourceCodeTheme = BasicSourceCodeTheme()
    
    var consoleBackgroundColor: UIColor {
        .secondarySystemBackground
    }
    
    let name: String? = "Basic"
}
