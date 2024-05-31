import SwiftUI

extension View {
    func flexible(width: Bool, height: Bool) -> some View {
        self.modifier(MatchingParentModifier(width: width, height: height))
    }
}

struct MatchingParentModifier: ViewModifier {
    @State private var intrinsicSize: CGSize = UIScreen.main.bounds.size
    private let intrinsicWidth:  Bool
    private let intrinsicHeight:  Bool

    init(width: Bool, height: Bool) {
        intrinsicWidth = !width
        intrinsicHeight = !height
    }

    func body(content: Content) -> some View {
        GeometryReader { _ in
            content.modifier(intrinsicSizeModifier(intrinsicSize: $intrinsicSize))
        }
        .frame(
            maxWidth: intrinsicWidth ? intrinsicSize.width : nil,
            maxHeight: intrinsicHeight ? intrinsicSize.height : nil
        )
    }
}

struct intrinsicSizeModifier: ViewModifier {
    @Binding var intrinsicSize: CGSize

    func body(content: Content) -> some View {
        content.readIntrinsicContentSize(to: $intrinsicSize)
    }
}

struct IntrinsicContentSizePreferenceKey: PreferenceKey {
    static let defaultValue: CGSize = .zero

    static func reduce(value: inout CGSize, nextValue: () -> CGSize) {
        value = nextValue()
    }
}

extension View {
    func readIntrinsicContentSize(to size: Binding<CGSize>) -> some View {
        background(
            GeometryReader {
                Color.clear.preference(
                    key: IntrinsicContentSizePreferenceKey.self,
                    value: $0.size
                )
            }
        )
        .onPreferenceChange(IntrinsicContentSizePreferenceKey.self) {
            size.wrappedValue = $0
        }
    }
}
