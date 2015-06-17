#include "gpsmodule.h"
#include "mainwindow.h"

GPSModule::GPSModule(QObject *parent,QString target) :
    QObject(parent), SerialHelper(target)
{
    initConnections();
    if(!serial->isOpen()) {
        qDebug() <<port_name << serial->open(QIODevice::ReadWrite);
    }
}

void GPSModule::setFather(MainWindow *father)
{
    this->father = father;
}

void GPSModule::readyRead()
{
    qDebug() << "gps read once";
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
            //            father->setSpeed(speed);
            //            father->setLongitude(longitude);
            //            father->setLatitude(latitude);
            //            father->setDirection(direction);
            //更新father中的这些数据
            //            }
        }
    }
}

void GPSModule::initConnections()
{
    connect(serial,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

