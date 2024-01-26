// Generated by gencpp from file dji_osdk_ros/Activation.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_ACTIVATION_H
#define DJI_OSDK_ROS_MESSAGE_ACTIVATION_H

#include <ros/service_traits.h>


#include <dji_osdk_ros/ActivationRequest.h>
#include <dji_osdk_ros/ActivationResponse.h>


namespace dji_osdk_ros
{

struct Activation
{

typedef ActivationRequest Request;
typedef ActivationResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Activation
} // namespace dji_osdk_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dji_osdk_ros::Activation > {
  static const char* value()
  {
    return "f03b0bc279b265c40946c1011df83013";
  }

  static const char* value(const ::dji_osdk_ros::Activation&) { return value(); }
};

template<>
struct DataType< ::dji_osdk_ros::Activation > {
  static const char* value()
  {
    return "dji_osdk_ros/Activation";
  }

  static const char* value(const ::dji_osdk_ros::Activation&) { return value(); }
};


// service_traits::MD5Sum< ::dji_osdk_ros::ActivationRequest> should match
// service_traits::MD5Sum< ::dji_osdk_ros::Activation >
template<>
struct MD5Sum< ::dji_osdk_ros::ActivationRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::Activation >::value();
  }
  static const char* value(const ::dji_osdk_ros::ActivationRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::ActivationRequest> should match
// service_traits::DataType< ::dji_osdk_ros::Activation >
template<>
struct DataType< ::dji_osdk_ros::ActivationRequest>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::Activation >::value();
  }
  static const char* value(const ::dji_osdk_ros::ActivationRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dji_osdk_ros::ActivationResponse> should match
// service_traits::MD5Sum< ::dji_osdk_ros::Activation >
template<>
struct MD5Sum< ::dji_osdk_ros::ActivationResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dji_osdk_ros::Activation >::value();
  }
  static const char* value(const ::dji_osdk_ros::ActivationResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dji_osdk_ros::ActivationResponse> should match
// service_traits::DataType< ::dji_osdk_ros::Activation >
template<>
struct DataType< ::dji_osdk_ros::ActivationResponse>
{
  static const char* value()
  {
    return DataType< ::dji_osdk_ros::Activation >::value();
  }
  static const char* value(const ::dji_osdk_ros::ActivationResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_ACTIVATION_H
