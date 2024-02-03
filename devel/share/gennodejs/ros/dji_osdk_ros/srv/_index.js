
"use strict";

let MissionWpUpload = require('./MissionWpUpload.js')
let MFIO = require('./MFIO.js')
let InitWaypointV2Setting = require('./InitWaypointV2Setting.js')
let GetWholeBatteryInfo = require('./GetWholeBatteryInfo.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let GetGoHomeAltitude = require('./GetGoHomeAltitude.js')
let GenerateWaypointV2Action = require('./GenerateWaypointV2Action.js')
let GetM300StereoParams = require('./GetM300StereoParams.js')
let CameraStartShootBurstPhoto = require('./CameraStartShootBurstPhoto.js')
let GetHMSData = require('./GetHMSData.js')
let CameraFocusPoint = require('./CameraFocusPoint.js')
let CameraAperture = require('./CameraAperture.js')
let SetJoystickMode = require('./SetJoystickMode.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let GetGlobalCruisespeed = require('./GetGlobalCruisespeed.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let CameraStartShootIntervalPhoto = require('./CameraStartShootIntervalPhoto.js')
let CameraStartShootSinglePhoto = require('./CameraStartShootSinglePhoto.js')
let SendPayloadData = require('./SendPayloadData.js')
let MFIOConfig = require('./MFIOConfig.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let MissionStatus = require('./MissionStatus.js')
let CameraEV = require('./CameraEV.js')
let SetGlobalCruisespeed = require('./SetGlobalCruisespeed.js')
let FlightTaskControl = require('./FlightTaskControl.js')
let GetSingleBatteryDynamicInfo = require('./GetSingleBatteryDynamicInfo.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let UploadWaypointV2Mission = require('./UploadWaypointV2Mission.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let MissionWpAction = require('./MissionWpAction.js')
let CameraStopShootPhoto = require('./CameraStopShootPhoto.js')
let DownloadWaypointV2Mission = require('./DownloadWaypointV2Mission.js')
let CameraStartShootAEBPhoto = require('./CameraStartShootAEBPhoto.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let SetAvoidEnable = require('./SetAvoidEnable.js')
let UploadWaypointV2Action = require('./UploadWaypointV2Action.js')
let SetCurrentAircraftLocAsHomePoint = require('./SetCurrentAircraftLocAsHomePoint.js')
let ObtainControlAuthority = require('./ObtainControlAuthority.js')
let CameraZoomCtrl = require('./CameraZoomCtrl.js')
let CameraAction = require('./CameraAction.js')
let ResumeWaypointV2Mission = require('./ResumeWaypointV2Mission.js')
let SetHomePoint = require('./SetHomePoint.js')
let SetGoHomeAltitude = require('./SetGoHomeAltitude.js')
let StopWaypointV2Mission = require('./StopWaypointV2Mission.js')
let KillSwitch = require('./KillSwitch.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let JoystickAction = require('./JoystickAction.js')
let CameraTapZoomPoint = require('./CameraTapZoomPoint.js')
let EmergencyBrake = require('./EmergencyBrake.js')
let SetupCameraH264 = require('./SetupCameraH264.js')
let CameraShutterSpeed = require('./CameraShutterSpeed.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let GetDroneType = require('./GetDroneType.js')
let SubscribeWaypointV2State = require('./SubscribeWaypointV2State.js')
let CameraISO = require('./CameraISO.js')
let Activation = require('./Activation.js')
let StartWaypointV2Mission = require('./StartWaypointV2Mission.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let MissionHpAction = require('./MissionHpAction.js')
let CameraRecordVideoAction = require('./CameraRecordVideoAction.js')
let SubscribeWaypointV2Event = require('./SubscribeWaypointV2Event.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let GimbalAction = require('./GimbalAction.js')
let PauseWaypointV2Mission = require('./PauseWaypointV2Mission.js')
let SetHardSync = require('./SetHardSync.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let CameraSetZoomPara = require('./CameraSetZoomPara.js')
let DroneArmControl = require('./DroneArmControl.js')
let GetAvoidEnable = require('./GetAvoidEnable.js')
let SendMobileData = require('./SendMobileData.js')

module.exports = {
  MissionWpUpload: MissionWpUpload,
  MFIO: MFIO,
  InitWaypointV2Setting: InitWaypointV2Setting,
  GetWholeBatteryInfo: GetWholeBatteryInfo,
  MissionWpGetInfo: MissionWpGetInfo,
  GetGoHomeAltitude: GetGoHomeAltitude,
  GenerateWaypointV2Action: GenerateWaypointV2Action,
  GetM300StereoParams: GetM300StereoParams,
  CameraStartShootBurstPhoto: CameraStartShootBurstPhoto,
  GetHMSData: GetHMSData,
  CameraFocusPoint: CameraFocusPoint,
  CameraAperture: CameraAperture,
  SetJoystickMode: SetJoystickMode,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  QueryDroneVersion: QueryDroneVersion,
  MissionHpUpload: MissionHpUpload,
  GetGlobalCruisespeed: GetGlobalCruisespeed,
  StereoVGASubscription: StereoVGASubscription,
  CameraStartShootIntervalPhoto: CameraStartShootIntervalPhoto,
  CameraStartShootSinglePhoto: CameraStartShootSinglePhoto,
  SendPayloadData: SendPayloadData,
  MFIOConfig: MFIOConfig,
  MissionWpGetSpeed: MissionWpGetSpeed,
  MissionStatus: MissionStatus,
  CameraEV: CameraEV,
  SetGlobalCruisespeed: SetGlobalCruisespeed,
  FlightTaskControl: FlightTaskControl,
  GetSingleBatteryDynamicInfo: GetSingleBatteryDynamicInfo,
  MissionHpResetYaw: MissionHpResetYaw,
  UploadWaypointV2Mission: UploadWaypointV2Mission,
  SetupCameraStream: SetupCameraStream,
  MissionWpAction: MissionWpAction,
  CameraStopShootPhoto: CameraStopShootPhoto,
  DownloadWaypointV2Mission: DownloadWaypointV2Mission,
  CameraStartShootAEBPhoto: CameraStartShootAEBPhoto,
  SetLocalPosRef: SetLocalPosRef,
  MFIOSetValue: MFIOSetValue,
  MissionHpGetInfo: MissionHpGetInfo,
  MissionWpSetSpeed: MissionWpSetSpeed,
  SetAvoidEnable: SetAvoidEnable,
  UploadWaypointV2Action: UploadWaypointV2Action,
  SetCurrentAircraftLocAsHomePoint: SetCurrentAircraftLocAsHomePoint,
  ObtainControlAuthority: ObtainControlAuthority,
  CameraZoomCtrl: CameraZoomCtrl,
  CameraAction: CameraAction,
  ResumeWaypointV2Mission: ResumeWaypointV2Mission,
  SetHomePoint: SetHomePoint,
  SetGoHomeAltitude: SetGoHomeAltitude,
  StopWaypointV2Mission: StopWaypointV2Mission,
  KillSwitch: KillSwitch,
  StereoDepthSubscription: StereoDepthSubscription,
  JoystickAction: JoystickAction,
  CameraTapZoomPoint: CameraTapZoomPoint,
  EmergencyBrake: EmergencyBrake,
  SetupCameraH264: SetupCameraH264,
  CameraShutterSpeed: CameraShutterSpeed,
  DroneTaskControl: DroneTaskControl,
  GetDroneType: GetDroneType,
  SubscribeWaypointV2State: SubscribeWaypointV2State,
  CameraISO: CameraISO,
  Activation: Activation,
  StartWaypointV2Mission: StartWaypointV2Mission,
  Stereo240pSubscription: Stereo240pSubscription,
  MissionHpAction: MissionHpAction,
  CameraRecordVideoAction: CameraRecordVideoAction,
  SubscribeWaypointV2Event: SubscribeWaypointV2Event,
  SDKControlAuthority: SDKControlAuthority,
  GimbalAction: GimbalAction,
  PauseWaypointV2Mission: PauseWaypointV2Mission,
  SetHardSync: SetHardSync,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  CameraSetZoomPara: CameraSetZoomPara,
  DroneArmControl: DroneArmControl,
  GetAvoidEnable: GetAvoidEnable,
  SendMobileData: SendMobileData,
};
