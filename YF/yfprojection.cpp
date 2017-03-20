#include "yfprojection.h"

//屏幕坐标转经纬度
QPointF ScreenToCoor(QPoint screen, QRect rectscr, QRectF rectgeo)
{//coor:屏幕坐标；rectscr：屏幕坐标范围；rectgeo：地理坐标范围，屏幕坐标转为经纬度
    double scaleX=0,scaleY=0,scale=0;//X,Y方向比例因子,取代表实际范围较大/小的因子作为比例尺
    scaleX=qAbs(rectgeo.width())/qAbs(rectscr.width());//每个像素点代表的实际地理范围
    scaleY=qAbs(rectgeo.height())/qAbs(rectscr.height());
    scale=scaleX>scaleY?scaleX:scaleY;
    double lon=0,lat=0;//经纬度
    lon=rectgeo.left()+scale*(screen.x()-rectscr.left());
    lat=rectgeo.top()+scale*(rectscr.bottom()-screen.y());
    return QPointF(lon,lat);
}
//经纬度转屏幕坐标
QPoint CoorToScreen(QPointF coor, QRect rectscr, QRectF rectgeo)
{
    double scaleX=0,scaleY=0,scale=0;//X,Y方向比例因子,取代表实际范围较大/小的因子作为比例尺
    scaleX=qAbs(rectgeo.width())/qAbs(rectscr.width());//每个像素点代表的实际地理范围
    scaleY=qAbs(rectgeo.height())/qAbs(rectscr.height());
    scale=scaleX>scaleY?scaleX:scaleY;
    int xpos=0,ypos=0;
    xpos=rectscr.left()+(int)((coor.x()-rectgeo.left())/scale);
    ypos=rectscr.bottom()-(int)((coor.y()-rectgeo.top())/scale);
//    qDebug()<<rectscr.left()<<rectgeo.left()<<rectscr.bottom()<<rectgeo.bottom();
    return QPoint(xpos,ypos);

}

/***************************************************************************************************************/
//高斯投影
//6度带宽   54年北京坐标系
//高斯投影由经纬度(Unit:DD)反算大地坐标(含带号，Unit:Metres)
QPointF CoorToGauss(double longitude, double latitude)
{
    if(longitude<0)
        longitude*=-1;
    if(latitude<0)
        latitude*=-1;
    int ProjNo=0;    int ZoneWide;   ////带宽
    double  longitude1,latitude1, longitude0,latitude0, X0,Y0, xval,yval;
    double  a,f, e2,ee, NN, T,C,A, M, iPI;
    iPI = 0.0174532925199433;   ////3.1415926535898/180.0;
    ZoneWide = 6;     ////6度带宽
    a=6378245.0;   f=1.0/298.3;      //54年北京坐标系参数
    ////a=6378140.0;   f=1/298.257;      //80年西安坐标系参数
    ProjNo = (int)(longitude / ZoneWide) ;
    longitude0 = ProjNo * ZoneWide + ZoneWide / 2;
    longitude0 = longitude0 * iPI ;
    latitude0=0;
    longitude1 = longitude * iPI ;   //经度转换为弧度
    latitude1 = latitude * iPI ;     //纬度转换为弧度
    e2=2*f-f*f;
    ee=e2*(1.0-e2);
    NN=a/sqrt(1.0-e2*sin(latitude1)*sin(latitude1));
    T=tan(latitude1)*tan(latitude1);
    C=ee*cos(latitude1)*cos(latitude1);
    A=(longitude1-longitude0)*cos(latitude1);
    M=a*((1-e2/4-3*e2*e2/64-5*e2*e2*e2/256)*latitude1-(3*e2/8+3*e2*e2/32+45*e2*e2*e2/1024)*sin(2*latitude1)
         +(15*e2*e2/256+45*e2*e2*e2/1024)*sin(4*latitude1)-(35*e2*e2*e2/3072)*sin(6*latitude1));
    xval = NN*(A+(1-T+C)*A*A*A/6+(5-18*T+T*T+72*C-58*ee)*A*A*A*A*A/120);
    yval = M+NN*tan(latitude1)*(A*A/2+(5-T+9*C+4*C*C)*A*A*A*A/24
                                +(61-58*T+T*T+600*C-330*ee)*A*A*A*A*A*A/720);
    X0 = 1000000L*(ProjNo+1)+500000L;
    Y0 = 0;
    xval =xval+X0;  yval = yval+Y0;
    QPointF*dot=new QPointF(xval,yval);
    return *dot;
}

