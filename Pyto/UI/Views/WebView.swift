//
//  WebView.swift
//  Pyto
//
//  Created by Emma Labbé on 13-05-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import WebKit

class WebView: WKWebView {
        
    @objc func didPan(_ gesture: UIPanGestureRecognizer) {
        let y = gesture.velocity(in: self).y
        let velocity = (Int((y/100).rounded(y > 0 ? .up : .down))/4)+(y > 0 ? 1 : -1)
        var code = ""
        for _ in 0...(velocity > 0 ? velocity : velocity*(-1)) {
            if velocity < 0 {
                code += "t.scrollLineDown();"
            } else {
                code += "t.scrollLineUp();"
            }
        }
        
        evaluateJavaScript(code, completionHandler: nil)
    }
    
    init() {
        super.init(frame: .zero, configuration: WKWebViewConfiguration())
        
        if isiOSAppOnMac {
            let gesture = UIPanGestureRecognizer(target: self, action: #selector(didPan(_:)))
            if #available(iOS 13.4, *) {
                gesture.allowedScrollTypesMask = .all
            }
            
            addGestureRecognizer(gesture)
            
            scrollView.isScrollEnabled = false
        }
    }
    
    override init(frame: CGRect, configuration: WKWebViewConfiguration) {
        super.init(frame: frame, configuration: configuration)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
