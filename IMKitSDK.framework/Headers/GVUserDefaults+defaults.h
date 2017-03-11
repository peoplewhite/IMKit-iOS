//
//  GVUserDefaults+defaults.h
//
//  Created by FUNTEK Inc. on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import <GVUserDefaults/GVUserDefaults.h>
#import "IMDataModels.h"

#define IMUserDefault [GVUserDefaults standardUserDefaults]

@interface GVUserDefaults (defaults)

@property (strong, nonatomic) NSString *clientID;

@property (assign, nonatomic) BOOL firstTimeLaunch;
@property (strong, nonatomic) NSMutableDictionary *currentUser;
//@property (strong, nonatomic) NSMutableDictionary *currentIntallation;

@property (strong, nonatomic) NSString *token;

@property (strong, nonatomic) NSMutableDictionary *messageCache;

@property (strong, nonatomic) NSArray *log;

- (void)write;

@end
