/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QPushButton *loginButton;
    QPushButton *quitButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Username;
    QLineEdit *Password;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(314, 194);
        loginButton = new QPushButton(LoginDlg);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(170, 130, 75, 23));
        quitButton = new QPushButton(LoginDlg);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(70, 130, 75, 23));
        label = new QLabel(LoginDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 40, 51, 20));
        label_2 = new QLabel(LoginDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 80, 54, 12));
        Username = new QLineEdit(LoginDlg);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(120, 40, 120, 24));
        Password = new QLineEdit(LoginDlg);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(120, 80, 120, 24));

        retranslateUi(LoginDlg);
        QObject::connect(quitButton, SIGNAL(clicked()), LoginDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "\347\231\273\345\275\225", 0));
        loginButton->setText(QApplication::translate("LoginDlg", "\347\231\273\345\275\225", 0));
        quitButton->setText(QApplication::translate("LoginDlg", "\351\200\200\345\207\272", 0));
        label->setText(QApplication::translate("LoginDlg", "\347\224\250\346\210\267\345\220\215:", 0));
        label_2->setText(QApplication::translate("LoginDlg", "\345\257\206  \347\240\201:", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
