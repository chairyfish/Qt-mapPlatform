#ifndef NEWLAYER_H
#define NEWLAYER_H

#include <QDialog>
#include<QDebug>

namespace Ui {
class NewLayer;
}

class NewLayer : public QDialog
{
    Q_OBJECT

public:
    explicit NewLayer(QWidget *parent = 0);
    ~NewLayer();

private slots:
    void on_NewLayer_OK_clicked();
signals:
    void sendNewLayerSignal(QString,int);
private:
    Ui::NewLayer *ui;
};

#endif // NEWLAYER_H
