
"use strict";

let GetSingleBatteryDynamicInfo = require('./GetSingleBatteryDynamicInfo.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let MFIOConfig = require('./MFIOConfig.js')
let CameraAperture = require('./CameraAperture.js')
let MissionHpAction = require('./MissionHpAction.js')
let ObtainControlAuthority = require('./ObtainControlAuthority.js')
let GimbalAction = require('./GimbalAction.js')
let InitWaypointV2Setting = require('./InitWaypointV2Setting.js')
let KillSwitch = require('./KillSwitch.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let SetHardSync = require('./SetHardSync.js')
let Activation = require('./Activation.js')
let EmergencyBrake = require('./EmergencyBrake.js')
let SetupCameraH264 = require('./SetupCameraH264.js')
let CameraStartShootAEBPhoto = require('./CameraStartShootAEBPhoto.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let MissionWpAction = require('./MissionWpAction.js')
let JoystickAction = require('./JoystickAction.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let SetHomePoint = require('./SetHomePoint.js')
let MFIO = require('./MFIO.js')
let CameraStartShootBurstPhoto = require('./CameraStartShootBurstPhoto.js')
let GetGoHomeAltitude = require('./GetGoHomeAltitude.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let CameraTapZoomPoint = require('./CameraTapZoomPoint.js')
let CameraStartShootSinglePhoto = require('./CameraStartShootSinglePhoto.js')
let CameraZoomCtrl = require('./CameraZoomCtrl.js')
let CameraSetZoomPara = require('./CameraSetZoomPara.js')
let MissionStatus = require('./MissionStatus.js')
let UploadWaypointV2Mission = require('./UploadWaypointV2Mission.js')
let CameraEV = require('./CameraEV.js')
let ResumeWaypointV2Mission = require('./ResumeWaypointV2Mission.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let StopWaypointV2Mission = require('./StopWaypointV2Mission.js')
let SetJoystickMode = require('./SetJoystickMode.js')
let CameraShutterSpeed = require('./CameraShutterSpeed.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let CameraAction = require('./CameraAction.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let GetDroneType = require('./GetDroneType.js')
let StartWaypointV2Mission = require('./StartWaypointV2Mission.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let CameraRecordVideoAction = require('./CameraRecordVideoAction.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let CameraISO = require('./CameraISO.js')
let PauseWaypointV2Mission = require('./PauseWaypointV2Mission.js')
let DownloadWaypointV2Mission = require('./DownloadWaypointV2Mission.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let GetGlobalCruisespeed = require('./GetGlobalCruisespeed.js')
let SetGlobalCruisespeed = require('./SetGlobalCruisespeed.js')
let CameraFocusPoint = require('./CameraFocusPoint.js')
let SubscribeWaypointV2State = require('./SubscribeWaypointV2State.js')
let FlightTaskControl = require('./FlightTaskControl.js')
let GetWholeBatteryInfo = require('./GetWholeBatteryInfo.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let GetAvoidEnable = require('./GetAvoidEnable.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let CameraStartShootIntervalPhoto = require('./CameraStartShootIntervalPhoto.js')
let SubscribeWaypointV2Event = require('./SubscribeWaypointV2Event.js')
let SetGoHomeAltitude = require('./SetGoHomeAltitude.js')
let SetAvoidEnable = require('./SetAvoidEnable.js')
let GetM300StereoParams = require('./GetM300StereoParams.js')
let GenerateWaypointV2Action = require('./GenerateWaypointV2Action.js')
let SendPayloadData = require('./SendPayloadData.js')
let UploadWaypointV2Action = require('./UploadWaypointV2Action.js')
let CameraStopShootPhoto = require('./CameraStopShootPhoto.js')
let SetCurrentAircraftLocAsHomePoint = require('./SetCurrentAircraftLocAsHomePoint.js')
let SendMobileData = require('./SendMobileData.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let DroneArmControl = require('./DroneArmControl.js')
let GetHMSData = require('./GetHMSData.js')

module.exports = {
  GetSingleBatteryDynamicInfo: GetSingleBatteryDynamicInfo,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  MFIOConfig: MFIOConfig,
  CameraAperture: CameraAperture,
  MissionHpAction: MissionHpAction,
  ObtainControlAuthority: ObtainControlAuthority,
  GimbalAction: GimbalAction,
  InitWaypointV2Setting: InitWaypointV2Setting,
  KillSwitch: KillSwitch,
  QueryDroneVersion: QueryDroneVersion,
  SetHardSync: SetHardSync,
  Activation: Activation,
  EmergencyBrake: EmergencyBrake,
  SetupCameraH264: SetupCameraH264,
  CameraStartShootAEBPhoto: CameraStartShootAEBPhoto,
  StereoDepthSubscription: StereoDepthSubscription,
  MissionWpAction: MissionWpAction,
  JoystickAction: JoystickAction,
  SetLocalPosRef: SetLocalPosRef,
  SetHomePoint: SetHomePoint,
  MFIO: MFIO,
  CameraStartShootBurstPhoto: CameraStartShootBurstPhoto,
  GetGoHomeAltitude: GetGoHomeAltitude,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  MissionWpSetSpeed: MissionWpSetSpeed,
  CameraTapZoomPoint: CameraTapZoomPoint,
  CameraStartShootSinglePhoto: CameraStartShootSinglePhoto,
  CameraZoomCtrl: CameraZoomCtrl,
  CameraSetZoomPara: CameraSetZoomPara,
  MissionStatus: MissionStatus,
  UploadWaypointV2Mission: UploadWaypointV2Mission,
  CameraEV: CameraEV,
  ResumeWaypointV2Mission: ResumeWaypointV2Mission,
  MissionHpUpload: MissionHpUpload,
  StopWaypointV2Mission: StopWaypointV2Mission,
  SetJoystickMode: SetJoystickMode,
  CameraShutterSpeed: CameraShutterSpeed,
  SDKControlAuthority: SDKControlAuthority,
  MFIOSetValue: MFIOSetValue,
  CameraAction: CameraAction,
  SetupCameraStream: SetupCameraStream,
  GetDroneType: GetDroneType,
  StartWaypointV2Mission: StartWaypointV2Mission,
  DroneTaskControl: DroneTaskControl,
  CameraRecordVideoAction: CameraRecordVideoAction,
  StereoVGASubscription: StereoVGASubscription,
  MissionWpUpload: MissionWpUpload,
  CameraISO: CameraISO,
  PauseWaypointV2Mission: PauseWaypointV2Mission,
  DownloadWaypointV2Mission: DownloadWaypointV2Mission,
  MissionHpResetYaw: MissionHpResetYaw,
  GetGlobalCruisespeed: GetGlobalCruisespeed,
  SetGlobalCruisespeed: SetGlobalCruisespeed,
  CameraFocusPoint: CameraFocusPoint,
  SubscribeWaypointV2State: SubscribeWaypointV2State,
  FlightTaskControl: FlightTaskControl,
  GetWholeBatteryInfo: GetWholeBatteryInfo,
  MissionWpGetSpeed: MissionWpGetSpeed,
  GetAvoidEnable: GetAvoidEnable,
  MissionHpGetInfo: MissionHpGetInfo,
  MissionWpGetInfo: MissionWpGetInfo,
  CameraStartShootIntervalPhoto: CameraStartShootIntervalPhoto,
  SubscribeWaypointV2Event: SubscribeWaypointV2Event,
  SetGoHomeAltitude: SetGoHomeAltitude,
  SetAvoidEnable: SetAvoidEnable,
  GetM300StereoParams: GetM300StereoParams,
  GenerateWaypointV2Action: GenerateWaypointV2Action,
  SendPayloadData: SendPayloadData,
  UploadWaypointV2Action: UploadWaypointV2Action,
  CameraStopShootPhoto: CameraStopShootPhoto,
  SetCurrentAircraftLocAsHomePoint: SetCurrentAircraftLocAsHomePoint,
  SendMobileData: SendMobileData,
  Stereo240pSubscription: Stereo240pSubscription,
  DroneArmControl: DroneArmControl,
  GetHMSData: GetHMSData,
};
