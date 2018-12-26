//
//  ErrorView.swift
//  Pyto
//
//  Created by Adrian Labbe on 12/26/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

fileprivate let latestTracebackKey = "latestTraceback" // Stored in User Defaults due to memory issue

/// A view for displaying a Python exception.
@objc class ErrorViewController: UIViewController, UIAdaptivePresentationControllerDelegate {
    
    /// The label containing the error type.
    @IBOutlet weak var errorTypeLabel: UILabel!
    
    /// The label containing the reason.
    @IBOutlet weak var reasonTextView: UITextView!
    
    /// Prints the traceback.
    @IBAction func showTraceback(_ sender: Any) {
        dismiss(animated: true) {
            PyOutputHelper.print("\n"+(UserDefaults.standard.string(forKey: latestTracebackKey) ?? "")+"\n")
        }
    }
    
    // MARK: - Presenting
    
    /// Presents error with given information.
    ///
    /// - Parameters:
    ///     - reason: The reason of the error.
    ///     - type: The type of the error.
    ///     - traceback: The full traceback.
    @objc static func presentError(reason: String, type: String, traceback: String) {
        DispatchQueue.main.sync {
            let controller = ErrorViewController(nibName: "Error", bundle: Bundle.main)
            controller.loadViewIfNeeded()
            controller.reasonTextView.text = reason
            controller.errorTypeLabel.text = type
            UserDefaults.standard.set(traceback, forKey: latestTracebackKey)
            UserDefaults.standard.synchronize()
            controller.modalPresentationStyle = .popover
            controller.popoverPresentationController?.permittedArrowDirections = []
            controller.popoverPresentationController?.sourceView = ConsoleViewController.visible.view
            controller.popoverPresentationController?.sourceRect = ConsoleViewController.visible.view.bounds
            controller.presentationController?.delegate = controller
            
            ConsoleViewController.visible.present(controller, animated: true, completion: nil)
        }
    }
    
    // MARK: - Adaptive presentation controller delegate
    
    func adaptivePresentationStyle(for controller: UIPresentationController) -> UIModalPresentationStyle {
        return .none
    }
}
