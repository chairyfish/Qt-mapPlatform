#include "selectlayer.h"
#include "ui_selectlayer.h"
#include<QDebug>
#include"yfmysql.h"
#include"mainwindow.h"
#include<QMessageBox>
#include"userdata.h"
#include<QHBoxLayout>

SelectLayer::SelectLayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectLayer)
{
    ui->setupUi(this);  
    loadLayerFromSql();
    showTableWidget();

//    connect(ui->SelectTable, SIGNAL(cellChanged(int,int)), this, SLOT(changeTest(int, int)));

}

SelectLayer::~SelectLayer()
{
    delete ui;
}
QStringList SelectLayer::checkPoint;
QStringList SelectLayer::checkLine;
QStringList SelectLayer::checkPoly;


void SelectLayer::loadLayerFromSql(){

    if(!UserData::mysql.YFIsOpen()){
        QMessageBox::warning(this,tr("提示"),("连接失败，错误代码：E001"),QMessageBox::Yes);
        UserData::mysql.YFOpenConn();
    }
     //清空数组
    selePoint.clear();
    seleLine.clear();
    selePoly.clear();
//    qDebug()<<selePointNum<<seleLineNum;

    //获取图层名 读入QStringList
    QSqlQuery queryPoint=UserData::mysql.YFDoSQLSelect("select * from ManageTable where tableType=1;");
    while(queryPoint.next()){
        selePoint<<QString(queryPoint.value(0).toString());
        selePointNum++;
    }
    QSqlQuery queryLine=UserData::mysql.YFDoSQLSelect("select * from ManageTable where tableType=2;");
    while(queryLine.next()){
        seleLine<<QString(queryLine.value(0).toString());
        seleLineNum++;
    }
    QSqlQuery queryPoly=UserData::mysql.YFDoSQLSelect("select * from ManageTable where tableType=3;");
    while(queryPoly.next()){
        selePoly<<QString(queryPoly.value(0).toString());
        selePolyNum++;
    }
    // 关闭数据库连接
//     UserData::mysql.YFCloseConn();
}

void SelectLayer::showTableWidget(){
    ui->SelectTable->setColumnCount(3);
    ui->SelectTable->setHorizontalHeaderLabels(QStringList()<<"图层名"<<"图层类型"<<"是否载入");
    int row=0;

    for(int i=row;i<selePointNum;i++)
    {
        ui->SelectTable->insertRow(i);
        ui->SelectTable->setItem(i,0,new QTableWidgetItem(selePoint.at(i)));
        ui->SelectTable->item(i,0)->setFlags(Qt::ItemIsEnabled);
        ui->SelectTable->setItem(i,1,new QTableWidgetItem("点图层"));
        ui->SelectTable->item(i,1)->setFlags(Qt::ItemIsEnabled);
        QTableWidgetItem *checkBox = new QTableWidgetItem();
        checkBox->setCheckState(Qt::Checked);
        ui->SelectTable ->setItem(i, 2, checkBox);
               row++;
     }
    for(int i=row;i<selePointNum+seleLineNum;i++)
    {
        ui->SelectTable->insertRow(i);
        ui->SelectTable->setItem(i,0,new QTableWidgetItem(seleLine.at(i-selePointNum)));
        ui->SelectTable->item(i,0)->setFlags(Qt::ItemIsEnabled);
        ui->SelectTable->setItem(i,1,new QTableWidgetItem("线图层"));
        ui->SelectTable->item(i,1)->setFlags(Qt::ItemIsEnabled);
        QTableWidgetItem *checkBox = new QTableWidgetItem();
        checkBox->setCheckState(Qt::Checked);
        ui->SelectTable ->setItem(i, 2, checkBox);
        row++;
    }
    for(int i=row;i<selePointNum+seleLineNum+selePolyNum;i++)
    {
        ui->SelectTable->insertRow(i);
        ui->SelectTable->setItem(i,0,new QTableWidgetItem(selePoly.at(i-selePointNum-seleLineNum)));
        ui->SelectTable->item(i,0)->setFlags(Qt::ItemIsEnabled);
        ui->SelectTable->setItem(i,1,new QTableWidgetItem("面图层"));
        ui->SelectTable->item(i,1)->setFlags(Qt::ItemIsEnabled);
        QTableWidgetItem *checkBox = new QTableWidgetItem();
        checkBox->setCheckState(Qt::Checked);
        ui->SelectTable ->setItem(i, 2, checkBox);
        row++;
    }
}

void SelectLayer::changeTest(){
    int row=0;
    checkPoint.clear();
    checkLine.clear();
    checkPoly.clear();

    for(int i=0;i<selePointNum;i++)
    {
        if(ui->SelectTable->item(row, 2)->checkState() == Qt::Checked){
            checkPoint<<selePoint.at(i);            
        }
        row++;
    }
    for(int i=row;i<selePointNum+seleLineNum;i++){
        if(ui->SelectTable->item(row, 2)->checkState() == Qt::Checked){
            checkLine<<seleLine.at(i-selePointNum);           
        }
        row++;
    }
    for(int i=row;i<selePointNum+seleLineNum+selePolyNum;i++){
        if(ui->SelectTable->item(row, 2)->checkState() == Qt::Checked){
            checkPoly<<selePoly.at(i-selePointNum-seleLineNum);           
        }
        row++;
    }
}

void SelectLayer::on_SelectLayer_OK_clicked()
{
    changeTest();
    emit  sendReloadSignal();
    accept();
}

//void SelectLayer::sendReloadSignal(){
//    qDebug()<<"send";
//}

