//
//  IMKit.h
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <JSONModel/JSONModel.h>
#import "IMDataModels.h"
#import "IMDB.h"

typedef NS_ENUM (int, IMKitConnectStatus) {
    IMKitConnectStatusConnected,
    IMKitConnectStatusDisconnect,
    IMKitConnectStatusError,
    IMKitConnectStatusReconnect,
    IMKitConnectStatusReconnectAttempt,
    IMKitConnectStatusReconnecting,
    IMKitConnectStatusReconnectfailed,
};

#define IMKitInstance [IMKit shareInstance]

@protocol IMKitDelegate;
@interface IMKit : JSONModel
@property (assign, nonatomic) BOOL isPausedLoadingRoomData;
@property (assign, nonatomic) IMKitConnectStatus connectStatus;

@property (strong, nonatomic) NSMutableArray <IMRoom *> *chatRooms;
@property (strong, nonatomic) NSMutableArray <IMMessage *> *messages;

@property (strong, nonatomic) IMBadge *badge;

@property (weak, nonatomic) id <IMKitDelegate> delegate;
@property (strong, nonatomic, readonly) NSString *token;
@property (strong, nonatomic) NSString *deviceToken;
@property (weak, nonatomic, readonly) NSString *clientID;
@property (assign, nonatomic, readonly) BOOL firstTimeLaunch;

@property (assign, nonatomic) int roomCountLimit;

//request timeout , default to 5 second
@property (assign, nonatomic) NSInteger timeout;

//apiKey & clientKey to connect with backend
@property (strong, nonatomic) NSString *apiKey;
@property (strong, nonatomic) NSString *clientKey;

@property (assign, nonatomic) BOOL log;
@property (assign, nonatomic) BOOL printLog;

+ (instancetype)shareInstance;

- (void)connectWithURL:(NSString *)url options:(NSDictionary *)option onConnect:(void (^)(void))onConnect;

- (void)logDictionaryIfNeeded:(id)obj;

#pragma mark - query

- (void)queryWithClass:(Class)objectClass offset:(NSUInteger)offset limit:(NSUInteger)limit sort:(NSString *)sort Success:(void (^)(NSArray *response))success failure:(void (^)(NSError *err))failure;

#pragma mark - client

//list all clients
- (void)clientsListWithOffset:(int)offset Success:(void (^)(NSArray <IMClient *> *clients))success failure:(void (^)(NSError *err))failure;

- (void)signWithClient:(IMClient *)client Success:(void (^)(IMClient *client))success failure:(void (^)(NSError *err))failure;
//to receive room messages
- (void)chatinSuccess:(void (^)(IMClient *client))success failure:(void (^)(NSError *err))failure;
//stop receive room messages
- (void)chatOutSuccess:(void (^)(void))success failure:(void (^)(NSError *err))failure;

/**
 *  update token if possiable, or auto update at signup instead
 */
- (void)updateDeviceTokenIfPossiable:(NSData *)deviceToken;

- (void)logout;

#pragma mark - badge
/**
 *  get all badge of rooms , costs more backend resouce than badgeTotalSuccess:
 */
- (void)badgeSuccess:(void (^)(IMBadge *badge))success failure:(void (^)(NSError *err))failure;

/**
 *  get just total badge number
 */
- (void)badgeTotalSuccess:(void (^)(int total))success failure:(void (^)(NSError *err))failure;

#pragma mark - room

- (void)joinRoomWithID:(NSString *)roomID;

- (void)createRoom:(IMRoom *)room Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)joinRoom:(IMRoom *)room Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;

//create room with client, return old room if exists
- (void)createRoom:(IMRoom *)room WithClientID:(NSString *)ClientID duplicate:(BOOL)duplicate Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure DEPRECATED_MSG_ATTRIBUTE("duplicate: DEPRECATED");

- (void)createRoom:(IMRoom *)room WithClientID:(NSString *)clientID success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;

//create room with client
- (void)forceCreateRoom:(IMRoom *)room WithClient:(NSString *)clientID success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;

