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
    
    /// The editor that holds this controller.
    weak var editor: EditorViewController?
    
    /// A downloaded documentation.
    struct Documentation {
        
        /// The name.
        var name: String
        
        /// The file URL to the index.html file.
        var url: URL
        
        /// The file URL to the selected HTML page.
        var pageURL: URL?
        
        /// Pyto's documentation.
        static let pyto = Documentation(name: "Pyto", url: FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("docs_build").appendingPathComponent("html/index.html"), pageURL: FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("docs_build").appendingPathComponent("html/index.html"))
        
        /// Python's documentation
        static let python = Documentation(name: "Python", url: Bundle.main.url(forResource: "python-3.10.0-docs-html/index", withExtension: "html")!, pageURL: Bundle.main.url(forResource: "python-3.10.0-docs-html/index", withExtension: "html")!)
    }
    
    /// The button for changing documentation.
    var documentationButton: UIBarButtonItem!
    
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
    
    /// The selected documentation
    var selectedDocumentation = Documentation.pyto {
        didSet {
            
            if (selectedDocumentation.pageURL ?? selectedDocumentation.url) != (lastSelection?.pageURL ?? lastSelection?.url) {
                let url = selectedDocumentation.pageURL ?? selectedDocumentation.url
                if url.isFileURL {
                    if selectedDocumentation.url == Documentation.pyto.url {
                        webView.loadFileURL(selectedDocumentation.url, allowingReadAccessTo: selectedDocumentation.url.deletingLastPathComponent())
                        if var href = selectedDocumentation.pageURL?.resolvingSymlinksInPath().path.replacingOccurrences(of: selectedDocumentation.url.resolvingSymlinksInPath().deletingLastPathComponent().path, with: "") {
                            if href.hasPrefix("/") {
                                href.removeFirst()
                            }
                            loadHref = href
                        }
                    } else {
                        webView.loadFileURL(url, allowingReadAccessTo: selectedDocumentation.url.deletingLastPathComponent())
                    }
                } else {
                    webView.load(URLRequest(url: url))
                }
            }
            
            lastSelection = selectedDocumentation
            
            documentationButton.title = selectedDocumentation.name
            documentationButton.menu = makeDocumentationMenu()
            
            if view.window == nil {
                editor?.showDocs(self)
            }
        }
    }
    
    private func directories(in url: URL) -> [URL] {
        (try? FileManager.default.contentsOfDirectory(at: url, includingPropertiesForKeys: nil, options: []))?.filter({ url in
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir), isDir.boolValue {
                
                for file in (try? FileManager.default.contentsOfDirectory(at: url, includingPropertiesForKeys: nil, options: [])) ?? [] {
                    
                    if file.pathExtension == "html" {
                        return true
                    }
                }
                
                return false
            } else {
                return false
            }
        }) ?? []
    }
    
    private func menuItems(for documentation: Documentation, directory: URL) -> [UIMenuElement] {
        ((try? FileManager.default.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil, options: [])) ?? []).filter({ $0.pathExtension == "html" && !$0.lastPathComponent.hasPrefix("genindex") }).filter({ (directory == documentation.url.deletingLastPathComponent() && $0.lastPathComponent == "index.html") ? false : true }).sorted(by: { $0.lastPathComponent == "index.html" ? true : $0.lastPathComponent < $1.lastPathComponent }).map({ doc in
            
            UIAction(title: doc.deletingPathExtension().lastPathComponent, image: nil, identifier: nil, discoverabilityTitle: doc.deletingPathExtension().lastPathComponent, attributes: [], state: selectedDocumentation.pageURL == doc ? .on : .off, handler: { _ in
                self.selectedDocumentation = Documentation(name: documentation.name, url: documentation.url, pageURL: doc)
            })
            
        })
    }
    
    private func menuItems(for documentation: Documentation) -> [UIMenuElement] {
        [
            UIAction(title: "index", image: nil, identifier: nil, discoverabilityTitle: "index", attributes: [], state: selectedDocumentation.pageURL == documentation.url ? .on : .off, handler: { _ in
                self.selectedDocumentation = Documentation(name: documentation.name, url: documentation.url, pageURL: nil)
            })
        ] + directories(in: documentation.url.deletingLastPathComponent()).sorted(by: { $0.lastPathComponent < $1.lastPathComponent }).map({ folder in
            
            UIMenu(title: folder.lastPathComponent, image: self.selectedDocumentation.pageURL?.deletingLastPathComponent() == folder ? UIImage(systemName: "checkmark") : nil, identifier: nil, options: [], children: self.menuItems(for: documentation, directory: folder))
            
        }) + menuItems(for: documentation, directory: documentation.url.deletingLastPathComponent())
    }
    
    private func makeThirdPartyMenuItems() -> [UIMenuElement] {
        var items = [UIMenuElement]()
        
        let bundled = ((try? FileManager.default.contentsOfDirectory(at: Bundle.main.url(forResource: "site-packages", withExtension: nil)!, includingPropertiesForKeys: nil, options: [])) ?? []).filter({ $0.pathExtension == "dist-info" || $0.pathExtension == "egg-info" })
        
        let installed = ((try? FileManager.default.contentsOfDirectory(at: FileBrowserViewController.localContainerURL.appendingPathComponent("site-packages"), includingPropertiesForKeys: nil, options: [])) ?? []).filter({ $0.pathExtension == "dist-info" || $0.pathExtension == "egg-info" })
        
        for package in (bundled+installed).sorted(by: { $0.lastPathComponent < $1.lastPathComponent }) {
            
            let metadata = FileManager.default.fileExists(atPath: package.appendingPathComponent("METADATA").path) ? package.appendingPathComponent("METADATA") : package.appendingPathComponent("PKG-INFO")
            
            guard FileManager.default.fileExists(atPath: metadata.path) else {
                continue
            }
            
            // Well it's rst actually but whatever
            guard let markdown = try? String(contentsOf: metadata) else {
                continue
            }
            
            var name = package.deletingPathExtension().lastPathComponent
            
            for line in markdown.components(separatedBy: "\n") {
                if line.hasPrefix("Name: "), let _name = line.components(separatedBy: "Name: ").last {
                    name = _name
                    break
                }
            }
                        
            for line in markdown.components(separatedBy: "\n") {
                if line.hasPrefix("Name: "), let _name = line.components(separatedBy: "Name: ").last {
                    name = _name
                    break
                }
            }
            
            items.append(UIAction(title: name, image: nil, identifier: nil, discoverabilityTitle: name, attributes: [], state: selectedDocumentation.name == name ? .on : .off, handler: { _ in
                
                guard let jsonURL = URL(string: "https://pypi.org/pypi/\(name)/json") else {
                    return
                }
                
                URLSession.shared.dataTask(with: jsonURL) { data, _, error in
                    guard error == nil else {
                        return print(error!.localizedDescription)
                    }
                    
                    guard let data = data else {
                        return
                    }
                    
                    do {
                        guard let info = try JSONSerialization.jsonObject(with: data, options: []) as? [String:Any] else {
                            return
                        }
                        
                        guard let urls = (info["info"] as? [String:Any])?["project_urls"] as? [String:String] else {
                            return
                        }
                        
                        guard let urlString = urls["Documentation"] ?? urls["Homepage"] ?? urls["Source Code"] else {
                            return
                        }
                        
                        guard let url = URL(string: urlString) else {
                            return
                        }
                        
                        DispatchQueue.main.async {
                            self.selectedDocumentation = Documentation(name: name, url: url, pageURL: nil)
                        }
                    } catch {
                        print(error.localizedDescription)
                    }
                }.resume()
            }))
        }
        
        return items
    }
    
    /// Returns the menu for selecting documentation.
    func makeDocumentationMenu() -> UIMenu {
        UIMenu(title: NSLocalizedString("help.documentation", comment: "'Documentation' button"), image: UIImage(systemName: "book"), identifier: nil, options: [], children: [
        
            UIMenu(title: "Pyto", image: selectedDocumentation.url == Documentation.pyto.url ? UIImage(systemName: "checkmark") : nil, identifier: nil, options: [], children: menuItems(for: .pyto)),
            
            UIMenu(title: "Python", image: selectedDocumentation.url == Documentation.python.url ? UIImage(systemName: "checkmark") : nil, identifier: nil, options: [], children: menuItems(for: .python)),
            
            UIMenu(title: "Third Party", image: (selectedDocumentation.url != Documentation.pyto.url && selectedDocumentation.url != Documentation.python.url) ? UIImage(systemName: "checkmark") : nil, identifier: nil, options: [], children: makeThirdPartyMenuItems()),
        ])
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
        
        documentationButton = UIBarButtonItem(title: selectedDocumentation.name, style: .plain, target: nil, action: nil)
        documentationButton.menu = makeDocumentationMenu()
        if !(self is AcknowledgmentsViewController) {
            navigationItem.rightBarButtonItem = documentationButton
        }
        
        goBackButton = UIBarButtonItem(image: UIImage(named: "back"), style: .plain, target: self, action: #selector(goBack))
        goForwardButton = UIBarButtonItem(image: UIImage(named: "forward"), style: .plain, target: self, action: #selector(goForward))
        
        toolbarItems = [goBackButton, UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil), goForwardButton]
        
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        }
        
        navigationItem.largeTitleDisplayMode = .never
        
        webView.loadFileURL(selectedDocumentation.url, allowingReadAccessTo: selectedDocumentation.url.deletingLastPathComponent())
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        documentationButton.menu = nil // Release menu
        editor?.setBarItems()
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
        
        documentationButton.menu = makeDocumentationMenu()
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
        
        if let loadHref = loadHref {
            self.loadHref = nil
            webView.evaluateJavaScript("location.href = '\(loadHref.replacingOccurrences(of: "'", with: "\\'"))'", completionHandler: nil)
        }
    }
}

