//
//  FTObject.h
//  GiishChat
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface IMObject : JSONModel

@property (strong, nonatomic) NSString *url;
@property (strong, nonatomic) NSString *className;
@property (strong, nonatomic) NSString *objectID;

@property (strong, nonatomic) NSString *createdAt;
@property (strong, nonatomic) NSString *updatedAt;

/**
 *  userinfo
 */
@property (strong, nonatomic) NSMutableDictionary *data;
@end

@interface NSString (to8601Date)
- (NSDate *)toDate;
- (NSString *)toStringWithDateFormat:(NSString *)dateFormat;
@end

@interface NSDate (to8601String)
- (NSString *)toString8601;


- (BOOL)isToday;
- (BOOL)isThisWeek;
- (BOOL)isThisMonth;
- (BOOL)isThisYear;
- (BOOL)isThisEra;
- (NSInteger)daysAgo;
- (NSInteger)hoursAgo;
- (NSInteger)minutesAgo;

@end
