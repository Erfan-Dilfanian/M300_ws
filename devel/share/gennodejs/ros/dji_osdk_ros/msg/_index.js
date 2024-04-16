
"use strict";

let WaypointV2AssociateTrigger = require('./WaypointV2AssociateTrigger.js');
let Gimbal = require('./Gimbal.js');
let FlightAnomaly = require('./FlightAnomaly.js');
let VOPosition = require('./VOPosition.js');
let SmartBatteryState = require('./SmartBatteryState.js');
let GPSUTC = require('./GPSUTC.js');
let WaypointV2Action = require('./WaypointV2Action.js');
let WaypointV2CameraActuator = require('./WaypointV2CameraActuator.js');
let WaypointV2Config = require('./WaypointV2Config.js');
let WaypointV2AircraftControlActuator = require('./WaypointV2AircraftControlActuator.js');
let BatteryState = require('./BatteryState.js');
let WaypointV2SampleReachPointTrigger = require('./WaypointV2SampleReachPointTrigger.js');
let WaypointV2IntervalTrigger = require('./WaypointV2IntervalTrigger.js');
let WaypointV2AircraftControlActuatorFlying = require('./WaypointV2AircraftControlActuatorFlying.js');
let MissionWaypoint = require('./MissionWaypoint.js');
let MobileData = require('./MobileData.js');
let PayloadData = require('./PayloadData.js');
let WaypointV2CameraActuatorFocalLengthParam = require('./WaypointV2CameraActuatorFocalLengthParam.js');
let WaypointV2CameraActuatorFocusParam = require('./WaypointV2CameraActuatorFocusParam.js');
let WaypointList = require('./WaypointList.js');
let HMSPushInfo = require('./HMSPushInfo.js');
let FCTimeInUTC = require('./FCTimeInUTC.js');
let MissionWaypointAction = require('./MissionWaypointAction.js');
let MissionWaypointTask = require('./MissionWaypointTask.js');
let WaypointV2TrajectoryTrigger = require('./WaypointV2TrajectoryTrigger.js');
let SmartBatteryDynamicInfo = require('./SmartBatteryDynamicInfo.js');
let WaypointV2ReachpointTrigger = require('./WaypointV2ReachpointTrigger.js');
let BatteryWholeInfo = require('./BatteryWholeInfo.js');
let WaypointV2InitSetting = require('./WaypointV2InitSetting.js');
let WaypointV2 = require('./WaypointV2.js');
let Waypoint = require('./Waypoint.js');
let WaypointV2GimbalActuatorRotationParam = require('./WaypointV2GimbalActuatorRotationParam.js');
let MissionHotpointTask = require('./MissionHotpointTask.js');
let WaypointV2AircraftControlActuatorRotateHeading = require('./WaypointV2AircraftControlActuatorRotateHeading.js');
let WaypointV2MissionStatePush = require('./WaypointV2MissionStatePush.js');
let JoystickParams = require('./JoystickParams.js');
let WaypointV2GimbalActuator = require('./WaypointV2GimbalActuator.js');
let WaypointV2MissionEventPush = require('./WaypointV2MissionEventPush.js');

module.exports = {
  WaypointV2AssociateTrigger: WaypointV2AssociateTrigger,
  Gimbal: Gimbal,
  FlightAnomaly: FlightAnomaly,
  VOPosition: VOPosition,
  SmartBatteryState: SmartBatteryState,
  GPSUTC: GPSUTC,
  WaypointV2Action: WaypointV2Action,
  WaypointV2CameraActuator: WaypointV2CameraActuator,
  WaypointV2Config: WaypointV2Config,
  WaypointV2AircraftControlActuator: WaypointV2AircraftControlActuator,
  BatteryState: BatteryState,
  WaypointV2SampleReachPointTrigger: WaypointV2SampleReachPointTrigger,
  WaypointV2IntervalTrigger: WaypointV2IntervalTrigger,
  WaypointV2AircraftControlActuatorFlying: WaypointV2AircraftControlActuatorFlying,
  MissionWaypoint: MissionWaypoint,
  MobileData: MobileData,
  PayloadData: PayloadData,
  WaypointV2CameraActuatorFocalLengthParam: WaypointV2CameraActuatorFocalLengthParam,
  WaypointV2CameraActuatorFocusParam: WaypointV2CameraActuatorFocusParam,
  WaypointList: WaypointList,
  HMSPushInfo: HMSPushInfo,
  FCTimeInUTC: FCTimeInUTC,
  MissionWaypointAction: MissionWaypointAction,
  MissionWaypointTask: MissionWaypointTask,
  WaypointV2TrajectoryTrigger: WaypointV2TrajectoryTrigger,
  SmartBatteryDynamicInfo: SmartBatteryDynamicInfo,
  WaypointV2ReachpointTrigger: WaypointV2ReachpointTrigger,
  BatteryWholeInfo: BatteryWholeInfo,
  WaypointV2InitSetting: WaypointV2InitSetting,
  WaypointV2: WaypointV2,
  Waypoint: Waypoint,
  WaypointV2GimbalActuatorRotationParam: WaypointV2GimbalActuatorRotationParam,
  MissionHotpointTask: MissionHotpointTask,
  WaypointV2AircraftControlActuatorRotateHeading: WaypointV2AircraftControlActuatorRotateHeading,
  WaypointV2MissionStatePush: WaypointV2MissionStatePush,
  JoystickParams: JoystickParams,
  WaypointV2GimbalActuator: WaypointV2GimbalActuator,
  WaypointV2MissionEventPush: WaypointV2MissionEventPush,
};
