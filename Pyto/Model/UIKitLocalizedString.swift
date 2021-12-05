//
//  UIKitLocalizedString.swift
//  Pyto
//
//  Created by Emma on 05-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit

/// Returns a localized string from UIKit with given key.
///
/// - Parameters:
///     - key: The key of the String.
///
/// - Returns: The localized string from UIKit corresponding to the given key.
func UIKitLocalizedString(key: String) -> String {
    return Bundle(for: UIApplication.self).localizedString(forKey: key, value: nil, table: nil)
}
