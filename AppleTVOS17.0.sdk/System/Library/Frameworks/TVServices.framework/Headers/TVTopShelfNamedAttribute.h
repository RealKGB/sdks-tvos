//
//  TVTopShelfNamedAttribute.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// An object that represents a named attribute with a list of associated values. Instances of this class will be displayed in a stylized manner by the Top Shelf UI.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfNamedAttribute : NSObject

/// The attribute's localized name.
@property (nonatomic, readonly, copy) NSString *name;

/// The attribute's values.
@property (nonatomic, readonly, copy) NSArray<NSString *> *values;

/// Create a named attribute.
- (instancetype)initWithName:(NSString *)name values:(NSArray<NSString *> *)values NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
