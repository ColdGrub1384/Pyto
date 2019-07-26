//
//  PyLabel.swift
//  Pyto
//
//  Created by Adrian Labbé on 03-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A Python wrapper for `UIView`.
@available(iOS 13.0, *) @objc public class PyLabel: PyView {
    
    override init(managed: Any! = NSObject()) {
        super.init(managed: managed)
    }
    
    @objc override class func newView() -> PyView {
        return PyLabel(managed: get {
            let label = UILabel()
            label.numberOfLines = 0
            return label
        })
    }
    
    /// The label associated with this object.
    @objc public var label: UILabel {
        return get {
            return self.managed as! UILabel
        }
    }
    
    @objc public var text: String! {
        get {
            return get {
                return self.label.text ?? ""
            }
        }
        
        set {
            set {
                self.label.text = newValue
            }
        }
    }
    
    @objc var textColor: PyColor? {
        get {
            return get {
                if let color = self.label.textColor {
                    return PyColor(managed: color)
                } else {
                    return nil
                }
            }
        }
        
        set {
            set {
                if let color = newValue?.managed as? UIColor {
                    self.label.textColor = color
                } else {
                    self.label.textColor = nil
                }
            }
        }
    }
    
    @objc public var font: UIFont! {
        get {
            return get {
                return self.label.font
            }
        }
        
        set {
            set {
                self.label.font = newValue
            }
        }
    }
    
    @objc var textAlignment: Int {
        get {
            return get {
                return self.label.textAlignment.rawValue
            }
        }
        
        set {
            set {
                self.label.textAlignment = NSTextAlignment(rawValue: newValue) ?? NSTextAlignment.natural
            }
        }
    }
    
    @objc var lineBreakMode: Int {
        get {
            return get {
                return self.label.lineBreakMode.rawValue
            }
        }
        
        set {
            set {
                self.label.lineBreakMode = NSLineBreakMode(rawValue: newValue) ?? NSLineBreakMode.byTruncatingTail
            }
        }
    }
    
    @objc public var adjustsFontSizeToFitWidth: Bool {
        get {
            return get {
                return self.label.adjustsFontSizeToFitWidth
            }
        }
        
        set {
            set {
                self.label.adjustsFontSizeToFitWidth = newValue
            }
        }
    }
    
    @objc public var allowsDefaultTighteningForTruncation: Bool {
        get {
            return get {
                return self.label.allowsDefaultTighteningForTruncation
            }
        }
        
        set {
            set {
                self.label.allowsDefaultTighteningForTruncation = newValue
            }
        }
    }
    
    @objc public var baselineAdjustment: Int {
        get {
            return get {
                return self.label.baselineAdjustment.rawValue
            }
        }
        
        set {
            set {
                self.label.baselineAdjustment = UIBaselineAdjustment(rawValue: newValue) ?? UIBaselineAdjustment.none
            }
        }
    }
    
    @objc public var minimumScaleFactor: Double {
        get {
            return get {
                return Double(self.label.minimumScaleFactor)
            }
        }
        
        set {
            set {
                self.label.minimumScaleFactor = CGFloat(newValue)
            }
        }
    }
    
    @objc public var numberOfLines: Int {
        get {
            return get {
                return self.label.numberOfLines
            }
        }
        
        set {
            set {
                self.label.numberOfLines = newValue
            }
        }
    }
    
    @objc public static let TextAlignmentLeft = NSTextAlignment.left
    
    @objc public static let TextAlignmentRight = NSTextAlignment.right
    
    @objc public static let TextAlignmentCenter = NSTextAlignment.center
    
    @objc public static let TextAlignmentJustified = NSTextAlignment.justified
    
    @objc public static let TextAlignmentNatural = NSTextAlignment.natural
    
    @objc public static let LineBreakModeByWordWrapping = NSLineBreakMode.byWordWrapping
    
    @objc public static let LineBreakModeByCharWrapping = NSLineBreakMode.byCharWrapping
    
    @objc public static let LineBreakModeByClipping = NSLineBreakMode.byClipping
    
    @objc public static let LineBreakModeByTruncatingHead = NSLineBreakMode.byTruncatingHead
    
    @objc public static let LineBreakModeByTruncatingTail = NSLineBreakMode.byTruncatingTail
    
    @objc public static let LineBreakModeByTruncatingMiddle = NSLineBreakMode.byTruncatingMiddle
}
