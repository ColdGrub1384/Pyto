//
//  ThemeChooserCollectionViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 1/17/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import SavannaKit
import SourceEditor
import Highlightr

/// A View controller for choosing a theme.
class ThemeChooserCollectionViewController: UICollectionViewController, UIContextMenuInteractionDelegate {
    
    private var textViews = [Data:UITextView]()
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    var styleSegmentedControl: UISegmentedControl!
    
    var userInterfaceStyle: UIUserInterfaceStyle {
        (styleSegmentedControl?.selectedSegmentIndex ?? 0) == 0 ? .light : .dark
    }
    
    @IBAction func didChangeStyle(_ sender: Any) {
        collectionView.reloadData()
    }
    
    // MARK: - Collection view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let collectionLayout = UICollectionViewFlowLayout()
        collectionLayout.itemSize = CGSize(width: 228, height: 145)
        collectionLayout.sectionInset = UIEdgeInsets(top: 20, left: 25, bottom: 20, right: 25)
        collectionLayout.headerReferenceSize = CGSize(width: collectionView.frame.size.width, height: 50)
        
        collectionView.collectionViewLayout = collectionLayout
        
        view.accessibilityIgnoresInvertColors = true
        
        if #available(iOS 13.0, *) {
        } else {
            navigationItem.rightBarButtonItems = nil
        }
        
        NotificationCenter.default.addObserver(forName: ThemeDidChangeNotification, object: nil, queue: .main) { [weak self] _ in
            self?.collectionView.reloadData()
        }
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        
        if #available(iOS 13.0, *) {
            view.backgroundColor = UIColor.systemBackground
        }
        collectionView.reloadData()
    }
    
    override func collectionView(_ collectionView: UICollectionView, viewForSupplementaryElementOfKind kind: String, at indexPath: IndexPath) -> UICollectionReusableView {
        
        let headerView = collectionView.dequeueReusableSupplementaryView(ofKind: UICollectionView.elementKindSectionHeader, withReuseIdentifier: "header", for: indexPath)

        headerView.frame.size.height = 50
        let _styleSegmentedControl = headerView.subviews.first as? UISegmentedControl
        if styleSegmentedControl != _styleSegmentedControl {
            styleSegmentedControl = _styleSegmentedControl
            collectionView.reloadData()
        }
        
        return headerView
    }
    
    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return Themes.count
    }
    
    override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell", for: indexPath)
        
        let theme = Themes[indexPath.row].value
        cell.overrideUserInterfaceStyle = theme.userInterfaceStyle
        cell.contentView.clipsToBounds = true
        cell.contentView.layer.cornerRadius = 6
        cell.contentView.layer.borderWidth = 2
        cell.contentView.isUserInteractionEnabled = false
        UITraitCollection(userInterfaceStyle: theme.userInterfaceStyle).performAsCurrent {
            cell.contentView.layer.borderColor = UIColor.secondaryLabel.cgColor
        }
        cell.addInteraction(UIContextMenuInteraction(delegate: self))
        
        let label = (cell.contentView.subviews.compactMap({ $0 as? UILabel })).first
        label?.textColor = theme.sourceCodeTheme.color(for: .plain)
        label?.text = Themes[indexPath.row].name
        
        let checkmark = (cell.contentView.subviews.compactMap({ $0 as? UIImageView })).first
        checkmark?.isHidden = theme.data != ConsoleViewController.theme(for: userInterfaceStyle).data
        
        guard let containerView = cell.contentView.subviews.filter({ !($0 is UILabel) && !($0 is UIImageView) }).first else {
            return cell
        }
        
        let textView: UITextView
        if let _textView = textViews[theme.data] {
            textView = _textView
        } else {
            
            let textStorage = CodeAttributedString()
            textStorage.language = "Python"
            
            let layoutManager = NSLayoutManager()
            textStorage.addLayoutManager(layoutManager)
            
            let container = NSTextContainer()
            layoutManager.addTextContainer(container)
            
            let highlightr = textStorage.highlightr
            highlightr.theme = HighlightrTheme(themeString: theme.css)
            highlightr.theme.setCodeFont(EditorViewController.font.withSize(6))
            
            textView = UITextView(frame: .zero, textContainer: container)
            textView.text = """
                @requires_authorization
                def somefunc(param1='', param2=0):
                    r'''A docstring'''
                    if param1 > param2: # interesting
                        print('Gre\\'ater')
                    return (param2 - param1 + 1 + 0b10l) or None

                class SomeClass:
                    pass
                """
            
            textViews[theme.data] = textView
        }
        
        textView.frame = containerView.frame
        textView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        textView.isScrollEnabled = false
        textView.isEditable = false
        containerView.addSubview(textView)
        
        textView.backgroundColor = theme.sourceCodeTheme.backgroundColor
        cell.contentView.backgroundColor = theme.sourceCodeTheme.backgroundColor
        
        return cell
    }
    
    override func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        ConsoleViewController.set(theme: Themes[indexPath.row].value, for: userInterfaceStyle)
        collectionView.reloadData()
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        super.prepare(for: segue, sender: sender)
        
        guard #available(iOS 13.0, *) else {
            return
        }
        
        if segue.identifier == "customTheme" {
            let vc = (segue.destination as? UINavigationController)?.viewControllers.last as? ThemeMakerTableViewController
            
            let theme = ConsoleViewController.theme(for: userInterfaceStyle)
            
            var name = theme.name ?? ""
            var i = 1
            while (Themes.map({ $0.value })+ThemeMakerTableViewController.themes).contains(where: { $0.name == name }) {
                i += 1
                name = "\(theme.name ?? "") \(i)"
            }
            
            ThemeMakerTableViewController.themes.append(theme)
            
            vc?.index = ThemeMakerTableViewController.themes.count-1
            vc?.loadViewIfNeeded()
            vc?.name = name
        }
    }
    
    // MARK: - Syntax text view delegate
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {}
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    
    // MARK: - Context menu interaction delegate
    
    func contextMenuInteraction(_ interaction: UIContextMenuInteraction, configurationForMenuAtLocation location: CGPoint) -> UIContextMenuConfiguration? {
        
        guard let cell = interaction.view as? UICollectionViewCell else {
            return nil
        }
        
        guard let indexPath = collectionView.indexPath(for: cell) else {
            return nil
        }
        
        let isCustom = ThemeMakerTableViewController.themes.indices.contains(indexPath.row-((Themes.count-ThemeMakerTableViewController.themes.count)))
        
        let config = UIContextMenuConfiguration(identifier: nil, previewProvider: nil) { _ in
            return UIMenu(title: "", image: nil, identifier: nil, options: [], children: [
                
                UIAction(title: "Edit", image: UIImage(systemName: "pencil"), identifier: nil, discoverabilityTitle: "Edit", attributes: !isCustom ? .disabled : [], state: .off, handler: { [unowned self] _ in
                    
                    let i = indexPath.row
                    
                    let index = i-((Themes.count-ThemeMakerTableViewController.themes.count))
                    
                    guard ThemeMakerTableViewController.themes.indices.contains(index) else {
                        return
                    }
                    
                    guard let vc = storyboard?.instantiateViewController(withIdentifier: "themeMaker") as? ThemeMakerTableViewController else {
                        return
                    }
                    
                    vc.loadViewIfNeeded()
                    
                    vc.index = index
                    vc.theme = Themes[i].value
                    
                    self.present(UINavigationController(rootViewController: vc), animated: true, completion: nil)
                }),
                
                UIAction(title: "Delete", image: UIImage(systemName: "trash"), identifier: nil, discoverabilityTitle: "Delete", attributes: !isCustom ? [.disabled, .destructive] : [.destructive], state: .off, handler: { [unowned self] _ in
                    
                    let index = indexPath.row-((Themes.count-ThemeMakerTableViewController.themes.count))
                    
                    guard ThemeMakerTableViewController.themes.indices.contains(index) else {
                        return
                    }
                    
                    ThemeMakerTableViewController.themes.remove(at: index)
                    
                    self.collectionView.deleteItems(at: [indexPath])
                })
            ])
        }
        
        return config
    }
}
