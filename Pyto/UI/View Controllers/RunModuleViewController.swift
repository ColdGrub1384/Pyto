//
//  PipInstallerViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 5/5/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

/// A View controller for running `python -m` commands.
@objc class RunModuleViewController: EditorSplitViewController, UIDocumentPickerDelegate {
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
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
        
    private var viewAppeared = false
    
    @objc private func setCurrentDirectory() {
        console?.movableTextField?.textField.resignFirstResponder()
        let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
        picker.delegate = self
        picker.allowsMultipleSelection = true
        present(picker, animated: true, completion: nil)
    }
    
    // MARK: - Editor split view controller
    
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand.command(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: NSLocalizedString("interrupt", comment: "Description for CTRL+C key command."))]
    }
    
    override func loadView() {
        super.loadView()
        
        ratio = 0
        
        if let repl = Bundle.main.url(forResource: "command_runner", withExtension: "py") {
            
            /// Taken from https://stackoverflow.com/a/26845710/7515957
            func randomString(length: Int) -> String {
                let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
                return String((0..<length).map{ _ in letters.randomElement()! })
            }
            
            let newURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(randomString(length: 5)).appendingPathExtension("repl.py")
            try? FileManager.default.copyItem(at: repl, to: newURL)
            
            let editor = EditorViewController(document: PyDocument(fileURL: newURL))
            self.editor = editor
        }
        
        console = ConsoleViewController()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = "Shell"
        
        firstChild = editor
        secondChild = console
        
        arrangement = .horizontal
        
        navigationItem.largeTitleDisplayMode = .never
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationItem.leftBarButtonItems = []
        navigationItem.rightBarButtonItems = []
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .organize, target: self, action: #selector(setCurrentDirectory))
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(goToFileBrowser))
        }
        navigationController?.isToolbarHidden = true
        title = "Shell"
        parent?.title = title
        parent?.navigationItem.title = title
        parent?.navigationItem.rightBarButtonItems = navigationItem.rightBarButtonItems
                
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        guard !viewAppeared else {
            return
        }
        
        #if SCREENSHOTS
        console?.print("\u{1B}[2J\u{1B}[H\u{1B}[3JType the name of a module to run it as \'__main__\'.\nRun \'help\' to show a list of executable modules.\n\u{1B}[32mDocuments\u{1B}[39m $ ls\n\u{1B}[34mProjects\u{1B}[39m\n\u{1B}[34mTemplates\u{1B}[39m\n\u{1B}[34mWidgets\u{1B}[39m\nmy_script.py\n\u{1B}[34mtest\u{1B}[39m\n\u{1B}[32mDocuments\u{1B}[39m $ edit my_script.py\nSave as [my_script.py] (^c to not save): \n\u{1B}[32mDocuments\u{1B}[39m $ python my_script.py\nThis script is executed from the shell\nArguments: [\'my_script.py\']\n\u{1B}[32mDocuments\u{1B}[39m $ pip uninstall sympy\nPackage removed.\nRemoving dependency: mpmath\nPackage removed.\n\u{1B}[32mDocuments\u{1B}[39m $ help\n\u{1B}[1mBuiltins\u{1B}[0m\ncd, clear, edit, exit, help, ls, man, pip, python, rm\n\n\u{1B}[1m* Everything in sys.path\u{1B}[0m\n\u{1B}[32mDocuments\u{1B}[39m $ ")
        #endif
        
        viewAppeared = true
        
        #if !SCREENSHOTS
        _ = Timer.scheduledTimer(withTimeInterval: 0.3, repeats: true, block: { [weak self] (timer) in
            if Python.shared.isSetup && isUnlocked {
                if let dir = (self?.view.window?.windowScene?.delegate as? SceneDelegate)?.sidebarSplitViewController?.fileBrowser.directory {
                    self?.editor?.currentDirectory = dir
                }
                self?.editor?.run()
                timer.invalidate()
            }
        })
        #endif
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
    
    // MARK: Document picker view controller
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        console?.movableTextField?.focus()
        _ = urls[0].startAccessingSecurityScopedResource()
        REPLViewController.pickedDirectory[editor!.document!.fileURL.path] = urls[0].path
        console?.movableTextField?.handler?("")
    }
}

