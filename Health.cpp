#include "Health.h"
#include "Game.h"
#include <QFont>
#include <QApplication>


extern Game* game;


Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    m_health = 3;


    setPlainText(QString("Health: ") + QString::number(m_health));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",13));
}

void Health::decrease(){
    m_health--;
    setPlainText(QString("Health: ") + QString::number(m_health));
    if(m_health<=0){
        qApp->quit();
    }

}


int Health::getHealth(){
    return m_health;
}
