//
//  IMDB.h
//  Pods
//
//  Created by Kuo-HsunShih on 2016/4/26.
//
//

#import <Foundation/Foundation.h>
#import "IMRoom.h"
#import "IMMessage.h"

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
- (void)saveRooms:(NSArray <IMRoom*>*)rooms;
- (void)saveMessages:(NSArray *)messags;
- (NSMutableArray <IMRoom*>*)getAllRooms;
- (NSMutableArray <IMMessage*>*)queryMessagesForRoom:(IMRoom *)room byDate:(NSDate *)date limit:(NSUInteger)limit;
- (void)resetDatabase;

@end