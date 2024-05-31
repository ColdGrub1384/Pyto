import UIKit

@available(iOS 15.0, *)
public class InterfaceBuilderButton: UIButton {
    
    var interfaceBuilderButtonConfiguration = "Plain" {
        didSet {
            configuration = buttonConfiguration(named: interfaceBuilderButtonConfiguration)
            configuration?.imagePadding = interfaceBuilderImagePadding
            configuration?.subtitle = interfaceBuilderButtonSubtitle
            configuration?.imagePlacement = NSDirectionalRectEdge(rawValue: interfaceBuilderImagePlacement)
            setupImage()
        }
    }
    
    var interfaceBuilderButtonSubtitle: String? {
        didSet {
            configuration?.subtitle = interfaceBuilderButtonSubtitle
        }
    }
    
    var interfaceBuilderImagePadding: CGFloat = 0 {
        didSet {
            configuration?.imagePadding = interfaceBuilderImagePadding
        }
    }
    
    var interfaceBuilderImagePlacement: UInt = NSDirectionalRectEdge.leading.rawValue {
        didSet {
            configuration?.imagePlacement = NSDirectionalRectEdge(rawValue: interfaceBuilderImagePlacement)
        }
    }
    
    var interfaceBuilderSymbolFont: UIFont? {
        didSet {
            if let interfaceBuilderSymbolFont {
                configuration?.preferredSymbolConfigurationForImage = .init(font: interfaceBuilderSymbolFont)
            } else {
                configuration?.preferredSymbolConfigurationForImage = nil
            }
        }
    }
    
    var interfaceBuilderButtonImage: InspectorImage? {
        didSet {
            setupImage()
        }
    }
    
    func setupImage() {
        guard #available(iOS 16.0, *) else {
            return
        }
        
        if configuration == nil {
            interfaceBuilderButtonConfiguration = "Plain"
        }
        
        guard let interfaceBuilderButtonImage = interfaceBuilderButtonImage else {
            configuration?.image = nil
            return
        }
        
        switch interfaceBuilderButtonImage {
        case .symbol(let name):
            configuration?.image = UIImage(systemName: name)
        case .path(let path):
            let dirURL: URL
            if let url = InterfaceDocument.currentlyDecodingURL?.deletingLastPathComponent() {
                dirURL = url
            } else if let url = interfaceBuilder?.document?.fileURL.deletingLastPathComponent() {
                dirURL = url
            } else {
                break
            }
            
            let imageURL = URL(fileURLWithPath: path, relativeTo: dirURL)
            configuration?.image = UIImage(contentsOfFile: imageURL.path)
        case .data(let data):
            configuration?.image = UIImage(data: data)
        }
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        
        if let config = coder.decodeObject(forKey: "interfaceBuilderButtonConfiguration") as? String {
            interfaceBuilderButtonConfiguration = config
        }
        
        if let imageData = coder.decodeObject(forKey: "interfaceBuilderButtonImage") as? Data {
            interfaceBuilderButtonImage = try? JSONDecoder().decode(InspectorImage.self, from: imageData)
        }
        
        if let padding = coder.decodeObject(forKey: "interfaceBuilderButtonImagePadding") as? CGFloat {
            interfaceBuilderImagePadding = padding
        }
        
        if let placement = coder.decodeObject(forKey: "interfaceBuilderButtonImagePlacement") as? UInt {
            interfaceBuilderImagePlacement = placement
        }
        
        if let symbolFont = coder.decodeObject(forKey: "interfaceBuilderSymbolFont") as? Data, let font = try? NSKeyedUnarchiver.unarchivedObject(ofClass: UIFont.self, from: symbolFont) {
            interfaceBuilderSymbolFont = font
        }
        
