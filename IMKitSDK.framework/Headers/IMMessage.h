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

@class IMRoom;
@class IMClient;
@interface IMMessage : IMObject

@property (strong, nonatomic) NSString *message;
@property (strong, nonatomic) NSString *messageType;
@property (strong, nonatomic) IMRoom *room;
@property (strong, nonatomic) IMClient *sender;

- (instancetype)initWithRoom:(IMRoom *)room;

- (void)setMessageWithType:(IMKitMessageType)messageType;

@end