//高斯投影由大地坐标(Unit:Metres)反算经纬度(Unit:DD)
QPointF GaussToCoor(double X, double Y)
{
    int ProjNo;    int ZoneWide;   ////带宽
    double longitude1,latitude1, longitude0,latitude0, X0,Y0, xval,yval;
    double e1,e2,f,a, ee, NN, T,C, M, D,R,u,fai, iPI;
    iPI = 0.0174532925199433;   ////3.1415926535898/180.0;
    a = 6378245.0;   f = 1.0/298.3;    //54年北京坐标系参数
    ////a=6378140.0;   f=1/298.257;      //80年西安坐标系参数
    ZoneWide = 6;     ////6度带宽
    ProjNo = (int)(X/1000000L) ;    //查找带号
    longitude0 = (ProjNo-1) * ZoneWide + ZoneWide / 2;
    longitude0 = longitude0 * iPI ;     //中央经线
    X0 = ProjNo*1000000L+500000L;
    Y0 = 0;
    xval = X-X0;  yval = Y-Y0;      //带内大地坐标
    e2 = 2*f-f*f;
    e1 = (1.0-sqrt(1-e2))/(1.0+sqrt(1-e2));
    ee = e2/(1-e2);
    M = yval;
    u = M/(a*(1-e2/4-3*e2*e2/64-5*e2*e2*e2/256));
    fai = u+(3*e1/2-27*e1*e1*e1/32)*sin(2*u)+(21*e1*e1/16-55*e1*e1*e1*e1/32)*sin(4*u)
            +(151*e1*e1*e1/96)*sin(6*u)+(1097*e1*e1*e1*e1/512)*sin(8*u);
    C = ee*cos(fai)*cos(fai);
    T = tan(fai)*tan(fai);
    NN = a/sqrt(1.0-e2*sin(fai)*sin(fai));
    R = a*(1-e2)/sqrt((1-e2*sin(fai)*sin(fai))*(1-e2*sin(fai)*sin(fai))*(1-e2*sin(fai)*sin(fai)));
    D = xval/NN;
    //计算经度(Longitude) 纬度(Latitude)
    longitude1 = longitude0+(D-(1+2*T+C)*D*D*D/6+(5-2*C+28*T-3*C*C+8*ee+24*T*T)*D*D*D*D*D/120)/cos(fai);
    latitude1 = fai -(NN*tan(fai)/R)*(D*D/2-(5+3*T+10*C-4*C*C-9*ee)*D*D*D*D/24
                                      +(61+90*T+298*C+45*T*T-256*ee-3*C*C)*D*D*D*D*D*D/720);
    //转换为度 DD
    double longitude;
    double latitude;
    longitude = longitude1 / iPI;
    latitude = latitude1 / iPI;
    QPointF*dot=new QPointF(longitude,latitude);
    return *dot;
}

