//
//  IMBadge.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/1/20.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface IMBadge : JSONModel
@property (assign, nonatomic) int total;
@property (strong, nonatomic) NSDictionary *badgeDict;
@end
