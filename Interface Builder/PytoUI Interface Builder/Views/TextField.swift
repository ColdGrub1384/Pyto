import UIKit

/// An `UITextField`.
public struct TextField: InterfaceBuilderView {
    
    public init() {}
    
    public var type: UIView.Type {
        return UITextField.self
    }
    
    public func preview(view: UIView) {
        let textField = view as! UITextField
        textField.text = "Text"
        textField.frame.size.height = 30
        textField.borderStyle = .roundedRect
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        let textField = view as! UITextField
        textField.frame.size.height = 30
        textField.borderStyle = .roundedRect
        model.customSize.flexibleWidth[view.tag] = true
    }
    
    public var image: UIImage? {
        UIImage(systemName: "character.cursor.ibeam")
    }
}

extension UITextField {
    
    @objc class var UITextField_properties: [Any] {
        return [
            
            InspectorProperty(
                name: "Text",
                valueType: .string,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let textField = view as? UITextField else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: textField.text ?? "")
            }, handler: { (view, value) in
                guard let textField = view as? UITextField else {
                    return
                }
                
                if let text = value.value as? String {
                    textField.text = text
                }
            }),
            
            InspectorProperty(
                name: "Placeholder",
                valueType: .string,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let textField = view as? UITextField else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: textField.placeholder ?? "")
            }, handler: { (view, value) in
                
                guard let textField = view as? UITextField else {
                    return
                }
                
                if let text = value.value as? String {
                    textField.placeholder = text
                }
            }),
            
            InspectorProperty(
                name: "Border Style",
                valueType: .enumeration([
                    "Line",
                    "Bezel",
                    "Rounded Rect",
                    "None"
                ]),
                getValue: { (view) -> InspectorProperty.Value in
                    guard let textField = view as? UITextField else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    switch textField.borderStyle {
                    case .bezel:
                        return .init(value: "Bezel")
                    case .none:
                        return .init(value: "None")
                    case .roundedRect:
                        return .init(value: "Rounded Rect")
                    case .line:
                        return .init(value: "Line")
                    @unknown default:
                        return .init(value: nil)
                    }
            }, handler: { (view, value) in
                
                guard let textField = view as? UITextField else {
                    return
                }
                
                switch value.value as? String {
                case "Bezel":
                    textField.borderStyle = .bezel
                case "None":
                    textField.borderStyle = .none
                case "Rounded Rect":
                    textField.borderStyle = .roundedRect
                case "Line":
                    textField.borderStyle = .line
                default:
                    break
                }
            }),
        ]+TextInputProperties
    }
    
    @objc class var UITextField_connections: [String] {
        ["action"]
    }
}
