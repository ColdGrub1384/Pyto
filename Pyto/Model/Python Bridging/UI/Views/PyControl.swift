//
//  PyControl.swift
//  Pyto
//
//  Created by Emma Labbé on 30-06-19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *) @objc public class PyControl: PyView {
    
    public override class var pythonName: String {
        return "Control"
    }
    
    @objc public var action: PyValue?
    
    @objc public var managedValue: PyValue?
    
    @objc public func callAction() {
        action?.call(parameter: managedValue)
    }
    
    @objc public var enabled: Bool {
        get {
            return get {
                return self.control.isEnabled
            }
        }
        
        set {
            set {
                self.control.isEnabled = newValue
            }
        }
    }
    
    @objc public var contentHorizontalAlignment: Int {
        get {
            return get {
                return self.control.contentHorizontalAlignment.rawValue
            }
        }
        
        set {
            set {
                self.control.contentHorizontalAlignment = UIControl.ContentHorizontalAlignment(rawValue: newValue) ?? UIControl.ContentHorizontalAlignment.center
            }
        }
    }
    
    @objc public var contentVerticalAlignment: Int {
        get {
            return get {
                return self.control.contentVerticalAlignment.rawValue
            }
        }
        
        set {
            set {
                self.control.contentVerticalAlignment = UIControl.ContentVerticalAlignment(rawValue: newValue) ?? UIControl.ContentVerticalAlignment.center
            }
        }
    }
    
    @objc static public let ContentHorizontalAlignmentCenter = UIControl.ContentHorizontalAlignment.center
    
    @objc static public let ContentHorizontalAlignmentFill = UIControl.ContentHorizontalAlignment.fill
    
    @objc static public let ContentHorizontalAlignmentLeading = UIControl.ContentHorizontalAlignment.leading
    
    @objc static public let ContentHorizontalAlignmentLeft = UIControl.ContentHorizontalAlignment.left
    
    @objc static public let ContentHorizontalAlignmentRight = UIControl.ContentHorizontalAlignment.right
    
    @objc static public let ContentHorizontalAlignmentTrailing = UIControl.ContentHorizontalAlignment.trailing
    
    @objc static public let ContentVerticalAlignmentBottom = UIControl.ContentVerticalAlignment.bottom
    
    @objc static public let ContentVerticalAlignmentCenter = UIControl.ContentVerticalAlignment.center
    
    @objc static public let ContentVerticalAlignmentFill = UIControl.ContentVerticalAlignment.fill
    
    @objc static public let ContentVerticalAlignmentTop = UIControl.ContentVerticalAlignment.top
    
    /// The control associated with this object.
    @objc public var control: UIControl {
        return get {
            return self.managed as! UIControl
        }
    }
    
    @objc override class func newView() -> PyView {
        return PyControl(managed: get {
            return UIControl()
        })
    }
}
