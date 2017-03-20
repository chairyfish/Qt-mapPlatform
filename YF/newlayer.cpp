#include "newlayer.h"
#include "ui_newlayer.h"

NewLayer::NewLayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLayer)
{
    ui->setupUi(this);
}

NewLayer::~NewLayer()
{
    delete ui;
}

void NewLayer::on_NewLayer_OK_clicked()
{
    int TYPE=0;
    QString layerType=ui->NewLayerType->currentText();
   if(layerType=="点图层"){
       TYPE=1;
   }else if(layerType=="线图层"){
       TYPE=2;
   }else if(layerType=="面图层"){
       TYPE=3;
   }
       emit sendNewLayerSignal(ui->NewLayerName->text(),TYPE);
   accept();
}
//void NewLayer::sendNewLayerSignal(QString,int){
//}
