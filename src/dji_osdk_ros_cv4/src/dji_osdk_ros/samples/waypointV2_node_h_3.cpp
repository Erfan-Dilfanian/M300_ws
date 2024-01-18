/** @file mission_node.cpp
 *  @version 4.0
 *  @date July 2020
 *
 *  @brief node of waypoint V2.0.
 *
 *  @Copyright (c) 2020 DJI
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <dji_osdk_ros/waypointV2_node_h_3.h>

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define INF 10e7
#define min(a,b) ((a > b) ? b : a)

static const int N = 5;
static const int M = 1 << (N - 1);

// 节点结构体定义
class node {
public:
    double x, y; // 城市结点的坐标
    int id; // 城市结点的id

    node(int id_, double x_, double y_)
    {
        id = id_;
        x = x_;
        y = y_;
    }
};

// 计算城市间距离
double calculateDis(const node& a, const node& b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
};

// 存储城市之间的距离

double dis[N][N];

node nodes[N] = {
    {0, 0, 0},
    {1, 5, 5},
    {2, 8, 12},
    {3, 9, 3},
    {4, 7, 5},
};

// nodes[0] = {0, }
void deriveDis()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dis[i][j] = calculateDis(nodes[i], nodes[j]);
        }
    }
    
}

// 保存顶点i到状态s最后回到起始点的最小距离
double dp[N][M];
// 保存路径
std::vector<int> path;

// 核心函数，求出动态规划dp数组
void TSP() {
    // 初始化dp[i][0]
    for (int i = 0; i < N; i++) {
        dp[i][0] = dis[i][0];
    }
    // 求解dp[i][j],先更新列再更新行
    for (int j = 1; j < M; j++) {
        for (int i = 0; i < N; i++) {
            dp[i][j] = INF;
            // 如果集合j(或状态j)中包含结点i,则不符合条件退出
            if (((j >> (i - 1)) & 1) == 1) {
                continue;
            }
            for (int k = 1; k < N; k++) {
                if (((j >> (k - 1)) & 1) == 0) {
                    continue;
                }
                if (dp[i][j] > dis[i][k] + dp[k][j ^ (1 << (k - 1))]) {
                    dp[i][j] = dis[i][k] + dp[k][j ^ (1 << (k - 1))];
                }
            }
        }
    }
}

// 判断结点是否都已访问,不包括0号结点
bool isVisited(bool visited[]) {
    for (int i = 1; i < N; i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    return true;
}

// 获取最优路径，保存在path中,根据动态规划公式反向找出最短路径结点
void getPath() {
    // 标记访问数组
    bool visited[N] = { false };
    // 前驱节点编号
    int pioneer = 0, min = INF, S = M - 1, temp;
    // 把起点结点编号加入容器
    path.push_back(0);

    while (!isVisited(visited)) {
        for (int i = 1; i < N; i++) {
            if (visited[i] == false && (S & (1 << (i - 1))) != 0) {
                if (min > dis[pioneer][i] + dp[i][(S ^ (1 << (i - 1)))]) {
                    min = dis[pioneer][i] + dp[i][(S ^ (1 << (i - 1)))];
                    temp = i;
                }
            }
        }
        pioneer = temp;
        path.push_back(pioneer);
        visited[pioneer] = true;
        S = S ^ (1 << (pioneer - 1));
        min = INF;
    }
}

// 输出路径
void printPath() {
    std::cout << "最小路径为：";
    std::vector<int>::iterator it = path.begin();
    for (it; it != path.end(); it++) {
        std::cout << *it << "--->";
    }
    // 单独输出起点编号
    std::cout << 0;
}

void gpsPositionSubCallback(const sensor_msgs::NavSatFix::ConstPtr& gpsPosition)
{
  gps_position_ = *gpsPosition;
}

void waypointV2MissionEventSubCallback(const dji_osdk_ros::WaypointV2MissionEventPush::ConstPtr& waypointV2MissionEventPush)
{
  waypoint_V2_mission_event_push_ = *waypointV2MissionEventPush;

  ROS_INFO("waypoint_V2_mission_event_push_.event ID :0x%x\n", waypoint_V2_mission_event_push_.event);

  if(waypoint_V2_mission_event_push_.event == 0x01)
  {
    ROS_INFO("interruptReason:0x%x\n", waypoint_V2_mission_event_push_.interruptReason);
  }
  if(waypoint_V2_mission_event_push_.event == 0x02)
  {
    ROS_INFO("recoverProcess:0x%x\n", waypoint_V2_mission_event_push_.recoverProcess);
  }
  if(waypoint_V2_mission_event_push_.event== 0x03)
  {
    ROS_INFO("finishReason:0x%x\n", waypoint_V2_mission_event_push_.finishReason);
  }

  if(waypoint_V2_mission_event_push_.event == 0x10)
  {
    ROS_INFO("current waypointIndex:%d\n", waypoint_V2_mission_event_push_.waypointIndex);
  }

  if(waypoint_V2_mission_event_push_.event == 0x11)
  {
    ROS_INFO("currentMissionExecNum:%d\n", waypoint_V2_mission_event_push_.currentMissionExecNum);
  }
}

void waypointV2MissionStateSubCallback(const dji_osdk_ros::WaypointV2MissionStatePush::ConstPtr& waypointV2MissionStatePush)
{
  waypoint_V2_mission_state_push_ = *waypointV2MissionStatePush;

  ROS_INFO("waypointV2MissionStateSubCallback");
  ROS_INFO("missionStatePushAck->commonDataVersion:%d\n",waypoint_V2_mission_state_push_.commonDataVersion);
  ROS_INFO("missionStatePushAck->commonDataLen:%d\n",waypoint_V2_mission_state_push_.commonDataLen);
  ROS_INFO("missionStatePushAck->data.state:0x%x\n",waypoint_V2_mission_state_push_.state);
  ROS_INFO("missionStatePushAck->data.curWaypointIndex:%d\n",waypoint_V2_mission_state_push_.curWaypointIndex);
  ROS_INFO("missionStatePushAck->data.velocity:%d\n",waypoint_V2_mission_state_push_.velocity);
}

void setWaypointV2Defaults(dji_osdk_ros::WaypointV2& waypointV2)
{
  waypointV2.waypointType = dji_osdk_ros::DJIWaypointV2FlightPathModeGoToPointInAStraightLineAndStop;
  waypointV2.headingMode = dji_osdk_ros::DJIWaypointV2HeadingModeAuto;
  waypointV2.config.useLocalCruiseVel = 0;
  waypointV2.config.useLocalMaxVel = 0;

  waypointV2.dampingDistance = 40;
  waypointV2.heading = 0;
  waypointV2.turnMode = dji_osdk_ros::DJIWaypointV2TurnModeClockwise;

  waypointV2.positionX = 0;
  waypointV2.positionY = 0;
  waypointV2.positionZ = 0;
  waypointV2.maxFlightSpeed= 9;
  waypointV2.autoFlightSpeed = 2;
}

std::vector<dji_osdk_ros::WaypointV2> generatePolygonWaypoints(ros::NodeHandle &nh)
{
  // Let's create a vector to store our waypoints in.
  std::vector<dji_osdk_ros::WaypointV2> waypointList;
  dji_osdk_ros::WaypointV2 startPoint;
  dji_osdk_ros::WaypointV2 waypointV2;

  startPoint.latitude  = gps_position_.latitude * C_PI / 180.0;
  startPoint.longitude = gps_position_.longitude * C_PI / 180.0;
  startPoint.relativeHeight = 15;
  setWaypointV2Defaults(startPoint);
  waypointList.push_back(startPoint);

  // Iterative algorithm
  for (int i = 1; i < N; i++) {
    setWaypointV2Defaults(waypointV2);
    waypointV2.latitude = nodes[path[i]].y/EARTH_RADIUS + startPoint.latitude;
    waypointV2.longitude = nodes[path[i]].x/(EARTH_RADIUS * cos(startPoint.latitude)) + startPoint.longitude;
    waypointV2.relativeHeight = startPoint.relativeHeight ;
    waypointList.push_back(waypointV2);
  }
  waypointList.push_back(startPoint);

  return waypointList;
}

bool initWaypointV2Setting(ros::NodeHandle &nh)
{
    waypointV2_init_setting_client = nh.serviceClient<dji_osdk_ros::InitWaypointV2Setting>("dji_osdk_ros/waypointV2_initSetting");
    // initWaypointV2Setting_.request.polygonNum = 6;
    // initWaypointV2Setting_.request.radius = 6;
    initWaypointV2Setting_.request.actionNum = 5;

    /*! Generate actions*/
    generateWaypointV2Actions(nh, initWaypointV2Setting_.request.actionNum);
    initWaypointV2Setting_.request.waypointV2InitSettings.repeatTimes = 1;
    initWaypointV2Setting_.request.waypointV2InitSettings.finishedAction = initWaypointV2Setting_.request.waypointV2InitSettings.DJIWaypointV2MissionFinishedGoHome;
    initWaypointV2Setting_.request.waypointV2InitSettings.maxFlightSpeed = 10;
    initWaypointV2Setting_.request.waypointV2InitSettings.autoFlightSpeed = 2;
    initWaypointV2Setting_.request.waypointV2InitSettings.exitMissionOnRCSignalLost = 1;
    initWaypointV2Setting_.request.waypointV2InitSettings.gotoFirstWaypointMode = initWaypointV2Setting_.request.waypointV2InitSettings.DJIWaypointV2MissionGotoFirstWaypointModePointToPoint;
    initWaypointV2Setting_.request.waypointV2InitSettings.mission = generatePolygonWaypoints(nh);
    initWaypointV2Setting_.request.waypointV2InitSettings.missTotalLen = initWaypointV2Setting_.request.waypointV2InitSettings.mission.size();

    waypointV2_init_setting_client.call(initWaypointV2Setting_);
    if (initWaypointV2Setting_.response.result)
    {
      ROS_INFO("Init mission setting successfully!\n");
    }
    else
    {
      ROS_ERROR("Init mission setting failed!\n");
    }

    return initWaypointV2Setting_.response.result;

}

