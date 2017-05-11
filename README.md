# PopPicker提神加薪


## 单选,多选,默认选,各种选

# 用法

### 点击事件处


    PopPickerView *picker = [[PopPickerView alloc] initWithHeaderTitle:@"重复设置" cancelButtonTitle:@"取消" confirmButtonTitle:@"确认"];
    picker.delegate = self;
    picker.dataSource = self;
    picker.allowMultipleSelection = YES;
    picker.needFooterView = YES;
    picker.selectedRows = @[@3];
    [picker show];
    
 ### 代理方法:
 
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
        - (void)PopPickerView:(PopPickerView *)pickerView didConfirmWithItemsAtRows:(NSArray *)rows{}

  
![fuck](http://ww3.sinaimg.cn/large/006tNc79gy1ffhhggrjiij30ku12ataa.jpg)
