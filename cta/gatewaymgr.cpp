#include "gatewaymgr.h"
#include "bfgateway.grpc.pb.h"
#include "bfproxy.grpc.pb.h"
#include "servicemgr.h"
#include <QThread>
#include <grpc++/grpc++.h>

using namespace bftrader;
using namespace bftrader::bfproxy;
using namespace bftrader::bfgateway;

//
// Proxy
//

class Proxy final : public BfProxyService::Service {
public:
    Proxy()
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
    }
    virtual ~Proxy()
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
    }
    virtual ::grpc::Status OnPing(::grpc::ServerContext* context, const ::bftrader::BfPingData* request, ::bftrader::BfPingData* response) override
    {
        BfDebug("%s on thread:%d,from:(%s)", __FUNCTION__, ::GetCurrentThreadId(), qPrintable(getClientId(context)));
        response->set_message(request->message());
        return grpc::Status::OK;
    }

    virtual ::grpc::Status OnTradeWillBegin(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "tradeWillBegin", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfVoid, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnGotContracts(::grpc::ServerContext* context, const ::bftrader::BfVoid* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotContracts", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfVoid, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnTick(::grpc::ServerContext* context, const ::bftrader::BfTickData* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotTick", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfTickData, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnError(::grpc::ServerContext* context, const ::bftrader::BfErrorData* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotError", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfErrorData, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnLog(::grpc::ServerContext* context, const ::bftrader::BfLogData* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotLog", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfLogData, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnTrade(::grpc::ServerContext* context, const ::bftrader::BfTradeData* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotTrade", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfTradeData, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnOrder(::grpc::ServerContext* context, const ::bftrader::BfOrderData* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotOrder", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfOrderData, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnPosition(::grpc::ServerContext* context, const ::bftrader::BfPositionData* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotPosition", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfPositionData, *request));
        return grpc::Status::OK;
    }
    virtual ::grpc::Status OnAccount(::grpc::ServerContext* context, const ::bftrader::BfAccountData* request, ::bftrader::BfVoid* response) override
    {
        BfDebug("%s on thread:%d", __FUNCTION__, ::GetCurrentThreadId());
        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "gotAccount", Qt::QueuedConnection, Q_ARG(QString, getClientId(context)), Q_ARG(BfAccountData, *request));
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
};

//
// GatewayClient
//
class GatewayClient {
public:
    GatewayClient(std::shared_ptr<grpc::Channel> channel, QString gatewayId, const BfConnectReq& req)
        : stub_(BfGatewayService::NewStub(channel))
        , gatewayId_(gatewayId)
        , req_(req)
    {
        BfDebug(__FUNCTION__);
    }
    ~GatewayClient() {}

    // ref: grpc\test\cpp\interop\interop_client.cc
    void Ping(const BfPingData& req, BfPingData& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->Ping(&ctx, req, &resp);
        if (!status.ok()) {
            pingfail_count_++;
            BfError("(%s)->Ping fail(%d),code:%d,msg:%s", qPrintable(gatewayId_), pingfail_count_, status.error_code(), status.error_message().c_str());
            //if (pingfail_count_ > 3) {
            //    BfError("(%s)->Ping fail too long,so kill it", qPrintable(gatewayId_));
            //    QMetaObject::invokeMethod(g_sm->gatewayMgr(), "disconnectGateway", Qt::QueuedConnection, Q_ARG(QString, gatewayId_));
            //}
            return;
        }
        pingfail_count_ = 0;

        if (req.message() != resp.message()) {
            BfError("(%s)->Ping fail,ping:%s,pong:%s", qPrintable(gatewayId_), req.message().c_str(), resp.message().c_str());
            return;
        }
    }

    void Connect(const BfConnectReq& req, BfConnectResp& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->Connect(&ctx, req, &resp);
        if (!status.ok()) {
            BfError("(%s)->Connect,code:%d,msg:%s", qPrintable(gatewayId_), status.error_code(), status.error_message().c_str());
        }
    }

    void Disconnect(const BfVoid& req, BfVoid& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->Disconnect(&ctx, req, &resp);
        if (!status.ok()) {
            BfError("(%s)->Disconnect,code:%d,msg:%s", qPrintable(gatewayId_), status.error_code(), status.error_message().c_str());
        }
    }

    void GetContract(const BfGetContractReq& req, BfContractData& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->GetContract(&ctx, req, &resp);
        if (!status.ok()) {
            BfError("(%s)->GetContract,code:%d,msg:%s", qPrintable(gatewayId_), status.error_code(), status.error_message().c_str());
        }
    }

    void SendOrder(const BfSendOrderReq& req, BfSendOrderResp& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->SendOrder(&ctx, req, &resp);
        if (!status.ok()) {
            BfError("(%s)->SendOrder,code:%d,msg:%s", qPrintable(gatewayId_), status.error_code(), status.error_message().c_str());
        }
    }

    void CancelOrder(const BfCancelOrderReq& req, BfVoid& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->CancelOrder(&ctx, req, &resp);
        if (!status.ok()) {
            BfError("(%s)->CancelOrder,code:%d,msg:%s", qPrintable(gatewayId_), status.error_code(), status.error_message().c_str());
        }
    }

    void QueryAccount(const BfVoid& req, BfVoid& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->QueryAccount(&ctx, req, &resp);
        if (!status.ok()) {
            BfError("(%s)->QueryAccount,code:%d,msg:%s", qPrintable(gatewayId_), status.error_code(), status.error_message().c_str());
        }
    }

    void QueryPosition(const BfVoid& req, BfVoid& resp)
    {
        grpc::ClientContext ctx;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::milliseconds(deadline_);
        ctx.set_deadline(deadline);
        ctx.AddMetadata("clientid", req_.clientid());

        grpc::Status status = stub_->QueryPosition(&ctx, req, &resp);
        if (!status.ok()) {
            BfError("(%s)->QueryPosition,code:%d,msg:%s", qPrintable(gatewayId_), status.error_code(), status.error_message().c_str());
        }
    }

private:
    std::unique_ptr<BfGatewayService::Stub> stub_;
    int pingfail_count_ = 0;
    const int deadline_ = 500;
    QString gatewayId_;
    BfConnectReq req_;
};

//
// GatewayMgr
//
GatewayMgr::GatewayMgr(QObject* parent)
    : QObject(parent)
{
}

void GatewayMgr::init()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);

    // qRegisterMetaType
    qRegisterMetaType<BfAccountData>("BfAccountData");
    qRegisterMetaType<BfPositionData>("BfPositionData");
    qRegisterMetaType<BfOrderData>("BfOrderData");
    qRegisterMetaType<BfTradeData>("BfTradeData");
    qRegisterMetaType<BfSendOrderReq>("BfSendOrderReq");
    qRegisterMetaType<BfCancelOrderReq>("BfCancelOrderReq");
    qRegisterMetaType<BfConnectReq>("BfConnectReq");

    qRegisterMetaType<BfErrorData>("BfErrorData");
    qRegisterMetaType<BfLogData>("BfLogData");

    qRegisterMetaType<BfGetContractReq>("BfGetContractReq");
    qRegisterMetaType<BfContractData>("BfContractData");

    // start timer
    this->pingTimer_ = new QTimer(this);
    this->pingTimer_->setInterval(5 * 1000);
    QObject::connect(this->pingTimer_, &QTimer::timeout, this, &GatewayMgr::onPing);
    this->pingTimer_->start();
}

void GatewayMgr::shutdown()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);

    // close timer
    this->pingTimer_->stop();
    delete this->pingTimer_;
    this->pingTimer_ = nullptr;

    // stop proxy
    stopProxy();
}

