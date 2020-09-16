//
//  PipInstallerViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 5/5/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller for running `python -m` commands.
@objc class RunModuleViewController: EditorSplitViewController, UIDocumentPickerDelegate {
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    /// The last visible instance.
    static var shared: RunModuleViewController?
    
    /// Arguments sent to the script containing script to run name.
    var argv: [String]? {
        didSet {
            loadViewIfNeeded()
            editor?.args = argv?.joined(separator: " ") ?? ""
        }
    }
    
    @objc private func goToFileBrowser() {
        dismiss(animated: true, completion: nil)
    }
    
    private static let console = ConsoleViewController()
    
    private var viewAppeared = false
    
    @objc private func setCurrentDirectory() {
        console.movableTextField?.textField.resignFirstResponder()
        let picker = UIDocumentPickerViewController(documentTypes: ["public.folder"], in: .open)
        picker.delegate = self
        picker.allowsMultipleSelection = true
        present(picker, animated: true, completion: nil)
    }
    
    // MARK: - Editor split view controller
    
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand.command(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: Localizable.interrupt)]
    }
    
    override func loadView() {
        super.loadView()
        
        ratio = 0
        
        if let repl = Bundle.main.url(forResource: "command_runner", withExtension: "py") {
            let editor = EditorViewController(document: PyDocument(fileURL: repl))
            self.editor = editor
            self.editor?.args = ""
        }
        console = RunModuleViewController.console
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        firstChild = editor
        secondChild = console
        
        arrangement = .horizontal
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationItem.leftBarButtonItems = []
        navigationItem.rightBarButtonItems = []
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .organize, target: self, action: #selector(setCurrentDirectory))
        navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(goToFileBrowser))
        navigationController?.isToolbarHidden = true
        title = Localizable.repl
        parent?.title = title
        parent?.navigationItem.title = title
        parent?.navigationItem.rightBarButtonItems = navigationItem.rightBarButtonItems
        
        RunModuleViewController.shared = self
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        guard !viewAppeared else {
            return
        }
        
        viewAppeared = true
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.3, repeats: true, block: { (timer) in
            if Python.shared.isSetup && isUnlocked {
                self.editor?.run()
                timer.invalidate()
            }
        })
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        editor?.stop()
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
    
    // MARK: Document picker view controller
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        console.movableTextField?.focus()
        _ = urls[0].startAccessingSecurityScopedResource()
        Python.shared.run(code: "import os, sys; path = \"\(urls[0].path.replacingOccurrences(of: "\"", with: "\\\""))\"; os.chdir(path); sys.path.append(path)")
    }
}

