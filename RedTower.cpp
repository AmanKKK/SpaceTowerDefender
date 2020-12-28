#include "RedTower.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

RedTower::RedTower(QGraphicsItem *parent){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void RedTower::fire(){
    Bullet * bullet = new Bullet();
    Bullet * bullet1 = new Bullet();
    bullet->setPixmap(QPixmap(":/s_images/resources/images/red_laser.png"));
    bullet1->setPixmap(QPixmap(":/s_images/resources/images/red_laser.png"));
    bullet->setPos(x()+40,y()+40);
    bullet1->setPos(x()+40,y()+40);

    QLineF ln(QPointF(x()+40,y()+40),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    bullet1->setRotation(angle+10);
    game->scene->addItem(bullet);
    game->scene->addItem(bullet1);
}

void RedTower::aquire_target(){
    Tower::aquire_target();
}
