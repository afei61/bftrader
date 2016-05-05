#include "rpcservice.h"
#include "bfgateway.grpc.pb.h"
#include "ctputils.h"
#include "encode_utils.h"
#include "gatewaymgr.h"
#include "pushservice.h"
#include "servicemgr.h"
#include <QThread>
#include <QtCore/QDebug>
#include <grpc++/grpc++.h>

using namespace bftrader;
using namespace bftrader::bfgateway;

//
// Gateway
//

class Gateway final : public BfGatewayService::Service {
public:
    explicit Gateway(QString gatewayId)
        : gatewayId_(gatewayId)
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
    }
    virtual ~Gateway()
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
    }
    virtual ::grpc::Status Connect(::grpc::ServerContext* context, const ::bftrader::BfConnectReq* request, ::bftrader::BfConnectResp* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());

        BfDebug("peer:%s,%s:%s:%d", context->peer().c_str(), request->clientid().c_str(), request->clientip().c_str(), request->clientport());
        QMetaObject::invokeMethod(g_sm->pushService(), "connectProxy", Qt::QueuedConnection, Q_ARG(QString, gatewayId_), Q_ARG(BfConnectReq, *request));

        response->set_errorcode(0);
        return grpc::Status::OK;
    }
    virtual ::grpc::Status Ping(::grpc::ServerContext* context, const ::bftrader::BfPingData* request, ::bftrader::BfPingData* response) override
    {
        QString clientId = getClientId(context);
        response->set_message(request->message());
        return grpc::Status::OK;
    }
    virtual ::grpc::Status Disconnect(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());

        QString clientId = getClientId(context);
        BfDebug("clientId=%s", qPrintable(clientId));

        QMetaObject::invokeMethod(g_sm->pushService(), "disconnectProxy", Qt::QueuedConnection, Q_ARG(QString, clientId));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status GetContract(::grpc::ServerContext* context, const ::bftrader::BfGetContractReq* request, ::bftrader::BfContractData* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());

        QString clientId = getClientId(context);
        BfDebug("clientId=%s", qPrintable(clientId));

        int index = request->index();
        if (index <= 0) {
            QString symbol = request->symbol().c_str();
            void* contract = g_sm->gatewayMgr()->getContract(symbol);
            CtpUtils::translateContract(contract, response);
        } else {
            QStringList ids = request->subscribled() ? g_sm->gatewayMgr()->getIds() : g_sm->gatewayMgr()->getIdsAll();
            if (ids.length() > index - 1) {
                QString symbol = ids.at(index - 1);
                void* contract = g_sm->gatewayMgr()->getContract(symbol);
                CtpUtils::translateContract(contract, response);
            }
        }

        return grpc::Status::OK;
    }
    virtual ::grpc::Status SendOrder(::grpc::ServerContext* context, const ::bftrader::BfSendOrderReq* request, ::bftrader::BfSendOrderResp* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());

        QString clientId = getClientId(context);
        BfDebug("clientId=%s", qPrintable(clientId));

        QString bfOrderId = g_sm->gatewayMgr()->genOrderId();
        response->set_bforderid(bfOrderId.toStdString());

        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "sendOrderWithId", Qt::QueuedConnection, Q_ARG(QString, bfOrderId), Q_ARG(BfSendOrderReq, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status CancelOrder(::grpc::ServerContext* context, const ::bftrader::BfCancelOrderReq* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());

        QString clientId = getClientId(context);
        BfDebug("clientId=%s", qPrintable(clientId));

        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "cancelOrder", Qt::QueuedConnection, Q_ARG(BfCancelOrderReq, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status QueryAccount(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());

        QString clientId = getClientId(context);
        BfDebug("clientId=%s", qPrintable(clientId));

        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "queryAccount", Qt::QueuedConnection);
        return grpc::Status::OK;
    }
    virtual ::grpc::Status QueryPosition(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());

        QString clientId = getClientId(context);
        BfDebug("clientId=%s", qPrintable(clientId));

        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "queryPosition", Qt::QueuedConnection);
        return grpc::Status::OK;
    }

private:
    // metadata-key只能是小写的=
    QString getClientId(::grpc::ServerContext* context)
    {
        QString clientId;
        if (0 != context->client_metadata().count("clientid")) {
            auto its = context->client_metadata().equal_range("clientid");
            auto it = its.first;
            clientId = grpc::string(it->second.begin(), it->second.end()).c_str();
            //BfDebug("metadata: clientid=%s", clientId.toStdString().c_str());
        }
        return clientId;
    }

private:
    QString gatewayId_;
};

//
// RpcService
//

RpcService::RpcService(QObject* parent)
    : QObject(parent)
{
}

void RpcService::init()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::RPC);
}

void RpcService::shutdown()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::RPC);

    stop();
}

void RpcService::start()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::RPC);

    if (gatewayThread_ == nullptr) {
        gatewayThread_ = new QThread();
        QObject::connect(gatewayThread_, &QThread::started, this, &RpcService::onGatewayThreadStarted, Qt::DirectConnection);
        gatewayThread_->start();
    }
}

void RpcService::stop()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::RPC);

    if (gatewayThread_ != nullptr) {
        grpcServer_->Shutdown();
        grpcServer_ = nullptr;

        gatewayThread_->quit();
        gatewayThread_->wait();
        delete gatewayThread_;
        gatewayThread_ = nullptr;

        QMetaObject::invokeMethod(g_sm->pushService(), "onGatewayClosed", Qt::QueuedConnection);
    }
}

void RpcService::onGatewayThreadStarted()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::EXTERNAL);

    std::string server_address("0.0.0.0:50051");
    Gateway gateway("ctpgateway");

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&gateway);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    BfInfo(QString("gateway listening on ") + server_address.c_str());
    grpcServer_ = server.get();

    server->Wait();
    BfInfo(QString("gateway shutdown"));
}
