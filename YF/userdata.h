#ifndef USERDATA_H
#define USERDATA_H
#include"QString"
#include"yfmysql.h"
class UserData      //一个用来存全局变量的类
{
public:
    UserData();
    static QString USERNAME;
    static QString PASSWORD;
    static YFMYSQL mysql;
};

#endif // USERDATA_H
