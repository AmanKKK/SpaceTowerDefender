#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // необходим для создание списка точек, по которым будут передвигаться объекты Enemy
#include <QPointF>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p); // метод для ротации объекта относительно точки
public slots:
    void moveForward();
private:
    QList<QPointF> points;
    QPointF dest;  // направление, в котором будет двигаться вражеский объект
    int point_index;
};

#endif // ENEMY_H
