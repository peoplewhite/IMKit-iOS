//
//  GVUserDefaults+defaults.h
//  GiishChat
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import <GVUserDefaults/GVUserDefaults.h>
#import <IMKitSDK/IMDataModels.h>

#define IMUserDefault [GVUserDefaults standardUserDefaults]

@interface GVUserDefaults (defaults)

@property (strong, nonatomic) NSString *clientID;

@property (assign, nonatomic) BOOL firstTimeLaunch;
@property (strong, nonatomic) NSMutableDictionary *currentUser;
@property (strong, nonatomic) NSMutableDictionary *currentIntallation;

@property (strong, nonatomic) NSString *token;
- (void)write;

@end
