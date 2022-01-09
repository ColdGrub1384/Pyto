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
    
    var creationHandler: (URL) -> ()
    
    func create() {
        guard let templateURL = Bundle.main.url(forResource: "_project_template", withExtension: nil) else {
            return
        }
        
        let tmpURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent(name)
        
        if FileManager.default.fileExists(atPath: tmpURL.path) {
            try? FileManager.default.removeItem(at: tmpURL)
        }
        
        do {
            try FileManager.default.copyItem(at: templateURL, to: tmpURL)
            for file in (try FileManager.default.contentsOfDirectory(at: tmpURL, includingPropertiesForKeys: nil, options: [])) {
                
                let packageName = name.lowercased().replacingOccurrences(of: " ", with: "_")
                
                if file.lastPathComponent == "{name}" {
                    try FileManager.default.moveItem(at: file, to: file.deletingLastPathComponent().appendingPathComponent(packageName))
                    continue
                }
                
                var string = try String(contentsOf: file)
                string = string.replacingOccurrences(of: "{name}", with: name.replacingOccurrences(of: " ", with: "-"))
                string = string.replacingOccurrences(of: "{pkg}", with: packageName)
                string = string.replacingOccurrences(of: "{author}", with: author)
                string = string.replacingOccurrences(of: "{description}", with: description)
                string = string.replacingOccurrences(of: "{url}", with: url)
                
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
                        Text("Name")
                        TextField("", text: $name, prompt: nil).textInputAutocapitalization(.none)
                    }
                    
                    HStack {
                        Text("Author")
                        TextField("", text: $author, prompt: nil).textContentType(.name)
                    }
                    
                    HStack {
                        Text("URL")
                        TextField("", text: $url, prompt: nil).textContentType(.URL)
                    }
                    
                    HStack {
                        Text("Description")
                        TextField("", text: $description, prompt: nil)
                    }
                }.disableAutocorrection(true).navigationTitle(Text("New project")).toolbar(content: {
                    ToolbarItemGroup(placement: .navigationBarLeading) {
                        Button {
                            dismiss()
                        } label: {
                            Text("Cancel")
                        }
                    }
                    
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        Button {
                            create()
                        } label: {
                            Text("Create").bold()
                        }.disabled(name.isEmpty)
                    }
                })
                
                if error != nil {
                    Text(error!).foregroundColor(.red)
                }
            }
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
                } catch {
                    self.error = error.localizedDescription
                }
                
                url.stopAccessingSecurityScopedResource()
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
