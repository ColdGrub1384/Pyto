/* CoreAnimation - CAEAGLLayer.h

   Copyright (c) 2007-2018, Apple Inc.
   All rights reserved. */

#import <QuartzCore/CALayer.h>
#import <OpenGLES/EAGLDrawable.h>

NS_ASSUME_NONNULL_BEGIN

/* CAEAGLLayer is a layer that implements the EAGLDrawable protocol,
 * allowing it to be used as an OpenGLES render target. Use the
 * `drawableProperties' property defined by the protocol to configure
 * the created surface. */

#ifndef GLES_SILENCE_DEPRECATION
API_DEPRECATED("OpenGLES is deprecated",
               ios(2.0, 12.0), watchos(2.0, 5.0), tvos(9.0, 12.0))
#else
API_AVAILABLE(ios(2.0), watchos(2.0), tvos(9.0))
#endif
API_UNAVAILABLE(macos)
@interface CAEAGLLayer : CALayer <EAGLDrawable>
{
@private
  struct _CAEAGLNativeWindow *_win;
}

/* When false (the default value) changes to the layer's render buffer
 * appear on-screen asynchronously to normal layer updates. When true,
 * changes to the GLES content are sent to the screen via the standard
 * CATransaction mechanisms. */

@property BOOL presentsWithTransaction API_AVAILABLE(ios(9.0), watchos(2.0), tvos(9.0));

/* Note: the default value of the `opaque' property in this class is true,
 * not false as in CALayer. */

@end

NS_ASSUME_NONNULL_END
