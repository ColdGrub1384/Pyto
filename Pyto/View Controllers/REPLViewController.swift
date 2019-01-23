//
//  REPLSplitViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/21/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller with the REPL.
class REPLViewController: EditorSplitViewController {
    
    /// The shared instance.
    static var shared: REPLViewController?
    
    // MARK: - Editor split view controller
    
    override func loadView() {
        super.loadView()
        
        if let repl = Bundle.main.url(forResource: "UserREPL", withExtension: "py") {
            editor = EditorViewController(document: PyDocument(fileURL: repl))
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
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        console.completions = []
        console.suggestions = []
        editor.close()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        editor.run()
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
}
