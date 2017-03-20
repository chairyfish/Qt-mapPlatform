#include "yfmysql.h"
YFMYSQL::YFMYSQL(){}
YFMYSQL::YFMYSQL(QString UserName, QString Password)
{
       db = QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("119.28.101.207");
       db.setPort(3306);
       db.setDatabaseName(UserName);
       db.setUserName(UserName);
       db.setPassword(Password);
}
YFMYSQL::~YFMYSQL(){if(db.isOpen()){db.close();}}
bool YFMYSQL::YFOpenConn()
{
     if(db.open()){return true;}
     else
     {

         return false;
     }
}
QString YFMYSQL::YFSQLConnError()
{
return db.lastError().text();
}
QString YFMYSQL::YFSQLQueryError()
{
return QueryError;
}
bool YFMYSQL::YFIsOpen()
{
    if(db.isOpen()){return true;}
    else{return false;}
}
void YFMYSQL::YFCloseConn()
{
    db.close();
}
QSqlQuery YFMYSQL::YFDoSQLSelect(QString querysql)
{
QSqlQuery query1;
    query1.exec(querysql);
    QueryError=query1.lastError().text();
    db.commit();
    query=query1;
    return query1;
}
bool YFMYSQL::YFDoSQLExec(QString querysql)
{
    QSqlQuery query1;
    if(query1.exec(querysql)){db.commit();query=query1;return true;}
    else {QueryError=query.lastError().text();return false;}

}
QSqlDatabase YFMYSQL::YFGetConn(){return db;}
