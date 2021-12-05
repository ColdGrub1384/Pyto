//
//  DocumentationViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 12/8/18.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import WebKit
import SafariServices
import Zip

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
        ((presenting as? EditorSplitViewController.NavigationController)?.viewControllers.first as? EditorSplitViewController)?.editor?.documentationNavigationController = nil
        dismiss(animated: true) {
            func showDocs() {
                let navVC = UINavigationController(rootViewController: self)
                navVC.view.backgroundColor = .systemBackground
                SceneDelegate.viewControllerToShow = navVC
                SceneDelegate.viewControllerDidShow = {
                    self.view.window?.tintColor = ConsoleViewController.choosenTheme.tintColor
                }
                if #available(iOS 13.0, *) {
                    UIApplication.shared.requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: { error in
                        print(error.localizedDescription)
                    })
                }
                
                self.navigationItem.rightBarButtonItem = nil
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
    
    var docsURL: URL {
        let url = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("docs_build")
        
        if /*!FileManager.default.fileExists(atPath: url.path),*/ let bundledDocs = Bundle.main.url(forResource: "docs", withExtension: "zip") {
            
            do {
                try Zip.unzipFile(bundledDocs, destination: url.deletingLastPathComponent(), overwrite: true, password: nil)
            } catch {
                print(error.localizedDescription)
            }
        }
        
        return url
    }
        
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = NSLocalizedString("help.documentation", comment: "'Documentation' button")
        
        edgesForExtendedLayout = []
        
        webView = WKWebView(frame: view.frame)
        webView.allowsBackForwardNavigationGestures = true
        webView.navigationDelegate = self
        webView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(webView)
        
        DispatchQueue.global().async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            let url = self.docsURL
            DispatchQueue.main.async { [weak self] in
                self?.webView.loadFileURL(url.appendingPathComponent("html/index.html"), allowingReadAccessTo: url)
            }
        }
        
        goBackButton = UIBarButtonItem(image: UIImage(named: "back"), style: .plain, target: self, action: #selector(goBack))
        goForwardButton = UIBarButtonItem(image: UIImage(named: "forward"), style: .plain, target: self, action: #selector(goForward))
        
        toolbarItems = [goBackButton, UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), goForwardButton]
        
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        }
        
        if UIDevice.current.userInterfaceIdiom == .pad && splitViewController == nil {
            navigationItem.rightBarButtonItem = UIBarButtonItem(image: UIImage(systemName: "chevron.down.square.fill"), style: .plain, target: self, action: #selector(openInNewWindow))
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationController?.navigationBar.isTranslucent = false
        navigationController?.navigationBar.backgroundColor = .systemBackground
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        parent?.toolbarItems = toolbarItems
        navigationController?.setToolbarHidden(false, animated: true)
                
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = NSLocalizedString("help.documentation", comment: "'Documentation' button")
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = ""
        }
    }
    
    // MARK: - Navigation delegate
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        goBackButton.isEnabled = webView.canGoBack
        goForwardButton.isEnabled = webView.canGoForward
    }
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        
        if let url = navigationAction.request.url, url.scheme == "http" || url.scheme == "https", url.host != "pyto.readthedocs.io" {
            if !isiOSAppOnMac {
                present(SFSafariViewController(url: url), animated: true, completion: nil)
            } else {
                UIApplication.shared.open(url, options: [:], completionHandler: nil)
            }
            decisionHandler(.cancel)
        } else {
            decisionHandler(.allow)
        }
    }
}

