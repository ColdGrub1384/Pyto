//
//  PyColor.swift
//  Pyto
//
//  Created by Adrian Labbé on 29-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A Python wrapper for `UIColor`.
@available(iOS 13.0, *) @objc public class PyColor: PyWrapper {
    
    /// The `UIColor` represented by this object.
    var color: UIColor {
        return get {
            return self.managed as? UIColor ?? .clear
        }
    }
    
    @objc public override func isEqual(_ object: Any?) -> Bool {
        if let color = object as? PyColor {
            return self.color == color.color
        } else {
            return super.isEqual(object)
        }
    }
    
    /// Returns the red value.
    @objc public var red: Double {
        return get {
            var r: CGFloat = 0
            self.color.getRed(&r, green: nil, blue: nil, alpha: nil)
            return Double(r )
        }
    }
    
    /// Returns the green value.
    @objc public var green: Double {
        return get {
            var g: CGFloat = 0
            self.color.getRed(nil, green: &g, blue: nil, alpha: nil)
            return Double(g )
        }
    }
    
    /// Returns the blue value.
    @objc public var blue: Double {
        return get {
            var b: CGFloat = 0
            self.color.getRed(nil, green: nil, blue: &b, alpha: nil)
            return Double(b)
        }
    }
    
    /// Returns the alpha value.
    @objc public var alpha: Double {
        return get {
            var a: CGFloat = 0
            self.color.getRed(nil, green: nil, blue: nil, alpha: &a)
            return Double(a)
        }
    }
    
    /// Initializes a new color with given values.
    ///
    /// - Parameters:
    ///     - red: Red value / 1.
    ///     - green: Green value / 1.
    ///     - blue: Blue value / 1.
    ///     - alpha: Alpha value / 1.
    @objc public static func color(red: Float, green: Float, blue: Float, alpha: Float) -> PyColor {
        let color = UIColor(displayP3Red: CGFloat(red), green: CGFloat(green), blue: CGFloat(blue), alpha: CGFloat(alpha))
        return PyColor(managed: color)
    }
    
    /// Initializes a new color with given values.
    ///
    /// - Parameters:
    ///     - white: White value / 1.
    ///     - alpha: Alpha value / 1.
    @objc public static func color(white: Float, alpha: Float) -> PyColor {
        let color = UIColor(white: CGFloat(white), alpha: CGFloat(alpha))
        return PyColor(managed: color)
    }
    
    /// Initializes a new color for different appearances.
    ///
    /// - Parameters:
    ///     - light: Color displayed on light appearance.
    ///     - dark: Color displayed on dark appearance.
    @objc public static func color(light: PyColor, dark: PyColor) -> PyColor {
        let color = UIColor(dynamicProvider: { (traitCollection) -> UIColor in
            
            if traitCollection.userInterfaceStyle == .dark {
                return dark.color
            } else {
                return light.color
            }
        })
        return PyColor(managed: color)
    }
    
    override init(managed: NSObject! = NSObject()) {
        super.init(managed: managed)
    }
    
    /// `label` color.
    @objc public class var label: PyColor {
        return get {
            return PyColor(managed: UIColor.label)
        }
    }
    
    /// `secondaryLabel` color.
    @objc public class var secondaryLabel: PyColor {
        return get {
            return PyColor(managed: UIColor.secondaryLabel)
        }
    }
    
    /// `tertiaryLabel` color.
    @objc public class var tertiaryLabel: PyColor {
        return get {
            return PyColor(managed: UIColor.tertiaryLabel)
        }
    }
    
    /// `quaternaryLabel` color.
    @objc public class var quaternaryLabel: PyColor {
        return get {
            return PyColor(managed: UIColor.quaternaryLabel)
        }
    }
    
    /// `systemFill` color.
    @objc public class var systemFill: PyColor {
        return get {
            return PyColor(managed: UIColor.systemFill)
        }
    }
    
    /// `secondarySystemFill` color.
    @objc public class var secondarySystemFill: PyColor {
        return get {
            return PyColor(managed: UIColor.secondarySystemFill)
        }
    }
    
    /// `tertiarySystemFill` color.
    @objc public class var tertiarySystemFill: PyColor {
        return get {
            return PyColor(managed: UIColor.tertiarySystemFill)
        }
    }
    
    /// `quaternarySystemFill` color.
    @objc public class var quaternarySystemFill: PyColor {
        return get {
            return PyColor(managed: UIColor.quaternarySystemFill)
        }
    }
    
    /// `placeholderText` color.
    @objc public class var placeholderText: PyColor {
        return get {
            return PyColor(managed: UIColor.placeholderText)
        }
    }
    
    /// `systemBackground` color.
    @objc public class var systemBackground: PyColor {
        return get {
            return PyColor(managed: UIColor.systemBackground)
        }
    }
    
    /// `secondarySystemBackground` color.
    @objc public class var secondarySystemBackground: PyColor {
        return get {
            return PyColor(managed: UIColor.secondarySystemBackground)
        }
    }
    
    /// `tertiarySystemBackground` color.
    @objc public class var tertiarySystemBackground: PyColor {
        return get {
            return PyColor(managed: UIColor.tertiarySystemBackground)
        }
    }
    
