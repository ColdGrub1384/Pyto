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
    
    var titleView: UIStackView!
    
    var previousTitle = ""
    
    func setTitle(_ title: String) {
        let size = console?.terminalSize
        self.title = "\(ShortenFilePaths(in: title)) — \(size?.columns ?? 0)x\(size?.rows ?? 0)"
    }
    
    private var chdir = false
    
    // MARK: - Editor split view controller
    
    override var title: String? {
        didSet {
            for view in titleView.subviews {
                if let label = view as? UILabel {
                    label.text = title
                    label.sizeToFit()
                    titleView.sizeToFit()
                    break
                }
            }
            
            if view.window != nil {
                view.window?.windowScene?.title = title
            }
        }
    }
    
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
        
        let chdirButton = UIButton(frame: CGRect(origin: .zero, size: CGSize(width: 40, height: 40)))
        chdirButton.setImage(UIImage(systemName: "folder.fill"), for: .normal)
        chdirButton.tintColor = .systemBlue
        chdirButton.addTarget(self, action: #selector(setCurrentDirectory), for: .touchUpInside)
        
        let titleLabel = UILabel()
        titleLabel.font = UIFont.boldSystemFont(ofSize: UIFont.systemFontSize)
        
        titleView = UIStackView(arrangedSubviews: [chdirButton, titleLabel])
        titleView.spacing = 10 
        titleView.axis = .horizontal
        titleLabel.sizeToFit()
        titleView.sizeToFit()
        
        navigationItem.titleView = titleView
        
        super.viewDidLoad()
        
        title = ""
        
        firstChild = editor
        secondChild = console
        
        arrangement = .horizontal
        
        navigationItem.largeTitleDisplayMode = .never
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationItem.leftBarButtonItems = []
        navigationItem.rightBarButtonItems = []
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(goToFileBrowser))
        }
        navigationController?.isToolbarHidden = true
        parent?.title = title
        parent?.navigationItem.title = title
        parent?.navigationItem.rightBarButtonItems = navigationItem.rightBarButtonItems
                
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        view.window?.windowScene?.title = nil
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if chdir {
            console?.input = ""
            console?.webView.enter()
            chdir = false
        }
        
        guard !viewAppeared else {
            return
        }
        
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
        
        view.window?.windowScene?.title = title
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {}
    
    // MARK: Document picker view controller
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        _ = urls[0].startAccessingSecurityScopedResource()
        REPLViewController.pickedDirectory[editor!.document!.fileURL.path] = urls[0].path
        if view.window == nil {
            chdir = true // chdir on viewDidAppear
        } else {
            console?.input = ""
            console?.webView.enter()
        }
    }
}

