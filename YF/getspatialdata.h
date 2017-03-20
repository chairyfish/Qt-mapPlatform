#ifndef GETSPATIALDATA_H
#define GETSPATIALDATA_H
#include"sortandjsonconvert.h"
#include"yfmysql.h"
#include"yfprojection.h"
////////////////////////////////////////////////////////////////////
#include<QVector>
#include<QPointF>
#include"qlinestringf.h"
#include<QPolygonF>
///////////////////////////////////////////////////////////////////
QVector<QPointF> GetPointFromDatabase(YFMYSQL &sql,QString tablename);
QVector<QLineStringF> GetLineStringFromDatabase(YFMYSQL &sql,QString tablename);
QVector<QPolygonF> GetPolygonFromDatabase(YFMYSQL &sql,QString tablename);
#endif // GETSPATIALDATA_H
