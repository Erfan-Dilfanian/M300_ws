
"use strict";

let FlightTaskControl = require('./FlightTaskControl.js')
let SetHomePoint = require('./SetHomePoint.js')
let SetGoHomeAltitude = require('./SetGoHomeAltitude.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let CameraFocusPoint = require('./CameraFocusPoint.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let CameraSetZoomPara = require('./CameraSetZoomPara.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let SetCurrentAircraftLocAsHomePoint = require('./SetCurrentAircraftLocAsHomePoint.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let Activation = require('./Activation.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let JoystickAction = require('./JoystickAction.js')
let StartWaypointV2Mission = require('./StartWaypointV2Mission.js')
let SendPayloadData = require('./SendPayloadData.js')
let MFIO = require('./MFIO.js')
let CameraShutterSpeed = require('./CameraShutterSpeed.js')
let CameraStartShootBurstPhoto = require('./CameraStartShootBurstPhoto.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let DroneArmControl = require('./DroneArmControl.js')
let ObtainControlAuthority = require('./ObtainControlAuthority.js')
let UploadWaypointV2Action = require('./UploadWaypointV2Action.js')
let CameraStartShootIntervalPhoto = require('./CameraStartShootIntervalPhoto.js')
let CameraStopShootPhoto = require('./CameraStopShootPhoto.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let SetGlobalCruisespeed = require('./SetGlobalCruisespeed.js')
let GetDroneType = require('./GetDroneType.js')
let GetGlobalCruisespeed = require('./GetGlobalCruisespeed.js')
let CameraEV = require('./CameraEV.js')
let CameraAction = require('./CameraAction.js')
let SubscribeWaypointV2Event = require('./SubscribeWaypointV2Event.js')
let CameraZoomCtrl = require('./CameraZoomCtrl.js')
let MissionStatus = require('./MissionStatus.js')
let MFIOConfig = require('./MFIOConfig.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let UploadWaypointV2Mission = require('./UploadWaypointV2Mission.js')
let InitWaypointV2Setting = require('./InitWaypointV2Setting.js')
let SetHardSync = require('./SetHardSync.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let GetAvoidEnable = require('./GetAvoidEnable.js')
let EmergencyBrake = require('./EmergencyBrake.js')
let PauseWaypointV2Mission = require('./PauseWaypointV2Mission.js')
let GetSingleBatteryDynamicInfo = require('./GetSingleBatteryDynamicInfo.js')
let CameraISO = require('./CameraISO.js')
let CameraTapZoomPoint = require('./CameraTapZoomPoint.js')
let MissionHpAction = require('./MissionHpAction.js')
let CameraStartShootAEBPhoto = require('./CameraStartShootAEBPhoto.js')
let ResumeWaypointV2Mission = require('./ResumeWaypointV2Mission.js')
let GetHMSData = require('./GetHMSData.js')
let CameraStartShootSinglePhoto = require('./CameraStartShootSinglePhoto.js')
let CameraAperture = require('./CameraAperture.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let GetM300StereoParams = require('./GetM300StereoParams.js')
let KillSwitch = require('./KillSwitch.js')
let SetAvoidEnable = require('./SetAvoidEnable.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let DownloadWaypointV2Mission = require('./DownloadWaypointV2Mission.js')
let GimbalAction = require('./GimbalAction.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let CameraRecordVideoAction = require('./CameraRecordVideoAction.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let SendMobileData = require('./SendMobileData.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let GenerateWaypointV2Action = require('./GenerateWaypointV2Action.js')
let SetupCameraH264 = require('./SetupCameraH264.js')
let MissionWpAction = require('./MissionWpAction.js')
let GetWholeBatteryInfo = require('./GetWholeBatteryInfo.js')
let SubscribeWaypointV2State = require('./SubscribeWaypointV2State.js')
let GetGoHomeAltitude = require('./GetGoHomeAltitude.js')
let SetJoystickMode = require('./SetJoystickMode.js')
let StopWaypointV2Mission = require('./StopWaypointV2Mission.js')

module.exports = {
  FlightTaskControl: FlightTaskControl,
  SetHomePoint: SetHomePoint,
  SetGoHomeAltitude: SetGoHomeAltitude,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  CameraFocusPoint: CameraFocusPoint,
  MFIOSetValue: MFIOSetValue,
  CameraSetZoomPara: CameraSetZoomPara,
  DroneTaskControl: DroneTaskControl,
  SetLocalPosRef: SetLocalPosRef,
  MissionWpGetSpeed: MissionWpGetSpeed,
  SetCurrentAircraftLocAsHomePoint: SetCurrentAircraftLocAsHomePoint,
  MissionWpUpload: MissionWpUpload,
  Activation: Activation,
  SDKControlAuthority: SDKControlAuthority,
  JoystickAction: JoystickAction,
  StartWaypointV2Mission: StartWaypointV2Mission,
  SendPayloadData: SendPayloadData,
  MFIO: MFIO,
  CameraShutterSpeed: CameraShutterSpeed,
  CameraStartShootBurstPhoto: CameraStartShootBurstPhoto,
  MissionHpUpload: MissionHpUpload,
  DroneArmControl: DroneArmControl,
  ObtainControlAuthority: ObtainControlAuthority,
  UploadWaypointV2Action: UploadWaypointV2Action,
  CameraStartShootIntervalPhoto: CameraStartShootIntervalPhoto,
  CameraStopShootPhoto: CameraStopShootPhoto,
  MissionWpGetInfo: MissionWpGetInfo,
  SetGlobalCruisespeed: SetGlobalCruisespeed,
  GetDroneType: GetDroneType,
  GetGlobalCruisespeed: GetGlobalCruisespeed,
  CameraEV: CameraEV,
  CameraAction: CameraAction,
  SubscribeWaypointV2Event: SubscribeWaypointV2Event,
  CameraZoomCtrl: CameraZoomCtrl,
  MissionStatus: MissionStatus,
  MFIOConfig: MFIOConfig,
  SetupCameraStream: SetupCameraStream,
  UploadWaypointV2Mission: UploadWaypointV2Mission,
  InitWaypointV2Setting: InitWaypointV2Setting,
  SetHardSync: SetHardSync,
  StereoVGASubscription: StereoVGASubscription,
  GetAvoidEnable: GetAvoidEnable,
  EmergencyBrake: EmergencyBrake,
  PauseWaypointV2Mission: PauseWaypointV2Mission,
  GetSingleBatteryDynamicInfo: GetSingleBatteryDynamicInfo,
  CameraISO: CameraISO,
  CameraTapZoomPoint: CameraTapZoomPoint,
  MissionHpAction: MissionHpAction,
  CameraStartShootAEBPhoto: CameraStartShootAEBPhoto,
  ResumeWaypointV2Mission: ResumeWaypointV2Mission,
  GetHMSData: GetHMSData,
  CameraStartShootSinglePhoto: CameraStartShootSinglePhoto,
  CameraAperture: CameraAperture,
  MissionWpSetSpeed: MissionWpSetSpeed,
  MissionHpResetYaw: MissionHpResetYaw,
  GetM300StereoParams: GetM300StereoParams,
  KillSwitch: KillSwitch,
  SetAvoidEnable: SetAvoidEnable,
  QueryDroneVersion: QueryDroneVersion,
  MissionHpGetInfo: MissionHpGetInfo,
  DownloadWaypointV2Mission: DownloadWaypointV2Mission,
  GimbalAction: GimbalAction,
  Stereo240pSubscription: Stereo240pSubscription,
  CameraRecordVideoAction: CameraRecordVideoAction,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  SendMobileData: SendMobileData,
  StereoDepthSubscription: StereoDepthSubscription,
  GenerateWaypointV2Action: GenerateWaypointV2Action,
  SetupCameraH264: SetupCameraH264,
  MissionWpAction: MissionWpAction,
  GetWholeBatteryInfo: GetWholeBatteryInfo,
  SubscribeWaypointV2State: SubscribeWaypointV2State,
  GetGoHomeAltitude: GetGoHomeAltitude,
  SetJoystickMode: SetJoystickMode,
  StopWaypointV2Mission: StopWaypointV2Mission,
};
