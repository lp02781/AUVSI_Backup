// Generated by gencpp from file kocheng/communication.msg
// DO NOT EDIT!


#ifndef KOCHENG_MESSAGE_COMMUNICATION_H
#define KOCHENG_MESSAGE_COMMUNICATION_H


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
struct communication_
{
  typedef communication_<ContainerAllocator> Type;

  communication_()
    : heartbeat_payload()
    , run_course_payload()
    , follow_payload()
    , docking_payload()  {
    }
  communication_(const ContainerAllocator& _alloc)
    : heartbeat_payload(_alloc)
    , run_course_payload(_alloc)
    , follow_payload(_alloc)
    , docking_payload(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _heartbeat_payload_type;
  _heartbeat_payload_type heartbeat_payload;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _run_course_payload_type;
  _run_course_payload_type run_course_payload;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _follow_payload_type;
  _follow_payload_type follow_payload;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _docking_payload_type;
  _docking_payload_type docking_payload;





  typedef boost::shared_ptr< ::kocheng::communication_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kocheng::communication_<ContainerAllocator> const> ConstPtr;

}; // struct communication_

typedef ::kocheng::communication_<std::allocator<void> > communication;

typedef boost::shared_ptr< ::kocheng::communication > communicationPtr;
typedef boost::shared_ptr< ::kocheng::communication const> communicationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kocheng::communication_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kocheng::communication_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kocheng

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geographic_msgs': ['/opt/ros/kinetic/share/geographic_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'mavros_msgs': ['/opt/ros/kinetic/share/mavros_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'kocheng': ['/home/mfikih15/Documents/AUVSI/src/kocheng/msg'], 'uuid_msgs': ['/opt/ros/kinetic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::kocheng::communication_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kocheng::communication_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kocheng::communication_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kocheng::communication_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kocheng::communication_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kocheng::communication_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kocheng::communication_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a4a71690d66d1b694fd29ac92ce201eb";
  }

  static const char* value(const ::kocheng::communication_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa4a71690d66d1b69ULL;
  static const uint64_t static_value2 = 0x4fd29ac92ce201ebULL;
};

template<class ContainerAllocator>
struct DataType< ::kocheng::communication_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kocheng/communication";
  }

  static const char* value(const ::kocheng::communication_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kocheng::communication_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string heartbeat_payload\n\
string run_course_payload\n\
string follow_payload\n\
string docking_payload\n\
";
  }

  static const char* value(const ::kocheng::communication_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kocheng::communication_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.heartbeat_payload);
      stream.next(m.run_course_payload);
      stream.next(m.follow_payload);
      stream.next(m.docking_payload);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct communication_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kocheng::communication_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kocheng::communication_<ContainerAllocator>& v)
  {
    s << indent << "heartbeat_payload: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.heartbeat_payload);
    s << indent << "run_course_payload: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.run_course_payload);
    s << indent << "follow_payload: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.follow_payload);
    s << indent << "docking_payload: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.docking_payload);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KOCHENG_MESSAGE_COMMUNICATION_H