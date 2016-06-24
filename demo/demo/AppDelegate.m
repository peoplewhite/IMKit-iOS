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
//    IMKitInstance.apiKey = @"24138f798c35e3a3019bd7a3dfa4bda1ce97139f";
//    IMKitInstance.clientKey = @"0e0c671fada0c586485cf59fd5769d4f905c9b85";
//    NSString *url = @"http://ec2-54-249-117-19.ap-northeast-1.compute.amazonaws.com:35968";

    //行政
    IMKitInstance.apiKey = @"cb6185b563a5d041691baad1756bd92a9477b3ff";
    IMKitInstance.clientKey = @"d9e66a01a8dd63ef44c284af5862329e8cea6e09";
    NSString *url = @"http://ec2-54-249-117-19.ap-northeast-1.compute.amazonaws.com:35967";
    
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
