//
//  TVTopShelfInsetContent.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <TVServices/TVTopShelfContent.h>

NS_ASSUME_NONNULL_BEGIN

@class TVTopShelfItem;

/// An object that represents inset banner content.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfInsetContent : NSObject <TVTopShelfContent>

/// The content's items.
@property (nonatomic, readonly, copy) NSArray<TVTopShelfItem *> *items;

/// The size of images in the inset content style.
@property (nonatomic, readonly, class) CGSize imageSize;

/// Create a content with the given items.
- (instancetype)initWithItems:(NSArray<TVTopShelfItem *> *)items;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
