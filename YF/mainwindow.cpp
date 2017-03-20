#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p=new myPaintWidget(this);
    p->setAutoFillBackground(true);
    QPalette pp;
    pp.setColor(QPalette::Background,QColor(255,255,255));
    p->setPalette(pp);
    setCentralWidget(p);
    //    getLayer();        //读取图层
    //    loadLayer();        //加载图层tree视图

    /*******************连接信号和槽*********************/
    //treeWidget节点双击事件

//    connect(ui->listLayer,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
//            this,SLOT(deleLayer(QTreeWidgetItem*,int)));
    //可见性
//    connect(ui->listLayer,SIGNAL(itemChanged(QTreeWidgetItem*,int)),
//            this,SLOT(checkLayerState(QTreeWidgetItem*,int)));
    connect(ui->listLayer,SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            this,SLOT(choosedLayer(QTreeWidgetItem*,int)));

}
//读取图层信息的槽函数
void MainWindow::GetLayerDataSlot(int a)
{
    qDebug()<<"getlayersuccess"<<endl;
    ISDATALOAD=1;
    for(int i=0;i<PointList.size();i++)
        p->drawlayer(1,PointList[i]);
    for(int i=0;i<LineList.size();i++)
        p->drawlayer(2,LineList[i]);
    for(int i=0;i<PolyList.size();i++)
        p->drawlayer(3,PolyList[i]);
    qDebug()<<p->layers[0]->Name;
    QVector<YFPointLayer> temppointlayer=getdatathread->GetPointData();
    QVector<YFLineLayer> templinelayer=getdatathread->GetLineData();
    QVector<YFPolyLayer> temppolylayer=getdatathread->GetPolyData();
    for(int i=0;i<temppointlayer.size();i++)//遍历每一个图层
    {    QVector<QPoint> scrpoint;//一个点图层数据转换后屏幕点坐标集合
        QString layername=temppointlayer[i].layername;//图层名

        QRectF rpoints=GetPointLayerRect(temppointlayer[i].pointsdata);
        for(int j=0;j<temppointlayer[i].pointsdata.size();j++)
        {
            scrpoint.append(CoorToScreen(temppointlayer[i].pointsdata[j],screen,rpoints));
        }
        for(int a=0;a<p->layers.size();a++){
            if(p->layers[a]->Name==layername){
                p->layers[a]->ps=scrpoint;
                break;
            }
        }

    }
    for(int i=0;i<templinelayer.size();i++)
    {    QVector<QLineString> scrline;QLineString temp;//存储每个图层的转换为屏幕坐标之后的数据
        QRectF rlines=GetLineLayerRect(templinelayer[i].linesdata);
        QString layername=templinelayer[i].layername;
        for(int j=0;j<templinelayer[i].linesdata.size();j++)//每一条线
        {
            temp.clear();
            for(int ij=0;ij<templinelayer[i].linesdata[j].size();ij++)//每一条线上的每一个点
            {
                temp.append(CoorToScreen(templinelayer[i].linesdata[j][ij],screen,rlines));
                qDebug()<<temp[ij].x()<<" "<<temp[ij].y();
            }
            scrline.append(temp);
        }
        for(int a=0;a<p->layers.size();a++){
            if(p->layers[a]->Name==layername){
                p->layers[a]->linestring=scrline;
                break;
            }
        }
    }
    for(int i=0;i<temppolylayer.size();i++)
    {
        QVector<QPolygon> srcpoly;QPolygon temp;//存储每个图层的转换为屏幕坐标之后的数据
        QRectF rpolys=GetPolyLayerRect(temppolylayer[i].polysdata);
                QString layername=temppolylayer[i].layername;
        for(int j=0;j<temppolylayer[i].polysdata.size();j++)//每一条线
        {
            temp.clear();
            for(int ij=0;ij<temppolylayer[i].polysdata[j].size();ij++)//每一条线上的每一个点
            {
                temp.append(CoorToScreen(temppolylayer[i].polysdata[j][ij],screen,rpolys));

            }
            srcpoly.append(temp);
        }
        for(int a=0;a<p->layers.size();a++){
            if(p->layers[a]->Name==layername){
                p->layers[a]->polygons=srcpoly;
                break;
            }
        }
    }

}

    MainWindow::~MainWindow()
    {
        delete p;
        delete ui;
    }

    /*************************************可视化加载   未完成*****************************************/
    void MainWindow::showLayer(QTreeWidgetItem * item,int column){
        QString layerName=item->text(column);
        //    if(layerName!="点图层"&&layerName!="线图层"&&layerName!="面图层"){
        //        QMessageBox::warning(this,tr("提示"),(layerName),QMessageBox::Yes);
        //    }
    }

    /*************************************检测图层是否勾选*****************************************/
    void MainWindow::checkLayerState(QTreeWidgetItem* item,int column){
        if(ISDATALOAD==1){
            if(item->checkState(column)==Qt::Checked){
                QMessageBox::warning(this,tr("提示"),("显示图层"),QMessageBox::Yes);
                //showLayer(item->text(0));           显示图层
            }else if(item->checkState(column)==Qt::Unchecked){
                QMessageBox::warning(this,tr("提示"),("隐藏图层"),QMessageBox::Yes);
                //hideLayer(item->text(0));
            }
        }
    }

    /*************************************判断选中的图层名和类型*****************************************/
    void MainWindow::choosedLayer(QTreeWidgetItem* item,int column){
//        setAllUnchecked();
        QString layerName=item->text(column);
        if(layerName!="点图层"&&layerName!="线图层"&&layerName!="面图层"){
            for(int i=0;i<p->layers.size();i++)
                if(p->layers[i]->Name==layerName)
                    p->cureditlayer=p->layers[i];

            CHOOSEDLAYER=layerName;
            QString TYPE=item->parent()->text(0);
            if(TYPE=="点图层"){
                LAYERTYPE=1;
                p->type=0;
            }else if(TYPE=="线图层"){
                LAYERTYPE=2;
                p->type=2;
            }else if(TYPE=="面图层"){
                LAYERTYPE=3;
                p->type=3;
            }
         p->update();
//            item->setCheckState(0,Qt::Checked);
            qDebug()<<CHOOSEDLAYER<<QString::number(LAYERTYPE);

        }
    }




    /*****************************获取要打开的图层名*************************/
    void MainWindow::getLayer(){
        PointList.clear();
        LineList.clear();
        PolyList.clear();
        PointList=SelectLayer::checkPoint;
        LineList=SelectLayer::checkLine;
        PolyList=SelectLayer::checkPoly;
        PointLayerNum=PointList.size();
        LineLayerNum=LineList.size();
        PolyLayerNum=PolyList.size();
        getdatathread=new GetDataThread(UserData::mysql,PointList,LineList,PolyList);
        connect(getdatathread, SIGNAL(GetDataThreadSignal(int)), this, SLOT(GetLayerDataSlot(int)));
        getdatathread->start();
    }



    /********************************************读取图层*******************************************/
    void MainWindow::readLayer(){
        //数据库连接
        YFMYSQL getLayer(UserData::USERNAME,UserData::PASSWORD);
        getLayer.YFOpenConn();
        if(!getLayer.YFIsOpen()){
            QMessageBox::warning(this,tr("提示"),("连接失败，错误代码：E001"),QMessageBox::Yes);
        }
        //清空数组
        PointList.clear();
        LineList.clear();
        PolyList.clear();

        //获取图层名 读入QStringList
        QSqlQuery queryPoint=getLayer.YFDoSQLSelect("select * from ManageTable where tableType=1;");
        while(queryPoint.next()){
            PointList<<QString(queryPoint.value(0).toString());
            PointLayerNum++;
        }
        QSqlQuery queryLine=getLayer.YFDoSQLSelect("select * from ManageTable where tableType=2;");
        while(queryLine.next()){
            LineList<<QString(queryLine.value(0).toString());
            LineLayerNum++;
        }
        QSqlQuery queryPoly=getLayer.YFDoSQLSelect("select * from ManageTable where tableType=3;");
        while(queryPoly.next()){
            PolyList<<QString(queryPoly.value(0).toString());
            PolyLayerNum++;
        }
        // 关闭数据库连接
        getLayer.YFCloseConn();
    }
    /*****************************************加载图层tree视图******************************************/
    void MainWindow::loadLayer(){
        removeAllLayer();
        ui->listLayer->setColumnCount(1);
        ui->listLayer->setHeaderLabel(tr("图层"));      //父节点

        QTreeWidgetItem *pointItem = new QTreeWidgetItem(ui->listLayer,QStringList(QString("点图层"))); //新增节点
        if(PointLayerNum!=0){
            for(int i=0;i<PointLayerNum;i++){
                QTreeWidgetItem *pointLayer = new QTreeWidgetItem(pointItem,QStringList(PointList.at(i))); //子节点
                pointLayer->setCheckState(0,Qt::Unchecked);         //设置可选
                pointItem->addChild(pointLayer); //添加子节点
            }
        }
        QTreeWidgetItem *lineItem = new QTreeWidgetItem(ui->listLayer,QStringList(QString("线图层")));
        if(LineLayerNum!=0){
            for(int i=0;i<LineLayerNum;i++){
                QTreeWidgetItem *lineLayer = new QTreeWidgetItem(lineItem,QStringList(LineList.at(i))); //子节点
                lineLayer->setCheckState(0,Qt::Unchecked);          //设置可选
                lineItem->addChild(lineLayer); //添加子节点
            }
        }
        QTreeWidgetItem *polyItem = new QTreeWidgetItem(ui->listLayer,QStringList(QString("面图层")));
        if(PolyLayerNum!=0){
            for(int i=0;i<PolyLayerNum;i++){
                QTreeWidgetItem *polyLayer = new QTreeWidgetItem(polyItem,QStringList(PolyList.at(i))); //子节点
                polyLayer->setCheckState(0,Qt::Unchecked);          //设置可选
                polyItem->addChild(polyLayer); //添加子节点
            }
        }
        ui->listLayer->expandAll();     //展开树
    }
    /**************************************移除所有图层的视图*******************************************/
    void MainWindow::removeAllLayer(){
        ui->listLayer->clear();
    }

    /***************************************删除子节点*********************************************/
    void MainWindow::deleteCurrentItem(){

    }
    /******************************************树视图加入一个图层******************************************/
    void MainWindow::insertLayer(QString layerName,int TYPE){
        p->drawlayer(TYPE,layerName);
        switch (TYPE) {
        case 1:
            PointList<<layerName;
            PointLayerNum++;
            break;
        case 2:
            LineList<<layerName;
            LineLayerNum++;
            break;
        case 3:
            PolyList<<layerName;
            PolyLayerNum++;
            break;
        default:
            break;
        }
//        removeAllLayer();
        loadLayer();
    }
    /******************************************向数据库加入一个图层******************************************/
    void MainWindow::insertLayerIntoMysql(YFMYSQL& sql,QString layerName, int TYPE){
        if(!sql.YFIsOpen())
        {
            sql.YFOpenConn();
            qDebug()<<"Database Open InsertLayer into table"<<endl;
        }
        QString sqlName;
        QString sqlType;
        QString sql2;
        switch (TYPE) {
        case 1:
            sqlName="YFPoint";
            sqlType="POINT";
            sql2="INSERT into ManageTable values('"+layerName+"',1);";
            break;
        case 2:
            sqlName="YFLineString";
            sqlType="LINESTRING";
            sql2="INSERT into "+UserData::USERNAME+".ManageTable values('"+layerName+"',2);";
            break;
        case 3:
            sqlName="YFPolygon";
            sqlType="POLYGON";
            sql2="INSERT into ManageTable values('"+layerName+"',3);";
            break;
        default:
            break;
        }
        QString sql1="CREATE TABLE "+layerName+" (id INT NOT NULL AUTO_INCREMENT,"+sqlName+" "+sqlType+" NOT NULL, PRIMARY KEY (id))ENGINE = MyISAM;";
        if(!sql.YFDoSQLExec(sql1)){QMessageBox::warning(this,tr("提示"),("新建图层失败"),QMessageBox::Yes);};
        if(!sql.YFDoSQLExec(sql2)){QMessageBox::warning(this,tr("提示"),("管理数据插入失败"),QMessageBox::Yes);};
    }

    void MainWindow::deleteLayerfromMysql(YFMYSQL& sql,QString layerName){
        if(!sql.YFIsOpen())
        {
            sql.YFOpenConn();
            qDebug()<<"Database delete layer from sql"<<endl;
        }
        QString sql1="DELETE FROM ManageTable where TableName='"+layerName+"';";
        QString sql2="DROP TABLE "+layerName+";";
        qDebug()<<sql1<<endl<<sql2;
        if(!sql.YFDoSQLExec(sql1)){QMessageBox::warning(this,tr("提示"),("管理数据删除失败"),QMessageBox::Yes);};
        if(!sql.YFDoSQLExec(sql2)){QMessageBox::warning(this,tr("提示"),("图层删除失败"),QMessageBox::Yes);};
    }


    void MainWindow::receiveNewLayerSignal(QString s,int i){
        QString iii=QString::number(i);
        qDebug()<<"新建图层成功"<<s<<iii;
        insertLayer(s,i);
        insertLayerIntoMysql(UserData::mysql,s,i);
    }

    void MainWindow::receiveReloadSignal(){
        qDebug()<<"接收图层名成功";
        getLayer();
        loadLayer();
    }

    /******************************************查询当前表的属性*******************************************/
    QVector<Attribute> MainWindow::GetAttributeOfTable(YFMYSQL &sql,QString tablename){
        if(!sql.YFIsOpen())
        {
            sql.YFOpenConn();
            qDebug()<<"Database Open GetAttributeOfTable"<<endl;
        }
        QVector<Attribute> attr;
        QString str="desc "+tablename+";";
        sql.YFDoSQLSelect(str);
        if(sql.query.next())
        {
            do{//将图层所有字段信息添加到QVector<Attribute>数组中
                Attribute a;
                a.attributename=sql.query.value(0).toString();
                a.attributetype=sql.query.value(1).toString();
                attr.push_back(a);
            }while(sql.query.next());
            for(int i=0;i<attr.size();i++)
            {
                qDebug()<<attr[i].attributename<<" "<<attr[i].attributetype;
            }
        }
        else{qDebug()<<"query GetAttributeOfTable failed"<<sql.YFSQLQueryError();}
        //        sql.YFCloseConn();
        qDebug()<<"Database Close UpdateAttributeOfTable"<<endl;
        return attr;
    }

    QVector<QStringList> MainWindow::GetValueOfAttr(YFMYSQL& sql,QStringList attrname,QString tablename){
        if(!sql.YFIsOpen())
        {
            sql.YFOpenConn();
            qDebug()<<"Database Open GetValueOfAttr"<<endl;
        }
        QVector<QStringList> value;
        for(int i=0;i<attrname.size();i++){
            QStringList s;
            QString str="SELECT "+attrname.at(i) +" From "+tablename+";";
            qDebug()<<attrname.at(i);
            sql.YFDoSQLSelect(str);
            if(sql.query.next()){
                do{
                    s<<sql.query.value(0).toString();
                    qDebug()<<sql.query.value(0).toString();
                }while(sql.query.next()) ;
            }else{qDebug()<<"query GetValueOfAttr failed"<<sql.YFSQLQueryError();}
            value.push_back(s);
        }
        qDebug()<<"query value of attr success";
        return value;
    }

    /*************************************新建图层*****************************************/
    void MainWindow::on_action_New_triggered()
    {
        NewLayer* newlayerDlg=new NewLayer(this);
        newlayerDlg->setWindowTitle("新建图层");
        connect(newlayerDlg,SIGNAL(sendNewLayerSignal(QString,int)),this,SLOT(receiveNewLayerSignal(QString,int)));
        newlayerDlg->show();

    }


    /*************************************打开图层*****************************************/
    void MainWindow::on_action_Open_triggered()
    {
        ISDATALOAD=0;
        SelectLayer *sele = new SelectLayer(this);
        sele->setWindowTitle("打开图层");
        connect(sele, SIGNAL(sendReloadSignal()), this, SLOT(receiveReloadSignal()));
        sele->show();
    }


    /*************************************开始编辑*****************************************/
    void MainWindow::on_action_StartEdit_triggered()
    {
        ISEDITING=1;
        for(int i=0;i<p->layers.size();i++)
            if(CHOOSEDLAYER==p->layers[i]->Name)
                p->layers[i]->isEdit=true;
    }
    /*************************************结束编辑*****************************************/


    void MainWindow::on_action_StopEdit_triggered()
    {
        ISEDITING=0;
        for(int i=0;i<p->layers.size();i++)
            if(CHOOSEDLAYER==p->layers[i]->Name){
                p->layers[i]->isEdit=false;
                p->curState=p->viewState::NoneState;
                p->ID.clear();
                // p->cureditlayer=NULL;
            }
    }

    void MainWindow::on_action_AddPoint_triggered()
    {
        p->curState=p->viewState::DrawType;
        p->type=0;
    }

    void MainWindow::on_Select_triggered()
    {
        p->curState=p->viewState::SelectType;
        if(LAYERTYPE==1)
            p->type=0;
        if(LAYERTYPE==2)
            p->type=2;
        if(LAYERTYPE==3)
            p->type=3;
    }

    void MainWindow::on_action_MovePoint_triggered()
    {
        p->curState=p->viewState::MoveType;
        p->type=0;
    }

    void MainWindow::on_action_DelePoint_triggered()
    {
        p->curState=p->viewState::DeleteType;
        p->deleteYffeature();

    }

    void MainWindow::on_CopyPoint_triggered()
    {
        p->curState=p->viewState::CopyType;
        p->type=0;
    }

    void MainWindow::on_action_AddLine_triggered()
    {
        p->type=2;
        p->curState=p->viewState::DrawType;

    }

    void MainWindow::on_action_MoveLine_triggered()
    {
        p->curState=p->viewState::MoveType;
        p->type=2;
    }

    void MainWindow::on_CopyLine_triggered()
    {
        p->curState=p->viewState::CopyType;
        p->type=2;
    }

    void MainWindow::on_action_PointFromLine_triggered()
    {
        p->curState=p->viewState::PntAddToLine;
        p->type=2;
        p->update();

    }

    void MainWindow::on_EditType_triggered()
    {
        p->curState=p->viewState::EditType;
        p->type=2;
        p->update();
    }

    void MainWindow::on_PntDelFromLine_triggered()
    {
        p->type=2;
        p->curState=p->viewState::PntDelFromLine;
        p->update();

    }

    void MainWindow::on_action_AddPoly_triggered()
    {
        p->curState=p->viewState::DrawType;
        p->type=3;
    }

    void MainWindow::on_action_DelePoly_triggered()
    {
        p->curState=p->viewState::DeleteType;
        p->type=3;
        p->deleteYffeature();
    }

    void MainWindow::on_action_MovePoly_triggered()
    {
        p->curState=p->viewState::MoveType;
        p->type=3;
    }

    void MainWindow::on_CopyPolygon_triggered()
    {
        p->curState=p->viewState::CopyType;
        p->type=3;
    }

    void MainWindow::on_Edit_Polygon_triggered()
    {
        p->curState=p->viewState::EditType;
        p->update();
        p->type=3;
    }

    void MainWindow::on_PntAddToLine_Polygon_triggered()
    {
        p->curState=p->viewState::PntAddToLine;
        p->update();
        p->type=3;
    }

    void MainWindow::on_PntDelFromLine_Polygon_triggered()
    {

        p->curState=p->viewState::PntDelFromLine;
        p->type=3;
        p->update();


    }

    void MainWindow::on_action_DeleLine_triggered()
    {
        p->curState=p->viewState::DeleteType;
        p->update();
        p->type=2;
        p->deleteYffeature();
    }

    /************************************删除图层*************************************/
    void MainWindow::on_action_DeleLayer_triggered()
    {
        if(CHOOSEDLAYER==""&&LAYERTYPE==0){
            QMessageBox::critical(NULL, "删除图层", "当前无图层处于选中状态", QMessageBox::Yes );
        }else{
            QMessageBox message(QMessageBox::NoIcon, "删除图层", "是否删除选中图层?", QMessageBox::Yes | QMessageBox::No, NULL);
            if(message.exec() == QMessageBox::Yes)
            {
                qDebug()<<"确定删除"<<PointLayerNum<<LineLayerNum<<PolyLayerNum;
                deleteLayerfromMysql(UserData::mysql,CHOOSEDLAYER);
                for(int i=0;i<p->layers.size();i++){
                    if(p->layers[i]->Name==CHOOSEDLAYER){
                        p->layers.removeAt(i);
                        p->type=-1;
                    }
                }

                QStringList a;
                switch (LAYERTYPE) {
                case 1:
                    for(int i=0;i<PointLayerNum;i++){
                        if(PointList.at(i)!=CHOOSEDLAYER){
                            a<<PointList.at(i);
                        }
                    }
                    PointList=a;
                    PointLayerNum--;
                    break;
                case 2:
                    for(int i=0;i<LineLayerNum;i++){
                        if(LineList.at(i)!=CHOOSEDLAYER){
                            a<<LineList.at(i);
                        }
                    }
                    LineList=a;
                    LineLayerNum--;
                    break;
                case 3:
                    for(int i=0;i<PolyLayerNum;i++){
                        if(PolyList.at(i)!=CHOOSEDLAYER){
                            a<<PolyList.at(i);
                        }
                    }
                    PolyList=a;
                    PolyLayerNum--;
                    break;
                default:
                    break;
                }
            }
            loadLayer();

            CHOOSEDLAYER="";
            LAYERTYPE=0;
            }
    }

    void MainWindow::on_action_showAttr_triggered()
    {
        if(CHOOSEDLAYER!=""&&LAYERTYPE!=0){

            QVector<Attribute> attr=GetAttributeOfTable(UserData::mysql,CHOOSEDLAYER);
            QStringList attrlist;
            for(int i=0;i<attr.size();i++){
                if(i!=1){attrlist<<attr[i].attributename;}
            }
            int rownum=attrlist.size();
            QVector<QStringList> value=GetValueOfAttr(UserData::mysql,attrlist,CHOOSEDLAYER);

            QTableWidget* attrtable=new QTableWidget;
            attrtable->setWindowTitle(CHOOSEDLAYER+"的属性");
            attrtable->setColumnCount(rownum);
            attrtable->setRowCount(value[0].size());
            attrtable->setHorizontalHeaderLabels(attrlist);
            for(int i=0;i<value[0].size();i++){
                for(int j=0;j<value.size();j++){
                    attrtable->setItem(i,j,new QTableWidgetItem(value[j].at(i)));
                    attrtable->item(i,j)->setFlags(Qt::ItemIsEnabled);
                }
            }
            attrtable->show();
        }
    }

