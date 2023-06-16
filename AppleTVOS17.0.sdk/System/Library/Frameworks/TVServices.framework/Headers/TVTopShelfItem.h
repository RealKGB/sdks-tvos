//
//  TVTopShelfItem.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <TVServices/TVTopShelfObject.h>

NS_ASSUME_NONNULL_BEGIN

@class TVTopShelfAction;
@class TVTopShelfNamedAttribute;

/// A set of traits that allows the system to request variants of an image.
typedef NS_OPTIONS(NSUInteger, TVTopShelfItemImageTraits)
{
    /// Variant used when the device is running in 1x.
    TVTopShelfItemImageTraitScreenScale1x = 1 << 0,

    /// Variant used when the device is running in 2x.
    TVTopShelfItemImageTraitScreenScale2x = 2 << 0
} API_AVAILABLE(tvos(13.0)) NS_SWIFT_NAME(TVTopShelfItem.ImageTraits);

/// The base class for describing Top Shelf content to the system.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfItem : TVTopShelfObject

/// The item's unique identifier.
///
/// This identifier must be unique in the set of items you return to the system.
@property (nonatomic, readonly, copy) NSString *identifier;

/// The action performed when the user wants to play an item.
///
/// In sectioned and inset content styles this action is used when the user presses the play/pause button when the item is focused. In carousel content styles this is the first button shown to the user.
@property (nonatomic, strong, nullable) TVTopShelfAction *playAction;

/// The action performed when the user wants to see more information about an item.
///
/// In sectioned and inset content styles this action is used when the user selects the item. In carousel content styles this is the second button shown to the user.
@property (nonatomic, strong, nullable) TVTopShelfAction *displayAction;

/// The date when the user will no longer be able to access the item.
@property (nonatomic, copy, nullable) NSDate *expirationDate;

/// Set an image URL for the given combination of traits.
///
/// In sectioned and inset content styles this is the image displayed for the item. In carousel content styles this image is displayed before the preview video.
- (void)setImageURL:(nullable NSURL *)imageURL forTraits:(TVTopShelfItemImageTraits)traits;

/// Get the image URL for the given combination of traits.
///
/// In sectioned and inset content styles this is the image displayed for the item. In carousel content styles this image is displayed before the preview video.
- (nullable NSURL *)imageURLForTraits:(TVTopShelfItemImageTraits)traits;

/// Create an item with a unique identifier.
///
/// This identifier must be unique in the set of items you return to the system.
- (instancetype)initWithIdentifier:(NSString *)identifier NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
