//
//  REPLSplitViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/21/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller with the REPL.
@objc class REPLViewController: EditorSplitViewController, UIDocumentPickerDelegate {
    
    /// The shared instance.
    @objc static var shared: REPLViewController?
    
    /// Set to `false` to don't reload the REPL.
    var reloadREPL = true
    
    /// Goes back to the file browser
    @objc static func goToFileBrowser() {
        DispatchQueue.main.async {
            REPLViewController.shared?.dismiss(animated: true, completion: nil)
        }
    }
    
    @objc private func setCurrentDirectory() {
        let picker = UIDocumentPickerViewController(documentTypes: ["public.folder"], in: .open)
        picker.delegate = self
        present(picker, animated: true, completion: nil)
    }
    
    // MARK: - Editor split view controller
    
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: Localizable.interrupt)]
    }
    
    override func loadView() {
        super.loadView()
        
        ratio = 0
        
        if let repl = Bundle.main.url(forResource: "UserREPL", withExtension: "py") {
            editor = EditorViewController(document: PyDocument(fileURL: repl))
        }
        console = ConsoleViewController()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        REPLViewController.shared = self
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationItem.leftBarButtonItems = []
        navigationItem.rightBarButtonItems = []
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .organize, target: self, action: #selector(setCurrentDirectory))
        navigationItem.leftBarButtonItem = UIBarButtonItem(image: EditorSplitViewController.gridImage, style: .plain, target: REPLViewController.self, action: #selector(REPLViewController.goToFileBrowser))
        navigationController?.isToolbarHidden = true
        title = Localizable.repl
        
        if #available(iOS 13.0, *) {
            view.backgroundColor = .systemBackground
        } else {
            view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if !Python.shared.isScriptRunning {
            editor.run()
        }
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
    
    // MARK: Document picker view controller
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        _ = urls[0].startAccessingSecurityScopedResource()
        console.movableTextField?.textField.text = "import os; os.chdir(\"\(urls[0].path.replacingOccurrences(of: "\"", with: "\\\""))\")"
        console.movableTextField?.textField.becomeFirstResponder()
    }
}
