//
//  Default.swift
//  Pyto
//
//  Created by Emma Labbé on 06-06-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
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
    
    var consoleBackgroundColor: UIColor {
        .secondarySystemBackground
    }
    
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
