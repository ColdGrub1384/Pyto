//
//  Run_Python_Script.h
//  Run Python Script
//
//  Created by Emma Labbé on 14-01-21.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

#import <Automator/AMBundleAction.h>
#import <AppKit/AppKit.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>
#import <OSLog/OSLog.h>
#import <CoreFoundation/CoreFoundation.h>

@interface Run_Python_Script : AMBundleAction <NSTextFieldDelegate>

@property (nonatomic, weak) IBOutlet NSTextField *scriptNameText;

@property (nonatomic, weak) IBOutlet NSTextField *argumentsTextField;

@property (nonatomic, strong) NSURL *selectedScript;

@property (nonatomic, strong) NSString *output;

@property (nonatomic, strong) dispatch_semaphore_t semaphore;

- (IBAction) chooseFile:(NSButton *)sender;

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo;

@end
