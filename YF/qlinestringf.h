#ifndef QLINESTRING_H
#define QLINESTRING_H

#include <QObject>
#include <QWidget>
#include<QPolygonF>
class QLineStringF : public QPolygonF
{
public:
    QLineStringF(const QVector<QPointF> &points);
    QLineStringF();
};

#endif // QLINESTRING_H
