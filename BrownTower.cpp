#include "BrownTower.h"
#include <QTimer>
#include "Bullet.h"
#include "Game.h"

extern Game * game;

BrownTower::BrownTower(QGraphicsItem *parent){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void BrownTower::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+40,y()+40);

    QLineF ln(QPointF(x()+40,y()+40),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void BrownTower::aquire_target(){
    Tower::aquire_target();
}
