/*
	File:  UIWindow.h
 
	Framework:  AVKit
 
	Copyright © 2017-2023 Apple Inc. All rights reserved.
 */

#import <AVKit/AVKitDefines.h>
#import <UIKit/UIKit.h>


@class AVDisplayManager;

NS_ASSUME_NONNULL_BEGIN

@interface UIWindow (AVAdditions)

/*!
	@property   avDisplayManager
	@abstract   The AVDisplayManager instance coordinating screen display properties for this UIWindow
	@discussion Use this object to manually manage requests for specific screen resolution, refresh rate & HDR modes.
 */
#if TARGET_OS_XR
@property (nonatomic, readonly) AVDisplayManager *avDisplayManager API_AVAILABLE(tvos(11.2), xros(1.0));
#else
@property (nonatomic, readonly) AVDisplayManager *avDisplayManager API_AVAILABLE(tvos(11.2));
#endif // TARGET_OS_XR

@end

NS_ASSUME_NONNULL_END
