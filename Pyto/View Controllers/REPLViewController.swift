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
    
    /// Goes back to the file browser
    @objc func goToFileBrowser() {
        DispatchQueue.main.async {
            self.dismiss(animated: true, completion: nil)
        }
    }
    
    @objc private func setCurrentDirectory() {
        let picker = UIDocumentPickerViewController(documentTypes: ["public.folder"], in: .open)
        picker.delegate = self
        present(picker, animated: true, completion: nil)
    }
    
    // MARK: - Editor split view controller
    
    #if !targetEnvironment(UIKitForMac)
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: Localizable.interrupt)]
    }
    #endif
    
    override func loadView() {
        super.loadView()
        
        ratio = 0
        
        if let repl = Bundle.main.url(forResource: "UserREPL", withExtension: "py") {
            
            /// Taken from https://stackoverflow.com/a/26845710/7515957
            func randomString(length: Int) -> String {
                let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
                return String((0..<length).map{ _ in letters.randomElement()! })
            }
            
            let newURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(randomString(length: 5)).appendingPathExtension("repl.py")
            try? FileManager.default.copyItem(at: repl, to: newURL)
            
            editor = EditorViewController(document: PyDocument(fileURL: newURL))
        }
        console = ConsoleViewController()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        arrangement = .horizontal
        REPLViewController.shared = self
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationItem.leftBarButtonItems = []
        navigationItem.rightBarButtonItems = []
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .organize, target: self, action: #selector(setCurrentDirectory))
        #if targetEnvironment(UIKitForMac)
        navigationItem.leftBarButtonItems = []
        #else
        navigationItem.leftBarButtonItem = UIBarButtonItem(image: EditorSplitViewController.gridImage, style: .plain, target: self, action: #selector(goToFileBrowser))
        #endif
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
        
        if let script = editor.document?.fileURL.path, !Python.shared.isScriptRunning(script) {
            editor.run()
        }
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
            view.window?.windowScene?.titlebar?.titleVisibility = .hidden
        }
    }
    
    // MARK: Document picker view controller
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        _ = urls[0].startAccessingSecurityScopedResource()
        console.movableTextField?.textField.text = "import os; os.chdir(\"\(urls[0].path.replacingOccurrences(of: "\"", with: "\\\""))\")"
        console.movableTextField?.textField.becomeFirstResponder()
    }
}
