//
//  ViewController.m
//  PopPicker
//
//  Created by Zin_戦 on 2017/5/11.
//  Copyright © 2017年 Zin_戦. All rights reserved.
//

#import "ViewController.h"
#import "PopPickerView.h"
@interface ViewController ()<PopPickerViewDelegate,PopPickerViewDataSource>
@property(nonatomic, strong) NSArray   *weeks;
//时间选择Arr
@property(strong,nonatomic)NSMutableArray *weeksArr;

@end

@implementation ViewController

- (NSAttributedString *)PopPickerView:(PopPickerView *)pickerView attributedTitleForRow:(NSInteger)row
{
    NSAttributedString *att = [[NSAttributedString alloc]
                               initWithString:self.weeks[row]
                               attributes:@{
                                            NSFontAttributeName:[UIFont fontWithName:@"Avenir-Light" size:18.0]
                                            }];
    return att;
}

- (NSString *)PopPickerView:(PopPickerView *)pickerView titleForRow:(NSInteger)row{
    return self.weeks[row];
}

- (NSInteger)numberOfRowsInPickerView:(PopPickerView *)pickerView{
    return self.weeks.count;
}

//单选时调用的代理方法
- (void)PopPickerView:(PopPickerView *)pickerView didConfirmWithItemAtRow:(NSInteger)row{
         NSLog(@"%@ is chosen!", self.weeks[row]);
}
//多选时调用的
- (void)PopPickerView:(PopPickerView *)pickerView didConfirmWithItemsAtRows:(NSArray *)rows{

        self.weeksArr = [[NSMutableArray alloc]initWithCapacity:self.weeks.count];
        for(NSNumber *n in rows){
            NSInteger row = [n integerValue];
            NSLog(@"%@ is chosen!!!", self.weeks[row]);
            //加载所选重复时间
            [self.weeksArr addObject:self.weeks[row]];
        }
        NSLog(@"%@",self.weeksArr);
 
}
- (void)PopPickerViewDidClickCancelButton:(PopPickerView *)pickerView{
        NSLog(@"Canceled.");
}
- (void)viewDidLoad {
    [super viewDidLoad];
    self.weeks = @[@"周一", @"周二", @"周三", @"周四", @"周五",@"周六",@"周日"];
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(100, 100, 100, 50);
    btn.backgroundColor = [UIColor orangeColor];
    [btn addTarget:self action:@selector(clicked:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
}

- (void)clicked:(UIButton *)sender{

    //重复
    PopPickerView *picker = [[PopPickerView alloc] initWithHeaderTitle:@"重复设置" cancelButtonTitle:@"取消" confirmButtonTitle:@"确认"];
    picker.delegate = self;
    picker.dataSource = self;
    picker.allowMultipleSelection = YES;
    picker.needFooterView = YES;
    picker.selectedRows = @[@3];
    [picker show];

}



@end
