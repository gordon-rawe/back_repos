#include "maplayer.h"

MapLayer::MapLayer()
{
    /*
        QPointF(118.804, 32.0806)
        QPointF(118.639, 32.1683)
    */


//    //左上角
//    x1 = 118.804;
//    y1 = 32.0806;
//    //右下角
//    x2 = 118.639;
//    y2 = 32.1683;
    x1 = 118.61;
    y1 = 31.9174;
    x2 = 118.98;
    y2 = 32.178;

    proportion = (x2-x1)/(y2-y1);

    //屏幕参数
    this->w = 800;
    this->h = 800/proportion;

    //计算参数
    wx = x2-x1;
    hy = y2-y1;
}

QPointF MapLayer::coordToMap(double x, double y)
{
    QPointF point;
    point = QPointF(((x-x1)/wx)*w-w/2,-(((y-y1)/hy)*h-h/2));
    return point;
}

void MapLayer::generatePointLayer(mitab_feature feature,QStringList &fields)
{
    qDebug() << "drawing Point";
    QList<QPointF*> coordinates;
    int penColor, penPattern, penWidth, brushColor, brushPattern;//对于点是有画刷的

    penColor = mitab_c_get_pen_color(feature);
    penPattern = mitab_c_get_pen_pattern(feature);
    penWidth = mitab_c_get_pen_width(feature);
    brushColor = mitab_c_get_brush_bgcolor(feature);
    brushPattern = mitab_c_get_brush_pattern(feature);

    for(int x = 0; x < mitab_c_get_parts(feature); ++ x){
        for(int y = 0; y < mitab_c_get_vertex_count(feature,x); ++y){
            QPointF *newPoint = new QPointF;
            newPoint->setX(mitab_c_get_vertex_x(feature,x,y));
            newPoint->setY(mitab_c_get_vertex_y(feature,x,y));
            *newPoint = coordToMap(newPoint->x(),newPoint->y());
            coordinates.append(newPoint);
        }
    }
    //对于点就没有分区域什么的说法了
    foreach (QPointF *var, coordinates) {
        MapPoint *temporaryPoint = new MapPoint;
        temporaryPoint->dot.setCenter(var->x(),var->y());
        temporaryPoint->dot.setColor(penColor);
        points.append(temporaryPoint);
    }
}

void MapLayer::generateLinesLayer(mitab_feature feature, QStringList &fields)
{
    qDebug() << "drawing Lines";
    QList<QPointF*> coordinates;
    int penColor, penPattern, penWidth;//对于线没有画刷

    penColor = mitab_c_get_pen_color(feature);
    penPattern = mitab_c_get_pen_pattern(feature);
    penWidth = mitab_c_get_pen_width(feature);

    QPen pen;
    pen.setColor(QColor(penColor));
    pen.setWidth(penWidth/3);//把线宽将为1/3
    if(penPattern==2) pen.setStyle(Qt::SolidLine); else pen.setStyle(Qt::DashLine);

    for(int x = 0; x < mitab_c_get_parts(feature); x++){
        //其实对于lines的话这个parts永远是一,每次读的都是一条线
        for(int y = 0; y < mitab_c_get_vertex_count(feature,x); y++){
            QPointF *newPoint = new QPointF;
            newPoint->setX(mitab_c_get_vertex_x(feature,x,y));
            newPoint->setY(mitab_c_get_vertex_y(feature,x,y));
//            qDebug() << newPoint->x() << newPoint->y();
            *newPoint = coordToMap(newPoint->x(),newPoint->y());
            coordinates.append(newPoint);
            qDebug() << newPoint->x() << newPoint->y();
        }
    }

    MapCurveline *curve = new MapCurveline;
    for(int index = 0; index < coordinates.count() - 1; index++){
        QGraphicsLineItem *line = new QGraphicsLineItem;
        line->setPen(pen);
//        line->setLine(QLineF(coordinates.at(index)->x(),coordinates.at(index)->y(),coordinates.at(index+1)->x(),coordinates.at(index+1)->y()));
        line->setLine(QLineF(*coordinates.at(index),*coordinates.at(index+1)));
        curve->curve.append(line);
//        qDebug() << *coordinates.at(index);
    }
    lines.append(curve);
}

