/** @file advanced_sensing_node.cpp
author: Erfan Dilfanian, Huajun Dong
 */

//INCLUDE
#include <ros/ros.h>
#include <dji_osdk_ros/common_type.h>
#include <iostream>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

#include <vector>
#include <random>
#include <cmath>


#include <dji_osdk_ros/FlightTaskControl.h>
#include <dji_osdk_ros/SetGoHomeAltitude.h>
#include <dji_osdk_ros/GetGoHomeAltitude.h>
#include <dji_osdk_ros/SetCurrentAircraftLocAsHomePoint.h>
#include <dji_osdk_ros/SetAvoidEnable.h>
#include <dji_osdk_ros/ObtainControlAuthority.h>
#include <dji_osdk_ros/EmergencyBrake.h>
#include <dji_osdk_ros/GetAvoidEnable.h>

#include <cstdlib>

#include<dji_osdk_ros/SetJoystickMode.h>
#include<dji_osdk_ros/JoystickAction.h>

#include <dji_osdk_ros/common_type.h>
#include <dji_osdk_ros/GimbalAction.h>
#include <dji_osdk_ros/CameraEV.h>
#include <dji_osdk_ros/CameraShutterSpeed.h>
#include <dji_osdk_ros/CameraAperture.h>
#include <dji_osdk_ros/CameraISO.h>
#include <dji_osdk_ros/CameraFocusPoint.h>
#include <dji_osdk_ros/CameraTapZoomPoint.h>
#include <dji_osdk_ros/CameraSetZoomPara.h>
#include <dji_osdk_ros/CameraZoomCtrl.h>
#include <dji_osdk_ros/CameraStartShootBurstPhoto.h>
#include <dji_osdk_ros/CameraStartShootAEBPhoto.h>
#include <dji_osdk_ros/CameraStartShootSinglePhoto.h>
#include <dji_osdk_ros/CameraStartShootIntervalPhoto.h>
#include <dji_osdk_ros/CameraStopShootPhoto.h>
#include <dji_osdk_ros/CameraRecordVideoAction.h>

#include <fstream>

// #include <app/single_fire_point_task/SingleFirePointTaskManager.hpp>
#include <sensor_msgs/NavSatFix.h>

#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseArray.h>

#include <vector>
#include <sensor_msgs/ChannelFloat32.h>
#include <glog/logging.h>
#include <message_filters/time_synchronizer.h>

#include <geometry_msgs/QuaternionStamped.h>


#include <tools/MathLib.hpp>

// #include <dji_sdk_ros/SetLocalPosRef.h>

#include "std_msgs/UInt16.h"

//CODE

using namespace dji_osdk_ros;
using namespace std;

/*
FFDS::APP::SingleFirePointTaskManager::SingleFirePointTaskManager() {



    task_control_client =
            nh.serviceClient<dji_osdk_ros::FlightTaskControl>("/flight_task_control");


    gpsPositionSub =
            nh.subscribe("dji_osdk_ros/gps_position", 10,
                         &SingleFirePointTaskManager::gpsPositionSubCallback, this);
    attitudeSub =
            nh.subscribe("dji_osdk_ros/attitude", 10,
                         &SingleFirePointTaskManager::attitudeSubCallback, this);*/



// gimbal_control_client = nh.serviceClient<dji_osdk_ros::GimbalAction>("gimbal_task_control");





// obtain the authorization when really needed... Now :)
/* obtainCtrlAuthority.request.enable_obtain = true;
 obtain_ctrl_authority_client.call(obtainCtrlAuthority);
 if (obtainCtrlAuthority.response.result) {
     PRINT_INFO("get control authority!");
 } else {
     PRINT_ERROR("can NOT get control authority!");
     return;
 }

 ros::Duration(3.0).sleep();
 //PRINT_INFO("initializing Done");
}
*/

/*FFDS::APP::SingleFirePointTaskManager::~SingleFirePointTaskManager() {
   /* obtainCtrlAuthority.request.enable_obtain = false;
    obtain_ctrl_authority_client.call(obtainCtrlAuthority);
    if (obtainCtrlAuthority.response.result) {
        PRINT_INFO("release control authority!");
    } else {
        PRINT_ERROR("can NOT release control authority!");
    }*/
//}

ros::Publisher servoPub;

ros::ServiceClient task_control_client;
ros::ServiceClient set_joystick_mode_client;
ros::ServiceClient joystick_action_client;

bool moveByPosOffset(FlightTaskControl &task, const JoystickCommand &offsetDesired,
                     float posThresholdInM,
                     float yawThresholdInDeg);

void CircularPlanner(const JoystickCommand &offsetDesired, uint32_t timeMs);


sensor_msgs::NavSatFix gps_position_;

geometry_msgs::PointStamped local_position_;

float euler[3];


void gpsPositionSubCallback2(
        const sensor_msgs::NavSatFix::ConstPtr &gpsPosition) {
    gps_position_ = *gpsPosition;
    // ROS_INFO("latitude is [%f]",gps_position_.latitude);
    // ROS_INFO("longitude is [%f]",gps_position_.longitude);

}

void QuaternionSubCallback(const geometry_msgs::QuaternionStamped msg) {


    float quat[4];
    quat[0] = msg.quaternion.x;
    quat[1] = msg.quaternion.y;
    quat[2] = msg.quaternion.z;
    quat[3] = msg.quaternion.w;

    euler[0] = atan2(2.0 * (quat[3] * quat[2] + quat[0] * quat[1]),
                     1.0 - 2.0 * (quat[1] * quat[1] + quat[2] * quat[2]));
    euler[1] = asin(2.0 * (quat[2] * quat[0] - quat[3] * quat[1]));
    euler[2] = atan2(2.0 * (quat[3] * quat[0] + quat[1] * quat[2]),
                     -1.0 + 2.0 * (quat[0] * quat[0] + quat[1] * quat[1]));
    euler[0] = euler[0] * 180 / M_PI; // radian to degree
    euler[1] = euler[1] * 180 / M_PI; // radian to degree
    euler[2] = euler[2] * 180 / M_PI; // radian to degree

    // calibration. making frames equal. when drone pointing north, yaw be 0.
    // beware of changes between NED  and ENU
    euler[0] = 90 - euler[0];


    // euler[0] is yaw
}

void LocalPositionSubCallback(
        const geometry_msgs::PointStamped::ConstPtr &LocalPosition) {
    local_position_ = *LocalPosition;

}


/*sensor_msgs::NavSatFix
FFDS::APP::SingleFirePointTaskManager::getHomeGPosAverage(int times) {
    FFDS::TOOLS::PositionHelper posHelper;
    return posHelper.getAverageGPS(times);
}*/

sensor_msgs::NavSatFix getAverageGPS(const int);


float cosd(float angleDegrees) {
    double angleRadians = angleDegrees * (M_PI / 180.0);
    return cos(angleRadians);
}

float sind(float angleDegrees) {
    double angleRadians = angleDegrees * (M_PI / 180.0);
    return sin(angleRadians);
}

float Rad2Deg(float Rad) { return Rad * (180 / M_PI); }

sensor_msgs::NavSatFix fire_gps;

static int N;//Fire spots number

static int M;

float INF = 1e100; // infinity

//Define destination class
class node {
public:
    double x, y; // coordinate of the node
    double z; //height of the node
    int id; // id of the node
};


//Define vector to store all the nodes
std::vector <node> nodes_vec;

//Define the function to calculate the distance of nodes
double calculateDis(const node &a, const node &b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
};

