// Generated by gencpp from file franka_control/SetEEFrame.msg
// DO NOT EDIT!


#ifndef FRANKA_CONTROL_MESSAGE_SETEEFRAME_H
#define FRANKA_CONTROL_MESSAGE_SETEEFRAME_H

#include <ros/service_traits.h>


#include <franka_control/SetEEFrameRequest.h>
#include <franka_control/SetEEFrameResponse.h>


namespace franka_control
{

struct SetEEFrame
{

typedef SetEEFrameRequest Request;
typedef SetEEFrameResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetEEFrame
} // namespace franka_control


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::franka_control::SetEEFrame > {
  static const char* value()
  {
    return "1e4ea5c444c20450d45357b4d238129b";
  }

  static const char* value(const ::franka_control::SetEEFrame&) { return value(); }
};

template<>
struct DataType< ::franka_control::SetEEFrame > {
  static const char* value()
  {
    return "franka_control/SetEEFrame";
  }

  static const char* value(const ::franka_control::SetEEFrame&) { return value(); }
};


// service_traits::MD5Sum< ::franka_control::SetEEFrameRequest> should match
// service_traits::MD5Sum< ::franka_control::SetEEFrame >
template<>
struct MD5Sum< ::franka_control::SetEEFrameRequest>
{
  static const char* value()
  {
    return MD5Sum< ::franka_control::SetEEFrame >::value();
  }
  static const char* value(const ::franka_control::SetEEFrameRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::franka_control::SetEEFrameRequest> should match
// service_traits::DataType< ::franka_control::SetEEFrame >
template<>
struct DataType< ::franka_control::SetEEFrameRequest>
{
  static const char* value()
  {
    return DataType< ::franka_control::SetEEFrame >::value();
  }
  static const char* value(const ::franka_control::SetEEFrameRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::franka_control::SetEEFrameResponse> should match
// service_traits::MD5Sum< ::franka_control::SetEEFrame >
template<>
struct MD5Sum< ::franka_control::SetEEFrameResponse>
{
  static const char* value()
  {
    return MD5Sum< ::franka_control::SetEEFrame >::value();
  }
  static const char* value(const ::franka_control::SetEEFrameResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::franka_control::SetEEFrameResponse> should match
// service_traits::DataType< ::franka_control::SetEEFrame >
template<>
struct DataType< ::franka_control::SetEEFrameResponse>
{
  static const char* value()
  {
    return DataType< ::franka_control::SetEEFrame >::value();
  }
  static const char* value(const ::franka_control::SetEEFrameResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // FRANKA_CONTROL_MESSAGE_SETEEFRAME_H