void MapLayer::generateRegionLayer(mitab_feature feature, QStringList &fields)
{
    qDebug() << "drawing Regions";
    QList<QPointF*> coordinates;
    int penColor, penPattern, penWidth, brushColor, brushPattern;//对于区域是有画刷的

    penColor = mitab_c_get_pen_color(feature);
    penPattern = mitab_c_get_pen_pattern(feature);
    penWidth = mitab_c_get_pen_width(feature);
    brushColor = mitab_c_get_brush_bgcolor(feature);
    brushPattern = mitab_c_get_brush_pattern(feature);

    QPen pen;
    QBrush brush;
    pen.setColor(QColor(penColor));
    pen.setWidth(penWidth);
    if(penPattern==2) pen.setStyle(Qt::SolidLine); else pen.setStyle(Qt::DashLine);
    brush.setColor(QColor(brushColor));

    for(int x = 0; x < mitab_c_get_parts(feature); x++){
        for(int y = 0; y < mitab_c_get_vertex_count(feature,x); y++){
            QPointF *newPoint = new QPointF;
            newPoint->setX(mitab_c_get_vertex_x(feature,x,y));
            newPoint->setY(mitab_c_get_vertex_y(feature,x,y));
            *newPoint = coordToMap(newPoint->x(),newPoint->y());
            coordinates.append(newPoint);
        }
    }
    MapArea *area = new MapArea;
    QPolygonF *poly = new QPolygonF;
    foreach (QPointF *var, coordinates) {
        poly->append(QPointF(var->x(),var->y()));
    }

    //设置画笔和花刷

    area->area.setPolygon(*poly);
    area->area.setBrush(brush);
    area->area.setPen(pen);
    areas.append(area);
}

void MapLayer::generateLayer(QString layerName)
{
    mitab_handle handle;
    mitab_feature feature;
    int featureId, fieldCount, featureCount, featureType;
    QStringList fieldNames;
    qDebug() << layerName;
    handle = mitab_c_open(layerName.toAscii().data());
    if(handle)  qDebug() << "open success!"; else {
        qDebug() << "fail to open layer!";  return;
    }
    featureCount = mitab_c_get_feature_count(handle);
    fieldCount = mitab_c_get_field_count(handle);
    for (int var = 0; var < fieldCount; ++var) {
        fieldNames.append(mitab_c_get_field_name(handle,var));
    }

    for( featureId = mitab_c_next_feature_id(handle,-1);featureId != -1;
         featureId = mitab_c_next_feature_id(handle,featureId) ){
        feature = mitab_c_read_feature(handle,featureId);
        featureType = mitab_c_get_type(feature);
        switch (featureType) {
        /*
            #define TABFC_Point     1
            #define TABFC_FontPoint 2
            #define TABFC_CustomPoint 3
            #define TABFC_Text      4
            #define TABFC_Polyline  5
            #define TABFC_Arc       6
            #define TABFC_Region    7
            #define TABFC_Rectangle 8
            #define TABFC_Ellipse   9
            在这里只考虑了1,5,7三种能够绘制的图像,因为其他的我们的图层里面没有
        */
        case TABFC_Point:
            generatePointLayer(feature,fieldNames);
            break;
        case TABFC_Polyline:
            generateLinesLayer(feature,fieldNames);
            break;
        case TABFC_Region:
            generateRegionLayer(feature,fieldNames);
            break;
        default:
            //其他的我们什么也不做
            break;
        }
        mitab_c_destroy_feature(feature);
    }
    mitab_c_close(handle);
}

void MapLayer::beginDrawOnCanvas(QGraphicsScene *scene)
{
    this->scene = scene;
    generateLayer("mapModule/map/Road.mif");
    drawLayer();
}

double MapLayer::getProportion()
{
    return this->proportion;
}

void MapLayer::drawLayer()
{
    //draw areas
    foreach (MapArea *area, this->areas) {
        //do something
        scene->addItem(&area->area);
    }

    //draw lines
    foreach (MapCurveline* line, this->lines) {
        //do something
        foreach (QGraphicsLineItem *x, line->curve) {
            scene->addItem(x);
        }
    }

    //draw points
    foreach (MapPoint *point, this->points) {
        //do something
        scene->addItem(&point->dot);
    }
}
