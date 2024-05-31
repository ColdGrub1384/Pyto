import UIKit

/// An `UIStepper`.
public struct Stepper: InterfaceBuilderView {
    
    public init() {}
    
    public var type: UIView.Type {
        return UIStepper.self
    }
    
    public func preview(view: UIView) {}
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        view.frame.size.width = 94
        view.frame.size.height = 29
    }
    
    public var image: UIImage? {
        UIImage(systemName: "plus.forwardslash.minus")
    }
}

extension UIStepper {
    
    @objc class var UIStepper_properties: [Any] {
        return [
            
            InspectorProperty(
                name: "Minimum Value",
                valueType: .number,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let stepper = view as? UIStepper else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: stepper.minimumValue)
                }, handler: { (view, propertyValue) in
                    
                    guard let stepper = view as? UIStepper else {
                        return
                    }
                    
                    let value: Double
                    if let integer = propertyValue.value as? Int {
                        value = Double(exactly: integer) ?? 0
                    } else if let double = propertyValue.value as? Double {
                        value = double
                    } else if let cgFloat = propertyValue.value as? CGFloat {
                        value = Double(cgFloat)
                    } else {
                        value = propertyValue.value as? Double ?? 0
                    }
                    stepper.minimumValue = value
                }),
            
            InspectorProperty(
                name: "Maximum Value",
                valueType: .number,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let stepper = view as? UIStepper else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: stepper.maximumValue)
                }, handler: { (view, propertyValue) in
                    
                    guard let stepper = view as? UIStepper else {
                        return
                    }
                    
                    let value: Double
                    if let integer = propertyValue.value as? Int {
                        value = Double(exactly: integer) ?? 0
                    } else if let double = propertyValue.value as? Double {
                        value = double
                    } else if let cgFloat = propertyValue.value as? CGFloat {
                        value = Double(cgFloat)
                    } else {
                        value = propertyValue.value as? Double ?? 0
                    }
                    stepper.maximumValue = value
                }),
            
            InspectorProperty(
                name: "Step Value",
                valueType: .number,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let stepper = view as? UIStepper else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: stepper.stepValue)
                }, handler: { (view, propertyValue) in
                    
                    guard let stepper = view as? UIStepper else {
                        return
                    }
                    
                    let value: Double
                    if let integer = propertyValue.value as? Int {
                        value = Double(exactly: integer) ?? 0
                    } else if let double = propertyValue.value as? Double {
                        value = double
                    } else if let cgFloat = propertyValue.value as? CGFloat {
                        value = Double(cgFloat)
                    } else {
                        value = propertyValue.value as? Double ?? 0
                    }
                    stepper.stepValue = value
                }),
            
            InspectorProperty(
                name: "Value",
                valueType: .number,
                getValue: { (view) -> InspectorProperty.Value in
                    guard let stepper = view as? UIStepper else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: stepper.value)
                }, handler: { (view, propertyValue) in
                    
                    guard let stepper = view as? UIStepper else {
                        return
                    }
                    
                    let value: Double
                    if let integer = propertyValue.value as? Int {
                        value = Double(exactly: integer) ?? 0
                    } else if let double = propertyValue.value as? Double {
                        value = double
                    } else if let cgFloat = propertyValue.value as? CGFloat {
                        value = Double(cgFloat)
                    } else {
                        value = propertyValue.value as? Double ?? 0
                    }
                    stepper.value = value
                })
        ]
    }
    
    @objc class var UIStepper_connections: [String] {
        ["action"]
    }
}
