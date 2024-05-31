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
import SwiftUI
import SwiftSoup

/// A View controller showing offline documentation.
class DocumentationViewController: UIViewController, WKNavigationDelegate {
    
    /// The editor that holds this controller.
    weak var editor: EditorViewController?
    
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
    
    private var lastSelection: Documentation?
    
    private var loadHref: String?
    
    static func getPytoDocumentation() async throws -> Documentation? {
        
        var documentation: DownloadableDocumentation?
        for doc in DocumentationManager().downloadableDocumentations.recommended {
            if doc.name == "pyto" {
                documentation = doc
                break
            }
        }
        
        guard let documentation = documentation else {
            return nil
        }
        
        let manager = DocumentationManager()
        await manager.update()
        try await manager.download(documentations: [documentation])
        return manager.downloadedDocumentations.first(where: { $0.name == "pyto" })
    }
    
    /// The selected documentation
    var selectedDocumentation = Documentation(name: "nothing", url: URL(string: "file:///")!) {
        didSet {
            
            if (selectedDocumentation.pageURL ?? selectedDocumentation.url) != (lastSelection?.pageURL ?? lastSelection?.url) {
                var url = selectedDocumentation.pageURL ?? selectedDocumentation.url
                var parent = selectedDocumentation.parent
                while parent != nil {
                    url = (parent as? Documentation)?.url ?? url
                    parent = (parent as? Documentation)?.parent
                }
                if url.isFileURL {
                    webView.loadFileURL(url, allowingReadAccessTo: url.deletingLastPathComponent())
                    if var href = selectedDocumentation.pageURL?.resolvingSymlinksInPath().path.replacingOccurrences(of: url.resolvingSymlinksInPath().deletingLastPathComponent().path, with: "") {
                        if href.hasPrefix("/") {
                            href.removeFirst()
                        }
                        loadHref = href
                    }
                } else {
                    webView.load(URLRequest(url: url))
                }
            }
            
            lastSelection = selectedDocumentation
        }
    }
    
    var picker: SidebarViewController!
    
    var pickerButtonItem: UIBarButtonItem!
    
    @objc func showPicker() {
        let navVC = UINavigationController(rootViewController: picker)
        navVC.navigationBar.prefersLargeTitles = true
        present(navVC, animated: true)
    }
            
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
                
        edgesForExtendedLayout = []
        
        picker = SidebarViewController(documentationViewController: self)
        pickerButtonItem = UIBarButtonItem(image: UIImage(systemName: "menucard"), style: .plain, target: self, action: #selector(showPicker))
        
        webView = WKWebView(frame: view.frame)
        webView.allowsBackForwardNavigationGestures = true
        webView.navigationDelegate = self
        webView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(webView)
        
        goBackButton = UIBarButtonItem(image: UIImage(named: "back"), style: .plain, target: self, action: #selector(goBack))
        goForwardButton = UIBarButtonItem(image: UIImage(named: "forward"), style: .plain, target: self, action: #selector(goForward))
        
        toolbarItems = [goBackButton, UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), goForwardButton]
        
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        }
        
        navigationItem.rightBarButtonItem = pickerButtonItem
        
        navigationItem.largeTitleDisplayMode = .never
        
        webView.loadFileURL(selectedDocumentation.url, allowingReadAccessTo: selectedDocumentation.url.deletingLastPathComponent())
        
        if selectedDocumentation.url == URL(string: "file:///")! {
            Task {
                guard let doc = try await Self.getPytoDocumentation() else {
                    return
                }
                await MainActor.run {
                    self.selectedDocumentation = doc
                }
            }
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        editor?.setBarItems()
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
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        
        guard let url = navigationAction.request.mainDocumentURL else {
            return decisionHandler(.allow)
        }
        
        switch url.scheme {
        case "http", "https":
            let safari = SFSafariViewController(url: url)
            present(safari, animated: true, completion: nil)
            decisionHandler(.cancel)
        default:
            decisionHandler(.allow)
        }
    }
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        goBackButton.isEnabled = webView.canGoBack
        goForwardButton.isEnabled = webView.canGoForward
        
        if let loadHref = loadHref {
            self.loadHref = nil
            webView.evaluateJavaScript("location.href = '\(loadHref.replacingOccurrences(of: "'", with: "\\'"))'", completionHandler: nil)
        }
        
        title = webView.title
        
        if title?.isEmpty != false {
            webView.evaluateJavaScript("document.getElementsByTagName('h1')[0].innerText") { title, _ in
                self.title = (title as? String)?.replacingOccurrences(of: "", with: "")
            }
        }
    }
}

