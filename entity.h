#ifndef ENTITY_H
#define ENTITY_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
using namespace std;

class Entity : public QGraphicsItem
{
    public:
        Entity();
        QRectF boundingRect() const;
        void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
        void setX (int);
        void setY (int);
    
        QPixmap enemy;
        int posX, posY;
    
    ~Entity(){}
};


#endif //ENTITY_H
