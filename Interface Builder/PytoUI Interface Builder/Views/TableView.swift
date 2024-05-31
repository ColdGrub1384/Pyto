//
//  TableView.swift
//  InterfaceBuilder
//
//  Created by Emma on 07-09-22.
//

import UIKit

class PreviewTableViewDataSource: NSObject, UITableViewDataSource, UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return .leastNonzeroMagnitude
    }
    
    func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        return .leastNonzeroMagnitude
    }
    
    func tableView(_ tableView: UITableView, estimatedHeightForHeaderInSection section: Int) -> CGFloat {
        .leastNonzeroMagnitude
    }
    
    func tableView(_ tableView: UITableView, estimatedHeightForFooterInSection section: Int) -> CGFloat {
        .leastNonzeroMagnitude
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        1
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = UITableViewCell()
        
        var content = cell.defaultContentConfiguration()
        content.text = "Configure cells programatically"
                
        cell.contentConfiguration = content
        return cell
    }
}

protocol TableView: InterfaceBuilderView {
}

extension TableView {
    
    public var type: UIView.Type {
        return UITableView.self
    }
    
    public func preview(view: UIView) {
        view.backgroundColor = .secondarySystemBackground
        view.frame.size = CGSize(width: 40, height: 40)
        view.layer.borderColor = UIColor.gray.cgColor
        view.layer.borderWidth = 1
    }
    
    public var previewColor: UIColor? {
        .secondaryLabel
    }
    
    public func configure(view: UIView, model: inout InterfaceModel) {
        model.customSize.flexibleHeight[view.tag] = true
        model.customSize.flexibleWidth[view.tag] = true
    }
    
    public var image: UIImage? {
        UIImage(systemName: "list.bullet")
    }
}

public struct InsetGroupedTableView: TableView {
    
    public func makeView() -> UIView {
        UITableView(frame: .zero, style: .insetGrouped)
    }
}

public struct GroupedTableView: TableView {
    
    public func makeView() -> UIView {
        UITableView(frame: .zero, style: .grouped)
    }
}

public struct PlainTableView: TableView {
    
    public func makeView() -> UIView {
        UITableView(frame: .zero, style: .plain)
    }
}

extension UITableView {
    
    @objc class var UITableView_properties: [Any] {
        return []
    }
    
    @objc class var UITableView_connections: [String] {
        ["did_select_cell", "did_tap_cell_accessory_button", "did_delete_cell", "did_move_cell"]
    }
    
    @objc class var UITableView_customConnectionsSignatures: [String:String] {
        [
            "did_select_cell": "section: ui.TableViewSection, index: int",
            "did_tap_cell_accessory_button": "section: ui.TableViewSection, index: int",
            "did_delete_cell": "section: ui.TableViewSection, index: int",
            "did_move_cell": "section: ui.TableViewSection, source_index: int, destination_index: int"
        ]
    }
}
