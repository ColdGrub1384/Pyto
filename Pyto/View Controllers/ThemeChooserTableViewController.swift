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
@available(*, deprecated, message: "Use dialog instead.")
class ThemeChooserTableViewController: UITableViewController, SyntaxTextViewDelegate {
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.accessibilityIgnoresInvertColors = true
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
        
        from time import sleep
        
        name = input("What's your name? ")
        print("Hello "+name+"!")
        
        sleep(1)
        
        print("Bye!") # Comment
        """
        
        textView.theme = ReadonlyTheme(theme.sourceCodeTheme)
        
        textView.frame = containerView.frame
        textView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        containerView.addSubview(textView)
        
        cell.backgroundColor = theme.sourceCodeTheme.backgroundColor
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        dismiss(animated: true) {
            ConsoleViewController.choosenTheme = Themes[indexPath.row].value
        }
    }
    
    // MARK: - Syntax text view delegate
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {}
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
}
