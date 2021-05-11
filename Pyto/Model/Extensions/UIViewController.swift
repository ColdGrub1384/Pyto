//
//  UIViewController+isDarkModeEnabled.swift
//  Pyto
//
//  Created by Emma Labbé on 4/17/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

extension UIViewController {
    
    /// Returns `true` if dark mode is enabled.
    var isDarkModeEnabled: Bool {
        return (traitCollection.userInterfaceStyle == .dark || UIAccessibility.isInvertColorsEnabled)
    }
}
