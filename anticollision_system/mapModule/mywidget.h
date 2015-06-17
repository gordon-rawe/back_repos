#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "maplayer.h"
#include <QTimer>
#include <QFile>
#include <QGraphicsEllipseItem>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

signals:
    void goToPage(int);

public slots:
    void zoomSlot(int value);
    void changePosition();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget *ui;
    void setGUI();
    MapLayer *map;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *self;
    qreal zoom;

    void setUpParameters();
    void setUpConnections();
    void lookAt(QPointF);

    QList<QPointF> getCoordinates();

    QFile *file;
    QList<QPointF> track;
};

#endif // MYWIDGET_H
