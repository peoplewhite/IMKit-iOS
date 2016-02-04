//
//  FTRoom.h
//  GiishChat
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import "IMObject.h"
@class IMMessage;
@class IMClient;
@interface IMRoom : IMObject
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *thumbnail;
@property (assign, nonatomic) BOOL isPublic;

@property (strong, nonatomic) NSMutableArray <NSMutableDictionary *> *client;
@property (strong, nonatomic) NSMutableArray <NSMutableDictionary *> *message;
@property (strong, nonatomic) NSDictionary *readTime;
@property (strong, nonatomic) NSString *lastMessageTime;
@property (strong, nonatomic) IMClient *sender;
@property (assign, nonatomic) int badge;

@property (strong, nonatomic,readonly) IMClient *anyOtherClient;
@end
