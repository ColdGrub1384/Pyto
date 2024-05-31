//
//  ImageView.swift
//  InterfaceBuilder
//
//  Created by Emma on 21-08-22.
//

import UIKit

/// An `UIImageView` created with the interface builder.
public class InterfaceBuilderImageView: UIView {
    
    var imageView: UIImageView!
    
    var image: UIImage? {
        get {
            imageView?.image
        }
        
        set {
            imageView?.image = newValue
        }
    }
    
    func setupImageView() {
        
        guard imageView == nil else {
            return
        }
        
        imageView = UIImageView()
        imageView.clipsToBounds = true
        imageView.frame = frame
        imageView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        addSubview(imageView)
    }
    
    public override var intrinsicContentSize: CGSize {
        if image == nil && interfaceBuilderImage != nil {
            setupImage()
        }
        return imageView?.intrinsicContentSize ?? CGSize(width: 10, height: 10)
    }
    
    init() {
        super.init(frame: .zero)
        setupImageView()
    }
    
    var imageViewContentMode: UIView.ContentMode = .scaleToFill {
        didSet {
            imageView?.contentMode = imageViewContentMode
        }
    }
    
    func setupImage() {
        guard #available(iOS 16.0, *) else {
            return
        }
        
        guard let image = interfaceBuilderImage else {
            self.image = nil
            return
        }
        
        switch image {
        case .symbol(let name):
            self.image = UIImage(systemName: name)
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
            self.image = UIImage(contentsOfFile: imageURL.path)
        case .data(let data):
            self.image = UIImage(data: data)
        }
        
        setContentCompressionResistancePriority(.defaultLow, for: .horizontal)
        setContentCompressionResistancePriority(.defaultLow, for: .vertical)
        imageView.contentMode = imageViewContentMode
    }
    
    var interfaceBuilderImage: InspectorImage? {
        didSet {
            setupImage()
        }
    }
    
    public required init?(coder: NSCoder) {
        super.init(coder: coder)
        
        if let contentMode = UIView.ContentMode(rawValue: coder.decodeInteger(forKey: "imageViewContentMode")) {
            imageViewContentMode = contentMode
        }
        
        if let data = coder.decodeObject(forKey: "interfaceBuilderImage") as? Data, let image = try? JSONDecoder().decode(InspectorImage.self, from: data) {
            setupImageView()
            interfaceBuilderImage = image
        }
        
        imageView.contentMode = imageViewContentMode
    }
    
    public override func encode(with coder: NSCoder) {
        imageView.removeFromSuperview()
        if let image = interfaceBuilderImage, let data = try? JSONEncoder().encode(image) {
            coder.encode(data, forKey: "interfaceBuilderImage")
        } else {
            coder.encode(nil, forKey: "interfaceBuilderImage")
        }
        coder.encode(imageViewContentMode.rawValue, forKey: "imageViewContentMode")
        super.encode(with: coder)
        addSubview(imageView)
    }
}

/// An `UIImageView`
public struct ImageView: InterfaceBuilderView {
    
    public init() {}
    
    func setup(view: UIView) {
        let imageView = view as! InterfaceBuilderImageView
        imageView.imageView.contentMode = .scaleToFill
        imageView.interfaceBuilderImage = .symbol("photo")
        imageView.sizeToFit()
    }
    
    public var type: UIView.Type {
        return InterfaceBuilderImageView.self
    }
    
    public func preview(view: UIView) {
        setup(view: view)
        view.frame.size = CGSize(width: 24, height: 20)
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        setup(view: view)
    }
    
    public func makeView() -> UIView {
        InterfaceBuilderImageView()
    }
    
    public var image: UIImage? {
        UIImage(systemName: "photo")
    }
}

fileprivate func name(from contentMode: UIView.ContentMode) -> String {
    switch contentMode {
    case .scaleToFill:
        return "Scale to Fill"
    case .scaleAspectFit:
        return "Scale Aspect Fit"
    case .scaleAspectFill:
        return "Scale Aspect Fill"
    case .redraw:
        return "Redraw"
    case .center:
        return "Center"
    case .top:
        return "Top"
    case .bottom:
        return "Bottom"
    case .left:
        return "Left"
    case .right:
        return "Right"
    case .topLeft:
        return "Top Left"
    case .topRight:
        return "Top Right"
    case .bottomLeft:
        return "Bottom Left"
    case .bottomRight:
        return "Bottom Right"
    @unknown default:
        return "Scale to Fill"
    }
}

fileprivate func _contentMode(named name: String) -> UIView.ContentMode {
    switch name {
    case "Scale to Fill":
        return .scaleToFill
    case "Scale Aspect Fit":
        return .scaleAspectFit
    case "Scale Aspect Fill":
        return .scaleAspectFill
    case "Redraw":
        return .redraw
    case "Center":
        return .center
    case "Top":
        return .top
    case "Bottom":
        return .bottom
    case "Left":
        return .left
    case "Right":
        return .right
    case "Top Left":
        return .topLeft
    case "Top Right":
        return .topRight
    case "Bottom Left":
        return .bottomLeft
    case "Bottom Right":
        return .bottomRight
    default:
        return .scaleToFill
    }
}

extension InterfaceBuilderImageView {
    
    @objc class var InterfaceBuilderImageView_properties: [Any] {
        return [
            
            InspectorProperty(
                name: "Image",
                valueType: .optional(.image, { _ in
                    .init(value: InspectorImage.symbol("photo"))
                }),
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let imageView = view as? InterfaceBuilderImageView else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: imageView.interfaceBuilderImage)
            }, handler: { (view, value) in
                
                guard let imageView = view as? InterfaceBuilderImageView else {
                    return
                }
                
                if let image = value.value as? InspectorImage {
                    imageView.interfaceBuilderImage = image
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
            
            InspectorProperty(
                name: "Content Mode",
                valueType: .enumeration([
                    UIView.ContentMode.scaleToFill,
                    UIView.ContentMode.scaleAspectFit,
                    UIView.ContentMode.scaleAspectFill,
                    UIView.ContentMode.bottomLeft,
                    UIView.ContentMode.bottomRight,
                    UIView.ContentMode.left,
                    UIView.ContentMode.redraw,
                    UIView.ContentMode.right,
                    UIView.ContentMode.top,
                    UIView.ContentMode.bottom,
                    UIView.ContentMode.topLeft,
                    UIView.ContentMode.topRight,
                    UIView.ContentMode.center
                ].map { name(from: $0) }),
                getValue: { (view) -> InspectorProperty.Value in
                    
                    guard let imageView = view as? InterfaceBuilderImageView else {
                        return InspectorProperty.Value(value: 0)
                    }
                    
                    return InspectorProperty.Value(value: name(from: imageView.imageViewContentMode))
            }, handler: { (view, value) in
                
                guard let imageView = view as? InterfaceBuilderImageView else {
                    return
                }
                
                guard let str = value.value as? String else {
                    return
                }
                
                imageView.imageViewContentMode = _contentMode(named: str)
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
        ]
    }
}
