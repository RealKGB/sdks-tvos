//
//  TVTopShelfCarouselItem.h
//  TVServices
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <TVServices/TVTopShelfItem.h>

NS_ASSUME_NONNULL_BEGIN

/// Options for describing media capabilities supported by a movie or show.
typedef NS_OPTIONS(NSUInteger, TVTopShelfCarouselItemMediaOptions)
{
    /// High-definition video resolution.
    ///
    /// Only one resolution value should be provided.
    TVTopShelfCarouselItemVideoResolutionHD = 1 << 0,

    /// Ultra-high-definition 4K video resolution.
    ///
    /// Only one resolution value should be provided.
    TVTopShelfCarouselItemVideoResolution4K = 2 << 0,

    /// High-dynamic-range video.
    ///
    /// Only one color space value should be provided.
    TVTopShelfCarouselItemVideoColorSpaceHDR = 1 << 6,

    /// Dolby Vision video.
    ///
    /// Only one color space value should be provided.
    TVTopShelfCarouselItemVideoColorSpaceDolbyVision = 2 << 6,

    /// Whether the movie or show supports Dolby Atmos audio.
    TVTopShelfCarouselItemAudioDolbyAtmos = 1 << 12,

    /// Whether the movie or show supports closed captioning.
    TVTopShelfCarouselItemAudioTranscriptionClosedCaptioning = 1 << 13,

    /// Whether the movie or show supports subtitles for the deaf and hard-of-hearing.
    TVTopShelfCarouselItemAudioTranscriptionSDH = 1 << 14,

    /// Whether the movie or show supports audio descriptions.
    TVTopShelfCarouselItemAudioDescription = 1 << 15
} API_AVAILABLE(tvos(13.0)) NS_SWIFT_NAME(TVTopShelfCarouselItem.MediaOptions);

/// An object that represents a single item in the carousel content style.
API_AVAILABLE(tvos(13.0))
@interface TVTopShelfCarouselItem : TVTopShelfItem

/// A localized string that describes why this item is being shown in the Top Shelf.
@property (nonatomic, copy, nullable) NSString *contextTitle;

/// A descriptive summary of the movie or show.
@property (nonatomic, copy, nullable) NSString *summary;

/// The genre of the movie or show.
@property (nonatomic, copy, nullable) NSString *genre;

/// The length of the movie or show.
@property (nonatomic) NSTimeInterval duration;

/// The date this item was created or released.
@property (nonatomic, copy, nullable) NSDate *creationDate;

/// The media options supported by the movie or show.
///
/// Values provided here are used to show media capability badges in the Top Shelf UI.
@property (nonatomic) TVTopShelfCarouselItemMediaOptions mediaOptions;

/// The trailer for the movie or show.
///
/// If provided this video is played after the image or cinemagraph when the user rests on the item.
@property (nonatomic, copy, nullable) NSURL *previewVideoURL;

/// A looping video shown before the preview video instead of the image.
///
/// If provided this video takes the place of the image. It will loop without sound until the preview video is ready to play.
@property (nonatomic, copy, nullable) NSURL *cinemagraphURL;

/// A collection of up to 4 named attributes displayed by the Top Shelf UI in a stylized manner.
@property (nonatomic, copy) NSArray<TVTopShelfNamedAttribute *> *namedAttributes;

@end

NS_ASSUME_NONNULL_END
