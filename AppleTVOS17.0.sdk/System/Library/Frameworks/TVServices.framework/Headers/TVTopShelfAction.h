//
//  TVTopShelfAction.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVServices/TVServicesDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// An object that describes a user action in the Top Shelf.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfAction : NSObject

/// The URL that will be opened when the action is selected.
@property (nonatomic, copy, readonly) NSURL *URL;

/// Create an action.
- (instancetype)initWithURL:(NSURL *)URL NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
