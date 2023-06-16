//
//  TVUserManager.h
//  TVServices Framework
//
//  Copyright © 2022 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVServices/TVServicesDefines.h>
#import <TVServices/TVAppProfileDescriptor.h>


NS_ASSUME_NONNULL_BEGIN

/*
 User identifiers are ASCII strings of 64 characters or less. They should never be shown to the user in UI, as they will be meaningless to the user.  These identifiers should be compared case-sensitively (e.g., isEqual: is just fine).
 */
typedef NSString *TVUserIdentifier NS_SWIFT_BRIDGED_TYPEDEF API_DEPRECATED("User Management capability get-current-user is no longer supported. Please use runs-as-current-user-with-user-independent-keychain and kSecUseUserIndependentKeychain for sharing keychain items across users.", tvos(13.0, 16.0));


/*!
 @class         TVUserManager
 @abstract      An object that provides facilities to best handle system users
 as it relates to their preferences like app-specific profiles.
 @discussion    Applications sometimes have their own notion of a "profile", to
 track users' preferences or other state. Those applications can rely on tvOS
 to handle separating each user's data by adopting the "Runs as Current User"
 entitlement, with this entitlement reading and writing data will happen for the
 selected user.

 @note When running as the current user each user would have to sign in again to
 the app, to avoid that behavior it is highly recommended that those apps also
 use `kSecUseUserIndependentKeychain` to store their account credentials across
 users.
 */
API_AVAILABLE(tvos(13.0))
@interface TVUserManager : NSObject

/*!
 @property shouldStorePreferencesForCurrentUser
 @abstract Indicates if the system recommends that the app saves the user's
 preferences.

 @discussion Apps with the User Management capability "Runs as Current User"
 should remember the user's choices, like which profile they use, that way
 people will immediately see the content they want without any interruptions
 like having to pick their profile again.

 You can safely assume that storing the user's preferences is the desirable
 behavior. In some situations though it might not be, and this method represents
 when the system believe it best to continue to, for example, show the profile
 picker.

 This property will return `NO` if there is only one Apple TV user, or if your
 app doesn't have the capability of running as the current user.

 @note If your app is deployed on tvOS 15 or earlier, you should treat those as
 if this property is returning `NO`.
 */
@property (nonatomic, assign, readonly) BOOL shouldStorePreferencesForCurrentUser API_AVAILABLE(tvos(16.0)) API_UNAVAILABLE(macos, ios, watchos);

// MARK: - Deprecated

/*!
 @property      currentUserIdentifier
 @abstract      Retrieve the identifier for the current system user.
 @discussion    This value may be nil if no value is available to the application.  When this is nil or the application has no existing mapping from the user to a preferred profile, the application can put up its profile picker or adopt some other appropriate behavior. For users which are part of the Home this Apple TV is in, this value is the same on all the Apple TVs that are part of that Home.
 This property is KVO-observable, to watch for changes.  You will need to hold onto a TVUserManager instance to observe this property on it.
 */
@property (nonatomic, nullable, readonly) TVUserIdentifier currentUserIdentifier API_DEPRECATED("User Management capability get-current-user is no longer supported. Please use runs-as-current-user-with-user-independent-keychain and kSecUseUserIndependentKeychain for sharing keychain items across users.", tvos(13.0, 16.0));

/*!
 @property      userIdentifiersForCurrentProfile
 @abstract      Tell the system the user identifiers to which the current profile corresponds.
 @discussion    The value should be an NSArray with the system user identifiers that prefer the current profile in the application. An application which is maintaining system user identifer to profile mappings should write a new value to this set whenever the user changes the current profile within the application. The value of this property can be read, but it simply contains the last value stored in it, and starts empty when an application launches.
 This property is KVO-observable, to watch for changes.  You will need to hold onto a TVUserManager instance to observe this property on it.
 */
@property (nonatomic, copy) NSArray<TVUserIdentifier> *userIdentifiersForCurrentProfile API_DEPRECATED("User Management capability get-current-user is no longer supported. Please use runs-as-current-user-with-user-independent-keychain and kSecUseUserIndependentKeychain for sharing keychain items across users.", tvos(13.0, 16.0));

