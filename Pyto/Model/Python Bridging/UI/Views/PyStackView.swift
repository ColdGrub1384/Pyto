//
//  PyStackView.swift
//  Pyto
//
//  Created by Emma Labbé on 06-02-21.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI

fileprivate class StackViewManager: ObservableObject {
    
    let axis: Int
    
    var padding = EdgeInsets(top: 0, leading: 0, bottom: 0, trailing: 0)
    
    init(axis: Int) {
        self.axis = axis
    }
    
    var views = [PyView]() {
        willSet {
            objectWillChange.send()
        }
    }
}

fileprivate struct StackViewContained: UIViewRepresentable {
    
    let view: UIView
    
    typealias UIViewType = UIView
    
    func makeUIView(context: Context) -> UIView {
        return view
    }
    
    func updateUIView(_ uiView: UIView, context: Context) {
        
    }
}

fileprivate struct _PyStackView: View {
    
    @ObservedObject var manager: StackViewManager
    
    var content: some View {
        ForEach(manager.views, id: \.id) { item in
            if !(item is PyStackSpacerView) {
                if item._setSize {
                    StackViewContained(view: item.view).frame(width: CGFloat(item.width), height: CGFloat(item.height))
                } else if !(item is PyTableView) {
                    StackViewContained(view: item.view).fixedSize()
                } else {
                    StackViewContained(view: item.view)
                }
            } else {
                Spacer()
            }
        }
    }
    
    var body: some View {
        if manager.axis == 0 {
            HStack {
                content
            }.padding(manager.padding)
        } else if manager.axis == 1 {
            VStack {
                content
            }.padding(manager.padding)
        } else {
            Text("Invalid axis")
        }
    }
}

@objc public class PyStackSpacerView: PyView {
    
    override class func newView() -> PyView {
        return PyStackSpacerView(managed: get {
            return UIView()
        })
    }
    
    public override class var pythonName: String {
        return "_StackSpacerView"
    }
}

@objc public class PyStackView: PyView {
    
    override func releaseHandler() {
        set {
            /*for view in self.manager.views {
                view.releaseReference()
            }*/
            self.manager.views = []
        }
    }
    
    @objc public var padding: [Double] {
        get {
            return get {
                return [Double(self.manager.padding.top), Double(self.manager.padding.bottom), Double(self.manager.padding.leading), Double(self.manager.padding.trailing)]
            }
        }
        
        set {
            set {
                self.manager.padding = EdgeInsets(top: CGFloat(newValue[0]), leading: CGFloat(newValue[2]), bottom: CGFloat(newValue[1]), trailing: CGFloat(newValue[3]))
            }
        }
    }
    
    public override var subviews: NSArray {
        return NSArray(array: manager.views)
    }
    
    public override func addSubview(_ view: PyView) {
        manager.views.append(view)
    }
    
    public override func insertSubview(_ view: PyView, at index: Int) {
        manager.views.insert(view, at: index)
    }
    
    public override func insertSubview(_ view: PyView, below subview: PyView) {
        var i = 0
        for v in manager.views {
            
            if v.view == subview.view {
                manager.views.insert(view, at: i-1)
            }
            
            i += 1
        }
    }
    
    public override func insertSubview(_ view: PyView, above subview: PyView) {
        var i = 0
        for v in manager.views {
            
            if v.view == subview.view {
                manager.views.insert(view, at: i+1)
            }
            
            i += 1
        }
    }
    
    fileprivate let manager: StackViewManager
    
    required init(managed: NSObject! = NSObject()) {
        self.manager = StackViewManager(axis: -1)
        super.init(managed: managed)
    }
    
    fileprivate init(managed: NSObject! = NSObject(), manager: StackViewManager) {
        self.manager = manager
        super.init(managed: managed)
    }
    
    @objc class func horizontal() -> PyView {
        
        let manager = StackViewManager(axis: 0)
        
        let view = PyStackView(managed: get {
            let controller = UIHostingController(rootView: _PyStackView(manager: manager))
            return controller.view
        }, manager: manager)
        return view
    }
    
    @objc class func vertical() -> PyView {
        let manager = StackViewManager(axis: 1)
        
        let view = PyStackView(managed: get {
            let controller = UIHostingController(rootView: _PyStackView(manager: manager))
            return controller.view
        }, manager: manager)
        return view
    }
    
    public override class var pythonName: String {
        return "StackView"
    }
}
