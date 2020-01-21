//
//  SplitViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 12/21/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SplitKit

/// A Split view controller for displaying the editor and the console.
class EditorSplitViewController: SplitViewController {
    
    /// If set to `true`, console will be shown at bottom.
    static var shouldShowConsoleAtBottom: Bool {
        get {
            return UserDefaults.standard.bool(forKey: "shouldShowConsoleAtBottom")
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "shouldShowConsoleAtBottom")
        }
    }
    
    /// If set to `true`, the separator between the console and the editor will be shown.
    static var shouldShowSeparator: Bool {
        get {
            return UserDefaults.standard.bool(forKey: "shouldShowSeparator")
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "shouldShowSeparator")
        }
    }
    
    /// The View controller for editing code.
    @objc var editor: EditorViewController!
    
    /// The console.
    @objc var console: ConsoleViewController! {
        didSet {
            console.editorSplitViewController = self
        }
    }
    
    /// Set to `true` if this View controller was just shown.
    var justShown = true
    
    /// A down arrow image for dismissing keyboard.
    static var downArrow: UIImage {
        return UIGraphicsImageRenderer(size: .init(width: 24, height: 24)).image(actions: { context in
         
            let path = UIBezierPath()
            path.move(to: CGPoint(x: 1, y: 7))
            path.addLine(to: CGPoint(x: 11, y: 17))
            path.addLine(to: CGPoint(x: 22, y: 7))
            
            if #available(iOS 13.0, *) {
                if UITraitCollection.current.userInterfaceStyle == .dark {
                    UIColor.white.setStroke()
                } else {
                    UIColor.black.setStroke()
                }
            } else {
                if ConsoleViewController.choosenTheme.keyboardAppearance == .dark {
                    UIColor.white.setStroke()
                } else {
                    UIColor.black.setStroke()
                }
            }
            path.lineWidth = 2
            path.stroke()
            
            context.cgContext.addPath(path.cgPath)
            
        }).withRenderingMode(.alwaysOriginal)
    }
    
    /// Last visible controller.
    //@available(*, deprecated, message: "Use scenes APIs instead.") @objc static var visible: EditorSplitViewController?
    
    // MARK: - Key commands
    
    /// Runs the code.
    @IBAction func runScript(_ sender: Any) {
        editor?.run()
    }
    
    /// Stops the current running script.
    @IBAction func stopScript(_ sender: Any) {
        if let path = editor.document?.fileURL.path, Python.shared.isScriptRunning(path) {
            Python.shared.stop(script: path)
        }
    }
    
    /// Closes the controller.
    @objc func close() {
        editor?.close()
    }
    
    /// Show documentation.
    @objc func showDocs() {
        editor?.showDocs(editor!.docItem)
    }
    
    /// Runs code with arguments.
    @objc func runWithArguments() {
        editor?.setArgs(true)
    }
    
    /// Find or replace text.
    @objc func search() {
        editor?.search()
    }
    
    /// Interrupts current running script.
    @IBAction func interrupt(_ sender: Any) {
        
        guard let path = editor.document?.fileURL.path else {
            return
        }
        
        Python.shared.interrupt(script: path)
    }
    
    /// Sets navigation bar items.
    func setNavigationBarItems() {
        
        guard !(self is REPLViewController), !(self is PipInstallerViewController), !(self is RunModuleViewController) else {
            return
        }
        
        guard let path = editor.document?.fileURL.path else {
            return
        }
        
        if firstChild == editor {
            navigationItem.leftBarButtonItems = [editor.scriptsItem, editor.searchItem]
            if Python.shared.isScriptRunning(path) {
                navigationItem.rightBarButtonItems = [
                    editor.stopBarButtonItem,
                    editor.debugItem,
                ]
            } else {
                navigationItem.rightBarButtonItems = [
                    editor.runBarButtonItem,
                    editor.debugItem,
                ]
            }
        } else {
            navigationItem.leftBarButtonItems = [editor.scriptsItem]
            navigationItem.rightBarButtonItems = [closeConsoleBarButtonItem]
        }
    }
    
    /// The button for closing the full screen console.
    var closeConsoleBarButtonItem: UIBarButtonItem!
    
    /// Shows the editor on full screen.
    @objc func showEditor() {
        
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
        
        firstChild?.view.superview?.backgroundColor = view.backgroundColor
        secondChild?.view.superview?.backgroundColor = view.backgroundColor
        
        UIView.animate(withDuration: 0.25) {
            self.view.alpha = 0
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25, execute: {
            self.firstChild = nil
            self.secondChild = nil
            
            for view in self.view.subviews {
                view.removeFromSuperview()
            }
            
            super.viewDidLoad()
            super.viewWillTransition(to: self.view.frame.size, with: ViewControllerTransitionCoordinator())
            super.viewDidAppear(true)
            
            self.removeGestures()
            
            self.firstChild = self.editor
            self.secondChild = self.console
            
            self.setNavigationBarItems()
            
            UIView.animate(withDuration: 0.25) {
                self.view.alpha = 1
            }
        })
        
        if let path = editor.document?.fileURL.path {
            Python.shared.stop(script: path)
        }
    }
    
    /// Shows the console on full screen.
    func showConsole(_ completion: @escaping (() -> Void)) {
        
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
        
        firstChild?.view.superview?.backgroundColor = view.backgroundColor
        secondChild?.view.superview?.backgroundColor = view.backgroundColor
        
        UIView.animate(withDuration: 0.25) {
            self.view.alpha = 0
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+0.25, execute: {
            self.firstChild = nil
            self.secondChild = nil
            
            for view in self.view.subviews {
                view.removeFromSuperview()
            }
            
            super.viewDidLoad()
            super.viewWillTransition(to: self.view.frame.size, with: ViewControllerTransitionCoordinator())
            super.viewDidAppear(true)
            
            self.removeGestures()
            
            self.firstChild = self.console
            self.secondChild = self.editor
            
            self.setNavigationBarItems()
            
            completion()
            
            UIView.animate(withDuration: 0.25) {
                self.view.alpha = 1
            }
        })
    }
    
    /// Remove gesture recognizers.
    func removeGestures() {
        if ratio == 1 || ratio == 0 {
            for view in view.subviews {
                for gesture in view.gestureRecognizers ?? [] {
                    if gesture is UIPanGestureRecognizer {
                        view.removeGestureRecognizer(gesture)
                    }
                }
            }
        }
    }
    
    private var willRun: Bool?
    
    // MARK: - Split view controller
    
    override func canPerformAction(_ action: Selector, withSender sender: Any?) -> Bool {
        
        guard let path = editor.document?.fileURL.path else {
            return super.canPerformAction(action, withSender: sender)
        }
        
        if action == #selector(runScript(_:)) {
            return !Python.shared.isScriptRunning(path)
        } else if action == #selector(stopScript(_:)) || action == #selector(interrupt(_:)) {
            return Python.shared.isScriptRunning(path)
        } else {
            return super.canPerformAction(action, withSender: sender)
        }
    }
    
    override var keyCommands: [UIKeyCommand]? {
        var commands = [
            UIKeyCommand(input: "d", modifierFlags: .command, action: #selector(showDocs), discoverabilityTitle: Localizable.Help.documentation),
            UIKeyCommand(input: "f", modifierFlags: .command, action: #selector(search), discoverabilityTitle: Localizable.find),
            UIKeyCommand(input: "w", modifierFlags: .command, action: #selector(close), discoverabilityTitle: Localizable.close),
        ]
        
        guard let path = editor.document?.fileURL.path else {
            return commands
        }
        
        if Python.shared.isScriptRunning(path) {
            commands.append(
                UIKeyCommand(input: "c", modifierFlags: .control, action: #selector(interrupt(_:)), discoverabilityTitle: Localizable.interrupt)
            )
        } else {
            commands.append(
                UIKeyCommand(input: "r", modifierFlags: .command, action: #selector(runScript(_:)), discoverabilityTitle: Localizable.MenuItems.run)
            )
            
            commands.append(
                UIKeyCommand(input: "r", modifierFlags: [.command, .shift], action: #selector(runWithArguments), discoverabilityTitle: Localizable.runAndSetArguments)
            )
        }
        
        return commands
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        closeConsoleBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(showEditor))
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
        
        if arrangement == .horizontal && justShown {
            firstChild = editor
            secondChild = console
        }
        
        firstChild?.view.superview?.backgroundColor = view.backgroundColor
        secondChild?.view.superview?.backgroundColor = view.backgroundColor
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = editor.document?.fileURL.deletingPathExtension().lastPathComponent
        }
        
        willTransition(to: traitCollection, with: ViewControllerTransitionCoordinator())
        justShown = false
        
        removeGestures()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = ""
        }
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        guard let firstChild = self.firstChild, let secondChild = self.secondChild else {
            return
        }
        
        firstChild.view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        secondChild.view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        
        firstChild.viewWillTransition(to: firstChild.view.frame.size, with: ViewControllerTransitionCoordinator())
        secondChild.viewWillTransition(to: firstChild.view.frame.size, with: ViewControllerTransitionCoordinator())
        
        firstChild.view.superview?.backgroundColor = view.backgroundColor
        secondChild.view.superview?.backgroundColor = view.backgroundColor
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        guard view != nil else {
            return
        }
        
        super.viewWillTransition(to: size, with: coordinator)
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {
        
        guard view != nil else {
            return
        }
        
        guard presentedViewController == nil else {
            return
        }
        
        if willRun == nil {
            willRun = editor.shouldRun
        }
        
        if (newCollection.horizontalSizeClass == .compact || UIDevice.current.userInterfaceIdiom == .phone) && !EditorSplitViewController.shouldShowConsoleAtBottom && !willRun! {
            arrangement = .vertical
        } else {
            
            if EditorSplitViewController.shouldShowConsoleAtBottom {
                arrangement = .vertical
            } else if arrangement != .horizontal {
                arrangement = .horizontal
            }
            
            if firstChild != editor || secondChild != console {
                
                for view in view.subviews {
                    view.removeFromSuperview()
                }
                
                super.viewDidLoad()
                super.viewDidAppear(true)
                removeGestures()
                
                for view in self.view.subviews {
                    if view.backgroundColor == .white {
                        view.backgroundColor = self.view.backgroundColor
                    }
                }
                firstChild?.view.superview?.backgroundColor = self.view.backgroundColor
                secondChild?.view.superview?.backgroundColor = self.view.backgroundColor
                
                if EditorSplitViewController.shouldShowConsoleAtBottom {
                    arrangement = .vertical
                } else if arrangement != .horizontal {
                    arrangement = .horizontal
                }
                
                firstChild = editor
                secondChild = console
            }
        }
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        firstChild?.view.backgroundColor = view.backgroundColor
        secondChild?.view.backgroundColor = view.backgroundColor
    }
    
    override var canBecomeFirstResponder: Bool {
        return true
    }
    
    override var prefersHomeIndicatorAutoHidden: Bool {
        return editor?.textView.contentTextView.isFirstResponder ?? false
    }
    
    // MARK: Symbols
    
    /// The image of the button used for returning the file browser.
    static var gridImage: UIImage {
        if #available(iOS 13.0, *) {
            return UIImage(systemName: "square.grid.2x2.fill") ?? UIImage(named: "Grid") ?? UIImage()
        } else {
            return UIImage(named: "Grid") ?? UIImage()
        }
    }
    
    /// The image of the button used for opening settings.
    static var gearImage: UIImage {
        if #available(iOS 13.0, *) {
            return UIImage(systemName: "gear") ?? UIImage(named: "gear") ?? UIImage()
        } else {
            return UIImage(named: "gear") ?? UIImage()
        }
    }
    
    /// The image of the button used for showing more.
    static var threeDotsImage: UIImage {
        if #available(iOS 13.0, *) {
            return UIImage(systemName: "ellipsis") ?? UIImage(named: "more") ?? UIImage()
        } else {
            return UIImage(named: "more") ?? UIImage()
        }
    }
    
    /// The image of the button used for debugging.
    static var debugImage: UIImage {
        if #available(iOS 13.0, *) {
            return UIImage(systemName: "ant.fill") ?? UIImage(named: "Debug") ?? UIImage()
        } else {
            return UIImage(named: "Debug") ?? UIImage()
        }
    }
    
    // MARK: - Navigation controller
    
    /// A Navigation controller that has the user interface style of the selected theme.
    class NavigationController: UINavigationController {
        
        @objc private func themeDidChange(_ notification: Notification) {
            if #available(iOS 13.0, *) {
                if ConsoleViewController.choosenTheme.userInterfaceStyle != .unspecified {
                    overrideUserInterfaceStyle = ConsoleViewController.choosenTheme.userInterfaceStyle
                }
            }
        }
        
        override func viewDidLoad() {
            super.viewDidLoad()
            
            if #available(iOS 13.0, *) {
                if ConsoleViewController.choosenTheme.userInterfaceStyle != .unspecified {
                    overrideUserInterfaceStyle = ConsoleViewController.choosenTheme.userInterfaceStyle
                }
                NotificationCenter.default.addObserver(self, selector: #selector(themeDidChange(_:)), name: ThemeDidChangeNotification, object: nil)
            }
        }
    }
}
