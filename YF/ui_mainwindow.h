/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save_As;
    QAction *action_Con;
    QAction *action_AddPoint;
    QAction *action_MovePoint;
    QAction *action_DelePoint;
    QAction *action_ModPoint;
    QAction *action_AddLine;
    QAction *action_DeleLine;
    QAction *CopyLine;
    QAction *action_LjLine;
    QAction *action_ModLine;
    QAction *action_PointFromLine;
    QAction *action_4;
    QAction *action_AddPoly;
    QAction *action_MovePoly;
    QAction *action_ModPoly;
    QAction *action_11;
    QAction *action_13;
    QAction *action_14;
    QAction *action_15;
    QAction *action_Delete;
    QAction *action_Enlarge;
    QAction *action_Narrow;
    QAction *action_Resize;
    QAction *action_StartEdit;
    QAction *action_Property;
    QAction *action_18;
    QAction *action_DelePoly;
    QAction *action_MoveLine;
    QAction *action_StopEdit;
    QAction *action_SaveEdit;
    QAction *Select;
    QAction *CopyPoint;
    QAction *EditType;
    QAction *PntDelFromLine;
    QAction *CopyPolygon;
    QAction *Edit_Polygon;
    QAction *PntAddToLine_Polygon;
    QAction *PntDelFromLine_Polygon;
    QAction *action_DeleLayer;
    QAction *action_showAttr;
    QAction *action_Layers;
    QAction *action_properties;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QMenuBar *menu_Layer;
    QMenu *menu_File;
    QMenu *menu_Point;
    QMenu *menu_Line;
    QMenu *menu_Poly;
    QMenu *menu_General;
    QMenu *menu_Basic;
    QMenu *menu_Help;
    QMenu *menu_View;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_Layer;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QTreeWidget *listLayer;
    QDockWidget *dockWidget_Param;
    QWidget *dockWidgetContents_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QComboBox *comboBox_LineType;
    QLabel *label;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QSpinBox *spinBox_LineWeight;
    QLabel *label_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_pen;
    QToolButton *color_pen;
    QLabel *label_3;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser_fill;
    QPushButton *pushButton_tianchong;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1228, 605);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\256\213\344\275\223\";\n"
