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
    @objc static var visible: EditorSplitViewController?
    
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
        
    // MARK: - Split view controller
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        for view in self.view.subviews {
            if view.backgroundColor == .white {
                view.backgroundColor = self.view.backgroundColor
            }
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        willTransition(to: traitCollection, with: ViewControllerTransitionCoordinator())
        justShown = false
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
        
        if newCollection.horizontalSizeClass == .compact {
            firstChild?.view.removeFromSuperview()
            firstChild?.removeFromParent()
            secondChild?.view.removeFromSuperview()
            secondChild?.removeFromParent()
            firstChild = nil
            secondChild = nil
            
            for view in view.subviews {
                view.removeFromSuperview()
            }
            
            let justShown = self.justShown
            DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
                self.addChild(self.editor)
                self.editor.view.frame = self.view.bounds
                self.editor.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                self.view.addSubview(self.editor.view)
                
                if Python.shared.isScriptRunning && !justShown {
                    let navVC = UINavigationController(rootViewController: self.console)
                    navVC.modalPresentationStyle = .overFullScreen
                    self.present(navVC, animated: true, completion: nil)
                }
            }
        } else {
            
            for view in view.subviews {
                view.removeFromSuperview()
            }
            
            viewDidLoad()
            arrangement = .horizontal
            super.viewDidAppear(false)
            
            firstChild = editor
            secondChild = console
        }
    }    
}
