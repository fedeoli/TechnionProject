// Generated by gencpp from file robot_localization_custom/GetState.msg
// DO NOT EDIT!


#ifndef ROBOT_LOCALIZATION_CUSTOM_MESSAGE_GETSTATE_H
#define ROBOT_LOCALIZATION_CUSTOM_MESSAGE_GETSTATE_H

#include <ros/service_traits.h>


#include <robot_localization_custom/GetStateRequest.h>
#include <robot_localization_custom/GetStateResponse.h>


namespace robot_localization_custom
{

struct GetState
{

typedef GetStateRequest Request;
typedef GetStateResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetState
} // namespace robot_localization_custom


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::robot_localization_custom::GetState > {
  static const char* value()
  {
    return "b143410e9c7f7be208eedf8f691d8069";
  }

  static const char* value(const ::robot_localization_custom::GetState&) { return value(); }
};

template<>
struct DataType< ::robot_localization_custom::GetState > {
  static const char* value()
  {
    return "robot_localization_custom/GetState";
  }

  static const char* value(const ::robot_localization_custom::GetState&) { return value(); }
};


// service_traits::MD5Sum< ::robot_localization_custom::GetStateRequest> should match
// service_traits::MD5Sum< ::robot_localization_custom::GetState >
template<>
struct MD5Sum< ::robot_localization_custom::GetStateRequest>
{
  static const char* value()
  {
    return MD5Sum< ::robot_localization_custom::GetState >::value();
  }
  static const char* value(const ::robot_localization_custom::GetStateRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::robot_localization_custom::GetStateRequest> should match
// service_traits::DataType< ::robot_localization_custom::GetState >
template<>
struct DataType< ::robot_localization_custom::GetStateRequest>
{
  static const char* value()
  {
    return DataType< ::robot_localization_custom::GetState >::value();
  }
  static const char* value(const ::robot_localization_custom::GetStateRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::robot_localization_custom::GetStateResponse> should match
// service_traits::MD5Sum< ::robot_localization_custom::GetState >
template<>
struct MD5Sum< ::robot_localization_custom::GetStateResponse>
{
  static const char* value()
  {
    return MD5Sum< ::robot_localization_custom::GetState >::value();
  }
  static const char* value(const ::robot_localization_custom::GetStateResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::robot_localization_custom::GetStateResponse> should match
// service_traits::DataType< ::robot_localization_custom::GetState >
template<>
struct DataType< ::robot_localization_custom::GetStateResponse>
{
  static const char* value()
  {
    return DataType< ::robot_localization_custom::GetState >::value();
  }
  static const char* value(const ::robot_localization_custom::GetStateResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROBOT_LOCALIZATION_CUSTOM_MESSAGE_GETSTATE_H