- (void)roomWithRoomID:(NSString *)roomID Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)messageWithRoom:(IMRoom *)room offset:(NSUInteger)offset limit:(int)limit Success:(void (^)(NSMutableArray <IMMessage *> *messages))success failure:(void (^)(NSError *err))failure;
- (void)messageWithRoom:(IMRoom *)room pinDate:(NSString *)pinDate limit:(int)limit success:(void (^)(NSMutableArray <IMMessage *> *messages))success failure:(void (^)(NSError *err))failure;

/**
 *  get room list
 *
 *  @param success success block
 *  @param failure failure block
 *  @param complete complete block
 *  @response in callback with block, and update all rooms in IMKitDidUpdateRooms:
 */
- (void)roomListInBackground;
- (void)roomListSuccess:(void (^)(NSArray <IMRoom *> *rooms))success failure:(void (^)(NSError *err))failure;
- (void)roomListWithOffset:(NSInteger)offset limit:(NSInteger)limit Success:(void (^)(NSArray <IMRoom *> *rooms))success failure:(void (^)(NSError *err))failure;
- (void)roomListWithOffset:(NSInteger)offset limit:(NSInteger)limit Success:(void (^)(NSArray <IMRoom *> *rooms))success failure:(void (^)(NSError *err))failure complete:(void (^)(NSError *err, NSArray <IMRoom *> *rooms))complete;
- (void)roomListForUbeeAgentWithSuccess:(void (^)(NSArray <IMRoom *> *rooms))success
                                failure:(void (^)(NSError *err))failure
                               complete:(void (^)(NSError *err, NSArray <IMRoom *> *rooms))complete;


//
- (void)roomListKeepUpdateingToNewestComplete:(void (^)(NSError *err, NSArray <IMRoom *> *rooms))complete;
- (void)roomListLastMessageTime:(NSDate *)lastMessageTime Offset:(NSUInteger)offset limit:(NSUInteger)limit Success:(void (^)(NSArray <IMRoom *> *rooms))success failure:(void (^)(NSError *err))failure complete:(void (^)(NSError *err, NSArray <IMRoom *> *rooms))complete;

- (void)archiveRoom:(IMRoom *)room Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;

#pragma mark - message

/**
 *  send message to room
 */
- (void)sendMessageInBackground:(IMMessage *)message;

/**
 *  send message to room
 */
- (void)sendMessage:(IMMessage *)message Success:(void (^)(IMMessage *messages))success failure:(void (^)(NSError *err))failure;

/**
 *  tell backend message received
 *  and rezero badge to room at the same time
 *
 *  @param echo : set NO to just update badge with room
 */
- (void)updateReadTimeWithRoom:(IMRoom *)room echoToRoom:(BOOL)echo;

- (void)updateMessage:(IMMessage *)message Success:(void (^)(IMMessage *message))success failure:(void (^)(NSError *err))failure;

- (void)unseenCountAfterLastSeenDate:(NSString *)lastSeenDate
                   beforeMessageDate:(NSString *)messageDate
                              inRoom:(IMRoom *)room
                             success:(void (^)(int unseenCount))success
                             failure:(void (^)(NSError *err))failure;

#pragma mark - file

/**
 *  get file with name , will download file everytime called
 */
- (void)getFileWithName:(NSString *)filename complete:(void (^)(NSError *err, NSData *data))complete DEPRECATED_MSG_ATTRIBUTE("plz use getFileWithName:progress:success:failure:");

/**
 *  get file with name
 *  @param fromCache : Force download and override cache by "fromCache = NO" , Or check if exists in cache .
 */
- (void)getFileWithName:(NSString *)filename fromCache:(BOOL)fromCache success:(void (^)(NSData *data))success failure:(void (^)(NSError *err))failure DEPRECATED_MSG_ATTRIBUTE("plz use getFileWithName:progress:success:failure:");

/**
 *  get file with name , fromCache default to @YES
 */
