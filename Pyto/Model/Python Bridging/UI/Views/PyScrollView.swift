//
//  PyScrollView.swift
//  Pyto
//
//  Created by Emma Labbé on 05-02-21.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI

fileprivate class ScrollViewManager: ObservableObject {
    
    @Published var axes: Axis.Set = .vertical {
        willSet {
            objectWillChange.send()
        }
    }
    
    @Published var width: CGFloat? {
        willSet {
            objectWillChange.send()
        }
    }
    
    @Published var height: CGFloat? {
        willSet {
            objectWillChange.send()
        }
    }
}

fileprivate struct PyScrollViewContent: UIViewRepresentable {
    
    var view: UIView
    
    typealias UIViewType = UIView
    
    func makeUIView(context: Context) -> UIView {
        return view
    }
    
    func updateUIView(_ uiView: UIView, context: Context) {
        
    }
}

fileprivate struct _PyScrollView: View {
    
    var content: PyScrollViewContent
    
    @ObservedObject var scrollViewManager: ScrollViewManager
    
    var body: some View {
        ScrollView(scrollViewManager.axes, showsIndicators: true, content: {
            content.frame(width: scrollViewManager.width, height: scrollViewManager.height)
        })
    }
}

@objc public class PyScrollView: PyView {
    
    override func releaseHandler() {
        content.references = 0
    }
    
    @objc let content: PyView
    
    private var manager: ScrollViewManager?
    
    @objc var contentWidth: Double {
        get {
            return Double(manager?.width ?? -1)
        }
        
        set {
            if newValue == -1 {
                manager?.width = 0
            } else {
                manager?.width = CGFloat(newValue)
                content.width = newValue
            }
        }
    }
    
    @objc var contentHeight: Double {
        get {
            return Double(manager?.height ?? -1)
        }
        
        set {
            if newValue == -1 {
                manager?.height = 0
            } else {
                manager?.height = CGFloat(newValue)
                content.height = newValue
            }
        }
    }
    
    @objc var horizontal: Bool {
        get {
            return manager?.axes.contains(.horizontal) == true
        }
        
        set {
            if !horizontal && newValue {
                manager?.axes.update(with: .horizontal)
            } else if horizontal && !newValue {
                manager?.axes.remove(.horizontal)
            }
        }
    }
    
    @objc var vertical: Bool {
        get {
            return manager?.axes.contains(.vertical) == true
        }
        
        set {
            if !vertical && newValue {
                manager?.axes.update(with: .vertical)
            } else if vertical && !newValue {
                manager?.axes.remove(.vertical)
            }
        }
    }
    
    required init(managed: NSObject! = NSObject()) {
        
        self.content = PyView.newView()
        
        super.init(managed: managed)
    }
    
    init(content: UIView) {
        self.content = PyView(managed: content)
        
        let manager = ScrollViewManager()
        
        let scrollView = _PyScrollView(content: PyScrollViewContent(view: content), scrollViewManager: manager)
        let controller = UIHostingController(rootView: scrollView)
                
        super.init(managed: controller.view)
        
        self.manager = manager
    }
    
    @objc override class func newView() -> PyView {
        return get {
            return PyScrollView(content: UIView())
        }
    }
    
    public override class var pythonName: String {
        return "ScrollView"
    }
    
    
}
