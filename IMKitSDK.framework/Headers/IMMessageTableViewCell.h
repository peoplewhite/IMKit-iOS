//
//  ChatRoomCollectionViewCell.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/8.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMTableViewCell.h"
#import "IMKit.h"
#import "IMBubbleView.h"
@interface IMMessageTableViewCell : IMTableViewCell

@property (assign,nonatomic) BOOL showDate;

@property (strong ,nonatomic) IMMessage* message;



@property (assign, nonatomic) IMKitMessageSendingType cellType;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *indicator;
@property (weak, nonatomic) IBOutlet LOTextView *subTextView;
@property (weak, nonatomic) IBOutlet LOLabel *readLabel;
@property (weak, nonatomic) IBOutlet LOButton *errorButton;
@property (weak, nonatomic) IBOutlet IMBubbleView *bubbleView;

@property (weak, nonatomic) IBOutlet LOLabel *dateLabel;

@end
