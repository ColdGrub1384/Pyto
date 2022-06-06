//
//  LAContext.h
//  LocalAuthentication
//
//  Copyright (c) 2014 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LocalAuthentication/LAPublicDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LAPolicy)
{
    /// Device owner is going to be authenticated using a biometric method (Touch ID or Face ID).
    ///
    /// @discussion Biometric authentication is required. If the biometry is not available, not enrolled,
    ///             or locked out, then the evaluation of this policy will fail with LAErrorBiometryNotAvailable,
    ///             LAErrorBiometryNotEnrolled or LAErrorBiometryLockout. Biometry can't be used without a passcode,
    ///             i.e. when biometry is available, enrolled and not locked out but passcode is not set, then
    ///             the evaluation will fail with LAErrorPasscodeNotSet.
    ///
    ///             Touch ID authentication dialog contains a cancel button with default title "Cancel"
    ///             which can be customized using localizedCancelTitle property, and a fallback button with
    ///             default title "Enter Password" which can be customized using localizedFallbackTitle
    ///             property. Fallback button is initially hidden and shows up after first unsuccessful
    ///             Touch ID attempt. Tapping either button causes evaluatePolicy call to fail, returning
    ///             a distinct error code: LAErrorUserCancel or LAErrorUserFallback.
    ///
    ///             Face ID authentication begins with animating HUD. If it succeeds at first attempt,
    ///             the HUD will disappear and no other UI is shown. If the first attempt fails, then
    ///             LocalAuthentication will show a dialog with two buttons: "Cancel" and "Try Face ID Again".
    ///             After second failure, the buttons are "Cancel" and "Enter Password" with the same
    ///             semantics as in the case of Touch ID.
    ///
    ///             Biometric authentication will get locked after 5 unsuccessful attempts. After that,
    ///             users have to unlock it by entering passcode. The passcode can be entered either at
    ///             Lock Screen or even in app by the means of LAPolicyDeviceOwnerAuthentication.
    ///             The Lock Screen unlock is preferred user experience because we generaly don't want users to
    ///             enter their passcode at app's request.
    LAPolicyDeviceOwnerAuthenticationWithBiometrics API_AVAILABLE(ios(8.0), macos(10.12.2), watchos(3.0), tvos(10.0)) = kLAPolicyDeviceOwnerAuthenticationWithBiometrics,

    /// Device owner is going to be authenticated by biometry or device passcode.
    ///
    /// @discussion Biometric or passcode authentication is required. If the biometry is available, enrolled and
    ///             not locked out, users are asked for it first. Otherwise they are asked to enter device
    ///             passcode. If passcode is not enabled, policy evaluation will fail with LAErrorPasscodeNotSet.
    ///
    ///             Biometric authentication dialog behaves similarly as the one used by
    ///             LAPolicyDeviceOwnerAuthenticationWithBiometrics. However, instead of "Enter Password"
    ///             button there is "Enter Passcode" button which, when tapped, switches the authentication
    ///             method and allows users to enter device passcode.
    ///
    ///             Passcode authentication will get locked after 6 unsuccessful attempts with progressively
    ///             increased backoff delay.
    LAPolicyDeviceOwnerAuthentication API_AVAILABLE(ios(9.0), macos(10.11), watchos(3.0), tvos(10.0)) = kLAPolicyDeviceOwnerAuthentication,
    
    /// Device owner is going to be authenticated by Watch.
    ///
    /// @discussion Watch authentication is required. If no nearby paired watch device can be found,
    ///             LAErrorWatchNotAvailable is returned.
    ///
    ///             Watch authentication dialog looks and behaves similarly to the biometric variant. Users can
    ///             confirm authentication by double-clicking the side button on their watch.
    LAPolicyDeviceOwnerAuthenticationWithWatch API_AVAILABLE(macos(10.15), macCatalyst(13.0)) API_UNAVAILABLE(ios, watchos, tvos) = kLAPolicyDeviceOwnerAuthenticationWithWatch,
    
    /// Device owner is going to be authenticated by biometry or Watch.
    ///
    /// @discussion Watch or biometric authentication is required. If no nearby paired watch device can be found,
    ///             it behaves as LAPolicyDeviceOwnerAuthenticationWithBiometrics. Similarly, if biometry is
    ///             unavailable it behaves as LAPolicyDeviceOwnerAuthenticationWithWatch.
    ///
    ///             Watch authentication dialog looks and behaves similarly to biometric variant. When both
    ///             machanisms are available, user is asked to use biometry and watch authentication will run in
    ///             parallel.
    LAPolicyDeviceOwnerAuthenticationWithBiometricsOrWatch API_AVAILABLE(macos(10.15), macCatalyst(13.0)) API_UNAVAILABLE(ios, watchos, tvos) = kLAPolicyDeviceOwnerAuthenticationWithBiometricsOrWatch
} API_AVAILABLE(ios(8.0), macos(10.10), watchos(3.0), tvos(10.0));

