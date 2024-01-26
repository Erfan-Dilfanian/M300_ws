// Generated by gencpp from file dji_osdk_ros/GetWholeBatteryInfo.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_GETWHOLEBATTERYINFO_H
#define DJI_OSDK_ROS_MESSAGE_GETWHOLEBATTERYINFO_H

#include <ros/service_traits.h>


#include <dji_osdk_ros/GetWholeBatteryInfoRequest.h>
#include <dji_osdk_ros/GetWholeBatteryInfoResponse.h>


namespace dji_osdk_ros
{

struct GetWholeBatteryInfo
{

typedef GetWholeBatteryInfoRequest Request;
typedef GetWholeBatteryInfoResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetWholeBatteryInfo
} // namespace dji_osdk_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfo > {
  static const char* value()
  {
    return "a954f2c109885a4dd2f5564d3eb1433a";
  }

  static const char* value(const ::dji_osdk_ros::GetWholeBatteryInfo&) { return value(); }
};

template<>
struct DataType< ::dji_osdk_ros::GetWholeBatteryInfo > {
  static const char* value()
  {
    return "dji_osdk_ros/GetWholeBatteryInfo";
  }

  static const char* value(const ::dji_osdk_ros::GetWholeBatteryInfo&) { return value(); }
};


// service_traits::MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfoRequest> should match
// service_traits::MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfo >
template<>
struct MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfoRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfo >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetWholeBatteryInfoRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::GetWholeBatteryInfoRequest> should match
// service_traits::DataType< ::dji_osdk_ros::GetWholeBatteryInfo >
template<>
struct DataType< ::dji_osdk_ros::GetWholeBatteryInfoRequest>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::GetWholeBatteryInfo >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetWholeBatteryInfoRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfoResponse> should match
// service_traits::MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfo >
template<>
struct MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfoResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::GetWholeBatteryInfo >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetWholeBatteryInfoResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::GetWholeBatteryInfoResponse> should match
// service_traits::DataType< ::dji_osdk_ros::GetWholeBatteryInfo >
template<>
struct DataType< ::dji_osdk_ros::GetWholeBatteryInfoResponse>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::GetWholeBatteryInfo >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetWholeBatteryInfoResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_GETWHOLEBATTERYINFO_H
