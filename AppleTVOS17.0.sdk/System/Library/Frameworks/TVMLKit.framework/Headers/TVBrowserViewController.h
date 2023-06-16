//
//  TVFullScreenBrowserShelfViewController.h
//  TVMLKit
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TVMLKit/TVDocumentViewController.h>
#import <TVMLKit/TVViewElement.h>

NS_ASSUME_NONNULL_BEGIN

@class TVBrowserViewController;

API_AVAILABLE(tvos(13.0))
// Provides animations to and from a full screen browser
@interface TVBrowserTransitionAnimator : NSObject <UIViewControllerAnimatedTransitioning>
@end

API_AVAILABLE(tvos(13.0))
@protocol TVBrowserViewControllerDataSource <NSObject>

// Provides the document view controller to be used for a particular child of the originating full screen browser
- (nullable TVDocumentViewController *)browserViewController:(TVBrowserViewController *)browserViewController documentViewControllerForElement:(TVViewElement *)viewElement;

@end

API_AVAILABLE(tvos(13.0))
@protocol TVBrowserViewControllerDelegate <NSObject>

@optional

- (void)browserViewController:(TVBrowserViewController *)browserViewController willCenterOnViewElement:(TVViewElement *)viewElement;

- (void)browserViewController:(TVBrowserViewController *)browserViewController didCenterOnViewElement:(TVViewElement *)viewElement;

@end

API_AVAILABLE(tvos(13.0))
@interface TVBrowserViewController : UIViewController

// The view element that the full screen browser is constructed from
@property (nonatomic, strong, readonly) TVViewElement *viewElement;

// Adjusts the corner radius on the individual full screen browser items.
// Defaults to 36.0
@property (nonatomic, assign) CGFloat cornerRadius;

// Adjusts the spacing between full screen browser items.
// Defaults to 20.0
@property (nonatomic, assign) CGFloat interitemSpacing;

// Adjusts the insets from full screen that represents the full screen browser item.
// Defaults to UIEdgeInsetsMake(32.0, 120.0, 0.0, 120.0)
@property (nonatomic, assign) UIEdgeInsets maskInset;

// Gets/sets the full screen browser item that's supposed to be centered based on its view element
@property (nonatomic, strong) TVViewElement *centeredViewElement;

// For delegate call backs
@property (nonatomic, weak) id<TVBrowserViewControllerDelegate> delegate;

// To provide data to the full screen browser
@property (nonatomic, weak) id<TVBrowserViewControllerDataSource> dataSource;

// Create a full screen browser from a view element unless its a view element that's not supported
+ (nullable instancetype)viewControllerForElement:(TVViewElement *)viewElement NS_SWIFT_NAME(init(viewElement:));

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