/// The maximum value for LAContext touchIDAuthenticationAllowableReuseDuration property.
extern const NSTimeInterval LATouchIDAuthenticationMaximumAllowableReuseDuration API_AVAILABLE(macos(10.12), ios(9.0)) API_UNAVAILABLE(watchos, tvos);

/// Class that represents an authentication context.
///
/// @discussion This context can be used for evaluating policies.
///
/// @see LAPolicy
API_AVAILABLE(macos(10.10), ios(8.0), watchos(3.0), tvos(10.0))
@interface LAContext : NSObject

/// Determines if a particular policy can be evaluated.
///
/// @discussion Policies can have certain requirements which, when not satisfied, would always cause
///             the policy evaluation to fail - e.g. a passcode set, a fingerprint
///             enrolled with Touch ID or a face set up with Face ID. This method allows easy checking
///             for such conditions.
///
///             Applications should consume the returned value immediately and avoid relying on it
///             for an extensive period of time. At least, it is guaranteed to stay valid until the
///             application enters background.
///
/// @warning    Do not call this method in the reply block of evaluatePolicy:reply: because it could
///             lead to a deadlock.
///
/// @param policy Policy for which the preflight check should be run.
///
/// @param error Optional output parameter which is set to nil if the policy can be evaluated, or it
///              contains error information if policy evaluation is not possible.
///
/// @return YES if the policy can be evaluated, NO otherwise.
- (BOOL)canEvaluatePolicy:(LAPolicy)policy error:(NSError * __autoreleasing *)error __attribute__((swift_error(none)))
    API_AVAILABLE(macos(10.10), ios(8.0), watchos(3.0), tvos(10.0));

/// Evaluates the specified policy.
///
/// @discussion Policy evaluation may involve prompting user for various kinds of interaction
///             or authentication. Actual behavior is dependent on evaluated policy, device type,
///             and can be affected by installed configuration profiles.
///
///             Be sure to keep a strong reference to the context while the evaluation is in progress.
///             Otherwise, an evaluation would be canceled when the context is being deallocated.
///
///             The method does not block. Instead, the caller must provide a reply block to be
///             called asynchronously when evaluation finishes. The block is executed on a private
///             queue internal to the framework in an unspecified threading context. Other than that,
///             no guarantee is made about which queue, thread, or run-loop the block is executed on.
///
///             Implications of successful policy evaluation are policy specific. In general, this
///             operation is not idempotent. Policy evaluation may fail for various reasons, including
///             user cancel, system cancel and others, see LAError codes.
///
/// @param policy Policy to be evaluated.
///
/// @param reply Reply block that is executed when policy evaluation finishes.
///              success Reply parameter that is YES if the policy has been evaluated successfully or
///                      NO if the evaluation failed.
///              error Reply parameter that is nil if the policy has been evaluated successfully, or it
///                    contains error information about the evaluation failure.
///
/// @param localizedReason Application reason for authentication. This string must be provided in correct
///                        localization and should be short and clear. It will be eventually displayed in
///                        the authentication dialog subtitle for Touch ID or passcode. The name of the
///                        calling application will be displayed in title, so it should not be duplicated here.
///
///                        This parameter is mostly ignored by Face ID authentication. Face ID will show
///                        generic instructions unless a customized fallback title is provided in
///                        localizedFallbackTitle property. For that case, it will show the authentication
///                        reason so that the instructions can be made consistent with the custom button
///                        title. Therefore, you should make sure that users are already aware of the need
///                        and reason for Face ID authentication before they have triggered the policy evaluation.
///
/// @warning localizedReason parameter is mandatory and the call will throw NSInvalidArgumentException if
///          nil or empty string is specified.
///
/// @warning Applications should also supply NSFaceIDUsageDescription key in the Info.plist. This key identifies
///          a string value that contains a message to be displayed to users when the app is trying to use
///          Face ID for the first time. Users can choose to allow or deny the use of Face ID by the app before
///          the first use or later in Face ID privacy settings. When the use of Face ID is denied, evaluations
///          will fail with LAErrorBiometryNotAvailable.
///
/// @see LAError
///
/// Typical error codes returned by this call are:
/// @li          LAErrorUserFallback if user tapped the fallback button
/// @li          LAErrorUserCancel if user has tapped the Cancel button
/// @li          LAErrorSystemCancel if some system event interrupted the evaluation (e.g. Home button pressed).
- (void)evaluatePolicy:(LAPolicy)policy
       localizedReason:(NSString *)localizedReason
                 reply:(void(^)(BOOL success, NSError * __nullable error))reply
    API_AVAILABLE(macos(10.10), ios(8.0), watchos(3.0), tvos(10.0));

