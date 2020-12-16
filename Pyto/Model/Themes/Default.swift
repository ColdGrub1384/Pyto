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
    
    private var window: UIWindow? {
        for scene in UIApplication.shared.connectedScenes {
            if let windowScene = scene as? UIWindowScene {
                if windowScene.activationState == .foregroundActive || windowScene.activationState == .foregroundInactive {
                    return windowScene.windows.first
                }
            }
        }
        
        return nil
    }
    
    var keyboardAppearance: UIKeyboardAppearance {
        return (window?.traitCollection.userInterfaceStyle == .dark ? .dark : .default)
    }
    
    var userInterfaceStyle: UIUserInterfaceStyle {
        return .unspecified
    }
    
    let barStyle: UIBarStyle = .default
    
    var sourceCodeTheme: SourceCodeTheme {
        
        let darkTheme: SourceCodeTheme
        if #available(iOS 14.0, *), ProcessInfo.processInfo.isiOSAppOnMac {
            darkTheme = XcodeDarkSourceCodeTheme()
        } else {
            darkTheme = MidnightSourceCodeTheme()
        }
        
        return (window?.traitCollection.userInterfaceStyle == .dark ? darkTheme : XcodeLightSourceCodeTheme())
    }
    
    var name: String? {
        return (window?.traitCollection.userInterfaceStyle == .dark ? "Midnight" : "Xcode")
    }
}
