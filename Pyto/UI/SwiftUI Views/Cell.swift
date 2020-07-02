//
//  Cell.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 18-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

func isString(_ text: String) -> Bool {
    return (text.hasPrefix("'") && text.hasSuffix("'")) || (text.hasPrefix("\"") && text.hasSuffix("\""))
}

@available(iOS 13.0, *)
struct Cell: View {
    
    @State var title = ""
    
    @State var detail = ""
    
    var body: some View {
        HStack {
            if isString(title) {
                Text(title).foregroundColor(.red)
            } else {
                Text(title)
            }
            Spacer()
            Text(detail).foregroundColor(.secondary)
        }.frame(maxHeight: 60)
    }
}

@available(iOS 13.0, *)
struct Cell_Previews: PreviewProvider {
    static var previews: some View {
        List {
            Cell(title: "Title", detail: "Detail")
            Cell(title: "Title", detail: "Detail")
            Cell(title: "Title", detail: "Detail")
        }
    }
}
