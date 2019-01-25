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
}
