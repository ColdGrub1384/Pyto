//
//  EditorTheme.swift
//  Pyto
//
//  Created by Adrian Labbe on 12/21/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import SavannaKit
import SourceEditor

/// The theme used by the code editor.
struct EditorTheme: SourceCodeTheme {
    
    let defaultTheme = DefaultSourceCodeTheme()
    
    var lineNumbersStyle: LineNumbersStyle? {
        return defaultTheme.lineNumbersStyle
    }
    
    var gutterStyle: GutterStyle {
        return GutterStyle(backgroundColor: .clear, minimumWidth: defaultTheme.gutterStyle.minimumWidth)
    }
    
    var font: Font {
        return defaultTheme.font
    }
    
    let backgroundColor = Color.clear
    
    func color(for syntaxColorType: SourceCodeTokenType) -> Color {
        return defaultTheme.color(for: syntaxColorType)
    }
    
}