bool uploadWaypointV2Mission(ros::NodeHandle &nh)
{
    waypointV2_upload_mission_client = nh.serviceClient<dji_osdk_ros::UploadWaypointV2Mission>("dji_osdk_ros/waypointV2_uploadMission");
    waypointV2_upload_mission_client.call(uploadWaypointV2Mission_);

    if(uploadWaypointV2Mission_.response.result)
    {
      ROS_INFO("Upload waypoint v2 mission successfully!\n");
    }
    else
    {
      ROS_ERROR("Upload waypoint v2 mission failed!\n");
    }

    return uploadWaypointV2Mission_.response.result;
}

bool uploadWaypointV2Action(ros::NodeHandle &nh)
{
    waypointV2_upload_action_client = nh.serviceClient<dji_osdk_ros::UploadWaypointV2Action>("dji_osdk_ros/waypointV2_uploadAction");
    waypointV2_upload_action_client.call(uploadWaypointV2Action_);

    if(uploadWaypointV2Action_.response.result)
    {
      ROS_INFO("Upload waypoint v2 actions successfully!\n");
    }
    else
    {
      ROS_ERROR("Upload waypoint v2 actions failed!\n");
    }

    return uploadWaypointV2Action_.response.result;
}

bool downloadWaypointV2Mission(ros::NodeHandle &nh, std::vector<dji_osdk_ros::WaypointV2> &mission)
{
    waypointV2_download_mission_client = nh.serviceClient<dji_osdk_ros::DownloadWaypointV2Mission>("dji_osdk_ros/waypointV2_downloadMission");
    waypointV2_download_mission_client.call(downloadWaypointV2Mission_);
    mission = downloadWaypointV2Mission_.response.mission;

    if(downloadWaypointV2Mission_.response.result)
    {
      ROS_INFO("Download waypoint v2 mission successfully!\n");
    }
    else
    {
      ROS_ERROR("Download waypoint v2 mission failed!\n");
    }

    return downloadWaypointV2Mission_.response.result; 
}

