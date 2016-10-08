//
//  ChatRoomViewController.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/7.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import "IMMessageTableViewCell.h"
#import "IMViewController.h"

IB_DESIGNABLE
@interface IMMessageViewController : IMViewController

@property (assign, nonatomic) IBInspectable BOOL echoReadToRoom;

@property (strong, nonatomic) IMRoom *room;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *inputViewToBottomDistance;
@property (weak, nonatomic) IBOutlet UIButton *sendMessageBtn;
@property (weak, nonatomic) IBOutlet UIButton *moreOptionBtn;
@property (weak, nonatomic) IBOutlet UIButton *pictureBtn;

@property (weak, nonatomic) IBOutlet UITableView *tableview;
@property (weak, nonatomic) IBOutlet LOTextView *inputTextView;

@property (assign, nonatomic) IBInspectable BOOL showMoreOptionBtn;
@property (assign, nonatomic) IBInspectable BOOL disableTintColor;
//inherit override if need to custom cell
- (NSString *)cellIDForMessage:(IMMessage *)message;
- (IMMessageTableViewCell *)customCellWithIdentifier:(NSString *)cellID message:(IMMessage *)message cell:(IMMessageTableViewCell *)cell indexPath:(NSIndexPath *)indexPath;

- (IBAction)sendMessageBtnPressed:(UIButton *)sender;
- (IBAction)resendBtnPressed:(UIButton *)sender;
- (IBAction)cameraBtnPressed:(UIButton *)sender;
- (IBAction)moreButtonDidPressed:(UIButton *)sender;
- (IBAction)shareRoomWithURLSchemeLastObjectBtnPressed:(UIBarButtonItem *)sender;
- (IBAction)cancelBtnPressed:(LOButton *)sender;

- (void)longPressForMessageAtRowOfIndexPath:(NSIndexPath *)indexPath;

+ (BOOL)handleRemoteNotificationAppdelegateWindow:(UIWindow *)window launchOptions:(NSDictionary *)launchOptions;

@end

@interface UIColor (CompareColor)
- (BOOL)isEqualToColor:(UIColor *)otherColor;
@end
