//
//  LocalsAndGlobalsREPLViewController.swift
//  Pyto
//
//  Created by Emma on 20-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit

class LocalsAndGlobalsREPLViewController: ScriptRunnerViewController {
    
    var id: String?
    
    var url: URL?
    
    init(id: String, line: String, url: URL) {
        
        func randomString(length: Int) -> String {
          let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
          return String((0..<length).map{ _ in letters.randomElement()! })
        }
        
        let scriptURL = Bundle.main.url(forResource: "locals_and_globals_repl", withExtension: "py")!
        let newURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(randomString(length: 5)+".repl.py")
        
        var scriptContent = try! String(contentsOf: scriptURL)
        scriptContent = scriptContent.replacingOccurrences(of: "%ID%", with: id)
        scriptContent = scriptContent.replacingOccurrences(of: "%LINE%", with: line.replacingOccurrences(of: "\"", with: "\\\""))
        try? scriptContent.write(to: newURL, atomically: false, encoding: .utf8)
        
        self.url = url
        
        super.init(scriptURL: newURL)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func loadView() {
        super.loadView()
        
        ratio = 0
        
        if let script = scriptURL {
            let editor = EditorViewController(document: PyDocument(fileURL: script))
            self.editor = editor
        }
        console = ConsoleViewController()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationItem.rightBarButtonItems = []
        parent?.navigationItem.rightBarButtonItems = []
        
        navigationController?.isToolbarHidden = true
        
        title = scriptURL.deletingPathExtension().lastPathComponent
        
        navigationItem.rightBarButtonItems = []
        parent?.navigationItem.rightBarButtonItems = []
    }
}
