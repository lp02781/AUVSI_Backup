// Generated by gencpp from file kocheng/image_in.msg
// DO NOT EDIT!


#ifndef KOCHENG_MESSAGE_IMAGE_IN_H
#define KOCHENG_MESSAGE_IMAGE_IN_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace kocheng
{
template <class ContainerAllocator>
struct image_in_
{
  typedef image_in_<ContainerAllocator> Type;

  image_in_()
    : x_init(0)
    , y_init(0)
    , width(0)
    , height(0)
    , LowH(0)
    , HighH(0)
    , LowS(0)
    , HighS(0)
    , LowV(0)
    , HighV(0)
    , Noise(0)  {
    }
  image_in_(const ContainerAllocator& _alloc)
    : x_init(0)
    , y_init(0)
    , width(0)
    , height(0)
    , LowH(0)
    , HighH(0)
    , LowS(0)
    , HighS(0)
    , LowV(0)
    , HighV(0)
    , Noise(0)  {
  (void)_alloc;
    }



   typedef int32_t _x_init_type;
  _x_init_type x_init;

   typedef int32_t _y_init_type;
  _y_init_type y_init;

   typedef int32_t _width_type;
  _width_type width;

   typedef int32_t _height_type;
  _height_type height;

   typedef int32_t _LowH_type;
  _LowH_type LowH;

   typedef int32_t _HighH_type;
  _HighH_type HighH;

   typedef int32_t _LowS_type;
  _LowS_type LowS;

   typedef int32_t _HighS_type;
  _HighS_type HighS;

   typedef int32_t _LowV_type;
  _LowV_type LowV;

   typedef int32_t _HighV_type;
  _HighV_type HighV;

   typedef int32_t _Noise_type;
  _Noise_type Noise;





  typedef boost::shared_ptr< ::kocheng::image_in_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kocheng::image_in_<ContainerAllocator> const> ConstPtr;

}; // struct image_in_

typedef ::kocheng::image_in_<std::allocator<void> > image_in;

typedef boost::shared_ptr< ::kocheng::image_in > image_inPtr;
typedef boost::shared_ptr< ::kocheng::image_in const> image_inConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kocheng::image_in_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kocheng::image_in_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kocheng

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geographic_msgs': ['/opt/ros/kinetic/share/geographic_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'mavros_msgs': ['/opt/ros/kinetic/share/mavros_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'kocheng': ['/home/mfikih15/Documents/AUVSI/src/kocheng/msg'], 'uuid_msgs': ['/opt/ros/kinetic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::kocheng::image_in_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kocheng::image_in_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kocheng::image_in_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kocheng::image_in_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kocheng::image_in_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kocheng::image_in_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kocheng::image_in_<ContainerAllocator> >
{
  static const char* value()
  {
    return "98a894c5a1e69900105970008d648417";
  }

  static const char* value(const ::kocheng::image_in_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x98a894c5a1e69900ULL;
  static const uint64_t static_value2 = 0x105970008d648417ULL;
};

template<class ContainerAllocator>
struct DataType< ::kocheng::image_in_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kocheng/image_in";
  }

  static const char* value(const ::kocheng::image_in_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kocheng::image_in_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 x_init\n\
int32 y_init\n\
int32 width\n\
int32 height\n\
int32 LowH \n\
int32 HighH\n\
int32 LowS\n\
int32 HighS\n\
int32 LowV\n\
int32 HighV\n\
int32 Noise\n\
";
  }

  static const char* value(const ::kocheng::image_in_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kocheng::image_in_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x_init);
      stream.next(m.y_init);
      stream.next(m.width);
      stream.next(m.height);
      stream.next(m.LowH);
      stream.next(m.HighH);
      stream.next(m.LowS);
      stream.next(m.HighS);
      stream.next(m.LowV);
      stream.next(m.HighV);
      stream.next(m.Noise);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct image_in_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kocheng::image_in_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kocheng::image_in_<ContainerAllocator>& v)
  {
    s << indent << "x_init: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x_init);
    s << indent << "y_init: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y_init);
    s << indent << "width: ";
    Printer<int32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);
    s << indent << "LowH: ";
    Printer<int32_t>::stream(s, indent + "  ", v.LowH);
    s << indent << "HighH: ";
    Printer<int32_t>::stream(s, indent + "  ", v.HighH);
    s << indent << "LowS: ";
    Printer<int32_t>::stream(s, indent + "  ", v.LowS);
    s << indent << "HighS: ";
    Printer<int32_t>::stream(s, indent + "  ", v.HighS);
    s << indent << "LowV: ";
    Printer<int32_t>::stream(s, indent + "  ", v.LowV);
    s << indent << "HighV: ";
    Printer<int32_t>::stream(s, indent + "  ", v.HighV);
    s << indent << "Noise: ";
    Printer<int32_t>::stream(s, indent + "  ", v.Noise);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KOCHENG_MESSAGE_IMAGE_IN_H