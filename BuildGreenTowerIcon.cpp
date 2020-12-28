#include "BuildGreenTowerIcon.h"
#include "Game.h"
#include "GreenTower.h"

extern Game * game;

BuildGreenTowerIcon::BuildGreenTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/s_images/resources/images/green_tower_icon.png"));
}

void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if(game->m_money->getMoneyAmount()>=500){
    if(!game->building){
        game->building = new GreenTower();
        game->setCursor(QString(":/s_images/resources/images/green_space_tower.png"));
        game->m_money->decreaseAmount(500);
    }
    }
}