        if let subtitle = coder.decodeObject(forKey: "interfaceBuilderButtonSubtitle") as? String {
            interfaceBuilderButtonSubtitle = subtitle
        }
    }
    
    public override func encode(with coder: NSCoder) {
        super.encode(with: coder)
        
        coder.encode(interfaceBuilderButtonConfiguration, forKey: "interfaceBuilderButtonConfiguration")
        coder.encode(interfaceBuilderButtonImage != nil ? try? JSONEncoder().encode(interfaceBuilderButtonImage!) : nil, forKey: "interfaceBuilderButtonImage")
        coder.encode(interfaceBuilderImagePadding, forKey: "interfaceBuilderButtonImagePadding")
        coder.encode(interfaceBuilderImagePlacement, forKey: "interfaceBuilderButtonImagePlacement")
        coder.encode(interfaceBuilderSymbolFont != nil ? (try? NSKeyedArchiver.archivedData(withRootObject: interfaceBuilderSymbolFont!, requiringSecureCoding: false)) : nil, forKey: "interfaceBuilderSymbolFont")
        coder.encode(interfaceBuilderButtonSubtitle, forKey: "interfaceBuilderButtonSubtitle")
    }
}

/// An `UIButton`
public struct Button: InterfaceBuilderView {
    
    public init() {}
    
    func setup(view: UIView) {
        let button = view as! UIButton
        button.frame.size.width = 60
        button.frame.size.height = 30
        button.setTitle("Button", for: .normal)
    }
    
    public var type: UIView.Type {
        if #available(iOS 15.0, *) {
            return InterfaceBuilderButton.self
        } else {
            return UIButton.self
        }
    }
    
    public func preview(view: UIView) {
        setup(view: view)
        view.sizeToFit()
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        setup(view: view)
    }
    
    public func makeView() -> UIView {
        let button: UIButton
        if #available(iOS 15.0, *) {
            button = InterfaceBuilderButton(type: .system)
        } else {
            button = UIButton(type: .system)
        }
        return button
    }
    
    public var image: UIImage? {
        UIImage(systemName: "hand.tap")
    }
}

@available(iOS 15.0, *)
fileprivate func name(for buttonConfiguration: UIButton.Configuration) -> String {
    switch buttonConfiguration {
    case .filled():
        return "Filled"
    case .plain():
        return "Plain"
    case .tinted():
        return "Tinted"
    case .borderedTinted():
        return "Bordered Tinted"
    case .bordered():
        return "Bordered"
    case .borderedProminent():
        return "Bordered Prominent"
    case .borderless():
        return "Borderless"
    case .gray():
        return "Gray"
    default:
        return "Plain"
    }
}

@available(iOS 15.0, *)
fileprivate func buttonConfiguration(named name: String) -> UIButton.Configuration {
    switch name {
    case "Filled":
        return .filled()
    case "Plain":
        return .plain()
    case "Tinted":
        return .tinted()
    case "Bordered Tinted":
        return .borderedTinted()
    case "Bordered":
        return .bordered()
    case "Bordered Prominent":
        return .borderedProminent()
    case "Borderless":
        return .borderless()
    case "Gray":
        return .gray()
    default:
        return .plain()
    }
}

fileprivate func imagePosition(named name: String) -> NSDirectionalRectEdge {
    switch name {
    case "Leading":
        return .leading
    case "Trailing":
        return .trailing
    case "Top":
        return .top
    case "Bottom":
        return .bottom
    default:
        return .leading
    }
}

fileprivate func name(for imagePosition: NSDirectionalRectEdge) -> String {
    switch imagePosition {
    case .leading:
        return "Leading"
    case .trailing:
        return "Trailing"
    case .top:
        return "Top"
    case .bottom:
        return "Bottom"
    default:
        return "Leading"
    }
}

@available(iOS 15.0, *)
extension InterfaceBuilderButton {
    
