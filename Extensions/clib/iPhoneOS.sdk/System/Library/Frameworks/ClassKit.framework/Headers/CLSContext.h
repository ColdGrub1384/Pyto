//
//  CLSContext.h
//  ClassKit
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <ClassKit/CLSDefines.h>
#import <ClassKit/CLSObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CLSContextType) {
    CLSContextTypeNone = 0,

    CLSContextTypeApp,       // Reserved for the main app context

    CLSContextTypeChapter,
    CLSContextTypeSection,
    CLSContextTypeLevel,
    CLSContextTypePage,

    CLSContextTypeTask,
    CLSContextTypeChallenge,
    CLSContextTypeQuiz,
    CLSContextTypeExercise,
    CLSContextTypeLesson,

    CLSContextTypeBook,
    CLSContextTypeGame,

    CLSContextTypeDocument,
    CLSContextTypeAudio,
    CLSContextTypeVideo,

} API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);

typedef NSString * CLSContextTopic NS_STRING_ENUM API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);

CLS_EXTERN CLSContextTopic const CLSContextTopicMath API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);
CLS_EXTERN CLSContextTopic const CLSContextTopicScience API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);
CLS_EXTERN CLSContextTopic const CLSContextTopicLiteracyAndWriting API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);
CLS_EXTERN CLSContextTopic const CLSContextTopicWorldLanguage API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);
CLS_EXTERN CLSContextTopic const CLSContextTopicSocialScience API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);
CLS_EXTERN CLSContextTopic const CLSContextTopicComputerScienceAndEngineering API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);
CLS_EXTERN CLSContextTopic const CLSContextTopicArtsAndMusic API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);
CLS_EXTERN CLSContextTopic const CLSContextTopicHealthAndFitness API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);


/*!
 @abstract      Contexts represent activities, documents, and areas within your app.
 @discussion    Contexts have two major components.

                (1) Child contexts, used to model your app hierarchy.
                (2) Activity, holds user generated data that pertains to this context.

 */
API_AVAILABLE(ios(11.3)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos)
@interface CLSContext : CLSObject

- (instancetype)init NS_UNAVAILABLE;

/*!
 @abstract      App-assigned identifier. This identifier should work across users and devices and be unique with regards to its siblings within its parent.
 @discussion    The identifier could be used to embed information later used for deep linking. For example: @em hydrogen-element, or @em chapter-1.
 */
@property (nonatomic, copy, readonly) NSString *identifier;


/*!
 @abstract      Alternative deep link URL using universal links.
 @discussion    If your app supports universal links, you can supply them here to link the content this context represents.
 */
@property (nullable, nonatomic, strong) NSURL *universalLinkURL API_AVAILABLE(ios(11.4)) API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos);

/*!
 @abstract      Type of this context
 @discussion    The type that best describes this context.
 */
@property (nonatomic, assign, readonly) CLSContextType type;

/*!
 @abstract      Title of this context.
 @discussion    For example: @em Level 1 @em.
 */
@property (nonatomic, copy) NSString *title;

/*!
 @abstract      The displayOrder is by default sorted ascending.
 @discussion    Set the displayOrder if you want your contexts to be displayed in a particular order. The
                sort key is used as a way to sort sibling contexts in a particular order.
 */
@property (nonatomic, assign) NSInteger displayOrder;

/*!
 @abstract      Topic associated with this context.
 @discussion    See above for valid, predefined topics.
 */
@property (nullable, nonatomic, copy) CLSContextTopic topic;

/*!
@abstract      Initialize and configure the type of content this context represents.
 @param         identifier     App-assigned identifier for this context. 256 characters max length.
 @param         type           The type of content this context represents.
 @param         title          Title for what this context represents. 256 characters max length.
*/
- (instancetype)initWithType:(CLSContextType)type
                  identifier:(NSString *)identifier
                       title:(NSString *)title NS_DESIGNATED_INITIALIZER;

/*!
 @discussion    Returns true if self is the active context.
 */
@property (nonatomic, assign, readonly, getter=isActive) BOOL active;

/*!
 @abstract      Marks contexts as active.
 @discussion    If a context is already active, it will remain active. If another context is active, the other will resign active before this one becomes active.
 */
- (void)becomeActive;

/*!
 @abstract      Resign being active.
 @discussion    This method does nothing if the reciever of the message is not active.
 */
- (void)resignActive;

@end

@interface CLSContext (Hierarchy)

/*!
 @abstract      Returns the parent of this context.
 */
@property (nullable, nonatomic, weak, readonly) CLSContext *parent;

/*!
 @abstract      Removes this child context from its parent.
 @discussion    If you remove a context from its parent and do not add it as a child of another
                context, it will be deleted when you call -save on the dataStore.
 */
- (void)removeFromParent;

/*!
 @abstract      Adds a child context.
 @discussion    A context can only have a single parent.
 @note          objectID of child context may change after it's been added.
 */
- (void)addChildContext:(CLSContext *)child;

/*!
 @abstract      Returns a descendant of this context matching the context path you provide.
                Context path must start with an identifier of a child context of the context to which this message is sent.
 @discussion    If there are any missing contexts, they will be filled in by calling the following method on the context's data store's delegate:
                @code -[CLSDataStoreDelegate createContextForIdentifier:parentContext:parentIdentifierPath:] @endcode
                If the dataStore does not have a delegate and there are missing contexts then an incomplete list of contexts will be passed to the completion handler.
 				Completion block is called on a background thread.
 */
- (void)descendantMatchingIdentifierPath:(NSArray<NSString *> *)identifierPath
                              completion:(void(^)(CLSContext * _Nullable context, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
