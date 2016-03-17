//
//  ViewController.m
//  demo
//
//  Created by Kuo-HsunShih on 2016/3/13.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import "ViewController.h"
#import <ChameleonFramework/Chameleon.h>
#import "customRLVC.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *textField;

@end

@implementation ViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    if ([IMClient currentClient].clientID) {
        [self nextWithAnimation:NO];
    }
}

- (IBAction)btn:(id)sender {
    IMClient *client = [[IMClient alloc] init];
    client.clientID = self.textField.text;
    client.password = @"123123123";
    client.username = self.textField.text;
    client.photo = @"https://scontent-tpe1-1.xx.fbcdn.net/hphotos-xpf1/v/t1.0-9/11695010_918364614868649_445191402297426844_n.jpg?oh=cb3961a7f9e962c8f20b0c072e98d178&oe=574C3E02";
    
    //註冊 & get token
    [IMKitInstance signWithClient:client Success:^(IMClient *client) {
        //login
        [IMKitInstance chatinSuccess:^(IMClient *client) {
            [ self nextWithAnimation:YES];
        } failure:^(NSError *err) {
            NSLog(@"error1");
        }];
    } failure:^(NSError *err) {
        NSLog(@"error sign error");
        //
    }];
}

- (void)nextWithAnimation:(BOOL)animation {
    
    customRLVC *controller = [[UIStoryboard storyboardWithName:@"IMMain" bundle:nil] instantiateViewControllerWithIdentifier:@"IMRoomListViewController"];
    [self.navigationController pushViewController:controller animated:animation];
    
    [self.navigationController setStatusBarStyle:UIStatusBarStyleLightContent];
}

@end
