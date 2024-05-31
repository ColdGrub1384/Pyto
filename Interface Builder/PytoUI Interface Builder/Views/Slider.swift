import UIKit

/// An `UISlider`.
public struct Slider: InterfaceBuilderView {
    
    public init() {}
    
    public var type: UIView.Type {
        return UISlider.self
    }
    
    public func preview(view: UIView) {
        (view as! UISlider).value = 1
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        let slider = view as! UISlider
        slider.value = 0.5
        slider.frame.size.width = 118
        slider.frame.size.height = 30
    }
    
    public var image: UIImage? {
        UIImage(systemName: "slider.horizontal.below.rectangle")
    }
}

extension UISlider {
    
    @objc class var UISlider_properties: [Any] {
        return [
            InspectorProperty(
                name: "Value",
                valueType: .number,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let slider = view as? UISlider else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: slider.value)
                }, handler: { (view, propertyValue) in
                    
                    guard let slider = view as? UISlider else {
                        return
                    }
                    
                    let value: Float
                    if let integer = propertyValue.value as? Int {
                        value = Float(exactly: integer) ?? 0
                    } else if let double = propertyValue.value as? Double {
                        value = Float(exactly: double) ?? 0
                    } else if let cgFloat = propertyValue.value as? CGFloat {
                        value = Float(cgFloat)
                    } else {
                        value = propertyValue.value as? Float ?? 0
                    }
                    slider.value = value
                })
        ]
    }
    
    @objc class var UISlider_connections: [String] {
        ["action"]
    }
}
