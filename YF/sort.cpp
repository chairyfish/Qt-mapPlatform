#include"sort.h"
//若点a大于点b,即点a在点b逆时针方向,返回true,否则返回false
bool YFPointCmp(const QPoint &a,const QPoint &b,const QPoint &center)
{
    if (a.x() >= 0 && b.x() < 0)
        return true;
    if (a.x() == 0 && b.x() == 0)
        return a.y() > b.y();
    //向量OA和向量OB的叉积
    int det = (a.x() - center.x()) * (b.y() - center.y()) - (b.x() - center.x()) * (a.y() - center.y());
    if (det < 0)
        return true;
    if (det > 0)
        return false;
    //向量OA和向量OB共线，以距离判断大小
    int d1 = (a.x() - center.x()) * (a.x() - center.x()) + (a.y() - center.y()) * (a.y() - center.y());
    int d2 = (b.x() - center.x()) * (b.x() - center.y()) + (b.y() - center.y()) * (b.y() - center.y());
    return d1 > d2;
}
bool YFPointCmp(const QPointF &a,const QPointF &b,const QPointF &center)
{
    if (a.x() >= 0 && b.x() < 0)
        return true;
    if (a.x() == 0 && b.x() == 0)
        return a.y() > b.y();
    //向量OA和向量OB的叉积
    int det = (a.x() - center.x()) * (b.y() - center.y()) - (b.x() - center.x()) * (a.y() - center.y());
    if (det < 0)
        return true;
    if (det > 0)
        return false;
    //向量OA和向量OB共线，以距离判断大小
    int d1 = (a.x() - center.x()) * (a.x() - center.x()) + (a.y() - center.y()) * (a.y() - center.y());
    int d2 = (b.x() - center.x()) * (b.x() - center.y()) + (b.y() - center.y()) * (b.y() - center.y());
    return d1 > d2;
}
/***过重心做平行于x()轴正方向的向量，每个顶点与重心连线与重心向量的夹角从小到大排序即为逆时针排序
 *
 *
 *
 ****/
void YFClockwiseSortPoints(QPolygon &vPoints)
{
    //计算重心
    QPoint center;
    double x = 0,y = 0;
    for (int i = 0;i < vPoints.size();i++)
    {
        x += vPoints[i].x();
        y += vPoints[i].y();
    }
    center.setX((int)x/vPoints.size());
    center.setY((int)y/vPoints.size());

    //冒泡排序
    for(int i = 0;i < vPoints.size() - 1;i++)
    {
        for (int j = 0;j < vPoints.size() - i - 1;j++)
        {
            if (YFPointCmp(vPoints[j],vPoints[j+1],center))
            {
                QPoint tmp = vPoints[j];
                vPoints[j] = vPoints[j + 1];
                vPoints[j + 1] = tmp;
            }
        }
    }
}
void YFClockwiseSortPoints(QPolygonF &vPoints)
{
    //计算重心
    QPointF center;
    double x = 0,y = 0;
    for (int i = 0;i < vPoints.size();i++)
    {
        x += vPoints[i].x();
        y += vPoints[i].y();
    }
    center.setX((int)x/vPoints.size());
    center.setY((int)y/vPoints.size());

    //冒泡排序
    for(int i = 0;i < vPoints.size() - 1;i++)
    {
        for (int j = 0;j < vPoints.size() - i - 1;j++)
        {
            if (YFPointCmp(vPoints[j],vPoints[j+1],center))
            {
                QPointF tmp = vPoints[j];
                vPoints[j] = vPoints[j + 1];
                vPoints[j + 1] = tmp;
            }
        }
    }
}
QPointF GeoJSONtoQPointF(QString geojsonpoint){
    QString jsonStr = geojsonpoint;
    QPointF qpointf;
   // qDebug()<<"test json!";
    QJsonParseError jsonErr;
    QJsonDocument myjsonDoc1 = QJsonDocument::fromJson(jsonStr.toLatin1(),&jsonErr);
    if (jsonErr.error == QJsonParseError::NoError)
    {
        if (myjsonDoc1.isEmpty()){
            qDebug()<<"the json is empty!"<<jsonStr.toLatin1();
        }
        else{
            if (myjsonDoc1.isObject())
            {
                QJsonObject jobj = myjsonDoc1.object();
                QJsonArray coordinates=jobj.value("coordinates").toArray();
                qpointf.setX(coordinates[0].toDouble());
                qpointf.setY(coordinates[1].toDouble());

            }
            else{qDebug()<<"json is not object";}
        }
    }
    return qpointf;
}
QLineStringF GeoJSONtoQLineStringF(QString geojsonlinestring){
    QString jsonStr = geojsonlinestring;
    QLineStringF qlinestringf;
    //qDebug()<<"test json!";
    QJsonParseError jsonErr;
    QJsonDocument myjsonDoc1 = QJsonDocument::fromJson(jsonStr.toLatin1(),&jsonErr);
    if (jsonErr.error == QJsonParseError::NoError)
    {
        if (myjsonDoc1.isEmpty()){
            qDebug()<<"the json is empty!"<<jsonStr.toLatin1();
        }
        else{
            if (myjsonDoc1.isObject())
            {
                QJsonObject jobj = myjsonDoc1.object();
                QJsonArray coordinates=jobj.value("coordinates").toArray();
                for(int i=0;i<coordinates.count();i++)
                {
                    QJsonArray coor=coordinates[i].toArray();
                    qlinestringf<<QPointF(coor[0].toDouble(),coor[1].toDouble());
                }


            }
            else{qDebug()<<"json is not object";}
        }
    }
    return qlinestringf;
}
QPolygonF GeoJSONtoQPolygonF(QString geojsonpolygon)
{
    QString jsonStr = geojsonpolygon;
    QPolygonF qpolygonf;
    //qDebug()<<"test json!";
    QJsonParseError jsonErr;
    QJsonDocument myjsonDoc1 = QJsonDocument::fromJson(jsonStr.toLatin1(),&jsonErr);
    if (jsonErr.error == QJsonParseError::NoError)
    {
        if (myjsonDoc1.isEmpty()){
            qDebug()<<"the json is empty!"<<jsonStr.toLatin1();
        }
        else{
            if (myjsonDoc1.isObject())
            {
                QJsonObject jobj = myjsonDoc1.object();
                QJsonArray coordinates=jobj.value("coordinates").toArray();
                QJsonArray coorpoly=coordinates[0].toArray();
                for(int i=0;i<coorpoly.count();i++)
                {
                    QJsonArray coor=coorpoly[i].toArray();
                    qpolygonf<<QPointF(coor[0].toDouble(),coor[1].toDouble());
                    qDebug()<<coor[0].toDouble()<<" "<<coor[1].toDouble();
                }


            }
            else{qDebug()<<"json is not object";}
        }
    }
    return qpolygonf;
}
