//
//  TemplateChooser.swift
//  Pyto
//
//  Created by Emma on 15-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import SwiftUI

// MARK: - Template

/// A template.
struct Template: Codable {
    
    /// The path of the template.
    var path: String
    
    /// The file extension.
    var `extension`: String
    
    /// The localized key for the name.
    var localized_name: String
    
    /// The URL.
    var url: URL? {
        Bundle.main.url(forResource: path, withExtension: nil)
    }
}

// MARK: - TemplateChooser

/// A view to choose a template.
struct TemplateChooser: View {
    
    /// The view controller presenting this view.
    var parent: UIViewController
    
    /// If set to `true`, an alert to set the new file name will be presented.
    var chooseName: Bool
    
    /// The block called when a template is imported. The parameters are the URL of the template and the `UIDocumentBrowserViewController.ImportMode` if the handler is from the document browser.
    var importHandler: ((URL?, UIDocumentBrowserViewController.ImportMode) -> Void)
    
    /// A list of bundled templates.
    var bundledTemplates: [Template] {
        do {
            guard let url = Bundle.main.url(forResource: "templates", withExtension: "json") else {
                return []
            }
            let data = try Data(contentsOf: url)
            return try JSONDecoder().decode([Template].self, from: data)
        } catch {
            return []
        }
    }
    
    /// The URL of the directory containing all of the user's template.
    var userTemplatesURL: URL {
        FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("templates")
    }
    
    /// Returns the templates that the user manually added.
    ///
    /// - Returns: A list of `URL`s added by the user.
    func getUserTemplates() -> [URL] {
        var urls = (try? FileManager.default.contentsOfDirectory(at: userTemplatesURL, includingPropertiesForKeys: nil, options: [])) ?? []
        urls = urls.sorted(by: { a, b in
            a.absoluteString.compare(b.absoluteString, options: .numeric) == .orderedAscending
        })
        return urls
    }
    
    /// The user's template.
    @State var userTemplates = [URL]()
    
    /// Imports a  template with the given name.
    ///
    ///     - Parameters: The name of the new file / folder
    ///     - templateURL: The template to import.
    func create(name: String, templateURL: URL) {
        let importHandler = self.importHandler
        
        func callHandler() {
            let newURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent(name)
            
            if FileManager.default.fileExists(atPath: newURL.path) {
                try? FileManager.default.removeItem(at: newURL)
            }
            
            try? FileManager.default.copyItem(at: templateURL, to: newURL)
            
            importHandler(newURL, .move)
        }
        
        if chooseName {
            parent.dismiss(animated: true) {
                callHandler()
            }
        } else {
            callHandler()
        }
    }
    
