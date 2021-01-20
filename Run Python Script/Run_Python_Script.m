//
//  Run_Python_Script.m
//  Run Python Script
//
//  Created by Emma Labbé on 14-01-21.
//  Copyright © 2021 Adrian Labbé. All rights reserved.
//

#import "Run_Python_Script.h"

@implementation Run_Python_Script

@synthesize output;

- (void)awakeFromNib {
    [super awakeFromNib];
    
    if ([self.parameters.allKeys containsObject:@"Arguments"]) {
        self.argumentsTextField.stringValue = self.parameters[@"Arguments"];
    }
    
    if ([self.parameters.allKeys containsObject:@"Script"]) {
        NSData *bookmark = (NSData *)[self.parameters objectForKey:@"Script"];
        NSURL *url = [NSURL URLByResolvingBookmarkData:bookmark options:0 relativeToURL:NULL bookmarkDataIsStale:NULL error:NULL];
        self.selectedScript = url;
        
        if (url) {
            self.scriptNameText.stringValue = url.lastPathComponent;
        }
    }
}

void notificationCallback(CFNotificationCenterRef center, void * observer, CFStringRef name, const void * object, CFDictionaryRef userInfo) {
    
    Run_Python_Script *self = (__bridge Run_Python_Script *)observer;

    self.output = [[NSPasteboard pasteboardWithName:@"Pyto.Automator"] stringForType:NSPasteboardTypeString];
    dispatch_semaphore_signal(self.semaphore);
        
    return;
}

- (IBAction) chooseFile:(NSButton *)sender {
    NSOpenPanel *panel = [NSOpenPanel openPanel];
    panel.canChooseDirectories = NO;
    panel.canChooseFiles = YES;
    panel.allowsMultipleSelection = NO;
    panel.allowedContentTypes = @[UTTypePythonScript];
    [panel runModal];
    
    if (panel.URLs.count == 0) {
        self.scriptNameText.stringValue = @"No selected file";
        self.selectedScript = NULL;
        return;
    }
    
    NSURL *url = panel.URLs.firstObject;
    [url startAccessingSecurityScopedResource];
    
    self.selectedScript = url;
    self.scriptNameText.stringValue = url.lastPathComponent;
    
    [self updateParameters];
}

- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo {
    
    NSData *script;
    
    if ([self.parameters.allKeys containsObject:@"Script"]) {
        script = [self.parameters objectForKey:@"Script"];
    } else {
        return NULL;
    }
    
    NSString *bundleID = [self.bundle.bundleIdentifier stringByReplacingOccurrencesOfString:@".Run-Python-Script" withString:@""];
        
    NSURL *pytoURL = [NSWorkspace.sharedWorkspace URLForApplicationWithBundleIdentifier:bundleID];
    
    NSString *urlToOpen = @"pyto://automator/?bookmark=";
    urlToOpen = [urlToOpen stringByAppendingString:[script base64EncodedStringWithOptions:0]];
    
    NSString *arguments;
    
    if ([self.parameters.allKeys containsObject:@"Arguments"] && ![[self.parameters objectForKey:@"Arguments"] isEqualToString:@""]) {
        arguments = [self.parameters objectForKey:@"Arguments"];
    } else if ([input isKindOfClass: [NSArray class]] && ((NSArray *)input).count > 0) {
        
        NSData *json = [NSJSONSerialization dataWithJSONObject:(NSArray *)input options:NSJSONWritingPrettyPrinted error:NULL];
        arguments = [json base64EncodedStringWithOptions:0];
    } else {
        arguments = @"";
    }
    
    if (![arguments isEqualToString:@""]) {
        urlToOpen = [urlToOpen stringByAppendingString:@"&arguments="];
        urlToOpen = [urlToOpen stringByAppendingString:[arguments stringByAddingPercentEncodingWithAllowedCharacters:NSCharacterSet.URLQueryAllowedCharacterSet]];
    }
    
    NSWorkspaceOpenConfiguration *config = [[NSWorkspaceOpenConfiguration alloc] init];
    config.activates = NO;
    config.hides = YES;
    
    [NSWorkspace.sharedWorkspace openURLs:@[[NSURL URLWithString:urlToOpen]] withApplicationAtURL:pytoURL configuration:config completionHandler:^(NSRunningApplication * _Nullable app, NSError * _Nullable error) {
        
        [app hide];
    }];
    
    CFNotificationCenterRef center = CFNotificationCenterGetDarwinNotifyCenter();
    CFNotificationCenterAddObserver(center, (__bridge const void *)(self), notificationCallback, CFSTR("pyto.receivedOutput"), NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
    
    self.semaphore = dispatch_semaphore_create(0);
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    
    CFNotificationCenterRemoveObserver(center, (__bridge const void *)(self), CFSTR("pyto.receivedOutput"), NULL);
    
    return self.output;
}

- (void)updateParameters {
    
    if (self.selectedScript != NULL) {
        [self.parameters setObject:[self.selectedScript bookmarkDataWithOptions:0 includingResourceValuesForKeys:NULL relativeToURL:NULL error:NULL] forKey:@"Script"];
    } else if ([self.parameters.allKeys containsObject:@"Script"]) {
        [self.parameters removeObjectForKey:@"Script"];
    }
    
    [self.parameters setObject:self.argumentsTextField.stringValue forKey:@"Arguments"];
    
    [super updateParameters];
}

- (void)controlTextDidChange:(NSNotification *)obj {
    [self updateParameters];
}

@end
