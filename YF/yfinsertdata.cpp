#include"yfinsertdata.h"
void YFInsertPointF(QVector<QPointF> a,YFMYSQL b,QString Tname)   //a为QPoint数组，b为YFMYSQL对象，Tname为数据库名+字符串名
{
    bool value;
    int Alength=a.size();        //数组长度
    bool value2=b.YFIsOpen();
    if(!value2)                  //判断数据库是否连接，若没有连接建立连接
    b.YFOpenConn();
    QString dst="delete from ";      //删除表中原有所有数据
    dst.append(Tname);
    dst.append(" where id >=0;");
    bool value1=b.YFDoSQLExec(dst);
    if(!value1)
      qDebug()<< b.YFSQLQueryError();    //删除失败,输出失败原因

    QString st="insert into ";    //sql语句
    st.append(Tname);             //拼接sql语句
    st.append("(id,YFPoint) values");
    QString Rst=st;
    for(int i=0;i<Alength;i++)    //读取QPoint数组中所有的元素
    {
    st.append("(null,point("+QString::number(a[i].x())+","+QString::number(a[i].y())+"))");
    value=b.YFDoSQLExec(st);
    st=Rst;                        //重置sql语句
    if(!value)
      qDebug()<< b.YFSQLQueryError();    //插入失败,输出失败原因
    }
    b.YFCloseConn();
}

void YFInsertLineStringF(QVector<QLineStringF> a,YFMYSQL b,QString Tname)
{
    bool value;
    int Alength=a.size();        //数组长度
    bool value2=b.YFIsOpen();
    if(!value2)                  //判断数据库是否连接，若没有连接建立连接
    b.YFOpenConn();

    QString dst="delete from ";      //删除表中原有所有数据
    dst.append(Tname);
    dst.append(" where id >=0;");
    bool value1=b.YFDoSQLExec(dst);
    if(!value1)
      qDebug()<< b.YFSQLQueryError();    //删除失败,输出失败原因

    QString st="insert into ";    //sql语句
    st.append(Tname);             //拼接sql语句
    st.append("(id,YFLineString) values");
     st.append("(null,ST_linefromtext('linestring(");
    QString Rst=st;
    for(int i=0;i<Alength;i++)     //两个for循环读取容器中所有的点
    {
        for(int j=0;j<a[i].length();j++)
        {
         st.append(QString::number(a[i][j].x())+" "+QString::number(a[i][j].y()));
         if(j<a[i].length()-1)
         st.append(",");
         }
       st.append(")'));");
       value=b.YFDoSQLExec(st);
       st=Rst;                               //重置sql语句
       if(!value)
       qDebug()<< b.YFSQLQueryError();    //插入失败,输出失败原因
    }
     b.YFCloseConn();
}
void YFInsertPolygonF(QVector<QPolygonF> a,YFMYSQL b,QString Tname) //对数据库进行写入操作，将QPolygonF类型数组a插入数据库，Tname为数据库名+字符串名
{
    bool value;
    int Alength=a.size();        //数组长度
    bool value2=b.YFIsOpen();
    if(!value2)                  //判断数据库是否连接，若没有连接建立连接
    b.YFOpenConn();
    QString dst="delete from ";      //删除表中原有所有数据
    dst.append(Tname);
    dst.append(" where id >=0;");
    bool value1=b.YFDoSQLExec(dst);
    if(!value1)
      qDebug()<< b.YFSQLQueryError();    //删除失败,输出失败原因

    QString st="insert into ";    //sql语句
    st.append(Tname);             //拼接sql语句
    st.append("(id,YFPolygon) values");
    st.append("(null,ST_polyfromtext('POLYGON((");
    QString Rst=st;
    for(int i=0;i<Alength;i++)      //两个for循环读取容器中所有的点
    {
        for(int j=0;j<a[i].length();j++)
        {
         st.append(QString::number(a[i][j].x())+" "+QString::number(a[i][j].y()));
         if(j<a[i].length())
         st.append(",");
         }
        st.append(QString::number(a[i][0].x())+" "+QString::number(a[i][0].y()));
       st.append("))'));");
       value=b.YFDoSQLExec(st);
       st=Rst;                            //重置sql语句
       if(!value)
       qDebug()<<st<< b.YFSQLQueryError();    //插入失败,输出失败原因
    }
     b.YFCloseConn();
}
