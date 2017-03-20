#include "qlinestringf.h"

QLineStringF::QLineStringF(const QVector<QPointF> &points):QPolygonF(points)
{

}

QLineStringF::QLineStringF():QPolygonF()
{

}
