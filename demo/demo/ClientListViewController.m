//
//  ClientListViewController.m
//  demo
//
//  Created by Kuo-HsunShih on 2016/4/21.
//  Copyright © 2016年 funtek. All rights reserved.
//

#import "ClientListViewController.h"
#import "UIAlertController+LOAlertController.h"

@interface ClientListViewController ()<IMKitDelegate,UITableViewDelegate,UITableViewDataSource>

@property (strong,nonatomic) NSArray <IMClient*>* clients;
@property (weak, nonatomic) IBOutlet UITableView *tableview;

@end

@implementation ClientListViewController

#pragma mark - Life Cycle

-(void)viewDidLoad{
    [super viewDidLoad];
    
    self.title = [IMClient currentClient].username;
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    IMKitInstance.delegate = self;
    
    if (IMKitInstance.connectStatus == IMKitConnectStatusConnected) {
        [self IMKitDidChatIn];
    }
    
    self.tableview.tableFooterView = [[UIView alloc]initWithFrame:CGRectZero];
}

#pragma mark - IBAction

- (IBAction)logout:(id)sender {
    [UIAlertController showWithController:self cancelTitle:@"cancel" type:UIAlertControllerStyleActionSheet title:nil message:@"Logout" buttons:@[@"YES"] complete:^(NSInteger buttonIndex) {
        if (buttonIndex > -1 ) {
            [IMKitInstance logout];
            [self.navigationController popViewControllerAnimated:YES];
        }
    }];
}

#pragma mark - IMKitDelegate

-(void)IMKitDidChatIn{
    [IMKitInstance clientsListWithOffset:0 Success:^(NSArray<IMClient *> *clients) {
        self.clients = clients;
        [self.tableview reloadData];
        NSLog(@"%d",(int)self.clients.count);
    } failure:^(NSError *err) {
        
    }];
}

#pragma mark - UITableViewDelegate

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.clients.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    IMClient *client = self.clients[indexPath.row];
    
    cell.textLabel.text = client.username ? client.username : client.clientID;
    

    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    
    IMMessageViewController* controller = [[UIStoryboard storyboardWithName:@"IMMain" bundle:nil] instantiateViewControllerWithIdentifier:@"IMMessageViewController"];
    
    IMRoom* room = [[IMRoom alloc]init];
    room.name = @"cool";
    room.thumbnail = [IMClient currentClient].photo;
    
    IMClient *client = self.clients[indexPath.row];
    
    [IMKitInstance createRoom:room WithClientID:client.clientID success:^(IMRoom *room) {
        NSLog(@"%@",room.toDictionary);
        controller.room = room;
        [self.navigationController pushViewController:controller animated:YES];
    } failure:^(NSError *err) {
        
    }];
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    if ([self.clients[indexPath.row].clientID isEqualToString:[IMClient currentClient].clientID]) {
        return 0;
    }
    return 60;
}

- (NSArray <IMClient*>*)clients {
	if (!_clients) {
		_clients = [[NSArray alloc] init];
	}
	return _clients;
}

@end
