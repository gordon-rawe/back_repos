#ifndef SAFEMODEL_H
#define SAFEMODEL_H
#include <QtCore>
#include <math.h>
enum Track{
    Left,
    Right
};

enum Trend{
    Closer,
    Further
};

enum State{
    Safe,
    Careful,
    Warning,
    Dangerous
};

struct Data{
    Data(){
        speed = direction = longitude = latitude = 0.0f;
        name = "No1";track = Left;trend = Further;
    }
    QString name;float speed,direction,longitude,latitude;Track track;Trend trend;//这里Trend一开始设置为Further
};

struct GpsData{
    float speed,direction,longitude,latitude;
    GpsData(){
        speed = direction = longitude = latitude = 0.0f;
    }
};

struct WirelessData{
    QString name;float distance_wire,speed_wire,direction_wire;Track track;
    WirelessData(){
        name = "";distance_wire = speed_wire = direction_wire = 0.0f;track = Left;
    }
};

struct ResultNode{Trend trend;float last_distance;State state;
    ResultNode(){
        trend = Closer;last_distance = 10000.0f;state = Safe;//初始设定为10000m
    }
};

class SafeModel
{
public:
    SafeModel();
//------------------------------------------------
    Data* getSelf();
    QList<Data*>* getOthers();//用于返回周边车辆的信息
    QHash<QString,float> gpsDistances();
    QHash<QString,float>* getDirectDistances();

    void clearStack();

public slots:
    void pushOne(Data*);

protected:
    float acceleration;QString name;GpsData *gps_self;Track track;float v_self,direction_self;
    QList<GpsData*>* gpsStack;//用于辅助定位
    QList<WirelessData*>* wirelessStack;//用于储存邻车信息,包括速度，方向等
    QHash<QString,ResultNode*>* resultStack;

    State calcSafeLevel(float v1,float angle1,float v2,float angle2,float distance,Track track,Trend trend);
    void refreshState();//用来刷新状态，比如邻车状态信息
//------------------------------------------------
    Data *self;
    QList<Data*>* others;
    QHash<QString,float> directDistances;

private:
    void initData();
};

#endif // SAFEMODEL_H
