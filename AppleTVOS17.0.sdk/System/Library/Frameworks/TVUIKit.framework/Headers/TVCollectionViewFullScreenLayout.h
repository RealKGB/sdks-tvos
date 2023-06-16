//
//  TVCollectionViewFullScreenLayout.h
//  TVUIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((visibility("default"))) API_AVAILABLE(tvos(13.0)) API_UNAVAILABLE(ios, watchos)
@interface TVCollectionViewFullScreenLayoutAttributes  : UICollectionViewLayoutAttributes

// The amount of corner radius to apply to the cell
@property (nonatomic, assign) CGFloat cornerRadius;

// How much of the content bleeds into the masked portions
@property (nonatomic, assign) UIEdgeInsets contentBleed;

// How far away is this layout attribute from being the center cell in the context
// of the collection view
// [left] -1 <-> 0 [center] <-> 1 [right]
@property (nonatomic, assign) CGFloat normalizedPosition;

// Amount of mask to apply
@property (nonatomic, assign) CGFloat maskAmount;

// How far away (point value) should the parallax background be away from the center of the cell
@property (nonatomic, assign) CGFloat parallaxOffset;

@end

__attribute__((visibility("default"))) API_AVAILABLE(tvos(13.0)) API_UNAVAILABLE(ios, watchos)
@protocol TVCollectionViewDelegateFullScreenLayout <UICollectionViewDelegate>
@optional

// Notifies when a cell is going to be the center cell.
- (void)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout willCenterCellAtIndexPath:(NSIndexPath *)indexPath;

// Notifies when the cell has completed transition to become the center cell.
- (void)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout didCenterCellAtIndexPath:(NSIndexPath *)indexPath;

@end

__attribute__((visibility("default"))) API_AVAILABLE(tvos(13.0)) API_UNAVAILABLE(ios, watchos)
@interface TVCollectionViewFullScreenLayout : UICollectionViewLayout

// Corner radius to apply to the cell, defaults to 36.0.
@property (nonatomic, assign) CGFloat cornerRadius;

// Distance between each cell, defaults to 20.0.
@property (nonatomic, assign) CGFloat interitemSpacing;

// How much slower should the background move relative to the foreground, defaults to 0.8.
@property (nonatomic, assign) CGFloat parallaxFactor;

// Use this to change the mask amount for cells. The layout will automatically
// update the mask amount on the layout attributes of the cells and apply them
// progress to masked state [0..1] = unmaksed (fullscreen) -> masked
// Default value is 1.0
@property (nonatomic, assign) CGFloat maskAmount;

// Used to create a fake mask around the cell that can be showcased to be revealed, defaults to UIEdgeInsetsMake(32.0, 120.0, 0.0, 120.0)
@property (nonatomic, assign) UIEdgeInsets maskInset;

// Current index path based on current content offset
@property (nonatomic, strong, readonly, nullable) NSIndexPath *centerIndexPath;

// Indicates if the center index path is changing to a new one.
@property (nonatomic, readonly, getter=isTransitioningToCenterIndexPath) BOOL transitioningToCenterIndexPath;

@end

NS_ASSUME_NONNULL_END
