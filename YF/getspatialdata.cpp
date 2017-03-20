#include"getspatialdata.h"
QVector<QPointF> GetPointFromDatabase(YFMYSQL &sql,QString tablename)
{
    if(!sql.YFIsOpen())
    {
        sql.YFOpenConn();
        qDebug()<<"Database Open points"<<endl;
    }
    QVector<QPointF> pointfromdatabase;
    QString str="SELECT ST_AsGeoJson(YFPoint) FROM "+tablename;
    sql.YFDoSQLSelect(str);
    if(sql.query.next())
    {
        do{
            QString geojsonpoint= sql.query.value(0).toString();
            pointfromdatabase.push_back(GeoJSONtoQPointF(geojsonpoint));
        }while(sql.query.next());
        for(int i=0;i<pointfromdatabase.size();i++)
        {
            qDebug()<<pointfromdatabase[i].x()<<" "<<pointfromdatabase[i].y();
        }
    }
    else{qDebug()<<"query points failed"<<sql.YFSQLQueryError();}
    sql.YFCloseConn();
    qDebug()<<"Database Close points"<<endl;
    return pointfromdatabase;
}
QVector<QLineStringF> GetLineStringFromDatabase(YFMYSQL &sql,QString tablename)
{
    if(!sql.YFIsOpen())
    {
        sql.YFOpenConn();
        qDebug()<<"Database Open LineString"<<endl;
    }
    QVector<QLineStringF> linestringfromdatabase;
    QString str="SELECT ST_AsGeoJson(YFLineString) FROM "+tablename;
    sql.YFDoSQLSelect(str);
    if(sql.query.next())
    {
        do{
            QString geojsonlinestring= sql.query.value(0).toString();
            linestringfromdatabase.push_back(GeoJSONtoQLineStringF(geojsonlinestring));
        }while(sql.query.next());
        for(int i=0;i<linestringfromdatabase.size();i++)
        {
            qDebug()<<"第"<<i<<"个线"<<endl;
            for(int j=0;j<linestringfromdatabase[i].size();j++){
            qDebug()<<linestringfromdatabase[i][j].x()<<" "<<linestringfromdatabase[i][j].y();}
        }
    }
    else{qDebug()<<"query LineString failed"<<sql.YFSQLQueryError();}
    sql.YFCloseConn();
    qDebug()<<"Database Close LineString"<<endl;
    return linestringfromdatabase;
}
QVector<QPolygonF> GetPolygonFromDatabase(YFMYSQL &sql,QString tablename)
{
    if(!sql.YFIsOpen())
    {
        sql.YFOpenConn();
        qDebug()<<"Database Open Polygon"<<endl;
    }
    QVector<QPolygonF> polygonfromdatabase;
    QString str="SELECT ST_AsGeoJson(YFPolygon) FROM "+tablename;
    sql.YFDoSQLSelect(str);
    if(sql.query.next())
    {
        do{
            QString geojsonpolygon= sql.query.value(0).toString();
            polygonfromdatabase.push_back(GeoJSONtoQPolygonF(geojsonpolygon));
        }while(sql.query.next());
        for(int i=0;i<polygonfromdatabase.size();i++)
        {
            qDebug()<<"第"<<i<<"个多边形"<<endl;
            for(int j=0;j<polygonfromdatabase[i].size();j++){
            qDebug()<<polygonfromdatabase[i][0].x()<<" "<<polygonfromdatabase[i][0].y();}

        }
    }
    else{qDebug()<<"query Polygon failed"<<sql.YFSQLQueryError();}
    sql.YFCloseConn();
    qDebug()<<"Database Close Polygon"<<endl;
    return polygonfromdatabase;
}
