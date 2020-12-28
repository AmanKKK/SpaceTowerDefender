#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "Bullet.h"
#include <QPointF>
#include <QLineF>
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "Enemy.h"

extern Game * game;

#include <QDebug>
Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    // создание вектора, содержащего точки, которые представляют полигон
    // координаты точек составляются на основе центра полигона, который находится в x(1.5) и y(1.5)
    QVector<QPointF> points;
    // добавление точек через <<
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // расширение полигона
    int SCALE_FACTOR = 75; // значение, на котороре будет увеличиваться полигон
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // создание QGraphicsPolygonItem из увеличенных points
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));

    // перемещение полигона к башне
    QPointF poly_center(1.5,1.5); // центр полигона
    poly_center *= SCALE_FACTOR; // маштабирование центра
    poly_center = mapToScene(poly_center); // установка координат центра полигона в координатной системе QGraphicsScene
    QPointF tower_center(x()+40,y()+40);  // координаты центра башни
    QLineF ln(poly_center,tower_center); // создание линии, которая будет смещать полигон к центру башни
    attack_area->setPos(x()+ln.dx(),y()+ln.dy()); // смещение полигона к центру башни

    // установка направление выстрелов
    attack_dest = QPointF(0,0);
    has_target = false;
}

// Данный метод возвращает расстояние между башней и вражеским объектом
double Tower::distanceTo(QGraphicsItem *item){

    QLineF ln(this->pos(),item->pos());
    return ln.length();
}

void Tower::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+40,y()+40);

    // ротация снаряда
    QLineF ln(QPointF(x()+40,y()+40),attack_dest); // создание линии, которая будет направлять выстрел в направлении вражеского объекта
    int angle = -1 * ln.angle(); // идем перемножение на -1, чтобы изменения направления выстрела проходило по часовой стрелке

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::aquire_target(){

    // получение списка всех вражеских объектов, которые попадают в зону поражение башни, поиск самого близкого
    // получение списка всех врагов внутри полигона
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    // У башни нет цели пока, она не появится в её полигоне
    has_target = false;

    // поиск наиболее близкого вражеского объекта
    double closest_dist = 300;
    QPointF closest_pt(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){

        // убедиться в том, что объект в полигоне является вражеским
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);

        // поиск наиболее ближнего вражеского объекта
        if (enemy){
            double this_dist = distanceTo(colliding_items[i]);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }

    // если есть цель, начать атаку в ее направлении.
    if (has_target){
        attack_dest = closest_pt;
        fire();
    }
}
