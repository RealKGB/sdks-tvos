//
//  TVTopShelfObject.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// An abstract base class for describing Top Shelf items and Top Shelf item collections.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfObject : NSObject

/// The title of the section or item.
@property (nonatomic, copy, nullable) NSString *title;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
