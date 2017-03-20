#include "yfku.h"


Yfku::Yfku()
{
}


QLineString::QLineString(const QVector<QPoint> &points):QPolygon(points)
{
}
QLineString:: QLineString(const QPolygon &polygon):QPolygon(polygon){}
QLineString:: QLineString():QPolygon(){}



Yflayer::Yflayer(int a,QString b){
    l_type=a;
    Name=b;
    isVisual=true;
    isEdit=false;
}
Yflayer::~Yflayer(){
   ps.clear();
   lines.clear();
   linestring.clear();
   polygons.clear();
}
void Yflayer::setEdit(Yflayer* layer){
    layer->isEdit=true;
}
void Yflayer::finishEdit(Yflayer* layer){
    layer->isEdit=false;
}



myPaintWidget::myPaintWidget(QWidget*parent):QWidget(parent){

    this->setMouseTracking(true);
    this->isPressed = false;
    this->isMoved = false;
    brush1=QBrush(Qt::red);
    pen1.setColor(Qt::red);
    timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(timerDone()) );
    m=0;


}
//Yfdrawpoint::Yfdrawpoint(){
// pen=new QPen();
//}

myPaintWidget::~myPaintWidget(){
    ID.clear();
    // delete cureditlayer;
    qDeleteAll(layers);
    // cureditlayer->lines.clear();
    qDeleteAll(cicles);
    delete timer;

}
void myPaintWidget::timerDone(){//计时器用来表示选中状态
    if(brush1.color()==Qt::red){
        brush1.setColor(Qt::yellow);
    }
    else{
        brush1.setColor(Qt::red);

    }
    if(pen1.color()==Qt::red){
        pen1.setColor(Qt::yellow);

    }
    else{
        pen1.setColor(Qt::red);

    }
    update();

}

void myPaintWidget::mousePressDraw(QMouseEvent *event)
{
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==0){//点
       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);
          startPnt.setX(event->pos().x());
          startPnt.setY(event->pos().y());
          QPoint p;
          p=startPnt;
          cureditlayer->ps.push_back(p);//鼠标点击位置存入点数组
          update();
       }
       this->isPressed = true;
    }

    if(type==1){
       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);
          startPnt.setX(event->pos().x());
          startPnt.setY(event->pos().y());
          endPnt.setX(event->pos().x());
          endPnt.setY(event->pos().y());

          this->isPressed = true;
       }
    }
    if(type==2){//折线

       if (Qt::LeftButton == event->button()){
           setCursor(Qt::PointingHandCursor);

           if(m==0){
              polygon.clear();
              startPnt.setX(event->pos().x());
              startPnt.setY(event->pos().y());
              endPnt.setX(event->pos().x());
              endPnt.setY(event->pos().y());
           }
           if(m>=1){
             startPnt=endPnt;
             endPnt.setX(event->pos().x());
             endPnt.setY(event->pos().y());
             QLineF line ;
             line.setP1(startPnt);
             line.setP2(endPnt);
             this->lines.push_back(line);//lines数组用来临时存储画的每一条线段，方便可视化
             polygon.append(startPnt);   //Polygon存一条折线的所有点
             repaint();
           }
           m++;

           this->isPressed = true;
       }
       if (Qt::RightButton == event->button()){

           polygon.append(endPnt);//右键单击表示画完一条折线
           QLineString Line(polygon);
           cureditlayer->linestring.push_back(Line);//折线存入线数组
           this->lines.clear();
             //update();
           m=0;
       }
    }
    if(type==3){//多边形（面）

       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);

          if(m==0){
             polygon.clear();
             startPnt.setX(event->pos().x());
             startPnt.setY(event->pos().y());
             polygon.append(startPnt);//polygon为全局对象,可视化需要

          }
          if(m>=1){
             endPnt.setX(event->pos().x());
             endPnt.setY(event->pos().y());
             polygon.append(endPnt);
             update();

             //this->isRPressed=false;
          }
          m++;
       }
       if(Qt::RightButton == event->button()){
          cureditlayer->polygons.push_back(polygon);//右键多边形存入多边形数组
          polygon.clear();
          update();
          m=0;

       }
       this->isPressed = true;
    }
    if(type==4){//矩形（面）：鼠标左键按下确定矩形左上角顶点，移动过程右下角顶点不断移动，左键松开确定最终矩形（橡皮条技术）
       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);
          startPnt.setX(event->pos().x());
          startPnt.setY(event->pos().y());
          this->isMoved=false;
          this->isPressed = true;
       }
    }
    if(type==5){
       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);
          startPnt.setX(event->pos().x());
          startPnt.setY(event->pos().y());
          this->isMoved=false;
          this->isPressed = true;
       }
    }

    }
}
void myPaintWidget::mousePressMove(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(curState==MoveType){
       if(Qt::LeftButton == event->button()){
           setCursor(Qt::PointingHandCursor);
           startPnt.setX(event->pos().x());
           startPnt.setY(event->pos().y());
        }
    }

    }
