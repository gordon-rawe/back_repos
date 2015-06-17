#ifndef SERIALHELPER_H
#define SERIALHELPER_H

#include <qextserialenumerator.h>
#include <qextserialport.h>
#include <QtCore>
#include <QtGui>

class SerialHelper
{
public:
    SerialHelper();
    SerialHelper(QString);
    ~SerialHelper();

    QVariantList getPortNames();
    void setSerialPortByString(QString ,QString);
    void initializePort();

protected:
    QVariantList result;
    PortSettings config;
    QextSerialPort *serial;
    QString port_name;
private:
    void listPorts();

};

#endif // SERIALHELPER_H
