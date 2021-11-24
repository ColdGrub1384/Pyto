//
//  WidgetSimulatorViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 16-07-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

// Sorry Pythonista, I had to copy this awesome feature.

import UIKit
import NotificationCenter

/// A View controller for previewing a widget.
@available(iOS 13.0, *)
class WidgetSimulatorViewController: UIViewController {
    
    /// The only visible instances. ( Yep, the app supports multiple windows but not multiple widgets :) )
    static var visible: WidgetSimulatorViewController?
    
    /// Set to `true` if the widget can be expanded.
    static var canBeExpanded = false {
        didSet {
            DispatchQueue.main.async {
                self.visible?.showMoreButton.isHidden = !canBeExpanded
            }
        }
    }
    
    /// The maximum height of the widget.
    static var maximumHeight: Double = 280 {
        didSet {
            DispatchQueue.main.async {
                if self.visible?.isExpanded == true {
                    self.visible?.showMore(self.visible!.showMoreButton)
                    DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
                        self.visible?.showMore(self.visible!.showMoreButton)
                    }
                }
            }
        }
    }
    
    /// The widget view to be displayed.
    var pyView: PyView?
    
    /// The URL of the script presenting this UI.
    var scriptURL: URL?
    
    /// `true` if the widget is expanded.
    var isExpanded = false
    
    private var isViewSetup = false
    
    /// The scroll view containing the widget.
    @IBOutlet weak var scrollView: UIScrollView!
    
    /// The view containing the app icon.
    @IBOutlet weak var iconView: UIImageView!
    
    /// The view representing the widget.
    @IBOutlet weak var containerView: UIView!
    
    /// The view containing buttons.
    @IBOutlet weak var titleView: UIView!
    
    /// The blur widget background view.
    @IBOutlet weak var blurView: UIVisualEffectView!
    
    /// The view that contains the widget content.
    @IBOutlet weak var contentView: UIView!
    
    /// The wallpaper.
    @IBOutlet weak var wallpaperView: UIImageView!
    
    /// The button for expanding the widget.
    @IBOutlet weak var showMoreButton: UIButton!
    
    /// Expands the widget.
    @IBAction func showMore(_ sender: UIButton) {
        
        UIView.animate(withDuration: 0.25) {
            if self.isExpanded {
                // Collapse
                self.contentView.frame.size.height = 110
                self.pyView?.view.frame.size.height = 110
                self.containerView.frame.size.height = 154
                self.blurView.frame.size.height = 154
                //self.wallpaperView.frame.size.height = self.containerView.frame.maxY+25
            } else {
                // Expand
                self.contentView.frame.size.height = CGFloat(WidgetSimulatorViewController.maximumHeight)
                self.pyView?.view.frame.size.height = CGFloat(WidgetSimulatorViewController.maximumHeight)
                self.containerView.frame.size.height = CGFloat(WidgetSimulatorViewController.maximumHeight)+44
                self.blurView.frame.size.height = CGFloat(WidgetSimulatorViewController.maximumHeight)+44
                //self.wallpaperView.frame.size.height = self.containerView.frame.maxY+25
            }
            
            self.scrollView.contentSize.height = self.containerView.frame.height+15
        }
        
        if isExpanded {
            sender.setTitle(Localizable.WidgetSimulator.showMore, for: .normal)
        } else {
            sender.setTitle(Localizable.WidgetSimulator.showLess, for: .normal)
        }
        
        isExpanded = !isExpanded
    }
    
    /// Adds the widget.
    @IBAction func addWidget(_ sender: UIButton) {
        
        guard let url = scriptURL else {
            return
        }
        
        do {
            UserDefaults.standard.set(try url.bookmarkData(), forKey: "todayWidgetScriptPath")
            
            let alert = UIAlertController(title: Localizable.WidgetSimulator.alertTitle, message: Localizable.WidgetSimulator.alertMessage, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: Localizable.ok, style: .default, handler: nil))
            present(alert, animated: true, completion: nil)
        } catch {
            let alert = UIAlertController(title: Localizable.WidgetSimulator.alertTitle, message: error.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: Localizable.ok, style: .default, handler: nil))
            present(alert, animated: true, completion: nil)
        }
        (UIApplication.shared.delegate as? AppDelegate)?.copyModules()        
    }
    
    /// Closes the widget simulator.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    // MARK: - View controller
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if let visible = WidgetSimulatorViewController.visible, visible != self {
            visible.dismiss(animated: true, completion: nil)
        }
        
        WidgetSimulatorViewController.visible = self
        
        guard !isViewSetup else {
            return
        }
        isViewSetup = true
        
        pyView?.tintColor = PyColor(managed: UIColor.systemBlue)
        
        containerView.alpha = 0
        
        if let iconsDictionary = Bundle.main.infoDictionary?["CFBundleIcons"] as? NSDictionary,
            let primaryIconsDictionary = iconsDictionary["CFBundlePrimaryIcon"] as? NSDictionary,
            let iconFiles = primaryIconsDictionary["CFBundleIconFiles"] as? NSArray,
            // First will be smallest for the device class, last will be the largest for device class
            let firstIcon = iconFiles.firstObject as? String,
            let icon = UIImage(named: firstIcon) {
            
            iconView.image = icon
        }
        
        iconView.layer.cornerRadius = 4
        
        containerView.frame.origin.y = 10
        containerView.layer.cornerRadius = 13
        
        containerView.frame.size.width = view.safeAreaLayoutGuide.layoutFrame.width-10
        contentView.frame.size.width = containerView.frame.width
        contentView.frame.size.height = 110
        titleView.frame.size.width = view.safeAreaLayoutGuide.layoutFrame.width-10
        blurView.frame.size.width = view.safeAreaLayoutGuide.layoutFrame.width-10
        showMoreButton.frame.origin.x = titleView.frame.width-showMoreButton.frame.width
        containerView.center.x = view.center.x
        
        /*wallpaperView.frame.size.width = view.frame.width
        wallpaperView.frame.size.height = containerView.frame.maxY+25
        wallpaperView.layer.cornerRadius = 13*/
        wallpaperView.frame.size = view.frame.size
        
        showMoreButton.isHidden = !WidgetSimulatorViewController.canBeExpanded
        
        scrollView.frame = view.safeAreaLayoutGuide.layoutFrame
        scrollView.contentSize.height = containerView.frame.height+15
        
        if let widget = pyView {
            contentView.addSubview(widget.view)
            widget.view.frame.size = contentView.frame.size
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        scrollView.frame = view.safeAreaLayoutGuide.layoutFrame
        
        UIView.animate(withDuration: 0.25) {
            self.containerView.alpha = 1
        }
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        
        /*wallpaperView.frame.size.width = size.width
        wallpaperView.frame.size.height = containerView.frame.maxY+25*/
        wallpaperView.frame.size = size
        
        coordinator.animate(alongsideTransition: nil) { (_) in
            self.scrollView.frame = self.view.safeAreaLayoutGuide.layoutFrame
            self.scrollView.contentSize.height = self.containerView.frame.height+15
            self.containerView.frame.size.width = self.view.safeAreaLayoutGuide.layoutFrame.width-10
            self.contentView.frame.size.width = self.containerView.frame.width
            self.pyView?.view.frame.size.width = self.containerView.frame.width
            if self.isExpanded {
                self.contentView.frame.size.height = 280
            } else {
                self.contentView.frame.size.height = 110
            }
            self.titleView.frame.size.width = self.view.safeAreaLayoutGuide.layoutFrame.width-10
            self.blurView.frame.size.width = self.view.safeAreaLayoutGuide.layoutFrame.width-10
            self.showMoreButton.frame.origin.x = self.titleView.frame.width-self.showMoreButton.frame.width
            self.containerView.center.x = self.view.center.x
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        pyView?.isPresented = false
    }
}
