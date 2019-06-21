//
//  EditorTheme_.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/15/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SourceEditor

import UIKit

/// A protocol for implementing an editor and console theme.
protocol Theme {
    
    /// The keyboard appearance used in the editor and the console.
    var keyboardAppearance: UIKeyboardAppearance { get }
    
    /// The navigation and tool bar style.
    var barStyle: UIBarStyle { get }
    
    /// The source code theme type.
    var sourceCodeTheme: SourceCodeTheme { get }
    
    /// The tint color of the interface.
    var tintColor: UIColor? { get }
}

extension Theme {
    
    var tintColor: UIColor? {
        return UIColor(named: "TintColor")
    }
}

/// A dictionary with all themes.
let Themes: [(name: String, value: Theme)] = [
    (name: "Default", value: DefaultTheme()),
    (name: "Xcode Light", value: XcodeLightTheme()),
    (name: "Xcode Dark", value: XcodeDarkTheme()),
    (name: "Basic", value: BasicTheme()),
    (name: "Dusk", value: DuskTheme()),
    (name: "LowKey", value: LowKeyTheme()),
    (name: "Midnight", value: MidnightTheme()),
    (name: "Sunset", value: SunsetTheme()),
    (name: "WWDC16", value: WWDC16Theme()),
    (name: "Cool Glow", value: CoolGlowTheme()),
    (name: "Solarized Light", value: SolarizedLightTheme()),
    (name: "Solarized Dark", value: SolarizedDarkTheme())
]

/// A notification sent when the user choosed theme.
let ThemeDidChangeNotification = Notification.Name("ThemeDidChangeNotification")

/// The font size used on the editor.
var ThemeFontSize: Int {
    get {
        return (UserDefaults.standard.value(forKey: "fontSize") as? Int) ?? 15
    }
    
    set {
        UserDefaults.standard.set(newValue, forKey: "fontSize")
        UserDefaults.standard.synchronize()
    }
}
