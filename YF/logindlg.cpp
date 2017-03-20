#include "logindlg.h"
#include "ui_logindlg.h"
#include"mainwindow.h"
#include"QMessageBox"
#include "yfmysql.h"
#include"userdata.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);     //输入密码时显示为*
    ui->Username->setText("YFUSER");
    ui->Password->setText("961219");
}

LoginDlg::~LoginDlg()
{
    delete ui;
}



void LoginDlg::on_loginButton_clicked()
{
    QString qUsername=ui->Username->text();     //取出用户名
    QString qPassword=ui->Password->text();     //取出密码
    UserData::mysql=YFMYSQL(qUsername,qPassword);       //验证是否连接成功
    UserData:: mysql.YFOpenConn();
    if(UserData:: mysql.YFIsOpen())
    {
        UserData::USERNAME=qUsername;
        UserData::PASSWORD=qPassword;
//        UserData:: mysql.YFCloseConn();
        accept();
    }
    else
    {
        QMessageBox::warning(this,tr("登录失败"),("用户名或密码错误！"),QMessageBox::Yes);    //警告对话框
        ui->Username->clear();                      //清除用户名
        ui->Password->clear();                 //清除密码
        ui->Username->setFocus();              //鼠标回到用户名栏
        UserData::mysql.YFCloseConn();
    }

}


void LoginDlg::on_LoginDlg_accepted()
{

}