//A function defination for TSP
bool isVisited(bool visited[]) {
    for (int i = 1; i < N; i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    return true;
}

void FireCallback(const geometry_msgs::PoseArrayConstPtr &fire_spots_GPS) {
    // print number of fire spots
    LOG(INFO) << "The number of fire spots: " << fire_spots_GPS->poses.size() << ".";
    // print the average GPS positions of fire spots
    double latitude = 0;
    double longitude = 0;
    double altitude = 0;
    for (const geometry_msgs::Pose &fire_spot: fire_spots_GPS->poses) {
        latitude += fire_spot.position.x;
        longitude += fire_spot.position.y;
        altitude += fire_spot.position.z;
    }
    latitude /= fire_spots_GPS->poses.size();
    longitude /= fire_spots_GPS->poses.size();
    altitude /= fire_spots_GPS->poses.size();
    LOG(INFO) << "The average GPS positions of fire spots: " << latitude << ", " << longitude << ", " << altitude
              << ".";

    fire_gps.latitude = latitude;
    fire_gps.longitude = longitude;
    fire_gps.altitude = altitude;

}

void
velocityAndYawRateControl(const JoystickCommand &offsetDesired, uint32_t timeMs, float abs_vel, float d, float height,
                          float delay);

void controlServo(int angle) {
    std_msgs::UInt16 msg;
    msg.data = angle;
    servoPub.publish(msg);
}


void FireCallback2(const geometry_msgs::PoseArrayConstPtr &fire_spots_GPS) {
    // Print number of fire spots
    LOG(INFO) << "The number of fire spots: " << fire_spots_GPS->poses.size() << ".";

    //Put subscribed fire spots number to N
    N = fire_spots_GPS->poses.size();

    //Define array to store all the nodes
    node nodes[N];


    //Put fire spots GPS into “nodes”， array of node class
    int i = 1;

    for (const geometry_msgs::Pose &fire_spot: fire_spots_GPS->poses) {
        nodes[i].id = i;
        nodes[i].x = fire_spot.position.x;
        nodes[i].y = fire_spot.position.y;
        nodes[i].z = fire_spot.position.z;
        i++;
    }


    //    homeGPos = getAverageGPS(50);
    ros::spinOnce();

    //Put home GPS into “nodes”， array of node class
    nodes[0].id = 0;
    nodes[0].x = gps_position_.latitude;
    nodes[0].y = gps_position_.longitude;
    nodes[0].z = gps_position_.altitude;

    //Get home GPS
    float homeGPS_posArray[3];
    homeGPS_posArray[0] = gps_position_.latitude;
    homeGPS_posArray[1] = gps_position_.longitude;
    homeGPS_posArray[2] = gps_position_.altitude;

    //Define a 2D array to store the distance
    double dis[N][N];

    //Calculate the distance of nodes
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dis[i][j] = calculateDis(nodes[i], nodes[j]);
        }
    }

    //The following codes are for dynamic programming
    M = 1 << (N - 1);
    double dp[N][M];
    // store the path
    std::vector<int> path;

    //TSP Algorithm
    // ��ʼ��dp[i][0]
    for (int i = 0; i < N; i++) {
        dp[i][0] = dis[i][0];
    }
    // ���dp[i][j],�ȸ������ٸ�����
    for (int j = 1; j < M; j++) {
        for (int i = 0; i < N; i++) {
            dp[i][j] = INF;
            // �������j(��״̬j)�а������i,�򲻷��������˳�
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

    // ��Ƿ�������
    bool visited[N] = {false};
    // ǰ���ڵ���
    int pioneer = 0, min = INF, S = M - 1, temp;
    // ��������ż�������
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
    //Till here we get the path vector, which stores the travelling sequence for the nodes

    // Put the sequenced nodes in array into predefined globalvector
    for (int i = 1; i < N; i++) {
        nodes_vec.push_back(nodes[path[i]]);
    }
}

char in_or_out;  // this variable tells whether you are doing indoor experiment or outdoor experiment

void LineOfFireCallback(const geometry_msgs::PoseArrayConstPtr &fire_spots_GPS) {

    cout << "LineOfFireCallback called";

    // Print number of fire spots
    LOG(INFO) << "The number of fire spots: " << fire_spots_GPS->poses.size() << ".";

    //Put subscribed fire spots number to N
    N = fire_spots_GPS->poses.size();

    // Define array to store all the nodes
    std::vector<node> nodes(fire_spots_GPS->poses.size());

    // Put fire spots GPS into “nodes”， array of node class
    int i = 0;
    for (const geometry_msgs::Pose &fire_spot: fire_spots_GPS->poses) {
        nodes[i].id = i;                   // fire index
        nodes[i].x = fire_spot.position.x; // fire latitude
        nodes[i].y = fire_spot.position.y; // fire longitude
        nodes[i].z = fire_spot.position.z; // fire altitude
        i++;
    }

    // Copy nodes to nodes_vec
    nodes_vec = nodes;
}


// Define a structure to represent a 2D point
struct Point {
    float x, y;
};

// Structure to hold the parameters of a line
struct Line {
    double slope;
    double intercept;
    int num_inliers;
};

// Function to calculate the distance between two points
double distance(const Point &p1, const Point &p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

// Function to fit a line to a set of 2D points using RANSAC
Line fitLineRANSAC(const std::vector <Point> &points, int num_iterations, double threshold) {
    cout << "We are in fitLineRANSAC function" << endl;
    // Initialize variables to store the best-fitting line parameters
    Line best_line = {0.0, 0.0, 0};

    // Random number generator for sampling points
    std::random_device rd;
    std::cout << "Random device seed: " << rd() << std::endl; // Print random device seed
    std::mt19937 gen(rd());
    std::cout << "Initial value of gen: " << gen() << std::endl; // Print initial value of gen


    for (int i = 0; i < num_iterations; ++i) {
        // Randomly sample two points
        std::uniform_int_distribution<int> dist(0, points.size() - 1);
        int idx1 = dist(gen);
        int idx2 = dist(gen);

        // Fit a line to the sampled points (simple linear regression)
        float x1 = points[idx1].x, y1 = points[idx1].y;
        float x2 = points[idx2].x, y2 = points[idx2].y;
        double slope = (y2 - y1) / (x2 - x1);
        double intercept = y1 - slope * x1;

        // Print the slope and intercept of the current line
        std::cout << "Iteration " << i << ": Slope = " << slope << ", Intercept = " << intercept << std::endl;

        // Count the number of inliers
        int inliers = 0;
        for (const Point &p: points) {
            double d = std::abs(p.y - (slope * p.x + intercept));
            if (d < threshold) {
                inliers++;
            }
        }

        // Update the best-fitting line if the current line has more inliers
        if (inliers > best_line.num_inliers) {
            best_line.slope = slope;
            best_line.intercept = intercept;
            best_line.num_inliers = inliers;
        }
    }

    return best_line;
}

// Function to process the array and call RANSAC
// Line processArrayAndFitLine(const float fire_gps_local_pos[][3], int size) {

Line processArrayAndFitLine(const float fire_gps_local_pos[][3], int size, float threshold) {


    cout << "We are in ProcessArrayAndFitLine function";
    // Convert the array to vector of points
    std::vector <Point> points;
    for (int i = 0; i < size; ++i) {
        Point p;
        p.x = fire_gps_local_pos[i][0];
        p.y = fire_gps_local_pos[i][1];
        points.push_back(p);

        // Print the x and y values
        std::cout << "Point " << i + 1 << ": x = " << p.x << ", y = " << p.y << std::endl;


    }

    // Fit a line using RANSAC
    int num_iterations = 100; // Adjust as needed

    return fitLineRANSAC(points, num_iterations, threshold);
}

// Function to locate the point on the fitted line closest to the first sample
/*
Point closestPointOnLine(const Line& line, const Point& first_sample) {
    // Calculate the point on the line closest to the first sample
    Point closest_point;
    closest_point.x = (first_sample.y - line.intercept + line.slope * first_sample.x) / (1 + std::pow(line.slope, 2));
    closest_point.y = line.slope * closest_point.x + line.intercept;
    return closest_point;
}
*/
// Function to calculate the point on the line closest to the given sample point
Point closestPointOnLine(const Line &line, const Point &sample_point) {
    Point closest_point;
    double slope_inverse = -1 / line.slope; // Slope of the line perpendicular to the given line

    // Calculate x-coordinate of the closest point using perpendicular distance formula
    closest_point.x = (sample_point.x + slope_inverse * sample_point.y - line.intercept + line.slope * line.intercept) /
                      (line.slope + slope_inverse);

    // Calculate y-coordinate of the closest point using the equation of the given line
    closest_point.y = line.slope * closest_point.x + line.intercept;

    return closest_point;
}

// Function to find the intersection point of two lines
Point intersectionPoint(const Line &best_line, const Point &first_sample) {
    Point intersection;

    // Calculate the slope of the line perpendicular to the best-fitting line
    double perpendicular_slope = -1.0 / best_line.slope;

    // Calculate the y-intercept of the line passing through the first sample
    double perpendicular_intercept = first_sample.y - perpendicular_slope * first_sample.x;

    // Calculate the x-coordinate of the intersection point
    intersection.x = (perpendicular_intercept - best_line.intercept) / (best_line.slope - perpendicular_slope);

    // Calculate the y-coordinate of the intersection point
    intersection.y = best_line.slope * intersection.x + best_line.intercept;

    return intersection;
}

// Function to traverse on the best-fitting line from a given point for a certain distance
Point traverseOnLine(const Line &best_line, const Point &starting_point, double distance) {
    Point new_point;

    // Calculate the change in x and y based on the slope of the best-fitting line
    double delta_x = distance / std::sqrt(1 + std::pow(best_line.slope, 2));
    double delta_y = best_line.slope * delta_x;

    // Determine the direction of traversal based on the slope of the line
    if (best_line.slope >= 0) {
        new_point.x = starting_point.x + delta_x;
        new_point.y = starting_point.y + delta_y;
    } else {
        new_point.x = starting_point.x - delta_x;
        new_point.y = starting_point.y - delta_y;
    }

    return new_point;
}

class ZigZagParams {  // A class for ZigZag pattern parameters
public:
    float length; //zigzag length
    float width;  //zigzag width
    int number;   //number of zigzag
    int split;  //division in each branch of the zigzag
    float orientation; //orientation of the zigzag
/*
    ZigZagParams(float l, float w, float o, int n, int s) {
        length = l;
        width = w;
        number = n;
        split = s;
        orientation = o;
    }
*/

};

void ZigZagPlanner(FlightTaskControl &task, ZigZagParams zz_params);

Point GPS2Coordinates(sensor_msgs::NavSatFix homeGPos, sensor_msgs::NavSatFix GPS){
    Point coordinates;
    float homeGPS_posArray[3] = {homeGPos.latitude, homeGPos.longitude, homeGPos.altitude};

    float current_GPS_posArray[3] = {gps_position_.latitude, gps_position_.longitude, gps_position_.altitude};

    ROS_INFO("homegpos latitude is [%f]", homeGPS_posArray[0]);
    ROS_INFO("homegpos longitude is [%f]", homeGPS_posArray[1]);
    ROS_INFO("homegpos attitude is [%f]", homeGPS_posArray[2]);

    ROS_INFO("currentpos latitude is [%f]", current_GPS_posArray[0]);
    ROS_INFO("currentgpos longitude is [%f]", current_GPS_posArray[1]);
    ROS_INFO("currentgpos attitude is [%f]", current_GPS_posArray[2]);

    // ros::Duration(2).sleep();

    float m[3];


    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, m);

    ROS_INFO("x is [%f]", m[0]);
    ROS_INFO("y is [%f]", m[1]);

    m[0] = coordinates.x;
    m[1] = coordinates.y;

    return coordinates;

}

void doRANSAC(std::vector <node> nodes_vec, float fire_coordinates[]);

int main(int argc, char **argv) {

    /*FFDS::MODULES::GimbalCameraOperator gcOperator;

      /*reset the camera and gimbal */
    // if (gcOperator.resetCameraZoom() && gcOperator.resetGimbal()) {
    //    PRINT_INFO("reset camera and gimbal successfully!")
    //} else {
    //   PRINT_WARN("reset camera and gimbal failed!")
    //}

    float release_delay;
/*
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;

    // Open the file for writing
    std::ofstream outputFile(filename);

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1; // Exit with error
    }

    // Write header
    outputFile
            << "M300_position: (s)\tM300.lat \tM300.long \tM300.alt \t fire.lat \t fire.long\t fire.alt \t fire_gps_expected.lat \t fire_gps_expected.long \tfire_gps_expected.alt \n  ";
*/
    ros::init(argc, argv, "flight_control_node");
    ros::NodeHandle nh;
    task_control_client = nh.serviceClient<FlightTaskControl>("/flight_task_control");
    auto set_go_home_altitude_client = nh.serviceClient<SetGoHomeAltitude>("/set_go_home_altitude");
    auto get_go_home_altitude_client = nh.serviceClient<GetGoHomeAltitude>("get_go_home_altitude");
    auto set_current_point_as_home_client = nh.serviceClient<SetCurrentAircraftLocAsHomePoint>(
            "/set_current_aircraft_point_as_home");
    auto enable_horizon_avoid_client = nh.serviceClient<SetAvoidEnable>("/set_horizon_avoid_enable");
    auto enable_upward_avoid_client = nh.serviceClient<SetAvoidEnable>("/set_upwards_avoid_enable");
    auto get_avoid_enable_client = nh.serviceClient<GetAvoidEnable>("get_avoid_enable_status");
    auto obtain_ctrl_authority_client = nh.serviceClient<dji_osdk_ros::ObtainControlAuthority>(
            "obtain_release_control_authority");
    auto emergency_brake_client = nh.serviceClient<dji_osdk_ros::EmergencyBrake>("emergency_brake");

    set_joystick_mode_client = nh.serviceClient<SetJoystickMode>("set_joystick_mode");
    joystick_action_client = nh.serviceClient<JoystickAction>("joystick_action");

    // Here, you can add the code to set the home position using the /dji_sdk/set_local_pos_ref service
    /*ros::ServiceClient client = nh.serviceClient<dji_osdk_ros::SetLocalPosRef>("/set_local_pos_reference");

   // Wait for the service to become available
   if (!setLocalPosRefClient.waitForExistence(ros::Duration(5.0)))
   {
       ROS_ERROR("Service '/dji_sdk/set_local_pos_ref' not available.");
       return 1;
   }

   // Create the service request
   dji_sdk::SetLocalPosRef srv;

   // Call the service to set the home position
   if (setLocalPosRefClient.call(srv))
   {
       if (srv.response.result)
       {
           ROS_INFO("Home position set successfully.");
       }
       else
       {
           ROS_ERROR("Failed to set home position.");
       }
   }
   else
   {
       ROS_ERROR("Service call failed.");
       return 1;
   }

*/

    cout << "please select case (all cases are for single fire point): " << std::endl
         << "[a] In-motion-dropping without geo-positioning" << std::endl
         << "[b] Hovering dropping after geo-positioning" << std::endl << "[c] In-motion-dropping after geo-positioning"
         << std::endl << "[d] guided-IN-motion-dropping after geopositioning"
         << std::endl << "[e] Multiple fire spots hovering mode"
         << std::endl << "[f] Line of fire" << std::endl;
    char scenario;
    cin >> scenario;

    cout << "please enter camera pitch angle in degree (no f at end please)" << endl;
    float camera_pitch;
    cin >> camera_pitch;

    cout << "indoor test or outdoor test?" << endl << "[a] indoor" << endl << "[b] outdoor" << endl;
    cin >> in_or_out;

    cout << "please enter valve delay in miliseconds" << endl;
    cin >> release_delay;

    float height;
    cout << "please enter altitude to reach" << endl;
    cin >> height;


    auto gimbal_control_client = nh.serviceClient<GimbalAction>("gimbal_task_control");
    auto camera_set_EV_client = nh.serviceClient<CameraEV>("camera_task_set_EV");
    auto camera_set_shutter_speed_client = nh.serviceClient<CameraShutterSpeed>("camera_task_set_shutter_speed");
    auto camera_set_aperture_client = nh.serviceClient<CameraAperture>("camera_task_set_aperture");
    auto camera_set_iso_client = nh.serviceClient<CameraISO>("camera_task_set_ISO");
    auto camera_set_focus_point_client = nh.serviceClient<CameraFocusPoint>("camera_task_set_focus_point");
    auto camera_set_tap_zoom_point_client = nh.serviceClient<CameraTapZoomPoint>("camera_task_tap_zoom_point");
    auto camera_set_zoom_para_client = nh.serviceClient<CameraSetZoomPara>("camera_task_set_zoom_para");
    auto camera_task_zoom_ctrl_client = nh.serviceClient<CameraZoomCtrl>("camera_task_zoom_ctrl");
    auto camera_start_shoot_single_photo_client = nh.serviceClient<CameraStartShootSinglePhoto>(
            "camera_start_shoot_single_photo");
    auto camera_start_shoot_aeb_photo_client = nh.serviceClient<CameraStartShootAEBPhoto>(
            "camera_start_shoot_aeb_photo");
    auto camera_start_shoot_burst_photo_client = nh.serviceClient<CameraStartShootBurstPhoto>(
            "camera_start_shoot_burst_photo");
    auto camera_start_shoot_interval_photo_client = nh.serviceClient<CameraStartShootIntervalPhoto>(
            "camera_start_shoot_interval_photo");
    auto camera_stop_shoot_photo_client = nh.serviceClient<CameraStopShootPhoto>("camera_stop_shoot_photo");
    auto camera_record_video_action_client = nh.serviceClient<CameraRecordVideoAction>("camera_record_video_action");



/*

  std::cout << "Please select the estimated orientation of the fire: ";

    std::cout
            << "| Available commands:                                            |"
            << std::endl;
    std::cout
            << "| [a] North                                |"
            << std::endl;
    std::cout
            << "| [b] North-west             |"
            << std::endl;
    std::cout << "| [c] West  |"
              << std::endl;
    std::cout << "| [d] South-West |"
              << std::endl;
    std::cout << "| [e] South |"
              << std::endl;
    std::cout << "| [f] South-East |"
              << std::endl;
    std::cout << "| [g] East |"
              << std::endl;
    std::cout << "| [h] North-East |"
              << std::endl;
*/



/*
    char inputChar;
    std::cin >> inputChar;

    switch (inputChar) {
        case 'a':
        {
            break;
        }

        
    }
  */

    EmergencyBrake emergency_brake;
    FlightTaskControl control_task;
    ObtainControlAuthority obtainCtrlAuthority;

    obtainCtrlAuthority.request.enable_obtain = true;
    obtain_ctrl_authority_client.call(obtainCtrlAuthority);

    ros::Subscriber gpsPositionSub;
    gpsPositionSub =
            nh.subscribe("dji_osdk_ros/gps_position", 10,
                         gpsPositionSubCallback2);


    ros::Subscriber LocalPositionSub;
    LocalPositionSub =
            nh.subscribe("dji_osdk_ros/local_position", 10,
                         LocalPositionSubCallback);

    ros::Subscriber QuaternionSub;
    QuaternionSub =
            nh.subscribe("dji_osdk_ros/attitude", 10,
                         QuaternionSubCallback);


    servoPub = nh.advertise<std_msgs::UInt16>("servo", 10); // Initialize servoPub

    // subscribe to the fire GPS
    ros::Subscriber fire_spots_GPS_sub = nh.subscribe("/position/fire_spots_GPS", 1, FireCallback);


    sensor_msgs::NavSatFix homeGPos = getAverageGPS(50);
    float homeGPS_posArray[3];
    homeGPS_posArray[0] = homeGPos.latitude;
    homeGPS_posArray[1] = homeGPos.longitude;
    homeGPS_posArray[2] = homeGPos.altitude;

    // FFDS::TOOLS::T a_pos[2];



    Point recent_drone_coord; // recent drone coordinates



    if (scenario == 'a') {


        float lat;
        float lon;
        float alt;
        cout << "please enter fire's latitude" << endl;
        cin >> lat;
        cout << endl;
        cout << "please enter fire's longitude" << endl;
        cin >> lon;
        cout << endl;
        cout << "please enter lateral adjustment" << endl;
        float lateral_adjustment;
        cout << endl;
        cin >> lateral_adjustment;
        // cout<<"please enter fire's alt"<<endl;
        //cin>>alt;

        control_task.request.task = FlightTaskControl::Request::TASK_TAKEOFF;
        ROS_INFO_STREAM("Takeoff request sending ...");
        task_control_client.call(control_task);
        if (control_task.response.result == false) {
            ROS_ERROR_STREAM("Takeoff task failed");
        }

        if (control_task.response.result == true) {
            ROS_INFO_STREAM("Takeoff task successful");
            // ros::Duration(2.0).sleep();




            fire_gps.latitude = lat;
            fire_gps.longitude = lon;
            fire_gps.altitude = alt;

/*
            fire_gps.latitude = 45.45842238198102;
            fire_gps.longitude = -73.93238311980387;
            fire_gps.altitude = 111.356392;
*/

            float fire_GPS_posArray[3]; // posArray :  Position Array

            fire_GPS_posArray[0] = fire_gps.latitude;
            fire_GPS_posArray[1] = fire_gps.longitude;
            fire_GPS_posArray[2] = fire_gps.altitude;

            ros::spinOnce();


            ROS_INFO("fire_GPS_posArray[0] Is [%f]", fire_GPS_posArray[0]);
            ROS_INFO("fire_GPS_posArray[1] Is [%f]", fire_GPS_posArray[1]);
            ROS_INFO("fire_GPS_posArray[2] Is [%f]", fire_GPS_posArray[2]);

            float fire_gps_local_pos[3];

            FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, fire_GPS_posArray, fire_gps_local_pos);

            ROS_INFO("fire_gps_local_pos[0] Is [%f]", fire_gps_local_pos[0]);
            ROS_INFO("fire_gps_local_pos[1] Is [%f]", fire_gps_local_pos[1]);
            ROS_INFO("fire_gps_local_pos[2] Is [%f]", fire_gps_local_pos[2]);

            ros::spinOnce();

            moveByPosOffset(control_task, {0, 0, height - 1, 0}, 1, 3);

            float mission_start_pos[3] = {fire_gps_local_pos[0] - 10, fire_gps_local_pos[1] + 8,
                                          9}; // it also can be current x y z

            ROS_INFO("homegpos latitude is [%f]", homeGPS_posArray[0]);
            ROS_INFO("homegpos longitude is [%f]", homeGPS_posArray[1]);
            ROS_INFO("homegpos attitude is [%f]", homeGPS_posArray[2]);


            float yaw_const = 0;

            moveByPosOffset(control_task,
                            {mission_start_pos[0], mission_start_pos[1], 0, yaw_const}, 1, 3);

            ros::spinOnce();

            float current_GPS_posArray[3];
            current_GPS_posArray[0] = gps_position_.latitude;
            current_GPS_posArray[1] = gps_position_.longitude;
            current_GPS_posArray[2] = gps_position_.altitude;

            FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, mission_start_pos);


            float yaw_adjustment; // yaw adjustment before approach
            float deltaX = fire_gps_local_pos[0] - mission_start_pos[0];
            float deltaY = fire_gps_local_pos[1] - mission_start_pos[1];

            ROS_INFO("deltaX is [%f]", deltaX);
            ROS_INFO("deltaY is [%f]", deltaY);


            yaw_adjustment = Rad2Deg(atan2(deltaY, deltaX)); // note that tan2 output is in radian
            // Also I added 90 as we want the yaw angle from x axis which is in Y direction

            ROS_INFO("yaw_adjustment_angle is [%f]", yaw_adjustment);
            moveByPosOffset(control_task, {0, 0, 0, yaw_adjustment}, 1,
                            3);  // note that x y z goes into this funciton

            // velocity mission

            float d = sqrt(
                    pow(fire_gps_local_pos[0] - mission_start_pos[0], 2) +
                    pow(fire_gps_local_pos[1] - mission_start_pos[1], 2));

            float abs_vel = 5; // absolute velocity that needs to be projected



            moveByPosOffset(control_task,
                            {-lateral_adjustment * sind(yaw_adjustment), lateral_adjustment * cosd(yaw_adjustment), 0,
                             yaw_adjustment}, 1,
                            3);


            velocityAndYawRateControl({abs_vel * cosd(yaw_adjustment), abs_vel * sind(yaw_adjustment), 0}, 5000,
                                      abs_vel, d, height, release_delay);


            ROS_INFO_STREAM("Step 1 over!EmergencyBrake for 2s\n");
            emergency_brake_client.call(emergency_brake);
            ros::Duration(2).sleep();
        }

    }
    if (scenario == 'b' || scenario == 'c' || scenario == 'd') {


        float fire_GPS_posArray[3]; // posArray :  Position Array


        sensor_msgs::NavSatFix fire_gps_expected;
        float epsilon;

        float diff_latitude;
        float diff_longitude;
        float diff_altitude;

        float zz_l; //zigzag_length
        float zz_w; //zigzag_width

        cout << "please enter zigzag length (like 8 meter)" << endl;
        cin >> zz_l;
        cout << "please enter zigzag width (like 4 meter)" << endl;
        cin >> zz_w;

        float split; // split value
        cout << "please enter the split value, like 12" << endl;
        cin >> split;


        std::cout << "Please enter the approximate expected GPS position of fire: " << std::endl;
        std::cout << "Latitude: ";
        std::cin >> fire_gps_expected.latitude;
        std::cout << "Longitude: ";
        std::cin >> fire_gps_expected.longitude;
        std::cout << "Altitude: ";
        std::cin >> fire_gps_expected.altitude;

        cout << "please enter the epsilon, the allowed geolocalizing error, like 0.001" << endl;
        cin >> epsilon;

        //note that inputs shoudl be before take off!
        float m[3];

        float current_GPS_posArray[3];

        float yaw_const;
        std::cout << " please enter initial yaw angle in degree-Z axes downward" << std::endl;
        std::cin >> yaw_const;

        float gimbal_yaw_adjustment;
        cout << "please enter gimbal yaw adjustment" << endl;
        cin >> gimbal_yaw_adjustment;


        control_task.request.task = FlightTaskControl::Request::TASK_TAKEOFF;
        ROS_INFO_STREAM("Takeoff request sending ...");
        task_control_client.call(control_task);
        if (control_task.response.result == false) {
            ROS_ERROR_STREAM("Takeoff task failed");
        }

        if (control_task.response.result == true) {
            ROS_INFO_STREAM("Takeoff task successful");
            // ros::Duration(2.0).sleep();

            moveByPosOffset(control_task, {0, 0, 0, yaw_const}, 1, 3);

            ros::spinOnce();
            ROS_INFO("euler1 is [%f]", euler[0]);
            ROS_INFO("euler2 is [%f]", euler[1]);
            ROS_INFO("euler3 is [%f]", euler[2]);

            ROS_INFO("yaw_const is [%f]", yaw_const);


            GimbalAction gimbalAction;
            gimbalAction.request.is_reset = false;
            gimbalAction.request.payload_index = static_cast<uint8_t>(dji_osdk_ros::PayloadIndex::PAYLOAD_INDEX_0);
            gimbalAction.request.rotationMode = 0;
            gimbalAction.request.pitch = camera_pitch;
            gimbalAction.request.roll = 0.0f;
            // gimbalAction.request.yaw = -yaw_const+90;
            gimbalAction.request.yaw = 180.0f + gimbal_yaw_adjustment;
            gimbalAction.request.time = 0.5;
            gimbal_control_client.call(gimbalAction);

            cout << "camera angle changed!" << endl;


            ROS_INFO_STREAM("Move by position offset request sending ...");
            moveByPosOffset(control_task, {0, 0, height - 1, yaw_const}, 1, 3);

            cout << "M300 rotated";


            if (in_or_out == 'b') {
                bool SLAM_flag = 0;
                while (SLAM_flag == 0) {
                    cout << "please rosrun detection and SLAM nodes. Then press 1" << endl;
                    int detect_index;//detection_starter_indicator
                    cin >> detect_index;
                    if (detect_index == 1) { SLAM_flag = 1; }
                    else { cout << "Please press 1 if SLAM is initiated"; }
                }



                // Print the entered GPS coordinates
                std::cout << "Entered GPS position: " << std::endl;
                std::cout << "Latitude: " << fire_gps_expected.latitude << std::endl;
                std::cout << "Longitude: " << fire_gps_expected.longitude << std::endl;
                std::cout << "Altitude: " << fire_gps_expected.altitude << std::endl;


                while (true) {


                    ros::spinOnce();


                    double frequency = 30; // 30 Hz
                    ros::Rate rate(frequency);


                    ROS_INFO("destination y is [%f] and x is [%f]: ", zz_l * sind(yaw_const), zz_l * cosd(yaw_const));

                    float zzl1 = -zz_l * sind(yaw_const) / split;
                    float zzl2 = zz_l * cosd(yaw_const) / split;

                    for (int i = 0; i < split; i++) {

                        moveByPosOffset(control_task, {zzl1, zzl2, 0, yaw_const}, 1, 3);

                        ros::spinOnce();
                        rate.sleep();
                        cout << "ROS spinned" << endl;
                       /* outputFile << std::setprecision(10) << gps_position_.latitude << "\t" << std::setprecision(10)
                                   << gps_position_.longitude << "\t" << std::setprecision(10) << gps_position_.altitude
                                   << "\t" << std::setprecision(10) << fire_gps.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps.longitude << "\t" << std::setprecision(10) << fire_gps.altitude << "\t"
                                   << std::setprecision(10) << fire_gps_expected.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps_expected.longitude << "\t" << std::setprecision(10)
                                   << fire_gps_expected.altitude << "\n";
*/
                    }


                    current_GPS_posArray[0] = gps_position_.latitude;
                    current_GPS_posArray[1] = gps_position_.longitude;
                    current_GPS_posArray[2] = gps_position_.altitude;

                    ROS_INFO("homegpos latitude is [%f]", homeGPS_posArray[0]);
                    ROS_INFO("homegpos longitude is [%f]", homeGPS_posArray[1]);
                    ROS_INFO("homegpos attitude is [%f]", homeGPS_posArray[2]);

                    ROS_INFO("currentpos latitude is [%f]", current_GPS_posArray[0]);
                    ROS_INFO("currentgpos longitude is [%f]", current_GPS_posArray[1]);
                    ROS_INFO("currentgpos attitude is [%f]", current_GPS_posArray[2]);

                    // ros::Duration(2).sleep();


                    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, m);

                    ROS_INFO("x is [%f]", m[0]);
                    ROS_INFO("y is [%f]", m[1]);





                    /* ROS_INFO("x is [%f]",local_position_.point.x);
                     ROS_INFO("y is [%f]",local_position_.point.y);
                     ROS_INFO("z is [%f]",local_position_.point.z);*/
                    //ROS_INFO("latitude is [%f]",gps_position_.latitude);
                    //ROS_INFO("longitude is [%f]",gps_position_.longitude);
                    //ros::spin(); //here is good?
                    ROS_INFO_STREAM("first zigzag line completed!");

                    diff_latitude = std::abs(fire_gps_expected.latitude - fire_gps.latitude);
                    diff_longitude = std::abs(fire_gps_expected.longitude - fire_gps.longitude);
                    diff_altitude = std::abs(fire_gps_expected.altitude - fire_gps.altitude);

                    cout << "diff_latitude is" << diff_latitude << endl;
                    cout << "diff_longitude is" << diff_longitude << endl;
                    cout << "diff_latitude is" << diff_altitude << endl;

                    // Check if the difference exceeds the epsilon value
                    if (diff_latitude < epsilon || diff_longitude < epsilon) {
                        cout << "desirable difference" << endl;
                        break;

                        // altitude difference does not matter
                    }

                    float zzw1 = zz_w * cosd(yaw_const) / split;
                    float zzw2 = zz_w * sind(yaw_const) / split;

                    for (int i = 0; i < split; i++) {

                        moveByPosOffset(control_task, {zzw1, zzw2, 0, yaw_const}, 1, 3);

                        ros::spinOnce();
                        rate.sleep();
                        cout << "ROS spinned" << endl;
                       /* outputFile << std::setprecision(10) << gps_position_.latitude << "\t" << std::setprecision(10)
                                   << gps_position_.longitude << "\t" << std::setprecision(10) << gps_position_.altitude
                                   << "\t" << std::setprecision(10) << fire_gps.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps.longitude << "\t" << std::setprecision(10) << fire_gps.altitude << "\t"
                                   << std::setprecision(10) << fire_gps_expected.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps_expected.longitude << "\t" << std::setprecision(10)
                                   << fire_gps_expected.altitude << "\n";
*/

                    }

                    ros::spinOnce();

                    diff_latitude = std::abs(fire_gps_expected.latitude - fire_gps.latitude);
                    diff_longitude = std::abs(fire_gps_expected.longitude - fire_gps.longitude);
                    diff_altitude = std::abs(fire_gps_expected.altitude - fire_gps.altitude);

                    cout << "diff_latitude is" << diff_latitude << endl;
                    cout << "diff_longitude is" << diff_longitude << endl;
                    cout << "diff_latitude is" << diff_altitude << endl;


                    if (diff_latitude < epsilon && diff_longitude < epsilon) {
                        cout << "desirable difference" << endl;
                        break;
                    }


                    current_GPS_posArray[0] = gps_position_.latitude;
                    current_GPS_posArray[1] = gps_position_.longitude;
                    current_GPS_posArray[2] = gps_position_.altitude;

                    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, m);

                    ROS_INFO("x is [%f]", m[0]);
                    ROS_INFO("y is [%f]", m[1]);


                    ROS_INFO_STREAM("Second zigzag line completed!");

                    float zzl3 = zz_l * sind(yaw_const) / split;
                    float zzl4 = -zz_l * cosd(yaw_const) / split;

                    for (int i = 0; i < split; i++) {

                        moveByPosOffset(control_task, {zzl3, zzl4, 0.0, yaw_const}, 0.8, 3);

                        ros::spinOnce();
                        rate.sleep();
                        cout << "ROS spinned" << endl;
                      /*  outputFile << std::setprecision(10) << gps_position_.latitude << "\t" << std::setprecision(10)
                                   << gps_position_.longitude << "\t" << std::setprecision(10) << gps_position_.altitude
                                   << "\t" << std::setprecision(10) << fire_gps.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps.longitude << "\t" << std::setprecision(10) << fire_gps.altitude << "\t"
                                   << std::setprecision(10) << fire_gps_expected.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps_expected.longitude << "\t" << std::setprecision(10)
                                   << fire_gps_expected.altitude << "\n";
*/
                    }

                    ros::spinOnce();

                    diff_latitude = std::abs(fire_gps_expected.latitude - fire_gps.latitude);
                    diff_longitude = std::abs(fire_gps_expected.longitude - fire_gps.longitude);
                    diff_altitude = std::abs(fire_gps_expected.altitude - fire_gps.altitude);

                    cout << "diff_latitude is" << diff_latitude << endl;
                    cout << "diff_longitude is" << diff_longitude << endl;
                    cout << "diff_latitude is" << diff_altitude << endl;


                    if (diff_latitude < epsilon && diff_longitude < epsilon) {
                        cout << "desirable difference" << endl;
                        break;
                    }


                    ROS_INFO_STREAM("Third zigzag line completed!");


                    float zzw3 = zz_w * cosd(yaw_const) / split;
                    float zzw4 = zz_w * sind(yaw_const) / split;

                    for (int i = 0; i < split; i++) {

                        moveByPosOffset(control_task, {zzw3, zzw4, 0.0, yaw_const}, 1, 3);

                        ros::spinOnce();
                        rate.sleep();
                        cout << "ROS spinned" << endl;
                   /*     outputFile << std::setprecision(10) << gps_position_.latitude << "\t" << std::setprecision(10)
                                   << gps_position_.longitude << "\t" << std::setprecision(10) << gps_position_.altitude
                                   << "\t" << std::setprecision(10) << fire_gps.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps.longitude << "\t" << std::setprecision(10) << fire_gps.altitude << "\t"
                                   << std::setprecision(10) << fire_gps_expected.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps_expected.longitude << "\t" << std::setprecision(10)
                                   << fire_gps_expected.altitude << "\n";
*/
                    }

                    ros::spinOnce();

                    diff_latitude = std::abs(fire_gps_expected.latitude - fire_gps.latitude);
                    diff_longitude = std::abs(fire_gps_expected.longitude - fire_gps.longitude);
                    diff_altitude = std::abs(fire_gps_expected.altitude - fire_gps.altitude);

                    cout << "diff_latitude is" << diff_latitude << endl;
                    cout << "diff_longitude is" << diff_longitude << endl;
                    cout << "diff_latitude is" << diff_altitude << endl;


                    if (diff_latitude < epsilon && diff_longitude < epsilon) {
                        cout << "desirable difference" << endl;
                        break;
                    }


                    ROS_INFO_STREAM("Fourth zigzag line completed!");


                    float zzl5 = -zz_l * sind(yaw_const) / split;
                    float zzl6 = zz_l * cosd(yaw_const) / split;

                    for (int i = 0; i < split; i++) {

                        moveByPosOffset(control_task, {zzl5, zzl6, 0.0, yaw_const}, 1, 3);

                        ros::spinOnce();
                        rate.sleep();
                        cout << "ROS spinned" << endl;
                       /* outputFile << std::setprecision(10) << gps_position_.latitude << "\t" << std::setprecision(10)
                                   << gps_position_.longitude << "\t" << std::setprecision(10) << gps_position_.altitude
                                   << "\t" << std::setprecision(10) << fire_gps.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps.longitude << "\t" << std::setprecision(10) << fire_gps.altitude << "\t"
                                   << std::setprecision(10) << fire_gps_expected.latitude << "\t"
                                   << std::setprecision(10)
                                   << fire_gps_expected.longitude << "\t" << std::setprecision(10)
                                   << fire_gps_expected.altitude << "\n";
*/
                    }

                    ros::spinOnce();

                    diff_latitude = std::abs(fire_gps_expected.latitude - fire_gps.latitude);
                    diff_longitude = std::abs(fire_gps_expected.longitude - fire_gps.longitude);
                    diff_altitude = std::abs(fire_gps_expected.altitude - fire_gps.altitude);

                    cout << "diff_latitude is" << diff_latitude << endl;
                    cout << "diff_longitude is" << diff_longitude << endl;
                    cout << "diff_latitude is" << diff_altitude << endl;

                    ROS_INFO_STREAM("fifth zigzag line completed!");

                    ros::spinOnce();

                    current_GPS_posArray[0] = gps_position_.latitude;
                    current_GPS_posArray[1] = gps_position_.longitude;
                    current_GPS_posArray[2] = gps_position_.altitude;

                    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, m);

                    ROS_INFO("x is [%f]", m[0]);
                    ROS_INFO("y is [%f]", m[1]);

                    ros::spinOnce();

                    if (diff_latitude < epsilon && diff_longitude < epsilon) {
                        cout << "desirable difference" << endl;
                        break;
                    } else { break; }






                    // moveByPosOffset(control_task, {zz_w*cosd(yaw_const), zz_w*sind(yaw_const), 0.0, yaw_const}, 1, 3);
                    // moveByPosOffset(control_task, {-3*sind(yaw_const), static_cast<DJI::OSDK::float32_t>(-6.5*cosd(yaw_const)), 0.0, yaw_const}, 1, 3);

// the more generous you are in threshold, the more agile your drone would be




                }


                if (diff_latitude < epsilon && diff_longitude < epsilon) {

                    fire_GPS_posArray[0] = fire_gps.latitude;
                    fire_GPS_posArray[1] = fire_gps.longitude;
                    fire_GPS_posArray[2] = fire_gps.altitude;
                } else {
                    fire_GPS_posArray[0] = fire_gps_expected.latitude;
                    fire_GPS_posArray[1] = fire_gps_expected.longitude;
                    fire_GPS_posArray[2] = fire_gps_expected.altitude;
                }


            }


            if (in_or_out == 'a') {

                float zz_l = 8;  //zigzag_length
                float zz_w = 4;   //zigzag_width

                moveByPosOffset(control_task, {-zz_l * sind(yaw_const), zz_l * cosd(yaw_const), 0, yaw_const}, 1,
                                3);

                moveByPosOffset(control_task, {zz_w * cosd(yaw_const), zz_w * sind(yaw_const), 0, yaw_const}, 1, 3);

                moveByPosOffset(control_task, {zz_l * sind(yaw_const), -zz_l * cosd(yaw_const), 0.0, yaw_const},
                                0.8,
                                3);

                moveByPosOffset(control_task, {zz_w * cosd(yaw_const), zz_w * sind(yaw_const), 0.0, yaw_const}, 1,
                                3);


                fire_gps.latitude = 45.45936158153436;
                fire_gps.longitude = -73.91910071573902;
                fire_gps.altitude = 111.356392;


                fire_GPS_posArray[0] = fire_gps.latitude;
                fire_GPS_posArray[1] = fire_gps.longitude;
                fire_GPS_posArray[2] = fire_gps.altitude;

            }


            ros::spinOnce();

            current_GPS_posArray[0] = gps_position_.latitude;
            current_GPS_posArray[1] = gps_position_.longitude;
            current_GPS_posArray[2] = gps_position_.altitude;  // these assignments should be before using LatLong2Meter function

            ROS_INFO("fire_GPS_posArray[0] Is [%f]", fire_GPS_posArray[0]);
            ROS_INFO("fire_GPS_posArray[0] Is [%f]", fire_GPS_posArray[1]);
            ROS_INFO("fire_GPS_posArray[0] Is [%f]", fire_GPS_posArray[2]);


            FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, m);
            ROS_INFO("current position's x is [%f]", m[0]);
            ROS_INFO("current position's y is [%f]", m[1]);
            ROS_INFO("current position's z is [%f]", m[2]); //m[2] is incorrect

            float fire_gps_local_pos[3];

            FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, fire_GPS_posArray, fire_gps_local_pos);


            ROS_INFO("fire's x is [%f]", fire_gps_local_pos[0]);
            ROS_INFO("fire's y is [%f]", fire_gps_local_pos[1]);
            ROS_INFO("fire's z is [%f]", fire_gps_local_pos[2]);


            if (scenario == 'b') {

                int angle = 100;

                moveByPosOffset(control_task,
                                {fire_gps_local_pos[0] - m[0], fire_gps_local_pos[1] - m[1], 0.0, yaw_const}, 0.1,
                                3); //less threshold



                ros::spinOnce();

                current_GPS_posArray[0] = gps_position_.latitude;
                current_GPS_posArray[1] = gps_position_.longitude;
                current_GPS_posArray[2] = gps_position_.altitude;


                FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, m);
                ROS_INFO("current position's x is [%f]", m[0]);
                ROS_INFO("current position's y is [%f]", m[1]);

                ROS_INFO("current position's lat is [%f]", current_GPS_posArray[0]);
                ROS_INFO("current position's long is [%f]", current_GPS_posArray[1]);


                std::string DropWaterCommand = "rosrun arduino_actuator servo_pub.py";
                FILE *pp = popen(DropWaterCommand.c_str(), "r");
                if (pp != NULL) {
                    PRINT_INFO("drop water successfully!");
                } else {
                    PRINT_INFO("fail to drop water!");


                }

                ros::Duration(4).sleep();

