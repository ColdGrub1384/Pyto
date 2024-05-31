import UIKit

public let DidChangeViewPaddingOrFrameNotificationName = Notification.Name("DidChangeViewPaddingNotification")

@available(iOS 16.0, *)
extension UIView {
    
    var cornerRadius: CGFloat {
        get {
            CGFloat(model?.cornerRadius[self.tag] ?? 0)
        }
        
        set {
            model?.cornerRadius[self.tag] = Float(newValue)
        }
    }
    
    var customWidth: CGFloat? {
        get {
            model?.customSize.width[self.tag]
        }
        
        set {
            model?.customSize.width[self.tag] = newValue
        }
    }
    
    var customHeight: CGFloat? {
        get {
            model?.customSize.height[self.tag]
        }
        
        set {
            model?.customSize.height[self.tag] = newValue
        }
    }
    
    var flexibleWidth: Bool {
        get {
            model?.customSize.flexibleWidth[self.tag] ?? false
        }
        
        set {
            model?.customSize.flexibleWidth[self.tag] = newValue
        }
    }
    
    var flexibleHeight: Bool {
        get {
            model?.customSize.flexibleHeight[self.tag] ?? false
        }
        
        set {
            model?.customSize.flexibleHeight[self.tag] = newValue
        }
    }
    
    static var paddingProperties: [InspectorProperty] {
        
        [
            InspectorProperty(
                name: "Top",
                valueType: .number) { view in
                    InspectorProperty.Value(value: view.layoutMargins.top)
                } handler: { view, value in
                    let v: CGFloat
                    if let integer = value.value as? Int {
                        v = CGFloat(integerLiteral: integer)
                    } else if let double = value.value as? Double {
                        v = CGFloat(double)
                    } else if let float = value.value as? Float {
                        v = CGFloat(float)
                    } else {
                        v = value.value as? CGFloat ?? 0
                    }
                        
                    view.layoutMargins.top = v
                    
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
                },
            
            InspectorProperty(
                name: "Bottom",
                valueType: .number) { view in
                    InspectorProperty.Value(value: view.layoutMargins.bottom)
                } handler: { view, value in
                    let v: CGFloat
                    if let integer = value.value as? Int {
                        v = CGFloat(integerLiteral: integer)
                    } else if let double = value.value as? Double {
                        v = CGFloat(double)
                    } else if let float = value.value as? Float {
                        v = CGFloat(float)
                    } else {
                        v = value.value as? CGFloat ?? 0
                    }
                        
                    view.layoutMargins.bottom = v
                    
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
                },
            
            InspectorProperty(
                name: "Left",
                valueType: .number) { view in
                    InspectorProperty.Value(value: view.layoutMargins.left)
                } handler: { view, value in
                    let v: CGFloat
                    if let integer = value.value as? Int {
                        v = CGFloat(integerLiteral: integer)
                    } else if let double = value.value as? Double {
                        v = CGFloat(double)
                    } else if let float = value.value as? Float {
                        v = CGFloat(float)
                    } else {
                        v = value.value as? CGFloat ?? 0
                    }
                        
                    view.layoutMargins.left = v
                    
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
                },
            
            InspectorProperty(
                name: "Right",
                valueType: .number) { view in
                    InspectorProperty.Value(value: view.layoutMargins.right)
                } handler: { view, value in
                    let v: CGFloat
                    if let integer = value.value as? Int {
                        v = CGFloat(integerLiteral: integer)
                    } else if let double = value.value as? Double {
                        v = CGFloat(double)
                    } else if let float = value.value as? Float {
                        v = CGFloat(float)
                    } else {
                        v = value.value as? CGFloat ?? 0
                    }
                        
                    view.layoutMargins.right = v
                    
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
                }
        ]
    }
    
    static var frameProperties: [InspectorProperty] {
        [
            InspectorProperty(
                name: "Flexible Width",
                valueType: .boolean,
                getValue: { (view) -> InspectorProperty.Value in
                    return InspectorProperty.Value(value: view.flexibleWidth)
                },
                handler: { (view, value) in
                    view.flexibleWidth = (value.value as? Bool) ?? false
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view.interfaceBuilder?.containerView ?? view)
                },
                isChangeable: { view in
                    view.customWidth == nil && !(view is StackViewContainer)
                }
            ),
            
            InspectorProperty(
                name: "Flexible Height",
                valueType: .boolean,
                getValue: { (view) -> InspectorProperty.Value in
                    return InspectorProperty.Value(value: view.flexibleHeight)
                },
                handler: { (view, value) in
                    view.flexibleHeight = (value.value as? Bool) ?? false
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view.interfaceBuilder?.containerView ?? view)
                },
                isChangeable: { view in
                    view.customHeight == nil && !(view is StackViewContainer)
                }
            ),
            
