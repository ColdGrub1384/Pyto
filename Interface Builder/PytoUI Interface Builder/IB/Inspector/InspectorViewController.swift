import UIKit
import SwiftUI

/// A View controlller for inspecting a view.
@available(iOS 16.0, *) public class InspectorViewController: UIViewController, UIPopoverPresentationControllerDelegate, UITextFieldDelegate {
    
    /// The inspected view.
    public var inspectedView: UIView!
    
    /// A boolean indicating whether `view` is the root view.
    public var isRoot: Bool!
    
    /// A boolean indicating wether to show the top bar.
    var showTopBar = true
    
    /// Initializes with given view.
    ///
    /// - Parameters:
    ///     - view: The inspected view.
    ///     - isRoot: A boolean indicating whether `view` is the root view.
    ///     - showTopBar: A boolean indicating wether to show the top bar.
    public init(view: UIView, isRoot: Bool = false, showTopBar: Bool = true) {
        super.init(nibName: nil, bundle: nil)
        inspectedView = view
        self.isRoot = isRoot
        self.showTopBar = showTopBar
    }
    
    @objc private func close() {
        dismiss(animated: true, completion: nil)
    }
    
    // MARK: - View controller
    
    public required init?(coder aDecoder: NSCoder) {
        fatalError("Not implemented")
    }
    
    public override var canBecomeFirstResponder: Bool {
        return true
    }
    
    override public func viewDidLoad() {
        super.viewDidLoad()
        
        title = prettifyClassName(NSStringFromClass(type(of: inspectedView)))
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        
        let inspectorVC = UIHostingController(rootView: InspectorView(inspectorViewController: self, showTopBar: showTopBar))
        inspectorVC.view.frame = view.frame
        inspectorVC.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        addChild(inspectorVC)
        view.addSubview(inspectorVC.view)
    }
    
    public override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if showTopBar {
            navigationController?.isNavigationBarHidden = true
        }
    }
    
    public override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        inspectedView.tintAdjustmentMode = .normal
    }
    
    public override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        inspectedView.interfaceBuilder?.autosave()
        NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: inspectedView)
    }
    
    // MARK: - Popover presentation controller delegate
    
    public func adaptivePresentationStyle(for controller: UIPresentationController) -> UIModalPresentationStyle {
        return .formSheet
    }
}