/*

                std::string DropWaterCommand = "rosrun arduino_actuator servo_pub.py";
                int result2 = system(DropWaterCommand.c_str());

                if (result2 == 0) {
                    ROS_INFO("drop water successfully!");
                } else {
                    ROS_INFO("fail to drop water!");
                }

                for (int i=1; i<100;i++) {
                    controlServo(angle);
                    ros::spinOnce();
                }
*/
            }
            if (scenario == 'c') {

                // set mission start position. I set it at the south east of the fire point
                float mission_start_pos[3] = {fire_gps_local_pos[0] - 7, fire_gps_local_pos[1] + 4,
                                              9}; // it also can be current x y z

                ROS_INFO("moving to the start mission position");




                // go to mission start position
                moveByPosOffset(control_task,
                                {mission_start_pos[0] - m[0], mission_start_pos[1] - m[1], 0, yaw_const},
                                1, 3);


                // adjust initial yaw angle
                float yaw_adjustment; // yaw adjustment before approach
                float deltaX = fire_gps_local_pos[0] - mission_start_pos[0];
                float deltaY = fire_gps_local_pos[1] - mission_start_pos[1];

                ROS_INFO("deltaX is [%f]", deltaX);
                ROS_INFO("deltaY is [%f]", deltaY);


                yaw_adjustment = Rad2Deg(atan2(deltaY, deltaX)); // note that tan2 output is in radian
                // Also I added 90 as we want the yaw angle from x axis which is in Y direction

                ROS_INFO("yaw_adjustment_angle is [%f]", yaw_adjustment);
                moveByPosOffset(control_task, {0, 0, 0, yaw_adjustment}, 1, 3);

                // velocity mission

                float d = sqrt(
                        pow(fire_gps_local_pos[0] - mission_start_pos[0], 2) +
                        pow(fire_gps_local_pos[1] - mission_start_pos[1], 2));

                float abs_vel = 5; // absolute velocity that needs to be projected



                velocityAndYawRateControl({abs_vel * cosd(yaw_adjustment), abs_vel * sind(yaw_adjustment), 0}, 5000,
                                          abs_vel, d, height, release_delay);


                ROS_INFO_STREAM("Step 1 over!EmergencyBrake for 2s\n");
                emergency_brake_client.call(emergency_brake);
                ros::Duration(2).sleep();


            }
        }
    }

    if (scenario == 'e') {
        // float homeGPS_posArray[3];


        //Get fire GPS position and use callback function to put all the deteced fire spots GPS info and sequence to nodes_vec, a global vector
        ros::Subscriber fire_spots_GPS_sub = nh.subscribe("/position/fire_spots_GPS", 1, FireCallback2);


        // Some copied codes from Erfan's about M300 functions (including some new codes)
        control_task.request.task = FlightTaskControl::Request::TASK_TAKEOFF;
        ROS_INFO_STREAM("Takeoff request sending ...");
        task_control_client.call(control_task);
        if (control_task.response.result == false) {
            ROS_ERROR_STREAM("Takeoff task failed");
        }
        if (control_task.response.result == true) {
            ROS_INFO_STREAM("Takeoff task successful");

            float yaw_const;
            std::cout << " please enter initial yaw angle in degree-Z axes downward" << std::endl;
            std::cin >> yaw_const;


            float zz_l = 8;  //zigzag_length
            float zz_w = 4;   //zigzag_width

            moveByPosOffset(control_task, {-zz_l * sind(yaw_const), zz_l * cosd(yaw_const), 0, yaw_const}, 1,
                            3);

            moveByPosOffset(control_task, {zz_w * cosd(yaw_const), zz_w * sind(yaw_const), 0, yaw_const}, 1, 3);

            moveByPosOffset(control_task, {zz_l * sind(yaw_const), -zz_l * cosd(yaw_const), 0.0, yaw_const},
                            0.8,
                            3);

            moveByPosOffset(control_task, {zz_w * cosd(yaw_const), zz_w * sind(yaw_const), 0.0, yaw_const}, 1,
                            3);


            ros::spinOnce();

            float current_GPS_posArray[3];


            for (int i = 0; i < nodes_vec.size(); i++) {
                float fire_GPS_posArray[nodes_vec.size()][3];
                float fire_gps_local_pos[nodes_vec.size() - 1][3];
                if (i = 0) {
                    //Define fire_GPS_posArray[i][3] for relative distance transformation
                    fire_GPS_posArray[i][0] = nodes_vec[1].x;
                    fire_GPS_posArray[i][1] = nodes_vec[1].y;
                    fire_GPS_posArray[i][2] = nodes_vec[1].z;

                    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, fire_GPS_posArray[i], fire_gps_local_pos[i]);

                    ros::spinOnce();

                    //Increase some height
                    moveByPosOffset(control_task, {0, 0, 7, 0}, 1, 3);

                    //Define mission start position
                    float mission_start_pos[3] = {fire_gps_local_pos[i][0] - 7, fire_gps_local_pos[i][1] + 4,
                                                  0}; // it also can be current x y z

                    //Fly to the mission start position with fixed yaw angle
                    moveByPosOffset(control_task, {mission_start_pos[0], mission_start_pos[1], 0, yaw_const}, 1,
                                    3);

                    ros::spinOnce();

                    current_GPS_posArray[0] = gps_position_.latitude;
                    current_GPS_posArray[1] = gps_position_.longitude;
                    current_GPS_posArray[2] = gps_position_.altitude;

                    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, mission_start_pos);

                    float yaw_adjustment; // yaw adjustment before approach
                    float deltaX = fire_gps_local_pos[i][0] - mission_start_pos[0];
                    float deltaY = fire_gps_local_pos[i][1] - mission_start_pos[1];

                    ROS_INFO("deltaX is [%f]", deltaX);
                    ROS_INFO("deltaY is [%f]", deltaY);

                    yaw_adjustment = Rad2Deg(atan2(deltaY, deltaX));
                    // note that tan2 output is in radian
                    // Also I added 90 as we want the yaw angle from x axis which is in Y direction
                    ROS_INFO("yaw_adjustment_angle is [%f]", yaw_adjustment);

                    moveByPosOffset(control_task, {0, 0, 0, yaw_adjustment}, 1,
                                    3);  // note that x y z goes into this funciton

                    // velocity mission

                    float d = sqrt(
                            pow(fire_gps_local_pos[i][0] - mission_start_pos[0], 2) +
                            pow(fire_gps_local_pos[i][1] - mission_start_pos[1], 2));

                    float abs_vel = 5; // absolute velocity that needs to be projected

                    float height = 10;
                    velocityAndYawRateControl(
                            {abs_vel * cosd(yaw_adjustment), abs_vel * sind(yaw_adjustment), 0}, 5000,
                            abs_vel, d, height, 0);
                    ROS_INFO_STREAM("Step 1 over!EmergencyBrake for 2s\n");
                    emergency_brake_client.call(emergency_brake);
                    ros::Duration(2).sleep();
                } else {
                    //Define fire_GPS_posArray[i][3] for relative distance transformation
                    fire_GPS_posArray[i][0] = nodes_vec[i + 1].x;
                    fire_GPS_posArray[i][1] = nodes_vec[i + 1].y;
                    fire_GPS_posArray[i][2] = nodes_vec[i + 1].z;

                    FFDS::TOOLS::LatLong2Meter(fire_GPS_posArray[i - 1], fire_GPS_posArray[i],
                                               fire_gps_local_pos[i]);

                    ros::spinOnce();

                    current_GPS_posArray[0] = gps_position_.latitude;
                    current_GPS_posArray[1] = gps_position_.longitude;
                    current_GPS_posArray[2] = gps_position_.altitude;

                    float recent_local_pos[3];

                    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, recent_local_pos);

                    float yaw_adjustment; // yaw adjustment before approach
                    float deltaX = fire_gps_local_pos[i][0] - recent_local_pos[0];
                    float deltaY = fire_gps_local_pos[i][1] - recent_local_pos[1];

                    ROS_INFO("deltaX is [%f]", deltaX);
                    ROS_INFO("deltaY is [%f]", deltaY);

                    yaw_adjustment = Rad2Deg(atan2(deltaY, deltaX));
                    // note that tan2 output is in radian
                    // Also I added 90 as we want the yaw angle from x axis which is in Y direction
                    ROS_INFO("yaw_adjustment_angle is [%f]", yaw_adjustment);


                    moveByPosOffset(control_task, {0, 0, 0, yaw_adjustment}, 1,
                                    3);  // note that x y z goes into this funciton
                    float d = sqrt(
                            pow(fire_gps_local_pos[i][0] - recent_local_pos[0], 2) +
                            pow(fire_gps_local_pos[i][1] - recent_local_pos[1], 2));

                    float abs_vel = 5; // absolute velocity that needs to be projected

                    float height = 10;
                    velocityAndYawRateControl(
                            {abs_vel * cosd(yaw_adjustment), abs_vel * sind(yaw_adjustment), 0}, 5000,
                            abs_vel, d, height, 0);
                    ROS_INFO_STREAM("Step 1 over!EmergencyBrake for 2s\n");
                    emergency_brake_client.call(emergency_brake);
                    ros::Duration(2).sleep();
                }
            }

        }
    }

    if (scenario == 'f') {
        // float homeGPS_posArray[3];

        cout << "we are inside scenario's f code" << endl;  // for debug
        //Get fire GPS position and use callback function to put all the detected fire spots GPS info and sequence to nodes_vec, a global vector
        ros::Subscriber line_of_fire_sub = nh.subscribe("/position/fire_spots_GPS", 1, LineOfFireCallback);

        float yaw_const;
        std::cout << " please enter initial yaw angle in degree-Z axes downward" << std::endl;
        std::cin >> yaw_const;

        float threshold;
        cout << "please enter threshold for RANSAC";
        cin >> threshold;
        // Some copied codes from Erfan's about M300 functions (including some new codes)
        control_task.request.task = FlightTaskControl::Request::TASK_TAKEOFF;
        ROS_INFO_STREAM("Takeoff request sending ...");
        task_control_client.call(control_task);
        if (control_task.response.result == false) {
            ROS_ERROR_STREAM("Takeoff task failed");
        }
        if (control_task.response.result == true) {
            ROS_INFO_STREAM("Takeoff task successful");


                moveByPosOffset(control_task, {0, 0, height - 1, yaw_const}, 1, 3);


                float theta_dot = 0.1;
                float radius = 7;
                float theta_step_degrees = 10;
                float theta_step_radians = theta_step_degrees * M_PI / 180.0;
                float total_time = (2 * M_PI) / 0.1;
                float number_of_divisions = 360 / theta_step_degrees;
                float time_step = total_time / number_of_divisions;
                // float time_step = theta_step_radians / theta_dot;
                float Vx;
                float Vy;


                for (float theta = 0; theta < 360; theta = theta + theta_step_degrees) {
                    // time_step = (M_PI/theta_dot)/theta_step;
                    Vx = radius * theta_dot * cosd(theta);
                    Vy = radius * theta_dot * sind(theta);
                    cout << "Vx is:" << Vx << " Vy is:" << Vy << "time step in ms is:" << time_step * 1000 << endl;
                    CircularPlanner({Vx, Vy, 0, theta_dot}, time_step * 1000);

                }

                float zz_l = 12;  //zigzag_length
                float zz_w = 6;   //zigzag_width
                int n_zz = 2;
                ZigZagParams zigzag_params;
                zigzag_params.length = 12;
                zigzag_params.width = 6;
                zigzag_params.number = 1;
                zigzag_params.split = 1;
                zigzag_params.orientation = yaw_const; // next time read it from a yaml file
                ZigZagPlanner(control_task, zigzag_params);


                ros::spinOnce();

                // Clear the vector if needed
                nodes_vec.clear();
            int detect_index;//detection_starter_indicator
            if (in_or_out == 'b') {
                bool SLAM_flag = 0;
                while (SLAM_flag == 0) {
                    cout << "please rosrun detection and SLAM nodes. Then press 1" << endl;
                    cin >> detect_index;
                    if (detect_index == 1) { SLAM_flag = 1; }
                    else { cout << "Please press 1 if SLAM is initiated"; }
                }
            }

                /* for parking lot:
                // Create and initialize node objects
                node n1;
                n1.x = 45.459209212306355;
                n1.y = -73.91904076800327;
                n1.z = 0;
                n1.id = 1;

                node n2;
                n2.x = 45.45923743249868;
                n2.y = -73.91904210910772;
                n2.z = 0;
                n2.id = 2;

                node n3;
                n3.x = 45.459243546871804;
                n3.y = -73.91907295451003;
                n3.z = 0;
                n3.id = 3;

                node n4;
                n4.x = 45.45927694074417;
                n4.y = -73.91904210910772;
                n4.z = 0;
                n4.id = 4;
                */

                // for P7 area:
                // Create and initialize node objects
                /*
                node n1;
                n1.x = 45.45836575506897;
                n1.y = -73.93233197405084;
                n1.z = 0;
                n1.id = 1;

                node n2;
                n2.x = 45.45836575503348;
                n2.y = -73.93233197404479;
                n2.z = 0;
                n2.id = 1;


                node n3;
                n3.x = 45.45836575508932;
                n3.y = -73.93233197401255;
                n3.z = 0;
                n3.id = 1;

                node n4;
                n4.x = 45.45836575507632;
                n4.y = -73.93233197400416;
                n4.z = 0;
                n4.id = 1;


                node n5;
                n2.x = 45.458375161942016;
                n2.y = -73.93236483111184;
                n2.z = 0;
                n2.id = 2;

                node n6;
                n2.x = 45.458375161943359;
                n2.y = -73.93236483114390;
                n2.z = 0;
                n2.id = 2;

                node n7;
                n2.x = 45.458375161945590;
                n2.y = -73.93236483119482;
                n2.z = 0;
                n2.id = 2;

                node n8;
                n2.x = 45.458375161948811;
                n2.y = -73.93236483110022;
                n2.z = 0;
                n2.id = 2;

                node n9;
                n3.x = 45.45840855632869;
                n3.y = -73.93236214890278;
                n3.z = 0;
                n3.id = 3;

                node n10;
                n3.x = 45.45840855633733;
                n3.y = -73.93236214896590;
                n3.z = 0;
                n3.id = 3;

                node n11;
                n3.x = 45.45840855632869;
                n3.y = -73.93236214890278;
                n3.z = 0;
                n3.id = 3;

                node n12;
                n4.x = 45.458413259761834;
                n4.y = -73.93241042866589;
                n4.z = 0;
                n4.id = 4;
*/
/*
                node n1;
                n1.x = 45.45836575506897;
                n1.y = -73.93233197405084;
                n1.z = 0;
                n1.id = 1;


                node n2;
                n2.x = 45.458375161942016;
                n2.y = -73.93236483111184;
                n2.z = 0;
                n2.id = 2;


                node n3;
                n3.x = 45.45840855632869;
                n3.y = -73.93236214890278;
                n3.z = 0;
                n3.id = 3;


                node n4;
                n4.x = 45.458413259761834;
                n4.y = -73.93241042866589;
                n4.z = 0;
                n4.id = 4;

                // Push nodes into the vector
                nodes_vec.push_back(n1);
                nodes_vec.push_back(n2);
                nodes_vec.push_back(n3);
                nodes_vec.push_back(n4);
                */

            if (in_or_out == 'a') {

                // Load YAML file
                YAML::Node config = YAML::LoadFile("nodes.yaml");

                // Check if "nodes" key exists
                if (config["nodes"]) {
                    for (const auto &n: config["nodes"]) {
                        node temp;
                        temp.id = n["id"].as<int>();
                        temp.x = n["x"].as<float>();
                        temp.y = n["y"].as<float>();
                        temp.z = n["z"].as<float>();
                        nodes_vec.push_back(temp);
                    }
                }

                // Print loaded nodes
                for (const auto &n: nodes_vec) {
                    std::cout << "Node ID: " << n.id << ", X: " << n.x << ", Y: " << n.y << ", Z: " << n.z << std::endl;
                }
            }

                /*
                nodes_vec.push_back(n5);
                nodes_vec.push_back(n6);
                nodes_vec.push_back(n7);
                nodes_vec.push_back(n8);
                nodes_vec.push_back(n9);
                nodes_vec.push_back(n10);
                nodes_vec.push_back(n11);
                nodes_vec.push_back(n12);
*/


                float current_GPS_posArray[3];

                float fire_gps_local_pos[nodes_vec.size()][3]; // coordinates of fire spots (x,y,z)

                float fire_GPS_posArray[nodes_vec.size()][3];  // GPS of fire spots

                cout << "number of fire spots are: " << nodes_vec.size() << std::endl;

                cout << "Home GPS position: latitude  " << homeGPS_posArray[0] << "longitude  " << homeGPS_posArray[1];

                for (int i = 0; i < nodes_vec.size(); ++i) {

                    fire_GPS_posArray[i][0] = nodes_vec[i].x;
                    fire_GPS_posArray[i][1] = nodes_vec[i].y;
                    fire_GPS_posArray[i][2] = nodes_vec[i].z;

                    FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, fire_GPS_posArray[i], fire_gps_local_pos[i]);
                    std::cout << "Node ID: " << nodes_vec[i].id << ", latitude: " << nodes_vec[i].x << ", longitude: "
                              << nodes_vec[i].y << ", z: " << nodes_vec[i].z << std::endl;
                    std::cout << "fire's x position " << fire_gps_local_pos[i][0] << ", fire's y position "
                              << fire_gps_local_pos[i][1] << std::endl;


                }

                // Extract x and y coordinates into vectors
                std::vector<float> x, y;
                for (size_t i = 0; i < nodes_vec.size(); ++i) {
                    x.push_back(fire_gps_local_pos[i][0]);
                    y.push_back(fire_gps_local_pos[i][1]);
                }


                // Print x and y before plotting
                std::cout << "X coordinates: ";
                for (auto val: x) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                std::cout << "Y coordinates: ";
                for (auto val: y) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;

                // Plot the points with x and y switched
                plt::plot(y, x, "bo"); // Switched x and y

                // Set labels and title with switched axes
                plt::xlabel("Y"); // Y-axis now represents X-coordinate
                plt::ylabel("X"); // X-axis now represents Y-coordinate
                plt::title("Scatter Plot of Points");

                // Show plot
                //     plt::show();


                cout << "now we have gps position of fire spots, we go ahead and find optimum line for approach";

            doRANSAC(nodes_vec, fire_gps_local_pos);





                ros::spinOnce();


/*
                current_GPS_posArray[0] = gps_position_.latitude;
                current_GPS_posArray[1] = gps_position_.longitude;
                current_GPS_posArray[2] = gps_position_.altitude;

                float recent_local_pos[3];
*/
                recent_drone_coord = GPS2Coordinates(homeGPos, gps_position_);

                // FFDS::TOOLS::LatLong2Meter(homeGPS_posArray, current_GPS_posArray, recent_local_pos);


                float yaw_adjustment; // yaw adjustment before approach

                cout << "recent x :" << starting_point.x << "recent y :" << starting_point.y
                     << endl;
                // yaw_adjustment = Rad2Deg(atan2(deltaY, deltaX));
                // note that tan2 output is in radian
                // Also I added 90 as we want the yaw angle from x axis which is in Y direction


                moveByPosOffset(control_task,
                                {starting_point.x - recent_drone_coord.x, starting_point.y - recent_drone_coord.y, 0, 0},
                                1, 3);  // note that x y z goes into this function

                yaw_adjustment = Rad2Deg(atan(best_line.slope));
                cout << "yaw_adjustment is" << yaw_adjustment << endl;
                moveByPosOffset(control_task, {0, 0, 0, yaw_adjustment}, 1,
                                3);  // note that x y z goes into this funciton
                // velocity mission

                cout << "rotated and ready for approaching fire!" << endl;

                float abs_vel = 5; // absolute velocity that needs to be projected


                velocityAndYawRateControl({abs_vel * cosd(yaw_adjustment), abs_vel * sind(yaw_adjustment), 0}, 4000,
                                          abs_vel, 5, height, release_delay);


        }
    }


    PRINT_INFO("going home now");
    control_task.request.task =
            dji_osdk_ros::FlightTaskControl::Request::TASK_GOHOME;
    task_control_client.call(control_task);
    if (control_task.response.result == true) {
        PRINT_INFO("go home successful");
    } else {
        PRINT_WARN("go home failed.");
    }

    control_task.request.task =
            dji_osdk_ros::FlightTaskControl::Request::TASK_LAND;
    PRINT_INFO(
            "Landing request sending ... need your confirmation on the remoter!");
    task_control_client.call(control_task);
    if (control_task.response.result == true) {
        PRINT_INFO("land task successful");
    } else {
        PRINT_ERROR("land task failed.");
    }


    ROS_INFO_STREAM("Finished. Press CTRL-C to terminate the node");
   // outputFile.close();
    ros::spin();
    return 0;
}


