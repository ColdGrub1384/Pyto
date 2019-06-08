//
//  PipInstallerViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 5/5/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller for running `python -m` commands.
@objc class RunModuleViewController: EditorSplitViewController {
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    /// The last visible instance.
    static var shared: RunModuleViewController?
    
    /// Arguments sent to the script containing script to run name.
    var argv: [String]? {
        didSet {
            loadViewIfNeeded()
            editor.args = argv?.joined(separator: " ") ?? ""
        }
    }
    
    @objc private func goToFileBrowser() {
        dismiss(animated: true, completion: nil)
    }
    
    private static let console = ConsoleViewController()
    
    // MARK: - Editor split view controller
    
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: Localizable.interrupt)]
    }
    
    override func loadView() {
        super.loadView()
        
        if let repl = Bundle.main.url(forResource: "command_runner", withExtension: "py") {
            editor = EditorViewController(document: PyDocument(fileURL: repl))
        }
        console = RunModuleViewController.console
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        edgesForExtendedLayout = []
                
        addChild(console)
        view.addSubview(console.view)
        console.view.frame = view.frame
        console.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        navigationItem.leftBarButtonItem = UIBarButtonItem(image: UIImage(named: "Grid"), style: .plain, target: self, action: #selector(goToFileBrowser))
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        RunModuleViewController.shared = self
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if Python.shared.isScriptRunning {
            editor.stop()
            DispatchQueue.main.asyncAfter(deadline: .now()+2) {
                self.editor.run()
            }
        } else {
            DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                self.editor.run()
            }
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        editor.stop()
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
}

