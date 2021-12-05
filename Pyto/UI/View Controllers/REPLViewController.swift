//
//  REPLSplitViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 1/21/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

/// A View controller with the REPL.
@objc class REPLViewController: EditorSplitViewController, UIDocumentPickerDelegate {
    
    @objc private static var scriptsToRun = NSMutableArray() // Selected scripts to run
    
    /// The shared instance.
    @objc static var shared: REPLViewController?
    
    /// The directory picked from the directory picker per script path.
    static var pickedDirectory = [String:String]()
    
    /// Set to `false` to not reload the REPL.
    var reloadREPL = false
    
    /// Goes back to the file browser
    @objc static func goToFileBrowser() {
        DispatchQueue.main.async {
            REPLViewController.shared?.dismiss(animated: true, completion: nil)
        }
    }
    
    /// Goes back to the file browser
    @objc func goToFileBrowser() {
        DispatchQueue.main.async { [weak self] in
            self?.dismiss(animated: true, completion: nil)
        }
    }
    
    /// Runs a selected script in the REPL.
    @objc func addScript() {
        let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.pythonScript])
        picker.delegate = self
        picker.allowsMultipleSelection = true
        present(picker, animated: true, completion: nil)
    }
    
    @objc private func setCurrentDirectory() {
        console?.movableTextField?.textField.resignFirstResponder()
        let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
        picker.allowsMultipleSelection = true
        picker.delegate = self
        present(picker, animated: true, completion: nil)
    }
    
    /// Set to `true` to disable the REPL banner.
    var noBanner = false {
        didSet {
            loadViewIfNeeded()
            editor?.args = "no-banner"
        }
    }
    
    @objc private var scriptPath: String?
    
    private var opened = false
        
    // MARK: - Editor split view controller
    
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
            
            let editor = EditorViewController(document: PyDocument(fileURL: newURL))
            self.editor = editor
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
                
        let chdirItem = UIBarButtonItem(barButtonSystemItem: .organize, target: self, action: #selector(setCurrentDirectory))
        
        navigationItem.leftBarButtonItems = []
        if #available(iOS 13.0, *) {
            navigationItem.rightBarButtonItems = [chdirItem, UIBarButtonItem(image: UIImage(systemName: "arrow.down.doc") ?? UIImage(), style: .plain, target: self, action: #selector(addScript))]
        } else {
            navigationItem.rightBarButtonItems = [chdirItem]
        }
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(goToFileBrowser))
        }
        
        navigationItem.largeTitleDisplayMode = .never
        
        parent?.navigationItem.rightBarButtonItems = navigationItem.rightBarButtonItems
        
        navigationController?.isToolbarHidden = true
        title = NSLocalizedString("repl", comment: "'REPL' tab")
        parent?.title = title
        parent?.navigationItem.title = title
        
        if #available(iOS 13.0, *) {
            view.backgroundColor = .systemBackground
        } else {
            view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if !opened, let script = editor?.document?.fileURL.path, !Python.shared.isScriptRunning(script) {
            opened = true
            editor?.currentDirectory = (splitViewController as? SidebarSplitViewController)?.fileBrowser.directory ?? editor!.currentDirectory
            _ = Timer.scheduledTimer(withTimeInterval: 0.3, repeats: true, block: { [weak self] (timer) in
                if Python.shared.isSetup && isUnlocked {
                    self?.editor?.run()
                    timer.invalidate()
                }
            })
        }
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
        }
    }
        
    // MARK: Document picker view controller
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        
        guard editor != nil else {
            return
        }
        
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: urls[0].path, isDirectory: &isDir), isDir.boolValue {
            console?.movableTextField?.focus()
            _ = urls[0].startAccessingSecurityScopedResource()
            Self.pickedDirectory[editor!.document!.fileURL.path] = urls[0].path
        } else {
            REPLViewController.scriptsToRun = NSMutableArray()
            for url in urls {
                _ = url.startAccessingSecurityScopedResource()
                
                REPLViewController.scriptsToRun.add(url.path)
            }
            
            let code = """
            import console
            import importlib.util
            from pyto import REPLViewController, PyInputHelper

            print()

            for script in REPLViewController.scriptsToRun:
                spec = importlib.util.spec_from_file_location("__main__", str(script))
                script = importlib.util.module_from_spec(spec)
                spec.loader.exec_module(script)

                console.__repl_namespace__[__file__.split("/")[-1]].update(vars(script))
                PyInputHelper.userInput.setObject("", forKey=__file__)
            """
            
            guard editor!.document!.fileURL.lastPathComponent.hasSuffix(".repl.py") else {
                return
            }
            
            try? code.write(to: editor!.document!.fileURL, atomically: true, encoding: .utf8)
            
            var arguments = editor!.args.components(separatedBy: " ")
            ParseArgs(&arguments)
                                    
            Python.shared.run(script: .init(path: editor!.document!.fileURL.path, args: NSArray(array: arguments), workingDirectory: editor!.currentDirectory.path, debug: false, runREPL: true))
        }
    }
}