bool moveByPosOffset(FlightTaskControl &task, const JoystickCommand &offsetDesired,
                     float posThresholdInM,
                     float yawThresholdInDeg) {
    task.request.task = FlightTaskControl::Request::TASK_POSITION_AND_YAW_CONTROL;
    task.request.joystickCommand.x = offsetDesired.x;
    task.request.joystickCommand.y = offsetDesired.y;
    task.request.joystickCommand.z = offsetDesired.z;
    task.request.joystickCommand.yaw = offsetDesired.yaw;
    task.request.posThresholdInM = posThresholdInM;
    task.request.yawThresholdInDeg = yawThresholdInDeg;

    task_control_client.call(task);
    return task.response.result;
}


void
velocityAndYawRateControl(const JoystickCommand &offsetDesired, uint32_t timeMs, float abs_vel, float d, float height,
                          float delay) {


    double originTime = 0;
    double currentTime = 0;
    // uint64_t elapsedTimeInMs = 0;
    float elapsedTimeInMs = 0;

    SetJoystickMode joystickMode;
    JoystickAction joystickAction;

    joystickMode.request.horizontal_mode = joystickMode.request.HORIZONTAL_VELOCITY;
    joystickMode.request.vertical_mode = joystickMode.request.VERTICAL_VELOCITY;
    joystickMode.request.yaw_mode = joystickMode.request.YAW_RATE;
    joystickMode.request.horizontal_coordinate = joystickMode.request.HORIZONTAL_GROUND;
    joystickMode.request.stable_mode = joystickMode.request.STABLE_ENABLE;
    set_joystick_mode_client.call(joystickMode);

    joystickAction.request.joystickCommand.x = offsetDesired.x;
    joystickAction.request.joystickCommand.y = offsetDesired.y;
    joystickAction.request.joystickCommand.z = offsetDesired.z;
    // joystickAction.request.joystickCommand.yaw = offsetDesired.yaw;  // This is for yaw rate, which we dont want
    int angle = 100;  // Set the desired angle here
    originTime = ros::Time::now().toSec();
    currentTime = originTime;
    elapsedTimeInMs = (currentTime - originTime) * 1000;
    bool flag = 0;
    while (elapsedTimeInMs <= timeMs) {
        currentTime = ros::Time::now().toSec();
        elapsedTimeInMs = (currentTime - originTime) * 1000;
        // ROS_INFO("timeinMs [%f]",elapsedTimeInMs);

        float g = 9.81;

        float release_time = (((d / abs_vel) - sqrt((2 * height) / g)) * 1000) + delay; // release time in Ms

        if (elapsedTimeInMs > release_time) {
            // controlServo(angle);


            ros::spinOnce();
            if (flag == 0) {

                std::string DropWaterCommand = "rosrun arduino_actuator servo_pub.py";
                FILE *pp = popen(DropWaterCommand.c_str(), "r");
                if (pp != NULL) {
                    PRINT_INFO("drop water successfully!");
                } else {
                    PRINT_INFO("fail to drop water!");


                }

/*
                std::string DropWaterCommand = "rosrun arduino_actuator servo_pub.py";
                int result3 = system(DropWaterCommand.c_str());

                if (result3 == 0) {
                    ROS_INFO("drop water successfully!");
                } else {
                    ROS_INFO("fail to drop water!");
                }
                */

                ROS_INFO("released valve at [%f]", elapsedTimeInMs);
            }
            joystick_action_client.call(joystickAction);
            flag = 1;
        } else {
            joystick_action_client.call(joystickAction);

        }


    }
}


