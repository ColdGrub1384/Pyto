import UIKit

/// An `UILabel`.
public struct Label: InterfaceBuilderView {
    
    public init() {}
    
    func setup(view: UIView) {
        let label = view as! UILabel
        label.text = "Label"
        label.frame.size.height = 30
        label.frame.size.width = (view as! UILabel).systemLayoutSizeFitting(UIView.layoutFittingCompressedSize).width
    }
    
    public var type: UIView.Type {
        return UILabel.self
    }
    
    public func preview(view: UIView) {
       setup(view: view)
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        setup(view: view)
    }
    
    public var image: UIImage? {
        UIImage(systemName: "textformat.abc")
    }
}

extension UILabel {
    
    @objc class var UILabel_properties: [Any] {
        return [
            
            InspectorProperty(
                name: "Text",
                valueType: .string,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let label = view as? UILabel else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: label.text ?? "")
            }, handler: { (view, value) in
                
                guard let label = view as? UILabel else {
                    return
                }
                
                if let text = value.value as? String {
                    label.text = text
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: label)
            }),
            
            InspectorProperty(
                name: "Font",
                valueType: .font,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let label = view as? UILabel else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: label.font ?? UIFont.systemFont(ofSize: UIFont.systemFontSize))
            }, handler: { (view, value) in
                
                guard let label = view as? UILabel else {
                    return
                }
                
                label.font = value.value as? UIFont
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: label)
            }),
            
            InspectorProperty(
                name: "Text Color",
                valueType: .color,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let label = view as? UILabel else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: label.textColor ?? .label)
            }, handler: { (view, value) in
                
                guard let label = view as? UILabel else {
                    return
                }
                
                label.textColor = value.value as? UIColor
            }),
            
            InspectorProperty(
                name: "Text Alignment",
                valueType: .enumeration([
                    "Natural",
                    "Center",
                    "Left",
                    "Right",
                    "Justified"
                ]),
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let label = view as? UILabel else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    let repr: String
                    switch label.textAlignment {
                        case .center:
                            repr = "Center"
                        case .justified:
                            repr = "Justified"
                        case .left:
                            repr = "Left"
                        case .natural:
                            repr = "Natural"
                        case .right:
                            repr = "Right"
                        @unknown default:
                            repr = "Unknown"
                    }
                    
                    return InspectorProperty.Value(value: repr)
            }, handler: { (view, value) in
                
                guard let label = view as? UILabel else {
                    return
                }
                
                switch value.value as? String {
                case "Center":
                    label.textAlignment = .center
                case "Justified":
                    label.textAlignment = .justified
                case "Left":
                    label.textAlignment = .left
                case "Natural":
                    label.textAlignment = .natural
                case "Right":
                    label.textAlignment = .right
                default:
                    break
                }
            }),
            
            InspectorProperty(
                name: "Number of lines",
                valueType: .integer,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let label = view as? UILabel else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: label.numberOfLines)
            }, handler: { (view, value) in
                
                guard let label = view as? UILabel else {
                    return
                }
                
                label.numberOfLines = (value.value as? Int) ?? label.numberOfLines
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: label)
            }),
        ]
    }
}