bool startWaypointV2Mission(ros::NodeHandle &nh)
{
    waypointV2_start_mission_client = nh.serviceClient<dji_osdk_ros::StartWaypointV2Mission>("dji_osdk_ros/waypointV2_startMission");
    waypointV2_start_mission_client.call(startWaypointV2Mission_);

    if(startWaypointV2Mission_.response.result)
    {
      ROS_INFO("Start waypoint v2 mission successfully!\n");
    }
    else
    {
      ROS_ERROR("Start waypoint v2 mission failed!\n");
    }

    return startWaypointV2Mission_.response.result;
}

bool stopWaypointV2Mission(ros::NodeHandle &nh)
{
    waypointV2_stop_mission_client = nh.serviceClient<dji_osdk_ros::StopWaypointV2Mission>("dji_osdk_ros/waypointV2_stopMission");
    waypointV2_stop_mission_client.call(stopWaypointV2Mission_);

    if(stopWaypointV2Mission_.response.result)
    {
      ROS_INFO("Stop waypoint v2 mission successfully!\n");
    }
    else
    {
      ROS_ERROR("Stop waypoint v2 mission failed!\n");
    }

    return stopWaypointV2Mission_.response.result;
}

bool pauseWaypointV2Mission(ros::NodeHandle &nh)
{
    waypointV2_pause_mission_client = nh.serviceClient<dji_osdk_ros::PauseWaypointV2Mission>("dji_osdk_ros/waypointV2_pauseMission");
    waypointV2_pause_mission_client.call(pauseWaypointV2Mission_);

    if(pauseWaypointV2Mission_.response.result)
    {
      ROS_INFO("Pause waypoint v2 mission successfully!\n");
    }
    else
    {
      ROS_ERROR("Pause waypoint v2 mission failed!\n");
    }

    return pauseWaypointV2Mission_.response.result;
}

