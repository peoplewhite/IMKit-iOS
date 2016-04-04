//
//  IMDB.h
//  RichSDKDemo
//
//  Created by JmeHsieh on 3/20/16.
//  Copyright © 2016 funtek. All rights reserved.
//

#import <Foundation/Foundation.h>


#define IMDBInstance [IMDB sharedInstance]
extern NSString * const IMDB_Collection_Client;
extern NSString * const IMDB_Collection_Room;
extern NSString * const IMDB_Collection_Message;
extern NSString * const IMDB_View_RoomMessagesView;
extern NSString * const IMDB_SecondaryIndex_MessageDate;

@class IMRoom;
@interface IMDB : NSObject

// Shared Object
+ (instancetype)sharedInstance;

// Instance Methods
- (void)saveRooms:(NSArray *)rooms;
- (void)saveMessages:(NSArray *)messags;
- (NSArray *)getAllRooms;
- (NSArray *)queryMessagesForRoom:(IMRoom *)room byDate:(NSDate *)date limit:(NSUInteger)limit;
- (void)resetDatabase;

@end
