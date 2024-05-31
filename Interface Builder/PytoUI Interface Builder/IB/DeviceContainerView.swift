//
//  DeviceContainerView.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 02-07-22.
//

import SwiftUI

@available(iOS 16.0, *) struct DeviceContainerView: View {
    
    class DeviceLayoutManager: ObservableObject {
        
        @Published var deviceLayout: DeviceLayout {
            didSet {
                objectWillChange.send()
            }
        }
        
        @Published var orientation: InterfaceModel.Orientation {
            didSet {
                objectWillChange.send()
            }
        }
        
        init(deviceLayout: DeviceLayout, orientation: InterfaceModel.Orientation) {
            self.deviceLayout = deviceLayout
            self.orientation = orientation
        }
    }
    
    struct ContainerNavigationController: UIViewControllerRepresentable {
        
        var navigationController: UINavigationController
        
        func makeUIViewController(context: Context) -> some UIViewController {
            navigationController
        }
        
        func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
        }
    }
    
    var containerNavigationController: ContainerNavigationController
    
    @ObservedObject var deviceLayoutManager: DeviceLayoutManager
    
    @State var backgroundColor: UIColor?
    
    @Environment(\.colorScheme) var colorScheme: ColorScheme
    
    var body: some View {
        ZStack {
            
            ZStack {
                Color(backgroundColor ?? .systemBackground).overlay {
                    Color(.label).opacity(0.1)
                }
                
                containerNavigationController
                    .padding((deviceLayoutManager.orientation == .portrait || deviceLayoutManager.deviceLayout.userInterfaceIdiom == .pad) ? .top : [], deviceLayoutManager.deviceLayout.statusBarHeight)
                    .padding(.bottom, deviceLayoutManager.deviceLayout.homeIndicatorHeight)
                    .padding((deviceLayoutManager.orientation == .landscape && deviceLayoutManager.deviceLayout.hasNotch) ? .leading : [], deviceLayoutManager.deviceLayout.statusBarHeight)
                
                    .padding((deviceLayoutManager.orientation == .landscape && deviceLayoutManager.deviceLayout.hasNotch) ? .trailing : [], deviceLayoutManager.deviceLayout.statusBarHeight)
                
            }.onReceive(containerNavigationController.navigationController.viewControllers.first!.view.publisher(for: \.backgroundColor)) { value in
                if value == UIColor.systemBackground {
                    backgroundColor = nil
                } else {
                    backgroundColor = value
                }
            }
        }
    }
}
