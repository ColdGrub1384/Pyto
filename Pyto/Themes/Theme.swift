//
//  EditorTheme_.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/15/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import SourceEditor

#if os(iOS)

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
    (name: "Xcode", value: XcodeTheme()),
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

#else

import Cocoa

/// A dictionary with all themes.
let Themes: [(name: String, value: SourceCodeTheme)] = [
    (name: "Xcode", value: XcodeSourceCodeTheme()),
    (name: "Xcode Dark", value: XcodeDarkSourceCodeTheme()),
    (name: "Basic", value: BasicSourceCodeTheme()),
    (name: "Dusk", value: DuskSourceCodeTheme()),
    (name: "LowKey", value: LowKeySourceCodeTheme()),
    (name: "Midnight", value: MidnightSourceCodeTheme()),
    (name: "Sunset", value: SunsetSourceCodeTheme()),
    (name: "WWDC16", value: WWDC16SourceCodeTheme()),
    (name: "Cool Glow", value: CoolGlowSourceCodeTheme()),
    (name: "Solarized Light", value: SolarizedLightSourceCodeTheme()),
    (name: "Solarized Dark", value: SolarizedDarkSourceCodeTheme())
]

/// The theme the user choosed.
var ChoosenTheme: SourceCodeTheme {
    set {
        
        let themeID: Int
        
        switch newValue {
        case is XcodeSourceCodeTheme:
            themeID = 0
        case is XcodeDarkSourceCodeTheme:
            themeID = 0
        case is BasicSourceCodeTheme:
            themeID = 1
        case is DuskSourceCodeTheme:
            themeID = 2
        case is LowKeySourceCodeTheme:
            themeID = 3
        case is MidnightSourceCodeTheme:
            themeID = 4
        case is SunsetSourceCodeTheme:
            themeID = 5
        case is WWDC16SourceCodeTheme:
            themeID = 6
        case is CoolGlowSourceCodeTheme:
            themeID = 7
        case is SolarizedLightSourceCodeTheme:
            themeID = 8
        case is SolarizedDarkSourceCodeTheme:
            themeID = 9
        default:
            themeID = 0
        }
        
        UserDefaults.standard.set(themeID, forKey: "theme")
        UserDefaults.standard.synchronize()
        
        NotificationCenter.default.post(name: ThemeDidChangeNotification, object: newValue)
    }
    
    get {
        switch UserDefaults.standard.integer(forKey: "theme") {
        case 0:
            if NSView().isDarkMode {
                return XcodeDarkSourceCodeTheme()
            } else {
                return XcodeSourceCodeTheme()
            }
        case 1:
            return BasicSourceCodeTheme()
        case 2:
            return DuskSourceCodeTheme()
        case 3:
            return LowKeySourceCodeTheme()
        case 4:
            return MidnightSourceCodeTheme()
        case 5:
            return SunsetSourceCodeTheme()
        case 6:
            return WWDC16SourceCodeTheme()
        case 7:
            return CoolGlowSourceCodeTheme()
        case 8:
            return SolarizedLightSourceCodeTheme()
        case 9:
            return SolarizedDarkSourceCodeTheme()
        default:
            return XcodeSourceCodeTheme()
        }
    }
}

#endif

/// A notification sent when the user choosed theme.
let ThemeDidChangeNotification = Notification.Name("ThemeDidChangeNotification")

#if os(iOS)
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
#endif
