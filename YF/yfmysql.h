#ifndef YFMYSQL_H
#define YFMYSQL_H
#include <QCoreApplication>
#include<QtSql>
#include <QtWidgets/QWidget>
#include<QDebug>
#include<string.h>
#include<QString>
#include<Qxmlstream.h>
#include<QFile>
using namespace std;
class YFMYSQL
{
private:
    QSqlDatabase db;
    QString QueryError;
public:
    YFMYSQL(QString UserName,QString Password );//构造函数
    YFMYSQL();
    ~YFMYSQL();
    bool YFOpenConn();//打开数据库连接
    QString YFSQLConnError();//捕捉连接错误并返回字符串
    QString YFSQLQueryError();//捕捉查询错误并返回字符串
    bool YFIsOpen();//判断数据库是否连接
    void YFCloseConn();//关闭数据库连接
    QSqlQuery YFDoSQLSelect(QString querysql);//需要返回结果集的查询
    bool YFDoSQLExec(QString querysql);//不需返回结果集的查询（增加，删除，修改）
    QSqlDatabase YFGetConn();//获得连接
    QSqlQuery query;
};
struct Attribute//属性
{
 QString attributename;//属性字段名称
 QString attributetype; //属性字段类型
};
#endif // YFMYSQL_H
