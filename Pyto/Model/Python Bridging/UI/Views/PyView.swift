//
//  PyView.swift
//  Pyto
//
//  Created by Emma Labbé on 29-06-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import WebKit
#if MAIN
import InterfaceBuilder
#else
let DidChangeViewPaddingOrFrameNotificationName = Notification.Name(rawValue: "DidChangeViewPaddingOrFrameNotification")
#endif

@available(iOS 13.0, *) extension UIView {
    
    struct Holder {
        static var presentationMode = [UIView:Int]()
        static var leftButtonItems = [UIView:[UIBarButtonItem]]()
        static var rightButtonItems = [UIView:[UIBarButtonItem]]()
        static var viewController = [UIView:UIViewController]()
        static var title = [UIView:String]()
        static var name = [UIView:String]()
        static var customClassName = [UIView:String]()
    }
    
    /// A name to identify the view.
    public var name: String? {
        get {
            return Holder.name[self]
        }
        
        set {
            Holder.name[self] = newValue
        }
    }
    
    /// The way the view will be presented, set from Python API. The setter is only used internally and has no effect.
    public var presentationMode: Int {
        get {
            return Holder.presentationMode[self] ?? 0
        }
        
        set {
            Holder.presentationMode[self] = newValue
        }
    }
    
    /// The title of the view.
    public var _title: String? {
        get {
            return Holder.title[self]
        }
        
        set {
            Holder.title[self] = newValue
        }
    }
    
    /// Bar button items to be displayed on the left of the navigation bar.
    public var leftButtonItems: NSArray {
        get {
            return Holder.leftButtonItems[self] as NSArray? ?? [] as NSArray
        }
        
        set {
            Holder.leftButtonItems[self] = newValue as? [UIBarButtonItem]
        }
    }
    
    /// Bar button items to be displayed on the right of the navigation bar.
    public var rightButtonItems: NSArray {
        get {
            return Holder.rightButtonItems[self] as NSArray? ?? [] as NSArray
        }
        
        set {
            Holder.rightButtonItems[self] = newValue as? [UIBarButtonItem]
        }
    }
    
    /// The View controller showing this View from Python.
     public var viewController: UIViewController? {
        get {
            return Holder.viewController[self]
        }
        
        set {
            Holder.viewController[self] = newValue
        }
    }

    /// The Python class name.
    public var customClassName: String? {
        get {
            return Holder.customClassName[self]
        }
        
        set {
            Holder.customClassName[self] = newValue
        }
    }
    
    #if MAIN
    @objc public func containsOrIs(_ view: UIView) -> Bool {
        
        guard #available(iOS 16.0, *) else {
            return false
        }
        
        if self == view {
            return true
        }
        
        let items = ((leftButtonItems as? [UIBarButtonItem]) ?? []) + ((rightButtonItems as? [UIBarButtonItem]) ?? [])
        for item in items {
            var containsItem = false
            
            PyWrapper.set {
                containsItem = item.customView == view
            }
            
            if containsItem {
                return true
            }
        }
        
        for subview in ((self is StackViewContainer) ? (self as! StackViewContainer).manager.views : subviews) {
            if subview.containsOrIs(view) {
                return true
            }
        }
        
        return false
    }
    
    @objc public func getUIKitSubviews() -> [UIView] {
        PyWrapper.get {
            self.subviews
        }
    }
    #endif
}

/// A Python wrapper for `UIView`.
@available(iOS 13.0, *) @objc public class PyView: PyWrapper, UIContextMenuInteractionDelegate {
    
    @objc static var lastError: String?
    
    @objc static var lastErrorType: String?
    
    #if MAIN
    @objc static func copyAttributes(sourceNavVC: UINavigationController, destNavVC: PyNavigationView) -> UINavigationController {
        set {
            destNavVC.navigationController.navigationBar.titleTextAttributes = sourceNavVC.navigationBar.titleTextAttributes
            destNavVC.navigationController.navigationBar.largeTitleTextAttributes = sourceNavVC.navigationBar.titleTextAttributes
            destNavVC.navigationBarHidden = sourceNavVC.isNavigationBarHidden
        }
        return sourceNavVC
    }
    
    @objc static func view(_ view: UIView) -> PyView? {
        PyView.values[view]
    }
        
    @available(iOS 16.0, *)
    private static func setModel(_ model: InterfaceModel, view: UIView) {
        if let stackView = view as? StackViewContainer {
            for view in stackView.manager.views {
                setModel(model, view: view)
            }
        }
        
        view.model = model
    }
    
