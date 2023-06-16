//
//  TVDocumentViewController.h
//  TVMLKit
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TVMLKit/TVApplicationController.h>
#import <TVMLKit/TVViewElement.h>

NS_ASSUME_NONNULL_BEGIN
@class TVDocumentViewController;

extern NSErrorDomain const TVDocumentErrorDomain API_AVAILABLE(tvos(13.0));

typedef NS_ERROR_ENUM(TVDocumentErrorDomain, TVDocumentError) {
    TVDocumentErrorFailed,
    TVDocumentErrorCancelled
} API_AVAILABLE(tvos(13.0));

API_AVAILABLE(tvos(13.0))
typedef NSString* TVDocumentEvent NS_TYPED_EXTENSIBLE_ENUM NS_SWIFT_NAME(TVDocumentViewController.Event);

extern TVDocumentEvent const TVDocumentEventPlay API_AVAILABLE(tvos(13.0));
extern TVDocumentEvent const TVDocumentEventSelect API_AVAILABLE(tvos(13.0));
extern TVDocumentEvent const TVDocumentEventHoldSelect API_AVAILABLE(tvos(13.0));
extern TVDocumentEvent const TVDocumentEventHighlight API_AVAILABLE(tvos(13.0));
extern TVDocumentEvent const TVDocumentEventLoad API_AVAILABLE(tvos(13.0));
extern TVDocumentEvent const TVDocumentEventUnload API_AVAILABLE(tvos(13.0));
extern TVDocumentEvent const TVDocumentEventAppear API_AVAILABLE(tvos(13.0));
extern TVDocumentEvent const TVDocumentEventDisappear API_AVAILABLE(tvos(13.0));

API_AVAILABLE(tvos(13.0))
@protocol TVDocumentViewControllerDelegate <NSObject>
@optional
// When the doucment view controller is going to be updated with a new/updated template
- (void)documentViewControllerWillUpdate:(TVDocumentViewController *)documentViewController;
- (void)documentViewControllerDidUpdate:(TVDocumentViewController *)documentViewController;

// Events for a document update that is requested with a context
- (void)documentViewController:(TVDocumentViewController *)documentViewController didUpdateWithContext:(NSDictionary<NSString *,id> *)context;
- (void)documentViewController:(TVDocumentViewController *)documentViewController didFailUpdateWithError:(NSError *)error;

// Return YES to stop JS from handling the event as well
- (BOOL)documentViewController:(TVDocumentViewController *)documentViewController handleEvent:(TVDocumentEvent)event withElement:(TVViewElement *)element;
@end

API_AVAILABLE(tvos(13.0))
@interface TVDocumentViewController : UIViewController

// Current document context whether its brand new or updated
@property (nonatomic, strong, readonly) NSDictionary<NSString *,id> *documentContext;

// Associated App Controller
@property (nonatomic, weak, readonly) TVApplicationController *appController;

// Delegate for handling document events
@property (nonatomic, weak) id<TVDocumentViewControllerDelegate> delegate;

+ (instancetype)viewControllerWithContext:(NSDictionary<NSString *,id> *)context forAppController:(TVApplicationController *)appController NS_SWIFT_NAME(init(context:for:));
- (void)updateUsingContext:(NSDictionary<NSString *,id> *)context NS_SWIFT_NAME(update(using:));

- (instancetype)init API_UNAVAILABLE(ios, tvos, watchos, macos);
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil API_UNAVAILABLE(ios, tvos, watchos, macos);
- (instancetype)initWithCoder:(NSCoder *)coder API_UNAVAILABLE(ios, tvos, watchos, macos);
@end

NS_ASSUME_NONNULL_END
