#ifndef SHOWLEVEL_H
#define SHOWLEVEL_H

#include <QGraphicsTextItem>

class ShowLevel: public QGraphicsTextItem
{
private:
    int m_level=1;
public:
    ShowLevel(QGraphicsItem* parent = 0);

    int getLevel();
    void increaseLevel();

};

#endif // SHOWLEVEL_H
