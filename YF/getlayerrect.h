#ifndef GETLAYERRECT_H
#define GETLAYERRECT_H
#include <QObject>
#include <QWidget>
#include"getspatialdata.h"
#include"yflayer.h"
#include"yfmysql.h"
#include<QString>
#include<QRectF>
QRectF GetPointLayerRect(QVector<QPointF> points);
QRectF GetLineLayerRect(QVector<QLineStringF> lines);
QRectF GetPolyLayerRect(QVector<QPolygonF> polys);
#endif // GETLAYERRECT_H
