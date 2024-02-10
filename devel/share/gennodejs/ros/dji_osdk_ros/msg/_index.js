
"use strict";

let FlightAnomaly = require('./FlightAnomaly.js');
let WaypointV2IntervalTrigger = require('./WaypointV2IntervalTrigger.js');
let SmartBatteryDynamicInfo = require('./SmartBatteryDynamicInfo.js');
let MissionWaypointAction = require('./MissionWaypointAction.js');
let VOPosition = require('./VOPosition.js');
let SmartBatteryState = require('./SmartBatteryState.js');
let WaypointV2CameraActuatorFocusParam = require('./WaypointV2CameraActuatorFocusParam.js');
let WaypointV2GimbalActuator = require('./WaypointV2GimbalActuator.js');
let WaypointV2CameraActuator = require('./WaypointV2CameraActuator.js');
let MissionWaypointTask = require('./MissionWaypointTask.js');
let WaypointV2ReachpointTrigger = require('./WaypointV2ReachpointTrigger.js');
let WaypointV2MissionStatePush = require('./WaypointV2MissionStatePush.js');
let WaypointV2CameraActuatorFocalLengthParam = require('./WaypointV2CameraActuatorFocalLengthParam.js');
let WaypointV2AircraftControlActuatorFlying = require('./WaypointV2AircraftControlActuatorFlying.js');
let WaypointV2InitSetting = require('./WaypointV2InitSetting.js');
let GPSUTC = require('./GPSUTC.js');
let WaypointV2MissionEventPush = require('./WaypointV2MissionEventPush.js');
let PayloadData = require('./PayloadData.js');
let WaypointV2AssociateTrigger = require('./WaypointV2AssociateTrigger.js');
let WaypointList = require('./WaypointList.js');
let WaypointV2Config = require('./WaypointV2Config.js');
let WaypointV2 = require('./WaypointV2.js');
let BatteryState = require('./BatteryState.js');
let WaypointV2SampleReachPointTrigger = require('./WaypointV2SampleReachPointTrigger.js');
let WaypointV2GimbalActuatorRotationParam = require('./WaypointV2GimbalActuatorRotationParam.js');
let MissionWaypoint = require('./MissionWaypoint.js');
let FCTimeInUTC = require('./FCTimeInUTC.js');
let Waypoint = require('./Waypoint.js');
let WaypointV2AircraftControlActuatorRotateHeading = require('./WaypointV2AircraftControlActuatorRotateHeading.js');
let WaypointV2AircraftControlActuator = require('./WaypointV2AircraftControlActuator.js');
let JoystickParams = require('./JoystickParams.js');
let MobileData = require('./MobileData.js');
let WaypointV2Action = require('./WaypointV2Action.js');
let MissionHotpointTask = require('./MissionHotpointTask.js');
let BatteryWholeInfo = require('./BatteryWholeInfo.js');
let Gimbal = require('./Gimbal.js');
let WaypointV2TrajectoryTrigger = require('./WaypointV2TrajectoryTrigger.js');
let HMSPushInfo = require('./HMSPushInfo.js');

module.exports = {
  FlightAnomaly: FlightAnomaly,
  WaypointV2IntervalTrigger: WaypointV2IntervalTrigger,
  SmartBatteryDynamicInfo: SmartBatteryDynamicInfo,
  MissionWaypointAction: MissionWaypointAction,
  VOPosition: VOPosition,
  SmartBatteryState: SmartBatteryState,
  WaypointV2CameraActuatorFocusParam: WaypointV2CameraActuatorFocusParam,
  WaypointV2GimbalActuator: WaypointV2GimbalActuator,
  WaypointV2CameraActuator: WaypointV2CameraActuator,
  MissionWaypointTask: MissionWaypointTask,
  WaypointV2ReachpointTrigger: WaypointV2ReachpointTrigger,
  WaypointV2MissionStatePush: WaypointV2MissionStatePush,
  WaypointV2CameraActuatorFocalLengthParam: WaypointV2CameraActuatorFocalLengthParam,
  WaypointV2AircraftControlActuatorFlying: WaypointV2AircraftControlActuatorFlying,
  WaypointV2InitSetting: WaypointV2InitSetting,
  GPSUTC: GPSUTC,
  WaypointV2MissionEventPush: WaypointV2MissionEventPush,
  PayloadData: PayloadData,
  WaypointV2AssociateTrigger: WaypointV2AssociateTrigger,
  WaypointList: WaypointList,
  WaypointV2Config: WaypointV2Config,
  WaypointV2: WaypointV2,
  BatteryState: BatteryState,
  WaypointV2SampleReachPointTrigger: WaypointV2SampleReachPointTrigger,
  WaypointV2GimbalActuatorRotationParam: WaypointV2GimbalActuatorRotationParam,
  MissionWaypoint: MissionWaypoint,
  FCTimeInUTC: FCTimeInUTC,
  Waypoint: Waypoint,
  WaypointV2AircraftControlActuatorRotateHeading: WaypointV2AircraftControlActuatorRotateHeading,
  WaypointV2AircraftControlActuator: WaypointV2AircraftControlActuator,
  JoystickParams: JoystickParams,
  MobileData: MobileData,
  WaypointV2Action: WaypointV2Action,
  MissionHotpointTask: MissionHotpointTask,
  BatteryWholeInfo: BatteryWholeInfo,
  Gimbal: Gimbal,
  WaypointV2TrajectoryTrigger: WaypointV2TrajectoryTrigger,
  HMSPushInfo: HMSPushInfo,
};
