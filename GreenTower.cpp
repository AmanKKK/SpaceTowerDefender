#include "GreenTower.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

GreenTower::GreenTower(QGraphicsItem *parent){

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void GreenTower::fire(){

    Bullet * bullet1 = new Bullet();
    Bullet * bullet2 = new Bullet();
    Bullet * bullet3 = new Bullet();


    bullet1->setPixmap(QPixmap(":/s_images/resources/images/green_laser.png"));
    bullet2->setPixmap(QPixmap(":/s_images/resources/images/green_laser.png"));
    bullet3->setPixmap(QPixmap(":/s_images/resources/images/green_laser.png"));

    bullet1->setPos(x()+40,y()+40);
    bullet2->setPos(x()+40,y()+40);
    bullet3->setPos(x()+40,y()+40);

    QLineF ln(QPointF(x()+40,y()+40),attack_dest);
    int angle = -1 * ln.angle();

    bullet1->setRotation(angle);
    bullet2->setRotation(angle+10);
    bullet3->setRotation(angle-10);

    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
}

void GreenTower::aquire_target(){
    Tower::aquire_target();
}
