#ifndef SORTANDJSONCONVERT_H
#define SORTANDJSONCONVERT_H
#include <QDebug>
#include <QPoint>
#include <QPointF>
#include <QPolygon>
#include <QPolygonF>
#include "qlinestringf.h"
#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QApplication>
bool YFPointCmp(const QPoint &a,const QPoint &b,const QPoint &center);
bool YFPointCmp(const QPointF &a,const QPointF &b,const QPointF &center);
void YFClockwiseSortPoints(QPolygon &vPoints);
void YFClockwiseSortPoints(QPolygonF &vPoints);
QPointF GeoJSONtoQPointF(QString geojsonpoint);
QLineStringF GeoJSONtoQLineStringF(QString geojsonlinestring);
QPolygonF GeoJSONtoQPolygonF(QString geojsonpolygon);
#endif // SORTANDJSONCONVERT_H
