#ifndef YFLAYER_H
#define YFLAYER_H
#include<QPointF>
#include<QPolygonF>
#include"qlinestringf.h"
//点图层类
class YFPointLayer
{
public:
    YFPointLayer();
    QString layername;
    QVector<QPointF> pointsdata;
};
//线图层类
class YFLineLayer
{
public:
    YFLineLayer();
    QString layername;
    QVector<QLineStringF> linesdata;
};
//Layer Of Polygon
class YFPolyLayer
{
public:
    YFPolyLayer();
    QString layername;
    QVector<QPolygonF> polysdata;
};
#endif // YFLAYER_H
