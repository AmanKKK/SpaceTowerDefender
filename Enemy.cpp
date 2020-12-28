#include "Enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "Game.h"

extern Game* game;
int STEP_SIZE = 5;

#include <QDebug>
Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent){
    // установка изорбажения вражеского персонажа
    setPixmap(QPixmap(":s_images/resources/images/TIEFighter.png"));

    // установка точек, по которым будет осуществляться передвижение вражеского объекта
    points = pointsToFollow;
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveForward()));
    timer->start(150);
}

// данный метод принимает точку, по которому будет меняться направление вражеского объекта
// каждый раз, когда вражеский объект будет доходить до dest, его направление будет
void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Enemy::increaseSpeed(){
    STEP_SIZE+=5;
}

void Enemy::moveForward(){

    // если вражеский объект доходит до dest, то происходит его ротация до следующего dest
    QLineF ln(pos(),dest);

    if (ln.length() < 5){
        point_index++;
        // если последняя точка достигнута
        if (point_index >= points.size()){
            return;
        }

        dest = points[point_index];
        rotateToPoint(dest);
    }

    // перемещение вражеского объекта под текущим углом
//    int STEP_SIZE = 5;
    double theta = rotation(); // получение градусов

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
    if(pos().x() < 5){
    game->m_health->decrease();

        qDebug() << " passed " + QString::number(pos().x()) ;
    }
}

\
