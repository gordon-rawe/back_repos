#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initializeParameters();
    initializeUI();
    initializeModules();
    initializeConnections();
    initializeComponents();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initializeModules()
{

}

void MainWindow::initializeParameters()
{

}

void MainWindow::initializeConnections()
{
    QTimer *timer = new QTimer;
    timer->setInterval(1000);
}

void MainWindow::initializeUI()
{
    stackedWidget = new QStackedWidget(this);
    view = new QDeclarativeView;
    view->setSource(QUrl::fromLocalFile("frontEnd/radar/main.qml"));
    view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view->setRenderHints(QPainter::Antialiasing);
    view->setRenderHints(QPainter::SmoothPixmapTransform);
    setFixedSize(640,480);
    setCentralWidget(view);
    displayAtCenter();
}

void MainWindow::initializeComponents()
{
    gps = new GPSModule(this,"/dev/ttyUSB0");
    wireless = new WirelessModule(this,"/dev/ttyUSB1");
    wireless->setFather(this);
}

void MainWindow::displayAtCenter()
{
    setGeometry(qApp->desktop()->width()/2-width()/2,
                qApp->desktop()->height()/2-height()/2,
                width(),height());
}

QString MainWindow::getNeighbourStatus()
{
    //    QString ret = "";
    //    foreach (Vehicle v, *others) {
    //        ret += v.name + "#" + QString::number(v.longitude)
    //                + "#" + QString::number(v.latitude) + "#" + QString::number(v.speed) + "#" + QString::number(v.direction) + "@";
    //    }
    return "xxx";//ret.left(ret.count()-1);
}

void MainWindow::clearOthersStack()
{
    this->others->clear();
}
