#include "safemodel.h"

SafeModel::SafeModel()
{
    initData();
}

Data* SafeModel::getSelf()
{
    return this->self;
}

QList<Data *>* SafeModel::getOthers()
{
    return this->others;
}

QHash<QString,float> SafeModel::gpsDistances()
{
    QHash<QString,float>  ret;
    foreach(Data* e,*others){
        ret.insert(e->name,sqrt(pow(e->longitude - self->longitude,2)+pow(e->latitude - self->latitude,2)));
    }
    return ret;
}

QHash<QString,float>* SafeModel::getDirectDistances()
{
    return &this->directDistances;
}

void SafeModel::refreshState()
{
    //根据wirelesStack计算各组安全状态resultStack
    foreach (WirelessData* wire, *wirelessStack) {
        ResultNode *t = this->resultStack->value(wire->name);
        if(t==NULL){//新来的
            ResultNode* one = new ResultNode;
            resultStack->insert(wire->name,one);
        }else{
            if(wire->distance_wire > t->last_distance){
                t->trend = Further;
                t->last_distance = wire->distance_wire;
            }else t->trend = Closer;//首先判断trend,bing geng gai
            t->state = calcSafeLevel(v_self,direction_self,wire->speed_wire,wire->direction_wire,wire->distance_wire,wire->track,t->trend);
        }
    }
}

void SafeModel::pushOne(Data* data)
{
    this->others->append(data);
}

State SafeModel::calcSafeLevel(float v1, float angle1, float v2, float angle2, float distance,Track track,Trend trend)
{
    if(track!=self->track || trend==Further) return Safe;//首先判断轨道号和距离趋势
    if(abs(angle1-angle2) < 20){//辆车属于同向，并且后面车的速度大于前面车的速度
        float dis_stop = abs(sqrt(v1)/(2*acceleration)-sqrt(v2)/(2*acceleration))-distance;
        if(dis_stop > 100) return Safe;//当停下来的距离小于5米
        if(dis_stop > 50) return Careful;
        if(dis_stop > 10) return Warning;
        return Dangerous;
    }else if(abs(angle1-angle2) > 160){//两车相向而行
        float dis_stop = sqrt(v1)/(2*acceleration)+sqrt(v2)/(2*acceleration)-distance;
        if(dis_stop > 100) return Safe;//当停下来的距离小于5米
        if(dis_stop > 50) return Careful;
        if(dis_stop > 10) return Warning;
        return Dangerous;
    }
    return Safe;
}

void SafeModel::initData()
{
    gpsStack = new QList<GpsData*>;
    wirelessStack = new QList<WirelessData*>;
    resultStack = new QHash<QString,ResultNode*>;
    acceleration = 1.0;//设置加速度
    gps_self = new GpsData;
    name = "1";
    track = Left;
    v_self = direction_self = 0.0f;
}

void SafeModel::clearStack()
{
    int static count = 0;
    if(count == 3) {
        this->others->clear();
        this->directDistances.clear();
        count = 0;
    }
    count ++;
}

