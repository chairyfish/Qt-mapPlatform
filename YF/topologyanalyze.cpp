#include"topologyanalyze.h"
QPolygon GetIntersected(QPolygon poly1,QPolygon poly2)//多边形相交函数
{
    return poly1.intersected(poly2);
}
QPolygon GetSubtracted(QPolygon poly1,QPolygon poly2)//多边形相减函数，poly1-poly2
{
    return poly1.subtracted(poly2);
}
QPolygon GetUnited(QPolygon poly1,QPolygon poly2)//多边形求并函数
{
    return poly1.united(poly2);
}
