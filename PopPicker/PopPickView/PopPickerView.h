//
//  PopPickerView.h
//  PopPicker
//
//  Created by Zin_戦 on 2017/5/11.
//  Copyright © 2017年 Zin_戦. All rights reserved.
//

#import <UIKit/UIKit.h>
@class PopPickerView;
@protocol PopPickerViewDataSource <NSObject>

@required
/* 有多少行 */
- (NSInteger)numberOfRowsInPickerView:(PopPickerView *)pickerView;

@optional
/*
 至少实现下面一个方法
 PopPickerView:(PopPickerView *)pickerView
 attributedTitleForRow:(NSInteger)row 优先级最高
 */

/* attributed picker item title for each row */
- (NSAttributedString *)PopPickerView:(PopPickerView *)pickerView
               attributedTitleForRow:(NSInteger)row;

/* picker item title for each row */
- (NSString *)PopPickerView:(PopPickerView *)pickerView
               titleForRow:(NSInteger)row;

/* picker item image for each row */
- (UIImage *)PopPickerView:(PopPickerView *)pickerView imageForRow:(NSInteger)row;

@end

@protocol PopPickerViewDelegate <NSObject>

@optional

/** delegate method for picking one item */
- (void)PopPickerView:(PopPickerView *)pickerView
didConfirmWithItemAtRow:(NSInteger)row;

/*
 delegate method for picking multiple items,
 implement this method if allowMultipleSelection is YES,
 rows is an array of NSNumbers
 */
- (void)PopPickerView:(PopPickerView *)pickerView
didConfirmWithItemsAtRows:(NSArray *)rows;

/** delegate method for canceling */
- (void)PopPickerViewDidClickCancelButton:(PopPickerView *)pickerView;
@end

@interface PopPickerView : UIView<UITableViewDelegate,UITableViewDataSource>

/** Initialize the picker view with titles
 @param headerTitle The title of header
 @param cancelButtonTitle The title for cancelButton
 @param confirmButtonTitle The title for confirmButton
 */
- (id)initWithHeaderTitle:(NSString *)headerTitle
        cancelButtonTitle:(NSString *)cancelButtonTitle
       confirmButtonTitle:(NSString *)confirmButtonTitle;

/** show the picker */
- (void)show;

/** return previously selected row, in array of NSNumber form. */
- (NSArray *)selectedRows;

/** set pre-selected rows, rows should be array of NSNumber. */
- (void)setSelectedRows: (NSArray *)rows;

@property id<PopPickerViewDelegate> delegate;

@property id<PopPickerViewDataSource> dataSource;

/** whether to show footer (including confirm and cancel buttons), default NO */
@property BOOL needFooterView;

/** whether allow tap background to dismiss the picker, default YES */
@property BOOL tapBackgroundToDismiss;

/** whether allow selection of multiple items/rows, default NO, if this
 property is YES, then footerView will be shown */
@property BOOL allowMultipleSelection;

/** picker header background color */
@property (nonatomic, strong) UIColor *headerBackgroundColor;

/** picker header title color */
@property (nonatomic, strong) UIColor *headerTitleColor;

/** picker cancel button background color */
@property (nonatomic, strong) UIColor *cancelButtonBackgroundColor;

/** picker cancel button normal state color */
@property (nonatomic, strong) UIColor *cancelButtonNormalColor;

/** picker cancel button highlighted state color */
@property (nonatomic, strong) UIColor *cancelButtonHighlightedColor;

/** picker confirm button background color */
@property (nonatomic, strong) UIColor *confirmButtonBackgroundColor;

/** picker confirm button normal state color */
@property (nonatomic, strong) UIColor *confirmButtonNormalColor;

/** picker confirm button highlighted state color */
@property (nonatomic, strong) UIColor *confirmButtonHighlightedColor;

/** picker's animation duration for showing and dismissing*/
@property CGFloat animationDuration;

@end
