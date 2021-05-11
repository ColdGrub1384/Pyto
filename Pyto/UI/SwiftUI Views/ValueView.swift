//
//  ValueView.swift
//  SwiftUI Views
//
//  Created by Emma Labbé on 18-05-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 13.0, *)
struct TextView: UIViewRepresentable {
    
    @State var text = ""
    
    func makeUIView(context: Context) -> UITextView {
        let v = UITextView()
        v.text = text
        v.font = UIFont(name: "Menlo", size: 15)
        
        if (text.hasPrefix("'") && text.hasSuffix("'")) || (text.hasPrefix("\"") && text.hasSuffix("\"")) {
            // Is String
            v.textColor = .systemRed
        }
        
        v.isEditable = false
        return v
    }
    
    func updateUIView(_ activityIndicator: UITextView, context: Context) {
    }
}

@available(iOS 13.0, *)
struct ValueView: View {
    
    @State var title = ""
    
    @State var text = ""
        
    var body: some View {
        TextView(text: text)
        .navigationBarTitle(Text(title), displayMode: .inline)
    }
}

@available(iOS 13.0, *)
struct ValueView_Previews: PreviewProvider {
    static var previews: some View {
        ValueView(title: "var_name", text: "'Hello World'")
    }
}
