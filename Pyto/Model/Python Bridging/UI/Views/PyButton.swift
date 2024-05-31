//
//  PyButton.swift
//  Pyto
//
//  Created by Emma Labbé on 30-06-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *) @objc public class PyButton: PyControl {
    
    /// The button associated with this object.
    @objc public var button: UIButton {
        return get {
            return self.managed as! UIButton
        }
    }
    
    public override class var pythonName: String {
        return "Button"
    }
    
    public override var action: PyValue? {
        didSet {
            set {
                if !self.button.allTargets.contains(self) {
                    self.button.addTarget(self, action: #selector(PyControl.callAction), for: .touchUpInside)
                }
            }
        }
    }
    
    #if MAIN
    @available(iOS 15.0, *)
    @objc public override func setMenu(_ menu: PyMenuElement?) {
        set {
            self.button.menu = menu?.makeMenu()
        }
    }
    #endif
    
    @objc public var showsMenuAsPrimaryAction: Bool {
        get {
            get {
                self.button.showsMenuAsPrimaryAction
            }
        }
        
        set {
            set {
                self.button.showsMenuAsPrimaryAction = newValue
            }
        }
    }
    
    @objc override public var title: String? {
        get {
            return get {
                return self.button.title(for: .normal) ?? self.button.attributedTitle(for: .normal)?.string
            }
        }
        
        set {
            set {
                self.button.setAttributedTitle(NSAttributedString(string: newValue ?? "", attributes: [.font: self.button.titleLabel?.font ?? UIFont.systemFont(ofSize: UIFont.systemFontSize)]), for: .normal)
            }
        }
    }
    
    @objc public var subtitle: String? {
        get {
            return get {
                if #available(iOS 15.0, *) {
                    return self.button.configuration?.subtitle
                } else {
                    return nil
                }
            }
        }
        
        set {
            set {
                if #available(iOS 15.0, *) {
                    self.button.configuration?.subtitle = newValue
                }
            }
        }
    }
    
    @objc public var titleColor: PyColor? {
        get {
            return get {
                if let color = self.button.titleColor(for: .normal) {
                    return PyColor(managed: color)
                } else {
                    return nil
                }
            }
        }
        
        set {
            set {
                if let color = newValue?.managed as? UIColor {
                    self.button.setTitleColor(color, for: .normal)
                } else {
                    self.button.setTitleColor(nil, for: .normal)
                }
            }
        }
    }
    
    @objc public var font: UIFont? {
        get {
            return get {
                return self.button.titleLabel?.font
            }
        }
        
        set {
            set {
                self.button.titleLabel?.font = newValue
            }
        }
    }
    
    @objc public var image: UIImage? {
        get {
            return get {
                return self.button.image(for: .normal)
            }
        }
        
        set {
            set {
                self.button.setImage(newValue, for: .normal)
            }
        }
    }
    
    @objc public class func newButton(type: UIButton.ButtonType) -> PyView {
        let pyButton = PyButton()
        pyButton.managed = get {
            let button = UIButton(type: type)
            button.addTarget(pyButton, action: #selector(PyButton.callAction), for: .touchUpInside)
            button.setTitle("Button", for: .normal)
            button.setTitleColor(nil, for: .normal)
            button.sizeToFit()
            PyView.values[button] = pyButton
            return button
        }
        return pyButton
    }
    
    @objc public static let TypeSystem = UIButton.ButtonType.system
    
    @objc public static let TypeContactAdd = UIButton.ButtonType.contactAdd
    
    @objc public static let TypeCustom = UIButton.ButtonType.custom
    
    @objc public static let TypeDetailDisclosure = UIButton.ButtonType.detailDisclosure
    
    @objc public static let TypeInfoDark = UIButton.ButtonType.infoDark
    
    @objc public static let TypeInfoLight = UIButton.ButtonType.infoLight
    
    required init(managed: NSObject! = NSObject()) {
        super.init(managed: managed)
    }
    
    @objc override class func newView() -> PyView {
        return PyButton(managed: get {
            let button = UIButton(type: .system)
            button.addTarget(self, action: #selector(PyButton.callAction), for: .touchUpInside)
            button.setTitle("Button", for: .normal)
            button.setTitleColor(nil, for: .normal)
            button.sizeToFit()
            return button
        })
    }
    
}
