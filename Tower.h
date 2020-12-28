#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    virtual void fire();
public slots:
    void aquire_target(); // метод для атаки вражеского объекта, который находится в полигоне башни
protected:
    // используется полигон, так как QGraphicsPolygonItem предоставляет возможность
    // отслеживать объекты, который оказываются внуртри него
    QGraphicsPolygonItem * attack_area; // область-полигон, в которой башня может атакавать
    QPointF attack_dest; // объект, который будет атакован башней
    bool has_target;
};


#endif // TOWER_H
