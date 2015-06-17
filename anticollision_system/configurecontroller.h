#ifndef CONFIGURECONTROLLER_H
#define CONFIGURECONTROLLER_H

#include <QObject>
#include <qextserialenumerator.h>
#include <qextserialport.h>
#include <QtCore>
#include <QtGui>

class MainWindow;

class ConfigureController : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QVariantList list READ getResult WRITE setResult NOTIFY onResultChanged)
public:
    explicit ConfigureController(QObject *parent = 0);
    ~ConfigureController();

//    void setResult(QVariantList str);

    Q_INVOKABLE QVariantList getPortNames();
    Q_INVOKABLE void setSerialPort(QString ,QString);
signals:
    void onResultChanged();
    void onPortSettingChanged(QString name,QString target,PortSettings setting);
public slots:


private:
    QVariantList result;
    PortSettings config;
    void listPorts();
};

#endif // CONFIGURECONTROLLER_H
