#ifndef ZIGBEEMODULE_H
#define ZIGBEEMODULE_H

#include <QThread>
#include <qextserialport.h>
#include <qextserialenumerator.h>
#include <QtCore>

class MainWindow;

class ZigbeeModule : public QThread
{
    Q_OBJECT
public:
    explicit ZigbeeModule(QObject *parent = 0);
    ~ZigbeeModule();
    void setFather(MainWindow *father);


protected:
    void run();

signals:

public slots:
    void broadcast();
    void stops();
    void changePortSetting(QString name,QString target,PortSettings);
    void updateInfo();

private:
//[resources]
    bool flag;
    int interval,time_wait_to_exit;
    MainWindow *father;
    QextSerialPort *serial;
    QString port_name;
    PortSettings config;\
    QTimer *timer;
//[methods]
    void initializePort();
    void initializeWorks();
};

#endif // ZIGBEEMODULE_H
