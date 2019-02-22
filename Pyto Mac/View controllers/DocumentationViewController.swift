//
//  DocumentationViewController.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/22/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa
import WebKit

/// A View controller containing documentation.
class DocumentationViewController: NSViewController, WKNavigationDelegate {
    
    /// The Web view containing documentation.
    @IBOutlet weak var webView: WKWebView!
    
    /// Button for going back.
    var backButton: NSButton?
    
    /// Button for going forward.
    var forwardButton: NSButton?
    
    /// Goes back.
    @objc func goBack(_ sender: Any) {
        webView.goBack()
    }
    
    /// Goes forward.
    @objc func goForward(_ sender: Any) {
        webView.goForward()
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if let docsURL = Bundle.main.url(forResource: "docs", withExtension: nil) {
            webView.loadFileURL(docsURL.appendingPathComponent("index.html"), allowingReadAccessTo: docsURL)
        }
        
        webView.navigationDelegate = self
    }
    
    override func viewWillAppear() {
        super.viewWillAppear()
        
        backButton = view.window?.toolbar?.items[0].view as? NSButton
        forwardButton = view.window?.toolbar?.items[1].view as? NSButton
        
        backButton?.target = self
        backButton?.action = #selector(goBack(_:))
        
        forwardButton?.target = self
        forwardButton?.action = #selector(goForward(_:))
    }
    
    // MARK: - Navigation delegate
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        
        backButton?.isEnabled = webView.canGoBack
        forwardButton?.isEnabled = webView.canGoForward
    }
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        
        if let url = navigationAction.request.url, !url.isFileURL {
            NSWorkspace.shared.open(url)
            decisionHandler(.cancel)
        } else {
            decisionHandler(.allow)
        }
    }
}
