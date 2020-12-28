#include "Bullet.h"
#include "Enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include <QList>


extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // установка коричневого лазера
    setPixmap(QPixmap(":/s_images/resources/images/brown_laser.png"));

    // подключение объекта таймера к объекту bullet к слоту move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50); // каждые 50 милисекунд будет вызываться слот move(), для передвижение снаряда

    //инициализация значений
    maxRange = 100;
    distanceTravelled = 0;
}

void Bullet::move(){

    int STEP_SIZE = 30; // длина лазерного снаряда
    double theta = rotation(); // возвращает градусы


    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

    QList<QGraphicsItem*> colliding_items = collidingItems();
        for(int i=0,n=colliding_items.size();i<n;++i){
            if(typeid(*(colliding_items[i])) == typeid(Enemy)){

                   game->m_money->increaseAmount(25);
                   scene()->removeItem(colliding_items[i]);
                   scene()->removeItem(this);
                   delete colliding_items[i];
                   delete this;


                   return;


        }
        }


}

double Bullet::getMaxRange(){
    return maxRange;
}

double Bullet::getDistanceTravelled(){
    return distanceTravelled;
}

void Bullet::setMaxRange(double rng){
maxRange = rng;
}

void Bullet::setDistanceTravelled(double dist){
    distanceTravelled = dist;
}
