//
//  FTMessage.h
//
//  Created by FUNTEK Inc. on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import "IMObject.h"
#import <UIKit/UIKit.h>

UIKIT_EXTERN NSString *const kMessageTypeText;
UIKIT_EXTERN NSString *const kMessageTypeImage;
UIKIT_EXTERN NSString *const kMessageTypeAudio;
UIKIT_EXTERN NSString *const kMessageTypeVideo;
UIKIT_EXTERN NSString *const kMessageTypeGeo;
UIKIT_EXTERN NSString *const kMessageTypeSticker;
UIKIT_EXTERN NSString *const kMessageTypeOther;
UIKIT_EXTERN NSString *const kMessageTypeDelete;
UIKIT_EXTERN NSString *const kMessageTypeDate;

typedef NS_ENUM (int, IMKitMessageType) {
    IMKitMessageTypeText,
    IMKitMessageTypeImage,
    IMKitMessageTypeAudio,
    IMKitMessageTypeVideo,
    IMKitMessageTypeGEO,
    IMKitMessageTypeSticker,
    IMKitMessageTypeOther,
    IMKitMessageTypeDelete,
    IMKitMessageTypeDate
};

typedef NS_ENUM (NSUInteger, IMKitMessageSendingType) {
    IMKitMessageSendingTypeNomal,
    IMKitMessageSendingTypeSending,
    IMKitMessageSendingTypeError,
    IMKitMessageSendingTypeEditing,
};

@class IMRoom;
@class IMClient;
@class IMMessageOption;
@interface IMMessage : IMObject

/**
 *  message content
 */
@property (strong, nonatomic) NSString *message;

/**
 *  a tag for detect message type, example for image , audio ,or text.
 */
@property (strong, nonatomic) NSString *messageType;

/**
 *  message send from/to room
 */
@property (strong, nonatomic) IMRoom *room;

/**
 *  message sender
 */
@property (strong, nonatomic) IMClient *sender;

/**
 *  create on init , for detecting message when received
 */
@property (assign, nonatomic) NSInteger idFromSender;

/**
 *  for message sending error handing , just store in local memory
 */
@property (assign, nonatomic) IMKitMessageSendingType sendingType;

/**
 *  any object for temp store in message,won't be send to backend
 */
@property (strong, nonatomic) id <Ignore> temp;

@property (strong, nonatomic) IMMessageOption *option;

//*****for send message******
- (instancetype)initWithRoom:(IMRoom *)room;

- (void)setMessageWithType:(IMKitMessageType)messageType;

- (void)copyPropertiesFromMessage:(IMMessage *)message;

/**
 *  the same as [IMKitInstance sendMessageInBackground:message];
 */
- (void)send;

- (void)update;

/**
 *  to detect if in the same day
 *
 *  @param message another message
 *
 *  @return if different
 */
- (BOOL)isDifferentDateWithMessage:(IMMessage *)message;

//- (BOOL)didReadFromAnother;
//- (NSUInteger)numberOfReadFromUsers;
@end

@interface IMMessageOption : JSONModel

/**
 *  default to message.message
 */
@property (strong, nonatomic) NSString <Optional> *pushMessage;

/**
 *  default to YES
 */
@property (assign, nonatomic) BOOL needToPush;

/**
 *  if increase room badge to self , default to NO
 */
@property (assign, nonatomic) BOOL badgeIncrease;

/**
 *  default to system sound
 */
@property (strong, nonatomic) NSString <Optional> *pushSound;
@end
