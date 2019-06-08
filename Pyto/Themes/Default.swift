//
//  Default.swift
//  Pyto
//
//  Created by Adrian Labbé on 06-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SourceEditor
import UIKit

/// Default theme based on system appearance.
struct DefaultTheme: Theme {
    
    var keyboardAppearance: UIKeyboardAppearance {
        return (UIApplication.shared.keyWindow?.traitCollection.userInterfaceStyle == .dark ? .dark : .default)
    }
    
    let barStyle: UIBarStyle = .default
    
    var sourceCodeTheme: SourceCodeTheme {
        return (UIApplication.shared.keyWindow?.traitCollection.userInterfaceStyle == .dark ? MidnightSourceCodeTheme() : XcodeLightSourceCodeTheme())
    }
}
