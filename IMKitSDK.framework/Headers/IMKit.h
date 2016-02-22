//
//  IMKit.h
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <JSONModel/JSONModel.h>
#import "IMDataModels.h"

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
@property (assign, nonatomic) IMKitConnectStatus connectStatus;

@property (weak, nonatomic) id <IMKitDelegate> delegate;
@property (strong, nonatomic, readonly) NSString *token;
@property (strong, nonatomic) NSString *deviceToken;
@property (weak, nonatomic, readonly) NSString *clientID;
@property (assign, nonatomic, readonly) BOOL firstTimeLaunch;

//request timeout , default to 5 second
@property (assign, nonatomic) NSInteger timeout;

//apiKey & clientKey to connect with backend
@property (strong, nonatomic) NSString *apiKey;
@property (strong, nonatomic) NSString *clientKey;

+ (instancetype)shareInstance;

- (void)connectWithURL:(NSString *)url options:(NSDictionary *)option onConnect:(void (^)(void))onConnect;

#pragma mark - query

- (void)queryWithClass:(Class)objectClass offset:(NSUInteger)offset limit:(NSUInteger)limit sort:(NSString *)sort Success:(void (^)(NSArray *response))success failure:(void (^)(NSError *err))failure;

#pragma mark - client

//list all clients
- (void)clientsListWithOffset:(int)offset Success:(void (^)(NSArray <IMClient *> *clients))success failure:(void (^)(NSError *err))failure;

- (void)signUpWithClientID:(IMClient *)client Success:(void (^)(IMClient *client))success failure:(void (^)(NSError *err))failure DEPRECATED_MSG_ATTRIBUTE("signUpWithClient:Success:failure: instead");
- (void)signUpWithClient:(IMClient *)client Success:(void (^)(IMClient *client))success failure:(void (^)(NSError *err))failure;
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
- (void)badgeSuccess:(void (^)(IMBadge *badge))success failure:(void (^)(NSError *err))failure;
#pragma mark - room

- (void)createRoom:(IMRoom *)room Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)joinRoom:(IMRoom *)room Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)createRoom:(IMRoom *)room WithClientID:(NSString *)ClientID duplicate:(BOOL)duplicate Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)roomWithRoomID:(NSString *)roomID Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)messageWithRoom:(IMRoom *)room offset:(NSUInteger)offset limit:(int)limit Success:(void (^)(NSMutableArray <IMMessage *> *messages))success failure:(void (^)(NSError *err))failure;
- (void)roomListSuccess:(void (^)(NSMutableArray <IMRoom *> *rooms))success failure:(void (^)(NSError *err))failure;

#pragma mark - message
/**
 *  send message to room
 */
- (void)sendMessage:(IMMessage *)message Success:(void (^)(IMMessage *messages))success failure:(void (^)(NSError *err))failure;
/**
 * tell backend message received
 * and rezero badge to room at the same time
 *
 */
- (void)updateReadTimeWithRoom:(IMRoom *)room DEPRECATED_MSG_ATTRIBUTE("updateReadTimeWithRoom:echoToRoom: instead");

/**
 *  tell backend message received
 *  and rezero badge to room at the same time
 *
 *  @param echo : if echo to others that current client's read time refreshed
 */
- (void)updateReadTimeWithRoom:(IMRoom *)room echoToRoom:(BOOL)echo;

#pragma mark - file

/**
 *  get file with name , will download file everytime called
 */
- (void)getFileWithName:(NSString *)filename complete:(void (^)(NSError *err, NSData *data))complete;

/**
 *  get file with name
 *  @param fromCache : Force download and override cache by "fromCache = NO" , Or check if exists in cache .
 */
- (void)getFileWithName:(NSString *)filename fromCache:(BOOL)fromCache Success:(void (^)(NSData *data))success failure:(void (^)(NSError *err))failure;

- (void)uploadFileWithImage:(UIImage *)image Room:(IMRoom *)room isPublic:(BOOL)isPublic Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure;
/**
 *  uploadFileWithData
 *
 *  @param data     NSData file
 *  @param room     send to room
 *  @param isPublic public for client which not in room
 *  @param success  response success
 *  @param failure  response fail
 */
- (void)uploadFileWithData:(NSData *)data type:(NSString *)type Room:(IMRoom *)room isPublic:(BOOL)isPublic Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure;
- (void)uploadFileWithData:(NSData *)data type:(NSString *)type Room:(IMRoom *)room isPublic:(BOOL)isPublic progress:(void (^)(CGFloat progress))progress Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure;
@end

@protocol IMKitDelegate <NSObject>

@optional

/*
 * NSNotifications
 *
 * IMKitDidChatIn
 * IMKitDidUpdateRooms
 * IMKitDidUpdateReadTimeWithRoom
 * IMKitDidJoinedWithRoom
 * IMKitDidReceiveMessage
 * IMKitDidChangeConnectStatus
 *
 */

- (void)IMKitDidChatIn;

- (BOOL)IMKitWillStartLoadingMessageWithRoom:(IMRoom *)room;
- (void)IMKitDidEndLoadingMessageWithRoom:(IMRoom *)room;

/**
 *  called when receive message , include send from self
 */
- (void)IMKitDidReceiveMessage:(IMMessage *)message;
/**
 *  called when receive message witch send from other device
 */
- (void)IMKitDidReceiveMessageFromOthers:(IMMessage *)message;

/**
 *  called when sending message changes type
 */
- (void)IMKitDidChangeMessageSendingType:(IMMessage *)message;

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
 *  TODO
 */
//- (void)IMKitDidUpdateMessages:(NSMutableArray <IMMessage *> *)messages;

/**
 *  called when joined a room
 */
- (void)IMKitDidJoinedWithRoom:(IMRoom *)room;

/**
 *  called when connect status changed
 */
- (void)IMKitDidChangeConnectStatus:(IMKitConnectStatus)status WithMessage:(NSString *)message;

@end
