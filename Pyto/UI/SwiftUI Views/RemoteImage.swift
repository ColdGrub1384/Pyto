//
//  RemoteImage.swift
//  UnicornStore
//
//  Created by Emma Labbé on 20-09-20.
//

import SwiftUI

@available(iOS 14.0, *)
struct RemoteImage: View {
    
    var url: URL
    
    init(url: URL) {
        self.url = url
    }
    
    @State var image: UIImage?
    
    func download(image: Binding<UIImage?>) {
        URLSession.shared.dataTask(with: url) { (data, _, _) in
            if let data = data {
                DispatchQueue.main.async {
                    image.wrappedValue = UIImage(data: data)
                }
            }
        }.resume()
    }
    
    var body: some View {
        if image == nil {
            download(image: $image)
            return AnyView(ProgressView().progressViewStyle(CircularProgressViewStyle()))
        }
        
        return AnyView(Image(uiImage: image ?? UIImage())
                        .resizable()
                        .aspectRatio(contentMode: .fit))
    }
}
