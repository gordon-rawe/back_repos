#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initializeParameters();
    initializeUI();
    initializeModules();
    initializeConnections();
    registerSons();
//    startSons();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setSpeed(float speed)
{
    this->speed = speed;
}

void MainWindow::setDirection(float direction)
{
    this->direction = direction;
}

void MainWindow::setLongitude(float longitude)
{
    this->longitude = longitude;
}

void MainWindow::setLatitude(float latitude)
{
    this->latitude = latitude;
}

void MainWindow::setName(float name)
{
    this->name = name;
}



void MainWindow::initializeModules()
{
    gps = new GlobalPositionModule;
    zigbee = new ZigbeeModule;
    //    controller = new ConfigureController(this);
}

void MainWindow::initializeParameters()
{
    safe = 100;
    neighbourCount = 1;
    zigbeeSignal=40;
    gpsSignal=80;
    nanoTrackSignal=74;
    nearestDistance = 0.0;
    direction = 0;
    speed  = longitude = latitude = 0.0f;
    name = "No.1";
    safeLevel = "Safe";
    others = new QList<Vehicle>;
}

void MainWindow::initializeConnections()
{
    QTimer *timer = new QTimer;
    timer->setInterval(500);
    connect(timer,SIGNAL(timeout()),this,SLOT(report()));
    connect(timer,SIGNAL(timeout()),this,SLOT(simulator()));
    timer->start();

    connect(controller,SIGNAL(onPortSettingChanged(QString,QString,PortSettings)),
            zigbee,SLOT(changePortSetting(QString,QString,PortSettings)));
    connect(controller,SIGNAL(onPortSettingChanged(QString,QString,PortSettings)),
            gps,SLOT(changePortSetting(QString,QString,PortSettings)));

    connect(mapWidget,SIGNAL(goToPage(int)),this,SLOT(goToPage(int)));
}

void MainWindow::initializeUI()
{
    stackedWidget = new QStackedWidget(this);
    mapWidget = new MyWidget(this);
    view = new QDeclarativeView;
    controller = new ConfigureController(this);
    exposeToQml();
    view->setSource(QUrl::fromLocalFile("ui/view.qml"));
    view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view->setRenderHints(QPainter::Antialiasing);
    view->setRenderHints(QPainter::SmoothPixmapTransform);
    stackedWidget->addWidget(view);
    stackedWidget->addWidget(mapWidget);
//    stackedWidget->setCurrentIndex(1);
    setCentralWidget(stackedWidget);
    setFixedSize(view->width(),view->height());
    displayAtCenter();


    //write a function to exchange between pages

}

void MainWindow::registerSons()
{
    gps->setFather(this);
    threads.append(gps);
    zigbee->setFather(this);
    threads.append(zigbee);
}

void MainWindow::startSons()
{
    QThread *t;
    foreach(t,threads){
        t->start();
    }
}

void MainWindow::displayAtCenter()
{
    setGeometry(qApp->desktop()->width()/2-width()/2,
                qApp->desktop()->height()/2-height()/2,
                width(),height());
}

void MainWindow::exposeToQml()
{
    view->rootContext()->setContextProperty("core",this);
    view->rootContext()->setContextProperty("controller",controller);
}

void MainWindow::simulator()
{
    this->name = "No.1";
    this->direction = qrand()%100;
    this->safe = qrand()%100;
    this->neighbourCount = qrand()%100;
    this->zigbeeSignal = 40+qrand()%20;
    this->gpsSignal = 40+qrand()%20;
    this->nanoTrackSignal = 40+qrand()%20;
    this->nearestDistance = qrand()%100;
    this->direction = -80 + qrand()%160;
    this->speed  =  qrand()%100;
    this->longitude = qrand()%100;
    this->latitude = qrand()%100;
}

void MainWindow::goToPage(int index)
{
    stackedWidget->setCurrentIndex(index);
}

QString MainWindow::getName()
{
    return this->name;
}

QString MainWindow::getSafeLevel()
{
    return safeLevel;
}

float MainWindow::getSpeed()
{
    return this->speed;
}

int MainWindow::getNeighbourCount()
{
    return this->neighbourCount;
}

float MainWindow::getNearestDistance()
{
    return this->nearestDistance;
}

void MainWindow::clearNeighbourStack()
{
    this->others->clear();
}

void MainWindow::pushOneVehicle(Vehicle v)
{
    this->others->push_back(v);
}

void MainWindow::report()
{
    qDebug() << this->longitude << "\t" << this->latitude << this->direction;
}

float MainWindow::getLatitude()
{
    return this->latitude;
}

float MainWindow::getLongitude()
{
    return this->longitude;
}

int MainWindow::getDirection()
{
    return this->direction;
}

int MainWindow::getNanoTrackSignal()
{
    return this->nanoTrackSignal;
}

//void MainWindow::changeToPage(int index)
//{
//    stackedWidget->setCurrentIndex(index);
//}

int MainWindow::getGpsSignal()
{
    return this->gpsSignal;
}

int MainWindow::getSafe()
{
    return this->safe;
}

int MainWindow::getZigbeeSignal()
{
    return this->zigbeeSignal;
}