            InspectorProperty(
                name: "Custom Width",
                valueType: .optional(.number, { view in
                    .init(value: view.frame.width)
                }),
                getValue: { (view) -> InspectorProperty.Value in
                    return InspectorProperty.Value(value: view.customWidth)
                },
                handler: { (view, value) in
                        
                    let width: CGFloat?
                    if let integer = value.value as? Int {
                        width = CGFloat(integerLiteral: integer)
                    } else if let double = value.value as? Double {
                        width = CGFloat(double)
                    } else if let float = value.value as? Float {
                        width = CGFloat(float)
                    } else {
                        width = value.value as? CGFloat
                    }
                        
                    view.customWidth = width
                    
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view.interfaceBuilder?.containerView ?? view)
                },
                isChangeable: { view in
                    !view.flexibleWidth
                }
            ),
            
            InspectorProperty(
                name: "Custom Height",
                valueType: .optional(.number, { view in
                        .init(value: view.frame.height)
                }),
                getValue: { (view) -> InspectorProperty.Value in
                    return InspectorProperty.Value(value: view.customHeight)
                },
                handler: { (view, value) in
                    
                    let height: CGFloat?
                    if let integer = value.value as? Int {
                        height = CGFloat(integerLiteral: integer)
                    } else if let double = value.value as? Double {
                        height = CGFloat(double)
                    } else if let float = value.value as? Float {
                        height = CGFloat(float)
                    } else {
                        height = value.value as? CGFloat
                    }
                    
                    view.customHeight = height
                    
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view.interfaceBuilder?.containerView ?? view)
                },
                isChangeable: { view in
                    !view.flexibleHeight
                }
            )
        ]
    }
}

extension UIView {
    
    @objc class var UIView_properties: [Any] {
        [
            InspectorProperty(name: "Background Color", valueType: .color, getValue: { view in
                InspectorProperty.Value(value: view.backgroundColor ?? UIColor.clear)
            }, handler: { view, value in
                view.backgroundColor = value.value as? UIColor
            }),
            
            InspectorProperty(name: "Tint Color", valueType: .color, getValue: { view in
                InspectorProperty.Value(value: view.tintColor ?? UIColor.clear)
            }, handler: { view, value in
                view.tintColor = value.value as? UIColor
            }),
            
            InspectorProperty(name: "Hidden", valueType: .boolean, getValue: { view in
                InspectorProperty.Value(value: view.isHidden)
            }, handler: { view, value in
                view.isHidden = (value.value as? Bool) ?? false
            }),
            
            InspectorProperty(name: "Corner Radius", valueType: .number, getValue: { view in
                if #available(iOS 16.0, *) {
                    return InspectorProperty.Value(value: view.cornerRadius)
                } else {
                    return InspectorProperty.Value(value: 0)
                }
            }, handler: { view, value in
                let cornerRadius: CGFloat
                if let integer = value.value as? Int {
                    cornerRadius = CGFloat(integerLiteral: integer)
                } else if let double = value.value as? Double {
                    cornerRadius = CGFloat(double)
                } else if let float = value.value as? Float {
                    cornerRadius = CGFloat(float)
                } else {
                    cornerRadius = value.value as? CGFloat ?? 0
                }
                
                if #available(iOS 16.0, *) {
                    view.cornerRadius = cornerRadius
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
        ]
    }
}

internal class WeakWrapper : NSObject {
    weak var weakObject : NSObject?

    init(_ weakObject: NSObject?) {
        self.weakObject = weakObject
    }
}

fileprivate var interfaceBuilderKey = "interfaceBuilder"
fileprivate var modelKey = "interfaceBuilderModel"

@available(iOS 16.0, *)
public extension UIView {
    
    var model: InterfaceModel? {
        get {
            if let model = interfaceBuilder?.model {
                return model
            } else if let data = objc_getAssociatedObject(self, &modelKey) as? Data {
                return try? JSONDecoder().decode(InterfaceModel.self, from: data)
            } else {
                return nil
            }
        }
        
        set {
            guard let data = try? JSONEncoder().encode(newValue) else {
                return
            }
            
            objc_setAssociatedObject(self, &modelKey, data, objc_AssociationPolicy.OBJC_ASSOCIATION_RETAIN)
            
            if let model = newValue {
                interfaceBuilder?.model = model
            }
        }
    }
    
    var interfaceBuilder: InterfaceBuilderViewController? {
        get {
            let obj = objc_getAssociatedObject(self, &interfaceBuilderKey)
            if let builder = obj as? InterfaceBuilderViewController {
                return builder
            }
            let weakWrapper: WeakWrapper? = obj as? WeakWrapper
            return weakWrapper?.weakObject as? InterfaceBuilderViewController
        }
        set {
            var weakWrapper: WeakWrapper? = objc_getAssociatedObject(self, &interfaceBuilderKey) as? WeakWrapper
            if weakWrapper == nil {
                weakWrapper = WeakWrapper(newValue)
                objc_setAssociatedObject(self, &interfaceBuilderKey, weakWrapper, objc_AssociationPolicy.OBJC_ASSOCIATION_RETAIN)
            } else {
                weakWrapper!.weakObject = newValue
            }
        }
    }
}
