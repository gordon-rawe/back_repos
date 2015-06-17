#ifndef GPSMODULE_H
#define GPSMODULE_H

#include <QObject>
#include "serialhelper.h"

class MainWindow;

class GPSModule : public QObject,public SerialHelper
{
    Q_OBJECT
public:
    explicit GPSModule(QObject *parent = 0,QString target = "/dev/ttyUSB1");
    void setFather(MainWindow *father);

signals:
    
public slots:
    void readyRead();

private:
    MainWindow *father;

    void initConnections();
};

#endif // GPSMODULE_H
