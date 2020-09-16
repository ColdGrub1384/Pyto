//
//  ThemeMakerTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 13-10-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import SourceEditor
import SavannaKit
import Color_Picker_for_iOS
import Highlightr

@available(iOS 13.0, *)
class ThemeMakerTableViewController: UITableViewController, UITextFieldDelegate {
    
    static var themes: [Theme] {
        get {
            guard let themesData = UserDefaults.standard.array(forKey: "themes") as? [Data] else {
                return []
            }
            
            var themes = [Theme]()
            
            for theme in themesData {
                if let decoded = ThemeFromData(theme) {
                    themes.append(decoded)
                }
            }
            
            return themes
        }
        
        set {
            var data = [Data]()
            
            for theme in newValue {
                data.append(theme.data)
            }
            
            UserDefaults.standard.set(data, forKey: "themes")
        }
    }
    
    var index: Int!
    
    var presentingVC: UIViewController?
    
    // MARK: - Theme properties
    
    private var previewAfterSettingProperties = true
    
    var theme = ConsoleViewController.choosenTheme {
        didSet {
            if previewAfterSettingProperties {
                previewTheme(setTheme: false)
            }
        }
    }
    
    var name = "" {
        didSet {
            textField.text = name
        }
    }
    
    var interfaceStyle = UIUserInterfaceStyle.unspecified {
        didSet {
            if interfaceStyle == .light {
                interfaceStyleSegmentedControl.selectedSegmentIndex = 0
            } else if interfaceStyle == .dark {
                interfaceStyleSegmentedControl.selectedSegmentIndex = 1
            } else {
                interfaceStyleSegmentedControl.selectedSegmentIndex = 2
            }
            preview.overrideUserInterfaceStyle = interfaceStyle
        }
    }
    
    var tint: UIColor! {
        didSet {
            preview.tintColor = tint
            tintView.backgroundColor = tint
        }
    }
    
    var background: UIColor! {
        didSet {
            backgroundView.backgroundColor = background
            previewTheme()
        }
    }
    
    var plain: UIColor! {
        didSet {
            plainView.backgroundColor = plain
            textView.contentTextView.textColor = plain
            previewTheme()
        }
    }
    
    var comment: UIColor! {
        didSet {
            commentView.backgroundColor = comment
            previewTheme()
        }
    }
    
    var identifier: UIColor! {
        didSet {
            identifierView.backgroundColor = identifier
            previewTheme()
        }
    }
    
    var keyword: UIColor! {
        didSet {
            keywordView.backgroundColor = keyword
            previewTheme()
        }
    }
    
    var number: UIColor! {
        didSet {
            numberView.backgroundColor = number
            previewTheme()
        }
    }
    
    var string: UIColor! {
        didSet {
            stringView.backgroundColor = string
            previewTheme()
        }
    }
    
    var exception_: UIColor! {
        didSet {
            exceptionView.backgroundColor = exception_
            previewTheme()
        }
    }
    
    var warning: UIColor! {
        didSet {
            warningView.backgroundColor = warning
            previewTheme()
        }
    }
    
    func makeTheme() -> Theme {
        
        struct CustomTheme: Theme {
                        
            var keyboardAppearance: UIKeyboardAppearance
            
            var barStyle: UIBarStyle
            
            var sourceCodeTheme: SourceCodeTheme
            
            var userInterfaceStyle: UIUserInterfaceStyle
            
            var name: String?
            
            var tintColor: UIColor?
            
            var exceptionColor: UIColor
            
            var warningColor: UIColor
        }
        
        struct CustomSourceCodeTheme: SourceCodeTheme {
            
            let defaultTheme = DefaultSourceCodeTheme()
            
            var themeMaker: ThemeMakerTableViewController
            
            func color(for syntaxColorType: SourceCodeTokenType) -> Color {
                switch syntaxColorType {
                case .comment:
                    return themeMaker.comment
                case .editorPlaceholder:
                    return defaultTheme.color(for: .editorPlaceholder)
                case .identifier:
                    return themeMaker.identifier
                case .keyword:
                    return themeMaker.keyword
                case .number:
                    return themeMaker.number
                case .plain:
                    return themeMaker.plain
                case .string:
                    return themeMaker.string
                }
            }
            
            func globalAttributes() -> [NSAttributedString.Key : Any] {
                
                var attributes = [NSAttributedString.Key: Any]()
                
                attributes[.font] = font
                attributes[.foregroundColor] = color(for: .plain)
                
                return attributes
            }
            
            var lineNumbersStyle: LineNumbersStyle? {
                return defaultTheme.lineNumbersStyle
            }
            
            var gutterStyle: GutterStyle {
                return GutterStyle(backgroundColor: backgroundColor, minimumWidth: defaultTheme.gutterStyle.minimumWidth)
            }
            
            var font: Font {
                return EditorViewController.font.withSize(CGFloat(ThemeFontSize))
            }
            
            var backgroundColor: Color {
                return themeMaker.background
            }
        }
        
        return CustomTheme(keyboardAppearance: (interfaceStyle == .dark ? .dark : (interfaceStyle == .light ? .light : .default)), barStyle: (interfaceStyle == .dark ? .black : .default), sourceCodeTheme: CustomSourceCodeTheme(themeMaker: self), userInterfaceStyle: interfaceStyle, name: name, tintColor: tint, exceptionColor: exception_, warningColor: warning)
    }
    
