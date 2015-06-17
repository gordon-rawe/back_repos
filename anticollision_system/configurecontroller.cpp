#include "configurecontroller.h"
#include "mainwindow.h"

ConfigureController::ConfigureController(QObject *parent) :
    QObject(parent)
{
//    result << "hello" << "world" << "baby";
    listPorts();
    config.BaudRate = BAUD9600;
    config.DataBits = DATA_8;
    config.FlowControl = FLOW_OFF;
    config.StopBits = STOP_1;
    config.Parity = PAR_NONE;
}

ConfigureController::~ConfigureController()
{

}

//void ConfigureController::setResult(QVariantList str)
//{
//    result = str;
//    emit onResultChanged();
//}

QVariantList ConfigureController::getPortNames()
{
    return this->result;
}

void ConfigureController::setSerialPort(QString target, QString paras)
{
    QStringList list = paras.split("#");
    QString portname = list.at(0);
    QString baudrate =list.at(1);
    QString databits = list.at(2);
    QString parity = list.at(3);
    QString stopbits = list.at(4);

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

    emit onPortSettingChanged(portname,target,config);
}

void ConfigureController::listPorts()
{
    foreach(QextPortInfo info,QextSerialEnumerator::getPorts()){
        result << info.portName;
    }
}
