
"use strict";

let MissionWpAction = require('./MissionWpAction.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let GetSingleBatteryDynamicInfo = require('./GetSingleBatteryDynamicInfo.js')
let SetJoystickMode = require('./SetJoystickMode.js')
let CameraTapZoomPoint = require('./CameraTapZoomPoint.js')
let SetAvoidEnable = require('./SetAvoidEnable.js')
let DownloadWaypointV2Mission = require('./DownloadWaypointV2Mission.js')
let CameraAperture = require('./CameraAperture.js')
let MFIO = require('./MFIO.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let SetGoHomeAltitude = require('./SetGoHomeAltitude.js')
let SendPayloadData = require('./SendPayloadData.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let KillSwitch = require('./KillSwitch.js')
let FlightTaskControl = require('./FlightTaskControl.js')
let SendMobileData = require('./SendMobileData.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let CameraFocusPoint = require('./CameraFocusPoint.js')
let GetAvoidEnable = require('./GetAvoidEnable.js')
let CameraStartShootAEBPhoto = require('./CameraStartShootAEBPhoto.js')
let GimbalAction = require('./GimbalAction.js')
let InitWaypointV2Setting = require('./InitWaypointV2Setting.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let SetHomePoint = require('./SetHomePoint.js')
let DroneArmControl = require('./DroneArmControl.js')
let SetGlobalCruisespeed = require('./SetGlobalCruisespeed.js')
let GetDroneType = require('./GetDroneType.js')
let SetupCameraH264 = require('./SetupCameraH264.js')
let MissionHpAction = require('./MissionHpAction.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let GetM300StereoParams = require('./GetM300StereoParams.js')
let MissionStatus = require('./MissionStatus.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let EmergencyBrake = require('./EmergencyBrake.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let UploadWaypointV2Action = require('./UploadWaypointV2Action.js')
let CameraAction = require('./CameraAction.js')
let PauseWaypointV2Mission = require('./PauseWaypointV2Mission.js')
let CameraZoomCtrl = require('./CameraZoomCtrl.js')
let CameraStartShootBurstPhoto = require('./CameraStartShootBurstPhoto.js')
let GetGlobalCruisespeed = require('./GetGlobalCruisespeed.js')
let UploadWaypointV2Mission = require('./UploadWaypointV2Mission.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let CameraRecordVideoAction = require('./CameraRecordVideoAction.js')
let SetHardSync = require('./SetHardSync.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')
let StartWaypointV2Mission = require('./StartWaypointV2Mission.js')
let CameraStopShootPhoto = require('./CameraStopShootPhoto.js')
let SubscribeWaypointV2Event = require('./SubscribeWaypointV2Event.js')
let CameraSetZoomPara = require('./CameraSetZoomPara.js')
let JoystickAction = require('./JoystickAction.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let CameraStartShootIntervalPhoto = require('./CameraStartShootIntervalPhoto.js')
let Activation = require('./Activation.js')
let GetGoHomeAltitude = require('./GetGoHomeAltitude.js')
let CameraShutterSpeed = require('./CameraShutterSpeed.js')
let SubscribeWaypointV2State = require('./SubscribeWaypointV2State.js')
let MFIOConfig = require('./MFIOConfig.js')
let GetHMSData = require('./GetHMSData.js')
let StopWaypointV2Mission = require('./StopWaypointV2Mission.js')
let GetWholeBatteryInfo = require('./GetWholeBatteryInfo.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let CameraISO = require('./CameraISO.js')
let GenerateWaypointV2Action = require('./GenerateWaypointV2Action.js')
let CameraStartShootSinglePhoto = require('./CameraStartShootSinglePhoto.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let ObtainControlAuthority = require('./ObtainControlAuthority.js')
let SetCurrentAircraftLocAsHomePoint = require('./SetCurrentAircraftLocAsHomePoint.js')
let CameraEV = require('./CameraEV.js')
let ResumeWaypointV2Mission = require('./ResumeWaypointV2Mission.js')

module.exports = {
  MissionWpAction: MissionWpAction,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  GetSingleBatteryDynamicInfo: GetSingleBatteryDynamicInfo,
  SetJoystickMode: SetJoystickMode,
  CameraTapZoomPoint: CameraTapZoomPoint,
  SetAvoidEnable: SetAvoidEnable,
  DownloadWaypointV2Mission: DownloadWaypointV2Mission,
  CameraAperture: CameraAperture,
  MFIO: MFIO,
  MissionHpUpload: MissionHpUpload,
  SetGoHomeAltitude: SetGoHomeAltitude,
  SendPayloadData: SendPayloadData,
  StereoVGASubscription: StereoVGASubscription,
  KillSwitch: KillSwitch,
  FlightTaskControl: FlightTaskControl,
  SendMobileData: SendMobileData,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  MissionWpUpload: MissionWpUpload,
  CameraFocusPoint: CameraFocusPoint,
  GetAvoidEnable: GetAvoidEnable,
  CameraStartShootAEBPhoto: CameraStartShootAEBPhoto,
  GimbalAction: GimbalAction,
  InitWaypointV2Setting: InitWaypointV2Setting,
  SetupCameraStream: SetupCameraStream,
  SetHomePoint: SetHomePoint,
  DroneArmControl: DroneArmControl,
  SetGlobalCruisespeed: SetGlobalCruisespeed,
  GetDroneType: GetDroneType,
  SetupCameraH264: SetupCameraH264,
  MissionHpAction: MissionHpAction,
  DroneTaskControl: DroneTaskControl,
  MissionHpGetInfo: MissionHpGetInfo,
  GetM300StereoParams: GetM300StereoParams,
  MissionStatus: MissionStatus,
  Stereo240pSubscription: Stereo240pSubscription,
  MissionWpSetSpeed: MissionWpSetSpeed,
  EmergencyBrake: EmergencyBrake,
  MissionWpGetInfo: MissionWpGetInfo,
  MFIOSetValue: MFIOSetValue,
  UploadWaypointV2Action: UploadWaypointV2Action,
  CameraAction: CameraAction,
  PauseWaypointV2Mission: PauseWaypointV2Mission,
  CameraZoomCtrl: CameraZoomCtrl,
  CameraStartShootBurstPhoto: CameraStartShootBurstPhoto,
  GetGlobalCruisespeed: GetGlobalCruisespeed,
  UploadWaypointV2Mission: UploadWaypointV2Mission,
  QueryDroneVersion: QueryDroneVersion,
  CameraRecordVideoAction: CameraRecordVideoAction,
  SetHardSync: SetHardSync,
  SDKControlAuthority: SDKControlAuthority,
  StartWaypointV2Mission: StartWaypointV2Mission,
  CameraStopShootPhoto: CameraStopShootPhoto,
  SubscribeWaypointV2Event: SubscribeWaypointV2Event,
  CameraSetZoomPara: CameraSetZoomPara,
  JoystickAction: JoystickAction,
  MissionWpGetSpeed: MissionWpGetSpeed,
  StereoDepthSubscription: StereoDepthSubscription,
  CameraStartShootIntervalPhoto: CameraStartShootIntervalPhoto,
  Activation: Activation,
  GetGoHomeAltitude: GetGoHomeAltitude,
  CameraShutterSpeed: CameraShutterSpeed,
  SubscribeWaypointV2State: SubscribeWaypointV2State,
  MFIOConfig: MFIOConfig,
  GetHMSData: GetHMSData,
  StopWaypointV2Mission: StopWaypointV2Mission,
  GetWholeBatteryInfo: GetWholeBatteryInfo,
  SetLocalPosRef: SetLocalPosRef,
  CameraISO: CameraISO,
  GenerateWaypointV2Action: GenerateWaypointV2Action,
  CameraStartShootSinglePhoto: CameraStartShootSinglePhoto,
  MissionHpResetYaw: MissionHpResetYaw,
  ObtainControlAuthority: ObtainControlAuthority,
  SetCurrentAircraftLocAsHomePoint: SetCurrentAircraftLocAsHomePoint,
  CameraEV: CameraEV,
  ResumeWaypointV2Mission: ResumeWaypointV2Mission,
};
