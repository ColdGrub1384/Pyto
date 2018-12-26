//
//  REPLViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 10/12/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// The View controller for the REPL in the Tab bar controller.
class REPLViewController: ConsoleViewController {
    
    /// The visible instance.
    static var visibleREPL: REPLViewController?
    
    // MARK: - Console view controller
    
    override var ignoresInput: Bool {
        get {
            return false
        }
        
        set {}
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        REPLViewController.visibleREPL = self
        title = Localizable.repl
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationController?.view.backgroundColor = .white
        navigationController?.navigationBar.shadowImage = UIImage()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        textView.text = ""
        prompt = ""
        console = ""
        
        if Python.shared.isREPLRunning {
            
            func sendInput() {
                PyInputHelper.userInput = [
                    "import os",
                    "import PytoClasses",
                    "import sys",
                    "iCloudDrive = '\(DocumentBrowserViewController.iCloudContainerURL?.path ?? DocumentBrowserViewController.localContainerURL.path)'",
                    "sys.path.insert(0, iCloudDrive)",
                    "os.system = PytoClasses.Python.shared.system",
                    "import code",
                    "code.interact()",
                    "sys.path.remove(iCloudDrive)"
                ].joined(separator: ";")
            }
            
            if !Python.shared.isScriptRunning {
                sendInput()
            } else {
                Python.shared.isScriptRunning = false
                
                DispatchQueue.main.asyncAfter(deadline: .now()+2) {
                    sendInput()
                }
            }
        }
    }
    
    override func numberOfSuggestionsInInputAssistantView() -> Int {
        return 0
    }
}

