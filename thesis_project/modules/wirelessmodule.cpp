#include "wirelessmodule.h"
#include "mainwindow.h"

WirelessModule::WirelessModule(QObject *parent,QString target) :
    QObject(parent),SerialHelper(target)
{
    interval = 1000;
    timer = new QTimer(this);
    timer->setInterval(interval);
    initConnections();
    timer->start();
    if(!serial->isOpen()) {
        qDebug() << port_name << serial->open(QIODevice::ReadWrite);
    }
}

void WirelessModule::setFather(MainWindow *father)
{
    this->father = father;
}

void WirelessModule::readOnce()
{
    getDirectDistances();
//    while(serial->atEnd()){//readAll data
//        char line[200];
//        if(serial->canReadLine()){
//            serial->readLine(line,200);
//            QString result = QString(QLatin1String(line));
//            QStringList list = result.split("#");
//            QString name = list.at(0);
//            float longitude = list.at(1).toFloat();
//            float latitude = list.at(2).toFloat();
//            float speed = list.at(3).toFloat();
//            float direction = list.at(4).toFloat();
//            Vehicle v(name,longitude,latitude,speed,direction);
//            this->father->pushOneVehicle(v);
//        }
//    }
    qDebug() << "wireless read once";
}

void WirelessModule::broadcastOnce()
{
//    this->father->clearStack();

//    QString report =father->getName()+"#"+QString::number(father->getLongitude())
//            +"#"+QString::number(father->getLatitude())+"#"+QString::number(father->getSpeed())
//            +"#"+QString::number(father->getDirection())+"\n";
//    qDebug() << report.trimmed();
//    if (serial->isOpen()){
//        serial->write(report.toLatin1());
//        serial->flush();
//    }
//    QString ret = father->getSelf()->name + "#" + QString::number(father->getSelf()->longitude)
//            + "#" + QString::number(father->getSelf()->latitude) + "#" + QString::number(father->getSelf()->speed)
//            + "#" + QString::number(father->getSelf()->direction);// + "#" + QString::number(this->getDirectDistances());

//    qDebug() << ret;
//    qDebug() << father->gpsDistances();
//    qDebug() << *father->getDirectDistances();
}

void WirelessModule::initConnections()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(broadcastOnce()));
    connect(serial,SIGNAL(readyRead()),this,SLOT(readOnce()));
}

void WirelessModule::getDirectDistances()
{
    //manipulate the directDistances
//    this->father->getDirectDistances()->insert("No",109.2);
}