    /// Imports the given template
    ///
    /// - Parameters:
    ///         templateURL: The URL of the template to import.
    func create(templateURL: URL) {
        if chooseName {
            let alert = UIAlertController(title: NSLocalizedString("creation.createScriptTitle", comment: "The title of the button shown for creating a script"), message: NSLocalizedString("creation.typeFileName", comment: "The message of the alert shown for creating a file"), preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
            alert.addAction(UIAlertAction(title: NSLocalizedString("create", comment: "'Create' button"), style: .default, handler: { (_) in
                
                var name = ""
                if let text = alert.textFields?.first?.text {
                    if !text.replacingOccurrences(of: " ", with: "").isEmpty {
                        name = text
                    } else {
                        name = alert.textFields?.first?.placeholder ?? ""
                    }
                } else {
                    name = NSLocalizedString("untitled", comment: "Untitled")
                }
                
                if (name as NSString).pathExtension.lowercased() != templateURL.deletingPathExtension().pathExtension {
                    name = (name as NSString).appendingPathExtension(templateURL.deletingPathExtension().pathExtension) ?? ""
                }
                
                create(name: name, templateURL: templateURL)
            }))
            alert.addTextField { (textField) in
                textField.placeholder = NSLocalizedString("untitled", comment: "Untitled")
            }
            parent.presentedViewController?.present(alert, animated: true, completion: nil)
        } else {
            var isDir: ObjCBool = false
            create(name: NSLocalizedString("untitled", comment: "Untitled")+"\((FileManager.default.fileExists(atPath: templateURL.path, isDirectory: &isDir) && isDir.boolValue) ? "" : ".py")", templateURL: templateURL)
        }
    }
    
    @State var isShowingTemplateImporter = false
    
    @State var error: Error?
    
    func remove(template: URL) {
        do {
            try FileManager.default.removeItem(at: template)
            
            userTemplates = getUserTemplates()
        } catch {
            self.error = error
        }
    }
    
    var body: some View {
        NavigationView {
            List {
                Section {
                    ForEach(bundledTemplates, id: \.path) { template in
                        Button {
                            guard let url = template.url else {
                                return
                            }
                            
                            create(templateURL: url)
                        } label: {
                            Label {
                                Text(NSLocalizedString(template.localized_name, comment: "")).foregroundColor(.primary)
                            } icon: {
                                Image(systemName: "doc.fill")
                            }
                        }
                    }
                }
                
                Section {
                    Button {
                        if !FileManager.default.fileExists(atPath: userTemplatesURL.path) {
                            try? FileManager.default.createDirectory(at: userTemplatesURL, withIntermediateDirectories: true, attributes: nil)
                        }
                        
                        isShowingTemplateImporter = true
                    } label: {
                        Label {
                            Text("importTemplate")
                        } icon: {
                            Image(systemName: "plus")
                        }
                    }
                    
                    ForEach(userTemplates, id: \.path) { template in
                        Button {
                            create(templateURL: template)
                        } label: {
                            Label {
                                Text(template.lastPathComponent).foregroundColor(.primary)
                            } icon: {
                                Image(systemName: "doc.fill")
                            }
                        }.contextMenu {
                            if #available(iOS 15.0, *) {
                                Button(role: .destructive) {
                                    remove(template: template)
                                } label: {
                                    Label {
                                        Text("menuItems.remove")
                                    } icon: {
                                        Image(systemName: "trash.fill")
                                    }
                                }
                            } else {
                                Button {
                                    remove(template: template)
                                } label: {
                                    Label {
                                        Text("menuItems.remove")
                                    } icon: {
                                        Image(systemName: "trash.fill")
                                    }
                                }
                            }
                        }
                    }.onDelete { indexSet in
                        guard let i = indexSet.first else {
                            return
                        }
                        
                        let template = userTemplates[i]
                        remove(template: template)
                    }
                }
            }.navigationTitle(NSLocalizedString("newScript", comment: "The title of the template chooser"))
                .navigationBarItems(trailing: Button(action: {
                    parent.dismiss(animated: true, completion: nil)
                }, label: {
                    Text("cancel")
                }))
        }.navigationViewStyle(.stack).fileImporter(isPresented: $isShowingTemplateImporter, allowedContentTypes: [.pythonScript, .html]) { result in
            switch result {
            case .success(let url):
                do {
                    let dest = userTemplatesURL.appendingPathComponent(url.lastPathComponent)
                    
                    if FileManager.default.fileExists(atPath: dest.path) {
                        try FileManager.default.removeItem(at: dest)
                    }
                    
                    try FileManager.default.copyItem(at: url, to: dest)
                    
                    userTemplates = getUserTemplates()
                } catch {
                    self.error = error
                }
            case .failure(let error):
                print(error.localizedDescription)
            }
        }.alert(isPresented: .constant(error != nil)) {
            Alert(title: Text("error"), message: Text(error!.localizedDescription), dismissButton: .cancel({
                error = nil
            }))
        }.onAppear {
            userTemplates = getUserTemplates()
        }
    }
}

struct TemplateChooser_Previews: PreviewProvider {
    static var previews: some View {
        TemplateChooser(parent: UIViewController(), chooseName: true) { _, _ in
        }
    }
}
