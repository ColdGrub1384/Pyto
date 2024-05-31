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
    
    enum Language {
        case python
        case c
        case cpp
    }
    
    @Environment(\.dismiss) var dismiss
    
    @State var name = ""
    
    @AppStorage("projectsAuthor") var author = ""
    
    @State var url = ""
    
    @State var description = ""
    
    @State var error: String?
    
    @State var isExporting = false
    
    @State var projectURL: URL?
    
    @State var docs = true
    
    @State var cext = false
    
    @State var ui = false
    
    @State var language = Language.python
    
    var creationHandler: (URL) -> ()
    
    func createPythonProject() {
        guard let templateURL = Bundle.main.url(forResource: cext ? "Samples/_project_template_cext" : "Samples/_project_template", withExtension: nil) else {
            return
        }
        
        var packageName = name.lowercased().replacingOccurrences(of: " ", with: "_").replacingOccurrences(of: "-", with: "_")
        let okayChars : Set<Character> =
                Set("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLKMNOPQRSTUVWXYZ1234567890_")
        packageName = String(packageName.filter {okayChars.contains($0) })
        
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
                
                if file.deletingPathExtension().lastPathComponent == "{name}" {
                    let newURL = file.deletingLastPathComponent().appendingPathComponent(packageName).appendingPathExtension(file.pathExtension)
                    try FileManager.default.moveItem(at: file, to: newURL)
                    
                    if file.pathExtension == "c" {
                        var string = try String(contentsOf: newURL)
                        string = string.replacingOccurrences(of: "{pkg}", with: packageName)
                        try string.write(to: newURL, atomically: false, encoding: .utf8)
                    }
                    
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
                
                if !ui && file.lastPathComponent == "ui_init.py" {
                    try FileManager.default.removeItem(at: file)
                } else if ui && file.lastPathComponent == "ui_init.py" {
                    let newInit = file.deletingLastPathComponent().appendingPathComponent("__init__.py")
                    try FileManager.default.removeItem(at: newInit)
                    try FileManager.default.moveItem(at: file, to: newInit)
                }
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
    
    func createCommandLineProject(_ language: Language) {
        guard let templateURL = Bundle.main.url(forResource: "Samples/_\(language == .cpp ? "cpp" : "c")_project_template", withExtension: nil) else {
            return
        }
        
        let tmpURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent(name)
        
        if FileManager.default.fileExists(atPath: tmpURL.path) {
            try? FileManager.default.removeItem(at: tmpURL)
        }
        
        do {
            try FileManager.default.copyItem(at: templateURL, to: tmpURL)
            try """
            import sys
            import runpy
            import os

            sys.argv = ["setup.py", "build", "--run"]
            runpy.run_path(os.path.join(os.path.dirname(__file__), "..", "setup.py"))
            """.write(toFile: tmpURL.appendingPathComponent("src/.run.py").path, atomically: false, encoding: .utf8)
            
            for file in (try FileManager.default.contentsOfDirectory(at: tmpURL, includingPropertiesForKeys: nil)) {
                
                var packageName = name.lowercased().replacingOccurrences(of: " ", with: "_").replacingOccurrences(of: "-", with: "_")
                let okayChars : Set<Character> =
                        Set("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLKMNOPQRSTUVWXYZ1234567890_")
                packageName = String(packageName.filter {okayChars.contains($0) })
                
                if file.deletingPathExtension().lastPathComponent == "{name}" {
                    try FileManager.default.moveItem(at: file, to: file.deletingLastPathComponent().appendingPathComponent(packageName))
                    continue
                }
                
                var isDir: ObjCBool = false
                guard FileManager.default.fileExists(atPath: file.path, isDirectory: &isDir) && !isDir.boolValue else {
                    continue
                }
                
                var string = try String(contentsOf: file)
                string = string.replacingOccurrences(of: "{name}", with: name.replacingOccurrences(of: " ", with: "-"))
                string = string.replacingOccurrences(of: "{cmd}", with: packageName.replacingOccurrences(of: "_", with: "-"))
                string = string.replacingOccurrences(of: "{description}", with: description)
                
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
                    Section {
                        HStack {
                            Text("projectCreator.language", comment: "The language of the project")
                            Spacer()
                            Picker(selection: $language) {
                                Text("Python").tag(Language.python)
                                Text("C").tag(Language.c)
                                Text("C++").tag(Language.cpp)
                            } label: {
                                EmptyView()
                            }
                        }
                    }
                    
                    Section {
                        HStack {
                            Text("projectCreator.name", comment: "The name of the project")
                            TextField("", text: $name, prompt: nil).textInputAutocapitalization(.none)
                        }
                        
                        if language == .python {
                            HStack {
                                Text("projectCreator.author", comment: "The author of the project")
                                TextField("", text: $author, prompt: nil).textContentType(.name)
                            }
                            
                            HStack {
                                Text("projectCreator.url", comment: "The URL of the project")
                                TextField("", text: $url, prompt: nil).textContentType(.URL)
                            }
                        }
                        
                        HStack {
                            Text("projectCreator.description", comment: "The description of the project")
                            TextField("", text: $description, prompt: nil)
                        }
                        
                        if language == .python {
                            
                            HStack {
                                Toggle(isOn: $ui) {
                                    Text("projectCreator.ui", comment: "Include UI")
                                }
                            }
                            
                            HStack {
                                Toggle(isOn: $cext) {
                                    Text("projectCreator.cext", comment: "Include C Extension")
                                }
                            }
                            
                            HStack {
                                Toggle(isOn: $docs) {
                                    Text("projectCreator.sphinxDocumentation", comment: "The label of the switch for toggling Sphinx Docs")
                                }
                            }
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
                            if language == .python {
                                createPythonProject()
                            } else {
                                createCommandLineProject(language)
                            }
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
                    
                    #if !PREVIEW
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
                    #endif
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
