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
    IMKitInstance.apiKey = @"005398ef62b92519cc526469f92bf399b4ae6bfd";
    IMKitInstance.clientKey = @"5119f2d0b786758c084c09daa54ca605e70f2731";
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
