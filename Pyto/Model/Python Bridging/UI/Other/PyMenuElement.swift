//
//  PyMenuElement.swift
//  Pyto
//
//  Created by Emma on 01-02-23.
//  Copyright © 2023 Emma Labbé. All rights reserved.
//

import Foundation

@available(iOS 15.0, *)
@objc public class PyMenuElement: PyWrapper {
    
    @objc var update: PyValue?
    
    @objc var value: PyValue?
    
    @objc var title = ""
    
    @objc var subtitle: String?
    
    @objc var symbolName: String?
    
    @objc var action: PyValue?
    
    @objc var state = 0
    
    @objc var attributes = 0
    
    @objc var preferredElementSize = 0
    
    @objc var options = 0
    
    @objc var children: NSArray?
    
    @objc var isMenu = false
    
    func makeElement() -> UIMenuElement {
        isMenu ? menu(inline: false) : makeAction()
    }
    
    @objc func makeAction() -> UIAction {
        
        self.update?.call(parameter: value, sync: true)
        
        let action = UIAction(title: title,
                              subtitle: subtitle,
                              image: symbolName != nil ? UIImage(systemName: symbolName!) : nil,
                              identifier: nil,
                              discoverabilityTitle: nil,
                              attributes: UIMenuElement.Attributes(rawValue: UInt(attributes)),
                              state: UIMenuElement.State(rawValue: state) ?? .off) { [weak self] _ in
            self?.action?.call(parameter: self?.value)
        }
        
        return action
    }
   
    func menu(inline: Bool = true) -> UIMenu {
        
        self.update?.call(parameter: value, sync: true)
        
        var options = UIMenu.Options(rawValue: UInt(options))
        if inline {
            options = options.update(with: .displayInline) ?? options
        }
        
        let menu: UIMenu
        if #available(iOS 16.0, *) {
            menu = UIMenu(title: title,
                          subtitle: subtitle,
                          image: symbolName != nil ? UIImage(systemName: symbolName!) : nil,
                          identifier: nil,
                          options: options,
                          preferredElementSize: UIMenu.ElementSize(rawValue: preferredElementSize) ?? .large,
                          children: ((children as? [PyMenuElement]) ?? []).map {
                $0.makeElement()
            })
        } else {
            menu = UIMenu(title: title,
                          subtitle: subtitle,
                          image: symbolName != nil ? UIImage(systemName: symbolName!) : nil,
                          identifier: nil,
                          options: options,
                          children: ((children as? [PyMenuElement]) ?? []).map {
                $0.makeElement()
            })
        }
        
        return menu
    }
    
    @objc func makeMenu() -> UIMenu {
        let menu = UIDeferredMenuElement.uncached { [weak self] block in
            guard let self = self else {
                return block([])
            }
            
            block([self.menu()])
        }
        
        return UIMenu(children: [menu])
    }
}
