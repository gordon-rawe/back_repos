#ifndef MAPLAYER_H
#define MAPLAYER_H

#include <QPainter>
#include <QPointF>
#include <QList>
#include "mitab.h"
#include "mitab_capi.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QString>

static int global;

class QGraphicsDotItem : public QGraphicsItem
{
public:
    QGraphicsDotItem(){
        this->radius = 2;
        color = 1232321;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
        QPointF points[4] = {
            QPointF(center.x()-radius,center.y()),
            QPointF(center.x(),center.y()+radius),
            QPointF(center.x()+radius,center.y()),
            QPointF(center.x(),center.y()-radius),
        };
        painter->setPen(Qt::black);
        painter->setBrush(QColor(color));
        painter->drawPolygon(points,4);
    }

    QRectF boundingRect() const{
        return QRectF(-radius,-radius,2*radius,2*radius);
    }

    void setCenter(int x, int y){
        center.setX(x);
        center.setY(y);
    }

    void setColor(int color){
        this->color = color;
    }

private:
    QPointF center;
    int radius;
    int color;
};

struct MapPoint{
    MapPoint(){}
    QString pointName;
    QGraphicsDotItem dot;
};

struct MapCurveline{
    MapCurveline(){}
    QString polyName;
    QList<QGraphicsLineItem *> curve;
};

struct MapArea{
    MapArea(){}
    QString areaName;
    QGraphicsPolygonItem area;
};


class MapLayer
{
public:
    MapLayer();


    void beginDrawOnCanvas(QGraphicsScene *scene);
    double getProportion();
private:
    double x1;//画布左上角代表的经度
    double y1;//画布左上角代表的纬度
    double x2;//画布右下角代表的经度
    double y2;//画布右下角代表的纬度
    double w;//当前显示区域的宽度
    double h;//当前显示区域的高度
    double wx;//当前显示区域经度的范围
    double hy;//当前显示区域纬度的范围
    double proportion;

    QGraphicsScene *scene;


    QList<MapArea *> areas;
    QList<MapCurveline *> lines;
    QList<MapPoint *> points;

    //功能函数
    QPointF coordToMap(double x,double y);//转换函数

    //获取信息函数
    void generatePointLayer(mitab_feature feature,QStringList &fields);
    void generateLinesLayer(mitab_feature feature,QStringList &fields);
    void generateRegionLayer(mitab_feature feature,QStringList &fields);
    void generateLayer(QString);

    //绘图函数
    void drawLayer();
};

#endif // MAPLAYER_H
