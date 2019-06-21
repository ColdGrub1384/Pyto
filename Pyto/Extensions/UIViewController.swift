//
//  UIViewController+isDarkModeEnabled.swift
//  Pyto
//
//  Created by Adrian Labbé on 4/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

extension UIViewController {
    
    /// Returns `true` if dark mode is enabled.
    var isDarkModeEnabled: Bool {
        return (traitCollection.userInterfaceStyle == .dark || UIAccessibility.isInvertColorsEnabled)
    }
}
