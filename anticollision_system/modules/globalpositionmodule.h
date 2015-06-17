#ifndef GLOBALPOSITIONMODULE_H
#define GLOBALPOSITIONMODULE_H

#include <QThread>
#include <qextserialenumerator.h>
#include <qextserialport.h>

class MainWindow;

class GlobalPositionModule : public QThread
{
    Q_OBJECT
public:
    explicit GlobalPositionModule(QObject *parent = 0);
    ~GlobalPositionModule();
    void setFather(MainWindow *father);

protected:
    void run();

signals:

private slots:
    void updateOnce();
    void changePortSetting(QString name,QString target,PortSettings setting);

public slots:

    void stops();
private:
//  [resources]
    MainWindow *father;
    bool flag;
    int time_wait_to_exit;
    int interval;
    QextSerialPort *serial;
    QString port_name;
    PortSettings config;
//  [methods]
    void initializePort();
};

#endif // GLOBALPOSITIONMODULE_H
