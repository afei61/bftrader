// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: bfrobot.proto

#include "bfrobot.pb.h"
#include "bfrobot.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace bftrader {
namespace bfrobot {

static const char* BfRobotService_method_names[] = {
  "/bftrader.bfrobot.BfRobotService/OnPing",
  "/bftrader.bfrobot.BfRobotService/OnTick",
  "/bftrader.bfrobot.BfRobotService/OnTrade",
  "/bftrader.bfrobot.BfRobotService/OnOrder",
  "/bftrader.bfrobot.BfRobotService/OnInit",
  "/bftrader.bfrobot.BfRobotService/OnStart",
  "/bftrader.bfrobot.BfRobotService/OnStop",
};

std::unique_ptr< BfRobotService::Stub> BfRobotService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< BfRobotService::Stub> stub(new BfRobotService::Stub(channel));
  return stub;
}

BfRobotService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_OnPing_(BfRobotService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnTick_(BfRobotService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnTrade_(BfRobotService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnOrder_(BfRobotService_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnInit_(BfRobotService_method_names[4], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnStart_(BfRobotService_method_names[5], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnStop_(BfRobotService_method_names[6], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BfRobotService::Stub::OnPing(::grpc::ClientContext* context, const ::bftrader::BfPingData& request, ::bftrader::BfPingData* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnPing_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfPingData>* BfRobotService::Stub::AsyncOnPingRaw(::grpc::ClientContext* context, const ::bftrader::BfPingData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfPingData>(channel_.get(), cq, rpcmethod_OnPing_, context, request);
}

::grpc::Status BfRobotService::Stub::OnTick(::grpc::ClientContext* context, const ::bftrader::BfTickData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnTick_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfRobotService::Stub::AsyncOnTickRaw(::grpc::ClientContext* context, const ::bftrader::BfTickData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnTick_, context, request);
}

::grpc::Status BfRobotService::Stub::OnTrade(::grpc::ClientContext* context, const ::bftrader::BfTradeData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnTrade_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfRobotService::Stub::AsyncOnTradeRaw(::grpc::ClientContext* context, const ::bftrader::BfTradeData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnTrade_, context, request);
}

::grpc::Status BfRobotService::Stub::OnOrder(::grpc::ClientContext* context, const ::bftrader::BfOrderData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnOrder_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfRobotService::Stub::AsyncOnOrderRaw(::grpc::ClientContext* context, const ::bftrader::BfOrderData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnOrder_, context, request);
}

::grpc::Status BfRobotService::Stub::OnInit(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnInit_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfRobotService::Stub::AsyncOnInitRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnInit_, context, request);
}

::grpc::Status BfRobotService::Stub::OnStart(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnStart_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfRobotService::Stub::AsyncOnStartRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnStart_, context, request);
}

::grpc::Status BfRobotService::Stub::OnStop(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnStop_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfRobotService::Stub::AsyncOnStopRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnStop_, context, request);
}

BfRobotService::Service::Service() {
  (void)BfRobotService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      BfRobotService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfRobotService::Service, ::bftrader::BfPingData, ::bftrader::BfPingData>(
          std::mem_fn(&BfRobotService::Service::OnPing), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfRobotService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfRobotService::Service, ::bftrader::BfTickData, ::bftrader::BfVoid>(
          std::mem_fn(&BfRobotService::Service::OnTick), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfRobotService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfRobotService::Service, ::bftrader::BfTradeData, ::bftrader::BfVoid>(
          std::mem_fn(&BfRobotService::Service::OnTrade), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfRobotService_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfRobotService::Service, ::bftrader::BfOrderData, ::bftrader::BfVoid>(
          std::mem_fn(&BfRobotService::Service::OnOrder), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfRobotService_method_names[4],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfRobotService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfRobotService::Service::OnInit), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfRobotService_method_names[5],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfRobotService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfRobotService::Service::OnStart), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfRobotService_method_names[6],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfRobotService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfRobotService::Service::OnStop), this)));
}

BfRobotService::Service::~Service() {
}

::grpc::Status BfRobotService::Service::OnPing(::grpc::ServerContext* context, const ::bftrader::BfPingData* request, ::bftrader::BfPingData* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfRobotService::Service::OnTick(::grpc::ServerContext* context, const ::bftrader::BfTickData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfRobotService::Service::OnTrade(::grpc::ServerContext* context, const ::bftrader::BfTradeData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfRobotService::Service::OnOrder(::grpc::ServerContext* context, const ::bftrader::BfOrderData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfRobotService::Service::OnInit(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfRobotService::Service::OnStart(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfRobotService::Service::OnStop(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace bftrader
}  // namespace bfrobot