this->isPressed = true;
}
void myPaintWidget::mousePressEdit(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==2){
       if (Qt::LeftButton == event->button()){
           setCursor(Qt::PointingHandCursor);
           this->isMoved=false;
           for(int i=0;i<cureditlayer->linestring.size();i++){
               QRect rect=cureditlayer->linestring[i].boundingRect();
               rect.adjust(-5,-5,5,5);
               if(rect.contains(event->pos().x(),event->pos().y())){
                  for(int j=0;j<cureditlayer->linestring[i].size();j++){
                      if(abs(event->pos().x()-cureditlayer->linestring[i][j].x())<=5&&abs(event->pos().y()-cureditlayer->linestring[i][j].y())<=5){
                         id0=j;
                         id1=i;
                         this->isMoved=true;
                         break;
                      }
                   }
               }
           }
       }

    }
    if(type==3){
       if (Qt::LeftButton == event->button()){
           setCursor(Qt::PointingHandCursor);
           this->isMoved=false;
           for(int i=0;i<cureditlayer->polygons.size();i++){
               QRect rect=cureditlayer->polygons[i].boundingRect();
               rect.adjust(-5,-5,5,5);
                if(rect.contains(event->pos().x(),event->pos().y())){
                   for(int j=0;j<cureditlayer->polygons[i].size();j++){
                       if(abs(event->pos().x()-cureditlayer->polygons[i][j].x())<=5&&abs(event->pos().y()-cureditlayer->polygons[i][j].y())<=5){
                          id0=j;
                          id1=i;
                          this->isMoved=true;
                          break;
                       }
                   }
                }
           }

       }
    }
    if(type==4){
       if (Qt::LeftButton == event->button()){
           setCursor(Qt::PointingHandCursor);
           this->isMoved=false;
           for(int i=0;i<cureditlayer->polygons.size();i++){
               QRect rect=cureditlayer->polygons[i].boundingRect();
               rect.adjust(-5,-5,5,5);
               if(rect.contains(event->pos().x(),event->pos().y())){
                  for(int j=0;j<cureditlayer->polygons[i].size();j++){
                      if(abs(event->pos().x()-cureditlayer->polygons[i][j].x())<=5&&abs(event->pos().y()-cureditlayer->polygons[i][j].y())<=5){
                         id0=j;
                         id1=i;
                         this->isMoved=true;
                         break;
                      }
                  }
               }
           }
        }
    }
    if(Qt::RightButton == event->button()){
        curState=NoneState;
        update();
     }

    }
    this->isPressed = true;
}
void myPaintWidget::mousePressSelect(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(Qt::LeftButton == event->button()){
       setCursor(Qt::PointingHandCursor);
       startPnt.setX(event->pos().x());
       startPnt.setY(event->pos().y());
       this->isMoved=false;
        this->isPressed = true;

    }
    if(Qt::RightButton == event->button()){
       curState=NoneState;
       ID.clear();
    }
    }

}
void myPaintWidget::mousePressCopy(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==0){
       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);
          int dx=event->pos().x()-cureditlayer->ps[ID[0]].x();
          int dy=event->pos().y()-cureditlayer->ps[ID[0]].y();//以选中的第一个点和鼠标当前点击位置的坐标差设置偏移量
          for(int i=0;i<ID.size();i++){
              QPoint p=cureditlayer->ps[ID[i]];
              p.setX(p.x()+dx);
              p.setY(p.y()+dy);
              cureditlayer->ps.push_back(p);
          }
          update();
       }
    }
    if(type==2){
       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);
          int dx=event->pos().x()-cureditlayer->linestring[ID[0]].boundingRect().center().x();
          int dy=event->pos().y()-cureditlayer->linestring[ID[0]].boundingRect().center().y();//以选中的第一个折线的外包矩形的中心和鼠标当前点击位置的坐标差设置偏移量
          for(int i=0;i<ID.size();i++){
              QPolygon polygon=cureditlayer->linestring[ID[i]];
              polygon.translate(dx,dy);
              QLineString Line(polygon);
              cureditlayer->linestring.push_back(Line);
          }
          update();
       }
    }
    if(type==3||type==4){
       if(Qt::LeftButton == event->button()){
          setCursor(Qt::PointingHandCursor);
          int dx=event->pos().x()-cureditlayer->polygons[ID[0]].boundingRect().center().x();
          int dy=event->pos().y()-cureditlayer->polygons[ID[0]].boundingRect().center().y();//以选中的第一个多边形的外包矩形的中心和鼠标当前点击位置的坐标差设置偏移量
          for(int i=0;i<ID.size();i++){
              QPolygon polygon=cureditlayer->polygons[ID[i]];
              polygon.translate(dx,dy);
              cureditlayer->polygons.push_back(polygon);
          }
          update();
       }
    }

    }
     this->isPressed = true;
}
void myPaintWidget::mousePressPntAddToLine(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==2){
        if(Qt::LeftButton == event->button()){
           setCursor(Qt::PointingHandCursor);
           QPoint p;
           p.setX(event->pos().x()); p.setY(event->pos().y());
           int a=0;int b=0;
           double S=10000.0;
           for(int i=0;i<cureditlayer->linestring.size();i++){
               if(cureditlayer->linestring[i].boundingRect().contains(p.x(),p.y())){
                   for(int j=0;j<cureditlayer->linestring[i].size()-1;j++){
                       QLineF line(cureditlayer->linestring[i][j],cureditlayer->linestring[i][j+1]);
                       int x1,x2,y1,y2;
                       if(line.x1()<line.x2()){
                           x1=line.x1();x2=line.x2();
                       }
                       else{
                           x1=line.x2();x2=line.x1();
                       }
                       if(line.y1()<line.y2()){
                          y1=line.y1();y2=line.y2();
                       }
                       else{
                           y1=line.y2();y2=line.y1();
                       }
                       QRect rect(QPoint(x1,y1),QPoint(x2,y2));
                       QLineF lin(cureditlayer->linestring[i][j],p);
                       double angle=abs(line.angle()-lin.angle());
                       double temp=sqrt(pow(lin.x2()-lin.x1(),2)+pow(lin.y2()-lin.y1(),2))*sin(angle*3.14/180);
                       if(rect.contains(p.x(),p.y())&&S>temp){
                           S=temp;
                           a=i;b=j;

                       }

                   }
               }
           }

           QLineF line1(cureditlayer->linestring[a][b],cureditlayer->linestring[a][b+1]);
           for(int j=event->pos().y()-5;j<event->pos().y()+5;j++){
               p.setY(j);
               QLineF line2(cureditlayer->linestring[a][b],p);
               int a1=line1.angle();
               int a2=line2.angle();
               if(a1==a2){
                  cureditlayer->linestring[a].insert(b+1,p);
                  break;
                  }
               }
           update();
        }
    }
    if(type==3||type==4){
        if(Qt::LeftButton == event->button()){
           setCursor(Qt::PointingHandCursor);
           QPoint p;
           p.setX(event->pos().x()); p.setY(event->pos().y());
           int a=0;int b=0;
           double S=10000.0;
           for(int i=0;i<cureditlayer->polygons.size();i++){
               if(cureditlayer->polygons[i].boundingRect().contains(p.x(),p.y())){
                   for(int j=0;j<cureditlayer->polygons[i].size();j++){
                       QLineF line;
                       if(j<cureditlayer->polygons[i].size()-1)
                          line.setPoints(cureditlayer->polygons[i][j],cureditlayer->polygons[i][j+1]);
                       else if(j==cureditlayer->polygons[i].size()-1)
                         line.setPoints(cureditlayer->polygons[i][j],cureditlayer->polygons[i][0]);
                       int x1,x2,y1,y2;
                       if(line.x1()<line.x2()){
                           x1=line.x1();x2=line.x2();
                       }
                       else{
                           x1=line.x2();x2=line.x1();
                       }
                       if(line.y1()<line.y2()){
                          y1=line.y1();y2=line.y2();
                       }
                       else{
                           y1=line.y2();y2=line.y1();
                       }
                       QRect rect(QPoint(x1,y1),QPoint(x2,y2));
                       QLineF lin(cureditlayer->polygons[i][j],p);
                       double angle=abs(line.angle()-lin.angle());
                       double temp=sqrt(pow(lin.x2()-lin.x1(),2)+pow(lin.y2()-lin.y1(),2))*sin(angle*3.14/180);
                       if(rect.contains(p.x(),p.y())&&S>temp){
                           S=temp;
                           a=i;b=j;

                       }

                   }
               }
           }
           QLineF line1;
           if(b<cureditlayer->polygons[a].size()-1)
              line1.setPoints(cureditlayer->polygons[a][b],cureditlayer->polygons[a][b+1]);
           else if(b==cureditlayer->polygons[a].size()-1)
              line1.setPoints(cureditlayer->polygons[a][b],cureditlayer->polygons[a][0]);
           for(int j=event->pos().y()-5;j<event->pos().y()+5;j++){
               p.setY(j);
               QLineF line2(cureditlayer->polygons[a][b],p);
               int a1=line1.angle();
               int a2=line2.angle();
               if(a1==a2){
                  if(b<cureditlayer->polygons[a].size()-1)
                    cureditlayer-> polygons[a].insert(b+1,p);
                  else if(b==cureditlayer->polygons[a].size()-1)
                     cureditlayer->polygons[a].insert(0,p);
                  break;
                  }
               }
           update();
        }
    }
    if(Qt::RightButton == event->button()){
        curState=NoneState;
        update();
    }
    this->isPressed=true;
    }
}

