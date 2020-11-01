//
//  WidgetPreview.swift
//  Pyto
//
//  Created by Adrian Labbé on 06-08-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WidgetKit
import SwiftUI

/// A view for previewing widgets.
@available(iOS 14.0, *)
struct WidgetPreview: View {
        
    var entry: ScriptEntry
    
    let viewControllerStore = ViewControllerStore()
    
    @Environment(\.horizontalSizeClass) var horizontalSize
    
    func widget(family: WidgetFamily) -> some View {
        WidgetEntryView(entry: entry, customFamily: family)
            .frame(width: size(for: family, size: horizontalSize ?? .compact).width, height: size(for: family, size: horizontalSize ?? .compact).height)
            .cornerRadius(16)
            .padding()
    }
    
    var body: some View {
        
        NavigationView {
            ScrollView {
                VStack {
                    if horizontalSize == .compact {
                        widget(family: .systemSmall)
                        widget(family: .systemMedium)
                        widget(family: .systemLarge)
                    } else {
                        HStack {
                            widget(family: .systemSmall)
                            widget(family: .systemMedium)
                            Spacer()
                        }
                        HStack {
                            widget(family: .systemLarge)
                            Spacer()
                        }
                    }
                }
            }
            .frame(minWidth: 0, maxWidth: .infinity)
            .background(Image("Wallpaper").resizable().aspectRatio(contentMode: ContentMode.fill))
            .navigationBarItems(trailing: Button(action: {
                self.viewControllerStore.vc?.dismiss(animated: true, completion: nil)
            }, label: {
                Text("done").fontWeight(.bold)
            }).hoverEffect())
            .navigationBarTitleDisplayMode(.inline)
        }
        .navigationViewStyle(StackNavigationViewStyle())
    }
}
