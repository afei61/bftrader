// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: bfgateway.proto

#include "bfgateway.pb.h"
#include "bfgateway.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace bftrader {
namespace bfgateway {

static const char* BfGatewayService_method_names[] = {
  "/bftrader.bfgateway.BfGatewayService/Connect",
  "/bftrader.bfgateway.BfGatewayService/Ping",
  "/bftrader.bfgateway.BfGatewayService/Disconnect",
  "/bftrader.bfgateway.BfGatewayService/GetContract",
  "/bftrader.bfgateway.BfGatewayService/SendOrder",
  "/bftrader.bfgateway.BfGatewayService/CancelOrder",
  "/bftrader.bfgateway.BfGatewayService/QueryAccount",
  "/bftrader.bfgateway.BfGatewayService/QueryPosition",
};

std::unique_ptr< BfGatewayService::Stub> BfGatewayService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< BfGatewayService::Stub> stub(new BfGatewayService::Stub(channel));
  return stub;
}

BfGatewayService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Connect_(BfGatewayService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Ping_(BfGatewayService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Disconnect_(BfGatewayService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetContract_(BfGatewayService_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendOrder_(BfGatewayService_method_names[4], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CancelOrder_(BfGatewayService_method_names[5], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_QueryAccount_(BfGatewayService_method_names[6], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_QueryPosition_(BfGatewayService_method_names[7], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BfGatewayService::Stub::Connect(::grpc::ClientContext* context, const ::bftrader::BfConnectReq& request, ::bftrader::BfConnectResp* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Connect_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfConnectResp>* BfGatewayService::Stub::AsyncConnectRaw(::grpc::ClientContext* context, const ::bftrader::BfConnectReq& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfConnectResp>(channel_.get(), cq, rpcmethod_Connect_, context, request);
}

::grpc::Status BfGatewayService::Stub::Ping(::grpc::ClientContext* context, const ::bftrader::BfPingData& request, ::bftrader::BfPingData* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Ping_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfPingData>* BfGatewayService::Stub::AsyncPingRaw(::grpc::ClientContext* context, const ::bftrader::BfPingData& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfPingData>(channel_.get(), cq, rpcmethod_Ping_, context, request);
}

::grpc::Status BfGatewayService::Stub::Disconnect(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Disconnect_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfGatewayService::Stub::AsyncDisconnectRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_Disconnect_, context, request);
}

::grpc::Status BfGatewayService::Stub::GetContract(::grpc::ClientContext* context, const ::bftrader::BfGetContractReq& request, ::bftrader::BfContractData* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_GetContract_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfContractData>* BfGatewayService::Stub::AsyncGetContractRaw(::grpc::ClientContext* context, const ::bftrader::BfGetContractReq& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfContractData>(channel_.get(), cq, rpcmethod_GetContract_, context, request);
}

::grpc::Status BfGatewayService::Stub::SendOrder(::grpc::ClientContext* context, const ::bftrader::BfSendOrderReq& request, ::bftrader::BfSendOrderResp* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_SendOrder_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfSendOrderResp>* BfGatewayService::Stub::AsyncSendOrderRaw(::grpc::ClientContext* context, const ::bftrader::BfSendOrderReq& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfSendOrderResp>(channel_.get(), cq, rpcmethod_SendOrder_, context, request);
}

::grpc::Status BfGatewayService::Stub::CancelOrder(::grpc::ClientContext* context, const ::bftrader::BfCancelOrderReq& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_CancelOrder_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfGatewayService::Stub::AsyncCancelOrderRaw(::grpc::ClientContext* context, const ::bftrader::BfCancelOrderReq& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_CancelOrder_, context, request);
}

::grpc::Status BfGatewayService::Stub::QueryAccount(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_QueryAccount_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfGatewayService::Stub::AsyncQueryAccountRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_QueryAccount_, context, request);
}

::grpc::Status BfGatewayService::Stub::QueryPosition(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::bftrader::BfVoid* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_QueryPosition_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>* BfGatewayService::Stub::AsyncQueryPositionRaw(::grpc::ClientContext* context, const ::bftrader::BfVoid& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::bftrader::BfVoid>(channel_.get(), cq, rpcmethod_QueryPosition_, context, request);
}

BfGatewayService::Service::Service() {
  (void)BfGatewayService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfConnectReq, ::bftrader::BfConnectResp>(
          std::mem_fn(&BfGatewayService::Service::Connect), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfPingData, ::bftrader::BfPingData>(
          std::mem_fn(&BfGatewayService::Service::Ping), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfGatewayService::Service::Disconnect), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfGetContractReq, ::bftrader::BfContractData>(
          std::mem_fn(&BfGatewayService::Service::GetContract), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[4],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfSendOrderReq, ::bftrader::BfSendOrderResp>(
          std::mem_fn(&BfGatewayService::Service::SendOrder), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[5],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfCancelOrderReq, ::bftrader::BfVoid>(
          std::mem_fn(&BfGatewayService::Service::CancelOrder), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[6],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfGatewayService::Service::QueryAccount), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      BfGatewayService_method_names[7],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< BfGatewayService::Service, ::bftrader::BfVoid, ::bftrader::BfVoid>(
          std::mem_fn(&BfGatewayService::Service::QueryPosition), this)));
}

BfGatewayService::Service::~Service() {
}

::grpc::Status BfGatewayService::Service::Connect(::grpc::ServerContext* context, const ::bftrader::BfConnectReq* request, ::bftrader::BfConnectResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfGatewayService::Service::Ping(::grpc::ServerContext* context, const ::bftrader::BfPingData* request, ::bftrader::BfPingData* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfGatewayService::Service::Disconnect(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfGatewayService::Service::GetContract(::grpc::ServerContext* context, const ::bftrader::BfGetContractReq* request, ::bftrader::BfContractData* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfGatewayService::Service::SendOrder(::grpc::ServerContext* context, const ::bftrader::BfSendOrderReq* request, ::bftrader::BfSendOrderResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfGatewayService::Service::CancelOrder(::grpc::ServerContext* context, const ::bftrader::BfCancelOrderReq* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfGatewayService::Service::QueryAccount(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BfGatewayService::Service::QueryPosition(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace bftrader
}  // namespace bfgateway

