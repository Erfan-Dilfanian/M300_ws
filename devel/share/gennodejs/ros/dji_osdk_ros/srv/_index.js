
"use strict";

let InitWaypointV2Setting = require('./InitWaypointV2Setting.js')
let UploadWaypointV2Action = require('./UploadWaypointV2Action.js')
let StartWaypointV2Mission = require('./StartWaypointV2Mission.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let UploadWaypointV2Mission = require('./UploadWaypointV2Mission.js')
let KillSwitch = require('./KillSwitch.js')
let GetDroneType = require('./GetDroneType.js')
let SendMobileData = require('./SendMobileData.js')
let GimbalAction = require('./GimbalAction.js')
let CameraRecordVideoAction = require('./CameraRecordVideoAction.js')
let EmergencyBrake = require('./EmergencyBrake.js')
let JoystickAction = require('./JoystickAction.js')
let CameraStopShootPhoto = require('./CameraStopShootPhoto.js')
let CameraAction = require('./CameraAction.js')
let MissionHpAction = require('./MissionHpAction.js')
let CameraZoomCtrl = require('./CameraZoomCtrl.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let Activation = require('./Activation.js')
let ObtainControlAuthority = require('./ObtainControlAuthority.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let SetGlobalCruisespeed = require('./SetGlobalCruisespeed.js')
let GetWholeBatteryInfo = require('./GetWholeBatteryInfo.js')
let MFIOConfig = require('./MFIOConfig.js')
let MissionStatus = require('./MissionStatus.js')
let DownloadWaypointV2Mission = require('./DownloadWaypointV2Mission.js')
let SubscribeWaypointV2Event = require('./SubscribeWaypointV2Event.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let CameraSetZoomPara = require('./CameraSetZoomPara.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let CameraStartShootBurstPhoto = require('./CameraStartShootBurstPhoto.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let CameraISO = require('./CameraISO.js')
let SetupCameraH264 = require('./SetupCameraH264.js')
let CameraStartShootSinglePhoto = require('./CameraStartShootSinglePhoto.js')
let GetGlobalCruisespeed = require('./GetGlobalCruisespeed.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let CameraAperture = require('./CameraAperture.js')
let PauseWaypointV2Mission = require('./PauseWaypointV2Mission.js')
let SetHomePoint = require('./SetHomePoint.js')
let SetCurrentAircraftLocAsHomePoint = require('./SetCurrentAircraftLocAsHomePoint.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let GetM300StereoParams = require('./GetM300StereoParams.js')
let CameraStartShootAEBPhoto = require('./CameraStartShootAEBPhoto.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let CameraFocusPoint = require('./CameraFocusPoint.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let GetHMSData = require('./GetHMSData.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let CameraTapZoomPoint = require('./CameraTapZoomPoint.js')
let MissionWpAction = require('./MissionWpAction.js')
let SetAvoidEnable = require('./SetAvoidEnable.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let GetSingleBatteryDynamicInfo = require('./GetSingleBatteryDynamicInfo.js')
let CameraEV = require('./CameraEV.js')
let ResumeWaypointV2Mission = require('./ResumeWaypointV2Mission.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let SubscribeWaypointV2State = require('./SubscribeWaypointV2State.js')
let CameraShutterSpeed = require('./CameraShutterSpeed.js')
let FlightTaskControl = require('./FlightTaskControl.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let SetJoystickMode = require('./SetJoystickMode.js')
let SetHardSync = require('./SetHardSync.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let GetAvoidEnable = require('./GetAvoidEnable.js')
let StopWaypointV2Mission = require('./StopWaypointV2Mission.js')
let SetGoHomeAltitude = require('./SetGoHomeAltitude.js')
let CameraStartShootIntervalPhoto = require('./CameraStartShootIntervalPhoto.js')
let SendPayloadData = require('./SendPayloadData.js')
let GenerateWaypointV2Action = require('./GenerateWaypointV2Action.js')
let DroneArmControl = require('./DroneArmControl.js')
let GetGoHomeAltitude = require('./GetGoHomeAltitude.js')
let MFIO = require('./MFIO.js')

module.exports = {
  InitWaypointV2Setting: InitWaypointV2Setting,
  UploadWaypointV2Action: UploadWaypointV2Action,
  StartWaypointV2Mission: StartWaypointV2Mission,
  DroneTaskControl: DroneTaskControl,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  UploadWaypointV2Mission: UploadWaypointV2Mission,
  KillSwitch: KillSwitch,
  GetDroneType: GetDroneType,
  SendMobileData: SendMobileData,
  GimbalAction: GimbalAction,
  CameraRecordVideoAction: CameraRecordVideoAction,
  EmergencyBrake: EmergencyBrake,
  JoystickAction: JoystickAction,
  CameraStopShootPhoto: CameraStopShootPhoto,
  CameraAction: CameraAction,
  MissionHpAction: MissionHpAction,
  CameraZoomCtrl: CameraZoomCtrl,
  StereoVGASubscription: StereoVGASubscription,
  Activation: Activation,
  ObtainControlAuthority: ObtainControlAuthority,
  QueryDroneVersion: QueryDroneVersion,
  SetGlobalCruisespeed: SetGlobalCruisespeed,
  GetWholeBatteryInfo: GetWholeBatteryInfo,
  MFIOConfig: MFIOConfig,
  MissionStatus: MissionStatus,
  DownloadWaypointV2Mission: DownloadWaypointV2Mission,
  SubscribeWaypointV2Event: SubscribeWaypointV2Event,
  SDKControlAuthority: SDKControlAuthority,
  Stereo240pSubscription: Stereo240pSubscription,
  CameraSetZoomPara: CameraSetZoomPara,
  SetLocalPosRef: SetLocalPosRef,
  CameraStartShootBurstPhoto: CameraStartShootBurstPhoto,
  StereoDepthSubscription: StereoDepthSubscription,
  CameraISO: CameraISO,
  SetupCameraH264: SetupCameraH264,
  CameraStartShootSinglePhoto: CameraStartShootSinglePhoto,
  GetGlobalCruisespeed: GetGlobalCruisespeed,
  MFIOSetValue: MFIOSetValue,
  CameraAperture: CameraAperture,
  PauseWaypointV2Mission: PauseWaypointV2Mission,
  SetHomePoint: SetHomePoint,
  SetCurrentAircraftLocAsHomePoint: SetCurrentAircraftLocAsHomePoint,
  MissionHpResetYaw: MissionHpResetYaw,
  GetM300StereoParams: GetM300StereoParams,
  CameraStartShootAEBPhoto: CameraStartShootAEBPhoto,
  MissionWpGetSpeed: MissionWpGetSpeed,
  CameraFocusPoint: CameraFocusPoint,
  MissionHpGetInfo: MissionHpGetInfo,
  GetHMSData: GetHMSData,
  MissionWpUpload: MissionWpUpload,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  CameraTapZoomPoint: CameraTapZoomPoint,
  MissionWpAction: MissionWpAction,
  SetAvoidEnable: SetAvoidEnable,
  MissionHpUpload: MissionHpUpload,
  GetSingleBatteryDynamicInfo: GetSingleBatteryDynamicInfo,
  CameraEV: CameraEV,
  ResumeWaypointV2Mission: ResumeWaypointV2Mission,
  MissionWpSetSpeed: MissionWpSetSpeed,
  SubscribeWaypointV2State: SubscribeWaypointV2State,
  CameraShutterSpeed: CameraShutterSpeed,
  FlightTaskControl: FlightTaskControl,
  SetupCameraStream: SetupCameraStream,
  SetJoystickMode: SetJoystickMode,
  SetHardSync: SetHardSync,
  MissionWpGetInfo: MissionWpGetInfo,
  GetAvoidEnable: GetAvoidEnable,
  StopWaypointV2Mission: StopWaypointV2Mission,
  SetGoHomeAltitude: SetGoHomeAltitude,
  CameraStartShootIntervalPhoto: CameraStartShootIntervalPhoto,
  SendPayloadData: SendPayloadData,
  GenerateWaypointV2Action: GenerateWaypointV2Action,
  DroneArmControl: DroneArmControl,
  GetGoHomeAltitude: GetGoHomeAltitude,
  MFIO: MFIO,
};