void GatewayMgr::startProxy()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);

    if (proxyThread_ == nullptr) {
        proxyThread_ = new QThread();
        QObject::connect(proxyThread_, &QThread::started, this, &GatewayMgr::onProxyThreadStarted, Qt::DirectConnection);
        proxyThread_->start();
    }
}

void GatewayMgr::stopProxy()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);

    if (proxyThread_ != nullptr) {
        grpcServer_->Shutdown();
        grpcServer_ = nullptr;

        proxyThread_->quit();
        proxyThread_->wait();
        delete proxyThread_;
        proxyThread_ = nullptr;

        QMetaObject::invokeMethod(g_sm->gatewayMgr(), "onProxyClosed", Qt::QueuedConnection);
    }
}

void GatewayMgr::onProxyThreadStarted()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::EXTERNAL);

    std::string server_address("0.0.0.0:50053");
    Proxy proxy;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&proxy);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    BfInfo(QString("proxy listening on ") + server_address.c_str());
    grpcServer_ = server.get();

    server->Wait();
    BfInfo(QString("proxy shutdown"));
}

void GatewayMgr::connectGateway(QString gatewayId, QString endpoint, const BfConnectReq& req)
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);
    QMutexLocker lock(&clients_mutex_);

    // gatewayclient
    GatewayClient* client = new GatewayClient(grpc::CreateChannel(endpoint.toStdString(), grpc::InsecureChannelCredentials()),
        gatewayId, req);

    // cache
    if (clients_.contains(gatewayId)) {
        auto it = clients_[gatewayId];
        delete it;
        clients_.remove(gatewayId);
    }
    clients_[gatewayId] = client;

    // connecct
    BfConnectResp resp;
    client->Connect(req, resp);
    BfDebug("connect:%s,code:%d,msg:(%s)", qPrintable(gatewayId), resp.errorcode(), resp.errormsg().c_str());
}