void CircularPlanner(const JoystickCommand &offsetDesired, uint32_t timeMs) {
    double originTime = 0;
    double currentTime = 0;
    uint64_t elapsedTimeInMs = 0;

    SetJoystickMode joystickMode;
    JoystickAction joystickAction;

    joystickMode.request.horizontal_mode = joystickMode.request.HORIZONTAL_VELOCITY;
    joystickMode.request.vertical_mode = joystickMode.request.VERTICAL_VELOCITY;
    joystickMode.request.yaw_mode = joystickMode.request.YAW_RATE;
    joystickMode.request.horizontal_coordinate = joystickMode.request.HORIZONTAL_GROUND;
    joystickMode.request.stable_mode = joystickMode.request.STABLE_ENABLE;
    set_joystick_mode_client.call(joystickMode);

    joystickAction.request.joystickCommand.x = offsetDesired.x;
    joystickAction.request.joystickCommand.y = offsetDesired.y;
    joystickAction.request.joystickCommand.z = offsetDesired.z;
    joystickAction.request.joystickCommand.yaw = offsetDesired.yaw;

    originTime = ros::Time::now().toSec();
    currentTime = originTime;
    elapsedTimeInMs = (currentTime - originTime) * 1000;

    while (elapsedTimeInMs <= timeMs) {
        currentTime = ros::Time::now().toSec();
        elapsedTimeInMs = (currentTime - originTime) * 1000;
        joystick_action_client.call(joystickAction);
    }
}

