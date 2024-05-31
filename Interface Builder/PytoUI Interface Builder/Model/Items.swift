import UIKit

/// Items that can be placed from the library. You can add your own.
@available(iOS 16.0, *) public var Items: [InterfaceBuilderView] = [
    VerticalStackView(),
    HorizontalStackView(),
    ScrollView(),
    Spacer(),
    Divider(),
    Label(),
    Button(),
    ImageView(),
    ActivityIndicatorView(),
    Switch(),
    Slider(),
    Stepper(),
    SegmentedControl(),
    TextField(),
    TextView(),
    InsetGroupedTableView(),
    GroupedTableView(),
    PlainTableView()
]

var PytoUIClassMap: [String : String] {
    [
        "StackViewContainer": "StackView",
        "InterfaceBuilderButton": "Button",
        "UILabel": "Label",
        "UISlider": "Slider",
        "UIStepper": "Stepper",
        "UISwitch": "Switch",
        "UITextField": "TextField",
        "InterfaceBuilderImageView": "ImageView",
        "InterfaceBuilderSegmentedControl": "SegmentedControl",
        "UITextView": "TextView",
        "UITableView": "TableView",
    ]
}

/// Get the name of the PytoUI class from the given UIKit class.
///
/// - Parameters:
///     - cls: The UIKit class.
///
/// - Returns: The name of the PytoUI class corresponding the UIKit class.
public func PytoUIClassName(from cls: UIView.Type) -> String {
    let name = NSStringFromClass(cls).components(separatedBy: ".").last ?? ""
    return PytoUIClassMap[name] ?? "View"
}
