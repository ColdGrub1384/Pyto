//
//  View Controller Presentation.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 30-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

// MARK: - View controllers presentation

/// A View Controller containing another View Controller. This is because `UIViewControllerRepresentable` must always return a new instance of `UIViewController` so it returns a new instance of `ContainerViewController` containing the View Controller to display.
public class ContainerViewController: UIViewController {
    
    /// Updates the NavigationItem and the toolbar.
    public func update() {
        if let child = children.first {
            parent?.navigationItem.rightBarButtonItems = child.navigationItem.rightBarButtonItems
            parent?.toolbarItems = child.toolbarItems
            parent?.title = child.title
            
            if traitCollection.horizontalSizeClass == .compact {
                parent?.navigationItem.leftBarButtonItem = child.navigationItem.leftBarButtonItem
            } else if (child.navigationItem.leftBarButtonItems?.count ?? 0) > 1{
                parent?.navigationItem.leftBarButtonItems = child.navigationItem.leftBarButtonItems
            } else {
                parent?.navigationItem.leftBarButtonItems = []
            }
        }
    }
    
    public override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        update()
    }
}

/// A protocol that can tell to its SwiftUI container to update its Navigation Item.
public protocol ContainedViewController {

    /// The container view controller. Will be set automatically, so just set it to `nil`. Use this instance to call `ContainerViewController.update` when a change is made.
    var container: ContainerViewController? { get set }
}


/// A View Controller represented in SwiftUI.
@available(iOS 13.4, *)
public struct ViewController: UIViewControllerRepresentable {
    
    /// The UIKit View Controller.
    var viewController: UIViewController
    
    /// Initialize with a given VC.
    ///
    /// - Parameters:
    ///     - viewController: The UIKit View Controller.
    public init(viewController: UIViewController) {
        self.viewController = viewController
    }
    
    public func makeUIViewController(context: Context) -> some UIViewController {
        let vc = ContainerViewController()
        viewController.removeFromParent()
        viewController.view.removeFromSuperview()
        vc.addChild(viewController)
        vc.view.addSubview(viewController.view)
        viewController.view.frame = vc.view.frame
        viewController.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        var contained = viewController as? (UIViewController & ContainedViewController)
        contained?.container = vc
        
        return vc
    }
    
    public func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
    }
}

@available(iOS 14.0, *)
extension View {
    
    /// A link for this View to pass to `NavigationLink`.
    ///
    /// - Parameters:
    ///     - store: The object storing the current view of the navigation.
    ///     - isStack: A boolean indicating whether the navigaton view should be presented as stack.
    ///
    /// - Returns: A view that sets the current view on appear.
    func link(store: CurrentViewStore, isStack: Binding<Bool>) -> some View {
        onAppear {
            isStack.wrappedValue = false
            store.currentView = AnyView(self)
        }
    }
}
