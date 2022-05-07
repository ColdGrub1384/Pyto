//
//  DocumentationsDownloadScreen.swift
//  Pyto
//
//  Created by Emma on 19-03-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI

struct DocumentationsDownloadScreen: View {
    
    @ObservedObject var documentationManager: DocumentationManager
    
    @State var downloadingDocumentations = [DownloadableDocumentation]()
    
    @State var error: String?
    
    @State var progress: Progress?
    
    var documentationSidebarViewController: DocumentationViewController.SidebarViewController?
    
    func download() {
        let docs = downloadingDocumentations
        downloadingDocumentations = []
        Task {
            do {
                try await documentationManager.download(documentations: docs, progress: $progress)
            } catch {
                print(error)
            }
            await MainActor.run {
                progress = nil
            }
        }
    }
    
    var body: some View {
        List {
            
            if progress != nil {
                Section {
                    VStack {
                        ProgressView(progress!)
                        if progress!.completedUnitCount == progress!.totalUnitCount {
                            Text(NSLocalizedString("decompressing", comment: "Something is decompressing")).padding(.top)
                        }
                    }
                }
            }
            
            if documentationManager.nonDownloadedDocumentations.count > 0 {
                Button {
                    downloadingDocumentations = documentationManager.nonDownloadedDocumentations
                } label: {
                    Text(NSLocalizedString("downloadAll", comment: "Download all"))
                }.onAppear {
                    fixBackgroundColor(documentationSidebarViewController: documentationSidebarViewController)
                }.onDisappear {
                    fixBackgroundColor(documentationSidebarViewController: documentationSidebarViewController)
                }
                
                ForEach(documentationManager.nonDownloadedDocumentations) { doc in
                    Button {
                        downloadingDocumentations = [doc]
                    } label: {
                        Label {
                            VStack {
                                HStack {
                                    Text(doc.name).foregroundColor(.primary)
                                    Spacer()
                                }
                                HStack {
                                    Text(doc.version).font(.footnote).foregroundColor(.secondary)
                                    Spacer()
                                }
                            }
                        } icon: {
                            Image(systemName: "icloud.and.arrow.down.fill")
                        }
                    }
                }.disabled(progress != nil).background(Group {
                    if #available(iOS 15.0, *) {
                        Text("").alert(error != nil ? NSLocalizedString("error", comment: "Error") : NSLocalizedString("download", comment: "Download something"), isPresented: .constant(downloadingDocumentations.count > 0 || error != nil)) {
                            
                            Button(role: .cancel) {
                                downloadingDocumentations = []
                                error = nil
                            } label: {
                                Text(NSLocalizedString("cancel", comment: "'Cancel' button"))
                            }
                            
                            if error == nil {
                                Button {
                                    download()
                                } label: {
                                    Text(NSLocalizedString("download", comment: "Download something"))
                                }
                            }
                        } message: {
                            if error != nil {
                                Text(error!)
                            } else {
                                Text("\(NSString(format: NSLocalizedString("downloadDocumentation", comment: "A dialog asking the user if they want to download the documentation(s). Replace %@ by the documentations to download.") as NSString, downloadingDocumentations.map({ $0.name }).joined(separator: ", ")))")
                            }
                        }
                    } else {
                        Text("").alert(isPresented: .constant(downloadingDocumentations.count > 0 || error != nil)) {
                            
                            if error == nil {
                                return Alert(title: Text(NSLocalizedString("download", comment: "Download something")), message: Text("\(NSString(format: NSLocalizedString("downloadDocumentation", comment: "A dialog asking the user if they want to download the documentation(s). Replace %@ by the documentations to download.") as NSString, downloadingDocumentations.map({ $0.name }).joined(separator: ", ")))"), primaryButton: .cancel({
                                    downloadingDocumentations = []
                                }), secondaryButton: Alert.Button.default(Text(NSLocalizedString("download", comment: "Download something")), action: {
                                    download()
                                }))
                            } else {
                                return Alert(title: Text(NSLocalizedString("error", comment: "Error")), message: Text("\(error!)"), dismissButton: .cancel({
                                    downloadingDocumentations = []
                                    error = nil
                                }))
                            }
                        }
                    }
                })
            }
        }.navigationBarTitle(Text(NSLocalizedString("downloads", comment: "The title of the downloadable documentations view")))
    }
}
