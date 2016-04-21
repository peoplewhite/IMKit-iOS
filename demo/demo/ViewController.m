//
//  ViewController.m
//  demo
//
//  Created by Kuo-HsunShih on 2016/3/13.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import "ViewController.h"


@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *textField;

@end

@implementation ViewController

-(void)viewDidLoad{
    [super viewDidLoad];
    
    if ([IMClient currentClient].clientID) {
        [self goClientList];
    }
    
    self.navigationItem.leftBarButtonItem = nil;
}

- (IBAction)btn:(id)sender {
    if (!self.textField.text.length) {
        return;
    }
    
    IMClient *client = [[IMClient alloc] init];
    client.clientID = self.textField.text;
    client.password = @"123123123";
    client.username = self.textField.text;

    //註冊 & get token
    [IMKitInstance signWithClient:client Success:^(IMClient *client) {
        //login
        [IMKitInstance chatinSuccess:^(IMClient *client) {
            [self goClientList];
        } failure:^(NSError *err) {
            //
        }];
    } failure:^(NSError *err) {
        //
    }];
}

-(void)goClientList{
    [self performSegueWithIdentifier:@"goClientList" sender:nil];
}


@end
