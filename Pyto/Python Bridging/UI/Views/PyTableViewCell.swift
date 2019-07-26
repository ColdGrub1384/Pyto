//
//  PyTableViewCell.swift
//  Pyto
//
//  Created by Adrian Labbé on 18-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

extension UITableViewCell {
    
    private struct Holder {
        static var canBeDeleted = [UITableViewCell:Bool]()
        static var canBeMoved = [UITableViewCell:Bool]()
    }
    
    /// A boolean indicating if the cell can be deleted, set from Python API. The setter is only used internally and has no effect.
    var canBeDeleted: Bool {
        get {
            return Holder.canBeDeleted[self] ?? false
        }
        
        set {
            Holder.canBeDeleted[self] = newValue
        }
    }
    
    /// A boolean indicating if the cell can be moved, set from Python API. The setter is only used internally and has no effect.
    var canBeMoved: Bool {
        get {
            return Holder.canBeMoved[self] ?? false
        }
        
        set {
            Holder.canBeMoved[self] = newValue
        }
    }
}

@available(iOS 13.0, *) @objc public class PyTableViewCell: PyView {
    
    /// The cell associated with this object.
    @objc public var cell: UITableViewCell {
        return get {
            return self.managed as! UITableViewCell
        }
    }
    
    @objc public var managedValue: PyValue?
    
    @objc public var removable: Bool {
        get {
            return get {
                return self.cell.canBeDeleted
            }
        }
        
        set {
            set {
                self.cell.canBeDeleted = newValue
            }
        }
    }
    
    @objc public var movable: Bool {
        get {
            return get {
                return self.cell.canBeMoved
            }
        }
        
        set {
            set {
                self.cell.canBeMoved = newValue
            }
        }
    }
    
    @objc public var contentView: PyView {
        return get {
            return PyView(managed: self.cell.contentView)
        }
    }
    
    @objc public var imageView: PyImageView? {
        get {
            return get {
                if let view = self.cell.imageView {
                    return PyImageView(managed: view)
                } else {
                    return nil
                }
            }
        }
    }
    
    @objc public var textLabel: PyLabel? {
        return get {
            if let label = self.cell.textLabel {
                return PyLabel(managed: label)
            } else {
                return nil
            }
        }
    }
    
    @objc public var detailLabel: PyLabel? {
        return get {
            if let label = self.cell.detailTextLabel {
                return PyLabel(managed: label)
            } else {
                return nil
            }
        }
    }
    
    @objc public var accessoryType: UITableViewCell.AccessoryType {
        get {
            return get {
                return self.cell.accessoryType
            }
        }
        
        set {
            set {
                self.cell.accessoryType = newValue
            }
        }
    }
    
    override init(managed: Any! = NSObject()) {
        super.init(managed: managed)
    }
    
    @objc class func newView(style: UITableViewCell.CellStyle) -> PyView {
        return PyTableViewCell(managed: get {
            return UITableViewCell(style: style, reuseIdentifier: nil)
        })
    }
    
    @objc override class func newView() -> PyView {
        return PyTableViewCell(managed: get {
            return UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        })
    }
    
    @objc public static let StyleDefault = UITableViewCell.CellStyle.default
    
    @objc public static let StyleSubtitle = UITableViewCell.CellStyle.subtitle
    
    @objc public static let StyleValue1 = UITableViewCell.CellStyle.value1
    
    @objc public static let StyleValue2 = UITableViewCell.CellStyle.value2
    
    
    @objc public static let AccessoryTypeNone = UITableViewCell.AccessoryType.none
    
    @objc public static let AccessoryTypeCheckmark = UITableViewCell.AccessoryType.checkmark
    
    @objc public static let AccessoryTypeDetailButton = UITableViewCell.AccessoryType.detailButton
    
    @objc public static let AccessoryTypeDetailDisclosureButton = UITableViewCell.AccessoryType.detailDisclosureButton
    
    @objc public static let AccessoryTypeDisclosureIndicator = UITableViewCell.AccessoryType.disclosureIndicator    
}