"font: 75 10pt \"Arial\";"));
        MainWindow->setIconSize(QSize(25, 25));
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral("../picture/IDB_NEW_DOCUMENT.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../picture/IDB_OPEN_DOCUMENT.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral("../picture/IDB_OPEN_DOCUMENT.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_Open->setIcon(icon1);
        action_Save_As = new QAction(MainWindow);
        action_Save_As->setObjectName(QStringLiteral("action_Save_As"));
        action_Con = new QAction(MainWindow);
        action_Con->setObjectName(QStringLiteral("action_Con"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../picture/lianjie.png"), QSize(), QIcon::Normal, QIcon::On);
        action_Con->setIcon(icon2);
        action_AddPoint = new QAction(MainWindow);
        action_AddPoint->setObjectName(QStringLiteral("action_AddPoint"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../picture/IDB_EDIT_CTRLPNT.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_AddPoint->setIcon(icon3);
        action_MovePoint = new QAction(MainWindow);
        action_MovePoint->setObjectName(QStringLiteral("action_MovePoint"));
        action_DelePoint = new QAction(MainWindow);
        action_DelePoint->setObjectName(QStringLiteral("action_DelePoint"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../picture/ID_EDIT_PNT_DEL.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_DelePoint->setIcon(icon4);
        action_ModPoint = new QAction(MainWindow);
        action_ModPoint->setObjectName(QStringLiteral("action_ModPoint"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../picture/ID_EDIT_PNT_GRAPHE.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_ModPoint->setIcon(icon5);
        action_AddLine = new QAction(MainWindow);
        action_AddLine->setObjectName(QStringLiteral("action_AddLine"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../picture/ID_EditTool_InputLine.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_AddLine->setIcon(icon6);
        action_DeleLine = new QAction(MainWindow);
        action_DeleLine->setObjectName(QStringLiteral("action_DeleLine"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../picture/ID_BUTTON_EDIT_DELETE.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_DeleLine->setIcon(icon7);
        CopyLine = new QAction(MainWindow);
        CopyLine->setObjectName(QStringLiteral("CopyLine"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../picture/ID_BUTTON_CUTLIN.bmp"), QSize(), QIcon::Normal, QIcon::On);
        CopyLine->setIcon(icon8);
        action_LjLine = new QAction(MainWindow);
        action_LjLine->setObjectName(QStringLiteral("action_LjLine"));
        QIcon icon9;
        icon9.addFile(QStringLiteral("../picture/ID_SELECT_LIN.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_LjLine->setIcon(icon9);
        action_ModLine = new QAction(MainWindow);
        action_ModLine->setObjectName(QStringLiteral("action_ModLine"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../picture/ID_EditTool_AttributeModify\344\277\256\346\224\271\345\217\202\346\225\260.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_ModLine->setIcon(icon10);
        action_PointFromLine = new QAction(MainWindow);
        action_PointFromLine->setObjectName(QStringLiteral("action_PointFromLine"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("../picture/NewShape.ico"), QSize(), QIcon::Normal, QIcon::On);
        action_PointFromLine->setIcon(icon11);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        QIcon icon12;
        icon12.addFile(QStringLiteral("../picture/ID_BUTTON_DELETEPNT.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_4->setIcon(icon12);
        action_AddPoly = new QAction(MainWindow);
        action_AddPoly->setObjectName(QStringLiteral("action_AddPoly"));
        QIcon icon13;
        icon13.addFile(QStringLiteral("../picture/ID_EditTool_InputPoint.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_AddPoly->setIcon(icon13);
        action_MovePoly = new QAction(MainWindow);
        action_MovePoly->setObjectName(QStringLiteral("action_MovePoly"));
        action_ModPoly = new QAction(MainWindow);
        action_ModPoly->setObjectName(QStringLiteral("action_ModPoly"));
        QIcon icon14;
        icon14.addFile(QStringLiteral("../picture/ID_EditTool_InputRegion.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_ModPoly->setIcon(icon14);
        action_11 = new QAction(MainWindow);
        action_11->setObjectName(QStringLiteral("action_11"));
        QIcon icon15;
        icon15.addFile(QStringLiteral("../picture/clear.png"), QSize(), QIcon::Normal, QIcon::On);
        action_11->setIcon(icon15);
        action_13 = new QAction(MainWindow);
        action_13->setObjectName(QStringLiteral("action_13"));
        action_14 = new QAction(MainWindow);
        action_14->setObjectName(QStringLiteral("action_14"));
        action_15 = new QAction(MainWindow);
        action_15->setObjectName(QStringLiteral("action_15"));
        action_Delete = new QAction(MainWindow);
        action_Delete->setObjectName(QStringLiteral("action_Delete"));
        action_Enlarge = new QAction(MainWindow);
        action_Enlarge->setObjectName(QStringLiteral("action_Enlarge"));
        QIcon icon16;
        icon16.addFile(QStringLiteral("../picture/IDB_ZOOM_IN.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_Enlarge->setIcon(icon16);
        action_Narrow = new QAction(MainWindow);
        action_Narrow->setObjectName(QStringLiteral("action_Narrow"));
        QIcon icon17;
        icon17.addFile(QStringLiteral("../picture/IDB_ZOOM_OUT.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_Narrow->setIcon(icon17);
        action_Resize = new QAction(MainWindow);
        action_Resize->setObjectName(QStringLiteral("action_Resize"));
        QIcon icon18;
        icon18.addFile(QStringLiteral("../picture/fullExtent.png"), QSize(), QIcon::Normal, QIcon::On);
        action_Resize->setIcon(icon18);
        action_StartEdit = new QAction(MainWindow);
        action_StartEdit->setObjectName(QStringLiteral("action_StartEdit"));
        QIcon icon19;
        icon19.addFile(QStringLiteral("../picture/ID_EditTool_ExtractFeature.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_StartEdit->setIcon(icon19);
        action_Property = new QAction(MainWindow);
        action_Property->setObjectName(QStringLiteral("action_Property"));
        QIcon icon20;
        icon20.addFile(QStringLiteral("../picture/IDB_SET_CTRLPNT_PARAM.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_Property->setIcon(icon20);
        action_18 = new QAction(MainWindow);
        action_18->setObjectName(QStringLiteral("action_18"));
        action_DelePoly = new QAction(MainWindow);
        action_DelePoly->setObjectName(QStringLiteral("action_DelePoly"));
        action_MoveLine = new QAction(MainWindow);
        action_MoveLine->setObjectName(QStringLiteral("action_MoveLine"));
        action_StopEdit = new QAction(MainWindow);
        action_StopEdit->setObjectName(QStringLiteral("action_StopEdit"));
        QIcon icon21;
        icon21.addFile(QStringLiteral("../picture/delete.png"), QSize(), QIcon::Normal, QIcon::On);
        action_StopEdit->setIcon(icon21);
        action_SaveEdit = new QAction(MainWindow);
        action_SaveEdit->setObjectName(QStringLiteral("action_SaveEdit"));
        QIcon icon22;
        icon22.addFile(QStringLiteral("../picture/IDB_SAVE_DOCUMENT.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_SaveEdit->setIcon(icon22);
        Select = new QAction(MainWindow);
        Select->setObjectName(QStringLiteral("Select"));
        CopyPoint = new QAction(MainWindow);
        CopyPoint->setObjectName(QStringLiteral("CopyPoint"));
        EditType = new QAction(MainWindow);
        EditType->setObjectName(QStringLiteral("EditType"));
        PntDelFromLine = new QAction(MainWindow);
        PntDelFromLine->setObjectName(QStringLiteral("PntDelFromLine"));
        CopyPolygon = new QAction(MainWindow);
        CopyPolygon->setObjectName(QStringLiteral("CopyPolygon"));
        Edit_Polygon = new QAction(MainWindow);
        Edit_Polygon->setObjectName(QStringLiteral("Edit_Polygon"));
        PntAddToLine_Polygon = new QAction(MainWindow);
        PntAddToLine_Polygon->setObjectName(QStringLiteral("PntAddToLine_Polygon"));
        PntDelFromLine_Polygon = new QAction(MainWindow);
        PntDelFromLine_Polygon->setObjectName(QStringLiteral("PntDelFromLine_Polygon"));
        action_DeleLayer = new QAction(MainWindow);
        action_DeleLayer->setObjectName(QStringLiteral("action_DeleLayer"));
        action_showAttr = new QAction(MainWindow);
        action_showAttr->setObjectName(QStringLiteral("action_showAttr"));
        QIcon icon23;
        icon23.addFile(QStringLiteral("../picture/ID_BUTTON_MODIFYFEATATR.bmp"), QSize(), QIcon::Normal, QIcon::On);
        action_showAttr->setIcon(icon23);
        action_Layers = new QAction(MainWindow);
        action_Layers->setObjectName(QStringLiteral("action_Layers"));
        action_properties = new QAction(MainWindow);
        action_properties->setObjectName(QStringLiteral("action_properties"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menu_Layer = new QMenuBar(MainWindow);
        menu_Layer->setObjectName(QStringLiteral("menu_Layer"));
        menu_Layer->setGeometry(QRect(0, 0, 1228, 22));
        menu_File = new QMenu(menu_Layer);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Point = new QMenu(menu_Layer);
        menu_Point->setObjectName(QStringLiteral("menu_Point"));
        menu_Line = new QMenu(menu_Layer);
        menu_Line->setObjectName(QStringLiteral("menu_Line"));
        menu_Poly = new QMenu(menu_Layer);
        menu_Poly->setObjectName(QStringLiteral("menu_Poly"));
        menu_General = new QMenu(menu_Layer);
        menu_General->setObjectName(QStringLiteral("menu_General"));
        menu_Basic = new QMenu(menu_Layer);
        menu_Basic->setObjectName(QStringLiteral("menu_Basic"));
        menu_Help = new QMenu(menu_Layer);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menu_View = new QMenu(menu_Layer);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu = new QMenu(menu_Layer);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menu_Layer);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(25, 25));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_Layer = new QDockWidget(MainWindow);
        dockWidget_Layer->setObjectName(QStringLiteral("dockWidget_Layer"));
        dockWidget_Layer->setMinimumSize(QSize(109, 162));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listLayer = new QTreeWidget(dockWidgetContents_3);
        listLayer->setObjectName(QStringLiteral("listLayer"));
        listLayer->setLineWidth(3);
        listLayer->setColumnCount(0);

        verticalLayout->addWidget(listLayer);

        dockWidget_Layer->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_Layer);
        dockWidget_Param = new QDockWidget(MainWindow);
        dockWidget_Param->setObjectName(QStringLiteral("dockWidget_Param"));
        dockWidget_Param->setMinimumSize(QSize(100, 140));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        formLayoutWidget_2 = new QWidget(dockWidgetContents_2);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 18, 191, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_LineType = new QComboBox(formLayoutWidget_2);
        comboBox_LineType->setObjectName(QStringLiteral("comboBox_LineType"));
        comboBox_LineType->setMinimumSize(QSize(0, 30));

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, comboBox_LineType);

        label = new QLabel(formLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 20));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, label);

        formLayoutWidget_3 = new QWidget(dockWidgetContents_2);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 90, 191, 71));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        spinBox_LineWeight = new QSpinBox(formLayoutWidget_3);
        spinBox_LineWeight->setObjectName(QStringLiteral("spinBox_LineWeight"));
        spinBox_LineWeight->setMinimumSize(QSize(0, 30));

        formLayout_3->setWidget(1, QFormLayout::SpanningRole, spinBox_LineWeight);

        label_2 = new QLabel(formLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 20));

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, label_2);

        formLayoutWidget = new QWidget(dockWidgetContents_2);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 170, 141, 110));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser_pen = new QTextBrowser(formLayoutWidget);
        textBrowser_pen->setObjectName(QStringLiteral("textBrowser_pen"));
        textBrowser_pen->setMinimumSize(QSize(0, 0));
        textBrowser_pen->setMaximumSize(QSize(30, 30));
        textBrowser_pen->setAutoFillBackground(false);

        gridLayout->addWidget(textBrowser_pen, 1, 0, 1, 1);

        color_pen = new QToolButton(formLayoutWidget);
        color_pen->setObjectName(QStringLiteral("color_pen"));

        gridLayout->addWidget(color_pen, 1, 1, 1, 1);


        formLayout->setLayout(2, QFormLayout::LabelRole, gridLayout);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        formLayoutWidget_4 = new QWidget(dockWidgetContents_2);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(30, 280, 141, 80));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 30));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser_fill = new QTextBrowser(formLayoutWidget_4);
        textBrowser_fill->setObjectName(QStringLiteral("textBrowser_fill"));
        textBrowser_fill->setMaximumSize(QSize(30, 30));

        gridLayout_2->addWidget(textBrowser_fill, 0, 0, 1, 1);

        pushButton_tianchong = new QPushButton(formLayoutWidget_4);
        pushButton_tianchong->setObjectName(QStringLiteral("pushButton_tianchong"));
        pushButton_tianchong->setMaximumSize(QSize(100, 50));

        gridLayout_2->addWidget(pushButton_tianchong, 0, 1, 1, 1);


        formLayout_4->setLayout(1, QFormLayout::LabelRole, gridLayout_2);

        dockWidget_Param->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_Param);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menu_Layer->addAction(menu_File->menuAction());
        menu_Layer->addAction(menu_Basic->menuAction());
        menu_Layer->addAction(menu_Point->menuAction());
        menu_Layer->addAction(menu_Line->menuAction());
        menu_Layer->addAction(menu_Poly->menuAction());
        menu_Layer->addAction(menu_General->menuAction());
        menu_Layer->addAction(menu_View->menuAction());
        menu_Layer->addAction(menu->menuAction());
        menu_Layer->addAction(menu_Help->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_DeleLayer);
        menu_File->addAction(action_showAttr);
        menu_File->addAction(action_Con);
        menu_Point->addAction(action_AddPoint);
        menu_Point->addAction(action_DelePoint);
        menu_Point->addAction(action_MovePoint);
        menu_Point->addAction(CopyPoint);
        menu_Point->addAction(action_ModPoint);
        menu_Line->addAction(action_AddLine);
        menu_Line->addAction(action_DeleLine);
        menu_Line->addAction(action_MoveLine);
        menu_Line->addAction(CopyLine);
        menu_Line->addAction(action_PointFromLine);
        menu_Line->addAction(EditType);
        menu_Line->addAction(PntDelFromLine);
        menu_Line->addAction(action_ModLine);
        menu_Poly->addAction(action_AddPoly);
        menu_Poly->addAction(action_DelePoly);
        menu_Poly->addAction(action_MovePoly);
        menu_Poly->addAction(action_ModPoly);
        menu_Poly->addAction(CopyPolygon);
        menu_Poly->addAction(Edit_Polygon);
        menu_Poly->addAction(PntAddToLine_Polygon);
        menu_Poly->addAction(PntDelFromLine_Polygon);
        menu_General->addAction(action_Delete);
        menu_General->addAction(Select);
        menu_Basic->addAction(action_Enlarge);
        menu_Basic->addAction(action_Narrow);
        menu_Basic->addAction(action_Resize);
        menu_Basic->addAction(action_StartEdit);
        menu_Basic->addAction(action_SaveEdit);
        menu_Basic->addAction(action_StopEdit);
        menu_Basic->addAction(action_Property);
        menu_View->addAction(action_Layers);
        menu_View->addAction(action_properties);
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Resize);
        mainToolBar->addAction(action_Enlarge);
        mainToolBar->addAction(action_Narrow);
        mainToolBar->addAction(action_StartEdit);
        mainToolBar->addAction(action_Property);
        toolBar->addAction(action_AddPoint);
        toolBar->addAction(action_DelePoint);
        toolBar->addAction(action_AddLine);
        toolBar->addAction(action_DeleLine);
        toolBar->addAction(CopyLine);
        toolBar->addAction(action_PointFromLine);
        toolBar->addAction(action_4);
        toolBar->addAction(action_AddPoly);
        toolBar->addAction(action_ModPoly);
        toolBar->addAction(action_showAttr);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\271\231\346\226\271\345\217\257\350\247\206\345\214\226\347\274\226\350\276\221", 0));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\233\276\345\261\202(&N)", 0));
        action_New->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        action_Open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\345\261\202(&O)", 0));
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        action_Save_As->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", 0));
        action_Con->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
        action_AddPoint->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\202\271", 0));
        action_MovePoint->setText(QApplication::translate("MainWindow", "\347\247\273\345\212\250\347\202\271", 0));
        action_DelePoint->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\202\271", 0));
        action_ModPoint->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\202\271\345\217\202\346\225\260", 0));
        action_AddLine->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\272\277", 0));
        action_DeleLine->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\272\277", 0));
        CopyLine->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266\347\272\277", 0));
#ifndef QT_NO_TOOLTIP
        CopyLine->setToolTip(QApplication::translate("MainWindow", "\345\244\215\345\210\266\347\272\277", 0));
#endif // QT_NO_TOOLTIP
        action_LjLine->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\347\272\277 ", 0));
        action_ModLine->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\272\277\345\217\202\346\225\260", 0));
        action_PointFromLine->setText(QApplication::translate("MainWindow", "\347\272\277\344\270\212\345\212\240\347\202\271", 0));
        action_4->setText(QApplication::translate("MainWindow", "\347\272\277\344\270\212\345\210\240\347\202\271", 0));
        action_AddPoly->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\235\242 ", 0));
        action_MovePoly->setText(QApplication::translate("MainWindow", "\347\247\273\345\212\250\351\235\242", 0));
        action_ModPoly->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\351\235\242\345\217\202\346\225\260", 0));
        action_11->setText(QApplication::translate("MainWindow", "\346\213\211\346\241\206\351\200\211\346\213\251", 0));
        action_13->setText(QApplication::translate("MainWindow", "\345\234\206\351\200\211\346\213\251", 0));
        action_14->setText(QApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242\351\200\211\346\213\251", 0));
        action_15->setText(QApplication::translate("MainWindow", "\346\214\211\345\261\236\346\200\247\351\200\211\346\213\251", 0));
        action_Delete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\233\276\345\205\203", 0));
        action_Enlarge->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        action_Narrow->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        action_Resize->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", 0));
        action_StartEdit->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\274\226\350\276\221", 0));
        action_Property->setText(QApplication::translate("MainWindow", "\345\233\276\345\275\242\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        action_18->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\272\277", 0));
        action_DelePoly->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\351\235\242", 0));
        action_MoveLine->setText(QApplication::translate("MainWindow", "\347\247\273\345\212\250\347\272\277", 0));
        action_StopEdit->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\347\274\226\350\276\221", 0));
        action_SaveEdit->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\274\226\350\276\221", 0));
        Select->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\345\205\203", 0));
        CopyPoint->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266\347\202\271", 0));
        EditType->setText(QApplication::translate("MainWindow", "\347\272\277\344\270\212\347\247\273\347\202\271", 0));
        PntDelFromLine->setText(QApplication::translate("MainWindow", "\347\272\277\344\270\212\345\210\240\347\202\271", 0));
        CopyPolygon->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266\351\235\242", 0));
        Edit_Polygon->setText(QApplication::translate("MainWindow", "\347\272\277\344\270\212\347\247\273\347\202\271", 0));
        PntAddToLine_Polygon->setText(QApplication::translate("MainWindow", "\347\272\277\344\270\212\345\212\240\347\202\271", 0));
        PntDelFromLine_Polygon->setText(QApplication::translate("MainWindow", "\347\272\277\344\270\212\345\210\240\347\202\271", 0));
        action_DeleLayer->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\233\276\345\261\202", 0));
        action_showAttr->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\261\236\346\200\247", 0));
        action_Layers->setText(QApplication::translate("MainWindow", "\345\233\276\345\261\202", 0));
        action_properties->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        action->setText(QApplication::translate("MainWindow", "\345\233\276\345\205\203\346\261\202\344\272\244", 0));
        action_2->setText(QApplication::translate("MainWindow", "\345\233\276\345\205\203\346\261\202\345\271\266", 0));
        action_3->setText(QApplication::translate("MainWindow", "\345\233\276\345\205\203\346\261\202\345\267\256", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\261\202(&F)", 0));
        menu_Point->setTitle(QApplication::translate("MainWindow", "\347\202\271\347\274\226\350\276\221(&P)", 0));
        menu_Line->setTitle(QApplication::translate("MainWindow", "\347\272\277\347\274\226\350\276\221(&L)", 0));
        menu_Poly->setTitle(QApplication::translate("MainWindow", "\351\235\242\347\274\226\350\276\221(R)", 0));
        menu_General->setTitle(QApplication::translate("MainWindow", "\351\200\232\347\224\250\347\274\226\350\276\221(&G)", 0));
        menu_Basic->setTitle(QApplication::translate("MainWindow", "\345\237\272\346\234\254\346\223\215\344\275\234(&B)", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
        menu_View->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\347\251\272\351\227\264\345\210\206\346\236\220", 0));
        dockWidget_Layer->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\345\261\202", 0));
        dockWidget_Param->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\345\275\242\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        comboBox_LineType->clear();
        comboBox_LineType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\256\236\347\272\277", 0)
         << QApplication::translate("MainWindow", "\350\231\232\347\272\277", 0)
        );
        label->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224\347\272\277\345\236\213\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224\345\256\275\345\272\246\357\274\232", 0));
        textBrowser_pen->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:10pt; font-weight:72; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        color_pen->setText(QApplication::translate("MainWindow", "...", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\224\273\347\254\224\351\242\234\350\211\262\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\241\253\345\205\205\351\242\234\350\211\262\357\274\232", 0));
        pushButton_tianchong->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\345\272\223", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
