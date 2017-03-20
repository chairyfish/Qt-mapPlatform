#ifndef SELECTLAYER_H
#define SELECTLAYER_H

#include <QDialog>

namespace Ui {
class SelectLayer;
}

class SelectLayer : public QDialog
{
    Q_OBJECT

public:
    explicit SelectLayer(QWidget *parent = 0);
    ~SelectLayer();

private slots:
    void changeTest();
    void on_SelectLayer_OK_clicked();

private:
    Ui::SelectLayer *ui;
    int selePointNum=0;
    int seleLineNum=0;
    int selePolyNum=0;
public:
    QStringList selePoint;
    QStringList seleLine;
    QStringList selePoly;

    static QStringList checkPoint;
    static QStringList checkLine;
    static QStringList checkPoly;

    void loadLayerFromSql();
    void showTableWidget();
  signals:
    void sendReloadSignal();
};

#endif // SELECTLAYER_H
