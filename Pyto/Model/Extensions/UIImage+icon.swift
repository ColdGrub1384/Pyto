// https://indiestack.com/2018/05/icon-for-file-with-uikit/

import UIKit

extension UIImage {
    public enum FileIconSize {
        case smallest
        case largest
    }

    public class func icon(forFileURL fileURL: URL, preferredSize: FileIconSize = .smallest) -> UIImage {
        let myInteractionController = UIDocumentInteractionController(url: fileURL)
        let allIcons = myInteractionController.icons

        // allIcons is guaranteed to have at least one image
        switch preferredSize {
        case .smallest: return allIcons.first!
        case .largest: return allIcons.last!
        }
    }
}
