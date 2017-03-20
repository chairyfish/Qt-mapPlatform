#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QColorDialog>
#include<QTreeWidget>
#include "ui_mainwindow.h"
#include "QMessageBox"
#include"userdata.h"
#include"yfmysql.h"
#include"userdata.h"
#include"QDebug"
#include"newlayer.h"
#include"selectlayer.h"
#include"getdatathread.h"
#include"yfku.h"
#include"QTableWidget"
#include"getlayerrect.h"
#include"yfinsertdata.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myPaintWidget* p;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void receiveNewLayerSignal(QString,int);  //新建
    void receiveReloadSignal();  //打开


    void showLayer(QTreeWidgetItem * item,int column);
    void checkLayerState(QTreeWidgetItem* item,int column);
    void choosedLayer(QTreeWidgetItem* item,int column);

    void GetLayerDataSlot(int);//获取图层的成功的槽函数
    void on_action_New_triggered();
     void on_action_Open_triggered();


     void on_action_StartEdit_triggered();

     void on_action_StopEdit_triggered();

     void on_action_AddPoint_triggered();

     void on_Select_triggered();

     void on_action_MovePoint_triggered();

     void on_action_DelePoint_triggered();

     void on_CopyPoint_triggered();

     void on_action_AddLine_triggered();

     void on_action_MoveLine_triggered();

     void on_CopyLine_triggered();

     void on_action_PointFromLine_triggered();

     void on_EditType_triggered();

     void on_PntDelFromLine_triggered();

     void on_action_AddPoly_triggered();

     void on_action_DelePoly_triggered();

     void on_action_MovePoly_triggered();

     void on_CopyPolygon_triggered();

     void on_Edit_Polygon_triggered();

     void on_PntAddToLine_Polygon_triggered();

     void on_PntDelFromLine_Polygon_triggered();

     void on_action_DeleLine_triggered();

     void on_action_DeleLayer_triggered();

     void on_action_showAttr_triggered();

     void on_action_SaveEdit_triggered();

     void on_action_Layers_triggered();

     void on_action_properties_triggered();

     void on_action_triggered();

     void on_action_2_triggered();

     void on_action_3_triggered();

private:
    Ui::MainWindow *ui;


public:

    GetDataThread *getdatathread;//获取图层线程作为类的成员
    QStringList PointList;      //图层数组的名称
    QStringList LineList;
    QStringList PolyList;
    int PointLayerNum=0;        //图层数组的大小
    int LineLayerNum=0;
    int PolyLayerNum=0;

    void getLayer();                //从selectLayer读取图层
    void readLayer();
    void loadLayer();               //从selectLayer载入图层
    void removeAllLayer();              //移除所有的树
    void deleteCurrentItem();
    void insertLayer(QString layerName,int TYPE);       //插入图层
    void insertLayerIntoMysql(YFMYSQL& sql,QString layerName,int TYPE);      //将图层插入数据库
    void deleteLayerfromMysql(YFMYSQL& sql,QString layerName);

    QRect screen=QRect(QPoint(0,0),QPoint(1365,626));
    QRectF geo=QRectF(QPointF(115.822167,40.160866),QPointF(117.005343,39.73606));

    int ISDATALOAD=0;               //标记数据是否加载完毕
    int ISEDITING=0;                       //标记是否在编辑状态
    QString CHOOSEDLAYER="";
    int LAYERTYPE=0;

    QVector<Attribute> GetAttributeOfTable(YFMYSQL &sql,QString tablename);
    QVector<QStringList> GetValueOfAttr(YFMYSQL& sql,QStringList attrname,QString tablename);
};

#endif // MAINWINDOW_H
