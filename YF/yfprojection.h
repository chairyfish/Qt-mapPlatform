#ifndef YFPROJECTION_H
#define YFPROJECTION_H

#include <QObject>
#include <QWidget>
#include<QPointF>
#include<QRectF>
#include<QRect>
#include<QVector>
#include<QDebug>
#include<QtAlgorithms>
using namespace std;
    QPointF ScreenToCoor(QPoint coor,QRect rectscr,QRectF rectgeo );
    QPoint CoorToScreen(QPointF screen,QRect rectscr,QRectF rectgeo );
//    QVector<QPoint> MutiCoorToScreen(QVector<QPointF> muticoorpos);
//    QVector<QPointF> MutiScreenToCoor(QVector<QPoint> mutiscrpos);
    QPointF CoorToGauss(double longitude, double latitude);
    QPointF GaussToCoor(double X, double Y);
    QVector<QPointF> MutiCoorToGauss(QVector<QPointF> muticoorpos);
    QVector<QPointF> MutiGaussToCoor(QVector<QPointF> mutigausspos);
    double GetDistance(double lon1, double lat1, double lon2, double lat2);//经纬度计算距离
    double GetDistance1ine(QVector<QPointF> line);
    double GetArea(QVector<QPointF> poly);

#endif // YFPROJECTION_H
