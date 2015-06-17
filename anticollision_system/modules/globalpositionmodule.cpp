#include "globalpositionmodule.h"
#include "mainwindow.h"

GlobalPositionModule::GlobalPositionModule(QObject *parent) :
    QThread(parent)
{
    flag = true;
    interval = 1000;
    time_wait_to_exit = 1200;
    initializePort();
    connect(serial,SIGNAL(readyRead()),this,SLOT(updateOnce()));
}

GlobalPositionModule::~GlobalPositionModule()
{
    flag = false;
    wait(time_wait_to_exit);
}

void GlobalPositionModule::setFather(MainWindow *father)
{
    this->father = father;
}

void GlobalPositionModule::run()
{
    while(flag){
        sleep(10);
    }
}

void GlobalPositionModule::stops()
{
    flag = false;
}

void GlobalPositionModule::initializePort()
{
    config.BaudRate = BAUD9600;
    config.DataBits = DATA_8;
    config.FlowControl = FLOW_OFF;
    config.StopBits = STOP_1;
    config.Parity = PAR_NONE;
    port_name = "/dev/ttyUSB0";
    serial = new QextSerialPort(port_name,config,QextSerialPort::EventDriven);
    if(serial->open(QIODevice::ReadWrite)) qDebug() << "opened";else    qDebug() << "not opened";
}


void GlobalPositionModule::updateOnce()
{
    char line[100];
    if(serial->canReadLine()){
        serial->readLine(line,100);
        QString result = QString(line).trimmed();
        qDebug() << QString(line);
        QStringList list = result.split(",");
        if(list.at(0)=="$GPRMC"){
            float longitude = list.at(3)==""?0:list.at(3).toFloat();
            float latitude = list.at(5)==""?0:list.at(5).toFloat();
            float speed = list.at(7)==""?0:list.at(7).toFloat();
            float direction = list.at(8)==""?0:list.at(8).toFloat();
            //            if(list.at(0)=="A"){//gurantee the validity
            father->setSpeed(speed);
            father->setLongitude(longitude);
            father->setLatitude(latitude);
            father->setDirection(direction);
            //            }
        }
    }
}

void GlobalPositionModule::changePortSetting(QString name,QString target,PortSettings setting)
{
    if(target == "gps"){
        if(serial->isOpen()) serial->close();
        serial = new QextSerialPort(name,setting,QextSerialPort::EventDriven);
        if(serial->open(QIODevice::ReadWrite))  qDebug()
                << "opened";else   qDebug() << "not opened";
    }
}
