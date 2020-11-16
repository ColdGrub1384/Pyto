//
//  GalleryScript.swift
//  Pyto
//
//  Created by Emma Labbé on 07-11-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 14.0, *)
struct GalleryScript: View, Codable {
    
    var title: String
    
    var description: String
    
    var symbolName: String
    
    var colors: [UIColor]
    
    var imageURL: URL
    
    @State var isPresenting = false
    
    private var withBackground = true
    
    fileprivate var swiftUIColors: [Color] {
        var _colors = [Color]()
        for color in self.colors {
            _colors.append(Color(color))
        }
        return _colors
    }
    
    enum Keys: CodingKey {
        case title
        case description
        case symbolName
        case colors
        case imageURL
    }
    
    init(title: String, description: String, symbolName: String, colors: [UIColor], imageURL: URL) {
        
        self.title = title
        self.description = description
        self.symbolName = symbolName
        self.colors = colors
        self.imageURL = imageURL
    }
    
    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Keys.self)
        title = try container.decode(String.self, forKey: .title)
        description = try container.decode(String.self, forKey: .description)
        symbolName = try container.decode(String.self, forKey: .symbolName)
        imageURL = try container.decode(URL.self, forKey: .imageURL)
        
        let colorData = try container.decode([Data].self, forKey: .colors)
        var _colors = [UIColor]()
        for color in colorData {
            _colors.append(UIColor.color(withData: color))
        }
        colors = _colors
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(title, forKey: .title)
        try container.encode(description, forKey: .description)
        try container.encode(symbolName, forKey: .symbolName)
        try container.encode(imageURL, forKey: .imageURL)
        
        var colorData = [Data]()
        for color in colors {
            colorData.append(color.encode())
        }
        
        try container.encode(colorData, forKey: .colors)
    }
    
    var body: some View {
        
        let stack = HStack {
            Spacer()
            VStack {
                HStack {
                    Image(systemName: symbolName).font(.system(size: 30))
                        .padding(.horizontal, 5)
                        .padding(.vertical)
                    
                    Text(title).fontWeight(.bold)
                    
                    Spacer()
                    
                    Text("GET")
                        .padding(.horizontal)
                        .padding(.vertical, 5)
                        .overlay(
                            RoundedRectangle(cornerRadius: 20)
                                .stroke(Color.white, lineWidth: 1.5)
                        )
                }
                
                if withBackground {
                    HStack {
                        Text(description)
                        Spacer()
                    }
                }
                
                Spacer()
            }
            Spacer()
        }
            .foregroundColor(.white)
                
        if withBackground {
            return AnyView(Button(action: {
                isPresenting = true
            }, label: {
                ZStack {
                    LinearGradient(gradient: Gradient(colors: swiftUIColors), startPoint: .bottom, endPoint: .top).cornerRadius(16)
                    
                    stack
                }
            }).frame(height: 150).sheet(isPresented: $isPresenting, content: {
                GalleryScriptDetails(script: self)
            }))
        } else {
            return AnyView(stack)
        }
    }
    
    var withoutBackground: GalleryScript {
        var _self = self
        _self.withBackground = false
        return _self
    }
}

@available(iOS 14.0, *)
struct GalleryScriptDetails: View {
    
    var script: GalleryScript
    
    @Environment(\.presentationMode) var presentationMode
    
    var body: some View {
        VStack {
            ZStack {
                LinearGradient(gradient: Gradient(colors: script.swiftUIColors), startPoint: .bottom, endPoint: .top)
                
                VStack {
                    
                    Rectangle().fill(Color.clear).frame(height: 40)
                    
                    HStack {
                        Spacer()
                        Button(action: {
                            presentationMode.wrappedValue.dismiss()
                        }, label: {
                            Image(systemName: "xmark")
                                .padding(5)
                                .foregroundColor(.white)
                                .background(Color.gray.opacity(0.5))
                                .clipShape(Circle())
                        })
                    }.padding()
                    
                    Spacer()
                    script.withoutBackground
                }
            }.frame(height: 100)
            
            ScrollView {
                
                VStack {
                    HStack {
                        Spacer()
                        RemoteImage(url: script.imageURL)
                            .cornerRadius(0)
                        Spacer()
                    }
                        .frame(maxHeight: 500)
                        .padding()
                    
                    HStack {
                        Text(script.description)
                        Spacer()
                    }.padding()
                }
            }.padding(.top, 50)
            
            Spacer()
        }
    }
}

@available(iOS 14.0, *)
struct GalleryScript_Previews: PreviewProvider {
    
    static let script = GalleryScript(title: "Test Script", description: "That script does something.", symbolName: "wifi", colors: [UIColor(red: 255/225, green: 50/255, blue: 50/255, alpha: 1), UIColor(red: 255/255, green: 79/255, blue: 79/255, alpha: 1)], imageURL: URL(string: "https://www.iphonehacks.com/wp-content/uploads/2018/12/iPad-Pro-Assistive-Touch-settings.jpg")!)
    
    static var previews: some View {
        script.padding()
    }
}
