//
//  TVAppProfileDescriptor.h
//  TVServices Framework
//
//  Copyright © 2022 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVServices/TVServicesDefines.h>


NS_ASSUME_NONNULL_BEGIN

/*!
 @class         TVAppProfileDescriptor
 @abstract      A simple model object that describes a profile within an app that has multiple user profiles.
 */
API_DEPRECATED("User Management capability get-current-user is no longer supported. Please use runs-as-current-user-with-user-independent-keychain and kSecUseUserIndependentKeychain for sharing keychain items across users.", tvos(13.0, 16.0))
@interface TVAppProfileDescriptor : NSObject <NSCopying, NSSecureCoding>

/*!
 @method        initWithName:
 @abstract      Initializes a new descriptor with a name.
 */
- (instancetype)initWithName:(NSString *)name;

/*!
 @property      name
 @abstract      The user visible label of the profile.
 */
@property (nonatomic, copy) NSString *name;

@end

NS_ASSUME_NONNULL_END