- (void)getFileWithName:(NSString *)filename progress:(void (^)(CGFloat progress))progress success:(void (^)(NSData *data))success failure:(void (^)(NSError *err))failure;
/**
 *  get file with name ,
 *  @param fromCache : Force download and override cache by "fromCache = NO" , Or check if exists in cache .
 */
- (void)getFileWithName:(NSString *)filename fromCache:(BOOL)fromCache progress:(void (^)(CGFloat progress))progress success:(void (^)(NSData *data))success failure:(void (^)(NSError *err))failure;

- (NSURLSessionDataTask *)uploadFileWithImage:(UIImage *)image Room:(IMRoom *)room isPublic:(BOOL)isPublic Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure;
/**
 *  uploadFileWithData
 *
 *  @param data     NSData file
 *  @param room     send to room
 *  @param isPublic public for client which not in room
 *  @param success  response success
 *  @param failure  response fail
 */
- (NSURLSessionDataTask *)uploadFileWithData:(NSData *)data type:(NSString *)type Room:(IMRoom *)room isPublic:(BOOL)isPublic Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure;
- (NSURLSessionDataTask *)uploadFileWithData:(NSData *)data type:(NSString *)type Room:(IMRoom *)room isPublic:(BOOL)isPublic progress:(void (^)(CGFloat progress))progress Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure;

#pragma mark - url scheme

- (NSString *)urlType;
- (NSString *)urlStringForScheme;
- (NSString *)appIDOnStore;

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end

//NSNotification
UIKIT_EXTERN NSString *const kIMKitDidChatIn;
UIKIT_EXTERN NSString *const kIMKitDidUpdateRoom;
UIKIT_EXTERN NSString *const kIMKitDidUpdateRooms;
UIKIT_EXTERN NSString *const kIMKitDidUpdateReadTimeWithRoom;
UIKIT_EXTERN NSString *const kIMKitDidJoinedWithRoom;
UIKIT_EXTERN NSString *const kIMKitDidReceiveMessage;
UIKIT_EXTERN NSString *const kIMKitDidReceiveMessageFromOthers;
UIKIT_EXTERN NSString *const kIMKitDidUpdateMessage;
UIKIT_EXTERN NSString *const kIMKitDidUpdateBadge;
UIKIT_EXTERN NSString *const kIMKitDidChangeMessageSendingType;
UIKIT_EXTERN NSString *const kIMKitDidChangeConnectStatus;

#pragma mark - Delegate
@protocol IMKitDelegate <NSObject>

@optional

- (void)IMKitDidChatIn;

- (BOOL)IMKitWillStartLoadingMessageWithRoom:(IMRoom *)room;
- (void)IMKitDidEndLoadingMessageWithRoom:(IMRoom *)room;

/**
 *  called when receive message , include send from self
 */
- (void)IMKitDidReceiveMessage:(IMMessage *)message;
/**
 *  called when receive message witch send from other device , and others client
 */
- (void)IMKitDidReceiveMessageFromOthers:(IMMessage *)message;

/**
 *  message updated by someone
 */
- (void)IMKitDidUpdateMessage:(IMMessage *)message;

/**
 *  TODO
 */
//- (void)IMKitDidUpdateMessages:(NSMutableArray <IMMessage *> *)messages;

/**
 *  called when sending message changes type
 */
- (void)IMKitDidChangeMessageSendingType:(IMMessage *)message;

- (void)IMKitDidUpdateBadge:(IMBadge *)badge;

/**
 *  called when other device update read time in room
 */
- (void)IMKitDidUpdateReadTimeWithRoom:(IMRoom *)room;

/**
 *  called when room updated, example for got new message.
 */
- (void)IMKitDidUpdateRooms:(NSMutableArray <IMRoom *> *)rooms;
- (void)IMKitDidUpdateRoom:(IMRoom *)room;

/**
 *  called when joined a room
 */
- (void)IMKitDidJoinedWithRoom:(IMRoom *)room;

/**
 *  called when connect status changed
 */
- (void)IMKitDidChangeConnectStatus:(IMKitConnectStatus)status WithMessage:(NSString *)message;

@end
