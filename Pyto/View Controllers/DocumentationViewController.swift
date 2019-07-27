//
//  DocumentationViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 12/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import WebKit
import SafariServices

/// A View controller showing offline documentation.
class DocumentationViewController: UIViewController, WKNavigationDelegate {
    
    /// The button for going back.
    var goBackButton: UIBarButtonItem!
    
    /// The button for going forward.
    var goForwardButton: UIBarButtonItem!
    
    /// The Web view containing documentation.
    var webView: WKWebView!
    
    /// Goes back.
    @objc func goBack() {
        webView.goBack()
    }
    
    /// Goes forward
    @objc func goForward() {
        webView.goForward()
    }
    
    /// Closes this View controller.
    @objc func close() {
        dismiss(animated: true, completion: nil)
    }
    
    /// Opens the documentation in a new window.
    @objc func openInNewWindow() {
        let presenting = presentingViewController
        let navVC = navigationController
        ((presenting as? EditorSplitViewController.NavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor?.documentationNavigationController = nil
        dismiss(animated: true) {
            func showDocs() {
                SceneDelegate.viewControllerToShow = navVC ?? self
                SceneDelegate.viewControllerDidShow = {
                    self.view.window?.tintColor = ConsoleViewController.choosenTheme.tintColor
                }
                if #available(iOS 13.0, *) {
                    UIApplication.shared.requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: { error in
                        print(error.localizedDescription)
                    })
                }
                if self.navigationItem.rightBarButtonItems?.count == 2 {
                    self.navigationItem.rightBarButtonItems?.removeLast()
                }
            }
            
            if presenting?.modalPresentationStyle == .formSheet {
                presenting?.dismiss(animated: true, completion: {
                    showDocs()
                })
            } else {
                showDocs()
            }
        }
    }
    
    // MARK: - View controller
    
    #if !targetEnvironment(UIKitForMac)
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand(input: "w", modifierFlags: .command, action: #selector(close), discoverabilityTitle: Localizable.close)]
    }
    #endif
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        edgesForExtendedLayout = []
        
        webView = WKWebView(frame: view.frame)
        webView.allowsBackForwardNavigationGestures = true
        webView.navigationDelegate = self
        webView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(webView)
        
        if let url = Bundle.main.url(forResource: "docs/html", withExtension: "") {
            webView.loadFileURL(url.appendingPathComponent("index.html"), allowingReadAccessTo: url)
        }
        
        goBackButton = UIBarButtonItem(image: UIImage(named: "back"), style: .plain, target: self, action: #selector(goBack))
        goForwardButton = UIBarButtonItem(image: UIImage(named: "forward"), style: .plain, target: self, action: #selector(goForward))
        
        toolbarItems = [goBackButton, UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), goForwardButton]
        
        navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(close))
        
        if UIDevice.current.isMultitaskingSupported, #available(iOS 13.0, *) {
            navigationItem.rightBarButtonItems?.append(UIBarButtonItem(image: UIImage(systemName: "chevron.down.square.fill"), style: .plain, target: self, action: #selector(openInNewWindow)))
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        navigationController?.setToolbarHidden(false, animated: true)
    }
    
    // MARK: - Navigation delegate
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        goBackButton.isEnabled = webView.canGoBack
        goForwardButton.isEnabled = webView.canGoForward
    }
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        
        if let url = navigationAction.request.url, url.scheme == "http" || url.scheme == "https" {
            present(SFSafariViewController(url: url), animated: true, completion: nil)
            decisionHandler(.cancel)
        } else {
            decisionHandler(.allow)
        }
    }
}

