//
//  FTMessage.h
//  GiishChat
//
//  Created by Kuo-HsunShih on 2015/9/24.
//  Copyright © 2015年 Funtek. All rights reserved.
//

#import "IMObject.h"

#define kMessageTypeText @"text"
#define kMessageTypeImage @"image"
#define kMessageTypeAudio @"audio"
#define kMessageTypeVideo @"video"
#define kMessageTypeGeo @"GEO"
#define kMessageTypeSticker @"sticker"
#define kMessageTypeOther @"other"

typedef NS_ENUM (int, IMKitMessageType) {
    IMKitMessageTypeText,
    IMKitMessageTypeImage,
    IMKitMessageTypeAudio,
    IMKitMessageTypeVideo,
    IMKitMessageTypeGEO,
    IMKitMessageTypeSticker,
    IMKitMessageTypeOther,
};

typedef NS_ENUM(NSUInteger, IMKitMessageSendingType) {
    IMKitMessageSendingTypeNomal,
    IMKitMessageSendingTypeSending,
    IMKitMessageSendingTypeError,
};

@class IMRoom;
@class IMClient;
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
@property (strong, nonatomic) id<Ignore>temp;


- (instancetype)initWithRoom:(IMRoom *)room;

- (void)setMessageWithType:(IMKitMessageType)messageType;


- (void)copyPropertiesFromMessage:(IMMessage*)message;
@end
