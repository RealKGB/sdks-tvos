//
//  TVTopShelfCarouselContent.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVServices/TVTopShelfContent.h>

NS_ASSUME_NONNULL_BEGIN

@class TVTopShelfCarouselItem;

/// The style of the carousel content.
typedef NS_ENUM(NSInteger, TVTopShelfCarouselContentStyle)
{
    /// Carousel content that shows action buttons.
    TVTopShelfCarouselContentStyleActions,

    /// Carousel content that shows action buttons and details about the item.
    TVTopShelfCarouselContentStyleDetails
} NS_SWIFT_NAME(TVTopShelfCarouselContent.Style) API_AVAILABLE(tvos(13.0));

/// An object that represents carousel content.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfCarouselContent : NSObject <TVTopShelfContent>

/// The content's style.
@property (nonatomic, readonly) TVTopShelfCarouselContentStyle style;

/// The content's items.
@property (nonatomic, readonly, copy) NSArray<TVTopShelfCarouselItem *> *items;

/// Create a content with the given style and items.
- (instancetype)initWithStyle:(TVTopShelfCarouselContentStyle)style items:(NSArray<TVTopShelfCarouselItem *> *)items NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
