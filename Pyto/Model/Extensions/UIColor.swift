//
//  UIColor.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/25/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

extension UIColor {
    
    /// Returns an hexadecimal color representation as String.
    var hexString: String {
        let colorRef = cgColor.components
        let r = colorRef?[0] ?? 0
        let g = colorRef?[1] ?? 0
        let b = ((colorRef?.count ?? 0) > 2 ? colorRef?[2] : g) ?? 0
        let a = cgColor.alpha

        var color = String(
            format: "#%02lX%02lX%02lX",
            lroundf(Float(r * 255)),
            lroundf(Float(g * 255)),
            lroundf(Float(b * 255))
        )

        if a < 1 {
            color += String(format: "%02lX", lroundf(Float(a)))
        }

        return color
    }
    
    /// Returns a color from a hexadecimal string.
    ///
    /// - Parameters:
    ///     - hexString: Hexadecimal string.
    ///     - alpha: The alpha of the color.
    convenience init(hexString: String, alpha: CGFloat = 1) {
        let chars = Array(hexString.dropFirst())
        self.init(red:   .init(strtoul(String(chars[0...1]),nil,16))/255,
                  green: .init(strtoul(String(chars[2...3]),nil,16))/255,
                  blue:  .init(strtoul(String(chars[4...5]),nil,16))/255,
                  alpha: alpha)
    }
    
    /// Returns a color from given data.
    ///
    /// - Parameters:
    ///     - data: Data representing the color.
    ///
    /// - Returns: The color represented by `data`.
    class func color(withData data:Data) -> UIColor {
        return try! NSKeyedUnarchiver.unarchivedObject(ofClass: UIColor.self, from: data)!
    }

    /// Encodes the color into data.
    ///
    /// - Returns: Data.
    func encode() -> Data {
         return try! NSKeyedArchiver.archivedData(withRootObject: self, requiringSecureCoding: false)
    }
}
