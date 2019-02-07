//
//  REPLSplitViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/21/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller with the REPL.
@objc class REPLViewController: EditorSplitViewController {
    
    /// The shared instance.
    @objc static var shared: REPLViewController?
    
    /// Set to `false` to don't reload the REPL.
    var reloadREPL = true
    
    /// Goes back to the file browser
    @objc static func goToFileBrowser() {
        DispatchQueue.main.async {
            (UIApplication.shared.keyWindow?.rootViewController as? UITabBarController)?.selectedIndex = 0
        }
    }
    
    // MARK: - Editor split view controller
    
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: Localizable.interrupt)]
    }
    
    override func loadView() {
        super.loadView()
        
        if let repl = Bundle.main.url(forResource: "UserREPL", withExtension: "py") {
            editor = EditorViewController(document: repl)
        }
        console = ConsoleViewController()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        REPLViewController.shared = self
        
        addChild(console)
        view.addSubview(console.view)
        console.view.frame = view.frame
        console.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if !Python.shared.isScriptRunning {
            editor.run()
        }
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
}