    /// `systemGroupedBackground` color.
    @objc public class var systemGroupedBackground: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGroupedBackground)
        }
    }
    
    /// `secondarySystemGroupedBackground` color.
    @objc public class var secondarySystemGroupedBackground: PyColor {
        return get {
            return PyColor(managed: UIColor.secondarySystemGroupedBackground)
        }
    }
    
    /// `tertiarySystemGroupedBackground` color.
    @objc public class var tertiarySystemGroupedBackground: PyColor {
        return get {
            return PyColor(managed: UIColor.tertiarySystemGroupedBackground)
        }
    }
    
    /// `separator` color.
    @objc public class var separator: PyColor {
        return get {
            return PyColor(managed: UIColor.separator)
        }
    }
    
    /// `opaqueSeparator` color.
    @objc public class var opaqueSeparator: PyColor {
        return get {
            return PyColor(managed: UIColor.opaqueSeparator)
        }
    }
    
    /// `link` color.
    @objc public class var link: PyColor {
        return get {
            return PyColor(managed: UIColor.link)
        }
    }
    
    /// `darkText` color.
    @objc public class var darkText: PyColor {
        return get {
            return PyColor(managed: UIColor.darkText)
        }
    }
    
    /// `lightText` color.
    @objc public class var lightText: PyColor {
        return get {
            return PyColor(managed: UIColor.lightText)
        }
    }
    
    /// `systemBlue` color.
    @objc public class var systemBlue: PyColor {
        return get {
            return PyColor(managed: UIColor.systemBlue)
        }
    }
    
    /// `systemGreen` color.
    @objc public class var systemGreen: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGreen)
        }
    }
    
    /// `systemIndigo` color.
    @objc public class var systemIndigo: PyColor {
        return get {
            return PyColor(managed: UIColor.systemIndigo)
        }
    }
    
    /// `systemOrange` color.
    @objc public class var systemOrange: PyColor {
        return get {
            return PyColor(managed: UIColor.systemOrange)
        }
    }
    
    /// `systemPink` color.
    @objc public class var systemPink: PyColor {
        return get {
            return PyColor(managed: UIColor.systemPink)
        }
    }
    
    /// `systemPurple` color.
    @objc public class var systemPurple: PyColor {
        return get {
            return PyColor(managed: UIColor.systemPurple)
        }
    }
    
    /// `systemRed` color.
    @objc public class var systemRed: PyColor {
        return get {
            return PyColor(managed: UIColor.systemRed)
        }
    }
    
    /// `systemTeal` color.
    @objc public class var systemTeal: PyColor {
        return get {
            return PyColor(managed: UIColor.systemTeal)
        }
    }
    
    /// `systemYellow` color.
    @objc public class var systemYellow: PyColor {
        return get {
            return PyColor(managed: UIColor.systemYellow)
        }
    }
    
    /// `systemGray` color.
    @objc public class var systemGray: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGray)
        }
    }
    
    /// `systemGray2` color.
    @objc public class var systemGray2: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGray2)
        }
    }
    
    /// `systemGray3` color.
    @objc public class var systemGray3: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGray3)
        }
    }
    
    /// `systemGray4` color.
    @objc public class var systemGray4: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGray4)
        }
    }
    
    /// `systemGray5` color.
    @objc public class var systemGray5: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGray5)
        }
    }
    
    /// `systemGray6` color.
    @objc public class var systemGray6: PyColor {
        return get {
            return PyColor(managed: UIColor.systemGray6)
        }
    }
    
    /// `clear` color.
    @objc public class var clear: PyColor {
        return get {
            return PyColor(managed: UIColor.clear)
        }
    }
    
    /// `black` color.
    @objc public class var black: PyColor {
        return get {
            return PyColor(managed: UIColor.black)
        }
    }
    
    /// `blue` color.
    @objc public class var blue: PyColor {
        return get {
            return PyColor(managed: UIColor.blue)
        }
    }
    
    /// `brown` color.
    @objc public class var brown: PyColor {
        return get {
            return PyColor(managed: UIColor.brown)
        }
    }
    
    /// `cyan` color.
    @objc public class var cyan: PyColor {
        return get {
            return PyColor(managed: UIColor.cyan)
        }
    }
    
    /// `darkGray` color.
    @objc public class var darkGray: PyColor {
        return get {
            return PyColor(managed: UIColor.darkGray)
        }
    }
    
    /// `gray` color.
    @objc public class var gray: PyColor {
        return get {
            return PyColor(managed: UIColor.gray)
        }
    }
    
    /// `green` color.
    @objc public class var green: PyColor {
        return get {
            return PyColor(managed: UIColor.green)
        }
    }
    
    /// `lightGray` color.
    @objc public class var lightGray: PyColor {
        return get {
            return PyColor(managed: UIColor.lightGray)
        }
    }
    
    /// `magenta` color.
    @objc public class var magenta: PyColor {
        return get {
            return PyColor(managed: UIColor.magenta)
        }
    }
    
    /// `orange` color.
    @objc public class var orange: PyColor {
        return get {
            return PyColor(managed: UIColor.orange)
        }
    }
    
    /// `purple` color.
    @objc public class var purple: PyColor {
        return get {
            return PyColor(managed: UIColor.purple)
        }
    }
    
    /// `red` color.
    @objc public class var red: PyColor {
        return get {
            return PyColor(managed: UIColor.red)
        }
    }
    
    /// `white` color.
    @objc public class var white: PyColor {
        return get {
            return PyColor(managed: UIColor.white)
        }
    }
    
    /// `yellow` color.
    @objc public class var yellow: PyColor {
        return get {
            return PyColor(managed: UIColor.yellow)
        }
    }
}
