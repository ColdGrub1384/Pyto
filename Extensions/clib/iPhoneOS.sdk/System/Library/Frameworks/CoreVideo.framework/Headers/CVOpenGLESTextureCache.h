/*
 *  CVOpenGLESTextureCache.h
 *  CoreVideo
 *
 *  Copyright 2011-2015 Apple Inc. All rights reserved.
 *
 */

/*! @header CVOpenGLESTextureCache.h
 @copyright 2011-2015 Apple Inc. All rights reserved.
 @availability iOS 5.0 or later
 @discussion A CoreVideo TextureCache is used to cache and manage CVOpenGLESTextures.
 
 */

#if !defined(__COREVIDEO__CVOPENGLESTEXTURECACHE_H__)
#define __COREVIDEO__CVOPENGLESTEXTURECACHE_H__ 1

#include <CoreVideo/CVBase.h>
#include <CoreVideo/CVReturn.h>
#include <CoreVideo/CVBuffer.h>
#include <CoreVideo/CVOpenGLESTexture.h>

#if defined(__cplusplus)
extern "C" {
#endif

/*!
    @typedef	CVOpenGLESTextureCacheRef
    @abstract   CoreVideo OpenGLES Texture Cache

*/
typedef struct CV_BRIDGED_TYPE(id) __CVOpenGLESTextureCache *CVOpenGLESTextureCacheRef;

#ifndef COREVIDEO_USE_EAGLCONTEXT_CLASS_IN_API
#define COREVIDEO_USE_EAGLCONTEXT_CLASS_IN_API 1
#endif

#if defined(__OBJC__) && COREVIDEO_USE_EAGLCONTEXT_CLASS_IN_API
@class EAGLContext;
typedef EAGLContext *CVEAGLContext;
#else
typedef void *CVEAGLContext;
#endif

//
// cacheAttributes
//
// By default, textures will age out after one second.  Setting a maximum
// texture age of zero will disable the age-out mechanism completely.
// CVOpenGLESTextureCacheFlush() can be used to force eviction in either case.
	
CV_EXPORT const CFStringRef CV_NONNULL kCVOpenGLESTextureCacheMaximumTextureAgeKey COREVIDEO_GL_DEPRECATED(ios, 5.0, 12.0) COREVIDEO_GL_DEPRECATED(tvos, 9.0, 12.0) API_UNAVAILABLE(macosx) __WATCHOS_PROHIBITED;

//
// textureAttributes - reserved for future use
	
CV_EXPORT CFTypeID CVOpenGLESTextureCacheGetTypeID(void) COREVIDEO_GL_DEPRECATED(ios, 5.0, 12.0) COREVIDEO_GL_DEPRECATED(tvos, 9.0, 12.0) API_UNAVAILABLE(macosx) __WATCHOS_PROHIBITED;

/*!
    @function   CVOpenGLESTextureCacheCreate
    @abstract   Creates a new Texture Cache.
    @param      allocator The CFAllocatorRef to use for allocating the cache.  May be NULL.
    @param      cacheAttributes A CFDictionaryRef containing the attributes of the cache itself.   May be NULL.
    @param      eaglContext The OpenGLES 2.0 context into which the texture objects will be created.  OpenGLES 1.x contexts are not supported.
    @param      textureAttributes A CFDictionaryRef containing the attributes to be used for creating the CVOpenGLESTexture objects.  May be NULL.
    @param      cacheOut   The newly created texture cache will be placed here
    @result     Returns kCVReturnSuccess on success
*/
CV_EXPORT CVReturn CVOpenGLESTextureCacheCreate(
    CFAllocatorRef CV_NULLABLE allocator,
    CFDictionaryRef CV_NULLABLE cacheAttributes,
    CVEAGLContext CV_NONNULL eaglContext,
    CFDictionaryRef CV_NULLABLE textureAttributes,
    CV_RETURNS_RETAINED_PARAMETER CVOpenGLESTextureCacheRef CV_NULLABLE * CV_NONNULL cacheOut) COREVIDEO_GL_DEPRECATED(ios, 5.0, 12.0) COREVIDEO_GL_DEPRECATED(tvos, 9.0, 12.0) API_UNAVAILABLE(macosx) __WATCHOS_PROHIBITED;

/*!
    @function   CVOpenGLESTextureCacheCreateTextureFromImage
    @abstract   Creates a CVOpenGLESTexture object from an existing CVImageBuffer
    @param      allocator The CFAllocatorRef to use for allocating the CVOpenGLESTexture object.  May be NULL.
    @param      textureCache The texture cache object that will manage the texture.
    @param      sourceImage The CVImageBuffer that you want to create a CVOpenGLESTexture from.
    @param      textureAttributes A CFDictionaryRef containing attributes to be used for creating the CVOpenGLESTexture objects.  May be NULL.
    @param      target Specifies the target texture.  GL_TEXTURE_2D and GL_RENDERBUFFER are the only targets currently supported.
    @param      internalFormat Specifies the number of color components in the texture.  Examples are GL_RGBA, GL_LUMINANCE, GL_RGBA8_OES, GL_RG, and GL_RED (NOTE: On GLES3 use GL_R8 instead of GL_RED).
    @param      width Specifies the width of the texture image.
    @param      height Specifies the height of the texture image.
    @param      format Specifies the format of the pixel data.  Examples are GL_RGBA and GL_LUMINANCE.
    @param      type Specifies the data type of the pixel data.  Examples are GL_UNSIGNED_BYTE.
    @param      planeIndex Specifies the plane of the CVImageBuffer to map bind.  Ignored for non-planar CVImageBuffers.
    @param      textureOut The newly created texture object will be placed here.
    @result     Returns kCVReturnSuccess on success
    @discussion Creates or returns a cached CVOpenGLESTexture texture object mapped to the CVImageBuffer and
                associated params.  This creates a live binding between the CVImageBuffer and underlying
                CVOpenGLESTexture texture object.  The EAGLContext associated with the cache may be modified,
                to create, delete, or bind textures.  When used as a source texture or GL_COLOR_ATTACHMENT,
                the CVImageBuffer must be unlocked before rendering.  The source or render buffer texture should
                not be re-used until the rendering has completed.  This can be guaranteed by calling glFlush().

                Here are some example mappings:

                Mapping a BGRA buffer as a source texture:
                CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault, textureCache, pixelBuffer, NULL, GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0, &outTexture);

                Mapping a BGRA buffer as a renderbuffer:
                CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault, textureCache, pixelBuffer, NULL, GL_RENDERBUFFER, GL_RGBA8_OES, width, height, GL_RGBA, GL_UNSIGNED_BYTE, 0, &outTexture);

                Mapping the luma plane of a 420v buffer as a source texture:
                CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault, textureCache, pixelBuffer, NULL, GL_TEXTURE_2D, GL_LUMINANCE, width, height, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0, &outTexture);

                Mapping the chroma plane of a 420v buffer as a source texture:
                CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault, textureCache, pixelBuffer, NULL, GL_TEXTURE_2D, GL_LUMINANCE_ALPHA, width/2, height/2, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, 1, &outTexture);

                Mapping a yuvs buffer as a source texture (note: yuvs/f and 2vuy are unpacked and resampled -- not colorspace converted)
                CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault, textureCache, pixelBuffer, NULL, GL_TEXTURE_2D, GL_RGB_422_APPLE, width, height, GL_RGB_422_APPLE, GL_UNSIGNED_SHORT_8_8_APPLE, 1, &outTexture);
*/
CV_EXPORT CVReturn CVOpenGLESTextureCacheCreateTextureFromImage(
    CFAllocatorRef CV_NULLABLE allocator,
    CVOpenGLESTextureCacheRef CV_NONNULL textureCache,
    CVImageBufferRef CV_NONNULL sourceImage,
    CFDictionaryRef CV_NULLABLE textureAttributes,
    GLenum target,
    GLint internalFormat,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    size_t planeIndex,
    CV_RETURNS_RETAINED_PARAMETER CVOpenGLESTextureRef CV_NULLABLE * CV_NONNULL textureOut ) COREVIDEO_GL_DEPRECATED(ios, 5.0, 12.0) COREVIDEO_GL_DEPRECATED(tvos, 9.0, 12.0) API_UNAVAILABLE(macosx) __WATCHOS_PROHIBITED;

/*!
    @function   CVOpenGLESTextureCacheFlush
    @abstract   Performs internal housekeeping/recycling operations
    @discussion This call must be made periodically to give the texture cache a chance to make OpenGLES calls
                on the OpenGLES context used to create it in order to do housekeeping operations.  The EAGLContext
	            associated with the cache may be used to delete or unbind textures.
    @param      textureCache The texture cache object to flush
    @param      options Currently unused, set to 0.
*/
CV_EXPORT void CVOpenGLESTextureCacheFlush( CVOpenGLESTextureCacheRef CV_NONNULL textureCache, CVOptionFlags options ) COREVIDEO_GL_DEPRECATED(ios, 5.0, 12.0) COREVIDEO_GL_DEPRECATED(tvos, 9.0, 12.0) API_UNAVAILABLE(macosx) __WATCHOS_PROHIBITED;

#if defined(__cplusplus)
}
#endif

#endif
