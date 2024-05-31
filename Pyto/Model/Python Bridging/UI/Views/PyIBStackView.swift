//
//  PyIBStackView.swift
//  Pyto
//
//  Created by Emma on 11-07-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import UIKit
import InterfaceBuilder

@available(iOS 16.0, *)
extension StackViewContainer {
    
    @objc func getSubviews() -> [UIView] {
        manager.views
    }
}

@available(iOS 16.0, *)
class PyIBStackView: PyView {
    
    override class var pythonName: String {
        "StackView"
    }
    
    override func releaseHandler() {
        set {
            self.manager.views = []
        }
    }
    
    public override var subviews: NSArray {
        NSArray(array: get {
            self.manager.views
        }.compactMap({ PyView.values[$0] }))
    }
    
    public override func addSubview(_ view: PyView) {
        manager.views.append(view.view)
    }
    
    public override func insertSubview(_ view: PyView, at index: Int) {
        manager.views.insert(view.view, at: index)
    }
    
    public override func insertSubview(_ view: PyView, below subview: PyView) {
        var i = 0
        for v in manager.views {
            
            if v == subview.view {
                manager.views.insert(view.view, at: i-1)
            }
            
            i += 1
        }
    }
    
    public override func insertSubview(_ view: PyView, above subview: PyView) {
        var i = 0
        for v in manager.views {
            
            if v == subview.view {
                manager.views.insert(view.view, at: i+1)
            }
            
            i += 1
        }
    }
    
    fileprivate var manager: InterfaceBuilder.StackViewManager! {
        (view as! StackViewContainer).manager
    }
    
    required init(managed: NSObject! = NSObject()) {
        super.init(managed: managed)
    }
}
