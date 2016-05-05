#include "mainwindow.h"
#include "debug_utils.h"
#include "debugform.h"
#include "errorform.h"
#include "gatewaymgr.h"
#include "infoform.h"
#include "logger.h"
#include "positionform.h"
#include "profile.h"
#include "pushservice.h"
#include "robotform.h"
#include "rpcservice.h"
#include "servicemgr.h"
#include "tablewidget_helper.h"
#include "ui_mainwindow.h"
#include "workingorderform.h"

#include <windows.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(Profile::appName());
    icon_ = QIcon(":/images/cta.png");
    setWindowIcon(icon_);

    //设置trayicon
    this->createActions();
    this->createTrayIcon();

    // actions
    ui->actionCtpConnect->setEnabled(true);
    ui->actionCtpDisconnect->setEnabled(false);

    ui->actionNetStart->setEnabled(true);
    ui->actionNetStop->setEnabled(false);

    // tabs
    infoForm_ = new InfoForm(this);
    errorForm_ = new ErrorForm(this);
    debugForm_ = new DebugForm(this);
    robotForm_ = new RobotForm(this);
    positionForm_ = new PositionForm(this);
    workingOrderForm_ = new WorkingOrderForm(this);

    ui->tabWidgetRobot->addTab(robotForm_, "robot");
    ui->tabWidgetPosition->addTab(positionForm_, "position");
    ui->tabWidgetOrder->addTab(workingOrderForm_, "workingOrder");
    ui->tabWidgetLog->addTab(infoForm_, "info");
    ui->tabWidgetLog->addTab(errorForm_, "error");
    ui->tabWidgetLog->addTab(debugForm_, "debug");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    infoForm_->init();
    errorForm_->init();
    debugForm_->init();
    robotForm_->init();
    positionForm_->init();
    workingOrderForm_->init();
}

void MainWindow::shutdown()
{
    infoForm_->shutdown();
    errorForm_->shutdown();
    debugForm_->shutdown();
    robotForm_->shutdown();
    positionForm_->shutdown();
    workingOrderForm_->shutdown();
}

void MainWindow::on_actionAppVersion_triggered()
{
    BfError(QString("application's buildtime<error>: ") + QString(__DATE__) + " " + QString(__TIME__));
    BfInfo(QString("application's buildtime<info>: ") + QString(__DATE__) + " " + QString(__TIME__));
    BfDebug(QString("application's buildtime<debug>: ") + QString(__DATE__) + " " + QString(__TIME__));
}

void MainWindow::on_actionAppQuit_triggered()
{
    Logger::stopExitMonitor();
    qApp->quit();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    this->hide();
    event->ignore();
}

void MainWindow::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(on_actionAppQuit_triggered()));
}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(icon_);
    trayIcon->setToolTip(Profile::appName());

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(onTrayIconActivated(QSystemTrayIcon::ActivationReason)));

    trayIcon->setVisible(true);
    trayIcon->show();
}

void MainWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        if (!this->isVisible())
            this->showNormal();
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:;
    }
}

Profile* MainWindow::profile()
{
    return g_sm->profile();
}

void MainWindow::on_actionCrashInvalidParamCrash_triggered()
{
    //InvalidParamCrash
    printf(nullptr);
}

void MainWindow::on_actionCrashPureCallCrash_triggered()
{
    //PureCallCrash
    base::debug::Derived derived;
    base::debug::Alias(&derived);
}

void MainWindow::on_actionCrashDerefZeroCrash_triggered()
{
    //DerefZeroCrash
    int* x = 0;
    *x = 1;
    base::debug::Alias(x);
}

void MainWindow::on_actionCrashQFatal_triggered()
{
    qFatal("crash for qFatal");
}

void MainWindow::on_actionCrashdebugbreak_triggered()
{
    __debugbreak();
}

void MainWindow::on_actionCrashDebugBreak_triggered()
{
    DebugBreak();
}

void MainWindow::on_actionCrashExit_triggered()
{
    exit(1);
}

void MainWindow::on_actionCrashExitProcess_triggered()
{
    ::ExitProcess(1);
}

void MainWindow::on_actionCrashTerminateProcess_triggered()
{
    ::TerminateProcess(::GetCurrentProcess(), 1);
}

void MainWindow::on_actionCtpConnect_triggered()
{
    ui->actionCtpConnect->setEnabled(false);
    ui->actionCtpDisconnect->setEnabled(true);

    QString gatewayId = "ctpgateway";
    QString endpoint = "localhost:50051";
    BfConnectReq req;
    req.set_clientid("cta");
    req.set_clientip("localhost");
    req.set_clientport(50053);
    QMetaObject::invokeMethod(g_sm->gatewayMgr(), "connectGateway", Qt::QueuedConnection, Q_ARG(QString, gatewayId), Q_ARG(QString, endpoint), Q_ARG(BfConnectReq, req));
}

void MainWindow::on_actionCtpDisconnect_triggered()
{
    ui->actionCtpConnect->setEnabled(true);
    ui->actionCtpDisconnect->setEnabled(false);

    QString gatewayId = "ctpgateway";
    QMetaObject::invokeMethod(g_sm->gatewayMgr(), "disconnectGateway", Qt::QueuedConnection, Q_ARG(QString, gatewayId));
}

void MainWindow::on_actionNetStart_triggered()
{
    ui->actionNetStart->setEnabled(false);
    ui->actionNetStop->setEnabled(true);
    QMetaObject::invokeMethod(g_sm->rpcService(), "start", Qt::QueuedConnection);
    QMetaObject::invokeMethod(g_sm->gatewayMgr(), "startProxy", Qt::QueuedConnection);
}

void MainWindow::on_actionNetStop_triggered()
{
    ui->actionNetStart->setEnabled(true);
    ui->actionNetStop->setEnabled(false);
    QMetaObject::invokeMethod(g_sm->rpcService(), "stop", Qt::QueuedConnection);
    QMetaObject::invokeMethod(g_sm->gatewayMgr(), "stopProxy", Qt::QueuedConnection);
}

void MainWindow::on_actionStopAutoTrading_triggered()
{
    QMetaObject::invokeMethod(g_sm->pushService(), "onAutoTradingStop", Qt::QueuedConnection);
}

void MainWindow::on_actionStartAutoTrading_triggered()
{
    QMetaObject::invokeMethod(g_sm->pushService(), "onAutoTradingStart", Qt::QueuedConnection);
}

void MainWindow::on_actionShowRobotOrder_triggered()
{
}

void MainWindow::on_actionShowRobotTrade_triggered()
{
}

void MainWindow::on_actionAddRobot_triggered()
{
}

void MainWindow::on_actionDeleteRobot_triggered()
{
}
