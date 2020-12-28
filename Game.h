#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
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

    // переменные члены
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * building;
    QTimer * spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    Health* m_health;
    QList<QPointF> pointsToFollow;
public slots:
    void spawnEnemy();
};



#endif // GAME_H
