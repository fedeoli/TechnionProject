// Generated by gencpp from file robot_localization_custom/ToLLResponse.msg
// DO NOT EDIT!


#ifndef ROBOT_LOCALIZATION_CUSTOM_MESSAGE_TOLLRESPONSE_H
#define ROBOT_LOCALIZATION_CUSTOM_MESSAGE_TOLLRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geographic_msgs/GeoPoint.h>

namespace robot_localization_custom
{
template <class ContainerAllocator>
struct ToLLResponse_
{
  typedef ToLLResponse_<ContainerAllocator> Type;

  ToLLResponse_()
    : ll_point()  {
    }
  ToLLResponse_(const ContainerAllocator& _alloc)
    : ll_point(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geographic_msgs::GeoPoint_<ContainerAllocator>  _ll_point_type;
  _ll_point_type ll_point;





  typedef boost::shared_ptr< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ToLLResponse_

typedef ::robot_localization_custom::ToLLResponse_<std::allocator<void> > ToLLResponse;

typedef boost::shared_ptr< ::robot_localization_custom::ToLLResponse > ToLLResponsePtr;
typedef boost::shared_ptr< ::robot_localization_custom::ToLLResponse const> ToLLResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_localization_custom::ToLLResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robot_localization_custom::ToLLResponse_<ContainerAllocator1> & lhs, const ::robot_localization_custom::ToLLResponse_<ContainerAllocator2> & rhs)
{
  return lhs.ll_point == rhs.ll_point;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robot_localization_custom::ToLLResponse_<ContainerAllocator1> & lhs, const ::robot_localization_custom::ToLLResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robot_localization_custom

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "191f0513cae6fcb95b63e2ec2e976938";
  }

  static const char* value(const ::robot_localization_custom::ToLLResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x191f0513cae6fcb9ULL;
  static const uint64_t static_value2 = 0x5b63e2ec2e976938ULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_localization_custom/ToLLResponse";
  }

  static const char* value(const ::robot_localization_custom::ToLLResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geographic_msgs/GeoPoint ll_point\n"
"\n"
"\n"
"================================================================================\n"
"MSG: geographic_msgs/GeoPoint\n"
"# Geographic point, using the WGS 84 reference ellipsoid.\n"
"\n"
"# Latitude [degrees]. Positive is north of equator; negative is south\n"
"# (-90 <= latitude <= +90).\n"
"float64 latitude\n"
"\n"
"# Longitude [degrees]. Positive is east of prime meridian; negative is\n"
"# west (-180 <= longitude <= +180). At the poles, latitude is -90 or\n"
"# +90, and longitude is irrelevant, but must be in range.\n"
"float64 longitude\n"
"\n"
"# Altitude [m]. Positive is above the WGS 84 ellipsoid (NaN if unspecified).\n"
"float64 altitude\n"
;
  }

  static const char* value(const ::robot_localization_custom::ToLLResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ll_point);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ToLLResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_localization_custom::ToLLResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_localization_custom::ToLLResponse_<ContainerAllocator>& v)
  {
    s << indent << "ll_point: ";
    s << std::endl;
    Printer< ::geographic_msgs::GeoPoint_<ContainerAllocator> >::stream(s, indent + "  ", v.ll_point);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_LOCALIZATION_CUSTOM_MESSAGE_TOLLRESPONSE_H
