//
//  IMKit.h
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <JSONModel/JSONModel.h>
#import "IMDataModels.h"

typedef NS_ENUM(int,IMKitConnectStatus) {
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

- (void)signUpWithClientID:(IMClient *)client Success:(void (^)(IMClient *client))success failure:(void (^)(NSError *err))failure;

//to receive room messages
- (void)chatinSuccess:(void (^)(IMClient *client))success failure:(void (^)(NSError *err))failure;
//stop receive room messages
- (void)chatOutSuccess:(void (^)(void))success failure:(void (^)(NSError *err))failure;
- (void)logout;

#pragma mark - badge
- (void)badgeSuccess:(void (^)(IMBadge* badge))success failure:(void (^)(NSError *err))failure;
#pragma mark - room

- (void)createRoom:(IMRoom *)room Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)joinRoom:(IMRoom *)room Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)createRoom:(IMRoom *)room WithClientID:(NSString *)ClientID duplicate:(BOOL)duplicate Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)roomWithRoomID:(NSString *)roomID Success:(void (^)(IMRoom *room))success failure:(void (^)(NSError *err))failure;
- (void)messageWithRoom:(IMRoom *)room offset:(NSUInteger)offset limit:(int)limit Success:(void (^)(NSMutableArray <IMMessage *> *messages))success failure:(void (^)(NSError *err))failure;
- (void)roomListSuccess:(void (^)(NSMutableArray <IMRoom *> *rooms))success failure:(void (^)(NSError *err))failure;

#pragma mark - message
//send message to room
- (void)sendMessage:(IMMessage *)message Success:(void (^)(IMMessage *messages))success failure:(void (^)(NSError *err))failure;
//tell backend message received
- (void)updateReadTimeWithRoom:(IMRoom *)room;

#pragma mark - file
/**
 *  uploadFileWithData
 *
 *  @param data     NSData file
 *  @param room     send to room
 *  @param isPublic public for client which not in room
 *  @param success  response success
 *  @param failure  response fail
 */
- (void)getFileWithName:(NSString *)filename complete:(void (^)(NSError *err, NSData *data))complete;


- (void)uploadFileWithImage:(UIImage*)image Room:(IMRoom *)room isPublic:(BOOL)isPublic Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure ;
- (void)uploadFileWithData:(NSData *)data type:(NSString *)type Room:(IMRoom *)room isPublic:(BOOL)isPublic Success:(void (^)(IMFile *file))success failure:(void (^)(NSError *err))failure ;

@end

@protocol IMKitDelegate <NSObject>

@optional

/*
 * notifications
 *
 * IMKitDidChatIn
 * IMKitDidUpdateRooms
 * IMKitDidUpdateReadTimeWithRoom
 * IMKitDidJoinedWithRoom
 * IMKitDidReceiveMessage
 * IMKitDidChangeConnectStatus
 *
 */
- (void)IMKitDidChatIn:(IMKit *)model;

- (BOOL)IMKit:(IMKit *)model willStartLoadingMessageWithRoom:(IMRoom *)room;
- (void)IMKit:(IMKit *)model didEndLoadingMessageWithRoom:(IMRoom *)room;

- (void)IMKit:(IMKit *)model didReceiveMessage:(IMMessage *)message;
- (void)IMKit:(IMKit *)model didUpdateReadTimeWithRoom:(IMRoom *)room;

- (void)IMKit:(IMKit *)model didUpdateRooms:(NSMutableArray <IMRoom *> *)rooms;
- (void)IMKit:(IMKit *)model didUpdateRoom:(IMRoom*)room;
- (void)IMKit:(IMKit *)model didUpdateMessages:(NSMutableArray <IMMessage *> *)messages;

- (void)IMKit:(IMKit *)model didJoinedWithRoom:(IMRoom *)room;
- (void)IMKit:(IMKit *)model didChangeConnectStatus:(IMKitConnectStatus)status WithMessage:(NSString *)message;
//- (void)IMKit:(IMKit *)model didUploadWithProgress:(NSProgress *)progress;

@end
