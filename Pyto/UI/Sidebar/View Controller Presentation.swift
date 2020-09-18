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
@available(iOS 14.0, *)
public class ContainerViewController: UIViewController {
    
    fileprivate var vcStore: ViewControllerStore?
    
    var containedViewController: UIViewController?
    
    /// Updates the NavigationItem and the toolbar.
    public func update() {
        
        guard let viewController = containedViewController else {
            return
        }
        
        if children.count == 0 {
            viewController.removeFromParent()
            viewController.view.removeFromSuperview()
            addChild(viewController)
            view.addSubview(viewController.view)
            viewController.view.frame = view.frame
            viewController.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
            if self.vcStore?.scene?.activationState != .background {
                self.vcStore?.showSidebar = (self.vcStore?.vc?.children.first as? UISplitViewController)?.displayMode != .secondaryOnly
            } else {
                (self.vcStore?.vc?.children.first as? UISplitViewController)?.preferredDisplayMode = ((self.vcStore?.showSidebar == true) ? .allVisible : .secondaryOnly)
            }
        }
        
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
            
            parent?.navigationItem.leftBarButtonItems = child.navigationItem.leftBarButtonItems
            parent?.navigationItem.title = child.navigationItem.title
        }
    }
    
    private func showEditor() {
        #if MAIN
        if let editor = children.first as? EditorSplitViewController {
            editor.animateLayouts = false
            if editor.isConsoleShown {
                editor.showConsole {}
            } else {
                editor.showEditor()
            }
        }
        #endif
    }
    
    public override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        update()
    }
    
    public override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        showEditor()
        update()
    }
}

/// A protocol that can tell to its SwiftUI container to update its Navigation Item.
public protocol ContainedViewController {

    /// The container view controller. Will be set automatically, so just set it to `nil`. Use this instance to call `ContainerViewController.update` when a change is made.
    @available(iOS 14.0, *)
    var container: ContainerViewController? { get set }
}

/// A View Controller represented in SwiftUI.
@available(iOS 14.0, *)
public struct ViewController: UIViewControllerRepresentable {
    
    /// The UIKit View Controller.
    public var viewController: UIViewController?
    
    /// The `ViewControllerStore` associated with the sidebar navigation.
    var viewControllerStore: ViewControllerStore?
    
    /// Initialize with a given VC.
    ///
    /// - Parameters:
    ///     - viewController: The UIKit View Controller.
    ///     - viewControllerStore: The `ViewControllerStore` associated with the sidebar navigation.
    public init(viewController: UIViewController, viewControllerStore: ViewControllerStore?) {
        self.viewController = viewController
        self.viewControllerStore = viewControllerStore
    }
    
    public func makeUIViewController(context: Context) -> UIViewController {
        guard let viewController = viewController else {
            return UIViewController()
        }
        
        let vc = ContainerViewController()
        vc.vcStore = viewControllerStore
        vc.containedViewController = viewController
        
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
    func link(store: CurrentViewStore, isStack: Binding<Bool>, selection: SelectedSection, selected: Binding<SelectedSection?>, restoredSelection: Binding<SelectedSection?>) -> some View {
        onAppear {
            isStack.wrappedValue = false
            store.currentView = AnyView(self)
            restoredSelection.wrappedValue = nil
            selected.wrappedValue = selection
        }
    }
}
