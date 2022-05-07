//
//  ProjectCreator.swift
//  Pyto
//
//  Created by Emma on 06-01-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 15.0, *)
struct ProjectCreator: View {
    
    @Environment(\.dismiss) var dismiss
    
    @State var name = ""
    
    @AppStorage("projectsAuthor") var author = ""
    
    @State var url = ""
    
    @State var description = ""
    
    @State var error: String?
    
    @State var isExporting = false
    
    @State var projectURL: URL?
    
    @State var docs = true
    
    var creationHandler: (URL) -> ()
    
    func create() {
        guard let templateURL = Bundle.main.url(forResource: "Samples/_project_template", withExtension: nil) else {
            return
        }
        
        let tmpURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent(name)
        
        if FileManager.default.fileExists(atPath: tmpURL.path) {
            try? FileManager.default.removeItem(at: tmpURL)
        }
        
        do {
            try FileManager.default.copyItem(at: templateURL, to: tmpURL)
            let docs = tmpURL.appendingPathComponent("docs")
            if !self.docs {
                try FileManager.default.removeItem(at: docs)
            }
            
            let docsContent = (try? FileManager.default.contentsOfDirectory(at: docs, includingPropertiesForKeys: nil, options: [])) ?? []
            for file in (try FileManager.default.contentsOfDirectory(at: tmpURL.appendingPathComponent("{name}"), includingPropertiesForKeys: nil, options: []))+(try FileManager.default.contentsOfDirectory(at: tmpURL, includingPropertiesForKeys: nil, options: []))+docsContent {
                
                let packageName = name.lowercased().replacingOccurrences(of: " ", with: "_").replacingOccurrences(of: "-", with: "_")
                
                if file.lastPathComponent == "{name}" {
                    try FileManager.default.moveItem(at: file, to: file.deletingLastPathComponent().appendingPathComponent(packageName))
                    continue
                }
                
                var isDir: ObjCBool = false
                guard FileManager.default.fileExists(atPath: file.path, isDirectory: &isDir) && !isDir.boolValue else {
                    continue
                }
                
                var string = try String(contentsOf: file)
                string = string.replacingOccurrences(of: "{name}", with: name.replacingOccurrences(of: " ", with: "-"))
                string = string.replacingOccurrences(of: "{pkg}", with: packageName)
                string = string.replacingOccurrences(of: "{cmd}", with: packageName.replacingOccurrences(of: "_", with: "-"))
                string = string.replacingOccurrences(of: "{author}", with: author)
                string = string.replacingOccurrences(of: "{description}", with: description)
                string = string.replacingOccurrences(of: "{url}", with: url)
                string = string.replacingOccurrences(of: "{year}", with: "\(Calendar.current.dateComponents([.year], from: Date()).year ?? 2022)")
                string = string.replacingOccurrences(of: "{doctitle}", with: String(repeating: "=", count: "Welcome to \(name.replacingOccurrences(of: " ", with: "-"))'s documentation!".count))
                
                try string.write(to: file, atomically: false, encoding: .utf8)
            }
            
            isExporting = true
            projectURL = tmpURL
        } catch {
            self.error = error.localizedDescription
            
            if FileManager.default.fileExists(atPath: tmpURL.path) {
                try? FileManager.default.removeItem(at: tmpURL)
            }
        }
    }
    
    var body: some View {
        NavigationView {
            VStack {
                List {
                    HStack {
                        Text("projectCreator.name", comment: "The name of the project")
                        TextField("", text: $name, prompt: nil).textInputAutocapitalization(.none)
                    }
                    
                    HStack {
                        Text("projectCreator.author", comment: "The author of the project")
                        TextField("", text: $author, prompt: nil).textContentType(.name)
                    }
                    
                    HStack {
                        Text("projectCreator.url", comment: "The URL of the project")
                        TextField("", text: $url, prompt: nil).textContentType(.URL)
                    }
                    
                    HStack {
                        Text("projectCreator.description", comment: "The description of the project")
                        TextField("", text: $description, prompt: nil)
                    }
                    
                    HStack {
                        Toggle(isOn: $docs) {
                            Text("projectCreator.sphinxDocumentation", comment: "The label of the switch for toggling Sphinx Docs")
                        }
                    }
                }.disableAutocorrection(true).navigationTitle(Text("projectCreator.title", comment: "The title of the project creator")).toolbar(content: {
                    ToolbarItemGroup(placement: .navigationBarLeading) {
                        Button {
                            dismiss()
                        } label: {
                            Text("cancel", comment: "'Cancel' button")
                        }
                    }
                    
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        Button {
                            create()
                        } label: {
                            Text("create", comment: "'Create' button").bold()
                        }.disabled(name.isEmpty)
                    }
                })
                
                if error != nil {
                    Text(error!).foregroundColor(.red)
                }
            }.textInputAutocapitalization(.never)
        }.navigationViewStyle(.stack).fileImporter(isPresented: $isExporting, allowedContentTypes: [.folder]) { result in
            switch result {
            case .failure(let error):
                self.error = error.localizedDescription
            case .success(let url):
                guard let projectURL = projectURL else {
                    return
                }

                _ = url.startAccessingSecurityScopedResource()
                
                let newURL = url.appendingPathComponent(projectURL.lastPathComponent)
                do {
                    try FileManager.default.moveItem(at: projectURL, to: newURL)
                    creationHandler(newURL)
                    
                    DispatchQueue.global().async {
                        Python.shared.run(code: """
                        import runpy
                        import sys
                        import os
                        import threading
                        
                        threading.current_thread().script_path = '\(UUID().uuidString)'
                        
                        os.chdir('\(newURL.path.replacingOccurrences(of: "'", with: "\\'"))')
                        
                        sys.argv = ['pip', 'install', '.']
                        try:
                            runpy.run_module('pip', run_name='__main__')
                        except SystemExit:
                            pass
                        """)
                    }
                } catch {
                    self.error = error.localizedDescription
                }                
            }
        }
    }
}

struct ProjectCreator_Previews: PreviewProvider {
    static var previews: some View {
        if #available(iOS 15.0, *) {
            ProjectCreator {
                print($0)
            }
        } else {
            EmptyView()
        }
    }
}
