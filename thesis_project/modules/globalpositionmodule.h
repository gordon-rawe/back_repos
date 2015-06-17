#ifndef GLOBALPOSITIONMODULE_H
#define GLOBALPOSITIONMODULE_H

#include <QThread>
#include "serialhelper.h"

class MainWindow;

class GlobalPositionModule : public SerialHelper
{
    Q_OBJECT
public:
    GlobalPositionModule();
    ~GlobalPositionModule();
    void setFather(MainWindow *father);

public slots:
    void stops();

private slots:
    void updateOnce();
private:
//  [resources]
    MainWindow *father;
    bool flag;
    int time_wait_to_exit;
    int interval;
//  [methods]
};

#endif // GLOBALPOSITIONMODULE_H
