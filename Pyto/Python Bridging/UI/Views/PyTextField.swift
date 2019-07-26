//
//  PyTextField.swift
//  Pyto
//
//  Created by Adrian Labbé on 19-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

import UIKit
@available(iOS 13.0, *) @objc public class PyTextField: PyView, PyTextInputTraits, UITextFieldDelegate {
    
    /// The text field associated with this object.
    @objc public var textField: UITextField {
        return get {
            return self.managed as! UITextField
        }
    }
    
    @objc public var managedValue: PyValue?
    
    @objc public var didBeginEditing: PyValue?
    
    @objc public var action: PyValue?
    
    @objc public var didEndEditing: PyValue?
    
    @objc public var text: String! {
        get {
            return get {
                return self.textField.text
            }
        }
        
        set {
            set {
                self.textField.text = newValue
            }
        }
    }
    
    @objc public var placeholder: String? {
        get {
            return get {
                return self.textField.placeholder
            }
        }
        
        set {
            set {
                self.textField.placeholder = newValue
            }
        }
    }
    
    @objc public var borderStyle: UITextField.BorderStyle {
        get {
            return get {
                return self.textField.borderStyle
            }
        }
        
        set {
            set {
                self.textField.borderStyle = newValue
            }
        }
    }
    
    @objc public var font: UIFont? {
        get {
            return get {
                return self.textField.font
            }
        }
        
        set {
            set {
                self.textField.font = newValue
            }
        }
    }
    
    @objc public var textColor: PyColor? {
        get {
            return get {
                if let color = self.textField.textColor {
                    return PyColor(managed: color)
                } else {
                    return nil
                }
            }
        }
        
        set {
            set {
                self.textField.textColor = newValue?.color
            }
        }
    }
    
    @objc var textAlignment: Int {
        get {
            return get {
                return self.textField.textAlignment.rawValue
            }
        }
        
        set {
            set {
                self.textField.textAlignment = NSTextAlignment(rawValue: newValue) ?? NSTextAlignment.natural
            }
        }
    }
    
    override init(managed: Any! = NSObject()) {
        super.init(managed: managed)
        
        DispatchQueue.main.async {
            (managed as? UITextField)?.delegate = self
            if (managed as? UITextField)?.allTargets.count == 0 {
                (managed as? UITextField)?.addTarget(self, action: #selector(self.callDidChangeText), for: .editingChanged)
            }
        }
    }
    
    @objc override class func newView() -> PyView {
        return PyTextField(managed: get {
            let textField = UITextField()
            textField.borderStyle = .roundedRect
            textField.sizeToFit()
            
            let toolbar = UIToolbar(frame: CGRect(x: 0, y: 0, width: 0, height: 50))
            toolbar.setItems([UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), UIBarButtonItem(barButtonSystemItem: .done, target: textField, action: #selector(textField.resignFirstResponder))], animated: false)
            toolbar.sizeToFit()
            textField.inputAccessoryView = toolbar
            
            return textField
        })
    }
    
    @objc public func callDidChangeText() {
        action?.call(parameter: managedValue)
    }
    
    public func textFieldDidBeginEditing(_ textField: UITextField) {
        didBeginEditing?.call(parameter: managedValue)
    }
    
    public func textFieldDidEndEditing(_ textField: UITextField) {
        didEndEditing?.call(parameter: managedValue)
    }
    
    public func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        return get {
            return self.textField.resignFirstResponder()
        }
    }
    
    
    @objc public static let BorderStyleNone = UITextField.BorderStyle.none
    
    @objc public static let BorderStyleBezel = UITextField.BorderStyle.bezel
    
    @objc public static let BorderStyleLine = UITextField.BorderStyle.line
    
    @objc public static let BorderStyleRoundedRect = UITextField.BorderStyle.roundedRect
}

