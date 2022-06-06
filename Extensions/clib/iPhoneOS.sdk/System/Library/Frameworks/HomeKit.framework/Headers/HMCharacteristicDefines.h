//
//  HMCharacteristicDefines.h
//  HomeKit
//
//  Copyright (c) 2013-2015 Apple Inc. All rights reserved.
//

#import <HomeKit/HMDefines.h>

/*!
 * @group Characteristic Valid Values
 *
 * @brief These constants define valid values for characteristic types supported by the HomeKit Accessory Profile for HomeKit based accessories.
 */

/*!
 @enum      HMCharacteristicValueDoorState

 @constant  HMCharacteristicValueDoorStateOpen          Door is fully open.
 @constant  HMCharacteristicValueDoorStateClosed        Door is fully closed.
 @constant  HMCharacteristicValueDoorStateOpening       Door is actively opening.
 @constant  HMCharacteristicValueDoorStateClosing       Door is actively closed.
 @constant  HMCharacteristicValueDoorStateStopped       Door is not moving, and is not fully open nor fully closed.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueDoorState) {
    HMCharacteristicValueDoorStateOpen = 0,
    HMCharacteristicValueDoorStateClosed,
    HMCharacteristicValueDoorStateOpening,
    HMCharacteristicValueDoorStateClosing,
    HMCharacteristicValueDoorStateStopped,
} API_AVAILABLE(ios(8.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueHeatingCooling

 @constant  HMCharacteristicValueHeatingCoolingOff      Heating/cooling is off.
 @constant  HMCharacteristicValueHeatingCoolingHeat     Heating/cooling is heating.
 @constant  HMCharacteristicValueHeatingCoolingCool     Heating/cooling is cooling.
 @constant  HMCharacteristicValueHeatingCoolingAuto     Heating/cooling is auto.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueHeatingCooling) {
    HMCharacteristicValueHeatingCoolingOff = 0,
    HMCharacteristicValueHeatingCoolingHeat,
    HMCharacteristicValueHeatingCoolingCool,
    HMCharacteristicValueHeatingCoolingAuto,
} API_AVAILABLE(ios(8.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueRotationDirection

 @constant  HMCharacteristicValueRotationDirectionClockwise             Clockwise rotation.
 @constant  HMCharacteristicValueRotationDirectionCounterClockwise      Counter-clockwise rotation.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueRotationDirection) {
    HMCharacteristicValueRotationDirectionClockwise = 0,
    HMCharacteristicValueRotationDirectionCounterClockwise,
} API_AVAILABLE(ios(8.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueTemperatureUnit

 @constant  HMCharacteristicValueTemperatureUnitCelsius                 Temperature unit in Celsius.
 @constant  HMCharacteristicValueTemperatureUnitFahrenheit              Temperature unit in Fahrenheit.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueTemperatureUnit) {
    HMCharacteristicValueTemperatureUnitCelsius = 0,
    HMCharacteristicValueTemperatureUnitFahrenheit,
} API_AVAILABLE(ios(8.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueLockMechanismState

 @constant  HMCharacteristicValueLockMechanismStateUnsecured            Lock mechanism is unsecured.
 @constant  HMCharacteristicValueLockMechanismStateSecured              Lock mechanism is secured.
 @constant  HMCharacteristicValueLockMechanismStateJammed               Lock mechanism is jammed.
 @constant  HMCharacteristicValueLockMechanismStateUnknown              Lock mechanism is unknown.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueLockMechanismState) {
    HMCharacteristicValueLockMechanismStateUnsecured = 0,
    HMCharacteristicValueLockMechanismStateSecured,
    HMCharacteristicValueLockMechanismStateJammed,
    HMCharacteristicValueLockMechanismStateUnknown,
} API_AVAILABLE(ios(8.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueLockMechanismLastKnownAction

 @constant  HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovementInterior       Last known action was secured using physical movement, interior.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovementInterior     Last known action was unsecured using physical movement, interior.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovementExterior       Last known action was secured using physical movement, exterior.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovementExterior     Last known action was unsecured using physical movement, exterior.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionSecuredWithKeypad                          Last known action was secured with keypad.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionUnsecuredWithKeypad                        Last known action was unsecured with keypad.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionSecuredRemotely                            Last known action was secured remotely.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionUnsecuredRemotely                          Last known action was unsecured remotely.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionSecuredWithAutomaticSecureTimeout          Last known action was secured automatically after timeout.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovement               Last known action was secured using physical movement.
 @constant  HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovement             Last known action was unsecured using physical movement.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueLockMechanismLastKnownAction) {
    HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovementInterior = 0,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovementInterior,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovementExterior,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovementExterior,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredWithKeypad,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredWithKeypad,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredRemotely,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredRemotely,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredWithAutomaticSecureTimeout,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovement,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovement,
} API_AVAILABLE(ios(8.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);


/*!
 @enum      HMCharacteristicValueAirParticulateSize

 @constant  HMCharacteristicValueAirParticulateSize2_5          Air particulate size of 2.5 micrometers.
 @constant  HMCharacteristicValueAirParticulateSize10           Air particulate size of 10 micrometers.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueAirParticulateSize) {
    HMCharacteristicValueAirParticulateSize2_5 = 0,
    HMCharacteristicValueAirParticulateSize10,
} API_AVAILABLE(ios(9.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);


/*!
 @enum      HMCharacteristicValueAirQuality

 @constant  HMCharacteristicValueAirQualityUnknown              Air quality is unknown.
 @constant  HMCharacteristicValueAirQualityExcellent            Air quality is excellent.
 @constant  HMCharacteristicValueAirQualityGood                 Air quality is good.
 @constant  HMCharacteristicValueAirQualityFair                 Air quality is fair.
 @constant  HMCharacteristicValueAirQualityInferior             Air quality is inferior.
 @constant  HMCharacteristicValueAirQualityPoor                 Air quality is poor.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueAirQuality) {
    HMCharacteristicValueAirQualityUnknown = 0,
    HMCharacteristicValueAirQualityExcellent,
    HMCharacteristicValueAirQualityGood,
    HMCharacteristicValueAirQualityFair,
    HMCharacteristicValueAirQualityInferior,
    HMCharacteristicValueAirQualityPoor,
} API_AVAILABLE(ios(9.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);


/*!
 @enum      HMCharacteristicValuePositionState

 @constant  HMCharacteristicValuePositionStateClosing           Position is moving towards minimum value.
 @constant  HMCharacteristicValuePositionStateOpening           Position is moving towards maximum value.
 @constant  HMCharacteristicValuePositionStateStopped           Position is Stopped.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValuePositionState) {
    HMCharacteristicValuePositionStateClosing = 0,
    HMCharacteristicValuePositionStateOpening,
    HMCharacteristicValuePositionStateStopped,
} API_AVAILABLE(ios(9.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);


/*!
 @enum      HMCharacteristicValueCurrentSecuritySystemState

 @constant  HMCharacteristicValueCurrentSecuritySystemStateStayArm       Home is occupied and residents are active.
 @constant  HMCharacteristicValueCurrentSecuritySystemStateAwayArm       Home is unoccupied.
 @constant  HMCharacteristicValueCurrentSecuritySystemStateNightArm      Home is occupied and residents are sleeping.
 @constant  HMCharacteristicValueCurrentSecuritySystemStateDisarmed      SecuritySystem is disarmed.
 @constant  HMCharacteristicValueCurrentSecuritySystemStateTriggered     SecuritySystem is triggered.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCurrentSecuritySystemState) {
    HMCharacteristicValueCurrentSecuritySystemStateStayArm = 0,
    HMCharacteristicValueCurrentSecuritySystemStateAwayArm,
    HMCharacteristicValueCurrentSecuritySystemStateNightArm,
    HMCharacteristicValueCurrentSecuritySystemStateDisarmed,
    HMCharacteristicValueCurrentSecuritySystemStateTriggered,
} API_AVAILABLE(ios(9.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);


/*!
 @enum      HMCharacteristicValueTargetSecuritySystemState

 @constant  HMCharacteristicValueTargetSecuritySystemStateStayArm        Home is occupied and residents are active.
 @constant  HMCharacteristicValueTargetSecuritySystemStateAwayArm        Home is unoccupied.
 @constant  HMCharacteristicValueTargetSecuritySystemStateNightArm       Home is occupied and residents are sleeping.
 @constant  HMCharacteristicValueTargetSecuritySystemStateDisarm         Disarm.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueTargetSecuritySystemState) {
    HMCharacteristicValueTargetSecuritySystemStateStayArm = 0,
    HMCharacteristicValueTargetSecuritySystemStateAwayArm,
    HMCharacteristicValueTargetSecuritySystemStateNightArm,
    HMCharacteristicValueTargetSecuritySystemStateDisarm,
} API_AVAILABLE(ios(9.0), watchos(2.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueBatteryStatus

 @constant  HMCharacteristicValueBatteryStatusNormal        Battery status is normal.
 @constant  HMCharacteristicValueBatteryStatusLow           Battery status is low.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueBatteryStatus) {
    HMCharacteristicValueBatteryStatusNormal = 0,
    HMCharacteristicValueBatteryStatusLow,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueJammedStatus

 @constant  HMCharacteristicValueJammedStatusNone               Not Jammed.
 @constant  HMCharacteristicValueJammedStatusJammed             Jammed.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueJammedStatus) {
    HMCharacteristicValueJammedStatusNone = 0,
    HMCharacteristicValueJammedStatusJammed,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueTamperStatus

 @constant  HMCharacteristicValueTamperStatusNone               Accessory is not tampered with.
 @constant  HMCharacteristicValueTamperStatusTampered           Accessory is tampered with.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueTamperedStatus) {
    HMCharacteristicValueTamperedStatusNone = 0,
    HMCharacteristicValueTamperedStatusTampered,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueLeakDetectionStatus

 @constant  HMCharacteristicValueLeakDetectionStatusNone        Leak is not detected.
 @constant  HMCharacteristicValueLeakDetectionStatusDetected    Leak is detected.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueLeakStatus) {
    HMCharacteristicValueLeakStatusNone = 0,
    HMCharacteristicValueLeakStatusDetected,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueSmokeDetectionStatus

 @constant  HMCharacteristicValueSmokeDetectionStatusNone       Smoke is not detected.
 @constant  HMCharacteristicValueSmokeDetectionStatusDetected   Smoke is detected.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueSmokeDetectionStatus) {
    HMCharacteristicValueSmokeDetectionStatusNone = 0,
    HMCharacteristicValueSmokeDetectionStatusDetected,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueChargingState

 @constant  HMCharacteristicValueChargingStateNone              Charging is not in progress.
 @constant  HMCharacteristicValueChargingStateInProgress        Charging is in progress.
 @constant  HMCharacteristicValueChargingStateNotChargeable     Charging is not supported.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueChargingState) {
    HMCharacteristicValueChargingStateNone = 0,
    HMCharacteristicValueChargingStateInProgress,
    HMCharacteristicValueChargingStateNotChargeable  API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)),  
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);


/*!
 @enum      HMCharacteristicValueContactState

 @constant  HMCharacteristicValueContactStateDetected           Contact is detected.
 @constant  HMCharacteristicValueContactStateNone               Contact is not detected.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueContactState) {
    HMCharacteristicValueContactStateDetected = 0,
    HMCharacteristicValueContactStateNone,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueStatusFault
 
 @constant  HMCharacteristicValueStatusFaultNoFault               No Fault.
 @constant  HMCharacteristicValueStatusFaultGeneralFault          General Fault.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueStatusFault) {
    HMCharacteristicValueStatusFaultNoFault = 0,
    HMCharacteristicValueStatusFaultGeneralFault,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueCarbonMonoxideDetectionStatus

 @constant  HMCharacteristicValueCarbonMonoxideDetectionStatusNotDetected       Carbon monoxide is not detected.
 @constant  HMCharacteristicValueCarbonMonoxideDetectionStatusDetected          Carbon monoxide is detected.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCarbonMonoxideDetectionStatus) {
    HMCharacteristicValueCarbonMonoxideDetectionStatusNotDetected = 0,
    HMCharacteristicValueCarbonMonoxideDetectionStatusDetected,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueCarbonDioxideDetectionStatus

 @constant  HMCharacteristicValueCarbonDioxideDetectionStatusNotDetected    Carbon dioxide is not detected.
 @constant  HMCharacteristicValueCarbonDioxideDetectionStatusDetected       Carbon dioxide is detected.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCarbonDioxideDetectionStatus) {
    HMCharacteristicValueCarbonDioxideDetectionStatusNotDetected = 0,
    HMCharacteristicValueCarbonDioxideDetectionStatusDetected,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueOccupancyStatus

 @constant  HMCharacteristicValueOccupancyStatusNotOccupied     Occupancy is not detected.
 @constant  HMCharacteristicValueOccupancyStatusOccupied        Occupancy is detected.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueOccupancyStatus) {
    HMCharacteristicValueOccupancyStatusNotOccupied = 0,
    HMCharacteristicValueOccupancyStatusOccupied,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueSecuritySystemAlarmType

 @constant  HMCharacteristicValueSecuritySystemAlarmTypeNoAlarm     No alarm.
 @constant  HMCharacteristicValueSecuritySystemAlarmTypeUnknown     Unknown alarm type.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueSecuritySystemAlarmType) {
    HMCharacteristicValueSecuritySystemAlarmTypeNoAlarm = 0,
    HMCharacteristicValueSecuritySystemAlarmTypeUnknown,
} API_AVAILABLE(ios(10.0), watchos(3.0), tvos(10.0)) API_UNAVAILABLE(macos);


/*!
 @enum      HMCharacteristicValueLockPhysicalControlsState

 @constant  HMCharacteristicValueLockPhysicalControlsStateNotLocked     Physical controls not locked.
 @constant  HMCharacteristicValueLockPhysicalControlsStateLocked        Physical controls locked.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueLockPhysicalControlsState) {
    HMCharacteristicValueLockPhysicalControlsStateNotLocked = 0,
    HMCharacteristicValueLockPhysicalControlsStateLocked,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueCurrentAirPurifierState

 @constant  HMCharacteristicValueCurrentAirPurifierStateInactive    Inactive.
 @constant  HMCharacteristicValueCurrentAirPurifierStateIdle        Idle.
 @constant  HMCharacteristicValueCurrentAirPurifierStateActive      Active.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCurrentAirPurifierState) {
    HMCharacteristicValueCurrentAirPurifierStateInactive = 0,
    HMCharacteristicValueCurrentAirPurifierStateIdle,
    HMCharacteristicValueCurrentAirPurifierStateActive,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueTargetAirPurifierState

 @constant  HMCharacteristicValueTargetAirPurifierStateManual       Air Purifier is in manual mode.
 @constant  HMCharacteristicValueTargetAirPurifierStateAutomatic    Air Purifier is in automatic mode.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueTargetAirPurifierState) {
    HMCharacteristicValueTargetAirPurifierStateManual = 0,
    HMCharacteristicValueTargetAirPurifierStateAutomatic,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueCurrentSlatState

 @constant  HMCharacteristicValueCurrentSlatStateStationary         Slats are stationary.
 @constant  HMCharacteristicValueCurrentSlatStateJammed             Slats are jammed.
 @constant  HMCharacteristicValueCurrentSlatStateOscillating        Slats are oscillating.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCurrentSlatState) {
    HMCharacteristicValueCurrentSlatStateStationary = 0,
    HMCharacteristicValueCurrentSlatStateJammed,
    HMCharacteristicValueCurrentSlatStateOscillating,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueSlatType

 @constant  HMCharacteristicValueSlatTypeHorizontal          Slat type is horizontal.
 @constant  HMCharacteristicValueSlatTypeVertical            Slat type is vertical.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueSlatType) {
    HMCharacteristicValueSlatTypeHorizontal = 0,
    HMCharacteristicValueSlatTypeVertical,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueFilterChange

 @constant  HMCharacteristicValueFilterChangeNotNeeded      Filter does not need to be changed.
 @constant  HMCharacteristicValueFilterChangeNeeded         Filter needs to be changed.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueFilterChange) {
    HMCharacteristicValueFilterChangeNotNeeded = 0,
    HMCharacteristicValueFilterChangeNeeded,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueCurrentFanState

 @constant  HMCharacteristicValueCurrentFanStateInactive            Inactive.
 @constant  HMCharacteristicValueCurrentFanStateIdle                Idle.
 @constant  HMCharacteristicValueCurrentFanStateActive              Active.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCurrentFanState) {
    HMCharacteristicValueCurrentFanStateInactive = 0,
    HMCharacteristicValueCurrentFanStateIdle,
    HMCharacteristicValueCurrentFanStateActive,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueTargetFanState

 @constant  HMCharacteristicValueTargetFanStateManual       Fan is in manual mode.
 @constant  HMCharacteristicValueTargetFanStateAutomatic    Fan is in automatic mode.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueTargetFanState) {
    HMCharacteristicValueTargetFanStateManual = 0,
    HMCharacteristicValueTargetFanStateAutomatic,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueCurrentHeaterCoolerState

 @constant  HMCharacteristicValueCurrentHeaterCoolerStateInactive   Inactive.
 @constant  HMCharacteristicValueCurrentHeaterCoolerStateIdle       Idle.
 @constant  HMCharacteristicValueCurrentHeaterCoolerStateHeating    Heating.
 @constant  HMCharacteristicValueCurrentHeaterCoolerStateCooling    Cooling.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCurrentHeaterCoolerState) {
    HMCharacteristicValueCurrentHeaterCoolerStateInactive = 0,
    HMCharacteristicValueCurrentHeaterCoolerStateIdle,
    HMCharacteristicValueCurrentHeaterCoolerStateHeating,
    HMCharacteristicValueCurrentHeaterCoolerStateCooling,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueTargetHeaterCoolerState

 @constant  HMCharacteristicValueTargetHeaterCoolerStateAutomatic       Automatic mode.
 @constant  HMCharacteristicValueTargetHeaterCoolerStateHeat            Heat mode.
 @constant  HMCharacteristicValueTargetHeaterCoolerStateCool            Cool mode.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueTargetHeaterCoolerState) {
    HMCharacteristicValueTargetHeaterCoolerStateAutomatic = 0,
    HMCharacteristicValueTargetHeaterCoolerStateHeat,
    HMCharacteristicValueTargetHeaterCoolerStateCool,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueCurrentHumidifierDehumidifierState

 @constant  HMCharacteristicValueCurrentHumidifierDehumidifierStateInactive         Inactive.
 @constant  HMCharacteristicValueCurrentHumidifierDehumidifierStateIdle             Idle.
 @constant  HMCharacteristicValueCurrentHumidifierDehumidifierStateHumidifying      Humidifying.
 @constant  HMCharacteristicValueCurrentHumidifierDehumidifierStateDehumidifying    Dehumidifying.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueCurrentHumidifierDehumidifierState) {
    HMCharacteristicValueCurrentHumidifierDehumidifierStateInactive = 0,
    HMCharacteristicValueCurrentHumidifierDehumidifierStateIdle,
    HMCharacteristicValueCurrentHumidifierDehumidifierStateHumidifying,
    HMCharacteristicValueCurrentHumidifierDehumidifierStateDehumidifying,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueTargetHumidifierDehumidifierState

 @constant  HMCharacteristicValueTargetHumidifierDehumidifierStateAutomatic             Automatic mode.
 @constant  HMCharacteristicValueTargetHumidifierDehumidifierStateHumidify              Humidify mode.
 @constant  HMCharacteristicValueTargetHumidifierDehumidifierStateDehumidify            Dehumidify mode.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueTargetHumidifierDehumidifierState) {
    HMCharacteristicValueTargetHumidifierDehumidifierStateAutomatic = 0,
    HMCharacteristicValueTargetHumidifierDehumidifierStateHumidify,
    HMCharacteristicValueTargetHumidifierDehumidifierStateDehumidify,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueSwingMode

 @constant  HMCharacteristicValueSwingModeDisabled                  Swing mode is disabled.
 @constant  HMCharacteristicValueSwingModeEnabled                   Swing mode is enabled.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueSwingMode) {
    HMCharacteristicValueSwingModeDisabled = 0,
    HMCharacteristicValueSwingModeEnabled,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueActivationState

 @constant  HMCharacteristicValueActivationStateInactive            Service is inactive.
 @constant  HMCharacteristicValueActivationStateActive              Service is active.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueActivationState) {
    HMCharacteristicValueActivationStateInactive = 0,
    HMCharacteristicValueActivationStateActive,
} API_AVAILABLE(ios(10.2), watchos(3.1.1), tvos(10.1)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueInputEvent

 @constant  HMCharacteristicValueInputEventSinglePress              Single tap or press.
 @constant  HMCharacteristicValueInputEventDoublePress              Double tap or press.
 @constant  HMCharacteristicValueInputEventLongPress                Long press.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueInputEvent) {
    HMCharacteristicValueInputEventSinglePress = 0,
    HMCharacteristicValueInputEventDoublePress,
    HMCharacteristicValueInputEventLongPress,
} API_AVAILABLE(ios(10.3), watchos(3.2), tvos(10.2)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueLabelNamespace

 @constant  HMCharacteristicValueLabelNamespaceDot                      Service labels are dots.
 @constant  HMCharacteristicValueLabelNamespaceNumeral                  Service labels are Arabic numerals.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueLabelNamespace) {
    HMCharacteristicValueLabelNamespaceDot = 0,
    HMCharacteristicValueLabelNamespaceNumeral,
} API_AVAILABLE(ios(10.3), watchos(3.2), tvos(10.2)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueProgramMode
 
 @constant  HMCharacteristicValueProgramModeNotScheduled                No programs scheduled.
 @constant  HMCharacteristicValueProgramModeScheduled                   Program scheduled.
 @constant  HMCharacteristicValueProgramModeScheduleOverriddenToManual  Schedule currently overridden to manual mode.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueProgramMode) {
    HMCharacteristicValueProgramModeNotScheduled = 0,
    HMCharacteristicValueProgramModeScheduled,
    HMCharacteristicValueProgramModeScheduleOverriddenToManual,
} API_AVAILABLE(ios(11.2), watchos(4.2), tvos(11.2)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueUsageState
 
 @constant  HMCharacteristicValueUsageStateNotInUse        Not in use.
 @constant  HMCharacteristicValueUsageStateInUse           Currently in use.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueUsageState) {
    HMCharacteristicValueUsageStateNotInUse = 0,
    HMCharacteristicValueUsageStateInUse,
} API_AVAILABLE(ios(11.2), watchos(4.2), tvos(11.2)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueValveType
 
 @constant  HMCharacteristicValueValveTypeGenericValve    Generic Valve.
 @constant  HMCharacteristicValueValveTypeIrrigation      Irrigation.
 @constant  HMCharacteristicValueValveTypeShowerHead      Shower Head.
 @constant  HMCharacteristicValueValveTypeWaterFaucet     Water Faucet.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueValveType) {
    HMCharacteristicValueValveTypeGenericValve = 0,
    HMCharacteristicValueValveTypeIrrigation,
    HMCharacteristicValueValveTypeShowerHead,
    HMCharacteristicValueValveTypeWaterFaucet,
} API_AVAILABLE(ios(11.2), watchos(4.2), tvos(11.2)) API_UNAVAILABLE(macos);

/*!
 @enum      HMCharacteristicValueConfigurationState
 
 @constant  HMCharacteristicValueConfigurationStateNotConfigured   Not Configured.
 @constant  HMCharacteristicValueConfigurationStateConfigured      Configured.
 */
typedef NS_ENUM(NSInteger, HMCharacteristicValueConfigurationState) {
    HMCharacteristicValueConfigurationStateNotConfigured = 0,
    HMCharacteristicValueConfigurationStateConfigured,
} API_AVAILABLE(ios(11.2), watchos(4.2), tvos(11.2)) API_UNAVAILABLE(macos);
