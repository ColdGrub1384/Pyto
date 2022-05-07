import SwiftUI

@available(iOS 15.0, *)
struct BreakpointCreator: View {
    
    var fileURL: URL
    
    var files: [URL]
    
    @State var isPickingFile = false
    
    @State var pickedFileURL: URL?
    
    @State var pickedFile = false
    
    @Environment(\.dismiss) var dismiss
    
    var body: some View {
        NavigationView {
            
            ZStack {
                NavigationLink(isActive: $pickedFile) { 
                    if pickedFileURL != nil {
                        ScriptView(fileURL: pickedFileURL!, dismiss: {
                            dismiss()
                        })
                    } else {
                        EmptyView()
                    }
                } label: { 
                    Text("")
                }.opacity(0)
                
                List {
                    ForEach(files, id: \.path) { file in
                        Button { 
                            pickedFileURL = file
                            pickedFile = true
                        } label: { 
                            Label { 
                                Text(file.lastPathComponent).foregroundColor(.primary)
                            } icon: { 
                                Image(systemName: "doc")
                            }
                        }
                    }
                    
                    Section { 
                        Button { 
                            isPickingFile = true
                        } label: { 
                            Label { 
                                Text("browse").foregroundColor(.primary)
                            } icon: { 
                                Image(systemName: "folder")
                            }
                        }
                    }
                }
            }
            .navigationTitle("addBreakpoint")
            .navigationBarTitleDisplayMode(.inline)
            .toolbar { 
                ToolbarItemGroup(placement: .navigationBarTrailing) { 
                    Button("cancel") { 
                        dismiss()
                    }
                }
            }
            
        }.navigationViewStyle(.stack).fileImporter(isPresented: $isPickingFile, allowedContentTypes: [.pythonScript]) { result in
            switch result {
            case .success(let url):
                _ = url.startAccessingSecurityScopedResource()
                pickedFileURL = url
                pickedFile = true
            default:
                break
            }
        }
    }
}
