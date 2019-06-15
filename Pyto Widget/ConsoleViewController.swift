//
//  TodayViewController.swift
//  Pyto Widget
//
//  Created by Adrian Labbé on 2/3/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import NotificationCenter

fileprivate var isPythonSetup = false

/// View controller with console content on the Today widget.
@objc class ConsoleViewController: UIViewController, NCWidgetProviding {
    
    /// The visible instance.
    @objc static var visible: ConsoleViewController!
    
    /// Set to `true` to start the script.
    @objc static var startScript = true
    
    /// The shared directory path to be passed to Python.
    @objc static var sharedDirectoryPath: String?
    
    /// Text view containing the console.
    @IBOutlet weak var textView: UITextView!
    
    /// Adds given text to the text view.
    ///
    /// - Parameters:
    ///     - text: Text to be added.
    @objc func print(_ text: String) {
        DispatchQueue.main.async {
            self.textView.text += text
        }
    }
    
    /// Clears screen.
    @objc func clear() {
        DispatchQueue.main.sync {
            textView.text = ""
        }
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view from its nib.
        
        ConsoleViewController.sharedDirectoryPath = dir?.path
        
        if !isPythonSetup {
            setup_python()
            isPythonSetup = true
        }
        
        sharedExtensionContext?.widgetLargestAvailableDisplayMode = .expanded
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if ConsoleViewController.visible != self {
            ConsoleViewController.visible = self
        }
    }
    
    // MARK: - Widget providing
    
    func widgetPerformUpdate(completionHandler: (@escaping (NCUpdateResult) -> Void)) {
        // Perform any setup necessary in order to update the view.
        
        // If an error is encountered, use NCUpdateResult.Failed
        // If there's no update required, use NCUpdateResult.NoData
        // If there's an update, use NCUpdateResult.NewData
        
        textView.text = ""
        ConsoleViewController.startScript = true
        
        let main = """
        __builtins__.iOS = "iOS"
        __builtins__.macOS = "macOS"
        __builtins__.__platform__ = __builtins__.iOS

        __builtins__.widget = "widget"
        __builtins__.app = "app"
        __builtins__.__host__ = widget

        import traceback

        try:
            import importlib.util
            from time import sleep
            import sys
            from outputredirector import *
            from extensionsimporter import *
            import pyto
            import io
        except Exception as e:
            ex_type, ex, tb = sys.exc_info()
            traceback.print_tb(tb)
        
        # MARK: - Create selector without class
        
        __builtins__.Selector = pyto.PySelector.makeSelector
        __builtins__.Target = pyto.SelectorTarget.shared

        # MARK: - Output
        
        def read(text):
            pyto.ConsoleViewController.visible.print(text)
        
        standardOutput = Reader(read)
        standardOutput._buffer = io.BufferedWriter(standardOutput)
        
        standardError = Reader(read)
        standardError._buffer = io.BufferedWriter(standardError)
        
        sys.stdout = standardOutput
        sys.stderr = standardError
                
        # MARK: - Run script

        directory = pyto.ConsoleViewController.sharedDirectoryPath
        
        if not directory+"/modules" in sys.path:
            sys.path.append(directory+"/modules")

        def run():
            pyto.ConsoleViewController.startScript = False
        
            try:
                spec = importlib.util.spec_from_file_location("__main__", directory+"/main.py")
                script = importlib.util.module_from_spec(spec)
                spec.loader.exec_module(script)
            except Exception as e:
                print(e.__class__.__name__, e)
        
            while not pyto.ConsoleViewController.startScript:
                sleep(0.5)
        
            run()

        run()
        """
        
        if Python.shared.runningScripts.count == 0, let newScriptURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask).first?.appendingPathComponent("main.py") {
            
            do {
                if FileManager.default.fileExists(atPath: newScriptURL.path) {
                    try FileManager.default.removeItem(at: newScriptURL)
                }
                if !FileManager.default.createFile(atPath: newScriptURL.path, contents: main.data(using: .utf8), attributes: nil) {
                    throw NSError(domain: "pyto.widget", code: 1, userInfo: [NSLocalizedDescriptionKey : "Error creating startup script."])
                }
                Python.shared.runScript(at: newScriptURL)
            } catch {
                print(error.localizedDescription)
            }
        }
        
        completionHandler(NCUpdateResult.newData)
    }
}