/*!
 @method        presentProfilePreferencePanelWithCurrentSettings:availableProfiles:completion:
 @abstract      Present a user-to-profile configuration panel to the user.
 @param currentSettings    All the mappings of system user identifiers to their preferred profile string labels that the application currently has. Profile descriptors with no name (or empty string) are ignored, along with the mapping in the dictionary. Profile descriptors which have names that aren't also in the availableProfiles list are ignored, along with the mapping in the dictionary. Ignored mappings will not be present in the resulting newSettings dictionary. It is not required that the profile descriptor values in the dictionary are the exact instances in the availableProfiles list.
 @param availableProfiles   A list of profile descriptors initialized with the third-party in-app profiles currently available in the application, from which the user can choose in the user interface. Profile descriptors with no name (or empty string) are ignored. Duplicate profile descriptors are ignored.
 @param completion      A block to be called when the user interface is dismissed. The dictionary argument to the block will give the new settings as changed by the user. Note that entries in the original settings argument may be missing in the new dictionary, if the user set the preferred profile for a user back to the "no preference" setting. The descriptor objects in the dictionary argument of the completion block come from among the specific instances in the availableProfiles input argument. In other words, the instances in the availableProfiles array are preserved through to the argument to the completion block, and the values of the input existingSettings dictionary are not (unless they happen to be the same objects that appear in the availableProfiles list), but neither are entirely new TVAppProfileDescriptor objects manufactured.
 @discussion    The system will present a panel to the user which allows the user to configure all the preferred profiles for this application for all users on the system.  Once the user dismisses the panel, the completion callback will give the new settings, which should be saved by the application.  The application should invoke this method from some place in its user interface, perhaps a button in the app's "settings" area.
 The completion block is executed on an arbitrary dispatch queue / thread.
 If invoked from within an extension, no UI will be presented and the dictionary parameter to the callback will be empty.
 */
- (void)presentProfilePreferencePanelWithCurrentSettings:(NSDictionary<TVUserIdentifier, TVAppProfileDescriptor *> *)currentSettings availableProfiles:(NSArray<TVAppProfileDescriptor *> *)availableProfiles completion:(void (^)(NSDictionary<TVUserIdentifier, TVAppProfileDescriptor *> *newSettings))completion NS_SWIFT_NAME(presentProfilePreferencePanel(currentSettings:availableProfiles:completion:)) API_DEPRECATED("User Management capability get-current-user is no longer supported. Please use runs-as-current-user-with-user-independent-keychain and kSecUseUserIndependentKeychain for sharing keychain items across users.", tvos(13.0, 16.0));

/*!
 @method        shouldStorePreferenceForCurrentUserToProfile:completion:
 @abstract      Ask the system if a new mapping from the current system user to a user-chosen profile should be created.
 @param profile     A profile descriptor initialized with the third-party in-app profile information. If the profile descriptor has no name or an empty string name, the answer to the completion block will be NO.
 @param completion  A block to be called upon completion of the request. The parameter of the block indicates whether or not the application should create a mapping or skip it.
 @discussion    An application uses this method to confirm with the system that the application should adopt a profile chosen from a profile picker as the preferred profile for that user identifier. The system will usually then ask the user with some user interface what the user wants to do. If the answer is NO, the application should not store the chosen profile as the user's preferred profile. An application should only ask this once per user identifier and profile pair, so even if the answer is NO, the application needs to record that the system has been asked, for that identifier + profile pair.
 The completion block is executed on an arbitrary dispatch queue / thread.
 If invoked from within an extension, no UI will be presented and the result will always be NO.
 */
- (void)shouldStorePreferenceForCurrentUserToProfile:(TVAppProfileDescriptor *)profile completion:(void (^)(BOOL shouldCreateMapping))completion NS_SWIFT_NAME(shouldStorePreferenceForCurrentUser(to:completion:)) API_DEPRECATED("User Management capability get-current-user is no longer supported. Please use runs-as-current-user-with-user-independent-keychain and kSecUseUserIndependentKeychain for sharing keychain items across users.", tvos(13.0, 16.0));


@end


/*!
 @constant      TVUserManagerCurrentUserIdentifierDidChangeNotification
 @abstract      Posted to the default NSNotificationCenter whenever the current system user changes.
 @discussion    The object of the notification is nil. In order to start receiving notification you have to instantiate TVUserManager at least once.
 */
TV_EXTERN NSNotificationName const TVUserManagerCurrentUserIdentifierDidChangeNotification NS_SWIFT_NAME(TVUserManager.currentUserIdentifierDidChangeNotification) API_DEPRECATED("User Management capability get-current-user is no longer supported. Use the capability runs-as-current-user-with-user-independent-keychain, with it there is no need to be notified of user changes.", tvos(13.0, 16.0));


NS_ASSUME_NONNULL_END