void myPaintWidget::mouseMoveDraw(QMouseEvent *event)
{
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
 if(type==1){
    if(this->isPressed){
       endPnt.setX(event->pos().x());
       endPnt.setY(event->pos().y());
       QLineF line;  //put the new line into vector
       line.setP1(startPnt);
       line.setP2(endPnt);
       cureditlayer->lines.push_back(line);
       update();
       startPnt = endPnt;
    }
 }
 if(type==4){
    if(this->isPressed){
        this->isMoved = TRUE;
        endPnt.setX(event->pos().x());
        endPnt.setY(event->pos().y());
        update();
        //startPnt = endPnt;
    }
 }
 if(type==5){
    if(this->isPressed){
        this->isMoved = TRUE;
        endPnt.setX(event->pos().x());
        endPnt.setY(event->pos().y());
        update();

        //startPnt = endPnt;
    }
 }


    }
}
void myPaintWidget::mouseMoveMove(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==0){
       if(this->isPressed){
       endPnt.setX(event->pos().x());
       endPnt.setY(event->pos().y());
       int dx=endPnt.x()-startPnt.x();
       int dy=endPnt.y()-startPnt.y();
       for(int i=0;i<ID.size();i++){
          cureditlayer->ps[ID[i]].setX(cureditlayer->ps[ID[i]].x()+dx);
          cureditlayer->ps[ID[i]].setY(cureditlayer->ps[ID[i]].y()+dy);
       }
       startPnt=endPnt;
       update();
       }
    }
    if(type==2){
       if(this->isPressed){
       endPnt.setX(event->pos().x());
       endPnt.setY(event->pos().y());
       int dx=endPnt.x()-startPnt.x();
       int dy=endPnt.y()-startPnt.y();
       for(int i=0;i<ID.size();i++){
           cureditlayer->linestring[ID[i]].translate(dx,dy);
       }
       startPnt=endPnt;
       update();

       }
    }
    if(type==3||type==4){
       if(this->isPressed){
       endPnt.setX(event->pos().x());
       endPnt.setY(event->pos().y());
       int dx=endPnt.x()-startPnt.x();
       int dy=endPnt.y()-startPnt.y();

       for(int i=0;i<ID.size();i++){
           cureditlayer->polygons[ID[i]].translate(dx,dy);
       }
       startPnt=endPnt;
       update();
       }
    }

    }
    this->isMoved=true;
}
void myPaintWidget::mouseMoveEdit(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==2){
       if(this->isPressed&&this->isMoved){
         p0.setX(event->pos().x());
         p0.setY(event->pos().y());
         cureditlayer->linestring[id1][id0]=p0;
         update();
       }
    }
    if(type==3){
       if(this->isPressed&&this->isMoved){
         p0.setX(event->pos().x());
         p0.setY(event->pos().y());
         cureditlayer->polygons[id1][id0]= p0;
         update();
       }
    }
    if(type==4){
       if(this->isPressed&&this->isMoved){
         QRect rect;
         rect.setTopLeft(cureditlayer->polygons[id1][0]);
         rect.setBottomRight(cureditlayer->polygons[id1][2]);
         p0.setX(event->pos().x());
         p0.setY(event->pos().y());
         if(id0==0)
         rect.setTopLeft(p0);
         else if(id0==1)
         rect.setTopRight(p0);
         else if(id0==2)
         rect.setBottomRight(p0);
         else if(id0==3)
         rect.setBottomLeft(p0);
         cureditlayer->polygons[id1][0]=rect.topLeft();
         cureditlayer->polygons[id1][1]=rect.topRight();
         cureditlayer->polygons[id1][2]=rect.bottomRight();
         cureditlayer->polygons[id1][3]=rect.bottomLeft();
         update();
       }
    }
    }
}
void myPaintWidget::mouseMoveSelect(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(this->isPressed){
        this->isMoved = true;
        endPnt.setX(event->pos().x());
        endPnt.setY(event->pos().y());
        update();
        //startPnt = endPnt;
    }
    }
}
void myPaintWidget::mouseMoveCopy(QMouseEvent *event){}
void myPaintWidget::mouseMovePntAddToLine(QMouseEvent *event){}

