// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bfgateway.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "bfgateway.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace bftrader {
namespace bfgateway {

namespace {


}  // namespace


void protobuf_AssignDesc_bfgateway_2eproto() {
  protobuf_AddDesc_bfgateway_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "bfgateway.proto");
  GOOGLE_CHECK(file != NULL);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_bfgateway_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_bfgateway_2eproto() {
}

void protobuf_AddDesc_bfgateway_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::bftrader::protobuf_AddDesc_bftrader_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017bfgateway.proto\022\022bftrader.bfgateway\032\016b"
    "ftrader.proto2\361\003\n\020BfGatewayService\022<\n\007Co"
    "nnect\022\026.bftrader.BfConnectReq\032\027.bftrader"
    ".BfConnectResp\"\000\0224\n\004Ping\022\024.bftrader.BfPi"
    "ngData\032\024.bftrader.BfPingData\"\000\0222\n\nDiscon"
    "nect\022\020.bftrader.BfVoid\032\020.bftrader.BfVoid"
    "\"\000\022E\n\013GetContract\022\032.bftrader.BfGetContra"
    "ctReq\032\030.bftrader.BfContractData\"\000\022B\n\tSen"
    "dOrder\022\030.bftrader.BfSendOrderReq\032\031.bftra"
    "der.BfSendOrderResp\"\000\022=\n\013CancelOrder\022\032.b"
    "ftrader.BfCancelOrderReq\032\020.bftrader.BfVo"
    "id\"\000\0224\n\014QueryAccount\022\020.bftrader.BfVoid\032\020"
    ".bftrader.BfVoid\"\000\0225\n\rQueryPosition\022\020.bf"
    "trader.BfVoid\032\020.bftrader.BfVoid\"\000b\006proto"
    "3", 561);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "bfgateway.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_bfgateway_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_bfgateway_2eproto {
  StaticDescriptorInitializer_bfgateway_2eproto() {
    protobuf_AddDesc_bfgateway_2eproto();
  }
} static_descriptor_initializer_bfgateway_2eproto_;

// @@protoc_insertion_point(namespace_scope)

}  // namespace bfgateway
}  // namespace bftrader

// @@protoc_insertion_point(global_scope)
