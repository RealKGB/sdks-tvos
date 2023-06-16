//
//  TVTopShelfItemCollection.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <TVServices/TVTopShelfObject.h>

@class TVTopShelfItem;

NS_ASSUME_NONNULL_BEGIN

/// An object that represents a collection of Top Shelf items that can be displayed in a section.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfItemCollection<Item : TVTopShelfItem *> : TVTopShelfObject

/// The collection's items.
@property (nonatomic, readonly, copy) NSArray<Item> *items;

/// Create a collection of items.
- (instancetype)initWithItems:(NSArray<Item> *)items;

@end

NS_ASSUME_NONNULL_END
