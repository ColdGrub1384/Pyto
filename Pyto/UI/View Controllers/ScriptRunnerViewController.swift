//
//  ScriptRunnerViewController.swift
//  Pyto
//
//  Created by Emma on 06-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit
import AVKit

/// A View Controller showing the console of a running script.
class ScriptRunnerViewController: REPLViewController {
    
    /// The URL of the script.
    var scriptURL: URL!

    init(scriptURL: URL) {
        self.scriptURL = scriptURL
        super.init(nibName: nil, bundle: nil)
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
        
        navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        
        if editor?.pipItem == nil {
            editor?.loadViewIfNeeded()
            editor?.pipItem = UIBarButtonItem(image: UIImage(systemName: "pip.enter"), style: .plain, target: editor, action: #selector(editor?.togglePIP))
        }
        
        if editor != nil && AVPictureInPictureController.isPictureInPictureSupported() && !isiOSAppOnMac {
            navigationItem.rightBarButtonItems = [editor!.pipItem]
            parent?.navigationItem.rightBarButtonItems = [editor!.pipItem]
        }
    }
}
