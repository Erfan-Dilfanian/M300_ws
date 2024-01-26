// Generated by gencpp from file dji_osdk_ros/SetHardSyncRequest.msg
// DO NOT EDIT!


#ifndef DJI_OSDK_ROS_MESSAGE_SETHARDSYNCREQUEST_H
#define DJI_OSDK_ROS_MESSAGE_SETHARDSYNCREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dji_osdk_ros
{
template <class ContainerAllocator>
struct SetHardSyncRequest_
{
  typedef SetHardSyncRequest_<ContainerAllocator> Type;

  SetHardSyncRequest_()
    : frequency(0)
    , tag(0)  {
    }
  SetHardSyncRequest_(const ContainerAllocator& _alloc)
    : frequency(0)
    , tag(0)  {
  (void)_alloc;
    }



   typedef uint32_t _frequency_type;
  _frequency_type frequency;

   typedef uint16_t _tag_type;
  _tag_type tag;





  typedef boost::shared_ptr< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetHardSyncRequest_

typedef ::dji_osdk_ros::SetHardSyncRequest_<std::allocator<void> > SetHardSyncRequest;

typedef boost::shared_ptr< ::dji_osdk_ros::SetHardSyncRequest > SetHardSyncRequestPtr;
typedef boost::shared_ptr< ::dji_osdk_ros::SetHardSyncRequest const> SetHardSyncRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator2> & rhs)
{
  return lhs.frequency == rhs.frequency &&
    lhs.tag == rhs.tag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator1> & lhs, const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dji_osdk_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "055883b322dfe2d79dcba9762ea2d6d4";
  }

  static const char* value(const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x055883b322dfe2d7ULL;
  static const uint64_t static_value2 = 0x9dcba9762ea2d6d4ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_osdk_ros/SetHardSyncRequest";
  }

  static const char* value(const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 frequency  # frequency in Hz\n"
"uint16 tag        # the tag is to distinguish between different call\n"
;
  }

  static const char* value(const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.frequency);
      stream.next(m.tag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetHardSyncRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_osdk_ros::SetHardSyncRequest_<ContainerAllocator>& v)
  {
    s << indent << "frequency: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.frequency);
    s << indent << "tag: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.tag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_OSDK_ROS_MESSAGE_SETHARDSYNCREQUEST_H
