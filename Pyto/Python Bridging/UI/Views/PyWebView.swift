//
//  PyWebView.swift
//  Pyto
//
//  Created by Adrian Labbé on 31-07-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import WebKit

@available(iOS 13.0, *) @objc public class PyWebView: PyView, WKNavigationDelegate, WKUIDelegate {
    
    public override class var pythonName: String {
        return "WebView"
    }
    
    @objc public var managedValue: PyValue?
    
    @objc public var didStartLoading: PyValue?
    
    @objc public var didFinishLoading: PyValue?
    
    @objc public var didFailLoading: PyValue?
    
    @objc public var url: String? {
        return get {
            return self.webView.url?.absoluteString
        }
    }
    
    @objc public func loadURL(_ url: String) {
        set {
            guard let url = URL(string: url) else {
                return
            }
            
            if url.isFileURL {
                self.webView.loadFileURL(url, allowingReadAccessTo: URL(fileURLWithPath: "/"))
            } else {
                self.webView.load(URLRequest(url: url))
            }
        }
    }
    
    @objc public func loadHTML(_ html: String, baseURL: String?) {
        set {
            self.webView.loadHTMLString(html, baseURL: baseURL == nil ? nil : URL(string: baseURL!))
        }
    }
    
    @objc public var isLoading: Bool {
        return get {
            return self.webView.isLoading
        }
    }
    
    @objc public func reload() {
        set {
            self.webView.reload()
        }
    }
    
    @objc public func goBack() {
        set {
            self.webView.goBack()
        }
    }
    
    @objc public var canGoBack: Bool {
        return get {
            return self.webView.canGoBack
        }
    }
    
    @objc public func goForward() {
        set {
            self.webView.goForward()
        }
    }
    
    @objc public var canGoForward: Bool {
        return get {
            return self.webView.canGoForward
        }
    }
    
    @objc public func stop() {
        set {
            self.webView.stopLoading()
        }
    }
    
    @objc public func evaluateJavaScript(_ code: String) -> String? {
        let semaphore = DispatchSemaphore(value: 0)
        
        var str: String?
        
        DispatchQueue.main.async {
            self.webView.evaluateJavaScript(code) { (value, error) in
                if let value = value {
                    str = "_VALULE_:\(value)"
                } else if let error = error {
                    str = "_ERROR_:\(error.localizedDescription)"
                }
                
                semaphore.signal()
            }
        }
        
        if !Thread.current.isMainThread {
            semaphore.wait()
        }
        
        return str
    }
    
    /// The Web view associated with this object.
    @objc public var webView: WKWebView {
        return get {
            return self.managed as! WKWebView
        }
    }
    
    required init(managed: Any! = NSObject()) {
        super.init(managed: managed)
        
        DispatchQueue.main.async {
            (managed as? WKWebView)?.navigationDelegate = self
            (managed as? WKWebView)?.uiDelegate = self
        }
    }
    
    @objc override class func newView() -> PyView {
        return PyWebView(managed: get {
            return WKWebView()
        })
    }
    
    public func webView(_ webView: WKWebView, didCommit navigation: WKNavigation!) {
        didStartLoading?.call(parameter: managedValue)
    }
    
    public func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        didFinishLoading?.call(parameter: managedValue)
    }
    
    public func webView(_ webView: WKWebView, didFail navigation: WKNavigation!, withError error: Error) {
        
        guard let identifier = managedValue?.identifier, let action = didFailLoading else {
            return
        }
        
        Python.shared.run(code: "import _values; param = _values.\(identifier); _values.\(action.identifier)(param, \"\(error.localizedDescription)\")")
    }
    
    public func webView(_ webView: WKWebView, createWebViewWith configuration: WKWebViewConfiguration, for navigationAction: WKNavigationAction, windowFeatures: WKWindowFeatures) -> WKWebView? {
        
        webView.load(navigationAction.request)
        
        return nil
    }
    
    public func webView(_ webView: WKWebView, runJavaScriptAlertPanelWithMessage message: String, initiatedByFrame frame: WKFrameInfo, completionHandler: @escaping () -> Void) {
        
        let alert = UIAlertController(title: "Pyto", message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
        #if MAIN && !WIDGET
        webView.window?.topViewController?.present(alert, animated: true, completion: nil)
        #endif
        
        completionHandler()
    }
}
