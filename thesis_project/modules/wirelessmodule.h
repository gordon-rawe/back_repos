#ifndef WIRELESSMODULE_H
#define WIRELESSMODULE_H

/*对于无线模块作出如下假设：
1. 可在1000米内通信
2. 可以在500米内测定两个车辆的距离，具体方式为：本机接受到对方机器的返回值
数据格式如下：name#longitude#latitude#speed#direction#distanceByTime*/

#include <QObject>
#include "serialhelper.h"

class MainWindow;

class WirelessModule : public QObject,public SerialHelper
{
    Q_OBJECT
public:
    explicit WirelessModule(QObject *parent = 0,QString target = "/dev/ttyUSB0");
    void setFather(MainWindow *father);

signals:
    
public slots:
    void readOnce();
    void broadcastOnce();

private:
    MainWindow *father;
    int interval;
    QTimer *timer;

    void initConnections();
    void getDirectDistances();//这个函数用来计算某车距离
};

#endif // WIRELESSMODULE_H