void MainWindow::on_action_SaveEdit_triggered()
{
    switch(LAYERTYPE){
    case 1://点图层
        for(int a=0;a<p->layers.size();a++){
            if(p->layers[a]->Name==CHOOSEDLAYER){
                QVector<QPoint> savedlayerscr=p->layers[a]->ps;
                QVector<QPointF> savedlayergeo;
                for(int i=0;i<savedlayerscr.size();i++)
                {
                    savedlayergeo.append(ScreenToCoor(savedlayerscr[i],screen,geo));
                }
                YFInsertPointF(savedlayergeo,UserData::mysql,CHOOSEDLAYER);
                break;
            }
        }
        break;
    case 2:
        for(int a=0;a<p->layers.size();a++){
            if(p->layers[a]->Name==CHOOSEDLAYER){
                QVector<QLineString> savedlayerscr=p->layers[a]->linestring;
                QVector<QLineStringF> savedlayergeo;QLineStringF temp;
                for(int i=0;i<savedlayerscr.size();i++)
                {
                    temp.clear();
                    for(int j=0;j<savedlayerscr[i].size();j++){
                        temp.append(ScreenToCoor(savedlayerscr[i][j],screen,geo));
                    }
                    savedlayergeo.append(temp);
                }
                YFInsertLineStringF(savedlayergeo,UserData::mysql,CHOOSEDLAYER);
                break;
            }
        }
        break;
    case 3:
        for(int a=0;a<p->layers.size();a++){
            if(p->layers[a]->Name==CHOOSEDLAYER){
                QVector<QPolygon> savedlayerscr=p->layers[a]->polygons;
                QVector<QPolygonF> savedlayergeo;QPolygonF temp;
                for(int i=0;i<savedlayerscr.size();i++)
                {
                    temp.clear();
                    for(int j=0;j<savedlayerscr[i].size();j++){
                        temp.append(ScreenToCoor(savedlayerscr[i][j],screen,geo));
                    }
                    savedlayergeo.append(temp);
                }
                for(int j=0;j<savedlayergeo.size();j++)
                {
                YFClockwiseSortPoints(savedlayergeo[j]);}
                YFInsertPolygonF(savedlayergeo,UserData::mysql,CHOOSEDLAYER);
                break;
            }
        }
        break;
    default:
        break;
    }
}

void MainWindow::on_action_Layers_triggered()
{
    ui->dockWidget_Layer->show();
}

void MainWindow::on_action_properties_triggered()
{
    ui->dockWidget_Param->show();
}

void MainWindow::on_action_triggered()
{
    p->curanlyse=p->anlyseState::qiujiao;
}

void MainWindow::on_action_2_triggered()
{
      p->curanlyse=p->anlyseState::qiubing;
}

void MainWindow::on_action_3_triggered()
{
    p->curanlyse=p->anlyseState::qiucha;
}
