//
//  ShortcutsView.swift
//  SwiftUI Views
//
//  Created by Emma Labbé on 31-05-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import SwiftUI

public struct Shortcut: Codable {
    
    var name: String
    
    var icon: UIImage
    
    var sfSymbol: String
    
    var description: String
    
    var url: URL
    
    enum CodingKeys: String, CodingKey {
        case name
        case sfSymbol
        case icon
        case description
        case url
    }
    
    public init(name: String, icon: UIImage, sfSymbol: String, description: String, url: URL) {
        self.name = name
        self.icon = icon
        self.sfSymbol = sfSymbol
        self.description = description
        self.url = url
    }
    
    public init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        self.name = try container.decode(String.self, forKey: .name)
        self.sfSymbol = try container.decode(String.self, forKey: .sfSymbol)
        self.description = try container.decode(String.self, forKey: .description)
        
        if let url = URL(string: try container.decode(String.self, forKey: .url)) {
            self.url = url
        } else {
            throw NSError()
        }
        
        if let image = UIImage(named: (try container.decode(String.self, forKey: .icon))) {
            self.icon = image
        } else {
            throw NSError()
        }
    }
    
    public func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        try container.encode(name, forKey: .name)
        try container.encode(sfSymbol, forKey: .sfSymbol)
        try container.encode(description, forKey: .description)
        try container.encode(url.absoluteString, forKey: .url)
        try container.encode(icon.accessibilityIdentifier ?? "SomeIcon", forKey: .icon)
    }
}

@available(iOS 13.0, *)
struct ShortcutCell: View {
    
    var secondaryColor: UIColor {
        var color = UIColor.secondaryLabel
        
        let semaphore = DispatchSemaphore(value: 0)
        UITraitCollection(userInterfaceStyle: .dark).performAsCurrent {
            
            var r: CGFloat = 0
            var g: CGFloat = 0
            var b: CGFloat = 0
            var a: CGFloat = 0
            
            color.getRed(&r, green: &g, blue: &b, alpha: &a)
            
            color = UIColor(displayP3Red: r, green: g, blue: b, alpha: a)
            
            semaphore.signal()
        }
        semaphore.wait()
        
        return color
    }
    
    var shortcut: Shortcut
    
    var body: some View {
         ZStack {
            Rectangle()
                .fill(Color(shortcut.icon.backgroundColor))
                .cornerRadius(13)
            
            VStack {
                HStack {
                    Image(systemName: shortcut.sfSymbol)
                        .font(.system(size: 30))
                        .offset(x: -80, y: 15)
                        .foregroundColor(.white)
                    
                    Image(systemName: "plus")
                        .font(.system(size: 20))
                        .offset(x: 80, y: 15)
                        .foregroundColor(.white)
                }
                Spacer()
            }
            
            VStack {
                Spacer()
                HStack {
                    Text(shortcut.name).foregroundColor(.white)
                        .offset(x: 10, y: -10)
                        .font(Font.system(.subheadline).bold())
                    Spacer()
                }
                HStack {
                    Text(shortcut.description).foregroundColor(Color(secondaryColor))
                        .offset(x: 10, y: -10)
                        .font(Font.system(.caption))
                        .multilineTextAlignment(.leading)
                    Spacer()
                }
            }
        }.frame(width: 240, height: 136)
    }
}

@available(iOS 13.4, *)
public struct ShortcutsView: View {
    
    public let shortcuts: [Shortcut]
    
    public let hostController: UIViewController?
    
    public init(shortcuts: [Shortcut], hostController: UIViewController? = nil) {
        self.shortcuts = shortcuts
        self.hostController = hostController
    }
    
    public var body: some View {
        
        ScrollView(.horizontal, content: {
            HStack {
                ForEach(self.shortcuts, id: \.name) { item in
                
                    Button(action: {
                        UIApplication.shared.open(item.url, options: [:], completionHandler: nil)
                    }) {
                        HStack {
                            Spacer()
                            ShortcutCell(shortcut: item)
                            Spacer()
                        }
                    }
                }
            }
        })
    }
}

@available(iOS 13.4, *)
struct ShortcutsView_Previews: PreviewProvider {

    static let shortcuts = [
        Shortcut(name: "Download Video", icon: UIImage(named: "download_video")!, sfSymbol: "square.and.arrow.down.fill", description: "Downloads a video with youtube_dl. youtube_dl must be installed from PyPi.", url: URL(string: "https://www.icloud.com/shortcuts/dc4b14506c5b487196366d1aa9b7cde7")!)
    ]
    
    static var previews: some View {
        ShortcutsView(shortcuts: shortcuts)
    }
}