    // MARK: - UI Elements
    
    // MARK: - Preview
    
    let textView: UITextView = {
        let textStorage = CodeAttributedString()
        textStorage.language = "Python"
        
        let layoutManager = NSLayoutManager()
        textStorage.addLayoutManager(layoutManager)
        
        let container = NSTextContainer()
        layoutManager.addTextContainer(container)
        
        let textView = UITextView(frame: .zero, textContainer: container)
        textView.backgroundColor = .clear
        return textView
    }()
    
    @IBOutlet weak var preview: UIView!
    
    @IBOutlet weak var editorPlaceholder: UIView!
    
    // MARK: - Properties UI Elements
    
    @IBOutlet weak var textField: UITextField!
    
    @IBOutlet weak var interfaceStyleSegmentedControl: UISegmentedControl!
    
    @IBOutlet weak var tintView: UIView!
    
    @IBOutlet weak var backgroundView: UIView!
    
    @IBOutlet weak var plainView: UIView!
    
    @IBOutlet weak var commentView: UIView!
    
    @IBOutlet weak var identifierView: UIView!
    
    @IBOutlet weak var keywordView: UIView!
    
    @IBOutlet weak var numberView: UIView!
    
    @IBOutlet weak var stringView: UIView!
    
    @IBOutlet weak var exceptionView: UIView!
    
    @IBOutlet weak var warningView: UIView!
    
    // MARK: - Actions
    
    fileprivate var colorHandler: ((UIColor) -> ())?
    
    @IBAction func didChangeInterfaceStyle(_ sender: UISegmentedControl) {
        switch sender.selectedSegmentIndex {
        case 0:
            interfaceStyle = .light
        case 1:
            interfaceStyle = .dark
        case 2:
            interfaceStyle = .unspecified
        default:
            break
        }
    }
    
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    func previewTheme(setTheme: Bool = true) {
        
        guard previewAfterSettingProperties else {
            return
        }
        
        if setTheme {
            theme = makeTheme()
        }
        
        let highlightrTheme = HighlightrTheme(themeString: theme.css)
        highlightrTheme.codeFont = EditorViewController.font.withSize(11)
        (textView.textStorage as? CodeAttributedString)?.highlightr.theme = highlightrTheme
        textView.backgroundColor = theme.sourceCodeTheme.backgroundColor
        editorPlaceholder.superview?.backgroundColor = theme.sourceCodeTheme.backgroundColor
    }
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        textView.contentTextView.isEditable = false
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
        
        previewTheme(setTheme: false)
        editorPlaceholder.addSubview(textView)
        
        textView.frame.size = editorPlaceholder.frame.size
        textView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        editorPlaceholder.superview?.backgroundColor = theme.sourceCodeTheme.backgroundColor
        
        tableView.backgroundColor = .systemGroupedBackground
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        theme = makeTheme()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        let theme = makeTheme()
        ConsoleViewController.choosenTheme = theme
        
        if ThemeMakerTableViewController.themes.indices.contains(index) {
            var themes = ThemeMakerTableViewController.themes
            themes.remove(at: index)
            themes.append(theme)
            ThemeMakerTableViewController.themes = themes
        }
        
        (((presentingVC as? UINavigationController)?.viewControllers.last as? ThemeChooserTableViewController) ?? presentingVC as? ThemeChooserTableViewController)?.tableView.reloadData()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        for view in [tintView, backgroundView, plainView, commentView, identifierView, keywordView, numberView, stringView] {
            view?.layer.borderColor = UIColor.systemFill.cgColor
            view?.layer.borderWidth = 1
        }
        
        name = theme.name ?? ""
        
        interfaceStyle = theme.userInterfaceStyle
        tint = theme.tintColor ?? .systemBlue
        