    @available(iOS 16.0, *)
    @objc static func readFromPath(_ path: String) -> NSArray? {
        get {
                        
            guard FileManager.default.fileExists(atPath: path) else {
                lastError = "No such file or directory: '\(URL(fileURLWithPath: path).lastPathComponent)'"
                lastErrorType = "fileNotFound"
                return nil
            }
            
            do {
                let data = try Data(contentsOf: URL(fileURLWithPath: path))
                
                let model = try JSONDecoder().decode(InterfaceModel.self, from: data)
                
                let vc = model.navigationController.viewControllers.first
                
                let barItems = ((vc?.navigationItem.leftBarButtonItems ?? []) + (vc?.navigationItem.rightBarButtonItems ?? []).compactMap({
                    $0.customView
                }) as? [UIView]) ?? []
                
                for name in model.names.names {
                    vc?.view.viewWithTag(name.key)?.name = name.value
                    
                    if let item = barItems.first(where: { $0.tag == name.key }) {
                        item.name = name.value
                    }
                }
                
                for className in model.names.customClassNames {
                    
                    if className.key == 0 {
                        vc?.view.customClassName = className.value
                        continue
                    }
                    
                    vc?.view.viewWithTag(className.key)?.customClassName = className.value
                    
                    if let item = barItems.first(where: { $0.tag == className.key }) {
                        item.customClassName = className.value
                    }
                }
                
                model.navigationController.viewControllers = []
                
                let connections = NSMutableArray()
                for view in model.connections {
                    let array = NSMutableArray()
                    for connection in view.value {
                        array.add(NSArray(array: [connection.attributeName, connection.functionName]))
                    }
                    
                    guard let viewObject = vc?.view.viewWithTag(view.key) ?? barItems.first(where: { $0.tag == view.key }) else {
                        continue
                    }
                    
                    connections.add(NSArray(array: [viewObject, array]))
                }
                
                if let view = vc?.view {
                    setModel(model, view: view)
                }
                                
                return NSArray(array: [vc!, model.navigationController!, connections, barItems])
            } catch {
                lastError = error.localizedDescription
                lastErrorType = "decodingError"
                return nil
            }
        }
    }
    #endif
    
    /// The Python custom class name.
    @objc var customClassName: String? {
        get {
            get {
                self.view.customClassName
            }
        }
        
        set {
            set {
                self.view.customClassName = newValue
            }
        }
    }
    
    override required init(managed: NSObject! = NSObject()) {
        super.init(managed: managed)
        
        if self.managed is UIView {
            addSizeObserver()
            
            if !Thread.current.isMainThread {
                DispatchQueue.main.async { [weak self] in
                    
                    guard let self = self else {
                        return
                    }
                    
                    PyView.values[self.view] = self
                }
            } else {
                PyView.values[self.view] = self
            }
        }
    }
    
    let id = UUID()
    
    var sizeObserver: NSKeyValueObservation?
    
    func addSizeObserver() {
        if !Thread.current.isMainThread {
            DispatchQueue.main.async { [weak self] in
                
                guard let self = self else {
                    return
                }
                
                self.sizeObserver = self.view.layer.observe(\.bounds) { [weak self] (_, _) in
                    self?.layoutAction?.call(parameter: self?.pyValue)
                }
            }
        } else {
            self.sizeObserver = self.view.layer.observe(\.bounds) { [weak self] (_, _) in
                self?.layoutAction?.call(parameter: self?.pyValue)
            }
        }
    }
    
    func releaseHandler() {
        
    }
    
    @objc var references = 0 {
        didSet {
            if references == 0 {
                
                releaseHandler()
                
                #if MAIN
                NotificationCenter.default.post(Notification(name: WillReleaseViewNotificationName, object: view))
                #endif
                
                PyView.values[view] = nil
                UIView.Holder.leftButtonItems[view] = nil
                UIView.Holder.rightButtonItems[view] = nil
                UIView.Holder.name[view] = nil
                UIView.Holder.presentationMode[view] = nil
                UIView.Holder.viewController[view] = nil
                UIView.Holder.customClassName[view] = nil
                
                sizeObserver?.invalidate()
                sizeObserver = nil
            }
        }
    }
    
    @objc func releaseReference() {
        references -= 1
    }
    
    @objc func retainReference() {
        references += 1
    }
        
    /// A dictionary containing `PyView`s per `UIView`.
    static var values = ThreadSafeDictionary<UIView, PyView>()
    
    /// The name of the Python class wrapping this.
    @objc open class var pythonName: String {
        return "View"
    }
    
    /// The Python instance.
    @objc public var pyValue: PyValue?
    
    /// The UIKit View controller associated with this view.
    var viewController: UIViewController? {
        get  {
            return get {
                return self.view.viewController
            }
        }
        
        set {
            set {
                self.view.viewController = newValue
                newValue?.overrideUserInterfaceStyle = self.view.overrideUserInterfaceStyle
            }
        }
    }
    
