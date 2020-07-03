//
//  PyView.swift
//  Pyto
//
//  Created by Adrian Labbé on 29-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import WebKit

@available(iOS 13.0, *) extension UIView {
    
    private struct Holder {
        static var presentationMode = [UIView:Int]()
        static var buttonItems = [UIView:[UIBarButtonItem]]()
        static var viewController = [UIView:UIViewController]()
        static var name = [UIView:String]()
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
    
    /// Bar button items to be displayed on the navigation bar.
    public var buttonItems: NSArray {
        get {
            return Holder.buttonItems[self] as NSArray? ?? [] as NSArray
        }
        
        set {
            Holder.buttonItems[self] = newValue as? [UIBarButtonItem]
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

}

/// A Python wrapper for `UIView`.
@available(iOS 13.0, *) @objc public class PyView: PyWrapper {
    
    override required init(managed: Any! = NSObject()) {
        super.init(managed: managed)
        
        if self.managed is UIView {
            DispatchQueue.main.async {
                self.view.layer.addObserver(self, forKeyPath: "bounds", options: .new, context: nil)
            }
            PyView.values[self.view] = self
        }
    }
    
    public override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {        
        layoutAction?.call(parameter: pyValue)
    }
    
    deinit {
        if Thread.current.isMainThread {
            view.layer.removeObserver(self, forKeyPath: "bounds")
        } else {
            let semaphore = DispatchSemaphore(value: 0)
            DispatchQueue.main.async {
                self.view.layer.removeObserver(self, forKeyPath: "bounds")
                semaphore.signal()
            }
            semaphore.wait()
        }
        viewController = nil
        pyValue = nil
    }
    
    /// A dictionary containing `PyView`s per `UIView`.
    static var values = [UIView:PyView]()
    
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
    
    /// A boolean indicating whether the Navigation Bar of the View should be hidden.
    @objc public var navigationBarHidden = false {
        didSet {
            set {
                (self.viewController as? UINavigationController)?.setNavigationBarHidden(self.navigationBarHidden, animated: true)
            }
        }
    }
    
    private var _title: String? {
        didSet {
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
    
    /// Closes this view.
    @objc public func close() {
        
        let semaphore = DispatchSemaphore(value: 0)
        
        DispatchQueue.main.async {
            #if WIDGET
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
            
            self.viewController?.dismiss(animated: true, completion: {
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
            return self.managed as! UIView
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
    
    private var _subviews = [PyView]()
    
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
        return get {
            var subviews = [PyView]()
            
            for view in self.view.subviews {
                
                for pyView in subviews {
                    if pyView.view == view {
                        break
                    }
                }
                
                if let v = PyView.values[view] {
                    subviews.append(v)
                }
            }
            
            self._subviews = subviews
            
            return NSArray(array: subviews)
        }
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
    ///     - subview: `view` will be placed bellow this view.
    @objc public func insertSubview(_ view: PyView, bellow subview: PyView) {
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
                return PyColor(managed: self.view.backgroundColor)
            }
        }
        
        set {
            set {
                self.view.backgroundColor = newValue?.managed as? UIColor
                ((self.viewController as? UINavigationController)?.viewControllers.first ?? self.viewController)?.view.backgroundColor = newValue?.managed as? UIColor
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
                return PyColor(managed: self.view.tintColor)
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
    
    /// The view user interface style.
    @objc public var appearance: Int {
        get {
            return get {
                return self.view.traitCollection.userInterfaceStyle.rawValue
            }
        }
        
        set {
            set {
                self.view.overrideUserInterfaceStyle = UIUserInterfaceStyle(rawValue: newValue) ?? .unspecified
                self.viewController?.overrideUserInterfaceStyle = self.view.overrideUserInterfaceStyle
            }
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
            return self.view.becomeFirstResponder()
        }
    }
    
    /// Resigns first responder.
    ///
    /// - Returns: A boolean indicating if the action was successfull.
    @objc public func resignFirstResponder() -> Bool {
        return get {
            return self.view.resignFirstResponder()
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
    
    /// Button items to be displayed on the view's corresponding navigation bar.
    @objc public var buttonItems: NSArray {
        get {
            return get {
                var items = [PyButtonItem]()
                for item in self.view.buttonItems {
                    items.append(PyButtonItem(managed: item))
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
                self.view.buttonItems = NSArray(array: items)
                ((self.viewController as? UINavigationController)?.viewControllers.first ?? self.viewController)?.navigationItem.leftBarButtonItems = items
            }
        }
    }
    
    /// Pushes the given view on the corresponding view's navigation controller.
    ///
    /// - Parameters:
    ///     - view. The view to display.
    @objc public func pushView(_ view: PyView) {
        set {
            let navVC = (self.viewController as? UINavigationController) ?? self.viewController?.navigationController
            guard let viewController = navVC?.viewControllers.first else {
                return
            }
            
            let ViewController = type(of: viewController) as UIViewController.Type
            
            let vc = ViewController.init()
            vc.view.addSubview(view.view)
            vc.title = view.title
            navVC?.pushViewController(vc, animated: true)
        }
        
    }
    
    /// Pops the visible view controller from the navigation controller.
    @objc public func pop() {
        set {
            ((self.viewController as? UINavigationController) ?? self.viewController?.navigationController)?.popViewController(animated: true)
        }
    }
}
