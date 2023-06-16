//
//  TVCollectionViewFullScreenCell.h
//  TVUIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((visibility("default"))) API_AVAILABLE(tvos(13.0)) API_UNAVAILABLE(ios, watchos)
@interface TVCollectionViewFullScreenCell : UICollectionViewCell

@property (nonatomic, readonly) CGFloat cornerRadius; // corner radius applied to this cell
@property (nonatomic, readonly) UIEdgeInsets contentBleed; // the amount by which the content bleeds out of bounds
@property (nonatomic, readonly) CGFloat parallaxOffset; // the amount in pixels that the background should be shifted from the center

@property (nonatomic, readonly) CGFloat normalizedPosition; // 0 = current. less than 0 = positioned on the left. more than 0 = positioned on right
@property (nonatomic, readonly) CGFloat maskAmount; // the amount of masking that should be applied on the cell, defaults to 1.0

@property (nonatomic, readonly) UIView *maskedBackgroundView; // background view that performs the parallax effect
@property (nonatomic, readonly) UIView *maskedContentView; // the content that will be given focus

- (void)maskAmountWillChange:(CGFloat)nextMaskAmount;
- (void)maskAmountDidChange;

- (void)normalizedPositionWillChange:(CGFloat)nextNormalizedPosition;
- (void)normalizedPositionDidChange;

@end

NS_ASSUME_NONNULL_END
