
"use strict";

let SetJoystickMode = require('./SetJoystickMode.js')
let StartWaypointV2Mission = require('./StartWaypointV2Mission.js')
let GetSingleBatteryDynamicInfo = require('./GetSingleBatteryDynamicInfo.js')
let SetupCameraH264 = require('./SetupCameraH264.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let MissionStatus = require('./MissionStatus.js')
let MissionHpAction = require('./MissionHpAction.js')
let StopWaypointV2Mission = require('./StopWaypointV2Mission.js')
let CameraEV = require('./CameraEV.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let Activation = require('./Activation.js')
let UploadWaypointV2Action = require('./UploadWaypointV2Action.js')
let GetM300StereoParams = require('./GetM300StereoParams.js')
let MFIO = require('./MFIO.js')
let SetHomePoint = require('./SetHomePoint.js')
let CameraRecordVideoAction = require('./CameraRecordVideoAction.js')
let CameraStopShootPhoto = require('./CameraStopShootPhoto.js')
let JoystickAction = require('./JoystickAction.js')
let FlightTaskControl = require('./FlightTaskControl.js')
let MFIOConfig = require('./MFIOConfig.js')
let CameraAperture = require('./CameraAperture.js')
let GenerateWaypointV2Action = require('./GenerateWaypointV2Action.js')
let CameraStartShootAEBPhoto = require('./CameraStartShootAEBPhoto.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let GetDroneType = require('./GetDroneType.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let CameraSetZoomPara = require('./CameraSetZoomPara.js')
let CameraStartShootSinglePhoto = require('./CameraStartShootSinglePhoto.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let SendMobileData = require('./SendMobileData.js')
let CameraShutterSpeed = require('./CameraShutterSpeed.js')
let SubscribeWaypointV2Event = require('./SubscribeWaypointV2Event.js')
let GetGoHomeAltitude = require('./GetGoHomeAltitude.js')
let SubscribeWaypointV2State = require('./SubscribeWaypointV2State.js')
let SetAvoidEnable = require('./SetAvoidEnable.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let CameraFocusPoint = require('./CameraFocusPoint.js')
let GimbalAction = require('./GimbalAction.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let EmergencyBrake = require('./EmergencyBrake.js')
let InitWaypointV2Setting = require('./InitWaypointV2Setting.js')
let DownloadWaypointV2Mission = require('./DownloadWaypointV2Mission.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let GetAvoidEnable = require('./GetAvoidEnable.js')
let CameraISO = require('./CameraISO.js')
let MissionWpAction = require('./MissionWpAction.js')
let GetGlobalCruisespeed = require('./GetGlobalCruisespeed.js')
let CameraStartShootBurstPhoto = require('./CameraStartShootBurstPhoto.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let UploadWaypointV2Mission = require('./UploadWaypointV2Mission.js')
let DroneArmControl = require('./DroneArmControl.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let CameraAction = require('./CameraAction.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let CameraTapZoomPoint = require('./CameraTapZoomPoint.js')
let ResumeWaypointV2Mission = require('./ResumeWaypointV2Mission.js')
let SetHardSync = require('./SetHardSync.js')
let CameraStartShootIntervalPhoto = require('./CameraStartShootIntervalPhoto.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let KillSwitch = require('./KillSwitch.js')
let SetGoHomeAltitude = require('./SetGoHomeAltitude.js')
let PauseWaypointV2Mission = require('./PauseWaypointV2Mission.js')
let GetHMSData = require('./GetHMSData.js')
let CameraZoomCtrl = require('./CameraZoomCtrl.js')
let SendPayloadData = require('./SendPayloadData.js')
let SetGlobalCruisespeed = require('./SetGlobalCruisespeed.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let GetWholeBatteryInfo = require('./GetWholeBatteryInfo.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let ObtainControlAuthority = require('./ObtainControlAuthority.js')
let SetCurrentAircraftLocAsHomePoint = require('./SetCurrentAircraftLocAsHomePoint.js')

module.exports = {
  SetJoystickMode: SetJoystickMode,
  StartWaypointV2Mission: StartWaypointV2Mission,
  GetSingleBatteryDynamicInfo: GetSingleBatteryDynamicInfo,
  SetupCameraH264: SetupCameraH264,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  MissionHpGetInfo: MissionHpGetInfo,
  MissionStatus: MissionStatus,
  MissionHpAction: MissionHpAction,
  StopWaypointV2Mission: StopWaypointV2Mission,
  CameraEV: CameraEV,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  Activation: Activation,
  UploadWaypointV2Action: UploadWaypointV2Action,
  GetM300StereoParams: GetM300StereoParams,
  MFIO: MFIO,
  SetHomePoint: SetHomePoint,
  CameraRecordVideoAction: CameraRecordVideoAction,
  CameraStopShootPhoto: CameraStopShootPhoto,
  JoystickAction: JoystickAction,
  FlightTaskControl: FlightTaskControl,
  MFIOConfig: MFIOConfig,
  CameraAperture: CameraAperture,
  GenerateWaypointV2Action: GenerateWaypointV2Action,
  CameraStartShootAEBPhoto: CameraStartShootAEBPhoto,
  StereoDepthSubscription: StereoDepthSubscription,
  GetDroneType: GetDroneType,
  MissionWpSetSpeed: MissionWpSetSpeed,
  CameraSetZoomPara: CameraSetZoomPara,
  CameraStartShootSinglePhoto: CameraStartShootSinglePhoto,
  MFIOSetValue: MFIOSetValue,
  SendMobileData: SendMobileData,
  CameraShutterSpeed: CameraShutterSpeed,
  SubscribeWaypointV2Event: SubscribeWaypointV2Event,
  GetGoHomeAltitude: GetGoHomeAltitude,
  SubscribeWaypointV2State: SubscribeWaypointV2State,
  SetAvoidEnable: SetAvoidEnable,
  MissionHpResetYaw: MissionHpResetYaw,
  CameraFocusPoint: CameraFocusPoint,
  GimbalAction: GimbalAction,
  SetupCameraStream: SetupCameraStream,
  EmergencyBrake: EmergencyBrake,
  InitWaypointV2Setting: InitWaypointV2Setting,
  DownloadWaypointV2Mission: DownloadWaypointV2Mission,
  MissionHpUpload: MissionHpUpload,
  GetAvoidEnable: GetAvoidEnable,
  CameraISO: CameraISO,
  MissionWpAction: MissionWpAction,
  GetGlobalCruisespeed: GetGlobalCruisespeed,
  CameraStartShootBurstPhoto: CameraStartShootBurstPhoto,
  SDKControlAuthority: SDKControlAuthority,
  UploadWaypointV2Mission: UploadWaypointV2Mission,
  DroneArmControl: DroneArmControl,
  QueryDroneVersion: QueryDroneVersion,
  CameraAction: CameraAction,
  StereoVGASubscription: StereoVGASubscription,
  MissionWpUpload: MissionWpUpload,
  CameraTapZoomPoint: CameraTapZoomPoint,
  ResumeWaypointV2Mission: ResumeWaypointV2Mission,
  SetHardSync: SetHardSync,
  CameraStartShootIntervalPhoto: CameraStartShootIntervalPhoto,
  Stereo240pSubscription: Stereo240pSubscription,
  KillSwitch: KillSwitch,
  SetGoHomeAltitude: SetGoHomeAltitude,
  PauseWaypointV2Mission: PauseWaypointV2Mission,
  GetHMSData: GetHMSData,
  CameraZoomCtrl: CameraZoomCtrl,
  SendPayloadData: SendPayloadData,
  SetGlobalCruisespeed: SetGlobalCruisespeed,
  MissionWpGetSpeed: MissionWpGetSpeed,
  GetWholeBatteryInfo: GetWholeBatteryInfo,
  SetLocalPosRef: SetLocalPosRef,
  DroneTaskControl: DroneTaskControl,
  MissionWpGetInfo: MissionWpGetInfo,
  ObtainControlAuthority: ObtainControlAuthority,
  SetCurrentAircraftLocAsHomePoint: SetCurrentAircraftLocAsHomePoint,
};
