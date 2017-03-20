/********************************************************************************
** Form generated from reading UI file 'selectlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTLAYER_H
#define UI_SELECTLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectLayer
{
public:
    QLabel *label;
    QTableWidget *SelectTable;
    QPushButton *SelectLayer_OK;
    QPushButton *SelectLayer_Cancel;

    void setupUi(QDialog *SelectLayer)
    {
        if (SelectLayer->objectName().isEmpty())
            SelectLayer->setObjectName(QStringLiteral("SelectLayer"));
        SelectLayer->resize(341, 330);
        label = new QLabel(SelectLayer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 131, 16));
        SelectTable = new QTableWidget(SelectLayer);
        SelectTable->setObjectName(QStringLiteral("SelectTable"));
        SelectTable->setGeometry(QRect(10, 30, 321, 251));
        SelectLayer_OK = new QPushButton(SelectLayer);
        SelectLayer_OK->setObjectName(QStringLiteral("SelectLayer_OK"));
        SelectLayer_OK->setGeometry(QRect(240, 290, 75, 23));
        SelectLayer_Cancel = new QPushButton(SelectLayer);
        SelectLayer_Cancel->setObjectName(QStringLiteral("SelectLayer_Cancel"));
        SelectLayer_Cancel->setGeometry(QRect(30, 290, 75, 23));

        retranslateUi(SelectLayer);
        QObject::connect(SelectLayer_Cancel, SIGNAL(clicked()), SelectLayer, SLOT(close()));
        QObject::connect(SelectLayer_OK, SIGNAL(clicked()), SelectLayer, SLOT(accept()));

        QMetaObject::connectSlotsByName(SelectLayer);
    } // setupUi

    void retranslateUi(QDialog *SelectLayer)
    {
        SelectLayer->setWindowTitle(QApplication::translate("SelectLayer", "Dialog", 0));
        label->setText(QApplication::translate("SelectLayer", "\350\257\267\351\200\211\346\213\251\350\246\201\350\275\275\345\205\245\347\232\204\345\233\276\345\261\202\357\274\232", 0));
        SelectLayer_OK->setText(QApplication::translate("SelectLayer", "\347\241\256\345\256\232", 0));
        SelectLayer_Cancel->setText(QApplication::translate("SelectLayer", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectLayer: public Ui_SelectLayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTLAYER_H