//批量投影转换
QVector<QPointF> MutiCoorToGauss(QVector<QPointF> muticoorpos)
{
    QVector<QPointF> mutigausspos;
    for(int i=0;i<muticoorpos.length();i++)
    {
        mutigausspos.push_back(CoorToGauss(muticoorpos[i].x(),muticoorpos[i].y()));
    }
    return mutigausspos;
}
QVector<QPointF> MutiGaussToCoor(QVector<QPointF> mutigausspos)
{
    QVector<QPointF> muticoorpos;
    for(int i=0;i<mutigausspos.length();i++)
    {
        muticoorpos.push_back(GaussToCoor(mutigausspos[i].x(),mutigausspos[i].y()));
    }
    return muticoorpos;
}
double GetDistance(double lon1, double lat1, double lon2, double lat2)
{
#define a_2d 6378137		//WGS84坐标系下的椭球长半轴6378137
#define e_2d 0.006694380	//偏心率
#define h_2d 15
#define DEG_2_RAD 0.01745329252		// 1度＝π/180 弧度 ( ≈0.017453弧度 )
#define RAD_2_DEG 57.29577951290	//因为    π弧度＝180° 所以   1弧度＝180° / π （≈57.3°）

    double x_rads = fabs(lon1) * DEG_2_RAD;		//x用经度换算为弧度
    double y_rads = fabs(lat1) * DEG_2_RAD;		//y用纬度换算为弧度

    double n_2ds = a_2d/sqrt(1 - e_2d * sin(y_rads) * sin(y_rads));

    double x_2d = (n_2ds + h_2d) * cos(y_rads) * cos(x_rads);
    double y_2d = (n_2ds + h_2d) * cos(y_rads) * sin(x_rads);
    double z_2d = (n_2ds * (1 - e_2d) + h_2d) * sin(y_rads);

    double x_radm = fabs(lon2) * DEG_2_RAD;
    double y_radm = fabs(lat2) * DEG_2_RAD;

    double n_2dm = a_2d/sqrt(1 - e_2d * sin(y_radm) * sin(y_radm));

    double x_2d_mark = (n_2dm + h_2d) * cos(y_radm) * cos(x_radm);
    double y_2d_mark = (n_2dm + h_2d) * cos(y_radm) * sin(x_radm);
    double z_2d_mark = (n_2dm * (1 - e_2d) + h_2d) * sin(y_radm);

    double t1 = x_2d * x_2d + y_2d * y_2d + z_2d * z_2d;
    double t = (t1 - (x_2d * x_2d_mark + y_2d * y_2d_mark + z_2d * z_2d_mark))/t1;
    double tempx = x_2d_mark + (t-1) * x_2d;
    double tempy = y_2d_mark + (t-1) * y_2d;
    double tempz = z_2d_mark + (t - 1) * z_2d;
    double hy1 = (x_2d * x_2d + y_2d * y_2d)/z_2d * tempz - x_2d * tempx - y_2d * tempy;
    double hy2 = sqrt(x_2d * x_2d + y_2d * y_2d + ((x_2d * x_2d + y_2d * y_2d)/z_2d) * ((x_2d * x_2d + y_2d * y_2d)/z_2d));
    double hy3 = sqrt(tempx * tempx + tempy * tempy + tempz * tempz);
    double hy = hy1/(hy2 * hy3);
           hy = acos(hy) * RAD_2_DEG;

    double condition = (y_2d - x_2d) * tempx + (x_2d * x_2d - x_2d * y_2d) * tempy/y_2d;
    double distance = (x_2d_mark - x_2d) * (x_2d_mark - x_2d) + (y_2d_mark - y_2d) * (y_2d_mark - y_2d) + (z_2d_mark - z_2d) * (z_2d_mark - z_2d);
    distance = sqrt(distance);
    return distance;
}
double GetDistance1ine(QVector<QPointF> line)//计算折线的长度
{
    double result=0;
    for(int i=1;i<line.length();i++)
    {
        result+=GetDistance(line[i-1].x(),line[i-1].y(),line[i].x(),line[i].y());
    }
    return result;
}
// calculate Area经纬度坐标下的球面多边形，先经过高斯投影转为平面坐标，再通过平面坐标计算面积
double GetArea(QVector<QPointF> poly)
{
    QVector<QPointF>poly1=MutiCoorToGauss(poly);
     qDebug()<<"GetArea"<<endl;
    for(int i=0;i<poly1.length();i++){
        qDebug()<<QString::number(poly1[i].x(),'f',6)<<QString::number(poly1[i].y(),'f',6);
    }
    int iCycle,iCount;
    double iArea;
    iCycle=0;
    iArea=0;
    iCount=poly1.size();

    for(iCycle=0;iCycle<iCount;iCycle++)
    {//面积单位转换为平方千米，除以1000000
        qDebug()<<iCycle<<QString::number((poly1[iCycle].x()*poly1[(iCycle+1)%iCount].y()-poly1[(iCycle+1) % iCount].x()*poly1[iCycle].y())/1000000,'f',6);
        iArea=iArea+(poly1[iCycle].x()*poly1[(iCycle+1)%iCount].y()-poly1[(iCycle+1) % iCount].x()*poly1[iCycle].y())/1000000;
        qDebug()<<QString::number(iArea,'f',6);
    }

    return 0.5*iArea;
}
