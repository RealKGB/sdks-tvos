//
//  TVTopShelfContentProvider.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TVTopShelfContent;

// The principal class of an extension should subclass this object to provide Top Shelf content.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfContentProvider : NSObject

/// Load Top Shelf content.
///
/// If the completion handler is not called in a timely manner or is called with empty content the system will display the static image instead.
///
/// - parameter completionHandler: You must call this handler and should do so as soon as possible. The handler can be called on any queue.
- (void)loadTopShelfContentWithCompletionHandler:(void (^) (id<TVTopShelfContent> _Nullable content))completionHandler;

/// Can be called from an application or extension to tell the system that your Top Shelf content has changed.
+ (void)topShelfContentDidChange;

@end

NS_ASSUME_NONNULL_END
