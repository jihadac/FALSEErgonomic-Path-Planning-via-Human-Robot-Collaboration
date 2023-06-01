// Generated by gencpp from file ros_openpose/BodyPart.msg
// DO NOT EDIT!


#ifndef ROS_OPENPOSE_MESSAGE_BODYPART_H
#define ROS_OPENPOSE_MESSAGE_BODYPART_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ros_openpose/Pixel.h>
#include <geometry_msgs/Point32.h>

namespace ros_openpose
{
template <class ContainerAllocator>
struct BodyPart_
{
  typedef BodyPart_<ContainerAllocator> Type;

  BodyPart_()
    : score(0.0)
    , pixel()
    , point()  {
    }
  BodyPart_(const ContainerAllocator& _alloc)
    : score(0.0)
    , pixel(_alloc)
    , point(_alloc)  {
  (void)_alloc;
    }



   typedef float _score_type;
  _score_type score;

   typedef  ::ros_openpose::Pixel_<ContainerAllocator>  _pixel_type;
  _pixel_type pixel;

   typedef  ::geometry_msgs::Point32_<ContainerAllocator>  _point_type;
  _point_type point;





  typedef boost::shared_ptr< ::ros_openpose::BodyPart_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_openpose::BodyPart_<ContainerAllocator> const> ConstPtr;

}; // struct BodyPart_

typedef ::ros_openpose::BodyPart_<std::allocator<void> > BodyPart;

typedef boost::shared_ptr< ::ros_openpose::BodyPart > BodyPartPtr;
typedef boost::shared_ptr< ::ros_openpose::BodyPart const> BodyPartConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_openpose::BodyPart_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_openpose::BodyPart_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_openpose::BodyPart_<ContainerAllocator1> & lhs, const ::ros_openpose::BodyPart_<ContainerAllocator2> & rhs)
{
  return lhs.score == rhs.score &&
    lhs.pixel == rhs.pixel &&
    lhs.point == rhs.point;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_openpose::BodyPart_<ContainerAllocator1> & lhs, const ::ros_openpose::BodyPart_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_openpose

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ros_openpose::BodyPart_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_openpose::BodyPart_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_openpose::BodyPart_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_openpose::BodyPart_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_openpose::BodyPart_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_openpose::BodyPart_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_openpose::BodyPart_<ContainerAllocator> >
{
  static const char* value()
  {
    return "243edb92e04d1e621047e9d565b8e64f";
  }

  static const char* value(const ::ros_openpose::BodyPart_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x243edb92e04d1e62ULL;
  static const uint64_t static_value2 = 0x1047e9d565b8e64fULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_openpose::BodyPart_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_openpose/BodyPart";
  }

  static const char* value(const ::ros_openpose::BodyPart_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_openpose::BodyPart_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# The location and score of body parts are stored in a float array.\n"
"# Therefore we are using 32 bits instead of 64 bits.\n"
"# src: https://github.com/CMU-Perceptual-Computing-Lab/openpose/blob/master/include/openpose/core/datum.hpp\n"
"float32 score\n"
"Pixel pixel\n"
"geometry_msgs/Point32 point\n"
"\n"
"================================================================================\n"
"MSG: ros_openpose/Pixel\n"
"# The location and score of body parts are stored in a float array.\n"
"# Therefore we are using 32 bits instead of 64 bits.\n"
"# src: https://github.com/CMU-Perceptual-Computing-Lab/openpose/blob/master/include/openpose/core/datum.hpp\n"
"# The location has been resized to the desired output\n"
"# resolution (e.g., `resolution` flag in the demo).\n"
"float32 x\n"
"float32 y\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point32\n"
"# This contains the position of a point in free space(with 32 bits of precision).\n"
"# It is recommeded to use Point wherever possible instead of Point32.  \n"
"# \n"
"# This recommendation is to promote interoperability.  \n"
"#\n"
"# This message is designed to take up less space when sending\n"
"# lots of points at once, as in the case of a PointCloud.  \n"
"\n"
"float32 x\n"
"float32 y\n"
"float32 z\n"
;
  }

  static const char* value(const ::ros_openpose::BodyPart_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_openpose::BodyPart_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.score);
      stream.next(m.pixel);
      stream.next(m.point);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct BodyPart_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_openpose::BodyPart_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_openpose::BodyPart_<ContainerAllocator>& v)
  {
    s << indent << "score: ";
    Printer<float>::stream(s, indent + "  ", v.score);
    s << indent << "pixel: ";
    s << std::endl;
    Printer< ::ros_openpose::Pixel_<ContainerAllocator> >::stream(s, indent + "  ", v.pixel);
    s << indent << "point: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point32_<ContainerAllocator> >::stream(s, indent + "  ", v.point);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_OPENPOSE_MESSAGE_BODYPART_H