/// Invalidates the context.
///
/// @discussion The context is invalidated automatically when it is (auto)released. This method
///             allows invalidating it manually while it is still in scope.
///
///             Invalidation terminates any existing policy evaluation and the respective call will
///             fail with LAErrorAppCancel. After the context has been invalidated, it can not be
///             used for policy evaluation and an attempt to do so will fail with LAErrorInvalidContext.
///
///             Invalidating a context that has been already invalidated has no effect.
- (void)invalidate API_AVAILABLE(macos(10.11), ios(9.0), watchos(3.0), tvos(10.0));

typedef NS_ENUM(NSInteger, LACredentialType)
{
    /// Password provided by application
    ///
    /// @discussion If not set, LocalAuthentication will ask for the password when necessary. It will use
    ///             its own user interface depending on the evaluated policy or ACL.
    ///             Applications can provide the password using the setCredential method. In such case,
    ///             LocalAuthentication will not show password entry user interface.
    ///             When entered from the LocalAuthentication user interface, the password is stored as
    ///             UTF-8 encoded string.
    LACredentialTypeApplicationPassword = kLACredentialTypeApplicationPassword,
} API_AVAILABLE(macos(10.11), ios(9.0), watchos(3.0), tvos(10.0));

/// Sets a credential to this context.
///
/// @discussion Some policies allow to bind application-provided credential with them.
///             This method allows credential to be passed to the right context.
///
/// @param credential Credential to be used with subsequent calls. Setting this parameter to nil will remove
///                   any existing credential of the specified type.
///
/// @param type Type of the provided credential.
///
/// @return YES if the credential was set successfully, NO otherwise.
///
- (BOOL)setCredential:(nullable NSData *)credential
                 type:(LACredentialType)type API_AVAILABLE(macos(10.11), ios(9.0), watchos(3.0), tvos(10.0));

/// Reveals if credential was set with this context.
///
/// @param type Type of credential we are asking for.
///
/// @return YES on success, NO otherwise.
///
- (BOOL)isCredentialSet:(LACredentialType)type API_AVAILABLE(macos(10.11), ios(9.0), watchos(3.0), tvos(10.0));

typedef NS_ENUM(NSInteger, LAAccessControlOperation)
{
    /// Access control will be used for item creation.
    LAAccessControlOperationCreateItem,

    /// Access control will be used for accessing existing item.
    LAAccessControlOperationUseItem,

    /// Access control will be used for key creation.
    LAAccessControlOperationCreateKey,

    /// Access control will be used for sign operation with existing key.
    LAAccessControlOperationUseKeySign,
    
    /// Access control will be used for data decryption using existing key.
    LAAccessControlOperationUseKeyDecrypt API_AVAILABLE(macos(10.12), ios(10.0)),

    /// Access control will be used for key exchange.
    LAAccessControlOperationUseKeyKeyExchange API_AVAILABLE(macos(10.12), ios(10.0)),
} API_AVAILABLE(macos(10.11), ios(9.0), watchos(3.0), tvos(10.0));