void myPaintWidget::mouseReleaseDraw(QMouseEvent *)
{
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    setCursor(Qt::ArrowCursor);
    if (type==4&&this->isMoved){
        QRect rect;
        rect.setTopLeft(startPnt);
        rect.setBottomRight(endPnt);
        QPolygon polygon;
        polygon.append(rect.topLeft());
        polygon.append(rect.topRight());
        polygon.append(rect.bottomRight());
        polygon.append(rect.bottomLeft());
        cureditlayer->polygons.push_back(polygon);
        update();
    }
    if (type==5&&this->isMoved){

        myCicle* cicle =new myCicle;  //put the new line into vector
        cicle->startPnt = startPnt;
        int r0;
        r0=sqrt((startPnt.x()-endPnt.x())*(startPnt.x()-endPnt.x())+(startPnt.y()-endPnt.y())*(startPnt.y()-endPnt.y()));
        cicle->r = r0;
        this->cicles.push_back(cicle);
        update();
    }
}
    this->isPressed = false;


}
void myPaintWidget::mouseReleaseMove(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    setCursor(Qt::ArrowCursor);
    curState=NoneState;
    ID.clear();
    update();

    }
this->isPressed = false;
}
void myPaintWidget::mouseReleaseEdit(QMouseEvent *event){
    setCursor(Qt::ArrowCursor);
    this->isPressed = false;

}
void myPaintWidget::mouseReleaseSelect(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    setCursor(Qt::ArrowCursor);
    update();
    if(type==0){
        ID.clear();
        for(int i=0;i<cureditlayer->ps.size();i++){

            if(cureditlayer->ps[i].x()+5<=Rect.bottomRight().x()&&cureditlayer->ps[i].x()-5>=Rect.topLeft().x()&&cureditlayer->ps[i].y()+5<=Rect.bottomRight().y()&&cureditlayer->ps[i].y()-5>=Rect.topLeft().y()){
               this->ID.push_back(i);

            }
        }
        update();

    }
    if(type==2){
        ID.clear();
        for(int i=0;i<cureditlayer->linestring.size();i++){
            if(cureditlayer->linestring[i].boundingRect().intersects(Rect)){
               for(int j=0;j<cureditlayer->linestring[i].size();j++){
                   if(cureditlayer->linestring[i][j].x()+5<=Rect.bottomRight().x()&&cureditlayer->linestring[i][j].x()-5>=Rect.topLeft().x()&&cureditlayer->linestring[i][j].y()+5<=Rect.bottomRight().y()&&cureditlayer->linestring[i][j].y()-5>=Rect.topLeft().y()){
                      this->ID.push_back(i);
                       break;

                    }
                   else if(j<cureditlayer->linestring[i].size()-1){
                       QLineF *line1=new QLineF;
                       line1->setP1(Rect.topLeft());line1->setP2(Rect.bottomLeft());
                       QLineF *line2=new QLineF;
                       line2->setP1(Rect.bottomLeft());line2->setP2(Rect.bottomRight());
                       QLineF *line3=new QLineF;
                       line3->setP1(Rect.bottomRight());line3->setP2(Rect.topRight());
                       QLineF *line4=new QLineF;
                       line4->setP1(Rect.topRight());line4->setP2(Rect.topLeft());
                       QLineF *line=new QLineF;
                       line->setP1(cureditlayer->linestring[i][j]);line->setP2(cureditlayer->linestring[i][j+1]);
                       int dx1 = line->p2().x()-line->p1().x();
                       int dy1 = line->p2().y()-line->p1().y();
                       int dx2 = line1->p2().x()-line1->p1().x();
                       int dy2 = line1->p2().y()-line1->p1().y();
                       int dx3 = line2->p2().x()-line2->p1().x();
                       int dy3 = line2->p2().y()-line2->p1().y();
                       int dx4 = line3->p2().x()-line3->p1().x();
                       int dy4 = line3->p2().y()-line3->p1().y();
                       int dx5 = line4->p2().x()-line4->p1().x();
                       int dy5 = line4->p2().y()-line4->p1().y();
                       if(((line1->p1().x() -line->p2().x()) * dy1 - (line1->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line1->p2().x() -line->p2().x()) * dy1 - (line1->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line1->p2().x()) * dy2 - (line->p1().y() - line1->p2().y()) * dx2 < 0) !=
                                  ((line->p2().x() - line1->p2().x()) * dy2 - (line->p2().y() - line1->p2().y()) * dx2 < 0)){

                           this->ID.push_back(i);
                           break;


                       }
                       else if(((line2->p1().x() -line->p2().x()) * dy1 - (line2->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line2->p2().x() -line->p2().x()) * dy1 - (line2->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line2->p2().x()) * dy3 - (line->p1().y() - line2->p2().y()) * dx3 < 0) !=
                                  ((line->p2().x() - line2->p2().x()) * dy3 - (line->p2().y() - line2->p2().y()) * dx3 < 0)){
                           this->ID.push_back(i);
                           break;


                       }
                       else if(((line3->p1().x() -line->p2().x()) * dy1 - (line3->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line3->p2().x() -line->p2().x()) * dy1 - (line3->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line3->p2().x()) * dy4 - (line->p1().y() - line3->p2().y()) * dx4 < 0) !=
                                  ((line->p2().x() - line3->p2().x()) * dy4 - (line->p2().y() - line3->p2().y()) * dx4 < 0)){
                           this->ID.push_back(i);
                           break;
                       }
                       else if(((line4->p1().x() -line->p2().x()) * dy1 - (line4->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line4->p2().x() -line->p2().x()) * dy1 - (line4->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line4->p2().x()) * dy5 - (line->p1().y() - line4->p2().y()) * dx5 < 0) !=
                                  ((line->p2().x() - line4->p2().x()) * dy5 - (line->p2().y() - line4->p2().y()) * dx5 < 0)){
                           this->ID.push_back(i);
                           break;
                       }

                   }
               }
            }
        }
        update();

    }
    if(type==3||type==4){
        ID.clear();
        for(int i=0;i<cureditlayer->polygons.size();i++){
            if(cureditlayer->polygons[i].boundingRect().intersects(Rect)){
               for(int j=0;j<cureditlayer->polygons[i].size();j++){
                   if(cureditlayer->polygons[i][j].x()+5<=Rect.bottomRight().x()&&cureditlayer->polygons[i][j].x()-5>=Rect.topLeft().x()&&cureditlayer->polygons[i][j].y()+5<=Rect.bottomRight().y()&&cureditlayer->polygons[i][j].y()-5>=Rect.topLeft().y()){
                      this->ID.push_back(i);
                       break;
                    }
                   else{
                       QLineF *line1=new QLineF;
                       line1->setP1(Rect.topLeft());line1->setP2(Rect.bottomLeft());
                       QLineF *line2=new QLineF;
                       line2->setP1(Rect.bottomLeft());line2->setP2(Rect.bottomRight());
                       QLineF *line3=new QLineF;
                       line3->setP1(Rect.bottomRight());line3->setP2(Rect.topRight());
                       QLineF *line4=new QLineF;
                       line4->setP1(Rect.topRight());line4->setP2(Rect.topLeft());
                       QLineF *line=new QLineF;
                       if(j<cureditlayer->polygons[i].size()-1){
                          line->setP1(cureditlayer->polygons[i][j]);line->setP2(cureditlayer->polygons[i][j+1]);
                       }
                       else if(j=cureditlayer->polygons[i].size()-1){
                          line->setP1(cureditlayer->polygons[i][j]);line->setP2(cureditlayer->polygons[i][0]);
                       }
                       int dx1 = line->p2().x()-line->p1().x();
                       int dy1 = line->p2().y()-line->p1().y();
                       int dx2 = line1->p2().x()-line1->p1().x();
                       int dy2 = line1->p2().y()-line1->p1().y();
                       int dx3 = line2->p2().x()-line2->p1().x();
                       int dy3 = line2->p2().y()-line2->p1().y();
                       int dx4 = line3->p2().x()-line3->p1().x();
                       int dy4 = line3->p2().y()-line3->p1().y();
                       int dx5 = line4->p2().x()-line4->p1().x();
                       int dy5 = line4->p2().y()-line4->p1().y();
                       if(((line1->p1().x() -line->p2().x()) * dy1 - (line1->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line1->p2().x() -line->p2().x()) * dy1 - (line1->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line1->p2().x()) * dy2 - (line->p1().y() - line1->p2().y()) * dx2 < 0) !=
                                  ((line->p2().x() - line1->p2().x()) * dy2 - (line->p2().y() - line1->p2().y()) * dx2 < 0)){

                           this->ID.push_back(i);
                           break;


                       }
                       else if(((line2->p1().x() -line->p2().x()) * dy1 - (line2->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line2->p2().x() -line->p2().x()) * dy1 - (line2->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line2->p2().x()) * dy3 - (line->p1().y() - line2->p2().y()) * dx3 < 0) !=
                                  ((line->p2().x() - line2->p2().x()) * dy3 - (line->p2().y() - line2->p2().y()) * dx3 < 0)){
                           this->ID.push_back(i);
                           break;


                       }
                       else if(((line3->p1().x() -line->p2().x()) * dy1 - (line3->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line3->p2().x() -line->p2().x()) * dy1 - (line3->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line3->p2().x()) * dy4 - (line->p1().y() - line3->p2().y()) * dx4 < 0) !=
                                  ((line->p2().x() - line3->p2().x()) * dy4 - (line->p2().y() - line3->p2().y()) * dx4 < 0)){
                           this->ID.push_back(i);
                           break;


                       }
                       else if(((line4->p1().x() -line->p2().x()) * dy1 - (line4->p1().y() -line->p2().y())  * dx1 < 0) !=
                                  ((line4->p2().x() -line->p2().x()) * dy1 - (line4->p2().y() -line->p2().y()) * dx1 < 0) &&
                                  ((line->p1().x() - line4->p2().x()) * dy5 - (line->p1().y() - line4->p2().y()) * dx5 < 0) !=
                                  ((line->p2().x() - line4->p2().x()) * dy5 - (line->p2().y() - line4->p2().y()) * dx5 < 0)){
                           this->ID.push_back(i);
                           break;


                       }

                   }
                   if(cureditlayer->polygons[i].boundingRect().contains(Rect)){
                      this->ID.push_back(i);
                      break;
                   }
               }
            }
        }
        update();

    }
    }
    this->isMoved=false;
    this->isPressed=false;
}
void myPaintWidget::mouseReleaseCopy(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(Qt::RightButton == event->button()){
       setCursor(Qt::ArrowCursor);
       ID.clear();
       curState=NoneState;
    }
    update();
}
    this->isPressed=false;
}
void myPaintWidget::mousePressPntDelFromLine(QMouseEvent *event){
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==2){
        if(Qt::LeftButton == event->button()){
            for(int i=0;i<cureditlayer->linestring.size();i++){
                if(cureditlayer->linestring[i].size()>2){
                   QRect rect=cureditlayer->linestring[i].boundingRect();
                   rect.adjust(-5,-5,5,5);
                   if(rect.contains(event->pos().x(),event->pos().y())){
                      for(int j=0;j<cureditlayer->linestring[i].size();j++){
                          if(abs(event->pos().x()-cureditlayer->linestring[i][j].x())<=5&&abs(event->pos().y()-cureditlayer->linestring[i][j].y())<=5){
                           cureditlayer->linestring[i].removeAt(j);
                            break;
                          }
                      }
                   }
                }
                else {
                    QMessageBox::about(this,tr("提示信息"),tr("构成线要素至少需要2个点！   "));
                }
            }
        }
    }
    if(type==3||type==4){
       if (Qt::LeftButton == event->button()){
           for(int i=0;i<cureditlayer->polygons.size();i++){
               if(cureditlayer->polygons[i].size()>3){
                  QRect rect=cureditlayer->polygons[i].boundingRect();
                  rect.adjust(-5,-5,5,5);
                  if(rect.contains(event->pos().x(),event->pos().y())){
                     for(int j=0;j<cureditlayer->polygons[i].size();j++){
                       if(abs(event->pos().x()-cureditlayer->polygons[i][j].x())<=5&&abs(event->pos().y()-cureditlayer->polygons[i][j].y())<=5){
                         cureditlayer->polygons[i].removeAt(j);
                          break;
                       }
                     }
                  }
               }
               else {
                   QMessageBox::about(this,tr("提示信息"),tr("构成面要素至少需要3个点！   "));
               }
           }
       }
    }

    if(Qt::RightButton == event->button()){
        curState=NoneState;
     }
    update();
    }
    this->isPressed;
}

