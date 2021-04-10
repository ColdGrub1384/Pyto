//
//  PytoUIPreviewViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 13-02-21.
//  Copyright © 2021 Adrian Labbé. All rights reserved.
//

import UIKit

@objc class PytoUIPreviewViewController: UIViewController {
    
    @objc static var code: String?
    
    @objc static var current: PytoUIPreviewViewController?
    
    @objc var preview: PyView? {
        didSet {
            
            DispatchQueue.main.async { [weak self] in
                guard let self = self else {
                    return
                }
                
                guard let view = self.preview?.view else {
                    return
                }
                                
                view.tag = 777
                view.isUserInteractionEnabled = false
                
                self.view.viewWithTag(777)?.removeFromSuperview()
                
                view.frame = self.view.frame
                view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                self.view.addSubview(view)
            }
        }
    }
    
    let previewButton = UIButton()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        previewButton.setTitle("Preview", for: .normal)
        previewButton.setTitleColor(.white, for: .normal)
        previewButton.addTarget(self, action: #selector(preview(_:)), for: .touchUpInside)
        previewButton.backgroundColor = view.tintColor
        previewButton.layer.cornerRadius = 6
        previewButton.frame.size = CGSize(width: 150, height: 50)
        previewButton.autoresizingMask = [.flexibleTopMargin, .flexibleBottomMargin, .flexibleLeftMargin, .flexibleRightMargin]
        previewButton.center = view.center
        view.addSubview(previewButton)        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.frame = parent?.view.frame ?? .zero
        
        previewButton.center = view.center
    }
    
    @objc func preview(_ sender: Any) {
        previewButton.isHidden = true
        
        PytoUIPreviewViewController.code = (parent as? ConsoleViewController)?.editorSplitViewController?.editor?.textView.text
        PytoUIPreviewViewController.current = self
        
        Python.shared.run(code: """
        from pyto import PytoUIPreviewViewController
        import __pyto_ui_garbage_collector__ as gc
        import sys
        import json

        try:
            del sys.modules["pyto_ui"]
            del sys.modules["ui_constants"]
        except KeyError:
            pass

        import pyto_ui as ui

        data = str(PytoUIPreviewViewController.code)

        view = json.loads(data, cls=ui.Decoder)
        view.__py_view__.release()
        PytoUIPreviewViewController.current.preview = view.__py_view__

        del view
        """)
    }
}
