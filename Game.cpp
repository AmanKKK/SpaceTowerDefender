#include "Game.h"
#include <QGraphicsScene>
#include "BrownTower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BuildBrownTowerIcon.h"
#include "BuildGreenTowerIcon.h"
#include "BuildRedTowerIcon.h"
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include <QGraphicsLineItem>
#include <QImage>
#include <QBrush>
#include <QDebug>




Game::Game(): QGraphicsView(){

      QTime t;
      time = new QTime(t.currentTime());
      time1 = new QTime(*time);
      *time1 = time1->addSecs(120);

    // создание сцены
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/s_images/resources/images/background.png")));

    // установка сцены
    setScene(scene);

    //установка курсора
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);


    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    timer_checker = new QTimer(this);
    connect(timer_checker,SIGNAL(timeout()),this,SLOT(increaseComplexity()));
    timer_checker->start(1000);


    pointsToFollow << QPointF(800,0) << QPointF(450,450) << QPointF(0,600);


    tmp_spawnEnemy();

    m_money = new Money();
    m_money->setPos(m_money->x()+75,m_money->y());
    scene->addItem(m_money);

    m_health = new Health();
    m_health->setPos(m_health->x()+75,m_health->y()+25);
    scene->addItem(m_health);


    creatRoad();

 // создание иконок в левом верхнем углу
    BuildBrownTowerIcon * bt = new BuildBrownTowerIcon();
    BuildGreenTowerIcon * gt = new BuildGreenTowerIcon();
    BuildRedTowerIcon * rt = new BuildRedTowerIcon();
    gt->setPos(x(),y()+100);
    rt->setPos(x(),y()+200);

    scene->addItem(bt);
    scene->addItem(gt);
    scene->addItem(rt);


}

void Game::increaseComplexity(){
    qDebug() << "time1:" + time1->toString("hh:mm:ss:zzz");
    qDebug() << "time:" + time->currentTime().toString("hh:mm:ss:zzz");
   if(spawnSpeed >=1200){
    if(time->currentTime().toString("hh:mm:ss") == time1->toString("hh:mm:ss")){
        qDebug() << "coincidence marked";
        *time1 = time1->addSecs(180);
        spawnSpeed -=200;
        tmp_spawnEnemy();
    }
   }else{
       timer_checker->disconnect();
   }

}

void Game::tmp_spawnEnemy(){
    spawnTimer = new QTimer(this);
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(spawnSpeed);
}

void Game::setCursor(QString filename){

    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if (cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    // если мы хотим установить новую башню на сцену
    if (building){

        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<Tower*>(items[i])){
                return;
            }
        }

        scene->addItem(building);
        building->setPos(event->pos());
        cursor = nullptr;
        building = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
    //

}





// траектория, по которой будут перемещаться вражеские объекты
void Game::creatRoad(){
    for (size_t i = 0, n = pointsToFollow.size()-1; i < n; i++){
        // создание линии соединяющие две точки
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);

        QPen pen;
        pen.setWidth(15);
        pen.setColor(Qt::darkGray);

        lineItem->setPen(pen);
        scene->addItem(lineItem);

    }
}

void Game::spawnEnemy(){
    Enemy * enemy = new Enemy(pointsToFollow);
    enemy->setPos(pointsToFollow[0]);
    scene->addItem(enemy);




}
