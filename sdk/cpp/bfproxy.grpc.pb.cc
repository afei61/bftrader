// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: bfproxy.proto

#include "bfproxy.pb.h"
#include "bfproxy.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace bftrader {
namespace bfproxy {

static const char* BfProxyService_method_names[] = {
  "/bftrader.bfproxy.BfProxyService/OnPing",
  "/bftrader.bfproxy.BfProxyService/OnTradeWillBegin",
  "/bftrader.bfproxy.BfProxyService/OnGotContracts",
  "/bftrader.bfproxy.BfProxyService/OnTick",
  "/bftrader.bfproxy.BfProxyService/OnError",
  "/bftrader.bfproxy.BfProxyService/OnLog",
  "/bftrader.bfproxy.BfProxyService/OnTrade",
  "/bftrader.bfproxy.BfProxyService/OnOrder",
  "/bftrader.bfproxy.BfProxyService/OnPosition",
  "/bftrader.bfproxy.BfProxyService/OnAccount",
};

std::unique_ptr< BfProxyService::Stub> BfProxyService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< BfProxyService::Stub> stub(new BfProxyService::Stub(channel));
  return stub;
}

BfProxyService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_OnPing_(BfProxyService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnTradeWillBegin_(BfProxyService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnGotContracts_(BfProxyService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnTick_(BfProxyService_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnError_(BfProxyService_method_names[4], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnLog_(BfProxyService_method_names[5], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnTrade_(BfProxyService_method_names[6], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnOrder_(BfProxyService_method_names[7], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnPosition_(BfProxyService_method_names[8], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_OnAccount_(BfProxyService_method_names[9], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BfProxyService::Stub::OnPing(::grpc::ClientContext* context, const ::bftrader::BfPingData& request, ::bftrader::BfPingData* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnPing_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfPingData>* BfProxyService::Stub::AsyncOnPingRaw(::grpc::ClientContext* context, const ::bftrader::BfPingData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfPingData>(channel_.get(), cq, rpcmethod_OnPing_, context, request);
}

::grpc::Status BfProxyService::Stub::OnTradeWillBegin(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnTradeWillBegin_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnTradeWillBeginRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnTradeWillBegin_, context, request);
}

::grpc::Status BfProxyService::Stub::OnGotContracts(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnGotContracts_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnGotContractsRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnGotContracts_, context, request);
}

::grpc::Status BfProxyService::Stub::OnTick(::grpc::ClientContext* context, const ::bftrader::BfTickData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnTick_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnTickRaw(::grpc::ClientContext* context, const ::bftrader::BfTickData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnTick_, context, request);
}

::grpc::Status BfProxyService::Stub::OnError(::grpc::ClientContext* context, const ::bftrader::BfErrorData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnError_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnErrorRaw(::grpc::ClientContext* context, const ::bftrader::BfErrorData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnError_, context, request);
}

::grpc::Status BfProxyService::Stub::OnLog(::grpc::ClientContext* context, const ::bftrader::BfLogData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnLog_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnLogRaw(::grpc::ClientContext* context, const ::bftrader::BfLogData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnLog_, context, request);
}

::grpc::Status BfProxyService::Stub::OnTrade(::grpc::ClientContext* context, const ::bftrader::BfTradeData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnTrade_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnTradeRaw(::grpc::ClientContext* context, const ::bftrader::BfTradeData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnTrade_, context, request);
}

::grpc::Status BfProxyService::Stub::OnOrder(::grpc::ClientContext* context, const ::bftrader::BfOrderData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnOrder_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnOrderRaw(::grpc::ClientContext* context, const ::bftrader::BfOrderData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnOrder_, context, request);
}

::grpc::Status BfProxyService::Stub::OnPosition(::grpc::ClientContext* context, const ::bftrader::BfPositionData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnPosition_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnPositionRaw(::grpc::ClientContext* context, const ::bftrader::BfPositionData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnPosition_, context, request);
}

::grpc::Status BfProxyService::Stub::OnAccount(::grpc::ClientContext* context, const ::bftrader::BfAccountData& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_OnAccount_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfProxyService::Stub::AsyncOnAccountRaw(::grpc::ClientContext* context, const ::bftrader::BfAccountData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_OnAccount_, context, request);
}

BfProxyService::Service::Service() {
  (void)BfProxyService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfPingData, ::bftrader::BfPingData>(
          std::mem_fn(&BfProxyService::Service::OnPing), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnTradeWillBegin), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnGotContracts), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfTickData, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnTick), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[4],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfErrorData, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnError), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[5],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfLogData, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnLog), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[6],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfTradeData, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnTrade), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[7],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfOrderData, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnOrder), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[8],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfPositionData, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnPosition), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfProxyService_method_names[9],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfProxyService::Service, ::bftrader::BfAccountData, ::bftrader::BfVoid>(
          std::mem_fn(&BfProxyService::Service::OnAccount), this)));
}

BfProxyService::Service::~Service() {
}

::grpc::Status BfProxyService::Service::OnPing(::grpc::ServerContext* context, const ::bftrader::BfPingData* request, ::bftrader::BfPingData* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnTradeWillBegin(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnGotContracts(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnTick(::grpc::ServerContext* context, const ::bftrader::BfTickData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnError(::grpc::ServerContext* context, const ::bftrader::BfErrorData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnLog(::grpc::ServerContext* context, const ::bftrader::BfLogData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnTrade(::grpc::ServerContext* context, const ::bftrader::BfTradeData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnOrder(::grpc::ServerContext* context, const ::bftrader::BfOrderData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnPosition(::grpc::ServerContext* context, const ::bftrader::BfPositionData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfProxyService::Service::OnAccount(::grpc::ServerContext* context, const ::bftrader::BfAccountData* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace bftrader
}  // namespace bfproxy

