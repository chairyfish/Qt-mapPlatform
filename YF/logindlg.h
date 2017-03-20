#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

private slots:
void on_LoginDlg_accepted();

    void on_loginButton_clicked();

private:
    Ui::LoginDlg *ui;
};

#endif // LOGINDLG_H
