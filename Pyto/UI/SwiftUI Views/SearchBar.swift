// https://www.appcoda.com/swiftui-search-bar/

import SwiftUI
 
@available(iOS 13.0, *)
struct SearchBar: View {
    
    @Binding var text: String
        
    var body: some View {
        HStack {
            Image(systemName: "magnifyingglass")
            .foregroundColor(.secondary)
            .padding(.horizontal, -20)
            
            TextField(NSLocalizedString("search", comment: "Placeholder of the search bar"), text: $text)
            .autocapitalization(.none)
            .disableAutocorrection(true)
            
        }
            .padding(7)
            .padding(.horizontal, 25)
            .background(Color(.secondarySystemFill))
            .cornerRadius(8)
            .padding(.horizontal, 10)
    }
}

@available(iOS 13.0.0, *)
struct SearchBar_Previews: PreviewProvider {
    static var previews: some View {
        SearchBar(text: .constant(""))
    }
}