void myPaintWidget::mouseReleasePntAddToLine(QMouseEvent *event){

    this->isPressed = false;
}

void myPaintWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  //QPainterPath path;
  pen.setColor(Qt::darkCyan);
  pen.setWidth(1);
  brush=QBrush(Qt::darkCyan);
  if(type!=0)
     brush.setStyle(Qt::HorPattern);
  painter.setPen(pen);
  //painter.setBrush(brush);
  if(type==0){
     for(int i = 0;i<cureditlayer->ps.size();i++){
         QPoint p = cureditlayer->ps[i];
         painter.setBrush(brush);
         painter.drawEllipse(p,5,5);
         painter.setBrush(Qt::NoBrush);
     }
  }
  if(type==1){
     for(int i = 0;i<cureditlayer->lines.size();i++){
         QLineF pLine = cureditlayer->lines[i];
         painter.drawLine(pLine.p1(),pLine.p2());
     }
  }
  if(type==2){
     for(int i = 0;i<lines.size();i++){
         QLineF pLine =lines[i];
         painter.drawLine(pLine.p1(),pLine.p2());
     }
     for(int i=0;i<cureditlayer->linestring.size();i++){
         for(int j=0;j<cureditlayer->linestring[i].size()-1;j++){
             painter.drawLine(cureditlayer->linestring[i][j],cureditlayer->linestring[i][j+1]);
         }
     }
     if(curState==EditType||curState==PntAddToLine||curState==PntDelFromLine){
         for(int i=0;i<cureditlayer->linestring.size();i++){
             for(int j=0;j<cureditlayer->linestring[i].size();j++){
                 brush.setStyle(Qt::SolidPattern);
                 painter.setBrush(brush);
                 painter.drawEllipse(cureditlayer->linestring[i][j],5,5);
                 painter.setBrush(Qt::NoBrush);
             }
         }
     }
  }
  if(type==3){
     painter.drawConvexPolygon(polygon);
     for(int i = 0;i<cureditlayer->polygons.size();i++){
         QPolygon polygon=cureditlayer->polygons[i];
         painter.setBrush(brush);
         painter.drawConvexPolygon(polygon);
         painter.setBrush(Qt::NoBrush);

     }
     if(curState==EditType||curState==PntAddToLine||curState==PntDelFromLine){
         for(int i=0;i<cureditlayer->polygons.size();i++){
             for(int j=0;j<cureditlayer->polygons[i].size();j++){
                 brush.setStyle(Qt::SolidPattern);
                 painter.setBrush(brush);
                 painter.drawEllipse(cureditlayer->polygons[i][j],5,5);
                 painter.setBrush(Qt::NoBrush);
             }
         }
     }

  }
  if(type==4){
      if(curState!=EditType){
         QRect rect;
         rect.setTopLeft(startPnt);
         rect.setBottomRight(endPnt);
         if(this->isPressed)
         painter.drawRect(rect);

      }
      for(int i = 0;i<cureditlayer->polygons.size();i++){
          QPolygon polygon=cureditlayer->polygons[i];
          painter.setBrush(brush);
          painter.drawConvexPolygon(polygon);
          painter.setBrush(Qt::NoBrush);
      }
      if(curState==EditType||curState==PntAddToLine||curState==PntDelFromLine){
          for(int i=0;i<cureditlayer->polygons.size();i++){
              for(int j=0;j<cureditlayer->polygons[i].size();j++){
                  brush.setStyle(Qt::SolidPattern);
                  painter.setBrush(brush);
                  painter.drawEllipse(cureditlayer->polygons[i][j],5,5);
                  painter.setBrush(Qt::NoBrush);
              }
          }
      }
  }
  if(type==5){
      int r0;
      r0=sqrt((startPnt.x()-endPnt.x())*(startPnt.x()-endPnt.x())+(startPnt.y()-endPnt.y())*(startPnt.y()-endPnt.y()));
      painter.drawEllipse(startPnt,r0,r0);
      for(int i = 0;i<cicles.size();i++){
          myCicle* cicle = cicles[i];
          painter.setBrush(Qt::darkCyan);
          painter.drawEllipse(cicle->startPnt,cicle->r,cicle->r);
          painter.setBrush(Qt::NoBrush);
      }
  }
  if(curState==SelectType||curState==MoveType||curState==CopyType){
      if(curState==SelectType&&this->isPressed&&this->isMoved){
          Rect.setTopLeft(startPnt);
          Rect.setBottomRight(endPnt);
          painter.setPen(Qt::black);
          painter.drawRect(Rect);
      }
       if(type==0){
          for(int i=0;i<ID.size();i++){
              pen.setColor(Qt::transparent);
              painter.setPen(pen);
              painter.setBrush(brush1);
              painter.drawEllipse(cureditlayer->ps[ID[i]],5,5);
              painter.setBrush(Qt::NoBrush);

          }
           timer->start(300);

      }
       if(type==2){
          for(int i=0;i<ID.size();i++){
              for(int j=0;j<cureditlayer->linestring[ID[i]].size()-1;j++){
                  painter.setPen(pen1);
                  painter.drawLine(cureditlayer->linestring[ID[i]][j],cureditlayer->linestring[ID[i]][j+1]);
              }

          }
           timer->start(300);


      }
       if((type==3||type==4)){
          for(int i=0;i<ID.size();i++){
                  painter.setPen(pen1);
                  brush1.setStyle(Qt::HorPattern);
                  painter.setBrush(brush1);
                  painter.drawConvexPolygon(cureditlayer->polygons[ID[i]]);
          }
           timer->start(300);


      }
  }
 if(curanlyse==qiujiao||curanlyse==qiucha||curanlyse==qiubing){
       QPolygon poly;
     if(curanlyse==qiujiao){

           poly=cureditlayer->polygons[ID[0]].intersected(cureditlayer->polygons[ID[1]]);
 }
     if(curanlyse==qiucha){

           poly=cureditlayer->polygons[ID[0]].subtracted(cureditlayer->polygons[ID[1]]);
 }
     if(curanlyse==qiubing){

           poly=cureditlayer->polygons[ID[0]].united(cureditlayer->polygons[ID[1]]);
 }
     painter.setPen(pen1);
     brush1.setStyle(Qt::SolidPattern);
     painter.setBrush(brush1);
     painter.drawConvexPolygon(poly);
      timer->start(300);
}
}

