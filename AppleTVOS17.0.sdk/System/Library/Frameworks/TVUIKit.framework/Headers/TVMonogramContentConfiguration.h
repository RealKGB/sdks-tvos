//
//  TVMonogramContentConfiguration.h
//  TVUIKit
//
//  Created by Nathan Wood on 08/04/21.
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TVUIKit/TVUIKitDefines.h>

@class TVMonogramContentTextProperties;

NS_ASSUME_NONNULL_BEGIN

TV_EXTERN API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios) NS_REFINED_FOR_SWIFT
@interface TVMonogramContentConfiguration : NSObject <UIContentConfiguration, NSSecureCoding>

/// Returns the default configuration for a circular monogram cell.
+ (instancetype)cellConfiguration;

/// The image to display.
@property (nonatomic, strong, nullable) UIImage *image;

/// The primary text.
@property (nonatomic, copy, nullable) NSString *text;
/// Additional properties to configure the primary text.
@property (nonatomic, readonly) TVMonogramContentTextProperties *textProperties;

/// The secondary text.
@property (nonatomic, copy, nullable) NSString *secondaryText;
/// Additional properties to configure the secondary text.
@property (nonatomic, readonly) TVMonogramContentTextProperties *secondaryTextProperties;

/// If no image is provided then a monogram is created for display using the personNameComponents.
@property (nonatomic, copy, nullable) NSPersonNameComponents *personNameComponents;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios)
@interface TVMonogramContentView : UIView <UIContentView>

- (instancetype)initWithConfiguration:(TVMonogramContentConfiguration *)configuration NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT;

@property (nonatomic, copy) TVMonogramContentConfiguration *configuration;

/// The content view may display itself in a larger frame when focused.
/// This layout guide can be used to align other elements with the content view image's focused frame.
@property (nonatomic, strong, readonly) UILayoutGuide *focusedFrameGuide;

- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

API_AVAILABLE(tvos(15.0)) API_UNAVAILABLE(macos, watchos, ios) NS_REFINED_FOR_SWIFT
@interface TVMonogramContentTextProperties : NSObject <NSCopying, NSSecureCoding>

/// The font used for the text.
@property (nonatomic, copy) UIFont *font;

/// The color of the text.
@property (nonatomic, copy) UIColor *color;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
