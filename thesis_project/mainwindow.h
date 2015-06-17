#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QStackedWidget>
#include <QtCore>
#include <QtDeclarative/QtDeclarative>
#include "modules/safemodel.h"
#include <modules/serialhelper.h>
#include <modules/wirelessmodule.h>
#include <modules/gpsmodule.h>

/*
//class Vehicle
//{

//public:
//    QString name;
//    float speed,direction,longitude,latitude;

//    Vehicle(){
//        speed = direction = longitude = latitude = 0.0f;
//        name = "";
//    }

//    Vehicle(QString name,float speed,float direction,float longitude,float latitude){
//        this->name = name;
//        this->speed = speed;
//        this->direction = direction;
//        this->longitude = longitude;
//        this->latitude = latitude;
//    }
//};
*/




class MainWindow : public QMainWindow, public SafeModel
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getNeighbourStatus();

public slots:
    //additional functions
    void clearOthersStack();

private:
    GPSModule *gps;
    WirelessModule *wireless;
    QStackedWidget *stackedWidget;
    QDeclarativeView *view;

    void initializeModules();
    void initializeParameters();
    void initializeConnections();
    void initializeUI();
    void initializeComponents();


    //auxiliary
    void displayAtCenter();

    //additional functions

};

#endif // MAINWINDOW_H