static bool isEqual(const double a, const double b) {
    return (fabs(a - b) <= 1e-15);
}

sensor_msgs::NavSatFix getAverageGPS(
        const int average_times) {
    sensor_msgs::NavSatFix homeGPos;
    while (isEqual(0.0, gps_position_.latitude) ||
           isEqual(0.0, gps_position_.longitude) ||
           isEqual(0.0, gps_position_.altitude)) {
        ros::spinOnce();

    }
    // PRINT_WARN("zero in gps_position, waiting for normal gps position!");

    for (int i = 0; (i < average_times) && ros::ok(); i++) {
        ros::spinOnce();

        homeGPos.latitude += gps_position_.latitude;
        homeGPos.longitude += gps_position_.longitude;
        homeGPos.altitude += gps_position_.altitude;

        ros::Rate(10).sleep();
    }
    homeGPos.latitude = homeGPos.latitude / average_times;
    homeGPos.longitude = homeGPos.longitude / average_times;
    homeGPos.altitude = homeGPos.altitude / average_times;

    return homeGPos;
}

void ZigZagPlanner(FlightTaskControl &task, ZigZagParams zz_params) {


    ros::spinOnce();

    float lengths_steps[5][2] = {
            {-zz_params.length * sind(zz_params.orientation) / zz_params.split,
                                                                                zz_params.length *
                                                                                cosd(zz_params.orientation) /
                                                                                zz_params.split},
            {zz_params.width * cosd(zz_params.orientation) / zz_params.split,   zz_params.width *
                                                                                sind(zz_params.orientation) /
                                                                                zz_params.split},
            {zz_params.length * sind(zz_params.orientation) / zz_params.split,  -zz_params.length *
                                                                                cosd(zz_params.orientation) /
                                                                                zz_params.split},
            {zz_params.width * cosd(zz_params.orientation) / zz_params.split,   zz_params.width *
                                                                                sind(zz_params.orientation) /
                                                                                zz_params.split},
            {-zz_params.length * sind(zz_params.orientation) / zz_params.split, zz_params.length *
                                                                                cosd(zz_params.orientation) /
                                                                                zz_params.split}};
    double frequency = 30; // 30 Hz
    ros::Rate rate(frequency);



    for (int n = 0; n < zz_params.number; n++) { // loop for the number of zigzags
        for (int i = 0; i < zz_params.split; i++) {
            moveByPosOffset(task, {lengths_steps[0][0], lengths_steps[0][1], 0, zz_params.orientation}, 1, 3);

            ros::spinOnce();
            rate.sleep();
            cout << "ROS spinned" << endl;
        }

        /* ROS_INFO("x is [%f]",local_position_.point.x);
         ROS_INFO("y is [%f]",local_position_.point.y);
         ROS_INFO("z is [%f]",local_position_.point.z);*/
        //ROS_INFO("latitude is [%f]",gps_position_.latitude);
        //ROS_INFO("longitude is [%f]",gps_position_.longitude);
        //ros::spin(); //here is good?
        ROS_INFO_STREAM("first zigzag line completed!");


        for (int i = 0; i < zz_params.split; i++) {
            moveByPosOffset(task, {lengths_steps[1][0], lengths_steps[1][1], 0, zz_params.orientation}, 1, 3);

            ros::spinOnce();
            rate.sleep();
            cout << "ROS spinned" << endl;


        }

        ros::spinOnce();


        ROS_INFO_STREAM("Second zigzag line completed!");


        for (int i = 0; i < zz_params.split; i++) {
            moveByPosOffset(task, {lengths_steps[2][0], lengths_steps[2][1], 0, zz_params.orientation}, 1, 3);

            ros::spinOnce();
            rate.sleep();
            cout << "ROS spinned" << endl;
        }

        ros::spinOnce();

        ROS_INFO_STREAM("Third zigzag line completed!");


        for (int i = 0; i < zz_params.split; i++) {
            moveByPosOffset(task, {lengths_steps[3][0], lengths_steps[3][1], 0, zz_params.orientation}, 1, 3);

            ros::spinOnce();
            rate.sleep();
            cout << "ROS spinned" << endl;

        }

        ros::spinOnce();


        ROS_INFO_STREAM("Fourth zigzag line completed!");

        for (int i = 0; i < zz_params.split; i++) {
            moveByPosOffset(task, {lengths_steps[4][0], lengths_steps[4][1], 0, zz_params.orientation}, 1, 3);

            ros::spinOnce();
            rate.sleep();
            cout << "ROS spinned" << endl;

        }

        ros::spinOnce();
    }

    // moveByPosOffset(control_task, {zz_w*cosd(yaw_const), zz_w*sind(yaw_const), 0.0, yaw_const}, 1, 3);
    // moveByPosOffset(control_task, {-3*sind(yaw_const), static_cast<DJI::OSDK::float32_t>(-6.5*cosd(yaw_const)), 0.0, yaw_const}, 1, 3);

// the more generous you are in threshold, the more agile your drone would be

}

