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
    
    override var ignoresInput: Bool {
        get {
            return false
        }
        
        set {}
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = Localizable.repl
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        prompt = ""
        console = ""
        textView.text = ""
        
        if Python.shared.isREPLRunning {
            if !Python.shared.isScriptRunning {
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
            } else {
                PyOutputHelper.print(Localizable.Python.alreadyRunning)
            }
        }
    }
    
    override func input(prompt: String) {
        guard textView != nil else {
            return
        }
        super.input(prompt: prompt)
    }
    
    
}

