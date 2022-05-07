//
//  DocumentationSidebar.swift
//  Pyto
//
//  Created by Emma on 14-03-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI

func fixBackgroundColor(documentationSidebarViewController: DocumentationViewController.SidebarViewController?) {
    
    guard documentationSidebarViewController != nil else {
        return
    }
    
    DispatchQueue.main.async {
        for view in getSubviewsOfView(v: documentationSidebarViewController!.view).filter( { $0.backgroundColor?.hexString == documentationSidebarViewController!.view.tintColor?.hexString } ) {
            view.backgroundColor = .secondarySystemGroupedBackground
        }
    }
}

struct DocumentationSidebar: View {
        
    @State var isShowingDownloads = false
    
    var documentationViewController: DocumentationViewController?
    
    var documentationSidebarViewController: DocumentationViewController.SidebarViewController?
    
    @ObservedObject var documentationManager = DocumentationManager()
            
    @State var downloadingDocumentations = [DownloadableDocumentation]()
    
    @Environment(\.colorScheme) var colorScheme
    
    var content: some View {
        List {
            Section {
                NavigationLink {
                    DocumentationsDownloadScreen(documentationManager: documentationManager, documentationSidebarViewController: documentationSidebarViewController)
                } label: {
                    Label {
                        Text(NSLocalizedString("downloads", comment: "The title of the downloadable documentations view"))
                    } icon: {
                        Image(systemName: "ellipsis.circle.fill")
                    }
                }
            }
            
            Section {
                ForEach(documentationManager.bookmarks) { bookmark in
                    if let url = bookmark.bookmarkURL {
                        DocumentationView(doc: [Documentation(name: bookmark.name, url: url, pageURL: bookmark.isFolder ? nil : url)].map({
                            var doc = $0
                            doc.parent = Documentation(name: bookmark.name, url: bookmark.parentURL ?? doc.url.deletingLastPathComponent())
                            doc.setTitle()
                            return doc
                        })[0], documentationViewController: documentationViewController, documentationSidebarViewController: documentationSidebarViewController, documentationManager: documentationManager)
                    } else {
                        EmptyView()
                    }
                }.onDelete { indexSet in
                    guard let i = indexSet.first else {
                        return
                    }
                    
                    documentationManager.bookmarks.remove(at: i)
                }.onMove { _from, to in
                    guard let from = _from.first else {
                        return
                    }
                    
                    var bookmarks = documentationManager.bookmarks
                    let a = bookmarks.remove(at: from)
                    bookmarks.insert(a, at: to)
                    documentationManager.bookmarks = bookmarks
                }
            } header: {
                Text(NSLocalizedString("bookmarks", comment: "The title of the bookmarked pages section"))
            }
            
            Section {
                ForEach(documentationManager.downloadedDocumentations.sorted(by: { $0.name.compare($1.name) == .orderedAscending })) { doc in
                    DocumentationView(doc: doc, documentationViewController: documentationViewController, documentationSidebarViewController: documentationSidebarViewController, documentationManager: documentationManager)
                }
            } header: {
                Text(NSLocalizedString("help.documentations", comment: "The title of the documentations section"))
            }
        }.sheet(isPresented: $isShowingDownloads) {
            DocumentationsDownloadScreen(documentationManager: documentationManager, documentationSidebarViewController: documentationSidebarViewController)
        }.toolbar {
            ToolbarItemGroup(placement: .navigationBarTrailing) {
                EditButton()
            }
        }
    }
    
    var body: some View {
        content
        .navigationTitle(NSLocalizedString("help.documentation", comment: "'Documentation' button"))
    }
}

fileprivate func findViewInside<T>(views: [UIView]?, findView: [T] = [], findType: T.Type = T.self) -> [T] {
    var findView = findView
    let views = views ?? []
    guard views.count > .zero else { return findView }
    let firstView = views[0]
    var loopViews = views.dropFirst()
    
    if let typeView = firstView as? T {
        findView = findView + [typeView]
        return findViewInside(views: Array(loopViews), findView: findView)
    } else if firstView.subviews.count > .zero {
        firstView.subviews.forEach { loopViews.append($0) }
        return findViewInside(views: Array(loopViews), findView: findView)
    } else {
        return findViewInside(views: Array(loopViews), findView: findView)
    }
}

fileprivate func getSubviewsOfView(v: UIView) -> [UIView] {
    var array = [UIView]()

    for subview in v.subviews {
        array += getSubviewsOfView(v: subview)
        array.append(subview)
    }

    return array
}

extension DocumentationViewController {
    
    class SidebarViewController: UIHostingController<AnyView> {
        
        init(documentationViewController: DocumentationViewController?) {
            super.init(rootView: AnyView(EmptyView()))
            
            rootView = AnyView(DocumentationSidebar(documentationViewController: documentationViewController, documentationSidebarViewController: self))
        }
        
        override func viewDidAppear(_ animated: Bool) {
            super.viewDidAppear(animated)
            
            UITableViewCell.appearance(whenContainedInInstancesOf: [SidebarViewController.self]).selectionStyle = .none
        }
        
        @MainActor @objc required dynamic init?(coder aDecoder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
    }
}
