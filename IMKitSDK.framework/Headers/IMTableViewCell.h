//
//  IMChatCollectionViewCell.h
//  IMKitSDK
//
//  Created by Kuo-HsunShih on 2016/3/8.
//  Copyright © 2016年 Funtek. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IMTableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UIImageView *photoImageView;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

@property (weak, nonatomic) IBOutlet UILabel *dateLabel;

@end
