#include "Money.h"
#include <QFont>

Money::Money(QGraphicsItem* parent):
     QGraphicsTextItem(parent)
 {
    setPlainText(QString("Money: ") + QString::number(m_money));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",13));

 }

void Money::decreaseAmount(int amount){
    m_money-=amount;
    setPlainText(QString("X-wing bullets: ") + QString::number(m_money));
}

void Money::increaseAmount(int amountForIncrease){
    m_money+=amountForIncrease;
     setPlainText(QString("X-wing bullets: ") + QString::number(m_money));
}

int Money::getMoneyAmount()
{
    return m_money;
}
