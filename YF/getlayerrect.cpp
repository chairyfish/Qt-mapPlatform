#include"getlayerrect.h"
QRectF GetPointLayerRect(QVector<QPointF> points)
{
    QPolygonF temp(points);
    return temp.boundingRect();
//    QRectF temprect(QPointF(temp.boundingRect().left(),temp.boundingRect().bottom()),QPointF(temp.boundingRect().right(),temp.boundingRect().top()));
//    return temprect;
}
QRectF GetLineLayerRect(QVector<QLineStringF> lines)
{
    QPolygonF temp;
    for(int i=0;i<lines.size();i++)
    {
        temp.append(lines[i]);
    }
    qDebug()<<temp.boundingRect().left()<<temp.boundingRect().top()<<temp.boundingRect().bottom()<<temp.boundingRect().right();
//    QRectF temprect(QPointF(temp.boundingRect().left(),temp.boundingRect().bottom()),QPointF(temp.boundingRect().right(),temp.boundingRect().top()));
//    return temprect;
    return temp.boundingRect();
}
QRectF GetPolyLayerRect(QVector<QPolygonF> polys)
{
    QPolygonF temp;
    for(int i=0;i<polys.size();i++)
    {
        temp.append(polys[i]);
    }
//    QRectF temprect(QPointF(temp.boundingRect().left(),temp.boundingRect().bottom()),QPointF(temp.boundingRect().right(),temp.boundingRect().top()));
//    return temprect;
    return temp.boundingRect();
}