    @objc var navigationView: PyView? {
        get {
            get { () -> PyView? in
                var next = self.view.next
                while !(next is UIViewController) {
                    next = next?.next
                    if next == nil {
                        break
                    }
                }
                
                guard let navigationController = (next as? UIViewController)?.navigationController else {
                    return nil
                }
                
                return PyView.values[navigationController.view]
            }
        }
    }
    
    /// The name identifying the view.
    @objc public var name: String? {
        set {
            set {
                self.view.name = newValue
            }
        }
        
        get {
            return get {
                return self.view.name
            }
        }
    }
    
    private var _title: String? {
        get {
            self.view._title
        }
        
        set {
            self.view._title = newValue
            
            for vc in (self.viewController as? UINavigationController)?.viewControllers ?? [] {
                if vc.view.subviews.first == view {
                    vc.title = _title
                    vc.navigationItem.title = _title
                }
            }
        }
    }
    
    /// The title of the view.
    @objc public var title: String? {
        set {
            set {
                self.viewController?.navigationItem.title = newValue
                self._title = newValue
            }
        }
        
        get {
            return get {
                return self._title
            }
        }
    }
    
    /// `true` if the view is presented on the console.
    @objc public var isPresented = false
    
    /// Creates a new view.
    ///
    /// - Returns: A newly initialized view.
    @objc class func newView() -> PyView {
        return PyView(managed: get {
            let view = UIView()
            view.frame.size = CGSize(width: 375, height: 668)
            return view
        })
    }
    
    /// View will be presented as a sheet.
    @objc public static let PresentationModeSheet = 0
    
    /// View will be presented in full screen.
    @objc public static let PresentationModeFullScreen = 1
    
    /// View will be presented in a widget.
    @objc public static let PresentationModeWidget = 3
    
    /// View will be presented in a new window.
    @objc public static let PresentationModeNewScene = 7
    
    private var _presentationMode: Int {
        get {
            return get {
                return self.view.presentationMode
            }
        }
        
        set {
            set {
                self.view.presentationMode = newValue
            }
        }
    }
    
    /// The way the view will be presented.
    @objc public var presentationMode: Int {
        set {
            _presentationMode = newValue
            
            for view in subviews {
                (view as? PyView)?.presentationMode = presentationMode
            }
        }
        
        get {
            return _presentationMode
        }
    }
    
    /// The function called when the size of the view changes.
    @objc public var layoutAction: PyValue?
    
    /// The function called when the view becomes visible on screen.
    @objc public var appearAction: PyValue?
    
    /// The function called when the view stops being visible on screen.
    @objc public var disappearAction: PyValue?
    
    /// Closes this view.
    @objc public func close() {
        
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            #if WIDGET && Xcode11
            self.viewController?.view.removeFromSuperview()
            self.viewController?.removeFromParent()
            
            ConsoleViewController.visible.textView.isHidden = false
            ConsoleViewController.visible.playButton.isHidden = false
            
            semaphore.signal()
            #else
            #if MAIN
            if WidgetSimulatorViewController.visible?.pyView == self {
                WidgetSimulatorViewController.visible?.dismiss(animated: true, completion: {
                    self.isPresented = false
                    semaphore.signal()
                })
                return
            }
            #endif
            
            if self.viewController == nil {
                semaphore.signal()
                return
            }
            
            var vc = self.viewController
            if vc is UINavigationController, let _vc = vc?.next?.next as? UIViewController {
                vc = _vc
            }
            
            #if MAIN
            let isScene = vc?.presentingViewController is SceneDelegate.ViewController
            
            if isScene, let session = vc?.view.window?.windowScene?.session {
                let options = UIWindowSceneDestructionRequestOptions()
                options.windowDismissalAnimation = .commit
                UIApplication.shared.requestSceneSessionDestruction(session, options: options)
            }
            #else
            let isScene = false
            #endif
                        
            vc?.dismiss(animated: !isScene, completion: {
                semaphore.signal()
            })
            #endif
        }
        
