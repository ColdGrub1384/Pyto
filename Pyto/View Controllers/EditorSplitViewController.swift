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
    @objc var console: ConsoleViewController!
    
    /// Set to `true` if this View controller was just shown.
    var justShown = true
    
    /// A down arrow image for dismissing keyboard.
    static var downArrow: UIImage {
        return UIGraphicsImageRenderer(size: .init(width: 24, height: 24)).image(actions: { context in
         
            let path = UIBezierPath()
            path.move(to: CGPoint(x: 1, y: 7))
            path.addLine(to: CGPoint(x: 11, y: 17))
            path.addLine(to: CGPoint(x: 22, y: 7))
            
            if ConsoleViewController.choosenTheme.keyboardAppearance == .dark {
                UIColor.white.setStroke()
            } else {
                UIColor.black.setStroke()
            }
            path.lineWidth = 2
            path.stroke()
            
            context.cgContext.addPath(path.cgPath)
            
        }).withRenderingMode(.alwaysOriginal)
    }
    
    /// Last visible controller.
    //@available(*, deprecated, message: "Use scenes APIs instead.") @objc static var visible: EditorSplitViewController?
    
    // MARK: - Key commands
    
    /// Runs the code
    @objc func run() {
        editor?.run()
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
    
    /// Interrupts current running script.
    @objc func interrupt() {
        Python.shared.interrupt()
    }
    
    /// Sets navigation bar items.
    func setNavigationBarItems() {
        if firstChild == editor {
            navigationItem.leftBarButtonItems = [editor.scriptsItem, editor.searchItem]
            if Python.shared.isScriptRunning {
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
        firstChild = nil
        secondChild = nil
        
        for view in view.subviews {
            view.removeFromSuperview()
        }
        
        super.viewDidLoad()
        super.viewWillTransition(to: view.frame.size, with: ViewControllerTransitionCoordinator())
        super.viewDidAppear(true)
        
        removeGestures()
        
        firstChild = editor
        secondChild = console
        
        setNavigationBarItems()
        
        Python.shared.stop()
    }
    
    /// Shows the console on full screen.
    func showConsole(_ completion: @escaping (() -> Void)) {
        
        firstChild = nil
        secondChild = nil
        
        for view in view.subviews {
            view.removeFromSuperview()
        }
        
        super.viewDidLoad()
        super.viewWillTransition(to: view.frame.size, with: ViewControllerTransitionCoordinator())
        super.viewDidAppear(true)
        
        removeGestures()
        
        firstChild = console
        secondChild = editor
        
        setNavigationBarItems()
        
        completion()
    }
    
    private func removeGestures() {
        if ratio == 1 {
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
    
    override var keyCommands: [UIKeyCommand]? {
        var commands = [
            UIKeyCommand(input: "r", modifierFlags: .command, action: #selector(run), discoverabilityTitle: Localizable.MenuItems.run),
            UIKeyCommand(input: "r", modifierFlags: [.command, .shift], action: #selector(runWithArguments), discoverabilityTitle: Localizable.runAndSetArguments),
            UIKeyCommand(input: "d", modifierFlags: .command, action: #selector(showDocs), discoverabilityTitle: Localizable.Help.documentation),
            UIKeyCommand(input: "w", modifierFlags: .command, action: #selector(close), discoverabilityTitle: Localizable.close),
        ]
        
        if Python.shared.isScriptRunning {
            commands.append(
                UIKeyCommand(input: "c", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: Localizable.interrupt)
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
        
        if #available(iOS 13.0, *) {
            view.backgroundColor = .systemBackground
        } else {
            view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        }
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
        
        if arrangement == .horizontal && justShown {
            firstChild = editor
            secondChild = console
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        willTransition(to: traitCollection, with: ViewControllerTransitionCoordinator())
        justShown = false
        
        removeGestures()
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
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {
        
        guard presentedViewController == nil else {
            return
        }
        
        if newCollection.horizontalSizeClass == .compact && !EditorSplitViewController.shouldShowConsoleAtBottom {
            arrangement = .vertical
        } else {
            
            if EditorSplitViewController.shouldShowConsoleAtBottom {
                arrangement = .vertical
            }
            
            if firstChild != editor || secondChild != console {
                
                for view in view.subviews {
                    view.removeFromSuperview()
                }
                
                super.viewDidLoad()
                super.viewDidAppear(true)
                removeGestures()
                
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
}
