#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include<logindlg.h>
#include"selectlayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    LoginDlg logindlg;
    logindlg.show();

    if(logindlg.exec()==QDialog::Accepted)
    {
//        SelectLayer sel;
//        sel.show();
//        if(sel.exec()==QDialog::Accepted){
            MainWindow w;
            w.show();
            return a.exec();
        }
//        return 0;
//    }
    else
        return 0;
}
