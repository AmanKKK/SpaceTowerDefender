#ifndef MONEY_H
#define MONEY_H

#include <QGraphicsTextItem>


class Money: public QGraphicsTextItem
{
private:
    int m_money=500;
public:
    Money(QGraphicsItem* parent = 0);

    void decreaseAmount(int amount);
    int getMoneyAmount();
    void increaseAmount(int amountForIncrease);

};

#endif // MONEY_H
