//
//  AppDelegate.m
//  demo
//
//  Created by Kuo-HsunShih on 2016/3/13.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import "AppDelegate.h"
#import <ChameleonFramework/Chameleon.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [Chameleon setGlobalThemeUsingPrimaryColor:FlatOrange withContentStyle:UIContentStyleContrast];
    
    IMKitInstance.apiKey = @"005398ef62b92519cc526469f92bf399b4ae6bfd";
    IMKitInstance.clientKey = @"5119f2d0b786758c084c09daa54ca605e70f2731";
    NSString *url = @"http://imkit.co:35967";
    
    NSDictionary *options = @{ @"reconnectWait" : @1, @"forceWebsockets" : @YES, };
    
    IMKitInstance.timeout = 3;
    [IMKitInstance connectWithURL:url options:options onConnect:^{
        NSLog(@"connected");
        if ([IMClient currentClient].clientID) {
            [IMKitInstance chatinSuccess:^(IMClient *client) {
                NSLog(@"chatin");
            } failure:^(NSError *err) {
                NSLog(@"fail");
            }];
        }
    }];
    return YES;
}

@end
