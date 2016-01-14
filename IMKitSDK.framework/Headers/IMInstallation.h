//
//  FTInstallations.h
//  GiishChat
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import "IMObject.h"

@interface IMInstallation : IMObject

@property (assign, nonatomic) BOOL createdOnServer;
@property (strong, nonatomic) NSString *deviceToken;
@property (strong, nonatomic) NSString *appName;
@property (strong, nonatomic) NSString *deviceType;
@property (strong, nonatomic) NSString *bundleID;
@property (strong, nonatomic) NSString *appVersion;
@property (assign, nonatomic) int badge;
@property (strong, nonatomic) NSString *timeZone;
@property (strong, nonatomic) NSString *language;

+ (IMInstallation *)currentInstallation;
- (void)setDeviceTokenFromData:(NSData *)deviceToken;
@end
