//
//  ThemeChooserTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import SavannaKit
import SourceEditor

/// A View controller for choosing a theme.
class ThemeChooserTableViewController: UITableViewController, SyntaxTextViewDelegate {
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    /// Edits a theme.
    @objc func editTheme(_ sender: UIButton) {
        
        guard #available(iOS 13.0, *) else {
            return
        }
        
        guard let title = sender.title(for: .disabled), let i = Int(title) else {
            return
        }
        
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
        
        present(UINavigationController(rootViewController: vc), animated: true, completion: nil)
    }
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.accessibilityIgnoresInvertColors = true
        
        if #available(iOS 13.0, *) {
        } else {
            navigationItem.rightBarButtonItems = nil
        }
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        
        if #available(iOS 13.0, *) {
            view.backgroundColor = UIColor.systemBackground
        }
        tableView.reloadData()
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Themes.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell") ?? UITableViewCell(style: .default, reuseIdentifier: nil)
        
        let theme = Themes[indexPath.row].value
        
        let label = cell.contentView.viewWithTag(1) as? UILabel
        
        label?.textColor = theme.sourceCodeTheme.color(for: .plain)
        label?.text = Themes[indexPath.row].name
        
        guard let containerView = cell.contentView.viewWithTag(2) else {
            return cell
        }
        
        let textView = SyntaxTextView()
        textView.delegate = self
        textView.text = """
        # Created with Pyto
        
        from time import sleep
        name = input("What's your name? ")
        sleep(1)
        print("Hello "+name+"!")
        """
        
        textView.theme = ReadonlyTheme(theme.sourceCodeTheme)
        
        textView.frame = containerView.frame
        textView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        containerView.addSubview(textView)
        
        cell.backgroundColor = theme.sourceCodeTheme.backgroundColor
        
        let button = cell.contentView.viewWithTag(3) as? UIButton
        button?.tintColor = theme.sourceCodeTheme.color(for: .plain)
        button?.setTitle("\(indexPath.row)", for: .disabled)
        button?.isHidden = !self.tableView(tableView, canEditRowAt: indexPath)
        button?.addTarget(self, action: #selector(editTheme(_:)), for: .touchUpInside)
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        navigationController?.popViewController(animated: true)
        ConsoleViewController.choosenTheme = Themes[indexPath.row].value
    }
    
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        if #available(iOS 13.0, *) {
            return indexPath.row > Themes.count-ThemeMakerTableViewController.themes.count-1
        } else {
            return false
        }
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        
        /*
         
         Default themes:
         
         0
         1
         2
         
         Created by user:
         
         3 <- Selected
         4
         5
         6
         
         Total: 7
        
         Index in themes created by user: 7-3-3-1 = 0
         
         */
        
        guard #available(iOS 13.0, *) else {
            return
        }
        
        let index = indexPath.row-((Themes.count-ThemeMakerTableViewController.themes.count))
        
        guard ThemeMakerTableViewController.themes.indices.contains(index) else {
            return
        }
        
        ThemeMakerTableViewController.themes.remove(at: index)
        
        tableView.deleteRows(at: [indexPath], with: .automatic)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        super.prepare(for: segue, sender: sender)
        
        guard #available(iOS 13.0, *) else {
            return
        }
        
        if segue.identifier == "customTheme" {
            let vc = (segue.destination as? UINavigationController)?.viewControllers.last as? ThemeMakerTableViewController
            
            let theme = ConsoleViewController.choosenTheme
            ThemeMakerTableViewController.themes.append(theme)
            
            vc?.index = ThemeMakerTableViewController.themes.count-1
        }
    }
    
    // MARK: - Syntax text view delegate
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {}
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
}
