//
//  FTClient.h
//  GiishChat
//
//  Created by Kuo-HsunShih on 2015/9/24.
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

@property (strong, nonatomic) NSArray *room;

+ (IMClient *)currentClient;
@end
