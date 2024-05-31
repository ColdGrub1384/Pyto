import UIKit

/// A View controller for placing views.
@available(iOS 16.0, *) public class LibraryViewController: UITableViewController, UITableViewDragDelegate {
    
    /// Did select a view.
    public var didSelect: ((InterfaceBuilderView) -> ())?
    
    public override func viewDidLoad() {
        super.viewDidLoad()
        
        title = "Objects"
        edgesForExtendedLayout = []
        tableView.dragDelegate = self
        tableView.dragInteractionEnabled = true
    }
    
    public override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Items.count
    }
    
    public override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    public override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 80
    }
    
    public override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        
        let item = Items[indexPath.row]
        
        var config = cell.defaultContentConfiguration()
        config.image = nil
        
        if item is InsetGroupedTableView {
            config.text = "Inset Grouped Table View"
        } else if item is GroupedTableView {
            config.text = "Grouped Table View"
        } else if item is PlainTableView {
            config.text = "Plain Table View"
        } else {
            config.text = item.customDisplayName ?? prettifyClassName(NSStringFromClass(item.type))
        }
        
        config.secondaryText = NSStringFromClass(item.type).components(separatedBy: ".").last ?? ""
        
        cell.contentView.viewWithTag(84)?.removeFromSuperview()
        
        if let backgroundColor = item.previewColor {
            config.imageProperties.tintColor = backgroundColor
            config.image = item.image
        } else {
            let view: UIView
            view = item.makeView()
            view.tag = 84
            
            view.frame.origin = cell.frame.origin
            view.isUserInteractionEnabled = false
            view.frame.size.width = 55
            view.frame.origin.x = 10
            view.autoresizingMask = [.flexibleTopMargin, .flexibleBottomMargin]
            
            item.preview(view: view)
            
            cell.contentView.addSubview(view)
        }
        
        cell.contentConfiguration = config
        
        let label = UILabel(frame: CGRect(x: 0, y: 0, width: 200, height: 20))
        label.textColor = .label
        label.font = UIFont(name: "Menlo", size: UIFont.systemFontSize)
        label.textAlignment = .right
        label.text = "ui.\(PytoUIClassMap[NSStringFromClass(item.type).components(separatedBy: ".").last ?? ""] ?? "View")"
        
        cell.accessoryView = label
        
        return cell
    }
    
    public override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        didSelect?(Items[indexPath.row])
    }
    
    // MARK: - Table view drag delegate
    
    public func tableView(_ tableView: UITableView, dragSessionWillBegin session: UIDragSession) {
        DispatchQueue.main.async {
            self.dismiss(animated: true)
        }
    }
    
    public func tableView(_ tableView: UITableView, itemsForBeginning session: UIDragSession, at indexPath: IndexPath) -> [UIDragItem] {
        
        let item = UIDragItem(itemProvider: NSItemProvider(item: (try? JSONEncoder().encode(LibraryItem(index: indexPath.row))) as? NSSecureCoding, typeIdentifier: "interfacebuilder.view"))
        if let view = tableView.cellForRow(at: indexPath)?.contentView.subviews.first {
            item.previewProvider = {
                return UIDragPreview(view: view)
            }
        }
        return [item]
    }
}
