//
//  DDDevicePickerViewController.h
//  DeviceDiscoveryUI
//
//  Copyright 2022 Apple Inc. All rights reserved.
//

#import <DeviceDiscoveryUI/DeviceDiscoveryUI.h>
#import <Foundation/Foundation.h>
#import <Network/Network.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

DeviceDiscoveryUI_EXTERN API_AVAILABLE(tvos(16.0)) API_UNAVAILABLE(macos, ios, watchos)
@interface DDDevicePickerViewController: UIViewController

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

#ifndef __swift__
+ (BOOL)isSupportedForBrowseDescriptor:(nw_browse_descriptor_t)browseDescriptor
                            parameters:(nullable nw_parameters_t)parameters;

- (nullable instancetype)initWithBrowseDescriptor:(nw_browse_descriptor_t)browseDescriptor
                                       parameters:(nullable nw_parameters_t)parameters NS_DESIGNATED_INITIALIZER;

- (void)setDevicePickerCompletionHandler:(void(^)(nw_endpoint_t _Nullable endpoint, nw_error_t _Nullable error))devicePickerCompletionHandler;
#endif

@end

NS_ASSUME_NONNULL_END
