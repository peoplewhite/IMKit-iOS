//
//  ViewController.m
//  demo
//
//  Created by Kuo-HsunShih on 2016/3/13.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import "ViewController.h"


@interface ViewController ()<IMRoomViewControllerDelegate>
@property (weak, nonatomic) IBOutlet UITextField *textField;

@end

@implementation ViewController

-(void)viewDidLoad{
    [super viewDidLoad];
    
    if ([IMClient currentClient].clientID) {
        [self nextWithAnimation:NO];
    }
}

- (IBAction)btn:(id)sender {
    IMClient *client = [[IMClient alloc] init];
    client.clientID = self.textField.text;
    client.password = @"123123123";
    client.username = self.textField.text;

    //註冊 & get token
    [IMKitInstance signWithClient:client Success:^(IMClient *client) {
        //login
        [IMKitInstance chatinSuccess:^(IMClient *client) {
            [self nextWithAnimation:YES];
        } failure:^(NSError *err) {
            //
        }];
    } failure:^(NSError *err) {
        //
    }];
}

- (void)nextWithAnimation:(BOOL)animation {
    IMRoomViewController *controller = [[UIStoryboard storyboardWithName:@"IMMain" bundle:nil] instantiateViewControllerWithIdentifier:@"IMRoomViewController"];
    controller.delegate = self;
    [self.navigationController pushViewController:controller animated:animation];
}

#pragma mark - IMRoomListViewControllerDelegate

-(void)IMRoomViewControllerDidPop{
    [IMKitInstance logout];
}


@end
