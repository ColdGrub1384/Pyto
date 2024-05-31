//
//  TextView.swift
//  InterfaceBuilder
//
//  Created by Emma on 06-09-22.
//

import UIKit

/// An `UITextView`.
public struct TextView: InterfaceBuilderView {
    
    public init() {}
    
    public var type: UIView.Type {
        return UITextView.self
    }
    
    public func preview(view: UIView) {
        view.backgroundColor = .secondarySystemBackground
        view.frame.size = CGSize(width: 40, height: 40)
        view.layer.borderColor = UIColor.gray.cgColor
        view.layer.borderWidth = 1
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        model.customSize.flexibleHeight[view.tag] = true
        model.customSize.flexibleWidth[view.tag] = true
    }
    
    public var image: UIImage? {
        UIImage(systemName: "note.text")
    }
}

extension UITextView {
    
    @objc class var UITextView_properties: [Any] {
        return [
            
            InspectorProperty(
                name: "Text",
                valueType: .string,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let textView = view as? UITextView else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: textView.text ?? "")
            }, handler: { (view, value) in
                guard let textView = view as? UITextView else {
                    return
                }
                
                if let text = value.value as? String {
                    textView.text = text
                }
            }),
            
            InspectorProperty(
                name: "Font",
                valueType: .font,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let textView = view as? UITextView else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: textView.font ?? UIFont.systemFont(ofSize: UIFont.systemFontSize))
            }, handler: { (view, value) in
                
                guard let textView = view as? UITextView else {
                    return
                }
                
                textView.font = value.value as? UIFont
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: textView)
            }),
            
            InspectorProperty(
                name: "Text Color",
                valueType: .color,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let textView = view as? UITextView else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: textView.textColor ?? .label)
            }, handler: { (view, value) in
                
                guard let textView = view as? UITextView else {
                    return
                }
                
                textView.textColor = value.value as? UIColor
            }),
            
            InspectorProperty(
                name: "Editable",
                valueType: .boolean,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let textView = view as? UITextView else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: textView.isEditable)
            }, handler: { (view, value) in
                guard let textView = view as? UITextView else {
                    return
                }
                
                if let isEditable = value.value as? Bool {
                    textView.isEditable = isEditable
                }
            }),
        ]+TextInputProperties
    }
    
    @objc class var UITextView_connections: [String] {
        ["action"]
    }
}
