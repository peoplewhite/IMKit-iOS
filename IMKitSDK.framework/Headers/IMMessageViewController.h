//
//  ChatRoomViewController.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMViewController.h"
#import "IMMessageTableViewCell.h"

//typedef NS_ENUM(NSUInteger, IMInputingType) {
//    IMInputingTypeNone,
//    IMInputingTypeText,
//    IMInputingTypeMore,
//};


@interface IMMessageViewController : IMViewController
@property (strong, nonatomic) IMRoom *room;
//@property (assign, nonatomic) IMInputingType inputingType;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *inputViewToBottomDistance;
@property (weak, nonatomic) IBOutlet UIButton *sendMessageBtn;
@property (weak, nonatomic) IBOutlet UITableView *tableview;
@property (weak, nonatomic) IBOutlet LOTextView *inputTextView;

//inherit override if need to custom cell
- (NSString *)cellIDForMessage:(IMMessage *)message;
- (UITableViewCell *)customCellWithIdentifier:(NSString *)cellID message:(IMMessage *)message cell:(IMMessageTableViewCell *)cell;

- (IBAction)moreButtonDidPressed:(UIButton*)sender;

@end
