//
//  PipViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 3/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import WebKit

/// A View controller for accessing PyPi.
@objc class PipViewController: UIViewController, WKNavigationDelegate, WKUIDelegate {
    
    /// The Web view displaying PyPi.
    @IBOutlet weak var webView: WKWebView!
    
    /// The button for going back.
    @IBOutlet weak var goBackButton: UIBarButtonItem!
    
    /// The button for going forward.
    @IBOutlet weak var goForwardButton: UIBarButtonItem!

    /// Goes back.
    @IBAction func goBack(_ sender: Any) {
        webView.goBack()
    }
    
    /// Goes forward.
    @IBAction func goForward(_ sender: Any) {
        webView.goForward()
    }
    
    /// Reloads page.
    @IBAction func reload(_ sender: Any) {
        if webView.url != nil {
            webView.reload()
        } else {
            webView.load(URLRequest(url: URL(string: "https://pypi.org")!))
        }
    }
    
    /// Dismisses this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    /// Progress view.
    @IBOutlet weak var progressView: UIProgressView!
    
    /// Button for installing or removing package.
    var installButton: UIBarButtonItem!
    
    /// Button for removing or removing package.
    var removeButton: UIBarButtonItem!
    
    private func run(command: String) {
        let navVC = ThemableNavigationController(rootViewController: PipInstallerViewController(command: command))
        navVC.modalPresentationStyle = .formSheet
        present(navVC, animated: true, completion: nil)
    }
    
    /// Installs package.
    @objc func install() {
        run(command: "install \(currentPackage ?? "")")
    }
    
    /// Removes package.
    @objc func remove() {
        run(command: "uninstall \(currentPackage ?? "")")
    }
    
    /// Bundled modules.
    @objc static var bundled = [String]()
    
    /// Returns the currently viewing package.
    var currentPackage: String? {
        get {
            if let url = webView.url, let projectIndex = url.pathComponents.firstIndex(of: "project"), url.host == "pypi.org" {
                if url.pathComponents.indices.contains(projectIndex+1) {
                    return url.pathComponents[projectIndex+1]
                }
            }
            return nil
        }
    }
    
    /// Returns `true` if the currently viewed package is installed.
    var isPackageInstalled: Bool {
        let index = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].appendingPathComponent("modules/.pypi_packages")
        if let str = (try? String(contentsOf: index)) {
            for line in str.components(separatedBy: .newlines) {
                if line.hasPrefix("["), let packageName = line.slice(from: "[", to: "]"), currentPackage == packageName {
                    return true
                }
            }
        }
        return false
    }
    
    // MARK: - View controller
    
    deinit {
        webView.removeObserver(self, forKeyPath: "estimatedProgress")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        installButton = UIBarButtonItem(title: Localizable.install, style: .plain, target: self, action: #selector(install))
        removeButton = UIBarButtonItem(barButtonSystemItem: .trash, target: self, action: #selector(remove))
        
        webView.navigationDelegate = self
        webView.uiDelegate = self
        webView.load(URLRequest(url: URL(string: "https://pypi.org")!))
        webView.addObserver(self,
                            forKeyPath: #keyPath(WKWebView.estimatedProgress),
                            options: .new,
                            context: nil)
        
        #if targetEnvironment(macCatalyst)
        navigationItem.leftBarButtonItems?.removeFirst()
        #endif
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if #available(iOS 13.0, *) {
            #if targetEnvironment(macCatalyst)
            view.window?.windowScene?.titlebar?.titleVisibility = .hidden
            #endif
            view.window?.windowScene?.title = title
        }
    }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        if keyPath == "estimatedProgress" {
            progressView.setProgress(Float(webView.estimatedProgress), animated: true)
        }
    }
    
    // MARK: - Navigation delegate
    
    func webView(_ webView: WKWebView, didStartProvisionalNavigation navigation: WKNavigation!) {
        progressView.isHidden = false
    }
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        goBackButton.isEnabled = webView.canGoBack
        goForwardButton.isEnabled = webView.canGoForward
        progressView.isHidden = true
        progressView.progress = 0
        
        if let package = currentPackage, !PipViewController.bundled.contains(package) {
            if isPackageInstalled {
                navigationItem.rightBarButtonItem = removeButton
            } else {
                installButton.isEnabled = true
                navigationItem.rightBarButtonItem = installButton
            }
        } else {
            navigationItem.rightBarButtonItem = installButton
            installButton.isEnabled = false
        }
    }
    
    func webView(_ webView: WKWebView, didFail navigation: WKNavigation!, withError error: Error) {
        progressView.isHidden = true
        progressView.progress = 0
        navigationItem.rightBarButtonItem = installButton
        installButton.isEnabled = false
        
        webView.loadHTMLString("""
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <h1>Error loading page</h1>
        <p>\(error.localizedDescription)</p>
        """, baseURL: nil)
    }
    
    // MARK: - UI Delegate
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationResponse: WKNavigationResponse, decisionHandler: @escaping (WKNavigationResponsePolicy) -> Void) {
        if !navigationResponse.canShowMIMEType, let url = navigationResponse.response.url {
            UIApplication.shared.open(url, options: [:], completionHandler: nil)
            return decisionHandler(.cancel)
        } else {
            return decisionHandler(.allow)
        }
    }
}
