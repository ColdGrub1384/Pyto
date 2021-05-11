//
//  GalleryView.swift
//  Pyto
//
//  Created by Emma Labbé on 07-11-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 14.0, *)
struct SwiftUIView: View {
    var body: some View {
        NavigationView {
            ScrollView {
                VStack {
                    
                    ScrollView(.horizontal, content: {
                        HStack {
                            ForEach(0...10, id: \.self) { i in
                                GalleryScript_Previews.script
                            }
                        }
                    })
                    
                    Divider()
                    
                    HStack {
                        Text("Home Screen Widgets").font(.title3).fontWeight(.bold)
                        Spacer()
                    }.padding()
                    
                    ScrollView(.horizontal, content: {
                        HStack {
                            ForEach(0...10, id: \.self) { i in
                                GalleryScript_Previews.script
                            }
                        }
                    })
                    
                    Divider()
                    
                    HStack {
                        Text("Great with Shortcuts").font(.title3).fontWeight(.bold)
                        Spacer()
                    }.padding()
                    
                    ScrollView(.horizontal, content: {
                        HStack {
                            ForEach(0...10, id: \.self) { i in
                                GalleryScript_Previews.script
                            }
                        }
                    })
                    
                    Divider()
                    
                    HStack {
                        Text("Utilities").font(.title3).fontWeight(.bold)
                        Spacer()
                    }.padding()
                    
                                        
                    ScrollView(.horizontal, content: {
                        HStack {
                            ForEach(0...10, id: \.self) { i in
                                GalleryScript_Previews.script
                            }
                        }
                    })
                }
            }.padding().navigationBarTitle("Gallery")
        }.navigationViewStyle(StackNavigationViewStyle())
    }
}

@available(iOS 14.0, *)
struct SwiftUIView_Previews: PreviewProvider {
    static var previews: some View {
        SwiftUIView()
    }
}
