//
//  ViewController.m
//  demo
//
//  Created by Kuo-HsunShih on 2016/3/13.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import "ViewController.h"

#define passwd @"123123123"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *textField;
@property (strong,nonatomic) UITapGestureRecognizer* tap;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    if ([IMClient currentClient].clientID) {
        [self goClientList];
    }
    
    [self.view addGestureRecognizer:self.tap];
}

- (IBAction)btn:(id)sender {
    if (!self.textField.text.length) {
        return;
    }
    
    IMClient *client = [[IMClient alloc] init];
    client.clientID = self.textField.text;
    client.password = passwd;
    client.username = self.textField.text;
    
    //註冊 & get token
    [IMKitInstance signWithClient:client Success:^(IMClient *client) {
        //login
        NSLog(@"signin success"); //kimuranow
        [IMKitInstance chatinSuccess:^(IMClient *client) {
            NSLog(@"chatin success"); //kimuranow
            [self goClientList];
        } failure:^(NSError *err) {
            NSLog(@"chatin fail error = %@", err.description); //kimuranow
            //
        }];
    } failure:^(NSError *err) {
        NSLog(@"signin fail error = %@", err.description); //kimuranow
        //
    }];
}

- (void)goClientList {
    [self performSegueWithIdentifier:@"goClientList" sender:nil];
}

- (UITapGestureRecognizer *)tap {
	if (!_tap) {
        _tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hideKeyboard)];
    }
	return _tap;
}

-(void)hideKeyboard{
    [self.view endEditing:YES];
}

@end
