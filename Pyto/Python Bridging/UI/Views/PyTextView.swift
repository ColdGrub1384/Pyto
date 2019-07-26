//
//  PyTextView.swift
//  Pyto
//
//  Created by Adrian Labbé on 18-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
@available(iOS 13.0, *) @objc public class PyTextView: PyView, PyTextInputTraits, UITextViewDelegate {
    
    /// The text view associated with this object.
    @objc public var textView: UITextView {
        return get {
            return self.managed as! UITextView
        }
    }
    
    @objc public var managedValue: PyValue?
    
    @objc public var didBeginEditing: PyValue?
    
    @objc public var didChangeText: PyValue?
    
    @objc public var didEndEditing: PyValue?
    
    @objc public var selectable: Bool {
        get {
            return get {
                return self.textView.isSelectable
            }
        }
        
        set {
            set {
                self.textView.isSelectable = newValue
            }
        }
    }
    
    @objc public var editable: Bool {
        get {
            return get {
                return self.textView.isEditable
            }
        }
        
        set {
            set {
                self.textView.isEditable = newValue
            }
        }
    }
    
    @objc public var text: String! {
        get {
            return get {
                return self.textView.text
            }
        }
        
        set {
            set {
                self.textView.text = newValue
            }
        }
    }
    
    @objc public var font: UIFont? {
        get {
            return get {
                return self.textView.font
            }
        }
        
        set {
            set {
                self.textView.font = newValue
            }
        }
    }
    
    @objc public var textColor: PyColor? {
        get {
            return get {
                if let color = self.textView.textColor {
                    return PyColor(managed: color)
                } else {
                    return nil
                }
            }
        }
        
        set {
            set {
                self.textView.textColor = newValue?.color
            }
        }
    }
    
    @objc var textAlignment: Int {
        get {
            return get {
                return self.textView.textAlignment.rawValue
            }
        }
        
        set {
            set {
                self.textView.textAlignment = NSTextAlignment(rawValue: newValue) ?? NSTextAlignment.natural
            }
        }
    }
    
    override init(managed: Any! = NSObject()) {
        super.init(managed: managed)
        
        DispatchQueue.main.async {
            (managed as? UITextView)?.delegate = self
        }
    }
    
    @objc override class func newView() -> PyView {
        return PyTextView(managed: get {
            let textView = UITextView()
            textView.backgroundColor = UIColor.systemBackground
            textView.textColor = UIColor.label
            
            let toolbar = UIToolbar(frame: CGRect(x: 0, y: 0, width: 0, height: 50))
            toolbar.setItems([UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), UIBarButtonItem(barButtonSystemItem: .done, target: textView, action: #selector(textView.resignFirstResponder))], animated: false)
            toolbar.sizeToFit()
            textView.inputAccessoryView = toolbar
            
            return textView
        })
    }
    
    public func textViewDidChange(_ textView: UITextView) {
        didChangeText?.call(parameter: managedValue)
    }
    
    public func textViewDidBeginEditing(_ textView: UITextView) {
        didBeginEditing?.call(parameter: managedValue)
    }
    
    public func textViewDidEndEditing(_ textView: UITextView) {
        didEndEditing?.call(parameter: managedValue)
    }
}
