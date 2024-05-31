import UIKit

/// An `UISwitch`.
public struct Switch: InterfaceBuilderView {
    
    public init() {}
    
    public var type: UIView.Type {
        return UISwitch.self
    }
    
    public func preview(view: UIView) {}
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        view.frame.size.width = 49
        view.frame.size.height = 31
    }
    
    public var image: UIImage? {
        UIImage(systemName: "switch.2")
    }
}

extension UISwitch {
    
    @objc class var UISwitch_properties: [Any] {
        return [
            InspectorProperty(
                name: "Is On",
                valueType: .boolean,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let `switch` = view as? UISwitch else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: `switch`.isOn)
                }, handler: { (view, value) in
                    
                    guard let `switch` = view as? UISwitch else {
                        return
                    }
                    
                    `switch`.isOn = ((value.value as? Bool) == true)
            })
        ]
    }
    
    @objc class var UISwitch_connections: [String] {
        ["action"]
    }
}
