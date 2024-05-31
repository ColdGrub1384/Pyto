import UIKit

/// A property of a view modifiable from the inspector.
///
/// To add your custom properties to a view, extend the UIKit view class with a class variable marked with `@objc` called `<class_name>_properties`. For example, the ``UITextField`` properties are declared like that:
///
/// ```
/// extension UITextField {
///     @objc class var UITextField_properties: [Any] {
///         ...
///     }
/// ```
public struct InspectorProperty: Identifiable {
    
    /// A value type.
    public indirect enum ValueType {
        
        /// An object holding a block that returns a list of values for a dynamic enumeration.
        @objc public class DynamicEnumerationHandlerHolder: NSObject {
            
            /// The block that returns a list of values for a dynamic enumeration.
            public var handler: ((UIView) -> [String])!
            
            /// Initializes the object with the given block.
            ///
            /// - Parameters:
            ///         - handler: The block that returns a list of values for a dynamic enumeration.
            public init(handler: @escaping (UIView) -> [String]) {
                self.handler = handler
            }
        }
        
        /// An integer number.
        case integer
        
        /// Any number.
        case number
        
        /// A string.
        case string
        
        /// A boolean.
        case boolean
        
        /// A color.
        case color
        
        /// A font.
        case font
        
        /// An image.
        case image
        
        /// A bar button item.
        case barItem
        
        /// An enumeration.
        case enumeration([String])
        
        /// A dynamic enumeration
        case dynamicEnumeration(DynamicEnumerationHandlerHolder)
        
        /// An array, with the default value when adding a new one.
        case array(ValueType, (() -> InspectorProperty.Value))
        
        /// An optional value, with a block to get the default value. Can be nil.
        case optional(ValueType, (UIView) -> InspectorProperty.Value)
    }
    
    /// A value.
    public struct Value {
        
        /// The raw value.
        public var value: Any?
    }
    
    /// The name of the property.
    public var name: String
    
    /// The value type.
    public var valueType: ValueType
    
    /// Code called for getting current value.
    public var getValue: ((UIView) -> Value)
    
    /// The code called when the value is modified.
    public var handler: ((UIView, Value) -> Void)
    
    /// A block called to determine whether the property will be shown in the inspector. If `nil`, the property will be shown by default.
    public var isChangeable: ((UIView) -> Bool)?
    
    public var id = UUID()
}