/// Evaluates access control object for the specified operation.
///
/// @discussion Access control evaluation may involve prompting user for various kinds of interaction
///             or authentication. Actual behavior is dependent on evaluated access control, device type,
///             and can be affected by installed configuration profiles.
///
///             Be sure to keep a strong reference to the context while the evaluation is in progress.
///             Otherwise, an evaluation would be canceled when the context is being deallocated.
///
///             The method does not block. Instead, the caller must provide a reply block to be
///             called asynchronously when evaluation finishes. The block is executed on a private
///             queue internal to the framework in an unspecified threading context. Other than that,
///             no guarantee is made about which queue, thread, or run-loop the block is executed on.
///
///             After successful access control evaluation, the LAContext can be used with keychain operations,
///             so that they do not require user to authenticate.
///
///             Access control evaluation may fail for various reasons, including user cancel, system cancel
///             and others, see LAError codes.
///
/// @param accessControl Access control object that is typically created by SecAccessControlCreateWithFlags.
///
/// @param operation Type of operation the access control will be used with.
///
/// @param localizedReason Application reason for authentication. This string must be provided in correct
///                        localization and should be short and clear. It will be eventually displayed in
///                        the authentication dialog subtitle for Touch ID or passcode. The name of the
///                        calling application will be displayed in title, so it should not be duplicated here.
///
///                        This parameter is mostly ignored by Face ID authentication. Face ID will show
///                        generic instructions unless a customized fallback title is provided in
///                        localizedFallbackTitle property. For that case, it will show the authentication
///                        reason so that the instructions can be made consistent with the custom button
///                        title. Therefore, you should make sure that users are already aware of the need
///                        and reason for Face ID authentication before they have triggered the policy evaluation.
///
/// @param reply Reply block that is executed when access control evaluation finishes.
///              success Reply parameter that is YES if the access control has been evaluated successfully or
///                      NO if the evaluation failed.
///              error Reply parameter that is nil if the access control has been evaluated successfully, or
///                    it contains error information about the evaluation failure.
///
/// @warning localizedReason parameter is mandatory and the call will throw NSInvalidArgumentException if
///          nil or empty string is specified.
///
/// @warning Applications should also supply NSFaceIDUsageDescription key in the Info.plist. This key identifies
///          a string value that contains a message to be displayed to users when the app is trying to use
///          Face ID for the first time. Users can choose to allow or deny the use of Face ID by the app before
///          the first use or later in Face ID privacy settings. When the use of Face ID is denied, evaluations
///          will fail with LAErrorBiometryNotAvailable.
- (void)evaluateAccessControl:(SecAccessControlRef)accessControl
                    operation:(LAAccessControlOperation)operation
              localizedReason:(NSString *)localizedReason
                        reply:(void(^)(BOOL success, NSError * __nullable error))reply
                        API_AVAILABLE(macos(10.11), ios(9.0), watchos(3.0)) API_UNAVAILABLE(tvos);

/// Fallback button title.
/// @discussion Allows fallback button title customization. If set to empty string, the button will be hidden.
///             A default title "Enter Password" is used when this property is left nil.
@property (nonatomic, nullable, copy) NSString *localizedFallbackTitle API_AVAILABLE(macos(10.10), ios(8.0), watchos(3.0), tvos(10.0));

/// This property is deprecated and setting it has no effect.
@property (nonatomic, nullable) NSNumber *maxBiometryFailures NS_DEPRECATED_IOS(8_3, 9_0) __WATCHOS_UNAVAILABLE __TVOS_UNAVAILABLE;

/// Cancel button title.
/// @discussion Allows cancel button title customization. A default title "Cancel" is used when
///             this property is left nil or is set to empty string.
@property (nonatomic, nullable, copy) NSString *localizedCancelTitle API_AVAILABLE(macos(10.12), ios(10.0), watchos(3.0), tvos(10.0));