    @objc class var InterfaceBuilderButton_properties: [Any] {
        return [
            
            InspectorProperty(
                name: "Title",
                valueType: .string,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? UIButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: button.attributedTitle(for: .normal)?.string ?? "")
            }, handler: { (view, value) in
                
                guard let button = view as? UIButton else {
                    return
                }
                
                if let text = value.value as? String {
                    
                    button.setAttributedTitle(NSAttributedString(string: text, attributes: [.font: button.titleLabel?.font ?? UIFont.systemFont(ofSize: UIFont.systemFontSize)]), for: .normal)
                    
                    button.frame.size.width = button.systemLayoutSizeFitting(UIView.layoutFittingCompressedSize).width+10
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
            
            InspectorProperty(
                name: "Title Font",
                valueType: .font,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? UIButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    guard let title = button.attributedTitle(for: .normal), !title.string.isEmpty else {
                        return InspectorProperty.Value(value: button.titleLabel?.font ?? UIFont.systemFont(ofSize: UIFont.systemFontSize))
                    }
                    
                    return InspectorProperty.Value(value: (title.attributes(at: 0, effectiveRange: nil)[.font] as? UIFont) ?? UIFont.systemFont(ofSize: UIFont.systemFontSize))
            }, handler: { (view, value) in
                
                guard let button = view as? UIButton else {
                    return
                }
                
                let titleAttrString = button.attributedTitle(for: .normal) ?? NSAttributedString(string: button.title(for: .normal) ?? "")
                
                guard let font = value.value as? UIFont else {
                    return
                }
                
                button.titleLabel?.font = font
                
                let mutable = NSMutableAttributedString(attributedString: titleAttrString)
                mutable.setAttributes([.font: font], range: NSRange(location: 0, length: titleAttrString.length))
                
                button.setAttributedTitle(mutable, for: .normal)
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: button)
            }),
            
            InspectorProperty(
                name: "Subtitle",
                valueType: .string,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? InterfaceBuilderButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: button.interfaceBuilderButtonSubtitle ?? "")
            }, handler: { (view, value) in
                
                guard let button = view as? InterfaceBuilderButton else {
                    return
                }
                
                if let text = value.value as? String {
                    button.interfaceBuilderButtonSubtitle = text
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
            
            InspectorProperty(
                name: "Style",
                valueType: .enumeration([
                    "Plain",
                    "Tinted",
                    "Filled",
                    "Gray",
                ]),
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? InterfaceBuilderButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: button.interfaceBuilderButtonConfiguration)
            }, handler: { (view, value) in
                
                guard let button = view as? InterfaceBuilderButton else {
                    return
                }
                
                if let name = value.value as? String {
                    button.interfaceBuilderButtonConfiguration = name
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
            
            InspectorProperty(
                name: "Image",
                valueType: .optional(.image, { _ in
                        .init(value: InspectorImage.symbol("play"))
                }),
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? InterfaceBuilderButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: button.interfaceBuilderButtonImage)
            }, handler: { (view, value) in
                
                guard let button = view as? InterfaceBuilderButton else {
                    return
                }
                
                button.interfaceBuilderButtonImage = value.value as? InspectorImage
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
            
            InspectorProperty(
                name: "Image Position",
                valueType: .enumeration([
                    "Leading",
                    "Trailing",
                    "Top",
                    "Bottom",
                ]),
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? InterfaceBuilderButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: name(for: NSDirectionalRectEdge(rawValue: button.interfaceBuilderImagePlacement)))
            }, handler: { (view, value) in
                
                guard let button = view as? InterfaceBuilderButton else {
                    return
                }
                
                if let position = value.value as? String {
                    button.interfaceBuilderImagePlacement = imagePosition(named: position).rawValue
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }, isChangeable: {
                ($0 as? InterfaceBuilderButton)?.interfaceBuilderButtonImage != nil
            }),
            
            InspectorProperty(
                name: "Image Padding",
                valueType: .number,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? InterfaceBuilderButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: button.interfaceBuilderImagePadding)
            }, handler: { (view, propertyValue) in
                
                guard let button = view as? InterfaceBuilderButton else {
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
                button.interfaceBuilderImagePadding = CGFloat(value)
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }, isChangeable: {
                ($0 as? InterfaceBuilderButton)?.interfaceBuilderButtonImage != nil
            }),
            
            InspectorProperty(
                name: "Symbol Font",
                valueType: .font,
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let button = view as? InterfaceBuilderButton else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: button.interfaceBuilderSymbolFont ?? UIFont.systemFont(ofSize: UIFont.systemFontSize))
            }, handler: { (view, value) in
                
                guard let button = view as? InterfaceBuilderButton else {
                    return
                }
                
                button.interfaceBuilderSymbolFont = value.value as? UIFont
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: button)
            }, isChangeable: { view in
                guard let button = view as? InterfaceBuilderButton else {
                    return false
                }
                
                return button.configuration?.image?.isSymbolImage == true
            }),
        ]
    }
    
    @objc class var InterfaceBuilderButton_connections: [String] {
        ["action"]
    }
}
