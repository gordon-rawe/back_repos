#ifndef SPEEDMODULE_H
#define SPEEDMODULE_H

#include <QObject>
#include "serialhelper.h"

class MainWindow;

class SpeedModule : public QObject,public SerialHelper
{
    Q_OBJECT
public:
    explicit SpeedModule(QObject *parent = 0);
    void setFather(MainWindow* father);

private:
    MainWindow *father;

signals:
    
public slots:
    
};

#endif // SPEEDMODULE_H
