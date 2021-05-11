//
//  PyTableViewSection.swift
//  Pyto
//
//  Created by Emma Labbé on 18-07-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *) @objc public class PyTableViewSection: NSObject {

    @objc public var tableView: PyTableView?
    
    @objc public var title: String?
    
    @objc public var cells = NSArray() {
        didSet {
            if self.reload, let index = self.tableView?.sections.index(of: self) {
                PyWrapper.set {
                    self.tableView?.tableView.reloadSections([index], with: .automatic)
                }
            }
        }
    }
    
    @objc public var managedValue: PyValue?
    
    @objc public var didSelectCell: PyValue?
    
    @objc public var accessoryButtonTapped: PyValue?
    
    @objc public var didDeleteCell: PyValue?
    
    @objc public var didMoveCell: PyValue?
    
    @objc public var reload = true
    
    @objc var references = 0
    
    @objc func releaseReference() {
        references -= 1
    }
    
    @objc func retainReference() {
        references += 1
    }
    
    public func call(action: PyValue, for index: Int, to destination: Int? = nil) {
        
        guard let identifier = managedValue?.identifier else {
            return
        }
        
        Python.shared.run(code: "import _values; param = _values.\(identifier); _values.\(action.identifier)(param, \(index)"+(destination != nil ? ", \(destination!))" : ")"))
    }
}