        if !Thread.current.isMainThread {
            semaphore.wait()
        }
    }
    
    /// The view associated with this object.
    @objc public var view: UIView {
        return get {
            return (self.managed as? UIView) ?? {
                let view = UIView()
                return view
            }()
        }
    }
    
    @objc var _setSize = false
    
    @objc var padding: [Double] {
        get {
            return get {
                return [
                    Double(self.view.layoutMargins.top),
                    Double(self.view.layoutMargins.bottom),
                    Double(self.view.layoutMargins.left),
                    Double(self.view.layoutMargins.right)]
            }
        }
        
        set {
            set {
                self.view.layoutMargins = UIEdgeInsets(top: CGFloat(newValue[0]), left: CGFloat(newValue[2]), bottom: CGFloat(newValue[1]), right: CGFloat(newValue[3]))
            }
        }
    }
    
    /// The x position.
    @objc public var x: Double {
        get {
            return get {
                return Double(self.view.frame.origin.x)
            }
        }
        
        set {
            set {
                self.view.frame.origin.x = CGFloat(newValue)
            }
        }
    }
    
    /// The y position.
    @objc public var y: Double {
        get {
            return get {
                return Double(self.view.frame.origin.y)
            }
        }
        
        set {
            set {
                self.view.frame.origin.y = CGFloat(newValue)
            }
        }
    }
    
    /// The width.
    @objc public var width: Double {
        get {
            return get {
                return Double(self.view.frame.width)
            }
        }
        
        set {
            _setSize = true
            set {
                self.view.frame.size.width = CGFloat(newValue)
            }
        }
    }
    
    /// The height.
    @objc public var height: Double {
        get {
            return get {
                return Double(self.view.frame.height)
            }
        }
        
        set {
            _setSize = true
            set {
                self.view.frame.size.height = CGFloat(newValue)
            }
        }
    }
    
    /// The x center position.
    @objc public var centerX: Double {
        get {
            return get {
                return Double(self.view.center.x)
            }
        }
        
        set {
            set {
                self.view.center.x = CGFloat(newValue)
            }
        }
    }
    
    /// The y center position.
   @objc public var centerY: Double {
        get {
            return get {
                return Double(self.view.center.y)
            }
        }
        
        set {
            set {
                self.view.center.y = CGFloat(newValue)
            }
        }
    }
    
    /// `true` if `UIView.autoresizingMask` contains `.flexibleWidth`.
    @objc public var flexibleWidth: Bool {
        get {
            return get {
                return self.view.autoresizingMask.contains(.flexibleWidth)
            }
        }
        
        set {
            set {
                if newValue {
                    if !self.view.autoresizingMask.contains(.flexibleWidth) {
                        self.view.autoresizingMask.insert(.flexibleWidth)
                    }
                } else {
                    if self.view.autoresizingMask.contains(.flexibleWidth) {
                        self.view.autoresizingMask.remove(.flexibleWidth)
                    }
                }
            }
        }
    }
    
    /// `true` if `UIView.autoresizingMask` contains `.flexibleHeight`.
    @objc public var flexibleHeight: Bool {
        get {
            return get {
                return self.view.autoresizingMask.contains(.flexibleHeight)
            }
        }
        
        set {
            set {
                if newValue {
                    if !self.view.autoresizingMask.contains(.flexibleHeight) {
                        self.view.autoresizingMask.insert(.flexibleHeight)
                    }
                } else {
                    if self.view.autoresizingMask.contains(.flexibleHeight) {
                        self.view.autoresizingMask.remove(.flexibleHeight)
                    }
                }
            }
        }
    }
    
    /// `true` if `UIView.autoresizingMask` contains `.flexibleLeftMargin`.
    @objc public var flexibleLeftMargin: Bool {
        get {
            return get {
                return self.view.autoresizingMask.contains(.flexibleLeftMargin)
            }
        }
        
        set {
            set {
                if newValue {
                    if !self.view.autoresizingMask.contains(.flexibleLeftMargin) {
                        self.view.autoresizingMask.insert(.flexibleLeftMargin)
                    }
                } else {
                    if self.view.autoresizingMask.contains(.flexibleLeftMargin) {
                        self.view.autoresizingMask.remove(.flexibleLeftMargin)
                    }
                }
            }
        }
    }
    
    /// `true` if `UIView.autoresizingMask` contains `.flexibleRightMargin`.
    @objc public var flexibleRightMargin: Bool {
        get {
            return get {
                return self.view.autoresizingMask.contains(.flexibleRightMargin)
            }
        }
        
        set {
            set {
                if newValue {
                    if !self.view.autoresizingMask.contains(.flexibleRightMargin) {
                        self.view.autoresizingMask.insert(.flexibleRightMargin)
                    }
                } else {
                    if self.view.autoresizingMask.contains(.flexibleRightMargin) {
                        self.view.autoresizingMask.remove(.flexibleRightMargin)
                    }
                }
            }
        }
    }
    
    /// `true` if `UIView.autoresizingMask` contains `.flexibleRightMargin`.
    @objc public var flexibleTopMargin: Bool {
        get {
            return get {
                return self.view.autoresizingMask.contains(.flexibleTopMargin)
            }
        }
        
        set {
            set {
                if newValue {
                    if !self.view.autoresizingMask.contains(.flexibleTopMargin) {
                        self.view.autoresizingMask.insert(.flexibleTopMargin)
                    }
                } else {
                    if self.view.autoresizingMask.contains(.flexibleTopMargin) {
                        self.view.autoresizingMask.remove(.flexibleTopMargin)
                    }
                }
            }
        }
    }
    
    /// `true` if `UIView.autoresizingMask` contains `.flexibleBottomMargin`.
    @objc public var flexibleBottomMargin: Bool {
        get {
            return get {
                return self.view.autoresizingMask.contains(.flexibleBottomMargin)
            }
        }
        
        set {
            set {
                if newValue {
                    if !self.view.autoresizingMask.contains(.flexibleBottomMargin) {
                        self.view.autoresizingMask.insert(.flexibleBottomMargin)
                    }
                } else {
                    if self.view.autoresizingMask.contains(.flexibleBottomMargin) {
                        self.view.autoresizingMask.remove(.flexibleBottomMargin)
                    }
                }
            }
        }
    }
    
    /// `true` if `UIView.autoresizingMask` contains all flexible margins.
    @objc public var flexibleMargins: Bool {
        get {
            return get {
                let a = self.view.autoresizingMask
                return (a.contains(.flexibleLeftMargin) && a.contains(.flexibleRightMargin) && a.contains(.flexibleTopMargin) && a.contains(.flexibleBottomMargin))
            }
        }
        
        set {
            set {
                if newValue {
                    if !self.view.autoresizingMask.contains(.flexibleLeftMargin) {
                        self.view.autoresizingMask.insert(.flexibleLeftMargin)
                    }
                    
                    if !self.view.autoresizingMask.contains(.flexibleRightMargin) {
                        self.view.autoresizingMask.insert(.flexibleRightMargin)
                    }
                    
                    if !self.view.autoresizingMask.contains(.flexibleBottomMargin) {
                        self.view.autoresizingMask.insert(.flexibleBottomMargin)
                    }
                    
                    if !self.view.autoresizingMask.contains(.flexibleTopMargin) {
                        self.view.autoresizingMask.insert(.flexibleTopMargin)
                    }
                } else {
                    
                    if self.view.autoresizingMask.contains(.flexibleLeftMargin) {
                        self.view.autoresizingMask.remove(.flexibleLeftMargin)
                    }
                    
                    if self.view.autoresizingMask.contains(.flexibleRightMargin) {
                        self.view.autoresizingMask.remove(.flexibleRightMargin)
                    }
                    
                    if self.view.autoresizingMask.contains(.flexibleTopMargin) {
                        self.view.autoresizingMask.remove(.flexibleTopMargin)
                    }
                    
                    if self.view.autoresizingMask.contains(.flexibleBottomMargin) {
                        self.view.autoresizingMask.remove(.flexibleBottomMargin)
                    }
                }
            }
        }
    }
    
    /// The parent of the view.
    @objc public var superView: PyView? {
        self.get {
            if let superView = self.view.superview {
                return PyView.values[superView]
            } else {
                return nil
            }
        }
    }
    
    /// The subviews of the view.
    @objc public var subviews: NSArray {
        NSArray(array: get {
            self.view.subviews
        }.compactMap({ PyView.values[$0] }))
    }
    
    /// Adds the given view as subview.
    ///
    /// - Parameters:
    ///     - view: The view to be added.
    @objc public func addSubview(_ view: PyView) {
        set {
            if !self.view.subviews.contains(view.view) {
                self.view.addSubview(view.view)
            }
        }
    }
    
    /// Inserts the given view as subview at the given index.
    ///
    /// - Parameters:
    ///     - view: The view to be added.
    ///     - index: The index where the view should be added.
    @objc public func insertSubview(_ view: PyView, at index: Int) {
        set {
            if !self.view.subviews.contains(view.view) {
                self.view.insertSubview(view.view, at: index)
            }
        }
    }
    
    /// Inserts the given view as subview below the given subview.
    ///
    /// - Parameters:
    ///     - view: The view to be added.
    ///     - subview: `view` will be placed below this view.
    @objc public func insertSubview(_ view: PyView, below subview: PyView) {
        set {
            if !self.view.subviews.contains(view.view) {
                self.view.insertSubview(view.view, belowSubview: subview.view)
            }
        }
    }
    
    /// Inserts the given view as subview above the given subview.
    ///
    /// - Parameters:
    ///     - view: The view to be added.
    ///     - subview: `view` will be placed above this view.
    @objc public func insertSubview(_ view: PyView, above subview: PyView) {
        set {
            if !self.view.subviews.contains(view.view) {
                self.view.insertSubview(view.view, aboveSubview: subview.view)
            }
        }
    }
    
    /// Removes this view from the superview.
    @objc public func removeFromSuperview() {
        set {
            self.view.removeFromSuperview()
        }
    }
    
    /// The background color of the view.
    @objc public var backgroundColor: PyColor? {
        get {
            return get {
                if let bg = self.view.backgroundColor {
                    return PyColor(managed: bg)
                } else {
                    return nil
                }
            }
        }
        
        set {
            set {
                self.view.backgroundColor = newValue?.managed as? UIColor
                #if MAIN
                (self.viewController as? ConsoleViewController.NavigationController)?.setBarColor()
                #endif
            }
        }
    }
    
    /// `true` if the view is hidden.
    @objc public var hidden: Bool {
        get {
            return get {
                return self.view.isHidden
            }
        }
        
        set {
            set {
                self.view.isHidden = newValue
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: self.view)
            }
        }
    }
    
    /// The alpha value.
    @objc public var alpha: Double {
        get {
            return get {
                return Double(self.view.alpha)
            }
        }
        
        set {
            set {
                self.view.alpha = CGFloat(newValue)
            }
        }
    }
    
    /// `true` if the view is opaque.
    @objc public var opaque: Bool {
        get {
            return get {
                return self.view.isOpaque
            }
        }
        
        set {
            set {
                self.view.isOpaque = newValue
            }
        }
    }
    
    /// The tint color.
    @objc public var tintColor: PyColor! {
        get {
            return get {
                if let tint = self.view.tintColor {
                    return PyColor(managed: tint)
                } else {
                    return nil
                }
            }
        }
        
        set {
            set {
                self.view.tintColor = newValue?.managed as? UIColor
            }
        }
    }
    
    /// `true` to enable user interaction.
    @objc public var userInteractionEnabled: Bool {
        get {
            return get {
                return self.view.isUserInteractionEnabled
            }
        }
        
        set {
            set {
                self.view.isUserInteractionEnabled = newValue
            }
        }
    }
    
    /// `true`if is exclusive touch.
    @objc public var exclusiveTouch: Bool {
        get {
            return get {
                return self.view.isExclusiveTouch
            }
        }
        
        set {
            set {
                self.view.isExclusiveTouch = newValue
            }
        }
    }
    
    /// `true` if subviews should be clipped.
    @objc public var clipsToBounds: Bool {
        get {
            return get {
                return self.view.clipsToBounds
            }
        }
        
        set {
            set {
                self.view.clipsToBounds = newValue
            }
        }
    }
    
    private var _borderColor: PyColor?
    
    /// Updates dynamic border colors in the receiver and all its subviews.
    func updateBorderColor() {
        borderColor = _borderColor
        for view in (subviews as? [PyView]) ?? [] {
            view.updateBorderColor()
        }
    }
    
    /// The border color.
    @objc public var borderColor: PyColor? {
        get {
            return get {
                if let cgColor = self.view.layer.borderColor {
                    return PyColor(managed: UIColor(cgColor: cgColor))
                } else {
                    return nil
                }
            }
        }
        
        set {
            _borderColor = newValue
            set {
                if let pyColor = newValue {
                    self.view.layer.borderColor = pyColor.color.cgColor
                } else {
                    self.view.layer.borderColor = nil
                }
            }
        }
    }
    
    /// The border width.
    @objc public var borderWidth: Double {
        get {
            return get {
                return Double(self.view.layer.borderWidth)
            }
        }
        
        set {
            set {
                self.view.layer.borderWidth = CGFloat(newValue)
            }
        }
    }
    
    /// The corner radius.
    @objc public var cornerRadius: Double {
        get {
            return get {
                return Double(self.view.layer.cornerRadius)
            }
        }
        
        set {
            set {
                self.view.layer.cornerRadius = CGFloat(newValue)
            }
        }
    }
    
    /// Content mode scale to fill.
    @objc public static let ContentModeScaleToFill = UIView.ContentMode.scaleToFill
    
    /// Content mode scale aspect fit.
    @objc public static let ContentModeScaleAspectFit = UIView.ContentMode.scaleAspectFit
    
    /// Content mode scale aspect fill.
    @objc public static let ContentModeScaleAspectFill = UIView.ContentMode.scaleAspectFill
    
    /// Content mode redraw.
    @objc public static let ContentModeRedraw = UIView.ContentMode.redraw
    
    /// Content mode center.
    @objc public static let ContentModeCenter = UIView.ContentMode.center
    
    /// Content mode top.
    @objc public static let ContentModeTop = UIView.ContentMode.top
    
    /// Content mode bottom.
    @objc public static let ContentModeBottom = UIView.ContentMode.bottom
    
    /// Content mode left.
    @objc public static let ContentModeLeft = UIView.ContentMode.left
    
    /// Content mode right.
    @objc public static let ContentModeRight = UIView.ContentMode.right
    
    /// Content mode top left.
    @objc public static let ContentModeTopLeft = UIView.ContentMode.left
    
    /// Content mode top right.
    @objc public static let ContentModeTopRight = UIView.ContentMode.right
    
    /// Content mode bottom left.
    @objc public static let ContentModeBottomLeft = UIView.ContentMode.left
    
    /// Content mode bottom right.
    @objc public static let ContentModeBottomRight = UIView.ContentMode.right
    
    /// The content mode of the view.
    @objc public var contentMode: Int {
        get {
            return get {
                return self.view.contentMode.rawValue
            }
        }
        
        set {
            set {
                self.view.contentMode = UIView.ContentMode(rawValue: newValue) ?? UIView.ContentMode.scaleToFill
            }
        }
    }
    
    /// Unspecified user interface style. Inherited from parent.
    @objc public static let AppearanceUnspecified = UIUserInterfaceStyle.unspecified
    
    /// Light user interface style.
    @objc public static let AppearanceLight = UIUserInterfaceStyle.light
    
    /// Dark user interface style.
    @objc public static let AppearanceDark = UIUserInterfaceStyle.dark
    
    @objc var customAppearance = 0
    
    /// The view user interface style.
    @objc public var appearance: Int {
        get {
            return get {
                return self.view.traitCollection.userInterfaceStyle.rawValue
            }
        }
        
        set {
            customAppearance = newValue
            set {
                self.view.overrideUserInterfaceStyle = UIUserInterfaceStyle(rawValue: newValue) ?? .unspecified
                self.viewController?.overrideUserInterfaceStyle = self.view.overrideUserInterfaceStyle
            }
            updateBorderColor()
        }
    }
    
    /// SIzes to fit content.
    @objc public func sizeToFit() {
        set {
            self.view.sizeToFit()
        }
    }
    
    /// Becomes first responder.
    ///
    /// - Returns: A boolean indicating if the action was successfull.
    @objc public func becomeFirstResponder() -> Bool {
        return get {
            if !self.view.becomeFirstResponder() {
                var vc: UIResponder? = self.viewController
                #if MAIN
                if vc == nil {
                    vc = self.view
                    while !(vc is ConsoleViewController.ViewController) {
                        vc = vc?.next
                        if vc == nil {
                            break
                        }
                    }
                }
                #endif
                return vc?.becomeFirstResponder() ?? false
            } else {
                return true
            }
        }
    }
    
    /// Resigns first responder.
    ///
    /// - Returns: A boolean indicating if the action was successfull.
    @objc public func resignFirstResponder() -> Bool {
        return get {
            if !self.view.resignFirstResponder() {
                var vc: UIResponder? = self.viewController
                #if MAIN
                if vc == nil {
                    vc = self.view
                    while !(vc is ConsoleViewController.ViewController) {
                        vc = vc?.next
                        if vc == nil {
                            break
                        }
                    }
                }
                #endif
                return vc?.resignFirstResponder() ?? false
            } else {
                return true
            }
        }
    }
    
    /// Returns a boolean indicating if the view is the first responder.
    @objc public var firstResponder: Bool {
        return get {
            return self.view.isFirstResponder
        }
    }
    
    /// Causes the view (or one of its embedded text fields) to resign the first responder status.
    ///
    /// - Parameters:
    ///     - force: Specify true to force the first responder to resign, regardless of whether it wants to do so.
    @objc public func endEditing(_ force: Bool) -> Bool {
        return get {
            return self.view.endEditing(force)
        }
    }
    
    /// All attached gesture recognizers.
    @objc public var gestureRecognizers: NSArray! {
        get {
            return get {
                var pythonic = [PyGestureRecognizer]()
                for gesture in self.view.gestureRecognizers ?? [] {
                    pythonic.append(PyGestureRecognizer(managed: gesture))
                }
                return NSArray(array: pythonic)
            }
        }
        
        set {
            set {
                
                guard newValue != nil else {
                    self.view.gestureRecognizers = []
                    return
                }
                
                var gestures = [UIGestureRecognizer]()
                for gesture in newValue {
                    if let gesture = gesture as? PyGestureRecognizer {
                        gestures.append(gesture.gestureRecognizer)
                    }
                }
                self.view.gestureRecognizers = gestures
            }
        }
    }
    
    /// Adds the given gesture recognizer.
    ///
    /// - Parameters:
    ///     - gestureRecognizer: Gesture recognizer to add.
    @objc public func addGestureRecognizer(_ gestureRecognizer: PyGestureRecognizer) {
        set {
            self.view.addGestureRecognizer(gestureRecognizer.gestureRecognizer)
        }
    }
    
    /// Removes the given gesture recognizer.
    ///
    /// - Parameters:
    ///     - gestureRecognizer: Gesture recognizer to remove.
    @objc public func removeGestureRecognizer(_ gestureRecognizer: PyGestureRecognizer) {
        set {
            self.view.removeGestureRecognizer(gestureRecognizer.gestureRecognizer)
        }
    }
    
    #if MAIN
    var menu: UIMenu?
    
    @objc var menuValue: PyValue?
    
    @available(iOS 15.0, *)
    @objc public func setMenu(_ menu: PyMenuElement?) {
        set {
            
            self.menu = menu?.makeMenu()
            
            if menu != nil {
                let interaction = UIContextMenuInteraction(delegate: self)
                self.view.addInteraction(interaction)
            } else if self.view.interactions.contains(where: { $0 is UIContextMenuInteraction }) {
                self.view.interactions.removeAll(where: { $0 is UIContextMenuInteraction })
            }
        }
    }
    #endif
    
    /// Button items to be displayed on the left of the view's corresponding navigation bar.
    @objc public var leftButtonItems: NSArray {
        get {
            return get {
                var items = [PyButtonItem]()
                for item in self.view.leftButtonItems {
                    if let item = item as? NSObject {
                        items.append(PyButtonItem(managed: item))
                    }
                }
                return NSArray(array: items)
            }
        }
        
        set {
            
            guard let newValue = newValue as? [PyButtonItem] else {
                return
            }
            
            set {
                var items = [UIBarButtonItem]()
                for item in newValue {
                    items.append(item.barButtonItem)
                }
                self.view.leftButtonItems = NSArray(array: items)
                self.viewController?.navigationItem.leftBarButtonItems = items
            }
        }
    }
    
    /// Button items to be displayed on the right of the view's corresponding navigation bar.
    @objc public var rightButtonItems: NSArray {
        get {
            return get {
                var items = [PyButtonItem]()
                for item in self.view.rightButtonItems {
                    if let item = item as? NSObject {
                        items.append(PyButtonItem(managed: item))
                    }
                }
                return NSArray(array: items)
            }
        }
        
        set {
            
            guard let newValue = newValue as? [PyButtonItem] else {
                return
            }
            
            set {
                var items = [UIBarButtonItem]()
                for item in newValue {
                    items.append(item.barButtonItem)
                }
                self.view.rightButtonItems = NSArray(array: items)
                self.viewController?.navigationItem.rightBarButtonItems = items
            }
        }
    }
    
    @objc var keyPressBegan: PyValue?
    
    @objc var keyPressEnded: PyValue?
    
    public func contextMenuInteraction(_ interaction: UIContextMenuInteraction, configurationForMenuAtLocation location: CGPoint) -> UIContextMenuConfiguration? {
            return UIContextMenuConfiguration(identifier: nil, previewProvider: nil) { [weak self] _ in
                #if MAIN
                return self?.menu
                #else
                return nil
                #endif
            }
        }
}

