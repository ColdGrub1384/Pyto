//
//  PyButtonItem.swift
//  Pyto
//
//  Created by Adrian Labbé on 20-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *) @objc public class PyButtonItem: PyWrapper {

    var barButtonItem: UIBarButtonItem {
        return managed as! UIBarButtonItem
    }
    
    @objc public var action: PyValue?
    
    @objc public var managedValue: PyValue?
    
    @objc public func callAction() {
        action?.call(parameter: managedValue)
    }
    
    @objc public var title: String? {
        get {
            return get {
                return self.barButtonItem.title
            }
        }
        
        set {
            set {
                self.barButtonItem.title = newValue
            }
        }
    }
    
    @objc public var image: UIImage? {
        get {
            return get {
                return self.barButtonItem.image
            }
        }
        
        set {
            set {
                self.barButtonItem.image = newValue
            }
        }
    }
    
    @objc public var style: UIBarButtonItem.Style {
        get {
            return get {
                return self.barButtonItem.style
            }
        }
        
        set {
            set {
                self.barButtonItem.style = newValue
            }
        }
    }
    
    @objc public var enabled: Bool {
        get {
            return get {
                return self.barButtonItem.isEnabled
            }
        }
        
        set {
            set {
                self.barButtonItem.isEnabled = newValue
            }
        }
    }
    
    public override init(managed: Any! = NSObject()) {
        super.init(managed: managed)
    }
    
    @objc public init(style: UIBarButtonItem.Style) {
        super.init(managed: PyWrapper.get {
            return UIBarButtonItem(title: nil, style: style, target: nil, action: nil)
        })
        
        set {
            self.barButtonItem.target = self
            self.barButtonItem.action = #selector(self.callAction)
        }
    }
    
    @objc public init(systemItem: UIBarButtonItem.SystemItem) {
        super.init(managed: PyWrapper.get {
            return UIBarButtonItem(barButtonSystemItem: systemItem, target: nil, action: nil)
        })
        
        set {
            self.barButtonItem.target = self
            self.barButtonItem.action = #selector(self.callAction)
        }
    }
    
    @objc public static let StylePlain = UIBarButtonItem.Style.plain
    
    @objc public static let StyleDone = UIBarButtonItem.Style.done
    
    
    @objc public static let SystemItemAction = UIBarButtonItem.SystemItem.action
    
    @objc public static let SystemItemAdd = UIBarButtonItem.SystemItem.add
    
    @objc public static let SystemItemBookmarks = UIBarButtonItem.SystemItem.bookmarks
    
    @objc public static let SystemItemCamera = UIBarButtonItem.SystemItem.camera
    
    @objc public static let SystemItemCancel = UIBarButtonItem.SystemItem.cancel
    
    @objc public static let SystemItemCompose = UIBarButtonItem.SystemItem.compose
    
    @objc public static let SystemItemDone = UIBarButtonItem.SystemItem.done
    
    @objc public static let SystemItemEdit = UIBarButtonItem.SystemItem.edit
    
    @objc public static let SystemItemFastForward = UIBarButtonItem.SystemItem.fastForward
    
    @objc public static let SystemItemFixedSpace = UIBarButtonItem.SystemItem.fixedSpace
    
    @objc public static let SystemItemFlexibleSpace = UIBarButtonItem.SystemItem.flexibleSpace
    
    @objc public static let SystemItemOrganize = UIBarButtonItem.SystemItem.organize
    
    @objc public static let SystemItemPause = UIBarButtonItem.SystemItem.pause
    
    @objc public static let SystemItemPlay = UIBarButtonItem.SystemItem.play
    
    @objc public static let SystemItemRedo = UIBarButtonItem.SystemItem.redo
    
    @objc public static let SystemItemRefresh = UIBarButtonItem.SystemItem.refresh
    
    @objc public static let SystemItemReply = UIBarButtonItem.SystemItem.reply
    
    @objc public static let SystemItemRewind = UIBarButtonItem.SystemItem.rewind
    
    @objc public static let SystemItemSave = UIBarButtonItem.SystemItem.save
    
    @objc public static let SystemItemSearch = UIBarButtonItem.SystemItem.search
    
    @objc public static let SystemItemStop = UIBarButtonItem.SystemItem.stop
    
    @objc public static let SystemItemTrash = UIBarButtonItem.SystemItem.trash
    
    @objc public static let SystemItemUndo = UIBarButtonItem.SystemItem.undo
}
