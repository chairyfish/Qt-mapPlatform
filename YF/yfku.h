#ifndef YFKU_H
#define YFKU_H

#if defined(YFKU_LIBRARY)
#  define YFKUSHARED_EXPORT Q_DECL_EXPORT
#else
#  define YFKUSHARED_EXPORT Q_DECL_IMPORT
#endif

#include <QtGui>
#include <QDebug>
#include <QObject>
#include <QWidget>
#include<QPolygon>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRubberBand>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QPoint>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QString>
#include<QMessageBox>
using namespace std;

typedef struct myCicle{
    QPoint startPnt;
    int r;
}myCicle;

class YFKUSHARED_EXPORT Yfku
{

public:
    Yfku();
};

class YFKUSHARED_EXPORT QLineString : public QPolygon
{
public:
    QLineString(const QVector<QPoint> &points);
       QLineString(const QPolygon &polygon);
       QLineString();
};


class YFKUSHARED_EXPORT Yflayer{
public:
    Yflayer(int a=-1,QString b="");
    ~Yflayer();
    //int ID;
    int l_type;
    QString Name;
    bool isVisual;
    bool isEdit;

    QVector<QPoint> ps;//存放所有的点
    QVector<QLineF> lines; //存放所有的线段
    QVector<QLineString>linestring;
    QVector<QPolygon> polygons;//存放所有的多边形

    void setEdit(Yflayer* layer);
    void finishEdit(Yflayer* layer);
};


class YFKUSHARED_EXPORT myPaintWidget:public QWidget{
    Q_OBJECT
public:
    myPaintWidget(QWidget*parent=0);
  //  Yfdrawpoint( );
   // Yfdrawpoint();//带有形参的构造函数
     ~myPaintWidget();
    int m;
    int type;
    int id0;//记录所编辑的点在数组的下标
    int id;
    int id1;//记录所编辑的图元在数组的下标
    vector<int>ID;
    QPoint p0;
    QPoint p1;
    QPoint startPnt;
    QPoint endPnt;
    QPolygon polygon;
    QRect Rect;//生成选中的矩形框
    bool isPressed;//鼠标是否按下
    bool isMoved;//鼠标是否移动

    Yflayer* cureditlayer;
    QVector<Yflayer*> layers;
   // QVector<QPoint> ps;//存放所有的点
    QVector<QLineF> lines; //存放所有的线段
   // QVector<QLineString>linestring;
    //QVector<QPolygon> polygons;//存放所有的多边形
    QVector<myCicle*> cicles; //存放所有的圆
    QRectF rect;
    enum viewState
    {
        NoneState,  //  0
        DrawType,   //  1
        MoveType,   //  2
        EditType,   //  3
        DeleteType, //  4
        SceneMoveType,  //5漫游状态
        SelectType,     //6
        CopyType,
        LineCut,        //7剪断线
        LineLink,       //8连接两条线
        PntAddToLine,   //9线上加点
        PntDelFromLine, //10线上删点
        RotateType
    };
    enum anlyseState
    {
        qiujiao,
        qiubing,
        qiucha
    };
    viewState curState;
    anlyseState curanlyse;


    QPen pen;//创建一个画笔
    QBrush brush;//创建一个画刷
    QPen pen1;//闪烁时的画笔
    QBrush brush1;//闪烁时的画刷

    QTimer *timer;
    void mousePressDraw(QMouseEvent *event);
    void mouseMoveDraw(QMouseEvent *event);
    void mouseReleaseDraw(QMouseEvent *event);

    void mousePressMove(QMouseEvent *event);
    void mouseMoveMove(QMouseEvent *event);
    void mouseReleaseMove(QMouseEvent *event);

    void mousePressEdit(QMouseEvent *event);
    void mouseMoveEdit(QMouseEvent *event);
    void mouseReleaseEdit(QMouseEvent *event);

    void mousePressSelect(QMouseEvent *event);
    void mouseMoveSelect(QMouseEvent *event);
    void mouseReleaseSelect(QMouseEvent *event);

    void mousePressCopy(QMouseEvent *event);
    void mouseMoveCopy(QMouseEvent *event);
    void mouseReleaseCopy(QMouseEvent *event);

    void mousePressPntAddToLine(QMouseEvent *event);
    void mouseMovePntAddToLine(QMouseEvent *event);
    void mouseReleasePntAddToLine(QMouseEvent *event);
    void mousePressPntDelFromLine(QMouseEvent *event);
    void deleteYffeature();
    void drawlayer(int a,QString b);
    void deletelayer(QString name);

  private slots:
    void timerDone();

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
   // void wheelEvent(QGraphicsSceneWheelEvent * wheelEvent);
};

#endif // YFKU_H
