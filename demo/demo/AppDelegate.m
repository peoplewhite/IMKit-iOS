//
//  AppDelegate.m
//  demo
//
//  Created by Kuo-HsunShih on 2016/3/13.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [self connectIMKit];
    
    //app launched from remote notification
    [IMMessageViewController handleRemoteNotificationAppdelegateWindow:self.window launchOptions:launchOptions];

    [self setNavigationBar];
    [self setNotification];
    
    return YES;
}

#pragma mark - notification

- (void)setNotification {
    [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];
    [[UIApplication sharedApplication] registerForRemoteNotifications];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [IMKitInstance updateDeviceTokenIfPossiable:deviceToken];
}

#pragma mark - UI

- (void)setNavigationBar {
    [UINavigationBar appearance].tintColor = [UIColor redColor];
}

#pragma mark - IMKit

-(void)connectIMKit{
    IMKitInstance.apiKey = @"af1a66e8ed65dd86673bc66ef207b9026bc04a0b";
    IMKitInstance.clientKey = @"18f87d684e858a6171e950a8a777ffb0c583c998";
    NSString *url = @"http://imkit.co:35967";
    
    NSDictionary *options = @{ @"reconnectWait" : @1, @"forceWebsockets" : @YES, };
    
    IMKitInstance.timeout = 3;
    [IMKitInstance connectWithURL:url options:options onConnect:^{
        NSLog(@"connected");
        if ([IMClient currentClient].clientID) {
            [IMKitInstance chatinSuccess:^(IMClient *client) {
                NSLog(@"%@",client.toDictionary);
                NSLog(@"chatin");
            } failure:^(NSError *err) {
                NSLog(@"fail");
            }];
        }
    }];

}

@end
