#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include "Money.h"
#include "Health.h"



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
    int enemiesSpawned;
    int spawnSpeed = 2000;
//    int maxNumberOfEnemies;
    Health* m_health;
    Money* m_money;
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * building;
    QTimer * spawnTimer; 
    QList<QPointF> pointsToFollow;
public slots:
    void spawnEnemy();



};



#endif // GAME_H
