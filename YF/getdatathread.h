#ifndef GETDATATHREAD_H
#define GETDATATHREAD_H

#include <QObject>
#include <QWidget>
#include"getspatialdata.h"
#include"yflayer.h"
#include"yfmysql.h"
#include<QString>
class GetDataThread : public QThread
{
      Q_OBJECT
public:
    explicit GetDataThread(YFMYSQL &mysql1,QStringList pointlayer1,QStringList linelayer1,QStringList polylayer1,QObject *parent=0);
    QVector<YFPointLayer> GetPointData();
    QVector<YFLineLayer> GetLineData();
    QVector<YFPolyLayer> GetPolyData();
signals:
    void GetDataThreadSignal(int a);
protected:
    YFMYSQL mysql;
    QStringList pointlayername;
    QStringList linelayername;
    QStringList polylayername;
    /////////////////////////////////////////////////////////////////////////////////
    QVector<YFPointLayer> pointlayer;
    QVector<YFLineLayer> linelayer;
    QVector<YFPolyLayer> polylayer;

     void run();//读取需要显示的图层
};

#endif // GETDATATHREAD_H