        previewAfterSettingProperties = false
        
        background = theme.sourceCodeTheme.backgroundColor
        plain = theme.sourceCodeTheme.color(for: .plain)
        comment = theme.sourceCodeTheme.color(for: .comment)
        identifier = theme.sourceCodeTheme.color(for: .identifier)
        keyword = theme.sourceCodeTheme.color(for: .keyword)
        number = theme.sourceCodeTheme.color(for: .number)
        string = theme.sourceCodeTheme.color(for: .string)
        
        exception_ = theme.exceptionColor
        warning = theme.warningColor
        
        previewAfterSettingProperties = true
        
        previewTheme()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        textView.frame.size = editorPlaceholder.frame.size
        textView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        presentingVC = presentingViewController
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        func pickColor(color: UIColor, handler: @escaping ((UIColor) -> Void)) {
            
            func handleColor(_ color: UIColor) {
                tableView.cellForRow(at: indexPath)?.contentView.viewWithTag(2)?.backgroundColor = color
                
                handler(color)
            }
            
            func showColorPicker() {
                let view = HRColorPickerView()
                view.color = color
                view.colorMapView.backgroundColor = .clear
                view.colorMapView.setValue(NSNumber(integerLiteral: 1), forKey: "saturationUpperLimit")
                view.brightnessSlider.setValue(NSNumber(integerLiteral: 0), forKey: "brightnessLowerLimit")
                (view.colorInfoView.value(forKey: "_hexColorLabel") as? UILabel)?.textColor = .label
                view.backgroundColor = .systemBackground
                            
                view.handler = handleColor
                
                class ViewController: UIViewController {
                    
                    @objc func close(_ sender: Any) {
                        navigationController?.dismiss(animated: true, completion: nil)
                    }
                }
                
                let vc = ViewController()
                vc.navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: vc, action: #selector(ViewController.close(_:)))
                vc.edgesForExtendedLayout = []
                vc.loadViewIfNeeded()
                
                view.frame = vc.view.frame
                view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                vc.view.addSubview(view)
                
                let navVC = UINavigationController(rootViewController: vc)
                navVC.preferredContentSize = CGSize(width: 480, height: 640)
                navVC.modalPresentationStyle = .formSheet
                
                present(navVC, animated: true, completion: nil)
            }
            
            #if !Xcode11
            if #available(iOS 14.0, *) {
                colorHandler = handleColor
                
                let vc = UIColorPickerViewController()
                vc.selectedColor = color
                vc.supportsAlpha = false
                vc.delegate = self
                present(vc, animated: true, completion: nil)
            } else {
                showColorPicker()
            }
            #else
            showColorPicker()
            #endif
        }
        
        switch indexPath {
        case IndexPath(row: 1, section: 2):
            pickColor(color: tint) { (color) in
                self.tint = color
            }
        case IndexPath(row: 0, section: 3):
            pickColor(color: background) { (color) in
                self.background = color
            }
        case IndexPath(row: 1, section: 3):
            pickColor(color: plain) { (color) in
                self.plain = color
            }
        case IndexPath(row: 2, section: 3):
            pickColor(color: comment) { (color) in
                self.comment = color
            }
        case IndexPath(row: 3, section: 3):
            pickColor(color: identifier) { (color) in
                self.identifier = color
            }
        case IndexPath(row: 4, section: 3):
            pickColor(color: keyword) { (color) in
                self.keyword = color
            }
        case IndexPath(row: 5, section: 3):
            pickColor(color: number) { (color) in
                self.number = color
            }
        case IndexPath(row: 6, section: 3):
            pickColor(color: string) { (color) in
                self.string = color
            }
        case IndexPath(row: 0, section: 4):
            pickColor(color: exception_) { (color) in
                self.exception_ = color
            }
        case IndexPath(row: 1, section: 4):
            pickColor(color: warning) { (color) in
                self.warning = color
            }
        default:
            break
        }
    }
    
    // MARK: - Text field delegate
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        
        defer {
            textField.resignFirstResponder()
        }
        
        return true
    }
    
    func textFieldShouldEndEditing(_ textField: UITextField) -> Bool {
        return true
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        name = textField.text ?? ""
    }
}

#if !Xcode11
@available(iOS 14.0, *)
extension ThemeMakerTableViewController: UIColorPickerViewControllerDelegate {
    
    func colorPickerViewControllerDidSelectColor(_ viewController: UIColorPickerViewController) {
        colorHandler?(viewController.selectedColor)
    }
}
#endif