bool resumeWaypointV2Mission(ros::NodeHandle &nh)
{
    waypointV2_resume_mission_client = nh.serviceClient<dji_osdk_ros::ResumeWaypointV2Mission>("dji_osdk_ros/waypointV2_resumeMission");
    waypointV2_resume_mission_client.call(resumeWaypointV2Mission_);

    if(resumeWaypointV2Mission_.response.result)
    {
      ROS_INFO("Resume Waypoint v2 mission successfully!\n");
    }
    else
    {
      ROS_ERROR("Resume Waypoint v2 mission failed!\n");
    }

    return resumeWaypointV2Mission_.response.result;
}

bool generateWaypointV2Actions(ros::NodeHandle &nh, uint16_t actionNum)
{
    waypointV2_generate_actions_client = nh.serviceClient<dji_osdk_ros::GenerateWaypointV2Action>("dji_osdk_ros/waypointV2_generateActions");
    dji_osdk_ros::WaypointV2Action actionVector;
    for (uint16_t i = 0; i < actionNum; i++)
    {
      actionVector.actionId  = i;
      actionVector.waypointV2ActionTriggerType  = dji_osdk_ros::WaypointV2Action::DJIWaypointV2ActionTriggerTypeSampleReachPoint;
      actionVector.waypointV2SampleReachPointTrigger.waypointIndex = i;
      actionVector.waypointV2SampleReachPointTrigger.terminateNum = 0;
      actionVector.waypointV2ACtionActuatorType = dji_osdk_ros::WaypointV2Action::DJIWaypointV2ActionActuatorTypeCamera;
      actionVector.waypointV2CameraActuator.actuatorIndex = 0;
      actionVector.waypointV2CameraActuator.DJIWaypointV2ActionActuatorCameraOperationType = dji_osdk_ros::WaypointV2CameraActuator::DJIWaypointV2ActionActuatorCameraOperationTypeTakePhoto;
      generateWaypointV2Action_.request.actions.push_back(actionVector);
    }

    waypointV2_generate_actions_client.call(generateWaypointV2Action_);

    return generateWaypointV2Action_.response.result;
}

bool setGlobalCruiseSpeed(ros::NodeHandle &nh, float32_t cruiseSpeed)
{
    waypointV2_set_global_cruisespeed_client = nh.serviceClient<dji_osdk_ros::SetGlobalCruisespeed>("dji_osdk_ros/waypointV2_setGlobalCruisespeed");
    setGlobalCruisespeed_.request.global_cruisespeed = cruiseSpeed;
    waypointV2_set_global_cruisespeed_client.call(setGlobalCruisespeed_);

    if(setGlobalCruisespeed_.response.result)
    {
      ROS_INFO("Current cruise speed is: %f m/s\n", cruiseSpeed);
    }
    else
    {
      ROS_ERROR("Set glogal cruise speed failed\n");
    }

    return setGlobalCruisespeed_.response.result;
}

