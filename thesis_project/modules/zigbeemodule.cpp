#include "zigbeemodule.h"
#include "mainwindow.h"


ZigbeeModule::ZigbeeModule(QObject *parent) :
    QThread(parent)
{
    flag = true;
    interval = 1000;
    time_wait_to_exit = 1200;
    initializePort();
    initializeWorks();
}

ZigbeeModule::~ZigbeeModule()
{
    flag = false;
    wait(time_wait_to_exit);
}

void ZigbeeModule::setFather(MainWindow *father)
{
    this->father = father;
}

void ZigbeeModule::run()
{
    while(flag){
        father->clearNeighbourStack();
        sleep(3);
    }
}

void ZigbeeModule::broadcast()
{
    QString report =father->getName()+"#"+QString::number(father->getLongitude())
            +"#"+QString::number(father->getLatitude())+"#"+QString::number(father->getSpeed())
            +"#"+QString::number(father->getDirection())+"\n";
    qDebug() << report.trimmed();
    if (serial->isOpen()){
        serial->write(report.toLatin1());
        serial->flush();
    }
}

void ZigbeeModule::stops()
{
    flag = false;
}

void ZigbeeModule::changePortSetting(QString name,QString target,PortSettings setting)
{
    if(target == "zigbee"){
        if(serial->isOpen()) serial->close();
        serial = new QextSerialPort(name,setting,QextSerialPort::EventDriven);
        if(serial->open(QIODevice::ReadWrite))  qDebug()
                << "opened";else   qDebug() << "zigbee not opened";
    }
}

void ZigbeeModule::updateInfo()
{
    while(serial->atEnd()){//readAll data
        char line[200];
        if(serial->canReadLine()){
            serial->readLine(line,200);
            QString result = QString(QLatin1String(line));
            QStringList list = result.split("#");
            QString name = list.at(0);
            float longitude = list.at(1).toFloat();
            float latitude = list.at(2).toFloat();
            float speed = list.at(3).toFloat();
            float direction = list.at(4).toFloat();
            Vehicle v(name,longitude,latitude,speed,direction);
            this->father->pushOneVehicle(v);
        }
    }
}

void ZigbeeModule::initializePort()
{
    config.BaudRate = BAUD9600;
    config.DataBits = DATA_8;
    config.FlowControl = FLOW_OFF;
    config.StopBits = STOP_1;
    config.Parity = PAR_NONE;
    port_name = "/dev/ttyUSB1";
    serial = new QextSerialPort(port_name,config,QextSerialPort::EventDriven);
    if(serial->open(QIODevice::ReadWrite))  qDebug()
            << "opened";else   qDebug() << "zigbee not opened";
}

void ZigbeeModule::initializeWorks()
{
    timer = new QTimer;
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(broadcast()));
    timer->start();
}
