//
//  TVMediaItemContentConfiguration.h
//  TVUIKit
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TVUIKit/TVUIKitDefines.h>

typedef NS_ENUM(NSInteger, TVMediaItemContentTextTransform) {
    TVMediaItemContentTextTransformNone,
    TVMediaItemContentTextTransformUppercase,
    TVMediaItemContentTextTransformLowercase,
    TVMediaItemContentTextTransformCapitalized
} API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios) NS_REFINED_FOR_SWIFT;

@class TVMediaItemContentTextProperties, TVMediaItemContentBadgeProperties;

NS_ASSUME_NONNULL_BEGIN

TV_EXTERN API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios) NS_REFINED_FOR_SWIFT
@interface TVMediaItemContentConfiguration : NSObject <UIContentConfiguration, NSSecureCoding>

/// Returns the default configuration for a wide cell with a 16:9 aspect ratio.
+ (instancetype)wideCellConfiguration;

/// The image to display.
@property (nonatomic, strong, nullable) UIImage *image;

/// The primary text.
@property (nonatomic, copy, nullable) NSString *text;
/// Additional properties to configure the primary text.
@property (nonatomic, readonly) TVMediaItemContentTextProperties *textProperties;

/// The secondary text.
@property (nonatomic, copy, nullable) NSString *secondaryText;
/// Additional properties to configure the secondary text.
@property (nonatomic, readonly) TVMediaItemContentTextProperties *secondaryTextProperties;

/// Playback progress to display. Value is clamped between 0.0 and 1.0.
@property (nonatomic, assign) float playbackProgress;

/// Optional text to display in a badge that is displayed in the top corner of the content.
@property (nonatomic, copy, nullable) NSString *badgeText;
/// Additional properties to configure the badge.
@property (nonatomic, copy) TVMediaItemContentBadgeProperties *badgeProperties;

/// The overlayView will be placed above the image, and automatically resized to fill frame.
/// Enable preservesSuperviewLayoutMargins to inherit layoutMargins.
@property (nonatomic, strong, nullable) UIView *overlayView;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

TV_EXTERN API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios)
@interface TVMediaItemContentView : UIView <UIContentView>

- (instancetype)initWithConfiguration:(TVMediaItemContentConfiguration *)configuration NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT;

@property (nonatomic, copy) TVMediaItemContentConfiguration *configuration NS_REFINED_FOR_SWIFT;

/// The content view may display itself in a larger frame when focused.
/// This layout guide can be used to align other elements with the image view's focused frame.
@property (nonatomic, strong, readonly) UILayoutGuide *focusedFrameGuide;

- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

TV_EXTERN API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios) NS_REFINED_FOR_SWIFT
@interface TVMediaItemContentTextProperties : NSObject <NSCopying, NSSecureCoding>

/// The font used for the text.
@property (nonatomic, copy) UIFont *font;

/// The color of the text.
@property (nonatomic, copy) UIColor *color;

/// A transform that is applied to the text before it is displayed.
@property (nonatomic) TVMediaItemContentTextTransform transform;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

TV_EXTERN API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios) NS_REFINED_FOR_SWIFT
@interface TVMediaItemContentBadgeProperties : NSObject <NSCopying, NSSecureCoding>

/// Returns the properties for a default styled badge.
+ (instancetype)defaultBadgeProperties;

/// Returns the properties for a badge representing live content.
+ (instancetype)liveContentBadgeProperties;

/// The background tint color of the badge.
@property (nonatomic, copy) UIColor *backgroundColor;

/// The font used for the badge text.
@property (nonatomic, copy) UIFont *font;

/// The color of the badge text.
@property (nonatomic, copy) UIColor *color;

/// A transform that is applied to the badge text before it is displayed.
@property (nonatomic, assign) TVMediaItemContentTextTransform transform;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

TV_EXTERN API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios)
@interface NSCollectionLayoutSection (TVMediaItemContentConfiguration)

/// Creates an orthogonal scrolling section with the system default sizing and spacing.
+ (NSCollectionLayoutSection *)orthogonalLayoutSectionForMediaItems;

@end

NS_ASSUME_NONNULL_END
