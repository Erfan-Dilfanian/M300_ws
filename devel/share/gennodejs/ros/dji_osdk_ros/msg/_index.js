
"use strict";

let HMSPushInfo = require('./HMSPushInfo.js');
let WaypointV2AssociateTrigger = require('./WaypointV2AssociateTrigger.js');
let WaypointV2TrajectoryTrigger = require('./WaypointV2TrajectoryTrigger.js');
let WaypointV2AircraftControlActuatorFlying = require('./WaypointV2AircraftControlActuatorFlying.js');
let FCTimeInUTC = require('./FCTimeInUTC.js');
let FlightAnomaly = require('./FlightAnomaly.js');
let SmartBatteryState = require('./SmartBatteryState.js');
let GPSUTC = require('./GPSUTC.js');
let MissionHotpointTask = require('./MissionHotpointTask.js');
let SmartBatteryDynamicInfo = require('./SmartBatteryDynamicInfo.js');
let WaypointV2IntervalTrigger = require('./WaypointV2IntervalTrigger.js');
let Gimbal = require('./Gimbal.js');
let WaypointV2 = require('./WaypointV2.js');
let JoystickParams = require('./JoystickParams.js');
let WaypointV2MissionEventPush = require('./WaypointV2MissionEventPush.js');
let WaypointV2CameraActuatorFocusParam = require('./WaypointV2CameraActuatorFocusParam.js');
let WaypointV2Action = require('./WaypointV2Action.js');
let WaypointV2AircraftControlActuatorRotateHeading = require('./WaypointV2AircraftControlActuatorRotateHeading.js');
let MissionWaypointTask = require('./MissionWaypointTask.js');
let WaypointV2AircraftControlActuator = require('./WaypointV2AircraftControlActuator.js');
let WaypointV2SampleReachPointTrigger = require('./WaypointV2SampleReachPointTrigger.js');
let Waypoint = require('./Waypoint.js');
let WaypointV2InitSetting = require('./WaypointV2InitSetting.js');
let MissionWaypointAction = require('./MissionWaypointAction.js');
let MissionWaypoint = require('./MissionWaypoint.js');
let PayloadData = require('./PayloadData.js');
let WaypointV2GimbalActuator = require('./WaypointV2GimbalActuator.js');
let WaypointV2GimbalActuatorRotationParam = require('./WaypointV2GimbalActuatorRotationParam.js');
let MobileData = require('./MobileData.js');
let WaypointV2CameraActuator = require('./WaypointV2CameraActuator.js');
let BatteryState = require('./BatteryState.js');
let WaypointV2MissionStatePush = require('./WaypointV2MissionStatePush.js');
let WaypointV2ReachpointTrigger = require('./WaypointV2ReachpointTrigger.js');
let WaypointV2Config = require('./WaypointV2Config.js');
let BatteryWholeInfo = require('./BatteryWholeInfo.js');
let WaypointList = require('./WaypointList.js');
let WaypointV2CameraActuatorFocalLengthParam = require('./WaypointV2CameraActuatorFocalLengthParam.js');
let VOPosition = require('./VOPosition.js');

module.exports = {
  HMSPushInfo: HMSPushInfo,
  WaypointV2AssociateTrigger: WaypointV2AssociateTrigger,
  WaypointV2TrajectoryTrigger: WaypointV2TrajectoryTrigger,
  WaypointV2AircraftControlActuatorFlying: WaypointV2AircraftControlActuatorFlying,
  FCTimeInUTC: FCTimeInUTC,
  FlightAnomaly: FlightAnomaly,
  SmartBatteryState: SmartBatteryState,
  GPSUTC: GPSUTC,
  MissionHotpointTask: MissionHotpointTask,
  SmartBatteryDynamicInfo: SmartBatteryDynamicInfo,
  WaypointV2IntervalTrigger: WaypointV2IntervalTrigger,
  Gimbal: Gimbal,
  WaypointV2: WaypointV2,
  JoystickParams: JoystickParams,
  WaypointV2MissionEventPush: WaypointV2MissionEventPush,
  WaypointV2CameraActuatorFocusParam: WaypointV2CameraActuatorFocusParam,
  WaypointV2Action: WaypointV2Action,
  WaypointV2AircraftControlActuatorRotateHeading: WaypointV2AircraftControlActuatorRotateHeading,
  MissionWaypointTask: MissionWaypointTask,
  WaypointV2AircraftControlActuator: WaypointV2AircraftControlActuator,
  WaypointV2SampleReachPointTrigger: WaypointV2SampleReachPointTrigger,
  Waypoint: Waypoint,
  WaypointV2InitSetting: WaypointV2InitSetting,
  MissionWaypointAction: MissionWaypointAction,
  MissionWaypoint: MissionWaypoint,
  PayloadData: PayloadData,
  WaypointV2GimbalActuator: WaypointV2GimbalActuator,
  WaypointV2GimbalActuatorRotationParam: WaypointV2GimbalActuatorRotationParam,
  MobileData: MobileData,
  WaypointV2CameraActuator: WaypointV2CameraActuator,
  BatteryState: BatteryState,
  WaypointV2MissionStatePush: WaypointV2MissionStatePush,
  WaypointV2ReachpointTrigger: WaypointV2ReachpointTrigger,
  WaypointV2Config: WaypointV2Config,
  BatteryWholeInfo: BatteryWholeInfo,
  WaypointList: WaypointList,
  WaypointV2CameraActuatorFocalLengthParam: WaypointV2CameraActuatorFocalLengthParam,
  VOPosition: VOPosition,
};
