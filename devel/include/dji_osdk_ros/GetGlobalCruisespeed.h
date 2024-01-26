// Generated by gencpp from file dji_osdk_ros/GetGlobalCruisespeed.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_GETGLOBALCRUISESPEED_H
#define DJI_OSDK_ROS_MESSAGE_GETGLOBALCRUISESPEED_H

#include <ros/service_traits.h>


#include <dji_osdk_ros/GetGlobalCruisespeedRequest.h>
#include <dji_osdk_ros/GetGlobalCruisespeedResponse.h>


namespace dji_osdk_ros
{

struct GetGlobalCruisespeed
{

typedef GetGlobalCruisespeedRequest Request;
typedef GetGlobalCruisespeedResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetGlobalCruisespeed
} // namespace dji_osdk_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeed > {
  static const char* value()
  {
    return "df3d2cfe28195de85b4c9680fe9f9068";
  }

  static const char* value(const ::dji_osdk_ros::GetGlobalCruisespeed&) { return value(); }
};

template<>
struct DataType< ::dji_osdk_ros::GetGlobalCruisespeed > {
  static const char* value()
  {
    return "dji_osdk_ros/GetGlobalCruisespeed";
  }

  static const char* value(const ::dji_osdk_ros::GetGlobalCruisespeed&) { return value(); }
};


// service_traits::MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeedRequest> should match
// service_traits::MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeed >
template<>
struct MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeedRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeed >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetGlobalCruisespeedRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::GetGlobalCruisespeedRequest> should match
// service_traits::DataType< ::dji_osdk_ros::GetGlobalCruisespeed >
template<>
struct DataType< ::dji_osdk_ros::GetGlobalCruisespeedRequest>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::GetGlobalCruisespeed >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetGlobalCruisespeedRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeedResponse> should match
// service_traits::MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeed >
template<>
struct MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeedResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::GetGlobalCruisespeed >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetGlobalCruisespeedResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::GetGlobalCruisespeedResponse> should match
// service_traits::DataType< ::dji_osdk_ros::GetGlobalCruisespeed >
template<>
struct DataType< ::dji_osdk_ros::GetGlobalCruisespeedResponse>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::GetGlobalCruisespeed >::value();
  }
  static const char* value(const ::dji_osdk_ros::GetGlobalCruisespeedResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_GETGLOBALCRUISESPEED_H
