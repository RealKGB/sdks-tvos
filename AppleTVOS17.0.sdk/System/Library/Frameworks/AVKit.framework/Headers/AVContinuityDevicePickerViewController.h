/*
	File:  AVContinuityDevicePickerViewController.h
	
	Framework:  AVKit
	
	Copyright © 2023 Apple Inc. All rights reserved.
	
	To report bugs, go to:  http://developer.apple.com/bugreporter/

 */

#import <AVFoundation/AVContinuityDevice.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AVContinuityDevicePickerViewControllerDelegate;

/*!
	@class		AVContinuityDevicePickerViewController
	@abstract	AVContinuityDevicePickerViewController is a view controller that can be presented modally to prompt users to pick/pair continuity devices (iPhone, iPad) to use as a remote camera and microphone.
	@discussion Always display the device picker as a full-screen, modal view. If the user selects a device, the system will update the devices property of the AVCaptureDeviceDiscoverySession instance.
 */
API_AVAILABLE(tvos(17.0)) API_UNAVAILABLE(macos, ios, watchos)
@interface AVContinuityDevicePickerViewController : UIViewController

/*!
	@property	delegate
	@abstract The picker view controller's delegate.
 */
@property (nonatomic, nullable, weak) id<AVContinuityDevicePickerViewControllerDelegate> delegate;

@end


/*!
	@protocol	AVContinuityDevicePickerViewControllerDelegate
	@abstract	A protocol for delegates of AVContinuityDevicePickerViewController.
 */
@protocol AVContinuityDevicePickerViewControllerDelegate <NSObject>
@optional

/*!
	@method		continuityDevicePickerWillBeginPresenting:
	@abstract	Informs the delegate that the device picker view controller will start presenting devices to the user.
 */
- (void)continuityDevicePickerWillBeginPresenting:(AVContinuityDevicePickerViewController *)pickerViewController;

/*!
	@method		continuityDevicePicker:didConnectDevice:
	@abstract	Informs the delegate that the device picker view controller finished presenting devices to the user and a device was connected.
 */
- (void)continuityDevicePicker:(AVContinuityDevicePickerViewController *)pickerViewController didConnectDevice:(AVContinuityDevice *)device;

/*!
	@method		continuityDevicePickerDidCancel:
	@abstract	Informs the delegate that the device picker presentation was cancelled by the user and a device was not connected.
 */
- (void)continuityDevicePickerDidCancel:(AVContinuityDevicePickerViewController *)pickerViewController;

/*!
	@method		continuityDevicePickerDidEndPresenting:
	@abstract	Informs the delegate that the device picker view controller finished presenting.
 */
- (void)continuityDevicePickerDidEndPresenting:(AVContinuityDevicePickerViewController *)pickerViewController;

@end

NS_ASSUME_NONNULL_END
