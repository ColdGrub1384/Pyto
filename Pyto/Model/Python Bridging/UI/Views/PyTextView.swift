//
//  PyTextView.swift
//  Pyto
//
//  Created by Adrian Labbé on 18-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *)
fileprivate class _PyTextView: UITextView {
    
    var html: String?
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        guard html != nil else {
            return
        }
        
        let _html = """
        <style>
            * {
                color: \(UIColor.label.hexString);
                font-family: '.SFNSDisplay-Regular', sans-serif;
            }
        </style>
        
        \(html!)
        """
        
        do {
            let htmlAttrs = try NSAttributedString(data: _html.data(using: .utf8) ?? Data(), options: [.documentType : NSAttributedString.DocumentType.html], documentAttributes: nil)
            attributedText = htmlAttrs
        } catch {
            print(error.localizedDescription)
        }
    }
}

@available(iOS 13.0, *) @objc public class PyTextView: PyView, PyTextInputTraits, UITextViewDelegate {
    
    /// The text view associated with this object.
    @objc public var textView: UITextView {
        return get {
            return self.managed as! UITextView
        }
    }
    
    public override class var pythonName: String {
        return "TextView"
    }
    
    @objc public var managedValue: PyValue?
    
    @objc public var didBeginEditing: PyValue?
    
    @objc public var didChangeText: PyValue?
    
    @objc public var didEndEditing: PyValue?
    
    @objc public func loadHTML(_ html: String) {
        set {
            let _html = """
            <style>
                * {
                    color: \(UIColor.label.hexString);
                    font-family: '.SFNSDisplay-Regular', sans-serif;
                }
            </style>
            
            \(html)
            """
            
            do {
                let htmlAttrs = try NSAttributedString(data: _html.data(using: .utf8) ?? Data(), options: [.documentType : NSAttributedString.DocumentType.html], documentAttributes: nil)
                (self.textView as? _PyTextView)?.html = html
                self.textView.attributedText = htmlAttrs
            } catch {
                print(error.localizedDescription)
            }
        }
    }
    
    @objc public var range: NSArray {
        return get {
            guard let start = self.textView.selectedTextRange?.start, let end = self.textView.selectedTextRange?.end else {
                return NSArray(array: [0, 0])
            }
            
            let startInt = self.textView.offset(from: self.textView.beginningOfDocument, to: start)
            let endInt = self.textView.offset(from: self.textView.beginningOfDocument, to: end)
            
            return NSArray(array: [startInt, endInt])
        }
    }
    
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
                (self.textView as? _PyTextView)?.html = nil
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
                (self.textView as? _PyTextView)?.html = nil
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
                (self.textView as? _PyTextView)?.html = nil
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
    
    required init(managed: Any! = NSObject()) {
        super.init(managed: managed)
        
        DispatchQueue.main.async { [weak self] in
            (managed as? UITextView)?.delegate = self
        }
    }
    
    @objc override class func newView() -> PyView {
        return PyTextView(managed: get {
            let textView = _PyTextView()
            textView.allowsEditingTextAttributes = true
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
        (textView as? _PyTextView)?.html = nil
        didBeginEditing?.call(parameter: managedValue)
    }
    
    public func textViewDidEndEditing(_ textView: UITextView) {
        didEndEditing?.call(parameter: managedValue)
    }
}
