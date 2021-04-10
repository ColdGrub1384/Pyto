//
//  SplitViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 12/21/18.
//  Copyright © 2018 Emma Labbé. All rights reserved.
//

import UIKit
import SplitKit

#if Xcode11
protocol ContainedViewController {}
#endif

/// A Split view controller for displaying the editor and the console.
public class EditorSplitViewController: SplitViewController {
    
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
            if UserDefaults.standard.value(forKey: "shouldShowSeparator") == nil {
                UserDefaults.standard.set(true, forKey: "shouldShowSeparator")
            }
            
            return UserDefaults.standard.bool(forKey: "shouldShowSeparator")
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "shouldShowSeparator")
        }
    }
    
    /// If set to `true`, console will be shown at bottom.
    var shouldShowConsoleAtBottom = EditorSplitViewController.shouldShowConsoleAtBottom
    
    /// The View controller for editing code.
    @objc var editor: EditorViewController?
    
    /// The console.
    @objc public var console: ConsoleViewController? {
        didSet {
            console?.editorSplitViewController = self
            if let console = console, !ConsoleViewController.visibles.contains(console) {
                ConsoleViewController.visibles.append(console)
            }
        }
    }
    
    /// Set to `true` if this View controller was just shown.
    var justShown = true
    
    /// If the script was opened in a project, the folder of the project.
    var folder: URL?
    
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
    
    /// Kills the attached REPL.
    func killREPL() {
        if let path = editor?.document?.fileURL.path {
            let code = """
            from console import __repl_threads__, __repl_namespace__
            from pyto import Python
            import stopit
            import threading

            path = "\(path.replacingOccurrences(of: "\"", with: "\\\""))"

            repl = path.split("/")[-1]
            if repl in __repl_namespace__:
                __repl_namespace__[repl] = {}

            if path in __repl_threads__:
            
                Python.shared.interruptInputWithScript(path)
                thread = __repl_threads__[path]
                for tid, tobj in threading._active.items():
                    if tobj is thread:
                        try:
                            stopit.async_raise(tid, SystemExit)
                            break
                        except Exception as e:
                            print(e)
                del __repl_threads__[path]
            """
            
            Python.shared.run(code: code)
        }
    }
    
    // MARK: - Key commands
    
    /// Runs the code.
    @IBAction func runScript(_ sender: Any) {
        editor?.run()
    }
    
    /// Stops the current running script.
    @IBAction func stopScript(_ sender: Any) {
        if let path = editor?.document?.fileURL.path, Python.shared.isScriptRunning(path) {
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
        
        guard let path = editor?.document?.fileURL.path else {
            return
        }
        
        Python.shared.interrupt(script: path)
    }
    
    /// Sets navigation bar items.
    func setNavigationBarItems() {
        
        guard !(self is REPLViewController), !(self is PipInstallerViewController), !(self is RunModuleViewController) else {
            return
        }
        
        guard let path = editor?.document?.fileURL.path else {
            return
        }
        
        guard let editor = editor else {
            return
        }
        
        if firstChild == editor {
            var items = [editor.scriptsItem!, editor.searchItem!, editor.definitionsItem!]
            
            if #available(iOS 14.0, *), ((parent as? EditorSplitViewController)?.folder == nil && editor.traitCollection.horizontalSizeClass != .compact) || isiOSAppOnMac, !editor.alwaysShowBackButton {
                items.removeFirst()
            }
            
            navigationItem.leftBarButtonItems = items
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
        
        if #available(iOS 14.0, *) {
            #if !Xcode11
            container?.update()
            #endif
        }
    }
    
    /// The button for closing the full screen console.
    var closeConsoleBarButtonItem: UIBarButtonItem!
    
    /// A boolean indicating whether `showEditor` and  `showConsole(completionm:)` are animated.
    var animateLayouts = true
    
    var exitScript = true
    
    /// Shows the editor on full screen.
    @objc func showEditor() {
        
        isConsoleShown = false
        
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
        
        firstChild?.view.superview?.backgroundColor = view.backgroundColor
        secondChild?.view.superview?.backgroundColor = view.backgroundColor
        
        if animateLayouts {
            UIView.animate(withDuration: 0.25) {
                self.view.alpha = 0
            }
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+(animateLayouts ? 0.25 : 0), execute: { [weak self] in
            
            guard let self = self else {
                return
            }
            
            self.firstChild = nil
            self.secondChild = nil
            
            /*for view in self.view.subviews {
                view.removeFromSuperview()
            }
            
            let arrangement = self.arrangement
            super.viewDidLoad()
            self.arrangement = arrangement
            super.viewWillTransition(to: self.view.frame.size, with: ViewControllerTransitionCoordinator())
            super.viewDidAppear(true)*/
            
            self.removeGestures()
            
            self.firstChild = self.editor
            self.secondChild = self.console
            
            self.setNavigationBarItems()
            
            if self.animateLayouts {
                UIView.animate(withDuration: 0.25) {
                    self.view.alpha = 1
                }
            }
            
            self.animateLayouts = true
        })
        
        if let path = editor?.document?.fileURL.path, exitScript {
            Python.shared.stop(script: path)
        }
        
        exitScript = true
    }
    
    /// A boolean indicating whether the console is shown in full screen.
    var isConsoleShown = false
    
    /// Shows the console on full screen.
    func showConsole(_ completion: @escaping (() -> Void)) {
        
        isConsoleShown = true
        
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
        
        firstChild?.view.superview?.backgroundColor = view.backgroundColor
        secondChild?.view.superview?.backgroundColor = view.backgroundColor
        
        if animateLayouts {
            UIView.animate(withDuration: 0.25) {
                self.view.alpha = 0
            }
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now()+(animateLayouts ? 0.25 : 0), execute: { [weak self] in
            
            guard let self = self else {
                return
            }
            
            self.firstChild = nil
            self.secondChild = nil
            
            /*for view in self.view.subviews {
                view.removeFromSuperview()
            }
            
            super.viewDidLoad()
            super.viewWillTransition(to: self.view.frame.size, with: ViewControllerTransitionCoordinator())
            super.viewDidAppear(true)*/
            
            self.removeGestures()
            
            self.firstChild = self.console
            self.secondChild = self.editor
            
            self.setNavigationBarItems()
            
            completion()
            
            if self.animateLayouts {
                UIView.animate(withDuration: 0.25) {
                    self.view.alpha = 1
                }
            }
            
            self.animateLayouts = true
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
    
    // MARK: - Split view controller
    
    public override func canPerformAction(_ action: Selector, withSender sender: Any?) -> Bool {
        
        guard let path = editor?.document?.fileURL.path else {
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
    
    public override var keyCommands: [UIKeyCommand]? {
        var commands = [
            UIKeyCommand.command(input: "d", modifierFlags: .command, action: #selector(showDocs), discoverabilityTitle: Localizable.Help.documentation),
            UIKeyCommand.command(input: "f", modifierFlags: .command, action: #selector(search), discoverabilityTitle: Localizable.find),
            UIKeyCommand.command(input: "w", modifierFlags: .command, action: #selector(close), discoverabilityTitle: Localizable.close),
        ]
        
        guard let path = editor?.document?.fileURL.path else {
            return commands
        }
        
        if Python.shared.isScriptRunning(path) {
            commands.append(
                UIKeyCommand.command(input: "c", modifierFlags: .control, action: #selector(interrupt(_:)), discoverabilityTitle: Localizable.interrupt)
            )
        } else {
            commands.append(
                UIKeyCommand.command(input: "r", modifierFlags: .command, action: #selector(runScript(_:)), discoverabilityTitle: Localizable.MenuItems.run)
            )
            
            commands.append(
                UIKeyCommand.command(input: "r", modifierFlags: [.command, .shift], action: #selector(runWithArguments), discoverabilityTitle: Localizable.runAndSetArguments)
            )
        }
        
        return commands
    }
    
    public override func viewDidLoad() {
        super.viewDidLoad()
        
        // In SwiftUI
        parent?.navigationItem.leftItemsSupplementBackButton = true
        
        // In UIKit
        navigationItem.leftItemsSupplementBackButton = true
        
        closeConsoleBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(showEditor))
        
        NotificationCenter.default.addObserver(forName: UIScene.willEnterForegroundNotification, object: nil, queue: OperationQueue.main) { [weak self] (_) in
            
            self?.console?.view.backgroundColor = self?.view.backgroundColor
        }
    }
    
    public override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
        
        if traitCollection.horizontalSizeClass == .compact {
            if arrangement == .horizontal && justShown {
                firstChild = editor
                secondChild = console
            }
        }
        
        firstChild?.view.superview?.backgroundColor = view.backgroundColor
        secondChild?.view.superview?.backgroundColor = view.backgroundColor
    }
    
    public override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        becomeFirstResponder()
        
        if #available(iOS 13.0, *), !(self is REPLViewController), !(self is RunModuleViewController) {
            view.window?.windowScene?.title = editor?.document?.fileURL.deletingPathExtension().lastPathComponent
        }
        
        // Yeah, it's normal that you don't remember why this code is here bc even when you wrote it you didn't know why
        if arrangement == .horizontal && justShown && !shouldShowConsoleAtBottom &&
            !(self is REPLViewController) && !(self is PipInstallerViewController) && !(self is RunModuleViewController) {
            firstChild = editor
            secondChild = console
        }
        
        firstChild?.view.superview?.backgroundColor = view.backgroundColor
        secondChild?.view.superview?.backgroundColor = view.backgroundColor
        
        if justShown {
            willTransition(to: traitCollection, with: ViewControllerTransitionCoordinator())
        }
        
        justShown = false
        
        removeGestures()
        
        #if !Xcode11
        if #available(iOS 14.0, *) {
            container?.update()
        }
        #endif
    }
    
    public override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        if #available(iOS 13.0, *), !(self is REPLViewController), !(self is RunModuleViewController) {
            view.window?.windowScene?.title = ""
        }
    }
    
    public override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        killREPL()
    }
    
    public override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
        #if Xcode11
        guard let firstChild = self.firstChild, let secondChild = self.secondChild else {
            return
        }
        
        firstChild.view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        secondChild.view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        
        firstChild.viewWillTransition(to: firstChild.view.frame.size, with: ViewControllerTransitionCoordinator())
        secondChild.viewWillTransition(to: firstChild.view.frame.size, with: ViewControllerTransitionCoordinator())
        
        firstChild.view.superview?.backgroundColor = view.backgroundColor
        secondChild.view.superview?.backgroundColor = view.backgroundColor
        #else
        editor?.textView.frame = editor?.view.safeAreaLayoutGuide.layoutFrame ?? .zero
        #endif
    }
    
    public override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        guard view != nil else {
            return
        }
        
        super.viewWillTransition(to: size, with: coordinator)
    }
    
    public override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {
        
        guard view != nil else {
            return
        }
        
        if !isiOSAppOnMac {
            guard view.window?.windowScene?.activationState != .background else {
                return
            }
        }
        
        guard presentedViewController == nil else {
            return
        }
        
        if newCollection.horizontalSizeClass == .compact && !shouldShowConsoleAtBottom {
            arrangement = .vertical
        } else {
            
            if shouldShowConsoleAtBottom {
                if arrangement != .vertical {
                    arrangement = .vertical
                }
            } else {
                if arrangement != .horizontal {
                    arrangement = .horizontal
                }
            }
            
            if firstChild != editor || secondChild != console {
                
                for view in self.view.subviews {
                    if view.backgroundColor == .white {
                        view.backgroundColor = self.view.backgroundColor
                    }
                }
                firstChild?.view.superview?.backgroundColor = self.view.backgroundColor
                secondChild?.view.superview?.backgroundColor = self.view.backgroundColor
                
                if shouldShowConsoleAtBottom {
                    arrangement = .vertical
                } else if arrangement != .horizontal {
                    arrangement = .horizontal
                }
                
                #if Xcode11
                if self is REPLViewController || self is RunModuleViewController || self is PipInstallerViewController {
                    firstChild = editor
                    secondChild = console
                } else {
                    if isConsoleShown {
                        showConsole({})
                    } else {
                        showEditor()
                    }
                }
                #else
                firstChild = editor
                secondChild = console
                #endif
            }
        }
    }
    
    public override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        guard view.window?.windowScene?.activationState != .background else {
            return
        }
        
        view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        firstChild?.view.backgroundColor = view.backgroundColor
        secondChild?.view.backgroundColor = view.backgroundColor
    }
    
    public override var canBecomeFirstResponder: Bool {
        return true
    }
    
    public override var prefersHomeIndicatorAutoHidden: Bool {
        return (editor?.textView.contentTextView.isFirstResponder ?? false) || (console?.movableTextField?.textField.isFirstResponder ?? false)
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
            return UIImage(systemName: "list.bullet") ?? UIImage(named: "more") ?? UIImage()
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
    
    /// A Split view controller displaying a file browser and the code editor?.
    class ProjectSplitViewController: UISplitViewController {
        
        /// The editor.
        var editor: EditorSplitViewController?
    }
    
    fileprivate var containerViewController: UIViewController?
}

#if !Xcode11
@available(iOS 14.0, *)
extension EditorSplitViewController: ContainedViewController {
    
    // MARK: - Contained view controller
    
    public var container: ContainerViewController? {
        set {
            containerViewController = newValue
        }
        
        get {
            return containerViewController as? ContainerViewController
        }
    }
}
#endif
