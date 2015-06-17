#include "serialhelper.h"

SerialHelper::SerialHelper()
{

}

SerialHelper::SerialHelper(QString target)
{
    listPorts();
    port_name = target;
    config.BaudRate = BAUD9600;
    config.DataBits = DATA_8;
    config.FlowControl = FLOW_OFF;
    config.StopBits = STOP_1;
    config.Parity = PAR_NONE;
    initializePort();
}

SerialHelper::~SerialHelper()
{

}

QVariantList SerialHelper::getPortNames()
{
    return this->result;
}

void SerialHelper::setSerialPortByString(QString target, QString paras)
{
    QStringList list = paras.split("#");
    QString baudrate =list.at(0);
    QString databits = list.at(1);
    QString parity = list.at(2);
    QString stopbits = list.at(3);

    if(baudrate == "1200") config.BaudRate = BAUD1200;
    else if(baudrate == "2400") config.BaudRate = BAUD2400;
    else if(baudrate == "4800") config.BaudRate = BAUD4800;
    else if(baudrate == "9600") config.BaudRate = BAUD9600;
    else if(baudrate == "115200") config.BaudRate = BAUD115200;
    else config.BaudRate = BAUD9600;

    if(stopbits == "1") config.StopBits = STOP_1;
    else if(stopbits == "2") config.StopBits = STOP_2;
    else config.StopBits = STOP_1;

    if(databits == "5") config.DataBits = DATA_5;
    else if(databits == "6") config.DataBits = DATA_6;
    else if(databits == "7") config.DataBits = DATA_7;
    else if(databits == "8") config.DataBits = DATA_8;
    else config.DataBits = DATA_8;

    if(parity == "none") config.Parity = PAR_NONE;
    else if(parity == "even") config.Parity = PAR_EVEN;
    else if(parity == "odd") config.Parity = PAR_ODD;
    else if(parity == "space") config.Parity = PAR_SPACE;
    else config.Parity = PAR_NONE;

    serial = new QextSerialPort(target,config,QextSerialPort::EventDriven);
}

void SerialHelper::initializePort()
{
    serial = new QextSerialPort(port_name ,config,QextSerialPort::EventDriven);
}

void SerialHelper::listPorts()
{
    foreach(QextPortInfo info,QextSerialEnumerator::getPorts()){
        result << info.portName;
    }
}
