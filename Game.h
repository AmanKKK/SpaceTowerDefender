#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include "Money.h"
#include "Health.h"
#include <QTime>



class Game: public QGraphicsView{
    Q_OBJECT
public:
    // методы класса
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createEnemies(int numberOfEnemies);
    void creatRoad();
    void tmp_spawnEnemy();

    // переменные члены
    QTime* time;
    QTime* time1;
    int spawnSpeed = 2000;
    Health* m_health;
    Money* m_money;
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * building;
    QTimer * spawnTimer; 
    QTimer * timer_checker;
    QList<QPointF> pointsToFollow;
public slots:
    void spawnEnemy();
    void increaseComplexity();



};



#endif // GAME_H
