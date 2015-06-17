#include "speedmodule.h"
#include "mainwindow.h"

SpeedModule::SpeedModule(QObject *parent) :
    QObject(parent)
{
}

void SpeedModule::setFather(MainWindow *father)
{
    this->father = father;
}
