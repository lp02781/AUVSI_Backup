// Generated by gencpp from file pid/pid_const_msg.msg
// DO NOT EDIT!


#ifndef PID_MESSAGE_PID_CONST_MSG_H
#define PID_MESSAGE_PID_CONST_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pid
{
template <class ContainerAllocator>
struct pid_const_msg_
{
  typedef pid_const_msg_<ContainerAllocator> Type;

  pid_const_msg_()
    : p(0.0)
    , i(0.0)
    , d(0.0)  {
    }
  pid_const_msg_(const ContainerAllocator& _alloc)
    : p(0.0)
    , i(0.0)
    , d(0.0)  {
  (void)_alloc;
    }



   typedef double _p_type;
  _p_type p;

   typedef double _i_type;
  _i_type i;

   typedef double _d_type;
  _d_type d;





  typedef boost::shared_ptr< ::pid::pid_const_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pid::pid_const_msg_<ContainerAllocator> const> ConstPtr;

}; // struct pid_const_msg_

typedef ::pid::pid_const_msg_<std::allocator<void> > pid_const_msg;

typedef boost::shared_ptr< ::pid::pid_const_msg > pid_const_msgPtr;
typedef boost::shared_ptr< ::pid::pid_const_msg const> pid_const_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pid::pid_const_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pid::pid_const_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pid

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'pid': ['/home/amvui/AUVSI/src/pid/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pid::pid_const_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pid::pid_const_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pid::pid_const_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pid::pid_const_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pid::pid_const_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pid::pid_const_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pid::pid_const_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4d7f5db5580abe953fdf6985b0b4717c";
  }

  static const char* value(const ::pid::pid_const_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4d7f5db5580abe95ULL;
  static const uint64_t static_value2 = 0x3fdf6985b0b4717cULL;
};

template<class ContainerAllocator>
struct DataType< ::pid::pid_const_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pid/pid_const_msg";
  }

  static const char* value(const ::pid::pid_const_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pid::pid_const_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 p\n\
float64 i\n\
float64 d\n\
";
  }

  static const char* value(const ::pid::pid_const_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pid::pid_const_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.p);
      stream.next(m.i);
      stream.next(m.d);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pid_const_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pid::pid_const_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pid::pid_const_msg_<ContainerAllocator>& v)
  {
    s << indent << "p: ";
    Printer<double>::stream(s, indent + "  ", v.p);
    s << indent << "i: ";
    Printer<double>::stream(s, indent + "  ", v.i);
    s << indent << "d: ";
    Printer<double>::stream(s, indent + "  ", v.d);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PID_MESSAGE_PID_CONST_MSG_H