float32_t getGlobalCruiseSpeed(ros::NodeHandle &nh)
{
    waypointV2_get_global_cruisespeed_client = nh.serviceClient<dji_osdk_ros::GetGlobalCruisespeed>("dji_osdk_ros/waypointV2_getGlobalCruisespeed");
    waypointV2_get_global_cruisespeed_client.call(getGlobalCruisespeed_);

    ROS_INFO("Current cruise speed is: %f m/s\n", getGlobalCruisespeed_.response.global_cruisespeed);

    return getGlobalCruisespeed_.response.global_cruisespeed;
}

bool runWaypointV2Mission(ros::NodeHandle &nh)
{
  int timeout = 1;
  bool result = false;

  get_drone_type_client = nh.serviceClient<dji_osdk_ros::GetDroneType>("get_drone_type");
  waypointV2_mission_state_push_client = nh.serviceClient<dji_osdk_ros::SubscribeWaypointV2Event>("dji_osdk_ros/waypointV2_subscribeMissionState");
  waypointV2_mission_event_push_client = nh.serviceClient<dji_osdk_ros::SubscribeWaypointV2State>("dji_osdk_ros/waypointV2_subscribeMissionEvent");

  waypointV2EventSub = nh.subscribe("dji_osdk_ros/waypointV2_mission_event", 10, &waypointV2MissionEventSubCallback);
  waypointV2StateSub = nh.subscribe("dji_osdk_ros/waypointV2_mission_state", 10, &waypointV2MissionStateSubCallback);

  subscribeWaypointV2Event_.request.enable_sub = true;
  subscribeWaypointV2State_.request.enable_sub = true;
 
  get_drone_type_client.call(drone_type);
  if (drone_type.response.drone_type != static_cast<uint8_t>(dji_osdk_ros::Dronetype::M300))
  {
      ROS_DEBUG("This sample only supports M300!\n");
      return false;
  }

  waypointV2_mission_state_push_client.call(subscribeWaypointV2State_);
  waypointV2_mission_event_push_client.call(subscribeWaypointV2Event_);

    /*! init mission */
    
  result = initWaypointV2Setting(nh);
  if(!result)
  {
    return false;
  }
  sleep(timeout);

  /*! upload mission */
  result = uploadWaypointV2Mission(nh);
  if(!result)
  {
    return false;
  }
  sleep(timeout);

 /*! download mission */
  std::vector<dji_osdk_ros::WaypointV2> mission;
  result = downloadWaypointV2Mission(nh, mission);
  if(!result)
  {
    return false;
  }
  sleep(timeout);

  /*! upload  actions */
  result = uploadWaypointV2Action(nh);
  if(!result)
  {
    return false;
  }
  sleep(timeout);

  /*! start mission */
  result = startWaypointV2Mission(nh);
  if(!result)
  {
    return false;
  }
  sleep(20);

  /*! set global cruise speed */
  result = setGlobalCruiseSpeed(nh, 1.5);
  if(!result)
  {
    return false;
  }
  sleep(timeout);

  /*! get global cruise speed */
  float32_t globalCruiseSpeed = 0;
  globalCruiseSpeed = getGlobalCruiseSpeed(nh);
  sleep(timeout);

  /*! pause the mission*/
  result = pauseWaypointV2Mission(nh);
  if(!result)
  {
    return false;
  }
  sleep(5);

  /*! resume the mission*/
  result = resumeWaypointV2Mission(nh);
  if(!result)
  {
    return false;
  }
  sleep(20);

return true;
}



int main(int argc, char** argv)
{
    deriveDis();
    TSP();
    getPath();

    ros::init(argc, argv, "waypointV2_node_h_3");
    ros::NodeHandle nh;

    ros::Subscriber gpsPositionSub = nh.subscribe("dji_osdk_ros/gps_position", 10, &gpsPositionSubCallback);
    auto obtain_ctrl_authority_client = nh.serviceClient<dji_osdk_ros::ObtainControlAuthority>(
      "obtain_release_control_authority");
    
    //if you want to fly without rc ,you need to obtain ctrl authority.Or it will enter rc lost.
    dji_osdk_ros::ObtainControlAuthority obtainCtrlAuthority;
    obtainCtrlAuthority.request.enable_obtain = true;
    obtain_ctrl_authority_client.call(obtainCtrlAuthority);

    ros::Duration(1).sleep();
    ros::AsyncSpinner spinner(1);
    spinner.start();
    runWaypointV2Mission(nh);

    ros::waitForShutdown();

    return 0;
}
