//
//  Clipboard.swift
//  InterfaceBuilder
//
//  Created by Emma on 30-10-22.
//

import UIKit

class Clipboard {
    
    static let didChangeNotificationName = Notification.Name("ClipboardDidChange")
    
    static let shared = Clipboard()
    
    private var content: UIView? {
        didSet {
            NotificationCenter.default.post(name: Self.didChangeNotificationName, object: self)
        }
    }
    
    var hasContent: Bool {
        content != nil
    }
    
    func copy(view: UIView) {
        content = view
    }
    
    func clear() {
        content = nil
    }
    
    func paste() -> UIView? {
        guard let content else {
            return nil
        }
        
        return duplicate(view: content)
    }
    
    @available(iOS 16.0, *)
    private func copyAttributes(from view: UIView, to newView: UIView?) {
        
        newView?.interfaceBuilder = view.interfaceBuilder
        
        var tag = Int.random(in: 1...9999)
        while view.interfaceBuilder?.containerView.viewWithTag(tag) != nil {
            tag = Int.random(in: 1...9999)
        }
        
        newView?.tag = tag

        newView?.model = view.model
        
        newView?.customWidth = view.customWidth
        newView?.customHeight = view.customHeight
        newView?.flexibleWidth = view.flexibleWidth
        newView?.flexibleHeight = view.flexibleHeight
        newView?.cornerRadius = view.cornerRadius
        
        newView?.model?.connections[tag] = newView?.model?.connections[view.tag]
        
        if let stack = view as? StackViewContainer, let newStack = newView as? StackViewContainer {
            
            for view in stack.manager.views.enumerated() {
                copyAttributes(from: view.element, to: newStack.manager.views[view.offset])
            }
        }
    }
    
    func duplicate(view: UIView) -> UIView? {
        
        guard #available(iOS 16.0, *) else {
            return nil
        }
        
        let newView = NSKeyedUnarchiver.unarchiveObject(with: NSKeyedArchiver.archivedData(withRootObject: content))! as? UIView
        copyAttributes(from: view, to: newView)
                
        return newView
    }
}
