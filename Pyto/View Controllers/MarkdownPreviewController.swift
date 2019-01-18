//
//  MarkdownPreviewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/18/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import WebKit
import Down

/// A View controller displaying Markdown.
class MarkdownPreviewController: UIViewController {
    
    /// Previews Markdown on given Web view.
    ///
    /// - Parameters:
    ///     - markdown: The Markdown string to be displayed.
    ///     - baseURL: URL used to resolve relative paths.
    ///     - webView: Web view used to display content.
    static func load(markdown: String, baseURL: URL? = nil, onWebView webView: WKWebView) {
        do {
            var str = ""
            
            if let bodyPath = Bundle.main.path(forResource: "body", ofType: "html"), let body = (try? String(contentsOfFile: bodyPath)) {
                str += body
            }
            
            str += (try Down(markdownString: markdown).toHTML())
            
            webView.loadHTMLString(str, baseURL: baseURL)
        } catch {
            webView.loadHTMLString(error.localizedDescription, baseURL: nil)
        }
    }
    
    /// Previews Markdown.
    ///
    /// - Parameters:
    ///     - markdown: The Markdown string to be displayed.
    ///     - baseURL: URL used to resolve relative paths.
    func load(markdown: String, baseURL: URL? = nil) {
        if let webView = view as? WKWebView {
            MarkdownPreviewController.load(markdown: markdown, baseURL: baseURL, onWebView: webView)
        }
    }
    
    // MARK: - View controller
    
    override func loadView() {
        view = WKWebView()
        view.isOpaque = false
        view.backgroundColor = .clear
    }
}
