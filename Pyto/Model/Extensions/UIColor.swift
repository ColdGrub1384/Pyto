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
        var r: CGFloat = 0
        var g: CGFloat = 0
        var b: CGFloat = 0
        
        getRed(&r, green: &g, blue: &b, alpha: nil)

        if r < 0 {
            r = 0
        } else if r > 1 {
            r = 1
        }
        
        if g < 0 {
            g = 0
        } else if g > 1 {
            g = 1
        }
        
        if b < 0 {
            b = 0
        } else if b > 1 {
            b = 1
        }
        
        return String(
            format: "#%02lX%02lX%02lX",
            lroundf(Float(r * 255)),
            lroundf(Float(g * 255)),
            lroundf(Float(b * 255))
        )
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
