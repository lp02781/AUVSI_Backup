// Generated by gencpp from file roboboat/node_master.msg
// DO NOT EDIT!


#ifndef ROBOBOAT_MESSAGE_NODE_MASTER_H
#define ROBOBOAT_MESSAGE_NODE_MASTER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace roboboat
{
template <class ContainerAllocator>
struct node_master_
{
  typedef node_master_<ContainerAllocator> Type;

  node_master_()
    : override_status(false)
    , pid_status(false)
    , simple_manuver(false)
    , simple_speed(false)
    , record_manuver(false)
    , record_speed(false)
    , path_manuver(false)
    , path_speed(false)  {
    }
  node_master_(const ContainerAllocator& _alloc)
    : override_status(false)
    , pid_status(false)
    , simple_manuver(false)
    , simple_speed(false)
    , record_manuver(false)
    , record_speed(false)
    , path_manuver(false)
    , path_speed(false)  {
  (void)_alloc;
    }



   typedef uint8_t _override_status_type;
  _override_status_type override_status;

   typedef uint8_t _pid_status_type;
  _pid_status_type pid_status;

   typedef uint8_t _simple_manuver_type;
  _simple_manuver_type simple_manuver;

   typedef uint8_t _simple_speed_type;
  _simple_speed_type simple_speed;

   typedef uint8_t _record_manuver_type;
  _record_manuver_type record_manuver;

   typedef uint8_t _record_speed_type;
  _record_speed_type record_speed;

   typedef uint8_t _path_manuver_type;
  _path_manuver_type path_manuver;

   typedef uint8_t _path_speed_type;
  _path_speed_type path_speed;





  typedef boost::shared_ptr< ::roboboat::node_master_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roboboat::node_master_<ContainerAllocator> const> ConstPtr;

}; // struct node_master_

typedef ::roboboat::node_master_<std::allocator<void> > node_master;

typedef boost::shared_ptr< ::roboboat::node_master > node_masterPtr;
typedef boost::shared_ptr< ::roboboat::node_master const> node_masterConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roboboat::node_master_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roboboat::node_master_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roboboat

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geographic_msgs': ['/opt/ros/kinetic/share/geographic_msgs/cmake/../msg'], 'roboboat': ['/home/amvui/AUVSI/src/roboboat/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'mavros_msgs': ['/opt/ros/kinetic/share/mavros_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'uuid_msgs': ['/opt/ros/kinetic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roboboat::node_master_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roboboat::node_master_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roboboat::node_master_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roboboat::node_master_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roboboat::node_master_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roboboat::node_master_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roboboat::node_master_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9783f29d89cc75e92f81094e627988e9";
  }

  static const char* value(const ::roboboat::node_master_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9783f29d89cc75e9ULL;
  static const uint64_t static_value2 = 0x2f81094e627988e9ULL;
};

template<class ContainerAllocator>
struct DataType< ::roboboat::node_master_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roboboat/node_master";
  }

  static const char* value(const ::roboboat::node_master_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roboboat::node_master_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool override_status\n\
bool pid_status\n\
bool simple_manuver\n\
bool simple_speed\n\
bool record_manuver\n\
bool record_speed\n\
bool path_manuver\n\
bool path_speed\n\
";
  }

  static const char* value(const ::roboboat::node_master_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roboboat::node_master_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.override_status);
      stream.next(m.pid_status);
      stream.next(m.simple_manuver);
      stream.next(m.simple_speed);
      stream.next(m.record_manuver);
      stream.next(m.record_speed);
      stream.next(m.path_manuver);
      stream.next(m.path_speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct node_master_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roboboat::node_master_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roboboat::node_master_<ContainerAllocator>& v)
  {
    s << indent << "override_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.override_status);
    s << indent << "pid_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.pid_status);
    s << indent << "simple_manuver: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.simple_manuver);
    s << indent << "simple_speed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.simple_speed);
    s << indent << "record_manuver: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.record_manuver);
    s << indent << "record_speed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.record_speed);
    s << indent << "path_manuver: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.path_manuver);
    s << indent << "path_speed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.path_speed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOBOAT_MESSAGE_NODE_MASTER_H
