#include "getdatathread.h"

GetDataThread::GetDataThread(YFMYSQL &mysql1,QStringList pointlayer1,QStringList linelayer1,QStringList polylayer1,QObject *parent)
    :QThread(parent)
{
    pointlayername=pointlayer1;
    linelayername=linelayer1;
    polylayername=polylayer1;
    mysql=mysql1;
}
QVector<YFPointLayer> GetDataThread::GetPointData()
{
    return pointlayer;
}
QVector<YFLineLayer> GetDataThread::GetLineData()
{
    return linelayer;
}
QVector<YFPolyLayer> GetDataThread::GetPolyData()
{
    return polylayer;
}
void GetDataThread::run()
{
    /////////////////////////read point layer//////////////////////////////
    for(int i=0;i<pointlayername.size();i++)
    {
        YFPointLayer player;
        player.layername=pointlayername.at(i);
        QVector<QPointF> data;
        data=GetPointFromDatabase(mysql,pointlayername.at(i));
        player.pointsdata=data;
        pointlayer.push_back(player);
    }
    /////////////////////////read line layer////////////////////////////////
     for(int i=0;i<linelayername.size();i++)
    {
        YFLineLayer llayer;
        llayer.layername=linelayername.at(i);
        QVector<QLineStringF> data;
        data=GetLineStringFromDatabase(mysql,linelayername.at(i));
        llayer.linesdata=data;
        linelayer.push_back(llayer);
    }
    /////////////////////////read poly layer////////////////////////////////
     for(int i=0;i<polylayername.size();i++)
    {
        YFPolyLayer polayer;
        polayer.layername=polylayername.at(i);
        QVector<QPolygonF> data;
        data=GetPolygonFromDatabase(mysql,polylayername.at(i));
        polayer.polysdata=data;
        polylayer.push_back(polayer);
    }
     emit GetDataThreadSignal(1);

}
//void GetDataThread::GetDataThreadSignal(bool sig){}
