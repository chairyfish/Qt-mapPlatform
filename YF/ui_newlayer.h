/********************************************************************************
** Form generated from reading UI file 'newlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLAYER_H
#define UI_NEWLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewLayer
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *NewLayerType;
    QPushButton *NewLayer_OK;
    QPushButton *NewLayer_Cancel;
    QLineEdit *NewLayerName;

    void setupUi(QDialog *NewLayer)
    {
        if (NewLayer->objectName().isEmpty())
            NewLayer->setObjectName(QStringLiteral("NewLayer"));
        NewLayer->resize(322, 203);
        label = new QLabel(NewLayer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 111, 16));
        label_2 = new QLabel(NewLayer);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 90, 111, 16));
        NewLayerType = new QComboBox(NewLayer);
        NewLayerType->setObjectName(QStringLiteral("NewLayerType"));
        NewLayerType->setGeometry(QRect(170, 90, 100, 24));
        NewLayer_OK = new QPushButton(NewLayer);
        NewLayer_OK->setObjectName(QStringLiteral("NewLayer_OK"));
        NewLayer_OK->setGeometry(QRect(190, 150, 75, 23));
        NewLayer_Cancel = new QPushButton(NewLayer);
        NewLayer_Cancel->setObjectName(QStringLiteral("NewLayer_Cancel"));
        NewLayer_Cancel->setGeometry(QRect(70, 150, 75, 23));
        NewLayerName = new QLineEdit(NewLayer);
        NewLayerName->setObjectName(QStringLiteral("NewLayerName"));
        NewLayerName->setGeometry(QRect(170, 40, 100, 24));

        retranslateUi(NewLayer);
        QObject::connect(NewLayer_Cancel, SIGNAL(clicked()), NewLayer, SLOT(close()));

        QMetaObject::connectSlotsByName(NewLayer);
    } // setupUi

    void retranslateUi(QDialog *NewLayer)
    {
        NewLayer->setWindowTitle(QApplication::translate("NewLayer", "Dialog", 0));
        label->setText(QApplication::translate("NewLayer", "\350\276\223\345\205\245\346\226\260\345\233\276\345\261\202\347\232\204\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("NewLayer", "\350\276\223\345\205\245\346\226\260\345\233\276\345\261\202\347\232\204\347\261\273\345\236\213\357\274\232", 0));
        NewLayerType->clear();
        NewLayerType->insertItems(0, QStringList()
         << QApplication::translate("NewLayer", "\347\202\271\345\233\276\345\261\202", 0)
         << QApplication::translate("NewLayer", "\347\272\277\345\233\276\345\261\202", 0)
         << QApplication::translate("NewLayer", "\351\235\242\345\233\276\345\261\202", 0)
        );
        NewLayer_OK->setText(QApplication::translate("NewLayer", "\347\241\256\345\256\232", 0));
        NewLayer_Cancel->setText(QApplication::translate("NewLayer", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class NewLayer: public Ui_NewLayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLAYER_H
