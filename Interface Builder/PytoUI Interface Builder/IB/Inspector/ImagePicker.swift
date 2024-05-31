//
//  ImagePicker.swift
//  InterfaceBuilder
//
//  Created by Emma on 21-08-22.
//

import SwiftUI

@available(iOS 16.0, *)
extension InspectorView.PropertyView {
    
    /// An image picker.
    struct ImagePicker: View {
        
        struct SymbolPicker: View {
            
            @Binding var image: InspectorImage?
            
            @State var searchText = ""
            
            var showNone = false
            
            var symbols: [String] {
                guard let url = Bundle(for: InterfaceDocument.self).url(forResource: "sf_symbols", withExtension: "txt") else {
                    return []
                }
                
                guard let content = try? String(contentsOf: url) else {
                    return []
                }
                
                var symbols = content.components(separatedBy: "\n").filter({ !$0.isEmpty })
                
                if !searchText.isEmpty {
                    symbols = symbols.filter({
                        $0
                            .replacingOccurrences(of: ".", with: "")
                            .replacingOccurrences(of: " ", with: "")
                            .lowercased()
                            .contains(searchText.lowercased().replacingOccurrences(of: ".", with: "")
                                .replacingOccurrences(of: " ", with: ""))
                        
                    })
                }
                
                return symbols
            }
            
            var body: some View {
                List {
                    ForEach(symbols, id: \.self) { symbol in
                        SwiftUI.Button {
                            self.image = InspectorImage.symbol(symbol)
                        } label: {
                            HStack {
                                SwiftUI.Label {
                                    Text(symbol).foregroundColor(.primary)
                                } icon: {
                                    Image(systemName: symbol).foregroundColor(.primary)
                                }
                                
                                if case let .symbol(symbolName) = image {
                                    if symbolName == symbol {
                                        SwiftUI.Spacer()
                                        Image(systemName: "checkmark")
                                    }
                                }
                            }
                        }
                    }
                }
                    .searchable(text: $searchText)
                    .autocorrectionDisabled()
                    .textInputAutocapitalization(.never)
            }
        }
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        private enum ImageType: Hashable {
            case symbol
            case path
            case data
        }
        
        @State private var image: InspectorImage?
        
        @State private var imageType: ImageType = .symbol
        
        @State private var imagePath = ""
        
        @State private var isPresentingFilePicker = false
        
        /// Initializes the text input with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        private func absoluteImageURL() -> URL {
            guard let url = view.interfaceBuilder?.document?.fileURL.deletingLastPathComponent() else {
                return URL(fileURLWithPath: imagePath)
            }
            return URL(fileURLWithPath: imagePath, relativeTo: url)
        }
        
        func imageExists() -> Bool {
            var isDir: ObjCBool = false
            let exists = FileManager.default.fileExists(atPath: absoluteImageURL().path, isDirectory: &isDir) && !isDir.boolValue
            return exists
        }
        
        var body: some View {
            VStack {
                switch imageType {
                case .symbol:
                    SymbolPicker(image: $image)
                case .data:
                    SwiftUI.Button {
                        isPresentingFilePicker = true
                    } label: {
                        Text("Pick file")
                    }.fileImporter(isPresented: $isPresentingFilePicker, allowedContentTypes: [.image]) { result in
                        switch result {
                        case .success(let url):
                            guard let data = try? Data(contentsOf: url) else {
                                return
                            }
                            
                            image = InspectorImage.data(data)
                        case .failure(_):
                            break
                        }
                    }
                    
                    Text("The image itself will be embedded inside the PytoUI file, not the file path.")
                        .font(.caption)
                        .foregroundColor(.secondary)
                case .path:
                    HStack {
                        Text("Path")
                        SwiftUI.TextField("./image.png", text: $imagePath)
                        
                        if imageExists() {
                            Image(systemName: "checkmark").foregroundColor(.green)
                        } else {
                            Image(systemName: "xmark").foregroundColor(.red)
                        }
                    }.padding()
                    
                    Text("Path of the image, relative to this .pytoui file.").foregroundColor(.secondary)
                    
                    SwiftUI.Spacer()
                }
            }
                .navigationTitle("Image")
                .toolbar {
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        Picker("Type", selection: $imageType) {
                            Text("Symbol").tag(ImageType.symbol)
                            Text("Path").tag(ImageType.path)
                            Text("Data").tag(ImageType.data)
                        }.pickerStyle(.menu)
                    }
                }
                .onAppear {
                    if let image = (property.getValue(view).value as? InspectorImage) {
                        self.image = image
                        
                        switch image {
                        case .symbol(_):
                            self.imageType = .symbol
                        case .path(_):
                            self.imageType = .path
                        case .data(_):
                            self.imageType = .data
                        }
                    }
                    
                }
                .onChange(of: image) { newValue in
                    property.handler(view, .init(value: newValue))
                }.onChange(of: imagePath) { newValue in
                    if imageExists() {
                        image = InspectorImage.path(newValue)
                    }
                }
        }
    }
}
