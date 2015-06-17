#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QStackedWidget>
#include <QtCore>
#include <QtDeclarative/QtDeclarative>
#include <modules/globalpositionmodule.h>
#include <modules/zigbeemodule.h>
#include <configurecontroller.h>
#include "mywidget.h"

class Vehicle
{
    QString name;
    float speed,direction,longitude,latitude;
public:
    Vehicle(){
        speed = direction = longitude = latitude = 0.0f;
        name = "";
    }

    Vehicle(QString name,float speed,float direction,float longitude,float latitude){
        this->name = name;
        this->speed = speed;
        this->direction = direction;
        this->longitude = longitude;
        this->latitude = latitude;
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //properties
    void setSpeed(float);
    void setDirection(float);
    void setLongitude(float);
    void setLatitude(float);
    void setName(float);


    Q_INVOKABLE float getSpeed();
    Q_INVOKABLE int getDirection();
    Q_INVOKABLE float getLongitude();
    Q_INVOKABLE float getLatitude();
    Q_INVOKABLE QString getName();
    Q_INVOKABLE QString getSafeLevel();
    Q_INVOKABLE int getNeighbourCount();
    Q_INVOKABLE float getNearestDistance();
    Q_INVOKABLE int getZigbeeSignal();
    Q_INVOKABLE int getGpsSignal();
    Q_INVOKABLE int getSafe();
    Q_INVOKABLE int getNanoTrackSignal();

//    Q_INVOKABLE void changeToPage(int);

    /*
    property string safeLevel: "Safe"
    property int speed: 0
    property int direction: 0
    property double latitude: 0.0
    property double longitude: 0.0
    property int neighbourCount: 10
    property double nearestDistance:101.10
    property int zigbeeSignal: 0
    property int gpsSignal: 0
    property int nanoTrackSignal: 0
    */
    void clearNeighbourStack();
    void pushOneVehicle(Vehicle v);

public slots:
    void report();
    void simulator();
    Q_INVOKABLE void goToPage(int);

private:

    //properties
    float speed,longitude,latitude,nearestDistance;
    QString name,safeLevel;
    int safe,neighbourCount,zigbeeSignal,gpsSignal,nanoTrackSignal,direction;
    QList<Vehicle> *others;

    //components
    QStackedWidget *stackedWidget;
    MyWidget *mapWidget;
    QDeclarativeView *view;
    QList<QThread *> threads;
    GlobalPositionModule *gps;
    ZigbeeModule *zigbee;
    ConfigureController *controller;


    void initializeModules();
    void initializeParameters();
    void initializeConnections();
    void initializeUI();
    void registerSons();
    void startSons();


    //auxiliary
    void displayAtCenter();
    void exposeToQml();

};

#endif // MAINWINDOW_H