void GatewayMgr::disconnectGateway(QString gatewayId)
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);
    QMutexLocker lock(&clients_mutex_);

    if (clients_.contains(gatewayId)) {
        BfDebug("delete gatewayclient:%s", qPrintable(gatewayId));
        GatewayClient* client = clients_[gatewayId];

        // disconnect
        BfVoid req, resp;
        client->Disconnect(req, resp);

        // free
        delete client;
        clients_.remove(gatewayId);
    }
}

void GatewayMgr::onProxyClosed()
{
    BfDebug(__FUNCTION__);
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);
    QMutexLocker lock(&clients_mutex_);

    for (auto client : clients_) {
        // disconnect
        BfVoid req, resp;
        client->Disconnect(req, resp);

        // free
        delete client;
    }
    clients_.clear();
}

void GatewayMgr::onPing()
{
    g_sm->checkCurrentOn(ServiceMgr::LOGIC);
    QMutexLocker lock(&clients_mutex_);

    BfPingData req, resp;
    req.set_message("cta");
    for (auto client : clients_) {
        client->Ping(req, resp);
    }
}

void GatewayMgr::getContract(QString gatewayId, const BfGetContractReq& req, BfContractData& resp)
{
    g_sm->checkCurrentOn(ServiceMgr::EXTERNAL);
    QMutexLocker lock(&clients_mutex_);

    auto client = clients_.value(gatewayId, nullptr);
    if (client != nullptr) {
        client->GetContract(req, resp);
    }
}

void GatewayMgr::sendOrder(QString gatewayId, const BfSendOrderReq& req, BfSendOrderResp& resp)
{
    g_sm->checkCurrentOn(ServiceMgr::EXTERNAL);
    QMutexLocker lock(&clients_mutex_);

    auto client = clients_.value(gatewayId, nullptr);
    if (client != nullptr) {
        client->SendOrder(req, resp);
    }
}

void GatewayMgr::cancelOrder(QString gatewayId, const BfCancelOrderReq& req)
{
    if (!g_sm->isCurrentOn(ServiceMgr::LOGIC)) {
        g_sm->checkCurrentOn(ServiceMgr::EXTERNAL);
    }
    QMutexLocker lock(&clients_mutex_);

    BfVoid resp;
    auto client = clients_.value(gatewayId, nullptr);
    if (client != nullptr) {
        client->CancelOrder(req, resp);
    }
}

void GatewayMgr::queryAccount(QString gatewayId)
{
    if (!g_sm->isCurrentOn(ServiceMgr::LOGIC)) {
        g_sm->checkCurrentOn(ServiceMgr::EXTERNAL);
    }
    QMutexLocker lock(&clients_mutex_);

    BfVoid req, resp;
    auto client = clients_.value(gatewayId, nullptr);
    if (client != nullptr) {
        client->QueryAccount(req, resp);
    }
}

void GatewayMgr::queryPosition(QString gatewayId)
{
    if (!g_sm->isCurrentOn(ServiceMgr::LOGIC)) {
        g_sm->checkCurrentOn(ServiceMgr::EXTERNAL);
    }
    QMutexLocker lock(&clients_mutex_);

    BfVoid req, resp;
    auto client = clients_.value(gatewayId, nullptr);
    if (client != nullptr) {
        client->QueryPosition(req, resp);
    }
}
