//
//  PipInstallerViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 3/20/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import WebKit

/// A View controller for running `pip` commands.
@objc class PipInstallerViewController: EditorSplitViewController {
    
    /// `true` if pip finished running.
    var done = false
    
    private var executed = false
    
    /// Closes this View controller.
    @objc func closeViewController() {
        return dismiss(animated: true, completion: {
            self.viewer?.tableView.reloadData()
        })
    }
    
    /// The View controller that requested the action.
    var viewer: PipViewController?
    
    private var command = ""
    
    /// Initializes for running given `pip` command.
    ///
    /// - Parameters:
    ///     - command: The command to run. Without the program name. For example, `install bottle` for running `pip install bottle`.
    init(command: String) {
        super.init(nibName: nil, bundle: nil)
        self.command = command
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    /// The last visible instance.
    static var shared: PipInstallerViewController?
    
    // MARK: - Editor split view controller
    
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand.command(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: NSLocalizedString("interrupt", comment: "Description for CTRL+C key command."))]
    }
    
    override func loadView() {
        super.loadView()
        
        ratio = 0
        
        if let repl = Bundle.main.url(forResource: "installer", withExtension: "py") {
            editor = EditorViewController(document: PyDocument(fileURL: repl))
            editor?.args = command
        }
        console = ConsoleViewController()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        arrangement = .horizontal
        if #available(iOS 13.0, *) {
            isModalInPresentation = true
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        viewer?.tableView.reloadData()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationItem.leftBarButtonItems = []
        navigationItem.rightBarButtonItems = []
        navigationController?.isToolbarHidden = true        
        PipInstallerViewController.shared = self
        
        navigationItem.leftBarButtonItems = [UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(closeViewController))]
        navigationItem.leftBarButtonItem?.isEnabled = false
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        guard !done && !executed else {
            return
        }
        
        executed = true
        
        if let path = editor?.document?.fileURL.path, Python.shared.isScriptRunning(path) {
            editor?.stop()
            DispatchQueue.main.asyncAfter(deadline: .now()+2) { [weak self] in
                self?.editor?.run()
            }
        } else {
            DispatchQueue.main.asyncAfter(deadline: .now()+1) { [weak self] in
                self?.editor?.run()
            }
        }
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
}

