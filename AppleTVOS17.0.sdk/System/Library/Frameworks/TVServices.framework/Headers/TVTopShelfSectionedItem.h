//
//  TVTopShelfSectionedItem.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <TVServices/TVTopShelfItem.h>

NS_ASSUME_NONNULL_BEGIN

/// The shape of an image in the sectioned content style.
typedef NS_ENUM(NSInteger, TVTopShelfSectionedItemImageShape)
{
    /// A 1:1 image.
    TVTopShelfSectionedItemImageShapeSquare,

    /// A 2:3 poster image.
    TVTopShelfSectionedItemImageShapePoster,

    /// A 16:9 image.
    TVTopShelfSectionedItemImageShapeHDTV NS_SWIFT_NAME(hdtv)
} API_AVAILABLE(tvos(13.0)) NS_SWIFT_NAME(TVTopShelfSectionedItem.ImageShape);

/// An object that represents a single item in the sectioned content style.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfSectionedItem : TVTopShelfItem

/// The shape of the item's image.
///
/// The default value is `.square`.
@property (nonatomic) TVTopShelfSectionedItemImageShape imageShape;

/// How far into the item the user has played.
///
/// Must be a number in the range `0...1`.
@property (nonatomic) double playbackProgress;

@end

NS_ASSUME_NONNULL_END
