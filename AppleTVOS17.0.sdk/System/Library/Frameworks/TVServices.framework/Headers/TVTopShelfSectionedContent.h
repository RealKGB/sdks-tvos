//
//  TVTopShelfSectionedContent.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <TVServices/TVTopShelfContent.h>
#import <TVServices/TVTopShelfItemCollection.h>
#import <TVServices/TVTopShelfSectionedItem.h>

NS_ASSUME_NONNULL_BEGIN

/// An object that represents sectioned content.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfSectionedContent : NSObject <TVTopShelfContent>

/// The content's sections.
@property (nonatomic, readonly, copy) NSArray<TVTopShelfItemCollection<TVTopShelfSectionedItem *> *> *sections;

/// Create a content with the given sections.
- (instancetype)initWithSections:(NSArray<TVTopShelfItemCollection<TVTopShelfSectionedItem *> *> *)sections NS_DESIGNATED_INITIALIZER;

/// Get image size for the given shape.
+ (CGSize)imageSizeForImageShape:(TVTopShelfSectionedItemImageShape)shape;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
