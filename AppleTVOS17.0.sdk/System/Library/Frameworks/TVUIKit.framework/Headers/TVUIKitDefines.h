//
//  TVUIKitDefines.h
//  TVUIKit
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#if !defined(TV_EXTERN)

#ifdef __cplusplus
#define TV_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define TV_EXTERN   extern __attribute__((visibility ("default")))
#endif

#endif // !defined(TV_EXTERN)
