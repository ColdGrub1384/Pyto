//
//  DocumentationView.swift
//  Pyto
//
//  Created by Emma on 19-03-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI

extension DocumentationSidebar {
    
    struct DocumentationView: View {
        
        var doc: Documentation
        
        var documentationViewController: DocumentationViewController?
        
        var documentationSidebarViewController: DocumentationViewController.SidebarViewController?
                
        @State var isExpanded = false
        
        static private let sharedDocumentationManager = DocumentationManager()
        
        @ObservedObject var documentationManager = sharedDocumentationManager
        
        @Environment(\.colorScheme) var colorScheme
        
        var isBookmarked: Bool {
            let bookmarks = documentationManager.bookmarks
            for bookmark in bookmarks {
                if bookmark.bookmarkURL?.resolvingSymlinksInPath() == (doc.pageURL ?? doc.url).resolvingSymlinksInPath() {
                    return true
                }
            }
            return false
        }
        
        func getRoot(from documentation: Documentation) -> Documentation? {
            var parent = documentation.parent as? Documentation
            while true {
                if let grandParent = parent?.parent as? Documentation {
                    parent = grandParent
                } else {
                    break
                }
            }
            return parent
        }
        
        func titleiseAndSort(docs: [Documentation]) -> [Documentation] {
            var titleised = docs.map({ doc -> Documentation in
                var newDoc = doc
                newDoc.setTitle()
                return newDoc
            })
            
            let indexDotHTML: Documentation?
            if let i = titleised.firstIndex(where: { $0.pageURL?.lastPathComponent == "index.html" }) {
                indexDotHTML = titleised.remove(at: i)
            } else {
                indexDotHTML = nil
            }
            
            let folders = titleised.filter({ $0.pageURL == nil }).sorted(by: { $0.title.compare($1.title) == .orderedAscending })
            let pages = titleised.filter({ $0.pageURL != nil }).sorted(by: { $0.title.compare($1.title) == .orderedAscending })
            
            return (indexDotHTML != nil ? [indexDotHTML!] : [])+pages+folders
        }
        
