//
//  ViewControllerTransitionCoordinator.swift
//  Pyto
//
//  Created by Adrian Labbe on 12/21/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// An empty `ViewControllerTransitionCoordinator` for calling `UIViewController` functions manually.
class ViewControllerTransitionCoordinator: NSObject, UIViewControllerTransitionCoordinator {
    var isAnimated: Bool = false
    var presentationStyle: UIModalPresentationStyle = .custom
    var initiallyInteractive: Bool = false
    var isInterruptible: Bool = false
    var isInteractive: Bool = false
    var isCancelled: Bool = false
    var transitionDuration: TimeInterval = 0.0
    var percentComplete: CGFloat = 0.0
    var completionVelocity: CGFloat = 0.0
    var completionCurve: UIView.AnimationCurve = .linear
    func viewController(forKey key: UITransitionContextViewControllerKey) -> UIViewController? { return nil }
    func view(forKey key: UITransitionContextViewKey) -> UIView? { return nil }
    var containerView: UIView = UIView()
    var targetTransform: CGAffineTransform = CGAffineTransform(rotationAngle: 0)
    func animate(alongsideTransition animation: ((UIViewControllerTransitionCoordinatorContext) -> Void)?, completion: ((UIViewControllerTransitionCoordinatorContext) -> Void)? = nil) -> Bool { return false }
    func animateAlongsideTransition(in view: UIView?, animation: ((UIViewControllerTransitionCoordinatorContext) -> Void)?, completion: ((UIViewControllerTransitionCoordinatorContext) -> Void)? = nil) -> Bool { return false }
    func notifyWhenInteractionEnds(_ handler: @escaping (UIViewControllerTransitionCoordinatorContext) -> Void) {}
    func notifyWhenInteractionChanges(_ handler: @escaping (UIViewControllerTransitionCoordinatorContext) -> Void) {}
}
