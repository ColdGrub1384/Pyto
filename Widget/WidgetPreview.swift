//
//  WidgetPreview.swift
//  Pyto
//
//  Created by Emma Labbé on 06-08-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import WidgetKit
import SwiftUI

/// A view for previewing widgets.
@available(iOS 14.0, *)
struct WidgetPreview: View {
    
    class ViewControllerStore {
        var vc: UIViewController?
    }
    
    var entry: ScriptEntry
        
    @Environment(\.horizontalSizeClass) var horizontalSize
    
    let viewControllerStore = ViewControllerStore()
    
    func widget(family: WidgetFamily) -> some View {
        WidgetEntryView(entry: entry, customFamily: family)
            .frame(width: size(for: family, size: horizontalSize ?? .compact).width, height: size(for: family, size: horizontalSize ?? .compact).height)
            .cornerRadius(16)
            .padding()
    }
    
    var body: some View {
        
        NavigationView {
            ZStack {
                Image("Wallpaper").resizable().aspectRatio(contentMode: ContentMode.fill).ignoresSafeArea()
                
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
            }
            .frame(minWidth: 0, maxWidth: .infinity)
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
