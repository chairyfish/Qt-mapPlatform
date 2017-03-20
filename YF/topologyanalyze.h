#ifndef TOPOLOGYANALYZE_H
#define TOPOLOGYANALYZE_H
#include"sortandjsonconvert.h"
#include"yfmysql.h"
#include"yfprojection.h"
////////////////////////////////////////////////////////////////////
#include<QVector>
#include<QPointF>
#include"qlinestring.h"
#include<QPolygonF>
/////////////////////////////////////////////////////////////
QPolygon GetIntersected(QPolygon poly1,QPolygon poly2);//多边形相交函数
QPolygon GetSubtracted(QPolygon poly1,QPolygon poly2);//多边形相减函数，poly1-poly2
QPolygon GetUnited(QPolygon poly1,QPolygon poly2);//多边形求并函数

#endif // TOPOLOGYANALYZE_H