void myPaintWidget::mousePressEvent(QMouseEvent *event)
{
    if(curState==DrawType)
    {
        mousePressDraw(event);

    }
    else if(curState==MoveType)
    {
        mousePressMove(event);

    }
    else if(curState==EditType)
    {
        mousePressEdit(event);

    }
    /*else if(curState==NoneState)
    {

    }
    else if(curState==DeleteType)
    {
        mousePressDelete(event);
    }
    else if(curState==SceneMoveType)
    {
        mousePressWander(event);
    }*/
    else if(curState==SelectType)
    {
        mousePressSelect(event);

    }
    else if(curState==CopyType)
    {
        mousePressCopy(event);

    }
    else if(curState==PntDelFromLine)
    {
        mousePressPntDelFromLine(event);
    }
    else if(curState==PntAddToLine)
    {
        mousePressPntAddToLine(event);

    }
    /*else if(curState==LineCut)
    {
        mousePressLineCut(event);
    }
    else if(curState==LineLink)
    {
        mousePressLineLink(event);
    }*/
   }

void myPaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(curState==DrawType)
    {
        mouseMoveDraw(event);

    }
    else if(curState==MoveType)
    {
        mouseMoveMove(event);

    }
    else if(curState==EditType)
    {
        mouseMoveEdit(event);

    }
    /*else if(curState==NoneState)
    {

    }
    else if(curState==SceneMoveType)
    {
        mouseMoveWander(event);
    }*/
   else if(curState==SelectType)
    {
        mouseMoveSelect(event);

    }
    else if(curState==CopyType)
     {
         mouseMoveCopy(event);

     }
    else if(curState==PntAddToLine)
    {
        mouseMovePntAddToLine(event);

    }
    /*else if(curState==LineCut)
    {
        mouseMoveLineCut(event);
    }*/

}


void myPaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(curState==DrawType)
    {
        mouseReleaseDraw(event);

    }
    else if(curState==MoveType)
    {
        mouseReleaseMove(event);

    }
    else if(curState==EditType)
    {
        mouseReleaseEdit(event);

    }
    /* else if(curState==NoneState)
    {

    }
    else if(curState==SceneMoveType)
    {
        mouseReleaseWander(event);
    }*/
    else if(curState==SelectType)
    {
        mouseReleaseSelect(event);

    }
    else if(curState==CopyType)
    {
        mouseReleaseCopy(event);

    }
   /*else if(curState==PntDelFromLine)
    {
        mouseReleasePntDelFromLine(event);
    }*/
    else if(curState==PntAddToLine)
    {
        mouseReleasePntAddToLine(event);

    }
   /* else if(curState==LineCut)
    {
        mouseReleaseLineCut(event);
    }
    else if(curState==LineLink)
    {
        mouseReleaseLineLink(event);
    }*/
}
void myPaintWidget::deleteYffeature(){
    curState=DeleteType;
    cureditlayer=NULL;
    for(int i=0;i<this->layers.count();i++){
        if(this->layers[i]->isEdit==true)
            cureditlayer=this->layers[i];
    }
    if(cureditlayer!=NULL){
    if(type==0){
        int k=0;
        for(int i=0;i<ID.size();i++){
            cureditlayer->ps.remove(ID[i]-k);
            k++;
        }
        ID.clear();
    }
    if(type==2){
        int k=0;
        for(int i=0;i<ID.size();i++){
            cureditlayer->linestring.remove(ID[i]-k);
            k++;
        }
        ID.clear();
    }
    if(type==3||type==4){
        int k=0;
        for(int i=0;i<ID.size();i++){
            cureditlayer->polygons.remove(ID[i]-k);
            k++;
        }
        ID.clear();
    }

   }
    update();
    }

void myPaintWidget::drawlayer(int a,QString b){
    Yflayer* lay=new Yflayer(a,b);
   // lay->isEdit=true;
    layers.push_back(lay);
}

void myPaintWidget::deletelayer(QString name){

}

