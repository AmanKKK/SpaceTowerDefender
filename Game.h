#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include "Money.h"
#include "Health.h"
#include "ShowLevel.h"
#include <QTime>



class Game: public QGraphicsView{
    Q_OBJECT
public:
    // методы класса
    Game();
    /* В этом методе происходит перерисовка курсора. То есть, когда мы нажимаем курсором на иконку башни, курсор
     * перерисовывается в одну из башен, взависимости какая из них была выбрана
     */
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void creatRoad();
    void tmp_spawnEnemy();

    // переменные члены
    QTime* always_updating_time;
    QTime* pereodically_updating_time;
    int spawnSpeed = 2000;
    ShowLevel* m_level;
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
