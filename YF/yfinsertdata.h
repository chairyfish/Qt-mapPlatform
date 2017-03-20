#ifndef YFINSERTDATA_H
#define YFINSERTDATA_H
#include"sortandjsonconvert.h"
#include"yfmysql.h"
#include"yfprojection.h"
////////////////////////////////////////////////////////////////////
#include<QVector>
#include<QPointF>
#include"qlinestringf.h"
#include<QPolygonF>
///////////////////////////////////////////////////////////////////
void YFInsertPointF(QVector<QPointF> a,YFMYSQL b,QString Tname);
void YFInsertLineStringF(QVector<QLineStringF> a,YFMYSQL b,QString Tname);
void YFInsertPolygonF(QVector<QPolygonF> a,YFMYSQL b,QString Tname); //对数据库进行写入操作，将QPolygonF类型数组a插入数据库，Tname为数据库名+字符串名

#endif // YFINSERTDATA_H
