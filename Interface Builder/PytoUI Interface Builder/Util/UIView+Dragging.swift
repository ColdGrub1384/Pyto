import UIKit
import MobileCoreServices

@available(iOS 16.0, *)
extension UIView: UIDragInteractionDelegate {
    
    public func dragInteraction(_ interaction: UIDragInteraction, itemsForBeginning session: UIDragSession) -> [UIDragItem] {
        
        let item = UIDragItem(itemProvider: NSItemProvider(item: tag as NSSecureCoding, typeIdentifier: "public.item"))
        item.localObject = self
        return [item]
    }
}