extension UIResponder {
    
    private func randomAlphaNumericString(length: Int) -> String {
        let allowedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
        let allowedCharsCount = UInt32(allowedChars.count)
        var randomString = ""

        for _ in 0 ..< length {
            let randomNum = Int(arc4random_uniform(allowedCharsCount))
            let randomIndex = allowedChars.index(allowedChars.startIndex, offsetBy: randomNum)
            let newCharacter = allowedChars[randomIndex]
            randomString += String(newCharacter)
        }

        return randomString
    }
    
    private func sendKey(_ key: UIKey?, function: PyValue?) {
        
        guard let key = key else {
            return
        }
        
        let id = randomAlphaNumericString(length: 12)
        
        Python.pythonShared?.perform(#selector(PythonRuntime.runCode(_:)), with: """
        import _values
        import pyto_ui as ui
        import base64
        
        chars = base64.b64decode("\(key.characters.data(using: .utf8)?.base64EncodedString() ?? "")".encode("utf-8")).decode("utf-8")
        
        key = ui.Key(ui.KeyCode(\(key.keyCode.rawValue)), ui.KeyModifier(\(key.modifierFlags.rawValue)), chars)
        
        _values.value(key, "\(id)")
        """)
        
        function?.call(parameter: PyValue(identifier: id), delete: false)
    }
    
    @objc func keyPressBegan(_ press: UIPress) {
        guard let view = self as? UIView else {
            return
        }
        
        if let pyView = PyView.values[view] {
            sendKey(press.key, function: pyView.keyPressBegan)
        }
    }
    
    @objc func keyPressEnded(_ press: UIPress) {
        guard let view = self as? UIView else {
            return
        }
        
        if let pyView = PyView.values[view] {
            sendKey(press.key, function: pyView.keyPressEnded)
        }
    }
}