/// Contains policy domain state.
///
/// @discussion  This property is set only when evaluatePolicy is called and succesful Touch ID or Face ID authentication
///              was performed, or when canEvaluatePolicy succeeds for a biometric policy.
///              It stays nil for all other cases.
///              If biometric database was modified (fingers or faces were removed or added), evaluatedPolicyDomainState
///              data will change. Nature of such database changes cannot be determined
///              but comparing data of evaluatedPolicyDomainState after different evaluatePolicy
///              will reveal the fact database was changed between calls.
///
/// @warning Please note that the value returned by this property can change exceptionally between major OS versions even if
///          the state of biometry has not changed.
@property (nonatomic, nullable, readonly) NSData *evaluatedPolicyDomainState API_AVAILABLE(macos(10.11), ios(9.0)) API_UNAVAILABLE(watchos, tvos);

/// Time interval for accepting a successful Touch ID or Face ID device unlock (on the lock screen) from the past.
///
/// @discussion This property can be set with a time interval in seconds. If the device was successfully unlocked by
///             biometry within this time interval, then biometric authentication on this context will succeed
///             automatically and the reply block will be called without prompting user for Touch ID or Face ID.
///
///             The default value is 0, meaning that no previous biometric unlock can be reused.
///
///             This property is meant only for reusing biometric matches from the device lock screen.
///             It does not allow reusing previous biometric matches in application or between applications.
///
///             The maximum supported interval is 5 minutes and setting the value beyond 5 minutes does not increase
///             the accepted interval.
///
/// @see LATouchIDAuthenticationMaximumAllowableReuseDuration
@property (nonatomic) NSTimeInterval touchIDAuthenticationAllowableReuseDuration API_AVAILABLE(macos(10.12), ios(9.0)) API_UNAVAILABLE(watchos, tvos);

/// Allows setting the default localized authentication reason on context.
///
/// @discussion A localized string from this property is displayed in the authentication UI if the caller didn't specify
///             its own authentication reason (e.g. a keychain operation with kSecUseAuthenticationContext). This property
///             is ignored if the authentication reason was provided by caller.
@property (nonatomic, copy) NSString *localizedReason API_AVAILABLE(macos(10.13), ios(11.0)) API_UNAVAILABLE(watchos, tvos);

/// Allows running authentication in non-interactive mode.
///
/// @discussion If the context is used in a keychain query by the means of kSecUseAuthenticationContext,
///             then setting this property to YES has the same effect as passing kSecUseNoAuthenticationUI
///             in the query, i.e. the keychain call will eventually fail with errSecInteractionNotAllowed
///             instead of displaying the authentication UI.
///
///             If this property is used with a LocalAuthentication evaluation, it will eventually fail with
///             LAErrorNotInteractive instead of displaying the authentication UI.
@property (nonatomic) BOOL interactionNotAllowed API_AVAILABLE(macos(10.13), ios(11.0)) API_UNAVAILABLE(watchos, tvos);


typedef NS_ENUM(NSInteger, LABiometryType)
{
    /// The device does not support biometry.
    LABiometryTypeNone API_AVAILABLE(macos(10.13.2), ios(11.2)),
    LABiometryNone API_DEPRECATED_WITH_REPLACEMENT("LABiometryTypeNone", macos(10.13, 10.13.2), ios(11.0, 11.2)) = LABiometryTypeNone,
    
    /// The device supports Touch ID.
    LABiometryTypeTouchID,
    
    /// The device supports Face ID.
    LABiometryTypeFaceID API_AVAILABLE(macos(10.15)),
} API_AVAILABLE(macos(10.13.2), ios(11.0)) API_UNAVAILABLE(watchos, tvos);


/// Indicates the type of the biometry supported by the device.
///
/// @discussion  This property is set when canEvaluatePolicy has been called for a biometric policy.
///              The default value is LABiometryTypeNone.
@property (nonatomic, readonly) LABiometryType biometryType API_AVAILABLE(macos(10.13.2), ios(11.0)) API_UNAVAILABLE(watchos, tvos);


@end

NS_ASSUME_NONNULL_END
