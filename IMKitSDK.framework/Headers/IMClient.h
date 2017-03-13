//
//  FTClient.h
//
//  Created by FUNTEK Inc. on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import "IMObject.h"

@interface IMClient : IMObject
@property (strong, nonatomic) NSString *clientID;
@property (strong, nonatomic) NSString *token;
@property (strong, nonatomic) NSString *email;
@property (strong, nonatomic) NSString *password;
@property (strong, nonatomic) NSString *emailVerified;
@property (strong, nonatomic) NSString *photo;
@property (strong, nonatomic) NSArray *roomIDs;
@property (strong, nonatomic) NSString *username;

@property (strong, nonatomic) NSString *chatinAt;
@property (strong, nonatomic) NSArray *room;
@property (assign, nonatomic) NSUInteger totalBadge;

+ (IMClient *)currentClient;
@end
