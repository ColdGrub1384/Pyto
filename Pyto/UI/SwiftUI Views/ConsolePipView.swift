//
//  ConsolePipView.swift
//  Pyto
//
//  Created by Emma on 22-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import SwiftUI

struct ConsolePipView: View {
    var body: some View {
        VStack {
            Image(systemName: "pip").resizable().aspectRatio(contentMode: .fit).frame(maxWidth: 130, maxHeight: 130)
            Text("Script is running in Picture in Picture (PIP)").padding()
        }.foregroundColor(.secondary).clipped()
    }
}

struct ConsolePipView_Previews: PreviewProvider {
    static var previews: some View {
        ConsolePipView()
    }
}
