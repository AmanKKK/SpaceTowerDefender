#include "BuildBrownTowerIcon.h"
#include "Game.h"
#include "BrownTower.h"

extern Game * game;

BuildBrownTowerIcon::BuildBrownTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/s_images/resources/images/brown_tower_icon.png"));
}

void BuildBrownTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->building){
        game->building = new BrownTower();
        game->setCursor(QString(":/s_images/resources/images/brown_space_tower.png"));
    }
}