void doRANSAC(std::vector <node> nodes_vector, float fire_coordinates[]){
    int size = nodes_vector.size(); // # number of rows in fire_gps_local

    // Process the array and fit the line
    // Line best_line = processArrayAndFitLine(fire_gps_local_pos, size);
    Line best_line = processArrayAndFitLine(fire_coordinates, size, threshold);

    // Print the parameters of the best-fitting line
    std::cout << "Best-fitting line: y = " << best_line.slope << "x + " << best_line.intercept << std::endl;
    std::cout << "Number of inliers: " << best_line.num_inliers << std::endl;

    // Calculate the point on the fitted line closest to the first sample
    Point first_sample = {fire_coordinates[0][0], fire_coordinates[0][1]};
    cout << "first sample x is:" << first_sample.x << "and first sample y is:" << first_sample.y << endl;
    Point closest_point = closestPointOnLine(best_line, first_sample);

    Point intersecPoint = intersectionPoint(best_line, first_sample);
    cout << "intersection_point_x is:" << intersecPoint.x << "and its y is:" << intersecPoint.y << endl;;
    // Print the coordinates of the closest point
    std::cout << "Closest point on the line to the first sample: (" << closest_point.x << ", "
              << closest_point.y << ")" << std::endl;

    // Plot the line
    std::vector<float> line_x, line_y;
    for (float x_val = -10; x_val <= 30; x_val += 0.1) { // Adjust the range as needed
        float y_val = best_line.slope * x_val + best_line.intercept;
        line_x.push_back(y_val);  // Note: Switched x and y
        line_y.push_back(x_val);  // Note: Switched x and y
    }
    plt::plot(line_x, line_y, "r"); // Plot the line in blue

    Point starting_point = traverseOnLine(best_line, intersecPoint, 5);
    std::cout << "starting point (x,y): (" << starting_point.x << ", " << starting_point.y << ")"
              << std::endl;

    plt::plot({starting_point.y}, {starting_point.x}, "go"); // DONT FORGET THE BRACKET
    // Show plot
    plt::show();
}