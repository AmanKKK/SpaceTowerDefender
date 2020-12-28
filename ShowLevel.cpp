#include "ShowLevel.h"
#include <QFont>



ShowLevel::ShowLevel(QGraphicsItem *parent): QGraphicsTextItem(parent){
    setPlainText(QString("Level: ") + QString::number(m_level)); //
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("times",13));
}

void ShowLevel::increaseLevel(){
    m_level+=1;
    setPlainText(QString("Level: ") + QString::number(m_level));
}