        var body: some View {
            Group {
                if doc.children == nil {
                    Button {
                        documentationViewController?.selectedDocumentation = doc
                        documentationViewController?.dismiss(animated: true)
                        fixBackgroundColor(documentationSidebarViewController: documentationSidebarViewController)
                    } label: {
                        VStack {
                            HStack {
                                Label {
                                    Text(doc.title).foregroundColor(.primary)
                                } icon: {
                                    if doc.pageURL?.lastPathComponent == "index.html" {
                                        Image(systemName: "house")
                                    } else {
                                        Image(systemName: "book.closed.fill")
                                    }
                                }
                                Spacer()
                            }
                            HStack {
                                Text(doc.pageURL?.lastPathComponent ?? doc.url.lastPathComponent).foregroundColor(.secondary).font(.footnote)
                                Spacer()
                            }
                        }.contextMenu {
                            if !isBookmarked {
                                Button {
                                    guard let bookmarkData = try? (doc.pageURL ?? doc.url)?.bookmarkData() else {
                                        return
                                    }
                                    
                                    let parentBookmarkData = try? getRoot(from: doc)?.url.bookmarkData()
                                    
                                    let bookmark = Documentation.Bookmark(name: doc.name, bookmarkData: bookmarkData,  parentBookmarkData: parentBookmarkData, isFolder: false)
                                    documentationManager.bookmarks.insert(bookmark, at: 0)
                                } label: {
                                    Label {
                                        Text("Add to bookmarks")
                                    } icon: {
                                        Image(systemName: "bookmark")
                                    }
                                }
                            }
                        }
                    }
                } else {
                    
                    if doc.parent == nil {
                        DisclosureGroup(isExpanded: $isExpanded) {
                            if isExpanded {
                                ForEach(titleiseAndSort(docs: doc.children!)) {
                                    DocumentationView(doc: $0, documentationViewController: documentationViewController, documentationSidebarViewController: documentationSidebarViewController, documentationManager: documentationManager)
                                }.onAppear {
                                    fixBackgroundColor(documentationSidebarViewController: documentationSidebarViewController)
                                }.onDisappear {
                                    fixBackgroundColor(documentationSidebarViewController: documentationSidebarViewController)
                                }
                            } else {
                                EmptyView()
                            }
                        } label: {
                            VStack {
                                HStack {
                                    Text(doc.name.localizedCapitalized).foregroundColor(colorScheme == .light ? .black : .white).font(.headline)
                                    Spacer()
                                }
                                HStack {
                                    Text(doc.title).foregroundColor(colorScheme == .light ? .black : .white).font(.caption)
                                    Spacer()
                                }
                                HStack {
                                    Text(doc.getVersion()).font(.caption).foregroundColor(.secondary)
                                    Spacer()
                                }
                            }
                             .contextMenu {
                                 
                                 if !isBookmarked {
                                     Button {
                                         guard let bookmarkData = try? (doc.pageURL ?? doc.url)?.bookmarkData() else {
                                             return
                                         }
                                         
                                         let parentBookmarkData = try? getRoot(from: doc)?.url.bookmarkData()
                                         
                                         let bookmark = Documentation.Bookmark(name: doc.name, bookmarkData: bookmarkData, parentBookmarkData: parentBookmarkData, isFolder: false)
                                         documentationManager.bookmarks.insert(bookmark, at: 0)
                                     } label: {
                                         Label {
                                             Text("Add to bookmarks")
                                         } icon: {
                                             Image(systemName: "bookmark")
                                         }
                                     }
                                 }
                                 
                                 Button {
                                     var downloadedDocumentation: DownloadableDocumentation?
                                     
                                     for _doc in documentationManager.downloadableDocumentations.recommended+documentationManager.downloadableDocumentations.other {
                                         if _doc.name == doc.name {
                                             downloadedDocumentation = _doc
                                             break
                                         }
                                     }
                                     
                                     if downloadedDocumentation == nil {
                                         for docURL in (try? FileManager.default.contentsOfDirectory(at: DocumentationManager.documentationsURL, includingPropertiesForKeys: nil, options: [])) ?? [] {
                                             let downloadableInfoURL = docURL.appendingPathComponent("pyto_documentation.json")
                                             guard let data = try? Data(contentsOf: downloadableInfoURL) else {
                                                 continue
                                             }
                                             
                                             guard let downloadableInfo = try? JSONDecoder().decode(DownloadableDocumentation.self, from: data) else {
                                                 continue
                                             }
                                             
                                             if downloadableInfo.name == doc.name {
                                                 downloadedDocumentation = downloadableInfo
                                                 break
                                             }
                                         }
                                     }
                                     
                                     guard let downloadedDocumentation = downloadedDocumentation else {
                                         return
                                     }
                                     
                                     Task {
                                         do {
                                             try await documentationManager.remove(documentation: downloadedDocumentation)
                                         } catch {
                                             print(error)
                                         }
                                     }
                                 } label: {
                                     Label {
                                         Text("Delete")
                                     } icon: {
                                         Image(systemName: "trash")
                                     }
                                 }
                             }
                        }
                    } else {
                        DisclosureGroup(isExpanded: $isExpanded) {
                            if isExpanded {
                                ForEach(titleiseAndSort(docs: doc.children!)) {
                                    DocumentationView(doc: $0, documentationViewController: documentationViewController, documentationSidebarViewController: documentationSidebarViewController, documentationManager: documentationManager)
                                }.onAppear {
                                    fixBackgroundColor(documentationSidebarViewController: documentationSidebarViewController)
                                }.onDisappear {
                                    fixBackgroundColor(documentationSidebarViewController: documentationSidebarViewController)
                                }
                            } else {
                                EmptyView()
                            }
                        } label: {
                            Label {
                                if colorScheme == .light {
                                    Text(doc.title).foregroundColor(.black)
                                } else {
                                    Text(doc.title).foregroundColor(.white)
                                }
                            } icon: {
                                Image(systemName: "folder")
                            }.contextMenu {
                                if !isBookmarked {
                                    Button {
                                        guard let bookmarkData = try? (doc.pageURL ?? doc.url)?.bookmarkData() else {
                                            return
                                        }
                                        
                                        let parentBookmarkData = try? getRoot(from: doc)?.url.bookmarkData()
                                        
                                        let bookmark = Documentation.Bookmark(name: doc.name, bookmarkData: bookmarkData, parentBookmarkData: parentBookmarkData, isFolder: true)
                                        documentationManager.bookmarks.insert(bookmark, at: 0)
                                    } label: {
                                        Label {
                                            Text("Add to bookmarks")
                                        } icon: {
                                            Image(systemName: "bookmark")
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
