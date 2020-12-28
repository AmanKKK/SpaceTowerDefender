#include "BuildRedTowerIcon.h"
#include "Game.h"
#include "BrownTower.h"
#include "RedTower.h"

extern Game * game;

BuildRedTowerIcon::BuildRedTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/s_images/resources/images/red_tower_icon.png"));
}

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new RedTower();
        game->setCursor(QString(":/s_images/resources/images/red_space_tower.png"));
    }
}
